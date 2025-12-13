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
using System.Xml;
using BAf09IelGAnFFuEoLl;
using C3SkWen3BkLxy6mgKG;
using CILCALDATASERVERLib;
using CILCompressionUtilitiesLib;
using CILDCLDEVICECONTROLLib;
using CILDICTIONARYLib;
using CILERRORHANDLINGLib;
using CILMSGHANDLINGLib;
using CILModuleDetection;
using CILSubFiles;
using CILSymbolicTree;
using CLDATAACCESSLib;
using Cummins.INSITE.Kernel.CCServices;
using Cummins.INSITE.Kernel.ECMServicesAPI;
using Cummins.INSITE.Kernel.ECMServicesCommonTypes;
using Cummins.INSITE.Kernel.ICLServices;
using Cummins.Interop;
using KPlfXvbUO3mWtkqCa5;
using YEIt6mOMp71LBlPI6t;
using aY81o5UFe9Bmqhhh9H;
using asXPlNXkRDFxmj2224;
using iOH6yk8YGtBw7m4XYC;
using ns4j3h16HO4JxlZtVU;

[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: Guid("ab9d3f8d-b7f5-48a3-ba9d-4be8e9a06e28")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyDelaySign(false)]
[assembly: ComVisible(true)]
[assembly: AssemblyTitle("Cummins.INSITE.Kernel.CCServices")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyTrademark("")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyProduct("Cummins.INSITE.Kernel.CCServices")]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace lTkVvUw3rNf5ZXNJQy
{
	internal static class IsfiG65stLGiC641jY
	{
	}
}
namespace Cummins.INSITE.Kernel.CCServices
{
	public enum CCObjectType
	{
		DeviceControl,
		CalDataServer
	}
	public interface ICCConnectionServices
	{
		IList<int> DetectDevices(IPhysicalConnectionConfiguration detectionConfig);

		ISystemProperties Connect(int connectionId, IPhysicalConnectionConfiguration connectionConfig);

		void PrepareConnection(int connectionId, int sourceAddress);

		void Disconnect(int connectionId);

		void OpenSession(int connectionId, int sourceAddress, ISessionInfo sessionInfo);

		string GetFirmwareVersion(int connectionId, int sourceAddress);

		object GetCCObject(int connectionId, int sourceAddress, CCObjectType objectType);

		IParameterValue GetParamterValue(int connectionId, int sourceAddress, string parameterName);

		void SetParameterValue(int connectionId, int sourceAddress, string parameterName, object value);

		void SetFieldParameterValue(int connectionId, int sourceAddress, string parameterName, string fieldParameterValue, object value);

		IParameterValues GetParameterValues(int connectionId, int sourceAddress, IList<string> parameterNames, out IEnumerable<string> unreadParameters);

		void SetParameterValues(int connectionId, int sourceAddress, IDictionary<string, object> paramValues, out IEnumerable<string> unwrittenParameters);

		int ExecuteOperation(int connectionId, int sourceAddress, string operationName, IDictionary<object, object> inArgs, out IParameterValues outArgs);

		void PingModule(int connectionId, int sourceAddress);
	}
}
namespace KPlfXvbUO3mWtkqCa5
{
	internal class IMyjBU7lxGtugY6hfK : ICCConnectionServices
	{
		private static IMyjBU7lxGtugY6hfK tY1bTkVvU;

		private AWs3nuVCfVjXO6pbEb wrNBf5ZXN;

		private Dictionary<int, RiJgwpDF8aqnRNENNf> KQyOHMyjB;

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public static IMyjBU7lxGtugY6hfK iWswfiG6s()
		{
			return tY1bTkVvU;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private IMyjBU7lxGtugY6hfK()
		{
			RC5jUHMDkrkP9QtAnE.ggyda19zX8XvI();
			base..ctor();
			wrNBf5ZXN = AWs3nuVCfVjXO6pbEb.c9bKnQps8G();
			KQyOHMyjB = new Dictionary<int, RiJgwpDF8aqnRNENNf>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<int> DetectDevices(IPhysicalConnectionConfiguration P_0)
		{
			DCLDevice dCLDevice;
			CILModuleDetection.ICICollection iCICollection = CWgu9fFT7UX6chSr7P.Q7LsdDREb(P_0, out dCLDevice);
			List<int> list = new List<int>();
			for (int i = 0; i < iCICollection.Count; i++)
			{
				ICIDeviceInfo2 iCIDeviceInfo = iCICollection[i] as ICIDeviceInfo2;
				list.Add(iCIDeviceInfo.Address);
			}
			return list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ISystemProperties Connect(int P_0, IPhysicalConnectionConfiguration P_1)
		{
			DCLDevice dCLDevice;
			CILModuleDetection.ICICollection iCICollection = CWgu9fFT7UX6chSr7P.Q7LsdDREb(P_1, out dCLDevice);
			SystemProperties systemProperties = new SystemProperties(P_0);
			Dictionary<int, CILCALDATASERVERLib.ICICalDataServer> dictionary = new Dictionary<int, CILCALDATASERVERLib.ICICalDataServer>();
			Dictionary<int, DCLDevice> dictionary2 = new Dictionary<int, DCLDevice>();
			for (int i = 0; i < iCICollection.Count; i++)
			{
				if (iCICollection[i] is ICIDeviceInfo2 iCIDeviceInfo)
				{
					ECUProperties eCUProperties = CWgu9fFT7UX6chSr7P.nKwAPq29m(iCIDeviceInfo);
					if (eCUProperties.GTISLevel == GTISLevel.GTIS_45 || eCUProperties.GTISLevel == GTISLevel.GTIS_46)
					{
						dictionary.Add(eCUProperties.SourceAddress, CWgu9fFT7UX6chSr7P.Mnwo9SBtB(dCLDevice, iCIDeviceInfo));
					}
					dictionary2.Add(eCUProperties.SourceAddress, iCIDeviceInfo.DataSource as DCLDevice);
					systemProperties.Add(eCUProperties);
				}
			}
			KQyOHMyjB.Add(P_0, new RiJgwpDF8aqnRNENNf(P_0, systemProperties, dictionary, dictionary2));
			return systemProperties;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void PrepareConnection(int P_0, int P_1)
		{
			tshK2WbVt(P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Disconnect(int P_0)
		{
			KQyOHMyjB[P_0].wh6MHO4Jx();
			KQyOHMyjB.Remove(P_0);
			AWs3nuVCfVjXO6pbEb.c9bKnQps8G().LTQK8QasXx();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void OpenSession(int P_0, int P_1, ISessionInfo P_2)
		{
			tshK2WbVt(P_0, P_1).dPfG3SkWe(P_1, P_2);
			AWs3nuVCfVjXO6pbEb.c9bKnQps8G().LTQK8QasXx();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetFirmwareVersion(int P_0, int P_1)
		{
			return tshK2WbVt(P_0, P_1).oKGRp1OaG(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public object GetCCObject(int P_0, int P_1, CCObjectType P_2)
		{
			return tshK2WbVt(P_0, P_1).JZtUVUuWs(P_1, P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValue GetParamterValue(int P_0, int P_1, string P_2)
		{
			return tshK2WbVt(P_0, P_1).wnuiCfVjX(P_1, P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetParameterValue(int P_0, int P_1, string P_2, object P_3)
		{
			tshK2WbVt(P_0, P_1).f6pmbEb4A(P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetFieldParameterValue(int P_0, int P_1, string P_2, string P_3, object P_4)
		{
			tshK2WbVt(P_0, P_1).C09uIlGAn(P_1, P_2, P_3, P_4);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValues GetParameterValues(int P_0, int P_1, IList<string> parameterNames, out IEnumerable<string> P_3)
		{
			return tshK2WbVt(P_0, P_1).jFu4EoLly(P_1, parameterNames, out P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetParameterValues(int P_0, int P_1, IDictionary<string, object> paramValues, out IEnumerable<string> P_3)
		{
			tshK2WbVt(P_0, P_1).uwxf7OI93(P_1, paramValues, out P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int ExecuteOperation(int P_0, int P_1, string P_2, IDictionary<object, object> inArgs, out IParameterValues P_4)
		{
			return tshK2WbVt(P_0, P_1).GLASk09rw(P_1, P_2, inArgs, out P_4);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private RiJgwpDF8aqnRNENNf tshK2WbVt(int P_0, int P_1)
		{
			RiJgwpDF8aqnRNENNf riJgwpDF8aqnRNENNf = null;
			if (KQyOHMyjB.ContainsKey(P_0))
			{
				riJgwpDF8aqnRNENNf = KQyOHMyjB[P_0];
				if (!riJgwpDF8aqnRNENNf.VYy32Ns4j(P_1, CCObjectType.CalDataServer) && !riJgwpDF8aqnRNENNf.VYy32Ns4j(P_1, CCObjectType.DeviceControl))
				{
					ICLServices iCLServices = new ICLServices();
					object dataServer = iCLServices.ConnectionServices.GetDataServer(P_0, P_1);
					object deviceControl = iCLServices.ConnectionServices.GetDeviceControl(P_0, P_1);
					riJgwpDF8aqnRNENNf.Hv6d5pusZ(P_1, CCObjectType.CalDataServer, dataServer);
					riJgwpDF8aqnRNENNf.Hv6d5pusZ(P_1, CCObjectType.DeviceControl, deviceControl);
				}
			}
			else
			{
				riJgwpDF8aqnRNENNf = vZl52e6Wx(P_0, P_1);
				KQyOHMyjB.Add(P_0, riJgwpDF8aqnRNENNf);
			}
			return riJgwpDF8aqnRNENNf;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private RiJgwpDF8aqnRNENNf vZl52e6Wx(int P_0, int P_1)
		{
			RiJgwpDF8aqnRNENNf riJgwpDF8aqnRNENNf = null;
			riJgwpDF8aqnRNENNf = new RiJgwpDF8aqnRNENNf(P_0);
			ICLServices iCLServices = new ICLServices();
			object dataServer = iCLServices.ConnectionServices.GetDataServer(P_0, P_1);
			object deviceControl = iCLServices.ConnectionServices.GetDeviceControl(P_0, P_1);
			riJgwpDF8aqnRNENNf.Hv6d5pusZ(P_1, CCObjectType.CalDataServer, dataServer);
			riJgwpDF8aqnRNENNf.Hv6d5pusZ(P_1, CCObjectType.DeviceControl, deviceControl);
			AWs3nuVCfVjXO6pbEb.c9bKnQps8G().LTQK8QasXx();
			return riJgwpDF8aqnRNENNf;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void PingModule(int P_0, int P_1)
		{
			tshK2WbVt(P_0, P_1).wBkjLxy6m(P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static IMyjBU7lxGtugY6hfK()
		{
			RC5jUHMDkrkP9QtAnE.ggyda19zX8XvI();
			tY1bTkVvU = new IMyjBU7lxGtugY6hfK();
		}
	}
}
namespace YEIt6mOMp71LBlPI6t
{
	internal static class eSnZ4fBCAlNrTOitFO
	{
		private static byte[] YSWtgu9fT;

		private static byte[] dUXa6chSr;

		[DllImport("ole32.dll", EntryPoint = "CLSIDFromProgID")]
		private static extern int ylxDGtugY([MarshalAs(UnmanagedType.LPWStr)] string P_0, out Guid P_1);

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static DCLDevice Ehf8KJPlf()
		{
			Guid guid = default(Guid);
			ylxDGtugY(aXtkqx0KSIocPot7nI.wHcKXkoBDR(0), out guid);
			LicensedComWrapper licensedComWrapper = new LicensedComWrapper(ComClassID.DCLDevice);
			object comInstance = licensedComWrapper.GetComInstance();
			if (comInstance != null)
			{
				return (DCLDevice)comInstance;
			}
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static CIModuleDetection qvUFO3mWt()
		{
			CIModuleDetectionClass cIModuleDetectionClass = new CIModuleDetectionClass();
			if (cIModuleDetectionClass != null)
			{
				return cIModuleDetectionClass;
			}
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static CICalDataServerClass LqCna57Sn()
		{
			CICalDataServerClass cICalDataServerClass = new CICalDataServerClass();
			if (cICalDataServerClass != null)
			{
				return cICalDataServerClass;
			}
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static SymbolicTreeClass P4fqCAlNr()
		{
			SymbolicTreeClass symbolicTreeClass = new SymbolicTreeClass();
			if (symbolicTreeClass != null)
			{
				return symbolicTreeClass;
			}
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static CIDataAccessClass VOi1tFOxE()
		{
			CIDataAccessClass cIDataAccessClass = new CIDataAccessClass();
			if (cIDataAccessClass != null)
			{
				return cIDataAccessClass;
			}
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static ICIFile Ut6VmMp71()
		{
			Guid guid = default(Guid);
			ylxDGtugY(aXtkqx0KSIocPot7nI.wHcKXkoBDR(42), out guid);
			LicensedComWrapper licensedComWrapper = new LicensedComWrapper(ComClassID.ConfigFile);
			object comInstance = licensedComWrapper.GetComInstance();
			if (comInstance != null)
			{
				return (ICIFile)comInstance;
			}
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static CISetRequestClass aBlePI6tA()
		{
			CISetRequestClass cISetRequestClass = new CISetRequestClass();
			if (cISetRequestClass != null)
			{
				return cISetRequestClass;
			}
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static CISetItemClass yJgNwpF8a()
		{
			CISetItemClass cISetItemClass = new CISetItemClass();
			if (cISetItemClass != null)
			{
				return cISetItemClass;
			}
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static CICollectionClass knRgNENNf()
		{
			CICollectionClass cICollectionClass = new CICollectionClass();
			if (cICollectionClass != null)
			{
				return cICollectionClass;
			}
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static ErrorMessageSetClass iOH06ykYG()
		{
			ErrorMessageSetClass errorMessageSetClass = new ErrorMessageSetClass();
			if (errorMessageSetClass != null)
			{
				return errorMessageSetClass;
			}
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static MsgManagerClass qBwX7m4XY()
		{
			MsgManagerClass msgManagerClass = new MsgManagerClass();
			if (msgManagerClass != null)
			{
				return msgManagerClass;
			}
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static eSnZ4fBCAlNrTOitFO()
		{
			RC5jUHMDkrkP9QtAnE.ggyda19zX8XvI();
			YSWtgu9fT = new byte[9] { 63, 33, 45, 32, 80, 78, 90, 86, 82 };
			dUXa6chSr = new byte[19]
			{
				56, 42, 89, 85, 80, 87, 39, 44, 42, 72,
				32, 92, 40, 69, 66, 95, 84, 42, 65
			};
		}
	}
}
namespace Cummins.INSITE.Kernel.CCServices
{
	public interface ICCCommunicationServices
	{
		ICCConnectionServices ConnectionServices { get; }
	}
	public class CCCommunicationServices : ICCCommunicationServices
	{
		public ICCConnectionServices ConnectionServices
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return IMyjBU7lxGtugY6hfK.iWswfiG6s();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public CCCommunicationServices()
		{
			RC5jUHMDkrkP9QtAnE.ggyda19zX8XvI();
			base..ctor();
		}
	}
}
namespace iOH6yk8YGtBw7m4XYC
{
	internal class RiJgwpDF8aqnRNENNf
	{
		private static readonly string LRDHFxmj2;

		private static readonly uint N24WLAEWj;

		private int LHAlCAco5;

		private Dictionary<int, CILCALDATASERVERLib.ICICalDataServer> p7wJqBQ8L;

		private Dictionary<int, DCLDevice> ayPQenpAa;

		private ISystemProperties IUWkFLCEm;

		private Dictionary<int, Dictionary<string, CILCALDATASERVERLib.ICICalEntity>> W0H2DuT6Q;

		private Dictionary<int, Dictionary<string, CILCALDATASERVERLib.ICICalEntity>> GyDyCiIlW;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public RiJgwpDF8aqnRNENNf(int P_0, SystemProperties P_1, Dictionary<int, CILCALDATASERVERLib.ICICalDataServer> calDataServers, Dictionary<int, DCLDevice> deviceControls)
		{
			RC5jUHMDkrkP9QtAnE.ggyda19zX8XvI();
			base..ctor();
			LHAlCAco5 = P_0;
			IUWkFLCEm = P_1;
			p7wJqBQ8L = calDataServers;
			ayPQenpAa = deviceControls;
			W0H2DuT6Q = new Dictionary<int, Dictionary<string, CILCALDATASERVERLib.ICICalEntity>>();
			GyDyCiIlW = new Dictionary<int, Dictionary<string, CILCALDATASERVERLib.ICICalEntity>>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public RiJgwpDF8aqnRNENNf(int P_0)
		{
			RC5jUHMDkrkP9QtAnE.ggyda19zX8XvI();
			base..ctor();
			LHAlCAco5 = P_0;
			W0H2DuT6Q = new Dictionary<int, Dictionary<string, CILCALDATASERVERLib.ICICalEntity>>();
			GyDyCiIlW = new Dictionary<int, Dictionary<string, CILCALDATASERVERLib.ICICalEntity>>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void dPfG3SkWe(int P_0, ISessionInfo P_1)
		{
			DCLDevice dCLDevice = null;
			if (p7wJqBQ8L != null && p7wJqBQ8L.ContainsKey(P_0))
			{
				dCLDevice = p7wJqBQ8L[P_0].DataAccess.DataSource as DCLDevice;
			}
			else if (ayPQenpAa != null && ayPQenpAa.ContainsKey(P_0))
			{
				dCLDevice = ayPQenpAa[P_0];
			}
			if (dCLDevice != null && dCLDevice is ICICLIPSession2 iCICLIPSession)
			{
				try
				{
					iCICLIPSession.Disconnect(sendClose: true);
					string configuration = string.Format(LRDHFxmj2, P_1.EncryptionLevel);
					iCICLIPSession.Connect(P_1.SessionInformation, configuration);
				}
				catch (COMException ex)
				{
					throw V1OaGHqv65pusZpYy2.OwLKwuXIww(ex);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void wBkjLxy6m(int P_0, int P_1)
		{
			if (p7wJqBQ8L == null)
			{
				return;
			}
			if (p7wJqBQ8L.ContainsKey(P_1))
			{
				try
				{
					CILCALDATASERVERLib.ICICalEntity iCICalEntity = p5XYtkqxK(P_1, aXtkqx0KSIocPot7nI.wHcKXkoBDR(86));
					if (iCICalEntity is ICICalAddressableEntity iCICalAddressableEntity)
					{
						iCICalAddressableEntity.CacheMode = CILCALDATASERVERLib.tagCICacheMode.readWrite;
						iCICalAddressableEntity.ClearCache();
					}
					V1OaGHqv65pusZpYy2.owJKL19J3C(iCICalEntity);
					return;
				}
				catch (COMException innerException)
				{
					if (AWs3nuVCfVjXO6pbEb.c9bKnQps8G().LKJK18Rce6())
					{
						throw new ECMServicesException(ECMServicesErrorCodes.DatalinkTimeout, string.Empty, innerException);
					}
					throw new ECMServicesException(ECMServicesErrorCodes.DatalinkError, string.Empty, innerException);
				}
			}
			throw new ArgumentException(aXtkqx0KSIocPot7nI.wHcKXkoBDR(112), aXtkqx0KSIocPot7nI.wHcKXkoBDR(160));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string oKGRp1OaG(int P_0)
		{
			//IL_007b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0081: Expected O, but got Unknown
			string result = string.Empty;
			DCLDevice dCLDevice = null;
			if (ayPQenpAa != null && ayPQenpAa.Count > 0)
			{
				dCLDevice = ayPQenpAa[P_0];
			}
			else if (p7wJqBQ8L != null && p7wJqBQ8L.Count > 0)
			{
				dCLDevice = p7wJqBQ8L[P_0].DataAccess.DataSource as DCLDevice;
			}
			if (dCLDevice != null)
			{
				try
				{
					XmlDocument val = new XmlDocument();
					val.LoadXml(dCLDevice.DeviceInfo);
					result = ((XmlNode)val.DocumentElement).SelectSingleNode(aXtkqx0KSIocPot7nI.wHcKXkoBDR(190)).InnerText;
				}
				catch
				{
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Hv6d5pusZ(int P_0, CCObjectType P_1, object P_2)
		{
			if (P_2 == null)
			{
				return;
			}
			switch (P_1)
			{
			case CCObjectType.CalDataServer:
			{
				CILCALDATASERVERLib.ICICalDataServer value2 = (CILCALDATASERVERLib.ICICalDataServer)P_2;
				if (p7wJqBQ8L == null)
				{
					p7wJqBQ8L = new Dictionary<int, CILCALDATASERVERLib.ICICalDataServer>();
				}
				if (!p7wJqBQ8L.ContainsKey(P_0))
				{
					p7wJqBQ8L.Add(P_0, value2);
				}
				else
				{
					p7wJqBQ8L[P_0] = value2;
				}
				break;
			}
			case CCObjectType.DeviceControl:
			{
				DCLDevice value = (DCLDevice)P_2;
				if (ayPQenpAa == null)
				{
					ayPQenpAa = new Dictionary<int, DCLDevice>();
				}
				if (!ayPQenpAa.ContainsKey(P_0))
				{
					ayPQenpAa.Add(P_0, value);
				}
				else
				{
					ayPQenpAa[P_0] = value;
				}
				break;
			}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool VYy32Ns4j(int P_0, CCObjectType P_1)
		{
			bool result = true;
			switch (P_1)
			{
			case CCObjectType.CalDataServer:
				if (p7wJqBQ8L == null || !p7wJqBQ8L.ContainsKey(P_0))
				{
					result = false;
				}
				break;
			case CCObjectType.DeviceControl:
				if (ayPQenpAa == null || !ayPQenpAa.ContainsKey(P_0))
				{
					result = false;
				}
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void wh6MHO4Jx()
		{
			W0H2DuT6Q.Clear();
			GyDyCiIlW.Clear();
			if (p7wJqBQ8L != null)
			{
				foreach (CILCALDATASERVERLib.ICICalDataServer value in p7wJqBQ8L.Values)
				{
					try
					{
						(value.DataAccess.DataSource as ICICLIPSession).Disconnect();
					}
					catch
					{
					}
				}
				p7wJqBQ8L.Clear();
			}
			if (ayPQenpAa == null)
			{
				return;
			}
			foreach (DCLDevice value2 in ayPQenpAa.Values)
			{
				try
				{
					value2.Close();
				}
				catch
				{
				}
			}
			ayPQenpAa.Clear();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public object JZtUVUuWs(int P_0, CCObjectType P_1)
		{
			object result = null;
			switch (P_1)
			{
			case CCObjectType.DeviceControl:
				if (ayPQenpAa.ContainsKey(P_0))
				{
					result = ayPQenpAa[P_0];
				}
				else if (p7wJqBQ8L.ContainsKey(P_0))
				{
					result = p7wJqBQ8L[P_0].DataAccess.DataSource;
				}
				break;
			case CCObjectType.CalDataServer:
				if (p7wJqBQ8L.ContainsKey(P_0))
				{
					result = p7wJqBQ8L[P_0];
				}
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValue wnuiCfVjX(int P_0, string P_1)
		{
			IParameterValue parameterValue = null;
			if (p7wJqBQ8L.ContainsKey(P_0))
			{
				try
				{
					CILCALDATASERVERLib.ICICalEntity iCICalEntity = p5XYtkqxK(P_0, P_1);
					if (iCICalEntity is ICICalAddressableEntity iCICalAddressableEntity)
					{
						iCICalAddressableEntity.CacheMode = CILCALDATASERVERLib.tagCICacheMode.readWrite;
						iCICalAddressableEntity.ClearCache();
					}
					return V1OaGHqv65pusZpYy2.owJKL19J3C(iCICalEntity);
				}
				catch (COMException ex)
				{
					throw V1OaGHqv65pusZpYy2.Nw9K544U9b(ex);
				}
			}
			throw new ArgumentException(aXtkqx0KSIocPot7nI.wHcKXkoBDR(220), aXtkqx0KSIocPot7nI.wHcKXkoBDR(268));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void f6pmbEb4A(int P_0, string P_1, object P_2)
		{
			if (p7wJqBQ8L.ContainsKey(P_0))
			{
				try
				{
					CILCALDATASERVERLib.ICICalEntity iCICalEntity = p5XYtkqxK(P_0, P_1);
					ICICalValueEntity iCICalValueEntity = iCICalEntity as ICICalValueEntity;
					(iCICalValueEntity as ICICalAddressableEntity).CacheMode = CILCALDATASERVERLib.tagCICacheMode.dataVolatile;
					if (iCICalEntity.EntityType == CILCALDATASERVERLib.tagCISymbolicType.SymString || iCICalEntity.EntityName == aXtkqx0KSIocPot7nI.wHcKXkoBDR(298))
					{
						iCICalValueEntity.ScaledValue = Convert.ToString(P_2);
					}
					else
					{
						iCICalValueEntity.ScaledFloat = Convert.ToDouble(P_2);
					}
					return;
				}
				catch (COMException ex)
				{
					throw V1OaGHqv65pusZpYy2.Nw9K544U9b(ex);
				}
			}
			throw new ArgumentException(aXtkqx0KSIocPot7nI.wHcKXkoBDR(338), aXtkqx0KSIocPot7nI.wHcKXkoBDR(386));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void C09uIlGAn(int P_0, string P_1, string P_2, object P_3)
		{
			if (p7wJqBQ8L.ContainsKey(P_0))
			{
				try
				{
					CILCALDATASERVERLib.ICICalEntity iCICalEntity = p5XYtkqxK(P_0, P_1);
					CILCALDATASERVERLib.ICITreeNode iCITreeNode = iCICalEntity as CILCALDATASERVERLib.ICITreeNode;
					CILCALDATASERVERLib.ICITreeNode iCITreeNode2 = iCITreeNode.FirstChild;
					for (int i = 0; i < iCITreeNode.ChildCount; i++)
					{
						if ((iCITreeNode2 as CILCALDATASERVERLib.ICICalEntity).EntityName == P_2)
						{
							break;
						}
						iCITreeNode2 = iCITreeNode2.Next;
					}
					ICICalValueEntity iCICalValueEntity = iCITreeNode2 as ICICalValueEntity;
					(iCICalValueEntity as ICICalAddressableEntity).CacheMode = CILCALDATASERVERLib.tagCICacheMode.dataVolatile;
					if ((iCITreeNode2 as CILCALDATASERVERLib.ICICalEntity).EntityType == CILCALDATASERVERLib.tagCISymbolicType.SymString)
					{
						iCICalValueEntity.ScaledValue = Convert.ToString(P_3);
					}
					else
					{
						iCICalValueEntity.ScaledFloat = Convert.ToDouble(P_3);
					}
					return;
				}
				catch (COMException ex)
				{
					throw V1OaGHqv65pusZpYy2.Nw9K544U9b(ex);
				}
			}
			throw new ArgumentException(aXtkqx0KSIocPot7nI.wHcKXkoBDR(416), aXtkqx0KSIocPot7nI.wHcKXkoBDR(464));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValues jFu4EoLly(int P_0, IList<string> parameterNames, out IEnumerable<string> P_2)
		{
			ParameterValues parameterValues = new ParameterValues();
			List<string> list = new List<string>();
			if (p7wJqBQ8L.ContainsKey(P_0))
			{
				CICollection cICollection = eSnZ4fBCAlNrTOitFO.knRgNENNf();
				CISetRequestClass cISetRequestClass = eSnZ4fBCAlNrTOitFO.aBlePI6tA();
				cISetRequestClass.SetProcessingMode = tagCISetProcessingMode.SOR_SPM_OPTIMIZED;
				cISetRequestClass.Requests = cICollection;
				foreach (string parameterName in parameterNames)
				{
					try
					{
						CISetItemClass cISetItemClass = eSnZ4fBCAlNrTOitFO.yJgNwpF8a();
						CILCALDATASERVERLib.ICICalEntity iCICalEntity = p5XYtkqxK(P_0, parameterName);
						if (iCICalEntity == null)
						{
							list.Add(parameterName);
							continue;
						}
						(iCICalEntity as CICalAddressableEntity).CacheMode = CILCALDATASERVERLib.tagCICacheMode.readWrite;
						cISetItemClass.request = iCICalEntity;
						cISetItemClass.RequestType = CILCALDATASERVERLib.RequestTypeEnum.DEVCTRL_READ;
						cICollection.Add(cISetItemClass);
					}
					catch (COMException ex)
					{
						ECMServicesException ex2 = V1OaGHqv65pusZpYy2.Nw9K544U9b(ex);
						if (ex2.ErrorCode == ECMServicesErrorCodes.DatalinkError || ex2.ErrorCode == ECMServicesErrorCodes.DatalinkTimeout)
						{
							throw ex2;
						}
						list.Add(parameterName);
					}
					catch
					{
						list.Add(parameterName);
					}
				}
				cICollection = k6A6DkFl7(P_0, list, cICollection, cISetRequestClass);
				for (int i = 0; i < cICollection.Count; i++)
				{
					try
					{
						ICISetItem iCISetItem = cICollection[i] as ICISetItem;
						if (iCISetItem.Result == 0)
						{
							if (iCISetItem.request is CILCALDATASERVERLib.ICICalEntity iCICalEntity2)
							{
								IParameterValue item = V1OaGHqv65pusZpYy2.owJKL19J3C(iCICalEntity2);
								parameterValues.Add(item);
							}
						}
						else
						{
							CILCALDATASERVERLib.ICICalEntity iCICalEntity3 = iCISetItem.request as CILCALDATASERVERLib.ICICalEntity;
							list.Add(iCICalEntity3.EntityName);
						}
					}
					catch (COMException ex3)
					{
						ECMServicesException ex4 = V1OaGHqv65pusZpYy2.Nw9K544U9b(ex3);
						if (ex4.ErrorCode == ECMServicesErrorCodes.DatalinkError || ex4.ErrorCode == ECMServicesErrorCodes.DatalinkTimeout)
						{
							throw ex4;
						}
						if (cICollection[i] is ICISetItem { request: CILCALDATASERVERLib.ICICalEntity request })
						{
							list.Add(request.EntityName);
						}
					}
				}
				P_2 = list;
				return parameterValues;
			}
			throw new ArgumentException(aXtkqx0KSIocPot7nI.wHcKXkoBDR(494), aXtkqx0KSIocPot7nI.wHcKXkoBDR(542));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void uwxf7OI93(int P_0, IDictionary<string, object> paramValues, out IEnumerable<string> P_2)
		{
			List<string> list = new List<string>();
			foreach (KeyValuePair<string, object> paramValue in paramValues)
			{
				try
				{
					f6pmbEb4A(P_0, paramValue.Key, paramValue.Value);
				}
				catch (COMException ex)
				{
					ECMServicesException ex2 = V1OaGHqv65pusZpYy2.Nw9K544U9b(ex);
					if (ex2.ErrorCode == ECMServicesErrorCodes.DatalinkError || ex2.ErrorCode == ECMServicesErrorCodes.DatalinkTimeout)
					{
						throw ex2;
					}
					list.Add(paramValue.Key);
				}
				catch (ECMServicesException ex3)
				{
					if (ex3.ErrorCode == ECMServicesErrorCodes.DatalinkError || ex3.ErrorCode == ECMServicesErrorCodes.DatalinkTimeout)
					{
						throw ex3;
					}
					list.Add(paramValue.Key);
				}
			}
			P_2 = list;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int GLASk09rw(int P_0, string P_1, IDictionary<object, object> inArgs, out IParameterValues P_3)
		{
			int responseCode = -1;
			CILCALDATASERVERLib.ICICalDataServer iCICalDataServer = p7wJqBQ8L[P_0];
			ICICalOperationEntity iCICalOperationEntity = (ICICalOperationEntity)iCICalDataServer.GetEntityByName(null, P_1);
			object[] array = null;
			if (inArgs != null && inArgs.Count > 0)
			{
				array = new object[inArgs.Count];
				int num = 0;
				foreach (KeyValuePair<object, object> inArg in inArgs)
				{
					string text = Convert.ToString(inArg.Key);
					CILCALDATASERVERLib.ICICalEntity entityByName = iCICalDataServer.GetEntityByName(null, text);
					if (entityByName is ICICalValueEntity iCICalValueEntity)
					{
						(iCICalValueEntity as ICICalAddressableEntity).CacheMode = CILCALDATASERVERLib.tagCICacheMode.readWrite;
						if (!V1OaGHqv65pusZpYy2.sW0z2QZMG(iCICalValueEntity as CILCALDATASERVERLib.ICICalEntity) && double.TryParse(inArg.Value.ToString(), out var result))
						{
							iCICalValueEntity.ScaledFloat = result;
						}
						else if (inArg.Value != null)
						{
							iCICalValueEntity.ScaledValue = inArg.Value.ToString();
						}
						else
						{
							iCICalValueEntity.ScaledValue = string.Empty;
						}
						array[num++] = iCICalValueEntity;
						continue;
					}
					CILCALDATASERVERLib.ICICalEntity iCICalEntity = jILcsXPlN(P_0, text);
					if (iCICalEntity != null)
					{
						array[num++] = iCICalEntity;
					}
					else
					{
						if (entityByName.EntityType != CILCALDATASERVERLib.tagCISymbolicType.SymArray)
						{
							continue;
						}
						List<byte> list = new List<byte>();
						foreach (object item in (IEnumerable)inArg.Value)
						{
							list.Add(Convert.ToByte(item));
						}
						byte[] array2 = new byte[list.Count];
						int num2 = 0;
						foreach (byte item2 in list)
						{
							array2[num2++] = item2;
						}
						ICICalAddressableEntity iCICalAddressableEntity = entityByName as ICICalAddressableEntity;
						iCICalAddressableEntity.CacheMode = CILCALDATASERVERLib.tagCICacheMode.readWrite;
						object rawData = array2;
						iCICalAddressableEntity.RawData = rawData;
						array[num++] = iCICalAddressableEntity;
					}
				}
			}
			object inputEntities = array;
			object outputEntities = new object();
			try
			{
				iCICalOperationEntity.Process(inputEntities, out outputEntities, out responseCode);
				P_3 = QS79GaNAI(P_0, outputEntities);
			}
			catch (COMException ex)
			{
				ECMServicesException ex2 = V1OaGHqv65pusZpYy2.OwLKwuXIww(ex);
				if (ex2.ErrorCode == ECMServicesErrorCodes.DatalinkError || ex2.ErrorCode == ECMServicesErrorCodes.DatalinkTimeout)
				{
					throw ex2;
				}
				P_3 = null;
				responseCode &= 0xFFFF;
			}
			return responseCode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private IParameterValues QS79GaNAI(int P_0, object P_1)
		{
			ParameterValues parameterValues = null;
			if (P_1 == null)
			{
				parameterValues = null;
			}
			else
			{
				object[] array = (object[])P_1;
				if (array.Length == 0)
				{
					parameterValues = null;
				}
				else
				{
					parameterValues = new ParameterValues();
					object[] array2 = array;
					foreach (object obj in array2)
					{
						IParameterValue parameterValue = V1OaGHqv65pusZpYy2.owJKL19J3C(obj as CILCALDATASERVERLib.ICICalEntity);
						parameterValues.Add(parameterValue);
						ICICalValueEntity iCICalValueEntity = obj as ICICalValueEntity;
						if (iCICalValueEntity == null)
						{
							CIorcPot7(P_0, parameterValue.ParameterAs<string>(), obj as CILCALDATASERVERLib.ICICalEntity);
						}
					}
				}
			}
			return parameterValues;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private CICollection k6A6DkFl7(int P_0, List<string> failedParameters, CICollection P_2, CISetRequestClass P_3)
		{
			CILCALDATASERVERLib.ICIProcessRequest iCIProcessRequest = p7wJqBQ8L[P_0] as CILCALDATASERVERLib.ICIProcessRequest;
			try
			{
				iCIProcessRequest.Process(P_3);
				P_2 = P_3.Requests;
			}
			catch (COMException)
			{
				ECMServicesErrorCodes eCMServicesErrorCodes = V1OaGHqv65pusZpYy2.aFHKKETtDh(P_3.DclStatus);
				if (eCMServicesErrorCodes == ECMServicesErrorCodes.DatalinkError || eCMServicesErrorCodes == ECMServicesErrorCodes.DatalinkTimeout)
				{
					throw new ECMServicesException(eCMServicesErrorCodes);
				}
				P_2 = P_3.Requests;
				int num = 0;
				while (num < P_2.Count)
				{
					ICISetItem iCISetItem = P_2[num] as ICISetItem;
					if (iCISetItem.Result == (int)N24WLAEWj)
					{
						P_2.Remove(num);
						string entityName = (iCISetItem.request as CILCALDATASERVERLib.ICICalEntity).EntityName;
						failedParameters.Add(entityName);
					}
					else
					{
						num++;
					}
				}
				if (P_3.SetProcessingMode == tagCISetProcessingMode.SOR_SPM_OPTIMIZED && P_2.Count != 0)
				{
					P_3.SetProcessingMode = tagCISetProcessingMode.SOR_SPM_CONTROLLED;
					k6A6DkFl7(P_0, failedParameters, P_2, P_3);
				}
				else
				{
					P_2 = P_3.Requests;
					int num2 = 0;
					while (num2 < P_2.Count)
					{
						ICISetItem iCISetItem2 = P_2[num2] as ICISetItem;
						P_2.Remove(num2);
						string entityName2 = (iCISetItem2.request as CILCALDATASERVERLib.ICICalEntity).EntityName;
						failedParameters.Add(entityName2);
					}
				}
			}
			return P_2;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private CILCALDATASERVERLib.ICICalEntity p5XYtkqxK(int P_0, string P_1)
		{
			CILCALDATASERVERLib.ICICalEntity iCICalEntity = null;
			if (!W0H2DuT6Q.ContainsKey(P_0))
			{
				W0H2DuT6Q.Add(P_0, new Dictionary<string, CILCALDATASERVERLib.ICICalEntity>());
			}
			if (W0H2DuT6Q[P_0].ContainsKey(P_1))
			{
				iCICalEntity = W0H2DuT6Q[P_0][P_1];
			}
			else
			{
				iCICalEntity = p7wJqBQ8L[P_0].GetEntityByName(null, P_1);
				W0H2DuT6Q[P_0].Add(P_1, iCICalEntity);
			}
			return iCICalEntity;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void CIorcPot7(int P_0, string P_1, CILCALDATASERVERLib.ICICalEntity P_2)
		{
			if (!GyDyCiIlW.ContainsKey(P_0))
			{
				GyDyCiIlW.Add(P_0, new Dictionary<string, CILCALDATASERVERLib.ICICalEntity>());
			}
			if (GyDyCiIlW[P_0].ContainsKey(P_1))
			{
				GyDyCiIlW[P_0][P_1] = P_2;
			}
			else
			{
				GyDyCiIlW[P_0].Add(P_1, P_2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private CILCALDATASERVERLib.ICICalEntity jILcsXPlN(int P_0, string P_1)
		{
			CILCALDATASERVERLib.ICICalEntity result = null;
			if (!GyDyCiIlW.ContainsKey(P_0))
			{
				GyDyCiIlW.Add(P_0, new Dictionary<string, CILCALDATASERVERLib.ICICalEntity>());
			}
			if (GyDyCiIlW[P_0].ContainsKey(P_1))
			{
				result = GyDyCiIlW[P_0][P_1];
			}
			else
			{
				foreach (Dictionary<string, CILCALDATASERVERLib.ICICalEntity> value in GyDyCiIlW.Values)
				{
					if (value.ContainsKey(P_1))
					{
						result = value[P_1];
						break;
					}
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static RiJgwpDF8aqnRNENNf()
		{
			RC5jUHMDkrkP9QtAnE.ggyda19zX8XvI();
			LRDHFxmj2 = aXtkqx0KSIocPot7nI.wHcKXkoBDR(572);
			N24WLAEWj = 2147500037u;
		}
	}
}
namespace C3SkWen3BkLxy6mgKG
{
	internal static class CWgu9fFT7UX6chSr7P
	{
		private static readonly string z0JI4DRNX;

		private static readonly string eCApC5jUH;

		private static readonly string hkrTkP9Qt;

		private static readonly string RnEvLY81o;

		private static readonly string aFex9Bmqh;

		private static SymbolicTreeClass Ph9CHRTYo;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static CILModuleDetection.ICICollection Q7LsdDREb(IPhysicalConnectionConfiguration P_0, out DCLDevice P_1)
		{
			P_1 = eSnZ4fBCAlNrTOitFO.Ehf8KJPlf();
			CIModuleDetection cIModuleDetection = eSnZ4fBCAlNrTOitFO.qvUFO3mWt();
			string xmlDataLinkConfiguration = Q4lh8yIRP(P_0);
			string xmlSessionConfiguration = AigZrMffK(P_0);
			return cIModuleDetection.Detect(P_1, xmlDataLinkConfiguration, eCApC5jUH, xmlSessionConfiguration);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string AigZrMffK(IPhysicalConnectionConfiguration P_0)
		{
			return hkrTkP9Qt;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string Q4lh8yIRP(IConnectionConfiguration P_0)
		{
			return RnEvLY81o;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static ECUProperties nKwAPq29m(ICIDeviceInfo2 P_0)
		{
			ECUProperties eCUProperties = new ECUProperties();
			eCUProperties.SourceAddress = P_0.Address;
			eCUProperties.ECUId = P_0.ModuleIdentifier;
			eCUProperties.ProductId = P_0.ProductIdentifier;
			eCUProperties.RunLocation = DdtP3bfsu(P_0.RunLocation);
			if (eCUProperties.ECUId == z0JI4DRNX)
			{
				eCUProperties.GTISLevel = GTISLevel.GTIS_45;
			}
			else
			{
				eCUProperties.GTISLevel = GTISLevel.Unknown;
			}
			eCUProperties.HarnessKeyStatus = P_0.HarnessKeyInputStatus;
			eCUProperties.HierarchyState = ECUHierarchy.Unknown;
			return eCUProperties;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static CILCALDATASERVERLib.ICICalDataServer Mnwo9SBtB(ICIDCLDevice P_0, ICIDeviceInfo2 P_1)
		{
			CILCALDATASERVERLib.ICICalDataServer iCICalDataServer = eSnZ4fBCAlNrTOitFO.LqCna57Sn();
			CILCALDATASERVERLib.ICIDataAccess iCIDataAccess = (CILCALDATASERVERLib.ICIDataAccess)eSnZ4fBCAlNrTOitFO.VOi1tFOxE();
			iCIDataAccess.DataSource = P_0;
			iCICalDataServer.DataAccess = iCIDataAccess;
			iCICalDataServer.Configuration = aFex9Bmqh;
			if (P_1 is ICIDeviceInfo3 iCIDeviceInfo)
			{
				iCICalDataServer.ByteOrder = (CILCALDATASERVERLib.tagCIByteOrder)iCIDeviceInfo.ByteOrder;
			}
			else
			{
				iCICalDataServer.ByteOrder = CILCALDATASERVERLib.tagCIByteOrder.ECM;
			}
			iCICalDataServer.SymbolicTree = (CILCALDATASERVERLib.ICISymbolicTree)DhsEePNSu();
			return iCICalDataServer;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static CILSymbolicTree.ICISymbolicTree DhsEePNSu()
		{
			if (Ph9CHRTYo == null)
			{
				string text = Path.Combine(Environment.CurrentDirectory, ECMServicesConfiguration.Configuration.GetConfigurationValue(aXtkqx0KSIocPot7nI.wHcKXkoBDR(758)));
				ICICompression iCICompression = new CompressClass();
				iCICompression.ArchiveName = text;
				iCICompression.Password = ECMServicesConfiguration.Configuration.GetConfigurationValue(aXtkqx0KSIocPot7nI.wHcKXkoBDR(778));
				iCICompression.FileCleanup = false;
				iCICompression.ExtractToMemory = false;
				string bstrFilename = (iCICompression.ExtractLocation = Path.GetTempFileName());
				try
				{
					if (iCICompression.ExtractSingleFile(Path.GetFileName(text)) != ExtractResultEnum.ExtractSuccess)
					{
						throw new FileLoadException();
					}
				}
				catch (COMException)
				{
					throw new FileLoadException(text + aXtkqx0KSIocPot7nI.wHcKXkoBDR(806));
				}
				ICIFile iCIFile = eSnZ4fBCAlNrTOitFO.Ut6VmMp71();
				iCIFile.ReadFile(bstrFilename);
				ICISymbolicInit iCISymbolicInit = (ICISymbolicInit)iCIFile;
				Ph9CHRTYo = eSnZ4fBCAlNrTOitFO.P4fqCAlNr();
				iCISymbolicInit.AttachToTree(Ph9CHRTYo, "", "");
			}
			return Ph9CHRTYo;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static RunLocation DdtP3bfsu(CIRunLocationEnum P_0)
		{
			RunLocation runLocation = RunLocation.Unknown;
			return P_0 switch
			{
				CIRunLocationEnum.MDC_RL_DEFAULT => RunLocation.Default, 
				CIRunLocationEnum.MDC_RL_DEVELOPMENT => RunLocation.Development, 
				CIRunLocationEnum.MDC_RL_ROM_BOOT_LOADER => RunLocation.Boot, 
				_ => RunLocation.Unknown, 
			};
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static CWgu9fFT7UX6chSr7P()
		{
			RC5jUHMDkrkP9QtAnE.ggyda19zX8XvI();
			z0JI4DRNX = aXtkqx0KSIocPot7nI.wHcKXkoBDR(856);
			eCApC5jUH = aXtkqx0KSIocPot7nI.wHcKXkoBDR(864);
			hkrTkP9Qt = aXtkqx0KSIocPot7nI.wHcKXkoBDR(1212);
			RnEvLY81o = aXtkqx0KSIocPot7nI.wHcKXkoBDR(3334);
			aFex9Bmqh = aXtkqx0KSIocPot7nI.wHcKXkoBDR(4294);
		}
	}
}
namespace ns4j3h16HO4JxlZtVU
{
	internal static class V1OaGHqv65pusZpYy2
	{
		private const int hfyK7g3AlP = 16777244;

		private const int mUuKbHkUnE = 16786075;

		private const int Fp2KBvuqpA = 16777220;

		private const string argKOxCgm5 = "s";

		private static readonly string loLKDmlmQ6;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static bool sW0z2QZMG(CILCALDATASERVERLib.ICICalEntity P_0)
		{
			bool result = false;
			if (P_0.EntityType == CILCALDATASERVERLib.tagCISymbolicType.SymString)
			{
				result = true;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static IParameterValue owJKL19J3C(CILCALDATASERVERLib.ICICalEntity P_0)
		{
			ParameterValue parameterValue = null;
			switch (P_0.EntityType)
			{
			case CILCALDATASERVERLib.tagCISymbolicType.SymArray:
			{
				CILCALDATASERVERLib.ICITreeNode iCITreeNode3 = P_0 as CILCALDATASERVERLib.ICITreeNode;
				if (!(P_0.EntityName == aXtkqx0KSIocPot7nI.wHcKXkoBDR(4360)) && !(P_0.EntityName == aXtkqx0KSIocPot7nI.wHcKXkoBDR(4388)) && iCITreeNode3.Data != null && iCITreeNode3.Data is Dict dict2)
				{
					object Key2 = loLKDmlmQ6;
					object pRetItem2 = 1;
					dict2.let_Item(ref Key2, ref pRetItem2);
				}
				CILCALDATASERVERLib.ICISymbolicData iCISymbolicData2 = iCITreeNode3.FirstChild as CILCALDATASERVERLib.ICISymbolicData;
				if (iCISymbolicData2 == null && iCITreeNode3.FirstChild.ChildCount == 0)
				{
					ICICalArrayEntity iCICalArrayEntity = P_0 as ICICalArrayEntity;
					List<object> list = new List<object>(iCICalArrayEntity.NumberOfElements);
					for (int k = 0; k < iCICalArrayEntity.NumberOfElements; k++)
					{
						iCICalArrayEntity.CurrentIndex = k;
						ICICalValueEntity iCICalValueEntity4 = (P_0 as CILCALDATASERVERLib.ICITreeNode).FirstChild as ICICalValueEntity;
						try
						{
							list.Add(iCICalValueEntity4.ScaledFloat);
						}
						catch (COMException)
						{
							break;
						}
						catch (NotImplementedException)
						{
							list.Add(iCICalValueEntity4.ScaledValue);
						}
					}
					parameterValue = new ParameterValue(P_0.EntityName, ParameterValueType.Array, list);
					break;
				}
				parameterValue = new ParameterValue(P_0.EntityName, ParameterValueType.Array, null);
				ICICalArrayEntity iCICalArrayEntity2 = P_0 as ICICalArrayEntity;
				int numberOfElements = iCICalArrayEntity2.NumberOfElements;
				for (int l = 0; l < numberOfElements; l++)
				{
					try
					{
						iCICalArrayEntity2.CurrentIndex = l;
						CILCALDATASERVERLib.ICICalEntity iCICalEntity = (P_0 as CILCALDATASERVERLib.ICITreeNode).FirstChild as CILCALDATASERVERLib.ICICalEntity;
						parameterValue.AddChild(owJKL19J3C(iCICalEntity));
					}
					catch (Exception)
					{
					}
				}
				break;
			}
			case CILCALDATASERVERLib.tagCISymbolicType.SymStructure:
			{
				parameterValue = new ParameterValue(P_0.EntityName, ParameterValueType.Structure, null);
				CILCALDATASERVERLib.ICITreeNode iCITreeNode = P_0 as CILCALDATASERVERLib.ICITreeNode;
				if (iCITreeNode.Data != null && iCITreeNode.Data is Dict dict)
				{
					object Key = loLKDmlmQ6;
					object pRetItem = 1;
					dict.let_Item(ref Key, ref pRetItem);
				}
				CILCALDATASERVERLib.ICITreeNode iCITreeNode2 = iCITreeNode.FirstChild;
				for (int j = 0; j < iCITreeNode.ChildCount; j++)
				{
					parameterValue.AddChild(owJKL19J3C(iCITreeNode2 as CILCALDATASERVERLib.ICICalEntity));
					iCITreeNode2 = iCITreeNode2.Next;
				}
				break;
			}
			case CILCALDATASERVERLib.tagCISymbolicType.SymEnumeration:
			{
				ICICalValueEntity iCICalValueEntity5 = P_0 as ICICalValueEntity;
				parameterValue = new ParameterValue(P_0.EntityName, ParameterValueType.Enumeration, Convert.ChangeType(iCICalValueEntity5.ScaledFloat, typeof(int)));
				break;
			}
			case CILCALDATASERVERLib.tagCISymbolicType.SymFloatingPoint:
			{
				ICICalValueEntity iCICalValueEntity = P_0 as ICICalValueEntity;
				double num = iCICalValueEntity.ScaledFloat;
				try
				{
					CILCALDATASERVERLib.ICISymbolicData iCISymbolicData = (iCICalValueEntity as CILCALDATASERVERLib.ICITreeNode).Data as CILCALDATASERVERLib.ICISymbolicData;
					if (iCISymbolicData.Units == aXtkqx0KSIocPot7nI.wHcKXkoBDR(4428))
					{
						num *= 1000.0;
					}
				}
				catch
				{
				}
				parameterValue = new ParameterValue(P_0.EntityName, ParameterValueType.Decimal, num);
				break;
			}
			case CILCALDATASERVERLib.tagCISymbolicType.SymInteger:
			{
				ICICalValueEntity iCICalValueEntity6 = P_0 as ICICalValueEntity;
				double num2 = iCICalValueEntity6.ScaledFloat;
				try
				{
					CILCALDATASERVERLib.ICISymbolicData iCISymbolicData3 = (iCICalValueEntity6 as CILCALDATASERVERLib.ICITreeNode).Data as CILCALDATASERVERLib.ICISymbolicData;
					if (iCISymbolicData3.Units == aXtkqx0KSIocPot7nI.wHcKXkoBDR(4434) && (iCISymbolicData3.ID == 16777244 || iCISymbolicData3.ID == 16786075 || iCISymbolicData3.ID == 16777220))
					{
						num2 *= 1000.0;
					}
				}
				catch
				{
				}
				parameterValue = new ParameterValue(P_0.EntityName, ParameterValueType.Integer, Convert.ChangeType(num2, typeof(long)));
				break;
			}
			case CILCALDATASERVERLib.tagCISymbolicType.SymDateTime:
			{
				ICICalValueEntity iCICalValueEntity3 = P_0 as ICICalValueEntity;
				parameterValue = ((!(P_0.EntityName == aXtkqx0KSIocPot7nI.wHcKXkoBDR(4440))) ? new ParameterValue(P_0.EntityName, ParameterValueType.DateTime, iCICalValueEntity3.ScaledFloat.ToString()) : new ParameterValue(P_0.EntityName, ParameterValueType.DateTime, iCICalValueEntity3.ScaledValue));
				break;
			}
			case CILCALDATASERVERLib.tagCISymbolicType.SymString:
			{
				ICICalValueEntity iCICalValueEntity2 = P_0 as ICICalValueEntity;
				parameterValue = new ParameterValue(P_0.EntityName, ParameterValueType.String, iCICalValueEntity2.ScaledValue);
				break;
			}
			case CILCALDATASERVERLib.tagCISymbolicType.SymDataBlock:
			{
				ICICalAddressableEntity iCICalAddressableEntity = P_0 as ICICalAddressableEntity;
				byte[] array = (byte[])iCICalAddressableEntity.RawData;
				StringBuilder stringBuilder = new StringBuilder();
				byte[] array2 = array;
				foreach (byte b in array2)
				{
					stringBuilder.Append(b.ToString(aXtkqx0KSIocPot7nI.wHcKXkoBDR(4480)));
				}
				parameterValue = new ParameterValue(P_0.EntityName, ParameterValueType.String, stringBuilder.ToString());
				break;
			}
			}
			return parameterValue;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static ECMServicesErrorCodes aFHKKETtDh(int P_0)
		{
			ECMServicesErrorCodes result = ECMServicesErrorCodes.UnknownError;
			switch (P_0)
			{
			case 0:
				result = ECMServicesErrorCodes.NoError;
				break;
			case 22:
			case 187:
			case 204:
				result = ECMServicesErrorCodes.DatalinkError;
				break;
			case 23:
			case 58:
			case 97:
				result = ECMServicesErrorCodes.DatalinkTimeout;
				break;
			case 24:
			case 25:
			case 26:
			case 28:
			case 29:
			case 30:
			case 31:
			case 32:
			case 33:
			case 34:
			case 35:
			case 36:
			case 37:
			case 38:
			case 39:
			case 40:
			case 41:
			case 42:
			case 43:
			case 44:
			case 45:
			case 46:
			case 47:
			case 48:
			case 49:
			case 50:
			case 51:
			case 52:
				result = ECMServicesErrorCodes.ErrorFromECU;
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static ECMServicesException Nw9K544U9b(COMException P_0)
		{
			ECMServicesException ex = null;
			ECMServicesErrorCodes errorCode = ECMServicesErrorCodes.UnknownError;
			try
			{
				errorCode = ((!AWs3nuVCfVjXO6pbEb.c9bKnQps8G().LKJK18Rce6()) ? ECMServicesErrorCodes.DatalinkError : ECMServicesErrorCodes.ModuleRejected);
				return new ECMServicesException(errorCode, string.Empty, P_0);
			}
			catch (COMException innerException)
			{
				return new ECMServicesException(errorCode, string.Empty, innerException);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static ECMServicesException OwLKwuXIww(COMException P_0)
		{
			ECMServicesException ex = null;
			ECMServicesErrorCodes errorCode = ECMServicesErrorCodes.UnknownError;
			try
			{
				string message = P_0.Message;
				ICIErrorMessageSet2 iCIErrorMessageSet = eSnZ4fBCAlNrTOitFO.iOH06ykYG();
				iCIErrorMessageSet.loadXML(message);
				if (iCIErrorMessageSet.DCLStatus != 0)
				{
					errorCode = aFHKKETtDh(iCIErrorMessageSet.DCLStatus);
				}
				return new ECMServicesException(errorCode, string.Empty, P_0);
			}
			catch (COMException innerException)
			{
				return new ECMServicesException(errorCode, string.Empty, innerException);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static V1OaGHqv65pusZpYy2()
		{
			RC5jUHMDkrkP9QtAnE.ggyda19zX8XvI();
			loLKDmlmQ6 = aXtkqx0KSIocPot7nI.wHcKXkoBDR(4488);
		}
	}
}
namespace BAf09IelGAnFFuEoLl
{
	internal class AWs3nuVCfVjXO6pbEb
	{
		private static AWs3nuVCfVjXO6pbEb qmYKelhaC3;

		private MsgManager aEMKNFOVmZ;

		private bool fRcKgC7ut3;

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public static AWs3nuVCfVjXO6pbEb c9bKnQps8G()
		{
			return qmYKelhaC3;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private AWs3nuVCfVjXO6pbEb()
		{
			RC5jUHMDkrkP9QtAnE.ggyda19zX8XvI();
			base..ctor();
			aEMKNFOVmZ = eSnZ4fBCAlNrTOitFO.qBwX7m4XY();
			aEMKNFOVmZ.ReceiveMessage += eX7KFK11ZH;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public bool LKJK18Rce6()
		{
			return fRcKgC7ut3;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void LTQK8QasXx()
		{
			fRcKgC7ut3 = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void eX7KFK11ZH(ICIMsg P_0)
		{
			if (P_0 != null && P_0.MessageType == MsgTypeEnum.MTYPE_DIAGNOSTIC && P_0 is ICIDiagnosticMsg iCIDiagnosticMsg && (iCIDiagnosticMsg.severity == MsgSeverityTypeEnum.MSGSEV_ERROR || iCIDiagnosticMsg.severity == MsgSeverityTypeEnum.MSGSEV_FATAL) && iCIDiagnosticMsg.Identifier == 96)
			{
				fRcKgC7ut3 = false;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static AWs3nuVCfVjXO6pbEb()
		{
			RC5jUHMDkrkP9QtAnE.ggyda19zX8XvI();
			qmYKelhaC3 = new AWs3nuVCfVjXO6pbEb();
		}
	}
}
internal class <Module>{993B9883-EEC9-4884-9A50-27E5BED13430}
{
}
namespace QS7GaNgAIn6ADkFl70
{
	internal class NRwx7ONI93rLAk09rw
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module lKhK0aO5FJ;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void iv4da199Xhaul(int typemdt)
		{
			Type type = lKhK0aO5FJ.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)lKhK0aO5FJ.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public NRwx7ONI93rLAk09rw()
		{
			RC5jUHMDkrkP9QtAnE.ggyda19zX8XvI();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static NRwx7ONI93rLAk09rw()
		{
			RC5jUHMDkrkP9QtAnE.ggyda19zX8XvI();
			lKhK0aO5FJ = typeof(NRwx7ONI93rLAk09rw).Assembly.ManifestModule;
		}
	}
}
namespace asXPlNXkRDFxmj2224
{
	internal class aXtkqx0KSIocPot7nI
	{
		internal class aAEWjktHACAco507wq : Attribute
		{
			internal class fQ8LKyaPenpAaWUWFL<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public fQ8LKyaPenpAaWUWFL()
				{
					RC5jUHMDkrkP9QtAnE.ggyda19zX8XvI();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[aAEWjktHACAco507wq(typeof(aXtkqx0KSIocPot7nI/aAEWjktHACAco507wq/fQ8LKyaPenpAaWUWFL<object>[]))]
			public aAEWjktHACAco507wq(object P_0)
			{
				RC5jUHMDkrkP9QtAnE.ggyda19zX8XvI();
				base..ctor();
			}
		}

		internal class YEmv0HGDuT6QryDCiI
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[aAEWjktHACAco507wq(typeof(aXtkqx0KSIocPot7nI/aAEWjktHACAco507wq/fQ8LKyaPenpAaWUWFL<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (Slf5bXF6Q9(Convert.ToBase64String(typeof(aXtkqx0KSIocPot7nI).Assembly.GetName().GetPublicKeyToken()), aXtkqx0KSIocPot7nI.wHcKXkoBDR(4518)) != aXtkqx0KSIocPot7nI.wHcKXkoBDR(4524))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[aAEWjktHACAco507wq(typeof(aXtkqx0KSIocPot7nI/aAEWjktHACAco507wq/fQ8LKyaPenpAaWUWFL<object>[]))]
			internal static string Slf5bXF6Q9(string P_0, string P_1)
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
			public YEmv0HGDuT6QryDCiI()
			{
				RC5jUHMDkrkP9QtAnE.ggyda19zX8XvI();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint JWh7LdjDREbuigrMff([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr aA4l8yRIRPNKwPq29m();

		internal struct Mnw9SBdtB9hsePNSu9
		{
			internal bool BK35B149oB;

			internal byte[] NOK5OZA1SP;
		}

		[Flags]
		private enum vt3bfs3um0J4DRNXbC
		{

		}

		private static byte[] VaEK2JaoZk;

		private static int euUKPmXM03;

		private static SortedList XaSKpJMUlW;

		internal static JWh7LdjDREbuigrMff M2HKxuZcAl;

		private static int TXW55F5GDH;

		private static IntPtr KyY5wLBybf;

		internal static Hashtable Ni157p6BWw;

		private static byte[] XphKZMNlxv;

		private static IntPtr GB8KAuFyOo;

		private static int Nsj5LZRPDf;

		private static byte[] AJRKyTgl9N;

		private static long TGqKvtVhtW;

		internal static JWh7LdjDREbuigrMff KFEKCcDgel;

		private static long uLtKzNG2ne;

		private static int[] NYAKEaimCq;

		private static byte[] LOIKseffLQ;

		private static bool EvM5KbLDcT;

		private static int HiKKTLXV7X;

		private static bool g3ZKIXrkIs;

		private static IntPtr zVkKh1tPeR;

		private static object DeEKo0ZrRG;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static aXtkqx0KSIocPot7nI()
		{
			VaEK2JaoZk = new byte[0];
			AJRKyTgl9N = new byte[0];
			LOIKseffLQ = new byte[0];
			XphKZMNlxv = new byte[0];
			zVkKh1tPeR = IntPtr.Zero;
			GB8KAuFyOo = IntPtr.Zero;
			DeEKo0ZrRG = new string[0];
			NYAKEaimCq = new int[0];
			euUKPmXM03 = 1;
			g3ZKIXrkIs = false;
			XaSKpJMUlW = new SortedList();
			HiKKTLXV7X = 0;
			TGqKvtVhtW = 0L;
			M2HKxuZcAl = null;
			KFEKCcDgel = null;
			uLtKzNG2ne = 0L;
			Nsj5LZRPDf = 0;
			EvM5KbLDcT = false;
			TXW55F5GDH = 0;
			KyY5wLBybf = IntPtr.Zero;
			Ni157p6BWw = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void cPSda19HOVLVC()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[aAEWjktHACAco507wq(typeof(aXtkqx0KSIocPot7nI/aAEWjktHACAco507wq/fQ8LKyaPenpAaWUWFL<object>[]))]
		static string wHcKXkoBDR(int P_0)
		{
			int num = 74;
			int num7 = default(int);
			int num4 = default(int);
			byte[] array = default(byte[]);
			byte[] array5 = default(byte[]);
			byte[] array3 = default(byte[]);
			byte[] array2 = default(byte[]);
			int num5 = default(int);
			MemoryStream memoryStream = default(MemoryStream);
			BinaryReader binaryReader = default(BinaryReader);
			int num2 = default(int);
			CryptoStream cryptoStream = default(CryptoStream);
			ICryptoTransform transform = default(ICryptoTransform);
			byte[] array4 = default(byte[]);
			byte[] array6 = default(byte[]);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			while (true)
			{
				int num3;
				int num6;
				switch (num)
				{
				case 36:
					num7 = 168 - 65;
					num3 = 305;
					if (fGbhacYLbmx2eV9ptL())
					{
						goto case 163;
					}
					goto IL_0477;
				case 163:
					num4 = 13 + 113;
					num = 266;
					continue;
				case 150:
					num4 = 12 + 47;
					num = 273;
					continue;
				case 167:
					array[1] = (byte)num4;
					num3 = 287;
					goto IL_0477;
				case 62:
					array[12] = 187;
					num3 = 150;
					goto IL_0477;
				case 154:
					array[1] = 149;
					num6 = 328;
					goto IL_0473;
				case 285:
					array[2] = 45;
					num3 = 278;
					goto IL_0477;
				case 171:
					num7 = 136 + 37;
					num = 84;
					continue;
				case 43:
					num4 = 196 - 65;
					num3 = 235;
					if (false)
					{
						goto case 258;
					}
					goto IL_0477;
				case 258:
					array[31] = 104;
					num3 = 31;
					goto IL_0477;
				case 242:
					array[30] = (byte)num4;
					num6 = 135;
					goto IL_0473;
				case 145:
					num4 = 96 + 102;
					num3 = 130;
					goto IL_0477;
				case 228:
					array[31] = 91;
					num = 258;
					continue;
				case 168:
					array[8] = (byte)num4;
					num3 = 29;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 313;
				case 126:
					num7 = 237 - 79;
					num = 49;
					continue;
				case 302:
					array[25] = 181;
					num6 = 6;
					goto IL_0473;
				case 330:
					array5[15] = array3[7];
					num = 77;
					continue;
				case 266:
					array[13] = (byte)num4;
					num = 126;
					continue;
				case 212:
					array[3] = (byte)num7;
					num3 = 208;
					if (fGbhacYLbmx2eV9ptL())
					{
						goto case 84;
					}
					goto IL_0477;
				case 84:
					array[18] = (byte)num7;
					num3 = 87;
					goto IL_0477;
				case 125:
					array[3] = (byte)num4;
					num3 = 97;
					if (false)
					{
						goto case 290;
					}
					goto IL_0477;
				case 290:
					array[17] = (byte)num4;
					num = 216;
					continue;
				case 224:
					array[14] = 118;
					num3 = 299;
					if (fGbhacYLbmx2eV9ptL())
					{
						goto case 142;
					}
					goto IL_0477;
				case 142:
					num7 = 103 + 23;
					num = 161;
					continue;
				case 201:
					array[0] = (byte)num7;
					num3 = 275;
					goto IL_0477;
				case 327:
					array[7] = (byte)num4;
					num = 180;
					continue;
				case 135:
					num7 = 142 + 94;
					num = 263;
					continue;
				case 265:
					array = new byte[32];
					num3 = 326;
					goto IL_0477;
				case 42:
					array5 = array2;
					num3 = 294;
					goto IL_0477;
				case 103:
					array2[14] = (byte)num5;
					num3 = 251;
					if (!sgyeknNJtFYo2R9Occ())
					{
						goto case 223;
					}
					goto IL_0477;
				case 223:
					IfI5Gsav6etG0uTLvO(memoryStream);
					num = 247;
					continue;
				case 303:
					array2[7] = 116;
					num = 38;
					continue;
				case 158:
					array2[11] = 223;
					num = 14;
					continue;
				case 49:
					array[14] = (byte)num7;
					num3 = 248;
					goto IL_0477;
				case 27:
					array[20] = 180;
					num3 = 83;
					goto IL_0477;
				case 80:
					num4 = 75 + 51;
					num3 = 90;
					if (false)
					{
						break;
					}
					goto IL_0477;
				case 64:
					binaryReader = new BinaryReader((Stream)soO5n8J9gGtwVGE1v1(nA1fgnubjGqwyq40jZ(typeof(aXtkqx0KSIocPot7nI).TypeHandle).Assembly, "45d6ll1WOHD6JIPeMZ.eWfX61HPdnflJNZLbZ"));
					num = 21;
					continue;
				case 149:
					num4 = 166 - 102;
					goto case 175;
				default:
					num6 = 175;
					goto IL_0473;
				case 0:
					num2 = i5r8Z3FiaEaOKjyGmQ(LOIKseffLQ, P_0);
					num3 = 334;
					if (true)
					{
						goto IL_0477;
					}
					goto case 79;
				case 79:
					array2[15] = 100;
					num6 = 250;
					goto IL_0473;
				case 251:
					array2[15] = 159;
					num3 = 10;
					goto IL_0477;
				case 148:
					array2[5] = (byte)num5;
					num3 = 313;
					if (fGbhacYLbmx2eV9ptL())
					{
						goto case 145;
					}
					goto IL_0477;
				case 184:
					array2[10] = (byte)num5;
					num6 = 81;
					goto IL_0473;
				case 319:
					array2[2] = 84;
					num3 = 329;
					if (0 == 0)
					{
						goto IL_0477;
					}
					goto case 210;
				case 210:
					array[24] = (byte)num7;
					num3 = 229;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 332;
				case 332:
					array2[12] = (byte)num5;
					num3 = 45;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 112;
				case 112:
					array2[9] = 159;
					num = 226;
					continue;
				case 164:
					array[12] = (byte)num7;
					num = 147;
					continue;
				case 118:
					array[25] = (byte)num7;
					num = 101;
					continue;
				case 232:
					num7 = 161 - 53;
					num6 = 141;
					goto IL_0473;
				case 108:
					array5[13] = array3[6];
					num3 = 330;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 270;
				case 270:
					num4 = 165 - 85;
					num = 53;
					continue;
				case 169:
					num4 = 50 + 14;
					num6 = 327;
					goto IL_0473;
				case 255:
					array[5] = (byte)num7;
					num6 = 142;
					goto IL_0473;
				case 21:
					rKKXmTeX0tRvV5SXWc(L7AME18TG0SR0UvrUe(binaryReader), 0L);
					num3 = 310;
					goto IL_0477;
				case 54:
					num5 = 20 + 68;
					num3 = 121;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 178;
				case 209:
					array2[10] = (byte)num5;
					num6 = 158;
					goto IL_0473;
				case 76:
					num5 = 161 + 8;
					num6 = 151;
					goto IL_0473;
				case 236:
					num4 = 5 + 124;
					num6 = 115;
					goto IL_0473;
				case 296:
					num4 = 185 + 57;
					num3 = 217;
					if (sgyeknNJtFYo2R9Occ())
					{
						goto IL_0477;
					}
					goto case 263;
				case 26:
					num7 = 123 + 119;
					num3 = 75;
					goto IL_0477;
				case 166:
					num5 = 209 - 69;
					num6 = 184;
					goto IL_0473;
				case 291:
					array2[13] = 128;
					num3 = 181;
					goto IL_0477;
				case 192:
					array[17] = (byte)num7;
					num = 22;
					continue;
				case 134:
					array[24] = 68;
					num6 = 261;
					goto IL_0473;
				case 300:
					cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
					num3 = 157;
					goto IL_0477;
				case 38:
					num5 = 227 - 75;
					num3 = 245;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 82;
				case 82:
					num7 = 25 + 102;
					num = 165;
					continue;
				case 177:
					array2[13] = 64;
					num3 = 51;
					goto IL_0477;
				case 267:
					num4 = 126 - 42;
					num6 = 178;
					goto IL_0473;
				case 68:
					array2[4] = 146;
					num3 = 221;
					goto IL_0477;
				case 172:
					array5[9] = array3[4];
					num = 114;
					continue;
				case 132:
					array[27] = 125;
					num = 2;
					continue;
				case 59:
					num7 = 65 + 93;
					num6 = 204;
					goto IL_0473;
				case 9:
					num5 = 58 + 7;
					num = 316;
					continue;
				case 292:
					array5[1] = array3[0];
					num3 = 143;
					goto IL_0477;
				case 160:
					array[23] = (byte)num7;
					num6 = 225;
					goto IL_0473;
				case 280:
					num5 = 29 + 108;
					num3 = 91;
					if (sgyeknNJtFYo2R9Occ())
					{
						goto IL_0477;
					}
					goto case 259;
				case 259:
					array2[14] = (byte)num5;
					goto case 67;
				case 157:
					iHHNCDwVjRsjlAuMkW(cryptoStream, array4, 0, array4.Length);
					num6 = 281;
					goto IL_0473;
				case 190:
					array[1] = 186;
					num3 = 154;
					if (0 == 0)
					{
						goto IL_0477;
					}
					goto case 52;
				case 52:
					array2[4] = (byte)num5;
					num6 = 68;
					goto IL_0473;
				case 131:
					array[8] = (byte)num7;
					num6 = 236;
					goto IL_0473;
				case 310:
					WlmevZKtvAapuHirkK(true);
					num = 284;
					continue;
				case 252:
					array[1] = 115;
					num3 = 190;
					if (fGbhacYLbmx2eV9ptL())
					{
						goto case 258;
					}
					goto IL_0477;
				case 261:
					num7 = 105 + 118;
					num3 = 210;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 326;
				case 278:
					num7 = 232 - 77;
					num6 = 212;
					goto IL_0473;
				case 28:
					array[5] = (byte)num7;
					num3 = 18;
					if (fGbhacYLbmx2eV9ptL())
					{
						goto case 126;
					}
					goto IL_0477;
				case 316:
					array2[9] = (byte)num5;
					num6 = 230;
					goto IL_0473;
				case 293:
					array[7] = (byte)num4;
					num6 = 156;
					goto IL_0473;
				case 37:
					array[28] = (byte)num4;
					num6 = 170;
					goto IL_0473;
				case 32:
					num5 = 5 + 12;
					num6 = 323;
					goto IL_0473;
				case 23:
					array[29] = 96;
					num3 = 155;
					if (0 == 0)
					{
						goto IL_0477;
					}
					goto case 110;
				case 110:
					num4 = 50 + 37;
					num6 = 37;
					goto IL_0473;
				case 197:
					array[29] = 49;
					num = 23;
					continue;
				case 250:
					array2[15] = 169;
					num6 = 42;
					goto IL_0473;
				case 326:
					num7 = 253 - 84;
					num = 201;
					continue;
				case 260:
					array[16] = 180;
					num3 = 43;
					if (sgyeknNJtFYo2R9Occ())
					{
						goto IL_0477;
					}
					goto case 41;
				case 165:
					array[23] = (byte)num7;
					num3 = 271;
					goto IL_0477;
				case 146:
					array[3] = (byte)num7;
					num = 309;
					continue;
				case 183:
					array2[4] = 232;
					num3 = 314;
					goto IL_0477;
				case 102:
					num4 = 120 + 112;
					num3 = 233;
					goto IL_0477;
				case 328:
					num4 = 79 - 53;
					num3 = 167;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 46;
				case 46:
					array[24] = 144;
					num6 = 134;
					goto IL_0473;
				case 20:
					array2[1] = 213;
					num3 = 111;
					goto IL_0477;
				case 25:
					array[20] = (byte)num4;
					num3 = 27;
					if (0 == 0)
					{
						goto IL_0477;
					}
					goto case 130;
				case 130:
					array[26] = (byte)num4;
					num6 = 203;
					goto IL_0473;
				case 17:
					array2[9] = 138;
					num = 205;
					continue;
				case 301:
					num7 = 51 + 9;
					num3 = 192;
					if (0 == 0)
					{
						goto IL_0477;
					}
					goto case 63;
				case 63:
					num7 = 43 + 114;
					num6 = 57;
					goto IL_0473;
				case 89:
					array2[8] = (byte)num5;
					num6 = 213;
					goto IL_0473;
				case 289:
					num4 = 133 - 13;
					num3 = 34;
					if (true)
					{
						goto IL_0477;
					}
					goto case 305;
				case 305:
					array[17] = (byte)num7;
					num6 = 185;
					goto IL_0473;
				case 288:
					num5 = 106 + 34;
					num6 = 259;
					goto IL_0473;
				case 1:
					array2 = new byte[16];
					num6 = 35;
					goto IL_0473;
				case 324:
					array[31] = 163;
					num3 = 16;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 77;
				case 299:
					array[14] = 117;
					num3 = 286;
					goto IL_0477;
				case 181:
					num5 = 212 - 70;
					num3 = 162;
					goto IL_0477;
				case 117:
					num5 = 228 - 76;
					num6 = 202;
					goto IL_0473;
				case 170:
					array[28] = 131;
					num3 = 243;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 176;
				case 176:
					num4 = 85 + 104;
					num6 = 293;
					goto IL_0473;
				case 104:
					array[20] = 50;
					num6 = 272;
					goto IL_0473;
				case 227:
					array[23] = (byte)num7;
					num3 = 80;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 274;
				case 274:
					array2[3] = 95;
					num3 = 109;
					if (true)
					{
						goto IL_0477;
					}
					goto case 307;
				case 307:
					num7 = 231 - 77;
					num6 = 58;
					goto IL_0473;
				case 155:
					array[29] = 36;
					num3 = 61;
					if (sgyeknNJtFYo2R9Occ())
					{
						goto IL_0477;
					}
					goto case 232;
				case 57:
					array[6] = (byte)num7;
					num6 = 232;
					goto IL_0473;
				case 81:
					num5 = 16 + 103;
					num6 = 333;
					goto IL_0473;
				case 58:
					array[5] = (byte)num7;
					num3 = 69;
					if (true)
					{
						goto IL_0477;
					}
					goto case 323;
				case 323:
					array2[5] = (byte)num5;
					num = 211;
					continue;
				case 245:
					array2[8] = (byte)num5;
					num3 = 117;
					if (0 == 0)
					{
						goto IL_0477;
					}
					goto case 65;
				case 65:
					array2[11] = 60;
					num3 = 60;
					goto IL_0477;
				case 73:
					array[25] = 144;
					num3 = 253;
					if (true)
					{
						goto IL_0477;
					}
					goto case 205;
				case 205:
					num5 = 228 - 76;
					num3 = 195;
					if (0 == 0)
					{
						goto IL_0477;
					}
					goto case 147;
				case 147:
					array[12] = 111;
					num = 62;
					continue;
				case 218:
					array[16] = 13;
					num6 = 260;
					goto IL_0473;
				case 311:
					array[14] = 130;
					num3 = 144;
					if (sgyeknNJtFYo2R9Occ())
					{
						goto IL_0477;
					}
					goto case 295;
				case 2:
					num4 = 243 - 81;
					num3 = 66;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 239;
				case 239:
					array[10] = (byte)num4;
					num = 152;
					continue;
				case 272:
					num4 = 136 - 45;
					num3 = 25;
					if (0 == 0)
					{
						goto IL_0477;
					}
					goto case 121;
				case 121:
					array2[1] = (byte)num5;
					num3 = 20;
					goto IL_0477;
				case 182:
					array2[3] = 127;
					num3 = 274;
					if (sgyeknNJtFYo2R9Occ())
					{
						goto IL_0477;
					}
					goto case 186;
				case 186:
					num4 = 151 - 50;
					num3 = 107;
					goto IL_0477;
				case 173:
					array[11] = (byte)num4;
					num = 26;
					continue;
				case 304:
					num7 = 2 + 36;
					num3 = 136;
					goto IL_0477;
				case 193:
					num7 = 38 + 23;
					num3 = 308;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 169;
				case 264:
					array[29] = 154;
					num3 = 197;
					if (true)
					{
						goto IL_0477;
					}
					goto case 56;
				case 56:
					array[6] = 109;
					num3 = 63;
					goto IL_0477;
				case 329:
					array2[2] = 125;
					num3 = 241;
					if (true)
					{
						goto IL_0477;
					}
					goto case 318;
				case 318:
					array[19] = 55;
					num = 104;
					continue;
				case 40:
					array2[7] = 91;
					num3 = 303;
					goto IL_0477;
				case 283:
					num4 = 45 + 89;
					num3 = 238;
					if (0 == 0)
					{
						goto IL_0477;
					}
					goto case 71;
				case 71:
					array6 = array;
					num3 = 1;
					if (true)
					{
						goto IL_0477;
					}
					goto case 317;
				case 317:
					array[21] = (byte)num7;
					num = 59;
					continue;
				case 137:
					array2[13] = (byte)num5;
					num3 = 288;
					if (0 == 0)
					{
						goto IL_0477;
					}
					goto case 199;
				case 199:
					array[7] = (byte)num7;
					num3 = 312;
					if (true)
					{
						goto IL_0477;
					}
					goto case 217;
				case 217:
					array[27] = (byte)num4;
					num6 = 110;
					goto IL_0473;
				case 198:
					transform = (ICryptoTransform)OsElFOfg8SKpnvRVqt(rijndaelManaged, array6, array5);
					num = 123;
					continue;
				case 10:
					array2[15] = 68;
					num = 237;
					continue;
				case 60:
					array2[12] = 112;
					num3 = 276;
					if (0 == 0)
					{
						goto IL_0477;
					}
					goto case 204;
				case 204:
					array[21] = (byte)num7;
					num3 = 267;
					if (0 == 0)
					{
						goto IL_0477;
					}
					goto case 74;
				case 74:
					if (LOIKseffLQ.Length == 0)
					{
						num = 64;
						continue;
					}
					goto case 0;
				case 87:
					num4 = 98 + 12;
					num3 = 138;
					if (true)
					{
						goto IL_0477;
					}
					goto case 98;
				case 98:
					array2[0] = (byte)num5;
					num3 = 124;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 277;
				case 114:
					array5[11] = array3[5];
					num3 = 108;
					goto IL_0477;
				case 279:
					array[28] = (byte)num4;
					num3 = 295;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 66;
				case 66:
					array[27] = (byte)num4;
					num6 = 244;
					goto IL_0473;
				case 159:
					array[3] = (byte)num7;
					num6 = 4;
					goto IL_0473;
				case 109:
					array2[3] = 161;
					num = 188;
					continue;
				case 15:
					array[22] = 120;
					num6 = 256;
					goto IL_0473;
				case 91:
					array2[6] = (byte)num5;
					num3 = 120;
					if (true)
					{
						goto IL_0477;
					}
					goto case 230;
				case 230:
					array2[9] = 29;
					num3 = 166;
					goto IL_0477;
				case 219:
					num7 = 67 + 24;
					num3 = 331;
					goto IL_0477;
				case 97:
					num7 = 18 + 119;
					num3 = 146;
					goto IL_0477;
				case 12:
				case 50:
					num4 = 35 + 35;
					num = 7;
					continue;
				case 140:
					array[26] = 25;
					num = 297;
					continue;
				case 51:
					array2[13] = 150;
					num = 325;
					continue;
				case 107:
					array[13] = (byte)num4;
					num = 163;
					continue;
				case 276:
					num5 = 244 - 81;
					num3 = 332;
					if (true)
					{
						goto IL_0477;
					}
					goto case 247;
				case 247:
					IfI5Gsav6etG0uTLvO(cryptoStream);
					num3 = 113;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 20;
				case 268:
					num5 = 60 - 15;
					num3 = 103;
					goto IL_0477;
				case 214:
					num5 = 19 + 92;
					num6 = 89;
					goto IL_0473;
				case 22:
					num4 = 76 + 42;
					num = 290;
					continue;
				case 129:
					array[26] = (byte)num4;
					num6 = 140;
					goto IL_0473;
				case 249:
					array[10] = 157;
					num6 = 88;
					goto IL_0473;
				case 143:
					array5[3] = array3[1];
					num3 = 55;
					goto IL_0477;
				case 333:
					array2[10] = (byte)num5;
					num = 200;
					continue;
				case 273:
					array[13] = (byte)num4;
					num6 = 186;
					goto IL_0473;
				case 127:
					num7 = 68 + 94;
					num6 = 28;
					goto IL_0473;
				case 138:
					array[19] = (byte)num4;
					num3 = 100;
					goto IL_0477;
				case 144:
					array[14] = 144;
					num3 = 224;
					if (true)
					{
						goto IL_0477;
					}
					goto case 75;
				case 75:
					array[11] = (byte)num7;
					num6 = 304;
					goto IL_0473;
				case 8:
					num5 = 249 - 83;
					num3 = 52;
					if (true)
					{
						goto IL_0477;
					}
					goto case 34;
				case 34:
					array[21] = (byte)num4;
					num3 = 30;
					if (true)
					{
						goto IL_0477;
					}
					goto case 321;
				case 321:
					array[29] = (byte)num4;
					num = 264;
					continue;
				case 202:
					array2[8] = (byte)num5;
					num3 = 133;
					if (sgyeknNJtFYo2R9Occ())
					{
						goto IL_0477;
					}
					goto case 282;
				case 282:
					array[8] = 132;
					num = 306;
					continue;
				case 277:
					array2[12] = 231;
					num3 = 291;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 241;
				case 241:
					num5 = 76 - 31;
					num = 206;
					continue;
				case 309:
					num7 = 54 + 43;
					num3 = 159;
					if (true)
					{
						goto IL_0477;
					}
					goto case 313;
				case 313:
					array2[6] = 100;
					num = 194;
					continue;
				case 115:
					array[8] = (byte)num4;
					num = 72;
					continue;
				case 78:
					num4 = 131 - 43;
					num6 = 85;
					goto IL_0473;
				case 187:
					num4 = 235 - 78;
					num3 = 321;
					goto IL_0477;
				case 325:
					array2[13] = 173;
					num = 93;
					continue;
				case 6:
					array[26] = 106;
					num = 145;
					continue;
				case 45:
					num5 = 136 - 45;
					num3 = 3;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 8;
				case 269:
					array[21] = (byte)num7;
					num3 = 289;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 17;
				case 253:
					num7 = 158 - 52;
					num6 = 118;
					goto IL_0473;
				case 35:
					array2[0] = 117;
					num3 = 207;
					if (sgyeknNJtFYo2R9Occ())
					{
						goto IL_0477;
					}
					goto case 61;
				case 61:
					array[30] = 196;
					num3 = 119;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 70;
				case 70:
					array2[15] = (byte)num5;
					num3 = 79;
					goto IL_0477;
				case 189:
					array[15] = (byte)num7;
					num = 218;
					continue;
				case 153:
					num7 = 111 + 96;
					num3 = 199;
					goto IL_0477;
				case 152:
					num4 = 57 + 30;
					num3 = 173;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 304;
				case 188:
					array2[3] = 25;
					num3 = 8;
					goto IL_0477;
				case 297:
					array[27] = 96;
					num3 = 132;
					if (sgyeknNJtFYo2R9Occ())
					{
						goto IL_0477;
					}
					goto case 112;
				case 33:
					if (array3 == null)
					{
						goto case 77;
					}
					num = 11;
					continue;
				case 287:
					array[2] = 227;
					num6 = 254;
					goto IL_0473;
				case 243:
					num4 = 131 - 43;
					num = 279;
					continue;
				case 47:
					array[2] = 110;
					num = 285;
					continue;
				case 119:
					num4 = 213 - 71;
					num6 = 242;
					goto IL_0473;
				case 244:
					num7 = 208 - 69;
					num6 = 5;
					goto IL_0473;
				case 55:
					array5[5] = array3[2];
					num3 = 94;
					goto IL_0477;
				case 233:
					array[9] = (byte)num4;
					num6 = 78;
					goto IL_0473;
				case 254:
					array[2] = 231;
					num3 = 47;
					goto IL_0477;
				case 7:
					array[1] = (byte)num4;
					num = 252;
					continue;
				case 213:
					array2[8] = 36;
					num3 = 112;
					goto IL_0477;
				case 24:
					array[4] = 158;
					num3 = 262;
					goto IL_0477;
				case 235:
					array[16] = (byte)num4;
					num6 = 13;
					goto IL_0473;
				case 178:
					array[21] = (byte)num4;
					num3 = 95;
					if (true)
					{
						goto IL_0477;
					}
					goto case 222;
				case 222:
					num4 = 182 - 95;
					num3 = 44;
					if (0 == 0)
					{
						goto IL_0477;
					}
					goto case 14;
				case 14:
					array2[11] = 84;
					num3 = 65;
					goto IL_0477;
				case 124:
					array2[0] = 86;
					num3 = 54;
					goto IL_0477;
				case 185:
					array[18] = 136;
					num = 116;
					continue;
				case 284:
					array4 = (byte[])T3WixUW2bqv72yJDdw(binaryReader, (int)zcxvvncbJfiXG1BlnW(L7AME18TG0SR0UvrUe(binaryReader)));
					num6 = 265;
					goto IL_0473;
				case 162:
					array2[13] = (byte)num5;
					num = 177;
					continue;
				case 206:
					array2[2] = (byte)num5;
					num3 = 182;
					goto IL_0477;
				case 16:
					array[31] = 112;
					num = 270;
					continue;
				case 67:
				case 298:
					array2[14] = 146;
					num3 = 268;
					if (sgyeknNJtFYo2R9Occ())
					{
						goto IL_0477;
					}
					goto case 208;
				case 208:
					num4 = 215 - 71;
					num6 = 125;
					goto IL_0473;
				case 262:
					array[4] = 133;
					num = 222;
					continue;
				case 229:
					array[25] = 156;
					num = 215;
					continue;
				case 88:
					num4 = 221 + 28;
					num3 = 239;
					goto IL_0477;
				case 238:
					array[0] = (byte)num4;
					num6 = 322;
					goto IL_0473;
				case 85:
					array[10] = (byte)num4;
					num3 = 257;
					goto IL_0477;
				case 122:
					num7 = 155 - 51;
					num3 = 164;
					if (0 == 0)
					{
						goto IL_0477;
					}
					goto case 215;
				case 215:
					num4 = 124 + 39;
					num3 = 139;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 101;
				case 101:
					num7 = 220 - 73;
					num = 48;
					continue;
				case 4:
					array[3] = 75;
					num3 = 24;
					if (0 == 0)
					{
						goto IL_0477;
					}
					goto case 86;
				case 86:
					array[16] = 219;
					num3 = 196;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 276;
				case 315:
					array[9] = 138;
					num3 = 320;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 263;
				case 263:
					array[30] = (byte)num7;
					num3 = 228;
					goto IL_0477;
				case 136:
					array[11] = (byte)num7;
					num = 39;
					continue;
				case 116:
					num7 = 70 + 58;
					num6 = 220;
					goto IL_0473;
				case 139:
					array[25] = (byte)num4;
					num3 = 73;
					goto IL_0477;
				case 5:
					array[27] = (byte)num7;
					num6 = 296;
					goto IL_0473;
				case 207:
					num5 = 187 - 62;
					num = 98;
					continue;
				case 211:
					num5 = 105 + 80;
					num = 148;
					continue;
				case 105:
					LOIKseffLQ = (byte[])FXqr3mBQqjaTyWNFT2(memoryStream);
					num3 = 223;
					if (0 == 0)
					{
						goto IL_0477;
					}
					goto case 306;
				case 306:
					num4 = 108 - 24;
					num6 = 168;
					goto IL_0473;
				case 39:
					array[11] = 160;
					num6 = 122;
					goto IL_0473;
				case 141:
					array[7] = (byte)num7;
					num6 = 176;
					goto IL_0473;
				case 248:
					array[14] = 56;
					num = 311;
					continue;
				case 221:
					array2[4] = 62;
					num = 183;
					continue;
				case 113:
					abFLYxvKI9GguX8Non(binaryReader);
					num3 = 0;
					goto IL_0477;
				case 44:
					array[4] = (byte)num4;
					num3 = 307;
					if (true)
					{
						goto IL_0477;
					}
					goto case 281;
				case 281:
					EPE4JN4edeVjGogWO7(cryptoStream);
					num6 = 105;
					goto IL_0473;
				case 195:
					array2[9] = (byte)num5;
					num = 9;
					continue;
				case 191:
					num7 = 250 - 83;
					num3 = 160;
					goto IL_0477;
				case 322:
					array[0] = 193;
					fGbhacYLbmx2eV9ptL();
					if (!sgyeknNJtFYo2R9Occ())
					{
						num6 = 67;
						goto IL_0473;
					}
					num3 = 50;
					if (true)
					{
						goto IL_0477;
					}
					goto case 196;
				case 196:
					array[17] = 142;
					num3 = 19;
					if (!sgyeknNJtFYo2R9Occ())
					{
						goto case 224;
					}
					goto IL_0477;
				case 93:
					num5 = 139 + 2;
					num6 = 137;
					goto IL_0473;
				case 106:
					ISQviaTB6fguvnUH7m(rijndaelManaged, CipherMode.CBC);
					num6 = 198;
					goto IL_0473;
				case 231:
					array[10] = (byte)num4;
					num3 = 249;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 187;
				case 18:
					num4 = 45 + 63;
					num = 128;
					continue;
				case 96:
					array[24] = 102;
					num6 = 46;
					goto IL_0473;
				case 48:
					array[25] = (byte)num7;
					num3 = 302;
					if (sgyeknNJtFYo2R9Occ())
					{
						goto IL_0477;
					}
					goto case 9;
				case 275:
					array[0] = 155;
					num3 = 283;
					goto IL_0477;
				case 308:
					array[9] = (byte)num7;
					num3 = 102;
					if (true)
					{
						goto IL_0477;
					}
					goto case 128;
				case 128:
					array[5] = (byte)num4;
					num3 = 179;
					goto IL_0477;
				case 120:
					array2[7] = 165;
					num6 = 40;
					goto IL_0473;
				case 11:
					if (array3.Length <= 0)
					{
						goto case 77;
					}
					num = 292;
					continue;
				case 234:
					array[9] = (byte)num4;
					num = 193;
					continue;
				case 19:
					array[17] = 161;
					num = 301;
					continue;
				case 179:
					num7 = 130 + 70;
					num = 255;
					continue;
				case 99:
					num5 = 59 + 71;
					num3 = 70;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 299;
				case 161:
					array[6] = (byte)num7;
					num = 56;
					continue;
				case 13:
					array[16] = 225;
					num = 92;
					continue;
				case 331:
					array[15] = (byte)num7;
					num6 = 174;
					goto IL_0473;
				case 294:
					array3 = (byte[])NKMMSGp76dGIcElnMt(MQdh1pibN0m5Q2AKkt(nA1fgnubjGqwyq40jZ(typeof(aXtkqx0KSIocPot7nI).TypeHandle).Assembly));
					num = 33;
					continue;
				case 31:
					array[31] = 145;
					num3 = 324;
					if (true)
					{
						goto IL_0477;
					}
					goto case 90;
				case 90:
					array[23] = (byte)num4;
					num3 = 149;
					goto IL_0477;
				case 69:
					array[5] = 142;
					num3 = 127;
					goto IL_0477;
				case 100:
					array[19] = 105;
					num6 = 318;
					goto IL_0473;
				case 133:
					array2[8] = 166;
					num = 214;
					continue;
				case 246:
					array[22] = (byte)num4;
					num3 = 191;
					goto IL_0477;
				case 257:
					num4 = 83 + 112;
					num = 231;
					continue;
				case 295:
					array[28] = 118;
					num = 187;
					continue;
				case 3:
					array2[12] = (byte)num5;
					num3 = 277;
					if (sgyeknNJtFYo2R9Occ())
					{
						goto IL_0477;
					}
					goto case 295;
				case 30:
					array[22] = 129;
					num6 = 15;
					goto IL_0473;
				case 312:
					num7 = 60 + 124;
					num3 = 131;
					goto IL_0477;
				case 95:
					num7 = 117 + 56;
					num3 = 269;
					if (sgyeknNJtFYo2R9Occ())
					{
						goto IL_0477;
					}
					goto case 206;
				case 156:
					array[7] = 158;
					num6 = 169;
					goto IL_0473;
				case 226:
					array2[9] = 166;
					num = 17;
					continue;
				case 92:
					num7 = 152 - 50;
					num6 = 41;
					goto IL_0473;
				case 256:
					num4 = 189 + 10;
					num3 = 246;
					if (0 == 0)
					{
						goto IL_0477;
					}
					goto case 216;
				case 216:
					array[17] = 196;
					num6 = 36;
					goto IL_0473;
				case 72:
					array[8] = 164;
					num6 = 282;
					goto IL_0473;
				case 240:
					array[23] = (byte)num4;
					num6 = 82;
					goto IL_0473;
				case 320:
					num4 = 161 - 53;
					num3 = 234;
					if (sgyeknNJtFYo2R9Occ())
					{
						goto IL_0477;
					}
					goto case 237;
				case 237:
					array2[15] = 139;
					num6 = 99;
					goto IL_0473;
				case 286:
					array[15] = 106;
					num3 = 219;
					goto IL_0477;
				case 200:
					num5 = 122 - 69;
					num6 = 209;
					goto IL_0473;
				case 194:
					array2[6] = 153;
					num6 = 280;
					goto IL_0473;
				case 203:
					num4 = 53 + 82;
					num = 129;
					continue;
				case 53:
					array[31] = (byte)num4;
					num6 = 71;
					goto IL_0473;
				case 111:
					array2[1] = 119;
					num = 76;
					continue;
				case 83:
					num7 = 69 + 36;
					num3 = 317;
					goto IL_0477;
				case 180:
					array[7] = 173;
					num3 = 153;
					if (!fGbhacYLbmx2eV9ptL())
					{
						goto IL_0477;
					}
					goto case 271;
				case 271:
					num7 = 45 + 98;
					num3 = 227;
					if (0 == 0)
					{
						goto IL_0477;
					}
					goto case 174;
				case 174:
					num7 = 106 + 37;
					num6 = 189;
					goto IL_0473;
				case 29:
					array[9] = 104;
					num6 = 315;
					goto IL_0473;
				case 151:
					array2[1] = (byte)num5;
					num = 319;
					continue;
				case 225:
					num4 = 210 - 70;
					num = 240;
					continue;
				case 175:
					array[23] = (byte)num4;
					num3 = 96;
					if (true)
					{
						goto IL_0477;
					}
					goto case 220;
				case 220:
					array[18] = (byte)num7;
					num3 = 171;
					if (0 == 0)
					{
						goto IL_0477;
					}
					goto case 94;
				case 94:
					array5[7] = array3[3];
					num3 = 172;
					if (true)
					{
						goto IL_0477;
					}
					goto case 41;
				case 41:
					array[16] = (byte)num7;
					num3 = 86;
					if (sgyeknNJtFYo2R9Occ())
					{
						goto IL_0477;
					}
					goto case 23;
				case 314:
					array2[5] = 163;
					num3 = 32;
					goto IL_0477;
				case 334:
					try
					{
						return (string)p3S4eGlo7Woo2NEI6F(kuHehJCOjvs42DHWGN(), LOIKseffLQ, P_0 + 4, num2);
					}
					catch
					{
					}
					return "";
				case 123:
					break;
				case 77:
					{
						rijndaelManaged = new RijndaelManaged();
						num3 = 106;
						goto IL_0477;
					}
					IL_0477:
					num = num3;
					continue;
					IL_0473:
					num3 = num6;
					goto IL_0477;
				}
				memoryStream = new MemoryStream();
				num = 300;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[aAEWjktHACAco507wq(typeof(aXtkqx0KSIocPot7nI/aAEWjktHACAco507wq/fQ8LKyaPenpAaWUWFL<object>[]))]
		internal static string vfiKtEtxHc(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void tUFKaJZnA1(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int BjTKGGByOS(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr MpwKjyc1iw(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void EljKRNH6HC()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void tf7Kdd9kni()
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
		internal static object LLKK3i5jM3(object P_0)
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
		public static extern IntPtr YhbKMH2rjq(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr VdOKU3SHov(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int ehvKi4MSvo(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int nCaKm7B8d0(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int m1kKupadvQ(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr saQK4pOQbB(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int RYDKfVnk6J(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[aAEWjktHACAco507wq(typeof(aXtkqx0KSIocPot7nI/aAEWjktHACAco507wq/fQ8LKyaPenpAaWUWFL<object>[]))]
		private static byte[] UETKS5djnA(string P_0)
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
		[aAEWjktHACAco507wq(typeof(aXtkqx0KSIocPot7nI/aAEWjktHACAco507wq/fQ8LKyaPenpAaWUWFL<object>[]))]
		private static byte[] lwJK94UXlW(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				78, 97, 253, 4, 132, 53, 65, 85, 44, 110,
				217, 48, 57, 108, 191, 85, 152, 222, 40, 230,
				131, 115, 40, 106, 150, 67, 61, 162, 24, 158,
				73, 63
			};
			rijndael.IV = new byte[16]
			{
				162, 190, 237, 103, 229, 4, 103, 167, 184, 83,
				124, 87, 182, 176, 37, 26
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] inaK6XleXh()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] xSIKYMZD2Z()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] tmGKrd1qqd()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] mgEKcCNw6a()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] fTlKHvBRa0()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] rRqKWo5FKw()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] DaKKlfQkIK()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] A1XKJ3xrMS()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] voTKQSJ9VY()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] xTvKkpO85k()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public aXtkqx0KSIocPot7nI()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type nA1fgnubjGqwyq40jZ(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object soO5n8J9gGtwVGE1v1(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object L7AME18TG0SR0UvrUe(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void rKKXmTeX0tRvV5SXWc(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void WlmevZKtvAapuHirkK(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long zcxvvncbJfiXG1BlnW(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object T3WixUW2bqv72yJDdw(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object MQdh1pibN0m5Q2AKkt(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object NKMMSGp76dGIcElnMt(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void ISQviaTB6fguvnUH7m(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object OsElFOfg8SKpnvRVqt(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void iHHNCDwVjRsjlAuMkW(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void EPE4JN4edeVjGogWO7(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object FXqr3mBQqjaTyWNFT2(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void IfI5Gsav6etG0uTLvO(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void abFLYxvKI9GguX8Non(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int i5r8Z3FiaEaOKjyGmQ(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object kuHehJCOjvs42DHWGN()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object p3S4eGlo7Woo2NEI6F(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool sgyeknNJtFYo2R9Occ()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool fGbhacYLbmx2eV9ptL()
		{
			return false;
		}
	}
}
namespace aY81o5UFe9Bmqhhh9H
{
	internal class RC5jUHMDkrkP9QtAnE
	{
		private static bool uiP5DgxmRj;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void ggyda19zX8XvI()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public RC5jUHMDkrkP9QtAnE()
		{
		}
	}
}
