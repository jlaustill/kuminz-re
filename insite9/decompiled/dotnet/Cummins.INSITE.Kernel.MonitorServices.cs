using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using System.Threading;
using System.Xml;
using Cummins.INSITE.Kernel.CommunicationServices;
using Cummins.INSITE.Kernel.ECMServicesAPI;
using Cummins.INSITE.Kernel.ECMServicesCommonTypes;
using Cummins.INSITE.Kernel.EvaluatorServices;
using Cummins.INSITE.Kernel.MetadataServices;
using Cummins.INSITE.Kernel.MonitorServices.LogFiles;
using eIOTCwgtN7fvJXNYMS;
using eoP53YVgQa1lbB0Xy6;

[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: InternalsVisibleTo("MonitorServicesUnitTest")]
[assembly: ComVisible(true)]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: AssemblyDelaySign(false)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyTrademark("")]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyProduct("Cummins.INSITE.Kernel.MonitorServices")]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyConfiguration("")]
[assembly: Guid("a8d12778-fd11-45ee-86ff-31b9cb36f7e2")]
[assembly: AssemblyTitle("Cummins.INSITE.Kernel.MonitorServices")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyVersion("7.6.0.272")]
internal static class J935KHQTmg7bS1F604
{
}
namespace Cummins.INSITE.Kernel.MonitorServices
{
	internal static class Utilities
	{
		private static IConnections I0MNGp3Bt;

		private static IMetadataServices aEpZfV70O;

		private static IParameterMetadataProvider XZ0vP6gOA;

		[CompilerGenerated]
		private static IConnector agqb8yiZc;

		public static IConnector Connector
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return agqb8yiZc;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				agqb8yiZc = value;
			}
		}

		public static IConnections Connections
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return I0MNGp3Bt;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				I0MNGp3Bt = value;
			}
		}

		public static IMetadataServices MetadataServices
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return aEpZfV70O;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				aEpZfV70O = value;
			}
		}

		public static IParameterMetadataProvider ParameterMetadataProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return XZ0vP6gOA;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				XZ0vP6gOA = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static IConnection GetConnection(int connectionId)
		{
			return Connections.Get(connectionId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static ISystem GetSystem(int connectionId)
		{
			IConnection connection = Connections.Get(connectionId);
			return connection.Systems[0];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static int GetSourceAddress(int connectionId, int ecuId)
		{
			IConnection connection = Connections.Get(connectionId);
			return connection.Systems[0].GetECU(ecuId).SourceAddress;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static ConnectionType GetConnectionType(int connectionId)
		{
			IConnection connection = Connections.Get(connectionId);
			return connection.ConnectionType;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static Protocol GetProtocolForParameter(int connectionId, int parameterId, out object parameterObject)
		{
			Protocol protocol = Protocol.ICL;
			parameterObject = parameterId;
			switch (GetConnectionType(connectionId))
			{
			case ConnectionType.Image:
				protocol = Protocol.Image;
				parameterObject = parameterId;
				break;
			case ConnectionType.Simulator:
				protocol = Protocol.ICL;
				parameterObject = parameterId;
				break;
			default:
				protocol = ParameterMetadataProvider.GetProtocolForParameter(parameterId);
				if (protocol == Protocol.ICL)
				{
					parameterObject = parameterId;
				}
				else
				{
					parameterObject = ParameterMetadataProvider.GetParameterConfigName(parameterId);
				}
				break;
			}
			return protocol;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static int GetParameterId(string parameter)
		{
			int result = 0;
			if (parameter != null && !int.TryParse(parameter, out result))
			{
				try
				{
					result = ParameterMetadataProvider.GetParameterId(parameter);
				}
				catch
				{
				}
			}
			return result;
		}
	}
	internal class ParameterPoller
	{
		private int Bsh74uRNF;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ParameterPoller(int connectionId)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			base..ctor();
			Bsh74uRNF = connectionId;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void BeginParameterPolling(MonitoredParameter parameter)
		{
			IReader reader = Utilities.Connector.GetReader(Bsh74uRNF);
			int parameterValueAsync = reader.GetParameterValueAsync(parameter.ParameterObject, parameter.SourceAddress, parameter.Protocol, parameter.SamplingRate, parameter.OnReadComplete);
			parameter.RequestId = parameterValueAsync;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void EndParameterPolling(MonitoredParameter parameter)
		{
			IReader reader = Utilities.Connector.GetReader(Bsh74uRNF);
			reader.CancelAsyncRequest(parameter.RequestId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void BeginGroupPolling(MonitoredGroup group)
		{
			IReader reader = Utilities.Connector.GetReader(Bsh74uRNF);
			int parameterValuesAsync = reader.GetParameterValuesAsync(group.Parameters, group.SourceAddress, group.Protocol, group.SamplingRate, group.OnReadComplete);
			group.RequestId = parameterValuesAsync;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void EndGroupPolling(MonitoredGroup group)
		{
			IReader reader = Utilities.Connector.GetReader(Bsh74uRNF);
			reader.CancelAsyncRequest(group.RequestId);
		}
	}
	internal abstract class Logfile : DisposableObject
	{
		public abstract event EventHandler LowDiskSpace;

		public abstract void AddHeaderInfo(string itemName, string itemValue);

		public abstract void AddECUInformation(IDictionary<int, int> ecuInfo);

		public abstract void AddSample(int ecuId, int parameterId, object value, DateTime timestamp, int sourceAddress);

		public abstract void AddLoggingResumedNotification(DateTime lastPausedTime, TimeSpan pauseDuration);

		public abstract void AddEvent(int eventId, DateTime timestamp, string description);

		public abstract void AddParameterRemovedNotification(DateTime timestamp, int parameterId, int sourceAddress);

		public abstract void Save();

		public abstract void SaveTo(string outputFileName);

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected Logfile()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			base..ctor();
		}
	}
	public class MonitorServices : IMonitorServices
	{
		private IDataServices YNEE2nyB4;

		private IConnector LEZLklU09;

		private Dictionary<int, MonitorService> s3CfX8h7K;

		private IParameterFactory Tl0yAtB98;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MonitorServices(IDataServices dataServices, IConnections connections, IConnector connector, IMetadataServices metadataServices, IParameterMetadataProvider parameterMetadataProvider, IParameterFactory parameterFactory)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			base..ctor();
			YNEE2nyB4 = dataServices;
			LEZLklU09 = connector;
			Tl0yAtB98 = parameterFactory;
			Utilities.Connections = connections;
			Utilities.MetadataServices = metadataServices;
			Utilities.ParameterMetadataProvider = parameterMetadataProvider;
			Utilities.Connector = LEZLklU09;
			s3CfX8h7K = new Dictionary<int, MonitorService>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IMonitorService Add(int connectionId)
		{
			IECUDataService dataService = YNEE2nyB4.AddECUDataService(connectionId);
			MonitoredParameterManager manager = MonitoredParameterManager.GetManager(connectionId);
			manager.ParameterPoller = new ParameterPoller(connectionId);
			MonitorService monitorService = new MonitorService(connectionId, dataService, Tl0yAtB98, manager);
			s3CfX8h7K.Add(monitorService.Id, monitorService);
			return monitorService;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IMonitorService Get(int monitorServiceId)
		{
			return s3CfX8h7K[monitorServiceId];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Remove(int monitorServiceId)
		{
			if (s3CfX8h7K.ContainsKey(monitorServiceId))
			{
				if (s3CfX8h7K[monitorServiceId].IsActive)
				{
					throw new ECMServicesException(ECMServicesErrorCodes.MonitoringIsActive);
				}
				YNEE2nyB4.Remove(s3CfX8h7K[monitorServiceId].DataService.Id);
				s3CfX8h7K.Remove(monitorServiceId);
			}
		}
	}
	[ComSourceInterfaces(typeof(IMonitorEvents))]
	internal class MonitorService : IMonitorService
	{
		private static int khvAmpemH;

		private int mhrnnVbtA;

		private int UMY3nRLf8;

		private IECUDataService A7N5NUhAO;

		private Monitor rTVm3iRJS;

		private Logger xnhDCgT3S;

		private CustomTriggerManager ppMO6pybM;

		public IDataService DataService
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return A7N5NUhAO;
			}
		}

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return mhrnnVbtA;
			}
		}

		public bool IsActive
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return rTVm3iRJS.IsActive;
			}
		}

		public ILogger Logger
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return xnhDCgT3S;
			}
		}

		public ICustomTriggerManager CustomTriggerManager
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ppMO6pybM;
			}
		}

		public event EventHandler<DisplayValueUpdatedEventArgs> DisplayValueUpdated
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				rTVm3iRJS.DisplayValueUpdated += value;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				rTVm3iRJS.DisplayValueUpdated -= value;
			}
		}

		public event EventHandler<RawValueUpdatedEventArgs> RawValueUpdated
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				rTVm3iRJS.RawValueUpdated += value;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				rTVm3iRJS.RawValueUpdated -= value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MonitorService(int connectionId, IECUDataService dataService, IParameterFactory parameterFactory, MonitoredParameterManager parameterManager)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			base..ctor();
			mhrnnVbtA = khvAmpemH++;
			UMY3nRLf8 = connectionId;
			A7N5NUhAO = dataService;
			rTVm3iRJS = new Monitor(mhrnnVbtA, UMY3nRLf8, parameterFactory, parameterManager);
			xnhDCgT3S = new Logger(rTVm3iRJS);
			ppMO6pybM = new CustomTriggerManager(rTVm3iRJS);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> AddGroup(IParameterGroup groupForMonitoring, int ECUId, int samplingRate, TriggerType triggerType)
		{
			if (groupForMonitoring.Count > 0)
			{
				rTVm3iRJS.AddGroup(groupForMonitoring, ECUId, samplingRate, triggerType, notifyClients: true);
			}
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddParameter(int parameterId, int ECUId, int samplingRate, TriggerType triggerType)
		{
			A7N5NUhAO.ECUId = ECUId;
			if (A7N5NUhAO.IsReadBlocked(parameterId))
			{
				throw new ECMServicesException(ECMServicesErrorCodes.ParameterReadBlocked);
			}
			rTVm3iRJS.AddParameter(parameterId, ECUId, samplingRate, triggerType, notifyClients: true);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void RemoveGroup(IParameterGroup monitoredParameters, int ECUId)
		{
			rTVm3iRJS.RemoveGroup(monitoredParameters, ECUId, notifyClients: true);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void RemoveGroupForModule(int ECUId)
		{
			rTVm3iRJS.RemoveGroup(ECUId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void RemoveParameter(int parameterId, int ECUId)
		{
			rTVm3iRJS.RemoveParameter(parameterId, ECUId, notifyClients: true);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void StartMonitoring()
		{
			rTVm3iRJS.StartMonitoring();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void StopMonitoring()
		{
			rTVm3iRJS.StopMonitoring();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static MonitorService()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			khvAmpemH = 1;
		}
	}
	internal abstract class MonitoredItem
	{
		private static readonly int EORpX6YnV;

		protected int _ecuId;

		protected int _sourceAddress;

		protected Protocol _protocol;

		protected int _referenceCount;

		protected int _requestId;

		protected Dictionary<int, ClientInfo> _clientsInfo;

		protected int _effectiveSamplingRate;

		public int ReferenceCount
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _referenceCount;
			}
		}

		public int SourceAddress
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _sourceAddress;
			}
		}

		public int SamplingRate
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _effectiveSamplingRate;
			}
		}

		public Protocol Protocol
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _protocol;
			}
		}

		public int RequestId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _requestId;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				_requestId = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected MonitoredItem(int ecuId, int sourceAddress, Protocol protocol)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			base..ctor();
			_referenceCount = 0;
			_clientsInfo = new Dictionary<int, ClientInfo>();
			_ecuId = ecuId;
			_sourceAddress = sourceAddress;
			_protocol = protocol;
		}

		public abstract void OnReadComplete(int requestId, bool requestSuccessful, object result);

		protected abstract void FireEventToClient(ClientInfo clientInfo);

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddClient(int clientId, TriggerType triggerType, int samplingRate, ValueUpdatedDelegate valueUpdatedCallback, ReadCompleteDelegate readCompleteCallback, CustomTriggerManager customTriggerManager)
		{
			ClientInfo value = new ClientInfo(clientId, triggerType, samplingRate, valueUpdatedCallback, readCompleteCallback, customTriggerManager);
			if (!_clientsInfo.ContainsKey(clientId))
			{
				_clientsInfo.Add(clientId, value);
				_referenceCount++;
			}
			Update();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void RemoveClient(int clientId)
		{
			_clientsInfo.Remove(clientId);
			_referenceCount--;
			Update();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ForceFireEventToClient(int clientId)
		{
			if (_clientsInfo.ContainsKey(clientId))
			{
				FireEventToClient(_clientsInfo[clientId]);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void Update()
		{
			_effectiveSamplingRate = int.MaxValue;
			foreach (ClientInfo value in _clientsInfo.Values)
			{
				if (_effectiveSamplingRate > value.SamplingRate)
				{
					_effectiveSamplingRate = value.SamplingRate;
				}
			}
			if (_effectiveSamplingRate < EORpX6YnV)
			{
				_effectiveSamplingRate = EORpX6YnV;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual bool IsTriggerMet(ClientInfo clientInfo, DateTime currentTime, int parameterId, IParameterValue oldValue, IParameterValue newValue, out int customTriggerId)
		{
			bool flag = false;
			customTriggerId = 0;
			if (clientInfo.LastEventFiredTime.AddMilliseconds(clientInfo.SamplingRate) < currentTime)
			{
				clientInfo.LastEventFiredTime = currentTime;
				flag = ((clientInfo.TriggerType == TriggerType.All || (clientInfo.TriggerType & TriggerType.Periodic) == TriggerType.Periodic) ? true : false);
				flag = !flag && (clientInfo.TriggerType & TriggerType.ValueChanged) == TriggerType.ValueChanged && !ParameterValue.AreEqual(newValue, oldValue);
				if (!flag && clientInfo.TriggerManager != null && (clientInfo.TriggerType & TriggerType.Custom) == TriggerType.Custom)
				{
					flag = clientInfo.TriggerManager.Evaluate(_ecuId, parameterId, newValue, out customTriggerId);
				}
			}
			else
			{
				flag = false;
			}
			return flag;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void FireDataChangedEventToClient(int parameterId, IParameterValue newValue, DateTime currentTime, ClientInfo clientInfo, int customTriggerId)
		{
			clientInfo.ValueUpdatedCallback?.Invoke(parameterId, _ecuId, newValue, currentTime, clientInfo.TriggerType, customTriggerId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void FireReadCompleteEventToClient(int parameterId, DateTime currentTime, ClientInfo clientInfo)
		{
			clientInfo.ReadCompleteCallback?.Invoke(parameterId, _ecuId, currentTime);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static MonitoredItem()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			EORpX6YnV = 250;
		}
	}
	internal class MonitoredGroup : MonitoredItem
	{
		private IParameterGroup S0je7yZUO;

		private List<object> NiYcSJnTc;

		private Dictionary<int, IParameterValue> dw2FR7yfy;

		public IList<object> Parameters
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return NiYcSJnTc;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MonitoredGroup(int ecuId, int sourceAddress, IParameterGroup group, List<object> parameters, Protocol protocol)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			base..ctor(ecuId, sourceAddress, protocol);
			S0je7yZUO = group;
			NiYcSJnTc = parameters;
			dw2FR7yfy = new Dictionary<int, IParameterValue>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void OnReadComplete(int requestId, bool requestSuccessful, object result)
		{
			if (requestSuccessful)
			{
				LIl9O3mCK(result as IParameterValues);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void FireEventToClient(ClientInfo clientInfo)
		{
			DateTime now = DateTime.Now;
			if (S0je7yZUO == null)
			{
				return;
			}
			for (int i = 0; i < S0je7yZUO.Count; i++)
			{
				int num = S0je7yZUO[i];
				if (dw2FR7yfy.ContainsKey(num))
				{
					IParameterValue parameterValue = dw2FR7yfy[num];
					if (parameterValue != null)
					{
						FireDataChangedEventToClient(num, parameterValue, now, clientInfo, 0);
					}
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void LIl9O3mCK(IParameterValues P_0)
		{
			DateTime now = DateTime.Now;
			for (int i = 0; i < P_0.Count; i++)
			{
				IParameterValue parameterValue = P_0[i];
				int parameterId = Utilities.GetParameterId(parameterValue.ParameterAs<string>());
				IParameterValue oldValue = null;
				if (dw2FR7yfy.ContainsKey(parameterId))
				{
					oldValue = dw2FR7yfy[parameterId];
				}
				try
				{
					foreach (ClientInfo value in _clientsInfo.Values)
					{
						if (IsTriggerMet(value, now, parameterId, oldValue, parameterValue, out var customTriggerId))
						{
							FireDataChangedEventToClient(parameterId, parameterValue, now, value, customTriggerId);
						}
						else
						{
							FireReadCompleteEventToClient(parameterId, now, value);
						}
					}
				}
				catch (InvalidOperationException)
				{
					if (_clientsInfo.Count == 0)
					{
						break;
					}
				}
				if (dw2FR7yfy.ContainsKey(parameterId))
				{
					dw2FR7yfy[parameterId] = parameterValue;
				}
				else
				{
					dw2FR7yfy.Add(parameterId, parameterValue);
				}
			}
		}
	}
	internal class MonitoredParameter : MonitoredItem
	{
		private int rNbIkAYZX;

		private object aeaSLNL0m;

		private IParameterValue PHit80arZ;

		public object ParameterObject
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return aeaSLNL0m;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MonitoredParameter(int ecuId, int sourceAddress, int parameterId, object parameterObject, Protocol protocol)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			base..ctor(ecuId, sourceAddress, protocol);
			PHit80arZ = null;
			rNbIkAYZX = parameterId;
			aeaSLNL0m = parameterObject;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void OnReadComplete(int requestId, bool requestSuccessful, object result)
		{
			if (requestSuccessful)
			{
				kI0hppvX2(result as IParameterValue);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void FireEventToClient(ClientInfo clientInfo)
		{
			if (PHit80arZ != null)
			{
				FireDataChangedEventToClient(rNbIkAYZX, PHit80arZ, DateTime.Now, clientInfo, 0);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void kI0hppvX2(IParameterValue P_0)
		{
			try
			{
				DateTime now = DateTime.Now;
				foreach (ClientInfo value in _clientsInfo.Values)
				{
					if (IsTriggerMet(value, now, rNbIkAYZX, PHit80arZ, P_0, out var customTriggerId))
					{
						FireDataChangedEventToClient(rNbIkAYZX, P_0, now, value, customTriggerId);
					}
					else
					{
						FireReadCompleteEventToClient(rNbIkAYZX, now, value);
					}
				}
				PHit80arZ = P_0;
			}
			catch (InvalidOperationException)
			{
			}
		}
	}
	internal class CustomTrigger : ICustomTrigger
	{
		public int ECUId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				throw new NotImplementedException();
			}
		}

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				throw new NotImplementedException();
			}
		}

		public int OperandParameterId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				throw new NotImplementedException();
			}
		}

		public CustomTriggerOperandType OperandType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				throw new NotImplementedException();
			}
		}

		public object OperandValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				throw new NotImplementedException();
			}
		}

		public CustomTriggerOperator Operator
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				throw new NotImplementedException();
			}
		}

		public int ParameterId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				throw new NotImplementedException();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public CustomTrigger()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			base..ctor();
		}
	}
}
namespace Cummins.INSITE.Kernel.MonitorServices.LogFiles
{
	internal class XmlNodeBuilder : XmlTextWriter
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public XmlNodeBuilder(MemoryStream stream)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			((XmlTextWriter)this)..ctor((Stream)stream, (Encoding)null);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override string ToString()
		{
			((XmlWriter)this).Flush();
			using StreamReader streamReader = new StreamReader(((XmlTextWriter)this).BaseStream);
			streamReader.BaseStream.Seek(0L, SeekOrigin.Begin);
			string text = streamReader.ReadToEnd();
			return text + Environment.NewLine;
		}
	}
}
namespace Cummins.INSITE.Kernel.MonitorServices
{
	internal delegate void ValueUpdatedDelegate(int parameterId, int ecuId, object value, DateTime timestamp, TriggerType triggerType, int customTriggerId);
	internal delegate void ReadCompleteDelegate(int parameterId, int ecuId, DateTime timestamp);
	internal class MonitoredParameterManager
	{
		private static Dictionary<int, MonitoredParameterManager> mGUsQaHHe;

		private int I1ARrAlVa;

		private ParameterPoller rqG4bBTPw;

		private Dictionary<int, Dictionary<int, MonitoredParameter>> cvEMetZ0p;

		private Dictionary<int, Dictionary<int, List<MonitoredGroup>>> A33GjDAiA;

		private object W3kixqYDE;

		public ParameterPoller ParameterPoller
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return rqG4bBTPw;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				rqG4bBTPw = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static MonitoredParameterManager()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			mGUsQaHHe = new Dictionary<int, MonitoredParameterManager>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static MonitoredParameterManager GetManager(int connectionId)
		{
			MonitoredParameterManager monitoredParameterManager = null;
			if (mGUsQaHHe.ContainsKey(connectionId))
			{
				monitoredParameterManager = mGUsQaHHe[connectionId];
			}
			else
			{
				monitoredParameterManager = new MonitoredParameterManager(connectionId);
				mGUsQaHHe.Add(connectionId, monitoredParameterManager);
			}
			return monitoredParameterManager;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private MonitoredParameterManager(int connectionId)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			W3kixqYDE = new object();
			base..ctor();
			I1ARrAlVa = connectionId;
			A33GjDAiA = new Dictionary<int, Dictionary<int, List<MonitoredGroup>>>();
			cvEMetZ0p = new Dictionary<int, Dictionary<int, MonitoredParameter>>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddParameter(int clientId, int ecuId, int parameterId, int samplingRate, TriggerType triggerType, ValueUpdatedDelegate valueUpdatedCallback, ReadCompleteDelegate readCompleteCallback, CustomTriggerManager customTriggerManager = null)
		{
			lock (W3kixqYDE)
			{
				STxPt220S(clientId, ecuId, parameterId, samplingRate, triggerType, valueUpdatedCallback, readCompleteCallback, customTriggerManager);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddGroup(int clientId, int ecuId, IParameterGroup group, int samplingRate, TriggerType triggerType, ValueUpdatedDelegate valueUpdatedCallback, ReadCompleteDelegate readCompleteCallback, CustomTriggerManager customTriggerManager = null)
		{
			lock (W3kixqYDE)
			{
				if (!A33GjDAiA.ContainsKey(ecuId))
				{
					A33GjDAiA.Add(ecuId, new Dictionary<int, List<MonitoredGroup>>());
				}
				if (!A33GjDAiA[ecuId].ContainsKey(group.Id))
				{
					gFpuM7l0p(clientId, ecuId, group, samplingRate, triggerType, valueUpdatedCallback, readCompleteCallback, customTriggerManager);
					return;
				}
				RemoveGroup(clientId, ecuId, group);
				gFpuM7l0p(clientId, ecuId, group, samplingRate, triggerType, valueUpdatedCallback, readCompleteCallback, customTriggerManager);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void RemoveParameter(int clientId, int ecuId, int parameterId)
		{
			lock (W3kixqYDE)
			{
				s2VqFC1HU(clientId, ecuId, parameterId);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void RemoveGroup(int clientId, int ecuId, IParameterGroup group)
		{
			lock (W3kixqYDE)
			{
				if (A33GjDAiA.ContainsKey(ecuId) && A33GjDAiA[ecuId].ContainsKey(group.Id))
				{
					List<MonitoredGroup> list = A33GjDAiA[ecuId][group.Id];
					foreach (MonitoredGroup item in list)
					{
						item.RemoveClient(clientId);
						if (item.ReferenceCount == 0)
						{
							rqG4bBTPw.EndGroupPolling(item);
						}
					}
					A33GjDAiA[ecuId].Remove(group.Id);
				}
				ISystem system = Utilities.GetSystem(I1ARrAlVa);
				IECU eCU = system.GetECU(ecuId);
				IUsageDefinition usageDefinition = Utilities.MetadataServices.UsageDefinitions.GetUsageDefinition(eCU.ECUDetectType, 31);
				List<int> list2 = new List<int>(usageDefinition.Parameters);
				foreach (int item2 in group)
				{
					if (list2.Contains(item2))
					{
						s2VqFC1HU(clientId, ecuId, item2);
					}
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ForceFireDataChangedEvent(int clientId)
		{
			lock (W3kixqYDE)
			{
				foreach (Dictionary<int, List<MonitoredGroup>> value in A33GjDAiA.Values)
				{
					foreach (List<MonitoredGroup> value2 in value.Values)
					{
						foreach (MonitoredGroup item in value2)
						{
							item.ForceFireEventToClient(clientId);
						}
					}
				}
				foreach (Dictionary<int, MonitoredParameter> value3 in cvEMetZ0p.Values)
				{
					foreach (MonitoredParameter value4 in value3.Values)
					{
						value4.ForceFireEventToClient(clientId);
					}
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void gFpuM7l0p(int P_0, int P_1, IParameterGroup P_2, int P_3, TriggerType P_4, ValueUpdatedDelegate P_5, ReadCompleteDelegate P_6, CustomTriggerManager P_7)
		{
			List<int> list2;
			List<MonitoredGroup> list = sMJHYgwXS(P_1, P_2, out list2);
			foreach (MonitoredGroup item in list)
			{
				item.AddClient(P_0, P_4, P_3, P_5, P_6, P_7);
				if (!A33GjDAiA[P_1].ContainsKey(P_2.Id))
				{
					A33GjDAiA[P_1].Add(P_2.Id, new List<MonitoredGroup>());
				}
				A33GjDAiA[P_1][P_2.Id].Add(item);
				rqG4bBTPw.BeginGroupPolling(item);
			}
			foreach (int item2 in list2)
			{
				STxPt220S(P_0, P_1, item2, P_3, P_4, P_5, P_6, P_7);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void STxPt220S(int P_0, int P_1, int P_2, int P_3, TriggerType P_4, ValueUpdatedDelegate P_5, ReadCompleteDelegate P_6, CustomTriggerManager P_7)
		{
			if (!cvEMetZ0p.ContainsKey(P_1))
			{
				cvEMetZ0p.Add(P_1, new Dictionary<int, MonitoredParameter>());
			}
			if (!cvEMetZ0p[P_1].ContainsKey(P_2))
			{
				MonitoredParameter monitoredParameter = mUE6rBlWK(P_1, P_2);
				monitoredParameter.AddClient(P_0, P_4, P_3, P_5, P_6, P_7);
				cvEMetZ0p[P_1].Add(P_2, monitoredParameter);
				rqG4bBTPw.BeginParameterPolling(monitoredParameter);
			}
			else
			{
				cvEMetZ0p[P_1][P_2].AddClient(P_0, P_4, P_3, P_5, P_6, P_7);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void s2VqFC1HU(int P_0, int P_1, int P_2)
		{
			if (cvEMetZ0p.ContainsKey(P_1) && cvEMetZ0p[P_1].ContainsKey(P_2))
			{
				cvEMetZ0p[P_1][P_2].RemoveClient(P_0);
				if (cvEMetZ0p[P_1][P_2].ReferenceCount == 0)
				{
					rqG4bBTPw.EndParameterPolling(cvEMetZ0p[P_1][P_2]);
					cvEMetZ0p[P_1].Remove(P_2);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private MonitoredParameter mUE6rBlWK(int P_0, int P_1)
		{
			object parameterObject = null;
			Protocol protocolForParameter = Utilities.GetProtocolForParameter(I1ARrAlVa, P_1, out parameterObject);
			int sourceAddress = Utilities.GetSourceAddress(I1ARrAlVa, P_0);
			return new MonitoredParameter(P_0, sourceAddress, P_1, parameterObject, protocolForParameter);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private List<MonitoredGroup> sMJHYgwXS(int P_0, IParameterGroup P_1, out List<int> P_2)
		{
			ISystem system = Utilities.GetSystem(I1ARrAlVa);
			IECU eCU = system.GetECU(P_0);
			IUsageDefinition usageDefinition = Utilities.MetadataServices.UsageDefinitions.GetUsageDefinition(eCU.ECUDetectType, 31);
			List<int> list = new List<int>(usageDefinition.Parameters);
			P_2 = new List<int>();
			List<MonitoredGroup> list2 = new List<MonitoredGroup>();
			Protocol protocol = Protocol.ICL;
			Dictionary<Protocol, List<object>> dictionary = new Dictionary<Protocol, List<object>>();
			Dictionary<Protocol, IParameterGroup> dictionary2 = new Dictionary<Protocol, IParameterGroup>();
			foreach (int item2 in P_1)
			{
				if (list.Contains(item2))
				{
					P_2.Add(item2);
					continue;
				}
				object parameterObject = null;
				protocol = Utilities.GetProtocolForParameter(I1ARrAlVa, item2, out parameterObject);
				if (!dictionary.ContainsKey(protocol))
				{
					dictionary.Add(protocol, new List<object>());
				}
				if (!dictionary2.ContainsKey(protocol))
				{
					dictionary2.Add(protocol, new GroupBuilder().CreateParameterGroup());
				}
				dictionary[protocol].Add(parameterObject);
				dictionary2[protocol].Add(item2);
			}
			int sourceAddress = Utilities.GetSourceAddress(I1ARrAlVa, P_0);
			foreach (KeyValuePair<Protocol, List<object>> item3 in dictionary)
			{
				MonitoredGroup item = new MonitoredGroup(P_0, sourceAddress, dictionary2[item3.Key], item3.Value, item3.Key);
				list2.Add(item);
			}
			return list2;
		}
	}
	internal class CustomTriggers : List<ICustomTrigger>, IList<ICustomTrigger>, ICustomTriggers, ICollection<ICustomTrigger>, IEnumerable, IEnumerable<ICustomTrigger>
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public CustomTriggers()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			base..ctor();
		}
	}
	internal class CustomTriggerManager : ICustomTriggerManager
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public CustomTriggerManager(Monitor monitor)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int AddTriggerWithParameterCheck(int parameterId, int ECUId, CustomTriggerOperator triggerOperator, int operandParameterId)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int AddTriggerWithValueCheck(int parameterId, int ECUId, CustomTriggerOperator triggerOperator, object operandValue)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ICustomTrigger GetTrigger(int triggerId)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ICustomTriggers GetTriggersForParameter(int parameterId, int ECUId)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void RemoveTrigger(int triggerId)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool Evaluate(int ecuId, int parameterId, IParameterValue parameterValue, out int customTriggerId)
		{
			throw new NotImplementedException();
		}
	}
	[ComSourceInterfaces(typeof(ILoggerEvents))]
	internal class Logger : ILogger
	{
		private static readonly string KTXCU3yPN;

		private Monitor v1fQMhFAR;

		private bool je1x97t7C;

		private string oHmdKgkk5;

		private Dictionary<string, string> aFUJKx9FB;

		private Dictionary<int, DateTime> XNqWnsxua;

		private DateTime WC7XDOphq;

		private DateTime qmCjbOovs;

		private Dictionary<DateTime, TimeSpan> ekYrjoYZQ;

		private Logfile klWkdWcxS;

		private int Ae71sQ6PQ;

		private Thread Tq50BoLPS;

		private ManualResetEvent HCEUqmTVb;

		private bool aa78VcS4H;

		private string iMXYe1GVN;

		private EventHandler SSma7sHip;

		public bool IsActive
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return je1x97t7C;
			}
		}

		public string LogFilePath
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return oHmdKgkk5;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				oHmdKgkk5 = value;
			}
		}

		public int AutoWriteFrequency
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Ae71sQ6PQ;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				Ae71sQ6PQ = value;
			}
		}

		public event EventHandler LowDiskSpace
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				EventHandler eventHandler = SSma7sHip;
				EventHandler eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref SSma7sHip, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				EventHandler eventHandler = SSma7sHip;
				EventHandler eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref SSma7sHip, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Logger(Monitor monitor)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			iMXYe1GVN = string.Empty;
			base..ctor();
			v1fQMhFAR = monitor;
			je1x97t7C = false;
			aFUJKx9FB = new Dictionary<string, string>();
			XNqWnsxua = new Dictionary<int, DateTime>();
			Ae71sQ6PQ = 300;
			aa78VcS4H = false;
			ekYrjoYZQ = new Dictionary<DateTime, TimeSpan>();
			Tq50BoLPS = new Thread(oeI2ueRPf);
			HCEUqmTVb = new ManualResetEvent(initialState: true);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddEventDescription(int eventId, string description)
		{
			klWkdWcxS.AddEvent(eventId, XNqWnsxua[eventId], description);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddEventMarker(int eventId)
		{
			XNqWnsxua.Add(eventId, WC7XDOphq);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetHeaderItem(string itemName, string itemValue)
		{
			if (aFUJKx9FB.ContainsKey(itemName))
			{
				aFUJKx9FB[itemName] = itemValue;
			}
			else
			{
				aFUJKx9FB.Add(itemName, itemValue);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetHeaderItems(IDictionary<string, string> headerItems)
		{
			foreach (KeyValuePair<string, string> headerItem in headerItems)
			{
				SetHeaderItem(headerItem.Key, headerItem.Value);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void StartLogging()
		{
			if (aa78VcS4H)
			{
				TimeSpan pauseDuration = DateTime.Now - qmCjbOovs;
				klWkdWcxS.AddLoggingResumedNotification(qmCjbOovs, pauseDuration);
			}
			else
			{
				klWkdWcxS = new XmlLogfile(LogFilePath);
				klWkdWcxS.LowDiskSpace += SBwoLOZfb;
				v1fQMhFAR.MonitorUpdated += M0tVM5Dqo;
				aa78VcS4H = true;
				SetHeaderItem(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(0), LogFilePath);
				ajAwoZPZ3();
			}
			je1x97t7C = true;
			v1fQMhFAR.RawValueUpdated += L5PlvIMBs;
			v1fQMhFAR.ReadComplete += tTPBDwoHG;
			if (!v1fQMhFAR.IsActive)
			{
				v1fQMhFAR.StartMonitoring();
			}
			else
			{
				v1fQMhFAR.ForceFireDataChangedEvent();
			}
			HCEUqmTVb.Reset();
			S5SgTD0J6();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void StopLogging()
		{
			v1fQMhFAR.RawValueUpdated -= L5PlvIMBs;
			v1fQMhFAR.ReadComplete -= tTPBDwoHG;
			HCEUqmTVb.Set();
			je1x97t7C = false;
			qmCjbOovs = DateTime.Now;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SaveLogFile(bool clearCachedData)
		{
			aa78VcS4H = false;
			if (aFUJKx9FB.ContainsKey(XmlLogNodeNames.Comments))
			{
				klWkdWcxS.AddHeaderInfo(XmlLogNodeNames.Comments, aFUJKx9FB[XmlLogNodeNames.Comments]);
			}
			klWkdWcxS.AddHeaderInfo(XmlLogNodeNames.StopTime, DateTime.Now.ToString(KTXCU3yPN));
			v1fQMhFAR.MonitorUpdated -= M0tVM5Dqo;
			klWkdWcxS.SaveTo(oHmdKgkk5);
			klWkdWcxS.LowDiskSpace -= SBwoLOZfb;
			XNqWnsxua.Clear();
			if (clearCachedData)
			{
				klWkdWcxS.Dispose();
				klWkdWcxS = null;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void SBwoLOZfb(object P_0, EventArgs P_1)
		{
			SSma7sHip?.Invoke(P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void L5PlvIMBs(object P_0, RawValueUpdatedEventArgs P_1)
		{
			WC7XDOphq = P_1.Timestamp;
			int sourceAddress = Utilities.GetSourceAddress(v1fQMhFAR.ConnectionId, P_1.ECUId);
			klWkdWcxS.AddSample(P_1.ECUId, P_1.ParameterId, P_1.Value, P_1.Timestamp, sourceAddress);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void tTPBDwoHG(int P_0, int P_1, DateTime P_2)
		{
			WC7XDOphq = P_2;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void M0tVM5Dqo(object P_0, MonitorUpdatedEventArgs P_1)
		{
			if (P_1.UpdateType == MonitorUpdateType.ParameterRemoved && klWkdWcxS != null)
			{
				klWkdWcxS.AddParameterRemovedNotification(DateTime.Now, P_1.ParameterId, P_1.SourceAddress);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void S5SgTD0J6()
		{
			switch (Tq50BoLPS.ThreadState)
			{
			case ThreadState.Unstarted:
				Tq50BoLPS.Start();
				break;
			case ThreadState.Stopped:
				Tq50BoLPS = new Thread(oeI2ueRPf);
				Tq50BoLPS.Start();
				break;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void oeI2ueRPf()
		{
			while (!HCEUqmTVb.WaitOne(Ae71sQ6PQ * 100))
			{
				klWkdWcxS.Save();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void ajAwoZPZ3()
		{
			iMXYe1GVN = DateTime.Now.ToString(KTXCU3yPN);
			SetHeaderItem(XmlLogNodeNames.StartTime, iMXYe1GVN);
			SetHeaderItem(XmlLogNodeNames.TimestampFormat, KTXCU3yPN);
			Dictionary<int, int> eCUInformation = v1fQMhFAR.GetECUInformation();
			klWkdWcxS.AddECUInformation(eCUInformation);
			foreach (KeyValuePair<string, string> item in aFUJKx9FB)
			{
				klWkdWcxS.AddHeaderInfo(item.Key, item.Value);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static Logger()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			KTXCU3yPN = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(32);
		}
	}
	internal enum MonitorUpdateType
	{
		ParameterAdded,
		ParameterRemoved
	}
	internal class MonitorUpdatedEventArgs : EventArgs
	{
		public readonly MonitorUpdateType UpdateType;

		public readonly int ParameterId;

		public readonly int SourceAddress;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MonitorUpdatedEventArgs(MonitorUpdateType updateType, int parameterId, int sourceAddress)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			base..ctor();
			UpdateType = updateType;
			ParameterId = parameterId;
			SourceAddress = sourceAddress;
		}
	}
	internal struct ParameterInfo
	{
		public readonly int ParameterId;

		public readonly int ECUId;

		public readonly int SamplingRate;

		public readonly TriggerType TriggerType;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ParameterInfo(int parameterId, int ecuId, int samplingRate, TriggerType triggerType)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			ParameterId = parameterId;
			ECUId = ecuId;
			SamplingRate = samplingRate;
			TriggerType = triggerType;
		}
	}
	internal struct GroupInfo
	{
		public readonly IParameterGroup ParameterGroup;

		public readonly int ECUId;

		public readonly int SamplingRate;

		public readonly TriggerType TriggerType;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public GroupInfo(IParameterGroup parameterGroup, int ecuId, int samplingRate, TriggerType triggerType)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			ParameterGroup = parameterGroup;
			ECUId = ecuId;
			SamplingRate = samplingRate;
			TriggerType = triggerType;
		}
	}
	internal struct ClientInfo
	{
		public readonly int ClientId;

		public readonly TriggerType TriggerType;

		public readonly int SamplingRate;

		public readonly ValueUpdatedDelegate ValueUpdatedCallback;

		public readonly ReadCompleteDelegate ReadCompleteCallback;

		public readonly CustomTriggerManager TriggerManager;

		private DateTime OPPTKmqd5;

		public DateTime LastEventFiredTime
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return OPPTKmqd5;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				OPPTKmqd5 = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ClientInfo(int clientId, TriggerType triggerType, int samplingRate, ValueUpdatedDelegate valueUpdatedCallback, ReadCompleteDelegate readCompleteCallback, CustomTriggerManager customTriggerManager)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			ClientId = clientId;
			TriggerType = triggerType;
			SamplingRate = samplingRate;
			ValueUpdatedCallback = valueUpdatedCallback;
			ReadCompleteCallback = readCompleteCallback;
			TriggerManager = customTriggerManager;
			OPPTKmqd5 = DateTime.MinValue;
		}
	}
	internal class Monitor
	{
		private int c4eNbGVynb;

		private int tonN7dELjS;

		private bool EQANE1HY2I;

		private MonitoredParameterManager UOYNLq32GB;

		private IParameterFactory dClNfi2O4R;

		private Dictionary<int, Dictionary<int, ParameterInfo>> wswNyoYVX8;

		private Dictionary<int, Dictionary<int, GroupInfo>> ytLNAwTtKw;

		private Dictionary<int, Dictionary<int, ParameterInfo>> XLHNn7xFwv;

		private Dictionary<int, Dictionary<int, GroupInfo>> zGpN35iQY7;

		private EventHandler<DisplayValueUpdatedEventArgs> YeHN5koaIJ;

		private EventHandler<RawValueUpdatedEventArgs> JA9Nmoq8BZ;

		private ReadCompleteDelegate pTbNDtdAtO;

		private EventHandler<MonitorUpdatedEventArgs> BC9NOKdkyg;

		public ConnectionType _currentConnectionType;

		public int ConnectionId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return tonN7dELjS;
			}
		}

		public bool IsActive
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return EQANE1HY2I;
			}
		}

		public event EventHandler<DisplayValueUpdatedEventArgs> DisplayValueUpdated
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				EventHandler<DisplayValueUpdatedEventArgs> eventHandler = YeHN5koaIJ;
				EventHandler<DisplayValueUpdatedEventArgs> eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler<DisplayValueUpdatedEventArgs> value2 = (EventHandler<DisplayValueUpdatedEventArgs>)Delegate.Combine(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref YeHN5koaIJ, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				EventHandler<DisplayValueUpdatedEventArgs> eventHandler = YeHN5koaIJ;
				EventHandler<DisplayValueUpdatedEventArgs> eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler<DisplayValueUpdatedEventArgs> value2 = (EventHandler<DisplayValueUpdatedEventArgs>)Delegate.Remove(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref YeHN5koaIJ, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
		}

		public event EventHandler<RawValueUpdatedEventArgs> RawValueUpdated
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				EventHandler<RawValueUpdatedEventArgs> eventHandler = JA9Nmoq8BZ;
				EventHandler<RawValueUpdatedEventArgs> eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler<RawValueUpdatedEventArgs> value2 = (EventHandler<RawValueUpdatedEventArgs>)Delegate.Combine(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref JA9Nmoq8BZ, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				EventHandler<RawValueUpdatedEventArgs> eventHandler = JA9Nmoq8BZ;
				EventHandler<RawValueUpdatedEventArgs> eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler<RawValueUpdatedEventArgs> value2 = (EventHandler<RawValueUpdatedEventArgs>)Delegate.Remove(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref JA9Nmoq8BZ, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
		}

		public event ReadCompleteDelegate ReadComplete
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				ReadCompleteDelegate readCompleteDelegate = pTbNDtdAtO;
				ReadCompleteDelegate readCompleteDelegate2;
				do
				{
					readCompleteDelegate2 = readCompleteDelegate;
					ReadCompleteDelegate value2 = (ReadCompleteDelegate)Delegate.Combine(readCompleteDelegate2, value);
					readCompleteDelegate = Interlocked.CompareExchange(ref pTbNDtdAtO, value2, readCompleteDelegate2);
				}
				while ((object)readCompleteDelegate != readCompleteDelegate2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				ReadCompleteDelegate readCompleteDelegate = pTbNDtdAtO;
				ReadCompleteDelegate readCompleteDelegate2;
				do
				{
					readCompleteDelegate2 = readCompleteDelegate;
					ReadCompleteDelegate value2 = (ReadCompleteDelegate)Delegate.Remove(readCompleteDelegate2, value);
					readCompleteDelegate = Interlocked.CompareExchange(ref pTbNDtdAtO, value2, readCompleteDelegate2);
				}
				while ((object)readCompleteDelegate != readCompleteDelegate2);
			}
		}

		public event EventHandler<MonitorUpdatedEventArgs> MonitorUpdated
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				EventHandler<MonitorUpdatedEventArgs> eventHandler = BC9NOKdkyg;
				EventHandler<MonitorUpdatedEventArgs> eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler<MonitorUpdatedEventArgs> value2 = (EventHandler<MonitorUpdatedEventArgs>)Delegate.Combine(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref BC9NOKdkyg, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				EventHandler<MonitorUpdatedEventArgs> eventHandler = BC9NOKdkyg;
				EventHandler<MonitorUpdatedEventArgs> eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler<MonitorUpdatedEventArgs> value2 = (EventHandler<MonitorUpdatedEventArgs>)Delegate.Remove(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref BC9NOKdkyg, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Monitor(int Id, int connectionId, IParameterFactory parameterFactory, MonitoredParameterManager parameterManager)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			base..ctor();
			c4eNbGVynb = Id;
			tonN7dELjS = connectionId;
			dClNfi2O4R = parameterFactory;
			UOYNLq32GB = parameterManager;
			EQANE1HY2I = false;
			wswNyoYVX8 = new Dictionary<int, Dictionary<int, ParameterInfo>>();
			ytLNAwTtKw = new Dictionary<int, Dictionary<int, GroupInfo>>();
			XLHNn7xFwv = new Dictionary<int, Dictionary<int, ParameterInfo>>();
			zGpN35iQY7 = new Dictionary<int, Dictionary<int, GroupInfo>>();
			_currentConnectionType = Utilities.GetConnectionType(tonN7dELjS);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddGroup(IParameterGroup groupForMonitoring, int ECUId, int samplingRate, TriggerType triggerType, bool notifyClients)
		{
			if (EQANE1HY2I)
			{
				if (groupForMonitoring.Count > 0)
				{
					UOYNLq32GB.AddGroup(c4eNbGVynb, ECUId, groupForMonitoring, samplingRate, triggerType, UJwNZqp5tK, wtBNvxRmfi);
				}
				if (!zGpN35iQY7.ContainsKey(ECUId))
				{
					zGpN35iQY7.Add(ECUId, new Dictionary<int, GroupInfo>());
				}
				if (!zGpN35iQY7[ECUId].ContainsKey(groupForMonitoring.Id))
				{
					zGpN35iQY7[ECUId].Add(groupForMonitoring.Id, new GroupInfo(groupForMonitoring, ECUId, samplingRate, triggerType));
				}
				if (!notifyClients)
				{
					return;
				}
				{
					foreach (int item in groupForMonitoring)
					{
						heLNNN0vcI(MonitorUpdateType.ParameterAdded, item, ECUId);
					}
					return;
				}
			}
			if (!ytLNAwTtKw.ContainsKey(ECUId) || !ytLNAwTtKw[ECUId].ContainsKey(groupForMonitoring.Id))
			{
				if (!ytLNAwTtKw.ContainsKey(ECUId))
				{
					ytLNAwTtKw.Add(ECUId, new Dictionary<int, GroupInfo>());
				}
				ytLNAwTtKw[ECUId].Add(groupForMonitoring.Id, new GroupInfo(groupForMonitoring, ECUId, samplingRate, triggerType));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddParameter(int parameterId, int ECUId, int samplingRate, TriggerType triggerType, bool notifyClients)
		{
			if (EQANE1HY2I)
			{
				UOYNLq32GB.AddParameter(c4eNbGVynb, ECUId, parameterId, samplingRate, triggerType, UJwNZqp5tK, wtBNvxRmfi);
				if (!XLHNn7xFwv.ContainsKey(ECUId))
				{
					XLHNn7xFwv.Add(ECUId, new Dictionary<int, ParameterInfo>());
				}
				if (!XLHNn7xFwv[ECUId].ContainsKey(parameterId))
				{
					XLHNn7xFwv[ECUId].Add(parameterId, new ParameterInfo(parameterId, ECUId, samplingRate, triggerType));
				}
				if (notifyClients)
				{
					heLNNN0vcI(MonitorUpdateType.ParameterAdded, parameterId, ECUId);
				}
			}
			else if (!wswNyoYVX8.ContainsKey(ECUId) || !wswNyoYVX8[ECUId].ContainsKey(parameterId))
			{
				if (!wswNyoYVX8.ContainsKey(ECUId))
				{
					wswNyoYVX8.Add(ECUId, new Dictionary<int, ParameterInfo>());
				}
				wswNyoYVX8[ECUId].Add(parameterId, new ParameterInfo(parameterId, ECUId, samplingRate, triggerType));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void RemoveGroup(IParameterGroup monitoredParameters, int ECUId, bool notifyClients)
		{
			if (EQANE1HY2I)
			{
				UOYNLq32GB.RemoveGroup(c4eNbGVynb, ECUId, monitoredParameters);
				zGpN35iQY7[ECUId].Remove(monitoredParameters.Id);
				if (!notifyClients)
				{
					return;
				}
				{
					foreach (int monitoredParameter in monitoredParameters)
					{
						heLNNN0vcI(MonitorUpdateType.ParameterRemoved, monitoredParameter, ECUId);
					}
					return;
				}
			}
			if (ytLNAwTtKw.ContainsKey(ECUId) && ytLNAwTtKw[ECUId].ContainsKey(monitoredParameters.Id))
			{
				ytLNAwTtKw[ECUId].Remove(monitoredParameters.Id);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void RemoveGroup(int ECUId)
		{
			if (EQANE1HY2I)
			{
				if (XLHNn7xFwv.ContainsKey(ECUId))
				{
					foreach (ParameterInfo value in XLHNn7xFwv[ECUId].Values)
					{
						RemoveParameter(value.ParameterId, value.ECUId, notifyClients: true);
					}
					XLHNn7xFwv.Remove(ECUId);
				}
				if (!zGpN35iQY7.ContainsKey(ECUId))
				{
					return;
				}
				int num = zGpN35iQY7[ECUId].Values.Count;
				while (num > 0)
				{
					IEnumerator<GroupInfo> enumerator2 = zGpN35iQY7[ECUId].Values.GetEnumerator();
					if (enumerator2.MoveNext())
					{
						RemoveGroup(enumerator2.Current.ParameterGroup, ECUId, notifyClients: true);
						num--;
					}
				}
				zGpN35iQY7.Remove(ECUId);
			}
			else
			{
				if (wswNyoYVX8.ContainsKey(ECUId))
				{
					wswNyoYVX8.Remove(ECUId);
				}
				if (ytLNAwTtKw.ContainsKey(ECUId))
				{
					ytLNAwTtKw.Remove(ECUId);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void RemoveParameter(int parameterId, int ECUId, bool notifyClients)
		{
			IParameterGroup parameterGroup = null;
			GroupInfo groupInfo = default(GroupInfo);
			if (EQANE1HY2I)
			{
				if (XLHNn7xFwv.ContainsKey(ECUId) && XLHNn7xFwv[ECUId].ContainsKey(parameterId))
				{
					XLHNn7xFwv[ECUId].Remove(parameterId);
					UOYNLq32GB.RemoveParameter(c4eNbGVynb, ECUId, parameterId);
				}
				else if (zGpN35iQY7.ContainsKey(ECUId))
				{
					foreach (GroupInfo value in zGpN35iQY7[ECUId].Values)
					{
						if (value.ParameterGroup.Contains(parameterId))
						{
							parameterGroup = value.ParameterGroup;
							groupInfo = value;
							break;
						}
					}
				}
				if (notifyClients)
				{
					heLNNN0vcI(MonitorUpdateType.ParameterRemoved, parameterId, ECUId);
				}
			}
			else if (wswNyoYVX8.ContainsKey(ECUId) && wswNyoYVX8[ECUId].ContainsKey(parameterId))
			{
				wswNyoYVX8[ECUId].Remove(parameterId);
			}
			else if (ytLNAwTtKw.ContainsKey(ECUId))
			{
				foreach (GroupInfo value2 in ytLNAwTtKw[ECUId].Values)
				{
					if (value2.ParameterGroup.Contains(parameterId))
					{
						parameterGroup = value2.ParameterGroup;
						groupInfo = value2;
						break;
					}
				}
			}
			if (parameterGroup != null)
			{
				RemoveGroup(parameterGroup, ECUId, notifyClients: false);
				parameterGroup.Remove(parameterId);
				AddGroup(parameterGroup, ECUId, groupInfo.SamplingRate, groupInfo.TriggerType, notifyClients: false);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void StartMonitoring()
		{
			EQANE1HY2I = true;
			sBpzosAKt();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void StopMonitoring()
		{
			EQANE1HY2I = false;
			aUSNKccgma();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ForceFireDataChangedEvent()
		{
			UOYNLq32GB.ForceFireDataChangedEvent(c4eNbGVynb);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Dictionary<int, int> GetECUInformation()
		{
			Dictionary<int, int> dictionary = new Dictionary<int, int>();
			foreach (ICumminsECU cumminsECU in Utilities.GetSystem(ConnectionId).CumminsECUs)
			{
				dictionary.Add(cumminsECU.SourceAddress, cumminsECU.ECUDetectType);
			}
			return dictionary;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void sBpzosAKt()
		{
			foreach (int key in ytLNAwTtKw.Keys)
			{
				foreach (GroupInfo value in ytLNAwTtKw[key].Values)
				{
					AddGroup(value.ParameterGroup, key, value.SamplingRate, value.TriggerType, notifyClients: true);
				}
				ytLNAwTtKw[key].Clear();
			}
			foreach (int key2 in wswNyoYVX8.Keys)
			{
				foreach (ParameterInfo value2 in wswNyoYVX8[key2].Values)
				{
					AddParameter(value2.ParameterId, key2, value2.SamplingRate, value2.TriggerType, notifyClients: true);
				}
				wswNyoYVX8[key2].Clear();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void aUSNKccgma()
		{
			foreach (int key in zGpN35iQY7.Keys)
			{
				if (!ytLNAwTtKw.ContainsKey(key))
				{
					ytLNAwTtKw.Add(key, new Dictionary<int, GroupInfo>());
				}
				foreach (KeyValuePair<int, GroupInfo> item in zGpN35iQY7[key])
				{
					UOYNLq32GB.RemoveGroup(c4eNbGVynb, key, item.Value.ParameterGroup);
					ytLNAwTtKw[key].Add(item.Key, item.Value);
				}
				zGpN35iQY7[key].Clear();
			}
			foreach (int key2 in XLHNn7xFwv.Keys)
			{
				if (!wswNyoYVX8.ContainsKey(key2))
				{
					wswNyoYVX8.Add(key2, new Dictionary<int, ParameterInfo>());
				}
				foreach (KeyValuePair<int, ParameterInfo> item2 in XLHNn7xFwv[key2])
				{
					UOYNLq32GB.RemoveParameter(c4eNbGVynb, key2, item2.Value.ParameterId);
					wswNyoYVX8[key2].Add(item2.Key, item2.Value);
				}
				XLHNn7xFwv[key2].Clear();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void heLNNN0vcI(MonitorUpdateType P_0, int P_1, int P_2)
		{
			BC9NOKdkyg?.Invoke(this, new MonitorUpdatedEventArgs(P_0, P_1, Utilities.GetSourceAddress(ConnectionId, P_2)));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void UJwNZqp5tK(int P_0, int P_1, object P_2, DateTime P_3, TriggerType P_4, int P_5)
		{
			object paramValue = (P_2 as IParameterValue).ValueAs<object>();
			bool applyDecimalPrecision = _currentConnectionType != ConnectionType.Image;
			IParameter parameter = dClNfi2O4R.UpdateParameter(tonN7dELjS, Utilities.GetSourceAddress(tonN7dELjS, P_1), P_0, paramValue, applyDecimalPrecision);
			try
			{
				JA9Nmoq8BZ?.Invoke(this, new RawValueUpdatedEventArgs(P_0, P_1, parameter.RawValue, P_3, P_4, P_5));
			}
			catch
			{
			}
			try
			{
				YeHN5koaIJ?.Invoke(this, new DisplayValueUpdatedEventArgs(P_0, P_1, parameter.DisplayValue, P_3, P_4, P_5));
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void wtBNvxRmfi(int P_0, int P_1, DateTime P_2)
		{
			try
			{
				pTbNDtdAtO?.Invoke(P_0, P_1, P_2);
			}
			catch
			{
			}
		}
	}
}
namespace Cummins.INSITE.Kernel.MonitorServices.LogFiles
{
	[StructLayout(LayoutKind.Sequential, Size = 1)]
	public struct Constants
	{
		public const int DriveLetter = 3;
	}
	internal static class XmlLogNodeNames
	{
		public const string SourceFileName = "sourceFileName";

		public static readonly string LogFile;

		public static readonly string Session;

		public static readonly string Header;

		public static readonly string Samples;

		public static readonly string Sample;

		public static readonly string ParameterId;

		public static readonly string ParameterValue;

		public static readonly string Timestamp;

		public static readonly string SourceAddress;

		public static readonly string Events;

		public static readonly string Event;

		public static readonly string EventId;

		public static readonly string EventTimestamp;

		public static readonly string EventDescription;

		public static readonly string StartTime;

		public static readonly string StopTime;

		public static readonly string ECU;

		public static readonly string DetectType;

		public static readonly string TimestampFormat;

		public static readonly string Pause;

		public static readonly string PauseTime;

		public static readonly string Duration;

		public static readonly string RemovedParameter;

		public static readonly string Comments;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static XmlLogNodeNames()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			LogFile = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(38);
			Session = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(56);
			Header = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(74);
			Samples = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(90);
			Sample = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(108);
			ParameterId = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(124);
			ParameterValue = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(150);
			Timestamp = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(182);
			SourceAddress = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(204);
			Events = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(234);
			Event = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(250);
			EventId = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(264);
			EventTimestamp = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(282);
			EventDescription = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(314);
			StartTime = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(350);
			StopTime = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(372);
			ECU = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(392);
			DetectType = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(402);
			TimestampFormat = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(426);
			Pause = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(460);
			PauseTime = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(474);
			Duration = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(496);
			RemovedParameter = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(516);
			Comments = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(552);
		}
	}
	internal class XmlLogfile : Logfile
	{
		private XmlTextWriter EUdNeaspUY;

		private string dEVNcGDB9Y;

		private object iYQNFrCoao;

		private EventHandler cyrNhSDQ0T;

		public override event EventHandler LowDiskSpace
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				EventHandler eventHandler = cyrNhSDQ0T;
				EventHandler eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref cyrNhSDQ0T, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				EventHandler eventHandler = cyrNhSDQ0T;
				EventHandler eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref cyrNhSDQ0T, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public XmlLogfile(string filename)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			iYQNFrCoao = new object();
			base..ctor();
			dEVNcGDB9Y = filename;
			ajnNpwiZrK(dEVNcGDB9Y);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void ajnNpwiZrK(string P_0)
		{
			//IL_0034: Unknown result type (might be due to invalid IL or missing references)
			//IL_003e: Expected O, but got Unknown
			//IL_0026: Unknown result type (might be due to invalid IL or missing references)
			//IL_0030: Expected O, but got Unknown
			if (File.Exists(P_0))
			{
				FileStream fileStream = File.OpenWrite(P_0);
				fileStream.Seek(0L, SeekOrigin.End);
				EUdNeaspUY = new XmlTextWriter((Stream)fileStream, (Encoding)null);
			}
			else
			{
				EUdNeaspUY = new XmlTextWriter(P_0, (Encoding)null);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void CleanUp()
		{
			if (EUdNeaspUY != null)
			{
				((XmlWriter)EUdNeaspUY).Close();
				EUdNeaspUY = null;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void AddHeaderInfo(string itemName, string itemValue)
		{
			XmlNodeBuilder xmlNodeBuilder = new XmlNodeBuilder(new MemoryStream());
			((XmlWriter)xmlNodeBuilder).WriteStartElement(itemName);
			((XmlWriter)xmlNodeBuilder).WriteValue(itemValue);
			((XmlWriter)xmlNodeBuilder).WriteEndElement();
			lock (iYQNFrCoao)
			{
				((XmlWriter)EUdNeaspUY).WriteRaw(((object)xmlNodeBuilder).ToString());
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void AddECUInformation(IDictionary<int, int> ecuInfo)
		{
			foreach (KeyValuePair<int, int> item in ecuInfo)
			{
				XmlNodeBuilder xmlNodeBuilder = new XmlNodeBuilder(new MemoryStream());
				((XmlWriter)xmlNodeBuilder).WriteStartElement(XmlLogNodeNames.ECU);
				((XmlWriter)xmlNodeBuilder).WriteAttributeString(XmlLogNodeNames.SourceAddress, item.Key.ToString());
				((XmlWriter)xmlNodeBuilder).WriteAttributeString(XmlLogNodeNames.DetectType, item.Value.ToString());
				((XmlWriter)xmlNodeBuilder).WriteEndElement();
				lock (iYQNFrCoao)
				{
					((XmlWriter)EUdNeaspUY).WriteRaw(((object)xmlNodeBuilder).ToString());
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void AddSample(int ecuId, int parameterId, object value, DateTime timestamp, int sourceAddress)
		{
			if (value != null)
			{
				XmlNodeBuilder xmlNodeBuilder = new XmlNodeBuilder(new MemoryStream());
				((XmlWriter)xmlNodeBuilder).WriteStartElement(XmlLogNodeNames.Sample);
				((XmlWriter)xmlNodeBuilder).WriteStartElement(XmlLogNodeNames.SourceAddress);
				((XmlWriter)xmlNodeBuilder).WriteValue(sourceAddress);
				((XmlWriter)xmlNodeBuilder).WriteEndElement();
				((XmlWriter)xmlNodeBuilder).WriteStartElement(XmlLogNodeNames.ParameterId);
				((XmlWriter)xmlNodeBuilder).WriteValue(parameterId);
				((XmlWriter)xmlNodeBuilder).WriteEndElement();
				((XmlWriter)xmlNodeBuilder).WriteStartElement(XmlLogNodeNames.ParameterValue);
				((XmlWriter)xmlNodeBuilder).WriteValue(value);
				((XmlWriter)xmlNodeBuilder).WriteEndElement();
				((XmlWriter)xmlNodeBuilder).WriteStartElement(XmlLogNodeNames.Timestamp);
				((XmlWriter)xmlNodeBuilder).WriteValue(timestamp.ToString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(572)));
				((XmlWriter)xmlNodeBuilder).WriteEndElement();
				((XmlWriter)xmlNodeBuilder).WriteEndElement();
				lock (iYQNFrCoao)
				{
					((XmlWriter)EUdNeaspUY).WriteRaw(((object)xmlNodeBuilder).ToString());
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void AddLoggingResumedNotification(DateTime lastPausedTime, TimeSpan pauseDuration)
		{
			XmlNodeBuilder xmlNodeBuilder = new XmlNodeBuilder(new MemoryStream());
			((XmlWriter)xmlNodeBuilder).WriteStartElement(XmlLogNodeNames.Pause);
			((XmlWriter)xmlNodeBuilder).WriteAttributeString(XmlLogNodeNames.PauseTime, lastPausedTime.ToString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(578)));
			((XmlWriter)xmlNodeBuilder).WriteAttributeString(XmlLogNodeNames.Duration, pauseDuration.ToString());
			((XmlWriter)xmlNodeBuilder).WriteEndElement();
			lock (iYQNFrCoao)
			{
				((XmlWriter)EUdNeaspUY).WriteRaw(((object)xmlNodeBuilder).ToString());
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void AddParameterRemovedNotification(DateTime timestamp, int parameterId, int sourceAddress)
		{
			XmlNodeBuilder xmlNodeBuilder = new XmlNodeBuilder(new MemoryStream());
			((XmlWriter)xmlNodeBuilder).WriteStartElement(XmlLogNodeNames.RemovedParameter);
			((XmlWriter)xmlNodeBuilder).WriteAttributeString(XmlLogNodeNames.ParameterId, parameterId.ToString());
			((XmlWriter)xmlNodeBuilder).WriteAttributeString(XmlLogNodeNames.SourceAddress, sourceAddress.ToString());
			((XmlWriter)xmlNodeBuilder).WriteAttributeString(XmlLogNodeNames.Timestamp, timestamp.ToString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(584)));
			((XmlWriter)xmlNodeBuilder).WriteEndElement();
			lock (iYQNFrCoao)
			{
				((XmlWriter)EUdNeaspUY).WriteRaw(((object)xmlNodeBuilder).ToString());
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void AddEvent(int eventId, DateTime timestamp, string description)
		{
			XmlNodeBuilder xmlNodeBuilder = new XmlNodeBuilder(new MemoryStream());
			((XmlWriter)xmlNodeBuilder).WriteStartElement(XmlLogNodeNames.Event);
			((XmlWriter)xmlNodeBuilder).WriteStartElement(XmlLogNodeNames.EventId);
			((XmlWriter)xmlNodeBuilder).WriteValue(eventId);
			((XmlWriter)xmlNodeBuilder).WriteEndElement();
			((XmlWriter)xmlNodeBuilder).WriteStartElement(XmlLogNodeNames.EventTimestamp);
			((XmlWriter)xmlNodeBuilder).WriteValue(timestamp.ToString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(590)));
			((XmlWriter)xmlNodeBuilder).WriteEndElement();
			((XmlWriter)xmlNodeBuilder).WriteStartElement(XmlLogNodeNames.EventDescription);
			((XmlWriter)xmlNodeBuilder).WriteValue(description);
			((XmlWriter)xmlNodeBuilder).WriteEndElement();
			((XmlWriter)xmlNodeBuilder).WriteEndElement();
			lock (iYQNFrCoao)
			{
				((XmlWriter)EUdNeaspUY).WriteRaw(((object)xmlNodeBuilder).ToString());
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void Save()
		{
			if (X1AN9dZ4xf())
			{
				if (EUdNeaspUY != null)
				{
					EUdNeaspUY.BaseStream.Flush();
				}
			}
			else
			{
				cyrNhSDQ0T?.Invoke(this, null);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void SaveTo(string outputFileName)
		{
			lock (iYQNFrCoao)
			{
				Save();
				if (dEVNcGDB9Y != outputFileName)
				{
					if (EUdNeaspUY != null)
					{
						((XmlWriter)EUdNeaspUY).Close();
						EUdNeaspUY = null;
					}
					File.Copy(dEVNcGDB9Y, outputFileName, overwrite: true);
					ajnNpwiZrK(dEVNcGDB9Y);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool X1AN9dZ4xf()
		{
			bool result = true;
			DriveInfo[] drives = DriveInfo.GetDrives();
			FileInfo fileInfo = new FileInfo(dEVNcGDB9Y);
			string text = dEVNcGDB9Y.Substring(0, 3);
			DriveInfo[] array = drives;
			foreach (DriveInfo driveInfo in array)
			{
				if (driveInfo.Name == text && fileInfo.Length >= driveInfo.TotalFreeSpace)
				{
					result = false;
					break;
				}
			}
			return result;
		}
	}
}
internal class <Module>{C009FA6C-0AB2-4BFA-A1FD-AB53C2CC59A4}
{
}
namespace eaNnw6oJwxIQQ7FE5G
{
	internal class eILexUWtydOj1ZbkDZ
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module e1WCAykK0;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void xBECH9TT2lXE8(int typemdt)
		{
			Type type = e1WCAykK0.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)e1WCAykK0.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public eILexUWtydOj1ZbkDZ()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static eILexUWtydOj1ZbkDZ()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
			e1WCAykK0 = typeof(eaNnw6oJwxIQQ7FE5G.eILexUWtydOj1ZbkDZ).Assembly.ManifestModule;
		}
	}
}
namespace eIOTCwgtN7fvJXNYMS
{
	internal class emYpxP33xAq8jO8oJ1
	{
		internal class epk4JLxQrEvWi6AHPc : Attribute
		{
			internal class eUElArGanLR6DFu5tm<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public eUElArGanLR6DFu5tm()
				{
					eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			public epk4JLxQrEvWi6AHPc(object P_0)
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
				base..ctor();
			}
		}

		internal class eqCW27S8VxFfnK7ae3
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (e1WCAykK0(Convert.ToBase64String(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).Assembly.GetName().GetPublicKeyToken()), eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(596)) != eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(602))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			internal static string e1WCAykK0(string P_0, string P_1)
			{
				byte[] bytes = Encoding.Unicode.GetBytes(P_0);
				byte[] array = bytes;
				byte[] key = new byte[32]
				{
					82, 102, 104, 110, 32, 77, 24, 34, 118, 181,
					51, 17, 18, 51, 12, 109, 10, 32, 77, 24,
					34, 158, 161, 41, 97, 28, 118, 181, 5, 25,
					1, 88
				};
				MD5 mD = new MD5CryptoServiceProvider();
				byte[] iV = mD.ComputeHash(Encoding.Unicode.GetBytes(P_1));
				MemoryStream memoryStream = new MemoryStream();
				Rijndael rijndael = Rijndael.Create();
				rijndael.Key = key;
				rijndael.IV = iV;
				CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateEncryptor(), CryptoStreamMode.Write);
				cryptoStream.Write(array, 0, array.Length);
				cryptoStream.Close();
				return Convert.ToBase64String(memoryStream.ToArray());
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public eqCW27S8VxFfnK7ae3()
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.uwaCH9TzMjcqN();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint epLVT0LsDNCS2M0vSw([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr ChnyIJy1AcQGhNQdnj();

		internal struct eMo8xctuZSKRfJjCaO
		{
			internal bool e1WCAykK0;

			internal byte[] eopWKtZX1;
		}

		[Flags]
		private enum vGCJW60f7yIhLgd40B
		{

		}

		private static byte[] SCtNVxlkhZ;

		private static byte[] IuiN2DRtTL;

		private static IntPtr BIKNQh8LtH;

		private static object AESNxaStTv;

		private static int QcjNJj96yB;

		internal static epLVT0LsDNCS2M0vSw eWbNGoLe6;

		private static long zcwNkhLARA;

		private static int gvxN1TZFCd;

		private static SortedList UKmNXQQprJ;

		private static int[] UCTNdICPQG;

		private static bool qakNWPRCZf;

		private static byte[] vVkNgcxJLq;

		private static IntPtr C4gN8jTujO;

		private static byte[] ghrNwQkd9Q;

		private static long BXLNr7dDkA;

		private static int TGZNj9EUbF;

		private static bool z88N0p644e;

		internal static Hashtable e712GIHvk;

		internal static epLVT0LsDNCS2M0vSw ebfRCcJMs;

		private static IntPtr LbvNCR6pMO;

		private static int HZyNUSUUXi;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static emYpxP33xAq8jO8oJ1()
		{
			SCtNVxlkhZ = new byte[0];
			vVkNgcxJLq = new byte[0];
			IuiN2DRtTL = new byte[0];
			ghrNwQkd9Q = new byte[0];
			LbvNCR6pMO = IntPtr.Zero;
			BIKNQh8LtH = IntPtr.Zero;
			AESNxaStTv = new string[0];
			UCTNdICPQG = new int[0];
			QcjNJj96yB = 1;
			qakNWPRCZf = false;
			UKmNXQQprJ = new SortedList();
			TGZNj9EUbF = 0;
			BXLNr7dDkA = 0L;
			ebfRCcJMs = null;
			eWbNGoLe6 = null;
			zcwNkhLARA = 0L;
			gvxN1TZFCd = 0;
			z88N0p644e = false;
			HZyNUSUUXi = 0;
			C4gN8jTujO = IntPtr.Zero;
			e712GIHvk = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void gshCH9TSw7CiZ()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		static string eopWKtZX1(int P_0)
		{
			int num = 176;
			byte[] array2 = default(byte[]);
			int num5 = default(int);
			int num3 = default(int);
			byte[] array = default(byte[]);
			int num8 = default(int);
			byte[] array3 = default(byte[]);
			byte[] array4 = default(byte[]);
			int num7 = default(int);
			BinaryReader binaryReader = default(BinaryReader);
			byte[] array6 = default(byte[]);
			int num2 = default(int);
			MemoryStream memoryStream = default(MemoryStream);
			CryptoStream cryptoStream = default(CryptoStream);
			ICryptoTransform transform = default(ICryptoTransform);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array5 = default(byte[]);
			while (true)
			{
				int num6;
				int num4;
				switch (num)
				{
				case 211:
					array2[8] = (byte)num5;
					num6 = 28;
					goto IL_0c17;
				case 322:
					num3 = 105 + 102;
					num = 95;
					break;
				case 172:
					num3 = 135 - 45;
					num4 = 107;
					if (1 == 0)
					{
						goto case 23;
					}
					goto IL_0c1b;
				case 23:
					array[7] = (byte)num8;
					num4 = 0;
					goto IL_0c1b;
				case 75:
					num5 = 36 + 124;
					num6 = 73;
					goto IL_0c17;
				case 192:
					array3[11] = array4[5];
					num6 = 356;
					goto IL_0c17;
				case 49:
					array[12] = 147;
					num4 = 142;
					if (U0K7XudfApNYWsOqBJ())
					{
						goto IL_0c1b;
					}
					goto case 346;
				case 183:
					array[17] = (byte)num7;
					num = 290;
					break;
				case 250:
					array[21] = 195;
					num4 = 21;
					if (A8XN3twHZvFA9XN2Jk())
					{
						goto case 155;
					}
					goto IL_0c1b;
				case 155:
					array[4] = (byte)num7;
					num = 62;
					break;
				case 105:
					array[26] = 104;
					num6 = 133;
					goto IL_0c17;
				case 194:
					array2[3] = (byte)num3;
					num4 = 188;
					if (A8XN3twHZvFA9XN2Jk())
					{
						goto case 6;
					}
					goto IL_0c1b;
				case 6:
					array[20] = 226;
					num = 131;
					break;
				case 79:
					num8 = 22 + 124;
					num4 = 1;
					if (A8XN3twHZvFA9XN2Jk())
					{
						goto case 60;
					}
					goto IL_0c1b;
				case 60:
					num7 = 113 + 0;
					num6 = 162;
					goto IL_0c17;
				case 102:
					array[17] = 136;
					num6 = 34;
					goto IL_0c17;
				case 2:
					num3 = 212 - 70;
					num4 = 194;
					if (1 == 0)
					{
						goto case 55;
					}
					goto IL_0c1b;
				case 55:
					num7 = 113 + 87;
					num = 304;
					break;
				case 93:
					num5 = 124 + 73;
					num4 = 287;
					if (1 == 0)
					{
						goto case 246;
					}
					goto IL_0c1b;
				case 246:
					num3 = 244 - 81;
					num4 = 184;
					goto IL_0c1b;
				case 131:
					array[21] = 91;
					num4 = 86;
					goto IL_0c1b;
				case 95:
					array2[6] = (byte)num3;
					num4 = 119;
					if (A8XN3twHZvFA9XN2Jk())
					{
						goto case 352;
					}
					goto IL_0c1b;
				case 352:
					array[21] = (byte)num7;
					num6 = 200;
					goto IL_0c17;
				case 351:
					array[6] = (byte)num7;
					num = 308;
					break;
				case 286:
					num8 = 193 - 64;
					num4 = 48;
					goto IL_0c1b;
				case 255:
					num8 = 94 + 97;
					num4 = 355;
					if (1 == 0)
					{
						goto case 142;
					}
					goto IL_0c1b;
				case 142:
					num8 = 200 - 66;
					num6 = 70;
					goto IL_0c17;
				case 314:
					array[23] = (byte)num8;
					num4 = 29;
					if (1 == 0)
					{
						goto case 151;
					}
					goto IL_0c1b;
				case 151:
					num3 = 174 - 58;
					num = 112;
					break;
				case 148:
					num5 = 133 + 77;
					num4 = 243;
					if (A8XN3twHZvFA9XN2Jk())
					{
						goto case 92;
					}
					goto IL_0c1b;
				case 92:
					array[18] = (byte)num8;
					num4 = 126;
					if (!A8XN3twHZvFA9XN2Jk())
					{
						goto IL_0c1b;
					}
					goto case 230;
				case 38:
					array = new byte[32];
					num4 = 358;
					if (!U0K7XudfApNYWsOqBJ())
					{
						goto case 84;
					}
					goto IL_0c1b;
				case 84:
					array[22] = (byte)num8;
					num4 = 59;
					if (A8XN3twHZvFA9XN2Jk())
					{
						goto case 343;
					}
					goto IL_0c1b;
				case 343:
					array[10] = 126;
					num6 = 52;
					goto IL_0c17;
				case 47:
					num5 = 16 + 33;
					num4 = 211;
					goto IL_0c1b;
				case 302:
					num8 = 125 + 50;
					num6 = 23;
					goto IL_0c17;
				case 239:
					array[7] = (byte)num8;
					num4 = 320;
					if (!A8XN3twHZvFA9XN2Jk())
					{
						goto IL_0c1b;
					}
					goto case 238;
				case 259:
					array[20] = 92;
					num4 = 140;
					if (U0K7XudfApNYWsOqBJ())
					{
						goto IL_0c1b;
					}
					goto case 115;
				case 261:
					array2[10] = 144;
					num = 75;
					break;
				case 14:
					array[15] = (byte)num8;
					num4 = 147;
					goto IL_0c1b;
				case 170:
				case 277:
					num8 = 219 - 73;
					num = 64;
					break;
				case 266:
					mNAUx6j4BW7yYNGUaw(true);
					num = 179;
					break;
				case 356:
					array3[13] = array4[6];
					num6 = 146;
					goto IL_0c17;
				case 188:
					num5 = 143 - 47;
					num = 237;
					break;
				case 339:
					array2[14] = 164;
					num = 74;
					break;
				case 107:
					array2[2] = (byte)num3;
					num4 = 33;
					goto IL_0c1b;
				case 307:
					array2[7] = (byte)num5;
					num4 = 298;
					if (1 == 0)
					{
						goto case 189;
					}
					goto IL_0c1b;
				case 189:
					array2[5] = 95;
					num6 = 291;
					goto IL_0c17;
				case 76:
					array[4] = (byte)num8;
					num4 = 362;
					if (!A8XN3twHZvFA9XN2Jk())
					{
						goto IL_0c1b;
					}
					goto case 265;
				case 177:
					num8 = 145 - 123;
					num = 323;
					break;
				case 281:
					eAKmPFFDfK0p6S4cNE(binaryReader);
					num = 110;
					break;
				case 53:
					num8 = 204 - 68;
					num4 = 215;
					if (1 == 0)
					{
						goto case 280;
					}
					goto IL_0c1b;
				case 280:
					array2[5] = 203;
					num4 = 151;
					goto IL_0c1b;
				case 196:
					num8 = 113 + 16;
					num4 = 92;
					goto IL_0c1b;
				case 254:
					array[15] = 166;
					num6 = 260;
					goto IL_0c17;
				case 117:
					array2[0] = 154;
					num4 = 164;
					if (false)
					{
						goto case 324;
					}
					goto IL_0c1b;
				case 324:
					array[1] = (byte)num7;
					num6 = 71;
					goto IL_0c17;
				case 186:
					array2[9] = (byte)num3;
					num6 = 67;
					goto IL_0c17;
				case 297:
					array2[1] = (byte)num3;
					num = 340;
					break;
				case 83:
					array[27] = (byte)num8;
					num4 = 228;
					if (1 == 0)
					{
						goto case 157;
					}
					goto IL_0c1b;
				case 157:
					if (array4.Length > 0)
					{
						num = 208;
						break;
					}
					goto case 240;
				case 132:
					array[0] = (byte)num7;
					num4 = 141;
					if (!A8XN3twHZvFA9XN2Jk())
					{
						goto IL_0c1b;
					}
					goto case 78;
				case 143:
					num7 = 157 + 46;
					num4 = 137;
					if (1 == 0)
					{
						goto case 198;
					}
					goto IL_0c1b;
				case 198:
					num5 = 136 - 45;
					num = 296;
					break;
				case 156:
					array[22] = (byte)num7;
					num4 = 145;
					if (false)
					{
						goto case 13;
					}
					goto IL_0c1b;
				case 13:
					if (array4 != null)
					{
						num4 = 157;
						goto IL_0c1b;
					}
					goto case 240;
				case 85:
					array[28] = (byte)num8;
					num4 = 181;
					if (!A8XN3twHZvFA9XN2Jk())
					{
						goto IL_0c1b;
					}
					goto case 68;
				case 160:
					num7 = 119 + 29;
					num4 = 270;
					if (false)
					{
						goto case 18;
					}
					goto IL_0c1b;
				case 18:
					num7 = 94 + 75;
					num4 = 104;
					if (1 == 0)
					{
						goto case 176;
					}
					goto IL_0c1b;
				case 176:
					if (IuiN2DRtTL.Length == 0)
					{
						num = 217;
						break;
					}
					goto case 110;
				case 215:
					array[7] = (byte)num8;
					num6 = 302;
					goto IL_0c17;
				case 159:
					num7 = 208 - 69;
					num6 = 123;
					goto IL_0c17;
				case 152:
					num8 = 235 - 78;
					num4 = 239;
					goto IL_0c1b;
				case 37:
					array2[11] = 89;
					num6 = 42;
					goto IL_0c17;
				case 42:
					num5 = 168 - 56;
					num = 258;
					break;
				case 284:
					num5 = 46 + 72;
					num6 = 303;
					goto IL_0c17;
				case 185:
					array[24] = 207;
					num4 = 329;
					goto IL_0c1b;
				case 285:
					array[26] = (byte)num8;
					num6 = 105;
					goto IL_0c17;
				case 135:
					array2 = new byte[16];
					num4 = 350;
					goto IL_0c1b;
				case 179:
					array6 = (byte[])nZiC5UMmvXoZLQSpa1(binaryReader, (int)dllNZv3nPPlBYeEBNi(kVD90NG1mGPHIC6dWG(binaryReader)));
					num4 = 38;
					if (false)
					{
						goto case 1;
					}
					goto IL_0c1b;
				case 1:
					array[15] = (byte)num8;
					num = 231;
					break;
				case 127:
					array[8] = 163;
					num4 = 108;
					goto IL_0c1b;
				case 256:
					array2[14] = 217;
					num6 = 347;
					goto IL_0c17;
				case 269:
					array2[8] = 95;
					num6 = 332;
					goto IL_0c17;
				case 29:
					array[23] = 29;
					num4 = 182;
					goto IL_0c1b;
				case 249:
					array2[9] = 105;
					num4 = 144;
					if (U0K7XudfApNYWsOqBJ())
					{
						goto IL_0c1b;
					}
					goto case 17;
				case 206:
					num8 = 140 + 49;
					num = 12;
					break;
				case 222:
					array[27] = 41;
					num4 = 359;
					goto IL_0c1b;
				case 121:
					array[14] = 75;
					num6 = 80;
					goto IL_0c17;
				case 342:
					array[11] = 118;
					num6 = 113;
					goto IL_0c17;
				case 205:
					array[5] = (byte)num7;
					num4 = 227;
					if (0 == 0)
					{
						goto IL_0c1b;
					}
					goto case 240;
				case 25:
					array2[10] = 160;
					num4 = 261;
					if (U0K7XudfApNYWsOqBJ())
					{
						goto IL_0c1b;
					}
					goto case 265;
				case 9:
					num8 = 153 - 51;
					num = 285;
					break;
				case 182:
					array[24] = 124;
					num6 = 328;
					goto IL_0c17;
				case 70:
					array[12] = (byte)num8;
					num4 = 60;
					if (A8XN3twHZvFA9XN2Jk())
					{
						goto case 69;
					}
					goto IL_0c1b;
				case 69:
					num8 = 41 + 48;
					num6 = 44;
					goto IL_0c17;
				case 355:
					array[6] = (byte)num8;
					num4 = 346;
					if (1 == 0)
					{
						goto case 344;
					}
					goto IL_0c1b;
				case 344:
					array2[0] = 159;
					num4 = 167;
					if (1 == 0)
					{
						goto case 97;
					}
					goto IL_0c1b;
				case 97:
					array[13] = 124;
					num4 = 325;
					if (false)
					{
						goto case 212;
					}
					goto IL_0c1b;
				case 212:
					num8 = 92 + 26;
					num6 = 76;
					goto IL_0c17;
				case 271:
					array2[14] = 150;
					num = 256;
					break;
				case 247:
					array[30] = 152;
					num = 174;
					break;
				case 77:
					array[19] = (byte)num8;
					num6 = 4;
					goto IL_0c17;
				case 187:
					array[26] = (byte)num8;
					goto case 9;
				default:
					num6 = 9;
					goto IL_0c17;
				case 74:
					num3 = 202 - 67;
					num4 = 251;
					if (0 == 0)
					{
						goto IL_0c1b;
					}
					goto case 274;
				case 274:
					num5 = 134 - 64;
					num = 349;
					break;
				case 104:
					array[2] = (byte)num7;
					num6 = 204;
					goto IL_0c17;
				case 10:
					array[7] = (byte)num7;
					num4 = 278;
					if (0 == 0)
					{
						goto IL_0c1b;
					}
					goto case 292;
				case 292:
					array[1] = (byte)num7;
					num = 330;
					break;
				case 165:
					array[8] = 139;
					num4 = 127;
					if (0 == 0)
					{
						goto IL_0c1b;
					}
					goto case 238;
				case 238:
					array2[10] = (byte)num5;
					num6 = 284;
					goto IL_0c17;
				case 32:
					array[11] = 113;
					num4 = 175;
					if (true)
					{
						goto IL_0c1b;
					}
					goto case 164;
				case 164:
					num3 = 135 - 45;
					num = 335;
					break;
				case 39:
					array[30] = (byte)num7;
					num = 111;
					break;
				case 62:
					array[4] = 113;
					num6 = 136;
					goto IL_0c17;
				case 8:
					num8 = 131 - 43;
					num = 85;
					break;
				case 3:
					array[18] = 162;
					num4 = 30;
					if (0 == 0)
					{
						goto IL_0c1b;
					}
					goto case 315;
				case 315:
					array2[2] = (byte)num5;
					num = 148;
					break;
				case 52:
					array[10] = 6;
					num4 = 342;
					if (0 == 0)
					{
						goto IL_0c1b;
					}
					goto case 310;
				case 310:
					array[16] = 103;
					num4 = 5;
					if (true)
					{
						goto IL_0c1b;
					}
					goto case 26;
				case 26:
					NJn9Lttcwq7vtSAgcw(kVD90NG1mGPHIC6dWG(binaryReader), 0L);
					num = 266;
					break;
				case 264:
					num3 = 94 + 94;
					goto case 282;
				case 360:
					array[29] = 151;
					num = 68;
					break;
				case 325:
					num7 = 9 + 46;
					num = 190;
					break;
				case 230:
					array[29] = 172;
					num4 = 118;
					if (U0K7XudfApNYWsOqBJ())
					{
						goto IL_0c1b;
					}
					goto case 81;
				case 81:
					array2[7] = 209;
					num = 139;
					break;
				case 68:
					num8 = 157 - 52;
					num4 = 311;
					if (U0K7XudfApNYWsOqBJ())
					{
						goto IL_0c1b;
					}
					goto case 332;
				case 332:
					num3 = 223 - 74;
					num4 = 186;
					goto IL_0c1b;
				case 316:
					array2[5] = (byte)num5;
					num4 = 322;
					if (0 == 0)
					{
						goto IL_0c1b;
					}
					goto case 273;
				case 273:
					array2[3] = 206;
					num4 = 43;
					if (!A8XN3twHZvFA9XN2Jk())
					{
						goto IL_0c1b;
					}
					goto case 313;
				case 313:
					array2[0] = (byte)num3;
					num6 = 117;
					goto IL_0c17;
				case 133:
					array[26] = 99;
					num6 = 163;
					goto IL_0c17;
				case 233:
					array[25] = 191;
					num4 = 225;
					if (0 == 0)
					{
						goto IL_0c1b;
					}
					goto case 262;
				case 262:
					array[27] = 134;
					num4 = 114;
					goto IL_0c1b;
				case 288:
					array[5] = (byte)num8;
					num = 279;
					break;
				case 173:
					array2[15] = 94;
					num = 22;
					break;
				case 162:
					array[12] = (byte)num7;
					num4 = 143;
					if (true)
					{
						goto IL_0c1b;
					}
					goto case 228;
				case 228:
					array[27] = 66;
					num = 222;
					break;
				case 333:
					num5 = 241 - 80;
					num = 40;
					break;
				case 163:
					array[26] = 28;
					num4 = 262;
					if (U0K7XudfApNYWsOqBJ())
					{
						goto IL_0c1b;
					}
					goto case 119;
				case 119:
					array2[6] = 159;
					num4 = 274;
					if (U0K7XudfApNYWsOqBJ())
					{
						goto IL_0c1b;
					}
					goto case 245;
				case 191:
					array[17] = (byte)num8;
					num = 235;
					break;
				case 80:
					array[14] = 86;
					num = 177;
					break;
				case 294:
					array2[15] = 50;
					num4 = 100;
					if (true)
					{
						goto IL_0c1b;
					}
					goto case 110;
				case 110:
					num2 = Mf7yXgmRNKb2cUBfeZ(IuiN2DRtTL, P_0);
					num6 = 363;
					goto IL_0c17;
				case 199:
					num3 = 95 + 41;
					num = 91;
					break;
				case 217:
					binaryReader = new BinaryReader((Stream)HJKxIyWS7YaXltWqj4(TkGJXF26ga5X1c1AH2(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).TypeHandle).Assembly, "kkptEBc8N2NqeplFoL.7uLHskveyXs94mTmQ5"));
					num4 = 26;
					goto IL_0c1b;
				case 113:
					array[11] = 105;
					num4 = 299;
					if (0 == 0)
					{
						goto IL_0c1b;
					}
					goto case 321;
				case 321:
					array2[8] = (byte)num5;
					num4 = 269;
					if (U0K7XudfApNYWsOqBJ())
					{
						goto IL_0c1b;
					}
					goto case 134;
				case 275:
					array2[8] = (byte)num3;
					num6 = 47;
					goto IL_0c17;
				case 362:
					num7 = 212 - 70;
					num = 155;
					break;
				case 138:
					array2[9] = (byte)num5;
					num4 = 249;
					if (true)
					{
						goto IL_0c1b;
					}
					goto case 5;
				case 5:
					array[16] = 183;
					num4 = 242;
					if (U0K7XudfApNYWsOqBJ())
					{
						goto IL_0c1b;
					}
					goto case 193;
				case 193:
					array[29] = (byte)num7;
					num4 = 360;
					goto IL_0c1b;
				case 96:
					array[6] = (byte)num8;
					num = 255;
					break;
				case 197:
					array[15] = (byte)num8;
					num = 79;
					break;
				case 331:
					array[6] = (byte)num7;
					num4 = 317;
					if (A8XN3twHZvFA9XN2Jk())
					{
						goto case 188;
					}
					goto IL_0c1b;
				case 291:
					num5 = 124 - 40;
					num4 = 316;
					goto IL_0c1b;
				case 158:
					num7 = 135 - 45;
					num4 = 132;
					goto IL_0c1b;
				case 137:
					array[12] = (byte)num7;
					num4 = 97;
					goto IL_0c1b;
				case 56:
					num8 = 47 + 46;
					num = 77;
					break;
				case 243:
					array2[2] = (byte)num5;
					num = 216;
					break;
				case 202:
					array[0] = 122;
					num6 = 122;
					goto IL_0c17;
				case 103:
					num8 = 183 - 61;
					num6 = 223;
					goto IL_0c17;
				case 319:
					array[6] = 104;
					num6 = 61;
					goto IL_0c17;
				case 278:
					num7 = 31 + 64;
					num6 = 252;
					goto IL_0c17;
				case 349:
					array2[6] = (byte)num5;
					num = 214;
					break;
				case 336:
					array[19] = 108;
					num4 = 56;
					if (U0K7XudfApNYWsOqBJ())
					{
						goto IL_0c1b;
					}
					goto case 207;
				case 207:
					array2[11] = (byte)num5;
					num = 7;
					break;
				case 190:
					array[13] = (byte)num7;
					num6 = 16;
					goto IL_0c17;
				case 213:
					vQu3vt6OAIFWsUbUXw(memoryStream);
					num = 209;
					break;
				case 236:
					array[9] = 192;
					num6 = 244;
					goto IL_0c17;
				case 341:
					array[16] = (byte)num8;
					num4 = 102;
					goto IL_0c1b;
				case 354:
					array[20] = (byte)num7;
					num4 = 259;
					goto IL_0c1b;
				case 161:
					array[18] = (byte)num8;
					num = 168;
					break;
				case 48:
					array[16] = (byte)num8;
					num4 = 310;
					if (U0K7XudfApNYWsOqBJ())
					{
						goto IL_0c1b;
					}
					goto case 309;
				case 50:
					num5 = 114 - 92;
					num4 = 238;
					if (!A8XN3twHZvFA9XN2Jk())
					{
						goto IL_0c1b;
					}
					goto case 108;
				case 108:
					num7 = 49 + 25;
					num6 = 263;
					goto IL_0c17;
				case 0:
					array[8] = 158;
					num6 = 220;
					goto IL_0c17;
				case 359:
					num8 = 234 - 78;
					num4 = 57;
					if (!A8XN3twHZvFA9XN2Jk())
					{
						goto IL_0c1b;
					}
					goto case 112;
				case 112:
					array2[5] = (byte)num3;
					num = 353;
					break;
				case 268:
					array[9] = (byte)num8;
					num6 = 58;
					goto IL_0c17;
				case 245:
					array[0] = (byte)num7;
					num4 = 202;
					if (U0K7XudfApNYWsOqBJ())
					{
						goto IL_0c1b;
					}
					goto case 63;
				case 214:
					num5 = 204 - 68;
					num6 = 307;
					goto IL_0c17;
				case 272:
					cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
					num = 248;
					break;
				case 59:
					num7 = 101 + 119;
					num = 156;
					break;
				case 226:
					num8 = 34 + 79;
					num6 = 96;
					goto IL_0c17;
				case 145:
					num8 = 92 + 78;
					num = 20;
					break;
				case 209:
					vQu3vt6OAIFWsUbUXw(cryptoStream);
					num6 = 281;
					goto IL_0c17;
				case 128:
					array[31] = (byte)num7;
					num6 = 169;
					goto IL_0c17;
				case 305:
					eLDokTNSVGPFCd4hxK(cryptoStream);
					num = 337;
					break;
				case 98:
					array2[3] = 153;
					num4 = 273;
					if (true)
					{
						goto IL_0c1b;
					}
					goto case 31;
				case 31:
					array[16] = 161;
					num4 = 286;
					goto IL_0c1b;
				case 171:
					array2[13] = 30;
					num4 = 198;
					if (!A8XN3twHZvFA9XN2Jk())
					{
						goto IL_0c1b;
					}
					goto case 278;
				case 134:
					array2[4] = (byte)num5;
					num6 = 41;
					goto IL_0c17;
				case 257:
					array3[9] = array4[4];
					num4 = 192;
					if (!A8XN3twHZvFA9XN2Jk())
					{
						goto IL_0c1b;
					}
					goto case 10;
				case 241:
					num7 = 230 - 76;
					num4 = 39;
					if (true)
					{
						goto IL_0c1b;
					}
					goto case 71;
				case 71:
					num8 = 160 - 53;
					num4 = 229;
					if (true)
					{
						goto IL_0c1b;
					}
					goto case 20;
				case 20:
					array[23] = (byte)num8;
					num6 = 219;
					goto IL_0c17;
				case 300:
					num5 = 51 + 72;
					num = 232;
					break;
				case 16:
					array[13] = 80;
					num4 = 121;
					if (true)
					{
						goto IL_0c1b;
					}
					goto case 174;
				case 174:
					num7 = 105 + 110;
					num6 = 149;
					goto IL_0c17;
				case 358:
					num7 = 233 - 77;
					num = 245;
					break;
				case 167:
					num5 = 66 + 35;
					num6 = 15;
					goto IL_0c17;
				case 122:
					array[0] = 170;
					num6 = 158;
					goto IL_0c17;
				case 72:
					array[20] = 142;
					num4 = 160;
					if (U0K7XudfApNYWsOqBJ())
					{
						goto IL_0c1b;
					}
					goto case 133;
				case 7:
					array2[11] = 136;
					num6 = 37;
					goto IL_0c17;
				case 267:
					num8 = 179 - 59;
					num = 14;
					break;
				case 123:
					array[2] = (byte)num7;
					num4 = 51;
					if (U0K7XudfApNYWsOqBJ())
					{
						goto IL_0c1b;
					}
					goto case 134;
				case 283:
					array2[9] = (byte)num3;
					num = 25;
					break;
				case 357:
					array2[10] = (byte)num3;
					num = 50;
					break;
				case 260:
					array[16] = 170;
					num6 = 31;
					goto IL_0c17;
				case 141:
					array[0] = 213;
					num4 = 11;
					if (true)
					{
						goto IL_0c1b;
					}
					goto case 54;
				case 54:
					array[25] = (byte)num8;
					num = 178;
					break;
				case 330:
					num7 = 35 + 102;
					num4 = 253;
					if (U0K7XudfApNYWsOqBJ())
					{
						goto IL_0c1b;
					}
					goto case 48;
				case 298:
					array2[7] = 118;
					num6 = 81;
					goto IL_0c17;
				case 252:
					array[7] = (byte)num7;
					num4 = 53;
					goto IL_0c1b;
				case 140:
					array[20] = 146;
					num4 = 6;
					goto IL_0c1b;
				case 106:
					num8 = 143 - 47;
					num = 288;
					break;
				case 21:
					array[22] = 96;
					num6 = 309;
					goto IL_0c17;
				case 109:
					array2[12] = 22;
					num6 = 153;
					goto IL_0c17;
				case 219:
					array[23] = 102;
					num4 = 78;
					goto IL_0c1b;
				case 328:
					num7 = 245 - 81;
					num4 = 17;
					if (U0K7XudfApNYWsOqBJ())
					{
						goto IL_0c1b;
					}
					goto case 114;
				case 114:
					num8 = 248 - 82;
					num4 = 83;
					goto IL_0c1b;
				case 347:
					array2[15] = 131;
					num4 = 173;
					if (0 == 0)
					{
						goto IL_0c1b;
					}
					goto case 73;
				case 73:
					array2[10] = (byte)num5;
					num4 = 300;
					goto IL_0c1b;
				case 225:
					num8 = 184 - 67;
					num4 = 54;
					if (U0K7XudfApNYWsOqBJ())
					{
						goto IL_0c1b;
					}
					goto case 296;
				case 296:
					array2[13] = (byte)num5;
					num4 = 93;
					goto IL_0c1b;
				case 61:
					num7 = 114 + 0;
					num4 = 331;
					if (0 == 0)
					{
						goto IL_0c1b;
					}
					goto case 293;
				case 293:
					array2[4] = 148;
					num6 = 210;
					goto IL_0c17;
				case 90:
					num7 = 180 - 107;
					num = 324;
					break;
				case 126:
					array[19] = 115;
					num4 = 336;
					goto IL_0c1b;
				case 323:
					array[14] = (byte)num8;
					num4 = 267;
					if (true)
					{
						goto IL_0c1b;
					}
					goto case 301;
				case 301:
					num3 = 242 - 80;
					num4 = 357;
					if (0 == 0)
					{
						goto IL_0c1b;
					}
					goto case 318;
				case 318:
					num7 = 189 - 63;
					num = 128;
					break;
				case 306:
					array[3] = 206;
					num6 = 212;
					goto IL_0c17;
				case 19:
					num8 = 147 - 49;
					num4 = 197;
					if (true)
					{
						goto IL_0c1b;
					}
					goto case 311;
				case 311:
					array[30] = (byte)num8;
					num4 = 247;
					goto IL_0c1b;
				case 22:
					array2[15] = 85;
					num4 = 294;
					if (true)
					{
						goto IL_0c1b;
					}
					goto case 45;
				case 45:
					array2[5] = (byte)num5;
					num6 = 348;
					goto IL_0c17;
				case 99:
					num5 = 230 - 76;
					num4 = 207;
					goto IL_0c1b;
				case 203:
					array3[7] = array4[3];
					num6 = 257;
					goto IL_0c17;
				case 180:
					num5 = 28 + 71;
					num6 = 134;
					goto IL_0c17;
				case 150:
					array[3] = (byte)num7;
					num6 = 124;
					goto IL_0c17;
				case 224:
					array[17] = (byte)num8;
					num6 = 3;
					goto IL_0c17;
				case 348:
					array2[5] = 124;
					num = 189;
					break;
				case 144:
					num3 = 135 - 97;
					num6 = 283;
					goto IL_0c17;
				case 166:
					array2[1] = 130;
					num6 = 289;
					goto IL_0c17;
				case 317:
					num7 = 212 - 70;
					num4 = 351;
					if (0 == 0)
					{
						goto IL_0c1b;
					}
					goto case 125;
				case 125:
					num3 = 176 - 58;
					num4 = 275;
					goto IL_0c1b;
				case 86:
					num7 = 217 - 72;
					num6 = 352;
					goto IL_0c17;
				case 334:
					num7 = 63 + 6;
					num = 354;
					break;
				case 100:
					array3 = array2;
					num4 = 221;
					goto IL_0c1b;
				case 345:
					array[25] = (byte)num8;
					num = 233;
					break;
				case 235:
					num8 = 162 + 12;
					num4 = 224;
					goto IL_0c1b;
				case 204:
					array[2] = 90;
					num4 = 159;
					goto IL_0c1b;
				case 63:
					array[28] = 52;
					num4 = 89;
					if (true)
					{
						goto IL_0c1b;
					}
					goto case 353;
				case 353:
					num5 = 160 - 53;
					num6 = 45;
					goto IL_0c17;
				case 168:
					array[18] = 118;
					num = 196;
					break;
				case 335:
					array2[0] = (byte)num3;
					num = 246;
					break;
				case 223:
					array[4] = (byte)num8;
					num6 = 130;
					goto IL_0c17;
				case 78:
					num8 = 153 - 51;
					num6 = 314;
					goto IL_0c17;
				case 282:
				case 338:
					array2[7] = (byte)num3;
					num4 = 125;
					if (U0K7XudfApNYWsOqBJ())
					{
						goto IL_0c1b;
					}
					goto case 33;
				case 33:
					array2[2] = 80;
					num6 = 199;
					goto IL_0c17;
				case 326:
					array[24] = 126;
					num = 185;
					break;
				case 242:
					num8 = 69 + 106;
					num4 = 341;
					if (true)
					{
						goto IL_0c1b;
					}
					goto case 44;
				case 44:
					array[22] = (byte)num8;
					num6 = 195;
					goto IL_0c17;
				case 88:
					array2[9] = 139;
					num4 = 46;
					goto IL_0c1b;
				case 251:
					array2[14] = (byte)num3;
					num6 = 333;
					goto IL_0c17;
				case 11:
					num7 = 47 + 17;
					num = 292;
					break;
				case 327:
					transform = (ICryptoTransform)aB5bgR8KOwS3EaYJ6A(rijndaelManaged, array5, array3);
					num6 = 295;
					goto IL_0c17;
				case 346:
					array[7] = 108;
					num4 = 152;
					goto IL_0c1b;
				case 89:
					array[29] = 98;
					num4 = 55;
					goto IL_0c1b;
				case 200:
					array[21] = 147;
					num4 = 250;
					if (0 == 0)
					{
						goto IL_0c1b;
					}
					goto case 36;
				case 36:
					array2[12] = 246;
					num4 = 171;
					if (!U0K7XudfApNYWsOqBJ())
					{
						goto case 102;
					}
					goto IL_0c1b;
				case 46:
					num5 = 177 - 59;
					num = 138;
					break;
				case 115:
					array[15] = (byte)num7;
					num = 254;
					break;
				case 234:
					array2[13] = 203;
					num4 = 339;
					if (0 == 0)
					{
						goto IL_0c1b;
					}
					goto case 279;
				case 279:
					num7 = 53 + 27;
					num4 = 205;
					if (!A8XN3twHZvFA9XN2Jk())
					{
						goto IL_0c1b;
					}
					goto case 87;
				case 87:
					array[28] = (byte)num8;
					num4 = 63;
					if (true)
					{
						goto IL_0c1b;
					}
					goto case 12;
				case 12:
					array[27] = (byte)num8;
					num6 = 8;
					goto IL_0c17;
				case 67:
					array2[9] = 148;
					num4 = 88;
					goto IL_0c1b;
				case 289:
					num5 = 90 + 66;
					num4 = 24;
					if (!U0K7XudfApNYWsOqBJ())
					{
						goto case 177;
					}
					goto IL_0c1b;
				case 299:
					array[11] = 107;
					num4 = 32;
					if (!A8XN3twHZvFA9XN2Jk())
					{
						goto IL_0c1b;
					}
					goto case 257;
				case 66:
					array[15] = (byte)num7;
					num4 = 19;
					if (true)
					{
						goto IL_0c1b;
					}
					goto case 290;
				case 290:
					num8 = 197 - 65;
					num4 = 191;
					goto IL_0c1b;
				case 147:
					num7 = 93 + 15;
					num4 = 66;
					if (!U0K7XudfApNYWsOqBJ())
					{
						goto case 23;
					}
					goto IL_0c1b;
				case 208:
					array3[1] = array4[0];
					num4 = 82;
					goto IL_0c1b;
				case 149:
					array[30] = (byte)num7;
					num6 = 241;
					goto IL_0c17;
				case 253:
					array[1] = (byte)num7;
					num4 = 201;
					goto IL_0c1b;
				case 227:
					array[5] = 32;
					num = 319;
					break;
				case 136:
					array[4] = 112;
					num6 = 103;
					goto IL_0c17;
				case 82:
					array3[3] = array4[1];
					num6 = 312;
					goto IL_0c17;
				case 340:
					array2[1] = 41;
					num4 = 172;
					goto IL_0c1b;
				case 221:
					array4 = (byte[])MWDunLOi3cnhqWpT3G(GUJFYeyc2da2tqkhD4(TkGJXF26ga5X1c1AH2(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).TypeHandle).Assembly));
					num6 = 13;
					goto IL_0c17;
				case 41:
					array2[4] = 81;
					num4 = 280;
					if (0 == 0)
					{
						goto IL_0c1b;
					}
					goto case 116;
				case 116:
					num7 = 95 + 41;
					num4 = 150;
					if (true)
					{
						goto IL_0c1b;
					}
					goto case 65;
				case 65:
					array[31] = 118;
					num4 = 318;
					goto IL_0c1b;
				case 231:
					num7 = 140 - 46;
					num4 = 115;
					goto IL_0c1b;
				case 270:
					array[20] = (byte)num7;
					num4 = 334;
					goto IL_0c1b;
				case 146:
					array3[15] = array4[7];
					num4 = 240;
					if (0 == 0)
					{
						goto IL_0c1b;
					}
					goto case 248;
				case 248:
					xOuniNsOgmExe7I1cn(cryptoStream, array6, 0, array6.Length);
					num = 305;
					break;
				case 244:
					array[10] = 120;
					num = 343;
					break;
				case 153:
					array2[12] = 53;
					num4 = 36;
					if (U0K7XudfApNYWsOqBJ())
					{
						goto IL_0c1b;
					}
					goto case 120;
				case 120:
					num5 = 143 - 47;
					num4 = 315;
					if (!A8XN3twHZvFA9XN2Jk())
					{
						goto IL_0c1b;
					}
					goto case 27;
				case 27:
					array2[1] = 74;
					num4 = 129;
					if (0 == 0)
					{
						goto IL_0c1b;
					}
					goto case 263;
				case 263:
					array[9] = (byte)num7;
					num4 = 265;
					if (!U0K7XudfApNYWsOqBJ())
					{
						goto case 324;
					}
					goto IL_0c1b;
				case 276:
					array[31] = 194;
					num = 361;
					break;
				case 232:
					array2[10] = (byte)num5;
					num6 = 301;
					goto IL_0c17;
				case 237:
					array2[3] = (byte)num5;
					num = 98;
					break;
				case 258:
					array2[12] = (byte)num5;
					num6 = 109;
					goto IL_0c17;
				case 130:
					array[4] = 33;
					num6 = 106;
					goto IL_0c17;
				case 40:
					array2[14] = (byte)num5;
					num6 = 271;
					goto IL_0c17;
				case 43:
					num5 = 92 + 58;
					num4 = 35;
					goto IL_0c1b;
				case 118:
					num7 = 25 + 0;
					num4 = 193;
					if (true)
					{
						goto IL_0c1b;
					}
					goto case 201;
				case 201:
					array[1] = 144;
					num6 = 90;
					goto IL_0c17;
				case 361:
					array5 = array;
					num4 = 135;
					if (0 == 0)
					{
						goto IL_0c1b;
					}
					goto case 309;
				case 309:
					num8 = 98 + 63;
					num4 = 101;
					if (true)
					{
						goto IL_0c1b;
					}
					goto case 57;
				case 57:
					array[27] = (byte)num8;
					num4 = 206;
					goto IL_0c1b;
				case 320:
					num7 = 102 + 59;
					num6 = 10;
					goto IL_0c17;
				case 216:
					array2[3] = 118;
					num = 2;
					break;
				case 129:
					num3 = 223 - 74;
					num4 = 297;
					goto IL_0c1b;
				case 175:
					num7 = 228 + 3;
					num = 154;
					break;
				case 265:
					num8 = 33 + 0;
					num = 268;
					break;
				case 329:
					num8 = 86 + 107;
					num = 345;
					break;
				case 184:
					array2[0] = (byte)num3;
					num6 = 344;
					goto IL_0c17;
				case 210:
					array2[4] = 45;
					num4 = 180;
					if (0 == 0)
					{
						goto IL_0c1b;
					}
					goto case 101;
				case 101:
					array[22] = (byte)num8;
					num = 69;
					break;
				case 195:
					num8 = 94 + 6;
					num = 84;
					break;
				case 287:
					array2[13] = (byte)num5;
					num = 234;
					break;
				case 178:
					num8 = 3 + 76;
					num4 = 187;
					if (!A8XN3twHZvFA9XN2Jk())
					{
						goto IL_0c1b;
					}
					goto case 91;
				case 91:
					array2[2] = (byte)num3;
					num = 120;
					break;
				case 218:
					array[6] = (byte)num7;
					num6 = 226;
					goto IL_0c17;
				case 30:
					num8 = 47 + 22;
					num6 = 161;
					goto IL_0c17;
				case 15:
					array2[1] = (byte)num5;
					num6 = 166;
					goto IL_0c17;
				case 24:
					array2[1] = (byte)num5;
					num = 27;
					break;
				case 64:
					array[24] = (byte)num8;
					num = 326;
					break;
				case 304:
					array[29] = (byte)num7;
					num4 = 230;
					goto IL_0c1b;
				case 4:
					array[19] = 151;
					num6 = 72;
					goto IL_0c17;
				case 94:
					x2qSAXnYp8efMr5Fe8(rijndaelManaged, CipherMode.CBC);
					num4 = 327;
					goto IL_0c1b;
				case 111:
					array[30] = 12;
					num6 = 65;
					goto IL_0c17;
				case 220:
					array[8] = 122;
					num6 = 165;
					goto IL_0c17;
				case 169:
					array[31] = 87;
					num4 = 276;
					if (U0K7XudfApNYWsOqBJ())
					{
						goto IL_0c1b;
					}
					goto case 54;
				case 303:
					array2[11] = (byte)num5;
					num4 = 99;
					if (!U0K7XudfApNYWsOqBJ())
					{
						goto case 215;
					}
					goto IL_0c1b;
				case 17:
					array[24] = (byte)num7;
					U0K7XudfApNYWsOqBJ();
					if (A8XN3twHZvFA9XN2Jk())
					{
						num6 = 338;
						goto IL_0c17;
					}
					num = 277;
					break;
				case 124:
					array[3] = 31;
					num4 = 306;
					if (true)
					{
						goto IL_0c1b;
					}
					goto case 350;
				case 350:
					num3 = 104 + 46;
					num4 = 313;
					goto IL_0c1b;
				case 154:
					array[11] = (byte)num7;
					num4 = 49;
					goto IL_0c1b;
				case 34:
					num7 = 59 + 91;
					num4 = 183;
					goto IL_0c1b;
				case 337:
					IuiN2DRtTL = (byte[])FgNkk8SV1bWAMR6HrP(memoryStream);
					num4 = 213;
					goto IL_0c1b;
				case 229:
					array[2] = (byte)num8;
					num = 18;
					break;
				case 181:
					num8 = 211 - 70;
					num4 = 87;
					goto IL_0c1b;
				case 58:
					array[9] = 130;
					num4 = 236;
					goto IL_0c1b;
				case 308:
					num7 = 174 - 58;
					num4 = 218;
					if (0 == 0)
					{
						goto IL_0c1b;
					}
					goto case 139;
				case 139:
					array2[7] = 29;
					num = 264;
					break;
				case 312:
					array3[5] = array4[2];
					num = 203;
					break;
				case 28:
					num5 = 169 - 56;
					num6 = 321;
					goto IL_0c17;
				case 35:
					array2[4] = (byte)num5;
					num4 = 293;
					goto IL_0c1b;
				case 51:
					array[2] = 48;
					num = 116;
					break;
				case 363:
					try
					{
						return (string)uq9BDPlWwv4u6B0hTV(N7BHyupltD5nEFFHGO(), IuiN2DRtTL, P_0 + 4, num2);
					}
					catch
					{
					}
					return "";
				case 240:
					rijndaelManaged = new RijndaelManaged();
					num = 94;
					break;
				case 295:
					{
						memoryStream = new MemoryStream();
						num = 272;
						break;
					}
					IL_0c17:
					num4 = num6;
					goto IL_0c1b;
					IL_0c1b:
					num = num4;
					break;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		internal static string ety3dOj1Z(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void OIGNI2vP1m(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int V22NSMl55r(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr eQ7GFE5Gm(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void arDNtTOXg7()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void rLtNuMT1JG()
		{
			try
			{
				RSACryptoServiceProvider.UseMachineKeyStore = true;
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object eN7tfvJXN(object P_0)
		{
			try
			{
				if (File.Exists(((Assembly)P_0).Location))
				{
					return ((Assembly)P_0).Location;
				}
			}
			catch
			{
			}
			try
			{
				if (File.Exists(((Assembly)P_0).GetName().CodeBase.ToString().Replace("file:///", "")))
				{
					return ((Assembly)P_0).GetName().CodeBase.ToString().Replace("file:///", "");
				}
			}
			catch
			{
			}
			try
			{
				if (File.Exists(P_0.GetType().GetProperty("Location").GetValue(P_0, new object[0])
					.ToString()))
				{
					return P_0.GetType().GetProperty("Location").GetValue(P_0, new object[0])
						.ToString();
				}
			}
			catch
			{
			}
			return "";
		}

		[DllImport("kernel32", EntryPoint = "LoadLibrary")]
		public static extern IntPtr eYMISpk4J(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr eLQQrEvWi(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int jmYNPAxx2q(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int gWKNqs3iLY(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int pMtN68LC6v(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr ob0NHOY37i(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int susNsHWV5C(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		private static byte[] iaPNRRU3E6(string P_0)
		{
			using FileStream fileStream = new FileStream(P_0, FileMode.Open, FileAccess.Read, FileShare.Read);
			int num = 0;
			long length = fileStream.Length;
			int num2 = (int)length;
			byte[] array = new byte[num2];
			while (num2 > 0)
			{
				int num3 = fileStream.Read(array, num, num2);
				num += num3;
				num2 -= num3;
			}
			return array;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		private static byte[] KQRN4cZrxa(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				76, 182, 178, 243, 83, 93, 152, 27, 172, 11,
				175, 85, 99, 97, 169, 226, 10, 72, 184, 230,
				229, 127, 152, 116, 201, 187, 95, 34, 34, 180,
				156, 78
			};
			rijndael.IV = new byte[16]
			{
				106, 118, 36, 173, 54, 204, 185, 109, 84, 235,
				172, 145, 200, 183, 68, 101
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] G6PNMQcN0I()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] dSeNGGkA9H()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] NmYNintboY()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] aChNo2GBS4()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] dKINlBA1Rv()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] fPBNBs5Eb4()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] eN1dFhEg9()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] eE1b9Gujx()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] exNm0KjsX()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] eHevhk2oP()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public emYpxP33xAq8jO8oJ1()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type TkGJXF26ga5X1c1AH2(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object HJKxIyWS7YaXltWqj4(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object kVD90NG1mGPHIC6dWG(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void NJn9Lttcwq7vtSAgcw(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void mNAUx6j4BW7yYNGUaw(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long dllNZv3nPPlBYeEBNi(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object nZiC5UMmvXoZLQSpa1(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object GUJFYeyc2da2tqkhD4(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object MWDunLOi3cnhqWpT3G(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void x2qSAXnYp8efMr5Fe8(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object aB5bgR8KOwS3EaYJ6A(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void xOuniNsOgmExe7I1cn(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void eLDokTNSVGPFCd4hxK(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object FgNkk8SV1bWAMR6HrP(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void vQu3vt6OAIFWsUbUXw(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void eAKmPFFDfK0p6S4cNE(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int Mf7yXgmRNKb2cUBfeZ(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object N7BHyupltD5nEFFHGO()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object uq9BDPlWwv4u6B0hTV(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool U0K7XudfApNYWsOqBJ()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool A8XN3twHZvFA9XN2Jk()
		{
			return false;
		}
	}
}
namespace eoP53YVgQa1lbB0Xy6
{
	internal class eGujxxQN0KjsXHehk2
	{
		private static bool u8hNYA5cef;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void uwaCH9TzMjcqN()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public eGujxxQN0KjsXHehk2()
		{
		}
	}
}
