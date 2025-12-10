#define TRACE
using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Management;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.Serialization;
using System.Runtime.Versioning;
using System.Security.Policy;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Windows.Forms;
using System.Xml;
using System.Xml.Schema;
using System.Xml.XPath;
using System.Xml.Xsl;
using Cummins.AddressRepresentation;
using Cummins.ApplicationServices;
using Cummins.CUTY;
using Cummins.Calibration;
using Cummins.EventLog;
using Cummins.FaultMonitor;
using Cummins.Interop.DataMonitoring;
using Cummins.Logging.EventDriven;
using Cummins.Module;
using Cummins.Parameter;
using Cummins.Services;
using Cummins.Subscription;
using Cummins.Widgets;

[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyTitle("Poodle")]
[assembly: CompilationRelaxations(8)]
[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - Logging")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.Logging
{
	public abstract class LogRecorder
	{
		public AutoResetEvent writeEventNumberValue = new AutoResetEvent(initialState: false);

		protected LogModel logModel;

		protected bool logActiveFaults;

		protected bool logInactiveFaults;

		private uint _logStartTime = uint.MaxValue;

		private bool _timeStampInSeconds;

		public LogRecorder(LogModel model)
		{
			logModel = model;
			logActiveFaults = model.Options.ShouldLogActiveFaults;
			logInactiveFaults = model.Options.ShouldLogInactiveFaults;
			GlobalEventNumber.WriteEventNumberToLogFile += OnEventNumberChanged;
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			_timeStampInSeconds = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.LogDLASecondsTime));
		}

		private void OnEventNumberChanged(object sender, EventArgs e)
		{
			writeEventNumberValue.Set();
		}

		public virtual void Register(int id)
		{
		}

		public virtual void UnRegister(int id)
		{
		}

		public abstract int RecordData(DataRefreshEventArgs e);

		public abstract int RecordUCLData(DataRefreshEventArgs e);

		protected bool RecordNotification(ICINotification asamNotification, IAddressValue sourceAddress, DataRow row)
		{
			bool flag = false;
			ICIMonitorElement iCIMonitorElement = null;
			string empty = string.Empty;
			for (int i = 0; i < asamNotification.Count; i++)
			{
				iCIMonitorElement = asamNotification.GetElement(i);
				try
				{
					empty = string.Empty;
					empty = LogModel.ColumnName(iCIMonitorElement.Name, sourceAddress);
					if (iCIMonitorElement.Value != null)
					{
						flag = UpdateColumns(empty, iCIMonitorElement.Value, row) || flag;
					}
				}
				catch (Exception)
				{
					flag = false;
				}
			}
			return flag;
		}

		protected bool RecordNotification(ArrayList parameterValues, IAddressValue sourceAddress, DataRow row)
		{
			string empty = string.Empty;
			CICPPMonitor cICPPMonitor = null;
			string empty2 = string.Empty;
			int num = -1;
			bool flag = false;
			foreach (ICIDataElementNotification parameterValue in parameterValues)
			{
				try
				{
					if (parameterValue.Status != tagCIDMStatusEnum.DM_STATUS_OK)
					{
						continue;
					}
					row["DLA Timestamp"] = FigureTimeStamp((uint)parameterValue.timeStamp);
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
						empty = LogModel.ColumnName(empty2, sourceAddress);
						flag = UpdateColumns(empty, parameterValue.ScaledValue, row) || flag;
						break;
					case tagCIDMAccessModeEnum.DM_MODE_ADDRESS:
						empty = LogModel.ColumnName(uint.Parse(cICPPMonitor.location.ToString()), cICPPMonitor.offset, (uint)cICPPMonitor.Length, sourceAddress);
						flag = UpdateColumns(empty, parameterValue.ScaledValue, row) || flag;
						break;
					}
				}
				catch (Exception)
				{
					flag = false;
				}
			}
			return flag;
		}

		protected bool RecordNotification(PGNList data, IAddressValue sourceAddress, DataRow row)
		{
			bool flag = false;
			string empty = string.Empty;
			row["DLA Timestamp"] = data.TimeStamp;
			foreach (PGN pGN in data.PGNs)
			{
				if (pGN.SPNs != null)
				{
					foreach (SPN sPN in pGN.SPNs)
					{
						try
						{
							empty = string.Empty;
							empty = LogModel.ColumnName(SPN.FigureFullName(pGN.Name, sPN.Name), AddressFactory.ProductAddressValue(sourceAddress.ToString()));
							if (sPN.Value != null)
							{
								flag = UpdateColumns(empty, sPN.Value, row) || flag;
							}
						}
						catch (Exception)
						{
							flag = false;
						}
					}
				}
				else
				{
					flag = false;
				}
			}
			return flag;
		}

		protected bool RecordNotification(CompositeJ1939_71Data data, DataRow row)
		{
			bool flag = false;
			string empty = string.Empty;
			J1939_71PGNMap j1939_71PGNMap = null;
			foreach (ushort key in data.Keys)
			{
				j1939_71PGNMap = data[key];
				uint num = FigureTimeStamp(j1939_71PGNMap.TimeStamp);
				row["DLA Timestamp"] = num;
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
							empty = LogModel.ColumnName(SPN.FigureFullName(value.Name, sPN.Name), AddressFactory.ProductAddressValue(key));
							if (sPN.Value != null)
							{
								flag = UpdateColumns(empty, sPN.Value, row) || flag;
							}
						}
						catch (Exception)
						{
							flag = false;
						}
					}
				}
			}
			return flag;
		}

		protected bool RecordUCLNotification(ICINotification asamNotification, IAddressValue sourceAddress, DataRow row)
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
					empty = LogModel.ColumnName(iCIMonitorElement.Name, sourceAddress);
					if (iCIMonitorElement.Value == null)
					{
						result = false;
					}
					else
					{
						UpdateUCLColumns(empty, iCIMonitorElement.Value, row);
					}
				}
				catch (Exception)
				{
					result = false;
				}
			}
			return result;
		}

		protected bool RecordUCLNotification(CompositeJ1939_71Data data, DataRow row)
		{
			bool result = true;
			string empty = string.Empty;
			J1939_71PGNMap j1939_71PGNMap = null;
			foreach (ushort key in data.Keys)
			{
				j1939_71PGNMap = data[key];
				row["DLA Timestamp"] = FigureTimeStamp(j1939_71PGNMap.TimeStamp);
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
							empty = LogModel.ColumnName(SPN.FigureFullName(value.Name, sPN.Name), AddressFactory.ProductAddressValue(key));
							empty.Contains("SHUTDN");
							if (sPN.Value == null)
							{
								result = false;
							}
							else
							{
								UpdateUCLColumns(empty, sPN.Value, row);
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

		protected bool RecordUCLNotification(ArrayList parameterValues, IAddressValue sourceAddress, DataRow row)
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
						row["DLA Timestamp"] = FigureTimeStamp((uint)parameterValue.timeStamp);
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
							empty = LogModel.ColumnName(empty2, sourceAddress);
							UpdateUCLColumns(empty, parameterValue.ScaledValue, row);
							break;
						case tagCIDMAccessModeEnum.DM_MODE_ADDRESS:
							empty = LogModel.ColumnName(uint.Parse(cICPPMonitor.location.ToString()), cICPPMonitor.offset, (uint)cICPPMonitor.Length, sourceAddress);
							UpdateUCLColumns(empty, parameterValue.ScaledValue, row);
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

		protected void RecordFaults(DataRow row)
		{
			if (!logModel.SuspendLoggingActiveFaults && logActiveFaults)
			{
				row["ActiveFaults"] = logModel.ActiveFaults;
			}
			if (!logModel.SuspendLoggingActiveFaults && logInactiveFaults)
			{
				row["InactiveFaults"] = logModel.InactiveFaults;
			}
		}

		protected void RecordPCTime(DataRow row)
		{
			_ = DateTime.Now;
			TimeSpan timeOfDay = DateTime.Now.TimeOfDay;
			row["PC Timestamp"] = $"{timeOfDay.Hours,2:D2}:{timeOfDay.Minutes,2:D2}:{timeOfDay.Seconds,2:D2}.{timeOfDay.Milliseconds:000}";
		}

		protected void RecordEventNumber(DataRow row)
		{
			if (writeEventNumberValue.WaitOne(0, exitContext: false))
			{
				row["EventNumber"] = GlobalEventNumber.currentEventNumber;
			}
			else
			{
				row["EventNumber"] = 0;
			}
		}

		protected bool UpdateColumns(string columnName, string val, DataRow row)
		{
			int[] columnIndexes = logModel.GetColumnIndexes(columnName);
			bool result = false;
			if (columnIndexes != null)
			{
				int[] array = columnIndexes;
				foreach (int num in array)
				{
					if (!(bool)logModel.LogBuffer.Columns[num].ExtendedProperties["Removed"])
					{
						row[num] = val;
					}
				}
				result = true;
			}
			return result;
		}

		protected void UpdateUCLColumns(string columnName, string val, DataRow row)
		{
			int[] uCLColumnIndexes = logModel.GetUCLColumnIndexes(columnName);
			int[] array = uCLColumnIndexes;
			foreach (int num in array)
			{
				if (!(bool)logModel.UCLogBuffer.Columns[num].ExtendedProperties["Removed"])
				{
					row[num] = val;
				}
			}
		}

		protected string ByteArrayToString(byte[] rawValue)
		{
			string text = "";
			foreach (byte b in rawValue)
			{
				text += b.ToString("X2");
			}
			return text;
		}

		protected uint FigureTimeStamp(uint currentTimeStamp)
		{
			uint num = currentTimeStamp;
			if (_timeStampInSeconds)
			{
				if (_logStartTime == uint.MaxValue)
				{
					_logStartTime = currentTimeStamp;
				}
				num -= _logStartTime;
			}
			return num;
		}
	}
	public class AllRecorder : LogRecorder
	{
		private class NotificationData
		{
			public bool Received;

			public DataRefreshEventArgs Notification;
		}

		private class PublicParameterCounts : Dictionary<ushort, int>
		{
		}

		private Hashtable notifications = new Hashtable();

		private PublicParameterCounts _publicDataParameterCounts = new PublicParameterCounts();

		private CompositeJ1939_71Data _j1939_71CompositeData;

		private CompositeJ1939_71Data J1939_71CompositeData
		{
			get
			{
				if (_j1939_71CompositeData == null)
				{
					_j1939_71CompositeData = new CompositeJ1939_71Data();
				}
				return _j1939_71CompositeData;
			}
			set
			{
				_j1939_71CompositeData = value;
			}
		}

		public AllRecorder(LogModel model, ArrayList registeredIds)
			: base(model)
		{
			foreach (int registeredId in registeredIds)
			{
				notifications.Add(registeredId, new NotificationData());
			}
		}

		public override void Register(int id)
		{
			lock (this)
			{
				if (!notifications.Contains(id))
				{
					notifications.Add(id, new NotificationData());
				}
				else
				{
					notifications[id] = new NotificationData();
				}
			}
		}

		public override void UnRegister(int id)
		{
			lock (this)
			{
				if (notifications.Contains(id))
				{
					notifications.Remove(id);
				}
			}
		}

		public override int RecordData(DataRefreshEventArgs e)
		{
			int result = -1;
			bool flag = true;
			lock (this)
			{
				if (e is J1939_71DataRefreshEventArgs)
				{
					PCLSubscriptionHelper.MergeJ1939_71Notifications(J1939_71CompositeData, e as J1939_71DataRefreshEventArgs);
				}
				else
				{
					(notifications[e.SubscriptionHashCode] as NotificationData).Notification = e;
					(notifications[e.SubscriptionHashCode] as NotificationData).Received = true;
				}
				if (AllDataReceived())
				{
					lock (logModel.LogBuffer)
					{
						DataRow dataRow = logModel.LogBuffer.NewRow();
						RecordPCTime(dataRow);
						RecordEventNumber(dataRow);
						RecordFaults(dataRow);
						foreach (int key in notifications.Keys)
						{
							DataRefreshEventArgs notification = (notifications[key] as NotificationData).Notification;
							if (notification == null)
							{
								continue;
							}
							if (notification.DataSourceType == DataSourceTypeEnum.ECM)
							{
								if (!RecordNotification((notification as ECMDataRefreshEventArgs).ECMData, (notification as ECMDataRefreshEventArgs).SourceAddress, dataRow))
								{
									flag = false;
									break;
								}
							}
							else if (notification.DataSourceType == DataSourceTypeEnum.ASAM && !RecordNotification((notification as ASAMDataRefreshEventArgs).ASAMData, (notification as ASAMDataRefreshEventArgs).SourceAddress, dataRow))
							{
								flag = false;
								break;
							}
						}
						RecordNotification(J1939_71CompositeData, dataRow);
						J1939_71CompositeData.Clear();
						if (flag)
						{
							logModel.LogBuffer.Rows.Add(dataRow);
						}
						ClearAll();
						result = (int)dataRow["index"];
					}
				}
			}
			return result;
		}

		public override int RecordUCLData(DataRefreshEventArgs e)
		{
			int result = -1;
			bool flag = true;
			lock (this)
			{
				if (e is J1939_71DataRefreshEventArgs)
				{
					PCLSubscriptionHelper.MergeJ1939_71Notifications(J1939_71CompositeData, e as J1939_71DataRefreshEventArgs);
				}
				else
				{
					(notifications[e.SubscriptionHashCode] as NotificationData).Notification = e;
					(notifications[e.SubscriptionHashCode] as NotificationData).Received = true;
				}
				if (AllDataReceived())
				{
					lock (logModel.UCLogBuffer)
					{
						DataRow dataRow = logModel.UCLogBuffer.NewRow();
						try
						{
							RecordPCTime(dataRow);
						}
						catch
						{
						}
						try
						{
							RecordFaults(dataRow);
						}
						catch
						{
						}
						foreach (int key in notifications.Keys)
						{
							DataRefreshEventArgs notification = (notifications[key] as NotificationData).Notification;
							if (notification == null)
							{
								continue;
							}
							if (notification.DataSourceType == DataSourceTypeEnum.ECM)
							{
								if (!RecordUCLNotification((notification as ECMDataRefreshEventArgs).ECMData, (notification as ECMDataRefreshEventArgs).SourceAddress, dataRow))
								{
									flag = false;
									break;
								}
							}
							else if (notification.DataSourceType == DataSourceTypeEnum.ASAM && !RecordUCLNotification((notification as ASAMDataRefreshEventArgs).ASAMData, (notification as ASAMDataRefreshEventArgs).SourceAddress, dataRow))
							{
								flag = false;
								break;
							}
						}
						RecordUCLNotification(J1939_71CompositeData, dataRow);
						if (flag)
						{
							logModel.UCLogBuffer.Rows.Add(dataRow);
						}
						result = (int)dataRow["index"];
					}
				}
			}
			return result;
		}

		private bool AllDataReceived()
		{
			bool flag = true;
			lock (this)
			{
				foreach (int key in notifications.Keys)
				{
					NotificationData notificationData = notifications[key] as NotificationData;
					if (notificationData.Received && notificationData.Notification != null)
					{
						if (notificationData.Notification.DataSourceType == DataSourceTypeEnum.ECM)
						{
							if ((notificationData.Notification as ECMDataRefreshEventArgs).ECMData.Count != notificationData.Notification.ParameterCount)
							{
								flag = false;
								break;
							}
						}
						else if (notificationData.Notification.DataSourceType == DataSourceTypeEnum.ASAM && (notificationData.Notification as ASAMDataRefreshEventArgs).ASAMData.Count < notificationData.Notification.ParameterCount)
						{
							flag = false;
							break;
						}
						continue;
					}
					flag = false;
					break;
				}
				if (flag)
				{
					foreach (ushort key2 in logModel.PublicDataCount.Keys)
					{
						if (GetParameterCount(key2, J1939_71CompositeData) < logModel.PublicDataCount[key2].Count)
						{
							flag = false;
							break;
						}
					}
				}
			}
			return flag;
		}

		private int GetParameterCount(ushort sourceAddress, CompositeJ1939_71Data compositeData)
		{
			int num = 0;
			if (compositeData.ContainsKey(sourceAddress))
			{
				J1939_71PGNMap j1939_71PGNMap = compositeData[sourceAddress];
				if (j1939_71PGNMap != null)
				{
					foreach (PGN value in j1939_71PGNMap.Values)
					{
						if (value.SPNs != null)
						{
							num += value.SPNs.Count;
						}
					}
				}
			}
			return num;
		}

		private void ClearAll()
		{
			lock (this)
			{
				ArrayList arrayList = new ArrayList(notifications.Keys);
				foreach (int item in arrayList)
				{
					notifications[item] = new NotificationData();
				}
			}
		}
	}
	public class AnyRecorder : LogRecorder
	{
		public AnyRecorder(LogModel logModel)
			: base(logModel)
		{
		}

		public override int RecordData(DataRefreshEventArgs e)
		{
			int result = -1;
			switch (e.DataSourceType)
			{
			case DataSourceTypeEnum.ASAM:
			{
				ASAMDataRefreshEventArgs e3 = e as ASAMDataRefreshEventArgs;
				if (e3.ASAMData != null)
				{
					result = AddOneRecord(e3.ASAMData, e3.SourceAddress, e.DataSourceType);
				}
				break;
			}
			case DataSourceTypeEnum.ECM:
			{
				ECMDataRefreshEventArgs e4 = e as ECMDataRefreshEventArgs;
				if (e4.ECMData != null)
				{
					result = AddOneRecord(e4.ECMData, e4.SourceAddress, e.DataSourceType);
				}
				break;
			}
			case DataSourceTypeEnum.J1939_71:
			{
				J1939_71DataRefreshEventArgs e2 = e as J1939_71DataRefreshEventArgs;
				if (e2.J1939_71Data == null)
				{
					break;
				}
				foreach (PGNList j1939_71Datum in e2.J1939_71Data)
				{
					if (j1939_71Datum.PGNs != null)
					{
						IAddressValue address = AddressFactory.ProductAddressValue(j1939_71Datum.SourceAddress.ToString("X2"));
						result = AddOneRecord(j1939_71Datum, address, e.DataSourceType);
					}
				}
				break;
			}
			}
			return result;
		}

		private int AddOneRecord<T>(T data, IAddressValue address, DataSourceTypeEnum sourceType)
		{
			int num = -1;
			bool flag = true;
			lock (logModel.LogBuffer)
			{
				DataRow dataRow = logModel.LogBuffer.NewRow();
				RecordPCTime(dataRow);
				RecordEventNumber(dataRow);
				RecordFaults(dataRow);
				switch (sourceType)
				{
				case DataSourceTypeEnum.ASAM:
					if (!RecordNotification(data as ICINotification, address, dataRow))
					{
						flag = false;
					}
					break;
				case DataSourceTypeEnum.ECM:
					if (!RecordNotification(data as ArrayList, address, dataRow))
					{
						flag = false;
					}
					break;
				case DataSourceTypeEnum.J1939_71:
					if (!RecordNotification(data as PGNList, address, dataRow))
					{
						flag = false;
					}
					break;
				}
				if (flag)
				{
					logModel.LogBuffer.Rows.Add(dataRow);
				}
				return (int)dataRow["index"];
			}
		}

		public override int RecordUCLData(DataRefreshEventArgs e)
		{
			int result = -1;
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
				DataRow dataRow;
				lock (logModel.UCLogBuffer)
				{
					dataRow = logModel.UCLogBuffer.NewRow();
				}
				try
				{
					RecordPCTime(dataRow);
				}
				catch
				{
				}
				try
				{
					RecordFaults(dataRow);
				}
				catch
				{
				}
				if (e.DataSourceType == DataSourceTypeEnum.ECM)
				{
					RecordUCLNotification((e as ECMDataRefreshEventArgs).ECMData, (e as ECMDataRefreshEventArgs).SourceAddress, dataRow);
				}
				else if (e.DataSourceType == DataSourceTypeEnum.ASAM)
				{
					RecordUCLNotification((e as ASAMDataRefreshEventArgs).ASAMData, (e as ASAMDataRefreshEventArgs).SourceAddress, dataRow);
				}
				else if (e.DataSourceType == DataSourceTypeEnum.J1939_71)
				{
					CompositeJ1939_71Data compositeJ1939_71Data = new CompositeJ1939_71Data();
					PCLSubscriptionHelper.MergeJ1939_71Notifications(compositeJ1939_71Data, e as J1939_71DataRefreshEventArgs);
					RecordUCLNotification(compositeJ1939_71Data, dataRow);
				}
				lock (logModel.UCLogBuffer)
				{
					logModel.UCLogBuffer.Rows.Add(dataRow);
					result = (int)dataRow["index"];
				}
			}
			return result;
		}
	}
	public abstract class LogWriter
	{
		protected const string NotANumber = "NaN";

		private const string _parametersWithDeviceAddress = "DeviceAddress <> ''";

		private const string _parametersWithoutDeviceAddress = "DeviceAddress = ''";

		protected string tempFileName;

		protected LoggingOptions options;

		public HeaderData headerData;

		public UCLHeaderData uclheaderData;

		protected bool _timestampsInSeconds;

		private static bool _isCustomHeaderSet = false;

		private static readonly object _customHeaderLock = new object();

		private static StringBuilder _customHeader = new StringBuilder();

		private StringBuilder _monitoringHeader = new StringBuilder();

		private StringBuilder _customHeaderString = new StringBuilder();

		public StringBuilder CustomHeader => _customHeaderString;

		public abstract long LogSize { get; }

		public LogWriter(LoggingOptions options)
		{
			this.options = options;
			headerData = default(HeaderData);
			uclheaderData = default(UCLHeaderData);
			headerData.IsDirty = false;
			uclheaderData.IsDirty = false;
			_isCustomHeaderSet = false;
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			_timestampsInSeconds = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.LogDLASecondsTime));
			options.LoggingOptionsChangedEvent = (EventHandler)Delegate.Combine(options.LoggingOptionsChangedEvent, new EventHandler(OnLoggingOptionsChangedEvent));
			SetCustomHeaderString();
		}

		protected void SetCustomHeaderString()
		{
			_customHeaderString.Clear();
			SetCustomHeader();
			SetMonitoringHeader();
			_customHeaderString.Append(_customHeader.ToString() + _monitoringHeader.ToString());
		}

		protected void SetMonitoringHeader()
		{
			lock (_customHeaderLock)
			{
				_monitoringHeader.Clear();
				CustomLogHeader.ParametersRow[] array = options.CustomLogHeader.Parameters.Select("DeviceAddress = ''") as CustomLogHeader.ParametersRow[];
				CustomLogHeader.ParametersRow[] array2 = array;
				foreach (CustomLogHeader.ParametersRow parametersRow in array2)
				{
					_monitoringHeader.Append(parametersRow.DeviceAddress + "," + parametersRow.ParameterName + "," + options.GetParameterValue(parametersRow.DeviceAddress, parametersRow.ParameterName) + Environment.NewLine);
				}
				_monitoringHeader.Remove(_monitoringHeader.Length - 2, 2);
			}
		}

		protected void SetCustomHeader()
		{
			lock (_customHeaderLock)
			{
				if (!_isCustomHeaderSet)
				{
					_customHeader.Clear();
					if (options.HeaderNotes.Length > 0)
					{
						_customHeader.Append("Notes ," + options.HeaderNotes + Environment.NewLine);
					}
					CustomLogHeader.ParametersRow[] array = options.CustomLogHeader.Parameters.Select("DeviceAddress <> ''") as CustomLogHeader.ParametersRow[];
					CustomLogHeader.ParametersRow[] array2 = array;
					foreach (CustomLogHeader.ParametersRow parametersRow in array2)
					{
						_customHeader.Append(parametersRow.DeviceAddress + "," + parametersRow.ParameterName + "," + options.GetParameterValue(parametersRow.DeviceAddress, parametersRow.ParameterName) + Environment.NewLine);
					}
					if (options.AddConfigNameToLogHeader)
					{
						_customHeader.Append(",Config File Name," + options.ConfigFileName + Environment.NewLine);
					}
					_isCustomHeaderSet = true;
				}
			}
		}

		public void OnLoggingOptionsChangedEvent(object sender, EventArgs e)
		{
			lock (_customHeaderLock)
			{
				_isCustomHeaderSet = false;
			}
			SetCustomHeaderString();
		}

		public abstract void WriteFileHeader();

		public abstract void WriteHeader(DataColumnCollection fields);

		public abstract void WriteUCLHeader(DataColumnCollection fields);

		public abstract void WriteData(DataTable values);

		public abstract void WriteUCLData(DataTable values);

		public abstract void Flush();

		public abstract void UCLFlush();

		public virtual void CalculateFreeSpaces()
		{
			options.DisplayFreeSpace = false;
		}

		public virtual void Save(string fileName)
		{
			Close();
			if (File.Exists(fileName))
			{
				File.Delete(fileName);
			}
			File.Move(tempFileName, fileName);
		}

		public abstract void Close();

		protected string FormatTime(uint time)
		{
			if (!_timestampsInSeconds)
			{
				double num = time;
				double num2 = Math.Floor((double)time / 1000.0);
				double num3 = Math.Floor(num2 / 60.0);
				double num4 = Math.Floor(num3 / 60.0);
				num -= num2 * 1000.0;
				num2 -= num3 * 60.0;
				num3 -= num4 * 60.0;
				string text = num.ToString();
				string text2 = num2.ToString();
				string text3 = num3.ToString();
				string text4 = num4.ToString();
				if (text4.Length < 2)
				{
					text4 = "0" + text4;
				}
				if (text3.Length < 2)
				{
					text3 = "0" + text3;
				}
				if (text2.Length < 2)
				{
					text2 = "0" + text2;
				}
				if (text.Length < 3)
				{
					text = ((text.Length >= 2) ? ("0" + text) : ("00" + text));
				}
				return text4 + ":" + text3 + ":" + text2 + "." + text;
			}
			return ((double)time / 1000.0).ToString("#.000");
		}
	}
	public abstract class StreamedLogWriter : LogWriter
	{
		internal const long TimeSpanUnit = 10000000L;

		internal const ulong TenMegs = 10485760uL;

		internal const string LineWithCommas = "--------------------------";

		internal const int DefaultMaxFlushCount = 20;

		internal const int MinutesInDay = 1440;

		internal const int MinutesInHour = 60;

		private LogStreamWriter writer;

		private DateTime lastFlushTime = DateTime.Now;

		private int numberOfFlushes;

		private long sizeAtlastFlush;

		private long previouslyAccumulatedLogSize;

		private int MaxFlushCount = 20;

		public override long LogSize => GetFileLength(tempFileName);

		protected LogStreamWriter Writer
		{
			get
			{
				lock (this)
				{
					if (writer == null)
					{
						tempFileName = options.GetLogFileName() + ".tmp";
						writer = new LogStreamWriter(tempFileName);
						writer.AutoFlush = true;
					}
				}
				return writer;
			}
		}

		public StreamedLogWriter(LoggingOptions options)
			: base(options)
		{
			CheckMediaFull();
		}

		~StreamedLogWriter()
		{
			try
			{
				Writer.Close();
				if (tempFileName.Length > 0 && File.Exists(tempFileName))
				{
					File.Delete(tempFileName);
				}
			}
			catch
			{
			}
		}

		public override void Save(string fileName)
		{
			base.Save(fileName);
			previouslyAccumulatedLogSize += GetFileLength(fileName);
			writer = null;
		}

		public override void Flush()
		{
			bool flag = CheckMediaFull();
			Writer.Flush();
			if (numberOfFlushes++ % MaxFlushCount == 0)
			{
				if (!flag)
				{
					CalculateFreeSpaces();
				}
				else
				{
					EventLogger.Info("Logging", "Media is already full");
				}
			}
		}

		public override void UCLFlush()
		{
			Writer.Flush();
		}

		public override void CalculateFreeSpaces()
		{
			try
			{
				TimeSpan timeSpan = DateTime.Now - lastFlushTime;
				ulong num = (ulong)(timeSpan.Seconds + timeSpan.Minutes * 60);
				long num2 = previouslyAccumulatedLogSize + LogSize;
				ulong num3 = (ulong)((num2 - sizeAtlastFlush) * 1024);
				if (num3 != 0)
				{
					ManagementObject diskInformation = GetDiskInformation(options.GetLogFileName());
					ulong num4 = Convert.ToUInt64(((ManagementBaseObject)diskInformation)["Size"]);
					ulong num5 = Convert.ToUInt64(num4 * 98 / 100);
					ulong val = num4 - num5;
					ulong num6 = Convert.ToUInt64(((ManagementBaseObject)diskInformation)["FreeSpace"]) - Math.Min(val, 10485760uL);
					diskInformation.Dispose();
					if (num6 == 0)
					{
						throw new InsufficientDiskSpaceException(9);
					}
					ulong seconds = num6 * num / num3;
					string message = "Estimated time before the media gets full for logger " + options.LogfilePrefix + " is : " + GetTimeString((long)seconds);
					string detailedMessage = "Logged " + num3 + " Bytes of data in " + num + " seconds.";
					EventLogger.Info("Logging", message, detailedMessage);
					AdjustTimeToCheckMediaFull((long)seconds);
				}
				sizeAtlastFlush = num2;
				lastFlushTime = DateTime.Now;
			}
			catch (TypeInitializationException ex)
			{
				EventLogger.Info("Logging", "You may not be getting any media full indications. Windows Management Instrumentation may not be registered on the machine. ", ex.Message.ToString());
			}
			catch (InsufficientDiskSpaceException)
			{
				throw;
			}
			catch (Exception ex3)
			{
				EventLogger.Warn("Logging", "Could not calculate available disk space", ex3);
			}
			base.CalculateFreeSpaces();
		}

		public override void Close()
		{
			Writer.Close();
		}

		private long GetFileLength(string fileName)
		{
			long result = 0L;
			if (File.Exists(fileName))
			{
				FileInfo fileInfo = new FileInfo(fileName);
				result = fileInfo.Length / 1024;
			}
			return result;
		}

		private ManagementObject GetDiskInformation(string fileName)
		{
			//IL_001b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0021: Expected O, but got Unknown
			string text = fileName.Substring(0, 2);
			string text2 = "win32_logicaldisk.deviceid=\"" + text + "\"";
			ManagementObject val = new ManagementObject(text2);
			val.Get();
			return val;
		}

		private string GetTimeString(long seconds)
		{
			TimeSpan timeSpan = new TimeSpan(seconds * 10000000);
			string text = string.Empty;
			if (timeSpan.Days > 0)
			{
				text = text + timeSpan.Days + " days";
			}
			if (timeSpan.Hours > 0)
			{
				object obj = text;
				text = string.Concat(obj, " ", timeSpan.Hours, " hours");
			}
			if (timeSpan.Minutes > 0)
			{
				object obj2 = text;
				text = string.Concat(obj2, " ", timeSpan.Minutes, " minutes");
			}
			if (timeSpan.Seconds > 0)
			{
				object obj3 = text;
				text = string.Concat(obj3, " ", timeSpan.Seconds, " seconds");
			}
			return text;
		}

		private void AdjustTimeToCheckMediaFull(long seconds)
		{
			TimeSpan timeSpan = new TimeSpan(seconds * 10000000);
			if (timeSpan.Days > 0)
			{
				MaxFlushCount = 1440;
			}
			else if (timeSpan.Hours > 0)
			{
				MaxFlushCount = 60;
			}
			else if (timeSpan.Minutes > 0)
			{
				MaxFlushCount = 20;
			}
		}

		private bool CheckMediaFull()
		{
			bool result = false;
			try
			{
				string logFileName = options.GetLogFileName();
				ManagementObject diskInformation = GetDiskInformation(logFileName);
				ulong num = Convert.ToUInt64(((ManagementBaseObject)diskInformation)["Size"]);
				ulong num2 = Convert.ToUInt64(((ManagementBaseObject)diskInformation)["FreeSpace"]);
				ulong num3 = num - num2;
				diskInformation.Dispose();
				if (num != 0)
				{
					ulong num4 = Convert.ToUInt64(num * 98 / 100);
					ulong val = num - num4;
					num4 = num - Math.Min(val, 10485760uL);
					if (num3 > num4)
					{
						result = true;
						if (!options.DeleteOldestOnMediaFull)
						{
							throw new InsufficientDiskSpaceException(9);
						}
						string directoryName = Path.GetDirectoryName(logFileName);
						if (!DeleteOldestPossibleFile(directoryName, "*.cmi,*.csv,*.html,*.txt"))
						{
							throw new InsufficientDiskSpaceException(9);
						}
					}
				}
			}
			catch (TypeInitializationException ex)
			{
				EventLogger.Info("Logging", "You may not be getting any media full indications. Windows Management Instrumentation may not be registered on the machine.", ex.Message.ToString());
			}
			catch (InsufficientDiskSpaceException)
			{
				throw;
			}
			catch (Exception ex3)
			{
				EventLogger.Warn("Logging", "Could not calculate available disk space", ex3);
			}
			return result;
		}

		private bool DeleteOldestPossibleFile(string path, string searchPattern)
		{
			bool flag = false;
			DirectoryInfo directoryInfo = new DirectoryInfo(path);
			string[] array = searchPattern.Split(new char[1] { ',' });
			ArrayList arrayList = new ArrayList();
			string[] array2 = array;
			foreach (string searchPattern2 in array2)
			{
				FileInfo[] files = directoryInfo.GetFiles(searchPattern2);
				for (int j = 0; j < files.Length; j++)
				{
					arrayList.Add(files[j]);
				}
			}
			if (arrayList.Count > 0)
			{
				arrayList.Sort(new FileInfoComparer());
				int num = 0;
				while (!flag && num < arrayList.Count)
				{
					FileInfo fileInfo = (FileInfo)arrayList[num];
					if ((fileInfo.Attributes & (FileAttributes.ReadOnly | FileAttributes.Hidden)) == 0 && fileInfo.FullName != tempFileName)
					{
						File.Delete(fileInfo.FullName);
						string text = "FileName : " + fileInfo.FullName + Environment.NewLine;
						object obj = text;
						text = string.Concat(obj, "Last Modification Time : ", fileInfo.LastWriteTime, Environment.NewLine);
						text = text + "Last Access Time : " + fileInfo.LastAccessTime;
						EventLogger.Info("Logging", "Deleted the file " + fileInfo.FullName + " to make space on media", text);
						flag = true;
					}
					num++;
				}
			}
			return flag;
		}
	}
	public class CSVLogWriter : StreamedLogWriter
	{
		internal static char Comma = ',';

		public CSVLogWriter(LoggingOptions options)
			: base(options)
		{
		}

		public override void WriteFileHeader()
		{
			base.Writer.WriteLine("Log File Version " + Comma + options.CustomLogHeader.LogHeader.NewLogHeaderRow().LogFileVersion);
			string value = DateTime.Now.ToShortDateString() + " " + DateTime.Now.ToLongTimeString();
			base.Writer.WriteLine(value);
			switch (options.RecordingMode)
			{
			case RecordingModes.AnyDataReceived:
				base.Writer.WriteLine("Log Mode " + Comma + "Log When Any Data Received");
				break;
			case RecordingModes.AllDataReceived:
				base.Writer.WriteLine("Log Mode " + Comma + "Log When All Data Received");
				break;
			case RecordingModes.UserSpecifiedRate:
				base.Writer.WriteLine("Log Mode " + Comma + "Log At User Specified Rate");
				base.Writer.WriteLine("Logging Rate is " + Comma + options.LogRate + "ms");
				break;
			}
			WriteCustomHeader();
			base.Writer.WriteLine("--------------------------");
		}

		public override void WriteHeader(DataColumnCollection fields)
		{
			headerData.Names = "Parameter Name";
			headerData.Units = "Units";
			headerData.Addresses = "Source Address";
			DataColumn dataColumn = null;
			for (int i = 1; i < fields.Count; i++)
			{
				dataColumn = fields[i];
				if ((bool)dataColumn.ExtendedProperties["Active"])
				{
					headerData.Names += Comma;
					headerData.Names += dataColumn.ExtendedProperties["displayName"];
					headerData.Units += Comma;
					headerData.Units += dataColumn.ExtendedProperties["units"];
					headerData.Addresses += Comma;
					headerData.Addresses += dataColumn.ExtendedProperties["address"];
				}
			}
			headerData.IsDirty = true;
		}

		public override void WriteUCLHeader(DataColumnCollection fields)
		{
			uclheaderData.Names = "Parameter Name";
			uclheaderData.Units = "Units";
			uclheaderData.Addresses = "Source Address";
			DataColumn dataColumn = null;
			for (int i = 1; i < fields.Count; i++)
			{
				dataColumn = fields[i];
				if ((bool)dataColumn.ExtendedProperties["Active"])
				{
					uclheaderData.Names += Comma;
					uclheaderData.Names += dataColumn.ExtendedProperties["displayName"];
					uclheaderData.Units += Comma;
					uclheaderData.Units += dataColumn.ExtendedProperties["units"];
					uclheaderData.Addresses += Comma;
					uclheaderData.Addresses += dataColumn.ExtendedProperties["address"];
				}
			}
			uclheaderData.IsDirty = true;
		}

		public override void WriteData(DataTable values)
		{
			if (headerData.IsDirty)
			{
				base.Writer.WriteLine(headerData.Names);
				base.Writer.WriteLine(headerData.Units);
				base.Writer.WriteLine(headerData.Addresses);
				headerData.IsDirty = false;
			}
			foreach (DataRow row in values.Rows)
			{
				string text = string.Empty;
				if ((bool)values.Columns["DLA Timestamp"].ExtendedProperties["Active"])
				{
					text += Comma;
					string text2 = "";
					if (row["DLA Timestamp"] != DBNull.Value)
					{
						text2 = FormatTime((uint)row["DLA Timestamp"]);
					}
					text += text2;
				}
				int num = 2;
				while (!base.Writer.Closed && num < values.Columns.Count)
				{
					bool flag = (bool)values.Columns[num].ExtendedProperties["Active"];
					bool flag2 = (bool)values.Columns[num].ExtendedProperties["Removed"];
					if (flag)
					{
						text += Comma;
						if (row[num] != DBNull.Value)
						{
							text += row[num].ToString();
						}
						else if (!flag2)
						{
							text += "NaN";
						}
					}
					base.Writer.Write(text);
					text = string.Empty;
					num++;
				}
				if (!base.Writer.Closed)
				{
					base.Writer.WriteLine(" ");
					continue;
				}
				break;
			}
		}

		public override void WriteUCLData(DataTable values)
		{
			if (uclheaderData.IsDirty)
			{
				base.Writer.WriteLine(uclheaderData.Names);
				base.Writer.WriteLine(uclheaderData.Units);
				base.Writer.WriteLine(uclheaderData.Addresses);
				uclheaderData.IsDirty = false;
			}
			foreach (DataRow row in values.Rows)
			{
				string text = string.Empty;
				if ((bool)values.Columns["DLA Timestamp"].ExtendedProperties["Active"])
				{
					text += Comma;
					string text2 = "";
					if (row["DLA Timestamp"] != DBNull.Value)
					{
						text2 = FormatTime((uint)row["DLA Timestamp"]);
					}
					text += text2;
				}
				for (int i = 2; i < values.Columns.Count; i++)
				{
					bool flag = (bool)values.Columns[i].ExtendedProperties["Active"];
					bool flag2 = (bool)values.Columns[i].ExtendedProperties["Removed"];
					if (flag)
					{
						text += Comma;
						if (row[i] != DBNull.Value)
						{
							text += row[i].ToString();
						}
						else if (!flag2)
						{
							text += "NaN";
						}
					}
					base.Writer.Write(text);
					text = string.Empty;
				}
				base.Writer.WriteLine(" ");
			}
		}

		private void WriteCustomHeader()
		{
			base.Writer.WriteLine(base.CustomHeader.ToString());
		}
	}
	[Serializable]
	[ToolboxItem(true)]
	[DesignerCategory("code")]
	[DebuggerStepThrough]
	public class CustomLogHeader : DataSet
	{
		public delegate void ParametersRowChangeEventHandler(object sender, ParametersRowChangeEvent e);

		public delegate void LogHeaderRowChangeEventHandler(object sender, LogHeaderRowChangeEvent e);

		[DebuggerStepThrough]
		public class ParametersDataTable : DataTable, IEnumerable
		{
			private DataColumn columnDeviceAddress;

			private DataColumn columnParameterName;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn DeviceAddressColumn => columnDeviceAddress;

			internal DataColumn ParameterNameColumn => columnParameterName;

			public ParametersRow this[int index] => (ParametersRow)base.Rows[index];

			public event ParametersRowChangeEventHandler ParametersRowChanged;

			public event ParametersRowChangeEventHandler ParametersRowChanging;

			public event ParametersRowChangeEventHandler ParametersRowDeleted;

			public event ParametersRowChangeEventHandler ParametersRowDeleting;

			internal ParametersDataTable()
				: base("Parameters")
			{
				InitClass();
			}

			internal ParametersDataTable(DataTable table)
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

			public void AddParametersRow(ParametersRow row)
			{
				base.Rows.Add(row);
			}

			public ParametersRow AddParametersRow(string DeviceAddress, string ParameterName)
			{
				ParametersRow parametersRow = (ParametersRow)NewRow();
				parametersRow.ItemArray = new object[2] { DeviceAddress, ParameterName };
				base.Rows.Add(parametersRow);
				return parametersRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				ParametersDataTable parametersDataTable = (ParametersDataTable)base.Clone();
				parametersDataTable.InitVars();
				return parametersDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new ParametersDataTable();
			}

			internal void InitVars()
			{
				columnDeviceAddress = base.Columns["DeviceAddress"];
				columnParameterName = base.Columns["ParameterName"];
			}

			private void InitClass()
			{
				columnDeviceAddress = new DataColumn("DeviceAddress", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnDeviceAddress);
				columnParameterName = new DataColumn("ParameterName", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnParameterName);
				columnDeviceAddress.AllowDBNull = false;
				columnParameterName.AllowDBNull = false;
			}

			public ParametersRow NewParametersRow()
			{
				return (ParametersRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new ParametersRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(ParametersRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.ParametersRowChanged != null)
				{
					this.ParametersRowChanged(this, new ParametersRowChangeEvent((ParametersRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.ParametersRowChanging != null)
				{
					this.ParametersRowChanging(this, new ParametersRowChangeEvent((ParametersRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.ParametersRowDeleted != null)
				{
					this.ParametersRowDeleted(this, new ParametersRowChangeEvent((ParametersRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.ParametersRowDeleting != null)
				{
					this.ParametersRowDeleting(this, new ParametersRowChangeEvent((ParametersRow)e.Row, e.Action));
				}
			}

			public void RemoveParametersRow(ParametersRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class ParametersRow : DataRow
		{
			private ParametersDataTable tableParameters;

			public string DeviceAddress
			{
				get
				{
					return (string)base[tableParameters.DeviceAddressColumn];
				}
				set
				{
					base[tableParameters.DeviceAddressColumn] = value;
				}
			}

			public string ParameterName
			{
				get
				{
					return (string)base[tableParameters.ParameterNameColumn];
				}
				set
				{
					base[tableParameters.ParameterNameColumn] = value;
				}
			}

			internal ParametersRow(DataRowBuilder rb)
				: base(rb)
			{
				tableParameters = (ParametersDataTable)base.Table;
			}
		}

		[DebuggerStepThrough]
		public class ParametersRowChangeEvent : EventArgs
		{
			private ParametersRow eventRow;

			private DataRowAction eventAction;

			public ParametersRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public ParametersRowChangeEvent(ParametersRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		[DebuggerStepThrough]
		public class LogHeaderDataTable : DataTable, IEnumerable
		{
			private DataColumn columnDisplayLogVersion;

			private DataColumn columnLogFileVersion;

			private DataColumn columnNotes;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn DisplayLogVersionColumn => columnDisplayLogVersion;

			internal DataColumn LogFileVersionColumn => columnLogFileVersion;

			internal DataColumn NotesColumn => columnNotes;

			public LogHeaderRow this[int index] => (LogHeaderRow)base.Rows[index];

			public event LogHeaderRowChangeEventHandler LogHeaderRowChanged;

			public event LogHeaderRowChangeEventHandler LogHeaderRowChanging;

			public event LogHeaderRowChangeEventHandler LogHeaderRowDeleted;

			public event LogHeaderRowChangeEventHandler LogHeaderRowDeleting;

			internal LogHeaderDataTable()
				: base("LogHeader")
			{
				InitClass();
			}

			internal LogHeaderDataTable(DataTable table)
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

			public void AddLogHeaderRow(LogHeaderRow row)
			{
				base.Rows.Add(row);
			}

			public LogHeaderRow AddLogHeaderRow(bool DisplayLogVersion, string LogFileVersion, string Notes)
			{
				LogHeaderRow logHeaderRow = (LogHeaderRow)NewRow();
				logHeaderRow.ItemArray = new object[3] { DisplayLogVersion, LogFileVersion, Notes };
				base.Rows.Add(logHeaderRow);
				return logHeaderRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				LogHeaderDataTable logHeaderDataTable = (LogHeaderDataTable)base.Clone();
				logHeaderDataTable.InitVars();
				return logHeaderDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new LogHeaderDataTable();
			}

			internal void InitVars()
			{
				columnDisplayLogVersion = base.Columns["DisplayLogVersion"];
				columnLogFileVersion = base.Columns["LogFileVersion"];
				columnNotes = base.Columns["Notes"];
			}

			private void InitClass()
			{
				columnDisplayLogVersion = new DataColumn("DisplayLogVersion", typeof(bool), null, MappingType.Attribute);
				base.Columns.Add(columnDisplayLogVersion);
				columnLogFileVersion = new DataColumn("LogFileVersion", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnLogFileVersion);
				columnNotes = new DataColumn("Notes", typeof(string), null, MappingType.Element);
				base.Columns.Add(columnNotes);
				columnDisplayLogVersion.Namespace = "";
				columnDisplayLogVersion.DefaultValue = true;
				columnLogFileVersion.AllowDBNull = false;
				columnLogFileVersion.DefaultValue = "2.3";
			}

			public LogHeaderRow NewLogHeaderRow()
			{
				return (LogHeaderRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new LogHeaderRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(LogHeaderRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.LogHeaderRowChanged != null)
				{
					this.LogHeaderRowChanged(this, new LogHeaderRowChangeEvent((LogHeaderRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.LogHeaderRowChanging != null)
				{
					this.LogHeaderRowChanging(this, new LogHeaderRowChangeEvent((LogHeaderRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.LogHeaderRowDeleted != null)
				{
					this.LogHeaderRowDeleted(this, new LogHeaderRowChangeEvent((LogHeaderRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.LogHeaderRowDeleting != null)
				{
					this.LogHeaderRowDeleting(this, new LogHeaderRowChangeEvent((LogHeaderRow)e.Row, e.Action));
				}
			}

			public void RemoveLogHeaderRow(LogHeaderRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class LogHeaderRow : DataRow
		{
			private LogHeaderDataTable tableLogHeader;

			public bool DisplayLogVersion
			{
				get
				{
					try
					{
						return (bool)base[tableLogHeader.DisplayLogVersionColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableLogHeader.DisplayLogVersionColumn] = value;
				}
			}

			public string LogFileVersion
			{
				get
				{
					return (string)base[tableLogHeader.LogFileVersionColumn];
				}
				set
				{
					base[tableLogHeader.LogFileVersionColumn] = value;
				}
			}

			public string Notes
			{
				get
				{
					try
					{
						return (string)base[tableLogHeader.NotesColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableLogHeader.NotesColumn] = value;
				}
			}

			internal LogHeaderRow(DataRowBuilder rb)
				: base(rb)
			{
				tableLogHeader = (LogHeaderDataTable)base.Table;
			}

			public bool IsDisplayLogVersionNull()
			{
				return IsNull(tableLogHeader.DisplayLogVersionColumn);
			}

			public void SetDisplayLogVersionNull()
			{
				base[tableLogHeader.DisplayLogVersionColumn] = Convert.DBNull;
			}

			public bool IsNotesNull()
			{
				return IsNull(tableLogHeader.NotesColumn);
			}

			public void SetNotesNull()
			{
				base[tableLogHeader.NotesColumn] = Convert.DBNull;
			}
		}

		[DebuggerStepThrough]
		public class LogHeaderRowChangeEvent : EventArgs
		{
			private LogHeaderRow eventRow;

			private DataRowAction eventAction;

			public LogHeaderRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public LogHeaderRowChangeEvent(LogHeaderRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		private ParametersDataTable tableParameters;

		private LogHeaderDataTable tableLogHeader;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Browsable(false)]
		public ParametersDataTable Parameters => tableParameters;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		[Browsable(false)]
		public LogHeaderDataTable LogHeader => tableLogHeader;

		public CustomLogHeader()
		{
			InitClass();
			CollectionChangeEventHandler value = SchemaChanged;
			base.Tables.CollectionChanged += value;
			base.Relations.CollectionChanged += value;
		}

		protected CustomLogHeader(SerializationInfo info, StreamingContext context)
		{
			//IL_0034: Unknown result type (might be due to invalid IL or missing references)
			//IL_003e: Expected O, but got Unknown
			string text = (string)info.GetValue("XmlSchema", typeof(string));
			if (text != null)
			{
				DataSet dataSet = new DataSet();
				dataSet.ReadXmlSchema((XmlReader?)new XmlTextReader((TextReader)new StringReader(text)));
				if (dataSet.Tables["Parameters"] != null)
				{
					base.Tables.Add(new ParametersDataTable(dataSet.Tables["Parameters"]));
				}
				if (dataSet.Tables["LogHeader"] != null)
				{
					base.Tables.Add(new LogHeaderDataTable(dataSet.Tables["LogHeader"]));
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
			CustomLogHeader customLogHeader = (CustomLogHeader)base.Clone();
			customLogHeader.InitVars();
			return customLogHeader;
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
			if (dataSet.Tables["Parameters"] != null)
			{
				base.Tables.Add(new ParametersDataTable(dataSet.Tables["Parameters"]));
			}
			if (dataSet.Tables["LogHeader"] != null)
			{
				base.Tables.Add(new LogHeaderDataTable(dataSet.Tables["LogHeader"]));
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
			tableParameters = (ParametersDataTable)base.Tables["Parameters"];
			if (tableParameters != null)
			{
				tableParameters.InitVars();
			}
			tableLogHeader = (LogHeaderDataTable)base.Tables["LogHeader"];
			if (tableLogHeader != null)
			{
				tableLogHeader.InitVars();
			}
		}

		private void InitClass()
		{
			base.DataSetName = "CustomLogHeader";
			base.Prefix = "";
			base.Namespace = "";
			base.Locale = new CultureInfo("en-US");
			base.CaseSensitive = false;
			base.EnforceConstraints = true;
			tableParameters = new ParametersDataTable();
			base.Tables.Add(tableParameters);
			tableLogHeader = new LogHeaderDataTable();
			base.Tables.Add(tableLogHeader);
		}

		private bool ShouldSerializeParameters()
		{
			return false;
		}

		private bool ShouldSerializeLogHeader()
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
	public class CustomLogHeaderControl : UserControl, IPropertyPage
	{
		private string parentNode;

		private string currentNode;

		private ILoggerConfiguration options;

		private CustomLogHeader customLogHeader;

		private Panel paLogHeader;

		private DataGrid dgParameters;

		private TextBox textBoxNotes;

		private Label labelNotes;

		private Panel upperPanel;

		private Panel lowerPanel;

		private CheckBox chkboxConfigNameToHeader;

		private Container components;

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

		public CustomLogHeaderControl()
		{
			InitializeComponent();
			parentNode = "";
			currentNode = "";
		}

		public CustomLogHeaderControl(ILoggerConfiguration options)
		{
			InitializeComponent();
			parentNode = "";
			currentNode = "";
			this.options = options;
		}

		public CustomLogHeaderControl(ILoggerConfiguration options, string parentNode, string currentNode)
		{
			InitializeComponent();
			this.parentNode = parentNode;
			this.currentNode = currentNode;
			this.options = options;
			if (options.CustomLogHeader != null)
			{
				customLogHeader = options.CustomLogHeader;
				customLogHeader.Parameters.ColumnChanging += OnParametersColumnChanging;
				dgParameters.SetDataBinding((object)customLogHeader, "Parameters");
			}
			GetOptions();
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			((ContainerControl)this).Dispose(disposing);
		}

		private void OnParametersColumnChanging(object sender, DataColumnChangeEventArgs e)
		{
			e.ProposedValue = (e.ProposedValue as string).Replace('\n', ' ');
			e.ProposedValue = (e.ProposedValue as string).Replace('\r', ' ');
			e.ProposedValue = (e.ProposedValue as string).Trim();
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
			paLogHeader = new Panel();
			lowerPanel = new Panel();
			dgParameters = new DataGrid();
			upperPanel = new Panel();
			labelNotes = new Label();
			textBoxNotes = new TextBox();
			chkboxConfigNameToHeader = new CheckBox();
			((Control)paLogHeader).SuspendLayout();
			((Control)lowerPanel).SuspendLayout();
			((ISupportInitialize)dgParameters).BeginInit();
			((Control)upperPanel).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)paLogHeader).Controls.Add((Control)(object)lowerPanel);
			((Control)paLogHeader).Controls.Add((Control)(object)upperPanel);
			((Control)paLogHeader).Dock = (DockStyle)5;
			((Control)paLogHeader).Location = new Point(0, 0);
			((Control)paLogHeader).Name = "paLogHeader";
			((Control)paLogHeader).Size = new Size(472, 320);
			((Control)paLogHeader).TabIndex = 0;
			((Control)lowerPanel).Controls.Add((Control)(object)dgParameters);
			((Control)lowerPanel).Dock = (DockStyle)5;
			((Control)lowerPanel).Location = new Point(0, 32);
			((Control)lowerPanel).Name = "lowerPanel";
			((Control)lowerPanel).Size = new Size(472, 288);
			((Control)lowerPanel).TabIndex = 6;
			dgParameters.DataMember = "";
			((Control)dgParameters).Dock = (DockStyle)5;
			dgParameters.FlatMode = true;
			dgParameters.HeaderForeColor = SystemColors.ControlText;
			((Control)dgParameters).Location = new Point(0, 0);
			((Control)dgParameters).Name = "dgParameters";
			dgParameters.PreferredColumnWidth = 150;
			((Control)dgParameters).Size = new Size(472, 288);
			((Control)dgParameters).TabIndex = 4;
			((Control)upperPanel).Controls.Add((Control)(object)chkboxConfigNameToHeader);
			((Control)upperPanel).Controls.Add((Control)(object)labelNotes);
			((Control)upperPanel).Controls.Add((Control)(object)textBoxNotes);
			((Control)upperPanel).Dock = (DockStyle)1;
			((Control)upperPanel).Location = new Point(0, 0);
			((Control)upperPanel).Name = "upperPanel";
			((Control)upperPanel).Size = new Size(472, 32);
			((Control)upperPanel).TabIndex = 5;
			((Control)labelNotes).Location = new Point(8, 8);
			((Control)labelNotes).Name = "labelNotes";
			((Control)labelNotes).Size = new Size(40, 16);
			((Control)labelNotes).TabIndex = 1;
			((Control)labelNotes).Text = "&Notes";
			((Control)textBoxNotes).Location = new Point(48, 6);
			((Control)textBoxNotes).Name = "textBoxNotes";
			((Control)textBoxNotes).Size = new Size(184, 20);
			((Control)textBoxNotes).TabIndex = 2;
			((Control)chkboxConfigNameToHeader).AutoSize = true;
			((Control)chkboxConfigNameToHeader).Location = new Point(257, 9);
			((Control)chkboxConfigNameToHeader).Name = "chkboxConfigNameToHeader";
			((Control)chkboxConfigNameToHeader).Size = new Size(127, 17);
			((Control)chkboxConfigNameToHeader).TabIndex = 3;
			((Control)chkboxConfigNameToHeader).Text = "Log Config File Name";
			((ButtonBase)chkboxConfigNameToHeader).UseVisualStyleBackColor = true;
			((Control)this).Controls.Add((Control)(object)paLogHeader);
			((Control)this).Name = "CustomLogHeaderControl";
			((Control)this).Size = new Size(472, 320);
			((Control)paLogHeader).ResumeLayout(false);
			((Control)lowerPanel).ResumeLayout(false);
			((ISupportInitialize)dgParameters).EndInit();
			((Control)upperPanel).ResumeLayout(false);
			((Control)upperPanel).PerformLayout();
			((Control)this).ResumeLayout(false);
		}

		public void Initialize()
		{
			GetOptions();
		}

		public void SetOptions()
		{
			options.HeaderNotes = ((Control)textBoxNotes).Text;
			options.AddConfigNameToLogHeader = chkboxConfigNameToHeader.Checked;
			options.Save();
		}

		private void GetOptions()
		{
			((Control)textBoxNotes).Text = options.HeaderNotes;
			chkboxConfigNameToHeader.Checked = options.AddConfigNameToLogHeader;
		}
	}
	public class MonitoredListChangedEventArgs : EventArgs
	{
		public DataTable LogData;

		public MonitoredListChangedEventArgs(DataTable logData)
		{
			LogData = logData;
		}
	}
	public class UCLMonitoredListChangedEventArgs : EventArgs
	{
		public DataTable UCLogData;

		public UCLMonitoredListChangedEventArgs(DataTable uclogData)
		{
			UCLogData = uclogData;
		}
	}
	public class StateChangeEventArgs : EventArgs
	{
		public LoggingState NewState;

		public LoggingState OldState;

		public DataColumnCollection MonitoredList;

		public StateChangeEventArgs(LoggingState newState, LoggingState oldState, DataColumnCollection monitoredList)
		{
			NewState = newState;
			OldState = oldState;
			MonitoredList = monitoredList;
		}
	}
	public class UCLStateChangeEventArgs : EventArgs
	{
		public UCLState NewState;

		public UCLState OldState;

		public DataColumnCollection MonitoredList;

		public UCLStateChangeEventArgs(UCLState newState, UCLState oldState, DataColumnCollection monitoredList)
		{
			NewState = newState;
			OldState = oldState;
			MonitoredList = monitoredList;
		}
	}
	public class LogSweptEventArgs : EventArgs
	{
		public DataTable Log;

		public LogSweptEventArgs(DataTable logTable)
		{
			Log = logTable;
		}
	}
	public class UCLogSweptEventArgs : EventArgs
	{
		public DataTable UCLog;

		public UCLogSweptEventArgs(DataTable logTable)
		{
			UCLog = logTable;
		}
	}
	public class LoggingOverEventArgs : EventArgs
	{
		public string LogFileName;

		public Formats Format;

		public bool DisplayLogFile;

		public LoggingOverEventArgs(string filename, Formats format, bool displayLogFile)
		{
			LogFileName = filename;
			Format = format;
			DisplayLogFile = displayLogFile;
		}
	}
}
namespace Cummins.Logging.EventDriven
{
	public abstract class Condition
	{
		public const string suffixOR = "OR";

		public const string suffixAND = "AND";

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

		public Condition()
		{
		}

		public Condition(string condition)
		{
		}

		protected abstract void Validate(string condition);

		public abstract bool Evaluate();
	}
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
					if (controller.ConditionType == ConditionType.Fault)
					{
						text = ((Control)cmbConditionBase).Text + " " + ((Control)edValue).Text + " " + ((Control)cmbRelation).Text;
					}
					else if (controller.ConditionType == ConditionType.Time)
					{
						text = ((Control)cmbConditionBase).Text + " " + ((Control)cmbRelation).Text + " " + ((Control)dateTimePickerTime).Text;
					}
					else if (controller.ConditionType == ConditionType.Value)
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
			ArrayList arrayList = (ArrayList)LogModel.MonitoredParameters.Clone();
			arrayList.AddRange(new string[2] { "FAULT", "TIME" });
			cmbConditionBase.DataSource = arrayList;
		}

		public ConditionEdit(Condition condition)
		{
			InitializeComponent();
			ArrayList arrayList = (ArrayList)LogModel.MonitoredParameters.Clone();
			arrayList.AddRange(new string[3] { "", "FAULT", "TIME" });
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
			((Control)edValue).Text = "";
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
			rbOR.CheckedChanged += OnConditionJoinerSuffixChanged;
			rbAND.Checked = true;
			((Control)rbAND).Location = new Point(8, 32);
			((Control)rbAND).Name = "rbAND";
			((Control)rbAND).Size = new Size(56, 16);
			((Control)rbAND).TabIndex = 3;
			rbAND.TabStop = true;
			((Control)rbAND).Text = "AND";
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
				MessageBox.Show(ex.Message, "Logging", (MessageBoxButtons)0, (MessageBoxIcon)16);
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
			if (controller.ConditionType == ConditionType.Fault)
			{
				((Control)edValue).Visible = true;
				((Control)edValue).Text = string.Empty;
				((Control)edValue).Left = ((Control)cmbConditionBase).Left + ((Control)cmbConditionBase).Width + 4;
				cmbRelation.DataSource = controller.faultOptionsArray.Clone();
				((Control)cmbRelation).Left = ((Control)edValue).Left + ((Control)edValue).Width + 4;
				((Control)dateTimePickerTime).Visible = false;
				((Control)cmbRelation).TabIndex = 2;
				((Control)edValue).TabIndex = 1;
				((Control)dateTimePickerTime).TabIndex = 5;
			}
			else if (controller.ConditionType == ConditionType.Time)
			{
				((Control)cmbRelation).Left = ((Control)cmbConditionBase).Left + ((Control)cmbConditionBase).Width + 4;
				cmbRelation.DataSource = controller.timeOptionsArray.Clone();
				((Control)dateTimePickerTime).Left = ((Control)cmbRelation).Left + ((Control)cmbRelation).Width + 4;
				((Control)edValue).Visible = false;
				((Control)dateTimePickerTime).Visible = true;
				((Control)cmbRelation).TabIndex = 1;
				((Control)dateTimePickerTime).TabIndex = 2;
				((Control)edValue).TabIndex = 5;
			}
			else
			{
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
			}
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

		private Condition condition;

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

		public void Initialize(Condition condition)
		{
			this.condition = condition;
			if (condition is ValueCondition)
			{
				Suffix = condition.Suffix;
				Relation = (int)(condition as ValueCondition).Operation;
				Value = (condition as ValueCondition).BaseValue;
				ConditionBase = (condition as ValueCondition).Name;
				ConditionType = ConditionType.Value;
			}
			else if (condition is TimerCondition)
			{
				Suffix = condition.Suffix;
				Relation = (int)(condition as TimerCondition).Operation;
				Value = (condition as TimerCondition).BaseValue;
				ConditionType = ConditionType.Time;
			}
			else if (condition is FaultCondition)
			{
				Suffix = condition.Suffix;
				Relation = (int)(condition as FaultCondition).ExpectedState;
				Value = (condition as FaultCondition).BaseValue;
				ConditionType = ConditionType.Fault;
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
			if (ConditionType == ConditionType.Fault && Relation != -1)
			{
				string input = ConditionBase + TXTLogWriter.Space + Value + TXTLogWriter.Space + faultOptionsArray[Relation];
				Regex regex = new Regex("FAULT\\s+((\\*)|([0-9,a-f,A-F]{2}[:]{1}\\d+))\\s+(becomes Active|becomes Inactive|New)\\s*(\\s*|AND\\s*|OR\\s*)$");
				return regex.IsMatch(input);
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
	public class ConditionFactory
	{
		public Condition Create(string condition, LogModel logModel)
		{
			if (condition == null)
			{
				throw new ArgumentNullException("condition");
			}
			Condition condition2 = null;
			condition = condition.Trim();
			if (condition.StartsWith("TIME"))
			{
				return new TimerCondition(condition);
			}
			if (condition.StartsWith("FAULT"))
			{
				if (logModel != null)
				{
					return new FaultCondition(condition, logModel.Faults);
				}
				return new FaultCondition(condition, null);
			}
			if (logModel != null)
			{
				return new ValueCondition(condition, logModel.LogBuffer);
			}
			return new ValueCondition(condition, null);
		}
	}
	public class FaultCondition : Condition
	{
		internal const string Any = "*";

		internal const string CurrentState = "CurrentStatus";

		internal const string PreviousState = "PreviousStatus";

		internal const string faultPattern = "FAULT\\s+((\\*)|([0-9,a-f,A-F]{2}[:]{1}\\d+))\\s+(becomes Active|becomes Inactive|New)\\s*(\\s*|AND\\s*|OR\\s*)$";

		private FaultState expectedState;

		private DataTable faultsTable;

		private string sourceAddress;

		private string faultCode;

		public string FaultCode
		{
			get
			{
				return faultCode;
			}
			set
			{
				faultCode = value;
			}
		}

		public FaultState ExpectedState
		{
			get
			{
				return expectedState;
			}
			set
			{
				expectedState = value;
			}
		}

		public FaultCondition(string condition, DataTable faultsTable)
		{
			Validate(condition);
			this.faultsTable = faultsTable;
			base.Suffix = ConditionJoiner.NONE;
			if (condition.Trim().EndsWith("OR"))
			{
				condition = condition.Remove(condition.LastIndexOf("OR"), "OR".Length);
				base.Suffix = ConditionJoiner.OR;
			}
			else if (condition.Trim().EndsWith("AND"))
			{
				condition = condition.Remove(condition.LastIndexOf("AND"), "AND".Length);
				base.Suffix = ConditionJoiner.AND;
			}
			condition = condition.Trim();
			string empty = string.Empty;
			if (condition.EndsWith("becomes Active"))
			{
				ExpectedState = FaultState.Active;
				empty = "becomes Active";
			}
			else if (condition.EndsWith("becomes Inactive"))
			{
				ExpectedState = FaultState.InActive;
				empty = "becomes Inactive";
			}
			else
			{
				if (!condition.EndsWith("New"))
				{
					throw new MalformedFaultConditionException(2);
				}
				ExpectedState = FaultState.New;
				empty = "New";
			}
			int startIndex = condition.LastIndexOf(empty);
			condition = condition.Remove(startIndex, empty.Length);
			if (condition.StartsWith("FAULT"))
			{
				base.BaseValue = condition.Substring(condition.IndexOf("FAULT") + 5).Trim();
				string[] array = base.BaseValue.Split(new char[1] { ':' });
				if (array.Length == 2)
				{
					sourceAddress = array[0];
					FaultCode = array[1];
				}
				return;
			}
			throw new InvalidConditionException(2);
		}

		public override bool Evaluate()
		{
			bool result = false;
			if (faultsTable != null)
			{
				lock (faultsTable)
				{
					result = ((!(FaultCode == "*")) ? EvaluateSpecificFault() : EvaluateForAnyFault());
				}
			}
			return result;
		}

		protected override void Validate(string condition)
		{
			if (condition == null || condition.Trim().Length == 0)
			{
				throw new ArgumentNullException("condition");
			}
			Regex regex = new Regex("FAULT\\s+((\\*)|([0-9,a-f,A-F]{2}[:]{1}\\d+))\\s+(becomes Active|becomes Inactive|New)\\s*(\\s*|AND\\s*|OR\\s*)$");
			if (!regex.IsMatch(condition))
			{
				throw new MalformedFaultConditionException(5);
			}
		}

		private bool EvaluateSpecificFault()
		{
			bool result = false;
			DataRow[] array = faultsTable.Select("FaultCode = '" + FaultCode + "' and SourceAddress = '" + sourceAddress + "'");
			string text = "";
			if (array.Length == 1)
			{
				switch (ExpectedState)
				{
				case FaultState.Active:
					text = (string)array[0]["CurrentStatus"];
					result = text == FaultState.Active.ToString();
					break;
				case FaultState.InActive:
					text = (string)array[0]["CurrentStatus"];
					result = text == FaultState.InActive.ToString();
					break;
				case FaultState.New:
				{
					string text2 = (string)array[0]["PreviousStatus"];
					text = (string)array[0]["CurrentStatus"];
					result = text2 == "Unknown" && text == FaultState.Active.ToString();
					break;
				}
				}
			}
			else if (array.Length > 1)
			{
				throw new InvalidOperationException("Fault Table in invalid state");
			}
			return result;
		}

		private bool EvaluateForAnyFault()
		{
			bool result = false;
			DataRow[] array = null;
			switch (ExpectedState)
			{
			case FaultState.Active:
				array = faultsTable.Select("CurrentStatus = 'Active'");
				result = array.Length > 0;
				break;
			case FaultState.InActive:
				array = faultsTable.Select("CurrentStatus = 'InActive'");
				result = array.Length > 0;
				break;
			case FaultState.New:
				array = faultsTable.Select("CurrentStatus = 'Active' and PreviousStatus = 'Unknown'");
				result = array.Length > 0;
				break;
			}
			return result;
		}
	}
	public class TimerCondition : Condition
	{
		private const string TimePattern = "TIME\\s+(is greater than or equal to|is less than or equal to|>=|<=)\\s+([0-9]{1,2}:){2}\\d{1,2}\\s+(AM|PM)\\s*(\\s*|AND\\s*|OR\\s*)$";

		private Operation operation;

		private DateTime baseTime;

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

		public TimerCondition(string condition)
		{
			Validate(condition);
			string pattern = "is greater than or equal to|is less than or equal to|>=|<=";
			Regex regex = new Regex(pattern);
			string[] array = regex.Split(condition);
			if (array.Length == 2)
			{
				string text = array[0].Trim();
				base.BaseValue = array[1].Trim();
				base.Suffix = ConditionJoiner.NONE;
				if (array[1].Trim().EndsWith("OR"))
				{
					base.Suffix = ConditionJoiner.OR;
					base.BaseValue = array[1].Remove(array[1].LastIndexOf("OR"), "OR".Length);
					condition = condition.Remove(condition.LastIndexOf("OR"), "OR".Length);
				}
				else if (array[1].Trim().EndsWith("AND"))
				{
					base.Suffix = ConditionJoiner.AND;
					base.BaseValue = array[1].Remove(array[1].LastIndexOf("AND"), "AND".Length);
					condition = condition.Remove(condition.LastIndexOf("AND"), "AND".Length);
				}
				string text2 = condition.Remove(condition.LastIndexOf(text), text.Length);
				text2 = text2.Remove(text2.LastIndexOf(base.BaseValue), base.BaseValue.Length);
				switch (text2.Trim())
				{
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
					baseTime = Convert.ToDateTime(base.BaseValue);
					return;
				}
				catch (Exception inner)
				{
					throw new MalformedTimerConditionException(7, "Time specified is not valid", inner);
				}
			}
			throw new InvalidConditionException(2);
		}

		public override bool Evaluate()
		{
			bool result = false;
			switch (Operation)
			{
			case Operation.GreatherThanEqual:
				result = DateTime.Now >= baseTime;
				break;
			case Operation.LessThanEqual:
				result = DateTime.Now <= baseTime;
				break;
			}
			return result;
		}

		protected override void Validate(string condition)
		{
			if (condition == null || condition.Trim().Length == 0)
			{
				throw new ArgumentNullException("condition");
			}
			Regex regex = new Regex("TIME\\s+(is greater than or equal to|is less than or equal to|>=|<=)\\s+([0-9]{1,2}:){2}\\d{1,2}\\s+(AM|PM)\\s*(\\s*|AND\\s*|OR\\s*)$");
			if (!regex.IsMatch(condition))
			{
				throw new MalformedTimerConditionException(6);
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

		public Trigger(string trigger, LogModel model)
		{
			if (trigger == null)
			{
				throw new ArgumentNullException("trigger");
			}
			if (trigger.Length <= 0)
			{
				return;
			}
			ConditionFactory conditionFactory = null;
			Condition condition = null;
			string empty = string.Empty;
			string empty2 = string.Empty;
			string text = trigger;
			int num = -1;
			int num2 = -1;
			Regex regex = new Regex(" OR | AND ");
			string[] array = regex.Split(trigger);
			conditionFactory = new ConditionFactory();
			if (array.Length == 0)
			{
				condition = conditionFactory.Create(trigger, model);
				if (condition != null)
				{
					Conditions.Add(condition);
				}
				return;
			}
			if (array.Length <= 4)
			{
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
					condition = conditionFactory.Create(empty + " " + empty2, model);
					if (condition != null)
					{
						Conditions.Add(condition);
					}
					if (num2 != -1)
					{
						text = text.Substring(num2);
					}
				}
				return;
			}
			throw new ConditionLimitExceededException(8, "Trigger cannot contain more than 4 conditions");
		}

		public bool Evaluate()
		{
			bool flag = false;
			if (Conditions.Count > 0)
			{
				flag = (Conditions[0] as Condition).Evaluate();
			}
			bool flag2 = false;
			for (int i = 1; i < Conditions.Count; i++)
			{
				flag2 = (Conditions[i] as Condition).Evaluate();
				switch ((Conditions[i - 1] as Condition).Suffix)
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

		public override string ToString()
		{
			string text = string.Empty;
			foreach (Condition condition in Conditions)
			{
				text += condition.ToString();
			}
			return text;
		}
	}
	public class TriggerConfigurationDlg : Form
	{
		private Button buttonCancel;

		private CheckBox ckEnableStopTrigger;

		private GroupBox gbTriggers;

		private TextBox edStopTrigger;

		private Button btnEditStopTrigger;

		private GroupBox gbStartTrigger;

		private TextBox edStartTrigger;

		private CheckBox ckEnableStartTrigger;

		private Button btnEditStartTrigger;

		private Label laPreTrigger;

		private Label laPostTrigger;

		private TextBox edPreTrigger;

		private Label laPreTriggerSeconds;

		private Label laPostTriggerSeconds;

		private TextBox edPostTrigger;

		private TextBox edRepeat;

		private Label laRepeatTimes;

		private CheckBox ckRepeatLogging;

		private Container components;

		private Button btnOK;

		private TriggerLoggingOptions triggerOptions;

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
			//IL_038f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0399: Expected O, but got Unknown
			//IL_03ac: Unknown result type (might be due to invalid IL or missing references)
			//IL_03b6: Expected O, but got Unknown
			//IL_0718: Unknown result type (might be due to invalid IL or missing references)
			//IL_0722: Expected O, but got Unknown
			//IL_0798: Unknown result type (might be due to invalid IL or missing references)
			//IL_07a2: Expected O, but got Unknown
			//IL_0ad3: Unknown result type (might be due to invalid IL or missing references)
			//IL_0add: Expected O, but got Unknown
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(TriggerConfigurationDlg));
			ckEnableStopTrigger = new CheckBox();
			gbTriggers = new GroupBox();
			laPostTriggerSeconds = new Label();
			laPostTrigger = new Label();
			edPostTrigger = new TextBox();
			edStopTrigger = new TextBox();
			btnEditStopTrigger = new Button();
			btnOK = new Button();
			buttonCancel = new Button();
			gbStartTrigger = new GroupBox();
			laPreTrigger = new Label();
			edPreTrigger = new TextBox();
			laPreTriggerSeconds = new Label();
			edStartTrigger = new TextBox();
			ckEnableStartTrigger = new CheckBox();
			btnEditStartTrigger = new Button();
			edRepeat = new TextBox();
			laRepeatTimes = new Label();
			ckRepeatLogging = new CheckBox();
			((Control)gbTriggers).SuspendLayout();
			((Control)gbStartTrigger).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)ckEnableStopTrigger).Location = new Point(8, 24);
			((Control)ckEnableStopTrigger).Name = "ckEnableStopTrigger";
			((Control)ckEnableStopTrigger).Size = new Size(136, 24);
			((Control)ckEnableStopTrigger).TabIndex = 9;
			((Control)ckEnableStopTrigger).Text = "Enable Stop T&rigger";
			ckEnableStopTrigger.CheckedChanged += ckEnableStartTrigger_CheckedChanged;
			((Control)gbTriggers).Controls.Add((Control)(object)laPostTriggerSeconds);
			((Control)gbTriggers).Controls.Add((Control)(object)laPostTrigger);
			((Control)gbTriggers).Controls.Add((Control)(object)edPostTrigger);
			((Control)gbTriggers).Controls.Add((Control)(object)ckEnableStopTrigger);
			((Control)gbTriggers).Controls.Add((Control)(object)edStopTrigger);
			((Control)gbTriggers).Controls.Add((Control)(object)btnEditStopTrigger);
			((Control)gbTriggers).Location = new Point(5, 160);
			((Control)gbTriggers).Name = "gbTriggers";
			((Control)gbTriggers).Size = new Size(488, 136);
			((Control)gbTriggers).TabIndex = 8;
			gbTriggers.TabStop = false;
			((Control)gbTriggers).Text = "Stopping Configuration";
			((Control)laPostTriggerSeconds).AutoSize = true;
			((Control)laPostTriggerSeconds).Location = new Point(434, 101);
			((Control)laPostTriggerSeconds).Name = "laPostTriggerSeconds";
			((Control)laPostTriggerSeconds).Size = new Size(47, 13);
			((Control)laPostTriggerSeconds).TabIndex = 14;
			((Control)laPostTriggerSeconds).Text = "seconds";
			((Control)laPostTrigger).Location = new Point(8, 96);
			((Control)laPostTrigger).Name = "laPostTrigger";
			((Control)laPostTrigger).Size = new Size(360, 26);
			((Control)laPostTrigger).TabIndex = 12;
			((Control)laPostTrigger).Text = "&Duration upto which Logging should continue once it has been started  automatically by the start trigger:";
			((Control)edPostTrigger).Location = new Point(376, 99);
			((TextBoxBase)edPostTrigger).MaxLength = 5;
			((Control)edPostTrigger).Name = "edPostTrigger";
			((Control)edPostTrigger).Size = new Size(48, 20);
			((Control)edPostTrigger).TabIndex = 13;
			((Control)edPostTrigger).Text = "0";
			edPostTrigger.TextAlign = (HorizontalAlignment)1;
			((Control)edPostTrigger).KeyPress += new KeyPressEventHandler(TimeLimit_KeyPress);
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
			btnOK.DialogResult = (DialogResult)1;
			((Control)btnOK).Location = new Point(328, 336);
			((Control)btnOK).Name = "btnOK";
			((Control)btnOK).Size = new Size(75, 23);
			((Control)btnOK).TabIndex = 18;
			((Control)btnOK).Text = "OK";
			((Control)btnOK).Click += btnOK_Click;
			buttonCancel.DialogResult = (DialogResult)2;
			((Control)buttonCancel).Location = new Point(418, 336);
			((Control)buttonCancel).Name = "buttonCancel";
			((Control)buttonCancel).Size = new Size(75, 23);
			((Control)buttonCancel).TabIndex = 19;
			((Control)buttonCancel).Text = "Cancel";
			((Control)gbStartTrigger).Controls.Add((Control)(object)laPreTrigger);
			((Control)gbStartTrigger).Controls.Add((Control)(object)edPreTrigger);
			((Control)gbStartTrigger).Controls.Add((Control)(object)laPreTriggerSeconds);
			((Control)gbStartTrigger).Controls.Add((Control)(object)edStartTrigger);
			((Control)gbStartTrigger).Controls.Add((Control)(object)ckEnableStartTrigger);
			((Control)gbStartTrigger).Controls.Add((Control)(object)btnEditStartTrigger);
			((Control)gbStartTrigger).Location = new Point(5, 16);
			((Control)gbStartTrigger).Name = "gbStartTrigger";
			((Control)gbStartTrigger).Size = new Size(488, 128);
			((Control)gbStartTrigger).TabIndex = 1;
			gbStartTrigger.TabStop = false;
			((Control)gbStartTrigger).Text = "Starting Configuration";
			((Control)laPreTrigger).Location = new Point(8, 88);
			((Control)laPreTrigger).Name = "laPreTrigger";
			((Control)laPreTrigger).Size = new Size(360, 26);
			((Control)laPreTrigger).TabIndex = 5;
			((Control)laPreTrigger).Text = "&Pretrigger (Time interval prior to the start trigger getting active from which data should actually be logged) :";
			((Control)edPreTrigger).Location = new Point(376, 91);
			((TextBoxBase)edPreTrigger).MaxLength = 5;
			((Control)edPreTrigger).Name = "edPreTrigger";
			((Control)edPreTrigger).Size = new Size(48, 20);
			((Control)edPreTrigger).TabIndex = 6;
			((Control)edPreTrigger).Text = "0";
			edPreTrigger.TextAlign = (HorizontalAlignment)1;
			((Control)edPreTrigger).KeyPress += new KeyPressEventHandler(TimeLimit_KeyPress);
			((Control)laPreTriggerSeconds).AutoSize = true;
			((Control)laPreTriggerSeconds).Location = new Point(434, 93);
			((Control)laPreTriggerSeconds).Name = "laPreTriggerSeconds";
			((Control)laPreTriggerSeconds).Size = new Size(47, 13);
			((Control)laPreTriggerSeconds).TabIndex = 7;
			((Control)laPreTriggerSeconds).Text = "seconds";
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
			((Control)edRepeat).Location = new Point(160, 302);
			((Control)edRepeat).Name = "edRepeat";
			((Control)edRepeat).Size = new Size(40, 20);
			((Control)edRepeat).TabIndex = 16;
			((Control)edRepeat).Text = "0";
			edRepeat.TextAlign = (HorizontalAlignment)1;
			((Control)laRepeatTimes).Location = new Point(202, 308);
			((Control)laRepeatTimes).Name = "laRepeatTimes";
			((Control)laRepeatTimes).Size = new Size(32, 8);
			((Control)laRepeatTimes).TabIndex = 17;
			((Control)laRepeatTimes).Text = "times";
			laRepeatTimes.TextAlign = (ContentAlignment)16;
			((Control)ckRepeatLogging).Location = new Point(5, 304);
			((Control)ckRepeatLogging).Name = "ckRepeatLogging";
			((Control)ckRepeatLogging).Size = new Size(147, 16);
			((Control)ckRepeatLogging).TabIndex = 15;
			((Control)ckRepeatLogging).Text = "&Repeat Logging cycle :";
			ckRepeatLogging.CheckedChanged += ckEnableStartTrigger_CheckedChanged;
			((Form)this).AcceptButton = (IButtonControl)(object)btnOK;
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).CancelButton = (IButtonControl)(object)buttonCancel;
			((Form)this).ClientSize = new Size(498, 367);
			((Control)this).Controls.Add((Control)(object)edRepeat);
			((Control)this).Controls.Add((Control)(object)laRepeatTimes);
			((Control)this).Controls.Add((Control)(object)ckRepeatLogging);
			((Control)this).Controls.Add((Control)(object)gbStartTrigger);
			((Control)this).Controls.Add((Control)(object)buttonCancel);
			((Control)this).Controls.Add((Control)(object)btnOK);
			((Control)this).Controls.Add((Control)(object)gbTriggers);
			((Form)this).FormBorderStyle = (FormBorderStyle)1;
			((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
			((Form)this).MaximizeBox = false;
			((Control)this).Name = "TriggerConfigurationDlg";
			((Form)this).ShowInTaskbar = false;
			((Control)this).Text = "Event-driven Logging";
			((Control)gbTriggers).ResumeLayout(false);
			((Control)gbTriggers).PerformLayout();
			((Control)gbStartTrigger).ResumeLayout(false);
			((Control)gbStartTrigger).PerformLayout();
			((Control)this).ResumeLayout(false);
			((Control)this).PerformLayout();
		}

		private void ckEnableStartTrigger_CheckedChanged(object sender, EventArgs e)
		{
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
					flag = InvalidateForm("Please specify a valid number for Duration of logging", (Control)(object)edPostTrigger);
				}
			}
			if (flag && ((Control)edPreTrigger).Text.Length != 0)
			{
				flag = ValidateNumericField((Control)(object)edPreTrigger, "Please specify a numeric value for PreTrigger");
			}
			if (flag && !ckEnableStopTrigger.Checked && ((Control)edPostTrigger).Text.Length != 0)
			{
				flag = ValidateNumericField((Control)(object)edPostTrigger, "Please specify a numeric value for Duration of logging");
			}
			if (flag && ((Control)edRepeat).Text.Trim().Length != 0)
			{
				flag = ValidateNumericField((Control)(object)edRepeat, "Please specify a numeric value for Repeat count of logging cycle");
			}
			if (flag)
			{
				((Form)this).DialogResult = (DialogResult)1;
			}
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

		private bool InvalidateForm(string message, Control focusControl)
		{
			//IL_0009: Unknown result type (might be due to invalid IL or missing references)
			MessageBox.Show(message, "Logging", (MessageBoxButtons)0, (MessageBoxIcon)64);
			focusControl.Focus();
			((Form)this).DialogResult = (DialogResult)0;
			return false;
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

		private void TimeLimit_KeyPress(object sender, KeyPressEventArgs e)
		{
			int keyChar = e.KeyChar;
			if (!char.IsDigit(e.KeyChar) && keyChar != 8)
			{
				e.Handled = true;
			}
		}
	}
	public class TriggerEditor : Form
	{
		internal const int MaxConditions = 4;

		private Button buttonCancel;

		private Button buttonOK;

		private ConditionEdit[] conditionEditList;

		private string outputTrigger = string.Empty;

		private Trigger trigger;

		private Container components;

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
			//IL_017c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0186: Expected O, but got Unknown
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(TriggerEditor));
			buttonCancel = new Button();
			buttonOK = new Button();
			((Control)this).SuspendLayout();
			buttonCancel.DialogResult = (DialogResult)2;
			((Control)buttonCancel).Location = new Point(184, 232);
			((Control)buttonCancel).Name = "buttonCancel";
			((Control)buttonCancel).Size = new Size(75, 23);
			((Control)buttonCancel).TabIndex = 5;
			((Control)buttonCancel).Text = "Cancel";
			buttonOK.DialogResult = (DialogResult)1;
			((Control)buttonOK).Location = new Point(96, 232);
			((Control)buttonOK).Name = "buttonOK";
			((Control)buttonOK).Size = new Size(75, 23);
			((Control)buttonOK).TabIndex = 4;
			((Control)buttonOK).Text = "OK";
			((Control)buttonOK).Click += buttonOK_Click;
			((Form)this).AcceptButton = (IButtonControl)(object)buttonOK;
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).CancelButton = (IButtonControl)(object)buttonCancel;
			((Form)this).ClientSize = new Size(514, 264);
			((Control)this).Controls.Add((Control)(object)buttonCancel);
			((Control)this).Controls.Add((Control)(object)buttonOK);
			((Form)this).FormBorderStyle = (FormBorderStyle)1;
			((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
			((Form)this).MaximizeBox = false;
			((Control)this).Name = "TriggerEditor";
			((Form)this).ShowInTaskbar = false;
			((Control)this).Text = "Edit Start Condition";
			((Control)this).ResumeLayout(false);
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

		private void CreateConditionEdits()
		{
			int num = 50;
			conditionEditList = new ConditionEdit[4];
			for (int i = 0; i < trigger.Conditions.Count; i++)
			{
				conditionEditList[i] = new ConditionEdit(trigger.Conditions[i] as Condition);
				((Control)conditionEditList[i]).Location = new Point(8, num * i);
				((Control)conditionEditList[i]).Name = "conditionEdit" + i;
				((Control)conditionEditList[i]).Size = new Size(424, num);
				((Control)conditionEditList[i]).TabIndex = i;
			}
			for (int j = trigger.Conditions.Count; j < 4; j++)
			{
				conditionEditList[j] = new ConditionEdit(null);
				((Control)conditionEditList[j]).Location = new Point(8, num * j);
				((Control)conditionEditList[j]).Name = "conditionEdit" + j;
				((Control)conditionEditList[j]).Size = new Size(424, num);
				((Control)conditionEditList[j]).TabIndex = j;
			}
			((Control)this).Controls.AddRange((Control[])(object)conditionEditList);
		}
	}
	public class TriggerLoggingOptions
	{
		internal const string TriggerFile = "trigger.xml";

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
			if ((string)dataRow["StartCondition"] != StartTrigger)
			{
				dataRow["StartCondition"] = StartTrigger;
			}
			if ((string)dataRow["StopCondition"] != StopTrigger)
			{
				dataRow["StopCondition"] = StopTrigger;
			}
			if ((int)dataRow["PreTrigger"] != PreTrigger)
			{
				dataRow["PreTrigger"] = PreTrigger;
			}
			if ((int)dataRow["PostTrigger"] != PostTrigger)
			{
				dataRow["PostTrigger"] = PostTrigger;
			}
			if ((int)dataRow["RepeatCount"] != RepeatCount)
			{
				dataRow["RepeatCount"] = RepeatCount;
			}
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
			return text + "\\trigger.xml";
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
	public class ValueCondition : Condition
	{
		private const string valuePattern = "[0-9,a-f,A-F]{2}[:]{1}\\w+\\s+(is greater than|is less than|equals|does not equals|is greater than or equal to|is less than or equal to|>|<|=|!=|>=|<=)\\s+(\\d+[.]?\\d*)\\s*(\\s*|AND\\s*|OR\\s*)$";

		private string name;

		private Operation operation;

		private double scaledFloat;

		private DataTable logBuffer;

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

		internal ValueCondition(string condition, DataTable logBuffer)
		{
			Validate(condition);
			this.logBuffer = logBuffer;
			string pattern = "does not equals|equals|is greater than or equal to|is less than or equal to|is greater than|is less than|>=|<=|!=|=|>|<";
			Regex regex = new Regex(pattern);
			string[] array = regex.Split(condition);
			if (array.Length == 2)
			{
				Name = array[0];
				base.BaseValue = array[1];
				base.Suffix = ConditionJoiner.NONE;
				if (array[1].Trim().EndsWith("OR"))
				{
					base.Suffix = ConditionJoiner.OR;
					base.BaseValue = array[1].Remove(array[1].LastIndexOf("OR"), "OR".Length);
					condition = condition.Remove(condition.LastIndexOf("OR"), "OR".Length);
				}
				else if (array[1].Trim().EndsWith("AND"))
				{
					base.Suffix = ConditionJoiner.AND;
					base.BaseValue = array[1].Remove(array[1].LastIndexOf("AND"), "AND".Length);
					condition = condition.Remove(condition.LastIndexOf("AND"), "AND".Length);
				}
				string text = condition.Remove(condition.LastIndexOf(Name), Name.Length);
				text = text.Remove(text.LastIndexOf(base.BaseValue), base.BaseValue.Length);
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
					scaledFloat = double.Parse(base.BaseValue);
					return;
				}
				catch (Exception inner)
				{
					throw new InvalidConditionException(2, "Not a valid float", inner);
				}
			}
			throw new InvalidConditionException(2);
		}

		public override bool Evaluate()
		{
			if (logBuffer == null)
			{
				throw new InvalidOperationException("Log buffer is not initialized");
			}
			double num = 0.0;
			int index = logBuffer.Rows.Count - 1;
			DataRow dataRow = logBuffer.Rows[index];
			try
			{
				num = double.Parse(dataRow[ColumnName()].ToString());
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

		protected override void Validate(string condition)
		{
			if (condition.Trim().Length == 0)
			{
				throw new ArgumentNullException("condition");
			}
			Regex regex = new Regex("[0-9,a-f,A-F]{2}[:]{1}\\w+\\s+(is greater than|is less than|equals|does not equals|is greater than or equal to|is less than or equal to|>|<|=|!=|>=|<=)\\s+(\\d+[.]?\\d*)\\s*(\\s*|AND\\s*|OR\\s*)$");
			if (!regex.IsMatch(condition))
			{
				throw new MalformedValueConditionException(3);
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
}
namespace Cummins.Logging
{
	public static class GlobalEventNumber
	{
		private static uint eventNumber = 0u;

		public static bool startTimeFlag = true;

		public static bool doNotActivateTrigger = false;

		public static uint currentEventNumber
		{
			get
			{
				return eventNumber;
			}
			set
			{
				eventNumber = value;
			}
		}

		public static event EventHandler WriteEventNumberToLogFile;

		public static void RaiseWriteEventNumbertoLogFile()
		{
			if (GlobalEventNumber.WriteEventNumberToLogFile != null)
			{
				GlobalEventNumber.WriteEventNumberToLogFile(null, EventArgs.Empty);
			}
		}
	}
	public class LoggingException : BaseException
	{
		public LoggingException(short errorNo)
			: base(Facility.Logging, errorNo)
		{
		}

		public LoggingException(Facility facility, short errorNo)
			: base(facility, errorNo)
		{
		}

		public LoggingException(Facility facility, short errorNo, string message)
			: base(facility, errorNo, message)
		{
		}

		public LoggingException(Facility facility, short errorNo, string message, Exception inner)
			: base(facility, errorNo, message, inner)
		{
		}

		public LoggingException(Facility facility, short errorNo, string message, string context)
			: base(facility, errorNo, message, context)
		{
		}

		public LoggingException(Facility facility, short errorNo, string message, string context, Exception inner)
			: base(facility, errorNo, message, context, inner)
		{
		}
	}
	public class InvalidConditionException : LoggingException
	{
		public InvalidConditionException(short errorNo)
			: base(Facility.Logging, errorNo)
		{
		}

		public InvalidConditionException(short errorNo, string message)
			: base(Facility.Logging, errorNo, message)
		{
		}

		public InvalidConditionException(short errorNo, string message, Exception inner)
			: base(Facility.Logging, errorNo, message, inner)
		{
		}
	}
	public class MalformedValueConditionException : LoggingException
	{
		public MalformedValueConditionException(short errorNo)
			: base(Facility.Logging, errorNo)
		{
		}

		public MalformedValueConditionException(short errorNo, string message)
			: base(Facility.Logging, errorNo, message)
		{
		}

		public MalformedValueConditionException(short errorNo, string message, Exception inner)
			: base(Facility.Logging, errorNo, message, inner)
		{
		}
	}
	public class MalformedFaultConditionException : LoggingException
	{
		public MalformedFaultConditionException(short errorNo)
			: base(Facility.Logging, errorNo)
		{
		}

		public MalformedFaultConditionException(short errorNo, string message)
			: base(Facility.Logging, errorNo, message)
		{
		}

		public MalformedFaultConditionException(short errorNo, string message, Exception inner)
			: base(Facility.Logging, errorNo, message, inner)
		{
		}
	}
	public class MalformedTimerConditionException : LoggingException
	{
		public MalformedTimerConditionException(short errorNo)
			: base(Facility.Logging, errorNo)
		{
		}

		public MalformedTimerConditionException(short errorNo, string message)
			: base(Facility.Logging, errorNo, message)
		{
		}

		public MalformedTimerConditionException(short errorNo, string message, Exception inner)
			: base(Facility.Logging, errorNo, message, inner)
		{
		}
	}
	public class InvalidTriggerException : LoggingException
	{
		public InvalidTriggerException(short errorNo)
			: base(Facility.Logging, errorNo)
		{
		}

		public InvalidTriggerException(short errorNo, string message)
			: base(Facility.Logging, errorNo, message)
		{
		}

		public InvalidTriggerException(short errorNo, string message, Exception inner)
			: base(Facility.Logging, errorNo, message, inner)
		{
		}
	}
	public class ConditionLimitExceededException : LoggingException
	{
		public ConditionLimitExceededException(short errorNo)
			: base(Facility.Logging, errorNo)
		{
		}

		public ConditionLimitExceededException(short errorNo, string message)
			: base(Facility.Logging, errorNo, message)
		{
		}

		public ConditionLimitExceededException(short errorNo, string message, Exception inner)
			: base(Facility.Logging, errorNo, message, inner)
		{
		}
	}
	public class InsufficientDiskSpaceException : LoggingException
	{
		public InsufficientDiskSpaceException(short errorNo)
			: base(Facility.Logging, errorNo)
		{
		}

		public InsufficientDiskSpaceException(short errorNo, string message)
			: base(Facility.Logging, errorNo, message)
		{
		}

		public InsufficientDiskSpaceException(short errorNo, string message, Exception inner)
			: base(Facility.Logging, errorNo, message, inner)
		{
		}
	}
	public class NoUpdateRateSpecifiedException : LoggingException
	{
		public NoUpdateRateSpecifiedException(short errorNo)
			: base(Facility.Logging, errorNo)
		{
		}

		public NoUpdateRateSpecifiedException(short errorNo, string message)
			: base(Facility.Logging, errorNo, message)
		{
		}

		public NoUpdateRateSpecifiedException(short errorNo, string message, Exception inner)
			: base(Facility.Logging, errorNo, message, inner)
		{
		}
	}
	public class NegativeUpdateRateException : LoggingException
	{
		public NegativeUpdateRateException(short errorNo)
			: base(Facility.Logging, errorNo)
		{
		}

		public NegativeUpdateRateException(short errorNo, string message)
			: base(Facility.Logging, errorNo, message)
		{
		}

		public NegativeUpdateRateException(short errorNo, string message, Exception inner)
			: base(Facility.Logging, errorNo, message, inner)
		{
		}
	}
	public class HTMLLogWriter : StreamedLogWriter
	{
		private enum Section
		{
			Start,
			Heading,
			Data,
			Footer
		}

		private Section section;

		public HTMLLogWriter(LoggingOptions options)
			: base(options)
		{
		}

		public override void WriteFileHeader()
		{
			if (section == Section.Data || section == Section.Heading)
			{
				base.Writer.Write("</table>");
			}
			section = Section.Heading;
			base.Writer.WriteLine("<tr>Log File Version :" + options.CustomLogHeader.LogHeader.NewLogHeaderRow().LogFileVersion + "</tr>");
			string text = DateTime.Now.ToShortDateString() + " " + DateTime.Now.ToLongTimeString();
			base.Writer.Write("<h3>" + text + "</h3>");
			switch (options.RecordingMode)
			{
			case RecordingModes.AnyDataReceived:
				base.Writer.WriteLine("<tr>Log Mode :Log When Any Data Received</tr>");
				break;
			case RecordingModes.AllDataReceived:
				base.Writer.WriteLine("<tr>Log Mode :Log When All Data Received</tr>");
				break;
			case RecordingModes.UserSpecifiedRate:
				base.Writer.WriteLine("<tr>Log Mode :Log At User Specified Rate</tr>");
				base.Writer.WriteLine("<tr>Logging Rate is :" + options.LogRate + "ms</tr>");
				break;
			}
			WriteCustomHeader();
			base.Writer.Write("<table border=\"1\">");
		}

		public override void WriteHeader(DataColumnCollection fields)
		{
			headerData.Names = "<th>Parameter Name</th>";
			headerData.Units = "<th>Units</th>";
			headerData.Addresses = "<th>Source Address</th>";
			DataColumn dataColumn = null;
			for (int i = 1; i < fields.Count; i++)
			{
				dataColumn = fields[i];
				if ((bool)dataColumn.ExtendedProperties["Active"])
				{
					headerData.Names += "<th>";
					headerData.Names += dataColumn.ExtendedProperties["displayName"];
					headerData.Names += "</th>";
					headerData.Units += "<th>";
					string text = dataColumn.ExtendedProperties["units"].ToString();
					if (text.Length != 0)
					{
						headerData.Units += text;
					}
					else
					{
						headerData.Units += "&nbsp";
					}
					headerData.Units += "</th>";
					headerData.Addresses += "<th>";
					string text2 = dataColumn.ExtendedProperties["address"].ToString();
					if (text2.Length != 0)
					{
						headerData.Addresses += text2;
					}
					else
					{
						headerData.Addresses += "&nbsp";
					}
					headerData.Addresses += text2;
					headerData.Addresses += "</th>";
				}
			}
			headerData.IsDirty = true;
		}

		public override void WriteUCLHeader(DataColumnCollection fields)
		{
			uclheaderData.Names = "<th>Parameter Name</th>";
			uclheaderData.Units = "<th>Units</th>";
			uclheaderData.Addresses = "<th>Source Address</th>";
			DataColumn dataColumn = null;
			for (int i = 1; i < fields.Count; i++)
			{
				dataColumn = fields[i];
				if ((bool)dataColumn.ExtendedProperties["Active"])
				{
					uclheaderData.Names += "<th>";
					uclheaderData.Names += dataColumn.ExtendedProperties["displayName"];
					uclheaderData.Names += "</th>";
					uclheaderData.Units += "<th>";
					string text = dataColumn.ExtendedProperties["units"].ToString();
					if (text.Length != 0)
					{
						uclheaderData.Units += text;
					}
					else
					{
						uclheaderData.Units += "&nbsp";
					}
					uclheaderData.Units += "</th>";
					uclheaderData.Addresses += "<th>";
					string text2 = dataColumn.ExtendedProperties["address"].ToString();
					if (text2.Length != 0)
					{
						uclheaderData.Addresses += text2;
					}
					else
					{
						uclheaderData.Addresses += "&nbsp";
					}
					uclheaderData.Addresses += text2;
					uclheaderData.Addresses += "</th>";
				}
			}
			uclheaderData.IsDirty = true;
		}

		public override void WriteData(DataTable values)
		{
			if (section == Section.Start)
			{
				WriteHeader(values.Columns);
			}
			if (headerData.IsDirty)
			{
				base.Writer.Write("<tr>" + headerData.Names + "</tr>");
				base.Writer.Write("<tr>" + headerData.Units + "</tr>");
				base.Writer.Write("<tr>" + headerData.Addresses + "</tr>");
				headerData.IsDirty = false;
			}
			section = Section.Data;
			foreach (DataRow row in values.Rows)
			{
				StringBuilder stringBuilder = new StringBuilder("<tr><td>&nbsp</td>");
				if ((bool)values.Columns["DLA Timestamp"].ExtendedProperties["Active"])
				{
					string value = "";
					if (row["DLA Timestamp"] != DBNull.Value)
					{
						value = FormatTime((uint)row["DLA Timestamp"]);
					}
					stringBuilder.Append("<td>");
					stringBuilder.Append(value);
					stringBuilder.Append("</td>");
				}
				for (int i = 2; i < values.Columns.Count; i++)
				{
					bool flag = (bool)values.Columns[i].ExtendedProperties["Active"];
					bool flag2 = (bool)values.Columns[i].ExtendedProperties["Removed"];
					if (flag)
					{
						stringBuilder.Append("<td>");
						if (row[i] != DBNull.Value)
						{
							stringBuilder.Append(row[i].ToString());
						}
						else if (!flag2)
						{
							stringBuilder.Append("NaN");
						}
						stringBuilder.Append("</td>");
					}
				}
				base.Writer.Write(stringBuilder.ToString());
			}
		}

		public override void WriteUCLData(DataTable values)
		{
			if (section == Section.Start)
			{
				WriteHeader(values.Columns);
			}
			if (uclheaderData.IsDirty)
			{
				base.Writer.Write("<tr>" + uclheaderData.Names + "</tr>");
				base.Writer.Write("<tr>" + uclheaderData.Units + "</tr>");
				base.Writer.Write("<tr>" + uclheaderData.Addresses + "</tr>");
				uclheaderData.IsDirty = false;
			}
			section = Section.Data;
			foreach (DataRow row in values.Rows)
			{
				StringBuilder stringBuilder = new StringBuilder("<tr><td>&nbsp</td>");
				if ((bool)values.Columns["DLA Timestamp"].ExtendedProperties["Active"])
				{
					string value = "";
					if (row["DLA Timestamp"] != DBNull.Value)
					{
						value = FormatTime((uint)row["DLA Timestamp"]);
					}
					stringBuilder.Append("<td>");
					stringBuilder.Append(value);
					stringBuilder.Append("</td>");
				}
				for (int i = 2; i < values.Columns.Count; i++)
				{
					bool flag = (bool)values.Columns[i].ExtendedProperties["Active"];
					bool flag2 = (bool)values.Columns[i].ExtendedProperties["Removed"];
					if (flag)
					{
						stringBuilder.Append("<td>");
						if (row[i] != DBNull.Value)
						{
							stringBuilder.Append(row[i].ToString());
						}
						else if (!flag2)
						{
							stringBuilder.Append("NaN");
						}
						stringBuilder.Append("</td>");
					}
				}
				base.Writer.Write(stringBuilder.ToString());
			}
		}

		public override void Close()
		{
			if (!base.Writer.Closed)
			{
				if (section == Section.Data || section == Section.Heading)
				{
					base.Writer.Write("</table>");
				}
				base.Writer.Write("</body></html>");
				base.Writer.Close();
			}
		}

		private void WriteCustomHeader()
		{
			if (options.HeaderNotes.Length > 0)
			{
				base.Writer.WriteLine("<tr>Notes:" + options.HeaderNotes + "</tr>");
			}
			if (options.CustomLogHeader.Parameters.Rows.Count <= 0)
			{
				return;
			}
			base.Writer.Write("<table border=\"1\">");
			base.Writer.Write("<tr>");
			base.Writer.Write("<th>Source Address</th>");
			base.Writer.Write("<th>Parameter Name</th>");
			base.Writer.Write("<th>Value</th>");
			base.Writer.Write("</tr>");
			foreach (CustomLogHeader.ParametersRow parameter in options.CustomLogHeader.Parameters)
			{
				base.Writer.Write("<tr>");
				base.Writer.Write("<th>" + parameter.DeviceAddress + "</th>");
				base.Writer.Write("<th>" + parameter.ParameterName + "</th>");
				base.Writer.Write("<th>" + options.GetParameterValue(parameter.DeviceAddress, parameter.ParameterName) + "</th>");
				base.Writer.Write("</tr>");
			}
			if (options.AddConfigNameToLogHeader)
			{
				base.Writer.Write("<tr>");
				base.Writer.Write("<th></th>");
				base.Writer.Write("<th>Config File Name</th>");
				base.Writer.Write("<th>" + options.ConfigFileName + "</th>");
				base.Writer.Write("</tr>");
			}
			base.Writer.Write("</table>");
			base.Writer.Write("<tr> </tr>");
		}
	}
	public delegate void LoggingStateChangedEventHandler(object caller, LoggingState state);
	public delegate void UCLoggingStateChangedEventHandler(object caller, UCLState ucLoggingState);
	public interface ILogger
	{
		ILoggerConfiguration Configuration { get; }

		LoggingState State { get; }

		IModuleNetwork Network { set; }

		Mode Mode { get; }

		Formats Format { get; set; }

		bool IsLogging { get; }

		bool DisplayLog { get; set; }

		bool LogActiveFaults { get; set; }

		string LogFileName { get; set; }

		DataAcquisitionType MonitorMode { get; set; }

		FaultsUpdateEventHandler FaultHandler { get; }

		int EDLRepeatsLeft { get; }

		int EDLTotalRepeats { get; }

		event LoggingStateChangedEventHandler LoggingStateChangeEvent;

		event UCLoggingStateChangedEventHandler UCLoggingStateChangeEvent;

		event LogFileSavingEventHandler LogFileSavingEvent;

		void Initialize();

		void Start();

		bool Stop();

		void Abort();

		void Add(string parameterName, string units, NetworkType networkType, IAddressValue address, bool isJ1939Data);

		void AddUCL(string parameterName, string units, NetworkType networkType, IAddressValue address, bool isJ1939Data);

		void Remove(string parameterName, string units, NetworkType networkType, IAddressValue address, bool isJ1939Data);

		void RemoveUCL(string parameterName, string units, NetworkType networkType, IAddressValue address, bool isJ1939Data);

		void Add(uint address, int offset, uint length, string units, IAddressValue sourceAddress, string displayName);

		void AddUCL(uint address, int offset, uint length, string units, IAddressValue sourceAddress, string displayName);

		void Add(ParameterListEventArgs parameterList);

		void AddUCL(ParameterListEventArgs parameterList);

		void Remove(IAddressValue deviceAddress);

		void RemoveUCL(IAddressValue deviceAddress);

		void Remove(uint address, int offset, uint length, IAddressValue sourceAddress);

		void RemoveUCL(uint address, int offset, uint length, IAddressValue sourceAddress);

		void RemoveAll();

		void RemoveAllUCL();

		void StartUCL();

		void StartUCLogging();

		void StopUCL();

		void RegisterDataProvider(IDataProvider dataProvider);

		void RegisterUCLDataProvider(IDataProvider dataProvider);

		void UnRegisterDataProvider(IDataProvider dataProvider);
	}
	public interface IEventDrivenLogger
	{
		bool CanConfigure { get; }

		void Configure();
	}
	public interface ILoggerConfiguration
	{
		DataAcquisitionType CurrentMode { get; set; }

		string LogFilePath { get; set; }

		string HeaderNotes { get; set; }

		string LogFilename { get; set; }

		string LogfilePrefix { get; }

		string PrefixRequestReceive { get; set; }

		string PrefixBAM { get; set; }

		string PrefixIDL { get; set; }

		RecordingModes RecordingMode { get; set; }

		Formats Format { get; set; }

		Mode Mode { get; set; }

		int FlushFrequency { get; set; }

		bool DisplayFreeSpace { get; set; }

		int MaxLogFileSize { get; set; }

		LoggingType LoggingType { get; }

		LoggingRateUnits LogRateUnit { get; set; }

		int LogRate { get; set; }

		CustomLogHeader CustomLogHeader { get; }

		bool LogPCTime { get; set; }

		bool EnableUCL_Logging { get; set; }

		bool LogDLASecondsTime { get; set; }

		bool ShouldLogInactiveFaults { get; set; }

		bool ShouldLogActiveFaults { get; set; }

		bool ShouldDisplayLogFile { get; set; }

		bool ShouldDisplayLogFileNameIn24hrTimeFormat { get; set; }

		bool ShouldDisplaySaveAsDialog { get; set; }

		bool IsAutoNumberingOn { get; set; }

		bool PromptForOverwrite { get; set; }

		bool DeleteOldestOnMediaFull { get; set; }

		bool ExportParamsOnStartup { get; set; }

		string InputFilterFilename { get; set; }

		string OutputExportFilename { get; set; }

		FileCreationChoice FileCreationChoice { get; set; }

		bool DisplayFaultFormat { get; set; }

		bool ShouldInsertEventNumber { get; set; }

		int UCLPreTriggerTime { get; set; }

		int UCLPostTriggerTime { get; set; }

		IModuleNetwork Network { get; set; }

		EventHandler LoggingOptionsChangedEvent { get; set; }

		EventHandler LogPCTimeStampOptionChanged { get; set; }

		EventHandler FaultsLoggingOptionChangedEvent { get; set; }

		EventHandler MonitorModeChangedEvent { get; set; }

		EventHandler CreateMiniLogFileEvent { get; set; }

		bool AddConfigNameToLogHeader { get; set; }

		void Initialize();

		void AddSpecialFileHeaderValue(string paramName, string paramValue);

		void RemoveSpecialFileHeader(string paramName);

		string GetParameterValue(string deviceAddress, string parameterName);

		void Save();

		string GetLogFileName();
	}
	public class LogController : IDisposable
	{
		internal const int DefaultEvaluteTimerRate = 1000;

		internal const int DefaultSweepTimerRate = 10000;

		internal const string Slash = "\\";

		public static bool debugFlag = false;

		public static bool startTimeflag = false;

		internal bool currentlySweeping;

		private LogModel model;

		private Timer sweepTimer;

		private Timer evaluateTimer;

		private DateTime loggingStartTime;

		public static DateTime ucloggingStartTime;

		private bool evaluating;

		private LogRecorder recorder;

		private IAppConfigService _appConfigService;

		private ArrayList registeredIdHolder = new ArrayList();

		private ArrayList _allRegisteredIds = new ArrayList();

		public LogSweptEventHandler LogSweptEvent;

		public UCLogSweptEventHandler UCLogSweptEvent;

		public LoggingOverEventHandler LoggingOverEvent;

		public UCLoggingOverEventHandler UCLoggingOverEvent;

		public LoggingState State
		{
			get
			{
				return Model.State;
			}
			set
			{
				switch (value)
				{
				case LoggingState.Idle:
					GoIdle();
					break;
				case LoggingState.Starting:
				case LoggingState.Stopping:
					Model.State = value;
					OnSweep(null);
					break;
				case LoggingState.Abort:
					Model.State = value;
					break;
				default:
					Model.State = value;
					break;
				}
			}
		}

		public UCLState UCLoggingState
		{
			get
			{
				return Model.UCLoggingState;
			}
			set
			{
				Model.UCLoggingState = value;
			}
		}

		public LogInstance logInstance
		{
			get
			{
				return Model.LoggingInstance;
			}
			set
			{
				Model.LoggingInstance = value;
			}
		}

		public LogModel Model => model;

		private bool Evaluating
		{
			get
			{
				return evaluating;
			}
			set
			{
				evaluating = value;
			}
		}

		public event LogFileSavingEventHandler LogFileSavingEvent;

		public event EventHandler LogFileSaveAbortedEvent;

		public event EventHandler UCLoggingOptionChangedEvent;

		public LogController(LogModel model)
		{
			this.model = model;
			model.MonitorListChangingEvent += OnMonitorListChanging;
			LoggingOptions options = model.Options;
			options.LoggingModeChanged = (EventHandler)Delegate.Combine(options.LoggingModeChanged, new EventHandler(OnLoggingModeChanged));
			_appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			evaluateTimer = new Timer(OnEvaluate, null, 1000, 1000);
			sweepTimer = new Timer(OnSweep, null, 10000, 10000);
		}

		~LogController()
		{
			if (Model.Mode == Mode.EventDriven)
			{
				State = LoggingState.Stopping;
			}
			else
			{
				Stop();
			}
		}

		public void Dispose()
		{
			sweepTimer = null;
			evaluateTimer = null;
			recorder = null;
		}

		public void RegisterDataProvider(IDataProvider dataProvider)
		{
			if (dataProvider == null)
			{
				throw new ArgumentNullException("dataProvider");
			}
			lock (registeredIdHolder)
			{
				if (registeredIdHolder.Contains(dataProvider.ID))
				{
					return;
				}
				bool flag = dataProvider is J1939_71BroadcastSubscription || dataProvider is J1939_71Subscription;
				if (!_allRegisteredIds.Contains(dataProvider.ID))
				{
					dataProvider.Notification += OnDataRefreshed;
					_allRegisteredIds.Add(dataProvider.ID);
				}
				if (!flag)
				{
					if (recorder != null)
					{
						recorder.Register(dataProvider.ID);
					}
					registeredIdHolder.Add(dataProvider.ID);
				}
			}
		}

		public void RegisterUCLDataProvider(IDataProvider dataProvider)
		{
			if (dataProvider == null)
			{
				throw new ArgumentNullException("dataProvider");
			}
			lock (registeredIdHolder)
			{
				if (registeredIdHolder.Contains(dataProvider.ID))
				{
					return;
				}
				bool flag = dataProvider is J1939_71BroadcastSubscription || dataProvider is J1939_71Subscription;
				if (!_allRegisteredIds.Contains(dataProvider.ID))
				{
					dataProvider.Notification += OnDataRefreshed;
					_allRegisteredIds.Add(dataProvider.ID);
				}
				if (!flag)
				{
					if (recorder != null)
					{
						recorder.Register(dataProvider.ID);
					}
					registeredIdHolder.Add(dataProvider.ID);
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
					if (recorder != null)
					{
						recorder.UnRegister(dataProvider.ID);
					}
					registeredIdHolder.Remove(dataProvider.ID);
				}
			}
		}

		public void Start()
		{
			try
			{
				Model.Mode = Mode.Manual;
				EventLogger.Info("Logging", "Attempting to start the Logger " + Model.Options.LogfilePrefix + ".");
				if (State != LoggingState.Logging)
				{
					State = LoggingState.Logging;
					EventLogger.Info("Logging", "Logger " + Model.Options.LogfilePrefix + " started.");
				}
			}
			catch (InsufficientDiskSpaceException)
			{
				EventLogger.Error("Logging", "The logging media has become full");
				Abort();
			}
			catch (Exception e)
			{
				EventLogger.Error("Logging", "Problem while starting logging.Double click for further details", e);
				Abort();
			}
		}

		public void OnLoggingStateChanged(object sender, LoggingState state)
		{
			if (state == LoggingState.Logging || state == LoggingState.Buffering)
			{
				if (recorder is TimerRecorder)
				{
					(recorder as TimerRecorder).Dispose();
				}
				switch (Model.Options.RecordingMode)
				{
				case RecordingModes.AllDataReceived:
					recorder = new AllRecorder(model, registeredIdHolder);
					break;
				case RecordingModes.UserSpecifiedRate:
					recorder = new TimerRecorder(model, registeredIdHolder, model.Options.LogRate);
					break;
				default:
					recorder = new AnyRecorder(model);
					break;
				}
			}
		}

		public bool Stop()
		{
			bool result = false;
			if (Model.LoggingInstance == LogInstance.Concurrent)
			{
				StopUCL();
			}
			if (Model.Mode == Mode.Manual)
			{
				if (State != LoggingState.Idle)
				{
					State = LoggingState.Idle;
					result = true;
					EventLogger.Info("Logging", "Logger " + Model.Options.LogfilePrefix + " stopped.");
					if (recorder is TimerRecorder)
					{
						(recorder as TimerRecorder).Dispose();
						lock (model.LogBuffer)
						{
							model.LogBuffer.Clear();
						}
						lock (model.UCLogBuffer)
						{
							model.UCLogBuffer.Clear();
						}
					}
				}
			}
			else if (State == LoggingState.Starting || State == LoggingState.Logging)
			{
				StopEventDrivenLogging();
				result = true;
				EventLogger.Info("Logging", "Logger " + Model.Options.LogfilePrefix + " stopped.");
			}
			return result;
		}

		public void Abort()
		{
			if (State != LoggingState.Idle)
			{
				State = LoggingState.Abort;
				EventLogger.Info("Logging", "Logger " + Model.Options.LogfilePrefix + " aborted.");
			}
		}

		public void Add(string parameterName, string units, NetworkType network, IAddressValue address, bool isJ1939Data)
		{
			Model.Add(parameterName, units, address, network, isJ1939Data);
		}

		public void AddUCL(string parameterName, string units, NetworkType network, IAddressValue address, bool isJ1939Data)
		{
			Model.AddUCL(parameterName, units, address, network, isJ1939Data);
		}

		public void Remove(string parameterName, string units, NetworkType network, IAddressValue address, bool isJ1939Data)
		{
			Model.Remove(parameterName, units, address, network, isJ1939Data);
		}

		public void RemoveUCL(string parameterName, string units, NetworkType network, IAddressValue address, bool isJ1939Data)
		{
			Model.RemoveUCL(parameterName, units, address, network, isJ1939Data);
		}

		public void Add(uint address, int offset, uint length, string units, IAddressValue sourceAddress, string displayName)
		{
			Model.Add(address, offset, length, units, sourceAddress, displayName);
		}

		public void AddUCL(uint address, int offset, uint length, string units, IAddressValue sourceAddress, string displayName)
		{
			Model.AddUCL(address, offset, length, units, sourceAddress, displayName);
		}

		public void Remove(uint address, int offset, uint length, IAddressValue sourceAddress)
		{
			Model.Remove(address, offset, length, sourceAddress);
		}

		public void RemoveUCL(uint address, int offset, uint length, IAddressValue sourceAddress)
		{
			Model.RemoveUCL(address, offset, length, sourceAddress);
		}

		public void RemoveAll()
		{
			Model.RemoveAllParameters();
		}

		public void RemoveAllUCL()
		{
			Model.RemoveAllParametersUCL();
		}

		public void Add(ParameterListEventArgs parameterList)
		{
			Model.Add(parameterList);
		}

		public void AddUCL(ParameterListEventArgs parameterList)
		{
			Model.AddUCL(parameterList);
		}

		public void Remove(IAddressValue deviceAddress)
		{
			Model.Remove(deviceAddress);
		}

		public void RemoveUCL(IAddressValue deviceAddress)
		{
			Model.RemoveUCL(deviceAddress);
		}

		public void OnDataRefreshed(object sender, DataRefreshEventArgs e)
		{
			if (State != LoggingState.Idle)
			{
				if (State == LoggingState.Buffering)
				{
					model.SetupFaultLogging();
					model.SetupUCLFaultLogging();
				}
				bool flag = bool.Parse(_appConfigService.GetAppSetting(ApplicationSettings.EnableUCL_Log));
				int num = 0;
				if (flag)
				{
					num = recorder.RecordUCLData(e);
				}
				int num2 = recorder.RecordData(e);
				if (num2 != -1 && num != -1)
				{
					Evaluate(flag);
				}
			}
		}

		public void StartUCL()
		{
			UCLoggingState = UCLState.Buffering;
		}

		public void StartUCLogging()
		{
			try
			{
				Model.LoggingInstance = LogInstance.Concurrent;
				UCLoggingState = UCLState.Active;
				try
				{
					lock (Model.UCLogBuffer)
					{
						if (Model.UCLogBuffer.Rows.Count > 0)
						{
							DeleteOldUCLRows();
							int num = Model.UCLogBuffer.Rows.Count - 1;
							_ = Model.UCLogBuffer.Rows[num];
							Model.UCLStartConditionTrueIndex = num;
							if (GlobalEventNumber.startTimeFlag)
							{
								ucloggingStartTime = DateTime.Now;
								GlobalEventNumber.startTimeFlag = false;
							}
							UCLoggingState = UCLState.Starting;
						}
					}
				}
				catch (Exception)
				{
				}
			}
			catch (InsufficientDiskSpaceException)
			{
				EventLogger.Error("Logging", "The logging media has become full");
				Abort();
			}
		}

		public void StopUCL()
		{
			try
			{
				if (Model.UCLogBuffer.Rows.Count > 0 && UCLoggingState == UCLState.Starting)
				{
					Mode mode = Model.Mode;
					int num = Model.UCLogBuffer.Rows.Count - 1;
					DataRow dataRow = Model.UCLogBuffer.Rows[num];
					Model.UCLStopConditionTrueIndex = (int)dataRow["index"];
					Model.UCLStopConditionTrueIndex = num;
					DataTable logTable = null;
					lock (Model.UCLogBuffer)
					{
						logTable = Model.UCLogBuffer.Copy();
					}
					RaiseUCLogSweptEvent(new UCLogSweptEventArgs(logTable));
					UCLoggingState = UCLState.Inactive;
					SaveLogFile(mode);
					RaiseUCLoggingOptionChangedEvent();
				}
				Model.LoggingInstance = LogInstance.Individual;
			}
			catch (Exception)
			{
			}
			finally
			{
				Model.Mode = Mode.Manual;
			}
		}

		protected void OnLoggingModeChanged(object sender, EventArgs e)
		{
			if (State == LoggingState.Logging || State == LoggingState.Buffering)
			{
				EventLogger.Warn("Logging", "Recording Mode Changed: Effect will take place from next session");
			}
			if (recorder is TimerRecorder)
			{
				(recorder as TimerRecorder).Dispose();
			}
			switch (Model.Options.RecordingMode)
			{
			case RecordingModes.AllDataReceived:
				lock (Model.LogBuffer)
				{
					Model.LogBuffer.Columns["DLA Timestamp"].ExtendedProperties["Removed"] = true;
				}
				lock (Model.UCLogBuffer)
				{
					Model.UCLogBuffer.Columns["DLA Timestamp"].ExtendedProperties["Removed"] = true;
					break;
				}
			case RecordingModes.UserSpecifiedRate:
				lock (Model.LogBuffer)
				{
					Model.LogBuffer.Columns["DLA Timestamp"].ExtendedProperties["Removed"] = true;
				}
				lock (Model.UCLogBuffer)
				{
					Model.UCLogBuffer.Columns["DLA Timestamp"].ExtendedProperties["Removed"] = true;
					break;
				}
			default:
				lock (Model.LogBuffer)
				{
					Model.LogBuffer.Columns["DLA Timestamp"].ExtendedProperties["Removed"] = false;
				}
				lock (Model.UCLogBuffer)
				{
					Model.UCLogBuffer.Columns["DLA Timestamp"].ExtendedProperties["Removed"] = false;
					break;
				}
			}
		}

		protected void OnSweep(object source)
		{
			bool flag = false;
			lock (this)
			{
				if (!currentlySweeping)
				{
					flag = (currentlySweeping = true);
				}
			}
			if (!flag)
			{
				return;
			}
			try
			{
				if (UCLoggingState != UCLState.Starting && UCLoggingState != UCLState.Active)
				{
					DeleteOldUCLRows();
				}
				if (UCLoggingState == UCLState.Buffering && !model.Options.EnableUCL_Logging)
				{
					lock (Model.UCLogBuffer)
					{
						Model.UCLStartConditionTrueIndex = -1;
					}
				}
				switch (State)
				{
				case LoggingState.Buffering:
					if (Model.TriggerOptions.PreTrigger != 0)
					{
						lock (Model.LogBuffer)
						{
							int count = Model.LogBuffer.Rows.Count;
							if (count > 0)
							{
								uint num = (uint)Model.LogBuffer.Rows[count - 1]["DLA Timestamp"];
								string filterCondition2 = "[DLA Timestamp] < " + (num - (uint)(Model.TriggerOptions.PreTrigger * 1000));
								DeleteRows(filterCondition2);
							}
							break;
						}
					}
					lock (Model.LogBuffer)
					{
						Model.LogBuffer.Clear();
						Model.StartConditionTrueIndex = -1;
						break;
					}
				case LoggingState.Starting:
					HandleSweepForStartingState();
					State = LoggingState.Logging;
					break;
				case LoggingState.Stopping:
				{
					if (Model.StartConditionTrueIndex != -1)
					{
						HandleSweepForStartingState();
					}
					string filterCondition = "index > " + Model.StopConditionTrueIndex;
					DeleteRows(filterCondition);
					State = LoggingState.Idle;
					break;
				}
				case LoggingState.Logging:
					SweepAll();
					break;
				}
			}
			catch (Exception)
			{
			}
			finally
			{
				lock (this)
				{
					currentlySweeping = false;
				}
			}
		}

		protected void OnEvaluate(object source)
		{
			try
			{
				bool enableUCL = bool.Parse(_appConfigService.GetAppSetting(ApplicationSettings.EnableUCL_Log));
				Evaluate(enableUCL);
			}
			catch (LoggingException)
			{
			}
		}

		protected void RaiseLogSweptEvent(LogSweptEventArgs e)
		{
			if (LogSweptEvent != null)
			{
				LogSweptEvent(this, e);
			}
		}

		protected void RaiseUCLogSweptEvent(UCLogSweptEventArgs e)
		{
			if (UCLogSweptEvent != null)
			{
				UCLogSweptEvent(this, e);
			}
		}

		protected void RaiseLogFileSavingEvent(LogFileSavingEventArgs e)
		{
			if (this.LogFileSavingEvent != null)
			{
				this.LogFileSavingEvent(this, e);
			}
		}

		protected void RaiseSaveAbortedEvent()
		{
			if (this.LogFileSaveAbortedEvent != null)
			{
				this.LogFileSaveAbortedEvent(this, EventArgs.Empty);
			}
		}

		protected void RaiseLoggingOverEvent(LoggingOverEventArgs e)
		{
			if (LoggingOverEvent != null)
			{
				LoggingOverEvent(this, e);
			}
		}

		protected void RaiseUCLoggingOverEvent(LoggingOverEventArgs e)
		{
			if (UCLoggingOverEvent != null)
			{
				UCLoggingOverEvent(this, e);
			}
		}

		private void HandleSweepForStartingState()
		{
			if (Model.TriggerOptions.PreTrigger != 0)
			{
				lock (Model.LogBuffer)
				{
					DataRow[] array = Model.LogBuffer.Select("index = " + Model.StartConditionTrueIndex);
					if (array.Length == 1)
					{
						string s = (string)array[0]["PC Timestamp"];
						DateTime dateTime = DateTime.Parse(s).Subtract(new TimeSpan(0, 0, 0, Model.TriggerOptions.PreTrigger));
						string text = $"{dateTime.Hour,2:D2}:{dateTime.Minute,2:D2}:{dateTime.Second,2:D2}.{dateTime.Millisecond:000}";
						string filterCondition = "[PC Timestamp] < '" + text + "'";
						DeleteRows(filterCondition);
					}
					return;
				}
			}
			lock (Model.LogBuffer)
			{
				string filterCondition2 = "index < " + Model.StartConditionTrueIndex;
				DeleteRows(filterCondition2);
			}
		}

		private void DeleteRows(string filterCondition)
		{
			DataRow[] array = Model.LogBuffer.Select(filterCondition);
			DataRow[] array2 = array;
			foreach (DataRow row in array2)
			{
				Model.LogBuffer.Rows.Remove(row);
			}
			Model.LogBuffer.AcceptChanges();
		}

		private void DeleteOldUCLRows()
		{
			try
			{
				lock (Model.UCLogBuffer)
				{
					if (Model.UCLogBuffer.Rows.Count <= 0)
					{
						return;
					}
					string empty = string.Empty;
					object obj = Model.UCLogBuffer.Rows[Model.UCLogBuffer.Rows.Count - 1]["DLA Timestamp"];
					if (obj != null && obj is int num)
					{
						empty = "[DLA Timestamp] < " + (num - Model.Options.UCLPreTriggerTime * 1000);
					}
					else
					{
						obj = Model.UCLogBuffer.Rows[Model.UCLogBuffer.Rows.Count - 1]["PC Timestamp"];
						DateTime dateTime = DateTime.Parse((string)obj).Subtract(new TimeSpan(0, 0, Model.Options.UCLPreTriggerTime));
						empty = "[PC Timestamp] < '" + $"{dateTime.Hour,2:D2}:{dateTime.Minute,2:D2}:{dateTime.Second,2:D2}.{dateTime.Millisecond:000}" + "'";
					}
					if (string.IsNullOrEmpty(empty))
					{
						return;
					}
					DataRow[] array = Model.UCLogBuffer.Select(empty);
					int num2 = 0;
					if (array.Length > 0)
					{
						num2 = Model.UCLogBuffer.Rows.IndexOf(array[^1]);
						if (num2 != -1)
						{
							for (int i = 0; i < num2; i++)
							{
								Model.UCLogBuffer.Rows.RemoveAt(0);
							}
						}
					}
					Model.UCLogBuffer.AcceptChanges();
				}
			}
			catch
			{
			}
		}

		private void Evaluate(bool enableUCL)
		{
			if (Model.Mode == Mode.EventDriven && !Evaluating)
			{
				lock (this)
				{
					try
					{
						Evaluating = true;
						if (State == LoggingState.Buffering && Model.TriggerOptions.StartTriggerSpecified)
						{
							lock (Model.LogBuffer)
							{
								if (Model.LogBuffer.Rows.Count > 0 && Model.StartTrigger.Evaluate())
								{
									StartEventDrivenLogging();
								}
							}
						}
						else if ((State == LoggingState.Starting || State == LoggingState.Logging) && Model.TriggerOptions.StopTriggerSpecified)
						{
							if (Model.TriggerOptions.StopTrigger.Length > 0)
							{
								lock (Model.LogBuffer)
								{
									if (Model.LogBuffer.Rows.Count > 0 && Model.StopTrigger.Evaluate())
									{
										StopEventDrivenLogging();
									}
								}
							}
							else
							{
								TimeSpan timeSpan = DateTime.Now - loggingStartTime;
								int num = timeSpan.Hours * 60 * 60 + timeSpan.Minutes * 60 + timeSpan.Seconds;
								if (num >= Model.TriggerOptions.PostTrigger)
								{
									StopEventDrivenLogging();
								}
							}
						}
						Evaluating = false;
						return;
					}
					catch (Exception)
					{
						return;
					}
					finally
					{
						Evaluating = false;
					}
				}
			}
			if (model.LoggingInstance != LogInstance.Concurrent || Evaluating || !enableUCL)
			{
				return;
			}
			lock (this)
			{
				try
				{
					Evaluating = true;
					if (UCLoggingState == UCLState.Starting)
					{
						if (model.Options.UCLPostTriggerTime > 0)
						{
							TimeSpan timeSpan2 = DateTime.Now - ucloggingStartTime;
							int num2 = timeSpan2.Hours * 60 * 60 + timeSpan2.Minutes * 60 + timeSpan2.Seconds;
							if (num2 >= Model.Options.UCLPostTriggerTime)
							{
								StopUCL();
							}
						}
						else
						{
							StopUCL();
						}
						Evaluating = false;
					}
					else if (UCLoggingState == UCLState.Inactive)
					{
						Evaluating = false;
					}
				}
				catch (Exception)
				{
				}
				finally
				{
					Evaluating = false;
				}
			}
		}

		private void StartEventDrivenLogging()
		{
			try
			{
				int index = Model.LogBuffer.Rows.Count - 1;
				DataRow dataRow = Model.LogBuffer.Rows[index];
				Model.StartConditionTrueIndex = (int)dataRow["index"];
				loggingStartTime = DateTime.Now;
				State = LoggingState.Starting;
			}
			catch (Exception)
			{
			}
		}

		private void StopEventDrivenLogging()
		{
			try
			{
				int index = Model.LogBuffer.Rows.Count - 1;
				DataRow dataRow = Model.LogBuffer.Rows[index];
				Model.StopConditionTrueIndex = (int)dataRow["index"];
				State = LoggingState.Stopping;
			}
			catch (Exception)
			{
			}
		}

		private void SweepAll()
		{
			try
			{
				DataTable dataTable = null;
				lock (Model.LogBuffer)
				{
					dataTable = Model.LogBuffer.Copy();
					Model.LogBuffer.Clear();
				}
				if (dataTable.Rows.Count > 0)
				{
					RaiseLogSweptEvent(new LogSweptEventArgs(dataTable));
				}
			}
			catch (InsufficientDiskSpaceException)
			{
				EventLogger.Error("Logging", "The logging media has become full");
				State = LoggingState.Error;
				Stop();
			}
		}

		protected virtual void RaiseUCLoggingOptionChangedEvent()
		{
			if (this.UCLoggingOptionChangedEvent != null)
			{
				this.UCLoggingOptionChangedEvent(this, EventArgs.Empty);
			}
		}

		private void GoIdle()
		{
			if (State != LoggingState.Idle && ((Model.Mode == Mode.Manual && State == LoggingState.Logging) || (Model.Mode == Mode.EventDriven && State == LoggingState.Stopping) || Model.State == LoggingState.Error))
			{
				Mode mode = Model.Mode;
				if (State != LoggingState.Error)
				{
					SweepAll();
				}
				Model.State = LoggingState.Idle;
				SaveLogFile(mode);
			}
		}

		private void SaveLogFile(Mode mode)
		{
			bool flag = false;
			string text;
			if (Model.LoggingInstance == LogInstance.Concurrent)
			{
				text = model.Options.GetUCLogFileName();
				flag = true;
			}
			else
			{
				text = model.Options.GetLogFileName();
			}
			if (mode == Mode.Manual && model.Options.FileCreationChoice == FileCreationChoice.Single && !flag)
			{
				LogFileSavingEventArgs e = new LogFileSavingEventArgs(text, model.Options);
				RaiseLogFileSavingEvent(e);
				if (!e.Cancel)
				{
					RaiseLoggingOverEvent(new LoggingOverEventArgs(e.LogFileName, e.FileFormat, model.Options.ShouldDisplayLogFile));
				}
				else
				{
					RaiseSaveAbortedEvent();
				}
			}
			else if (!flag)
			{
				RaiseLoggingOverEvent(new LoggingOverEventArgs(text, model.Options.Format, displayLogFile: false));
			}
			else if (flag)
			{
				RaiseUCLoggingOverEvent(new LoggingOverEventArgs(text, model.Options.Format, displayLogFile: false));
			}
		}

		private void OnMonitorListChanging(object sender, EventArgs e)
		{
			if (State == LoggingState.Logging)
			{
				SweepAll();
			}
		}

		private void OnStartTriggerChanged(object sender, EventArgs e)
		{
		}
	}
	public delegate void LogFileSavingEventHandler(object sender, LogFileSavingEventArgs e);
	public class LogFileSavingEventArgs : CancelEventArgs
	{
		private string logFileName;

		private ILoggerConfiguration options;

		private Formats fileFormat;

		public string LogFileName
		{
			get
			{
				return logFileName;
			}
			set
			{
				logFileName = value;
			}
		}

		public ILoggerConfiguration Options
		{
			get
			{
				return options;
			}
			set
			{
				options = value;
			}
		}

		public Formats FileFormat
		{
			get
			{
				return fileFormat;
			}
			set
			{
				fileFormat = value;
			}
		}

		public LogFileSavingEventArgs(string logFileName, ILoggerConfiguration options)
		{
			this.logFileName = logFileName;
			this.options = options;
			fileFormat = options.Format;
		}
	}
	public class Logging : Component, IPropertyPageProvider, ILogger, IEventDrivenLogger
	{
		private Container components;

		private LogModel model;

		private LogView view;

		private LogController controller;

		public ILoggerConfiguration Configuration => model.Options;

		public TriggerLoggingOptions TriggerConfiguration => model.TriggerOptions;

		public IModuleNetwork Network
		{
			set
			{
				model.Network = value;
			}
		}

		public FaultsUpdateEventHandler FaultHandler => model.OnFaultsUpdated;

		public LoggingState State => controller.State;

		public bool LogActiveFaults
		{
			get
			{
				return model.SuspendLoggingActiveFaults;
			}
			set
			{
				model.SuspendLoggingActiveFaults = value;
			}
		}

		public bool DisplayFaultFormat
		{
			get
			{
				return model.Options.DisplayFaultFormat;
			}
			set
			{
				model.Options.DisplayFaultFormat = value;
			}
		}

		public bool DisplayLog
		{
			get
			{
				return model.Options.ShouldDisplayLogFile;
			}
			set
			{
				model.Options.ShouldDisplayLogFile = value;
			}
		}

		public Formats Format
		{
			get
			{
				return model.Options.Format;
			}
			set
			{
				model.Options.Format = value;
			}
		}

		public bool LogDLASecondsTime
		{
			get
			{
				return model.Options.LogDLASecondsTime;
			}
			set
			{
				model.Options.LogDLASecondsTime = value;
			}
		}

		public bool IsLogging => model.State == LoggingState.Logging;

		public string LogFileName
		{
			get
			{
				return model.Options.GetLogFileName();
			}
			set
			{
				try
				{
					model.Options.LogFilePath = Path.GetDirectoryName(value);
					model.Options.LogFilename = Path.GetFileName(value);
					model.Options.IsAutoNumberingOn = false;
					model.Options.Save();
				}
				catch
				{
				}
			}
		}

		public DataAcquisitionType MonitorMode
		{
			get
			{
				return model.Options.CurrentMode;
			}
			set
			{
				model.Options.CurrentMode = value;
			}
		}

		public Mode Mode => model.Mode;

		public int EDLRepeatsLeft => model.EDLRepeatsLeft;

		public int EDLTotalRepeats => model.EDLTotalRepeats;

		public ArrayList Pages
		{
			get
			{
				LogPropertiesControl value = new LogPropertiesControl(model.Options, "", "Logging");
				CustomLogHeaderControl value2 = new CustomLogHeaderControl(model.Options, "", "Log Header");
				ArrayList arrayList = new ArrayList();
				arrayList.Add(value);
				arrayList.Add(value2);
				return arrayList;
			}
		}

		public bool CanConfigure
		{
			get
			{
				if (Mode != Mode.Manual && (Mode != Mode.EventDriven || model.State != LoggingState.Buffering))
				{
					if (Mode == Mode.EventDriven)
					{
						return model.State == LoggingState.Idle;
					}
					return false;
				}
				return true;
			}
		}

		public event LoggingStateChangedEventHandler LoggingStateChangeEvent;

		public event UCLoggingStateChangedEventHandler UCLoggingStateChangeEvent;

		public event EventHandler LoggingOptionsChangedEvent
		{
			add
			{
				LoggingOptions options = model.Options;
				options.LoggingOptionsChangedEvent = (EventHandler)Delegate.Combine(options.LoggingOptionsChangedEvent, value);
			}
			remove
			{
				LoggingOptions options = model.Options;
				options.LoggingOptionsChangedEvent = (EventHandler)Delegate.Remove(options.LoggingOptionsChangedEvent, value);
			}
		}

		public event LogFileSavingEventHandler LogFileSavingEvent
		{
			add
			{
				controller.LogFileSavingEvent += value;
			}
			remove
			{
				controller.LogFileSavingEvent -= value;
			}
		}

		public event EventHandler CreateMiniLogFileEvent
		{
			add
			{
				LoggingOptions options = model.Options;
				options.CreateMiniLogFileEvent = (EventHandler)Delegate.Combine(options.CreateMiniLogFileEvent, value);
			}
			remove
			{
				LoggingOptions options = model.Options;
				options.CreateMiniLogFileEvent = (EventHandler)Delegate.Remove(options.CreateMiniLogFileEvent, value);
			}
		}

		public event EventHandler UCLoggingOptionChangedEvent
		{
			add
			{
				controller.UCLoggingOptionChangedEvent += value;
			}
			remove
			{
				controller.UCLoggingOptionChangedEvent -= value;
			}
		}

		public Logging()
		{
			InitializeComponent();
			model = new LogModel();
			model.StateChangedEvent += OnStateChanged;
			model.UCLStateChangedEvent += OnUCLStateChanged;
			controller = new LogController(model);
			view = new LogView(model, controller);
			LoggingStateChangeEvent += controller.OnLoggingStateChanged;
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing)
			{
				if (components != null)
				{
					components.Dispose();
				}
				view = null;
				controller.Dispose();
				controller = null;
				model = null;
			}
			base.Dispose(disposing);
		}

		public void RegisterDataProvider(IDataProvider dataProvider)
		{
			controller.RegisterDataProvider(dataProvider);
		}

		public void RegisterUCLDataProvider(IDataProvider dataProvider)
		{
			controller.RegisterUCLDataProvider(dataProvider);
		}

		public void UnRegisterDataProvider(IDataProvider dataProvider)
		{
			controller.UnRegisterDataProvider(dataProvider);
		}

		public void Initialize()
		{
			InitializeInternals();
		}

		public void Start()
		{
			controller.Start();
		}

		public bool Stop()
		{
			return controller.Stop();
		}

		public void Abort()
		{
			controller.Abort();
		}

		public void Add(string parameterName, string units, NetworkType network, IAddressValue address, bool isJ1939Data)
		{
			controller.Add(parameterName, units, network, address, isJ1939Data);
		}

		public void AddUCL(string parameterName, string units, NetworkType network, IAddressValue address, bool isJ1939Data)
		{
			controller.AddUCL(parameterName, units, network, address, isJ1939Data);
		}

		public void Remove(string parameterName, string units, NetworkType network, IAddressValue address, bool isJ1939Data)
		{
			controller.Remove(parameterName, units, network, address, isJ1939Data);
		}

		public void RemoveUCL(string parameterName, string units, NetworkType network, IAddressValue address, bool isJ1939Data)
		{
			controller.RemoveUCL(parameterName, units, network, address, isJ1939Data);
		}

		public void Add(uint address, int offset, uint length, string units, IAddressValue sourceAddress, string displayName)
		{
			controller.Add(address, offset, length, units, sourceAddress, displayName);
		}

		public void AddUCL(uint address, int offset, uint length, string units, IAddressValue sourceAddress, string displayName)
		{
			controller.AddUCL(address, offset, length, units, sourceAddress, displayName);
		}

		public void Remove(uint address, int offset, uint length, IAddressValue sourceAddress)
		{
			controller.Remove(address, offset, length, sourceAddress);
		}

		public void RemoveUCL(uint address, int offset, uint length, IAddressValue sourceAddress)
		{
			controller.RemoveUCL(address, offset, length, sourceAddress);
		}

		public void RemoveAll()
		{
			controller.RemoveAll();
		}

		public void RemoveAllUCL()
		{
			controller.RemoveAllUCL();
		}

		public void Add(ParameterListEventArgs parameterList)
		{
			controller.Add(parameterList);
		}

		public void AddUCL(ParameterListEventArgs parameterList)
		{
			controller.AddUCL(parameterList);
		}

		public void Remove(IAddressValue deviceAddress)
		{
			controller.Remove(deviceAddress);
		}

		public void RemoveUCL(IAddressValue deviceAddress)
		{
			controller.RemoveUCL(deviceAddress);
		}

		public void StartUCL()
		{
			controller.StartUCL();
		}

		public void StartUCLogging()
		{
			controller.StartUCLogging();
		}

		public void StopUCL()
		{
			controller.StopUCL();
		}

		public void Configure()
		{
			//IL_0025: Unknown result type (might be due to invalid IL or missing references)
			//IL_002b: Invalid comparison between Unknown and I4
			if (!CanConfigure)
			{
				throw new InvalidOperationException("Event driven logging is not configurable at the moment");
			}
			TriggerConfigurationDlg triggerConfigurationDlg = new TriggerConfigurationDlg(model.TriggerOptions);
			if ((int)((Form)triggerConfigurationDlg).ShowDialog() == 1)
			{
				triggerConfigurationDlg.DoDataExchange();
			}
		}

		private void InitializeInternals()
		{
			model.Initialize();
		}

		private void OnStateChanged(object sender, StateChangeEventArgs e)
		{
			if (this.LoggingStateChangeEvent != null)
			{
				this.LoggingStateChangeEvent(this, e.NewState);
			}
		}

		private void OnUCLStateChanged(object sender, UCLStateChangeEventArgs e)
		{
			if (this.UCLoggingStateChangeEvent != null)
			{
				this.UCLoggingStateChangeEvent(this, e.NewState);
			}
		}

		private void InitializeComponent()
		{
			components = new Container();
		}
	}
	public class LoggingOptions : ILoggerConfiguration
	{
		internal const int DefaultMaxFileSize = 1024;

		internal const int MinLogFileSize = 10;

		internal const int DefaultFlushFrequency = 60;

		internal const string Slash = "\\";

		internal const string DefaultLogFileName = "data.log";

		internal const string CustomLogheaderFileName = "CustomLogHeader.xml";

		internal const string CustomLogHeaderSchema = "Cummins.Logging.OptionalLogHeader.xsd";

		private const string SpecialHeaderFilter = "DeviceAddress = '' AND ParameterName = '{0}'";

		internal const char ReturnChar = '\r';

		internal const char Newline = '\n';

		internal const int MinTriggerTime = 0;

		internal const int MaxTriggerTime = 60;

		internal const int DefaultTriggerTime = 30;

		private char[] illegalChars = new char[8] { '\\', '/', ':', '*', '?', '>', '<', '|' };

		private string prefixRR;

		private string prefixBAM;

		private string prefixIDL;

		private Formats format;

		private LoggingRateUnits logRateUnit;

		private LoggingType loggingType;

		private Mode mode;

		private RecordingModes recordingMode;

		private int logRate;

		private int flushFrequency = 60;

		private bool displayFreeSpace;

		private FileCreationChoice fileCreationChoice;

		private int maxLogFileSize = 1024;

		private string logFilePath = string.Empty;

		private bool logActiveFaults;

		private bool logInactiveFaults;

		private bool logPCTime;

		private bool faultDisplayMode;

		private bool displayLogFile;

		private bool dlaSecondsTimestamp;

		private bool shouldDisplaySaveAsDialog;

		private bool shouldDisplayLogFileNameIn24hrTimeFormat;

		private bool autoNumbering;

		private bool overWrite;

		private bool promptForOverwrite;

		private bool deleteOldestOnMediaFull = true;

		private bool exportParamsOnStartup;

		private string inputFilterFilename;

		private string outputExportFilename;

		private string filename;

		private CustomLogHeader customLogHeader;

		private string customHeaderNote = string.Empty;

		private bool includeLogFileVersion;

		private SortedList specialHeaderValues = new SortedList();

		private IModuleNetwork network;

		private DataAcquisitionType currentMode;

		private EventHandler loggingOptionsChangedEvent;

		private EventHandler faultsLoggingOptionChangedEvent;

		private EventHandler logPCTimeStampOptionChanged;

		private EventHandler monitorModeChangedEvent;

		private EventHandler loggingModeChanged;

		private bool insertEventNumber;

		private int uclpreTriggerTime = 30;

		private int uclpostTriggerTime = 30;

		private EventHandler createMiniLogFileEvent;

		private bool _enableUCL_logging;

		private bool _addConfigNameToLogHeader;

		private string _configFileName = string.Empty;

		public string ConfigFileName
		{
			get
			{
				return _configFileName;
			}
			set
			{
				_configFileName = value;
			}
		}

		public bool EnableUCL_Logging
		{
			get
			{
				return _enableUCL_logging;
			}
			set
			{
				_enableUCL_logging = value;
			}
		}

		public DataAcquisitionType CurrentMode
		{
			get
			{
				return currentMode;
			}
			set
			{
				if (currentMode != value)
				{
					currentMode = value;
					RaiseMonitorModeChangedEvent();
				}
			}
		}

		public RecordingModes RecordingMode
		{
			get
			{
				return recordingMode;
			}
			set
			{
				if (recordingMode != value)
				{
					recordingMode = value;
					RaiseLoggingModeChanged();
				}
			}
		}

		public int LogRate
		{
			get
			{
				return logRate;
			}
			set
			{
				logRate = value;
			}
		}

		public LoggingRateUnits LogRateUnit
		{
			get
			{
				return logRateUnit;
			}
			set
			{
				logRateUnit = value;
			}
		}

		public string LogFilePath
		{
			get
			{
				return logFilePath;
			}
			set
			{
				if (value == null)
				{
					logFilePath = string.Empty;
				}
				else if (value != LogFilePath)
				{
					logFilePath = value;
				}
			}
		}

		public string HeaderNotes
		{
			get
			{
				return customHeaderNote;
			}
			set
			{
				customHeaderNote = value;
			}
		}

		public CustomLogHeader CustomLogHeader
		{
			get
			{
				if (customLogHeader == null)
				{
					customLogHeader = new CustomLogHeader();
					IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
					string text = directoryService.RootDirectory;
					if (!text.EndsWith("\\"))
					{
						text += "\\";
					}
					if (File.Exists(text + "CustomLogHeader.xml"))
					{
						customLogHeader.ReadXml(text + "CustomLogHeader.xml");
						foreach (CustomLogHeader.ParametersRow parameter in customLogHeader.Parameters)
						{
							parameter.DeviceAddress = parameter.DeviceAddress.Replace('\n', ' ');
							parameter.DeviceAddress = parameter.DeviceAddress.Replace('\r', ' ');
							parameter.DeviceAddress = parameter.DeviceAddress.Trim();
							parameter.ParameterName = parameter.ParameterName.Replace('\n', ' ');
							parameter.ParameterName = parameter.ParameterName.Replace('\r', ' ');
							parameter.ParameterName = parameter.ParameterName.Trim();
						}
					}
					if (customLogHeader.LogHeader.Rows.Count == 0)
					{
						customLogHeader.LogHeader.Rows.Add(customLogHeader.LogHeader.NewLogHeaderRow());
						customLogHeader.AcceptChanges();
					}
				}
				return customLogHeader;
			}
		}

		public string LogFilename
		{
			get
			{
				return filename;
			}
			set
			{
				if (value == null)
				{
					filename = string.Empty;
				}
				else if (filename != value)
				{
					filename = value;
				}
			}
		}

		public string LogfilePrefix
		{
			get
			{
				string text = "";
				return CurrentMode switch
				{
					DataAcquisitionType.IDL => PrefixIDL, 
					DataAcquisitionType.BAM => PrefixBAM, 
					_ => PrefixRequestReceive, 
				};
			}
		}

		public string PrefixRequestReceive
		{
			get
			{
				return prefixRR;
			}
			set
			{
				if (value == null || value.Length == 0)
				{
					prefixRR = Prefix.monitor.ToString();
				}
				else
				{
					prefixRR = value;
				}
			}
		}

		public string PrefixBAM
		{
			get
			{
				return prefixBAM;
			}
			set
			{
				if (value == null || value.Length == 0)
				{
					prefixBAM = Prefix.bam.ToString();
				}
				else
				{
					prefixBAM = value;
				}
			}
		}

		public string PrefixIDL
		{
			get
			{
				return prefixIDL;
			}
			set
			{
				if (value == null || value.Length == 0)
				{
					prefixIDL = Prefix.idl.ToString();
				}
				else
				{
					prefixIDL = value;
				}
			}
		}

		public Formats Format
		{
			get
			{
				return format;
			}
			set
			{
				format = value;
			}
		}

		public Mode Mode
		{
			get
			{
				return mode;
			}
			set
			{
				mode = value;
			}
		}

		public int FlushFrequency
		{
			get
			{
				return flushFrequency;
			}
			set
			{
				flushFrequency = value;
			}
		}

		public bool DisplayFreeSpace
		{
			get
			{
				return displayFreeSpace;
			}
			set
			{
				displayFreeSpace = value;
			}
		}

		public int MaxLogFileSize
		{
			get
			{
				return maxLogFileSize;
			}
			set
			{
				if (value < 10)
				{
					maxLogFileSize = 10;
				}
				else
				{
					maxLogFileSize = value;
				}
			}
		}

		public int UCLPreTriggerTime
		{
			get
			{
				return uclpreTriggerTime;
			}
			set
			{
				if (value < 0)
				{
					uclpreTriggerTime = 0;
				}
				else if (value > 60)
				{
					uclpreTriggerTime = 60;
				}
				else
				{
					uclpreTriggerTime = value;
				}
			}
		}

		public int UCLPostTriggerTime
		{
			get
			{
				return uclpostTriggerTime;
			}
			set
			{
				if (value < 0)
				{
					uclpostTriggerTime = 0;
				}
				else if (value > 60)
				{
					uclpostTriggerTime = 60;
				}
				else
				{
					uclpostTriggerTime = value;
				}
			}
		}

		public LoggingType LoggingType
		{
			get
			{
				switch (CurrentMode)
				{
				case DataAcquisitionType.IDL:
					loggingType = LoggingType.IDL;
					break;
				case DataAcquisitionType.BAM:
					loggingType = LoggingType.BAM;
					break;
				default:
					loggingType = LoggingType.Monitor;
					break;
				}
				return loggingType;
			}
		}

		public bool LogPCTime
		{
			get
			{
				return logPCTime;
			}
			set
			{
				if (logPCTime != value)
				{
					logPCTime = value;
				}
			}
		}

		public bool ShouldLogActiveFaults
		{
			get
			{
				return logActiveFaults;
			}
			set
			{
				logActiveFaults = value;
			}
		}

		public bool ShouldLogInactiveFaults
		{
			get
			{
				return logInactiveFaults;
			}
			set
			{
				logInactiveFaults = value;
			}
		}

		public bool LogDLASecondsTime
		{
			get
			{
				return dlaSecondsTimestamp;
			}
			set
			{
				dlaSecondsTimestamp = value;
			}
		}

		public bool ShouldDisplayLogFile
		{
			get
			{
				return displayLogFile;
			}
			set
			{
				displayLogFile = value;
			}
		}

		public bool ShouldDisplayLogFileNameIn24hrTimeFormat
		{
			get
			{
				return shouldDisplayLogFileNameIn24hrTimeFormat;
			}
			set
			{
				shouldDisplayLogFileNameIn24hrTimeFormat = value;
			}
		}

		public bool ShouldDisplaySaveAsDialog
		{
			get
			{
				return shouldDisplaySaveAsDialog;
			}
			set
			{
				shouldDisplaySaveAsDialog = value;
			}
		}

		public bool IsAutoNumberingOn
		{
			get
			{
				return autoNumbering;
			}
			set
			{
				autoNumbering = value;
				overWrite = !autoNumbering;
			}
		}

		public bool PromptForOverwrite
		{
			get
			{
				return promptForOverwrite;
			}
			set
			{
				promptForOverwrite = value;
			}
		}

		public bool DeleteOldestOnMediaFull
		{
			get
			{
				return deleteOldestOnMediaFull;
			}
			set
			{
				if (value != deleteOldestOnMediaFull)
				{
					deleteOldestOnMediaFull = value;
					RaiseMediafullCheckChangedEvent();
				}
			}
		}

		public bool ExportParamsOnStartup
		{
			get
			{
				return exportParamsOnStartup;
			}
			set
			{
				exportParamsOnStartup = value;
			}
		}

		public string InputFilterFilename
		{
			get
			{
				return inputFilterFilename;
			}
			set
			{
				inputFilterFilename = value;
			}
		}

		public string OutputExportFilename
		{
			get
			{
				return outputExportFilename;
			}
			set
			{
				outputExportFilename = value;
			}
		}

		public bool ShouldInsertEventNumber
		{
			get
			{
				return insertEventNumber;
			}
			set
			{
				insertEventNumber = value;
			}
		}

		public FileCreationChoice FileCreationChoice
		{
			get
			{
				return fileCreationChoice;
			}
			set
			{
				fileCreationChoice = value;
			}
		}

		public bool DisplayFaultFormat
		{
			get
			{
				return faultDisplayMode;
			}
			set
			{
				faultDisplayMode = value;
			}
		}

		public IModuleNetwork Network
		{
			get
			{
				return network;
			}
			set
			{
				network = value;
			}
		}

		public EventHandler LoggingOptionsChangedEvent
		{
			get
			{
				return loggingOptionsChangedEvent;
			}
			set
			{
				loggingOptionsChangedEvent = value;
			}
		}

		public EventHandler LogPCTimeStampOptionChanged
		{
			get
			{
				return logPCTimeStampOptionChanged;
			}
			set
			{
				logPCTimeStampOptionChanged = value;
			}
		}

		public EventHandler FaultsLoggingOptionChangedEvent
		{
			get
			{
				return faultsLoggingOptionChangedEvent;
			}
			set
			{
				faultsLoggingOptionChangedEvent = value;
			}
		}

		public EventHandler MonitorModeChangedEvent
		{
			get
			{
				return monitorModeChangedEvent;
			}
			set
			{
				monitorModeChangedEvent = value;
			}
		}

		public EventHandler LoggingModeChanged
		{
			get
			{
				return loggingModeChanged;
			}
			set
			{
				loggingModeChanged = value;
			}
		}

		public EventHandler CreateMiniLogFileEvent
		{
			get
			{
				return createMiniLogFileEvent;
			}
			set
			{
				createMiniLogFileEvent = value;
			}
		}

		public bool AddConfigNameToLogHeader
		{
			get
			{
				return _addConfigNameToLogHeader;
			}
			set
			{
				_addConfigNameToLogHeader = value;
			}
		}

		public event EventHandler MediafullCheckChangedEvent;

		public LoggingOptions()
		{
			ShouldLogActiveFaults = false;
			LogPCTime = false;
			PrefixRequestReceive = LoggingType.Monitor.ToString().ToLower();
			PrefixBAM = LoggingType.BAM.ToString().ToLower();
			PrefixIDL = LoggingType.IDL.ToString().ToLower();
			format = Formats.CSV;
			displayLogFile = false;
			autoNumbering = true;
			shouldDisplaySaveAsDialog = true;
			dlaSecondsTimestamp = false;
			shouldDisplayLogFileNameIn24hrTimeFormat = false;
			LogFilePath = string.Empty;
			flushFrequency = 60;
			MaxLogFileSize = 1024;
			FileCreationChoice = FileCreationChoice.Single;
			promptForOverwrite = false;
			LogFilename = "data.log";
			loggingType = LoggingType.Monitor;
			_enableUCL_logging = false;
			insertEventNumber = false;
			UCLPreTriggerTime = 30;
			UCLPostTriggerTime = 30;
		}

		public void Initialize()
		{
			_ = Enum.GetValues(typeof(LoggingType)).Length;
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			if (appConfigService != null)
			{
				try
				{
					LogPCTime = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.LogPCTime));
				}
				catch
				{
				}
				try
				{
					ShouldLogActiveFaults = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.LogActiveFaults));
				}
				catch
				{
				}
				try
				{
					PrefixRequestReceive = appConfigService.GetAppSetting(ApplicationSettings.LogPrefixRR);
				}
				catch
				{
				}
				try
				{
					PrefixBAM = appConfigService.GetAppSetting(ApplicationSettings.LogPrefixBAM);
				}
				catch
				{
				}
				try
				{
					PrefixIDL = appConfigService.GetAppSetting(ApplicationSettings.LogPrefixIDL);
				}
				catch
				{
				}
				try
				{
					format = (Formats)Enum.Parse(typeof(Formats), appConfigService.GetAppSetting(ApplicationSettings.LogFormat));
				}
				catch
				{
				}
				try
				{
					displayLogFile = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.LogDisplay));
				}
				catch
				{
				}
				try
				{
					dlaSecondsTimestamp = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.LogDLASecondsTime));
				}
				catch
				{
				}
				try
				{
					autoNumbering = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.MonitorLogAutoNumbering));
				}
				catch
				{
				}
				try
				{
					shouldDisplaySaveAsDialog = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.DisplaySaveFileDialog));
				}
				catch
				{
				}
				try
				{
					shouldDisplayLogFileNameIn24hrTimeFormat = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.LogFileNameIn24hrTimeFormat));
				}
				catch
				{
				}
				try
				{
					LogFilePath = appConfigService.GetAppSetting(ApplicationSettings.LogFilePath);
				}
				catch
				{
				}
				try
				{
					flushFrequency = int.Parse(appConfigService.GetAppSetting(ApplicationSettings.LogFlushFrequency));
				}
				catch
				{
				}
				try
				{
					MaxLogFileSize = int.Parse(appConfigService.GetAppSetting(ApplicationSettings.MaxLogFileSize));
				}
				catch
				{
				}
				try
				{
					FileCreationChoice = (FileCreationChoice)Enum.Parse(typeof(FileCreationChoice), appConfigService.GetAppSetting(ApplicationSettings.LogFileCreationChoice), ignoreCase: true);
				}
				catch
				{
				}
				try
				{
					promptForOverwrite = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.PromptForOverwrite));
				}
				catch
				{
				}
				try
				{
					deleteOldestOnMediaFull = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.DeleteOldestOnMediaFull));
				}
				catch
				{
					appConfigService.SetAppSetting(ApplicationSettings.DeleteOldestOnMediaFull, bool.TrueString);
				}
				try
				{
					ExportParamsOnStartup = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.ExportParamsOnStartup));
				}
				catch
				{
					appConfigService.SetAppSetting(ApplicationSettings.ExportParamsOnStartup, bool.FalseString);
				}
				try
				{
					InputFilterFilename = appConfigService.GetAppSetting(ApplicationSettings.InputFilterFilename);
				}
				catch
				{
					appConfigService.SetAppSetting(ApplicationSettings.InputFilterFilename, string.Empty);
				}
				try
				{
					OutputExportFilename = appConfigService.GetAppSetting(ApplicationSettings.OutputExportFilename);
				}
				catch
				{
					appConfigService.SetAppSetting(ApplicationSettings.OutputExportFilename, string.Empty);
				}
				try
				{
					LogFilename = appConfigService.GetAppSetting(ApplicationSettings.LogFileName);
				}
				catch
				{
				}
				try
				{
					LogRate = int.Parse(appConfigService.GetAppSetting(ApplicationSettings.LogRate));
					if (LogRate < 1)
					{
						LogRate = 1;
					}
				}
				catch
				{
				}
				try
				{
					RecordingMode = (RecordingModes)Enum.Parse(typeof(RecordingModes), appConfigService.GetAppSetting(ApplicationSettings.RecordingMode));
				}
				catch
				{
				}
				try
				{
					LogRateUnit = (LoggingRateUnits)Enum.Parse(typeof(LoggingRateUnits), appConfigService.GetAppSetting(ApplicationSettings.LogRateUnit));
				}
				catch
				{
				}
				try
				{
					EnableUCL_Logging = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.EnableUCL_Log));
				}
				catch
				{
				}
				try
				{
					insertEventNumber = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.InsertEventNumber));
				}
				catch
				{
				}
				try
				{
					UCLPreTriggerTime = int.Parse(appConfigService.GetAppSetting(ApplicationSettings.UCLPreTriggerTime));
				}
				catch
				{
				}
				try
				{
					UCLPostTriggerTime = int.Parse(appConfigService.GetAppSetting(ApplicationSettings.UCLPostTriggerTime));
				}
				catch
				{
				}
				try
				{
					string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
					ConfigFileName = appConfigService.GetLastUsedValue(appSetting, LastUsedType.LastConfigurationFile);
				}
				catch
				{
				}
				try
				{
					AddConfigNameToLogHeader = bool.Parse(appConfigService.GetAppSetting(ApplicationSettings.ChkboxConfigNameToHeaderChecked));
				}
				catch
				{
					AddConfigNameToLogHeader = false;
				}
				RaiseLoggingOptionsChangedEvent();
				RaiseCreateMiniLogFileEvent();
			}
			try
			{
				HeaderNotes = ((CustomLogHeader.LogHeaderRow)CustomLogHeader.LogHeader.Rows[0]).Notes;
			}
			catch
			{
			}
		}

		public void Save()
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			if (appConfigService != null)
			{
				appConfigService.SetAppSetting(ApplicationSettings.LogActiveFaults, ShouldLogActiveFaults.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.LogPCTime, LogPCTime.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.LogPrefixRR, PrefixRequestReceive);
				appConfigService.SetAppSetting(ApplicationSettings.LogPrefixBAM, PrefixBAM);
				appConfigService.SetAppSetting(ApplicationSettings.LogPrefixIDL, PrefixIDL);
				appConfigService.SetAppSetting(ApplicationSettings.LogFormat, Format.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.LogDisplay, ShouldDisplayLogFile.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.MonitorLogAutoNumbering, IsAutoNumberingOn.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.DisplaySaveFileDialog, ShouldDisplaySaveAsDialog.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.LogFileNameIn24hrTimeFormat, ShouldDisplayLogFileNameIn24hrTimeFormat.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.MaxLogFileSize, MaxLogFileSize.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.LogFilePath, LogFilePath.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.LogFileName, LogFilename.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.LogFlushFrequency, FlushFrequency.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.LogFileCreationChoice, FileCreationChoice.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.PromptForOverwrite, PromptForOverwrite.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.PromptForMediaFull, DeleteOldestOnMediaFull.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.LogRate, LogRate.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.RecordingMode, RecordingMode.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.LogRateUnit, LogRateUnit.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.LogDLASecondsTime, LogDLASecondsTime.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.ExportParamsOnStartup, ExportParamsOnStartup.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.InputFilterFilename, InputFilterFilename);
				appConfigService.SetAppSetting(ApplicationSettings.OutputExportFilename, OutputExportFilename);
				appConfigService.SetAppSetting(ApplicationSettings.EnableUCL_Log, EnableUCL_Logging.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.InsertEventNumber, ShouldInsertEventNumber.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.UCLPreTriggerTime, UCLPreTriggerTime.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.UCLPostTriggerTime, UCLPostTriggerTime.ToString());
				appConfigService.SetAppSetting(ApplicationSettings.ChkboxConfigNameToHeaderChecked, AddConfigNameToLogHeader.ToString());
				((CustomLogHeader.LogHeaderRow)customLogHeader.LogHeader.Rows[0]).Notes = HeaderNotes;
				_ = EnableUCL_Logging;
				IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
				string text = directoryService.RootDirectory;
				if (!text.EndsWith("\\"))
				{
					text += "\\";
				}
				customLogHeader.WriteXml(text + "CustomLogHeader.xml");
				RaiseLoggingOptionsChangedEvent();
				RaiseCreateMiniLogFileEvent();
			}
		}

		public string GetLogFileName()
		{
			string empty = string.Empty;
			if (LogFilePath.Length == 0)
			{
				IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
				string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
				IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
				empty = directoryService.FolderName(FolderType.Product, appSetting);
			}
			else
			{
				empty = LogFilePath;
			}
			if (!empty.EndsWith("\\"))
			{
				empty += "\\";
			}
			string prefix = ReplaceIllegalFileCharacters(LogfilePrefix);
			if (IsAutoNumberingOn || FileCreationChoice == FileCreationChoice.Multiple)
			{
				return empty + Utility.AvailableFilename(prefix, "", ".log." + Format.ToString().ToLower(), empty);
			}
			if (LogFilename.Length > 0)
			{
				if (Path.GetExtension(LogFilename).Length == 0)
				{
					return empty + LogFilename + ".log." + Format.ToString().ToLower();
				}
				return empty + LogFilename;
			}
			return empty + Utility.AvailableFilename(prefix, "", ".log." + Format.ToString().ToLower(), empty);
		}

		public string GetUCLogFileName()
		{
			string empty = string.Empty;
			if (LogFilePath.Length == 0)
			{
				IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
				string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
				IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
				empty = directoryService.FolderName(FolderType.Product, appSetting);
			}
			else
			{
				empty = LogFilePath;
			}
			if (!empty.EndsWith("\\"))
			{
				empty += "\\";
			}
			string prefix = ReplaceIllegalFileCharacters(LogfilePrefix);
			string text = ((GlobalEventNumber.currentEventNumber < 10) ? ("000" + GlobalEventNumber.currentEventNumber) : ((GlobalEventNumber.currentEventNumber < 100) ? ("00" + GlobalEventNumber.currentEventNumber) : ((GlobalEventNumber.currentEventNumber >= 100) ? GlobalEventNumber.currentEventNumber.ToString() : ("0" + GlobalEventNumber.currentEventNumber))));
			return empty + Utility.AvailableFilename(prefix, " UserEvent" + text, ".log." + Format.ToString().ToLower(), empty);
		}

		public string GetParameterValue(string deviceAddress, string parameterName)
		{
			string result = string.Empty;
			try
			{
				if (deviceAddress == "")
				{
					return specialHeaderValues[parameterName].ToString();
				}
				IAddressValue addressValue = AddressFactory.ProductAddressValue(deviceAddress);
				if (Network.Modules[addressValue] != null)
				{
					ICalibrationOnline calibration = Network.GetCalibration(addressValue);
					IParameterSpecification specification = calibration.GetSpecification(parameterName);
					if (specification.Type != AccessModeType.Invalid)
					{
						IValueModel valueModel = (IValueModel)calibration.FuzzyGet(specification.Name);
						result = valueModel.ScaledValue;
					}
				}
			}
			catch (Exception)
			{
			}
			return result;
		}

		public void AddSpecialFileHeaderValue(string paramName, string paramValue)
		{
			if (paramName == null)
			{
				throw new ArgumentNullException("paramName", "paramName can't be null");
			}
			if (paramValue == null)
			{
				throw new ArgumentNullException("paramName", "paramName can't be null");
			}
			string filterExpression = $"DeviceAddress = '' AND ParameterName = '{paramName}'";
			DataRow[] array = customLogHeader.Parameters.Select(filterExpression);
			if (array == null || array.Length == 0)
			{
				CustomLogHeader.ParametersRow parametersRow = CustomLogHeader.Parameters.NewParametersRow();
				parametersRow.DeviceAddress = "";
				parametersRow.ParameterName = paramName;
				CustomLogHeader.Parameters.AddParametersRow(parametersRow);
				CustomLogHeader.Parameters.AcceptChanges();
			}
			specialHeaderValues[paramName] = paramValue;
		}

		public void RemoveSpecialFileHeader(string paramName)
		{
			string filterExpression = $"DeviceAddress = '' AND ParameterName = '{paramName}'";
			DataRow[] array = CustomLogHeader.Parameters.Select(filterExpression);
			if (array != null && array.Length != 0)
			{
				specialHeaderValues.Remove(paramName);
				CustomLogHeader.Parameters.RemoveParametersRow(array[0] as CustomLogHeader.ParametersRow);
			}
		}

		public void UpdateNotes()
		{
			try
			{
				HeaderNotes = CustomLogHeader.LogHeader[0].Notes;
			}
			catch
			{
			}
		}

		protected virtual void RaiseLoggingOptionsChangedEvent()
		{
			if (LoggingOptionsChangedEvent != null)
			{
				LoggingOptionsChangedEvent(this, EventArgs.Empty);
			}
		}

		protected virtual void RaiseLogPCTimeStampOptionChanged()
		{
			if (logPCTimeStampOptionChanged != null)
			{
				logPCTimeStampOptionChanged(this, EventArgs.Empty);
			}
		}

		protected virtual void RaiseFaultsLoggingOptionChangedEvent()
		{
			if (FaultsLoggingOptionChangedEvent != null)
			{
				FaultsLoggingOptionChangedEvent(this, EventArgs.Empty);
			}
		}

		protected virtual void RaiseMonitorModeChangedEvent()
		{
			if (MonitorModeChangedEvent != null)
			{
				MonitorModeChangedEvent(this, EventArgs.Empty);
			}
		}

		protected virtual void RaiseLoggingModeChanged()
		{
			if (LoggingModeChanged != null)
			{
				LoggingModeChanged(this, EventArgs.Empty);
			}
		}

		protected void RaiseMediafullCheckChangedEvent()
		{
			if (this.MediafullCheckChangedEvent != null)
			{
				this.MediafullCheckChangedEvent(this, EventArgs.Empty);
			}
		}

		protected virtual void RaiseCreateMiniLogFileEvent()
		{
			if (CreateMiniLogFileEvent != null)
			{
				CreateMiniLogFileEvent(this, EventArgs.Empty);
			}
		}

		private string ReplaceIllegalFileCharacters(string text)
		{
			char c = '_';
			char[] array = text.ToCharArray();
			StringBuilder stringBuilder = new StringBuilder(text.Length);
			for (int i = 0; i < array.Length; i++)
			{
				char value = ((!IsCharIllegal(array[i])) ? array[i] : c);
				stringBuilder.Append(value);
			}
			return stringBuilder.ToString();
		}

		private bool IsCharIllegal(char c)
		{
			bool result = false;
			for (int i = 0; i < illegalChars.Length; i++)
			{
				if (c == illegalChars[i])
				{
					result = true;
					break;
				}
			}
			return result;
		}
	}
}
namespace Cummins.Logging.LogManager
{
	public class CustomDataGridButtonColumn : DataGridTextBoxColumn
	{
		private SortedList buttonList;

		public CustomDataGridButtonColumn()
		{
			buttonList = new SortedList();
		}

		protected override void Edit(CurrencyManager source, int rowNum, Rectangle bounds, bool readOnly, string instantText, bool cellIsVisible)
		{
			Button button = GetButton(rowNum);
			((Control)button).BringToFront();
			((Control)button).Focus();
			((Control)button).Select();
		}

		public Button GetButton(int rowNum)
		{
			//IL_0011: Unknown result type (might be due to invalid IL or missing references)
			//IL_0017: Expected O, but got Unknown
			//IL_001a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0020: Expected O, but got Unknown
			//IL_005e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0063: Unknown result type (might be due to invalid IL or missing references)
			//IL_006d: Expected O, but got Unknown
			Button val = (Button)buttonList[rowNum];
			if (val == null)
			{
				val = new Button();
				((Control)val).Parent = ((Control)((DataGridTextBoxColumn)this).TextBox).Parent;
				((Control)val).ForeColor = SystemColors.ControlText;
				((Control)val).BackColor = SystemColors.Control;
				((Control)val).Font = new Font(((Control)val).Font.FontFamily, 6f, ((Control)val).Font.Style);
				((Control)val).TabStop = true;
				buttonList[rowNum] = val;
			}
			return val;
		}

		protected override void Paint(Graphics g, Rectangle bounds, CurrencyManager source, int rowNum, Brush backBrush, Brush foreBrush, bool alignToRight)
		{
			try
			{
				((DataGridTextBoxColumn)this).Paint(g, bounds, source, rowNum, backBrush, foreBrush, alignToRight);
				Button button = GetButton(rowNum);
				((Control)button).Size = new Size(bounds.Width, bounds.Height);
				((Control)button).Location = new Point(bounds.X, bounds.Y);
			}
			catch (Exception)
			{
			}
		}
	}
	public class CustomDataGridComboBoxColumn : DataGridTextBoxColumn
	{
		private ComboBox comboBox;

		private bool isEditing;

		private CurrencyManager source;

		private int rowNum;

		private SortedList enableList = new SortedList();

		public ComboBox ComboBox => comboBox;

		public CustomDataGridComboBoxColumn()
		{
			//IL_0012: Unknown result type (might be due to invalid IL or missing references)
			//IL_001c: Expected O, but got Unknown
			comboBox = new ComboBox();
			comboBox.DropDownStyle = (ComboBoxStyle)2;
			((Control)comboBox).Enter += OnComboBoxEnter;
			((Control)comboBox).Leave += OnComboBoxLeave;
		}

		public void SetEnabled(int row, bool isEnabled)
		{
			enableList[row] = isEnabled;
		}

		protected override void Edit(CurrencyManager source, int rowNum, Rectangle bounds, bool readOnly, string instantText, bool cellIsVisible)
		{
			((DataGridTextBoxColumn)this).Edit(source, rowNum, bounds, readOnly, instantText, cellIsVisible);
			this.rowNum = rowNum;
			this.source = source;
			((Control)comboBox).Parent = ((Control)((DataGridTextBoxColumn)this).TextBox).Parent;
			((Control)comboBox).Location = new Point(((Control)((DataGridTextBoxColumn)this).TextBox).Location.X, ((Control)((DataGridTextBoxColumn)this).TextBox).Location.Y - 2);
			((Control)comboBox).Size = ((Control)((DataGridTextBoxColumn)this).TextBox).Size;
			((Control)comboBox).Text = ((Control)((DataGridTextBoxColumn)this).TextBox).Text;
			((Control)((DataGridTextBoxColumn)this).TextBox).Visible = false;
			if (IsComboBoxVisible(rowNum))
			{
				((Control)comboBox).Visible = true;
				((Control)comboBox).BringToFront();
				((Control)comboBox).Focus();
			}
		}

		private bool IsComboBoxVisible(int rowNum)
		{
			if (enableList[rowNum] != null)
			{
				return (bool)enableList[rowNum];
			}
			return true;
		}

		protected override bool Commit(CurrencyManager dataSource, int rowNum)
		{
			if (isEditing)
			{
				isEditing = false;
				((DataGridColumnStyle)this).SetColumnValueAtRow(dataSource, rowNum, (object)((Control)comboBox).Text);
			}
			return true;
		}

		private void OnComboBoxEnter(object sender, EventArgs e)
		{
			if (IsComboBoxVisible(rowNum))
			{
				isEditing = true;
			}
			else
			{
				((Control)comboBox).Hide();
			}
		}

		private void OnComboBoxLeave(object sender, EventArgs e)
		{
			if (isEditing)
			{
				((DataGridColumnStyle)this).SetColumnValueAtRow(source, rowNum, (object)((Control)comboBox).Text);
				isEditing = false;
				((DataGridColumnStyle)this).Invalidate();
			}
			((Control)comboBox).Hide();
		}
	}
	public class CustomDataGridIconTextColumn : DataGridTextBoxColumn
	{
		private ImageList icons;

		private DataGrid parentGrid;

		private string[] description;

		public CustomDataGridIconTextColumn(ImageList Icons, string[] description, DataGrid parentGrid)
		{
			this.parentGrid = parentGrid;
			icons = Icons;
			this.description = description;
		}

		protected override void Edit(CurrencyManager source, int rowNum, Rectangle bounds, bool readOnly, string instantText, bool cellIsVisible)
		{
		}

		protected override void Paint(Graphics g, Rectangle bounds, CurrencyManager source, int rowNum, Brush backBrush, Brush foreBrush, bool alignToRight)
		{
			try
			{
				int num = (int)((DataGridColumnStyle)this).GetColumnValueAtRow(source, rowNum);
				Image val = icons.Images[num];
				Rectangle rectangle = new Rectangle(bounds.X, bounds.Y, val.Size.Width, bounds.Height);
				g.FillRectangle(backBrush, rectangle);
				g.DrawImage(val, rectangle);
				bounds.X += rectangle.Width;
				bounds.Width -= rectangle.Width;
				foreBrush = backBrush;
				val = null;
				((DataGridTextBoxColumn)this).Paint(g, bounds, source, rowNum, backBrush, foreBrush, alignToRight);
				RectangleF rectangleF = new RectangleF(bounds.X, bounds.Y + 2, bounds.Width, bounds.Height);
				g.DrawString(description[num], ((Control)parentGrid).Font, Brushes.Black, rectangleF);
			}
			catch (Exception)
			{
			}
		}
	}
	public class CustomDataGridTextBoxColumn : DataGridTextBoxColumn
	{
		private SortedList enableList = new SortedList();

		public void SetEnabled(int row, bool isEnabled)
		{
			enableList[row] = isEnabled;
		}

		private bool IsTextBoxVisible(int rowNum)
		{
			if (enableList[rowNum] != null)
			{
				return (bool)enableList[rowNum];
			}
			return true;
		}

		protected override void Edit(CurrencyManager source, int rowNum, Rectangle bounds, bool readOnly, string instantText, bool cellIsVisible)
		{
			((DataGridTextBoxColumn)this).Edit(source, rowNum, bounds, readOnly, instantText, cellIsVisible);
			((Control)((DataGridTextBoxColumn)this).TextBox).Visible = IsTextBoxVisible(rowNum);
		}
	}
	public struct LogConfig
	{
		public string LogName;

		public ParameterListEventArgs ParameterList;

		public ArrayList DataProviderList;

		public SortedList SpecialHeaders;
	}
	public enum SpecialHeaders
	{
		CaltermVersion,
		ScreenName,
		ScreenStatus,
		ScreenMonitorType,
		ScreenBAMRefreshRate,
		ScreenEDMRefreshRate,
		ScreenDataRefreshRate,
		ScreenRefreshRateUnit
	}
	public struct UCLogConfig
	{
		public string LogName;

		public ParameterListEventArgs ParameterList;

		public ArrayList DataProviderList;

		public SortedList SpecialHeaders;
	}
	public interface ILogManager
	{
		ArrayList LoggerList { get; }

		ILoggerConfiguration GlobalLogOption { get; }

		FaultsUpdateEventHandler FaultHandler { get; }

		event LoggingStateChangedEventHandler LoggingStateChangeEvent;

		event LogFileSavingEventHandler LogFileSavingEvent;

		event EventHandler UCLoggingOptionChangedEvent;

		void Initialize(DataTable screenTable);

		void StartAllLoggers(ArrayList logConfigList, ArrayList uclogConfigList);

		void StopAllLoggers();

		void ConfigureEventDriven(LogConfig logConfig);

		void ConfigureLoggers();

		void StartLogger(LogConfig logConfig);

		void StopLogger(string logName);

		void StartUCLogger(UCLogConfig uclogConfig);

		void StartWritingToMiniLogFiles();

		void StopUCLogger(string logName);

		void Add(string logName, ParameterListEventArgs parameterList);

		void Add(string logName, string parameterName, string units, NetworkType networkType, IAddressValue sourceAddress, bool isJ1939);

		void Add(string logName, uint address, int offset, uint length, string units, IAddressValue sourceAddress, string displayName);

		void Remove(string logName, string parameterName, string units, NetworkType networkType, IAddressValue sourceAddress, bool isJ1939Data);

		void Remove(string logName, uint address, int offset, uint length, IAddressValue sourceAddress);

		void RegisterDataProvider(string logName, IDataProvider dataProvider);

		void UnregisterDataProvider(string logName, IDataProvider dataProvider);

		void LoggingStatus(ArrayList logConfigList, ArrayList uclogConfigList);

		LoggingState LogState(string logName);
	}
	[Serializable]
	[DesignerCategory("code")]
	[ToolboxItem(true)]
	[DebuggerStepThrough]
	public class LogConfigTable : DataSet
	{
		public delegate void LogConfigRowChangeEventHandler(object sender, LogConfigRowChangeEvent e);

		[DebuggerStepThrough]
		public class LogConfigDataTable : DataTable, IEnumerable
		{
			private DataColumn columnDataLogger;

			private DataColumn columnOldLogPrefix;

			private DataColumn columnLogPrefix;

			private DataColumn columnLogMode;

			private DataColumn columnLogRate;

			private DataColumn columnLogUnit;

			private DataColumn columnPCTimestamp;

			private DataColumn columnActiveFaults;

			private DataColumn columnInactiveFaults;

			[Browsable(false)]
			public int Count => base.Rows.Count;

			internal DataColumn DataLoggerColumn => columnDataLogger;

			internal DataColumn OldLogPrefixColumn => columnOldLogPrefix;

			internal DataColumn LogPrefixColumn => columnLogPrefix;

			internal DataColumn LogModeColumn => columnLogMode;

			internal DataColumn LogRateColumn => columnLogRate;

			internal DataColumn LogUnitColumn => columnLogUnit;

			internal DataColumn PCTimestampColumn => columnPCTimestamp;

			internal DataColumn ActiveFaultsColumn => columnActiveFaults;

			internal DataColumn InactiveFaultsColumn => columnInactiveFaults;

			public LogConfigRow this[int index] => (LogConfigRow)base.Rows[index];

			public event LogConfigRowChangeEventHandler LogConfigRowChanged;

			public event LogConfigRowChangeEventHandler LogConfigRowChanging;

			public event LogConfigRowChangeEventHandler LogConfigRowDeleted;

			public event LogConfigRowChangeEventHandler LogConfigRowDeleting;

			internal LogConfigDataTable()
				: base("LogConfig")
			{
				InitClass();
			}

			internal LogConfigDataTable(DataTable table)
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

			public void AddLogConfigRow(LogConfigRow row)
			{
				base.Rows.Add(row);
			}

			public LogConfigRow AddLogConfigRow(string DataLogger, string OldLogPrefix, string LogPrefix, string LogMode, int LogRate, string LogUnit, bool PCTimestamp, bool ActiveFaults, bool InactiveFaults)
			{
				LogConfigRow logConfigRow = (LogConfigRow)NewRow();
				logConfigRow.ItemArray = new object[9] { DataLogger, OldLogPrefix, LogPrefix, LogMode, LogRate, LogUnit, PCTimestamp, ActiveFaults, InactiveFaults };
				base.Rows.Add(logConfigRow);
				return logConfigRow;
			}

			public IEnumerator GetEnumerator()
			{
				return base.Rows.GetEnumerator();
			}

			public override DataTable Clone()
			{
				LogConfigDataTable logConfigDataTable = (LogConfigDataTable)base.Clone();
				logConfigDataTable.InitVars();
				return logConfigDataTable;
			}

			protected override DataTable CreateInstance()
			{
				return new LogConfigDataTable();
			}

			internal void InitVars()
			{
				columnDataLogger = base.Columns["DataLogger"];
				columnOldLogPrefix = base.Columns["OldLogPrefix"];
				columnLogPrefix = base.Columns["LogPrefix"];
				columnLogMode = base.Columns["LogMode"];
				columnLogRate = base.Columns["LogRate"];
				columnLogUnit = base.Columns["LogUnit"];
				columnPCTimestamp = base.Columns["PCTimestamp"];
				columnActiveFaults = base.Columns["ActiveFaults"];
				columnInactiveFaults = base.Columns["InactiveFaults"];
			}

			private void InitClass()
			{
				columnDataLogger = new DataColumn("DataLogger", typeof(string), null, MappingType.Attribute);
				base.Columns.Add(columnDataLogger);
				columnOldLogPrefix = new DataColumn("OldLogPrefix", typeof(string), null, MappingType.Attribute);
				base.Columns.Add(columnOldLogPrefix);
				columnLogPrefix = new DataColumn("LogPrefix", typeof(string), null, MappingType.Attribute);
				base.Columns.Add(columnLogPrefix);
				columnLogMode = new DataColumn("LogMode", typeof(string), null, MappingType.Attribute);
				base.Columns.Add(columnLogMode);
				columnLogRate = new DataColumn("LogRate", typeof(int), null, MappingType.Attribute);
				base.Columns.Add(columnLogRate);
				columnLogUnit = new DataColumn("LogUnit", typeof(string), null, MappingType.Attribute);
				base.Columns.Add(columnLogUnit);
				columnPCTimestamp = new DataColumn("PCTimestamp", typeof(bool), null, MappingType.Attribute);
				base.Columns.Add(columnPCTimestamp);
				columnActiveFaults = new DataColumn("ActiveFaults", typeof(bool), null, MappingType.Attribute);
				base.Columns.Add(columnActiveFaults);
				columnInactiveFaults = new DataColumn("InactiveFaults", typeof(bool), null, MappingType.Attribute);
				base.Columns.Add(columnInactiveFaults);
				columnDataLogger.Namespace = "";
				columnDataLogger.DefaultValue = "";
				columnOldLogPrefix.Namespace = "";
				columnOldLogPrefix.DefaultValue = "";
				columnLogPrefix.Namespace = "";
				columnLogPrefix.DefaultValue = "";
				columnLogMode.Namespace = "";
				columnLogMode.DefaultValue = "Any Data";
				columnLogRate.Namespace = "";
				columnLogRate.DefaultValue = 1;
				columnLogUnit.Namespace = "";
				columnLogUnit.DefaultValue = "ms";
				columnPCTimestamp.Namespace = "";
				columnPCTimestamp.DefaultValue = false;
				columnActiveFaults.Namespace = "";
				columnActiveFaults.DefaultValue = false;
				columnInactiveFaults.Namespace = "";
				columnInactiveFaults.DefaultValue = false;
			}

			public LogConfigRow NewLogConfigRow()
			{
				return (LogConfigRow)NewRow();
			}

			protected override DataRow NewRowFromBuilder(DataRowBuilder builder)
			{
				return new LogConfigRow(builder);
			}

			protected override Type GetRowType()
			{
				return typeof(LogConfigRow);
			}

			protected override void OnRowChanged(DataRowChangeEventArgs e)
			{
				base.OnRowChanged(e);
				if (this.LogConfigRowChanged != null)
				{
					this.LogConfigRowChanged(this, new LogConfigRowChangeEvent((LogConfigRow)e.Row, e.Action));
				}
			}

			protected override void OnRowChanging(DataRowChangeEventArgs e)
			{
				base.OnRowChanging(e);
				if (this.LogConfigRowChanging != null)
				{
					this.LogConfigRowChanging(this, new LogConfigRowChangeEvent((LogConfigRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleted(DataRowChangeEventArgs e)
			{
				base.OnRowDeleted(e);
				if (this.LogConfigRowDeleted != null)
				{
					this.LogConfigRowDeleted(this, new LogConfigRowChangeEvent((LogConfigRow)e.Row, e.Action));
				}
			}

			protected override void OnRowDeleting(DataRowChangeEventArgs e)
			{
				base.OnRowDeleting(e);
				if (this.LogConfigRowDeleting != null)
				{
					this.LogConfigRowDeleting(this, new LogConfigRowChangeEvent((LogConfigRow)e.Row, e.Action));
				}
			}

			public void RemoveLogConfigRow(LogConfigRow row)
			{
				base.Rows.Remove(row);
			}
		}

		[DebuggerStepThrough]
		public class LogConfigRow : DataRow
		{
			private LogConfigDataTable tableLogConfig;

			public string DataLogger
			{
				get
				{
					try
					{
						return (string)base[tableLogConfig.DataLoggerColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableLogConfig.DataLoggerColumn] = value;
				}
			}

			public string OldLogPrefix
			{
				get
				{
					try
					{
						return (string)base[tableLogConfig.OldLogPrefixColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableLogConfig.OldLogPrefixColumn] = value;
				}
			}

			public string LogPrefix
			{
				get
				{
					try
					{
						return (string)base[tableLogConfig.LogPrefixColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableLogConfig.LogPrefixColumn] = value;
				}
			}

			public string LogMode
			{
				get
				{
					try
					{
						return (string)base[tableLogConfig.LogModeColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableLogConfig.LogModeColumn] = value;
				}
			}

			public int LogRate
			{
				get
				{
					try
					{
						return (int)base[tableLogConfig.LogRateColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableLogConfig.LogRateColumn] = value;
				}
			}

			public string LogUnit
			{
				get
				{
					try
					{
						return (string)base[tableLogConfig.LogUnitColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableLogConfig.LogUnitColumn] = value;
				}
			}

			public bool PCTimestamp
			{
				get
				{
					try
					{
						return (bool)base[tableLogConfig.PCTimestampColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableLogConfig.PCTimestampColumn] = value;
				}
			}

			public bool ActiveFaults
			{
				get
				{
					try
					{
						return (bool)base[tableLogConfig.ActiveFaultsColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableLogConfig.ActiveFaultsColumn] = value;
				}
			}

			public bool InactiveFaults
			{
				get
				{
					try
					{
						return (bool)base[tableLogConfig.InactiveFaultsColumn];
					}
					catch (InvalidCastException innerException)
					{
						throw new StrongTypingException("Cannot get value because it is DBNull.", innerException);
					}
				}
				set
				{
					base[tableLogConfig.InactiveFaultsColumn] = value;
				}
			}

			internal LogConfigRow(DataRowBuilder rb)
				: base(rb)
			{
				tableLogConfig = (LogConfigDataTable)base.Table;
			}

			public bool IsDataLoggerNull()
			{
				return IsNull(tableLogConfig.DataLoggerColumn);
			}

			public void SetDataLoggerNull()
			{
				base[tableLogConfig.DataLoggerColumn] = Convert.DBNull;
			}

			public bool IsOldLogPrefixNull()
			{
				return IsNull(tableLogConfig.OldLogPrefixColumn);
			}

			public void SetOldLogPrefixNull()
			{
				base[tableLogConfig.OldLogPrefixColumn] = Convert.DBNull;
			}

			public bool IsLogPrefixNull()
			{
				return IsNull(tableLogConfig.LogPrefixColumn);
			}

			public void SetLogPrefixNull()
			{
				base[tableLogConfig.LogPrefixColumn] = Convert.DBNull;
			}

			public bool IsLogModeNull()
			{
				return IsNull(tableLogConfig.LogModeColumn);
			}

			public void SetLogModeNull()
			{
				base[tableLogConfig.LogModeColumn] = Convert.DBNull;
			}

			public bool IsLogRateNull()
			{
				return IsNull(tableLogConfig.LogRateColumn);
			}

			public void SetLogRateNull()
			{
				base[tableLogConfig.LogRateColumn] = Convert.DBNull;
			}

			public bool IsLogUnitNull()
			{
				return IsNull(tableLogConfig.LogUnitColumn);
			}

			public void SetLogUnitNull()
			{
				base[tableLogConfig.LogUnitColumn] = Convert.DBNull;
			}

			public bool IsPCTimestampNull()
			{
				return IsNull(tableLogConfig.PCTimestampColumn);
			}

			public void SetPCTimestampNull()
			{
				base[tableLogConfig.PCTimestampColumn] = Convert.DBNull;
			}

			public bool IsActiveFaultsNull()
			{
				return IsNull(tableLogConfig.ActiveFaultsColumn);
			}

			public void SetActiveFaultsNull()
			{
				base[tableLogConfig.ActiveFaultsColumn] = Convert.DBNull;
			}

			public bool IsInactiveFaultsNull()
			{
				return IsNull(tableLogConfig.InactiveFaultsColumn);
			}

			public void SetInactiveFaultsNull()
			{
				base[tableLogConfig.InactiveFaultsColumn] = Convert.DBNull;
			}
		}

		[DebuggerStepThrough]
		public class LogConfigRowChangeEvent : EventArgs
		{
			private LogConfigRow eventRow;

			private DataRowAction eventAction;

			public LogConfigRow Row => eventRow;

			public DataRowAction Action => eventAction;

			public LogConfigRowChangeEvent(LogConfigRow row, DataRowAction action)
			{
				eventRow = row;
				eventAction = action;
			}
		}

		private LogConfigDataTable tableLogConfig;

		[Browsable(false)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public LogConfigDataTable LogConfig => tableLogConfig;

		public LogConfigTable()
		{
			InitClass();
			CollectionChangeEventHandler value = SchemaChanged;
			base.Tables.CollectionChanged += value;
			base.Relations.CollectionChanged += value;
		}

		protected LogConfigTable(SerializationInfo info, StreamingContext context)
		{
			//IL_0034: Unknown result type (might be due to invalid IL or missing references)
			//IL_003e: Expected O, but got Unknown
			string text = (string)info.GetValue("XmlSchema", typeof(string));
			if (text != null)
			{
				DataSet dataSet = new DataSet();
				dataSet.ReadXmlSchema((XmlReader?)new XmlTextReader((TextReader)new StringReader(text)));
				if (dataSet.Tables["LogConfig"] != null)
				{
					base.Tables.Add(new LogConfigDataTable(dataSet.Tables["LogConfig"]));
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
			LogConfigTable logConfigTable = (LogConfigTable)base.Clone();
			logConfigTable.InitVars();
			return logConfigTable;
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
			if (dataSet.Tables["LogConfig"] != null)
			{
				base.Tables.Add(new LogConfigDataTable(dataSet.Tables["LogConfig"]));
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
			tableLogConfig = (LogConfigDataTable)base.Tables["LogConfig"];
			if (tableLogConfig != null)
			{
				tableLogConfig.InitVars();
			}
		}

		private void InitClass()
		{
			base.DataSetName = "LogConfigTable";
			base.Prefix = "";
			base.Namespace = "http://tempuri.org/LogConfigTable.xsd";
			base.Locale = new CultureInfo("en-US");
			base.CaseSensitive = false;
			base.EnforceConstraints = true;
			tableLogConfig = new LogConfigDataTable();
			base.Tables.Add(tableLogConfig);
		}

		private bool ShouldSerializeLogConfig()
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
	public class LogManager : ILogManager, IPropertyPageProvider
	{
		private ILoggerConfiguration globalLogOption;

		private LogManagerModel model;

		private LogManagerController controller;

		public ArrayList LoggerList
		{
			get
			{
				ArrayList arrayList = null;
				if (model != null)
				{
					return model.LoggerList;
				}
				return new ArrayList();
			}
		}

		public ILoggerConfiguration GlobalLogOption => globalLogOption;

		public FaultsUpdateEventHandler FaultHandler => model.OnFaultsUpdated;

		public ArrayList Pages
		{
			get
			{
				LogPropertiesControl value = new LogPropertiesControl(GlobalLogOption, "", "Logging");
				CustomLogHeaderControl value2 = new CustomLogHeaderControl(GlobalLogOption, "", "Log Header");
				ArrayList arrayList = new ArrayList();
				arrayList.Add(value);
				arrayList.Add(value2);
				return arrayList;
			}
		}

		public event LoggingStateChangedEventHandler LoggingStateChangeEvent;

		public event LogFileSavingEventHandler LogFileSavingEvent;

		public event EventHandler UCLoggingOptionChangedEvent
		{
			add
			{
				model.UCLoggingOptionChangedEvent += value;
			}
			remove
			{
				model.UCLoggingOptionChangedEvent -= value;
			}
		}

		public LogManager()
		{
			globalLogOption = new LoggingOptions();
			globalLogOption.Initialize();
			ILoggerConfiguration loggerConfiguration = globalLogOption;
			loggerConfiguration.LoggingOptionsChangedEvent = (EventHandler)Delegate.Combine(loggerConfiguration.LoggingOptionsChangedEvent, new EventHandler(OnLoggingOptionsChanged));
			ILoggerConfiguration loggerConfiguration2 = globalLogOption;
			loggerConfiguration2.CreateMiniLogFileEvent = (EventHandler)Delegate.Combine(loggerConfiguration2.CreateMiniLogFileEvent, new EventHandler(OnUCLoggingOptionsChanged));
		}

		public void Initialize(DataTable screenTable)
		{
			if (model != null)
			{
				model.LoggingStateChangedEvent -= OnLoggingStateChangedEvent;
				model.LogFileSavingEvent -= OnLogFileSavingEvent;
				model.Dispose();
			}
			model = new LogManagerModel(globalLogOption);
			controller = new LogManagerController(model);
			model.Initialize(screenTable);
			model.LoggingStateChangedEvent += OnLoggingStateChangedEvent;
			model.LogFileSavingEvent += OnLogFileSavingEvent;
		}

		public void StartAllLoggers(ArrayList logConfigList, ArrayList uclogConfigList)
		{
			controller.StartAllLoggers(logConfigList, uclogConfigList);
		}

		public void StopAllLoggers()
		{
			controller.StopAllLoggers();
		}

		public void ConfigureEventDriven(LogConfig logConfig)
		{
			controller.ConfigureEventDriven(logConfig);
		}

		public void ConfigureLoggers()
		{
			//IL_0013: Unknown result type (might be due to invalid IL or missing references)
			LogManagerView logManagerView = new LogManagerView();
			logManagerView.Configure(model);
			((Form)logManagerView).ShowDialog();
		}

		public void StartLogger(LogConfig logConfig)
		{
			controller.StartLogger(logConfig);
		}

		public void StopLogger(string logName)
		{
			controller.StopLogger(logName);
		}

		public void StartUCLogger(UCLogConfig uclogConfig)
		{
			controller.StartUCLogger(uclogConfig);
		}

		public void StartWritingToMiniLogFiles()
		{
			controller.StartWritingToMiniLogFiles();
		}

		public void StopUCLogger(string logName)
		{
			controller.StopUCLogger(logName);
		}

		public void Add(string logName, ParameterListEventArgs parameterList)
		{
			controller.Add(logName, parameterList);
		}

		public void Add(string logName, string parameterName, string units, NetworkType networkType, IAddressValue sourceAddress, bool isJ1939Data)
		{
			controller.Add(logName, parameterName, units, networkType, sourceAddress, isJ1939Data);
		}

		public void Add(string logName, uint address, int offset, uint length, string units, IAddressValue sourceAddress, string displayName)
		{
			controller.Add(logName, address, offset, length, units, sourceAddress, displayName);
		}

		public void AddUCL(string logName, ParameterListEventArgs parameterList)
		{
			controller.AddUCL(logName, parameterList);
		}

		public void AddUCL(string logName, string parameterName, string units, NetworkType networkType, IAddressValue sourceAddress, bool isJ1939Data)
		{
			controller.AddUCL(logName, parameterName, units, networkType, sourceAddress, isJ1939Data);
		}

		public void AddUCL(string logName, uint address, int offset, uint length, string units, IAddressValue sourceAddress, string displayName)
		{
			controller.AddUCL(logName, address, offset, length, units, sourceAddress, displayName);
		}

		public void Remove(string logName, string parameterName, string units, NetworkType networkType, IAddressValue sourceAddress, bool isJ1939Data)
		{
			controller.Remove(logName, parameterName, units, networkType, sourceAddress, isJ1939Data);
		}

		public void Remove(string logName, uint address, int offset, uint length, IAddressValue sourceAddress)
		{
			controller.Remove(logName, address, offset, length, sourceAddress);
		}

		public void RemoveUCL(string logName, string parameterName, string units, NetworkType networkType, IAddressValue sourceAddress, bool isJ1939Data)
		{
			controller.RemoveUCL(logName, parameterName, units, networkType, sourceAddress, isJ1939Data);
		}

		public void RemoveUCL(string logName, uint address, int offset, uint length, IAddressValue sourceAddress)
		{
			controller.RemoveUCL(logName, address, offset, length, sourceAddress);
		}

		public void RegisterDataProvider(string logName, IDataProvider dataProvider)
		{
			controller.RegisterDataProvider(logName, dataProvider);
		}

		public void UnregisterDataProvider(string logName, IDataProvider dataProvider)
		{
			controller.UnregisterDataProvider(logName, dataProvider);
		}

		public void LoggingStatus(ArrayList logConfigList, ArrayList uclogConfigList)
		{
			//IL_0015: Unknown result type (might be due to invalid IL or missing references)
			LogStatusView logStatusView = new LogStatusView();
			logStatusView.Configure(controller, logConfigList, uclogConfigList);
			((Form)logStatusView).ShowDialog();
			((Component)(object)logStatusView).Dispose();
		}

		public LoggingState LogState(string logName)
		{
			ILogger logger = model.GetLogger(logName);
			LoggingState result = LoggingState.Idle;
			if (logger != null)
			{
				result = logger.State;
			}
			return result;
		}

		public int EDLRepeatsLeft(string logName)
		{
			ILogger logger = model.GetLogger(logName);
			int result = -1;
			if (logger != null)
			{
				result = logger.EDLRepeatsLeft;
			}
			return result;
		}

		public int EDLTotalRepeats(string logName)
		{
			ILogger logger = model.GetLogger(logName);
			int result = -1;
			if (logger != null)
			{
				result = logger.EDLTotalRepeats;
			}
			return result;
		}

		public static void SynchronizeOptions(ILoggerConfiguration srcOptions, ILoggerConfiguration localOptions)
		{
			localOptions.Format = srcOptions.Format;
			localOptions.ShouldDisplayLogFile = srcOptions.ShouldDisplayLogFile;
			localOptions.ShouldDisplaySaveAsDialog = srcOptions.ShouldDisplaySaveAsDialog;
			localOptions.LogFilePath = srcOptions.LogFilePath;
			localOptions.MaxLogFileSize = srcOptions.MaxLogFileSize;
			localOptions.FileCreationChoice = srcOptions.FileCreationChoice;
			localOptions.DeleteOldestOnMediaFull = srcOptions.DeleteOldestOnMediaFull;
			localOptions.HeaderNotes = srcOptions.HeaderNotes;
			localOptions.AddConfigNameToLogHeader = srcOptions.AddConfigNameToLogHeader;
			localOptions.ExportParamsOnStartup = srcOptions.ExportParamsOnStartup;
			localOptions.InputFilterFilename = srcOptions.InputFilterFilename;
			localOptions.OutputExportFilename = srcOptions.OutputExportFilename;
			localOptions.EnableUCL_Logging = srcOptions.EnableUCL_Logging;
			localOptions.ShouldInsertEventNumber = srcOptions.ShouldInsertEventNumber;
			localOptions.UCLPreTriggerTime = srcOptions.UCLPreTriggerTime;
			localOptions.UCLPostTriggerTime = srcOptions.UCLPostTriggerTime;
			localOptions.CustomLogHeader.LogHeader.Clear();
			foreach (CustomLogHeader.LogHeaderRow row in srcOptions.CustomLogHeader.LogHeader.Rows)
			{
				CustomLogHeader.LogHeaderRow logHeaderRow2 = localOptions.CustomLogHeader.LogHeader.NewLogHeaderRow();
				logHeaderRow2.Notes = row.Notes;
				localOptions.CustomLogHeader.LogHeader.AddLogHeaderRow(logHeaderRow2);
			}
			localOptions.CustomLogHeader.Parameters.Clear();
			foreach (CustomLogHeader.ParametersRow row2 in srcOptions.CustomLogHeader.Parameters.Rows)
			{
				CustomLogHeader.ParametersRow parametersRow2 = localOptions.CustomLogHeader.Parameters.NewParametersRow();
				parametersRow2.DeviceAddress = row2.DeviceAddress;
				parametersRow2.ParameterName = row2.ParameterName;
				localOptions.CustomLogHeader.Parameters.AddParametersRow(parametersRow2);
			}
		}

		private void OnLoggingStateChangedEvent(object sender, LoggingState e)
		{
			if (this.LoggingStateChangeEvent != null)
			{
				this.LoggingStateChangeEvent(sender, e);
			}
		}

		private void OnLogFileSavingEvent(object sender, LogFileSavingEventArgs e)
		{
			if (this.LogFileSavingEvent != null)
			{
				this.LogFileSavingEvent(sender, e);
			}
		}

		private void OnLoggingOptionsChanged(object sender, EventArgs e)
		{
			foreach (ILogger logger in LoggerList)
			{
				SynchronizeOptions(GlobalLogOption, logger.Configuration);
			}
		}

		private void OnUCLoggingOptionsChanged(object sender, EventArgs e)
		{
			foreach (ILogger logger in LoggerList)
			{
				SynchronizeOptions(GlobalLogOption, logger.Configuration);
			}
		}
	}
	public class LogManagerController
	{
		private const string InitialMonitorRateHeader = "Initial Monitor Rate";

		private LogManagerModel model;

		private SortedList dataProviderList;

		public LogManagerModel Model => model;

		public LogManagerController(LogManagerModel model)
		{
			this.model = model;
			dataProviderList = new SortedList();
		}

		public void StartAllLoggers(ArrayList logConfigList, ArrayList uclogConfigList)
		{
			foreach (LogConfig logConfig in logConfigList)
			{
				StartLogger(logConfig);
			}
			foreach (UCLogConfig uclogConfig in uclogConfigList)
			{
				StartUCLogger(uclogConfig);
			}
		}

		public void StopAllLoggers()
		{
			foreach (ILogger logger in Model.LoggerList)
			{
				if (logger.State != LoggingState.Idle)
				{
					logger.Stop();
				}
			}
			UnregisterAllDataProvider();
		}

		public void ConfigureEventDriven(LogConfig logConfig)
		{
			string logName = logConfig.LogName;
			ILogger logger = Model.GetLogger(logName);
			if (logger != null)
			{
				IEventDrivenLogger eventDrivenLogger = (IEventDrivenLogger)logger;
				logger.RemoveAll();
				logger.Network = Model.GlobalOptions.Network;
				logger.Add(logConfig.ParameterList);
				AddSpecialHeader(logger, logConfig.SpecialHeaders);
				RegisterDataProvider(logConfig);
				eventDrivenLogger.Configure();
			}
		}

		public void StartLogger(LogConfig logConfig)
		{
			string logName = logConfig.LogName;
			ILogger logger = Model.GetLogger(logName);
			if (logger != null)
			{
				logger.RemoveAll();
				logger.Add(logConfig.ParameterList);
				logger.Network = Model.GlobalOptions.Network;
				AddSpecialHeader(logger, logConfig.SpecialHeaders);
				RegisterDataProvider(logConfig);
				logger.Start();
			}
		}

		public void StopLogger(string logName)
		{
			ILogger logger = Model.GetLogger(logName);
			if (logger == null)
			{
				return;
			}
			logger.Stop();
			foreach (ILogger logger2 in Model.LoggerList)
			{
				if (logger2.State != LoggingState.Idle)
				{
					logger2.Configuration.DisplayFreeSpace = true;
				}
			}
			UnregisterDataProvider(logName);
		}

		public void Add(string logName, ParameterListEventArgs parameterList)
		{
			Model.GetLogger(logName)?.Add(parameterList);
		}

		public void AddUCL(string logName, ParameterListEventArgs parameterList)
		{
			Model.GetLogger(logName)?.AddUCL(parameterList);
		}

		public void Add(string logName, string parameterName, string units, NetworkType networkType, IAddressValue sourceAddress, bool isJ1939Data)
		{
			Model.GetLogger(logName)?.Add(parameterName, units, networkType, sourceAddress, isJ1939Data);
		}

		public void AddUCL(string logName, string parameterName, string units, NetworkType networkType, IAddressValue sourceAddress, bool isJ1939Data)
		{
			Model.GetLogger(logName)?.AddUCL(parameterName, units, networkType, sourceAddress, isJ1939Data);
		}

		public void Add(string logName, uint address, int offset, uint length, string units, IAddressValue sourceAddress, string displayName)
		{
			Model.GetLogger(logName)?.Add(address, offset, length, units, sourceAddress, displayName);
		}

		public void AddUCL(string logName, uint address, int offset, uint length, string units, IAddressValue sourceAddress, string displayName)
		{
			Model.GetLogger(logName)?.AddUCL(address, offset, length, units, sourceAddress, displayName);
		}

		public void Remove(string logName, string parameterName, string units, NetworkType networkType, IAddressValue sourceAddress, bool isJ1939Data)
		{
			Model.GetLogger(logName)?.Remove(parameterName, units, networkType, sourceAddress, isJ1939Data);
		}

		public void RemoveUCL(string logName, string parameterName, string units, NetworkType networkType, IAddressValue sourceAddress, bool isJ1939Data)
		{
			Model.GetLogger(logName)?.RemoveUCL(parameterName, units, networkType, sourceAddress, isJ1939Data);
		}

		public void Remove(string logName, uint address, int offset, uint length, IAddressValue sourceAddress)
		{
			Model.GetLogger(logName)?.Remove(address, offset, length, sourceAddress);
		}

		public void RemoveUCL(string logName, uint address, int offset, uint length, IAddressValue sourceAddress)
		{
			Model.GetLogger(logName)?.RemoveUCL(address, offset, length, sourceAddress);
		}

		public void RegisterDataProvider(string logName, IDataProvider dataProvider)
		{
			ILogger logger = Model.GetLogger(logName);
			if (logger == null)
			{
				return;
			}
			string key = GenerateDataProviderKey(logName, dataProvider);
			lock (dataProviderList)
			{
				if (dataProviderList[key] == null)
				{
					logger.RegisterDataProvider(dataProvider);
					RegisterSubscriptionEvents((ISubscription)dataProvider);
					dataProviderList[key] = dataProvider;
				}
			}
		}

		public void UnregisterDataProvider(string logName, IDataProvider dataProvider)
		{
			ILogger logger = Model.GetLogger(logName);
			if (logger == null)
			{
				return;
			}
			string key = GenerateDataProviderKey(logName, dataProvider);
			lock (dataProviderList)
			{
				if (dataProviderList[key] != null && (logger.Mode != Mode.EventDriven || logger.State == LoggingState.Idle))
				{
					logger.UnRegisterDataProvider(dataProvider);
					UnregisterSubscriptionEvents((ISubscription)dataProvider);
					dataProviderList.Remove(key);
				}
			}
		}

		public void StartUCLogger(UCLogConfig uclogConfig)
		{
			string logName = uclogConfig.LogName;
			ILogger logger = Model.GetLogger(logName);
			if (logger != null)
			{
				logger.RemoveAllUCL();
				logger.AddUCL(uclogConfig.ParameterList);
				logger.Network = Model.GlobalOptions.Network;
				AddSpecialHeader(logger, uclogConfig.SpecialHeaders);
				RegisterUCLDataProvider(uclogConfig);
				logger.StartUCL();
			}
		}

		public void StartWritingToMiniLogFiles()
		{
			ArrayList loggerList = Model.LoggerList;
			foreach (ILogger item in loggerList)
			{
				if (item.State == LoggingState.Logging && item.Mode != Mode.EventDriven)
				{
					Model.GetLogger(item.Configuration.LogfilePrefix)?.StartUCLogging();
				}
			}
			GlobalEventNumber.startTimeFlag = true;
		}

		public void StopUCLogger(string logName)
		{
			Model.GetLogger(logName)?.StopUCL();
		}

		public void ConfigureUCL(LogConfig logConfig)
		{
			string logName = logConfig.LogName;
			ILogger logger = Model.GetLogger(logName);
			logger.Network = Model.GlobalOptions.Network;
			logger.Add(logConfig.ParameterList);
			AddSpecialHeader(logger, logConfig.SpecialHeaders);
			RegisterDataProvider(logConfig);
		}

		private void AddSpecialHeader(ILogger logger, SortedList logHeaders)
		{
			if (logHeaders == null)
			{
				return;
			}
			if (logHeaders[SpecialHeaders.CaltermVersion] != null)
			{
				logger.Configuration.AddSpecialFileHeaderValue(SpecialHeaders.CaltermVersion.ToString(), logHeaders[SpecialHeaders.CaltermVersion].ToString());
			}
			if (logHeaders[SpecialHeaders.ScreenMonitorType] != null)
			{
				string text = logHeaders[SpecialHeaders.ScreenMonitorType].ToString();
				logger.Configuration.AddSpecialFileHeaderValue(SpecialHeaders.ScreenMonitorType.ToString(), text);
				SpecialHeaders specialHeaders = (DataAcquisitionType)Enum.Parse(typeof(DataAcquisitionType), text, ignoreCase: true) switch
				{
					DataAcquisitionType.EDM => SpecialHeaders.ScreenEDMRefreshRate, 
					DataAcquisitionType.BAM => SpecialHeaders.ScreenBAMRefreshRate, 
					_ => SpecialHeaders.ScreenDataRefreshRate, 
				};
				if (logHeaders[specialHeaders] != null && logHeaders[SpecialHeaders.ScreenRefreshRateUnit] != null)
				{
					string text2 = logHeaders[specialHeaders].ToString();
					string text3 = logHeaders[SpecialHeaders.ScreenRefreshRateUnit].ToString();
					logger.Configuration.AddSpecialFileHeaderValue("Initial Monitor Rate", text2 + " " + text3);
				}
			}
		}

		private void RegisterDataProvider(LogConfig logConfig)
		{
			foreach (IDataProvider dataProvider in logConfig.DataProviderList)
			{
				RegisterDataProvider(logConfig.LogName, dataProvider);
			}
		}

		private void RegisterUCLDataProvider(UCLogConfig uclogConfig)
		{
			foreach (IDataProvider dataProvider in uclogConfig.DataProviderList)
			{
				RegisterUCLDataProvider(uclogConfig.LogName, dataProvider);
			}
		}

		public void RegisterUCLDataProvider(string logName, IDataProvider dataProvider)
		{
			ILogger logger = Model.GetLogger(logName);
			if (logger == null)
			{
				return;
			}
			string key = GenerateDataProviderKey(logName, dataProvider);
			lock (dataProviderList)
			{
				if (dataProviderList[key] == null)
				{
					logger.RegisterUCLDataProvider(dataProvider);
					RegisterUCLSubscriptionEvents((ISubscription)dataProvider);
					dataProviderList[key] = dataProvider;
				}
			}
		}

		private void UnregisterDataProvider(string logName)
		{
			ArrayList arrayList = new ArrayList();
			lock (dataProviderList)
			{
				foreach (string key2 in dataProviderList.Keys)
				{
					string logNameFromKey = GetLogNameFromKey(key2);
					if (logNameFromKey == logName)
					{
						arrayList.Add(key2);
					}
				}
			}
			foreach (string item in arrayList)
			{
				string logNameFromKey2 = GetLogNameFromKey(item);
				UnregisterDataProvider(logNameFromKey2, (IDataProvider)dataProviderList[item]);
			}
		}

		private void UnregisterAllDataProvider()
		{
			ArrayList arrayList = null;
			lock (dataProviderList)
			{
				arrayList = new ArrayList(dataProviderList.Keys);
			}
			foreach (string item in arrayList)
			{
				string logNameFromKey = GetLogNameFromKey(item);
				UnregisterDataProvider(logNameFromKey, (IDataProvider)dataProviderList[item]);
			}
		}

		private void RegisterSubscriptionEvents(ISubscription subscription)
		{
			if (subscription != null)
			{
				subscription.Started += OnSubscriptionStarted;
				subscription.Stopped += OnSubscriptionStopped;
			}
		}

		private void RegisterUCLSubscriptionEvents(ISubscription subscription)
		{
			if (subscription != null)
			{
				subscription.Started += OnSubscriptionStarted;
				subscription.Stopped += OnSubscriptionStopped;
			}
		}

		private void UnregisterSubscriptionEvents(ISubscription subscription)
		{
			if (subscription != null)
			{
				subscription.Started -= OnSubscriptionStarted;
				subscription.Stopped -= OnSubscriptionStopped;
			}
		}

		private string GenerateDataProviderKey(string logName, IDataProvider provider)
		{
			return logName + "@" + provider.ID;
		}

		private string GetLogNameFromKey(string key)
		{
			return key.Substring(0, key.LastIndexOf("@"));
		}

		private void OnSubscriptionStopped(object sender, EventArgs e)
		{
			if (!(sender is IDataProvider provider))
			{
				return;
			}
			lock (dataProviderList)
			{
				foreach (string key in dataProviderList.Keys)
				{
					string logNameFromKey = GetLogNameFromKey(key);
					ILogger logger = model.GetLogger(logNameFromKey);
					if (logger != null && GenerateDataProviderKey(logNameFromKey, provider) == key)
					{
						logger.UnRegisterDataProvider((IDataProvider)dataProviderList[key]);
					}
				}
			}
		}

		private void OnSubscriptionStarted(object sender, EventArgs e)
		{
			if (!(sender is IDataProvider provider))
			{
				return;
			}
			lock (dataProviderList)
			{
				foreach (string key in dataProviderList.Keys)
				{
					string logNameFromKey = GetLogNameFromKey(key);
					ILogger logger = model.GetLogger(logNameFromKey);
					if (logger != null && GenerateDataProviderKey(logNameFromKey, provider) == key)
					{
						logger.RegisterDataProvider((IDataProvider)dataProviderList[key]);
					}
				}
			}
		}
	}
	public class LogManagerModel
	{
		private delegate void CreateLoggerDelegate(DataRow row);

		private const string AnyData = "Any Data";

		private const string AllData = "All Data";

		private const int MSInOneSec = 1000;

		private DataTable screenTable;

		private ListDictionary loggerList;

		private ILoggerConfiguration globalOptions;

		public LogConfigTable LoggerConfiguration
		{
			get
			{
				LogConfigTable logConfigTable = new LogConfigTable();
				foreach (DataRow row in screenTable.Rows)
				{
					if (row["ScreenType"].ToString() != "Complex")
					{
						LogConfigTable.LogConfigRow logConfigRow = logConfigTable.LogConfig.NewLogConfigRow();
						logConfigRow.LogPrefix = GetUniqueLogPrefix(row["Name"].ToString(), row["LogPrefix"].ToString());
						logConfigRow.OldLogPrefix = logConfigRow.LogPrefix;
						logConfigRow.DataLogger = row["Name"].ToString();
						logConfigRow.LogMode = row["LogMode"].ToString();
						logConfigRow.LogRate = int.Parse(row["LogRate"].ToString());
						logConfigRow.LogUnit = row["LogUnit"].ToString();
						logConfigRow.PCTimestamp = bool.Parse(row["PCTimestamp"].ToString());
						logConfigRow.ActiveFaults = bool.Parse(row["ActiveFaults"].ToString());
						logConfigRow.InactiveFaults = bool.Parse(row["InactiveFaults"].ToString());
						logConfigTable.LogConfig.AddLogConfigRow(logConfigRow);
					}
				}
				logConfigTable.LogConfig.LogPrefixColumn.Unique = true;
				return logConfigTable;
			}
		}

		public DataTable ScreenTable => screenTable;

		public ArrayList LoggerList
		{
			get
			{
				lock (loggerList)
				{
					return new ArrayList(loggerList.Values);
				}
			}
		}

		public ILoggerConfiguration GlobalOptions => globalOptions;

		public event LoggingStateChangedEventHandler LoggingStateChangedEvent;

		public event LogFileSavingEventHandler LogFileSavingEvent;

		public event EventHandler UCLoggingOptionChangedEvent;

		public LogManagerModel(ILoggerConfiguration loggerConfiguration)
		{
			loggerList = new ListDictionary();
			globalOptions = loggerConfiguration;
		}

		public void Initialize(DataTable screenTable)
		{
			this.screenTable = screenTable;
			if (this.screenTable != null)
			{
				InitDataLogger();
				screenTable.RowDeleting += OnScreenTableRowDeleting;
				screenTable.RowChanged += OnScreenTableRowChanged;
			}
		}

		public void SaveConfiguration(LogConfigTable logConfiguration)
		{
			ListDictionary listDictionary = new ListDictionary();
			lock (loggerList)
			{
				foreach (LogConfigTable.LogConfigRow row in logConfiguration.LogConfig.Rows)
				{
					DataRow dataRow = screenTable.Select("Name = '" + row.DataLogger + "'")[0];
					if (dataRow["LogMode"].ToString() != row.LogMode)
					{
						dataRow["LogMode"] = row.LogMode;
					}
					if (int.Parse(dataRow["LogRate"].ToString()) != row.LogRate)
					{
						dataRow["LogRate"] = row.LogRate;
					}
					if (dataRow["LogUnit"].ToString() != row.LogUnit)
					{
						dataRow["LogUnit"] = row.LogUnit;
					}
					if (bool.Parse(dataRow["PCTimestamp"].ToString()) != row.PCTimestamp)
					{
						dataRow["PCTimestamp"] = row.PCTimestamp;
					}
					if (bool.Parse(dataRow["ActiveFaults"].ToString()) != row.ActiveFaults)
					{
						dataRow["ActiveFaults"] = row.ActiveFaults;
					}
					if (bool.Parse(dataRow["InactiveFaults"].ToString()) != row.InactiveFaults)
					{
						dataRow["InactiveFaults"] = row.InactiveFaults;
					}
					if (dataRow["LogPrefix"].ToString() != row.LogPrefix)
					{
						dataRow["LogPrefix"] = row.LogPrefix;
					}
					ILogger logger = (ILogger)loggerList[row.OldLogPrefix];
					SaveConfiguration(logger, row.LogMode, row.LogRate, row.LogUnit, row.PCTimestamp, row.ActiveFaults, row.InactiveFaults, row.LogPrefix);
					listDictionary.Add(row.LogPrefix.ToString(), logger);
				}
			}
			loggerList = listDictionary;
		}

		public ILogger GetLogger(string logName)
		{
			lock (loggerList)
			{
				return (ILogger)loggerList[logName];
			}
		}

		public void OnFaultsUpdated(object caller, FaultsUpdateEventArgs args)
		{
			foreach (ILogger logger in LoggerList)
			{
				logger.FaultHandler.BeginInvoke(caller, args, null, null);
			}
		}

		public void Dispose()
		{
			if (screenTable != null)
			{
				screenTable.RowDeleting -= OnScreenTableRowDeleting;
				screenTable.RowChanged -= OnScreenTableRowChanged;
			}
			lock (loggerList)
			{
				ArrayList arrayList = new ArrayList(loggerList.Keys);
				foreach (string item in arrayList)
				{
					DeleteLogger(item);
				}
			}
		}

		private void InitDataLogger()
		{
			foreach (DataRow row in screenTable.Rows)
			{
				CreateLogger(row);
			}
		}

		private void CreateLogger(DataRow screenRow)
		{
			if (screenRow["ScreenType"].ToString() != "Complex")
			{
				string logMode = screenRow["LogMode"].ToString();
				int logRate = int.Parse(screenRow["LogRate"].ToString());
				string logUnit = screenRow["LogUnit"].ToString();
				bool pcTimestamp = bool.Parse(screenRow["PCTimestamp"].ToString());
				bool activeFaults = bool.Parse(screenRow["ActiveFaults"].ToString());
				bool inactiveFaults = bool.Parse(screenRow["InactiveFaults"].ToString());
				string uniqueLogPrefix = GetUniqueLogPrefix(screenRow["Name"].ToString(), screenRow["LogPrefix"].ToString());
				if (screenRow["LogPrefix"].ToString() != uniqueLogPrefix)
				{
					screenRow["LogPrefix"] = uniqueLogPrefix;
				}
				Logging logging = new Logging();
				logging.Initialize();
				logging.TriggerConfiguration.Initialize(screenRow);
				logging.LoggingStateChangeEvent += OnLoggingStateChangeEvent;
				logging.LogFileSavingEvent += OnLogFileSavingEvent;
				logging.UCLoggingOptionChangedEvent += OnLoggerUCLoggingOptionChangedEvent;
				SaveConfiguration(logging, logMode, logRate, logUnit, pcTimestamp, activeFaults, inactiveFaults, uniqueLogPrefix);
				lock (loggerList)
				{
					loggerList[uniqueLogPrefix] = logging;
				}
			}
		}

		private void OnLoggerUCLoggingOptionChangedEvent(object sender, EventArgs e)
		{
			this.UCLoggingOptionChangedEvent(sender, e);
		}

		private void DeleteLogger(string logName)
		{
			lock (loggerList)
			{
				ILogger logger = (ILogger)loggerList[logName];
				if (logger != null)
				{
					logger.Abort();
					logger.LoggingStateChangeEvent -= OnLoggingStateChangeEvent;
					logger.LogFileSavingEvent -= OnLogFileSavingEvent;
					loggerList.Remove(logName);
					(logger as IDisposable).Dispose();
				}
			}
		}

		private void SaveConfiguration(ILogger logger, string logMode, int logRate, string logUnit, bool pcTimestamp, bool activeFaults, bool inactiveFaults, string prefix)
		{
			logger.Configuration.RecordingMode = GetRecordingModes(logMode);
			logger.Configuration.LogRateUnit = (LoggingRateUnits)Enum.Parse(typeof(LoggingRateUnits), logUnit, ignoreCase: true);
			logger.Configuration.LogRate = GetLogRate(logRate, logger.Configuration.LogRateUnit);
			logger.Configuration.LogPCTime = pcTimestamp;
			logger.Configuration.ShouldLogActiveFaults = activeFaults;
			logger.Configuration.ShouldLogInactiveFaults = inactiveFaults;
			logger.Configuration.PrefixRequestReceive = prefix;
		}

		private int GetLogRate(int rate, LoggingRateUnits units)
		{
			int num = rate;
			if (units == LoggingRateUnits.ms)
			{
				return rate;
			}
			int num2 = rate;
			if (num2 < 1)
			{
				num2 = 1;
			}
			return 1000 / num2;
		}

		private RecordingModes GetRecordingModes(string logMode)
		{
			RecordingModes recordingModes = RecordingModes.Unknown;
			return logMode switch
			{
				"Any Data" => RecordingModes.AnyDataReceived, 
				"All Data" => RecordingModes.AllDataReceived, 
				_ => RecordingModes.UserSpecifiedRate, 
			};
		}

		private string GetUniqueLogPrefix(string screenName, string logPrefix)
		{
			int num = 0;
			string text = ((logPrefix == "") ? screenName : logPrefix);
			string format = "Name <> '{0}' AND LogPrefix = '{1}'";
			string text2 = text;
			while (ScreenTable.Select(string.Format(format, screenName, text2)).Length != 0)
			{
				text2 = text + "_" + num++;
			}
			return text2;
		}

		private void OnScreenTableRowDeleting(object sender, DataRowChangeEventArgs e)
		{
			if (e.Action == DataRowAction.Delete)
			{
				string logName = e.Row["LogPrefix"].ToString();
				DeleteLogger(logName);
			}
		}

		private void OnScreenTableRowChanged(object sender, DataRowChangeEventArgs e)
		{
			if (e.Action == DataRowAction.Add)
			{
				CreateLoggerDelegate createLoggerDelegate = CreateLogger;
				createLoggerDelegate.BeginInvoke(e.Row, null, null);
			}
		}

		private void OnLoggingStateChangeEvent(object caller, LoggingState state)
		{
			if (this.LoggingStateChangedEvent != null)
			{
				this.LoggingStateChangedEvent(caller, state);
			}
		}

		private void OnLogFileSavingEvent(object sender, LogFileSavingEventArgs e)
		{
			if (this.LogFileSavingEvent != null)
			{
				this.LogFileSavingEvent(sender, e);
			}
		}
	}
	public class LogManagerView : Form
	{
		private const int LogTypeColumnNumber = 2;

		private const int PCTimestampColumnNumber = 5;

		private const int ActiveFaultsColumnNumber = 6;

		private const int InactiveFaultsColumnNumber = 7;

		private DataGrid logConfigDataGrid;

		private int selectedLogConfigRow;

		private LogManagerModel model;

		private LogConfigTable logConfigTable;

		private DataGridTableStyle logConfigDataGridTableStyle;

		private CustomDataGridComboBoxColumn logTypeColumn;

		private CustomDataGridTextBoxColumn logRateColumn;

		private CustomDataGridComboBoxColumn logRateUnitColumn;

		private Button cancelButton;

		private Button okButton;

		private DataGridTextBoxColumn dataLoggerNameColumn;

		private DataGridBoolColumn logActiveFaultColumn;

		private DataGridBoolColumn logInactiveFaultColumn;

		private DataGridBoolColumn logPCTimeStampColumn;

		private Panel bottomPanel;

		private Panel upperPanel;

		private DataGridTextBoxColumn logPrefixColumn;

		private Container components;

		public LogManagerView()
		{
			InitializeComponent();
		}

		public void Configure(LogManagerModel model)
		{
			this.model = model;
			logConfigTable = model.LoggerConfiguration;
			InitDataGrid();
		}

		private void InitDataGrid()
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Expected O, but got Unknown
			//IL_0067: Unknown result type (might be due to invalid IL or missing references)
			//IL_0071: Expected O, but got Unknown
			//IL_00cd: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d7: Expected O, but got Unknown
			logActiveFaultColumn = new DataGridBoolColumn();
			logActiveFaultColumn.AllowNull = false;
			logActiveFaultColumn.FalseValue = false;
			((DataGridColumnStyle)logActiveFaultColumn).HeaderText = "Active Faults";
			((DataGridColumnStyle)logActiveFaultColumn).MappingName = "ActiveFaults";
			logActiveFaultColumn.TrueValue = true;
			((DataGridColumnStyle)logActiveFaultColumn).Width = 80;
			logInactiveFaultColumn = new DataGridBoolColumn();
			logInactiveFaultColumn.AllowNull = false;
			logInactiveFaultColumn.FalseValue = false;
			((DataGridColumnStyle)logInactiveFaultColumn).HeaderText = "Inactive Faults";
			((DataGridColumnStyle)logInactiveFaultColumn).MappingName = "InactiveFaults";
			logInactiveFaultColumn.TrueValue = true;
			((DataGridColumnStyle)logInactiveFaultColumn).Width = 80;
			logPCTimeStampColumn = new DataGridBoolColumn();
			logPCTimeStampColumn.AllowNull = false;
			logPCTimeStampColumn.FalseValue = false;
			((DataGridColumnStyle)logPCTimeStampColumn).HeaderText = "PC TimeStamp";
			((DataGridColumnStyle)logPCTimeStampColumn).MappingName = "PCTimestamp";
			logPCTimeStampColumn.TrueValue = true;
			((DataGridColumnStyle)logPCTimeStampColumn).Width = 85;
			logTypeColumn = new CustomDataGridComboBoxColumn();
			((DataGridColumnStyle)logTypeColumn).HeaderText = "Update Rate";
			((DataGridColumnStyle)logTypeColumn).MappingName = "LogMode";
			((DataGridColumnStyle)logTypeColumn).Width = 75;
			logTypeColumn.ComboBox.Items.AddRange((object[])new string[3] { "Any Data", "All Data", "Interval" });
			logTypeColumn.ComboBox.SelectedIndexChanged += OnLogTypeComboBoxSelectedIndexChanged;
			logRateColumn = new CustomDataGridTextBoxColumn();
			((DataGridColumnStyle)logRateColumn).HeaderText = "Rate (User Specified)";
			((DataGridColumnStyle)logRateColumn).MappingName = "LogRate";
			((DataGridColumnStyle)logRateColumn).Width = 50;
			((Control)((DataGridTextBoxColumn)logRateColumn).TextBox).Validating += OnLogRateColumnTextBoxValidating;
			logRateUnitColumn = new CustomDataGridComboBoxColumn();
			((DataGridColumnStyle)logRateUnitColumn).HeaderText = "Unit";
			((DataGridColumnStyle)logRateUnitColumn).MappingName = "LogUnit";
			((DataGridColumnStyle)logRateUnitColumn).Width = 40;
			logRateUnitColumn.ComboBox.Items.AddRange((object[])new string[2] { "ms", "Hz" });
			logConfigDataGridTableStyle.GridColumnStyles.AddRange((DataGridColumnStyle[])(object)new DataGridColumnStyle[6]
			{
				(DataGridColumnStyle)logTypeColumn,
				(DataGridColumnStyle)logRateColumn,
				(DataGridColumnStyle)logRateUnitColumn,
				(DataGridColumnStyle)logPCTimeStampColumn,
				(DataGridColumnStyle)logActiveFaultColumn,
				(DataGridColumnStyle)logInactiveFaultColumn
			});
			logConfigDataGrid.DataSource = logConfigTable.LogConfig.DefaultView;
			((DataView)logConfigDataGrid.DataSource).AllowNew = false;
			((DataView)logConfigDataGrid.DataSource).AllowDelete = false;
			int num = 0;
			foreach (LogConfigTable.LogConfigRow row in logConfigTable.LogConfig.Rows)
			{
				bool isEnabled = row.LogMode == "Interval";
				logRateColumn.SetEnabled(num, isEnabled);
				logRateUnitColumn.SetEnabled(num, isEnabled);
				num++;
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
			//IL_04df: Unknown result type (might be due to invalid IL or missing references)
			//IL_04e9: Expected O, but got Unknown
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(LogManagerView));
			logConfigDataGrid = new DataGrid();
			logConfigDataGridTableStyle = new DataGridTableStyle();
			dataLoggerNameColumn = new DataGridTextBoxColumn();
			logPrefixColumn = new DataGridTextBoxColumn();
			cancelButton = new Button();
			okButton = new Button();
			bottomPanel = new Panel();
			upperPanel = new Panel();
			((ISupportInitialize)logConfigDataGrid).BeginInit();
			((Control)bottomPanel).SuspendLayout();
			((Control)upperPanel).SuspendLayout();
			((Control)this).SuspendLayout();
			logConfigDataGrid.AllowSorting = false;
			logConfigDataGrid.DataMember = "";
			((Control)logConfigDataGrid).Dock = (DockStyle)5;
			logConfigDataGrid.GridLineColor = SystemColors.ActiveCaption;
			logConfigDataGrid.HeaderForeColor = SystemColors.ControlText;
			((Control)logConfigDataGrid).Location = new Point(0, 0);
			((Control)logConfigDataGrid).Name = "logConfigDataGrid";
			logConfigDataGrid.RowHeadersVisible = false;
			logConfigDataGrid.RowHeaderWidth = 0;
			((Control)logConfigDataGrid).Size = new Size(578, 119);
			((Control)logConfigDataGrid).TabIndex = 0;
			logConfigDataGrid.TableStyles.AddRange((DataGridTableStyle[])(object)new DataGridTableStyle[1] { logConfigDataGridTableStyle });
			((Control)logConfigDataGrid).DoubleClick += OnLogConfigDataGridClick;
			logConfigDataGrid.CurrentCellChanged += OnLogConfigDataGridCurrentCellChanged;
			((Control)logConfigDataGrid).Click += OnLogConfigDataGridClick;
			logConfigDataGridTableStyle.AllowSorting = false;
			logConfigDataGridTableStyle.DataGrid = logConfigDataGrid;
			logConfigDataGridTableStyle.GridColumnStyles.AddRange((DataGridColumnStyle[])(object)new DataGridColumnStyle[2]
			{
				(DataGridColumnStyle)dataLoggerNameColumn,
				(DataGridColumnStyle)logPrefixColumn
			});
			logConfigDataGridTableStyle.HeaderForeColor = SystemColors.ControlText;
			logConfigDataGridTableStyle.MappingName = "LogConfig";
			logConfigDataGridTableStyle.RowHeadersVisible = false;
			logConfigDataGridTableStyle.RowHeaderWidth = 0;
			dataLoggerNameColumn.Format = "";
			dataLoggerNameColumn.FormatInfo = null;
			((DataGridColumnStyle)dataLoggerNameColumn).HeaderText = "Data Logger";
			((DataGridColumnStyle)dataLoggerNameColumn).MappingName = "DataLogger";
			((DataGridColumnStyle)dataLoggerNameColumn).ReadOnly = true;
			((DataGridColumnStyle)dataLoggerNameColumn).Width = 75;
			logPrefixColumn.Format = "";
			logPrefixColumn.FormatInfo = null;
			((DataGridColumnStyle)logPrefixColumn).HeaderText = "Prefix";
			((DataGridColumnStyle)logPrefixColumn).MappingName = "LogPrefix";
			((DataGridColumnStyle)logPrefixColumn).NullText = "\"\"";
			((DataGridColumnStyle)logPrefixColumn).Width = 75;
			cancelButton.DialogResult = (DialogResult)2;
			((Control)cancelButton).Location = new Point(520, 5);
			((Control)cancelButton).Name = "cancelButton";
			((Control)cancelButton).Size = new Size(48, 23);
			((Control)cancelButton).TabIndex = 3;
			((Control)cancelButton).Text = "&Cancel";
			((Control)okButton).Location = new Point(464, 5);
			((Control)okButton).Name = "okButton";
			((Control)okButton).Size = new Size(48, 23);
			((Control)okButton).TabIndex = 4;
			((Control)okButton).Text = "&Ok";
			((Control)okButton).Click += OnOkButtonClick;
			((Control)bottomPanel).Controls.Add((Control)(object)okButton);
			((Control)bottomPanel).Controls.Add((Control)(object)cancelButton);
			((Control)bottomPanel).Dock = (DockStyle)2;
			((Control)bottomPanel).Location = new Point(0, 119);
			((Control)bottomPanel).Name = "bottomPanel";
			((Control)bottomPanel).Size = new Size(578, 32);
			((Control)bottomPanel).TabIndex = 5;
			((Control)upperPanel).Controls.Add((Control)(object)logConfigDataGrid);
			((Control)upperPanel).Dock = (DockStyle)5;
			((Control)upperPanel).Location = new Point(0, 0);
			((Control)upperPanel).Name = "upperPanel";
			((Control)upperPanel).Size = new Size(578, 119);
			((Control)upperPanel).TabIndex = 6;
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).CancelButton = (IButtonControl)(object)cancelButton;
			((Form)this).ClientSize = new Size(578, 151);
			((Control)this).Controls.Add((Control)(object)upperPanel);
			((Control)this).Controls.Add((Control)(object)bottomPanel);
			((Form)this).FormBorderStyle = (FormBorderStyle)1;
			((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
			((Form)this).MaximizeBox = false;
			((Form)this).MinimizeBox = false;
			((Control)this).Name = "LogManagerView";
			((Form)this).ShowInTaskbar = false;
			((Form)this).StartPosition = (FormStartPosition)4;
			((Control)this).Text = "Logging Manager";
			((ISupportInitialize)logConfigDataGrid).EndInit();
			((Control)bottomPanel).ResumeLayout(false);
			((Control)upperPanel).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		private void OnLogConfigDataGridClick(object sender, EventArgs e)
		{
			//IL_001d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0023: Invalid comparison between Unknown and I4
			//IL_0049: Unknown result type (might be due to invalid IL or missing references)
			//IL_004e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0096: Unknown result type (might be due to invalid IL or missing references)
			//IL_009d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0083: Unknown result type (might be due to invalid IL or missing references)
			HitTestInfo val = logConfigDataGrid.HitTest(((Control)logConfigDataGrid).PointToClient(Control.MousePosition));
			if ((int)val.Type == 1 && (val.Column == 5 || val.Column == 6 || val.Column == 7))
			{
				DataGridCell currentCell = logConfigDataGrid.CurrentCell;
				if (((DataGridCell)(ref currentCell)).ColumnNumber == 5 && logConfigDataGrid[((DataGridCell)(ref currentCell)).RowNumber, 2].ToString() != "Any Data")
				{
					logConfigDataGrid[currentCell] = true;
				}
				else
				{
					logConfigDataGrid[currentCell] = !(bool)logConfigDataGrid[currentCell];
				}
			}
		}

		private void OnLogConfigDataGridCurrentCellChanged(object sender, EventArgs e)
		{
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			//IL_000c: Unknown result type (might be due to invalid IL or missing references)
			DataGridCell currentCell = logConfigDataGrid.CurrentCell;
			selectedLogConfigRow = ((DataGridCell)(ref currentCell)).RowNumber;
		}

		private void OnLogTypeComboBoxSelectedIndexChanged(object sender, EventArgs e)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0007: Expected O, but got Unknown
			//IL_000d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0012: Unknown result type (might be due to invalid IL or missing references)
			ComboBox val = (ComboBox)sender;
			DataGridCell currentCell = logConfigDataGrid.CurrentCell;
			bool isEnabled = ((ListControl)val).SelectedIndex == 2;
			logRateColumn.SetEnabled(((DataGridCell)(ref currentCell)).RowNumber, isEnabled);
			logRateUnitColumn.SetEnabled(((DataGridCell)(ref currentCell)).RowNumber, isEnabled);
			logConfigDataGrid[((DataGridCell)(ref currentCell)).RowNumber, 5] = (bool)logConfigDataGrid[((DataGridCell)(ref currentCell)).RowNumber, 5] || ((ListControl)val).SelectedIndex != 0;
		}

		private void OnOkButtonClick(object sender, EventArgs e)
		{
			model.SaveConfiguration(logConfigTable);
			((Form)this).DialogResult = (DialogResult)1;
		}

		private void OnLogRateColumnTextBoxValidating(object sender, CancelEventArgs e)
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_000e: Expected O, but got Unknown
			//IL_0050: Unknown result type (might be due to invalid IL or missing references)
			//IL_0030: Unknown result type (might be due to invalid IL or missing references)
			e.Cancel = false;
			TextBox val = (TextBox)sender;
			try
			{
				if (((Control)val).Text.Length != 0)
				{
					int num = int.Parse(((Control)val).Text);
					if (num < 1)
					{
						MessageBox.Show("Please enter a positive integer");
						((Control)val).Text = "1";
						e.Cancel = true;
					}
				}
			}
			catch
			{
				MessageBox.Show("Please enter a positive integer");
				((Control)val).Text = "1";
				e.Cancel = true;
			}
		}
	}
	public class LogStatusView : Form
	{
		private enum MonitorStatus
		{
			Active,
			Inactive,
			Unknown
		}

		private enum LoggingStatus
		{
			LoggingOn,
			Buffering,
			LoggingOff
		}

		private enum ButtonText
		{
			Start,
			Stop
		}

		private const string IndexColumnName = "Index";

		private const string MonitorStatusColumnName = "MonitorStatus";

		private const string ScreenNameColumnName = "ScreenName";

		private const string LogHashIdColumnName = "HashId";

		private const string LogStatusColumnName = "LogStatus";

		private const string LogPrefixColumnName = "LogPrefix";

		private const string LogControlColumnName = "LogControl";

		private DataTable logStatusTable;

		private LogManagerController controller;

		private ArrayList logConfigList;

		private ArrayList uclogConfigList;

		private SortedList buttonList;

		private string[] monitorStatus = new string[3] { "Active", "Inactive", "Unknown" };

		private string[] loggingStatus = new string[3] { "Logging On", "Buffering", "Logging Off" };

		private string[] buttonText = new string[2] { "Start", "Stop" };

		private DataGridTextBoxColumn indexColumn;

		private CustomDataGridIconTextColumn monitorStatusColumn;

		private DataGridTextBoxColumn screenNameColumn;

		private CustomDataGridIconTextColumn loggingStatusColumn;

		private CustomDataGridButtonColumn loggingControlColumn;

		private Panel lowerPanel;

		private Panel upperPanel;

		private Button closeButton;

		private Button startAllButton;

		private Button stopAllButton;

		private DataGrid logStatusDataGrid;

		private ImageList monitorImageList;

		private ImageList loggingImageList;

		private DataGridTableStyle dataGridTableStyle;

		private ImageList buttonImageList;

		private IContainer components;

		public LogStatusView()
		{
			InitializeComponent();
		}

		public void Configure(LogManagerController controller, ArrayList logConfigList, ArrayList uclogConfigList)
		{
			this.controller = controller;
			this.logConfigList = logConfigList;
			this.uclogConfigList = uclogConfigList;
			buttonList = new SortedList();
			logStatusTable = new DataTable("LogStatus");
			InitDataGrid();
			InitDataSet();
			logStatusDataGrid.DataSource = logStatusTable.DefaultView;
			((DataView)logStatusDataGrid.DataSource).AllowNew = false;
			((DataView)logStatusDataGrid.DataSource).AllowDelete = false;
			this.controller.Model.LoggingStateChangedEvent += OnLoggingStateChangedEvent;
		}

		protected override void Dispose(bool disposing)
		{
			controller.Model.LoggingStateChangedEvent -= OnLoggingStateChangedEvent;
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
			//IL_006f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0079: Expected O, but got Unknown
			//IL_0080: Unknown result type (might be due to invalid IL or missing references)
			//IL_008a: Expected O, but got Unknown
			//IL_0091: Unknown result type (might be due to invalid IL or missing references)
			//IL_009b: Expected O, but got Unknown
			//IL_0418: Unknown result type (might be due to invalid IL or missing references)
			//IL_0422: Expected O, but got Unknown
			//IL_0485: Unknown result type (might be due to invalid IL or missing references)
			//IL_048f: Expected O, but got Unknown
			//IL_04f2: Unknown result type (might be due to invalid IL or missing references)
			//IL_04fc: Expected O, but got Unknown
			//IL_0590: Unknown result type (might be due to invalid IL or missing references)
			//IL_059a: Expected O, but got Unknown
			//IL_05db: Unknown result type (might be due to invalid IL or missing references)
			//IL_05e5: Expected O, but got Unknown
			components = new Container();
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(LogStatusView));
			lowerPanel = new Panel();
			stopAllButton = new Button();
			startAllButton = new Button();
			closeButton = new Button();
			upperPanel = new Panel();
			logStatusDataGrid = new DataGrid();
			dataGridTableStyle = new DataGridTableStyle();
			monitorImageList = new ImageList(components);
			loggingImageList = new ImageList(components);
			buttonImageList = new ImageList(components);
			((Control)lowerPanel).SuspendLayout();
			((Control)upperPanel).SuspendLayout();
			((ISupportInitialize)logStatusDataGrid).BeginInit();
			((Control)this).SuspendLayout();
			((Control)lowerPanel).Controls.Add((Control)(object)stopAllButton);
			((Control)lowerPanel).Controls.Add((Control)(object)startAllButton);
			((Control)lowerPanel).Controls.Add((Control)(object)closeButton);
			((Control)lowerPanel).Dock = (DockStyle)2;
			((Control)lowerPanel).Location = new Point(0, 143);
			((Control)lowerPanel).Name = "lowerPanel";
			((Control)lowerPanel).Size = new Size(344, 32);
			((Control)lowerPanel).TabIndex = 0;
			((Control)stopAllButton).Location = new Point(71, 4);
			((Control)stopAllButton).Name = "stopAllButton";
			((Control)stopAllButton).Size = new Size(64, 24);
			((Control)stopAllButton).TabIndex = 2;
			((Control)stopAllButton).Text = "S&top All";
			((Control)stopAllButton).Click += OnStopAllButtonClick;
			((Control)startAllButton).Location = new Point(7, 4);
			((Control)startAllButton).Name = "startAllButton";
			((Control)startAllButton).Size = new Size(64, 24);
			((Control)startAllButton).TabIndex = 1;
			((Control)startAllButton).Text = "&Start All";
			((Control)startAllButton).Click += OnStartAllButtonClick;
			closeButton.DialogResult = (DialogResult)2;
			((Control)closeButton).Location = new Point(288, 4);
			((Control)closeButton).Name = "closeButton";
			((Control)closeButton).Size = new Size(48, 24);
			((Control)closeButton).TabIndex = 3;
			((Control)closeButton).Text = "&Close";
			((Control)upperPanel).Controls.Add((Control)(object)logStatusDataGrid);
			((Control)upperPanel).Dock = (DockStyle)5;
			((Control)upperPanel).Location = new Point(0, 0);
			((Control)upperPanel).Name = "upperPanel";
			((Control)upperPanel).Size = new Size(344, 143);
			((Control)upperPanel).TabIndex = 1;
			logStatusDataGrid.DataMember = "";
			((Control)logStatusDataGrid).Dock = (DockStyle)5;
			logStatusDataGrid.HeaderForeColor = SystemColors.ControlText;
			((Control)logStatusDataGrid).Location = new Point(0, 0);
			((Control)logStatusDataGrid).Name = "logStatusDataGrid";
			logStatusDataGrid.PreferredRowHeight = 30;
			logStatusDataGrid.RowHeadersVisible = false;
			logStatusDataGrid.RowHeaderWidth = 0;
			((Control)logStatusDataGrid).Size = new Size(344, 143);
			((Control)logStatusDataGrid).TabIndex = 0;
			logStatusDataGrid.TableStyles.AddRange((DataGridTableStyle[])(object)new DataGridTableStyle[1] { dataGridTableStyle });
			dataGridTableStyle.AllowSorting = false;
			dataGridTableStyle.DataGrid = logStatusDataGrid;
			dataGridTableStyle.HeaderForeColor = SystemColors.ControlText;
			dataGridTableStyle.MappingName = "LogStatus";
			dataGridTableStyle.RowHeadersVisible = false;
			dataGridTableStyle.RowHeaderWidth = 0;
			monitorImageList.ImageStream = (ImageListStreamer)componentResourceManager.GetObject("monitorImageList.ImageStream");
			monitorImageList.TransparentColor = Color.Transparent;
			monitorImageList.Images.SetKeyName(0, "");
			monitorImageList.Images.SetKeyName(1, "");
			monitorImageList.Images.SetKeyName(2, "");
			loggingImageList.ImageStream = (ImageListStreamer)componentResourceManager.GetObject("loggingImageList.ImageStream");
			loggingImageList.TransparentColor = Color.Transparent;
			loggingImageList.Images.SetKeyName(0, "");
			loggingImageList.Images.SetKeyName(1, "");
			loggingImageList.Images.SetKeyName(2, "");
			buttonImageList.ImageStream = (ImageListStreamer)componentResourceManager.GetObject("buttonImageList.ImageStream");
			buttonImageList.TransparentColor = Color.Transparent;
			buttonImageList.Images.SetKeyName(0, "");
			buttonImageList.Images.SetKeyName(1, "");
			((Form)this).AutoScaleBaseSize = new Size(5, 13);
			((Form)this).ClientSize = new Size(344, 175);
			((Control)this).Controls.Add((Control)(object)upperPanel);
			((Control)this).Controls.Add((Control)(object)lowerPanel);
			((Form)this).FormBorderStyle = (FormBorderStyle)1;
			((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
			((Form)this).KeyPreview = true;
			((Form)this).MaximizeBox = false;
			((Form)this).MinimizeBox = false;
			((Control)this).Name = "LogStatusView";
			((Form)this).ShowInTaskbar = false;
			((Form)this).StartPosition = (FormStartPosition)4;
			((Control)this).Text = "Log Status";
			((Control)this).KeyUp += new KeyEventHandler(OnLogStatusViewKeyUp);
			((Control)lowerPanel).ResumeLayout(false);
			((Control)upperPanel).ResumeLayout(false);
			((ISupportInitialize)logStatusDataGrid).EndInit();
			((Control)this).ResumeLayout(false);
		}

		private void InitDataSet()
		{
			logStatusTable.Columns.Add("Index", typeof(int));
			logStatusTable.Columns.Add("MonitorStatus", typeof(MonitorStatus));
			logStatusTable.Columns.Add("ScreenName", typeof(string));
			logStatusTable.Columns.Add("HashId", typeof(int));
			logStatusTable.Columns.Add("LogStatus", typeof(LoggingStatus));
			logStatusTable.Columns.Add("LogPrefix", typeof(string));
			logStatusTable.Columns.Add("LogControl", typeof(int));
			int num = 0;
			ArrayList arrayList = new ArrayList();
			ArrayList arrayList2 = new ArrayList();
			foreach (LogConfig logConfig in logConfigList)
			{
				DataRow dataRow = logStatusTable.NewRow();
				dataRow["Index"] = num + 1;
				SortedList specialHeaders = logConfig.SpecialHeaders;
				if (specialHeaders[SpecialHeaders.ScreenStatus] != null)
				{
					try
					{
						dataRow["MonitorStatus"] = (MonitorStatus)Enum.Parse(typeof(MonitorStatus), specialHeaders[SpecialHeaders.ScreenStatus].ToString(), ignoreCase: true);
					}
					catch
					{
						dataRow["MonitorStatus"] = MonitorStatus.Unknown;
					}
				}
				else
				{
					dataRow["MonitorStatus"] = MonitorStatus.Unknown;
				}
				if (specialHeaders[SpecialHeaders.ScreenName] != null)
				{
					dataRow["ScreenName"] = specialHeaders[SpecialHeaders.ScreenName].ToString();
				}
				else
				{
					dataRow["ScreenName"] = "";
				}
				dataRow["LogPrefix"] = logConfig.LogName;
				ILogger logger = controller.Model.GetLogger(logConfig.LogName);
				if (logger == null)
				{
					continue;
				}
				if ((MonitorStatus)dataRow["MonitorStatus"] == MonitorStatus.Active)
				{
					dataRow["HashId"] = logger.GetHashCode();
					Button button = loggingControlColumn.GetButton(num);
					((Control)button).Click += OnButtonClicked;
					buttonList[((object)button).GetHashCode()] = num;
					dataRow["LogControl"] = num;
					SetLoggingStatus(dataRow, logger.State);
					arrayList.Add(logConfig);
					foreach (UCLogConfig uclogConfig in uclogConfigList)
					{
						if (logConfig.LogName == uclogConfig.LogName)
						{
							arrayList2.Add(uclogConfig);
						}
					}
				}
				else
				{
					dataRow["HashId"] = logger.GetHashCode();
					Button button2 = loggingControlColumn.GetButton(num);
					((Control)button2).Enabled = false;
					buttonList[((object)button2).GetHashCode()] = num;
					dataRow["LogControl"] = num;
					SetLoggingStatus(dataRow, LoggingState.Idle);
				}
				logStatusTable.Rows.Add(dataRow);
				num++;
			}
			logConfigList = arrayList;
			uclogConfigList = arrayList2;
		}

		private void SetButton(Button button, ButtonText buttonText)
		{
			((ButtonBase)button).Image = buttonImageList.Images[(int)buttonText];
			((ButtonBase)button).ImageAlign = (ContentAlignment)256;
			((Control)button).Text = this.buttonText[(int)buttonText];
		}

		private void InitDataGrid()
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_000b: Expected O, but got Unknown
			//IL_009b: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a5: Expected O, but got Unknown
			indexColumn = new DataGridTextBoxColumn();
			((DataGridColumnStyle)indexColumn).HeaderText = "#";
			((DataGridColumnStyle)indexColumn).Alignment = (HorizontalAlignment)0;
			((DataGridColumnStyle)indexColumn).MappingName = "Index";
			((DataGridColumnStyle)indexColumn).ReadOnly = true;
			((DataGridColumnStyle)indexColumn).Width = 20;
			monitorStatusColumn = new CustomDataGridIconTextColumn(monitorImageList, monitorStatus, logStatusDataGrid);
			((DataGridColumnStyle)monitorStatusColumn).HeaderText = "Monitor Status";
			((DataGridColumnStyle)monitorStatusColumn).MappingName = "MonitorStatus";
			((DataGridColumnStyle)monitorStatusColumn).Width = 80;
			screenNameColumn = new DataGridTextBoxColumn();
			((DataGridColumnStyle)screenNameColumn).HeaderText = "Screen Name";
			((DataGridColumnStyle)screenNameColumn).MappingName = "ScreenName";
			((DataGridColumnStyle)screenNameColumn).ReadOnly = true;
			((DataGridColumnStyle)screenNameColumn).Width = 90;
			loggingStatusColumn = new CustomDataGridIconTextColumn(loggingImageList, loggingStatus, logStatusDataGrid);
			((DataGridColumnStyle)loggingStatusColumn).HeaderText = "Logging Status";
			((DataGridColumnStyle)loggingStatusColumn).MappingName = "LogStatus";
			((DataGridColumnStyle)loggingStatusColumn).Width = 80;
			loggingControlColumn = new CustomDataGridButtonColumn();
			((DataGridColumnStyle)loggingControlColumn).HeaderText = "";
			((DataGridColumnStyle)loggingControlColumn).MappingName = "LogControl";
			((DataGridColumnStyle)loggingControlColumn).Width = 50;
			dataGridTableStyle.GridColumnStyles.AddRange((DataGridColumnStyle[])(object)new DataGridColumnStyle[5]
			{
				(DataGridColumnStyle)indexColumn,
				(DataGridColumnStyle)monitorStatusColumn,
				(DataGridColumnStyle)screenNameColumn,
				(DataGridColumnStyle)loggingStatusColumn,
				(DataGridColumnStyle)loggingControlColumn
			});
		}

		private void SetLoggingStatus(DataRow row, LoggingState logState)
		{
			Button button = loggingControlColumn.GetButton((int)row["LogControl"]);
			switch (logState)
			{
			case LoggingState.Logging:
				row["LogStatus"] = LoggingStatus.LoggingOn;
				SetButton(button, ButtonText.Stop);
				break;
			case LoggingState.Buffering:
				row["LogStatus"] = LoggingStatus.Buffering;
				SetButton(button, ButtonText.Start);
				break;
			case LoggingState.Idle:
				row["LogStatus"] = LoggingStatus.LoggingOff;
				SetButton(button, ButtonText.Start);
				break;
			case LoggingState.Starting:
				break;
			}
		}

		private void StartAllLoggers()
		{
			controller.StartAllLoggers(logConfigList, uclogConfigList);
		}

		private void StopAllLoggers()
		{
			controller.StopAllLoggers();
		}

		private void StartLogger(LogConfig logConfig)
		{
			controller.StartLogger(logConfig);
		}

		private void StopLogger(LogConfig logConfig)
		{
			controller.StopLogger(logConfig.LogName);
		}

		private void StartUCLogger(UCLogConfig uclogConfig)
		{
			controller.StartUCLogger(uclogConfig);
		}

		private void StopUCLogger(UCLogConfig uclogConfig)
		{
			controller.StopUCLogger(uclogConfig.LogName);
		}

		private LogConfig GetLogConfig(int row)
		{
			DataRow dataRow = logStatusTable.Rows[row];
			string text = dataRow["LogPrefix"].ToString();
			LogConfig result = default(LogConfig);
			foreach (LogConfig logConfig in logConfigList)
			{
				if (logConfig.LogName == text)
				{
					result = logConfig;
					return result;
				}
			}
			return result;
		}

		private UCLogConfig GetUCLogConfig(int row)
		{
			DataRow dataRow = logStatusTable.Rows[row];
			string text = dataRow["LogPrefix"].ToString();
			UCLogConfig result = default(UCLogConfig);
			foreach (UCLogConfig uclogConfig in uclogConfigList)
			{
				if (uclogConfig.LogName == text)
				{
					result = uclogConfig;
					return result;
				}
			}
			return result;
		}

		private void OnStartAllButtonClick(object sender, EventArgs e)
		{
			StartAllLoggers();
		}

		private void OnStopAllButtonClick(object sender, EventArgs e)
		{
			StopAllLoggers();
		}

		private void OnLogStatusViewKeyUp(object sender, KeyEventArgs e)
		{
			//IL_0001: Unknown result type (might be due to invalid IL or missing references)
			//IL_0006: Unknown result type (might be due to invalid IL or missing references)
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_000c: Invalid comparison between Unknown and I4
			//IL_001d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0023: Expected I4, but got Unknown
			Keys keyCode = e.KeyCode;
			if ((int)keyCode == 27)
			{
				((Form)this).DialogResult = (DialogResult)2;
				return;
			}
			int num = 49;
			int num2 = 57;
			int num3 = (int)e.KeyCode;
			if (num > num3 || num3 > num2)
			{
				return;
			}
			int num4 = num3 - num;
			DataRow dataRow = logStatusTable.Rows[num4];
			if ((MonitorStatus)dataRow["MonitorStatus"] == MonitorStatus.Active)
			{
				LoggingStatus loggingStatus = (LoggingStatus)dataRow["LogStatus"];
				LogConfig logConfig = GetLogConfig(num4);
				UCLogConfig uCLogConfig = GetUCLogConfig(num4);
				if (loggingStatus == LoggingStatus.LoggingOn)
				{
					StopLogger(logConfig);
					StopUCLogger(uCLogConfig);
				}
				else
				{
					StartLogger(logConfig);
					StartUCLogger(uCLogConfig);
				}
			}
		}

		private void OnButtonClicked(object sender, EventArgs e)
		{
			int num = (int)buttonList[sender.GetHashCode()];
			Button button = loggingControlColumn.GetButton(num);
			LogConfig logConfig = GetLogConfig(num);
			UCLogConfig uCLogConfig = GetUCLogConfig(num);
			if (((Control)button).Text == ButtonText.Start.ToString())
			{
				StartLogger(logConfig);
				StartUCLogger(uCLogConfig);
			}
			else
			{
				StopLogger(logConfig);
				StopUCLogger(uCLogConfig);
			}
		}

		private void OnLoggingStateChangedEvent(object caller, LoggingState state)
		{
			if (!((Control)this).InvokeRequired)
			{
				ILogger logger = (ILogger)caller;
				DataRow row = logStatusTable.Select("HashId= '" + logger.GetHashCode() + "'")[0];
				SetLoggingStatus(row, state);
			}
			else
			{
				LoggingStateChangedEventHandler loggingStateChangedEventHandler = OnLoggingStateChangedEvent;
				((Control)this).BeginInvoke((Delegate)loggingStateChangedEventHandler, new object[2] { caller, state });
			}
		}
	}
}
namespace Cummins.Logging
{
	public class LogModel
	{
		public class PublicDataParameters : Dictionary<ushort, List<string>>
		{
		}

		internal const string Address = "address";

		internal const string DisplayName = "displayName";

		internal const string Units = "units";

		internal const string ActiveFaultsColumn = "ActiveFaults";

		internal const string InactiveFaultsColumn = "InactiveFaults";

		internal const string TimeStamp = "DLA Timestamp";

		internal const string PCTimeStamp = "PC Timestamp";

		internal const string Index = "index";

		internal const string EventNumber = "EventNumber";

		internal const char UnderScore = '_';

		internal const char Dot = '.';

		internal const int StartOfAddress = 1;

		private const string ActiveFaultsFilter = "CurrentStatus = 'Active'";

		private const string InactiveFaultsFilter = "CurrentStatus = 'PrevActive'";

		internal const int MaxMediaPercentage = 98;

		private const int fixedColumn = 4;

		private const int fixedUCLColumn = 3;

		private Hashtable columnNameTable = new Hashtable();

		private Hashtable uclcolumnNameTable = new Hashtable();

		private bool suspendLoggingActiveFaults;

		internal static ArrayList MonitoredParameters = new ArrayList();

		private LoggingOptions options;

		private TriggerLoggingOptions triggerOptions;

		private DataTable logBuffer;

		private DataTable uclogBuffer;

		private DataTable faultsTable;

		private LoggingState state;

		private UCLState ucloggingState;

		private LogInstance loggingInstance;

		private string activeFaults = string.Empty;

		private string inactiveFaults = string.Empty;

		private int faultColumnIndex = -1;

		private int inactiveFaultColumnIndex = -1;

		private int startConditionTrueIndex = -1;

		private int stopConditionTrueIndex = -1;

		private int uclstartConditionTrueIndex = -1;

		private int uclstopConditionTrueIndex = -1;

		private int loggingCycles;

		private Mode mode;

		private Trigger startTrigger;

		private Trigger stopTrigger;

		private ManagementObject disk;

		private int numberOfDLParameters;

		private int numberOfNonDLParameters;

		private PublicDataParameters _publicDataCount;

		private PublicDataParameters _uclPublicDataCount;

		public IModuleNetwork Network
		{
			set
			{
				options.Network = value;
			}
		}

		public LoggingOptions Options
		{
			get
			{
				if (options == null)
				{
					options = new LoggingOptions();
				}
				return options;
			}
		}

		public TriggerLoggingOptions TriggerOptions
		{
			get
			{
				if (triggerOptions == null)
				{
					triggerOptions = new TriggerLoggingOptions();
				}
				return triggerOptions;
			}
		}

		public LoggingState State
		{
			get
			{
				return state;
			}
			set
			{
				LoggingState loggingState = State;
				Trace.WriteLine("State changing from " + loggingState.ToString() + " to " + value);
				if (value == LoggingState.Logging)
				{
					SetupFaultLogging();
					SetupUCLFaultLogging();
					SetupEventNumberLogging();
				}
				if (loggingState != value)
				{
					if (value == LoggingState.Buffering || value == LoggingState.Logging)
					{
						SetupPCTimeLogging();
						SetupUCLPCTimeLogging();
					}
					StateChangeEventArgs e = new StateChangeEventArgs(value, loggingState, LogBuffer.Columns);
					RaiseStateChangingEvent(e);
				}
				switch (value)
				{
				case LoggingState.Idle:
				case LoggingState.Abort:
					CleanUp();
					state = EndState();
					ResetMode();
					break;
				case LoggingState.Starting:
					state = value;
					break;
				case LoggingState.Stopping:
					loggingCycles++;
					state = value;
					break;
				case LoggingState.Buffering:
					state = value;
					break;
				case LoggingState.Logging:
					state = value;
					break;
				default:
					state = value;
					break;
				}
				if (loggingState != state)
				{
					StateChangeEventArgs e2 = new StateChangeEventArgs(state, loggingState, LogBuffer.Columns);
					RaiseStateChangedEvent(e2);
				}
			}
		}

		public UCLState UCLoggingState
		{
			get
			{
				return ucloggingState;
			}
			set
			{
				UCLState uCLoggingState = UCLoggingState;
				if (uCLoggingState != value)
				{
					if (value == UCLState.Buffering)
					{
						SetupUCLFaultLogging();
						SetupUCLPCTimeLogging();
					}
					UCLStateChangeEventArgs e = new UCLStateChangeEventArgs(value, uCLoggingState, UCLogBuffer.Columns);
					RaiseUCLStateChangingEvent(e);
				}
				ucloggingState = value;
				if (uCLoggingState != ucloggingState)
				{
					UCLStateChangeEventArgs e2 = new UCLStateChangeEventArgs(ucloggingState, uCLoggingState, UCLogBuffer.Columns);
					RaiseUCLStateChangedEvent(e2);
				}
			}
		}

		public LogInstance LoggingInstance
		{
			get
			{
				return loggingInstance;
			}
			set
			{
				loggingInstance = value;
			}
		}

		public string ActiveFaults
		{
			get
			{
				return activeFaults;
			}
			set
			{
				activeFaults = value;
			}
		}

		public string InactiveFaults
		{
			get
			{
				return inactiveFaults;
			}
			set
			{
				inactiveFaults = value;
			}
		}

		public int ActiveFaultsIndex => faultColumnIndex;

		public int InactiveFaultsIndex => inactiveFaultColumnIndex;

		public DataTable LogBuffer
		{
			get
			{
				if (logBuffer == null)
				{
					logBuffer = new DataTable();
					AddIndexColumnToLogBuffer();
					AddColumnToLogBuffer("DLA Timestamp", typeof(uint), "none", NetworkType.J1939, "DLA Timestamp", null);
					LogBuffer.Columns["DLA Timestamp"].ExtendedProperties["Active"] = false;
					AddPCTimeColumnToLogBuffer();
					AddEventNumberColumnToLogBuffer();
				}
				return logBuffer;
			}
		}

		public DataTable UCLogBuffer
		{
			get
			{
				if (uclogBuffer == null)
				{
					uclogBuffer = new DataTable();
					AddIndexColumnToUCLogBuffer();
					AddColumnToUCLogBuffer("DLA Timestamp", typeof(uint), "none", NetworkType.J1939, "DLA Timestamp", null);
					UCLogBuffer.Columns["DLA Timestamp"].ExtendedProperties["Active"] = false;
					AddPCTimeColumnToUCLogBuffer();
				}
				return uclogBuffer;
			}
		}

		public DataTable Faults
		{
			get
			{
				if (faultsTable == null)
				{
					faultsTable = new DataTable("FaultsTable");
					faultsTable.Columns.Add("FaultCode", typeof(string));
					faultsTable.Columns.Add("FaultCount", typeof(int));
					faultsTable.Columns.Add("PreviousStatus", typeof(string));
					faultsTable.Columns.Add("CurrentStatus", typeof(string));
					faultsTable.Columns.Add("SourceAddress", typeof(string));
					faultsTable.Columns.Add("BlockingStatus", typeof(bool));
				}
				return faultsTable;
			}
		}

		public int StartConditionTrueIndex
		{
			get
			{
				return startConditionTrueIndex;
			}
			set
			{
				startConditionTrueIndex = value;
			}
		}

		public int StopConditionTrueIndex
		{
			get
			{
				return stopConditionTrueIndex;
			}
			set
			{
				stopConditionTrueIndex = value;
			}
		}

		public Mode Mode
		{
			get
			{
				return mode;
			}
			set
			{
				mode = value;
			}
		}

		public Trigger StartTrigger
		{
			get
			{
				if (startTrigger == null)
				{
					startTrigger = new Trigger(TriggerOptions.StartTrigger, this);
				}
				return startTrigger;
			}
		}

		public Trigger StopTrigger
		{
			get
			{
				if (stopTrigger == null)
				{
					stopTrigger = new Trigger(TriggerOptions.StopTrigger, this);
				}
				return stopTrigger;
			}
		}

		public ManagementObject LoggingDiskInfo
		{
			get
			{
				//IL_0030: Unknown result type (might be due to invalid IL or missing references)
				//IL_003a: Expected O, but got Unknown
				string logFileName = Options.GetLogFileName();
				string text = logFileName.Substring(0, 2);
				if (disk == null)
				{
					string text2 = "win32_logicaldisk.deviceid=\"" + text + "\"";
					disk = new ManagementObject(text2);
				}
				disk.Get();
				return disk;
			}
		}

		public int EDLRepeatsLeft
		{
			get
			{
				int result = -1;
				if (mode == Mode.EventDriven)
				{
					result = loggingCycles;
				}
				return result;
			}
		}

		public int EDLTotalRepeats
		{
			get
			{
				int result = -1;
				if (mode == Mode.EventDriven)
				{
					result = TriggerOptions.RepeatCount;
				}
				return result;
			}
		}

		public int UCLStartConditionTrueIndex
		{
			get
			{
				return uclstartConditionTrueIndex;
			}
			set
			{
				uclstartConditionTrueIndex = value;
			}
		}

		public int UCLStopConditionTrueIndex
		{
			get
			{
				return uclstopConditionTrueIndex;
			}
			set
			{
				uclstopConditionTrueIndex = value;
			}
		}

		public bool SuspendLoggingActiveFaults
		{
			get
			{
				return suspendLoggingActiveFaults;
			}
			set
			{
				suspendLoggingActiveFaults = value;
			}
		}

		public PublicDataParameters PublicDataCount
		{
			get
			{
				if (_publicDataCount == null)
				{
					_publicDataCount = new PublicDataParameters();
				}
				return _publicDataCount;
			}
		}

		public PublicDataParameters UCLPublicDataCount
		{
			get
			{
				if (_uclPublicDataCount == null)
				{
					_uclPublicDataCount = new PublicDataParameters();
				}
				return _uclPublicDataCount;
			}
		}

		public event EventHandler MonitorListChangingEvent;

		public event EventHandler UCLMonitorListChangingEvent;

		public event MonitoredListChangedEventHandler MonitoredListChangedEvent;

		public event UCLMonitoredListChangedEventHandler UCLMonitoredListChangedEvent;

		public event StateChangedEventHandler StateChangedEvent;

		public event StateChangingEventHandler StateChangingEvent;

		public event UCLStateChangedEventHandler UCLStateChangedEvent;

		public event UCLStateChangingEventHandler UCLStateChangingEvent;

		public void Initialize()
		{
			LoggingOptions loggingOptions = Options;
			loggingOptions.FaultsLoggingOptionChangedEvent = (EventHandler)Delegate.Combine(loggingOptions.FaultsLoggingOptionChangedEvent, new EventHandler(OnFaultLoggingOptionsChanged));
			LoggingOptions loggingOptions2 = Options;
			loggingOptions2.LogPCTimeStampOptionChanged = (EventHandler)Delegate.Combine(loggingOptions2.LogPCTimeStampOptionChanged, new EventHandler(OnLogPCTimeStampOptionChanged));
			LoggingOptions loggingOptions3 = Options;
			loggingOptions3.MonitorModeChangedEvent = (EventHandler)Delegate.Combine(loggingOptions3.MonitorModeChangedEvent, new EventHandler(OnMonitorModeChanged));
			triggerOptions = new TriggerLoggingOptions();
			TriggerLoggingOptions triggerLoggingOptions = triggerOptions;
			triggerLoggingOptions.StartTriggerChangedEvent = (EventHandler)Delegate.Combine(triggerLoggingOptions.StartTriggerChangedEvent, new EventHandler(OnStartTriggerChanged));
			TriggerLoggingOptions triggerLoggingOptions2 = triggerOptions;
			triggerLoggingOptions2.StopTriggerChangedEvent = (EventHandler)Delegate.Combine(triggerLoggingOptions2.StopTriggerChangedEvent, new EventHandler(OnStopTriggerChanged));
			TriggerLoggingOptions triggerLoggingOptions3 = triggerOptions;
			triggerLoggingOptions3.RepeatCountChangedEvent = (EventHandler)Delegate.Combine(triggerLoggingOptions3.RepeatCountChangedEvent, new EventHandler(OnEDLRepeatCountChanged));
			Options.Initialize();
			State = LoggingState.Idle;
		}

		public void Add(string parameterName, string units, IAddressValue sourceAddress, NetworkType networkType, bool isJ1939Data)
		{
			if (parameterName == null || parameterName.Length == 0)
			{
				throw new ArgumentNullException("parameterName");
			}
			RaiseMonitorListChangingEvent();
			MonitoredListChangedEventArgs e;
			lock (this)
			{
				if (isJ1939Data)
				{
					AddPublicParameter(PublicDataCount, sourceAddress, parameterName);
				}
				string columnName = ColumnName(parameterName, sourceAddress);
				AddColumnToLogBuffer(columnName, typeof(string), units, networkType, parameterName, sourceAddress);
				e = new MonitoredListChangedEventArgs(LogBuffer.Clone());
				if (!MonitoredParameters.Contains(sourceAddress.Value + ":" + parameterName))
				{
					MonitoredParameters.Add(sourceAddress.Value + ":" + parameterName);
				}
			}
			RaiseMonitoredListChangedEvent(e);
		}

		public void AddUCL(string parameterName, string units, IAddressValue sourceAddress, NetworkType networkType, bool isJ1939Data)
		{
			if (parameterName == null || parameterName.Length == 0)
			{
				throw new ArgumentNullException("parameterName");
			}
			RaiseUCLMonitorListChangingEvent();
			UCLMonitoredListChangedEventArgs e;
			lock (this)
			{
				if (isJ1939Data)
				{
					AddPublicParameter(UCLPublicDataCount, sourceAddress, parameterName);
				}
				string columnName = ColumnName(parameterName, sourceAddress);
				AddColumnToUCLogBuffer(columnName, typeof(string), units, networkType, parameterName, sourceAddress);
				e = new UCLMonitoredListChangedEventArgs(UCLogBuffer.Clone());
				if (!MonitoredParameters.Contains(sourceAddress.Value + ":" + parameterName))
				{
					MonitoredParameters.Add(sourceAddress.Value + ":" + parameterName);
				}
			}
			RaiseUCLMonitoredListChangedEvent(e);
		}

		public void Remove(string parameterName, string units, IAddressValue sourceAddress, NetworkType networkType, bool isJ1939Data)
		{
			if (parameterName == null || parameterName.Length == 0)
			{
				throw new ArgumentNullException("parameterName");
			}
			RaiseMonitorListChangingEvent();
			lock (this)
			{
				if (isJ1939Data)
				{
					RemovePublicParameter(PublicDataCount, sourceAddress, parameterName);
				}
				string text = ColumnName(parameterName, sourceAddress);
				RemoveColumn(text);
				BuildMonitoredListChangedEventArgs();
				if (columnNameTable[text] != null)
				{
					MonitoredParameters.Remove(sourceAddress.Value + ":" + parameterName);
				}
			}
		}

		public void RemoveUCL(string parameterName, string units, IAddressValue sourceAddress, NetworkType networkType, bool isJ1939Data)
		{
			if (parameterName == null || parameterName.Length == 0)
			{
				throw new ArgumentNullException("parameterName");
			}
			RaiseUCLMonitorListChangingEvent();
			lock (this)
			{
				if (isJ1939Data)
				{
					RemovePublicParameter(UCLPublicDataCount, sourceAddress, parameterName);
				}
				string text = ColumnName(parameterName, sourceAddress);
				RemoveColumnUCL(text);
				BuildMonitoredListChangedUCLEventArgs();
				if (uclcolumnNameTable[text] != null)
				{
					MonitoredParameters.Remove(sourceAddress.Value + ":" + parameterName);
				}
			}
		}

		public void Add(uint address, int offset, uint length, string units, IAddressValue sourceAddress, string displayName)
		{
			RaiseMonitorListChangingEvent();
			MonitoredListChangedEventArgs e;
			lock (this)
			{
				string columnName = ColumnName(address, offset, length, sourceAddress);
				if (displayName == null || displayName.Length == 0)
				{
					displayName = address.ToString("X8");
				}
				AddColumnToLogBuffer(columnName, typeof(string), units, NetworkType.J1939, displayName, sourceAddress);
				e = new MonitoredListChangedEventArgs(LogBuffer.Clone());
			}
			RaiseMonitoredListChangedEvent(e);
		}

		public void AddUCL(uint address, int offset, uint length, string units, IAddressValue sourceAddress, string displayName)
		{
			RaiseUCLMonitorListChangingEvent();
			UCLMonitoredListChangedEventArgs e;
			lock (this)
			{
				string columnName = ColumnName(address, offset, length, sourceAddress);
				if (displayName == null || displayName.Length == 0)
				{
					displayName = address.ToString("X8");
				}
				AddColumnToUCLogBuffer(columnName, typeof(string), units, NetworkType.J1939, displayName, sourceAddress);
				e = new UCLMonitoredListChangedEventArgs(UCLogBuffer.Clone());
			}
			RaiseUCLMonitoredListChangedEvent(e);
		}

		public void Remove(uint address, int offset, uint length, IAddressValue sourceAddress)
		{
			RaiseMonitorListChangingEvent();
			lock (this)
			{
				string columnName = ColumnName(address, offset, length, sourceAddress);
				RemoveColumn(columnName);
				BuildMonitoredListChangedEventArgs();
			}
		}

		public void RemoveUCL(uint address, int offset, uint length, IAddressValue sourceAddress)
		{
			RaiseUCLMonitorListChangingEvent();
			string columnName = ColumnName(address, offset, length, sourceAddress);
			RemoveColumnUCL(columnName);
			BuildMonitoredListChangedUCLEventArgs();
		}

		public void RemoveAllParameters()
		{
			RaiseMonitorListChangingEvent();
			MonitoredListChangedEventArgs e;
			lock (this)
			{
				while (logBuffer.Columns.Count != 4)
				{
					string columnName = logBuffer.Columns[4].ColumnName;
					if (logBuffer.Columns[4].ExtendedProperties["address"] is IAddressValue addressValue)
					{
						DecrementNumberOfParametersInAddressType(addressValue.Type);
					}
					if (columnName == "ActiveFaults" || columnName == "InactiveFaults" || columnName.StartsWith('_'.ToString()))
					{
						columnNameTable.Remove(columnName);
					}
					logBuffer.Columns.RemoveAt(4);
				}
				MonitoredParameters.Clear();
				PublicDataCount.Clear();
				UCLPublicDataCount.Clear();
				e = BuildMonitoredListChangedEventArgs();
			}
			RaiseMonitoredListChangedEvent(e);
		}

		public void RemoveAllParametersUCL()
		{
			RaiseUCLMonitorListChangingEvent();
			UCLMonitoredListChangedEventArgs e;
			lock (this)
			{
				while (uclogBuffer.Columns.Count != 3)
				{
					string columnName = uclogBuffer.Columns[3].ColumnName;
					if (uclogBuffer.Columns[3].ExtendedProperties["address"] is IAddressValue addressValue)
					{
						DecrementNumberOfParametersInUCLAddressType(addressValue.Type);
					}
					if (columnName == "ActiveFaults" || columnName == "InactiveFaults" || columnName.StartsWith('_'.ToString()))
					{
						uclcolumnNameTable.Remove(columnName);
					}
					uclogBuffer.Columns.RemoveAt(3);
				}
				MonitoredParameters.Clear();
				e = BuildMonitoredListChangedUCLEventArgs();
			}
			RaiseUCLMonitoredListChangedEvent(e);
		}

		public void Add(ParameterListEventArgs parameterList)
		{
			RaiseMonitorListChangingEvent();
			lock (this)
			{
				foreach (string key in parameterList.Parameters.Keys)
				{
					IParameterModel parameterModel = (IParameterModel)parameterList.Parameters[key];
					if (parameterModel == null)
					{
						continue;
					}
					IAddressValue sourceAddress = parameterModel.SourceAddress;
					try
					{
						string text2 = key.Substring(key.IndexOf(":") + 1);
						if (parameterModel.DataType == ParameterType.Value || parameterModel.DataType == ParameterType.Enumeration)
						{
							string columnName = ColumnName(parameterModel.Name, sourceAddress);
							AddColumnToLogBuffer(columnName, typeof(string), parameterModel.EngineeringUnits, NetworkType.J1939, parameterModel.Name, sourceAddress);
							if (!MonitoredParameters.Contains(sourceAddress.Value + ":" + parameterModel.Name))
							{
								MonitoredParameters.Add(sourceAddress.Value + ":" + parameterModel.Name);
							}
						}
						else
						{
							SetCoordinates(text2, parameterModel);
							uint length = ((parameterModel is IDataBlockModel) ? 1u : parameterModel.Length);
							string text3 = text2;
							if (text2.IndexOf(':') > 0)
							{
								text3 = text2.Substring(text2.IndexOf(':') + 1);
							}
							string columnName = ColumnName(parameterModel.Address, parameterModel.Offset, length, sourceAddress);
							if (text3 == null || text3.Length == 0)
							{
								text3 = parameterModel.Address.ToString("X8");
							}
							AddColumnToLogBuffer(columnName, typeof(string), parameterModel.EngineeringUnits, NetworkType.J1939, text3, sourceAddress);
						}
						if (parameterModel is IPublicDataModel)
						{
							AddPublicParameter(PublicDataCount, sourceAddress, text2);
						}
					}
					catch
					{
					}
				}
			}
			MonitoredListChangedEventArgs e = new MonitoredListChangedEventArgs(LogBuffer.Clone());
			RaiseMonitoredListChangedEvent(e);
		}

		public void AddUCL(ParameterListEventArgs parameterList)
		{
			RaiseUCLMonitorListChangingEvent();
			lock (this)
			{
				foreach (string key in parameterList.Parameters.Keys)
				{
					IParameterModel parameterModel = (IParameterModel)parameterList.Parameters[key];
					if (parameterModel == null)
					{
						continue;
					}
					IAddressValue sourceAddress = parameterModel.SourceAddress;
					try
					{
						string text2 = key.Substring(key.IndexOf(":") + 1);
						if (parameterModel.DataType == ParameterType.Value || parameterModel.DataType == ParameterType.Enumeration)
						{
							string columnName = ColumnName(parameterModel.Name, sourceAddress);
							AddColumnToUCLogBuffer(columnName, typeof(string), parameterModel.EngineeringUnits, NetworkType.J1939, parameterModel.Name, sourceAddress);
							if (!MonitoredParameters.Contains(sourceAddress.Value + ":" + parameterModel.Name))
							{
								MonitoredParameters.Add(sourceAddress.Value + ":" + parameterModel.Name);
							}
						}
						else
						{
							SetCoordinates(text2, parameterModel);
							uint length = ((parameterModel is IDataBlockModel) ? 1u : parameterModel.Length);
							string text3 = text2;
							if (text2.IndexOf(':') > 0)
							{
								text3 = text2.Substring(text2.IndexOf(':') + 1);
							}
							string columnName = ColumnName(parameterModel.Address, parameterModel.Offset, length, sourceAddress);
							if (text3 == null || text3.Length == 0)
							{
								text3 = parameterModel.Address.ToString("X8");
							}
							AddColumnToUCLogBuffer(columnName, typeof(string), parameterModel.EngineeringUnits, NetworkType.J1939, text3, sourceAddress);
						}
						if (parameterModel is IPublicDataModel)
						{
							AddPublicParameter(UCLPublicDataCount, sourceAddress, text2);
						}
					}
					catch
					{
					}
				}
			}
			UCLMonitoredListChangedEventArgs e;
			lock (UCLogBuffer)
			{
				e = new UCLMonitoredListChangedEventArgs(UCLogBuffer.Clone());
			}
			RaiseUCLMonitoredListChangedEvent(e);
		}

		public void Remove(IAddressValue deviceAddress)
		{
			lock (LogBuffer)
			{
				if (PublicDataCount.ContainsKey(deviceAddress.DeviceAddress))
				{
					PublicDataCount.Remove(deviceAddress.DeviceAddress);
				}
				string columnName = ColumnName(deviceAddress);
				for (int i = 0; i < LogBuffer.Columns.Count; i++)
				{
					RemoveColumn(columnName);
				}
			}
		}

		public void RemoveUCL(IAddressValue deviceAddress)
		{
			lock (UCLogBuffer)
			{
				if (UCLPublicDataCount.ContainsKey(deviceAddress.DeviceAddress))
				{
					UCLPublicDataCount.Remove(deviceAddress.DeviceAddress);
				}
				string columnName = ColumnName(deviceAddress);
				for (int i = 0; i < UCLogBuffer.Columns.Count; i++)
				{
					RemoveColumnUCL(columnName);
				}
			}
		}

		public void OnFaultsUpdated(object caller, FaultsUpdateEventArgs args)
		{
			lock (Faults)
			{
				Faults.Clear();
				foreach (DataRow row in args.faultDataTable.Rows)
				{
					Faults.Rows.Add(row[0], row[1], row[2], row[3], row[4], row[5]);
				}
			}
			lock (ActiveFaults)
			{
				activeFaults = GetFaults("CurrentStatus = 'Active'");
			}
			lock (InactiveFaults)
			{
				inactiveFaults = GetFaults("CurrentStatus = 'PrevActive'");
			}
		}

		private string GetFaults(string filter)
		{
			string text = "";
			text = "";
			try
			{
				DataRow[] array = Faults.Select(filter);
				DataRow[] array2 = array;
				foreach (DataRow dataRow in array2)
				{
					if (dataRow != null)
					{
						if (Options.DisplayFaultFormat)
						{
							int num = int.Parse(dataRow["FaultCode"].ToString(), NumberStyles.Integer);
							string text2 = $"{num,4:X4}";
							object obj = text;
							text = string.Concat(obj, dataRow["SourceAddress"], ":0x", text2, " ");
						}
						else
						{
							object obj2 = text;
							text = string.Concat(obj2, dataRow["SourceAddress"], ":", dataRow["FaultCode"].ToString(), " ");
						}
					}
				}
			}
			catch
			{
			}
			return text;
		}

		protected void RaiseStateChangedEvent(StateChangeEventArgs e)
		{
			if (this.StateChangedEvent != null)
			{
				this.StateChangedEvent(this, e);
			}
		}

		protected void RaiseUCLStateChangedEvent(UCLStateChangeEventArgs e)
		{
			if (this.UCLStateChangedEvent != null)
			{
				this.UCLStateChangedEvent(this, e);
			}
		}

		protected void RaiseStateChangingEvent(StateChangeEventArgs e)
		{
			if (this.StateChangingEvent != null)
			{
				this.StateChangingEvent(this, e);
			}
		}

		protected void RaiseUCLStateChangingEvent(UCLStateChangeEventArgs e)
		{
			if (this.UCLStateChangingEvent != null)
			{
				this.UCLStateChangingEvent(this, e);
			}
		}

		protected virtual void RaiseMonitoredListChangedEvent(MonitoredListChangedEventArgs e)
		{
			if (state == LoggingState.Logging && this.MonitoredListChangedEvent != null)
			{
				this.MonitoredListChangedEvent(this, e);
			}
		}

		protected virtual void RaiseUCLMonitoredListChangedEvent(UCLMonitoredListChangedEventArgs e)
		{
			if (ucloggingState == UCLState.Buffering && this.UCLMonitoredListChangedEvent != null)
			{
				this.UCLMonitoredListChangedEvent(this, e);
			}
		}

		protected virtual void RaiseMonitorListChangingEvent()
		{
			if (state == LoggingState.Logging && this.MonitorListChangingEvent != null)
			{
				this.MonitorListChangingEvent(this, EventArgs.Empty);
			}
		}

		protected virtual void RaiseUCLMonitorListChangingEvent()
		{
			if (ucloggingState == UCLState.Buffering && this.UCLMonitorListChangingEvent != null)
			{
				this.UCLMonitorListChangingEvent(this, EventArgs.Empty);
			}
		}

		private DataColumn AddColumnToLogBuffer(string columnName, Type type, string units, NetworkType networkType, string displayName, IAddressValue sourceAddress)
		{
			DataColumn dataColumn = new DataColumn(columnName, type);
			if (units == null || units == "")
			{
				units = "HEX";
			}
			dataColumn.ExtendedProperties.Add("units", units);
			dataColumn.ExtendedProperties.Add("Network", networkType);
			dataColumn.ExtendedProperties.Add("Active", true);
			dataColumn.ExtendedProperties.Add("Removed", false);
			if (displayName != null)
			{
				dataColumn.ExtendedProperties.Add("displayName", displayName);
			}
			if (sourceAddress != null)
			{
				dataColumn.ExtendedProperties.Add("address", sourceAddress);
			}
			else
			{
				dataColumn.ExtendedProperties.Add("address", "");
			}
			AddColumn(dataColumn);
			return dataColumn;
		}

		private DataColumn AddColumnToUCLogBuffer(string columnName, Type type, string units, NetworkType networkType, string displayName, IAddressValue sourceAddress)
		{
			DataColumn dataColumn = new DataColumn(columnName, type);
			if (units == null || units == "")
			{
				units = "HEX";
			}
			dataColumn.ExtendedProperties.Add("units", units);
			dataColumn.ExtendedProperties.Add("Network", networkType);
			dataColumn.ExtendedProperties.Add("Active", true);
			dataColumn.ExtendedProperties.Add("Removed", false);
			if (displayName != null)
			{
				dataColumn.ExtendedProperties.Add("displayName", displayName);
			}
			if (sourceAddress != null)
			{
				dataColumn.ExtendedProperties.Add("address", sourceAddress);
			}
			else
			{
				dataColumn.ExtendedProperties.Add("address", "");
			}
			AddColumnUCL(dataColumn);
			return dataColumn;
		}

		private DataColumn AddColumnToLogBuffer(string columnName, Type type, string units, NetworkType networkType)
		{
			return AddColumnToLogBuffer(columnName, type, units, networkType, null, null);
		}

		private DataColumn AddColumnToUCLogBuffer(string columnName, Type type, string units, NetworkType networkType)
		{
			return AddColumnToUCLogBuffer(columnName, type, units, networkType, null, null);
		}

		private void AddColumn(DataColumn column)
		{
			string columnName = column.ColumnName;
			if (columnNameTable[columnName] == null)
			{
				columnNameTable[columnName] = new ArrayList();
			}
			ArrayList arrayList = columnNameTable[columnName] as ArrayList;
			column.ColumnName = ((arrayList.Count > 0) ? string.Concat(arrayList.Count) : "") + columnName;
			arrayList.Add(LogBuffer.Columns.Count);
			LogBuffer.Columns.Add(column);
			LogBuffer.Columns.IndexOf(column.ColumnName);
			if (column.ExtendedProperties["address"] is IAddressValue addressValue)
			{
				IncrementNumberOfParametersInAddressType(addressValue.Type);
			}
		}

		private void AddColumnUCL(DataColumn column)
		{
			string columnName = column.ColumnName;
			if (uclcolumnNameTable[columnName] == null)
			{
				uclcolumnNameTable[columnName] = new ArrayList();
			}
			ArrayList arrayList = uclcolumnNameTable[columnName] as ArrayList;
			column.ColumnName = ((arrayList.Count > 0) ? string.Concat(arrayList.Count) : "") + columnName;
			lock (UCLogBuffer)
			{
				arrayList.Add(UCLogBuffer.Columns.Count);
				UCLogBuffer.Columns.Add(column);
				UCLogBuffer.Columns.IndexOf(column.ColumnName);
			}
			if (column.ExtendedProperties["address"] is IAddressValue addressValue)
			{
				IncrementNumberOfParametersInUCLAddressType(addressValue.Type);
			}
		}

		private void AddIndexColumnToLogBuffer()
		{
			DataColumn dataColumn = new DataColumn("index", typeof(int));
			dataColumn.AutoIncrement = true;
			dataColumn.AutoIncrementSeed = 1L;
			dataColumn.AutoIncrementStep = 1L;
			dataColumn.ExtendedProperties.Add("Active", false);
			AddColumn(dataColumn);
		}

		private void AddIndexColumnToUCLogBuffer()
		{
			DataColumn dataColumn = new DataColumn("index", typeof(int));
			dataColumn.AutoIncrement = true;
			dataColumn.AutoIncrementSeed = 1L;
			dataColumn.AutoIncrementStep = 1L;
			dataColumn.ExtendedProperties.Add("Active", false);
			AddColumnUCL(dataColumn);
		}

		private void AddPCTimeColumnToLogBuffer()
		{
			DataColumn dataColumn = new DataColumn("PC Timestamp", typeof(string));
			dataColumn.ExtendedProperties.Add("units", "none");
			dataColumn.ExtendedProperties.Add("Active", false);
			dataColumn.ExtendedProperties.Add("Removed", false);
			dataColumn.ExtendedProperties.Add("displayName", "PC Timestamp");
			AddColumn(dataColumn);
			SetupPCTimeLogging();
		}

		private void AddEventNumberColumnToLogBuffer()
		{
			DataColumn dataColumn = new DataColumn("EventNumber", typeof(string));
			dataColumn.ExtendedProperties.Add("units", "none");
			dataColumn.ExtendedProperties.Add("Active", false);
			dataColumn.ExtendedProperties.Add("Removed", false);
			dataColumn.ExtendedProperties.Add("displayName", "EventNumber");
			AddColumn(dataColumn);
			SetupEventNumberLogging();
		}

		private void AddPCTimeColumnToUCLogBuffer()
		{
			DataColumn dataColumn = new DataColumn("PC Timestamp", typeof(string));
			dataColumn.ExtendedProperties.Add("units", "none");
			dataColumn.ExtendedProperties.Add("Active", false);
			dataColumn.ExtendedProperties.Add("Removed", false);
			dataColumn.ExtendedProperties.Add("displayName", "PC Timestamp");
			AddColumnUCL(dataColumn);
			SetupUCLPCTimeLogging();
		}

		private void RemoveColumn(string columnName)
		{
			if (!(columnNameTable[columnName] is ArrayList arrayList))
			{
				throw new ArgumentOutOfRangeException(columnName);
			}
			int num = (int)arrayList[arrayList.Count - 1];
			DataColumn dataColumn = LogBuffer.Columns[num];
			if (State == LoggingState.Idle)
			{
				LogBuffer.Columns.Remove(dataColumn);
				arrayList.RemoveAt(arrayList.Count - 1);
				if (arrayList.Count == 0)
				{
					columnNameTable.Remove(columnName);
				}
				foreach (string key in columnNameTable.Keys)
				{
					ArrayList arrayList2 = (ArrayList)columnNameTable[key];
					for (int i = 0; i < arrayList2.Count; i++)
					{
						if ((int)arrayList2[i] > num)
						{
							arrayList2[i] = (int)arrayList2[i] - 1;
						}
					}
				}
				if (dataColumn.ExtendedProperties["address"] is IAddressValue addressValue)
				{
					DecrementNumberOfParametersInAddressType(addressValue.Type);
				}
			}
			else
			{
				arrayList.RemoveAt(arrayList.Count - 1);
				arrayList.Insert(0, num);
				dataColumn.ExtendedProperties["Removed"] = true;
			}
		}

		private void RemoveColumnUCL(string columnName)
		{
			if (!(uclcolumnNameTable[columnName] is ArrayList arrayList))
			{
				throw new ArgumentOutOfRangeException(columnName);
			}
			int num = (int)arrayList[arrayList.Count - 1];
			lock (UCLogBuffer)
			{
				DataColumn dataColumn = UCLogBuffer.Columns[num];
				if (State == LoggingState.Idle)
				{
					UCLogBuffer.Columns.Remove(dataColumn);
					arrayList.RemoveAt(arrayList.Count - 1);
					if (arrayList.Count == 0)
					{
						uclcolumnNameTable.Remove(columnName);
					}
					foreach (string key in uclcolumnNameTable.Keys)
					{
						ArrayList arrayList2 = (ArrayList)uclcolumnNameTable[key];
						for (int i = 0; i < arrayList2.Count; i++)
						{
							if ((int)arrayList2[i] > num)
							{
								arrayList2[i] = (int)arrayList2[i] - 1;
							}
						}
					}
					if (dataColumn.ExtendedProperties["address"] is IAddressValue addressValue)
					{
						DecrementNumberOfParametersInUCLAddressType(addressValue.Type);
					}
				}
				else
				{
					arrayList.RemoveAt(arrayList.Count - 1);
					arrayList.Insert(0, num);
					dataColumn.ExtendedProperties["Removed"] = true;
				}
			}
		}

		internal static string ColumnName(uint location, int offset, uint length, IAddressValue sourceAddress)
		{
			return '_' + sourceAddress.Value + '_' + location.ToString("X8") + '_' + offset.ToString("X8") + '_' + length.ToString("X2");
		}

		internal static string ColumnName(string parameterName, IAddressValue sourceAddress)
		{
			return '_' + sourceAddress.Value + '_' + parameterName;
		}

		public int[] GetColumnIndexes(string columnName)
		{
			lock (this)
			{
				int[] array = null;
				if (columnNameTable[columnName] is ArrayList arrayList)
				{
					array = new int[arrayList.Count];
					arrayList.ToArray().CopyTo(array, 0);
				}
				return array;
			}
		}

		public int[] GetUCLColumnIndexes(string columnName)
		{
			lock (this)
			{
				int[] array;
				if (uclcolumnNameTable[columnName] is ArrayList arrayList)
				{
					array = new int[arrayList.Count];
					arrayList.ToArray().CopyTo(array, 0);
				}
				else
				{
					array = new int[0];
				}
				return array;
			}
		}

		private string ColumnName(IAddressValue sourceAddress)
		{
			return '_' + sourceAddress.Value;
		}

		private void IncrementNumberOfParametersInAddressType(AddressType addrType)
		{
			if (addrType == AddressType.ECM)
			{
				numberOfDLParameters++;
				if (numberOfDLParameters > 0)
				{
					bool flag = (bool)LogBuffer.Columns["DLA Timestamp"].ExtendedProperties["Removed"];
					LogBuffer.Columns["DLA Timestamp"].ExtendedProperties["Active"] = !flag;
				}
			}
		}

		private void IncrementNumberOfParametersInUCLAddressType(AddressType addrType)
		{
			if (addrType == AddressType.ECM)
			{
				numberOfDLParameters++;
				if (numberOfDLParameters > 0)
				{
					bool flag = (bool)UCLogBuffer.Columns["DLA Timestamp"].ExtendedProperties["Removed"];
					UCLogBuffer.Columns["DLA Timestamp"].ExtendedProperties["Active"] = !flag;
				}
			}
		}

		private void DecrementNumberOfParametersInAddressType(AddressType addrType)
		{
			if (addrType == AddressType.ECM)
			{
				numberOfDLParameters--;
				if (numberOfDLParameters == 0)
				{
					LogBuffer.Columns["DLA Timestamp"].ExtendedProperties["Active"] = false;
				}
			}
		}

		private void DecrementNumberOfParametersInUCLAddressType(AddressType addrType)
		{
			if (addrType == AddressType.ECM)
			{
				numberOfDLParameters--;
				if (numberOfDLParameters == 0)
				{
					UCLogBuffer.Columns["DLA Timestamp"].ExtendedProperties["Active"] = false;
				}
			}
		}

		private MonitoredListChangedEventArgs BuildMonitoredListChangedEventArgs()
		{
			return new MonitoredListChangedEventArgs(LogBuffer.Clone());
		}

		private UCLMonitoredListChangedEventArgs BuildMonitoredListChangedUCLEventArgs()
		{
			lock (UCLogBuffer)
			{
				return new UCLMonitoredListChangedEventArgs(UCLogBuffer.Clone());
			}
		}

		public void SetupFaultLogging()
		{
			MonitoredListChangedEventArgs e = null;
			bool flag = false;
			bool flag2 = false;
			bool flag3 = false;
			lock (LogBuffer)
			{
				flag = LogBuffer.Columns.Contains("ActiveFaults");
				flag2 = LogBuffer.Columns.Contains("InactiveFaults");
			}
			if (!flag && Options.ShouldLogActiveFaults)
			{
				RaiseMonitorListChangingEvent();
				lock (LogBuffer)
				{
					AddColumnToLogBuffer("ActiveFaults", typeof(string), "none", NetworkType.J1939, "ActiveFaults", null);
					faultColumnIndex = LogBuffer.Columns.IndexOf("ActiveFaults");
					e = BuildMonitoredListChangedEventArgs();
					flag3 = true;
				}
			}
			if (!flag2 && Options.ShouldLogInactiveFaults)
			{
				RaiseMonitorListChangingEvent();
				lock (LogBuffer)
				{
					AddColumnToLogBuffer("InactiveFaults", typeof(string), "none", NetworkType.J1939, "InactiveFaults", null);
					inactiveFaultColumnIndex = LogBuffer.Columns.IndexOf("InactiveFaults");
					e = BuildMonitoredListChangedEventArgs();
					flag3 = true;
				}
			}
			if (flag3)
			{
				RaiseMonitoredListChangedEvent(e);
			}
		}

		public void SetupUCLFaultLogging()
		{
			UCLMonitoredListChangedEventArgs e = null;
			bool flag = false;
			bool flag2 = false;
			bool flag3 = false;
			lock (UCLogBuffer)
			{
				flag = UCLogBuffer.Columns.Contains("ActiveFaults");
				flag2 = UCLogBuffer.Columns.Contains("InactiveFaults");
			}
			if (!flag && Options.ShouldLogActiveFaults)
			{
				RaiseUCLMonitorListChangingEvent();
				lock (UCLogBuffer)
				{
					AddColumnToUCLogBuffer("ActiveFaults", typeof(string), "none", NetworkType.J1939, "ActiveFaults", null);
					faultColumnIndex = UCLogBuffer.Columns.IndexOf("ActiveFaults");
					e = BuildMonitoredListChangedUCLEventArgs();
					flag3 = true;
				}
			}
			if (!flag2 && Options.ShouldLogInactiveFaults)
			{
				RaiseUCLMonitorListChangingEvent();
				lock (UCLogBuffer)
				{
					AddColumnToUCLogBuffer("InactiveFaults", typeof(string), "none", NetworkType.J1939, "InactiveFaults", null);
					inactiveFaultColumnIndex = UCLogBuffer.Columns.IndexOf("InactiveFaults");
					e = BuildMonitoredListChangedUCLEventArgs();
					flag3 = true;
				}
			}
			if (flag3)
			{
				RaiseUCLMonitoredListChangedEvent(e);
			}
		}

		private void SetupPCTimeLogging()
		{
			MonitoredListChangedEventArgs e = null;
			RaiseMonitorListChangingEvent();
			bool flag = false;
			int num = -1;
			lock (LogBuffer)
			{
				num = LogBuffer.Columns.IndexOf("PC Timestamp");
				if (num != -1)
				{
					flag = (bool)LogBuffer.Columns[num].ExtendedProperties["Active"];
					try
					{
						if (options.Network.Modules.Count > 0 && State == LoggingState.Idle)
						{
							LogBuffer.Columns[num].ExtendedProperties["Active"] = Options.LogPCTime;
							ICollection sourceAddresses = options.Network.GetSourceAddresses();
							foreach (IAddressValue item in sourceAddresses)
							{
								if (item.Type == AddressType.ASAM)
								{
									LogBuffer.Columns[num].ExtendedProperties["Active"] = true;
									break;
								}
							}
						}
					}
					catch
					{
					}
					LogBuffer.Columns[num].ExtendedProperties["address"] = "";
				}
				e = BuildMonitoredListChangedEventArgs();
			}
			if (flag != (bool)LogBuffer.Columns[num].ExtendedProperties["Active"])
			{
				RaiseMonitoredListChangedEvent(e);
			}
		}

		private void SetupUCLPCTimeLogging()
		{
			UCLMonitoredListChangedEventArgs e = null;
			RaiseUCLMonitorListChangingEvent();
			bool flag = false;
			int num = -1;
			lock (UCLogBuffer)
			{
				num = UCLogBuffer.Columns.IndexOf("PC Timestamp");
				if (num != -1)
				{
					flag = (bool)UCLogBuffer.Columns[num].ExtendedProperties["Active"];
					try
					{
						if (options.Network.Modules.Count > 0 && State == LoggingState.Idle)
						{
							UCLogBuffer.Columns[num].ExtendedProperties["Active"] = Options.LogPCTime;
							ICollection sourceAddresses = options.Network.GetSourceAddresses();
							foreach (IAddressValue item in sourceAddresses)
							{
								if (item.Type == AddressType.ASAM)
								{
									UCLogBuffer.Columns[num].ExtendedProperties["Active"] = true;
									break;
								}
							}
						}
					}
					catch
					{
					}
					UCLogBuffer.Columns[num].ExtendedProperties["address"] = "";
				}
				e = BuildMonitoredListChangedUCLEventArgs();
			}
			if (flag != (bool)UCLogBuffer.Columns[num].ExtendedProperties["Active"])
			{
				RaiseUCLMonitoredListChangedEvent(e);
			}
		}

		private void SetupEventNumberLogging()
		{
			int num = -1;
			lock (LogBuffer)
			{
				num = LogBuffer.Columns.IndexOf("EventNumber");
				try
				{
					if (num != -1)
					{
						LogBuffer.Columns[num].ExtendedProperties["Active"] = Options.ShouldInsertEventNumber;
						LogBuffer.Columns[num].ExtendedProperties["address"] = "";
					}
				}
				catch
				{
				}
			}
		}

		private void CleanUp()
		{
			Faults.Clear();
			LogBuffer.Clear();
			try
			{
				lock (UCLogBuffer)
				{
					UCLogBuffer.Clear();
				}
			}
			catch
			{
			}
			StartConditionTrueIndex = -1;
			StopConditionTrueIndex = -1;
			UCLStartConditionTrueIndex = -1;
			UCLStopConditionTrueIndex = -1;
			activeFaults = "";
		}

		private void ResetMode()
		{
			if (TriggerOptions.StartTriggerSpecified)
			{
				if (State != LoggingState.Logging || Mode != Mode.Manual)
				{
					Mode = Mode.EventDriven;
				}
			}
			else if (options.EnableUCL_Logging)
			{
				if (State == LoggingState.Logging && Mode == Mode.Manual)
				{
					ucloggingState = UCLState.Buffering;
				}
			}
			else
			{
				Mode = Mode.Manual;
			}
		}

		private void OnMonitorModeChanged(object sender, EventArgs e)
		{
			if (State == LoggingState.Buffering)
			{
				if (Options.CurrentMode == DataAcquisitionType.IDL)
				{
					state = LoggingState.Idle;
					mode = Mode.Manual;
					CleanUp();
					RaiseStateChangedEvent(new StateChangeEventArgs(LoggingState.Idle, LoggingState.Buffering, LogBuffer.Columns));
				}
				else
				{
					State = LoggingState.Idle;
				}
			}
			else if (State != LoggingState.Idle)
			{
				throw new InvalidOperationException("Logging must be stopped completely prior to changing mode");
			}
		}

		private void OnLoggingOptionsChanged(object sender, EventArgs e)
		{
		}

		private void OnFaultLoggingOptionsChanged(object sender, EventArgs e)
		{
		}

		private void OnLogPCTimeStampOptionChanged(object sender, EventArgs e)
		{
			SetupPCTimeLogging();
			SetupUCLPCTimeLogging();
		}

		private void OnStartTriggerChanged(object sender, EventArgs e)
		{
			startTrigger = null;
			ResetMode();
			if (TriggerOptions.StartTriggerSpecified)
			{
				if (State == LoggingState.Idle)
				{
					State = LoggingState.Buffering;
				}
			}
			else if (State == LoggingState.Buffering)
			{
				State = LoggingState.Idle;
			}
		}

		private void OnStopTriggerChanged(object sender, EventArgs e)
		{
			stopTrigger = null;
		}

		private void OnEDLRepeatCountChanged(object sender, EventArgs e)
		{
			loggingCycles = 0;
			ResetMode();
			if (TriggerOptions.StartTriggerSpecified)
			{
				if (State == LoggingState.Idle)
				{
					State = LoggingState.Buffering;
				}
			}
			else if (State == LoggingState.Buffering)
			{
				State = LoggingState.Idle;
			}
		}

		private void OnTriggerOptionsChanged(object sender, EventArgs e)
		{
			startTrigger = null;
			stopTrigger = null;
			ResetMode();
			loggingCycles = 0;
		}

		private LoggingState EndState()
		{
			LoggingState result = LoggingState.Idle;
			if (Mode == Mode.EventDriven && TriggerOptions.StartTriggerSpecified)
			{
				if (loggingCycles >= TriggerOptions.RepeatCount)
				{
					result = LoggingState.Idle;
					loggingCycles = 0;
				}
				else
				{
					result = LoggingState.Buffering;
				}
			}
			return result;
		}

		private void SetCoordinates(string parameterName, IParameterModel parameter)
		{
			IParameterSpecification parameterSpecification = null;
			string parameterName2 = parameterName;
			if (parameterName.IndexOf(':') > 0)
			{
				parameterName2 = parameterName.Substring(parameterName.IndexOf(':') + 1);
			}
			ICalibrationECM calibrationECM = (ICalibrationECM)parameter.DataSource;
			if (calibrationECM == null)
			{
				return;
			}
			parameterSpecification = calibrationECM.GetSpecification(parameterName2);
			if (parameterSpecification != null)
			{
				if (parameter is IArray2DModel)
				{
					((IArray2DModel)parameter).SetCurrentLocation(parameterSpecification.X, parameterSpecification.Y);
				}
				else if (parameter is IDataBlockModel)
				{
					(parameter as IDataBlockModel).X = parameterSpecification.X;
				}
				else if (parameter is IArray1DModel)
				{
					(parameter as IArray1DModel).X = parameterSpecification.X;
				}
			}
		}

		private void AddPublicParameter(PublicDataParameters parameterCollection, IAddressValue sourceAddress, string name)
		{
			if (!parameterCollection.ContainsKey(sourceAddress.DeviceAddress))
			{
				parameterCollection.Add(sourceAddress.DeviceAddress, new List<string>());
			}
			if (!parameterCollection[sourceAddress.DeviceAddress].Contains(name))
			{
				parameterCollection[sourceAddress.DeviceAddress].Add(name);
			}
		}

		private void RemovePublicParameter(PublicDataParameters parameterCollection, IAddressValue sourceAddress, string name)
		{
			if (parameterCollection.ContainsKey(sourceAddress.DeviceAddress))
			{
				parameterCollection[sourceAddress.DeviceAddress].Remove(name);
			}
		}
	}
	public class LogOptionControl : UserControl
	{
		private GroupBox groupBox2;

		private CheckBox ckLogActiveFaults;

		private CheckBox ckPCTime;

		private TextBox edPrefixRR;

		private Label label1;

		private GroupBox groupBox1;

		private ComboBox cbrateunit;

		private Label label2;

		private RadioButton rdLogOnAll;

		private RadioButton rdSpecifyUpdate;

		private TextBox edLogRate;

		private RadioButton rdLogOnAny;

		private ToolTip tipAll;

		private ToolTip tipAny;

		private ToolTip tipSpecified;

		private IContainer components;

		public int LogUpdateRate
		{
			get
			{
				return int.Parse(((Control)edLogRate).Text);
			}
			set
			{
				((Control)edLogRate).Text = value.ToString();
			}
		}

		public int LogRateInMS
		{
			get
			{
				if (((Control)cbrateunit).Text == "Hz")
				{
					if (int.Parse(((Control)edLogRate).Text) != 0)
					{
						return 1000 / int.Parse(((Control)edLogRate).Text);
					}
					return 0;
				}
				return int.Parse(((Control)edLogRate).Text);
			}
		}

		public LoggingRateUnits LogRateUnit
		{
			get
			{
				return (LoggingRateUnits)Enum.Parse(typeof(LoggingRateUnits), ((Control)cbrateunit).Text, ignoreCase: true);
			}
			set
			{
				switch (value)
				{
				case LoggingRateUnits.Hz:
					((Control)cbrateunit).Text = "Hz";
					break;
				case LoggingRateUnits.ms:
					((Control)cbrateunit).Text = "ms";
					break;
				}
			}
		}

		public string LogFilePrefix
		{
			get
			{
				return ((Control)edPrefixRR).Text;
			}
			set
			{
				((Control)edPrefixRR).Text = value;
			}
		}

		public bool LogPCTime
		{
			get
			{
				return ckPCTime.Checked;
			}
			set
			{
				ckPCTime.Checked = value;
			}
		}

		public bool LogActiveFaults
		{
			get
			{
				return ckLogActiveFaults.Checked;
			}
			set
			{
				ckLogActiveFaults.Checked = value;
			}
		}

		public RecordingModes RecordingMode
		{
			get
			{
				RecordingModes result = RecordingModes.AnyDataReceived;
				if (rdLogOnAny.Checked)
				{
					result = RecordingModes.AnyDataReceived;
				}
				if (rdLogOnAll.Checked)
				{
					result = RecordingModes.AllDataReceived;
				}
				if (rdSpecifyUpdate.Checked)
				{
					result = RecordingModes.UserSpecifiedRate;
				}
				return result;
			}
			set
			{
				switch (value)
				{
				case RecordingModes.AnyDataReceived:
					rdLogOnAny.Checked = true;
					break;
				case RecordingModes.AllDataReceived:
					rdLogOnAll.Checked = true;
					ckPCTime.Checked = true;
					((Control)ckPCTime).Enabled = false;
					break;
				case RecordingModes.UserSpecifiedRate:
					rdSpecifyUpdate.Checked = true;
					ckPCTime.Checked = true;
					((Control)ckPCTime).Enabled = false;
					break;
				default:
					rdLogOnAny.Checked = true;
					break;
				}
			}
		}

		public LogOptionControl()
		{
			InitializeComponent();
			tipAll.SetToolTip((Control)(object)rdLogOnAll, "Data is written to Log File when all data being logged is received. Data will be written at the rate of the slowest responding device.");
			tipAny.SetToolTip((Control)(object)rdLogOnAny, "Data is written to Log File as data is received per device.  Parameters from other devices will have a value of \"NaN\" until the device returns data.");
			tipSpecified.SetToolTip((Control)(object)rdSpecifyUpdate, "Data is written to Log File at user specified Log Update Rate. If some data has not been received in the specified time interval (Log Update rate), then a value of \"NaN\" will be written.");
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
			//IL_0096: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a0: Expected O, but got Unknown
			//IL_00a7: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b1: Expected O, but got Unknown
			//IL_00b8: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c2: Expected O, but got Unknown
			components = new Container();
			groupBox2 = new GroupBox();
			ckLogActiveFaults = new CheckBox();
			ckPCTime = new CheckBox();
			edPrefixRR = new TextBox();
			label1 = new Label();
			groupBox1 = new GroupBox();
			cbrateunit = new ComboBox();
			label2 = new Label();
			rdLogOnAll = new RadioButton();
			rdSpecifyUpdate = new RadioButton();
			edLogRate = new TextBox();
			rdLogOnAny = new RadioButton();
			tipAll = new ToolTip(components);
			tipAny = new ToolTip(components);
			tipSpecified = new ToolTip(components);
			((Control)groupBox2).SuspendLayout();
			((Control)groupBox1).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)groupBox2).Controls.Add((Control)(object)ckLogActiveFaults);
			((Control)groupBox2).Controls.Add((Control)(object)ckPCTime);
			((Control)groupBox2).Controls.Add((Control)(object)edPrefixRR);
			((Control)groupBox2).Controls.Add((Control)(object)label1);
			((Control)groupBox2).Location = new Point(0, 0);
			((Control)groupBox2).Name = "groupBox2";
			((Control)groupBox2).Size = new Size(208, 104);
			((Control)groupBox2).TabIndex = 57;
			groupBox2.TabStop = false;
			((Control)groupBox2).Text = "Log Options";
			((Control)ckLogActiveFaults).Location = new Point(8, 64);
			((Control)ckLogActiveFaults).Name = "ckLogActiveFaults";
			((Control)ckLogActiveFaults).Size = new Size(121, 17);
			((Control)ckLogActiveFaults).TabIndex = 45;
			((Control)ckLogActiveFaults).Text = "Log &active faults";
			((Control)ckPCTime).Location = new Point(8, 40);
			((Control)ckPCTime).Name = "ckPCTime";
			((Control)ckPCTime).Size = new Size(128, 24);
			((Control)ckPCTime).TabIndex = 44;
			((Control)ckPCTime).Text = "Log PC Time";
			((Control)edPrefixRR).Location = new Point(88, 16);
			((Control)edPrefixRR).Name = "edPrefixRR";
			((Control)edPrefixRR).Size = new Size(75, 20);
			((Control)edPrefixRR).TabIndex = 48;
			((Control)edPrefixRR).Text = "";
			((Control)label1).Location = new Point(8, 16);
			((Control)label1).Name = "label1";
			((Control)label1).Size = new Size(78, 21);
			((Control)label1).TabIndex = 49;
			((Control)label1).Text = "LogFile prefix";
			label1.TextAlign = (ContentAlignment)16;
			((Control)groupBox1).Controls.Add((Control)(object)cbrateunit);
			((Control)groupBox1).Controls.Add((Control)(object)label2);
			((Control)groupBox1).Controls.Add((Control)(object)rdLogOnAll);
			((Control)groupBox1).Controls.Add((Control)(object)rdSpecifyUpdate);
			((Control)groupBox1).Controls.Add((Control)(object)edLogRate);
			((Control)groupBox1).Controls.Add((Control)(object)rdLogOnAny);
			((Control)groupBox1).Location = new Point(0, 104);
			((Control)groupBox1).Name = "groupBox1";
			((Control)groupBox1).Size = new Size(208, 111);
			((Control)groupBox1).TabIndex = 56;
			groupBox1.TabStop = false;
			((Control)groupBox1).Text = "Log Update Rate";
			cbrateunit.Items.AddRange(new object[2] { "ms", "Hz" });
			((Control)cbrateunit).Location = new Point(154, 78);
			((Control)cbrateunit).Name = "cbrateunit";
			((Control)cbrateunit).Size = new Size(43, 21);
			((Control)cbrateunit).TabIndex = 1;
			((Control)cbrateunit).Text = "ms";
			((Control)label2).Location = new Point(10, 78);
			((Control)label2).Name = "label2";
			((Control)label2).Size = new Size(90, 20);
			((Control)label2).TabIndex = 0;
			((Control)label2).Text = "Log Update Rate";
			label2.TextAlign = (ContentAlignment)16;
			((Control)rdLogOnAll).Location = new Point(10, 36);
			((Control)rdLogOnAll).Name = "rdLogOnAll";
			((Control)rdLogOnAll).Size = new Size(189, 16);
			((Control)rdLogOnAll).TabIndex = 50;
			((Control)rdLogOnAll).Text = "Log Data when all data received";
			rdLogOnAll.CheckedChanged += rdLogOnAll_CheckedChanged;
			((Control)rdSpecifyUpdate).Location = new Point(10, 54);
			((Control)rdSpecifyUpdate).Name = "rdSpecifyUpdate";
			((Control)rdSpecifyUpdate).Size = new Size(176, 17);
			((Control)rdSpecifyUpdate).TabIndex = 51;
			((Control)rdSpecifyUpdate).Text = "Log Data at specified interval";
			rdSpecifyUpdate.CheckedChanged += rdSpecifyUpdate_CheckedChanged;
			((Control)edLogRate).Location = new Point(100, 78);
			((Control)edLogRate).Name = "edLogRate";
			((Control)edLogRate).Size = new Size(54, 20);
			((Control)edLogRate).TabIndex = 52;
			((Control)edLogRate).Text = "1";
			edLogRate.TextAlign = (HorizontalAlignment)1;
			((Control)edLogRate).Validating += edLogRate_Validating;
			((Control)rdLogOnAny).Location = new Point(10, 17);
			((Control)rdLogOnAny).Name = "rdLogOnAny";
			((Control)rdLogOnAny).Size = new Size(196, 16);
			((Control)rdLogOnAny).TabIndex = 53;
			((Control)rdLogOnAny).Text = "Log Data when any data received";
			rdLogOnAny.CheckedChanged += rdLogonDemand_CheckedChanged;
			((Control)this).Controls.Add((Control)(object)groupBox2);
			((Control)this).Controls.Add((Control)(object)groupBox1);
			((Control)this).Name = "LogOptionControl";
			((Control)this).Size = new Size(208, 216);
			((Control)groupBox2).ResumeLayout(false);
			((Control)groupBox1).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}

		private void edLogRate_Validating(object sender, CancelEventArgs e)
		{
			//IL_0058: Unknown result type (might be due to invalid IL or missing references)
			//IL_0033: Unknown result type (might be due to invalid IL or missing references)
			e.Cancel = false;
			try
			{
				if (((Control)edLogRate).Text.Length != 0)
				{
					int num = int.Parse(((Control)edLogRate).Text);
					if (num < 1)
					{
						MessageBox.Show("Please enter a positive integer");
						((Control)edLogRate).Text = "1";
						e.Cancel = true;
					}
				}
			}
			catch
			{
				MessageBox.Show("Please enter a positive integer");
				((Control)edLogRate).Text = "1";
				e.Cancel = true;
			}
		}

		private void rdLogonDemand_CheckedChanged(object sender, EventArgs e)
		{
			((Control)edLogRate).Enabled = !rdLogOnAny.Checked;
			((Control)cbrateunit).Enabled = !rdLogOnAny.Checked;
			((Control)ckPCTime).Enabled = true;
		}

		private void rdLogOnAll_CheckedChanged(object sender, EventArgs e)
		{
			((Control)edLogRate).Enabled = !rdLogOnAll.Checked;
			((Control)cbrateunit).Enabled = !rdLogOnAll.Checked;
			if (rdLogOnAll.Checked)
			{
				ckPCTime.Checked = true;
				((Control)ckPCTime).Enabled = false;
			}
		}

		private void rdSpecifyUpdate_CheckedChanged(object sender, EventArgs e)
		{
			((Control)edLogRate).Enabled = rdSpecifyUpdate.Checked;
			((Control)cbrateunit).Enabled = rdSpecifyUpdate.Checked;
			if (rdSpecifyUpdate.Checked)
			{
				ckPCTime.Checked = true;
				((Control)ckPCTime).Enabled = false;
			}
		}
	}
	public class LogPropertiesControl : UserControl, IPropertyPage
	{
		private IContainer components;

		private string parentNode;

		private string currentNode;

		private Label lblLogFilePath;

		private ComboBox cmbDefaultLogfileFomat;

		private Label laDefaultLogfileFormat;

		private GroupBox gbFileOptions;

		private Label lblKB;

		private TextBox txtLogFileSize;

		private Label lblMaxLogFileSize;

		private RadioButton rbSingleFile;

		private RadioButton rbMultipleFiles;

		private CheckBox ckSaveAsDialog;

		private CheckBox ckDisplayLogFile;

		private GroupBox gbTop;

		private Panel paLogging;

		private PathSelector logFilePathSelector;

		private CheckBox ckDLASecondsTimestamp;

		private GroupBox gbUCLOptions;

		private CheckBox ckInsertEventNumber;

		private Label lbls1;

		private TextBox txtUCLPreTriggertime;

		private Label lblUCLPreTriggertime;

		private Label lbls2;

		private TextBox txtUCLPostTriggertime;

		private Label lblUCLPostTriggertime;

		private CheckBox enableUCLlogCheckbox;

		private GroupBox logFileOptionsGroup;

		private Label outputExportFileNameLabel;

		private Label inputParamFileNameLabel;

		private CheckBox ckFileNameFormat;

		private CheckBox exportParametersCheckBox;

		private CheckBox ckDeleteOldestOnMediaFull;

		private FileSelectionControl outputExportFileSelection;

		private FileSelectionControl inputParamFileSelection;

		private ILoggerConfiguration options;

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

		public LogPropertiesControl()
		{
			InitializeComponent();
			parentNode = "";
			currentNode = "";
		}

		public LogPropertiesControl(ILoggerConfiguration options)
		{
			InitializeComponent();
			parentNode = "";
			currentNode = "";
			this.options = options;
			InitializeFormatComboBox();
		}

		public LogPropertiesControl(ILoggerConfiguration options, string parentNode, string currentNode)
		{
			InitializeComponent();
			this.parentNode = parentNode;
			this.currentNode = currentNode;
			this.options = options;
			GetOptions();
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			logFilePathSelector.ProductID = appSetting;
			InitializeFormatComboBox();
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
			//IL_00d2: Unknown result type (might be due to invalid IL or missing references)
			//IL_00dc: Expected O, but got Unknown
			//IL_00dd: Unknown result type (might be due to invalid IL or missing references)
			//IL_00e7: Expected O, but got Unknown
			//IL_00e8: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f2: Expected O, but got Unknown
			//IL_00f3: Unknown result type (might be due to invalid IL or missing references)
			//IL_00fd: Expected O, but got Unknown
			//IL_0109: Unknown result type (might be due to invalid IL or missing references)
			//IL_0113: Expected O, but got Unknown
			//IL_012a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0134: Expected O, but got Unknown
			//IL_0135: Unknown result type (might be due to invalid IL or missing references)
			//IL_013f: Expected O, but got Unknown
			//IL_0140: Unknown result type (might be due to invalid IL or missing references)
			//IL_014a: Expected O, but got Unknown
			//IL_014b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0155: Expected O, but got Unknown
			//IL_0156: Unknown result type (might be due to invalid IL or missing references)
			//IL_0160: Expected O, but got Unknown
			lblLogFilePath = new Label();
			cmbDefaultLogfileFomat = new ComboBox();
			laDefaultLogfileFormat = new Label();
			gbFileOptions = new GroupBox();
			ckDLASecondsTimestamp = new CheckBox();
			lblKB = new Label();
			txtLogFileSize = new TextBox();
			lblMaxLogFileSize = new Label();
			rbSingleFile = new RadioButton();
			rbMultipleFiles = new RadioButton();
			ckSaveAsDialog = new CheckBox();
			ckDisplayLogFile = new CheckBox();
			gbTop = new GroupBox();
			paLogging = new Panel();
			gbUCLOptions = new GroupBox();
			enableUCLlogCheckbox = new CheckBox();
			lbls2 = new Label();
			txtUCLPostTriggertime = new TextBox();
			lblUCLPostTriggertime = new Label();
			lbls1 = new Label();
			txtUCLPreTriggertime = new TextBox();
			lblUCLPreTriggertime = new Label();
			ckInsertEventNumber = new CheckBox();
			logFilePathSelector = new PathSelector();
			logFileOptionsGroup = new GroupBox();
			outputExportFileSelection = new FileSelectionControl();
			inputParamFileSelection = new FileSelectionControl();
			outputExportFileNameLabel = new Label();
			inputParamFileNameLabel = new Label();
			ckFileNameFormat = new CheckBox();
			exportParametersCheckBox = new CheckBox();
			ckDeleteOldestOnMediaFull = new CheckBox();
			((Control)gbFileOptions).SuspendLayout();
			((Control)paLogging).SuspendLayout();
			((Control)gbUCLOptions).SuspendLayout();
			((Control)logFileOptionsGroup).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)lblLogFilePath).AutoSize = true;
			((Control)lblLogFilePath).Location = new Point(13, 212);
			((Control)lblLogFilePath).Name = "lblLogFilePath";
			((Control)lblLogFilePath).Size = new Size(69, 13);
			((Control)lblLogFilePath).TabIndex = 24;
			((Control)lblLogFilePath).Text = "Log file Pat&h:";
			lblLogFilePath.TextAlign = (ContentAlignment)16;
			cmbDefaultLogfileFomat.DropDownStyle = (ComboBoxStyle)2;
			cmbDefaultLogfileFomat.ItemHeight = 13;
			((Control)cmbDefaultLogfileFomat).Location = new Point(90, 179);
			((Control)cmbDefaultLogfileFomat).Name = "cmbDefaultLogfileFomat";
			((Control)cmbDefaultLogfileFomat).Size = new Size(80, 21);
			((Control)cmbDefaultLogfileFomat).TabIndex = 10;
			((Control)laDefaultLogfileFormat).AutoSize = true;
			((Control)laDefaultLogfileFormat).Location = new Point(13, 182);
			((Control)laDefaultLogfileFormat).Name = "laDefaultLogfileFormat";
			((Control)laDefaultLogfileFormat).Size = new Size(76, 13);
			((Control)laDefaultLogfileFormat).TabIndex = 9;
			((Control)laDefaultLogfileFormat).Text = "Default &format:";
			laDefaultLogfileFormat.TextAlign = (ContentAlignment)16;
			((Control)gbFileOptions).Controls.Add((Control)(object)ckDLASecondsTimestamp);
			((Control)gbFileOptions).Controls.Add((Control)(object)lblKB);
			((Control)gbFileOptions).Controls.Add((Control)(object)txtLogFileSize);
			((Control)gbFileOptions).Controls.Add((Control)(object)lblMaxLogFileSize);
			((Control)gbFileOptions).Controls.Add((Control)(object)rbSingleFile);
			((Control)gbFileOptions).Controls.Add((Control)(object)rbMultipleFiles);
			((Control)gbFileOptions).Controls.Add((Control)(object)ckSaveAsDialog);
			((Control)gbFileOptions).Controls.Add((Control)(object)ckDisplayLogFile);
			((Control)gbFileOptions).Location = new Point(6, 5);
			((Control)gbFileOptions).Name = "gbFileOptions";
			((Control)gbFileOptions).Size = new Size(215, 157);
			((Control)gbFileOptions).TabIndex = 11;
			gbFileOptions.TabStop = false;
			((Control)gbFileOptions).Text = "Log &options";
			((Control)ckDLASecondsTimestamp).AutoSize = true;
			((Control)ckDLASecondsTimestamp).Location = new Point(10, 137);
			((Control)ckDLASecondsTimestamp).Name = "ckDLASecondsTimestamp";
			((Control)ckDLASecondsTimestamp).Size = new Size(155, 17);
			((Control)ckDLASecondsTimestamp).TabIndex = 27;
			((Control)ckDLASecondsTimestamp).Text = "DLA Timestamp in seconds";
			((ButtonBase)ckDLASecondsTimestamp).UseVisualStyleBackColor = true;
			((Control)lblKB).AutoSize = true;
			((Control)lblKB).Location = new Point(160, 52);
			((Control)lblKB).Name = "lblKB";
			((Control)lblKB).Size = new Size(21, 13);
			((Control)lblKB).TabIndex = 26;
			((Control)lblKB).Text = "KB";
			((Control)txtLogFileSize).Location = new Point(93, 49);
			((TextBoxBase)txtLogFileSize).MaxLength = 5;
			((Control)txtLogFileSize).Name = "txtLogFileSize";
			((Control)txtLogFileSize).Size = new Size(63, 20);
			((Control)txtLogFileSize).TabIndex = 14;
			((Control)txtLogFileSize).Validating += txtLogFileSize_Validating;
			((Control)lblMaxLogFileSize).Location = new Point(26, 51);
			((Control)lblMaxLogFileSize).Name = "lblMaxLogFileSize";
			((Control)lblMaxLogFileSize).Size = new Size(76, 13);
			((Control)lblMaxLogFileSize).TabIndex = 13;
			((Control)lblMaxLogFileSize).Text = "&Max. file size:";
			rbSingleFile.Checked = true;
			((Control)rbSingleFile).Location = new Point(10, 74);
			((Control)rbSingleFile).Name = "rbSingleFile";
			((Control)rbSingleFile).Size = new Size(144, 18);
			((Control)rbSingleFile).TabIndex = 15;
			rbSingleFile.TabStop = true;
			((Control)rbSingleFile).Text = "Create only one &Log file.";
			rbSingleFile.CheckedChanged += LogFileCreationOptionChanged;
			((Control)rbMultipleFiles).Location = new Point(8, 15);
			((Control)rbMultipleFiles).Name = "rbMultipleFiles";
			((Control)rbMultipleFiles).Size = new Size(182, 31);
			((Control)rbMultipleFiles).TabIndex = 12;
			((Control)rbMultipleFiles).Text = "&Create multiple Log files based on file size threshold.";
			rbMultipleFiles.CheckedChanged += LogFileCreationOptionChanged;
			ckSaveAsDialog.Checked = true;
			ckSaveAsDialog.CheckState = (CheckState)1;
			((Control)ckSaveAsDialog).Location = new Point(29, 112);
			((Control)ckSaveAsDialog).Name = "ckSaveAsDialog";
			((Control)ckSaveAsDialog).Size = new Size(158, 16);
			((Control)ckSaveAsDialog).TabIndex = 17;
			((Control)ckSaveAsDialog).Text = "Display &Save As file dialog";
			((Control)ckDisplayLogFile).Location = new Point(30, 91);
			((Control)ckDisplayLogFile).Name = "ckDisplayLogFile";
			((Control)ckDisplayLogFile).Size = new Size(104, 19);
			((Control)ckDisplayLogFile).TabIndex = 16;
			((Control)ckDisplayLogFile).Text = "&Display Log file";
			((Control)gbTop).Anchor = (AnchorStyles)13;
			((Control)gbTop).Location = new Point(73, 8);
			((Control)gbTop).Name = "gbTop";
			((Control)gbTop).Size = new Size(0, 4);
			((Control)gbTop).TabIndex = 35;
			gbTop.TabStop = false;
			((Control)paLogging).Anchor = (AnchorStyles)15;
			((Control)paLogging).Controls.Add((Control)(object)gbUCLOptions);
			((Control)paLogging).Controls.Add((Control)(object)logFilePathSelector);
			((Control)paLogging).Controls.Add((Control)(object)lblLogFilePath);
			((Control)paLogging).Controls.Add((Control)(object)cmbDefaultLogfileFomat);
			((Control)paLogging).Controls.Add((Control)(object)laDefaultLogfileFormat);
			((Control)paLogging).Controls.Add((Control)(object)gbFileOptions);
			((Control)paLogging).Controls.Add((Control)(object)gbTop);
			((Control)paLogging).Controls.Add((Control)(object)logFileOptionsGroup);
			((Control)paLogging).Location = new Point(0, 0);
			((Control)paLogging).Name = "paLogging";
			((Control)paLogging).Size = new Size(472, 325);
			((Control)paLogging).TabIndex = 0;
			((Control)gbUCLOptions).Controls.Add((Control)(object)enableUCLlogCheckbox);
			((Control)gbUCLOptions).Controls.Add((Control)(object)lbls2);
			((Control)gbUCLOptions).Controls.Add((Control)(object)txtUCLPostTriggertime);
			((Control)gbUCLOptions).Controls.Add((Control)(object)lblUCLPostTriggertime);
			((Control)gbUCLOptions).Controls.Add((Control)(object)lbls1);
			((Control)gbUCLOptions).Controls.Add((Control)(object)txtUCLPreTriggertime);
			((Control)gbUCLOptions).Controls.Add((Control)(object)lblUCLPreTriggertime);
			((Control)gbUCLOptions).Controls.Add((Control)(object)ckInsertEventNumber);
			((Control)gbUCLOptions).Location = new Point(227, 5);
			((Control)gbUCLOptions).Name = "gbUCLOptions";
			((Control)gbUCLOptions).Size = new Size(205, 157);
			((Control)gbUCLOptions).TabIndex = 27;
			gbUCLOptions.TabStop = false;
			((Control)gbUCLOptions).Text = "&User Centric logging options";
			((Control)enableUCLlogCheckbox).AutoSize = true;
			enableUCLlogCheckbox.Checked = true;
			enableUCLlogCheckbox.CheckState = (CheckState)1;
			((Control)enableUCLlogCheckbox).Location = new Point(10, 26);
			((Control)enableUCLlogCheckbox).Name = "enableUCLlogCheckbox";
			((Control)enableUCLlogCheckbox).Size = new Size(120, 17);
			((Control)enableUCLlogCheckbox).TabIndex = 35;
			((Control)enableUCLlogCheckbox).Text = "Enable UCL logging";
			((ButtonBase)enableUCLlogCheckbox).UseVisualStyleBackColor = true;
			enableUCLlogCheckbox.CheckedChanged += enableUCLlogCheckbox_CheckedChanged;
			((Control)lbls2).AutoSize = true;
			((Control)lbls2).Location = new Point(165, 91);
			((Control)lbls2).Name = "lbls2";
			((Control)lbls2).Size = new Size(12, 13);
			((Control)lbls2).TabIndex = 34;
			((Control)lbls2).Text = "s";
			((Control)txtUCLPostTriggertime).Location = new Point(119, 87);
			((TextBoxBase)txtUCLPostTriggertime).MaxLength = 5;
			((Control)txtUCLPostTriggertime).Name = "txtUCLPostTriggertime";
			((Control)txtUCLPostTriggertime).Size = new Size(44, 20);
			((Control)txtUCLPostTriggertime).TabIndex = 33;
			((Control)txtUCLPostTriggertime).Text = "30";
			((Control)txtUCLPostTriggertime).Validating += txtUCLPostTriggertime_Validating;
			((Control)lblUCLPostTriggertime).Location = new Point(15, 92);
			((Control)lblUCLPostTriggertime).Name = "lblUCLPostTriggertime";
			((Control)lblUCLPostTriggertime).Size = new Size(95, 18);
			((Control)lblUCLPostTriggertime).TabIndex = 32;
			((Control)lblUCLPostTriggertime).Text = "Post-&trigger time:";
			((Control)lbls1).AutoSize = true;
			((Control)lbls1).Location = new Point(165, 62);
			((Control)lbls1).Name = "lbls1";
			((Control)lbls1).Size = new Size(12, 13);
			((Control)lbls1).TabIndex = 31;
			((Control)lbls1).Text = "s";
			((Control)txtUCLPreTriggertime).Location = new Point(120, 57);
			((TextBoxBase)txtUCLPreTriggertime).MaxLength = 5;
			((Control)txtUCLPreTriggertime).Name = "txtUCLPreTriggertime";
			((Control)txtUCLPreTriggertime).Size = new Size(44, 20);
			((Control)txtUCLPreTriggertime).TabIndex = 30;
			((Control)txtUCLPreTriggertime).Text = "30";
			((Control)txtUCLPreTriggertime).Validating += txtUCLPreTriggertime_Validating;
			((Control)lblUCLPreTriggertime).Location = new Point(16, 61);
			((Control)lblUCLPreTriggertime).Name = "lblUCLPreTriggertime";
			((Control)lblUCLPreTriggertime).Size = new Size(87, 20);
			((Control)lblUCLPreTriggertime).TabIndex = 29;
			((Control)lblUCLPreTriggertime).Text = "&Pre-trigger time:";
			((Control)ckInsertEventNumber).Location = new Point(10, 126);
			((Control)ckInsertEventNumber).Name = "ckInsertEventNumber";
			((Control)ckInsertEventNumber).Size = new Size(177, 20);
			((Control)ckInsertEventNumber).TabIndex = 28;
			((Control)ckInsertEventNumber).Text = "Insert &Event number in log file";
			logFilePathSelector.Flat = false;
			((Control)logFilePathSelector).Location = new Point(90, 209);
			((Control)logFilePathSelector).Name = "logFilePathSelector";
			logFilePathSelector.ProductID = "";
			logFilePathSelector.SelectedPath = "";
			((Control)logFilePathSelector).Size = new Size(143, 22);
			((Control)logFilePathSelector).TabIndex = 25;
			logFilePathSelector.Title = "Select Folder for Log files";
			((Control)logFileOptionsGroup).Controls.Add((Control)(object)outputExportFileSelection);
			((Control)logFileOptionsGroup).Controls.Add((Control)(object)inputParamFileSelection);
			((Control)logFileOptionsGroup).Controls.Add((Control)(object)outputExportFileNameLabel);
			((Control)logFileOptionsGroup).Controls.Add((Control)(object)inputParamFileNameLabel);
			((Control)logFileOptionsGroup).Controls.Add((Control)(object)ckFileNameFormat);
			((Control)logFileOptionsGroup).Controls.Add((Control)(object)exportParametersCheckBox);
			((Control)logFileOptionsGroup).Controls.Add((Control)(object)ckDeleteOldestOnMediaFull);
			((Control)logFileOptionsGroup).Location = new Point(6, 162);
			((Control)logFileOptionsGroup).Name = "logFileOptionsGroup";
			((Control)logFileOptionsGroup).Size = new Size(426, 163);
			((Control)logFileOptionsGroup).TabIndex = 36;
			logFileOptionsGroup.TabStop = false;
			((Control)logFileOptionsGroup).Text = "Log file options";
			outputExportFileSelection.AllowEdit = true;
			outputExportFileSelection.AllowSelect = true;
			outputExportFileSelection.DialogType = DialogType.SaveAs;
			((Control)outputExportFileSelection).Enabled = false;
			outputExportFileSelection.FileName = "";
			outputExportFileSelection.Filter = "Calterm export file (exp.xml)|*.exp.xml";
			outputExportFileSelection.FilterIndex = 0;
			outputExportFileSelection.Flat = false;
			((Control)outputExportFileSelection).Location = new Point(132, 129);
			((Control)outputExportFileSelection).Name = "outputExportFileSelection";
			outputExportFileSelection.SelectionType = SelectionType.File;
			((Control)outputExportFileSelection).Size = new Size(276, 20);
			((Control)outputExportFileSelection).TabIndex = 50;
			inputParamFileSelection.AllowEdit = true;
			inputParamFileSelection.AllowSelect = true;
			inputParamFileSelection.DialogType = DialogType.OpenFile;
			((Control)inputParamFileSelection).Enabled = false;
			inputParamFileSelection.FileName = "";
			inputParamFileSelection.Filter = "All Files (*.*)|*.*";
			inputParamFileSelection.FilterIndex = 0;
			inputParamFileSelection.Flat = false;
			((Control)inputParamFileSelection).Location = new Point(132, 103);
			((Control)inputParamFileSelection).Name = "inputParamFileSelection";
			inputParamFileSelection.SelectionType = SelectionType.File;
			((Control)inputParamFileSelection).Size = new Size(276, 20);
			((Control)inputParamFileSelection).TabIndex = 49;
			((Control)outputExportFileNameLabel).Location = new Point(10, 129);
			((Control)outputExportFileNameLabel).Name = "outputExportFileNameLabel";
			((Control)outputExportFileNameLabel).Size = new Size(124, 20);
			((Control)outputExportFileNameLabel).TabIndex = 46;
			((Control)outputExportFileNameLabel).Text = "Output Export File:";
			outputExportFileNameLabel.TextAlign = (ContentAlignment)16;
			((Control)inputParamFileNameLabel).Location = new Point(10, 103);
			((Control)inputParamFileNameLabel).Name = "inputParamFileNameLabel";
			((Control)inputParamFileNameLabel).Size = new Size(124, 20);
			((Control)inputParamFileNameLabel).TabIndex = 43;
			((Control)inputParamFileNameLabel).Text = "Input Parameter List:";
			inputParamFileNameLabel.TextAlign = (ContentAlignment)16;
			((Control)ckFileNameFormat).AutoSize = true;
			((Control)ckFileNameFormat).Location = new Point(237, 21);
			((Control)ckFileNameFormat).Name = "ckFileNameFormat";
			((Control)ckFileNameFormat).Size = new Size(171, 17);
			((Control)ckFileNameFormat).TabIndex = 28;
			((Control)ckFileNameFormat).Text = "FileName in 24 hour timeformat";
			((ButtonBase)ckFileNameFormat).UseVisualStyleBackColor = true;
			((Control)exportParametersCheckBox).AutoSize = true;
			((Control)exportParametersCheckBox).Location = new Point(10, 78);
			((Control)exportParametersCheckBox).Name = "exportParametersCheckBox";
			((Control)exportParametersCheckBox).Size = new Size(161, 17);
			((Control)exportParametersCheckBox).TabIndex = 0;
			((Control)exportParametersCheckBox).Text = "Export parameters on startup";
			((ButtonBase)exportParametersCheckBox).UseVisualStyleBackColor = true;
			exportParametersCheckBox.CheckedChanged += checkBox1_CheckedChanged;
			ckDeleteOldestOnMediaFull.Checked = true;
			ckDeleteOldestOnMediaFull.CheckState = (CheckState)1;
			((Control)ckDeleteOldestOnMediaFull).Location = new Point(237, 51);
			((Control)ckDeleteOldestOnMediaFull).Name = "ckDeleteOldestOnMediaFull";
			((Control)ckDeleteOldestOnMediaFull).Size = new Size(189, 18);
			((Control)ckDeleteOldestOnMediaFull).TabIndex = 0;
			((Control)ckDeleteOldestOnMediaFull).Text = "Delete oldest file on media full";
			((Control)this).Controls.Add((Control)(object)paLogging);
			((Control)this).Name = "LogPropertiesControl";
			((Control)this).Size = new Size(472, 328);
			((Control)gbFileOptions).ResumeLayout(false);
			((Control)gbFileOptions).PerformLayout();
			((Control)paLogging).ResumeLayout(false);
			((Control)paLogging).PerformLayout();
			((Control)gbUCLOptions).ResumeLayout(false);
			((Control)gbUCLOptions).PerformLayout();
			((Control)logFileOptionsGroup).ResumeLayout(false);
			((Control)logFileOptionsGroup).PerformLayout();
			((Control)this).ResumeLayout(false);
		}

		public void Initialize()
		{
			GetOptions();
		}

		public void SetOptions()
		{
			options.Format = (Formats)Enum.Parse(typeof(Formats), ((Control)cmbDefaultLogfileFomat).Text);
			options.ShouldDisplayLogFile = ckDisplayLogFile.Checked;
			options.ShouldDisplaySaveAsDialog = ckSaveAsDialog.Checked;
			options.LogDLASecondsTime = ckDLASecondsTimestamp.Checked;
			options.ShouldDisplayLogFileNameIn24hrTimeFormat = ckFileNameFormat.Checked;
			options.LogFilePath = logFilePathSelector.SelectedPath;
			options.MaxLogFileSize = int.Parse(((Control)txtLogFileSize).Text);
			if (rbMultipleFiles.Checked)
			{
				options.FileCreationChoice = FileCreationChoice.Multiple;
			}
			else
			{
				options.FileCreationChoice = FileCreationChoice.Single;
			}
			options.DeleteOldestOnMediaFull = ckDeleteOldestOnMediaFull.Checked;
			options.ExportParamsOnStartup = exportParametersCheckBox.Checked;
			options.InputFilterFilename = inputParamFileSelection.FileName;
			options.OutputExportFilename = outputExportFileSelection.FileName;
			string text = ".exp.xml";
			if (!options.OutputExportFilename.EndsWith(text))
			{
				options.OutputExportFilename += text;
			}
			options.EnableUCL_Logging = enableUCLlogCheckbox.Checked;
			options.ShouldInsertEventNumber = ckInsertEventNumber.Checked;
			options.UCLPreTriggerTime = int.Parse(((Control)txtUCLPreTriggertime).Text);
			options.UCLPostTriggerTime = int.Parse(((Control)txtUCLPostTriggertime).Text);
			options.Save();
		}

		private void GetOptions()
		{
			((Control)cmbDefaultLogfileFomat).Text = options.Format.ToString();
			ckDisplayLogFile.Checked = options.ShouldDisplayLogFile;
			ckSaveAsDialog.Checked = options.ShouldDisplaySaveAsDialog;
			ckDLASecondsTimestamp.Checked = options.LogDLASecondsTime;
			logFilePathSelector.SelectedPath = options.LogFilePath;
			ckFileNameFormat.Checked = options.ShouldDisplayLogFileNameIn24hrTimeFormat;
			ckDeleteOldestOnMediaFull.Checked = options.DeleteOldestOnMediaFull;
			exportParametersCheckBox.Checked = options.ExportParamsOnStartup;
			inputParamFileSelection.FileName = options.InputFilterFilename;
			outputExportFileSelection.FileName = options.OutputExportFilename;
			((Control)txtLogFileSize).Text = options.MaxLogFileSize.ToString();
			rbMultipleFiles.Checked = options.FileCreationChoice == FileCreationChoice.Multiple;
			LogFileCreationOptionChanged(this, EventArgs.Empty);
			enableUCLlogCheckbox.Checked = options.EnableUCL_Logging;
			ckInsertEventNumber.Checked = options.ShouldInsertEventNumber;
			((Control)txtUCLPreTriggertime).Text = options.UCLPreTriggerTime.ToString();
			((Control)txtUCLPostTriggertime).Text = options.UCLPostTriggerTime.ToString();
		}

		private void InitializeFormatComboBox()
		{
			foreach (Formats value in Enum.GetValues(typeof(Formats)))
			{
				cmbDefaultLogfileFomat.Items.Add((object)value.ToString());
			}
		}

		private void txtLogFileSize_Validating(object sender, CancelEventArgs e)
		{
			//IL_0056: Unknown result type (might be due to invalid IL or missing references)
			e.Cancel = false;
			bool flag = true;
			int num = 10;
			try
			{
				num = int.Parse(((Control)txtLogFileSize).Text);
				if (num >= 10)
				{
					flag = false;
					e.Cancel = false;
				}
			}
			catch
			{
				flag = true;
			}
			if (flag)
			{
				MessageBox.Show("The Max Log file size must an Integer value not less than " + 10 + " KB.  Please enter a larger integer value.", "Logging", (MessageBoxButtons)0, (MessageBoxIcon)48);
				((Control)txtLogFileSize).Select();
				e.Cancel = true;
			}
		}

		private void LogFileCreationOptionChanged(object sender, EventArgs e)
		{
			bool flag = rbMultipleFiles.Checked;
			((Control)txtLogFileSize).Enabled = flag;
			((Control)ckDisplayLogFile).Enabled = !flag;
			((Control)ckSaveAsDialog).Enabled = !flag;
		}

		private void txtUCLPreTriggertime_Validating(object sender, CancelEventArgs e)
		{
			//IL_0043: Unknown result type (might be due to invalid IL or missing references)
			e.Cancel = false;
			bool flag = true;
			try
			{
				int num = int.Parse(((Control)txtUCLPreTriggertime).Text);
				if (num >= 0 && num <= 60)
				{
					flag = false;
					e.Cancel = false;
				}
			}
			catch
			{
				flag = true;
			}
			if (flag)
			{
				MessageBox.Show("The Pre trigger time must an Integer value between 0 and 60 s.Please enter a valid value.", "Logging", (MessageBoxButtons)0, (MessageBoxIcon)48);
				((Control)txtUCLPreTriggertime).Select();
				e.Cancel = true;
			}
		}

		private void txtUCLPostTriggertime_Validating(object sender, CancelEventArgs e)
		{
			//IL_0043: Unknown result type (might be due to invalid IL or missing references)
			e.Cancel = false;
			bool flag = true;
			try
			{
				int num = int.Parse(((Control)txtUCLPostTriggertime).Text);
				if (num >= 0 && num <= 60)
				{
					flag = false;
					e.Cancel = false;
				}
			}
			catch
			{
				flag = true;
			}
			if (flag)
			{
				MessageBox.Show("The Post trigger time must an Integer value between 0 and 60 s.Please enter a valid value.", "Logging", (MessageBoxButtons)0, (MessageBoxIcon)48);
				((Control)txtUCLPostTriggertime).Select();
				e.Cancel = true;
			}
		}

		private void enableUCLlogCheckbox_CheckedChanged(object sender, EventArgs e)
		{
			if (enableUCLlogCheckbox.Checked)
			{
				((Control)txtUCLPreTriggertime).Enabled = true;
				((Control)txtUCLPostTriggertime).Enabled = true;
			}
			else
			{
				((Control)txtUCLPreTriggertime).Enabled = false;
				((Control)txtUCLPostTriggertime).Enabled = false;
			}
		}

		private void checkBox1_CheckedChanged(object sender, EventArgs e)
		{
			if (exportParametersCheckBox.Checked)
			{
				((Control)inputParamFileSelection).Enabled = true;
				((Control)outputExportFileSelection).Enabled = true;
			}
			else
			{
				((Control)inputParamFileSelection).Enabled = false;
				((Control)outputExportFileSelection).Enabled = false;
			}
		}
	}
	public class LogView
	{
		internal const string TransformExtension = ".xslt";

		internal const string TransformPrefix = "Cummins.Logging.logging_";

		private LogModel model;

		private LogController controller;

		private LogWriter logWriter;

		private LogWriter uclogWriter;

		private DateTime lastSweepTime;

		private bool flushedOnce;

		public LogView(LogModel model, LogController controller)
		{
			this.model = model;
			this.controller = controller;
			model.MonitoredListChangedEvent += OnMonitoredListChanged;
			model.UCLMonitoredListChangedEvent += OnUCLMonitoredListChanged;
			model.StateChangingEvent += OnStateChanging;
			model.UCLStateChangingEvent += OnUCLStateChanging;
			controller.LogSweptEvent = (LogSweptEventHandler)Delegate.Combine(controller.LogSweptEvent, new LogSweptEventHandler(OnLogSwept));
			controller.UCLogSweptEvent = (UCLogSweptEventHandler)Delegate.Combine(controller.UCLogSweptEvent, new UCLogSweptEventHandler(OnUCLogSwept));
			controller.LoggingOverEvent = (LoggingOverEventHandler)Delegate.Combine(controller.LoggingOverEvent, new LoggingOverEventHandler(OnLoggingOver));
			controller.UCLoggingOverEvent = (UCLoggingOverEventHandler)Delegate.Combine(controller.UCLoggingOverEvent, new UCLoggingOverEventHandler(OnUCLoggingOver));
			controller.LogFileSaveAbortedEvent += OnSaveLogfileAborted;
		}

		private void OnMonitoredListChanged(object caller, MonitoredListChangedEventArgs args)
		{
			if (args.LogData.Columns.Count > 1 && logWriter != null)
			{
				logWriter.WriteHeader(args.LogData.Columns);
			}
		}

		private void OnUCLMonitoredListChanged(object caller, UCLMonitoredListChangedEventArgs args)
		{
			if (args.UCLogData.Columns.Count > 1 && uclogWriter != null)
			{
				uclogWriter.WriteUCLHeader(args.UCLogData.Columns);
			}
		}

		private void OnStateChanging(object caller, StateChangeEventArgs args)
		{
			if (args.NewState == LoggingState.Logging)
			{
				if (model.Options.Format == Formats.CSV)
				{
					logWriter = new CSVLogWriter(model.Options);
				}
				else if (model.Options.Format == Formats.HTML)
				{
					logWriter = new HTMLLogWriter(model.Options);
				}
				else if (model.Options.Format == Formats.TXT)
				{
					logWriter = new TXTLogWriter(model);
				}
				else
				{
					logWriter = new XMLLogWriter(model.Options);
				}
				lastSweepTime = DateTime.Now;
				logWriter.WriteFileHeader();
				logWriter.WriteHeader(args.MonitoredList);
			}
			else if (args.NewState == LoggingState.Idle || (args.OldState == LoggingState.Stopping && args.NewState == LoggingState.Buffering) || (args.OldState == LoggingState.Logging && args.NewState == LoggingState.Buffering))
			{
				if (logWriter != null)
				{
					logWriter.Close();
				}
			}
			else if (args.NewState == LoggingState.Abort)
			{
				logWriter = null;
			}
		}

		private void OnUCLStateChanging(object caller, UCLStateChangeEventArgs args)
		{
			if (args.NewState == UCLState.Starting)
			{
				if (model.Options.Format == Formats.CSV)
				{
					uclogWriter = new CSVLogWriter(model.Options);
				}
				else if (model.Options.Format == Formats.HTML)
				{
					uclogWriter = new HTMLLogWriter(model.Options);
				}
				else if (model.Options.Format == Formats.TXT)
				{
					uclogWriter = new TXTLogWriter(model);
				}
				else
				{
					uclogWriter = new XMLLogWriter(model.Options);
				}
				uclogWriter.WriteFileHeader();
				uclogWriter.WriteUCLHeader(args.MonitoredList);
			}
		}

		private void OnLogSwept(object caller, LogSweptEventArgs args)
		{
			lock (this)
			{
				if (logWriter == null)
				{
					throw new InvalidOperationException("LogWriter not initialized yet");
				}
				logWriter.WriteData(args.Log);
				DateTime now = DateTime.Now;
				TimeSpan timeSpan = now - lastSweepTime;
				int num = timeSpan.Minutes * 60 + timeSpan.Seconds;
				if (!flushedOnce || num >= model.Options.FlushFrequency)
				{
					logWriter.Flush();
					lastSweepTime = now;
					flushedOnce = true;
				}
				if (model.Options.DisplayFreeSpace)
				{
					logWriter.CalculateFreeSpaces();
				}
				if (model.Options.FileCreationChoice == FileCreationChoice.Multiple && logWriter.LogSize >= model.Options.MaxLogFileSize)
				{
					logWriter.Save(model.Options.GetLogFileName());
					logWriter.WriteFileHeader();
					logWriter.WriteHeader(args.Log.Columns);
				}
			}
		}

		private void OnUCLogSwept(object caller, UCLogSweptEventArgs args)
		{
			lock (this)
			{
				if (uclogWriter == null)
				{
					throw new InvalidOperationException("User Centric LogWriter not initialized yet");
				}
				uclogWriter.WriteUCLData(args.UCLog);
				uclogWriter.UCLFlush();
			}
		}

		private void OnLoggingOver(object sender, LoggingOverEventArgs e)
		{
			try
			{
				if (logWriter == null)
				{
					throw new InvalidOperationException("LogWriter not Initialized");
				}
				string text = e.Format.ToString().ToLower();
				string text2 = e.LogFileName;
				if (!text2.EndsWith(text, ignoreCase: true, null))
				{
					text2 = text2 + ".log." + text;
				}
				logWriter.Save(text2);
				EventLogger.Info("Logging", "Saved log file: " + text2);
				if (model.Options.FileCreationChoice == FileCreationChoice.Single && e.DisplayLogFile)
				{
					Process.Start(text2);
				}
				logWriter = null;
				flushedOnce = false;
			}
			catch (Exception ex)
			{
				EventLogger.Error("Logging", ex.Message, "StackTrace\r\n============\r\n" + ex.StackTrace);
			}
		}

		private void OnUCLoggingOver(object sender, LoggingOverEventArgs e)
		{
			try
			{
				if (uclogWriter == null)
				{
					throw new InvalidOperationException("LogWriter not Initialized");
				}
				uclogWriter.Save(e.LogFileName);
				EventLogger.Info("User centric logging", "Saved mini log file: " + e.LogFileName);
				uclogWriter = null;
			}
			catch (Exception ex)
			{
				EventLogger.Error("User centric logging", ex.Message, "StackTrace\r\n============\r\n" + ex.StackTrace);
			}
		}

		private void OnSaveLogfileAborted(object sender, EventArgs e)
		{
			logWriter = null;
			flushedOnce = false;
		}

		private void Transform(string inFileName, string outFileName, Formats format)
		{
			//IL_000f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0015: Expected O, but got Unknown
			//IL_0015: Unknown result type (might be due to invalid IL or missing references)
			//IL_001b: Expected O, but got Unknown
			//IL_0048: Unknown result type (might be due to invalid IL or missing references)
			//IL_004f: Expected O, but got Unknown
			TextReader textReader = new StreamReader(inFileName);
			StreamWriter streamWriter = File.CreateText(outFileName);
			XPathDocument val = new XPathDocument(textReader);
			XslTransform val2 = new XslTransform();
			string name = "Cummins.Logging.logging_" + format.ToString().ToLower() + ".xslt";
			XmlTextReader val3 = new XmlTextReader(Assembly.GetExecutingAssembly().GetManifestResourceStream(name));
			val2.Load((XmlReader)(object)val3, (XmlResolver)null, (Evidence)null);
			val2.Transform((IXPathNavigable)(object)val, (XsltArgumentList)null, (TextWriter)streamWriter, (XmlResolver)null);
			((XmlReader)val3).Close();
			streamWriter.Close();
		}
	}
	public struct HeaderData
	{
		private string names;

		private string units;

		private string addresses;

		private bool isDirty;

		public string Names
		{
			get
			{
				return names;
			}
			set
			{
				names = value;
			}
		}

		public string Units
		{
			get
			{
				return units;
			}
			set
			{
				units = value;
			}
		}

		public string Addresses
		{
			get
			{
				return addresses;
			}
			set
			{
				addresses = value;
			}
		}

		public bool IsDirty
		{
			get
			{
				return isDirty;
			}
			set
			{
				isDirty = value;
			}
		}
	}
	public struct UCLHeaderData
	{
		private string names;

		private string units;

		private string addresses;

		private bool isDirty;

		public string Names
		{
			get
			{
				return names;
			}
			set
			{
				names = value;
			}
		}

		public string Units
		{
			get
			{
				return units;
			}
			set
			{
				units = value;
			}
		}

		public string Addresses
		{
			get
			{
				return addresses;
			}
			set
			{
				addresses = value;
			}
		}

		public bool IsDirty
		{
			get
			{
				return isDirty;
			}
			set
			{
				isDirty = value;
			}
		}
	}
	public class FileInfoComparer : IComparer
	{
		public int Compare(object x, object y)
		{
			FileInfo fileInfo = (FileInfo)x;
			FileInfo fileInfo2 = (FileInfo)y;
			return fileInfo.LastWriteTime.CompareTo(fileInfo2.LastWriteTime);
		}
	}
	public class LogStreamWriter : StreamWriter
	{
		private object writeLock = new object();

		private bool closed;

		private long sizeWritten;

		public long SizeWritten => sizeWritten;

		public bool Closed => closed;

		public LogStreamWriter(string logFileName)
			: base(logFileName)
		{
		}

		public override void Write(string value)
		{
			try
			{
				lock (writeLock)
				{
					if (!Closed)
					{
						base.Write(value);
						sizeWritten += value.Length;
					}
				}
			}
			catch (Exception ex)
			{
				EventLogger.Warn("Logging", ex.Message, ex);
			}
		}

		public override void WriteLine(string value)
		{
			try
			{
				lock (writeLock)
				{
					if (!Closed)
					{
						((TextWriter)this).WriteLine(value);
						sizeWritten += value.Length;
					}
				}
			}
			catch (Exception ex)
			{
				EventLogger.Warn("Logging", ex.Message, ex);
			}
		}

		public override void Flush()
		{
			try
			{
				if (!Closed)
				{
					base.Flush();
				}
			}
			catch (Exception ex)
			{
				EventLogger.Warn("Logging", ex.Message, ex);
			}
		}

		public override void Close()
		{
			try
			{
				lock (writeLock)
				{
					base.Close();
					closed = true;
				}
			}
			catch (Exception ex)
			{
				EventLogger.Warn("Logging", ex.Message, ex);
			}
		}
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
}
namespace Cummins
{
	public class J1939_71PGNMap : Dictionary<string, PGN>
	{
		private uint _timeStamp;

		public uint TimeStamp
		{
			get
			{
				return _timeStamp;
			}
			set
			{
				_timeStamp = value;
			}
		}
	}
	public class CompositeJ1939_71Data : Dictionary<ushort, J1939_71PGNMap>
	{
	}
	public class PCLSubscriptionHelper
	{
		public static void MergeJ1939_71Notifications(CompositeJ1939_71Data compositeData, J1939_71DataRefreshEventArgs newData)
		{
			J1939_71PGNMap j1939_71PGNMap = null;
			foreach (PGNList j1939_71Datum in newData.J1939_71Data)
			{
				if (j1939_71Datum.PGNs == null)
				{
					continue;
				}
				if (!compositeData.ContainsKey(j1939_71Datum.SourceAddress))
				{
					compositeData.Add(j1939_71Datum.SourceAddress, new J1939_71PGNMap());
				}
				j1939_71PGNMap = compositeData[j1939_71Datum.SourceAddress];
				j1939_71PGNMap.TimeStamp = j1939_71Datum.TimeStamp;
				foreach (PGN pGN in j1939_71Datum.PGNs)
				{
					if (pGN.SPNs != null)
					{
						if (!j1939_71PGNMap.ContainsKey(pGN.Name))
						{
							j1939_71PGNMap.Add(pGN.Name, pGN);
						}
						else
						{
							j1939_71PGNMap[pGN.Name] = pGN;
						}
					}
				}
			}
		}

		public static List<J1939_71DataRefreshEventArgs> ConvertToNotification(CompositeJ1939_71Data J1939_71CompositeData)
		{
			List<J1939_71DataRefreshEventArgs> list = new List<J1939_71DataRefreshEventArgs>();
			J1939_71DataRefreshEventArgs e = null;
			foreach (KeyValuePair<ushort, J1939_71PGNMap> J1939_71CompositeDatum in J1939_71CompositeData)
			{
				e = new J1939_71DataRefreshEventArgs();
				e.IsProcessed = false;
				e.SourceAddress = AddressFactory.ProductAddressValue(J1939_71CompositeDatum.Key);
				e.J1939_71Data = ConvertJ1939_71PGNMapToPGNList(e.SourceAddress, J1939_71CompositeDatum.Value);
				list.Add(e);
			}
			return list;
		}

		private static List<PGNList> ConvertJ1939_71PGNMapToPGNList(IAddressValue iAddressValue, J1939_71PGNMap j1939_71PGNMap)
		{
			List<PGNList> list = new List<PGNList>();
			PGNList pGNList = null;
			pGNList = new PGNList();
			pGNList.SourceAddress = iAddressValue.DeviceAddress;
			pGNList.TimeStamp = j1939_71PGNMap.TimeStamp;
			foreach (PGN value in j1939_71PGNMap.Values)
			{
				pGNList.PGNs.Add(value);
			}
			list.Add(pGNList);
			return list;
		}
	}
}
namespace Cummins.Logging
{
	public class TimerRecorder : LogRecorder, IDisposable
	{
		private Timer logRateTimer;

		private bool disposed;

		private Hashtable notifications = new Hashtable();

		private CompositeJ1939_71Data _j1939_71CompositeData;

		private CompositeJ1939_71Data J1939_71CompositeData
		{
			get
			{
				if (_j1939_71CompositeData == null)
				{
					_j1939_71CompositeData = new CompositeJ1939_71Data();
				}
				return _j1939_71CompositeData;
			}
			set
			{
				_j1939_71CompositeData = value;
			}
		}

		public TimerRecorder(LogModel Model, ArrayList registeredIds, int Rate)
			: base(Model)
		{
			if (logRateTimer == null)
			{
				logRateTimer = new Timer(OnLogIntervalElapsed, null, Rate, Rate);
			}
			else
			{
				logRateTimer.Change(Rate, Rate);
			}
		}

		~TimerRecorder()
		{
			Dispose(disposing: false);
		}

		protected virtual void Dispose(bool disposing)
		{
			if (!disposed && disposing)
			{
				logRateTimer.Change(-1, -1);
				logRateTimer = null;
			}
			disposed = true;
		}

		public void Dispose()
		{
			Dispose(disposing: true);
			GC.SuppressFinalize(this);
		}

		public override int RecordData(DataRefreshEventArgs e)
		{
			lock (notifications)
			{
				if (e is J1939_71DataRefreshEventArgs)
				{
					PCLSubscriptionHelper.MergeJ1939_71Notifications(J1939_71CompositeData, e as J1939_71DataRefreshEventArgs);
				}
				else if (notifications.ContainsKey(e.SubscriptionHashCode))
				{
					notifications[e.SubscriptionHashCode] = e;
				}
				else
				{
					notifications.Add(e.SubscriptionHashCode, e);
				}
				return -1;
			}
		}

		public override int RecordUCLData(DataRefreshEventArgs e)
		{
			lock (notifications)
			{
				if (e is J1939_71DataRefreshEventArgs)
				{
					PCLSubscriptionHelper.MergeJ1939_71Notifications(J1939_71CompositeData, e as J1939_71DataRefreshEventArgs);
				}
				else if (notifications.ContainsKey(e.SubscriptionHashCode))
				{
					notifications[e.SubscriptionHashCode] = e;
				}
				else
				{
					notifications.Add(e.SubscriptionHashCode, e);
				}
				return -1;
			}
		}

		private void OnLogIntervalElapsed(object source)
		{
			try
			{
				Hashtable hashtable = null;
				DataRefreshEventArgs e = null;
				lock (logModel.LogBuffer)
				{
					lock (notifications)
					{
						hashtable = (Hashtable)notifications.Clone();
						notifications.Clear();
					}
					DataRow row = logModel.LogBuffer.NewRow();
					RecordPCTime(row);
					RecordEventNumber(row);
					RecordFaults(row);
					foreach (int key in hashtable.Keys)
					{
						e = (DataRefreshEventArgs)hashtable[key];
						RecordNotification(e, row);
					}
					RecordNotification(J1939_71CompositeData, row);
					J1939_71CompositeData.Clear();
					logModel.LogBuffer.Rows.Add(row);
				}
				lock (logModel.UCLogBuffer)
				{
					DataRow row = logModel.UCLogBuffer.NewRow();
					RecordPCTime(row);
					RecordFaults(row);
					foreach (int key2 in hashtable.Keys)
					{
						if (e != null)
						{
							e = (DataRefreshEventArgs)hashtable[key2];
							RecordUCLNotification(e, row);
							continue;
						}
						List<J1939_71DataRefreshEventArgs> list = hashtable[key2] as List<J1939_71DataRefreshEventArgs>;
						List<J1939_71DataRefreshEventArgs> list2;
						lock (list)
						{
							list2 = new List<J1939_71DataRefreshEventArgs>(list);
							list.Clear();
						}
						if (list2 == null)
						{
							continue;
						}
						foreach (J1939_71DataRefreshEventArgs item in list2)
						{
							RecordUCLNotification(item, row);
						}
					}
					logModel.UCLogBuffer.Rows.Add(row);
				}
			}
			catch (Exception)
			{
			}
		}

		private bool RecordNotification(DataRefreshEventArgs e, DataRow row)
		{
			if (e.DataSourceType == DataSourceTypeEnum.ECM)
			{
				RecordNotification((e as ECMDataRefreshEventArgs).ECMData, (e as ECMDataRefreshEventArgs).SourceAddress, row);
			}
			else if (e.DataSourceType == DataSourceTypeEnum.ASAM)
			{
				RecordNotification((e as ASAMDataRefreshEventArgs).ASAMData, (e as ASAMDataRefreshEventArgs).SourceAddress, row);
			}
			return true;
		}

		private bool RecordUCLNotification(DataRefreshEventArgs e, DataRow row)
		{
			if (e.DataSourceType == DataSourceTypeEnum.ECM)
			{
				RecordUCLNotification((e as ECMDataRefreshEventArgs).ECMData, (e as ECMDataRefreshEventArgs).SourceAddress, row);
			}
			else if (e.DataSourceType == DataSourceTypeEnum.ASAM)
			{
				RecordUCLNotification((e as ASAMDataRefreshEventArgs).ASAMData, (e as ASAMDataRefreshEventArgs).SourceAddress, row);
			}
			return true;
		}

		public void ChangeTime(int newtime)
		{
			if (logRateTimer != null)
			{
				logRateTimer.Change(newtime, newtime);
			}
		}
	}
	public class TXTLogWriter : StreamedLogWriter
	{
		internal static char Space = ' ';

		internal static string Blank = " ";

		internal static int Padding = 2;

		internal static string FaultsPadding = "  ";

		private LogModel logModel;

		private int width;

		public TXTLogWriter(LogModel model)
			: base(model.Options)
		{
			logModel = model;
			width = 12 + Padding;
		}

		public override void WriteFileHeader()
		{
			base.Writer.WriteLine("Log File version :" + options.CustomLogHeader.LogHeader.NewLogHeaderRow().LogFileVersion);
			string value = DateTime.Now.ToShortDateString() + " " + DateTime.Now.ToLongTimeString();
			base.Writer.WriteLine(value);
			switch (options.RecordingMode)
			{
			case RecordingModes.AnyDataReceived:
				base.Writer.WriteLine("Log Mode :Log When Any Data Received");
				break;
			case RecordingModes.AllDataReceived:
				base.Writer.WriteLine("Log Mode :Log When All Data Received");
				break;
			case RecordingModes.UserSpecifiedRate:
				base.Writer.WriteLine("Log Mode :Log At User Specified Rate");
				base.Writer.WriteLine("Logging Rate is :" + options.LogRate + "ms");
				break;
			}
			WriteCustomHeader();
			base.Writer.WriteLine("--------------------------");
		}

		public override void WriteHeader(DataColumnCollection fields)
		{
			CalculateWidth("Parameter Name");
			CalculateWidth("Units");
			CalculateWidth("Source Address");
			CalculateWidth(fields);
			string text = "Parameter Name";
			text = text.PadLeft(width, Space);
			headerData.Names = text;
			text = "Units";
			text = text.PadLeft(width, Space);
			headerData.Units = text;
			text = "Source Address";
			text = text.PadLeft(width, Space);
			headerData.Addresses = text;
			DataColumn dataColumn = null;
			for (int i = 1; i < fields.Count; i++)
			{
				if (i != logModel.ActiveFaultsIndex && i != logModel.InactiveFaultsIndex)
				{
					dataColumn = fields[i];
					if ((bool)dataColumn.ExtendedProperties["Active"])
					{
						text = dataColumn.ExtendedProperties["displayName"].ToString();
						text = text.PadLeft(width, Space);
						headerData.Names += text;
						text = dataColumn.ExtendedProperties["units"].ToString();
						text = text.PadLeft(width, Space);
						headerData.Units += text;
						text = dataColumn.ExtendedProperties["address"].ToString();
						text = text.PadLeft(width, Space);
						headerData.Addresses += text;
					}
				}
			}
			if (logModel.ActiveFaultsIndex != -1)
			{
				headerData.Names += FaultsPadding;
				headerData.Names += fields[logModel.ActiveFaultsIndex].ExtendedProperties["displayName"];
			}
			if (logModel.InactiveFaultsIndex != -1)
			{
				headerData.Names += FaultsPadding;
				headerData.Names += fields[logModel.InactiveFaultsIndex].ExtendedProperties["displayName"];
			}
			headerData.IsDirty = true;
		}

		public override void WriteUCLHeader(DataColumnCollection fields)
		{
			CalculateWidth("Parameter Name");
			CalculateWidth("Units");
			CalculateWidth("Source Address");
			CalculateWidth(fields);
			string text = "Parameter Name";
			text = text.PadLeft(width, Space);
			uclheaderData.Names = text;
			text = "Units";
			text = text.PadLeft(width, Space);
			uclheaderData.Units = text;
			text = "Source Address";
			text = text.PadLeft(width, Space);
			uclheaderData.Addresses = text;
			DataColumn dataColumn = null;
			for (int i = 1; i < fields.Count; i++)
			{
				if (i != logModel.ActiveFaultsIndex && i != logModel.InactiveFaultsIndex)
				{
					dataColumn = fields[i];
					if ((bool)dataColumn.ExtendedProperties["Active"])
					{
						text = dataColumn.ExtendedProperties["displayName"].ToString();
						text = text.PadLeft(width, Space);
						uclheaderData.Names += text;
						text = dataColumn.ExtendedProperties["units"].ToString();
						text = text.PadLeft(width, Space);
						uclheaderData.Units += text;
						text = dataColumn.ExtendedProperties["address"].ToString();
						text = text.PadLeft(width, Space);
						uclheaderData.Addresses += text;
					}
				}
			}
			if (logModel.ActiveFaultsIndex != -1)
			{
				uclheaderData.Names += FaultsPadding;
				uclheaderData.Names += fields[logModel.ActiveFaultsIndex].ExtendedProperties["displayName"];
			}
			if (logModel.InactiveFaultsIndex != -1)
			{
				uclheaderData.Names += FaultsPadding;
				uclheaderData.Names += fields[logModel.InactiveFaultsIndex].ExtendedProperties["displayName"];
			}
			uclheaderData.IsDirty = true;
		}

		public override void WriteData(DataTable values)
		{
			if (headerData.IsDirty)
			{
				base.Writer.WriteLine(headerData.Names);
				base.Writer.WriteLine(headerData.Units);
				base.Writer.WriteLine(headerData.Addresses);
				headerData.IsDirty = false;
			}
			foreach (DataRow row in values.Rows)
			{
				StringBuilder stringBuilder = new StringBuilder();
				string blank = Blank;
				blank = blank.PadLeft(width, Space);
				stringBuilder.Append(blank);
				blank = "";
				if ((bool)values.Columns["DLA Timestamp"].ExtendedProperties["Active"])
				{
					if (row["DLA Timestamp"] != DBNull.Value)
					{
						blank = FormatTime((uint)row["DLA Timestamp"]);
					}
					blank = blank.PadLeft(width, Space);
					stringBuilder.Append(blank);
				}
				for (int i = 2; i < values.Columns.Count; i++)
				{
					if (i == logModel.ActiveFaultsIndex || i == logModel.InactiveFaultsIndex)
					{
						continue;
					}
					bool flag = (bool)values.Columns[i].ExtendedProperties["Active"];
					bool flag2 = (bool)values.Columns[i].ExtendedProperties["Removed"];
					if (flag)
					{
						if (row[i] != DBNull.Value)
						{
							blank = row[i].ToString();
							blank = blank.PadLeft(width, Space);
							stringBuilder.Append(blank);
						}
						else if (!flag2)
						{
							blank = "NaN";
							blank = blank.PadLeft(width, Space);
							stringBuilder.Append("NaN");
						}
						else if (flag2)
						{
							blank = Blank;
							blank = blank.PadLeft(width, Space);
							stringBuilder.Append(blank);
						}
					}
				}
				if (-1 != logModel.ActiveFaultsIndex)
				{
					stringBuilder.Append(FaultsPadding);
					stringBuilder.Append(row[logModel.ActiveFaultsIndex].ToString());
				}
				if (-1 != logModel.InactiveFaultsIndex)
				{
					stringBuilder.Append(FaultsPadding);
					stringBuilder.Append(row[logModel.InactiveFaultsIndex].ToString());
				}
				base.Writer.WriteLine(stringBuilder.ToString());
			}
		}

		public override void WriteUCLData(DataTable values)
		{
			if (uclheaderData.IsDirty)
			{
				base.Writer.WriteLine(uclheaderData.Names);
				base.Writer.WriteLine(uclheaderData.Units);
				base.Writer.WriteLine(uclheaderData.Addresses);
				uclheaderData.IsDirty = false;
			}
			foreach (DataRow row in values.Rows)
			{
				StringBuilder stringBuilder = new StringBuilder();
				string blank = Blank;
				blank = blank.PadLeft(width, Space);
				stringBuilder.Append(blank);
				blank = "";
				if ((bool)values.Columns["DLA Timestamp"].ExtendedProperties["Active"])
				{
					if (row["DLA Timestamp"] != DBNull.Value)
					{
						blank = FormatTime((uint)row["DLA Timestamp"]);
					}
					blank = blank.PadLeft(width, Space);
					stringBuilder.Append(blank);
				}
				for (int i = 2; i < values.Columns.Count; i++)
				{
					if (i == logModel.ActiveFaultsIndex || i == logModel.InactiveFaultsIndex)
					{
						continue;
					}
					bool flag = (bool)values.Columns[i].ExtendedProperties["Active"];
					bool flag2 = (bool)values.Columns[i].ExtendedProperties["Removed"];
					if (flag)
					{
						if (row[i] != DBNull.Value)
						{
							blank = row[i].ToString();
							blank = blank.PadLeft(width, Space);
							stringBuilder.Append(blank);
						}
						else if (!flag2)
						{
							blank = "NaN";
							blank = blank.PadLeft(width, Space);
							stringBuilder.Append("NaN");
						}
						else if (flag2)
						{
							blank = Blank;
							blank = blank.PadLeft(width, Space);
							stringBuilder.Append(blank);
						}
					}
				}
				if (-1 != logModel.ActiveFaultsIndex)
				{
					stringBuilder.Append(FaultsPadding);
					stringBuilder.Append(row[logModel.ActiveFaultsIndex].ToString());
				}
				if (-1 != logModel.InactiveFaultsIndex)
				{
					stringBuilder.Append(FaultsPadding);
					stringBuilder.Append(row[logModel.InactiveFaultsIndex].ToString());
				}
				base.Writer.WriteLine(stringBuilder.ToString());
			}
		}

		private void CalculateWidth(DataColumnCollection fields)
		{
			for (int i = 1; i < fields.Count; i++)
			{
				if (i != logModel.ActiveFaultsIndex && i != logModel.InactiveFaultsIndex)
				{
					CalculateWidth(fields[i].ExtendedProperties["displayName"].ToString());
				}
			}
		}

		private void CalculateWidth(string str)
		{
			if (width - Padding < str.Length)
			{
				width = str.Length + Padding;
			}
		}

		private void WriteCustomHeader()
		{
			if (options.HeaderNotes.Length > 0)
			{
				base.Writer.WriteLine("Notes:" + options.HeaderNotes);
			}
			foreach (CustomLogHeader.ParametersRow parameter in options.CustomLogHeader.Parameters)
			{
				string empty = string.Empty;
				empty = parameter.DeviceAddress + Space + parameter.ParameterName + Space + options.GetParameterValue(parameter.DeviceAddress, parameter.ParameterName);
				base.Writer.WriteLine(empty);
			}
			if (options.AddConfigNameToLogHeader)
			{
				base.Writer.WriteLine(Space + "Config File Name" + Space + options.ConfigFileName);
			}
		}
	}
	public delegate void MonitoredListChangedEventHandler(object sender, MonitoredListChangedEventArgs e);
	public delegate void UCLMonitoredListChangedEventHandler(object sender, UCLMonitoredListChangedEventArgs e);
	public delegate void StateChangingEventHandler(object sender, StateChangeEventArgs e);
	public delegate void UCLStateChangingEventHandler(object sender, UCLStateChangeEventArgs e);
	public delegate void StateChangedEventHandler(object sender, StateChangeEventArgs e);
	public delegate void UCLStateChangedEventHandler(object sender, UCLStateChangeEventArgs e);
	public delegate void LogSweptEventHandler(object sender, LogSweptEventArgs e);
	public delegate void UCLogSweptEventHandler(object sender, UCLogSweptEventArgs e);
	public delegate void LoggingOverEventHandler(object sender, LoggingOverEventArgs e);
	public delegate void UCLoggingOverEventHandler(object sender, LoggingOverEventArgs e);
	public enum LoggingType
	{
		Monitor,
		BAM,
		IDL
	}
	public enum NetworkType
	{
		J1939,
		J1708
	}
	public enum LoggingState
	{
		Idle,
		Buffering,
		Starting,
		Logging,
		Stopping,
		Error,
		Abort
	}
	public enum Mode
	{
		Manual,
		EventDriven
	}
	public enum FaultState
	{
		Active,
		InActive,
		New,
		Clear
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
	public enum RecordingModes
	{
		Unknown,
		AnyDataReceived,
		AllDataReceived,
		UserSpecifiedRate
	}
	public enum LoggingRateUnits
	{
		ms,
		Hz
	}
	public enum ConditionJoiner
	{
		AND,
		OR,
		NONE
	}
	public enum Formats
	{
		HTML = 1,
		CSV,
		TXT,
		XML
	}
	public enum FileCreationChoice
	{
		Single,
		Multiple
	}
	public enum Prefix
	{
		monitor,
		bam,
		idl
	}
	public enum UCLState
	{
		Inactive,
		Active,
		Buffering,
		Starting,
		Stopping
	}
	public enum LogInstance
	{
		Individual,
		Concurrent
	}
	public class XMLLogWriter : StreamedLogWriter
	{
		internal const string LogSchema = "Cummins.Logging.logschema.xsd";

		internal const string SessionTableName = "session";

		internal const string SessionID = "session_Id";

		internal const string HeaderTableName = "header";

		internal const string HeaderID = "header_Id";

		internal const string ParameterHeaderName = "parameter";

		internal const string LogDataTableName = "data";

		internal const string DataID = "data_Id";

		internal const string DataElementTableName = "dataElement";

		internal new const string NotANumber = "NaN";

		private DataSet logData;

		private int activeSessionID = -1;

		private DataTable Session => logData.Tables["session"];

		private DataTable Header => logData.Tables["header"];

		private DataTable ParameterHeader => logData.Tables["parameter"];

		private DataTable LogData => logData.Tables["data"];

		private DataTable LogElement => logData.Tables["dataElement"];

		public XMLLogWriter(LoggingOptions options)
			: base(options)
		{
			logData = new DataSet("logFile");
			Stream stream = null;
			stream = Assembly.GetExecutingAssembly().GetManifestResourceStream("Cummins.Logging.logschema.xsd");
			if (stream != null)
			{
				logData.ReadXmlSchema(stream);
				tempFileName = options.GetLogFileName() + ".tmp";
				return;
			}
			throw new ResourceException(Facility.Logging, 1, "Unable to load Schema", "Cummins.Logging.logschema.xsd");
		}

		public override void WriteFileHeader()
		{
		}

		public override void WriteHeader(DataColumnCollection parameters)
		{
			lock (this)
			{
				DataRow dataRow = Session.NewRow();
				Session.Rows.Add(dataRow);
				activeSessionID = (int)dataRow["session_Id"];
				dataRow = Header.NewRow();
				dataRow["session_Id"] = activeSessionID;
				dataRow["Date"] = DateTime.Now.ToShortDateString() + " " + DateTime.Now.ToLongTimeString();
				Header.Rows.Add(dataRow);
				int num = (int)dataRow["header_Id"];
				DataColumn dataColumn = null;
				for (int i = 1; i < parameters.Count; i++)
				{
					dataColumn = parameters[i];
					if ((bool)dataColumn.ExtendedProperties["Active"])
					{
						dataRow = ParameterHeader.NewRow();
						dataRow["header_Id"] = num;
						dataRow["source"] = dataColumn.ExtendedProperties["address"].ToString();
						dataRow["name"] = (string)dataColumn.ExtendedProperties["displayName"];
						dataRow["units"] = (string)dataColumn.ExtendedProperties["units"];
						ParameterHeader.Rows.Add(dataRow);
					}
				}
				ParameterHeader.AcceptChanges();
				Header.AcceptChanges();
				Session.AcceptChanges();
			}
		}

		public override void WriteUCLHeader(DataColumnCollection parameters)
		{
			lock (this)
			{
				DataRow dataRow = Session.NewRow();
				Session.Rows.Add(dataRow);
				activeSessionID = (int)dataRow["session_Id"];
				dataRow = Header.NewRow();
				dataRow["session_Id"] = activeSessionID;
				dataRow["Date"] = DateTime.Now.ToShortDateString() + " " + DateTime.Now.ToLongTimeString();
				Header.Rows.Add(dataRow);
				int num = (int)dataRow["header_Id"];
				DataColumn dataColumn = null;
				for (int i = 1; i < parameters.Count; i++)
				{
					dataColumn = parameters[i];
					if ((bool)dataColumn.ExtendedProperties["Active"])
					{
						dataRow = ParameterHeader.NewRow();
						dataRow["header_Id"] = num;
						dataRow["source"] = dataColumn.ExtendedProperties["address"].ToString();
						dataRow["name"] = (string)dataColumn.ExtendedProperties["displayName"];
						dataRow["units"] = (string)dataColumn.ExtendedProperties["units"];
						ParameterHeader.Rows.Add(dataRow);
					}
				}
				ParameterHeader.AcceptChanges();
				Header.AcceptChanges();
				Session.AcceptChanges();
			}
		}

		public override void WriteData(DataTable values)
		{
			lock (this)
			{
				if (activeSessionID != -1)
				{
					foreach (DataRow row in values.Rows)
					{
						DataRow dataRow2 = LogData.NewRow();
						dataRow2["session_Id"] = activeSessionID;
						LogData.Rows.Add(dataRow2);
						int num = (int)dataRow2["data_Id"];
						DataRow dataRow3 = LogElement.NewRow();
						dataRow3["data_Id"] = num;
						dataRow3[0] = "";
						if ((bool)values.Columns["DLA Timestamp"].ExtendedProperties["Active"])
						{
							if (row["DLA Timestamp"] != DBNull.Value)
							{
								dataRow3[0] = FormatTime((uint)row["DLA Timestamp"]);
							}
							LogElement.Rows.Add(dataRow3);
						}
						for (int i = 2; i < values.Columns.Count; i++)
						{
							bool flag = (bool)values.Columns[i].ExtendedProperties["Active"];
							bool flag2 = (bool)values.Columns[i].ExtendedProperties["Removed"];
							if (flag)
							{
								dataRow3 = LogElement.NewRow();
								dataRow3["data_Id"] = num;
								if (row[i] != DBNull.Value)
								{
									dataRow3[0] = row[i].ToString();
								}
								else if (!flag2)
								{
									dataRow3[0] = "NaN";
								}
								else
								{
									dataRow3[0] = string.Empty;
								}
								LogElement.Rows.Add(dataRow3);
							}
						}
					}
					LogData.AcceptChanges();
					LogElement.AcceptChanges();
					return;
				}
				throw new InvalidOperationException("We got data without header");
			}
		}

		public override void WriteUCLData(DataTable values)
		{
			lock (this)
			{
				if (activeSessionID != -1)
				{
					foreach (DataRow row in values.Rows)
					{
						DataRow dataRow2 = LogData.NewRow();
						dataRow2["session_Id"] = activeSessionID;
						LogData.Rows.Add(dataRow2);
						int num = (int)dataRow2["data_Id"];
						DataRow dataRow3 = LogElement.NewRow();
						dataRow3["data_Id"] = num;
						dataRow3[0] = "";
						if ((bool)values.Columns["DLA Timestamp"].ExtendedProperties["Active"])
						{
							if (row["DLA Timestamp"] != DBNull.Value)
							{
								dataRow3[0] = FormatTime((uint)row["DLA Timestamp"]);
							}
							LogElement.Rows.Add(dataRow3);
						}
						for (int i = 2; i < values.Columns.Count; i++)
						{
							bool flag = (bool)values.Columns[i].ExtendedProperties["Active"];
							bool flag2 = (bool)values.Columns[i].ExtendedProperties["Removed"];
							if (flag)
							{
								dataRow3 = LogElement.NewRow();
								dataRow3["data_Id"] = num;
								if (row[i] != DBNull.Value)
								{
									dataRow3[0] = row[i].ToString();
								}
								else if (!flag2)
								{
									dataRow3[0] = "NaN";
								}
								else
								{
									dataRow3[0] = string.Empty;
								}
								LogElement.Rows.Add(dataRow3);
							}
						}
					}
					LogData.AcceptChanges();
					LogElement.AcceptChanges();
					return;
				}
				throw new InvalidOperationException("We got data without header");
			}
		}

		public override void Flush()
		{
			if (activeSessionID != -1)
			{
				logData.AcceptChanges();
				logData.WriteXml(tempFileName, XmlWriteMode.IgnoreSchema);
			}
		}

		public override void UCLFlush()
		{
			if (activeSessionID != -1)
			{
				logData.AcceptChanges();
				logData.WriteXml(tempFileName, XmlWriteMode.IgnoreSchema);
			}
		}

		public override void Close()
		{
			lock (this)
			{
				try
				{
					if (activeSessionID != -1)
					{
						logData.AcceptChanges();
						logData.WriteXml(tempFileName, XmlWriteMode.IgnoreSchema);
						logData.Clear();
					}
					activeSessionID = -1;
				}
				catch (Exception ex)
				{
					EventLogger.Error("Logging", ex.Message);
				}
			}
		}
	}
}
