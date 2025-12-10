#define TRACE
using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Diagnostics;
using System.Globalization;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text;
using System.Threading;
using CILMessage;
using Cummins.AddressRepresentation;
using Cummins.CUTY;
using Cummins.Calibration;
using Cummins.EventLog;
using Cummins.Interop.CalDataServer;
using Cummins.Interop.DataMonitoring;
using Cummins.Interop.Message;
using Cummins.Parameter;
using Cummins.ProductInformationProvider;
using Cummins.Services;
using PCLWrapper;

[assembly: AssemblyDelaySign(false)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyTitle("")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - Subscription")]
[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.Subscription;

internal abstract class Subscription
{
	private IAddressValue sourceAddress;

	private ArrayList duplicateParameterList;

	private NotifyType notificationType;

	private DataAcquisitionType dataAcquisitionMode = DataAcquisitionType.RequestReceive;

	private int rateMultiplier;

	private IDLStopType iDLStopMode = IDLStopType.Fill;

	private TriggerType triggerMode = TriggerType.Clock;

	protected int baseRate;

	protected bool validateParameter = true;

	protected int monitorTimeoutFactor;

	protected int monitorTimeoutFloor;

	protected bool monitorTimeoutEnabled;

	protected int idlBufferRetrievalRate;

	protected bool isActive;

	protected bool isStarted;

	protected bool disposed;

	protected StringDictionary parameterList;

	protected ICalibration calibration;

	public virtual StringDictionary ParameterList
	{
		get
		{
			if (parameterList == null)
			{
				parameterList = new StringDictionary();
			}
			return parameterList;
		}
	}

	public virtual int ParameterCount => ParameterList.Count;

	public virtual int ID => GetHashCode();

	public virtual int BaseRate
	{
		get
		{
			return baseRate;
		}
		set
		{
			baseRate = value;
		}
	}

	public virtual ICalibration DataSource => calibration;

	public virtual bool IsActive
	{
		get
		{
			return isActive;
		}
		set
		{
			isActive = value;
		}
	}

	public virtual bool IsStarted
	{
		get
		{
			return isStarted;
		}
		set
		{
			isStarted = value;
		}
	}

	public virtual int Count => 0;

	public virtual NotifyType NotificationType
	{
		get
		{
			return notificationType;
		}
		set
		{
			notificationType = value;
		}
	}

	public virtual DataAcquisitionType DataAcquisitionMode
	{
		get
		{
			return dataAcquisitionMode;
		}
		set
		{
			dataAcquisitionMode = value;
		}
	}

	public virtual IAddressValue SourceAddress
	{
		get
		{
			if (sourceAddress == null)
			{
				sourceAddress = DataSource.SourceAddress;
			}
			return sourceAddress;
		}
		set
		{
			sourceAddress = value;
		}
	}

	public virtual int RateMultiplier
	{
		get
		{
			return rateMultiplier;
		}
		set
		{
			rateMultiplier = value;
		}
	}

	public virtual IDLStopType IDLStopMode
	{
		get
		{
			return iDLStopMode;
		}
		set
		{
			iDLStopMode = value;
		}
	}

	public virtual TriggerType TriggerMode
	{
		get
		{
			return triggerMode;
		}
		set
		{
			triggerMode = value;
		}
	}

	public virtual bool ValidateParameter
	{
		get
		{
			return validateParameter;
		}
		set
		{
			validateParameter = value;
		}
	}

	public virtual int MonitorTimeoutFactor
	{
		get
		{
			return monitorTimeoutFactor;
		}
		set
		{
			monitorTimeoutFactor = value;
		}
	}

	public virtual int MonitorTimeoutFloor
	{
		get
		{
			return monitorTimeoutFloor;
		}
		set
		{
			monitorTimeoutFloor = value;
		}
	}

	public virtual bool MonitorTimeoutEnabled
	{
		get
		{
			return monitorTimeoutEnabled;
		}
		set
		{
			monitorTimeoutEnabled = value;
		}
	}

	public virtual ArrayList SubscriptionParameterList => null;

	public virtual int IDLBufferRetrievalRate
	{
		get
		{
			return idlBufferRetrievalRate;
		}
		set
		{
			idlBufferRetrievalRate = value;
		}
	}

	protected ArrayList DuplicateParameterList
	{
		get
		{
			if (duplicateParameterList == null)
			{
				duplicateParameterList = new ArrayList();
			}
			return duplicateParameterList;
		}
	}

	public event EventHandler Starting;

	public event EventHandler Started;

	public event EventHandler Stopping;

	public event EventHandler Stopped;

	public event EventHandler Pausing;

	public event EventHandler Paused;

	public event EventHandler Resuming;

	public event EventHandler Resumed;

	public event EventHandler LastParameterRemoved;

	private event IDLAutoTransferEventHandler iDLTransferInterrupt;

	private event EventHandler iDLBufferTransferStarted;

	private event EventHandler iDLBufferTransferCompleted;

	private event EventHandler iDLNotificationsStarted;

	private event EventHandler iDLNotificationsCompleted;

	private event EventHandler iDLBufferIsFull;

	private event IDLRetrievalRateEventHandler iDLRetrievalRateIsTooSlow;

	private event IDLRetrievalRateEventHandler iDLRetrievalRateIsTooFast;

	private event PerformanceEventHandler performanceStatistics;

	private event RunLocationChangeEventHandler runLocationChange;

	private event StopBroadCastEventHandler stopBroadCast;

	private event ConnectionLostEventHandler connectionLost;

	private event NotificationEventHandler notification;

	public virtual event NotificationEventHandler Notification
	{
		add
		{
			notification += value;
		}
		remove
		{
			notification -= value;
		}
	}

	public virtual event IDLAutoTransferEventHandler IDLTransferInterrupt
	{
		add
		{
			iDLTransferInterrupt += value;
		}
		remove
		{
			iDLTransferInterrupt -= value;
		}
	}

	public virtual event EventHandler IDLBufferTransferStarted
	{
		add
		{
			iDLBufferTransferStarted += value;
		}
		remove
		{
			iDLBufferTransferStarted -= value;
		}
	}

	public virtual event EventHandler IDLBufferTransferCompleted
	{
		add
		{
			iDLBufferTransferCompleted += value;
		}
		remove
		{
			iDLBufferTransferCompleted -= value;
		}
	}

	public virtual event EventHandler IDLNotificationsStarted
	{
		add
		{
			iDLNotificationsStarted += value;
		}
		remove
		{
			iDLNotificationsStarted -= value;
		}
	}

	public virtual event EventHandler IDLNotificationsCompleted
	{
		add
		{
			iDLNotificationsCompleted += value;
		}
		remove
		{
			iDLNotificationsCompleted -= value;
		}
	}

	public virtual event EventHandler IDLBufferIsFull
	{
		add
		{
			iDLBufferIsFull += value;
		}
		remove
		{
			iDLBufferIsFull -= value;
		}
	}

	public virtual event IDLRetrievalRateEventHandler IDLRetrievalRateIsTooSlow
	{
		add
		{
			iDLRetrievalRateIsTooSlow += value;
		}
		remove
		{
			iDLRetrievalRateIsTooSlow -= value;
		}
	}

	public virtual event IDLRetrievalRateEventHandler IDLRetrievalRateIsTooFast
	{
		add
		{
			iDLRetrievalRateIsTooFast += value;
		}
		remove
		{
			iDLRetrievalRateIsTooFast -= value;
		}
	}

	public virtual event PerformanceEventHandler PerformanceStatistics
	{
		add
		{
			performanceStatistics += value;
		}
		remove
		{
			performanceStatistics -= value;
		}
	}

	public virtual event RunLocationChangeEventHandler RunLocationChange
	{
		add
		{
			runLocationChange += value;
		}
		remove
		{
			runLocationChange -= value;
		}
	}

	public virtual event StopBroadCastEventHandler StopBroadCast
	{
		add
		{
			stopBroadCast += value;
		}
		remove
		{
			stopBroadCast -= value;
		}
	}

	public virtual event ConnectionLostEventHandler ConnectionLost
	{
		add
		{
			connectionLost += value;
		}
		remove
		{
			connectionLost -= value;
		}
	}

	public Subscription(ICalibration calibration)
	{
		this.calibration = calibration;
	}

	public virtual void Add(string parameterName)
	{
	}

	public virtual void Remove(string parameterName)
	{
	}

	public virtual void Add(uint address, int offset, uint length, IParameterModel parameterModel)
	{
	}

	public virtual void Remove(uint address, int offset, uint length)
	{
	}

	public virtual void RemoveAll()
	{
	}

	public virtual void Start()
	{
	}

	public virtual void Stop()
	{
	}

	public virtual void Pause()
	{
	}

	public virtual void Resume()
	{
	}

	public virtual void Dispose()
	{
	}

	public virtual bool SaveDC2Configuration()
	{
		return false;
	}

	protected virtual void RaiseStarting()
	{
		if (this.Starting != null)
		{
			this.Starting(this, EventArgs.Empty);
		}
	}

	protected virtual void RaiseStarted()
	{
		if (this.Started != null)
		{
			this.Started(this, EventArgs.Empty);
		}
	}

	protected virtual void RaiseStopping()
	{
		if (this.Stopping != null)
		{
			this.Stopping(this, EventArgs.Empty);
		}
	}

	protected virtual void RaiseStopped()
	{
		if (this.Stopped != null)
		{
			this.Stopped(this, EventArgs.Empty);
		}
	}

	protected virtual void RaisePausing()
	{
		if (this.Pausing != null)
		{
			this.Pausing(this, EventArgs.Empty);
		}
	}

	protected virtual void RaisePaused()
	{
		if (this.Paused != null)
		{
			this.Paused(this, EventArgs.Empty);
		}
	}

	protected virtual void RaiseResuming()
	{
		if (this.Resuming != null)
		{
			this.Resuming(this, EventArgs.Empty);
		}
	}

	protected virtual void RaiseResumed()
	{
		if (this.Resumed != null)
		{
			this.Resumed(this, EventArgs.Empty);
		}
	}

	protected virtual void RaiseLastParameterRemoved()
	{
		if (this.LastParameterRemoved != null)
		{
			this.LastParameterRemoved(this, EventArgs.Empty);
		}
	}
}
public interface ISubscription : IDisposable
{
	int ID { get; }

	int BaseRate { get; set; }

	ICalibration DataSource { get; }

	bool IsActive { get; }

	bool IsStarted { get; set; }

	int Count { get; }

	IAddressValue SourceAddress { get; set; }

	event EventHandler Starting;

	event EventHandler Started;

	event EventHandler Stopping;

	event EventHandler Stopped;

	event EventHandler Pausing;

	event EventHandler Paused;

	event EventHandler Resuming;

	event EventHandler Resumed;

	event EventHandler LastParameterRemoved;

	event NotificationEventHandler Notification;

	void Add(string parameterName);

	void Remove(string parameterName);

	void Remove(uint address, int offset, uint length);

	void RemoveAll();

	void Start();

	void Stop();
}
public interface IDataProvider
{
	int ID { get; }

	event NotificationEventHandler Notification;
}
public interface IAddressableSubscription : ISubscription, IDisposable
{
	void Add(uint address, int offset, uint length, IParameterModel parameterModel);
}
public interface IPausable
{
	void Pause();

	void Resume();
}
public interface IECMSubscription : IAddressableSubscription, ISubscription, IDisposable, IPausable
{
	NotifyType NotificationType { get; set; }

	DataAcquisitionType DataAcquisitionMode { get; set; }

	int RateMultiplier { get; set; }

	IDLStopType IDLStopMode { get; set; }

	TriggerType TriggerMode { get; set; }

	bool ValidateParameter { get; set; }

	int MonitorTimeoutFactor { get; set; }

	int MonitorTimeoutFloor { get; set; }

	bool MonitorTimeoutEnabled { get; set; }

	ArrayList SubscriptionParameterList { get; }

	int IDLBufferRetrievalRate { get; set; }

	event IDLAutoTransferEventHandler IDLTransferInterrupt;

	event EventHandler IDLBufferTransferStarted;

	event EventHandler IDLBufferTransferCompleted;

	event EventHandler IDLNotificationsStarted;

	event EventHandler IDLNotificationsCompleted;

	event EventHandler IDLBufferIsFull;

	event IDLRetrievalRateEventHandler IDLRetrievalRateIsTooSlow;

	event IDLRetrievalRateEventHandler IDLRetrievalRateIsTooFast;

	event PerformanceEventHandler PerformanceStatistics;

	event RunLocationChangeEventHandler RunLocationChange;

	event StopBroadCastEventHandler StopBroadCast;

	event ConnectionLostEventHandler ConnectionLost;

	bool SaveDC2Configuration();
}
internal class ASAMSubscription : Subscription, IDataProvider, IECMSubscription, IAddressableSubscription, ISubscription, IDisposable, IPausable
{
	private const string leadingParameterScope = "ConfigFile.";

	private ICalibrationASAM calibrationASAM;

	public override int BaseRate
	{
		get
		{
			return baseRate;
		}
		set
		{
			baseRate = value;
			calibrationASAM.ASAM3Monitor.MonitorRefreshRate = value;
		}
	}

	public override int Count => ParameterList.Count;

	private event NotificationEventHandler notification;

	public override event NotificationEventHandler Notification
	{
		add
		{
			notification += value;
		}
		remove
		{
			notification -= value;
		}
	}

	public ASAMSubscription(ICalibrationASAM calibrationASAM)
		: base(calibrationASAM)
	{
		this.calibrationASAM = calibrationASAM;
	}

	~ASAMSubscription()
	{
		Dispose();
	}

	public override void Dispose()
	{
		Dispose(Disposing: true);
		GC.SuppressFinalize(this);
	}

	public virtual void Dispose(bool Disposing)
	{
		if (!disposed)
		{
			disposed = true;
		}
	}

	public override void Add(string parameterName)
	{
		try
		{
			bool flag = false;
			StringBuilder stringBuilder = new StringBuilder();
			if (parameterName.IndexOf("ConfigFile.") < 0)
			{
				flag = parameterName.StartsWith("_");
				stringBuilder.Append("ConfigFile.");
			}
			else
			{
				flag = parameterName.StartsWith("ConfigFile._");
			}
			stringBuilder.Append(parameterName);
			if (!flag)
			{
				if (!ParameterList.ContainsKey(stringBuilder.ToString()))
				{
					ParameterList.Add(stringBuilder.ToString(), "");
					calibrationASAM.ASAM3Monitor.AddMonitorElement(parameterName.Substring(parameterName.IndexOf(".") + 1));
				}
				else
				{
					base.DuplicateParameterList.Add(stringBuilder.ToString());
				}
			}
		}
		catch (Exception e)
		{
			EventLogger.Error("ASAM Monitoring", "Error adding parameter", e);
		}
	}

	public override void Add(uint address, int offset, uint length, IParameterModel parameterModel)
	{
		string message = address.ToString("X8") + "_" + length + " cannot be monitored for file calibrations";
		EventLogger.Info("Subscription", message);
	}

	public override void Remove(string parameterName)
	{
		try
		{
			StringBuilder stringBuilder = new StringBuilder();
			if (parameterName.IndexOf("ConfigFile.") == -1)
			{
				stringBuilder.Append("ConfigFile.");
			}
			stringBuilder.Append(parameterName);
			if (!base.DuplicateParameterList.Contains(parameterName))
			{
				calibrationASAM.ASAM3Monitor.RemoveMonitorElement(parameterName.Substring(parameterName.IndexOf(".") + 1));
				if (ParameterList.ContainsKey(parameterName))
				{
					ParameterList.Remove(parameterName);
				}
			}
			else
			{
				base.DuplicateParameterList.Remove(parameterName);
			}
		}
		catch (Exception e)
		{
			EventLogger.Error("ASAM Monitoring", "Exception in ASAMSubscription Removing parameter", e);
		}
	}

	public override void RemoveAll()
	{
		try
		{
			calibrationASAM.ASAM3Monitor.RemoveAllMonitorElements();
			ParameterList.Clear();
			base.DuplicateParameterList.Clear();
		}
		catch (Exception e)
		{
			EventLogger.Error("ASAM Monitoring", "Error removing all the parameters", e);
		}
	}

	public override void Start()
	{
		try
		{
			if (!IsStarted)
			{
				calibrationASAM.ASAM3Client.MonitorDataRefresh += OnMonitorDataUpdate;
				calibrationASAM.ASAM3Monitor.StartMonitor(MonitorMode.MonitorModeRequestReceive);
				IsStarted = true;
				IsActive = true;
			}
		}
		catch (Exception ex)
		{
			EventLogger.Error("ASAM Monitoring", ex.Message, ex);
			calibrationASAM.ASAM3Client.MonitorDataRefresh -= OnMonitorDataUpdate;
		}
	}

	public override void Stop()
	{
		try
		{
			if (IsStarted)
			{
				try
				{
					calibrationASAM.ASAM3Monitor.StopMonitor();
				}
				catch
				{
				}
				calibrationASAM.ASAM3Client.MonitorDataRefresh -= OnMonitorDataUpdate;
				IsStarted = false;
				IsActive = false;
			}
		}
		catch (Exception ex)
		{
			EventLogger.Error("ASAM Monitoring", ex.Message, ex);
		}
		finally
		{
			RaiseStopped();
		}
	}

	public override void Pause()
	{
		Stop();
	}

	public override void Resume()
	{
		Start();
	}

	private void OnMonitorDataUpdate(ICINotification cutyNotification)
	{
		if (cutyNotification != null && cutyNotification.Count != 0)
		{
			ASAMDataRefreshEventArgs e = new ASAMDataRefreshEventArgs();
			e.SourceAddress = SourceAddress;
			e.SubscriptionHashCode = GetHashCode();
			e.ASAMData = cutyNotification;
			e.ParameterCount = Count;
			this.notification(this, e);
		}
	}
}
public class ConnectionEventArgs : EventArgs
{
	private IAddressValue deviceAddress;

	public IAddressValue DeviceAddress
	{
		get
		{
			return deviceAddress;
		}
		set
		{
			deviceAddress = value;
		}
	}
}
public interface IDataCollectorInfo
{
	DataCollectorStatus DataCollectorStatus { get; }

	DataCollectorType DataCollectorType { get; }

	DataAcquisitionType MonitorMode { get; }

	TriggerType TriggerMode { get; }

	IDLStopType IDLStopMode { get; }

	int ClockBaseRate { get; }

	int FrameBaseRate { get; }
}
public class DataCollectorInfo : IDataCollectorInfo
{
	private ICIDataCollectorInfo dcInfo;

	private int clockBaseRate = -1;

	private int frameBaseRate = -1;

	public DataCollectorStatus DataCollectorStatus
	{
		get
		{
			DataCollectorStatus result = DataCollectorStatus.Off;
			try
			{
				if (dcInfo.DataCollectorType != tagCIDataCollectorTypeEnum.NONE)
				{
					result = (DataCollectorStatus)dcInfo.Status;
				}
			}
			catch (Exception inner)
			{
				throw new DataRetrievalException(2, ExceptionMessage.GetMessage(SubscriptionMessageIDs.RetrieveDCStatusError), inner);
			}
			return result;
		}
	}

	public DataCollectorType DataCollectorType
	{
		get
		{
			DataCollectorType dataCollectorType = DataCollectorType.None;
			try
			{
				return (DataCollectorType)dcInfo.DataCollectorType;
			}
			catch (Exception inner)
			{
				throw new DataRetrievalException(3, ExceptionMessage.GetMessage(SubscriptionMessageIDs.RetrieveDCTypeError), inner);
			}
		}
	}

	public DataAcquisitionType MonitorMode
	{
		get
		{
			DataAcquisitionType dataAcquisitionType = DataAcquisitionType.RequestReceive;
			try
			{
				return (DataAcquisitionType)dcInfo.MonitorMode;
			}
			catch (Exception inner)
			{
				throw new DataRetrievalException(4, ExceptionMessage.GetMessage(SubscriptionMessageIDs.RetrieveDCMonitorModeError), inner);
			}
		}
	}

	public TriggerType TriggerMode
	{
		get
		{
			TriggerType triggerType = TriggerType.Clock;
			try
			{
				return (TriggerType)dcInfo.TriggerMode;
			}
			catch (Exception inner)
			{
				throw new DataRetrievalException(5, ExceptionMessage.GetMessage(SubscriptionMessageIDs.RetrieveDCTriggerTypeError), inner);
			}
		}
	}

	public IDLStopType IDLStopMode
	{
		get
		{
			IDLStopType iDLStopType = IDLStopType.Stop;
			try
			{
				return (IDLStopType)dcInfo.IDLStopMode;
			}
			catch (Exception inner)
			{
				throw new DataRetrievalException(6, ExceptionMessage.GetMessage(SubscriptionMessageIDs.RetrieveDCIDLStopModeError), inner);
			}
		}
	}

	public int ClockBaseRate
	{
		get
		{
			if (clockBaseRate == -1)
			{
				GetDCCapabilities();
			}
			return clockBaseRate;
		}
	}

	public int FrameBaseRate
	{
		get
		{
			if (frameBaseRate == -1)
			{
				GetDCCapabilities();
			}
			return frameBaseRate;
		}
	}

	public DataCollectorInfo(ICalibrationDataServer calDataServer)
	{
		dcInfo = new CIDataCollectorInfoClass();
		if (calDataServer != null && calDataServer.DataServer != null)
		{
			try
			{
				dcInfo.DataSource = (Cummins.Interop.DataMonitoring.ICICalDataServer)calDataServer.DataServer;
				return;
			}
			catch (Exception inner)
			{
				throw new SetDataServerException(1, ExceptionMessage.GetMessage(SubscriptionMessageIDs.SetDataServerError), inner);
			}
		}
		throw new ArgumentNullException(ExceptionMessage.GetMessage(SubscriptionMessageIDs.NullCalDataServer));
	}

	private void GetDCCapabilities()
	{
		try
		{
			string text = null;
			if (DataCollectorType == DataCollectorType.DataCollector1)
			{
				text = "ConfigFile.Data Collector.Operations.getDcCapabilities";
			}
			else if (DataCollectorType == DataCollectorType.DataCollector2)
			{
				text = "ConfigFile.Data Collector2.Operations.getDc2Capabilities";
			}
			if (text != null)
			{
				ICICalOperationEntity iCICalOperationEntity = (ICICalOperationEntity)dcInfo.DataSource.GetEntityByName(null, text);
				object[] inputEntities = null;
				int responseCode = 0;
				object outputEntities = null;
				iCICalOperationEntity.Process(inputEntities, out outputEntities, out responseCode);
				ICICalValueEntity iCICalValueEntity = (ICICalValueEntity)((object[])outputEntities)[2];
				ICICalValueEntity iCICalValueEntity2 = (ICICalValueEntity)((object[])outputEntities)[3];
				frameBaseRate = (int)iCICalValueEntity.ScaledFloat;
				clockBaseRate = (int)iCICalValueEntity2.ScaledFloat;
			}
		}
		catch (Exception)
		{
		}
	}
}
public abstract class DataRefreshEventArgs : EventArgs
{
	private int subscriptionHashCode;

	private int parameterCount;

	private IAddressValue sourceAddress;

	private bool isProcessed;

	public virtual DataSourceTypeEnum DataSourceType => DataSourceTypeEnum.Unknown;

	public int SubscriptionHashCode
	{
		get
		{
			return subscriptionHashCode;
		}
		set
		{
			subscriptionHashCode = value;
		}
	}

	public int ParameterCount
	{
		get
		{
			return parameterCount;
		}
		set
		{
			parameterCount = value;
		}
	}

	public IAddressValue SourceAddress
	{
		get
		{
			return sourceAddress;
		}
		set
		{
			sourceAddress = value;
		}
	}

	public bool IsProcessed
	{
		get
		{
			return isProcessed;
		}
		set
		{
			isProcessed = value;
		}
	}
}
public class ECMDataRefreshEventArgs : DataRefreshEventArgs
{
	private ArrayList parameterValues;

	public ArrayList ECMData
	{
		get
		{
			return parameterValues;
		}
		set
		{
			parameterValues = value;
		}
	}

	public override DataSourceTypeEnum DataSourceType => DataSourceTypeEnum.ECM;
}
public class ASAMDataRefreshEventArgs : DataRefreshEventArgs
{
	private ICINotification parameterValues;

	public ICINotification ASAMData
	{
		get
		{
			return parameterValues;
		}
		set
		{
			parameterValues = value;
		}
	}

	public override DataSourceTypeEnum DataSourceType => DataSourceTypeEnum.ASAM;
}
public class DiskDataRefreshEventArgs : DataRefreshEventArgs
{
	private SortedList parameterValues;

	public override DataSourceTypeEnum DataSourceType => DataSourceTypeEnum.Disk;

	public SortedList DiskData
	{
		get
		{
			return parameterValues;
		}
		set
		{
			parameterValues = value;
		}
	}
}
public class J1939_71DataRefreshEventArgs : DataRefreshEventArgs
{
	private List<PGNList> parameterValues;

	private List<SPN> _indexedList;

	public List<PGNList> J1939_71Data
	{
		get
		{
			return parameterValues;
		}
		set
		{
			parameterValues = value;
		}
	}

	public override DataSourceTypeEnum DataSourceType => DataSourceTypeEnum.J1939_71;

	public SPN this[int index]
	{
		get
		{
			if (_indexedList == null)
			{
				_indexedList = BuildIndexedList();
			}
			return _indexedList[index];
		}
	}

	private List<SPN> BuildIndexedList()
	{
		List<SPN> list = new List<SPN>();
		foreach (PGNList parameterValue in parameterValues)
		{
			foreach (PGN pGN in parameterValue.PGNs)
			{
				foreach (SPN sPN in pGN.SPNs)
				{
					list.Add(sPN);
				}
			}
		}
		return list;
	}
}
public interface IDiskSubscription : IAddressableSubscription, ISubscription, IDisposable, IPausable
{
}
internal class DiskSubscription : Subscription, IDiskSubscription, IAddressableSubscription, ISubscription, IDisposable, IPausable, IDataProvider
{
	private Timer dataRefreshTimer;

	private SortedList parameterModelList;

	public override int Count => ParameterList.Count;

	private SortedList ParameterModelList
	{
		get
		{
			if (parameterModelList == null)
			{
				parameterModelList = new SortedList();
			}
			return parameterModelList;
		}
	}

	private event NotificationEventHandler notification;

	public override event NotificationEventHandler Notification
	{
		add
		{
			notification += value;
		}
		remove
		{
			notification -= value;
		}
	}

	public DiskSubscription(ICalibration calibration)
		: base(calibration)
	{
		dataRefreshTimer = new Timer(OnDataRefresh, null, -1, -1);
	}

	~DiskSubscription()
	{
		Dispose();
	}

	public override void Dispose()
	{
		Dispose(disposing: true);
		GC.SuppressFinalize(this);
	}

	protected virtual void Dispose(bool disposing)
	{
		if (!disposed)
		{
			ParameterList.Clear();
			ParameterModelList.Clear();
			dataRefreshTimer.Dispose();
		}
		disposed = true;
	}

	private void OnDataRefresh(object source)
	{
		SortedList diskData = null;
		lock (ParameterModelList)
		{
			diskData = (SortedList)ParameterModelList.Clone();
		}
		RaiseDataRefreshEvent(diskData);
	}

	private void RaiseDataRefreshEvent(SortedList diskData)
	{
		if (this.notification != null)
		{
			DiskDataRefreshEventArgs e = new DiskDataRefreshEventArgs();
			e.SourceAddress = SourceAddress;
			e.SubscriptionHashCode = GetHashCode();
			e.DiskData = diskData;
			e.ParameterCount = ParameterCount;
			this.notification(this, e);
		}
	}

	public override void Add(string parameterName)
	{
		IParameterModel parameterModel = null;
		lock (DataSource)
		{
			parameterModel = DataSource.Get(parameterName);
		}
		if (parameterModel == null)
		{
			return;
		}
		if (parameterModel.AvailableOffline)
		{
			lock (ParameterModelList)
			{
				(parameterModel as IEntityModel).CacheMode = Cummins.Interop.CalDataServer.tagCICacheMode.dataVolatile;
				string fullName = parameterModel.FullName;
				if (!ParameterList.ContainsKey(fullName))
				{
					ParameterList.Add(fullName, "");
					ParameterModelList.Add(fullName, parameterModel);
				}
				else
				{
					base.DuplicateParameterList.Add(fullName);
				}
				return;
			}
		}
		throw new ParameterNotSupportedException(7, parameterModel.Name + "  is not a available offline");
	}

	public override void Add(uint address, int offset, uint length, IParameterModel parameterModel)
	{
		IParameterModel parameterModel2 = null;
		lock (DataSource)
		{
			parameterModel2 = DataSource.FuzzyGet(parameterModel.Name);
		}
		if (parameterModel2 == null)
		{
			return;
		}
		lock (ParameterModelList)
		{
			string fullName = parameterModel2.FullName;
			if (!ParameterList.ContainsKey(fullName))
			{
				ParameterList.Add(fullName, "");
				ParameterModelList.Add(fullName, parameterModel2);
			}
			else
			{
				base.DuplicateParameterList.Add(fullName);
			}
		}
	}

	public override void Remove(string parameterName)
	{
		lock (ParameterModelList)
		{
			if (!base.DuplicateParameterList.Contains(parameterName))
			{
				ParameterList.Remove(parameterName);
				ParameterModelList.Remove(parameterName);
			}
			else
			{
				base.DuplicateParameterList.Remove(parameterName);
			}
		}
	}

	public override void RemoveAll()
	{
		lock (ParameterModelList)
		{
			ParameterList.Clear();
			ParameterModelList.Clear();
		}
	}

	public override void Start()
	{
		if (!IsStarted)
		{
			lock (ParameterModelList)
			{
				RaiseStarting();
				dataRefreshTimer.Change(BaseRate, BaseRate);
				RaiseStarted();
				IsActive = true;
				IsStarted = true;
				return;
			}
		}
		Resume();
	}

	public override void Stop()
	{
		if (IsStarted)
		{
			lock (ParameterModelList)
			{
				RaiseStopping();
				dataRefreshTimer.Change(-1, -1);
				RaiseStopped();
				IsActive = false;
				IsStarted = false;
			}
		}
	}

	public override void Pause()
	{
		if (IsActive)
		{
			lock (ParameterModelList)
			{
				RaisePausing();
				dataRefreshTimer.Change(-1, -1);
				RaisePaused();
				IsActive = false;
			}
		}
	}

	public override void Resume()
	{
		if (!IsStarted)
		{
			Start();
		}
		else if (!IsActive)
		{
			lock (ParameterModelList)
			{
				RaiseResuming();
				dataRefreshTimer.Change(BaseRate, BaseRate);
				RaiseResumed();
				IsActive = true;
				IsStarted = true;
			}
		}
	}
}
public class SubscriptionRateHelper
{
	public static int GetBaseRate(IECMSubscription subscription, TriggerType trigger)
	{
		int result = 1;
		if (subscription != null || subscription.DataSource != null)
		{
			switch (trigger)
			{
			case TriggerType.Clock:
				result = new DataCollectorInfo(subscription.DataSource.CalibrationDataServer).ClockBaseRate;
				break;
			case TriggerType.Frame:
				result = new DataCollectorInfo(subscription.DataSource.CalibrationDataServer).FrameBaseRate;
				break;
			case TriggerType.ForeGroundActivated:
			case TriggerType.Timer:
				if (subscription.DataSource is ICalibrationECM calibrationECM)
				{
					result = GetBaseRate(calibrationECM.ProductID, calibrationECM.DeviceInfo.Phase);
				}
				break;
			}
			return result;
		}
		throw new ArgumentNullException();
	}

	public static int GetMaxBaseRate(SortedList subscriptionsList, TriggerType trigger)
	{
		int num = 1;
		if (subscriptionsList != null)
		{
			foreach (ECMSubscription value in subscriptionsList.Values)
			{
				if (value != null || value.DataSource != null)
				{
					int baseRate = GetBaseRate(value, trigger);
					if (baseRate > num)
					{
						num = baseRate;
					}
				}
			}
			return num;
		}
		throw new ArgumentNullException();
	}

	private static int GetBaseRate(string productId, string phase)
	{
		int result = 20;
		if (productId != null && productId.Length != 0)
		{
			try
			{
				ICIProductMaster iCIProductMaster = new ProductData();
				ICIProductDetail iCIProductDetail = iCIProductMaster[productId];
				result = iCIProductDetail.GetDataCollectorBaseRate(phase);
			}
			catch (Exception)
			{
			}
		}
		return result;
	}
}
internal class ECMSubscription : Subscription, IECMSubscription, IAddressableSubscription, ISubscription, IDisposable, IPausable, IDataProvider
{
	private enum MDASMessageId
	{
		DatalinkDropConnection = 11,
		RunFromDevelopment = 14,
		StopBroadCast = 15,
		IDLTransferInterrupt = 17,
		Notification = 101,
		CollectorStatus = 102,
		IDLBufferTransferStarted = 103,
		IDLBufferTransferCompleted = 104,
		IDLNotificationsStarted = 105,
		IDLNotificationsCompleted = 106,
		IDLBufferIsFull = 22,
		IDLRetrievalRateIsTooSlow = 24,
		IDLRetrievalRateIsTooFast = 25,
		DataCollectorNotStopping = 301
	}

	private enum IDLRetrievalRateMsgParameter
	{
		RequestedRate = 1,
		ActualRate
	}

	private class ValueConverter
	{
		public ICICalValueEntity Converter;

		public int Count;

		public string ScaledValue;
	}

	private const int DataMonitorOriginatorID = 17;

	private const string leadingParameterScope = ".";

	private const int SamplesToDiscard = 5;

	private const int RollingAverageSampleSize = 10;

	private const int MonitorTimeoutFloorDefault = 300;

	private Cummins.Interop.Message.MsgManager msgManager;

	private Hashtable arrayValueConverters = new Hashtable();

	private static CISubscriptionManager mdasSubcriptionManager;

	private IDataCollectorInfo dcInfo;

	private CISubscription mdasSubscription;

	private ICalibrationECM calibrationECM;

	private NotifyType notificationType;

	private static int runningGroupId = 0;

	private int messageGroupId;

	private int numberOfSamples;

	private int lastRefreshTime;

	private Queue rollingAverageRate;

	private bool latchedUpdateTimeout;

	public override ArrayList SubscriptionParameterList
	{
		get
		{
			ArrayList arrayList = new ArrayList();
			foreach (CICPPMonitor monitoredDataElement in MDASSubscription.MonitoredDataElements)
			{
				MonitoredElement monitoredElement = new MonitoredElement
				{
					length = monitoredDataElement.Length,
					mode = (AccessMode)monitoredDataElement.mode,
					location = monitoredDataElement.location,
					offset = monitoredDataElement.offset
				};
				if (monitoredElement.mode == AccessMode.ParameterId)
				{
					try
					{
						Cummins.Interop.CalDataServer.ICICalEntity entityByID = calibrationECM.CalibrationDataServer.DataServer.GetEntityByID(null, (int)monitoredDataElement.location);
						monitoredElement.mode = AccessMode.Name;
						monitoredElement.location = entityByID.FullName;
					}
					catch (Exception)
					{
					}
				}
				arrayList.Add(monitoredElement);
			}
			return arrayList;
		}
	}

	public override int RateMultiplier
	{
		get
		{
			return MDASDataCollectorSubscription.RateMultiplier;
		}
		set
		{
			bool flag = IsStarted;
			if (RateMultiplier == value)
			{
				return;
			}
			try
			{
				if (flag)
				{
					Stop();
				}
				MDASDataCollectorSubscription.RateMultiplier = value;
			}
			catch (Exception)
			{
			}
			finally
			{
				if (flag)
				{
					Start();
				}
			}
		}
	}

	public override int IDLBufferRetrievalRate
	{
		get
		{
			return idlBufferRetrievalRate;
		}
		set
		{
			if (idlBufferRetrievalRate != value)
			{
				idlBufferRetrievalRate = value;
				SetConfigurationXML(0);
			}
		}
	}

	public override IDLStopType IDLStopMode
	{
		get
		{
			return (IDLStopType)MDASDataCollectorSubscription.IDLStopMode;
		}
		set
		{
			bool flag = IsStarted;
			if (IDLStopMode == value)
			{
				return;
			}
			try
			{
				if (flag)
				{
					Stop();
				}
				MDASDataCollectorSubscription.IDLStopMode = (CIDMIDLStopMode)value;
			}
			catch (Exception)
			{
			}
			finally
			{
				if (flag)
				{
					Start();
				}
			}
		}
	}

	public override TriggerType TriggerMode
	{
		get
		{
			return (TriggerType)MDASDataCollectorSubscription.TriggerMode;
		}
		set
		{
			bool flag = IsStarted;
			if (TriggerMode == value)
			{
				return;
			}
			try
			{
				if (flag)
				{
					Stop();
				}
				MDASDataCollectorSubscription.TriggerMode = (tagCIDMTriggerMode)value;
			}
			catch (Exception)
			{
			}
			finally
			{
				if (flag)
				{
					Start();
				}
			}
		}
	}

	public override bool ValidateParameter
	{
		get
		{
			return validateParameter;
		}
		set
		{
			if (value != validateParameter)
			{
				validateParameter = value;
				if (MonitorTimeoutEnabled)
				{
					SetConfigurationXML(Math.Max(MonitorTimeoutFloor, (int)RollingAveragePerformance * MonitorTimeoutFactor));
				}
				else
				{
					SetConfigurationXML(0);
				}
			}
		}
	}

	public override int MonitorTimeoutFactor
	{
		get
		{
			return monitorTimeoutFactor;
		}
		set
		{
			if (monitorTimeoutFactor != value)
			{
				monitorTimeoutFactor = value;
				latchedUpdateTimeout = false;
			}
		}
	}

	public override int MonitorTimeoutFloor
	{
		get
		{
			return monitorTimeoutFloor;
		}
		set
		{
			if (monitorTimeoutFloor != value)
			{
				monitorTimeoutFloor = value;
				latchedUpdateTimeout = false;
			}
		}
	}

	public override bool MonitorTimeoutEnabled
	{
		get
		{
			return monitorTimeoutEnabled;
		}
		set
		{
			if (monitorTimeoutEnabled != value)
			{
				monitorTimeoutEnabled = value;
				if (!monitorTimeoutEnabled)
				{
					SetConfigurationXML(0);
				}
			}
		}
	}

	public override int BaseRate
	{
		get
		{
			return MDASSubscription.BaseRate;
		}
		set
		{
			if (value == MDASSubscription.BaseRate)
			{
				return;
			}
			bool flag = IsStarted;
			try
			{
				if (flag)
				{
					Stop();
				}
				MDASSubscription.BaseRate = value;
			}
			catch (Exception)
			{
			}
			finally
			{
				if (flag)
				{
					Start();
				}
			}
		}
	}

	public override int Count => MDASSubscription.MonitoredDataElements.Count;

	public override NotifyType NotificationType
	{
		get
		{
			return notificationType;
		}
		set
		{
			notificationType = value;
		}
	}

	public override DataAcquisitionType DataAcquisitionMode
	{
		get
		{
			return (DataAcquisitionType)MDASDataCollectorSubscription.MonitorMode;
		}
		set
		{
			bool flag = IsStarted;
			if (DataAcquisitionMode == value)
			{
				return;
			}
			if (flag)
			{
				Stop();
			}
			try
			{
				CISubscription cISubscription = new CISubscriptionClass();
				cISubscription.BaseRate = MDASSubscription.BaseRate;
				cISubscription.NotificationType = MDASSubscription.NotificationType;
				cISubscription.NotifyOnChange = MDASSubscription.NotifyOnChange;
				if (MDASSubscription.DataSource != null)
				{
					cISubscription.DataSource = MDASSubscription.DataSource;
				}
				ICIDataCollectorSubscription iCIDataCollectorSubscription = (ICIDataCollectorSubscription)cISubscription;
				iCIDataCollectorSubscription.IDLStopMode = MDASDataCollectorSubscription.IDLStopMode;
				iCIDataCollectorSubscription.RateMultiplier = MDASDataCollectorSubscription.RateMultiplier;
				iCIDataCollectorSubscription.TriggerMode = MDASDataCollectorSubscription.TriggerMode;
				CopyElementsTo(cISubscription);
				mdasSubscription = null;
				mdasSubscription = cISubscription;
				((Cummins.Interop.DataMonitoring.ICIAssignMsgGroup)MDASSubscription).Group = MessageGroupId;
				MDASDataCollectorSubscription.MonitorMode = (tagCIDMMonitorMode)value;
			}
			catch (Exception ex)
			{
				throw ex;
			}
			finally
			{
				if (flag)
				{
					Start();
				}
			}
		}
	}

	private Cummins.Interop.CalDataServer.ICICalDataServer CalDataServer => calibrationECM.CalibrationDataServer.DataServer;

	private DataCollectorType DataCollectorType
	{
		get
		{
			DataCollectorType result = DataCollectorType.None;
			try
			{
				result = dcInfo.DataCollectorType;
			}
			catch
			{
			}
			return result;
		}
	}

	private DataCollectorStatus DataCollectorStatus
	{
		get
		{
			DataCollectorStatus result = DataCollectorStatus.Off;
			try
			{
				result = dcInfo.DataCollectorStatus;
			}
			catch
			{
			}
			return result;
		}
	}

	private Cummins.Interop.Message.MsgManager MsgManager
	{
		get
		{
			if (msgManager == null)
			{
				msgManager = (Cummins.Interop.Message.MsgManager)new CILMessage.MsgManagerClass();
			}
			return msgManager;
		}
	}

	private CISubscription MDASSubscription
	{
		get
		{
			if (mdasSubscription == null)
			{
				mdasSubscription = new CISubscriptionClass();
				mdasSubscription.NotifyOnChange = false;
			}
			return mdasSubscription;
		}
		set
		{
			if (value == null)
			{
				return;
			}
			value.NotifyOnChange = false;
			((Cummins.Interop.DataMonitoring.ICIAssignMsgGroup)value).Group = MessageGroupId;
			if (NotificationType == NotifyType.Event)
			{
				value.NotificationType = tagCIDMNotifyTypesEnum.DM_NOTIFY_EVENT;
				if (mdasSubscription != null)
				{
					MDASSubscription.DataUpdate -= OnDataRefreshViaEvents;
				}
				value.DataUpdate += OnDataRefreshViaEvents;
			}
			else
			{
				value.NotificationType = tagCIDMNotifyTypesEnum.DM_NOTIFY_MESSAGE;
			}
			mdasSubscription = value;
		}
	}

	private ICIDataCollectorSubscription MDASDataCollectorSubscription => (ICIDataCollectorSubscription)MDASSubscription;

	private static ICISubscriptionManager2 MDASSubscriptionManager
	{
		get
		{
			if (mdasSubcriptionManager == null)
			{
				mdasSubcriptionManager = new CISubscriptionManagerClass();
				mdasSubcriptionManager.PerformanceMsgEnabled = true;
			}
			return (ICISubscriptionManager2)mdasSubcriptionManager;
		}
	}

	private int MessageGroupId
	{
		get
		{
			return messageGroupId;
		}
		set
		{
			messageGroupId = value;
		}
	}

	public double RollingAveragePerformance
	{
		get
		{
			double result = 0.0;
			lock (rollingAverageRate)
			{
				int num = 0;
				foreach (int item in rollingAverageRate)
				{
					num += item;
				}
				if (rollingAverageRate.Count > 0)
				{
					result = num / rollingAverageRate.Count;
				}
			}
			return result;
		}
	}

	private event NotificationEventHandler notification;

	private event IDLAutoTransferEventHandler iDLTransferInterrupt;

	private event EventHandler iDLBufferTransferStarted;

	private event EventHandler iDLBufferTransferCompleted;

	private event EventHandler iDLNotificationsStarted;

	private event EventHandler iDLNotificationsCompleted;

	private event EventHandler iDLBufferIsFull;

	private event IDLRetrievalRateEventHandler iDLRetrievalRateIsTooSlow;

	private event IDLRetrievalRateEventHandler iDLRetrievalRateIsTooFast;

	private event PerformanceEventHandler performanceStatistics;

	private event RunLocationChangeEventHandler runLocationChange;

	private event StopBroadCastEventHandler stopBroadCast;

	private event ConnectionLostEventHandler connectionLost;

	public override event NotificationEventHandler Notification
	{
		add
		{
			notification += value;
		}
		remove
		{
			notification -= value;
		}
	}

	public override event IDLAutoTransferEventHandler IDLTransferInterrupt
	{
		add
		{
			iDLTransferInterrupt += value;
		}
		remove
		{
			iDLTransferInterrupt -= value;
		}
	}

	public override event EventHandler IDLBufferTransferStarted
	{
		add
		{
			iDLBufferTransferStarted += value;
		}
		remove
		{
			iDLBufferTransferStarted -= value;
		}
	}

	public override event EventHandler IDLBufferTransferCompleted
	{
		add
		{
			iDLBufferTransferCompleted += value;
		}
		remove
		{
			iDLBufferTransferCompleted -= value;
		}
	}

	public override event EventHandler IDLNotificationsStarted
	{
		add
		{
			iDLNotificationsStarted += value;
		}
		remove
		{
			iDLNotificationsStarted -= value;
		}
	}

	public override event EventHandler IDLNotificationsCompleted
	{
		add
		{
			iDLNotificationsCompleted += value;
		}
		remove
		{
			iDLNotificationsCompleted -= value;
		}
	}

	public override event EventHandler IDLBufferIsFull
	{
		add
		{
			iDLBufferIsFull += value;
		}
		remove
		{
			iDLBufferIsFull -= value;
		}
	}

	public override event IDLRetrievalRateEventHandler IDLRetrievalRateIsTooSlow
	{
		add
		{
			iDLRetrievalRateIsTooSlow += value;
		}
		remove
		{
			iDLRetrievalRateIsTooSlow -= value;
		}
	}

	public override event IDLRetrievalRateEventHandler IDLRetrievalRateIsTooFast
	{
		add
		{
			iDLRetrievalRateIsTooFast += value;
		}
		remove
		{
			iDLRetrievalRateIsTooFast -= value;
		}
	}

	public override event PerformanceEventHandler PerformanceStatistics
	{
		add
		{
			performanceStatistics += value;
		}
		remove
		{
			performanceStatistics -= value;
		}
	}

	public override event RunLocationChangeEventHandler RunLocationChange
	{
		add
		{
			runLocationChange += value;
		}
		remove
		{
			runLocationChange -= value;
		}
	}

	public override event StopBroadCastEventHandler StopBroadCast
	{
		add
		{
			stopBroadCast += value;
		}
		remove
		{
			stopBroadCast -= value;
		}
	}

	public override event ConnectionLostEventHandler ConnectionLost
	{
		add
		{
			connectionLost += value;
		}
		remove
		{
			connectionLost -= value;
		}
	}

	public ECMSubscription(NotifyType notificationType, DataAcquisitionType mode, ICalibrationECM dataSource)
		: base(dataSource)
	{
		MessageGroupId = runningGroupId++;
		NotificationType = notificationType;
		calibrationECM = dataSource;
		if (MDASSubscription.DataSource == null)
		{
			MDASSubscription.DataSource = (Cummins.Interop.DataMonitoring.ICICalDataServer)dataSource.CalibrationDataServer.DataServer;
		}
		Cummins.Interop.DataMonitoring.ICICalDataServer dataSource2 = (Cummins.Interop.DataMonitoring.ICICalDataServer)calibrationECM.CalibrationDataServer.DataServer;
		dcInfo = new DataCollectorInfo(calibrationECM.CalibrationDataServer);
		CISubscription cISubscription = null;
		try
		{
			if (mode == DataAcquisitionType.IDL && (dcInfo.DataCollectorStatus == DataCollectorStatus.On || dcInfo.IDLStopMode == IDLStopType.KeyOn))
			{
				cISubscription = MDASSubscriptionManager.RetrieveDC2Configuration(dataSource2);
			}
		}
		catch (Exception)
		{
		}
		if (cISubscription != null)
		{
			mdasSubscription = cISubscription;
		}
		else
		{
			DataAcquisitionMode = mode;
		}
		Initialize();
	}

	public override void Dispose()
	{
		Dispose(disposing: true);
		GC.SuppressFinalize(this);
	}

	protected virtual void Dispose(bool disposing)
	{
		if (!disposed)
		{
			try
			{
				if (DataSource != null)
				{
					Stop();
				}
			}
			catch
			{
			}
			try
			{
				if (NotificationType == NotifyType.Event)
				{
					MDASSubscription.DataUpdate -= OnDataRefreshViaEvents;
				}
			}
			catch
			{
			}
			try
			{
				MsgManager.ReceiveMessage -= OnReceiveMessage;
				MsgManager.AssignFilters -= OnAssignFilters;
			}
			catch
			{
			}
			try
			{
				if (mdasSubscription != null)
				{
					while (Marshal.ReleaseComObject(mdasSubscription) > 0)
					{
					}
					mdasSubscription = null;
				}
			}
			catch (Exception)
			{
			}
		}
		disposed = true;
	}

	~ECMSubscription()
	{
		Dispose();
	}

	private void Initialize()
	{
		IsActive = false;
		IsStarted = false;
		numberOfSamples = 0;
		latchedUpdateTimeout = false;
		monitorTimeoutEnabled = false;
		MonitorTimeoutFloor = 300;
		((Cummins.Interop.DataMonitoring.ICIAssignMsgGroup)MDASSubscription).Group = MessageGroupId;
		if (NotificationType == NotifyType.Event)
		{
			MDASSubscription.NotificationType = tagCIDMNotifyTypesEnum.DM_NOTIFY_EVENT;
			MDASSubscription.DataUpdate += OnDataRefreshViaEvents;
		}
		else
		{
			MDASSubscription.NotificationType = tagCIDMNotifyTypesEnum.DM_NOTIFY_MESSAGE;
		}
		MsgManager.ReceiveMessage += OnReceiveMessage;
		MsgManager.AssignFilters += OnAssignFilters;
		if (DataCollectorStatus != DataCollectorStatus.On)
		{
			MDASDataCollectorSubscription.RateMultiplier = 5;
		}
		switch (DataAcquisitionMode)
		{
		case DataAcquisitionType.BAM:
			MDASDataCollectorSubscription.TriggerMode = tagCIDMTriggerMode.DM_IS_CLOCK;
			break;
		}
		rollingAverageRate = new Queue(10);
		lastRefreshTime = 0;
		MonitorTimeoutFactor = 2;
		SetConfigurationXML(0);
	}

	public override bool SaveDC2Configuration()
	{
		bool result = false;
		try
		{
			MDASSubscriptionManager.SaveDC2Configuration(MDASSubscription);
			result = true;
		}
		catch (Exception)
		{
		}
		return result;
	}

	public override void Add(uint address, int offset, uint length, IParameterModel parameterModel)
	{
		if (parameterModel is IArrayModel && !(parameterModel is IDataBlockModel))
		{
			AddArrayConverter(address, offset, length, parameterModel as IArrayModel);
		}
		if (DataAcquisitionMode == DataAcquisitionType.RequestReceive || DataAcquisitionMode == DataAcquisitionType.EDM || dcInfo.DataCollectorType == DataCollectorType.DataCollector2 || calibrationECM.CalibrationDataServer.GTISLevel != GTISVersion.GTIS45)
		{
			AddToSubscription(tagCIDMAccessModeEnum.DM_MODE_ADDRESS, address, offset, length);
			return;
		}
		string message = address.ToString("X8") + "_" + length + " cannot be monitored in " + DataAcquisitionMode.ToString() + " mode";
		EventLogger.Info("Monitor Subscription", message);
	}

	public override void Add(string parameterName)
	{
		bool flag = false;
		StringBuilder stringBuilder = new StringBuilder();
		if (parameterName.IndexOf(".") < 0)
		{
			flag = parameterName.StartsWith("_");
			stringBuilder.Append("ConfigFile.");
		}
		else
		{
			flag = parameterName.StartsWith("._");
		}
		stringBuilder.Append(parameterName);
		if (!flag || DataAcquisitionMode == DataAcquisitionType.RequestReceive)
		{
			AddToSubscription(tagCIDMAccessModeEnum.DM_MODE_NAME, stringBuilder.ToString(), 0, 0u);
		}
		else
		{
			EventLogger.Info("Monitor Subscription", parameterName + " cannot be monitored in " + DataAcquisitionMode.ToString() + " mode");
		}
	}

	private void AddToSubscription(tagCIDMAccessModeEnum mode, object location, int offset, uint length)
	{
		string text = location.ToString();
		if (DataSource == null)
		{
			return;
		}
		try
		{
			CICPPMonitor cICPPMonitor = new CICPPMonitorClass();
			cICPPMonitor.mode = mode;
			cICPPMonitor.location = location;
			if (mode == tagCIDMAccessModeEnum.DM_MODE_ADDRESS)
			{
				cICPPMonitor.offset = offset;
				cICPPMonitor.Length = (int)length;
				text = text + ":" + offset + ":" + length;
			}
			lock (this)
			{
				if (!ParameterList.ContainsKey(text))
				{
					MDASSubscription.MonitoredDataElements.Add(cICPPMonitor);
					ParameterList.Add(text, "");
				}
				else
				{
					base.DuplicateParameterList.Add(text);
				}
			}
		}
		catch (Exception innerException)
		{
			throw new Exception("Subscription: Could not add <" + SourceAddress.Value + ":" + location.ToString() + "> to subscription. ", innerException);
		}
	}

	public override void Remove(uint address, int offset, uint length)
	{
		RemoveFromSubscription(tagCIDMAccessModeEnum.DM_MODE_ADDRESS, address, offset, length);
		RemoveArrayConverter(address, offset, length);
	}

	public override void Remove(string parameterName)
	{
		StringBuilder stringBuilder = new StringBuilder();
		if (parameterName.IndexOf(".") == -1)
		{
			stringBuilder.Append("ConfigFile.");
		}
		stringBuilder.Append(parameterName);
		RemoveFromSubscription(tagCIDMAccessModeEnum.DM_MODE_NAME, stringBuilder.ToString(), 0, 0u);
	}

	public void RemoveFromSubscription(tagCIDMAccessModeEnum mode, object location, int offset, uint length)
	{
		if (DataSource == null)
		{
			return;
		}
		string text = string.Empty;
		try
		{
			lock (this)
			{
				bool flag = false;
				int num = 0;
				while (!flag && num < Count)
				{
					CICPPMonitor cICPPMonitor = (CICPPMonitor)MDASSubscription.MonitoredDataElements[num];
					if (cICPPMonitor.mode == mode)
					{
						switch (cICPPMonitor.mode)
						{
						case tagCIDMAccessModeEnum.DM_MODE_NAME:
							if ((string)cICPPMonitor.location == (string)location)
							{
								text = location.ToString();
								flag = true;
							}
							break;
						case tagCIDMAccessModeEnum.DM_MODE_ADDRESS:
							if ((uint)cICPPMonitor.location == (uint)location && cICPPMonitor.offset == offset && cICPPMonitor.Length == length)
							{
								text = string.Concat(location, ":", offset, ":", length);
								flag = true;
							}
							break;
						}
					}
					if (flag)
					{
						if (base.DuplicateParameterList.Contains(text))
						{
							base.DuplicateParameterList.Remove(text);
						}
						else
						{
							MDASSubscription.MonitoredDataElements.Remove(num);
							ParameterList.Remove(text);
						}
						if (ParameterList.Count == 0)
						{
							RaiseLastParameterRemoved();
						}
					}
					num++;
				}
			}
		}
		catch (Exception innerException)
		{
			throw new Exception("Subscription: Could not remove <" + location.ToString() + "> to subscription. ", innerException);
		}
	}

	public override void RemoveAll()
	{
		Stop();
		lock (this)
		{
			try
			{
				ParameterList.Clear();
				arrayValueConverters.Clear();
				MDASSubscription.MonitoredDataElements.Clear();
			}
			catch (Exception)
			{
			}
		}
	}

	public override void Start()
	{
		lock (MDASSubscriptionManager)
		{
			try
			{
				if (!IsStarted)
				{
					IsStarted = true;
					SetConfigurationXML(0);
					if (DataAcquisitionMode == DataAcquisitionType.BAM)
					{
						RaiseStopBroadCast();
					}
					RaiseStarting();
					InteropMessageReturnType interopMessageReturnType = InteropMessageReturnType.Yes;
					if (DataAcquisitionMode == DataAcquisitionType.BAM && calibrationECM.CalibrationDataServer.GTISLevel != GTISVersion.GTIS45 && calibrationECM.ECMRunLocation != RunLocationType.Development)
					{
						interopMessageReturnType = RaiseRunLocationChange(RunLocationType.Development);
					}
					if (interopMessageReturnType == InteropMessageReturnType.Yes)
					{
						MDASSubscriptionManager.Add(MDASSubscription);
						IsActive = true;
					}
				}
				else
				{
					Resume();
					IsActive = true;
				}
			}
			catch (Exception ex)
			{
				IsStarted = false;
				throw ex;
			}
			finally
			{
				latchedUpdateTimeout = false;
				RaiseStarted();
			}
		}
	}

	public override void Stop()
	{
		lock (MDASSubscriptionManager)
		{
			if (!IsStarted)
			{
				return;
			}
			IsStarted = false;
			IsActive = false;
			try
			{
				SetConfigurationXML(0);
				RaiseStopping();
				MDASSubscriptionManager.Remove(MDASSubscription);
			}
			catch (COMException)
			{
			}
			catch (Exception ex2)
			{
				throw ex2;
			}
			finally
			{
				RaiseStopped();
			}
		}
	}

	public override void Pause()
	{
		if (!IsActive)
		{
			return;
		}
		try
		{
			RaisePausing();
			MDASSubscriptionManager.Pause(MDASSubscription);
		}
		catch (Exception ex)
		{
			throw ex;
		}
		finally
		{
			RaisePaused();
		}
		IsActive = false;
	}

	public override void Resume()
	{
		bool flag = DataAcquisitionMode == DataAcquisitionType.IDL && (DataCollectorStatus == DataCollectorStatus.On || dcInfo.IDLStopMode == IDLStopType.KeyOn);
		if (!flag && IsActive)
		{
			return;
		}
		try
		{
			if (flag)
			{
				MDASSubscription = MDASSubscriptionManager.RetrieveDC2Configuration((Cummins.Interop.DataMonitoring.ICICalDataServer)calibrationECM.CalibrationDataServer.DataServer);
				SetConfigurationXML(0);
			}
			RaiseResuming();
			MDASSubscriptionManager.Resume(MDASSubscription);
			IsStarted = true;
			IsActive = true;
		}
		catch (Exception ex)
		{
			throw ex;
		}
		finally
		{
			RaiseResumed();
		}
	}

	private void CopyElementsTo(ICISubscription newSubscription)
	{
		if (DataSource == null)
		{
			return;
		}
		foreach (CICPPMonitor monitoredDataElement in MDASSubscription.MonitoredDataElements)
		{
			try
			{
				CICPPMonitor cICPPMonitor2 = new CICPPMonitorClass();
				cICPPMonitor2.mode = monitoredDataElement.mode;
				cICPPMonitor2.location = monitoredDataElement.location;
				if (monitoredDataElement.mode == tagCIDMAccessModeEnum.DM_MODE_ADDRESS)
				{
					cICPPMonitor2.offset = monitoredDataElement.offset;
					cICPPMonitor2.Length = monitoredDataElement.Length;
				}
				newSubscription.MonitoredDataElements.Add(cICPPMonitor2);
			}
			catch (Exception)
			{
			}
		}
	}

	private void SetConfigurationXML(int timeout)
	{
		string text = "";
		if (MonitorTimeoutEnabled && timeout > 0)
		{
			text = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><Configuration><DatalinkDropDetectionTimeout>" + timeout + "</DatalinkDropDetectionTimeout><ParameterValidationOptions><ReadabilityCheck>" + ValidateParameter.ToString().ToLower() + "</ReadabilityCheck></ParameterValidationOptions><DC2_IDL_DataRetrievalRate>" + idlBufferRetrievalRate + "</DC2_IDL_DataRetrievalRate></Configuration>";
			latchedUpdateTimeout = true;
		}
		else
		{
			text = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><Configuration><DatalinkDropDetectionTimeout>" + 0 + "</DatalinkDropDetectionTimeout><ParameterValidationOptions><ReadabilityCheck>" + ValidateParameter.ToString().ToLower() + "</ReadabilityCheck></ParameterValidationOptions><DC2_IDL_DataRetrievalRate>" + idlBufferRetrievalRate.ToString() + "</DC2_IDL_DataRetrievalRate></Configuration>";
			rollingAverageRate.Clear();
			lastRefreshTime = 0;
			latchedUpdateTimeout = false;
			numberOfSamples = 0;
		}
		((Cummins.Interop.DataMonitoring.ICIConfiguration)MDASSubscription).Configuration = text;
	}

	private void AddArrayConverter(uint address, int offset, uint length, IArrayModel parameter)
	{
		Cummins.Interop.CalDataServer.ICICalEntity entityByName = calibrationECM.CalibrationDataServer.DataServer.GetEntityByName(null, parameter.FullName);
		(entityByName as ICICalAddressableEntity).CacheMode = Cummins.Interop.CalDataServer.tagCICacheMode.readWrite;
		if (parameter is IArray2DModel)
		{
			(entityByName as ICICalArrayEntity).CurrentIndex = (parameter as IArrayAxis).XAxis.Count * (parameter as IArray2DModel).Y + (parameter as IArray2DModel).X;
		}
		else
		{
			(entityByName as ICICalArrayEntity).CurrentIndex = (parameter as IArray1DModel).X;
		}
		ICICalValueEntity iCICalValueEntity = (entityByName as Cummins.Interop.CalDataServer.ICITreeNode).FirstChild as ICICalValueEntity;
		(iCICalValueEntity as ICICalAddressableEntity).CacheMode = Cummins.Interop.CalDataServer.tagCICacheMode.readWrite;
		lock (arrayValueConverters)
		{
			string key = address + ":" + offset + ":" + length;
			ValueConverter valueConverter = (ValueConverter)arrayValueConverters[key];
			if (valueConverter == null)
			{
				valueConverter = new ValueConverter();
				valueConverter.Converter = iCICalValueEntity;
				valueConverter.Count = 1;
				arrayValueConverters[key] = valueConverter;
			}
			else
			{
				valueConverter.Count++;
			}
		}
	}

	private void RemoveArrayConverter(uint address, int offset, uint length)
	{
		string key = address + ":" + offset + ":" + length;
		lock (arrayValueConverters)
		{
			ValueConverter valueConverter = (ValueConverter)arrayValueConverters[key];
			if (valueConverter != null && --valueConverter.Count == 0)
			{
				arrayValueConverters.Remove(key);
			}
		}
	}

	private void RaisePerfomanceEvent()
	{
		if (this.performanceStatistics != null)
		{
			PerformanceEventArgs e = new PerformanceEventArgs();
			e.ElapsedTime = RollingAveragePerformance;
			this.performanceStatistics(this, e);
		}
	}

	private InteropMessageReturnType RaiseIDLTransferInterruptEvent()
	{
		InteropMessageReturnType result = InteropMessageReturnType.Yes;
		if (this.iDLTransferInterrupt != null)
		{
			IDLAutoTransferBufferEventArgs e = new IDLAutoTransferBufferEventArgs();
			this.iDLTransferInterrupt(this, e);
			result = e.ReturnType;
		}
		return result;
	}

	private InteropMessageReturnType RaiseStopBroadCast()
	{
		InteropMessageReturnType interopMessageReturnType = InteropMessageReturnType.Unspecified;
		if (this.stopBroadCast != null)
		{
			StopBroadCastEventArgs e = new StopBroadCastEventArgs();
			this.stopBroadCast(this, e);
			interopMessageReturnType = e.ReturnType;
			if (interopMessageReturnType == InteropMessageReturnType.Yes)
			{
				calibrationECM.Execute(Cummins.Calibration.CommandType.StopBroadcast);
			}
		}
		return interopMessageReturnType;
	}

	private void RaiseIDLBufferIsFullEvent()
	{
		if (this.iDLBufferIsFull != null)
		{
			this.iDLBufferIsFull(this, null);
		}
	}

	private void RaiseIDLRetrievalRateIsTooSlowEvent(string msg, int requestedRate, int actualRate)
	{
		if (this.iDLRetrievalRateIsTooSlow != null)
		{
			IDLRetrievalRateEventArgs e = new IDLRetrievalRateEventArgs();
			e.Message = msg;
			e.RequestedRate = requestedRate;
			e.ActualRate = actualRate;
			this.iDLRetrievalRateIsTooSlow(this, e);
		}
	}

	private void RaiseIDLRetrievalRateIsTooFastEvent(string msg, int requestedRate, int actualRate)
	{
		if (this.iDLRetrievalRateIsTooFast != null)
		{
			IDLRetrievalRateEventArgs e = new IDLRetrievalRateEventArgs();
			e.Message = msg;
			e.RequestedRate = requestedRate;
			e.ActualRate = actualRate;
			this.iDLRetrievalRateIsTooFast(this, e);
		}
	}

	private void OnDataRefreshViaEvents(object notification)
	{
		RaiseDataRefreshEvent((ArrayList)notification);
	}

	private void RaiseDataRefreshEvent(ArrayList parameterValues)
	{
		if (this.notification != null)
		{
			ECMDataRefreshEventArgs e = new ECMDataRefreshEventArgs();
			e.SourceAddress = SourceAddress;
			e.SubscriptionHashCode = GetHashCode();
			e.ECMData = parameterValues;
			e.ParameterCount = ParameterCount;
			this.notification(this, e);
		}
	}

	private void OnReceiveMessage(Cummins.Interop.Message.ICIMsg msg)
	{
		InteropMessageReturnType interopMessageReturnType = InteropMessageReturnType.Unspecified;
		try
		{
			if (msg.Originator != 17)
			{
				return;
			}
			switch (msg.MessageType)
			{
			case Cummins.Interop.Message.MsgTypeEnum.MTYPE_DIAGNOSTIC:
			{
				if (msg.Group != MessageGroupId)
				{
					break;
				}
				Cummins.Interop.Message.ICIDiagnosticMsg iCIDiagnosticMsg = (Cummins.Interop.Message.ICIDiagnosticMsg)msg;
				switch (iCIDiagnosticMsg.Identifier)
				{
				case 11:
				{
					string text = string.Empty;
					try
					{
						if (calibrationECM.DataLink is ICPPDataLink)
						{
							text = (calibrationECM.DataLink as ICPPDataLink).ECMID;
						}
						if (text == string.Empty)
						{
							SetConfigurationXML(0);
							RaiseConnectionLostEvent(SourceAddress);
						}
						break;
					}
					catch
					{
						break;
					}
				}
				case 14:
					interopMessageReturnType = RaiseRunLocationChange(RunLocationType.Development);
					msg.Response = (Cummins.Interop.Message.MsgReturnTypeEnum)interopMessageReturnType;
					break;
				case 15:
					interopMessageReturnType = RaiseStopBroadCast();
					msg.Response = (Cummins.Interop.Message.MsgReturnTypeEnum)interopMessageReturnType;
					break;
				case 17:
					interopMessageReturnType = RaiseIDLTransferInterruptEvent();
					msg.Response = (Cummins.Interop.Message.MsgReturnTypeEnum)interopMessageReturnType;
					break;
				case 22:
					RaiseIDLBufferIsFullEvent();
					break;
				case 24:
					RaiseIDLRetrievalRateIsTooSlowEvent(msg.ProgrammerText, (int)msg.Parameters[1].Value, (int)msg.Parameters[2].Value);
					break;
				case 25:
					RaiseIDLRetrievalRateIsTooSlowEvent(msg.ProgrammerText, (int)msg.Parameters[1].Value, (int)msg.Parameters[2].Value);
					break;
				}
				break;
			}
			case Cummins.Interop.Message.MsgTypeEnum.MTYPE_PROGRESS:
			{
				if (msg.Group != MessageGroupId)
				{
					break;
				}
				Cummins.Interop.Message.ICIProgressMsg iCIProgressMsg = (Cummins.Interop.Message.ICIProgressMsg)msg;
				switch (iCIProgressMsg.Identifier)
				{
				case 101:
				{
					lock (this)
					{
						int count = iCIProgressMsg.Parameters.Count;
						ArrayList arrayList = new ArrayList();
						for (int i = 1; i <= count; i++)
						{
							Cummins.Interop.Message.ICIMsgParam iCIMsgParam = iCIProgressMsg.Parameters[i];
							GetValueForArrayParameters(arrayList, (Cummins.Interop.DataMonitoring.ICICollection)iCIMsgParam.Value);
							if (DataAcquisitionMode == DataAcquisitionType.IDL)
							{
								MapParameterIDToName(arrayList);
							}
						}
						RaiseDataRefreshEvent(arrayList);
					}
					int timeStamp = ((ICIDataElementNotification)((Cummins.Interop.DataMonitoring.ICICollection)iCIProgressMsg.Parameters[1].Value)[0]).timeStamp;
					UpdateActualRefreshRate(timeStamp);
					break;
				}
				case 103:
					RaiseIDLBufferTransferStartedEvent();
					break;
				case 104:
					RaiseIDLBufferTransferCompletedEvent();
					break;
				case 105:
					RaiseIDLNotificationsStartedEvent();
					break;
				case 106:
					RaiseIDLNotificationsCompletedEvent();
					break;
				case 102:
					break;
				}
				break;
			}
			case Cummins.Interop.Message.MsgTypeEnum.MTYPE_PERFORMANCE:
				_ = (Cummins.Interop.Message.ICIPerformanceMsg)msg;
				RaisePerfomanceEvent();
				break;
			case Cummins.Interop.Message.MsgTypeEnum.MTYPE_REQUEST:
			{
				_ = (Cummins.Interop.Message.ICIRequestMsg)msg;
				int identifier = msg.Identifier;
				if (identifier == 301)
				{
					msg.Response = Cummins.Interop.Message.MsgReturnTypeEnum.MSGRT_NO;
				}
				break;
			}
			}
		}
		catch (Exception)
		{
		}
	}

	private void MapParameterIDToName(ArrayList parameterValues)
	{
		foreach (ICIDataElementNotification parameterValue in parameterValues)
		{
			CICPPMonitor cICPPMonitor = parameterValue.DataElementMonitor as CICPPMonitor;
			if (cICPPMonitor.mode == tagCIDMAccessModeEnum.DM_MODE_PARAMETER_ID)
			{
				try
				{
					Cummins.Interop.CalDataServer.ICICalEntity entityByID = calibrationECM.CalibrationDataServer.DataServer.GetEntityByID(null, (int)cICPPMonitor.location);
					cICPPMonitor.mode = tagCIDMAccessModeEnum.DM_MODE_NAME;
					cICPPMonitor.location = entityByID.FullName;
				}
				catch (Exception)
				{
				}
			}
		}
	}

	private void GetValueForArrayParameters(ArrayList dens, Cummins.Interop.DataMonitoring.ICICollection parameterValues)
	{
		lock (arrayValueConverters)
		{
			foreach (ICIDataElementNotification parameterValue in parameterValues)
			{
				dens.Add(parameterValue);
				CICPPMonitor cICPPMonitor = parameterValue.DataElementMonitor as CICPPMonitor;
				if (cICPPMonitor.mode != tagCIDMAccessModeEnum.DM_MODE_ADDRESS)
				{
					continue;
				}
				if (parameterValue.Status == tagCIDMStatusEnum.DM_STATUS_OK)
				{
					try
					{
						string key = string.Concat(cICPPMonitor.location, ":", cICPPMonitor.offset, ":", cICPPMonitor.Length);
						if (arrayValueConverters[key] != null)
						{
							ICICalValueEntity converter = ((ValueConverter)arrayValueConverters[key]).Converter;
							if (converter == null)
							{
								continue;
							}
							try
							{
								if (parameterValue.RawData != null)
								{
									if (parameterValue.Changed)
									{
										(converter as ICICalAddressableEntity).RawData = parameterValue.RawData;
										(arrayValueConverters[key] as ValueConverter).ScaledValue = converter.ScaledValue;
									}
									parameterValue.ScaledValue = (arrayValueConverters[key] as ValueConverter).ScaledValue;
								}
							}
							catch (Exception)
							{
							}
							continue;
						}
						parameterValue.ScaledValue = RawDataToString(parameterValue.RawData);
					}
					catch (Exception)
					{
					}
				}
				else
				{
					Trace.WriteLine("Got a notification with status " + parameterValue.Status);
				}
			}
		}
	}

	private string RawDataToString(object rawData)
	{
		byte[] array = (byte[])rawData;
		StringBuilder stringBuilder = new StringBuilder();
		if (array != null)
		{
			byte[] array2 = array;
			foreach (byte b in array2)
			{
				stringBuilder.Append(b.ToString("X2"));
			}
		}
		return stringBuilder.ToString();
	}

	private void OnAssignFilters(Cummins.Interop.Message.filters filters)
	{
		try
		{
			Cummins.Interop.Message.ICIFilterFactory iCIFilterFactory = (Cummins.Interop.Message.ICIFilterFactory)msgManager;
			filters.Add(iCIFilterFactory.CreateProgressMsgFilter(-1, 17, MessageGroupId, Cummins.Interop.Message.MsgProgressTypeEnum.MSGPROG_ANYPROGRESS));
		}
		catch (Exception ex)
		{
			throw ex;
		}
	}

	private InteropMessageReturnType RaiseRunLocationChange(RunLocationType runLocation)
	{
		InteropMessageReturnType interopMessageReturnType = InteropMessageReturnType.Unspecified;
		if (this.runLocationChange != null)
		{
			RunLocationChangeEventArgs e = new RunLocationChangeEventArgs(runLocation);
			this.runLocationChange(this, e);
			interopMessageReturnType = e.ReturnType;
			if (interopMessageReturnType == InteropMessageReturnType.Yes && runLocation == RunLocationType.Development)
			{
				calibrationECM.Execute(Cummins.Calibration.CommandType.RunFromDevelopment);
			}
		}
		return interopMessageReturnType;
	}

	private void RaiseIDLNotificationsStartedEvent()
	{
		if (this.iDLNotificationsStarted != null)
		{
			this.iDLNotificationsStarted(this, EventArgs.Empty);
		}
	}

	private void RaiseIDLNotificationsCompletedEvent()
	{
		if (this.iDLNotificationsCompleted != null)
		{
			this.iDLNotificationsCompleted(this, EventArgs.Empty);
		}
	}

	private void RaiseIDLBufferTransferStartedEvent()
	{
		if (this.iDLBufferTransferStarted != null)
		{
			this.iDLBufferTransferStarted(this, EventArgs.Empty);
		}
	}

	private void RaiseIDLBufferTransferCompletedEvent()
	{
		if (this.iDLBufferTransferCompleted != null)
		{
			this.iDLBufferTransferCompleted(this, EventArgs.Empty);
		}
	}

	private void RaiseConnectionLostEvent(IAddressValue deviceAddress)
	{
		if (IsActive && this.connectionLost != null)
		{
			ConnectionEventArgs e = new ConnectionEventArgs();
			e.DeviceAddress = deviceAddress;
			this.connectionLost(this, e);
		}
	}

	private void UpdateActualRefreshRate(int currentRefreshTime)
	{
		lock (rollingAverageRate)
		{
			if (rollingAverageRate.Count == 10)
			{
				if (MonitorTimeoutEnabled && !latchedUpdateTimeout)
				{
					SetConfigurationXML(Math.Max(MonitorTimeoutFloor, (int)RollingAveragePerformance * MonitorTimeoutFactor));
					latchedUpdateTimeout = true;
				}
				rollingAverageRate.Dequeue();
			}
			if (numberOfSamples++ > 5)
			{
				rollingAverageRate.Enqueue(currentRefreshTime - lastRefreshTime);
			}
		}
		lastRefreshTime = currentRefreshTime;
	}
}
public class RunLocationChangeEventArgs : EventArgs
{
	private RunLocationType runLocationType;

	private InteropMessageReturnType returnType;

	public RunLocationType EcmRunLocation => runLocationType;

	public InteropMessageReturnType ReturnType
	{
		get
		{
			return returnType;
		}
		set
		{
			returnType = value;
		}
	}

	public RunLocationChangeEventArgs(RunLocationType runLocation)
	{
		runLocationType = runLocation;
	}
}
public class StopBroadCastEventArgs : EventArgs
{
	private InteropMessageReturnType returnType;

	public InteropMessageReturnType ReturnType
	{
		get
		{
			return returnType;
		}
		set
		{
			returnType = value;
		}
	}
}
public class IDLAutoTransferBufferEventArgs : EventArgs
{
	private InteropMessageReturnType returnType;

	public InteropMessageReturnType ReturnType
	{
		get
		{
			return returnType;
		}
		set
		{
			returnType = value;
		}
	}
}
public class IDLRetrievalRateEventArgs : EventArgs
{
	private string msg;

	private int actualRate;

	private int requestedRate;

	public string Message
	{
		get
		{
			return msg;
		}
		set
		{
			msg = value;
		}
	}

	public int ActualRate
	{
		get
		{
			return actualRate;
		}
		set
		{
			actualRate = value;
		}
	}

	public int RequestedRate
	{
		get
		{
			return requestedRate;
		}
		set
		{
			requestedRate = value;
		}
	}
}
public class SubscriptionException : BaseException
{
	public SubscriptionException(short errorNo)
		: base(Facility.Subscription, errorNo)
	{
	}

	public SubscriptionException(Facility facility, short errorNo)
		: base(facility, errorNo)
	{
	}

	public SubscriptionException(Facility facility, short errorNo, string message)
		: base(facility, errorNo, message)
	{
	}

	public SubscriptionException(Facility facility, short errorNo, string message, Exception inner)
		: base(facility, errorNo, message, inner)
	{
	}

	public SubscriptionException(Facility facility, short errorNo, string message, string context)
		: base(facility, errorNo, message, context)
	{
	}

	public SubscriptionException(Facility facility, short errorNo, string message, string context, Exception inner)
		: base(facility, errorNo, message, context, inner)
	{
	}
}
public class DataRetrievalException : SubscriptionException
{
	public DataRetrievalException(short errorNo)
		: base(Facility.Subscription, errorNo)
	{
	}

	public DataRetrievalException(short errorNo, string message)
		: base(Facility.Subscription, errorNo, message)
	{
	}

	public DataRetrievalException(short errorNo, string message, Exception inner)
		: base(Facility.Subscription, errorNo, message, inner)
	{
	}
}
public enum SubscriptionMessageIDs
{
	NullCalDataServer,
	SetDataServerError,
	RetrieveDCStatusError,
	RetrieveDCTypeError,
	RetrieveDCMonitorModeError,
	RetrieveDCTriggerTypeError,
	RetrieveDCIDLStopModeError,
	ParameterNotSupported
}
internal class ExceptionMessage
{
	private const string StringResourceName = "Cummins.Subscription.Exception.ExceptionStrings";

	private static ResourceManager resources = new ResourceManager("Cummins.Subscription.Exception.ExceptionStrings", Assembly.GetExecutingAssembly());

	internal static string GetMessage(SubscriptionMessageIDs id)
	{
		return resources.GetString(id.ToString());
	}
}
public class SetDataServerException : SubscriptionException
{
	public SetDataServerException(short errorNo)
		: base(Facility.Subscription, errorNo)
	{
	}

	public SetDataServerException(short errorNo, string message)
		: base(Facility.Subscription, errorNo, message)
	{
	}

	public SetDataServerException(short errorNo, string message, Exception inner)
		: base(Facility.Subscription, errorNo, message, inner)
	{
	}
}
public class ParameterNotSupportedException : SubscriptionException
{
	public ParameterNotSupportedException(short errorNo)
		: base(Facility.Subscription, errorNo)
	{
	}

	public ParameterNotSupportedException(short errorNo, string message)
		: base(Facility.Subscription, errorNo, message)
	{
	}

	public ParameterNotSupportedException(short errorNo, string message, Exception inner)
		: base(Facility.Subscription, errorNo, message, inner)
	{
	}
}
public enum DataCollectorStatus
{
	On = 1,
	Off = 0
}
public enum DataCollectorType
{
	DataCollector1 = 1,
	DataCollector2 = 2,
	None = 0
}
public delegate void NotificationEventHandler(object sender, DataRefreshEventArgs e);
public abstract class PCLSubscriptionBase : IDisposable
{
	private const string AddressHeader = "<localAddress>";

	private PCLConnection _pclConnection;

	private string _connectionString;

	private string _dlaPrefix;

	private ushort _dlaChannelID;

	private ManualResetEvent _PCLConnectionLoaded = new ManualResetEvent(initialState: false);

	private bool _disposed;

	protected PCLConnection PCLConnection
	{
		get
		{
			return _pclConnection;
		}
		set
		{
			_pclConnection = value;
			if (_pclConnection != null)
			{
				_PCLConnectionLoaded.Set();
			}
			else
			{
				_PCLConnectionLoaded.Reset();
			}
		}
	}

	public event NotificationEventHandler Notification
	{
		add
		{
			notification += value;
		}
		remove
		{
			notification -= value;
		}
	}

	public event EventHandler Starting;

	public event EventHandler Started;

	public event EventHandler Stopping;

	public event EventHandler Stopped;

	public event EventHandler Pausing;

	public event EventHandler Paused;

	public event EventHandler Resuming;

	public event EventHandler Resumed;

	public event EventHandler LastParameterRemoved;

	private event NotificationEventHandler notification;

	public void RegisterForEvents(ICalibrationOnline calibration)
	{
		if (calibration is ICalibrationECM && calibration is ICalibrationECM calibrationECM)
		{
			calibrationECM.DataLink.Alive += DataLink_Alive;
			calibrationECM.DataLink.Dead += DataLink_Dead;
		}
	}

	protected void CreatePCLConnection(string dlaPrefix, ushort dlaChannelID, string connectionString)
	{
		PCLSystem.start();
		_connectionString = connectionString;
		_dlaPrefix = dlaPrefix;
		_dlaChannelID = dlaChannelID;
		PCLConnection = PCLSystem.openConnection(dlaPrefix, dlaChannelID, connectionString);
	}

	protected abstract void RebuildPCLRequest();

	protected abstract void ConnectionLost();

	public static List<PCLWrapper.ParameterInfo> GetParametersAvailable(string cbfFileName)
	{
		return PCLSystem.getParameters("j1939://*/" + cbfFileName);
	}

	public static int FigureParameterCount(List<PGNList> parameterValues)
	{
		int num = 0;
		foreach (PGNList parameterValue in parameterValues)
		{
			foreach (PGN pGN in parameterValue.PGNs)
			{
				if (pGN.SPNs != null)
				{
					num += pGN.SPNs.Count;
				}
			}
		}
		return num;
	}

	public void DataLink_Dead(object sender, EventArgs e)
	{
		if (PCLConnection != null)
		{
			ConnectionLost();
			CloseConnection();
		}
	}

	public void ReopenConnection()
	{
		if (PCLConnection == null)
		{
			CreatePCLConnection(_dlaPrefix, _dlaChannelID, _connectionString);
		}
	}

	public void CloseConnection()
	{
		if (PCLConnection != null)
		{
			lock (PCLConnection)
			{
				PCLSystem.closeConnection(PCLConnection);
				PCLConnection = null;
				PCLSystem.stop();
			}
		}
	}

	public void DataLink_Alive(object sender, EventArgs e)
	{
		if (PCLConnection == null)
		{
			CreatePCLConnection(_dlaPrefix, _dlaChannelID, _connectionString);
			RebuildPCLRequest();
		}
	}

	protected void WaitForPCLConnection()
	{
		_PCLConnectionLoaded.WaitOne();
	}

	protected void RaiseDataRefreshEvent(List<PGNList> parameterValues)
	{
		if (this.notification != null)
		{
			J1939_71DataRefreshEventArgs e = new J1939_71DataRefreshEventArgs();
			e.SourceAddress = GetSourceAddress(parameterValues);
			e.SubscriptionHashCode = GetHashCode();
			e.J1939_71Data = parameterValues;
			e.ParameterCount = FigureParameterCount(parameterValues);
			this.notification(this, e);
		}
	}

	protected IAddressValue GetSourceAddress(List<PGNList> parameterValues)
	{
		IAddressValue result = null;
		using (List<PGNList>.Enumerator enumerator = parameterValues.GetEnumerator())
		{
			if (enumerator.MoveNext())
			{
				PGNList current = enumerator.Current;
				result = AddressFactory.ProductAddressValue(current.SourceAddress.ToString("X2"));
			}
		}
		return result;
	}

	protected List<SPN> BuildSPNList(string pgnName, Value value, List<string> spnNames)
	{
		List<SPN> list = null;
		PCLValueType_t valueType = value.getValueType();
		if (valueType == PCLValueType_t.PCL_STRUCTURE)
		{
			list = new List<SPN>();
			PCLStructure pCLStructure = value as PCLStructure;
			for (int i = 0; i < pCLStructure.getFieldCount(); i++)
			{
				string fieldName = pCLStructure.getFieldName(i);
				if (spnNames == null || spnNames.Contains(fieldName))
				{
					list.Add(CreateSPN(pgnName, fieldName, pCLStructure.getFieldValue(i)));
				}
			}
		}
		return list;
	}

	protected SPN CreateSPN(string pgnName, string name, Value value)
	{
		SPN sPN = new SPN();
		sPN.Value = value.toString();
		sPN.PGNName = pgnName;
		sPN.Name = name;
		sPN.Number = -1;
		return sPN;
	}

	protected byte GetToolAddress(string deviceInfo)
	{
		int num = deviceInfo.IndexOf("<localAddress>");
		byte result = 249;
		if (num > -1)
		{
			num += "<localAddress>".Length;
			string s = deviceInfo.Substring(num, 2);
			result = byte.Parse(s, NumberStyles.HexNumber);
		}
		return result;
	}

	public void Pause()
	{
	}

	public void Resume()
	{
	}

	protected void RaiseStarting()
	{
		if (this.Starting != null)
		{
			this.Starting(this, EventArgs.Empty);
		}
	}

	protected void RaiseStarted()
	{
		if (this.Started != null)
		{
			this.Started(this, EventArgs.Empty);
		}
	}

	protected void RaiseStopping()
	{
		if (this.Stopping != null)
		{
			this.Stopping(this, EventArgs.Empty);
		}
	}

	protected void RaiseStopped()
	{
		if (this.Stopped != null)
		{
			this.Stopped(this, EventArgs.Empty);
		}
	}

	protected void RaiseLastParameterRemoved()
	{
		if (this.LastParameterRemoved != null)
		{
			this.LastParameterRemoved(this, EventArgs.Empty);
		}
	}

	public void Dispose()
	{
		Dispose(disposing: true);
		GC.SuppressFinalize(this);
	}

	protected virtual void Dispose(bool disposing)
	{
		if (!_disposed)
		{
			CloseConnection();
			_disposed = true;
		}
	}
}
public class J1939_71BroadcastSubscription : PCLSubscriptionBase, ISubscription, IDisposable, IPausable, IDataProvider
{
	private ResponseIterator _broadcastListenerRespItr;

	private Dictionary<string, List<string>> _listenToPGNNames = new Dictionary<string, List<string>>();

	private int _requestAllReferenceCount;

	private bool _started;

	private byte _toolAddress;

	public int ID => GetHashCode();

	public int BaseRate
	{
		get
		{
			return 500;
		}
		set
		{
		}
	}

	public ICalibration DataSource => null;

	public bool IsActive => _started;

	public bool IsStarted
	{
		get
		{
			return _started;
		}
		set
		{
			if (_started != value)
			{
				if (value)
				{
					Start();
				}
				else
				{
					Stop();
				}
			}
		}
	}

	public int Count
	{
		get
		{
			throw new Exception("The method or operation is not implemented.");
		}
	}

	public IAddressValue SourceAddress
	{
		get
		{
			return AddressFactory.ProductAddressValue(255);
		}
		set
		{
		}
	}

	public J1939_71BroadcastSubscription(ICalibrationOnline calibration, string dlaPrefix, string dlaChannelID, string toolAddress, string cbfFileName)
	{
		Initialize(dlaPrefix, dlaChannelID, toolAddress, cbfFileName);
		RegisterForEvents(calibration);
	}

	public J1939_71BroadcastSubscription(string dlaPrefix, string dlaChannelID, string toolAddress, string cbfFileName)
	{
		Initialize(dlaPrefix, dlaChannelID, toolAddress, cbfFileName);
	}

	protected void Initialize(string dlaPrefix, string dlaChannelID, string toolAddress, string cbfFileName)
	{
		_toolAddress = byte.Parse(toolAddress, NumberStyles.AllowHexSpecifier);
		ushort dlaChannelID2 = ushort.Parse(dlaChannelID);
		string connectionString = "j1939://*/" + cbfFileName;
		CreatePCLConnection(dlaPrefix, dlaChannelID2, connectionString);
	}

	~J1939_71BroadcastSubscription()
	{
		if (base.PCLConnection != null)
		{
			lock (base.PCLConnection)
			{
				PCLSystem.closeConnection(base.PCLConnection);
			}
		}
		PCLSystem.stop();
	}

	public void Add(string parameterName)
	{
		bool flag = false;
		bool flag2 = _listenToPGNNames.Count == 0;
		string text = null;
		string text2 = null;
		try
		{
			int num = parameterName.IndexOf('.');
			if (num > -1)
			{
				text = parameterName.Substring(0, num);
				text2 = parameterName.Substring(num + 1);
			}
			if (!(text == "*"))
			{
				lock (_listenToPGNNames)
				{
					if (!_listenToPGNNames.ContainsKey(text))
					{
						_listenToPGNNames.Add(text, new List<string>());
						flag = true;
					}
					if (!string.IsNullOrEmpty(text2))
					{
						List<string> list = _listenToPGNNames[text];
						list.Add(text2);
					}
				}
			}
			else if (_requestAllReferenceCount == 0)
			{
				_requestAllReferenceCount++;
				flag = true;
			}
		}
		catch
		{
		}
		if (_started && flag)
		{
			RebuildPCLRequest();
			if (flag2)
			{
				RaiseStarted();
			}
		}
	}

	public void Remove(string parameterName)
	{
		bool flag = false;
		_ = _listenToPGNNames.Count;
		string text = null;
		string item = null;
		try
		{
			int num = parameterName.IndexOf('.');
			if (num > -1)
			{
				text = parameterName.Substring(0, num);
				item = parameterName.Substring(num + 1);
			}
			if (text == "*")
			{
				if (_requestAllReferenceCount > 0)
				{
					_requestAllReferenceCount--;
					if (_requestAllReferenceCount == 0)
					{
						flag = true;
					}
				}
			}
			else if (_listenToPGNNames.ContainsKey(text))
			{
				List<string> list = _listenToPGNNames[text];
				if (list.Contains(item))
				{
					list.Remove(item);
				}
				if (list.Count == 0)
				{
					_listenToPGNNames.Remove(text);
					flag = true;
				}
			}
		}
		catch
		{
		}
		if (flag && _requestAllReferenceCount == 0 && _listenToPGNNames.Count == 0)
		{
			CloseIterator();
			RaiseLastParameterRemoved();
			RaiseStopped();
		}
	}

	public void Remove(uint address, int offset, uint length)
	{
	}

	public void RemoveAll()
	{
		CloseIterator();
		_requestAllReferenceCount = 0;
		_listenToPGNNames.Clear();
		RaiseLastParameterRemoved();
		RaiseStopped();
	}

	public void Start()
	{
		if (!_started)
		{
			RaiseStarting();
			_started = true;
			RebuildPCLRequest();
			RaiseStarted();
		}
	}

	public void Stop()
	{
		if (_started)
		{
			RaiseStopping();
			CloseIterator();
			_started = false;
			RaiseStopped();
		}
	}

	public new void Dispose()
	{
		Stop();
		CloseConnection();
	}

	protected override void RebuildPCLRequest()
	{
		if (!_started)
		{
			return;
		}
		if (_requestAllReferenceCount == 0 && _listenToPGNNames.Count == 0)
		{
			CloseIterator();
		}
		else
		{
			if (_broadcastListenerRespItr != null)
			{
				return;
			}
			WaitForPCLConnection();
			lock (base.PCLConnection)
			{
				uint item = base.PCLConnection.createParameterHandle("*");
				List<uint> list = new List<uint>();
				list.Add(item);
				if (_broadcastListenerRespItr == null)
				{
					_broadcastListenerRespItr = base.PCLConnection.requestGetParameterValues(list, 0u);
					_broadcastListenerRespItr.Response += PCLBroadcastResponse;
				}
			}
		}
	}

	protected override void ConnectionLost()
	{
		CloseIterator();
		_started = false;
	}

	protected void PCLBroadcastResponse(object sender)
	{
		if (_requestAllReferenceCount == 0 && _listenToPGNNames.Count == 0)
		{
			return;
		}
		ResponseIterator responseIterator = sender as ResponseIterator;
		List<PGNList> list = new List<PGNList>();
		if (_broadcastListenerRespItr != null)
		{
			try
			{
				lock (_broadcastListenerRespItr)
				{
					while (responseIterator.nextResponse())
					{
						if (!responseIterator.isPosResponse())
						{
							continue;
						}
						uint posResponseItemCount = responseIterator.getPosResponseItemCount();
						if (posResponseItemCount == 0)
						{
							continue;
						}
						PGNList pGNList = new PGNList();
						for (uint num = 0u; num < posResponseItemCount; num++)
						{
							string posResponseItemName = responseIterator.getPosResponseItemName((int)num);
							if (_requestAllReferenceCount > 0 || _listenToPGNNames.ContainsKey(posResponseItemName))
							{
								List<string> spnNames = ((_requestAllReferenceCount != 0) ? null : _listenToPGNNames[posResponseItemName]);
								PGN pGN = new PGN();
								pGN.Name = posResponseItemName;
								Value posResponseItemValue = responseIterator.getPosResponseItemValue((int)num);
								pGN.SPNs = BuildSPNList(pGN.Name, posResponseItemValue, spnNames);
								pGNList.PGNs.Add(pGN);
							}
						}
						if (pGNList.PGNs.Count > 0)
						{
							pGNList.TimeStamp = responseIterator.getResponseTimestamp();
							pGNList.SourceAddress = responseIterator.getSourceAddress();
							pGNList.DestinationAddress = responseIterator.getDestinationAddress();
							list.Add(pGNList);
						}
					}
				}
			}
			catch
			{
			}
		}
		if (list.Count > 0)
		{
			RaiseDataRefreshEvent(list);
		}
	}

	protected void CloseIterator()
	{
		if (_broadcastListenerRespItr != null)
		{
			lock (_broadcastListenerRespItr)
			{
				_broadcastListenerRespItr.close();
				_broadcastListenerRespItr = null;
			}
		}
	}
}
public class J1939_71Subscription : PCLSubscriptionBase, ISubscription, IDisposable, IPausable, IDataProvider
{
	private const double NumberOfRequestsPerSecond = 5.0;

	private ResponseIterator _respItr;

	private Dictionary<string, List<string>> _listenToPGNNames = new Dictionary<string, List<string>>();

	private bool _started;

	private int _updateRate = 500;

	private byte _sourceAddress;

	private byte _toolAddress;

	public int ID => GetHashCode();

	public int BaseRate
	{
		get
		{
			return _updateRate;
		}
		set
		{
			if (value != _updateRate)
			{
				_updateRate = value;
				RebuildPCLRequest();
			}
		}
	}

	public ICalibration DataSource => null;

	public bool IsActive => _started;

	public bool IsStarted
	{
		get
		{
			return _started;
		}
		set
		{
			if (_started != value)
			{
				if (value)
				{
					Start();
				}
				else
				{
					Stop();
				}
			}
		}
	}

	public int Count
	{
		get
		{
			throw new Exception("The method or operation is not implemented.");
		}
	}

	public IAddressValue SourceAddress
	{
		get
		{
			return AddressFactory.ProductAddressValue(_sourceAddress);
		}
		set
		{
		}
	}

	public J1939_71Subscription(ICalibrationOnline calibration, string dlaPrefix, string dlaChannelID, string toolAddress, string cbfFileName)
	{
		Initialize(dlaPrefix, dlaChannelID, toolAddress, cbfFileName);
		RegisterForEvents(calibration);
	}

	protected void Initialize(string dlaPrefix, string dlaChannelID, string toolAddress, string cbfFileName)
	{
		_toolAddress = byte.Parse(toolAddress, NumberStyles.AllowHexSpecifier);
		ushort dlaChannelID2 = ushort.Parse(dlaChannelID);
		string connectionString = "j1939://" + _sourceAddress.ToString("X2") + "h:" + _toolAddress.ToString("X2") + "h/" + cbfFileName;
		CreatePCLConnection(dlaPrefix, dlaChannelID2, connectionString);
	}

	~J1939_71Subscription()
	{
		if (base.PCLConnection != null)
		{
			lock (base.PCLConnection)
			{
				PCLSystem.closeConnection(base.PCLConnection);
			}
		}
		PCLSystem.stop();
	}

	public void Add(string parameterName)
	{
		bool flag = false;
		bool flag2 = _listenToPGNNames.Count == 0;
		string key = null;
		string text = null;
		try
		{
			int num = parameterName.IndexOf('.');
			if (num > -1)
			{
				key = parameterName.Substring(0, num);
				text = parameterName.Substring(num + 1);
			}
			lock (_listenToPGNNames)
			{
				if (!_listenToPGNNames.ContainsKey(key))
				{
					_listenToPGNNames.Add(key, new List<string>());
					flag = true;
				}
			}
			if (!string.IsNullOrEmpty(text))
			{
				List<string> list = _listenToPGNNames[key];
				list.Add(text);
			}
		}
		catch
		{
		}
		if (_started && flag)
		{
			RebuildPCLRequest();
			if (flag2)
			{
				RaiseStarted();
			}
		}
	}

	public void Remove(string parameterName)
	{
		bool flag = false;
		bool flag2 = _listenToPGNNames.Count > 0;
		string key = null;
		string item = null;
		try
		{
			int num = parameterName.IndexOf('.');
			if (num > -1)
			{
				key = parameterName.Substring(0, num);
				item = parameterName.Substring(num + 1);
			}
			if (_listenToPGNNames.ContainsKey(key))
			{
				List<string> list = _listenToPGNNames[key];
				if (list.Contains(item))
				{
					list.Remove(item);
				}
				if (list.Count == 0)
				{
					_listenToPGNNames.Remove(key);
					flag = true;
				}
			}
		}
		catch
		{
		}
		if (!flag)
		{
			return;
		}
		bool flag3 = false;
		if (_listenToPGNNames.Count == 0)
		{
			if (flag2)
			{
				if (_respItr != null)
				{
					_respItr.close();
					_respItr = null;
				}
				flag3 = true;
			}
		}
		else
		{
			flag3 = false;
			RebuildPCLRequest();
		}
		if (flag3)
		{
			RaiseLastParameterRemoved();
			RaiseStopped();
		}
	}

	public void Remove(uint address, int offset, uint length)
	{
	}

	public void RemoveAll()
	{
		if (_respItr != null)
		{
			_respItr.close();
			_respItr = null;
		}
		_listenToPGNNames.Clear();
		RaiseLastParameterRemoved();
		RaiseStopped();
	}

	public void Start()
	{
		if (!_started)
		{
			RaiseStarting();
			_started = true;
			RebuildPCLRequest();
			RaiseStarted();
		}
	}

	public void Stop()
	{
		if (_started)
		{
			RaiseStopping();
			if (_respItr != null)
			{
				_respItr.close();
				_respItr = null;
			}
			_started = false;
			RaiseStopped();
		}
	}

	public new void Dispose()
	{
		Stop();
		lock (base.PCLConnection)
		{
			PCLSystem.closeConnection(base.PCLConnection);
		}
		PCLSystem.stop();
	}

	protected override void RebuildPCLRequest()
	{
		if (!_started)
		{
			return;
		}
		WaitForPCLConnection();
		if (_listenToPGNNames.Count <= 0 || base.PCLConnection == null)
		{
			return;
		}
		List<uint> list = new List<uint>();
		Dictionary<string, List<string>>.KeyCollection keys = _listenToPGNNames.Keys;
		foreach (string item2 in keys)
		{
			uint item;
			lock (base.PCLConnection)
			{
				item = base.PCLConnection.createParameterHandle(item2);
			}
			list.Add(item);
		}
		if (_respItr != null)
		{
			_respItr.close();
			_respItr = null;
		}
		lock (base.PCLConnection)
		{
			_respItr = base.PCLConnection.requestGetParameterValues(list, (uint)FigureCorrectUpdatedRate());
		}
		_respItr.Response += PCLRequestResponse;
	}

	protected override void ConnectionLost()
	{
		if (_respItr != null)
		{
			_respItr.close();
			_respItr = null;
		}
		_started = false;
	}

	private int FigureCorrectUpdatedRate()
	{
		double num = (double)_listenToPGNNames.Count / 5.0;
		int val = (int)(num * 1000.0);
		return Math.Max(val, _updateRate);
	}

	private void PCLRequestResponse(object sender)
	{
		ResponseIterator responseIterator = sender as ResponseIterator;
		List<PGNList> list = new List<PGNList>();
		while (responseIterator.nextResponse())
		{
			if (!responseIterator.isPosResponse())
			{
				continue;
			}
			uint posResponseItemCount = responseIterator.getPosResponseItemCount();
			if (posResponseItemCount == 0)
			{
				continue;
			}
			PGNList pGNList = new PGNList();
			for (uint num = 0u; num < posResponseItemCount; num++)
			{
				if (responseIterator.isPosItemResponse((int)num))
				{
					string posResponseItemName = responseIterator.getPosResponseItemName((int)num);
					if (_listenToPGNNames.ContainsKey(posResponseItemName))
					{
						PGN pGN = new PGN();
						pGN.Name = posResponseItemName;
						Value posResponseItemValue = responseIterator.getPosResponseItemValue((int)num);
						pGN.SPNs = BuildSPNList(pGN.Name, posResponseItemValue, _listenToPGNNames[posResponseItemName]);
						pGNList.PGNs.Add(pGN);
					}
				}
			}
			if (pGNList.PGNs.Count > 0)
			{
				pGNList.TimeStamp = responseIterator.getResponseTimestamp();
				pGNList.SourceAddress = _sourceAddress;
				pGNList.DestinationAddress = _toolAddress;
				list.Add(pGNList);
			}
		}
		if (list.Count > 0)
		{
			RaiseDataRefreshEvent(list);
		}
	}
}
public class PerformanceEventArgs : EventArgs
{
	private double elapsedTime;

	public double ElapsedTime
	{
		get
		{
			return elapsedTime;
		}
		set
		{
			elapsedTime = value;
		}
	}
}
public delegate void PerformanceEventHandler(object sender, PerformanceEventArgs e);
public delegate void ConnectionLostEventHandler(object sender, ConnectionEventArgs e);
public delegate void RunLocationChangeEventHandler(object sender, RunLocationChangeEventArgs e);
public delegate void StopBroadCastEventHandler(object sender, StopBroadCastEventArgs e);
public delegate void IDLAutoTransferEventHandler(object sender, IDLAutoTransferBufferEventArgs e);
public delegate void IDLRetrievalRateEventHandler(object sender, IDLRetrievalRateEventArgs e);
public struct MonitoredElement
{
	public int length;

	public AccessMode mode;

	public object location;

	public int offset;
}
public enum AccessMode
{
	Name = 3,
	Address = 1,
	ParameterId = 2
}
public enum NotifyType
{
	Event,
	Message
}
public enum DataAcquisitionType
{
	RequestReceive = 1,
	BAM = 2,
	IDL = 3,
	EDM = 5,
	PublicBroadcast = 6,
	PublicRequestReceive = 7
}
public enum IDLStopType
{
	Stop = 1,
	Center,
	Fill,
	KeyOn
}
public enum TriggerType
{
	EngineSpeed = 1,
	RoadSpeed,
	TurboSpeed,
	Clock,
	Frame,
	ForeGroundActivated,
	CamCrankSpeed,
	Timer
}
public enum InteropMessageReturnType
{
	Yes = 4,
	No = 8,
	Unspecified = -1
}
public enum DataSourceTypeEnum
{
	Unknown,
	ECM,
	ASAM,
	Disk,
	J1939_71
}
public class SubscriptionProvider
{
	private static readonly IAppConfigService _appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));

	public static ISubscription Create(ICalibration calibration)
	{
		ISubscription result = null;
		if (calibration is ICalibrationECM)
		{
			result = Create(calibration as ICalibrationECM);
		}
		else if (calibration is ICalibrationASAM)
		{
			result = Create(calibration as ICalibrationASAM);
		}
		else if (calibration is ICalibrationDisk || calibration is ISubfile)
		{
			result = Create(calibration as ICalibrationDisk);
		}
		return result;
	}

	public static ISubscription Create(ICalibration calibration, DataAcquisitionType dataAcquisitionType, NotifyType NotificationType)
	{
		ISubscription result = null;
		if (dataAcquisitionType == DataAcquisitionType.PublicBroadcast || dataAcquisitionType == DataAcquisitionType.PublicRequestReceive)
		{
			result = Create(calibration as ICalibrationOnline, dataAcquisitionType == DataAcquisitionType.PublicBroadcast);
		}
		else if (calibration is ICalibrationECM)
		{
			result = Create(calibration as ICalibrationECM, dataAcquisitionType, NotificationType);
		}
		else if (calibration is ICalibrationASAM)
		{
			result = Create(calibration as ICalibrationASAM);
		}
		else if (calibration is ICalibrationDisk || calibration is ISubfile)
		{
			result = Create(calibration as ICalibrationDisk);
		}
		return result;
	}

	private static ISubscription Create(ICalibrationDisk calibration)
	{
		return new DiskSubscription(calibration);
	}

	private static ISubscription Create(ISubfile calibration)
	{
		return new DiskSubscription(calibration);
	}

	private static ISubscription Create(ICalibrationASAM calibration)
	{
		return new ASAMSubscription(calibration);
	}

	private static ISubscription Create(ICalibrationECM calibration, DataAcquisitionType dataAcquisitionType, NotifyType NotificationType)
	{
		switch (dataAcquisitionType)
		{
		case DataAcquisitionType.PublicBroadcast:
		{
			string cBFFileName2 = _appConfigService.CBFFileName;
			string appSetting4 = _appConfigService.GetAppSetting(ApplicationSettings.RP1210DllName);
			string appSetting5 = _appConfigService.GetAppSetting(ApplicationSettings.RP1210DeviceID);
			string appSetting6 = _appConfigService.GetAppSetting(ApplicationSettings.J1939ToolAddr);
			return new J1939_71BroadcastSubscription(calibration, appSetting4, appSetting5, appSetting6, cBFFileName2);
		}
		case DataAcquisitionType.PublicRequestReceive:
		{
			string cBFFileName = _appConfigService.CBFFileName;
			string appSetting = _appConfigService.GetAppSetting(ApplicationSettings.RP1210DllName);
			string appSetting2 = _appConfigService.GetAppSetting(ApplicationSettings.RP1210DeviceID);
			string appSetting3 = _appConfigService.GetAppSetting(ApplicationSettings.J1939ToolAddr);
			return new J1939_71Subscription(calibration, appSetting, appSetting2, appSetting3, cBFFileName);
		}
		default:
			return new ECMSubscription(NotificationType, dataAcquisitionType, calibration);
		}
	}

	private static ISubscription Create(ICalibrationOnline calibration, bool isPublicBroadcast)
	{
		string cBFFileName = _appConfigService.CBFFileName;
		string appSetting = _appConfigService.GetAppSetting(ApplicationSettings.RP1210DllName);
		string appSetting2 = _appConfigService.GetAppSetting(ApplicationSettings.RP1210DeviceID);
		string appSetting3 = _appConfigService.GetAppSetting(ApplicationSettings.J1939ToolAddr);
		if (isPublicBroadcast)
		{
			return new J1939_71BroadcastSubscription(calibration, appSetting, appSetting2, appSetting3, cBFFileName);
		}
		return new J1939_71Subscription(calibration, appSetting, appSetting2, appSetting3, cBFFileName);
	}

	private static ISubscription Create(ICalibrationASAM calibration, DataAcquisitionType dataAcquisitionType, NotifyType NotificationType)
	{
		return new ASAMSubscription(calibration);
	}

	private static ISubscription Create(ICalibrationDisk calibration, DataAcquisitionType dataAcquisitionType, NotifyType NotificationType)
	{
		return new DiskSubscription(calibration);
	}

	private static ISubscription Create(ISubfile calibration, DataAcquisitionType dataAcquisitionType, NotifyType NotificationType)
	{
		return new DiskSubscription(calibration);
	}
}
