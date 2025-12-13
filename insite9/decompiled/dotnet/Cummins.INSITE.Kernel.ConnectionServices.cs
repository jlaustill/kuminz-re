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
using Cummins.INSITE.Kernel.CommunicationServices;
using Cummins.INSITE.Kernel.ConnectionServices.ConnectionTypes;
using Cummins.INSITE.Kernel.ECMServicesAPI;
using Cummins.INSITE.Kernel.ECMServicesCommonTypes;
using Cummins.INSITE.Kernel.MetadataServices;
using eIOTCwgtN7fvJXNYMS;
using eoP53YVgQa1lbB0Xy6;

[assembly: ComVisible(true)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: Guid("49dfff00-f7e1-4f39-b5ae-dc1e0cbff49a")]
[assembly: InternalsVisibleTo("ConnectionServicesUnitTest")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyTitle("Cummins.INSITE.Kernel.ConnectionServices")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyTrademark("")]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyProduct("Cummins.INSITE.Kernel.ConnectionServices")]
[assembly: AssemblyVersion("7.6.0.272")]
internal static class o2fjNmRUyTiSwLV1Q9
{
}
namespace Cummins.INSITE.Kernel.ConnectionServices
{
	internal class ECU : IECU
	{
		protected int _Id;

		protected int _ecuType;

		protected int _ecuDetectType;

		protected string _name;

		protected bool _isCumminsECU;

		protected string _ecuId;

		protected GTISLevel _gtisLevel;

		protected ECUHierarchy _hierarchyState;

		protected string _productId;

		protected RunLocation _runLocation;

		protected int _sourceAddress;

		protected double _ecmVersion;

		protected string _ecmPhase;

		protected bool _isConnected;

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _Id;
			}
		}

		public int ECUType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _ecuType;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				_ecuType = value;
			}
		}

		public int ECUDetectType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _ecuDetectType;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				_ecuDetectType = value;
			}
		}

		public string Name
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _name;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				_name = value;
			}
		}

		public bool CumminsECU
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _isCumminsECU;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				_isCumminsECU = value;
			}
		}

		public string ECUId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _ecuId;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				_ecuId = value;
			}
		}

		public GTISLevel GTISLevel
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _gtisLevel;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				_gtisLevel = value;
			}
		}

		public ECUHierarchy HierarchyState
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _hierarchyState;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				_hierarchyState = value;
			}
		}

		public string ProductId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _productId;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				_productId = value;
			}
		}

		public RunLocation RunLocation
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _runLocation;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				_runLocation = value;
			}
		}

		public int SourceAddress
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _sourceAddress;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				_sourceAddress = value;
			}
		}

		public double ECMVersion
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _ecmVersion;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				_ecmVersion = value;
			}
		}

		public string ECMPhase
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _ecmPhase;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				_ecmPhase = value;
			}
		}

		public bool IsConnected
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _isConnected;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				_isConnected = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECU(int Id)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.o3UgQoPzRdnE2();
			base..ctor();
			_Id = Id;
		}
	}
	internal class CumminsECU : ECU, ICumminsECU, IECU
	{
		protected int _harnessKeyECMInstance;

		protected int _harnessKeyStatus;

		protected string _serviceECMMarketingName;

		protected bool _visible;

		public int HarnessKeyECMInstance
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _harnessKeyECMInstance;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				_harnessKeyECMInstance = value;
			}
		}

		public int HarnessKeyStatus
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _harnessKeyStatus;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				_harnessKeyStatus = value;
			}
		}

		public string ServiceECMMarketingName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _serviceECMMarketingName;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				_serviceECMMarketingName = value;
			}
		}

		public bool Visible
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _visible;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				_visible = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public CumminsECU(int Id)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.o3UgQoPzRdnE2();
			base..ctor(Id);
		}
	}
	[ComSourceInterfaces(typeof(IConnectionEvents))]
	public abstract class Connection : IConnection
	{
		protected static int _nextCookie;

		protected static IConnector _connector;

		private object wGLiuncNQ;

		protected int _connectionId;

		protected IConnectionConfiguration _connectionConfiguration;

		protected bool _isConnected;

		protected string _name;

		protected ISystems _systems;

		protected Dictionary<int, IDisconnectCallback> _disconnectCallbacks;

		private EventHandler<ConnectionStatusEventArgs> T70sle6UF;

		private ConnectionStatusChangedDelegate lvQZZZiNK;

		public static IConnector Connector
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _connector;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				_connector = value;
			}
		}

		public abstract ConnectionType ConnectionType { get; }

		public abstract string FirmwareVersion { get; }

		public IConnectionConfiguration ConnectionConfiguration
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _connectionConfiguration;
			}
		}

		public int ConnectionId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _connectionId;
			}
		}

		public bool IsConnected
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _isConnected;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			protected set
			{
				_isConnected = value;
			}
		}

		public string Name
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _name;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				_name = value;
			}
		}

		public ISystems Systems
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _systems;
			}
		}

		public virtual bool CanDisconnect
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				bool flag = true;
				foreach (IDisconnectCallback value in _disconnectCallbacks.Values)
				{
					flag = flag && value.AllowDisconnect(ConnectionId);
				}
				return flag;
			}
		}

		public event EventHandler<ConnectionStatusEventArgs> ConnectionStatusChanged
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				EventHandler<ConnectionStatusEventArgs> eventHandler = T70sle6UF;
				EventHandler<ConnectionStatusEventArgs> eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler<ConnectionStatusEventArgs> value2 = (EventHandler<ConnectionStatusEventArgs>)Delegate.Combine(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref T70sle6UF, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				EventHandler<ConnectionStatusEventArgs> eventHandler = T70sle6UF;
				EventHandler<ConnectionStatusEventArgs> eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler<ConnectionStatusEventArgs> value2 = (EventHandler<ConnectionStatusEventArgs>)Delegate.Remove(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref T70sle6UF, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
		}

		public event ConnectionStatusChangedDelegate OnConnectionStatusChanged
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				ConnectionStatusChangedDelegate connectionStatusChangedDelegate = lvQZZZiNK;
				ConnectionStatusChangedDelegate connectionStatusChangedDelegate2;
				do
				{
					connectionStatusChangedDelegate2 = connectionStatusChangedDelegate;
					ConnectionStatusChangedDelegate value2 = (ConnectionStatusChangedDelegate)Delegate.Combine(connectionStatusChangedDelegate2, value);
					connectionStatusChangedDelegate = Interlocked.CompareExchange(ref lvQZZZiNK, value2, connectionStatusChangedDelegate2);
				}
				while ((object)connectionStatusChangedDelegate != connectionStatusChangedDelegate2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				ConnectionStatusChangedDelegate connectionStatusChangedDelegate = lvQZZZiNK;
				ConnectionStatusChangedDelegate connectionStatusChangedDelegate2;
				do
				{
					connectionStatusChangedDelegate2 = connectionStatusChangedDelegate;
					ConnectionStatusChangedDelegate value2 = (ConnectionStatusChangedDelegate)Delegate.Remove(connectionStatusChangedDelegate2, value);
					connectionStatusChangedDelegate = Interlocked.CompareExchange(ref lvQZZZiNK, value2, connectionStatusChangedDelegate2);
				}
				while ((object)connectionStatusChangedDelegate != connectionStatusChangedDelegate2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected Connection(int connectionId)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.o3UgQoPzRdnE2();
			base..ctor();
			wGLiuncNQ = new object();
			_connectionId = connectionId;
			_disconnectCallbacks = new Dictionary<int, IDisconnectCallback>();
		}

		public abstract void Connect(ISystem system);

		public abstract void Connect(IConnectionConfiguration connectionConfiguration);

		public abstract void ResumeCommunication(int ecuId);

		public abstract void SuspendCommunication(int ecuId);

		public abstract void ConnectSystem(object ModuleAddressesInSystem);

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int RegisterDisconnectCallback(IDisconnectCallback callback)
		{
			int num = 0;
			lock (wGLiuncNQ)
			{
				num = _nextCookie;
				_disconnectCallbacks.Add(_nextCookie++, callback);
				return num;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void UnregisterDisconnectCallback(int cookie)
		{
			lock (wGLiuncNQ)
			{
				_disconnectCallbacks.Remove(cookie);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual void Disconnect(bool forceDisconnect, bool fireEvent = true)
		{
			bool flag = true;
			if (!forceDisconnect)
			{
				foreach (IDisconnectCallback value in _disconnectCallbacks.Values)
				{
					flag = flag && value.AllowDisconnect(ConnectionId);
				}
			}
			if (!flag)
			{
				return;
			}
			List<IDisconnectCallback> list = new List<IDisconnectCallback>(_disconnectCallbacks.Values);
			try
			{
				foreach (IDisconnectCallback item in list)
				{
					try
					{
						if (fireEvent)
						{
							item.HandleDisconnect(ConnectionId);
						}
					}
					catch
					{
					}
				}
			}
			catch
			{
			}
			Connector.Disconnect(_connectionId);
			IsConnected = false;
			if (fireEvent)
			{
				FireConnectionStatusChanged(ConnectionStatus.ConnectionTerminated);
			}
			Systems.Clear();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public virtual void Reinitialize()
		{
			Connector.GetConnectionProperties(ConnectionId);
			_systems.Clear();
			_systems = SystemIdentifier.IdentifySystems(_connectionConfiguration.ConnectionType, _connectionId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void BuildSystem()
		{
			_systems = SystemIdentifier.IdentifySystems(_connectionConfiguration.ConnectionType, _connectionId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void PrepareConnection()
		{
			foreach (ICumminsECU cumminsECU in Systems[0].CumminsECUs)
			{
				Connector.PrepareConnection(_connectionId, cumminsECU.SourceAddress);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void FireConnectionStatusChanged(ConnectionStatus status)
		{
			T70sle6UF?.Invoke(this, new ConnectionStatusEventArgs(_connectionId, status));
			ConnectionStatusChangedDelegate connectionStatusChangedDelegate = lvQZZZiNK;
			if (connectionStatusChangedDelegate != null)
			{
				try
				{
					connectionStatusChangedDelegate(_connectionId, status);
				}
				catch
				{
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static Connection()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.o3UgQoPzRdnE2();
			_nextCookie = 1;
		}
	}
}
namespace Cummins.INSITE.Kernel.ConnectionServices.ConnectionTypes
{
	internal class PhysicalConnection : Connection, ISession
	{
		private const uint CakhBD8Js = 2u;

		private static string IA3MSBnmL;

		private static string TlMwo9ffB;

		private List<object> EW48RFg2K;

		private List<int> tnMYQBkby;

		private List<int> d98LJqrkw;

		private List<int> FQ47EfXxH;

		private uint L3TvVdpgj;

		private Dictionary<int, int> LIfV8eUlu;

		private Dictionary<int, Dictionary<int, string>> rRlWkdYjH;

		private bool eyyy2Hhj6;

		private ManualResetEvent J4O6H9o8u;

		private bool hX6oq16Sa;

		public override ConnectionType ConnectionType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ConnectionType.Physical;
			}
		}

		public override string FirmwareVersion
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Connection._connector.GetFirmwareVersion(_connectionId);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public PhysicalConnection(int connectionId)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.o3UgQoPzRdnE2();
			d98LJqrkw = new List<int>();
			base..ctor(connectionId);
			LIfV8eUlu = new Dictionary<int, int>();
			eyyy2Hhj6 = false;
			J4O6H9o8u = new ManualResetEvent(initialState: false);
			hX6oq16Sa = true;
			L3TvVdpgj = 0u;
			EW48RFg2K = new List<object>();
			EW48RFg2K.Add(4010);
			EW48RFg2K.Add(4003);
			rRlWkdYjH = new Dictionary<int, Dictionary<int, string>>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void Connect(IConnectionConfiguration connectionConfiguration)
		{
			L3TvVdpgj = 0u;
			if (!(connectionConfiguration is IPhysicalConnectionConfiguration))
			{
				throw new ArgumentException(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(0), eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(146));
			}
			_connectionConfiguration = connectionConfiguration;
			Connection.Connector.Connect(connectionConfiguration, _connectionId);
			Connection.Connector.GetConnectionProperties(_connectionId);
			BuildSystem();
			if (base.Systems.Count > 1 && !ECMServicesConfiguration.Configuration.GetConfigurationValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(196), defaultValue: false))
			{
				throw new ECMServicesException(ECMServicesErrorCodes.MultipleSystemsDetected);
			}
			wDtRh9xgx();
			(base.Systems[0] as System).Connection = this;
			base.IsConnected = true;
			FireConnectionStatusChanged(ConnectionStatus.ConnectionEstablished);
			PrepareConnection();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void Connect(ISystem system)
		{
			List<int> list = new List<int>();
			foreach (ICumminsECU cumminsECU in system.CumminsECUs)
			{
				list.Add(cumminsECU.SourceAddress);
			}
			Connection.Connector.Connect(list, base.ConnectionId);
			_systems = new Systems();
			_systems.Add(system);
			V8sER8rJD();
			base.IsConnected = true;
			FireConnectionStatusChanged(ConnectionStatus.ConnectionEstablished);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void Disconnect(bool forceDisconnect, bool fireEvent = true)
		{
			KSBDeDmng();
			CkrqOBbZp();
			base.Disconnect(forceDisconnect, fireEvent);
			if (base.IsConnected)
			{
				wDtRh9xgx();
				V8sER8rJD();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void ResumeCommunication(int ecuId)
		{
			eyyy2Hhj6 = false;
			Connection.Connector.ResumeCommunication(base.ConnectionId);
			V8sER8rJD();
			J4O6H9o8u.WaitOne();
			if (!eyyy2Hhj6)
			{
				FireConnectionStatusChanged(ConnectionStatus.ConnectionResumed);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void SuspendCommunication(int ecuId)
		{
			eyyy2Hhj6 = false;
			KSBDeDmng();
			Connection.Connector.SuspendCommunication(base.ConnectionId);
			FireConnectionStatusChanged(ConnectionStatus.ConnectionSuspended);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void OpenSession(int ecuId)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void CloseSession(int ecuId)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetSessionInfo(int ecuId, ISessionInfo sessionInfo)
		{
			IECU eCU = base.Systems[0].GetECU(ecuId);
			if (eCU.GTISLevel == GTISLevel.GTIS_45 || eCU.GTISLevel == GTISLevel.GTIS_46)
			{
				Connection.Connector.OpenSession(_connectionId, eCU.SourceAddress, sessionInfo);
				try
				{
					wDtRh9xgx();
					return;
				}
				catch (ECMServicesException ex)
				{
					if (ex.ErrorCode == ECMServicesErrorCodes.DatalinkError || ex.ErrorCode == ECMServicesErrorCodes.DatalinkTimeout)
					{
						throw;
					}
					return;
				}
			}
			throw new NotSupportedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ISessionInfo GetSessionInfo(int ecuId)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void ConnectSystem(object ModuleAddressesInSystem)
		{
			try
			{
				int[] collection = ModuleAddressesInSystem as int[];
				bool flag = false;
				tnMYQBkby = new List<int>(collection);
				FQ47EfXxH = new List<int>();
				List<int> list = new List<int>();
				int num = 0;
				foreach (ISystem system in _systems)
				{
					bool flag2 = false;
					foreach (ICumminsECU cumminsECU in system.CumminsECUs)
					{
						flag = tnMYQBkby.Contains(cumminsECU.SourceAddress);
						if (cumminsECU.Visible && flag)
						{
							flag2 = true;
						}
						if (flag2 && !cumminsECU.Visible)
						{
							flag = true;
						}
					}
					if (!flag)
					{
						d98LJqrkw.Add(num);
					}
					num++;
				}
				foreach (int item in d98LJqrkw)
				{
					foreach (ICumminsECU cumminsECU2 in _systems[item].CumminsECUs)
					{
						list.Add(cumminsECU2.SourceAddress);
					}
					_systems.RemoveAt(item);
				}
				Connection.Connector.RemoveModules(list, base.ConnectionId);
				wDtRh9xgx();
				V8sER8rJD();
				(base.Systems[0] as System).Connection = this;
				base.IsConnected = true;
				FireConnectionStatusChanged(ConnectionStatus.ConnectionEstablished);
				PrepareConnection();
			}
			catch (Exception)
			{
				throw new ECMServicesException(ECMServicesErrorCodes.UnknownError);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void V8sER8rJD()
		{
			if ((!hX6oq16Sa && LIfV8eUlu.Count != 0) || !ECMServicesConfiguration.Configuration.GetConfigurationValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(248), defaultValue: true))
			{
				return;
			}
			hX6oq16Sa = false;
			GTISLevel gTISLevel = base.Systems[0].CumminsECUs[0].GTISLevel;
			if (gTISLevel != GTISLevel.GTIS_45 && gTISLevel != GTISLevel.GTIS_46)
			{
				EW48RFg2K.Add(15);
			}
			IReader reader = Connection.Connector.GetReader(base.ConnectionId);
			int configurationValue = ECMServicesConfiguration.Configuration.GetConfigurationValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(274), 7500);
			foreach (ICumminsECU cumminsECU in base.Systems[0].CumminsECUs)
			{
				int parameterValuesAsync = reader.GetParameterValuesAsync(EW48RFg2K, cumminsECU.SourceAddress, Protocol.ICL, configurationValue, snXag3dEt);
				LIfV8eUlu.Add(parameterValuesAsync, cumminsECU.SourceAddress);
				if (!rRlWkdYjH.ContainsKey(cumminsECU.SourceAddress))
				{
					rRlWkdYjH.Add(cumminsECU.SourceAddress, new Dictionary<int, string>());
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void KSBDeDmng()
		{
			hX6oq16Sa = true;
			IReader reader = Connection.Connector.GetReader(base.ConnectionId);
			foreach (int key in LIfV8eUlu.Keys)
			{
				reader.CancelAsyncRequest(key);
			}
			LIfV8eUlu.Clear();
			J4O6H9o8u.Reset();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void snXag3dEt(int P_0, bool P_1, object P_2)
		{
			if (!hX6oq16Sa)
			{
				if (P_1)
				{
					y6PgVUDkZ(P_0, P_2);
				}
				else
				{
					U9ejIGgD5(P_0, P_2);
				}
				J4O6H9o8u.Set();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void y6PgVUDkZ(int P_0, object P_1)
		{
			eyyy2Hhj6 = false;
			IParameterValues parameterValues = P_1 as IParameterValues;
			if (parameterValues.Count == 0)
			{
				GTISLevel gTISLevel = base.Systems[0].GetECUByAddress(LIfV8eUlu[P_0]).GTISLevel;
				if (gTISLevel == GTISLevel.GTIS_45 || gTISLevel == GTISLevel.GTIS_46)
				{
					hX6oq16Sa = true;
					FireConnectionStatusChanged(ConnectionStatus.ConnectionToDatalinkLost);
				}
				else
				{
					FireConnectionStatusChanged(ConnectionStatus.ECUHasChanged);
				}
			}
			else
			{
				TVRtnk44q(P_0, parameterValues);
			}
			L3TvVdpgj = 0u;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void TVRtnk44q(int P_0, IParameterValues P_1)
		{
			if (LIfV8eUlu.ContainsKey(P_0))
			{
				int num = LIfV8eUlu[P_0];
				{
					foreach (IParameterValue item in P_1)
					{
						int num2 = item.ParameterAs<int>();
						if (rRlWkdYjH[num].ContainsKey(num2))
						{
							if (rRlWkdYjH[num][num2] == item.ValueAs<string>())
							{
								continue;
							}
							GTISLevel gTISLevel = base.Systems[0].GetECUByAddress(LIfV8eUlu[P_0]).GTISLevel;
							if (P_1.Count != 1 || (gTISLevel != GTISLevel.GTIS_45 && gTISLevel != GTISLevel.GTIS_46))
							{
								if (P_1.Count != 1)
								{
									switch (num2)
									{
									case 4003:
										break;
									case 4010:
										FireConnectionStatusChanged(ConnectionStatus.SnHasChanged);
										return;
									default:
										continue;
									}
								}
								FireConnectionStatusChanged(ConnectionStatus.ECUHasChanged);
								break;
							}
							try
							{
								Connection.Connector.PingECU(_connectionId, num);
							}
							catch (ECMServicesException ex)
							{
								if (ex.ErrorCode == ECMServicesErrorCodes.DatalinkError)
								{
									hX6oq16Sa = true;
									FireConnectionStatusChanged(ConnectionStatus.ConnectionToDatalinkLost);
								}
								else if (ex.ErrorCode == ECMServicesErrorCodes.DatalinkTimeout)
								{
									hX6oq16Sa = true;
									FireConnectionStatusChanged(ConnectionStatus.ConnectionToECULost);
								}
							}
						}
						else
						{
							rRlWkdYjH[num].Add(num2, item.ValueAs<string>());
						}
					}
					return;
				}
			}
			if (eyyy2Hhj6)
			{
				KSBDeDmng();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void U9ejIGgD5(int P_0, object P_1)
		{
			bool flag = false;
			if (eyyy2Hhj6)
			{
				flag = false;
				return;
			}
			if (base.Systems[0].CumminsECUs.Count > 1)
			{
				int num = 0;
				foreach (ICumminsECU cumminsECU in base.Systems[0].CumminsECUs)
				{
					try
					{
						Connection.Connector.PingECU(_connectionId, cumminsECU.SourceAddress);
					}
					catch (ECMServicesException ex)
					{
						P_1 = ex;
						num++;
						(cumminsECU as ECU).IsConnected = false;
					}
				}
				if (base.Systems[0].CumminsECUs.Count - num > 0)
				{
					if (!eyyy2Hhj6)
					{
						FireConnectionStatusChanged(ConnectionStatus.ECUCountHasChanged);
					}
					flag = true;
				}
				else
				{
					flag = X5h4ZDwV0(P_1, P_0);
				}
			}
			else if (base.Systems[0].CumminsECUs.Count == 1)
			{
				ECMServicesException ex2 = P_1 as ECMServicesException;
				try
				{
					if (ex2.ErrorCode == ECMServicesErrorCodes.DatalinkTimeout)
					{
						flag = X5h4ZDwV0(P_1, P_0);
					}
					else
					{
						Connection.Connector.PingECU(_connectionId, base.Systems[0].CumminsECUs[0].SourceAddress);
						flag = false;
					}
				}
				catch (ECMServicesException)
				{
					flag = X5h4ZDwV0(P_1, P_0);
				}
			}
			if (flag)
			{
				eyyy2Hhj6 = true;
				KSBDeDmng();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool X5h4ZDwV0(object P_0, int P_1)
		{
			bool flag = false;
			if (P_0 is ECMServicesException ex)
			{
				switch (ex.ErrorCode)
				{
				case ECMServicesErrorCodes.DatalinkError:
					if (!eyyy2Hhj6)
					{
						FireConnectionStatusChanged(ConnectionStatus.ConnectionToDatalinkLost);
					}
					return true;
				case ECMServicesErrorCodes.DatalinkTimeout:
					if (!eyyy2Hhj6)
					{
						if (L3TvVdpgj < 2 && LIfV8eUlu.ContainsKey(P_1) && base.Systems[0].GetECUByAddress(LIfV8eUlu[P_1]).GTISLevel != GTISLevel.GTIS_45 && base.Systems[0].GetECUByAddress(LIfV8eUlu[P_1]).GTISLevel != GTISLevel.GTIS_46)
						{
							L3TvVdpgj++;
							return false;
						}
						FireConnectionStatusChanged(ConnectionStatus.ConnectionToECULost);
						L3TvVdpgj = 0u;
						return true;
					}
					return true;
				default:
					if (!eyyy2Hhj6)
					{
						FireConnectionStatusChanged(ConnectionStatus.ConnectionToECULost);
					}
					return true;
				}
			}
			FireConnectionStatusChanged(ConnectionStatus.ConnectionToECULost);
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void wDtRh9xgx()
		{
			IOperator obj = Connection.Connector.GetOperator(_connectionId);
			foreach (ICumminsECU cumminsECU in _systems[0].CumminsECUs)
			{
				if (cumminsECU.GTISLevel == GTISLevel.GTIS_45 || cumminsECU.GTISLevel == GTISLevel.GTIS_46)
				{
					int sourceAddress = cumminsECU.SourceAddress;
					if (obj.ExecuteOperation(IA3MSBnmL, null, sourceAddress, Protocol.CC, out var _) != 0)
					{
						throw new ECMServicesException(ECMServicesErrorCodes.AcquiringChangeLockFailed);
					}
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void CkrqOBbZp()
		{
			IOperator obj = Connection.Connector.GetOperator(_connectionId);
			foreach (ICumminsECU cumminsECU in _systems[0].CumminsECUs)
			{
				if (cumminsECU.GTISLevel == GTISLevel.GTIS_45 || cumminsECU.GTISLevel == GTISLevel.GTIS_46)
				{
					int sourceAddress = cumminsECU.SourceAddress;
					try
					{
						obj.ExecuteOperation(TlMwo9ffB, null, sourceAddress, Protocol.CC, out var _);
					}
					catch
					{
					}
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static PhysicalConnection()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.o3UgQoPzRdnE2();
			IA3MSBnmL = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(294);
			TlMwo9ffB = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(408);
		}
	}
}
namespace Cummins.INSITE.Kernel.ConnectionServices
{
	internal class CumminsECUs : List<ICumminsECU>, IList<ICumminsECU>, ICumminsECUs, ICollection<ICumminsECU>, IEnumerable, IEnumerable<ICumminsECU>
	{
		public new int Count
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				int num = 0;
				using Enumerator enumerator = GetEnumerator();
				while (enumerator.MoveNext())
				{
					ICumminsECU current = enumerator.Current;
					if (current.Visible)
					{
						num++;
					}
				}
				return num;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public CumminsECUs()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.o3UgQoPzRdnE2();
			base..ctor();
		}
	}
}
namespace Cummins.INSITE.Kernel.ConnectionServices.ConnectionTypes
{
	internal class SimulatorConnection : Connection
	{
		public override ConnectionType ConnectionType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ConnectionType.Simulator;
			}
		}

		public override string FirmwareVersion
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return string.Empty;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SimulatorConnection(int connectionId)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.o3UgQoPzRdnE2();
			base..ctor(connectionId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void Connect(IConnectionConfiguration connectionConfiguration)
		{
			if (!(connectionConfiguration is ISimulatorConnectionConfiguration simulatorConnectionConfiguration))
			{
				throw new ArgumentException(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(522), eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(670));
			}
			_connectionConfiguration = connectionConfiguration;
			Connection.Connector.Connect(connectionConfiguration, _connectionId);
			if (simulatorConnectionConfiguration.SystemType != 0)
			{
				IWriter writer = Connection.Connector.GetWriter(base.ConnectionId);
				writer.SetParameterValue(15, simulatorConnectionConfiguration.SimulatorType, 0, Protocol.ICL);
				writer.SetParameterValue(199999, simulatorConnectionConfiguration.SystemType, 0, Protocol.ICL);
			}
			BuildSystem();
			ICumminsECUs cumminsECUs = _systems[0].CumminsECUs;
			int num = 0;
			num = cumminsECUs.Count;
			ISystemProperties systemProperties = new SystemProperties(base.ConnectionId);
			for (int i = 0; i < num; i++)
			{
				ECUProperties item = new ECUProperties();
				systemProperties.Add(item);
				systemProperties[i].DetectType = cumminsECUs[i].ECUDetectType;
				systemProperties[i].ECUId = cumminsECUs[i].ECUId;
				systemProperties[i].GTISLevel = cumminsECUs[i].GTISLevel;
				systemProperties[i].HarnessKeyStatus = cumminsECUs[i].HarnessKeyStatus;
				systemProperties[i].HierarchyState = cumminsECUs[i].HierarchyState;
				systemProperties[i].ProductId = cumminsECUs[i].ProductId;
				systemProperties[i].RunLocation = cumminsECUs[i].RunLocation;
				systemProperties[i].SourceAddress = cumminsECUs[i].SourceAddress;
			}
			Connection.Connector.SetConnectionProperties(base.ConnectionId, systemProperties);
			Connection.Connector.GetConnectionProperties(_connectionId);
			(base.Systems[0] as System).Connection = this;
			base.IsConnected = true;
			PrepareConnection();
			FireConnectionStatusChanged(ConnectionStatus.ConnectionEstablished);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void Connect(ISystem system)
		{
			throw new NotSupportedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void ResumeCommunication(int ecuId)
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void SuspendCommunication(int ecuId)
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void ConnectSystem(object ModuleAddressesInSystem)
		{
			throw new NotSupportedException();
		}
	}
}
namespace Cummins.INSITE.Kernel.ConnectionServices
{
	public class Connections : List<IConnection>, IList<IConnection>, IConnections, ICollection<IConnection>, IEnumerable, IEnumerable<IConnection>
	{
		private IConnector NJxT7lbgV;

		private Dictionary<int, Connection> IE455Yxni;

		public new int Count
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return IE455Yxni.Count;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Connections(IConnector connector, IMetadataServices metadataServices, ISystemInformationProvider systemInfoProvider)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.o3UgQoPzRdnE2();
			base..ctor();
			IE455Yxni = new Dictionary<int, Connection>();
			NJxT7lbgV = connector;
			Connection.Connector = NJxT7lbgV;
			SystemIdentifier.Connector = NJxT7lbgV;
			SystemIdentifier.MetadataServices = metadataServices;
			SystemIdentifier.SystemInformationProvider = systemInfoProvider;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IConnection Add(ConnectionType connectionType)
		{
			Connection connection = ConnectionFactory.CreateNewConnection(connectionType);
			IE455Yxni.Add(connection.ConnectionId, connection);
			return connection;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IConnection AddConnectionForSystem(ISystem detectedSystem)
		{
			Connection connection = ConnectionFactory.CreateNewConnection(ConnectionType.Physical);
			IE455Yxni.Add(connection.ConnectionId, connection);
			connection.Connect(detectedSystem);
			return connection;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ISystems Detect(IPhysicalConnectionConfiguration connectionConfiguration)
		{
			throw new NotImplementedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IConnection Get(int connectionId)
		{
			return IE455Yxni[connectionId];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Remove(int connectionId)
		{
			if (IE455Yxni[connectionId].IsConnected)
			{
				throw new ECMServicesException(ECMServicesErrorCodes.ConnectionIsActive);
			}
			IE455Yxni.Remove(connectionId);
		}
	}
	internal class System : ISystem
	{
		private Connection zp2FE3E4L;

		private ICumminsECUs MhSbEb4IT;

		private IECUs fBel6Mwxn;

		private string REPfPETfq;

		private int K0TK6KQo3;

		private int BZ91UOSR1;

		private bool Eil2fgxgH;

		internal Connection Connection
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return zp2FE3E4L;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				zp2FE3E4L = value;
			}
		}

		public ICumminsECUs CumminsECUs
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return MhSbEb4IT;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				MhSbEb4IT = value;
			}
		}

		public string Name
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return REPfPETfq;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				REPfPETfq = value;
			}
		}

		public IECUs OtherDevices
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				if (!Eil2fgxgH && zp2FE3E4L != null)
				{
					IECU eCU = GetECU(0);
					if (zp2FE3E4L.ConnectionType == ConnectionType.Physical && (eCU.GTISLevel == GTISLevel.GTIS_45 || eCU.GTISLevel == GTISLevel.GTIS_46))
					{
						fBel6Mwxn = SystemIdentifier.UpdateSystemWithOtherDevices(Connection.ConnectionId, Connection.ConnectionConfiguration, MhSbEb4IT.Count);
					}
					Eil2fgxgH = true;
				}
				return fBel6Mwxn;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				fBel6Mwxn = value;
			}
		}

		public int PrimaryECUId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return K0TK6KQo3;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				K0TK6KQo3 = value;
			}
		}

		public int SystemType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return BZ91UOSR1;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			internal set
			{
				BZ91UOSR1 = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public System()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.o3UgQoPzRdnE2();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IECU GetECU(int ECUId)
		{
			IECU iECU = null;
			foreach (ICumminsECU item in MhSbEb4IT)
			{
				if (item.Id == ECUId)
				{
					iECU = item;
					break;
				}
			}
			if (iECU == null)
			{
				foreach (IECU item2 in fBel6Mwxn)
				{
					if (item2.Id == ECUId)
					{
						iECU = item2;
						break;
					}
				}
			}
			return iECU;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IECU GetECUByAddress(int sourceAddress)
		{
			IECU iECU = null;
			foreach (ICumminsECU item in MhSbEb4IT)
			{
				if (item.SourceAddress == sourceAddress)
				{
					iECU = item;
					break;
				}
			}
			if (iECU == null)
			{
				foreach (IECU item2 in fBel6Mwxn)
				{
					if (item2.SourceAddress == sourceAddress)
					{
						iECU = item2;
						break;
					}
				}
			}
			return iECU;
		}
	}
	internal class ECUs : List<IECU>, IList<IECU>, IECUs, ICollection<IECU>, IEnumerable, IEnumerable<IECU>
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECUs()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.o3UgQoPzRdnE2();
			base..ctor();
		}
	}
}
namespace Cummins.INSITE.Kernel.ConnectionServices.ConnectionTypes
{
	internal class ImageConnection : Connection
	{
		public override ConnectionType ConnectionType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ConnectionType.Image;
			}
		}

		public override string FirmwareVersion
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return string.Empty;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ImageConnection(int connectionId)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.o3UgQoPzRdnE2();
			base..ctor(connectionId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void Connect(IConnectionConfiguration connectionConfiguration)
		{
			if (!(connectionConfiguration is IImageConnectionConfiguration))
			{
				throw new ArgumentException(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(720), eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(860));
			}
			_connectionConfiguration = connectionConfiguration;
			Connection.Connector.Connect(connectionConfiguration, _connectionId);
			BuildSystem();
			ICumminsECUs cumminsECUs = _systems[0].CumminsECUs;
			int num = 0;
			num = cumminsECUs.Count;
			ISystemProperties systemProperties = new SystemProperties(base.ConnectionId);
			for (int i = 0; i < num; i++)
			{
				ECUProperties item = new ECUProperties();
				systemProperties.Add(item);
				systemProperties[i].DetectType = cumminsECUs[i].ECUDetectType;
				systemProperties[i].ECUId = cumminsECUs[i].ECUId;
				systemProperties[i].GTISLevel = cumminsECUs[i].GTISLevel;
				systemProperties[i].HarnessKeyStatus = cumminsECUs[i].HarnessKeyStatus;
				systemProperties[i].HierarchyState = cumminsECUs[i].HierarchyState;
				systemProperties[i].ProductId = cumminsECUs[i].ProductId;
				systemProperties[i].RunLocation = cumminsECUs[i].RunLocation;
				systemProperties[i].SourceAddress = cumminsECUs[i].SourceAddress;
			}
			Connection.Connector.SetConnectionProperties(base.ConnectionId, systemProperties);
			Connection.Connector.GetConnectionProperties(_connectionId);
			(base.Systems[0] as System).Connection = this;
			base.IsConnected = true;
			PrepareConnection();
			FireConnectionStatusChanged(ConnectionStatus.ConnectionEstablished);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void Connect(ISystem system)
		{
			throw new NotSupportedException();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void ResumeCommunication(int ecuId)
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void SuspendCommunication(int ecuId)
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void ConnectSystem(object ModuleAddressesInSystem)
		{
			throw new NotSupportedException();
		}
	}
}
namespace Cummins.INSITE.Kernel.ConnectionServices
{
	internal static class ConnectionFactory
	{
		private static int W6DATjS5G;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static Connection CreateNewConnection(ConnectionType connectionType)
		{
			Connection result = null;
			switch (connectionType)
			{
			case ConnectionType.Image:
				result = new ImageConnection(W6DATjS5G++);
				break;
			case ConnectionType.Physical:
				result = new PhysicalConnection(W6DATjS5G++);
				break;
			case ConnectionType.Simulator:
				result = new SimulatorConnection(W6DATjS5G++);
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static ConnectionFactory()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.o3UgQoPzRdnE2();
			W6DATjS5G = 1;
		}
	}
	internal class Systems : List<ISystem>, IList<ISystem>, ISystems, ICollection<ISystem>, IEnumerable, IEnumerable<ISystem>
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public Systems()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.o3UgQoPzRdnE2();
			base..ctor();
		}
	}
	internal static class SystemIdentifier
	{
		private static IConnector zCQxg7ie0;

		private static IMetadataServices xdOkpYWQB;

		private static ISystemInformationProvider xDySYGRlW;

		public static IConnector Connector
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return zCQxg7ie0;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				zCQxg7ie0 = value;
			}
		}

		public static IMetadataServices MetadataServices
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return xdOkpYWQB;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				xdOkpYWQB = value;
			}
		}

		public static ISystemInformationProvider SystemInformationProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return xDySYGRlW;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				xDySYGRlW = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static IECUs UpdateSystemWithOtherDevices(int connectionId, IConnectionConfiguration connectionConfig, int idToUse)
		{
			IECUs iECUs = new ECUs();
			if (connectionConfig.ConnectionType == ConnectionType.Physical)
			{
				IList<int> list = Connector.Detect(connectionConfig);
				foreach (int item in list)
				{
					if (SystemInformationProvider.IsSupportedSmartDevice(item))
					{
						ISmartDeviceInformation smartDeviceInformation = SystemInformationProvider.GetSmartDeviceInformation(item);
						ECU eCU = new ECU(idToUse);
						eCU.CumminsECU = false;
						eCU.GTISLevel = GTISLevel.NonGTIS;
						eCU.RunLocation = RunLocation.Default;
						eCU.SourceAddress = smartDeviceInformation.SourceAddress;
						eCU.ECUType = smartDeviceInformation.ECUType;
						eCU.ECUDetectType = smartDeviceInformation.DetectType;
						IEnumeration enumeration = MetadataServices.Enumerations.GetEnumeration(212, connectionId, eCU.Id);
						eCU.Name = enumeration.GetDisplayValueForEnum(eCU.ECUType);
						iECUs.Add(eCU);
					}
				}
			}
			return iECUs;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static ISystems IdentifySystems(ConnectionType connType, int connectionId)
		{
			ISystemProperties connectionProperties = Connector.GetConnectionProperties(connectionId);
			List<string> list = new List<string>(SystemInformationProvider.GetPrimaryProductIds());
			List<string> list2 = new List<string>(SystemInformationProvider.GetPrimaryECUIds());
			Systems systems = new Systems();
			bool flag = false;
			List<string> list3 = new List<string>();
			foreach (IECUProperties item4 in connectionProperties)
			{
				if (item4.Consumed)
				{
					continue;
				}
				if (item4.RunLocation == RunLocation.Application || item4.RunLocation == RunLocation.Default || item4.RunLocation == RunLocation.Development)
				{
					if (list.Contains(item4.ProductId))
					{
						if (!list3.Contains(item4.ECUId))
						{
							ISystemInformation systemInformationByProductId = SystemInformationProvider.GetSystemInformationByProductId(item4.ProductId);
							list3.Add(item4.ECUId);
							ISystem item = OWpmRHP6r(connType, connectionId, systemInformationByProductId, connectionProperties);
							systems.Add(item);
						}
						flag = true;
					}
				}
				else if (list2.Contains(item4.ECUId))
				{
					if (!list3.Contains(item4.ECUId))
					{
						ISystemInformation systemInformationByECUId = SystemInformationProvider.GetSystemInformationByECUId(item4.ECUId);
						list3.Add(item4.ECUId);
						ISystem item2 = OWpmRHP6r(connType, connectionId, systemInformationByECUId, connectionProperties);
						systems.Add(item2);
					}
					flag = true;
				}
			}
			if (!flag)
			{
				ISystem item3 = xCCcg0RHQ(connType, connectionId);
				systems.Add(item3);
			}
			return systems;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static ISystem OWpmRHP6r(ConnectionType P_0, int P_1, ISystemInformation P_2, ISystemProperties P_3)
		{
			System system = new System();
			system.CumminsECUs = new CumminsECUs();
			system.OtherDevices = new ECUs();
			int num = 0;
			int num2 = 0;
			bool flag = false;
			bool flag2 = false;
			foreach (IECUProperties item in P_3)
			{
				if (item.RunLocation == RunLocation.Application || item.RunLocation == RunLocation.Default || item.RunLocation == RunLocation.Development)
				{
					if (P_2.PrimaryProductId == item.ProductId && !flag)
					{
						CumminsECU cumminsECU = new CumminsECU(num++);
						cumminsECU.IsConnected = true;
						cumminsECU.Visible = true;
						uXlIcb5Wk(P_1, P_0, cumminsECU, item);
						system.CumminsECUs.Add(cumminsECU);
						item.Consumed = true;
						system.PrimaryECUId = num - 1;
						flag = true;
						if (item.ProductId == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(910) || item.ProductId == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(920))
						{
							flag2 = true;
						}
					}
					else
					{
						if (!P_2.SecondaryProductIds.Contains(item.ProductId))
						{
							continue;
						}
						if (item.GTISLevel == GTISLevel.NonGTIS)
						{
							ECU eCU = new ECU(num2++);
							eCU.IsConnected = true;
							Mg8HVb14u(P_1, eCU, item, P_0);
							system.OtherDevices.Add(eCU);
							continue;
						}
						CumminsECU cumminsECU2 = new CumminsECU(num++);
						cumminsECU2.IsConnected = true;
						if ((item.ProductId == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(930) || item.ProductId == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(940)) && flag2)
						{
							cumminsECU2.Visible = false;
						}
						else
						{
							cumminsECU2.Visible = true;
						}
						uXlIcb5Wk(P_1, P_0, cumminsECU2, item);
						system.CumminsECUs.Add(cumminsECU2);
						item.Consumed = true;
					}
				}
				else if (P_2.PrimaryECUId == item.ECUId && !flag)
				{
					CumminsECU cumminsECU3 = new CumminsECU(num++);
					cumminsECU3.Visible = true;
					cumminsECU3.IsConnected = true;
					uXlIcb5Wk(P_1, P_0, cumminsECU3, item);
					system.CumminsECUs.Add(cumminsECU3);
					system.PrimaryECUId = num - 1;
					flag = true;
					item.Consumed = true;
				}
				else if (P_2.SecondaryECUIds.Contains(item.ECUId))
				{
					if (item.GTISLevel == GTISLevel.NonGTIS)
					{
						ECU eCU2 = new ECU(num2++);
						eCU2.IsConnected = true;
						Mg8HVb14u(P_1, eCU2, item, P_0);
						system.OtherDevices.Add(eCU2);
					}
					else
					{
						CumminsECU cumminsECU4 = new CumminsECU(num++);
						cumminsECU4.Visible = true;
						cumminsECU4.IsConnected = true;
						uXlIcb5Wk(P_1, P_0, cumminsECU4, item);
						system.CumminsECUs.Add(cumminsECU4);
						item.Consumed = true;
					}
				}
			}
			dgOCCiBHE(system, P_1, P_0);
			return system;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static ISystem xCCcg0RHQ(ConnectionType P_0, int P_1)
		{
			System system = new System();
			ISystemProperties connectionProperties = Connector.GetConnectionProperties(P_1);
			Connector.GetReader(P_1);
			bool flag = false;
			system.CumminsECUs = new CumminsECUs();
			system.OtherDevices = new ECUs();
			int num = 0;
			foreach (IECUProperties item in connectionProperties)
			{
				if (item.GTISLevel == GTISLevel.NonGTIS)
				{
					ECU eCU = new ECU(num++);
					eCU.CumminsECU = false;
					Mg8HVb14u(P_1, eCU, item, P_0);
					system.OtherDevices.Add(eCU);
					continue;
				}
				CumminsECU cumminsECU = new CumminsECU(num++);
				cumminsECU.Visible = true;
				cumminsECU.IsConnected = true;
				if (item.ProductId == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(950))
				{
					if (!flag)
					{
						uXlIcb5Wk(P_1, P_0, cumminsECU, item);
						system.CumminsECUs.Add(cumminsECU);
						flag = true;
					}
				}
				else
				{
					uXlIcb5Wk(P_1, P_0, cumminsECU, item);
					system.CumminsECUs.Add(cumminsECU);
				}
			}
			dgOCCiBHE(system, P_1, P_0);
			return system;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void dgOCCiBHE(System P_0, int P_1, ConnectionType P_2)
		{
			bool flag = false;
			bool flag2 = false;
			double ecmVersion = 0.0;
			long num = 0L;
			long num2 = 0L;
			string text = "";
			string text2 = "";
			string ecmPhase = "";
			foreach (ICumminsECU cumminsECU in P_0.CumminsECUs)
			{
				if (!flag2)
				{
					ecmVersion = cumminsECU.ECMVersion;
					ecmPhase = cumminsECU.ECMPhase;
					flag2 = true;
				}
				if (cumminsECU.RunLocation == RunLocation.Boot || cumminsECU.RunLocation == RunLocation.Unknown)
				{
					flag = true;
					num++;
					text = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(960);
				}
				else
				{
					num2++;
					text2 = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(990);
				}
			}
			if (!flag)
			{
				bool bSimulatorType = P_2 == ConnectionType.Simulator;
				IProductInformation productInformation = MetadataServices.GetProductInformation(ecmPhase, ecmVersion, P_0.CumminsECUs[0].ECUDetectType, P_0.CumminsECUs[0].ProductId, P_0.CumminsECUs[0].ECUId, 0, bSimulatorType);
				if (P_0.CumminsECUs[0].GTISLevel != GTISLevel.GTIS_45 && P_0.CumminsECUs[0].GTISLevel != GTISLevel.GTIS_45)
				{
					IReader reader = Connector.GetReader(P_1);
					Protocol protocol = ((P_2 != ConnectionType.Image) ? Protocol.ICL : Protocol.Image);
					IParameterValue parameterValue = reader.GetParameterValue(199999, P_0.CumminsECUs[0].SourceAddress, protocol);
					P_0.SystemType = parameterValue.ValueAs<int>();
				}
				else
				{
					P_0.SystemType = productInformation.SystemType;
				}
				IEnumeration enumeration = MetadataServices.Enumerations.GetEnumeration(213, P_1);
				P_0.Name = enumeration.GetDisplayValueForEnum(P_0.SystemType);
				return;
			}
			int num3 = 1;
			int num4 = 1;
			foreach (ICumminsECU cumminsECU2 in P_0.CumminsECUs)
			{
				if (cumminsECU2.RunLocation == RunLocation.Boot || cumminsECU2.RunLocation == RunLocation.Unknown)
				{
					if (num != num3)
					{
						object obj = text;
						text = string.Concat(obj, cumminsECU2.Name, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1020), cumminsECU2.SourceAddress, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1026));
						text += eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1032);
					}
					else if (num > 1)
					{
						int length = text.Length;
						length -= 2;
						text = text.Remove(length);
						text += eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1040);
						object obj2 = text;
						text = string.Concat(obj2, cumminsECU2.Name, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1054), cumminsECU2.SourceAddress, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1060));
					}
					else
					{
						object obj3 = text;
						text = string.Concat(obj3, cumminsECU2.Name, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1066), cumminsECU2.SourceAddress, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1072));
					}
					num3++;
				}
				else
				{
					if (num2 != num4)
					{
						object obj4 = text2;
						text2 = string.Concat(obj4, cumminsECU2.Name, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1078), cumminsECU2.SourceAddress, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1084));
						text2 += eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1090);
					}
					else if (num2 > 1)
					{
						int length2 = text2.Length;
						length2 -= 2;
						text2 = text2.Remove(length2);
						text2 += eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1098);
						object obj5 = text2;
						text2 = string.Concat(obj5, cumminsECU2.Name, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1112), cumminsECU2.SourceAddress, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1118));
					}
					else
					{
						object obj6 = text2;
						text2 = string.Concat(obj6, cumminsECU2.Name, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1124), cumminsECU2.SourceAddress, eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1130));
					}
					num4++;
				}
			}
			P_0.Name = text + eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1136) + text2;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void uXlIcb5Wk(int P_0, ConnectionType P_1, CumminsECU P_2, IECUProperties P_3)
		{
			Mg8HVb14u(P_0, P_2, P_3, P_1);
			P_2.CumminsECU = true;
			IEnumeration enumeration = MetadataServices.Enumerations.GetEnumeration(430, P_0, P_2.Id);
			switch (P_1)
			{
			case ConnectionType.Simulator:
				P_2.HarnessKeyECMInstance = P_2.SourceAddress + 1;
				P_2.ServiceECMMarketingName = enumeration.GetDisplayValueForEnum(P_2.SourceAddress);
				break;
			case ConnectionType.Physical:
			{
				P_2.HarnessKeyECMInstance = P_3.HarnessKeyECMInstance;
				P_2.HarnessKeyStatus = P_3.HarnessKeyStatus;
				IReader reader = Connector.GetReader(P_0);
				if (P_2.GTISLevel == GTISLevel.GTIS_45 || P_2.GTISLevel == GTISLevel.GTIS_46)
				{
					int rawValue = reader.GetParameterValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1142), P_2.SourceAddress, Protocol.CC).ValueAs<int>();
					P_2.ServiceECMMarketingName = enumeration.GetDisplayValueForEnum(rawValue);
					P_2.HarnessKeyECMInstance = reader.GetParameterValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1200), P_2.SourceAddress, Protocol.CC).ValueAs<int>();
					if (P_2.HarnessKeyECMInstance != 0)
					{
						bool bSimulatorType = P_1 == ConnectionType.Simulator;
						IProductInformation productInformation = MetadataServices.GetProductInformation(P_2.ECMPhase, P_2.ECMVersion, P_2.ECUDetectType, P_2.ProductId, P_2.ECUId, P_2.HarnessKeyECMInstance, bSimulatorType);
						P_2.ECUType = productInformation.ECUType;
					}
					IEnumeration enumeration2 = MetadataServices.Enumerations.GetEnumeration(212, P_0, P_2.Id);
					P_2.Name = enumeration2.GetDisplayValueForEnum(P_2.ECUType);
				}
				else if (P_3.GTISLevel != GTISLevel.NonGTIS)
				{
					P_2.HarnessKeyStatus = P_3.HarnessKeyStatus;
					P_2.ServiceECMMarketingName = "";
				}
				break;
			}
			case ConnectionType.Image:
				P_2.HarnessKeyECMInstance = P_2.SourceAddress + 1;
				P_2.ServiceECMMarketingName = enumeration.GetDisplayValueForEnum(P_2.SourceAddress);
				break;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void Mg8HVb14u(int P_0, ECU P_1, IECUProperties P_2, ConnectionType P_3)
		{
			IProductInformation productInformation = null;
			P_1.SourceAddress = P_2.SourceAddress;
			P_1.ECMVersion = P_2.ECMVersion;
			P_1.ECMPhase = P_2.ECMPhase;
			MetadataServices.SetVersion(P_0, P_1.Id);
			MetadataServices.SetPhase(P_0, P_1.Id);
			if (P_3 == ConnectionType.Simulator || P_3 == ConnectionType.Image)
			{
				if (P_2.GTISLevel == GTISLevel.NonGTIS)
				{
					P_1.ECUType = P_2.DetectType;
					P_1.ECUDetectType = P_2.DetectType;
					P_1.GTISLevel = GTISLevel.NonGTIS;
				}
				else
				{
					IReader reader = Connector.GetReader(P_0);
					Protocol protocol = ((P_3 == ConnectionType.Simulator) ? Protocol.ICL : Protocol.Image);
					IParameterValue parameterValue = reader.GetParameterValue(15, P_1.SourceAddress, protocol);
					productInformation = MetadataServices.GetProductInformation(parameterValue.ValueAs<int>());
					P_1.ECUType = productInformation.ECUType;
					P_1.ECUDetectType = productInformation.DetectType;
					P_1.GTISLevel = productInformation.GTISLevel;
					P_1.ProductId = productInformation.ProductId;
				}
			}
			else if (P_2.RunLocation == RunLocation.Application || P_2.RunLocation == RunLocation.Default || P_2.RunLocation == RunLocation.Development)
			{
				bool bSimulatorType = P_3 == ConnectionType.Simulator;
				productInformation = MetadataServices.GetProductInformation(P_1.ECMPhase, P_1.ECMVersion, P_2.DetectType, P_2.ProductId, P_2.ECUId, 0, bSimulatorType);
				if (productInformation != null)
				{
					P_1.GTISLevel = productInformation.GTISLevel;
					if (P_1.GTISLevel != GTISLevel.GTIS_45 && P_1.GTISLevel != GTISLevel.GTIS_46)
					{
						IReader reader2 = Connector.GetReader(P_0);
						Protocol protocol2 = ((P_3 != ConnectionType.Image) ? Protocol.ICL : Protocol.Image);
						IParameterValue parameterValue2 = reader2.GetParameterValue(15, P_1.SourceAddress, protocol2);
						P_1.ECUType = parameterValue2.ValueAs<int>();
					}
					else
					{
						P_1.ECUType = productInformation.ECUType;
					}
					P_1.ECUDetectType = productInformation.DetectType;
					P_1.ProductId = productInformation.ProductId;
				}
				else if (P_2.RunLocation == RunLocation.Development && MetadataServices.IsECUSupported(P_2.ECUId, P_2.ECMVersion))
				{
					IReader reader3 = Connector.GetReader(P_0);
					IParameterValue parameterValue3 = reader3.GetParameterValue(15, P_1.SourceAddress, Protocol.ICL);
					P_1.ECUType = parameterValue3.ValueAs<int>();
					P_1.ECUDetectType = P_2.DetectType;
					P_1.GTISLevel = GTISLevel.GTIS_38;
					P_1.ProductId = string.Empty;
				}
			}
			else
			{
				IReader reader4 = Connector.GetReader(P_0);
				IParameterValue parameterValue4 = reader4.GetParameterValue(15, P_1.SourceAddress, Protocol.ICL);
				P_1.ECUType = parameterValue4.ValueAs<int>();
				P_1.ECUDetectType = P_2.DetectType;
				P_1.GTISLevel = GTISLevel.GTIS_38;
				P_1.ProductId = string.Empty;
			}
			P_1.ECUId = P_2.ECUId;
			P_1.RunLocation = P_2.RunLocation;
			IEnumeration enumeration = MetadataServices.Enumerations.GetEnumeration(212, P_0, P_1.Id);
			P_1.Name = enumeration.GetDisplayValueForEnum(P_1.ECUType);
			P_1.HierarchyState = P_2.HierarchyState;
		}
	}
}
internal class <Module>{DD60BD8B-A4A6-4C57-ADB5-BC4F7D0400A3}
{
}
namespace eaNnw6oJwxIQQ7FE5G
{
	internal class eILexUWtydOj1ZbkDZ
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module e1WCAykK0;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void xuagQoPPxsvQH(int typemdt)
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
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.o3UgQoPzRdnE2();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static eILexUWtydOj1ZbkDZ()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.o3UgQoPzRdnE2();
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
					eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.o3UgQoPzRdnE2();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			public epk4JLxQrEvWi6AHPc(object P_0)
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.o3UgQoPzRdnE2();
				base..ctor();
			}
		}

		internal class eqCW27S8VxFfnK7ae3
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (e1WCAykK0(Convert.ToBase64String(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).Assembly.GetName().GetPublicKeyToken()), eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1254)) != eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1260))
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
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.o3UgQoPzRdnE2();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint epLVT0LsDNCS2M0vSw([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr rQZZiNsKu8sR8rJDJS();

		internal struct eMo8xctuZSKRfJjCaO
		{
			internal bool e1WCAykK0;

			internal byte[] eopWKtZX1;
		}

		[Flags]
		private enum SeDmngZVnXg3dEtb6P
		{

		}

		private static byte[] vwFzAcaHY;

		private static byte[] zs9ieh5Dsk;

		private static int dTcigL21Hs;

		private static bool pv0itycDUi;

		private static SortedList xc7ijIpljN;

		internal static epLVT0LsDNCS2M0vSw ebfRCcJMs;

		private static int cyGiwWQrxG;

		private static byte[] uuNisbgxdh;

		private static int B1Mi4o3tj3;

		private static int[] NXviaBfjXM;

		private static long u0CiR73gNK;

		private static object WL6iDrt844;

		private static int JUPihkefon;

		private static IntPtr DdBi8XETde;

		private static bool j5JiMuKJTm;

		internal static epLVT0LsDNCS2M0vSw eWbNGoLe6;

		private static byte[] hIqiiDHkcP;

		private static IntPtr heWiECSiIu;

		internal static Hashtable e712GIHvk;

		private static IntPtr UZjiZTqFF4;

		private static long TwuiqkAI59;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static emYpxP33xAq8jO8oJ1()
		{
			vwFzAcaHY = new byte[0];
			zs9ieh5Dsk = new byte[0];
			hIqiiDHkcP = new byte[0];
			uuNisbgxdh = new byte[0];
			UZjiZTqFF4 = IntPtr.Zero;
			heWiECSiIu = IntPtr.Zero;
			WL6iDrt844 = new string[0];
			NXviaBfjXM = new int[0];
			dTcigL21Hs = 1;
			pv0itycDUi = false;
			xc7ijIpljN = new SortedList();
			B1Mi4o3tj3 = 0;
			u0CiR73gNK = 0L;
			ebfRCcJMs = null;
			eWbNGoLe6 = null;
			TwuiqkAI59 = 0L;
			JUPihkefon = 0;
			j5JiMuKJTm = false;
			cyGiwWQrxG = 0;
			DdBi8XETde = IntPtr.Zero;
			e712GIHvk = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void lxHgQoPxT0O2y()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		static string eopWKtZX1(int P_0)
		{
			int num = 205;
			byte[] array2 = default(byte[]);
			int num7 = default(int);
			int num6 = default(int);
			byte[] array = default(byte[]);
			int num4 = default(int);
			byte[] array6 = default(byte[]);
			byte[] array3 = default(byte[]);
			byte[] array4 = default(byte[]);
			ICryptoTransform transform = default(ICryptoTransform);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			int num5 = default(int);
			CryptoStream cryptoStream = default(CryptoStream);
			byte[] array5 = default(byte[]);
			MemoryStream memoryStream = default(MemoryStream);
			BinaryReader binaryReader = default(BinaryReader);
			while (true)
			{
				int num2 = num;
				while (true)
				{
					int num3;
					switch (num2)
					{
					case 243:
						array2[16] = (byte)num7;
						num3 = 107;
						goto IL_0974;
					case 93:
						num6 = 24 + 103;
						num = 35;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 56;
					case 56:
						array2[31] = (byte)num6;
						num = 51;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 333;
					case 333:
						array[1] = 132;
						num2 = 125;
						continue;
					case 110:
						num4 = 45 + 109;
						num3 = 121;
						goto IL_0974;
					case 331:
						num7 = 251 - 83;
						num = 178;
						break;
					case 278:
						array[13] = (byte)num4;
						num = 81;
						break;
					case 237:
						num7 = 138 + 4;
						num = 263;
						break;
					case 176:
						array2[29] = 25;
						num = 332;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 4;
					case 4:
						num4 = 72 + 29;
						num3 = 20;
						goto IL_0974;
					case 225:
						array2[7] = 79;
						num = 331;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 21;
					case 11:
						num4 = 196 - 78;
						num2 = 278;
						continue;
					case 87:
						array2[12] = (byte)num7;
						num = 140;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 266;
					case 266:
						num6 = 100 + 12;
						num = 288;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 167;
					case 201:
						num7 = 125 - 41;
						num3 = 73;
						goto IL_0974;
					case 284:
						array2[15] = (byte)num7;
						num = 281;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 139;
					case 317:
						array2[16] = 172;
						num = 165;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 227;
					case 227:
						array2[17] = 131;
						num3 = 37;
						goto IL_0974;
					case 42:
						num4 = 124 + 53;
						num3 = 95;
						goto IL_0974;
					case 256:
						array2[17] = 4;
						num = 98;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 212;
					case 264:
						array2[29] = (byte)num7;
						num2 = 176;
						continue;
					case 81:
						num4 = 146 - 48;
						num = 236;
						break;
					case 107:
						array2[16] = 120;
						num = 227;
						break;
					case 233:
						num4 = 135 - 108;
						num = 29;
						break;
					case 97:
						array[8] = (byte)num4;
						num = 103;
						break;
					case 308:
						array[8] = 133;
						num = 269;
						if (true)
						{
							break;
						}
						goto case 146;
					case 146:
						array2[17] = (byte)num6;
						num3 = 256;
						goto IL_0974;
					case 213:
						array[7] = (byte)num4;
						goto case 57;
					case 132:
						num4 = 127 - 42;
						num2 = 38;
						continue;
					case 322:
						array2[31] = 166;
						num2 = 130;
						continue;
					case 58:
						num7 = 187 - 62;
						num3 = 321;
						goto IL_0974;
					case 96:
						num7 = 239 - 79;
						num3 = 272;
						goto IL_0974;
					case 343:
						array2[8] = (byte)num6;
						num = 64;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 238;
					case 238:
						array2[6] = (byte)num6;
						num2 = 114;
						continue;
					case 330:
						num7 = 69 + 101;
						num2 = 13;
						continue;
					case 13:
						array2[25] = (byte)num7;
						num2 = 25;
						continue;
					case 269:
						num4 = 59 + 124;
						num = 49;
						break;
					case 63:
						POXHpZbYJ7wEsX2PBu(true);
						num3 = 184;
						goto IL_0974;
					case 75:
						array2[18] = (byte)num6;
						num = 23;
						if (true)
						{
							break;
						}
						goto case 16;
					case 16:
						array[3] = (byte)num4;
						num = 80;
						if (0 == 0)
						{
							break;
						}
						goto case 74;
					case 74:
						array[9] = 63;
						num = 160;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 90;
					case 76:
						array[10] = (byte)num4;
						num3 = 3;
						goto IL_0974;
					case 134:
						array[12] = (byte)num4;
						num2 = 233;
						continue;
					case 109:
						array[4] = (byte)num4;
						num3 = 159;
						goto IL_0974;
					case 300:
						array[7] = 113;
						num = 232;
						break;
					case 338:
						num6 = 201 - 67;
						num = 318;
						break;
					case 150:
						array2[0] = 161;
						num2 = 0;
						continue;
					case 337:
						array2[27] = 147;
						num3 = 255;
						goto IL_0974;
					case 41:
						array2[8] = (byte)num6;
						num = 148;
						break;
					case 249:
						num4 = 210 - 70;
						num = 76;
						if (true)
						{
							break;
						}
						goto case 328;
					case 328:
						array2[4] = (byte)num7;
						num = 261;
						break;
					case 282:
						num6 = 51 + 63;
						num2 = 340;
						continue;
					case 128:
						array2[12] = (byte)num7;
						num2 = 250;
						continue;
					case 253:
						array2[8] = (byte)num7;
						num3 = 290;
						goto IL_0974;
					case 5:
						array6 = array2;
						num = 45;
						break;
					case 208:
						num6 = 150 - 50;
						num = 343;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 108;
					case 108:
						array2[10] = (byte)num7;
						num = 129;
						if (0 == 0)
						{
							break;
						}
						goto case 248;
					case 248:
						array[6] = (byte)num4;
						num = 44;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 255;
					case 255:
						num6 = 46 - 13;
						num3 = 79;
						goto IL_0974;
					case 167:
						num6 = 230 - 76;
						num = 65;
						break;
					case 272:
						array2[28] = (byte)num7;
						num3 = 105;
						goto IL_0974;
					case 261:
						array2[4] = 105;
						num2 = 93;
						continue;
					case 78:
						array2[3] = 63;
						num = 22;
						break;
					case 196:
						array[14] = 116;
						num2 = 42;
						continue;
					case 116:
						array2[28] = 115;
						num3 = 96;
						goto IL_0974;
					case 71:
						array2[26] = 99;
						num = 46;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 177;
					case 67:
						array2[31] = (byte)num6;
						num2 = 5;
						continue;
					case 214:
						array[13] = 122;
						num2 = 244;
						continue;
					case 20:
						array[11] = (byte)num4;
						num2 = 199;
						continue;
					case 288:
						array2[12] = (byte)num6;
						num = 21;
						if (0 == 0)
						{
							break;
						}
						goto case 12;
					case 12:
						num7 = 47 + 77;
						num2 = 243;
						continue;
					case 287:
						array2[13] = (byte)num7;
						num2 = 186;
						continue;
					case 38:
						array[10] = (byte)num4;
						num2 = 210;
						continue;
					case 47:
						array2[13] = (byte)num6;
						num = 58;
						if (true)
						{
							break;
						}
						goto case 211;
					case 211:
						array2[1] = 211;
						num = 247;
						if (0 == 0)
						{
							break;
						}
						goto case 334;
					case 334:
						num6 = 219 - 73;
						num = 102;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 125;
					case 125:
						num4 = 114 - 76;
						num = 138;
						break;
					case 207:
						num6 = 64 + 114;
						num3 = 276;
						goto IL_0974;
					case 60:
						array3[13] = array4[6];
						num = 179;
						break;
					case 52:
						array2[7] = (byte)num6;
						num3 = 310;
						goto IL_0974;
					case 95:
						array[15] = (byte)num4;
						num2 = 215;
						continue;
					case 168:
						array2[26] = 118;
						goto case 246;
					default:
						num = 246;
						break;
					case 245:
						array2[30] = 132;
						num = 167;
						break;
					case 126:
						array2[21] = (byte)num6;
						num = 228;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 178;
					case 332:
						array2[30] = 151;
						num3 = 175;
						goto IL_0974;
					case 321:
						array2[13] = (byte)num7;
						num3 = 191;
						goto IL_0974;
					case 301:
						array2[15] = 110;
						num = 120;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 47;
					case 299:
						array2[15] = 106;
						num = 317;
						if (true)
						{
							break;
						}
						goto case 40;
					case 40:
						array3 = array;
						num2 = 294;
						continue;
					case 6:
						array2[24] = 155;
						num = 39;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 302;
					case 302:
						array[13] = (byte)num4;
						num2 = 11;
						continue;
					case 177:
						num6 = 45 + 114;
						num2 = 75;
						continue;
					case 37:
						num6 = 80 + 9;
						num = 319;
						if (0 == 0)
						{
							break;
						}
						goto case 9;
					case 9:
						array2[29] = (byte)num6;
						num = 144;
						break;
					case 267:
						array2[9] = 123;
						num2 = 77;
						continue;
					case 105:
						num6 = 237 - 79;
						num3 = 257;
						goto IL_0974;
					case 117:
						num7 = 98 + 68;
						num3 = 264;
						goto IL_0974;
					case 53:
						num6 = 9 + 17;
						num2 = 9;
						continue;
					case 170:
						num4 = 102 + 122;
						num3 = 304;
						goto IL_0974;
					case 197:
						array[9] = (byte)num4;
						num3 = 313;
						goto IL_0974;
					case 123:
						array2[5] = 120;
						num = 320;
						break;
					case 281:
						num6 = 173 - 57;
						num3 = 283;
						goto IL_0974;
					case 315:
						array2[19] = 105;
						num3 = 59;
						goto IL_0974;
					case 342:
						num4 = 85 + 54;
						num = 262;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 313;
					case 313:
						array[9] = 71;
						num2 = 132;
						continue;
					case 239:
						num4 = 227 - 75;
						num = 259;
						break;
					case 312:
						num6 = 222 - 74;
						num = 311;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 297;
					case 295:
						array[4] = 164;
						num = 174;
						break;
					case 36:
						num7 = 135 - 45;
						num2 = 253;
						continue;
					case 0:
						num7 = 111 + 6;
						num = 203;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 204;
					case 204:
						transform = (ICryptoTransform)IITnjoOEFdAIiuBQMW(rijndaelManaged, array6, array3);
						num3 = 220;
						goto IL_0974;
					case 229:
						array[0] = 184;
						_ = 0;
						if (!VwemKk75NTvlIwtZVI())
						{
							num3 = 57;
							goto IL_0974;
						}
						num = 136;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 6;
					case 182:
						array2[7] = (byte)num6;
						num2 = 234;
						continue;
					case 323:
						num6 = 44 - 29;
						num = 194;
						if (0 == 0)
						{
							break;
						}
						goto case 115;
					case 115:
						num6 = 28 + 121;
						num2 = 235;
						continue;
					case 250:
						array2[12] = 133;
						num2 = 152;
						continue;
					case 324:
						array2[11] = 90;
						num2 = 280;
						continue;
					case 129:
						array2[11] = 195;
						num = 324;
						if (0 == 0)
						{
							break;
						}
						goto case 145;
					case 145:
						array2[19] = 127;
						num3 = 315;
						goto IL_0974;
					case 259:
						array[8] = (byte)num4;
						num3 = 308;
						goto IL_0974;
					case 89:
						num5 = GAbrUGorgVRWnyVG5w(hIqiiDHkcP, P_0);
						num2 = 346;
						continue;
					case 190:
						array[14] = (byte)num4;
						num = 196;
						if (true)
						{
							break;
						}
						goto case 31;
					case 31:
						num4 = 53 + 83;
						num = 97;
						break;
					case 164:
						num4 = 16 + 84;
						num3 = 43;
						goto IL_0974;
					case 200:
						if (array4 == null)
						{
							goto case 221;
						}
						num2 = 91;
						continue;
					case 183:
						num6 = 138 - 46;
						num3 = 292;
						goto IL_0974;
					case 246:
						array2[26] = 67;
						num = 71;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 119;
					case 180:
						num4 = 149 - 49;
						num2 = 50;
						continue;
					case 286:
						cuDh0BfQiKuqf1CWj4(cryptoStream, array5, 0, array5.Length);
						num3 = 106;
						goto IL_0974;
					case 205:
						if (hIqiiDHkcP.Length == 0)
						{
							num2 = 314;
							continue;
						}
						goto case 89;
					case 193:
						num6 = 44 + 64;
						num2 = 94;
						continue;
					case 336:
						num6 = 161 - 53;
						num2 = 238;
						continue;
					case 48:
						array2[2] = (byte)num7;
						num = 157;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 96;
					case 83:
						array[15] = (byte)num4;
						num = 40;
						break;
					case 151:
						num6 = 109 + 55;
						num3 = 182;
						goto IL_0974;
					case 191:
						num7 = 214 - 71;
						num3 = 287;
						goto IL_0974;
					case 39:
						array2[24] = 137;
						num3 = 219;
						goto IL_0974;
					case 291:
						num4 = 50 + 97;
						num2 = 195;
						continue;
					case 136:
					case 218:
						num4 = 25 + 123;
						num3 = 209;
						goto IL_0974;
					case 68:
						num6 = 143 - 47;
						num3 = 146;
						goto IL_0974;
					case 335:
						array2[0] = (byte)num7;
						num = 237;
						break;
					case 303:
						num6 = 93 + 22;
						num2 = 126;
						continue;
					case 258:
						array2[2] = (byte)num6;
						num = 24;
						if (true)
						{
							break;
						}
						goto case 94;
					case 94:
						array2[20] = (byte)num6;
						num = 242;
						break;
					case 279:
						array[4] = (byte)num4;
						num = 295;
						break;
					case 294:
						array4 = (byte[])STHLleYNiR81I7RwaZ(AOWjDHdQUHH719ly0m(PaDYMgTCsIeijlE98C(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).TypeHandle).Assembly));
						num = 200;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 137;
					case 137:
						num4 = 141 - 47;
						num = 173;
						if (true)
						{
							break;
						}
						goto case 203;
					case 203:
						array2[0] = (byte)num7;
						num3 = 28;
						goto IL_0974;
					case 118:
						array2[0] = 126;
						num = 223;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 127;
					case 127:
						array2[25] = 51;
						num = 168;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 187;
					case 187:
						num4 = 104 + 79;
						num3 = 190;
						goto IL_0974;
					case 257:
						array2[28] = (byte)num6;
						num2 = 2;
						continue;
					case 112:
						array[4] = (byte)num4;
						num3 = 156;
						goto IL_0974;
					case 188:
						array3[3] = array4[1];
						num2 = 139;
						continue;
					case 157:
						array2[2] = 123;
						num2 = 113;
						continue;
					case 275:
						CmmUDs0YMU7SQMvtZj(rijndaelManaged, CipherMode.CBC);
						num2 = 204;
						continue;
					case 149:
						array2[14] = 173;
						num3 = 301;
						goto IL_0974;
					case 307:
						array3[11] = array4[5];
						num2 = 60;
						continue;
					case 77:
						array2[9] = 100;
						num = 323;
						break;
					case 153:
						array[14] = 137;
						num = 329;
						break;
					case 79:
						array2[27] = (byte)num6;
						num2 = 326;
						continue;
					case 18:
						cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
						num3 = 286;
						goto IL_0974;
					case 222:
						array2[27] = 166;
						num = 337;
						if (0 == 0)
						{
							break;
						}
						goto case 254;
					case 254:
						num6 = 108 + 59;
						num2 = 293;
						continue;
					case 175:
						array2[30] = 127;
						num3 = 245;
						goto IL_0974;
					case 141:
						array[1] = 127;
						num2 = 333;
						continue;
					case 298:
						num6 = 217 - 72;
						num2 = 226;
						continue;
					case 133:
						array[14] = 87;
						num2 = 187;
						continue;
					case 26:
						array3[1] = array4[0];
						num3 = 188;
						goto IL_0974;
					case 192:
						array[5] = 103;
						num = 305;
						break;
					case 70:
						array[3] = 85;
						num = 164;
						if (true)
						{
							break;
						}
						goto case 297;
					case 297:
						aX8RcXEdHLAA0GRY1y(memoryStream);
						num2 = 32;
						continue;
					case 7:
						array2[6] = (byte)num6;
						num = 336;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 62;
					case 62:
						array2[31] = (byte)num7;
						num3 = 345;
						goto IL_0974;
					case 102:
						array2[22] = (byte)num6;
						num2 = 92;
						continue;
					case 162:
						array2[16] = 167;
						num = 12;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 304;
					case 304:
						array[6] = (byte)num4;
						num2 = 169;
						continue;
					case 64:
						array2[8] = 35;
						num = 267;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 231;
					case 231:
						num4 = 170 - 48;
						num3 = 83;
						goto IL_0974;
					case 98:
						array2[18] = 114;
						num = 177;
						break;
					case 85:
						array[14] = (byte)num4;
						num2 = 133;
						continue;
					case 154:
						array2[29] = (byte)num7;
						num3 = 117;
						goto IL_0974;
					case 169:
						num4 = 196 + 50;
						num3 = 248;
						goto IL_0974;
					case 276:
						array2[30] = (byte)num6;
						num2 = 322;
						continue;
					case 131:
						num6 = 81 + 48;
						num3 = 30;
						goto IL_0974;
					case 194:
						array2[9] = (byte)num6;
						num = 143;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 216;
					case 216:
						num7 = 102 + 37;
						num3 = 155;
						goto IL_0974;
					case 277:
						num4 = 49 - 39;
						num3 = 90;
						goto IL_0974;
					case 30:
						array2[5] = (byte)num6;
						num = 123;
						break;
					case 91:
						if (array4.Length <= 0)
						{
							goto case 221;
						}
						num2 = 26;
						continue;
					case 340:
						array2[14] = (byte)num6;
						num2 = 149;
						continue;
					case 283:
						array2[15] = (byte)num6;
						num2 = 299;
						continue;
					case 268:
						array2[3] = (byte)num6;
						num2 = 115;
						continue;
					case 143:
						array2[10] = 167;
						num2 = 312;
						continue;
					case 285:
						array2[11] = 192;
						num3 = 266;
						goto IL_0974;
					case 21:
						num7 = 94 + 67;
						num2 = 128;
						continue;
					case 189:
						array2[25] = (byte)num6;
						num2 = 330;
						continue;
					case 206:
						num4 = 121 + 49;
						num2 = 134;
						continue;
					case 57:
					case 260:
						array[7] = 108;
						num2 = 110;
						continue;
					case 113:
						num6 = 114 - 95;
						num2 = 258;
						continue;
					case 244:
						num4 = 156 - 52;
						num2 = 17;
						continue;
					case 45:
						array = new byte[16];
						num = 185;
						if (0 == 0)
						{
							break;
						}
						goto case 124;
					case 124:
						num7 = 114 + 115;
						num = 284;
						if (true)
						{
							break;
						}
						goto case 104;
					case 104:
						array2[29] = 166;
						num = 53;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 54;
					case 72:
						array2[20] = 195;
						num2 = 193;
						continue;
					case 148:
						array2[8] = 107;
						num2 = 208;
						continue;
					case 235:
						array2[3] = (byte)num6;
						num = 78;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 73;
					case 73:
						array2[19] = (byte)num7;
						num = 217;
						if (true)
						{
							break;
						}
						goto case 135;
					case 135:
						num4 = 79 + 63;
						num3 = 109;
						goto IL_0974;
					case 290:
						num6 = 84 + 52;
						num2 = 41;
						continue;
					case 144:
						num7 = 38 + 42;
						num3 = 154;
						goto IL_0974;
					case 309:
						array2[18] = (byte)num6;
						num = 198;
						break;
					case 185:
						array[0] = 126;
						num = 158;
						break;
					case 101:
						num4 = 152 + 55;
						num = 100;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 183;
					case 240:
						num6 = 185 - 61;
						num = 161;
						break;
					case 293:
						array2[14] = (byte)num6;
						num2 = 282;
						continue;
					case 14:
						num7 = 107 + 42;
						num2 = 328;
						continue;
					case 159:
						num4 = 55 + 101;
						num2 = 112;
						continue;
					case 106:
						nZaHZE213hR0v53evW(cryptoStream);
						num = 34;
						if (true)
						{
							break;
						}
						goto case 161;
					case 161:
						array2[4] = (byte)num6;
						num = 14;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 184;
					case 184:
						array5 = (byte[])FrwVlNwdr7yosUtjoW(binaryReader, (int)KLM3nmS38ItKKbnWGk(lPviGBMSBtX7FJvC6x(binaryReader)));
						num3 = 344;
						goto IL_0974;
					case 305:
						array[5] = 44;
						num3 = 265;
						goto IL_0974;
					case 23:
						array2[18] = 78;
						num2 = 270;
						continue;
					case 217:
						array2[19] = 156;
						num3 = 145;
						goto IL_0974;
					case 54:
						array2[22] = 215;
						num = 334;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 314;
					case 345:
						array2[31] = 220;
						num2 = 82;
						continue;
					case 33:
						array[11] = 46;
						num = 163;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 155;
					case 219:
						array2[25] = 91;
						num2 = 84;
						continue;
					case 195:
						array[5] = (byte)num4;
						num = 137;
						break;
					case 1:
						array2[23] = 144;
						num = 111;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 267;
					case 247:
						array2[2] = 108;
						num = 341;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 325;
					case 320:
						num7 = 66 - 46;
						num = 325;
						if (0 == 0)
						{
							break;
						}
						goto case 44;
					case 44:
						num4 = 98 + 2;
						num3 = 213;
						goto IL_0974;
					case 223:
						num7 = 21 + 118;
						num2 = 335;
						continue;
					case 251:
						array2[11] = (byte)num6;
						num3 = 216;
						goto IL_0974;
					case 163:
						array[12] = 90;
						num2 = 172;
						continue;
					case 296:
						num6 = 129 - 46;
						num2 = 67;
						continue;
					case 210:
						array[10] = 156;
						num = 249;
						if (0 == 0)
						{
							break;
						}
						goto case 82;
					case 82:
						array2[31] = 150;
						num = 296;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 262;
					case 262:
						array[3] = (byte)num4;
						num2 = 70;
						continue;
					case 90:
						array[2] = (byte)num4;
						num = 342;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 163;
					case 319:
						array2[17] = (byte)num6;
						num = 68;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 147;
					case 88:
						IigNOI66DjQPuWCUhC(lPviGBMSBtX7FJvC6x(binaryReader), 0L);
						num3 = 63;
						goto IL_0974;
					case 280:
						num6 = 136 - 45;
						num2 = 251;
						continue;
					case 173:
						array[5] = (byte)num4;
						num3 = 192;
						goto IL_0974;
					case 25:
						num6 = 197 - 65;
						num3 = 252;
						goto IL_0974;
					case 263:
						array2[0] = (byte)num7;
						num = 19;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 17;
					case 17:
						array[13] = (byte)num4;
						num = 180;
						if (true)
						{
							break;
						}
						goto case 198;
					case 198:
						array2[19] = 110;
						num = 202;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 252;
					case 252:
						array2[25] = (byte)num6;
						num = 127;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 130;
					case 130:
						num6 = 225 - 75;
						num3 = 56;
						goto IL_0974;
					case 226:
						array2[15] = (byte)num6;
						num = 124;
						break;
					case 122:
						array[2] = (byte)num4;
						num2 = 277;
						continue;
					case 271:
						num4 = 120 + 71;
						num = 16;
						break;
					case 103:
						num4 = 133 - 44;
						num = 142;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 181;
					case 181:
						array2[11] = 167;
						num = 285;
						break;
					case 114:
						array2[6] = 140;
						num3 = 225;
						goto IL_0974;
					case 230:
						array[0] = (byte)num4;
						num = 229;
						break;
					case 289:
						array2[20] = (byte)num6;
						num3 = 72;
						goto IL_0974;
					case 172:
						array[12] = 72;
						num2 = 206;
						continue;
					case 274:
						num7 = 72 + 72;
						num = 108;
						if (true)
						{
							break;
						}
						goto case 310;
					case 310:
						array2[8] = 116;
						num3 = 36;
						goto IL_0974;
					case 341:
						num7 = 140 - 46;
						num2 = 48;
						continue;
					case 178:
						array2[7] = (byte)num7;
						num3 = 15;
						goto IL_0974;
					case 84:
						num6 = 122 + 104;
						num3 = 189;
						goto IL_0974;
					case 120:
						array2[15] = 163;
						num3 = 298;
						goto IL_0974;
					case 171:
						num6 = 210 - 70;
						num = 7;
						break;
					case 147:
						array2[19] = (byte)num7;
						num3 = 201;
						goto IL_0974;
					case 92:
						array2[22] = 196;
						num2 = 99;
						continue;
					case 158:
						num4 = 210 - 70;
						num3 = 230;
						goto IL_0974;
					case 344:
						array2 = new byte[32];
						num2 = 150;
						continue;
					case 80:
						num4 = 143 - 47;
						num3 = 279;
						goto IL_0974;
					case 236:
						array[14] = (byte)num4;
						num3 = 153;
						goto IL_0974;
					case 65:
						array2[30] = (byte)num6;
						num2 = 119;
						continue;
					case 202:
						num7 = 229 - 76;
						num = 147;
						if (true)
						{
							break;
						}
						goto case 50;
					case 50:
						array[13] = (byte)num4;
						num2 = 69;
						continue;
					case 209:
						array[1] = (byte)num4;
						num = 10;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 223;
					case 199:
						array[11] = 156;
						num = 33;
						break;
					case 327:
						num6 = 97 + 78;
						num3 = 289;
						goto IL_0974;
					case 55:
						array3[7] = array4[3];
						num = 316;
						break;
					case 215:
						array[15] = 127;
						num2 = 231;
						continue;
					case 234:
						num6 = 22 - 9;
						num2 = 52;
						continue;
					case 51:
						num7 = 145 - 48;
						num = 62;
						if (0 == 0)
						{
							break;
						}
						goto case 314;
					case 314:
						binaryReader = new BinaryReader((Stream)WH6ZetBLaiQQiDRR8a(PaDYMgTCsIeijlE98C(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).TypeHandle).Assembly, "1dXgnTultvr7Lt8CUP.fA2X4AafbE0lrEZYC3"));
						num3 = 88;
						goto IL_0974;
					case 100:
						array[10] = (byte)num4;
						num2 = 4;
						continue;
					case 139:
						array3[5] = array4[2];
						num3 = 55;
						goto IL_0974;
					case 329:
						num4 = 99 + 14;
						num2 = 85;
						continue;
					case 174:
						array[4] = 86;
						num = 135;
						if (true)
						{
							break;
						}
						goto case 111;
					case 111:
						array2[23] = 253;
						num2 = 224;
						continue;
					case 121:
						array[7] = (byte)num4;
						num = 300;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 204;
					case 10:
						array[1] = 100;
						num3 = 141;
						goto IL_0974;
					case 325:
						array2[5] = (byte)num7;
						num3 = 171;
						goto IL_0974;
					case 166:
						qPnPbNhmrggxvxi00K(binaryReader);
						num2 = 89;
						continue;
					case 160:
						num4 = 151 - 50;
						num2 = 197;
						continue;
					case 212:
						num6 = 125 + 116;
						num = 309;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 316;
					case 316:
						array3[9] = array4[4];
						num3 = 307;
						goto IL_0974;
					case 273:
						array2[1] = 91;
						num = 211;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 147;
					case 241:
						array[4] = (byte)num4;
						num2 = 291;
						continue;
					case 2:
						array2[28] = 94;
						num2 = 104;
						continue;
					case 140:
						num6 = 71 + 109;
						num3 = 47;
						goto IL_0974;
					case 19:
						array2[1] = 91;
						num3 = 273;
						goto IL_0974;
					case 24:
						num6 = 108 + 2;
						num = 268;
						break;
					case 22:
						array2[3] = 72;
						num2 = 240;
						continue;
					case 61:
						array2[21] = 88;
						num2 = 303;
						continue;
					case 43:
						array[3] = (byte)num4;
						num = 271;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 232;
					case 232:
						array[7] = 143;
						num = 239;
						if (0 == 0)
						{
							break;
						}
						goto case 27;
					case 27:
						array2[5] = 64;
						num3 = 131;
						goto IL_0974;
					case 3:
						array[10] = 159;
						num = 101;
						if (true)
						{
							break;
						}
						goto case 265;
					case 265:
						array[6] = 158;
						num2 = 170;
						continue;
					case 29:
						array[12] = (byte)num4;
						num = 86;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 292;
					case 292:
						array2[18] = (byte)num6;
						num2 = 212;
						continue;
					case 228:
						array2[21] = 89;
						num3 = 54;
						goto IL_0974;
					case 142:
						array[9] = (byte)num4;
						num2 = 74;
						continue;
					case 66:
						array[2] = 137;
						num = 8;
						break;
					case 49:
						array[8] = (byte)num4;
						num3 = 31;
						goto IL_0974;
					case 156:
						num4 = 152 + 23;
						num2 = 241;
						continue;
					case 32:
						aX8RcXEdHLAA0GRY1y(cryptoStream);
						num3 = 166;
						goto IL_0974;
					case 59:
						array2[20] = 117;
						num = 327;
						if (0 == 0)
						{
							break;
						}
						goto case 28;
					case 28:
						array2[0] = 163;
						num = 118;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 56;
					case 318:
						array2[12] = (byte)num6;
						num = 339;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 31;
					case 119:
						array2[30] = 126;
						num2 = 207;
						continue;
					case 99:
						array2[23] = 146;
						num = 1;
						if (!NNrVcIq9dXyIAlC5cr())
						{
							break;
						}
						goto case 8;
					case 8:
						num4 = 121 + 87;
						num3 = 122;
						goto IL_0974;
					case 224:
						array2[24] = 108;
						num3 = 6;
						goto IL_0974;
					case 69:
						num4 = 246 - 82;
						num = 302;
						if (true)
						{
							break;
						}
						goto case 34;
					case 34:
						hIqiiDHkcP = (byte[])YZHQHeNIQQ28jF2xoj(memoryStream);
						num = 297;
						if (true)
						{
							break;
						}
						goto case 86;
					case 86:
						array[13] = 153;
						num3 = 214;
						goto IL_0974;
					case 306:
						array2[7] = 174;
						num3 = 151;
						goto IL_0974;
					case 179:
						array3[15] = array4[7];
						num2 = 221;
						continue;
					case 46:
						array2[27] = 203;
						num3 = 222;
						goto IL_0974;
					case 165:
						array2[16] = 86;
						num = 162;
						break;
					case 326:
						array2[28] = 62;
						num2 = 116;
						continue;
					case 186:
						array2[13] = 98;
						num = 254;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 339;
					case 339:
						num7 = 143 + 13;
						num = 87;
						break;
					case 152:
						array2[12] = 131;
						num = 338;
						break;
					case 242:
						array2[20] = 87;
						num = 61;
						if (VwemKk75NTvlIwtZVI())
						{
							break;
						}
						goto case 336;
					case 270:
						array2[18] = 122;
						num2 = 183;
						continue;
					case 35:
						array2[4] = (byte)num6;
						num2 = 27;
						continue;
					case 311:
						array2[10] = (byte)num6;
						num3 = 274;
						goto IL_0974;
					case 155:
						array2[11] = (byte)num7;
						num3 = 181;
						goto IL_0974;
					case 15:
						array2[7] = 124;
						num3 = 306;
						goto IL_0974;
					case 138:
						array[1] = (byte)num4;
						num = 66;
						if (0 == 0)
						{
							break;
						}
						goto case 346;
					case 346:
						try
						{
							return (string)hgtQcNxWNK7Hxy8c1x(VMqE7vJsVXMIgvxF2q(), hIqiiDHkcP, P_0 + 4, num5);
						}
						catch
						{
						}
						return "";
					case 221:
						rijndaelManaged = new RijndaelManaged();
						num = 275;
						if (0 == 0)
						{
							break;
						}
						goto case 323;
					case 220:
						{
							memoryStream = new MemoryStream();
							num3 = 18;
							goto IL_0974;
						}
						IL_0974:
						num = num3;
						break;
					}
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
		private static extern void Sd4Jy1M6l(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int V0gpepnG9(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr eQ7GFE5Gm(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void igFOagR7d()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void uLPrLr0NO()
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
		private static extern int lj2PsbuPO(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int UynNleUus(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int goa39RcnP(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr rCg9xD2nQ(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int yY1d4lrVh(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		private static byte[] AA7BYUNvW(string P_0)
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
		private static byte[] YNEXu1t64(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				31, 103, 66, 239, 242, 106, 142, 137, 224, 28,
				179, 94, 167, 194, 144, 105, 1, 224, 85, 109,
				71, 89, 120, 77, 92, 119, 146, 190, 181, 239,
				202, 173
			};
			rijndael.IV = new byte[16]
			{
				55, 42, 119, 241, 78, 143, 192, 50, 70, 47,
				212, 204, 210, 250, 167, 165
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] i90n7g5pA()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] S8buUIUuN()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] AHfUUQTfW()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] SSd0KwvH7()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] t5lQ2BCaL()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] NmJGGWHf8()
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
		internal static Type PaDYMgTCsIeijlE98C(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object WH6ZetBLaiQQiDRR8a(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object lPviGBMSBtX7FJvC6x(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void IigNOI66DjQPuWCUhC(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void POXHpZbYJ7wEsX2PBu(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long KLM3nmS38ItKKbnWGk(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object FrwVlNwdr7yosUtjoW(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object AOWjDHdQUHH719ly0m(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object STHLleYNiR81I7RwaZ(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void CmmUDs0YMU7SQMvtZj(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object IITnjoOEFdAIiuBQMW(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void cuDh0BfQiKuqf1CWj4(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void nZaHZE213hR0v53evW(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object YZHQHeNIQQ28jF2xoj(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void aX8RcXEdHLAA0GRY1y(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void qPnPbNhmrggxvxi00K(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int GAbrUGorgVRWnyVG5w(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object VMqE7vJsVXMIgvxF2q()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object hgtQcNxWNK7Hxy8c1x(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool VwemKk75NTvlIwtZVI()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool NNrVcIq9dXyIAlC5cr()
		{
			return false;
		}
	}
}
namespace eoP53YVgQa1lbB0Xy6
{
	internal class eGujxxQN0KjsXHehk2
	{
		private static bool omQiY1oQyR;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void o3UgQoPzRdnE2()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public eGujxxQN0KjsXHehk2()
		{
		}
	}
}
