using System;
using System.Collections;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.ComTypes;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using System.Threading;
using COLLECTIONLib;
using Cummins.INSITE.CNL.Common;
using Cummins.INSITE.CNL.Monitors;
using ECMSERVICESAPILib;
using ECMSERVICESEVENTSLib;
using F8k2iNaHsEsEqN8yJY;
using FYEPOGma9kMq7fvgUV;
using KXkrH8U9DjglUpr456;
using L910u0iv2rou2mMGuS;
using dGEDhfPaJFHpNX0S8x;
using sNRQPmddsh7lJRKOQ3;
using zFj788rbVbJ0ddpfyA;

[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: CompilationRelaxations(8)]
[assembly: Guid("c5425de8-932b-4524-9718-1cfee8dbb021")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyDescription("Cummins .NET Libraries Monitors Component")]
[assembly: AssemblyConfiguration("")]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyTitle("Cummins.CNL.Monitors")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(true)]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyProduct("INSITE")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace tif0eryHvNn6qWqEep
{
	internal static class TTKNpH2crkwOu87cCs
	{
	}
}
namespace F8k2iNaHsEsEqN8yJY
{
	internal class jo6UUheG6gGRwNSiHU
	{
		private const string AX3srxdUQ = "100";

		private const string P9HXJUnx0 = "0";

		private string[] A5multN4L;

		private IEnumerations W2dC533lW;

		private IParameterDefinitions vGbWPL4ug;

		private IModules YYrc22aEl;

		private Dictionary<int, Dictionary<string, double>> yoe2yt6uZ;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public jo6UUheG6gGRwNSiHU(object P_0)
		{
			En9RagAMcX2rgK6BaU.CL6Ugf7z0ohmP();
			A5multN4L = new string[1] { vKNfOaX0MCxOqDs2ZG.aVjgE872eU(0) };
			base..ctor();
			yoe2yt6uZ = new Dictionary<int, Dictionary<string, double>>();
			IECMServices iECMServices = (IECMServices)P_0;
			vGbWPL4ug = iECMServices.ParameterDefinitions;
			W2dC533lW = iECMServices.Enumerations;
			YYrc22aEl = iECMServices.Connections.get_Item((object)iECMServices.ActiveConnectionID).System.Modules;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public double MCQgb191k(int P_0, long P_1, string P_2)
		{
			double result = 0.0;
			int moduleType = -1;
			for (int i = 1; i <= YYrc22aEl.Count; i++)
			{
				IModule module = YYrc22aEl.get_Item((object)i);
				if (module.ID == P_0.ToString())
				{
					moduleType = module.ModuleType;
					break;
				}
			}
			IParameterDefinition parameterDefinition = vGbWPL4ug.GetParameterDefinition(P_1.ToString(), moduleType);
			string unitId = parameterDefinition.unitId;
			int num = int.Parse(parameterDefinition.enumerationId);
			if (num == 0)
			{
				string text;
				if ((text = unitId) == null)
				{
					goto IL_011f;
				}
				if (!(text == vKNfOaX0MCxOqDs2ZG.aVjgE872eU(6)))
				{
					if (!(text == vKNfOaX0MCxOqDs2ZG.aVjgE872eU(16)))
					{
						goto IL_011f;
					}
					result = 0.0;
				}
				else
				{
					string[] array = P_2.Split(A5multN4L, StringSplitOptions.RemoveEmptyEntries);
					result = long.Parse(array[0]) * 3600 + long.Parse(array[1]) * 60 + long.Parse(array[2]);
				}
			}
			else if (yoe2yt6uZ.ContainsKey(num))
			{
				result = yoe2yt6uZ[num][P_2];
			}
			else
			{
				IEnumeration enumeration = W2dC533lW.GetEnumeration(num.ToString());
				BSTRCollection values = enumeration.Values;
				BSTRCollection enumRawValues = enumeration.EnumRawValues;
				yoe2yt6uZ.Add(num, new Dictionary<string, double>());
				for (int j = 1; j <= values.Count; j++)
				{
					string text2 = ((IBSTRCollection)values).get_Item(j);
					double num2 = double.Parse(((IBSTRCollection)enumRawValues).get_Item(j));
					yoe2yt6uZ[num].Add(text2, num2);
					if (P_2 == text2)
					{
						result = num2;
					}
				}
			}
			goto IL_01eb;
			IL_011f:
			result = double.Parse(P_2);
			goto IL_01eb;
			IL_01eb:
			return result;
		}
	}
}
namespace Cummins.INSITE.CNL.Monitors
{
	public interface IMonitorManager
	{
		long SamplingRate { get; set; }

		NotificationTriggerType NotificationTriggerType { get; set; }

		bool EnableLogging { get; set; }

		ClientContextInfo ClientContextInfo { get; set; }

		event EventHandler<MonitorDataChangedEventArgs> MonitorDataChanged;

		event OnDataUpdatedDelegate OnDataUpdated;

		void Initialize(object kernel, int pollingRate, int updateRate);

		void AddEventMarker(long eventId);

		void AddEventDescription(long eventId, string eventDescription);

		void AddMonitoredParameters(string[] parameterIds, int moduleId);

		void AddMonitoredParameter(string parameterId, int moduleId);

		void RemoveMonitoredParameter(string parameterId, int moduleId);

		void ClearMonitoredParameters();

		void StartMonitoring();

		void StopMonitoring();

		void SaveLogFile(string fileName);

		void SetLogFileHeader(Dictionary<string, string> logHeaderInformation);
	}
}
namespace dGEDhfPaJFHpNX0S8x
{
	internal class AdiTedJDb7VX8ZheBB
	{
		private IMonitorService P8sjx0Y6s;

		private IMonitors hwlDmJw4m;

		private Dictionary<int, Ur96UyYkBCs61C6Ogv> UqWOQvpqP;

		private Dictionary<string, string> GtQpbdi9F;

		private bool tmt6CyoE2;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public AdiTedJDb7VX8ZheBB(IMonitorService P_0)
		{
			En9RagAMcX2rgK6BaU.CL6Ugf7z0ohmP();
			base..ctor();
			P8sjx0Y6s = P_0;
			hwlDmJw4m = null;
			UqWOQvpqP = null;
			tmt6CyoE2 = false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public IMonitors mDgV6ioOq()
		{
			return hwlDmJw4m;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public void cnR8FfBHF(IMonitors P_0)
		{
			hwlDmJw4m = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public Dictionary<int, Ur96UyYkBCs61C6Ogv> u0H7aL48v()
		{
			return UqWOQvpqP;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public void tx2qVk7KX(Dictionary<int, Ur96UyYkBCs61C6Ogv> value)
		{
			UqWOQvpqP = value;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void P8Dtuum2L()
		{
			JIMNrkjCE();
			if (hwlDmJw4m != null)
			{
				ILog log = hwlDmJw4m.get_Monitor(UqWOQvpqP[0].aavEeEPPx).Logger.Log;
				ILogWriter logWriter = (ILogWriter)log;
				Dictionary<string, string>.Enumerator enumerator = GtQpbdi9F.GetEnumerator();
				while (enumerator.MoveNext())
				{
					logWriter.SetHeaderItem(enumerator.Current.Key, enumerator.Current.Value);
				}
			}
			foreach (Ur96UyYkBCs61C6Ogv value in UqWOQvpqP.Values)
			{
				IMonitor monitor = hwlDmJw4m.get_Monitor(value.aavEeEPPx);
				monitor.Logger.IsActive = true;
				monitor.NotifyMonitorOfLoggerStart();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void W8E0qaBTE()
		{
			foreach (Ur96UyYkBCs61C6Ogv value in UqWOQvpqP.Values)
			{
				IMonitor monitor = hwlDmJw4m.get_Monitor(value.aavEeEPPx);
				monitor.Logger.IsActive = false;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void vW1SNDajm(string P_0)
		{
			if (hwlDmJw4m != null)
			{
				ILog log = hwlDmJw4m.get_Monitor(UqWOQvpqP[0].aavEeEPPx).Logger.Log;
				ILogWriter logWriter = (ILogWriter)log;
				CultureInfo cultureInfo = new CultureInfo(vKNfOaX0MCxOqDs2ZG.aVjgE872eU(22));
				logWriter.LogStopTime = DateTime.Now.ToString(vKNfOaX0MCxOqDs2ZG.aVjgE872eU(36), cultureInfo);
				log.TransferSourceToDestination("", P_0);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void y3PxxyDTy(Dictionary<string, string> logHeaderInfo)
		{
			GtQpbdi9F = logHeaderInfo;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void yElTGROCV(long P_0)
		{
			if (hwlDmJw4m != null)
			{
				ILogger logger = hwlDmJw4m.get_Monitor(UqWOQvpqP[0].aavEeEPPx).Logger;
				logger.AddEventMarker((int)P_0);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void kJJ3w32IS(long P_0, string P_1)
		{
			if (hwlDmJw4m != null)
			{
				ILogger logger = hwlDmJw4m.get_Monitor(UqWOQvpqP[0].aavEeEPPx).Logger;
				logger.AddEventMarkerDescription((int)P_0, P_1);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void JIMNrkjCE()
		{
			if (tmt6CyoE2)
			{
				return;
			}
			ILog log = P8sjx0Y6s.CreateLog();
			log.AutoWriteFrequency = 300;
			ILogWriter logWriter = (ILogWriter)log;
			logWriter.DestinationName = Path.GetTempFileName();
			foreach (Ur96UyYkBCs61C6Ogv value in UqWOQvpqP.Values)
			{
				hwlDmJw4m.get_Monitor(value.aavEeEPPx).Logger.Log = log;
			}
			tmt6CyoE2 = true;
		}
	}
}
namespace L910u0iv2rou2mMGuS
{
	internal struct Ur96UyYkBCs61C6Ogv
	{
		public int aavEeEPPx;

		public string Y9InKIEP2;

		public List<string> atJrxExtl;
	}
}
namespace Cummins.INSITE.CNL.Monitors
{
	public enum NotificationTriggerType
	{
		DataChanged,
		Timer
	}
	public delegate void OnDataUpdatedDelegate(MonitoredParameterCollection ParameterCollection);
	public class MonitoredParameterCollection
	{
		private readonly List<MonitoredParameterInfo> gIEHEYC5S;

		public int Count
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return gIEHEYC5S.Count;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MonitoredParameterCollection(List<MonitoredParameterInfo> monitoredParams)
		{
			En9RagAMcX2rgK6BaU.CL6Ugf7z0ohmP();
			base..ctor();
			gIEHEYC5S = monitoredParams;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void GetParameterInfo(int index, out int ModuleId, out long ParameterId, out string DisplayValue, out double RawValue)
		{
			if (index < 0 || index > gIEHEYC5S.Count)
			{
				throw new IndexOutOfRangeException();
			}
			MonitoredParameterInfo monitoredParameterInfo = gIEHEYC5S[index];
			ModuleId = monitoredParameterInfo.ModuleId;
			ParameterId = monitoredParameterInfo.ParameterId;
			DisplayValue = monitoredParameterInfo.DisplayValue;
			RawValue = monitoredParameterInfo.RawValue;
		}
	}
}
namespace FYEPOGma9kMq7fvgUV
{
	internal class X2tOVcMPtN4wroKVJ0
	{
		private const long KN04vWDjR = 250L;

		private NotificationTriggerType pGBlhDOlF;

		private long HtsBPVZMV;

		private Thread noVIbcRVw;

		private u9jqrpBSlhCNFweeh3 MJyPWrCgE;

		private ManualResetEvent HjYiDpkgX;

		private OnDataUpdatedDelegate cwkaBnOHA;

		public event OnDataUpdatedDelegate oNEbod9m9
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				OnDataUpdatedDelegate onDataUpdatedDelegate = cwkaBnOHA;
				OnDataUpdatedDelegate onDataUpdatedDelegate2;
				do
				{
					onDataUpdatedDelegate2 = onDataUpdatedDelegate;
					OnDataUpdatedDelegate value2 = (OnDataUpdatedDelegate)Delegate.Combine(onDataUpdatedDelegate2, b);
					onDataUpdatedDelegate = Interlocked.CompareExchange(ref cwkaBnOHA, value2, onDataUpdatedDelegate2);
				}
				while ((object)onDataUpdatedDelegate != onDataUpdatedDelegate2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				OnDataUpdatedDelegate onDataUpdatedDelegate = cwkaBnOHA;
				OnDataUpdatedDelegate onDataUpdatedDelegate2;
				do
				{
					onDataUpdatedDelegate2 = onDataUpdatedDelegate;
					OnDataUpdatedDelegate value2 = (OnDataUpdatedDelegate)Delegate.Remove(onDataUpdatedDelegate2, value3);
					onDataUpdatedDelegate = Interlocked.CompareExchange(ref cwkaBnOHA, value2, onDataUpdatedDelegate2);
				}
				while ((object)onDataUpdatedDelegate != onDataUpdatedDelegate2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public X2tOVcMPtN4wroKVJ0(ref u9jqrpBSlhCNFweeh3 P_0)
		{
			En9RagAMcX2rgK6BaU.CL6Ugf7z0ohmP();
			HtsBPVZMV = 250L;
			base..ctor();
			MJyPWrCgE = P_0;
			HjYiDpkgX = new ManualResetEvent(initialState: false);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void sF4MZdCi3()
		{
			while (true)
			{
				try
				{
					OnDataUpdatedDelegate onDataUpdatedDelegate = cwkaBnOHA;
					if (onDataUpdatedDelegate == null)
					{
						continue;
					}
					List<MonitoredParameterInfo> list = null;
					switch (pGBlhDOlF)
					{
					case NotificationTriggerType.Timer:
						list = MJyPWrCgE.OQDgjbHScI();
						break;
					case NotificationTriggerType.DataChanged:
					{
						list = new List<MonitoredParameterInfo>();
						List<MonitoredParameterInfo>.Enumerator enumerator = MJyPWrCgE.OQDgjbHScI().GetEnumerator();
						while (enumerator.MoveNext())
						{
							if (enumerator.Current.ValueChanged)
							{
								list.Add(enumerator.Current);
							}
						}
						break;
					}
					}
					onDataUpdatedDelegate?.Invoke(new MonitoredParameterCollection(list));
				}
				finally
				{
					HjYiDpkgX.WaitOne((int)HtsBPVZMV, exitContext: false);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void mEEmFAb9j()
		{
			if (cwkaBnOHA != null)
			{
				if (noVIbcRVw == null)
				{
					noVIbcRVw = new Thread(sF4MZdCi3);
				}
				HjYiDpkgX.Reset();
				noVIbcRVw.Start();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void WuMRn0SHS()
		{
			if (noVIbcRVw != null)
			{
				HjYiDpkgX.Set();
				noVIbcRVw.Abort();
				noVIbcRVw = null;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public NotificationTriggerType eFUe8tFpB()
		{
			return pGBlhDOlF;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public void yLkGtS5Wf(NotificationTriggerType P_0)
		{
			pGBlhDOlF = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public long awvZ3whqB()
		{
			return HtsBPVZMV;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public void rOchV5oc6(long P_0)
		{
			if (P_0 < 250)
			{
				HtsBPVZMV = 250L;
			}
			else
			{
				HtsBPVZMV = P_0;
			}
		}
	}
}
namespace Cummins.INSITE.CNL.Monitors
{
	public sealed class MonitorDataChangedEventArgs : EventArgs
	{
		private int wPu1Ghmiw;

		private string iJNoH2n2n;

		private string mRCkCf9bZ;

		public int ModuleId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return wPu1Ghmiw;
			}
		}

		public string ParameterId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return iJNoH2n2n;
			}
		}

		public string ParameterDisplayValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return mRCkCf9bZ;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MonitorDataChangedEventArgs(int moduleId, string parameterId, string parameterDisplayValue)
		{
			En9RagAMcX2rgK6BaU.CL6Ugf7z0ohmP();
			base..ctor();
			wPu1Ghmiw = moduleId;
			iJNoH2n2n = parameterId;
			mRCkCf9bZ = parameterDisplayValue;
		}
	}
	public sealed class MonitorManager : DisposableObject, IMonitorEvents, IMonitorManager, IMonitorDataChangedEvent
	{
		private EventHandler<MonitorDataChangedEventArgs> k5pQLJTpO;

		private object wgJdPUHi9;

		private IECMServices er5LZFnY7;

		private IConnection ltNyQkRjo;

		private bool x12zTZSCZ;

		private int VV0gfcviTK;

		private IMonitors fG2ggTQRpj;

		private IConnectionPoint x3QgsqWP8Q;

		private int oCSgXDMJ9K;

		private Dictionary<int, Ur96UyYkBCs61C6Ogv> Bntgu1H3K1;

		private int s17gCB1Jpm;

		private int Xm1gWHr0Nq;

		private u9jqrpBSlhCNFweeh3 vrNgcsbgSZ;

		private X2tOVcMPtN4wroKVJ0 dqYg2CkncS;

		private jo6UUheG6gGRwNSiHU A3MgtovOJ5;

		private bool pPFg0UaZdW;

		private bool DxFgSbJCfv;

		private AdiTedJDb7VX8ZheBB A1rgxT6DDQ;

		private ClientContextInfo oHYgTrhLwZ;

		public NotificationTriggerType NotificationTriggerType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return dqYg2CkncS.eFUe8tFpB();
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				dqYg2CkncS.yLkGtS5Wf(value);
			}
		}

		public long SamplingRate
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return dqYg2CkncS.awvZ3whqB();
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				dqYg2CkncS.rOchV5oc6(value);
			}
		}

		public bool EnableLogging
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return DxFgSbJCfv;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				DxFgSbJCfv = value;
			}
		}

		public ClientContextInfo ClientContextInfo
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return oHYgTrhLwZ;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				oHYgTrhLwZ = value;
			}
		}

		public event EventHandler<MonitorDataChangedEventArgs> MonitorDataChanged
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				k5pQLJTpO = (EventHandler<MonitorDataChangedEventArgs>)Delegate.Combine(k5pQLJTpO, value);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				k5pQLJTpO = (EventHandler<MonitorDataChangedEventArgs>)Delegate.Remove(k5pQLJTpO, value);
			}
		}

		public event OnDataUpdatedDelegate OnDataUpdated
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				dqYg2CkncS.oNEbod9m9 += value;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				dqYg2CkncS.oNEbod9m9 -= value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Initialize(object kernel)
		{
			Initialize(kernel, 0, 0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Initialize(object kernel, int pollingRate, int updateRate)
		{
			if (kernel == null)
			{
				throw new ArgumentNullException(vKNfOaX0MCxOqDs2ZG.aVjgE872eU(80));
			}
			if (pollingRate < 0)
			{
				throw new ArgumentException(vKNfOaX0MCxOqDs2ZG.aVjgE872eU(96));
			}
			if (updateRate < 0)
			{
				throw new ArgumentException(vKNfOaX0MCxOqDs2ZG.aVjgE872eU(178));
			}
			wgJdPUHi9 = kernel;
			er5LZFnY7 = (IECMServices)wgJdPUHi9;
			s17gCB1Jpm = pollingRate;
			Xm1gWHr0Nq = updateRate;
			Bntgu1H3K1 = new Dictionary<int, Ur96UyYkBCs61C6Ogv>();
			vrNgcsbgSZ = new u9jqrpBSlhCNFweeh3();
			dqYg2CkncS = new X2tOVcMPtN4wroKVJ0(ref vrNgcsbgSZ);
			dqYg2CkncS.rOchV5oc6(updateRate);
			A3MgtovOJ5 = new jo6UUheG6gGRwNSiHU(kernel);
			pPFg0UaZdW = false;
			DxFgSbJCfv = false;
			oHYgTrhLwZ = ClientContextInfo.DEFAULT;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Gnj9i105a()
		{
			IConnectionPointContainer connectionPointContainer = (IConnectionPointContainer)er5LZFnY7.ConnectionPointServer;
			Guid riid = new Guid(EnumUtils.GetStringValue(EventIDs.MonitorEvents));
			connectionPointContainer.FindConnectionPoint(ref riid, out x3QgsqWP8Q);
			x3QgsqWP8Q.Advise(this, out oCSgXDMJ9K);
			ltNyQkRjo = er5LZFnY7.Connections.get_Item((object)er5LZFnY7.ActiveConnectionID);
			VV0gfcviTK = er5LZFnY7.MonitorServices.Add(ltNyQkRjo.ID);
			fG2ggTQRpj = er5LZFnY7.MonitorServices.get_MonitorService(VV0gfcviTK).Monitors;
			A1rgxT6DDQ = new AdiTedJDb7VX8ZheBB(er5LZFnY7.MonitorServices.get_MonitorService(VV0gfcviTK));
			x12zTZSCZ = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void csFwK5F05(int P_0, int P_1, string P_2, string P_3)
		{
			if (!Bntgu1H3K1.ContainsKey(P_1))
			{
				return;
			}
			Ur96UyYkBCs61C6Ogv ur96UyYkBCs61C6Ogv = Bntgu1H3K1[P_1];
			if (ur96UyYkBCs61C6Ogv.aavEeEPPx != P_0 || !ur96UyYkBCs61C6Ogv.atJrxExtl.Contains(P_2))
			{
				return;
			}
			af9U4jCfh(P_1, P_2, P_3);
			try
			{
				long num = long.Parse(P_2);
				if (DxFgSbJCfv)
				{
					vrNgcsbgSZ.HkcgqOFPCy(P_1, num, P_3, A3MgtovOJ5.MCQgb191k(P_1, num, P_3));
				}
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Cleanup()
		{
			if (x12zTZSCZ)
			{
				x3QgsqWP8Q.Unadvise(oCSgXDMJ9K);
				er5LZFnY7.MonitorServices.Remove(VV0gfcviTK);
				x12zTZSCZ = false;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddMonitoredParameters(string[] parameterIds, int moduleId)
		{
			if (parameterIds == null)
			{
				throw new ArgumentNullException(vKNfOaX0MCxOqDs2ZG.aVjgE872eU(258));
			}
			if (!x12zTZSCZ)
			{
				Gnj9i105a();
			}
			for (int i = 0; i < parameterIds.Length; i++)
			{
				AddMonitoredParameter(parameterIds[i], moduleId);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddMonitoredParameter(string parameterId, int moduleId)
		{
			if (parameterId == null)
			{
				throw new ArgumentNullException(vKNfOaX0MCxOqDs2ZG.aVjgE872eU(286));
			}
			if (!x12zTZSCZ)
			{
				Gnj9i105a();
			}
			Ur96UyYkBCs61C6Ogv ur96UyYkBCs61C6Ogv;
			if (Bntgu1H3K1.ContainsKey(moduleId))
			{
				ur96UyYkBCs61C6Ogv = Bntgu1H3K1[moduleId];
			}
			else
			{
				IMonitor monitor = null;
				Ur96UyYkBCs61C6Ogv ur96UyYkBCs61C6Ogv2 = default(Ur96UyYkBCs61C6Ogv);
				ur96UyYkBCs61C6Ogv2.atJrxExtl = new List<string>();
				IModule module = ltNyQkRjo.System.Modules.get_Item((object)moduleId.ToString());
				IGroupDefinition groupDefinition = module.GroupDefinitions.Add(null);
				ur96UyYkBCs61C6Ogv2.Y9InKIEP2 = groupDefinition.ID;
				if (oHYgTrhLwZ == ClientContextInfo.DEFAULT)
				{
					ur96UyYkBCs61C6Ogv2.aavEeEPPx = fG2ggTQRpj.Add(groupDefinition, moduleId, Xm1gWHr0Nq);
				}
				else
				{
					ur96UyYkBCs61C6Ogv2.aavEeEPPx = fG2ggTQRpj.AddEx(groupDefinition, moduleId, Xm1gWHr0Nq, oHYgTrhLwZ);
				}
				monitor = fG2ggTQRpj.get_Monitor(ur96UyYkBCs61C6Ogv2.aavEeEPPx);
				Bntgu1H3K1.Add(moduleId, ur96UyYkBCs61C6Ogv2);
				ur96UyYkBCs61C6Ogv = ur96UyYkBCs61C6Ogv2;
				monitor.UpdateGlobalPeriod(s17gCB1Jpm);
			}
			fG2ggTQRpj.AddParameter(ur96UyYkBCs61C6Ogv.Y9InKIEP2, parameterId);
			ur96UyYkBCs61C6Ogv.atJrxExtl.Add(parameterId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void RemoveMonitoredParameter(string parameterId, int moduleId)
		{
			if (Bntgu1H3K1.ContainsKey(moduleId) && Bntgu1H3K1[moduleId].atJrxExtl.Contains(parameterId))
			{
				fG2ggTQRpj.RemoveParameter(Bntgu1H3K1[moduleId].Y9InKIEP2, parameterId);
				Bntgu1H3K1[moduleId].atJrxExtl.Remove(parameterId);
				vrNgcsbgSZ.ncDgFLKMB5(moduleId, long.Parse(parameterId));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ClearMonitoredParameters()
		{
			StopMonitoring();
			foreach (int key in Bntgu1H3K1.Keys)
			{
				string y9InKIEP = Bntgu1H3K1[key].Y9InKIEP2;
				foreach (string item in Bntgu1H3K1[key].atJrxExtl)
				{
					try
					{
						fG2ggTQRpj.RemoveParameter(y9InKIEP, item);
					}
					catch
					{
					}
				}
				Bntgu1H3K1[key].atJrxExtl.Clear();
			}
			Bntgu1H3K1.Clear();
			vrNgcsbgSZ.I1FgD1Hblv();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void StartMonitoring()
		{
			foreach (Ur96UyYkBCs61C6Ogv value in Bntgu1H3K1.Values)
			{
				IMonitor monitor = fG2ggTQRpj.get_Monitor(value.aavEeEPPx);
				monitor.UpdateGlobalPeriod((int)SamplingRate);
			}
			fG2ggTQRpj.StartAll();
			dqYg2CkncS.mEEmFAb9j();
			pPFg0UaZdW = true;
			if (DxFgSbJCfv)
			{
				A1rgxT6DDQ.cnR8FfBHF(fG2ggTQRpj);
				A1rgxT6DDQ.tx2qVk7KX(Bntgu1H3K1);
				A1rgxT6DDQ.P8Dtuum2L();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void StopMonitoring()
		{
			dqYg2CkncS.WuMRn0SHS();
			fG2ggTQRpj.StopAll();
			pPFg0UaZdW = false;
			if (DxFgSbJCfv)
			{
				A1rgxT6DDQ.W8E0qaBTE();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SaveLogFile(string fileName)
		{
			if (DxFgSbJCfv)
			{
				A1rgxT6DDQ.vW1SNDajm(fileName);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetLogFileHeader(Dictionary<string, string> logHeaderInformation)
		{
			A1rgxT6DDQ.y3PxxyDTy(logHeaderInformation);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddEventMarker(long eventId)
		{
			A1rgxT6DDQ.yElTGROCV(eventId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddEventDescription(long eventId, string eventDescription)
		{
			A1rgxT6DDQ.kJJ3w32IS(eventId, eventDescription);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void af9U4jCfh(int P_0, string P_1, string P_2)
		{
			k5pQLJTpO?.Invoke(this, new MonitorDataChangedEventArgs(P_0, P_1, P_2));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IMonitorEvents.OnMonitorDataChanged(int monitorID, int moduleID, string parameterID, string parameterDisplayValue)
		{
			csFwK5F05(monitorID, moduleID, parameterID, parameterDisplayValue);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IMonitorEvents.OnMonitorError(int monitorID)
		{
			throw new NotImplementedException(vKNfOaX0MCxOqDs2ZG.aVjgE872eU(312));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IMonitorEvents.OnMonitorStarted(int monitorID)
		{
			throw new NotImplementedException(vKNfOaX0MCxOqDs2ZG.aVjgE872eU(402));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IMonitorEvents.OnMonitorStopped(int monitorID)
		{
			throw new NotImplementedException(vKNfOaX0MCxOqDs2ZG.aVjgE872eU(492));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IMonitorDataChangedEvent.OnMonitorDataChanged(int MonitorID, int moduleID, string parameterID, string parameterDisplayValue)
		{
			csFwK5F05(MonitorID, moduleID, parameterID, parameterDisplayValue);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MonitorManager()
		{
			En9RagAMcX2rgK6BaU.CL6Ugf7z0ohmP();
			base..ctor();
		}
	}
	public struct MonitoredParameterInfo
	{
		private int ttxg31uQQf;

		private long mRegNQKN1e;

		private string wb0gVEFVkl;

		private double DO6g8xl2Ht;

		private bool a0ugA58wTm;

		public int ModuleId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ttxg31uQQf;
			}
		}

		public long ParameterId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return mRegNQKN1e;
			}
		}

		public string DisplayValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return wb0gVEFVkl;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				wb0gVEFVkl = value;
			}
		}

		public double RawValue
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return DO6g8xl2Ht;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				if (DO6g8xl2Ht == value)
				{
					a0ugA58wTm = false;
				}
				else
				{
					a0ugA58wTm = true;
				}
				DO6g8xl2Ht = value;
			}
		}

		public bool ValueChanged
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return a0ugA58wTm;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MonitoredParameterInfo(int moduleId, long parameterId, string displayValue, double rawValue)
		{
			En9RagAMcX2rgK6BaU.CL6Ugf7z0ohmP();
			ttxg31uQQf = moduleId;
			mRegNQKN1e = parameterId;
			wb0gVEFVkl = displayValue;
			DO6g8xl2Ht = rawValue;
			a0ugA58wTm = true;
		}
	}
}
namespace KXkrH8U9DjglUpr456
{
	internal class u9jqrpBSlhCNFweeh3
	{
		private object leHgOlEFwL;

		private Dictionary<int, Dictionary<long, MonitoredParameterInfo>> aAggpeZAVu;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MonitoredParameterInfo AXbg7MeUEt(int P_0, long P_1)
		{
			lock (leHgOlEFwL)
			{
				if (aAggpeZAVu.ContainsKey(P_0))
				{
					if (aAggpeZAVu[P_0].ContainsKey(P_1))
					{
						return aAggpeZAVu[P_0][P_1];
					}
					return default(MonitoredParameterInfo);
				}
				throw new ArgumentException(vKNfOaX0MCxOqDs2ZG.aVjgE872eU(582));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void HkcgqOFPCy(int P_0, long P_1, string P_2, double P_3)
		{
			lock (leHgOlEFwL)
			{
				if (!aAggpeZAVu.ContainsKey(P_0))
				{
					aAggpeZAVu.Add(P_0, new Dictionary<long, MonitoredParameterInfo>());
				}
				if (!aAggpeZAVu[P_0].ContainsKey(P_1))
				{
					aAggpeZAVu[P_0].Add(P_1, new MonitoredParameterInfo(P_0, P_1, P_2, P_3));
					return;
				}
				MonitoredParameterInfo value = aAggpeZAVu[P_0][P_1];
				value.DisplayValue = P_2;
				value.RawValue = P_3;
				aAggpeZAVu[P_0][P_1] = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ncDgFLKMB5(int P_0, long P_1)
		{
			lock (leHgOlEFwL)
			{
				if (aAggpeZAVu.ContainsKey(P_0) && aAggpeZAVu[P_0].ContainsKey(P_1))
				{
					aAggpeZAVu[P_0].Remove(P_1);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public List<MonitoredParameterInfo> OQDgjbHScI()
		{
			List<MonitoredParameterInfo> list = new List<MonitoredParameterInfo>();
			lock (leHgOlEFwL)
			{
				try
				{
					Dictionary<int, Dictionary<long, MonitoredParameterInfo>>.ValueCollection values = aAggpeZAVu.Values;
					Dictionary<int, Dictionary<long, MonitoredParameterInfo>>.ValueCollection.Enumerator enumerator = values.GetEnumerator();
					while (enumerator.MoveNext())
					{
						list.AddRange(enumerator.Current.Values);
					}
				}
				catch
				{
				}
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void I1FgD1Hblv()
		{
			lock (leHgOlEFwL)
			{
				aAggpeZAVu.Clear();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public u9jqrpBSlhCNFweeh3()
		{
			En9RagAMcX2rgK6BaU.CL6Ugf7z0ohmP();
			leHgOlEFwL = new object();
			aAggpeZAVu = new Dictionary<int, Dictionary<long, MonitoredParameterInfo>>();
			base..ctor();
		}
	}
}
internal class <Module>{9C029118-5DDA-42EE-8224-AE4C5EA0F997}
{
}
namespace OJmbSNc4yXQbfLSI2s
{
	internal class uq8rGU57x0KlkUoVrs
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module sYYg6QwyrP;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void vpjUgf77JSO8q(int typemdt)
		{
			Type type = sYYg6QwyrP.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)sYYg6QwyrP.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public uq8rGU57x0KlkUoVrs()
		{
			En9RagAMcX2rgK6BaU.CL6Ugf7z0ohmP();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static uq8rGU57x0KlkUoVrs()
		{
			En9RagAMcX2rgK6BaU.CL6Ugf7z0ohmP();
			sYYg6QwyrP = typeof(uq8rGU57x0KlkUoVrs).Assembly.ManifestModule;
		}
	}
}
namespace sNRQPmddsh7lJRKOQ3
{
	internal class vKNfOaX0MCxOqDs2ZG
	{
		internal class At7hqo36rX05P7SpJG : Attribute
		{
			internal class B5NN8awNirTZAvJqj8<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public B5NN8awNirTZAvJqj8()
				{
					En9RagAMcX2rgK6BaU.CL6Ugf7z0ohmP();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[At7hqo36rX05P7SpJG(typeof(vKNfOaX0MCxOqDs2ZG/At7hqo36rX05P7SpJG/B5NN8awNirTZAvJqj8<object>[]))]
			public At7hqo36rX05P7SpJG(object P_0)
			{
				En9RagAMcX2rgK6BaU.CL6Ugf7z0ohmP();
				base..ctor();
			}
		}

		internal class g3VIPj0JqT1WAvsxY1
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[At7hqo36rX05P7SpJG(typeof(vKNfOaX0MCxOqDs2ZG/At7hqo36rX05P7SpJG/B5NN8awNirTZAvJqj8<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (GUXsT3lF5V(Convert.ToBase64String(typeof(vKNfOaX0MCxOqDs2ZG).Assembly.GetName().GetPublicKeyToken()), vKNfOaX0MCxOqDs2ZG.aVjgE872eU(648)) != vKNfOaX0MCxOqDs2ZG.aVjgE872eU(654))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[At7hqo36rX05P7SpJG(typeof(vKNfOaX0MCxOqDs2ZG/At7hqo36rX05P7SpJG/B5NN8awNirTZAvJqj8<object>[]))]
			internal static string GUXsT3lF5V(string P_0, string P_1)
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
			public g3VIPj0JqT1WAvsxY1()
			{
				En9RagAMcX2rgK6BaU.CL6Ugf7z0ohmP();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint EKxJmeCVSPU4mYHWft([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr N4uxiOFV8RZRVWv3A3();

		internal struct V48G9RlZ5HRq8IFiN2
		{
			internal bool lNEs3fmTiC;

			internal byte[] kfXsN5w1BU;
		}

		[Flags]
		private enum wokRgd79gwF5YX4vYt
		{

		}

		private static byte[] vVwgwXo0Os;

		private static IntPtr FnGgd3nTJU;

		private static int SR2sfum26B;

		private static bool dcqsg38UDf;

		private static SortedList M17ss0XWd7;

		internal static EKxJmeCVSPU4mYHWft SrWsC9ToOY;

		private static int OMrs2iBbt8;

		private static IntPtr S43sSNCj4A;

		internal static Hashtable d9NsxNim8F;

		private static bool lxbstq9qAy;

		private static int[] nCqgzWWJmQ;

		private static byte[] IQDgUbmZBY;

		internal static EKxJmeCVSPU4mYHWft SgnsWTTi18;

		private static object mrJgyQ5PtM;

		private static long OkRscAJMxQ;

		private static IntPtr BBygLcPqqV;

		private static int oZvs0xi24L;

		private static byte[] VYHgQNdC0H;

		private static int BLNsXKpp8F;

		private static byte[] pRBg94GlkS;

		private static long C0EsuC7f3H;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static vKNfOaX0MCxOqDs2ZG()
		{
			pRBg94GlkS = new byte[0];
			vVwgwXo0Os = new byte[0];
			IQDgUbmZBY = new byte[0];
			VYHgQNdC0H = new byte[0];
			FnGgd3nTJU = IntPtr.Zero;
			BBygLcPqqV = IntPtr.Zero;
			mrJgyQ5PtM = new string[0];
			nCqgzWWJmQ = new int[0];
			SR2sfum26B = 1;
			dcqsg38UDf = false;
			M17ss0XWd7 = new SortedList();
			BLNsXKpp8F = 0;
			C0EsuC7f3H = 0L;
			SrWsC9ToOY = null;
			SgnsWTTi18 = null;
			OkRscAJMxQ = 0L;
			OMrs2iBbt8 = 0;
			lxbstq9qAy = false;
			oZvs0xi24L = 0;
			S43sSNCj4A = IntPtr.Zero;
			d9NsxNim8F = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void rhyUgf7M9OahR()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[At7hqo36rX05P7SpJG(typeof(vKNfOaX0MCxOqDs2ZG/At7hqo36rX05P7SpJG/B5NN8awNirTZAvJqj8<object>[]))]
		static string aVjgE872eU(int P_0)
		{
			int num = 185;
			byte[] array4 = default(byte[]);
			byte[] array2 = default(byte[]);
			int num6 = default(int);
			byte[] array = default(byte[]);
			int num4 = default(int);
			byte[] array3 = default(byte[]);
			int num8 = default(int);
			int num7 = default(int);
			BinaryReader binaryReader = default(BinaryReader);
			CryptoStream cryptoStream = default(CryptoStream);
			MemoryStream memoryStream = default(MemoryStream);
			ICryptoTransform transform = default(ICryptoTransform);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array6 = default(byte[]);
			int num3 = default(int);
			byte[] array5 = default(byte[]);
			while (true)
			{
				int num2 = num;
				while (true)
				{
					int num5;
					switch (num2)
					{
					case 196:
						array4 = (byte[])egROVNic2DHowdExDD(xLwZuVoh3D8VCVoBwh(vC9ulsxvdtGSgH9J99(typeof(vKNfOaX0MCxOqDs2ZG).TypeHandle).Assembly));
						num = 272;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 129;
					case 129:
						array2[12] = (byte)num6;
						num = 56;
						if (!UQ78iy1efDXxLSZZG4())
						{
							break;
						}
						goto case 48;
					case 48:
						array[29] = (byte)num4;
						num2 = 186;
						continue;
					case 101:
						num6 = 254 - 84;
						num5 = 105;
						goto IL_0265;
					case 321:
						num4 = 222 - 74;
						num = 230;
						if (0 == 0)
						{
							break;
						}
						goto case 305;
					case 305:
						array[4] = 250;
						num2 = 270;
						continue;
					case 185:
						if (IQDgUbmZBY.Length == 0)
						{
							num5 = 3;
							goto IL_0265;
						}
						goto case 64;
					case 149:
						array3[9] = array4[4];
						num = 326;
						if (0 == 0)
						{
							break;
						}
						goto case 273;
					case 273:
						array2[5] = (byte)num8;
						num = 101;
						break;
					case 25:
						num4 = 205 + 38;
						num5 = 264;
						goto IL_0265;
					case 218:
						num7 = 198 - 66;
						num2 = 262;
						continue;
					case 1:
						num6 = 68 + 61;
						num = 30;
						break;
					case 73:
						array2[1] = (byte)num6;
						num = 219;
						break;
					case 215:
						array[27] = (byte)num4;
						num2 = 209;
						continue;
					case 261:
						num8 = 58 + 105;
						num5 = 263;
						goto IL_0265;
					case 110:
						Rxq2ZZlcUGgnO8ibmR(tPDV8fbSRtXm46aZIk(binaryReader), 0L);
						num2 = 171;
						continue;
					case 283:
						array[27] = (byte)num4;
						num2 = 317;
						continue;
					case 140:
						array[8] = (byte)num4;
						num5 = 348;
						goto IL_0265;
					case 7:
						num7 = 63 + 113;
						num = 198;
						if (!UQ78iy1efDXxLSZZG4())
						{
							break;
						}
						goto case 160;
					case 160:
						array[30] = 154;
						num = 310;
						if (0 == 0)
						{
							break;
						}
						goto case 315;
					case 315:
						array[25] = 121;
						goto case 124;
					default:
						num = 124;
						if (0 == 0)
						{
							break;
						}
						goto case 133;
					case 133:
						array[29] = 165;
						num5 = 234;
						goto IL_0265;
					case 17:
						array2[4] = 132;
						num5 = 9;
						goto IL_0265;
					case 320:
						num7 = 250 - 83;
						num = 265;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 22;
					case 22:
						num6 = 195 - 65;
						num2 = 73;
						continue;
					case 296:
						array2[0] = (byte)num8;
						num = 142;
						if (true)
						{
							break;
						}
						goto case 313;
					case 313:
						array2[0] = 129;
						num5 = 192;
						goto IL_0265;
					case 213:
						array[18] = 32;
						num5 = 19;
						goto IL_0265;
					case 204:
						array[12] = (byte)num7;
						num = 90;
						if (0 == 0)
						{
							break;
						}
						goto case 103;
					case 103:
						array2[14] = (byte)num8;
						num5 = 24;
						goto IL_0265;
					case 121:
						num7 = 28 + 60;
						num5 = 161;
						goto IL_0265;
					case 332:
						num7 = 194 - 64;
						num2 = 29;
						continue;
					case 230:
						array[16] = (byte)num4;
						num = 249;
						break;
					case 350:
						cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
						num2 = 316;
						continue;
					case 34:
						array[10] = 247;
						num = 339;
						if (true)
						{
							break;
						}
						goto case 122;
					case 51:
						array[29] = (byte)num4;
						num = 314;
						if (true)
						{
							break;
						}
						goto case 108;
					case 108:
						num7 = 210 - 70;
						num5 = 102;
						goto IL_0265;
					case 311:
						array2[5] = 161;
						num5 = 340;
						goto IL_0265;
					case 267:
						num8 = 225 - 75;
						num2 = 183;
						continue;
					case 352:
						zM4NEcXXlgal3axlPq(rijndaelManaged, CipherMode.CBC);
						num5 = 288;
						goto IL_0265;
					case 85:
						array[2] = (byte)num7;
						num5 = 70;
						goto IL_0265;
					case 245:
						num8 = 188 - 62;
						num = 58;
						if (!UQ78iy1efDXxLSZZG4())
						{
							break;
						}
						goto case 236;
					case 194:
						array3[13] = array4[6];
						num5 = 145;
						goto IL_0265;
					case 284:
						array[30] = 56;
						num2 = 160;
						continue;
					case 209:
						num7 = 53 + 105;
						num5 = 287;
						goto IL_0265;
					case 132:
						num7 = 89 - 84;
						num = 131;
						break;
					case 20:
						num7 = 229 - 76;
						num2 = 125;
						continue;
					case 83:
						array2[6] = (byte)num6;
						num5 = 107;
						goto IL_0265;
					case 202:
						array2[3] = 137;
						num5 = 299;
						goto IL_0265;
					case 263:
						array2[0] = (byte)num8;
						num5 = 313;
						goto IL_0265;
					case 156:
						array[4] = (byte)num4;
						num = 36;
						if (0 == 0)
						{
							break;
						}
						goto case 97;
					case 97:
						array[31] = (byte)num7;
						num2 = 26;
						continue;
					case 219:
						array2[1] = 179;
						num = 130;
						break;
					case 201:
						array[30] = (byte)num4;
						num = 285;
						break;
					case 299:
						num8 = 170 - 120;
						num5 = 259;
						goto IL_0265;
					case 114:
						num7 = 206 - 68;
						num = 139;
						if (true)
						{
							break;
						}
						goto case 208;
					case 208:
						num4 = 101 + 43;
						num = 53;
						break;
					case 248:
						array[31] = 156;
						num2 = 298;
						continue;
					case 137:
						num4 = 96 + 40;
						num2 = 222;
						continue;
					case 247:
						num7 = 124 - 5;
						num2 = 61;
						continue;
					case 235:
						num7 = 166 - 55;
						num5 = 155;
						goto IL_0265;
					case 310:
						array[30] = 42;
						num5 = 96;
						goto IL_0265;
					case 179:
						num8 = 193 - 64;
						num5 = 323;
						goto IL_0265;
					case 90:
						array[12] = 134;
						num = 247;
						break;
					case 8:
						array[23] = (byte)num7;
						num2 = 334;
						continue;
					case 287:
						array[28] = (byte)num7;
						num2 = 138;
						continue;
					case 193:
						array[13] = 103;
						num2 = 114;
						continue;
					case 289:
						array3[5] = array4[2];
						num = 23;
						if (!UQ78iy1efDXxLSZZG4())
						{
							break;
						}
						goto case 176;
					case 206:
						array2[1] = 26;
						num = 253;
						if (!UQ78iy1efDXxLSZZG4())
						{
							break;
						}
						goto case 63;
					case 63:
						array2[6] = 159;
						num = 152;
						break;
					case 49:
						array[18] = (byte)num4;
						num = 165;
						break;
					case 298:
						num7 = 87 - 84;
						num = 97;
						if (!UQ78iy1efDXxLSZZG4())
						{
							break;
						}
						goto case 151;
					case 190:
						num6 = 127 - 42;
						num = 47;
						if (0 == 0)
						{
							break;
						}
						goto case 329;
					case 329:
						array2[12] = (byte)num6;
						num2 = 224;
						continue;
					case 33:
						IQDgUbmZBY = (byte[])AQG93SwqblGP80QGZm(memoryStream);
						num2 = 31;
						continue;
					case 231:
						array[25] = (byte)num4;
						num5 = 188;
						goto IL_0265;
					case 203:
						array2[8] = 170;
						num2 = 115;
						continue;
					case 178:
						array[11] = 118;
						num2 = 88;
						continue;
					case 198:
						array[24] = (byte)num7;
						num5 = 16;
						goto IL_0265;
					case 105:
						array2[5] = (byte)num6;
						num2 = 301;
						continue;
					case 229:
						num4 = 205 - 96;
						num2 = 57;
						continue;
					case 162:
						num7 = 70 + 7;
						num5 = 330;
						goto IL_0265;
					case 72:
						num4 = 17 + 20;
						num = 42;
						if (true)
						{
							break;
						}
						goto case 45;
					case 45:
						array2[14] = (byte)num6;
						num2 = 252;
						continue;
					case 301:
						array2[5] = 89;
						num5 = 166;
						goto IL_0265;
					case 94:
						num7 = 127 - 42;
						num = 237;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 278;
					case 278:
						array3 = array2;
						num5 = 196;
						goto IL_0265;
					case 139:
						array[13] = (byte)num7;
						num = 223;
						break;
					case 26:
						array6 = array;
						num = 52;
						break;
					case 70:
						array[2] = 93;
						num5 = 55;
						goto IL_0265;
					case 170:
						num4 = 41 + 9;
						num = 134;
						if (!UQ78iy1efDXxLSZZG4())
						{
							break;
						}
						goto case 6;
					case 6:
						array[17] = (byte)num4;
						num2 = 238;
						continue;
					case 115:
						array2[8] = 123;
						num2 = 44;
						continue;
					case 277:
						array[9] = (byte)num4;
						num5 = 279;
						goto IL_0265;
					case 147:
						array[1] = (byte)num4;
						num2 = 68;
						continue;
					case 69:
						array2[15] = 105;
						num2 = 278;
						continue;
					case 237:
						array[19] = (byte)num7;
						num2 = 86;
						continue;
					case 5:
						array[11] = 58;
						num2 = 15;
						continue;
					case 13:
						array[13] = (byte)num7;
						num = 182;
						if (!UQ78iy1efDXxLSZZG4())
						{
							break;
						}
						goto case 340;
					case 340:
						num8 = 168 - 56;
						num5 = 273;
						goto IL_0265;
					case 113:
						array2[10] = (byte)num8;
						num2 = 177;
						continue;
					case 118:
						array2[6] = (byte)num6;
						num = 41;
						if (true)
						{
							break;
						}
						goto case 42;
					case 42:
						array[23] = (byte)num4;
						num5 = 143;
						goto IL_0265;
					case 131:
						array[24] = (byte)num7;
						num2 = 315;
						continue;
					case 216:
						array2[11] = 62;
						num5 = 127;
						goto IL_0265;
					case 335:
						array2[6] = (byte)num8;
						num5 = 153;
						goto IL_0265;
					case 239:
						array[4] = 215;
						UQ78iy1efDXxLSZZG4();
						if (NRJfkAIdWaEW7nKSq4())
						{
							num2 = 304;
							continue;
						}
						num5 = 346;
						goto IL_0265;
					case 27:
						array[0] = (byte)num7;
						num = 318;
						break;
					case 68:
						num7 = 169 - 82;
						num2 = 302;
						continue;
					case 344:
						array[7] = (byte)num7;
						num = 291;
						if (0 == 0)
						{
							break;
						}
						goto case 322;
					case 322:
						array[10] = 114;
						num5 = 342;
						goto IL_0265;
					case 223:
						array[13] = 105;
						num = 169;
						break;
					case 37:
						array[19] = 110;
						num5 = 136;
						goto IL_0265;
					case 142:
						array2[0] = 7;
						num = 84;
						if (0 == 0)
						{
							break;
						}
						goto case 95;
					case 95:
						array[8] = (byte)num7;
						num = 67;
						if (0 == 0)
						{
							break;
						}
						goto case 243;
					case 243:
						array[4] = (byte)num7;
						num2 = 305;
						continue;
					case 135:
						array2[1] = (byte)num8;
						num = 22;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 252;
					case 252:
						array2[14] = 38;
						num5 = 256;
						goto IL_0265;
					case 280:
						num8 = 66 + 70;
						num = 335;
						if (0 == 0)
						{
							break;
						}
						goto case 268;
					case 268:
						array[5] = 137;
						num2 = 184;
						continue;
					case 221:
						num7 = 72 + 110;
						num = 300;
						if (true)
						{
							break;
						}
						goto case 171;
					case 171:
						OFuxDYNbvy0YibDCIQ(true);
						num2 = 11;
						continue;
					case 84:
						num8 = 120 + 47;
						num2 = 135;
						continue;
					case 155:
						array[8] = (byte)num7;
						num = 62;
						break;
					case 93:
						array[22] = 112;
						num5 = 312;
						goto IL_0265;
					case 336:
						num7 = 161 - 53;
						num5 = 343;
						goto IL_0265;
					case 285:
						array[30] = 103;
						num = 284;
						break;
					case 39:
						array[0] = 124;
						num5 = 294;
						goto IL_0265;
					case 269:
						if (array4.Length > 0)
						{
							num = 98;
							if (0 == 0)
							{
								break;
							}
							goto case 87;
						}
						goto case 351;
					case 87:
						array[14] = (byte)num7;
						num = 174;
						break;
					case 176:
						array2[11] = 162;
						num = 190;
						if (0 == 0)
						{
							break;
						}
						goto case 89;
					case 89:
						array[14] = 31;
						num2 = 162;
						continue;
					case 81:
						array[5] = (byte)num4;
						num = 268;
						if (0 == 0)
						{
							break;
						}
						goto case 246;
					case 246:
						array[6] = 132;
						num2 = 208;
						continue;
					case 264:
						array[17] = (byte)num4;
						num = 331;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 14;
					case 318:
						array[0] = 23;
						num5 = 320;
						goto IL_0265;
					case 174:
						num7 = 233 - 77;
						num = 100;
						break;
					case 141:
						array[3] = (byte)num4;
						num5 = 236;
						goto IL_0265;
					case 57:
						array[25] = (byte)num4;
						num = 276;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 46;
					case 46:
						array[20] = (byte)num7;
						num = 225;
						if (!UQ78iy1efDXxLSZZG4())
						{
							break;
						}
						goto case 260;
					case 260:
						num7 = 197 - 65;
						num2 = 8;
						continue;
					case 62:
						num4 = 238 - 79;
						num5 = 140;
						goto IL_0265;
					case 166:
						array2[6] = 138;
						num5 = 63;
						goto IL_0265;
					case 334:
						array[23] = 142;
						num = 195;
						if (!UQ78iy1efDXxLSZZG4())
						{
							break;
						}
						goto case 207;
					case 207:
						num6 = 231 - 77;
						num2 = 282;
						continue;
					case 242:
						array[1] = 171;
						num = 226;
						if (!UQ78iy1efDXxLSZZG4())
						{
							break;
						}
						goto case 56;
					case 200:
						array2[9] = 224;
						num5 = 148;
						goto IL_0265;
					case 300:
						array[14] = (byte)num7;
						num2 = 43;
						continue;
					case 225:
						num7 = 142 - 47;
						num2 = 233;
						continue;
					case 314:
						num4 = 175 - 58;
						num5 = 201;
						goto IL_0265;
					case 236:
						array[3] = 163;
						num = 79;
						if (0 == 0)
						{
							break;
						}
						goto case 265;
					case 265:
						array[1] = (byte)num7;
						num2 = 242;
						continue;
					case 187:
						num7 = 44 + 121;
						num = 46;
						break;
					case 157:
						array2[8] = (byte)num8;
						num5 = 112;
						goto IL_0265;
					case 348:
						num7 = 236 - 114;
						num2 = 95;
						continue;
					case 82:
						array2[10] = 170;
						num5 = 176;
						goto IL_0265;
					case 199:
						num8 = 233 - 77;
						num = 303;
						if (!UQ78iy1efDXxLSZZG4())
						{
							break;
						}
						goto case 348;
					case 195:
						array[23] = 210;
						num = 72;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 24;
					case 44:
						array2[8] = 108;
						num2 = 220;
						continue;
					case 169:
						num7 = 116 - 32;
						num2 = 13;
						continue;
					case 96:
						array[31] = 197;
						num2 = 164;
						continue;
					case 192:
						num8 = 229 - 76;
						num2 = 14;
						continue;
					case 158:
						array2[3] = 75;
						num = 1;
						if (true)
						{
							break;
						}
						goto case 165;
					case 165:
						array[19] = 172;
						num5 = 94;
						goto IL_0265;
					case 36:
						num7 = 173 - 57;
						num2 = 232;
						continue;
					case 295:
						array[2] = (byte)num7;
						num = 319;
						if (0 == 0)
						{
							break;
						}
						goto case 191;
					case 191:
						array[28] = (byte)num4;
						num = 218;
						if (0 == 0)
						{
							break;
						}
						goto case 173;
					case 173:
						array[26] = 169;
						num2 = 254;
						continue;
					case 61:
						array[12] = (byte)num7;
						num5 = 210;
						goto IL_0265;
					case 297:
						array[28] = (byte)num4;
						num2 = 12;
						continue;
					case 286:
						Mvf5hW86jYk4iNkPSm(cryptoStream);
						num2 = 33;
						continue;
					case 130:
						array2[1] = 140;
						num5 = 175;
						goto IL_0265;
					case 220:
						num8 = 61 + 18;
						num5 = 65;
						goto IL_0265;
					case 256:
						num8 = 70 + 7;
						num2 = 103;
						continue;
					case 164:
						array[31] = 124;
						num = 274;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 52;
					case 309:
						array2[11] = (byte)num8;
						num = 179;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 144;
					case 144:
						num8 = 164 + 31;
						num = 157;
						if (!UQ78iy1efDXxLSZZG4())
						{
							break;
						}
						goto case 134;
					case 134:
						array[15] = (byte)num4;
						num2 = 337;
						continue;
					case 152:
						num8 = 129 - 43;
						num5 = 338;
						goto IL_0265;
					case 234:
						num7 = 182 - 60;
						num5 = 349;
						goto IL_0265;
					case 41:
						array2[7] = 126;
						num = 333;
						break;
					case 250:
						array[11] = (byte)num4;
						num = 178;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 107;
					case 107:
						num6 = 65 - 40;
						num = 118;
						if (true)
						{
							break;
						}
						goto case 180;
					case 180:
						array[28] = (byte)num7;
						num5 = 168;
						goto IL_0265;
					case 241:
						array[19] = (byte)num7;
						num = 37;
						break;
					case 291:
						num4 = 101 + 74;
						num = 18;
						if (true)
						{
							break;
						}
						goto case 271;
					case 271:
						num8 = 155 - 50;
						num2 = 227;
						continue;
					case 331:
						array[18] = 40;
						num = 213;
						if (!UQ78iy1efDXxLSZZG4())
						{
							break;
						}
						goto case 292;
					case 312:
						array[22] = 168;
						num = 260;
						break;
					case 188:
						num4 = 248 - 82;
						num2 = 74;
						continue;
					case 65:
						array2[8] = (byte)num8;
						num = 144;
						if (0 == 0)
						{
							break;
						}
						goto case 307;
					case 307:
						array[0] = (byte)num4;
						num = 20;
						if (0 == 0)
						{
							break;
						}
						goto case 77;
					case 77:
						array[11] = 156;
						num = 91;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 308;
					case 308:
						array[15] = (byte)num7;
						num5 = 170;
						goto IL_0265;
					case 124:
						num4 = 32 + 14;
						num5 = 231;
						goto IL_0265;
					case 177:
						array2[10] = 138;
						num5 = 207;
						goto IL_0265;
					case 38:
						num7 = 147 - 49;
						num2 = 85;
						continue;
					case 138:
						num4 = 161 - 53;
						num = 297;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 59;
					case 59:
						array[31] = 152;
						num = 248;
						if (0 == 0)
						{
							break;
						}
						goto case 163;
					case 163:
						num6 = 29 + 45;
						num5 = 129;
						goto IL_0265;
					case 54:
						array[10] = (byte)num7;
						num = 34;
						if (true)
						{
							break;
						}
						goto case 317;
					case 317:
						num4 = 177 + 40;
						num5 = 215;
						goto IL_0265;
					case 274:
						array[31] = 128;
						num2 = 59;
						continue;
					case 279:
						array[9] = 98;
						num5 = 119;
						goto IL_0265;
					case 56:
						num6 = 27 + 117;
						num = 329;
						break;
					case 303:
						array2[13] = (byte)num8;
						num2 = 126;
						continue;
					case 330:
						array[15] = (byte)num7;
						goto case 111;
					case 282:
						array2[10] = (byte)num6;
						num2 = 82;
						continue;
					case 337:
						num4 = 241 - 80;
						num2 = 99;
						continue;
					case 102:
						array[3] = (byte)num7;
						num = 116;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 64;
					case 64:
						num3 = iPDZoZUUNNpNu0dqSF(IQDgUbmZBY, P_0);
						num5 = 353;
						goto IL_0265;
					case 145:
						array3[15] = array4[7];
						num = 351;
						if (0 == 0)
						{
							break;
						}
						goto case 75;
					case 75:
						array[20] = 84;
						num5 = 275;
						goto IL_0265;
					case 12:
						num7 = 215 - 71;
						num5 = 180;
						goto IL_0265;
					case 211:
						num4 = 98 - 47;
						num = 51;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 310;
					case 21:
						num4 = 69 + 57;
						num2 = 6;
						continue;
					case 127:
						num8 = 111 + 114;
						num2 = 309;
						continue;
					case 343:
						array[20] = (byte)num7;
						num = 75;
						break;
					case 233:
						array[21] = (byte)num7;
						num = 341;
						break;
					case 119:
						array[9] = 39;
						num = 10;
						if (true)
						{
							break;
						}
						goto case 30;
					case 30:
						array2[3] = (byte)num6;
						num5 = 327;
						goto IL_0265;
					case 148:
						num8 = 78 + 49;
						num2 = 113;
						continue;
					case 210:
						array[13] = 125;
						num2 = 193;
						continue;
					case 302:
						array[1] = (byte)num7;
						num = 128;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 333;
					case 184:
						array[6] = 44;
						num = 246;
						break;
					case 214:
						array[21] = 43;
						num = 332;
						break;
					case 98:
						array3[1] = array4[0];
						num2 = 154;
						continue;
					case 342:
						num7 = 54 + 59;
						num = 54;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 228;
					case 228:
						array2[7] = (byte)num6;
						num = 271;
						if (!UQ78iy1efDXxLSZZG4())
						{
							break;
						}
						goto case 43;
					case 43:
						num4 = 72 + 17;
						num2 = 328;
						continue;
					case 109:
						array[19] = (byte)num7;
						num = 80;
						break;
					case 74:
						array[25] = (byte)num4;
						num = 229;
						break;
					case 151:
						num4 = 167 - 55;
						num2 = 81;
						continue;
					case 78:
						num8 = 138 - 46;
						num = 146;
						if (0 == 0)
						{
							break;
						}
						goto case 172;
					case 172:
						array[7] = 91;
						num = 235;
						break;
					case 324:
						array2[14] = (byte)num8;
						num5 = 245;
						goto IL_0265;
					case 47:
						array2[11] = (byte)num6;
						num = 216;
						break;
					case 197:
						num7 = 103 + 12;
						num5 = 87;
						goto IL_0265;
					case 18:
						array[7] = (byte)num4;
						num2 = 172;
						continue;
					case 292:
						array[2] = (byte)num7;
						num5 = 38;
						goto IL_0265;
					case 14:
						array2[0] = (byte)num8;
						num2 = 120;
						continue;
					case 186:
						num4 = 49 + 103;
						num5 = 347;
						goto IL_0265;
					case 71:
						array[23] = 94;
						num2 = 167;
						continue;
					case 11:
						array5 = (byte[])ldBJ8CnvPcsZeVBm8F(binaryReader, (int)zHq7atvZB8UPo4wGVD(tPDV8fbSRtXm46aZIk(binaryReader)));
						num = 244;
						if (!UQ78iy1efDXxLSZZG4())
						{
							break;
						}
						goto case 322;
					case 257:
						array[17] = 151;
						num = 21;
						if (0 == 0)
						{
							break;
						}
						goto case 40;
					case 40:
					case 304:
						num4 = 183 - 61;
						num2 = 156;
						continue;
					case 319:
						num7 = 146 - 48;
						num5 = 292;
						goto IL_0265;
					case 339:
						num4 = 119 + 18;
						num = 250;
						if (0 == 0)
						{
							break;
						}
						goto case 19;
					case 19:
						array[18] = 216;
						num2 = 123;
						continue;
					case 31:
						FBYWIxHIUbyDekGiVX(memoryStream);
						num2 = 325;
						continue;
					case 272:
						if (array4 == null)
						{
							goto case 351;
						}
						num = 269;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 127;
					case 253:
						array2[2] = 56;
						num = 267;
						if (!UQ78iy1efDXxLSZZG4())
						{
							break;
						}
						goto case 293;
					case 293:
						array2[15] = 97;
						num = 69;
						if (!UQ78iy1efDXxLSZZG4())
						{
							break;
						}
						goto case 123;
					case 123:
						num4 = 78 + 69;
						num = 49;
						break;
					case 55:
						array[3] = 150;
						num = 212;
						if (0 == 0)
						{
							break;
						}
						goto case 24;
					case 24:
						num8 = 138 - 37;
						num5 = 324;
						goto IL_0265;
					case 111:
					case 346:
						array[15] = 44;
						num5 = 181;
						goto IL_0265;
					case 23:
						array3[7] = array4[3];
						num = 149;
						if (0 == 0)
						{
							break;
						}
						goto case 126;
					case 126:
						array2[13] = 12;
						num = 2;
						if (0 == 0)
						{
							break;
						}
						goto case 338;
					case 338:
						array2[6] = (byte)num8;
						num2 = 280;
						continue;
					case 249:
						array[16] = 77;
						num = 257;
						if (true)
						{
							break;
						}
						goto case 347;
					case 347:
						array[29] = (byte)num4;
						num = 211;
						if (true)
						{
							break;
						}
						goto case 175;
					case 175:
						array2[1] = 33;
						num2 = 206;
						continue;
					case 150:
						array[3] = (byte)num4;
						num = 239;
						if (0 == 0)
						{
							break;
						}
						goto case 106;
					case 106:
						array[0] = 84;
						num2 = 39;
						continue;
					case 99:
						array[15] = (byte)num4;
						num = 345;
						break;
					case 60:
						array2[0] = 84;
						num5 = 261;
						goto IL_0265;
					case 294:
						num4 = 107 + 65;
						num2 = 307;
						continue;
					case 76:
						array2[2] = 187;
						num2 = 158;
						continue;
					case 333:
						num6 = 202 - 67;
						num2 = 228;
						continue;
					case 276:
						array[26] = 122;
						num = 121;
						if (0 == 0)
						{
							break;
						}
						goto case 10;
					case 10:
						array[10] = 149;
						num2 = 322;
						continue;
					case 232:
						array[4] = (byte)num7;
						num = 104;
						if (0 == 0)
						{
							break;
						}
						goto case 86;
					case 86:
						num7 = 218 - 72;
						num = 241;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 174;
					case 168:
						num4 = 143 + 50;
						num5 = 191;
						goto IL_0265;
					case 28:
						array[11] = (byte)num4;
						num5 = 5;
						goto IL_0265;
					case 50:
						array[21] = (byte)num4;
						num = 251;
						if (true)
						{
							break;
						}
						goto case 288;
					case 288:
						transform = (ICryptoTransform)g9hUKgKVmRJVUv2Ahj(rijndaelManaged, array6, array3);
						num = 122;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 128;
					case 128:
						num7 = 154 - 51;
						num = 295;
						if (true)
						{
							break;
						}
						goto case 67;
					case 67:
						num4 = 145 - 48;
						num = 277;
						break;
					case 100:
						array[14] = (byte)num7;
						num = 221;
						if (!UQ78iy1efDXxLSZZG4())
						{
							break;
						}
						goto case 275;
					case 275:
						array[20] = 98;
						num = 187;
						if (true)
						{
							break;
						}
						goto case 212;
					case 212:
						num4 = 120 + 21;
						num = 4;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 160;
					case 182:
						array[14] = 92;
						num2 = 197;
						continue;
					case 345:
						array[15] = 225;
						num2 = 255;
						continue;
					case 9:
						array2[4] = 106;
						num = 240;
						if (!UQ78iy1efDXxLSZZG4())
						{
							break;
						}
						goto case 35;
					case 35:
						array[21] = (byte)num7;
						num = 214;
						break;
					case 159:
						num7 = 223 - 74;
						num5 = 27;
						goto IL_0265;
					case 259:
						array2[3] = (byte)num8;
						num2 = 17;
						continue;
					case 2:
						num6 = 110 + 97;
						num2 = 45;
						continue;
					case 58:
						array2[15] = (byte)num8;
						num5 = 266;
						goto IL_0265;
					case 227:
						array2[7] = (byte)num8;
						num = 203;
						break;
					case 117:
						array[24] = (byte)num4;
						num2 = 7;
						continue;
					case 316:
						ET1d7v9uN0kpQgRiuX(cryptoStream, array5, 0, array5.Length);
						num5 = 286;
						goto IL_0265;
					case 181:
						num7 = 77 + 113;
						num = 308;
						break;
					case 226:
						num4 = 91 + 88;
						num5 = 147;
						goto IL_0265;
					case 91:
						num4 = 38 + 57;
						num2 = 28;
						continue;
					case 281:
						num7 = 173 - 57;
						num = 344;
						break;
					case 323:
						array2[12] = (byte)num8;
						num2 = 163;
						continue;
					case 16:
						array[24] = 94;
						num = 132;
						if (!UQ78iy1efDXxLSZZG4())
						{
							break;
						}
						goto case 61;
					case 266:
						array2[15] = 227;
						num = 293;
						break;
					case 53:
						array[6] = (byte)num4;
						num = 137;
						if (true)
						{
							break;
						}
						goto case 270;
					case 270:
						num7 = 124 + 43;
						num = 258;
						break;
					case 29:
						array[22] = (byte)num7;
						num = 93;
						break;
					case 52:
						array2 = new byte[16];
						num2 = 60;
						continue;
					case 120:
						num8 = 223 - 74;
						num2 = 296;
						continue;
					case 328:
						array[14] = (byte)num4;
						num = 89;
						if (0 == 0)
						{
							break;
						}
						goto case 125;
					case 125:
						array[0] = (byte)num7;
						num2 = 159;
						continue;
					case 341:
						num4 = 213 - 71;
						num = 50;
						if (!UQ78iy1efDXxLSZZG4())
						{
							break;
						}
						goto case 258;
					case 258:
						array[5] = (byte)num7;
						num = 151;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 183;
					case 183:
						array2[2] = (byte)num8;
						num = 76;
						break;
					case 92:
						array2[13] = 115;
						num = 199;
						if (0 == 0)
						{
							break;
						}
						goto case 325;
					case 325:
						FBYWIxHIUbyDekGiVX(cryptoStream);
						num = 189;
						if (true)
						{
							break;
						}
						goto case 326;
					case 326:
						array3[11] = array4[5];
						num2 = 194;
						continue;
					case 88:
						array[11] = 151;
						num2 = 77;
						continue;
					case 251:
						num7 = 223 - 74;
						num = 35;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 2;
					case 15:
						num7 = 254 - 84;
						num2 = 204;
						continue;
					case 4:
						array[3] = (byte)num4;
						num = 108;
						break;
					case 240:
						array2[4] = 58;
						num = 311;
						break;
					case 112:
						num6 = 196 - 65;
						num2 = 66;
						continue;
					case 161:
						array[26] = (byte)num7;
						num = 173;
						if (!UQ78iy1efDXxLSZZG4())
						{
							break;
						}
						goto case 272;
					case 32:
						array2[9] = 163;
						num5 = 200;
						goto IL_0265;
					case 143:
						array[23] = 114;
						num2 = 71;
						continue;
					case 3:
						binaryReader = new BinaryReader((Stream)TEgXQ7SYTHpbrNpItb(vC9ulsxvdtGSgH9J99(typeof(vKNfOaX0MCxOqDs2ZG).TypeHandle).Assembly, "qJarh6hygOI70EY1jf.Df48OctATPQ8iesO4g"));
						num2 = 110;
						continue;
					case 0:
						num4 = 39 + 54;
						num = 48;
						break;
					case 238:
						array[17] = 100;
						num = 25;
						break;
					case 205:
						array2[9] = 103;
						num5 = 32;
						goto IL_0265;
					case 306:
						array2[3] = (byte)num8;
						num2 = 202;
						continue;
					case 262:
						array[29] = (byte)num7;
						num = 133;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 255;
					case 255:
						array[16] = 132;
						num5 = 321;
						goto IL_0265;
					case 254:
						array[27] = 122;
						num2 = 290;
						continue;
					case 136:
						num7 = 49 - 6;
						num = 109;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 268;
					case 224:
						array2[13] = 84;
						num = 78;
						if (true)
						{
							break;
						}
						goto case 327;
					case 327:
						num8 = 111 + 52;
						num = 306;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 66;
					case 66:
						array2[9] = (byte)num6;
						num = 205;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 226;
					case 167:
						num4 = 183 - 61;
						num2 = 117;
						continue;
					case 217:
						num7 = 198 - 66;
						num2 = 243;
						continue;
					case 154:
						array3[3] = array4[1];
						num2 = 289;
						continue;
					case 146:
						array2[13] = (byte)num8;
						num5 = 92;
						goto IL_0265;
					case 349:
						array[29] = (byte)num7;
						num2 = 0;
						continue;
					case 116:
						num4 = 188 - 62;
						num = 141;
						if (true)
						{
							break;
						}
						goto case 104;
					case 104:
						array[4] = 129;
						num = 217;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 153;
					case 153:
						num6 = 101 + 43;
						num5 = 83;
						goto IL_0265;
					case 290:
						num4 = 158 - 52;
						num5 = 283;
						goto IL_0265;
					case 79:
						num4 = 68 + 76;
						num = 150;
						if (NRJfkAIdWaEW7nKSq4())
						{
							break;
						}
						goto case 290;
					case 80:
						array[20] = 88;
						num2 = 336;
						continue;
					case 244:
						array = new byte[32];
						num = 106;
						if (true)
						{
							break;
						}
						goto case 222;
					case 222:
						array[6] = (byte)num4;
						num5 = 281;
						goto IL_0265;
					case 189:
						s5VOVZJUywCc8slJns(binaryReader);
						num2 = 64;
						continue;
					case 353:
						try
						{
							return (string)EaPHwvMkIDnFjJGm2T(vVxPSTTrbXPTLEtSdt(), IQDgUbmZBY, P_0 + 4, num3);
						}
						catch
						{
						}
						return "";
					case 122:
						memoryStream = new MemoryStream();
						num2 = 350;
						continue;
					case 351:
						{
							rijndaelManaged = new RijndaelManaged();
							num = 352;
							break;
						}
						IL_0265:
						num = num5;
						break;
					}
					break;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[At7hqo36rX05P7SpJG(typeof(vKNfOaX0MCxOqDs2ZG/At7hqo36rX05P7SpJG/B5NN8awNirTZAvJqj8<object>[]))]
		internal static string gBqgnqt2wN(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void JwMgrcvdd2(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int aSugHrKSLp(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr F36gMsXwhW(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void E6mgm7djPF()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void utjgRqL6mJ()
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
		internal static object xgHgeGdkOS(object P_0)
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
		public static extern IntPtr hiAgGvIyOa(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr c0rgKgb7nc(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int WBmgZDxhO1(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int Cl0gh6sE7E(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int O20gJmkfIC(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr z0qg5Cwp6M(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int R7agvMyGO4(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[At7hqo36rX05P7SpJG(typeof(vKNfOaX0MCxOqDs2ZG/At7hqo36rX05P7SpJG/B5NN8awNirTZAvJqj8<object>[]))]
		private static byte[] hmmgYqVQbI(string P_0)
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
		[At7hqo36rX05P7SpJG(typeof(vKNfOaX0MCxOqDs2ZG/At7hqo36rX05P7SpJG/B5NN8awNirTZAvJqj8<object>[]))]
		private static byte[] hB3gbtQtmC(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				123, 207, 198, 180, 33, 138, 101, 216, 94, 56,
				125, 14, 74, 97, 185, 165, 179, 17, 222, 214,
				89, 33, 172, 10, 105, 123, 224, 179, 161, 68,
				227, 100
			};
			rijndael.IV = new byte[16]
			{
				51, 46, 124, 245, 4, 149, 137, 54, 177, 164,
				158, 200, 5, 120, 252, 181
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] wFJg4RlnO8()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] Pjvglaq1yb()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] m0ZgB3uYSC()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] tl8gIIqHFV()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] nPlgP5SWV5()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] iqGgiQvFQn()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] zW7gaC4pc3()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] zn0g1ecOyZ()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] aExgo929mL()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] MrUgkGQTQW()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public vKNfOaX0MCxOqDs2ZG()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type vC9ulsxvdtGSgH9J99(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object TEgXQ7SYTHpbrNpItb(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object tPDV8fbSRtXm46aZIk(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Rxq2ZZlcUGgnO8ibmR(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void OFuxDYNbvy0YibDCIQ(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long zHq7atvZB8UPo4wGVD(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object ldBJ8CnvPcsZeVBm8F(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object xLwZuVoh3D8VCVoBwh(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object egROVNic2DHowdExDD(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void zM4NEcXXlgal3axlPq(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object g9hUKgKVmRJVUv2Ahj(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void ET1d7v9uN0kpQgRiuX(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Mvf5hW86jYk4iNkPSm(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object AQG93SwqblGP80QGZm(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void FBYWIxHIUbyDekGiVX(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void s5VOVZJUywCc8slJns(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int iPDZoZUUNNpNu0dqSF(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object vVxPSTTrbXPTLEtSdt()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object EaPHwvMkIDnFjJGm2T(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool NRJfkAIdWaEW7nKSq4()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool UQ78iy1efDXxLSZZG4()
		{
			return false;
		}
	}
}
namespace zFj788rbVbJ0ddpfyA
{
	internal class En9RagAMcX2rgK6BaU
	{
		private static bool LVVsVrG8nh;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void CL6Ugf7z0ohmP()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public En9RagAMcX2rgK6BaU()
		{
		}
	}
}
