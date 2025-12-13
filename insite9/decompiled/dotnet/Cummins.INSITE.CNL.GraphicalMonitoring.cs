using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Printing;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.AccessControl;
using System.Security.Cryptography;
using System.Security.Principal;
using System.Text;
using System.Threading;
using System.Timers;
using System.Windows.Forms;
using AqLHMMamOWxUktS9Ta;
using C1.Win.C1FlexGrid;
using C1.Win.C1FlexGrid.Util.BaseControls;
using C2iZ1GhDJdOoXi2YMd;
using CILCompressionUtilitiesLib;
using COLLECTIONLib;
using Cummins.INSITE.CNL.Common;
using Cummins.INSITE.CNL.DMLLogFileConverter;
using Cummins.INSITE.CNL.Errors;
using Cummins.INSITE.CNL.Events;
using Cummins.INSITE.CNL.Events.Proxies;
using Cummins.INSITE.CNL.Factory;
using Cummins.INSITE.CNL.Help;
using Cummins.INSITE.CNL.Localization;
using Cummins.INSITE.CNL.Monitors;
using DataMonitorLoggerAPILib;
using ECMSERVICESAPILib;
using GJi4bIVZKYcPuwrRga;
using Gh2OwS8aCsjfBiV4u9;
using HPU5lGP7EtdR7quTaU1;
using HmIhwNLoVkWZe5vvEA;
using Hu7X4gEroD3jDTyOIL;
using Iocomp.Classes;
using Iocomp.Instrumentation.Plotting;
using Iocomp.Types;
using MRtHuibDQYy79wcljF;
using Microsoft.Win32;
using N92EARiGPWWybrZNel;
using NRo07PCcI8Ip92IPGD;
using Ob4WOlIBx5F1N21gPc;
using QIadPxnoakDxeCQSfq;
using R6d0DRjWMq48MPPfYU;
using SGAXiskxPaDHEOHCNF;
using ToolSecurityServicesAPILib;
using VersionServiceLib;
using YcsyoeJPV0DW6gWAfX;
using dmuvY6MFkuQ2wt5kOy;
using fVqwGUSBnT2UKedpWV;
using i2PRXtqo4Z5bQ3WRIJ;
using jxemMG6xsMfsxpqCJc;
using nMh7lew5PoYBfLBVLL;
using nVLZejXdyZSvvx2mMM;
using ng8J85vBrHbAuEp2Ea;
using o4psuUQwqEwg9nhGLU;
using ovJtGm74Rb6ljXLCPQ;
using qPYuBcDa9IXlTwe33U;
using wi4XrPFQChoQqep7xu;
using x7Xx5jmRQbBVnWxB3N;

[assembly: CLSCompliant(true)]
[assembly: ComVisible(true)]
[assembly: AssemblyTrademark("")]
[assembly: NeutralResourcesLanguage("EN", UltimateResourceFallbackLocation.MainAssembly)]
[assembly: Guid("07764b29-637d-4f20-b574-6cfab6912fb7")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyTitle("GraphicalMonitoring")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyProduct("GraphicalMonitoring")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace xruSh2sFBACMB1RA1V
{
	internal static class n8Agfw1jhJR4kv1kaX
	{
	}
}
namespace Cummins.INSITE.CNL.GraphicalMonitoring
{
	[Guid("6F34E155-A209-4562-9DB4-F590D65808F5")]
	[ComVisible(true)]
	public interface IGraphicalMonitor
	{
		bool GraphDisplayed { get; }

		void Initialize(object kernel, object shell, object availableGroups);

		void DisplayGraph();

		void SetInitialSelection(object parameters);

		void CloseGraph();
	}
}
namespace ovJtGm74Rb6ljXLCPQ
{
	internal static class ewqjA30Ig7KglKlcHq
	{
		private const string XiVb4u9Yq = "15";

		private static object NdxUqVZK2;

		private static IECMServices kuuDCkmXA;

		private static IDataService IAXKisxPa;

		private static IModules BHEVOHCNF;

		private static IEnumerationReader q104BcSEF;

		private static IParameterDefinitions kfVnXwir4;

		private static IUnitDefinitions h0meuvY6F;

		private static ICICompression nuQF2wt5k;

		private static string ryYpiYLuk;

		private static Dictionary<int, int> eVhvDbAf3;

		private static Dictionary<int, int> DhsGxxemM;

		private static bool IxsLMfsxp;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static void ku8PGVh7n(object P_0)
		{
			NdxUqVZK2 = P_0;
			kuuDCkmXA = (IECMServices)P_0;
			IConnection connection = kuuDCkmXA.Connections.get_Item((object)kuuDCkmXA.ActiveConnectionID);
			IAXKisxPa = kuuDCkmXA.DataServices.Add(connection.ID);
			BHEVOHCNF = IAXKisxPa.Connection.System.Modules;
			q104BcSEF = kuuDCkmXA.EnumerationReader;
			kfVnXwir4 = kuuDCkmXA.ParameterDefinitions;
			h0meuvY6F = kuuDCkmXA.UnitDefinitions;
			eVhvDbAf3.Clear();
			DhsGxxemM.Clear();
			IxsLMfsxp = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public static object O0yhiaph2()
		{
			return kfVnXwir4;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static void mQ21ORqMv()
		{
			IxsLMfsxp = false;
			kuuDCkmXA.DataServices.Remove(IAXKisxPa.ID);
			IAXKisxPa = null;
			BHEVOHCNF = null;
			q104BcSEF = null;
			kfVnXwir4 = null;
			h0meuvY6F = null;
			kuuDCkmXA = null;
			eVhvDbAf3.Clear();
			DhsGxxemM.Clear();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static bool zk8sAgfwj(string P_0)
		{
			if (P_0 == null)
			{
				return false;
			}
			if (P_0.Length <= 0)
			{
				return false;
			}
			string[] separator = new string[1] { MnxsD0lrg8kZaUPt2I.OPAImF4404(0) };
			string[] array = P_0.Split(separator, StringSplitOptions.RemoveEmptyEntries);
			if (array.Length == 3)
			{
				return true;
			}
			return false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static void yJR04kv1k(string P_0, out int P_1, out int P_2, out long P_3)
		{
			string[] separator = new string[1] { MnxsD0lrg8kZaUPt2I.OPAImF4404(6) };
			string[] array = P_0.Split(separator, StringSplitOptions.RemoveEmptyEntries);
			P_1 = int.Parse(array[0]);
			P_2 = int.Parse(array[1]);
			P_3 = long.Parse(array[2]);
			if (!DhsGxxemM.ContainsKey(P_1))
			{
				DhsGxxemM.Add(P_1, P_2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static lHyiuRpvRLKBqfyHe9 sXN7ruSh2(string P_0)
		{
			rKONSNssT();
			int num = -1;
			int moduleType = -1;
			long s7drXicJ9m = -1L;
			yJR04kv1k(P_0, out num, out moduleType, out s7drXicJ9m);
			lHyiuRpvRLKBqfyHe9 result = new lHyiuRpvRLKBqfyHe9
			{
				aaYrcWlA7H = P_0,
				s5rro9rTp8 = num,
				VaDrxUe24c = S1VI7wqjA(num),
				s7drXicJ9m = s7drXicJ9m
			};
			IParameterDefinition parameterDefinition = kfVnXwir4.GetParameterDefinition(s7drXicJ9m.ToString(), moduleType);
			result.A46rwSBvbY = parameterDefinition.Name;
			result.zK4rgN7EmU = h0meuvY6F.GetUnitDefinition(parameterDefinition.unitId).ShortName;
			result.V0vr8F8xS1 = int.Parse(parameterDefinition.enumerationId);
			result.yYErdkWprd = "";
			result.F3prkKJTTG = true;
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static lHyiuRpvRLKBqfyHe9 FBArCMB1R(IDMLParameter P_0)
		{
			rKONSNssT();
			int num = -1;
			int num2 = -1;
			long s7drXicJ9m = -1L;
			yJR04kv1k(P_0.Cookie, out num, out num2, out s7drXicJ9m);
			lHyiuRpvRLKBqfyHe9 result = new lHyiuRpvRLKBqfyHe9
			{
				aaYrcWlA7H = P_0.Cookie,
				s5rro9rTp8 = num,
				VaDrxUe24c = S1VI7wqjA(num),
				s7drXicJ9m = s7drXicJ9m,
				A46rwSBvbY = P_0.ParameterName,
				zK4rgN7EmU = P_0.ParameterUnit
			};
			if (int.TryParse(P_0.ParameterEnumId, out var result2))
			{
				result.V0vr8F8xS1 = result2;
			}
			else
			{
				result.V0vr8F8xS1 = 0;
			}
			result.yYErdkWprd = string.Empty;
			result.F3prkKJTTG = true;
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static int S1VI7wqjA(int P_0)
		{
			rKONSNssT();
			int num = -1;
			if (eVhvDbAf3.ContainsKey(P_0))
			{
				num = eVhvDbAf3[P_0];
			}
			else
			{
				num = int.Parse(IAXKisxPa.CurrentModuleID);
				try
				{
					for (int i = 1; i <= BHEVOHCNF.Count; i++)
					{
						IAXKisxPa.CurrentModuleID = BHEVOHCNF.get_Item((object)i).ID;
						IParameter parameter = (IParameter)IAXKisxPa.Read(MnxsD0lrg8kZaUPt2I.OPAImF4404(12), ReadTypesEnum.RT_Parameter);
						int num2 = int.Parse(parameter.RawValue.ToString());
						if (num2 == P_0)
						{
							num = int.Parse(BHEVOHCNF.get_Item((object)i).ID);
							break;
						}
					}
					eVhvDbAf3.Add(P_0, num);
				}
				catch (Exception)
				{
				}
			}
			return num;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static int oIgc7KglK(int P_0)
		{
			rKONSNssT();
			int num = -1;
			Dictionary<int, int>.Enumerator enumerator = eVhvDbAf3.GetEnumerator();
			while (enumerator.MoveNext())
			{
				if (enumerator.Current.Value == P_0)
				{
					num = enumerator.Current.Key;
					break;
				}
			}
			if (num == -1)
			{
				IAXKisxPa.CurrentModuleID = BHEVOHCNF.get_Item((object)P_0).ID;
				IParameter parameter = (IParameter)IAXKisxPa.Read(MnxsD0lrg8kZaUPt2I.OPAImF4404(20), ReadTypesEnum.RT_Parameter);
				num = int.Parse(parameter.RawValue.ToString());
			}
			return num;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string WcHXqkvJt(int P_0, long P_1)
		{
			rKONSNssT();
			string text = oIgc7KglK(P_0).ToString();
			return text + MnxsD0lrg8kZaUPt2I.OPAImF4404(28) + BHEVOHCNF.get_Item((object)(P_0 + 1)).ModuleType + MnxsD0lrg8kZaUPt2I.OPAImF4404(34) + P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string Jm4xRb6lj(lHyiuRpvRLKBqfyHe9 P_0)
		{
			if (BHEVOHCNF.Count > 1 && !P_0.A46rwSBvbY.Contains(MnxsD0lrg8kZaUPt2I.OPAImF4404(40)))
			{
				return P_0.A46rwSBvbY + MnxsD0lrg8kZaUPt2I.OPAImF4404(46) + P_0.VaDrxUe24c + MnxsD0lrg8kZaUPt2I.OPAImF4404(52) + P_0.aaYrcWlA7H + MnxsD0lrg8kZaUPt2I.OPAImF4404(60);
			}
			return P_0.A46rwSBvbY + MnxsD0lrg8kZaUPt2I.OPAImF4404(66) + P_0.aaYrcWlA7H + MnxsD0lrg8kZaUPt2I.OPAImF4404(72);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string hLCoPQpTe(string P_0)
		{
			int num = P_0.IndexOf(MnxsD0lrg8kZaUPt2I.OPAImF4404(78));
			if (num < 0)
			{
				return P_0;
			}
			return P_0.Remove(num);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string h8Iwfapx2()
		{
			return MnxsD0lrg8kZaUPt2I.OPAImF4404(84) + DateTime.Now.ToString(MnxsD0lrg8kZaUPt2I.OPAImF4404(100));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string F2XgE6dCb()
		{
			string result = Environment.GetFolderPath(Environment.SpecialFolder.Personal);
			try
			{
				RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(MnxsD0lrg8kZaUPt2I.OPAImF4404(134));
				result = (string)registryKey.GetValue(MnxsD0lrg8kZaUPt2I.OPAImF4404(302));
			}
			catch
			{
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static V6PGe1R884NJ3GD2LA DWO8lBx5F(long P_0, out int P_1, out int P_2, out int P_3, out int P_4)
		{
			TimeSpan timeSpan = TimeSpan.FromMilliseconds(P_0);
			V6PGe1R884NJ3GD2LA result = V6PGe1R884NJ3GD2LA.MilliSecs;
			P_4 = (int)P_0 % 1000;
			P_3 = timeSpan.Seconds;
			P_2 = timeSpan.Minutes;
			P_1 = timeSpan.Hours;
			if (P_3 != 0)
			{
				result = V6PGe1R884NJ3GD2LA.Secs;
			}
			if (P_2 != 0)
			{
				result = V6PGe1R884NJ3GD2LA.Mins;
			}
			if (P_1 != 0)
			{
				result = V6PGe1R884NJ3GD2LA.Hour;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static long aN2d1gPcS(decimal P_0, V6PGe1R884NJ3GD2LA P_1)
		{
			long result = 0L;
			switch (P_1)
			{
			case V6PGe1R884NJ3GD2LA.Hour:
				result = (long)(P_0 * 60m * 60m * 1000m);
				break;
			case V6PGe1R884NJ3GD2LA.Mins:
				result = (long)(P_0 * 60m * 1000m);
				break;
			case V6PGe1R884NJ3GD2LA.Secs:
				result = (long)(P_0 * 1000m);
				break;
			case V6PGe1R884NJ3GD2LA.MilliSecs:
				result = (long)P_0;
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string a6UkkVfud(string P_0, int P_1)
		{
			string text = P_0;
			if (P_0.Length > P_1)
			{
				text = P_0.Substring(0, P_1);
				int num = P_1;
				int num2 = P_0.Length - P_1;
				do
				{
					if (num2 < P_1)
					{
						P_1 = num2;
					}
					text = text + Environment.NewLine + P_0.Substring(num, P_1);
					num2 -= P_1;
					num += P_1;
				}
				while (num2 > 0);
			}
			return MnxsD0lrg8kZaUPt2I.OPAImF4404(314) + text + MnxsD0lrg8kZaUPt2I.OPAImF4404(320);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string iA53A7qRi(string P_0)
		{
			return P_0.Replace(MnxsD0lrg8kZaUPt2I.OPAImF4404(326), Environment.NewLine);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static void nVLMZejdy(string[] P_0, string P_1)
		{
			if (nuQF2wt5k == null)
			{
				nuQF2wt5k = new CompressClass();
			}
			nuQF2wt5k.ArchiveName = P_1;
			nuQF2wt5k.FileCleanup = true;
			nuQF2wt5k.FileSpecs = P_0;
			nuQF2wt5k.Compress();
			SecurityIdentifier securityIdentifier = new SecurityIdentifier(WellKnownSidType.WorldSid, null);
			NTAccount nTAccount = securityIdentifier.Translate(typeof(NTAccount)) as NTAccount;
			string identity = nTAccount.ToString();
			try
			{
				FileSecurity accessControl = File.GetAccessControl(P_1);
				accessControl.AddAccessRule(new FileSystemAccessRule(identity, FileSystemRights.FullControl, AccessControlType.Allow));
				File.SetAccessControl(P_1, accessControl);
			}
			catch (UnauthorizedAccessException)
			{
			}
			catch (FileNotFoundException)
			{
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static Stream tSv9vx2mM(string P_0, string P_1)
		{
			if (nuQF2wt5k == null)
			{
				nuQF2wt5k = new CompressClass();
			}
			nuQF2wt5k.ArchiveName = P_0;
			nuQF2wt5k.FileCleanup = false;
			nuQF2wt5k.ExtractToMemory = true;
			int num = P_1.LastIndexOf(MnxsD0lrg8kZaUPt2I.OPAImF4404(334));
			if (num >= 0)
			{
				P_1 = P_1.Substring(num + 1, P_1.Length - num - 1);
			}
			Stream result = null;
			if (nuQF2wt5k.ExtractSingleFile(P_1) == ExtractResultEnum.ExtractSuccess)
			{
				byte[] buffer = (byte[])nuQF2wt5k.get_MemoryFile();
				result = new MemoryStream(buffer);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string pZR6Gdbub()
		{
			if (ryYpiYLuk.Length <= 0)
			{
				VersionProviderClass versionProviderClass = new VersionProviderClass();
				ryYpiYLuk = versionProviderClass.ToolVersionForDisplay;
			}
			return ryYpiYLuk;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static bool CrYO7YZL3(string P_0)
		{
			rKONSNssT();
			bool flag = false;
			lHyiuRpvRLKBqfyHe9 lHyiuRpvRLKBqfyHe = sXN7ruSh2(P_0);
			if (string.IsNullOrEmpty(lHyiuRpvRLKBqfyHe.zK4rgN7EmU) && lHyiuRpvRLKBqfyHe.V0vr8F8xS1 == 0)
			{
				return true;
			}
			return false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static bool PnhaJXRto(lHyiuRpvRLKBqfyHe9 P_0)
		{
			bool flag = false;
			if (string.IsNullOrEmpty(P_0.zK4rgN7EmU) && P_0.V0vr8F8xS1 == 0)
			{
				return true;
			}
			return false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string chkZZNIY6()
		{
			rKONSNssT();
			IToolLevelRegistration toolLevelRegistration = (IToolLevelRegistration)NdxUqVZK2;
			return toolLevelRegistration.GetCurrentToolLevel();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static Dictionary<string, string> U3DEkMh7l()
		{
			rKONSNssT();
			Dictionary<string, string> dictionary = new Dictionary<string, string>();
			dictionary.Add(MnxsD0lrg8kZaUPt2I.OPAImF4404(340), MnxsD0lrg8kZaUPt2I.OPAImF4404(366));
			dictionary.Add(MnxsD0lrg8kZaUPt2I.OPAImF4404(394), MnxsD0lrg8kZaUPt2I.OPAImF4404(420));
			dictionary.Add(MnxsD0lrg8kZaUPt2I.OPAImF4404(436), pZR6Gdbub());
			string text = chkZZNIY6();
			if (text == MnxsD0lrg8kZaUPt2I.OPAImF4404(462))
			{
				text = MnxsD0lrg8kZaUPt2I.OPAImF4404(472);
			}
			dictionary.Add(MnxsD0lrg8kZaUPt2I.OPAImF4404(500), text);
			IAXKisxPa.CurrentModuleID = kuuDCkmXA.Connections.get_Item((object)kuuDCkmXA.ActiveConnectionID).System.PrimaryModuleID;
			dictionary.Add(MnxsD0lrg8kZaUPt2I.OPAImF4404(522), YVLqLouqL(1009L));
			dictionary.Add(MnxsD0lrg8kZaUPt2I.OPAImF4404(550), YVLqLouqL(1011L));
			dictionary.Add(MnxsD0lrg8kZaUPt2I.OPAImF4404(588), F5PtoYBfL());
			dictionary.Add(MnxsD0lrg8kZaUPt2I.OPAImF4404(614), YVLqLouqL(3003L));
			dictionary.Add(MnxsD0lrg8kZaUPt2I.OPAImF4404(654), YVLqLouqL(4003L));
			return dictionary;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static string F5PtoYBfL()
		{
			rKONSNssT();
			string result = string.Empty;
			try
			{
				IDataService dataService = kuuDCkmXA.DataServices.Add(kuuDCkmXA.ActiveConnectionID);
				for (int i = 1; i <= BHEVOHCNF.Count; i++)
				{
					dataService.CurrentModuleID = BHEVOHCNF.get_Item((object)i).ID;
					IParameter parameter = (IParameter)dataService.Read(MnxsD0lrg8kZaUPt2I.OPAImF4404(684), ReadTypesEnum.RT_Parameter);
					result = parameter.DisplayValue;
				}
				kuuDCkmXA.DataServices.Remove(dataService.ID);
			}
			catch
			{
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static string YVLqLouqL(long P_0)
		{
			string result = string.Empty;
			try
			{
				IParameter parameter = (IParameter)IAXKisxPa.Read(P_0.ToString(), ReadTypesEnum.RT_Parameter);
				result = parameter.DisplayValue;
			}
			catch
			{
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void rKONSNssT()
		{
			if (!IxsLMfsxp)
			{
				throw new Exception(MnxsD0lrg8kZaUPt2I.OPAImF4404(696));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static ewqjA30Ig7KglKlcHq()
		{
			JmLDt5P0cahRebTiifG.LYav19NzXHLb9();
			NdxUqVZK2 = null;
			kuuDCkmXA = null;
			IAXKisxPa = null;
			BHEVOHCNF = null;
			q104BcSEF = null;
			kfVnXwir4 = null;
			h0meuvY6F = null;
			nuQF2wt5k = null;
			ryYpiYLuk = "";
			eVhvDbAf3 = new Dictionary<int, int>();
			DhsGxxemM = new Dictionary<int, int>();
			IxsLMfsxp = false;
		}
	}
}
namespace Ob4WOlIBx5F1N21gPc
{
	[Guid("E723776A-8170-49d1-AA88-5D2D388D5DD9")]
	internal sealed class HTeX8Irfapx2F2XE6d : Form, IHelpInformation
	{
		private LocalizedStringProvider U7XS4groD;

		private MuZSd846qSL8CEOpUv ojDyTyOIL;

		private IContextSensitiveHelpProvider FecirPe4b;

		private bool AAEASlKRS;

		private IContainer cx2QPRXto;

		private TextBox DZ5ubQ3WR;

		private Button gJ0Y78MYp;

		private Button TLClKwkS1;

		private RadioButton DcZJV2iZ1;

		private RadioButton IDJBdOoXi;

		private GroupBox MYMTdpyN0;

		Guid IHelpInformation.GUID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ((object)this).GetType().GUID;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public HTeX8Irfapx2F2XE6d(LocalizedStringProvider P_0, object P_1, object P_2, bool P_3)
		{
			JmLDt5P0cahRebTiifG.LYav19NzXHLb9();
			((Form)this)..ctor();
			ntSf9TajL();
			U7XS4groD = P_0;
			ojDyTyOIL = (MuZSd846qSL8CEOpUv)0;
			FecirPe4b = Factory.CreateInstance<IContextSensitiveHelpProvider>();
			FecirPe4b.Initialize(P_1, P_2);
			AAEASlKRS = P_3;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public MuZSd846qSL8CEOpUv kdmCNAEG0()
		{
			return ojDyTyOIL;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void wCJRcX0Sc(object P_0, EventArgs P_1)
		{
			((Control)this).Text = U7XS4groD.GetLocalizedString((LLwdmNZAEG00aiD7e6)701);
			((Control)DZ5ubQ3WR).Text = U7XS4groD.GetLocalizedString((LLwdmNZAEG00aiD7e6)605);
			((Control)MYMTdpyN0).Text = U7XS4groD.GetLocalizedString((LLwdmNZAEG00aiD7e6)908);
			((Control)DcZJV2iZ1).Text = U7XS4groD.GetLocalizedString((LLwdmNZAEG00aiD7e6)906);
			((Control)IDJBdOoXi).Text = U7XS4groD.GetLocalizedString((LLwdmNZAEG00aiD7e6)907);
			((Control)gJ0Y78MYp).Text = U7XS4groD.GetLocalizedString((LLwdmNZAEG00aiD7e6)909);
			((Control)TLClKwkS1).Text = U7XS4groD.GetLocalizedString((LLwdmNZAEG00aiD7e6)901);
			DcZJV2iZ1.Checked = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void wWbjbNrTj(object P_0, EventArgs P_1)
		{
			((Form)this).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void wtH28OUqL(object P_0, EventArgs P_1)
		{
			//IL_007d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0083: Invalid comparison between Unknown and I4
			if (DcZJV2iZ1.Checked)
			{
				ojDyTyOIL = (MuZSd846qSL8CEOpUv)0;
			}
			else if (IDJBdOoXi.Checked)
			{
				ojDyTyOIL = (MuZSd846qSL8CEOpUv)1;
			}
			if (!AAEASlKRS || ojDyTyOIL != 0 || (int)MessageBox.Show(U7XS4groD.GetLocalizedString((LLwdmNZAEG00aiD7e6)609), U7XS4groD.GetLocalizedString((LLwdmNZAEG00aiD7e6)705), (MessageBoxButtons)4, (MessageBoxIcon)48) != 7)
			{
				((Form)this).DialogResult = (DialogResult)1;
				((Form)this).Close();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void aMMmmOWxU(object P_0, HelpEventArgs P_1)
		{
			FecirPe4b.ShowHelp(this);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Dispose(bool P_0)
		{
			if (P_0 && cx2QPRXto != null)
			{
				cx2QPRXto.Dispose();
			}
			((Form)this).Dispose(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void ntSf9TajL()
		{
			//IL_0018: Unknown result type (might be due to invalid IL or missing references)
			//IL_0022: Expected O, but got Unknown
			//IL_0023: Unknown result type (might be due to invalid IL or missing references)
			//IL_002d: Expected O, but got Unknown
			//IL_002e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0038: Expected O, but got Unknown
			//IL_0039: Unknown result type (might be due to invalid IL or missing references)
			//IL_0043: Expected O, but got Unknown
			//IL_0044: Unknown result type (might be due to invalid IL or missing references)
			//IL_004e: Expected O, but got Unknown
			//IL_004f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0059: Expected O, but got Unknown
			//IL_042a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0434: Expected O, but got Unknown
			//IL_0483: Unknown result type (might be due to invalid IL or missing references)
			//IL_048d: Expected O, but got Unknown
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(HTeX8Irfapx2F2XE6d));
			DZ5ubQ3WR = new TextBox();
			gJ0Y78MYp = new Button();
			TLClKwkS1 = new Button();
			DcZJV2iZ1 = new RadioButton();
			IDJBdOoXi = new RadioButton();
			MYMTdpyN0 = new GroupBox();
			((Control)MYMTdpyN0).SuspendLayout();
			((Control)this).SuspendLayout();
			((TextBoxBase)DZ5ubQ3WR).BorderStyle = (BorderStyle)0;
			((Control)DZ5ubQ3WR).Location = new Point(29, 20);
			((TextBoxBase)DZ5ubQ3WR).Multiline = true;
			((Control)DZ5ubQ3WR).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(906);
			((TextBoxBase)DZ5ubQ3WR).ReadOnly = true;
			((Control)DZ5ubQ3WR).Size = new Size(436, 37);
			((Control)DZ5ubQ3WR).TabIndex = 3;
			((Control)gJ0Y78MYp).Location = new Point(160, 181);
			((Control)gJ0Y78MYp).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(940);
			((Control)gJ0Y78MYp).Size = new Size(120, 33);
			((Control)gJ0Y78MYp).TabIndex = 1;
			((Control)gJ0Y78MYp).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(960);
			((ButtonBase)gJ0Y78MYp).UseVisualStyleBackColor = true;
			((Control)gJ0Y78MYp).Click += wtH28OUqL;
			TLClKwkS1.DialogResult = (DialogResult)2;
			((Control)TLClKwkS1).Location = new Point(354, 181);
			((Control)TLClKwkS1).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(972);
			((Control)TLClKwkS1).Size = new Size(122, 33);
			((Control)TLClKwkS1).TabIndex = 2;
			((Control)TLClKwkS1).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(996);
			((ButtonBase)TLClKwkS1).UseVisualStyleBackColor = true;
			((Control)TLClKwkS1).Click += wWbjbNrTj;
			((Control)DcZJV2iZ1).AutoSize = true;
			((Control)DcZJV2iZ1).Location = new Point(13, 28);
			((Control)DcZJV2iZ1).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(1012);
			((Control)DcZJV2iZ1).Size = new Size(85, 17);
			((Control)DcZJV2iZ1).TabIndex = 4;
			DcZJV2iZ1.TabStop = true;
			((Control)DcZJV2iZ1).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(1052);
			((ButtonBase)DcZJV2iZ1).UseVisualStyleBackColor = true;
			((Control)IDJBdOoXi).AutoSize = true;
			((Control)IDJBdOoXi).Location = new Point(13, 58);
			((Control)IDJBdOoXi).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(1080);
			((Control)IDJBdOoXi).Size = new Size(85, 17);
			((Control)IDJBdOoXi).TabIndex = 5;
			IDJBdOoXi.TabStop = true;
			((Control)IDJBdOoXi).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(1116);
			((ButtonBase)IDJBdOoXi).UseVisualStyleBackColor = true;
			((Control)MYMTdpyN0).Controls.Add((Control)(object)IDJBdOoXi);
			((Control)MYMTdpyN0).Controls.Add((Control)(object)DcZJV2iZ1);
			((Control)MYMTdpyN0).Location = new Point(12, 63);
			((Control)MYMTdpyN0).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(1144);
			((Control)MYMTdpyN0).Size = new Size(613, 93);
			((Control)MYMTdpyN0).TabIndex = 6;
			MYMTdpyN0.TabStop = false;
			((Control)MYMTdpyN0).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(1178);
			((ContainerControl)this).AutoScaleDimensions = new SizeF(6f, 13f);
			((ContainerControl)this).AutoScaleMode = (AutoScaleMode)1;
			((Form)this).CancelButton = (IButtonControl)(object)TLClKwkS1;
			((Form)this).ClientSize = new Size(637, 234);
			((Control)this).Controls.Add((Control)(object)MYMTdpyN0);
			((Control)this).Controls.Add((Control)(object)TLClKwkS1);
			((Control)this).Controls.Add((Control)(object)gJ0Y78MYp);
			((Control)this).Controls.Add((Control)(object)DZ5ubQ3WR);
			((Form)this).FormBorderStyle = (FormBorderStyle)3;
			((Form)this).Icon = (Icon)componentResourceManager.GetObject(MnxsD0lrg8kZaUPt2I.OPAImF4404(1200));
			((Form)this).MaximizeBox = false;
			((Form)this).MinimizeBox = false;
			((Control)this).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(1224);
			((Form)this).StartPosition = (FormStartPosition)4;
			((Control)this).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(1272);
			((Form)this).Load += wCJRcX0Sc;
			((Control)this).HelpRequested += new HelpEventHandler(aMMmmOWxU);
			((Control)MYMTdpyN0).ResumeLayout(false);
			((Control)MYMTdpyN0).PerformLayout();
			((Control)this).ResumeLayout(false);
			((Control)this).PerformLayout();
		}
	}
}
namespace nVLZejXdyZSvvx2mMM
{
	[Guid("A990AED6-EBA8-4a06-8B7E-C09F7FC9C2C4")]
	internal sealed class QH6UkVcfudxA5A7qRi : Form, IHelpInformation
	{
		private enum tRGdbuxbKrY7YZL3Sn
		{

		}

		private const short tNePWlcIlF = 1;

		private const short pOYPSll4On = 2;

		private const short Aq4PysH34p = 3;

		private const short cuUPiwqEwg = 4;

		private const short qnhPAGLUMg = 3;

		private const int yXcPQ0rlQv = 6;

		private ICachedDMLAvailableGroups D3wPuD00vc;

		private IDMLModuleNames aPGPYItuxe;

		private LocalizedStringProvider OvNPlOBH39;

		private IContextSensitiveHelpProvider MnxPJsD0rg;

		private Dictionary<string, lHyiuRpvRLKBqfyHe9> lkZPBaUPt2;

		private Dictionary<string, lHyiuRpvRLKBqfyHe9> gBcPTsyoeP;

		private Dictionary<string, lHyiuRpvRLKBqfyHe9> D0DPzW6gWA;

		private IBSTRCollection NXV1HyEJw3;

		private bool Xax1PosHZj;

		private long oHQ11ILeLc;

		private Dictionary<string, V6PGe1R884NJ3GD2LA> dtP1s0swCI;

		private Dictionary<V6PGe1R884NJ3GD2LA, int> S6L10aXiP7;

		private XRbgaoKmn16bImAki0 lio177cPPu;

		private string kQ91rKhySF;

		private Dictionary<string, lHyiuRpvRLKBqfyHe9> uve1I8GjYR;

		private Dictionary<string, lHyiuRpvRLKBqfyHe9> MCm1cwkivw;

		private IContainer a1V1Xk8c73;

		private Button Iek1x3wMlM;

		private Button QF81ogbUsq;

		private Button uJ61wfsfsX;

		private TextBox vZg1gsVZrn;

		private Button A0P18661f1;

		private ComboBox NLm1dLDt5c;

		private GroupBox thR1kebTii;

		private GroupBox NGp13PU5lG;

		private Button utd1MR7quT;

		private Button sU119kbZbQ;

		private ToolTip D1q16u5crK;

		private ToolTip zDF1ObPMLi;

		private DomainUpDown gHl1aN99tY;

		private C1FlexGrid dUE1ZJqxBb;

		private C1FlexGrid hoi1EdNhJs;

		Guid IHelpInformation.GUID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ((object)this).GetType().GUID;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void jfEzN6lv1(object P_0, EventArgs P_1)
		{
			//IL_0053: Unknown result type (might be due to invalid IL or missing references)
			//IL_005d: Expected O, but got Unknown
			//IL_02fe: Unknown result type (might be due to invalid IL or missing references)
			//IL_0308: Expected O, but got Unknown
			try
			{
				if (!Xax1PosHZj)
				{
					((Control)this).Text = OvNPlOBH39.GetLocalizedString((LLwdmNZAEG00aiD7e6)400);
					((Control)vZg1gsVZrn).Text = OvNPlOBH39.GetLocalizedString((LLwdmNZAEG00aiD7e6)604);
					((Control)vZg1gsVZrn).ContextMenu = new ContextMenu();
					((Control)dUE1ZJqxBb).Size = new Size(260, 207);
					((Control)hoi1EdNhJs).Size = new Size(250, 207);
					dUE1ZJqxBb.Redraw = false;
					XqfPOyHe9k();
					zAuPZEp2Ea();
					dUE1ZJqxBb.AutoSizeCols();
					dUE1ZJqxBb.AutoSizeRows();
					dUE1ZJqxBb.Redraw = true;
					hoi1EdNhJs.Redraw = false;
					l8JPa85BrH();
					FWcPEKfcWl();
					hoi1EdNhJs.AutoSizeCols();
					hoi1EdNhJs.AutoSizeRows();
					hoi1EdNhJs.Redraw = true;
					if (lkZPBaUPt2.Count <= 0)
					{
						((Control)Iek1x3wMlM).Enabled = false;
					}
					else
					{
						((Control)Iek1x3wMlM).Enabled = true;
					}
					((Control)uJ61wfsfsX).Enabled = false;
					((Control)QF81ogbUsq).Enabled = false;
					NLm1dLDt5c.SelectedIndexChanged += lamPouZSd8;
					NVhPVhnh7X();
					((Control)QF81ogbUsq).Text = OvNPlOBH39.GetLocalizedString((LLwdmNZAEG00aiD7e6)408);
					((Control)uJ61wfsfsX).Text = OvNPlOBH39.GetLocalizedString((LLwdmNZAEG00aiD7e6)409);
					((Control)Iek1x3wMlM).Text = OvNPlOBH39.GetLocalizedString((LLwdmNZAEG00aiD7e6)900);
					((Control)A0P18661f1).Text = OvNPlOBH39.GetLocalizedString((LLwdmNZAEG00aiD7e6)901);
					((Control)sU119kbZbQ).Text = OvNPlOBH39.GetLocalizedString((LLwdmNZAEG00aiD7e6)407);
					((Control)utd1MR7quT).Text = OvNPlOBH39.GetLocalizedString((LLwdmNZAEG00aiD7e6)250);
					((Control)thR1kebTii).Text = OvNPlOBH39.GetLocalizedString((LLwdmNZAEG00aiD7e6)400);
					((Control)NGp13PU5lG).Text = OvNPlOBH39.GetLocalizedString((LLwdmNZAEG00aiD7e6)403);
					D1q16u5crK.AutoPopDelay = 2000;
					D1q16u5crK.SetToolTip((Control)(object)dUE1ZJqxBb, OvNPlOBH39.GetLocalizedString((LLwdmNZAEG00aiD7e6)607));
					D1q16u5crK.Active = false;
					zDF1ObPMLi.AutoPopDelay = 2000;
					zDF1ObPMLi.SetToolTip((Control)(object)gHl1aN99tY, MnxsD0lrg8kZaUPt2I.OPAImF4404(1320));
					zDF1ObPMLi.Active = false;
					((Control)gHl1aN99tY).TextChanged += rqSPwL8CEO;
					((Control)gHl1aN99tY).ContextMenu = new ContextMenu();
					Xax1PosHZj = true;
				}
				afYPDULCTT((tRGdbuxbKrY7YZL3Sn)0);
				afYPDULCTT((tRGdbuxbKrY7YZL3Sn)1);
				gdePHFn2Rt(2);
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void gdePHFn2Rt(int P_0)
		{
			for (int i = 0; i < dUE1ZJqxBb.Rows.Count; i++)
			{
				if (dUE1ZJqxBb.Rows[i].IsNode && dUE1ZJqxBb.Rows[i].Node.Level == P_0)
				{
					dUE1ZJqxBb.Rows[i].Node.Collapsed = true;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void auiPPDQYy7(object P_0, FormClosingEventArgs P_1)
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_000e: Invalid comparison between Unknown and I4
			try
			{
				if ((int)P_1.CloseReason == 3)
				{
					hrPPMQChoQ();
				}
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void qwcP1ljFb2(object P_0, HelpEventArgs P_1)
		{
			try
			{
				MnxPJsD0rg.ShowHelp(this);
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void e0jPsT1r1w(object P_0, EventArgs P_1)
		{
			try
			{
				l84P5NJ3GD();
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Jk7P0eb8B6(object P_0, RangeEventArgs P_1)
		{
			try
			{
				if (vepP97xugH() && RiuP6RvRLK())
				{
					((Control)QF81ogbUsq).Enabled = true;
					D1q16u5crK.Active = false;
				}
				else if (!RiuP6RvRLK())
				{
					D1q16u5crK.Show(OvNPlOBH39.GetLocalizedString((LLwdmNZAEG00aiD7e6)607), (IWin32Window)(object)dUE1ZJqxBb);
				}
				else
				{
					((Control)QF81ogbUsq).Enabled = false;
				}
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void aYuP7Bca9I(object P_0, MouseEventArgs P_1)
		{
			try
			{
				if (RiuP6RvRLK())
				{
					D1q16u5crK.Active = false;
				}
				else
				{
					D1q16u5crK.Active = true;
				}
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void ilTPrwe33U(object P_0, EventArgs P_1)
		{
			try
			{
				long num = 0L;
				num = hoi1EdNhJs.MouseRow;
				if (num > 0)
				{
					LLAPbi6d0D();
				}
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void XRbPIgaomn(object P_0, RangeEventArgs P_1)
		{
			try
			{
				if (P_1.NewRange.IsValid && lkZPBaUPt2.Count > 0)
				{
					((Control)uJ61wfsfsX).Enabled = true;
				}
				else
				{
					((Control)uJ61wfsfsX).Enabled = false;
				}
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void a6bPcImAki(object P_0, EventArgs P_1)
		{
			try
			{
				if (!j5jP4RQbBV())
				{
					((UpDownBase)gHl1aN99tY).Select(0, ((Control)gHl1aN99tY).Text.Length);
					((Control)gHl1aN99tY).Focus();
					return;
				}
				((Form)this).DialogResult = (DialogResult)1;
				((Control)this).Hide();
				V6PGe1R884NJ3GD2LA v6PGe1R884NJ3GD2LA = dtP1s0swCI[(string)NLm1dLDt5c.Items[((ListControl)NLm1dLDt5c).SelectedIndex]];
				oHQ11ILeLc = ewqjA30Ig7KglKlcHq.aN2d1gPcS(decimal.Parse(((Control)gHl1aN99tY).Text), v6PGe1R884NJ3GD2LA);
				KWMPUq48MP();
				lio177cPPu = (XRbgaoKmn16bImAki0)0;
				gBcPTsyoeP.Clear();
				Dictionary<string, lHyiuRpvRLKBqfyHe9>.Enumerator enumerator = lkZPBaUPt2.GetEnumerator();
				while (enumerator.MoveNext())
				{
					gBcPTsyoeP.Add(enumerator.Current.Key, enumerator.Current.Value);
				}
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void dpJPXi4bIZ(object P_0, EventArgs P_1)
		{
			try
			{
				l84P5NJ3GD();
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void CYcPxPuwrR(object P_0, EventArgs P_1)
		{
			try
			{
				LLAPbi6d0D();
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void lamPouZSd8(object P_0, EventArgs P_1)
		{
			try
			{
				string key = (string)NLm1dLDt5c.Items[((ListControl)NLm1dLDt5c).SelectedIndex];
				V6PGe1R884NJ3GD2LA v6PGe1R884NJ3GD2LA = dtP1s0swCI[key];
				((ArrayList)(object)gHl1aN99tY.Items).Clear();
				switch (v6PGe1R884NJ3GD2LA)
				{
				case V6PGe1R884NJ3GD2LA.Hour:
					((ArrayList)(object)gHl1aN99tY.Items).Add((object?)MnxsD0lrg8kZaUPt2I.OPAImF4404(1530));
					break;
				case V6PGe1R884NJ3GD2LA.Secs:
				case V6PGe1R884NJ3GD2LA.Mins:
				{
					for (int num2 = 59; num2 > 0; num2--)
					{
						((ArrayList)(object)gHl1aN99tY.Items).Add((object?)num2);
					}
					break;
				}
				case V6PGe1R884NJ3GD2LA.MilliSecs:
				{
					((ArrayList)(object)gHl1aN99tY.Items).Add((object?)MnxsD0lrg8kZaUPt2I.OPAImF4404(1536));
					for (int num = 990; num > 10; num -= 10)
					{
						((ArrayList)(object)gHl1aN99tY.Items).Add((object?)num);
					}
					break;
				}
				}
				gHl1aN99tY.SelectedIndex = ((ArrayList)(object)gHl1aN99tY.Items).Count - 1;
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void rqSPwL8CEO(object P_0, EventArgs P_1)
		{
			try
			{
				if (j5jP4RQbBV())
				{
					zDF1ObPMLi.Active = false;
					return;
				}
				zDF1ObPMLi.Active = true;
				zDF1ObPMLi.Show(MnxsD0lrg8kZaUPt2I.OPAImF4404(1546), (IWin32Window)(object)gHl1aN99tY);
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void HUvPgyIadP(object P_0, EventArgs P_1)
		{
			try
			{
				if (j5jP4RQbBV())
				{
					zDF1ObPMLi.Active = false;
					return;
				}
				zDF1ObPMLi.Active = true;
				zDF1ObPMLi.Show(MnxsD0lrg8kZaUPt2I.OPAImF4404(1756), (IWin32Window)(object)gHl1aN99tY);
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void ioaP8kDxeC(object P_0, EventArgs P_1)
		{
			try
			{
				if (!j5jP4RQbBV())
				{
					((Control)gHl1aN99tY).Focus();
				}
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void TSfPdqh2IX(object P_0, EventArgs P_1)
		{
			try
			{
				((Control)this).Hide();
				hrPPMQChoQ();
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void JLGPkQpqCf(object P_0, EventArgs P_1)
		{
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			//IL_000d: Expected O, but got Unknown
			//IL_004f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0055: Invalid comparison between Unknown and I4
			try
			{
				OpenFileDialog val = new OpenFileDialog();
				((FileDialog)val).Title = OvNPlOBH39.GetLocalizedString((LLwdmNZAEG00aiD7e6)702);
				((FileDialog)val).Filter = OvNPlOBH39.GetLocalizedString((LLwdmNZAEG00aiD7e6)502);
				((FileDialog)val).InitialDirectory = ewqjA30Ig7KglKlcHq.F2XgE6dCb();
				if ((int)((CommonDialog)val).ShowDialog() == 1)
				{
					lio177cPPu = (XRbgaoKmn16bImAki0)1;
					kQ91rKhySF = ((FileDialog)val).FileName;
					((Form)this).DialogResult = (DialogResult)1;
					((Control)this).Hide();
				}
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void OUyP3uMNi4(object P_0, EventArgs P_1)
		{
			try
			{
				qwcP1ljFb2(P_0, null);
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void hrPPMQChoQ()
		{
			((Form)this).DialogResult = (DialogResult)2;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool vepP97xugH()
		{
			bool flag = false;
			int row = dUE1ZJqxBb.Row;
			if (row <= 0)
			{
				return false;
			}
			int num = uAYPh6PGe1((tRGdbuxbKrY7YZL3Sn)0, row);
			if (num == 4 || num == 3)
			{
				string text = dUE1ZJqxBb.Rows[row].UserData.ToString();
				if (ewqjA30Ig7KglKlcHq.zk8sAgfwj(text))
				{
					if (lkZPBaUPt2.ContainsKey(text))
					{
						return false;
					}
					return true;
				}
				return false;
			}
			return false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool RiuP6RvRLK()
		{
			bool flag = false;
			if (lkZPBaUPt2.Count >= 6)
			{
				return false;
			}
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void XqfPOyHe9k()
		{
			//IL_0131: Unknown result type (might be due to invalid IL or missing references)
			//IL_013b: Expected O, but got Unknown
			dUE1ZJqxBb.Rows.Count = 1;
			dUE1ZJqxBb.Cols.Count = 1;
			dUE1ZJqxBb.Cols.Fixed = 0;
			dUE1ZJqxBb.Rows.Fixed = 1;
			dUE1ZJqxBb.ScrollBars = (ScrollBars)3;
			dUE1ZJqxBb.AllowEditing = false;
			dUE1ZJqxBb.SelectionMode = SelectionModeEnum.ListBox;
			dUE1ZJqxBb.AutoSearch = AutoSearchEnum.FromCursor;
			dUE1ZJqxBb[0, 0] = OvNPlOBH39.GetLocalizedString((LLwdmNZAEG00aiD7e6)401);
			dUE1ZJqxBb.Styles.Normal.WordWrap = true;
			dUE1ZJqxBb.AutoResize = true;
			dUE1ZJqxBb.Tree.Column = 0;
			dUE1ZJqxBb.Tree.Style = TreeStyleFlags.SimpleLeaf;
			dUE1ZJqxBb.HighLight = HighLightEnum.Always;
			dUE1ZJqxBb.FocusRect = FocusRectEnum.Heavy;
			dUE1ZJqxBb.AutoSizeRows();
			CellStyle cellStyle = dUE1ZJqxBb.Styles.Add(MnxsD0lrg8kZaUPt2I.OPAImF4404(1966));
			cellStyle.Font = new Font(MnxsD0lrg8kZaUPt2I.OPAImF4404(1978), 8f, (FontStyle)1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void l8JPa85BrH()
		{
			hoi1EdNhJs.Rows.Count = 1;
			hoi1EdNhJs.Cols.Count = 1;
			hoi1EdNhJs.Cols.Fixed = 0;
			hoi1EdNhJs.Rows.Fixed = 1;
			hoi1EdNhJs.ScrollBars = (ScrollBars)3;
			hoi1EdNhJs.AllowEditing = false;
			hoi1EdNhJs.SelectionMode = SelectionModeEnum.ListBox;
			hoi1EdNhJs.AutoSearch = AutoSearchEnum.FromCursor;
			hoi1EdNhJs[0, 0] = OvNPlOBH39.GetLocalizedString((LLwdmNZAEG00aiD7e6)402);
			hoi1EdNhJs.Cols[0].TextAlign = TextAlignEnum.LeftCenter;
			hoi1EdNhJs.Styles.Normal.WordWrap = true;
			hoi1EdNhJs.Tree.Column = 0;
			hoi1EdNhJs.Tree.Style = TreeStyleFlags.Simple;
			hoi1EdNhJs.AutoResize = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void zAuPZEp2Ea()
		{
			BSTRCollection ppVal = null;
			LongCollection ppGroupTypes = null;
			D3wPuD00vc.GetGroupNames(out ppVal, out ppGroupTypes);
			ehhPtTBulZ(ppVal, ppGroupTypes, out var groupNames, out var groupNames2);
			int num = dUE1ZJqxBb.Rows.Count - 1;
			Row row = null;
			row = dUE1ZJqxBb.AddItem(OvNPlOBH39.GetLocalizedString((LLwdmNZAEG00aiD7e6)405));
			row.IsNode = true;
			num++;
			dUE1ZJqxBb.Rows[num].Node.Level = 1;
			CellRange cellRange = dUE1ZJqxBb.GetCellRange(num, 0, num, 0);
			cellRange.Style = dUE1ZJqxBb.Styles[MnxsD0lrg8kZaUPt2I.OPAImF4404(2022)];
			num = UpmPqIhwNo(groupNames, num);
			row = dUE1ZJqxBb.AddItem(OvNPlOBH39.GetLocalizedString((LLwdmNZAEG00aiD7e6)406));
			row.IsNode = true;
			num++;
			dUE1ZJqxBb.Rows[num].Node.Level = 1;
			cellRange = dUE1ZJqxBb.GetCellRange(num, 0, num, 0);
			cellRange.Style = dUE1ZJqxBb.Styles[MnxsD0lrg8kZaUPt2I.OPAImF4404(2034)];
			num = CkWPNZe5vv(groupNames2, num);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void FWcPEKfcWl()
		{
			y84Pe6Ztkb();
			Dictionary<string, lHyiuRpvRLKBqfyHe9>.Enumerator enumerator = lkZPBaUPt2.GetEnumerator();
			int num = hoi1EdNhJs.Rows.Count - 1;
			while (enumerator.MoveNext() && num <= 6)
			{
				lHyiuRpvRLKBqfyHe9 value = enumerator.Current.Value;
				if (aPGPYItuxe.Count > 1)
				{
					hoi1EdNhJs.AddItem(value.A46rwSBvbY + MnxsD0lrg8kZaUPt2I.OPAImF4404(2046) + value.VaDrxUe24c + MnxsD0lrg8kZaUPt2I.OPAImF4404(2052));
				}
				else
				{
					hoi1EdNhJs.AddItem(value.A46rwSBvbY);
				}
				num++;
				hoi1EdNhJs.Rows[num].UserData = enumerator.Current.Value.aaYrcWlA7H;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void ehhPtTBulZ(BSTRCollection P_0, LongCollection P_1, out List<string> P_2, out List<string> P_3)
		{
			P_2 = new List<string>();
			P_3 = new List<string>();
			string allParametersGroupName = D3wPuD00vc.GetAllParametersGroupName();
			for (int i = 1; i <= P_0.Count; i++)
			{
				string text = ((IBSTRCollection)P_0).get_Item(i);
				if (!(text == allParametersGroupName))
				{
					if (((ILongCollection)P_1).get_Item(i) == 1)
					{
						P_2.Add(text);
					}
					else
					{
						P_3.Add(text);
					}
				}
			}
			P_2.Sort();
			P_3.Sort();
			P_2.Insert(0, allParametersGroupName);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private int UpmPqIhwNo(List<string> groupNames, int P_1)
		{
			for (int i = 0; i < groupNames.Count; i++)
			{
				try
				{
					Row row = null;
					row = dUE1ZJqxBb.AddItem(groupNames[i]);
					row.IsNode = true;
					P_1++;
					CellRange cellRange = dUE1ZJqxBb.GetCellRange(P_1, 0, P_1, 0);
					cellRange.Style = dUE1ZJqxBb.Styles[MnxsD0lrg8kZaUPt2I.OPAImF4404(2058)];
					dUE1ZJqxBb.Rows[P_1].Node.Level = 2;
					for (int j = 1; j <= aPGPYItuxe.Count; j++)
					{
						string text = aPGPYItuxe.get_ModuleID(j);
						int value = aPGPYItuxe.get_SourceAddress(text);
						if (aPGPYItuxe.Count > 1)
						{
							StringBuilder stringBuilder = new StringBuilder();
							stringBuilder.Append(aPGPYItuxe.get_Name((object)text));
							stringBuilder.Append(MnxsD0lrg8kZaUPt2I.OPAImF4404(2070));
							stringBuilder.Append(value);
							stringBuilder.Append(MnxsD0lrg8kZaUPt2I.OPAImF4404(2076));
							row = dUE1ZJqxBb.AddItem(stringBuilder.ToString());
						}
						else
						{
							string item = aPGPYItuxe.get_Name((object)text);
							row = dUE1ZJqxBb.AddItem(item);
						}
						row.IsNode = true;
						P_1++;
						dUE1ZJqxBb.Rows[P_1].Node.Level = 3;
						dUE1ZJqxBb.Rows[P_1].UserData = value.ToString();
						IDMLParameters parameters = D3wPuD00vc.GetParameters(groupNames[i], aPGPYItuxe.get_ModuleID(j));
						SortedList<string, IDMLParameter> sortedList = new SortedList<string, IDMLParameter>(parameters.Count);
						for (int k = 1; k <= parameters.Count; k++)
						{
							try
							{
								IDMLParameter iDMLParameter = parameters.get_Item((object)k);
								sortedList.Add(iDMLParameter.ParameterName + iDMLParameter.Cookie, iDMLParameter);
							}
							catch
							{
							}
						}
						IEnumerator<KeyValuePair<string, IDMLParameter>> enumerator = sortedList.GetEnumerator();
						while (enumerator.MoveNext())
						{
							lHyiuRpvRLKBqfyHe9 lHyiuRpvRLKBqfyHe = ewqjA30Ig7KglKlcHq.FBArCMB1R(enumerator.Current.Value);
							if (!ewqjA30Ig7KglKlcHq.PnhaJXRto(lHyiuRpvRLKBqfyHe))
							{
								row = dUE1ZJqxBb.AddItem(lHyiuRpvRLKBqfyHe.A46rwSBvbY);
								row.IsNode = true;
								P_1++;
								dUE1ZJqxBb.Rows[P_1].UserData = lHyiuRpvRLKBqfyHe.aaYrcWlA7H;
								dUE1ZJqxBb.Rows[P_1].Node.Level = 4;
								try
								{
									D0DPzW6gWA.Add(lHyiuRpvRLKBqfyHe.aaYrcWlA7H, lHyiuRpvRLKBqfyHe);
								}
								catch
								{
								}
							}
						}
					}
				}
				catch
				{
				}
			}
			return P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private int CkWPNZe5vv(List<string> groupNames, int P_1)
		{
			for (int i = 0; i < groupNames.Count; i++)
			{
				try
				{
					Row row = dUE1ZJqxBb.AddItem(groupNames[i]);
					row.IsNode = true;
					P_1++;
					CellRange cellRange = dUE1ZJqxBb.GetCellRange(P_1, 0, P_1, 0);
					cellRange.Style = dUE1ZJqxBb.Styles[MnxsD0lrg8kZaUPt2I.OPAImF4404(2082)];
					dUE1ZJqxBb.Rows[P_1].Node.Level = 2;
					IDMLParameters parameters = D3wPuD00vc.GetParameters(groupNames[i], aPGPYItuxe.get_ModuleID(1));
					SortedList<string, IDMLParameter> sortedList = new SortedList<string, IDMLParameter>(parameters.Count);
					for (int j = 1; j <= parameters.Count; j++)
					{
						try
						{
							IDMLParameter iDMLParameter = parameters.get_Item((object)j);
							sortedList.Add(iDMLParameter.ParameterName + iDMLParameter.Cookie, iDMLParameter);
						}
						catch
						{
						}
					}
					IEnumerator<KeyValuePair<string, IDMLParameter>> enumerator = sortedList.GetEnumerator();
					while (enumerator.MoveNext())
					{
						lHyiuRpvRLKBqfyHe9 lHyiuRpvRLKBqfyHe = ewqjA30Ig7KglKlcHq.FBArCMB1R(enumerator.Current.Value);
						if (!ewqjA30Ig7KglKlcHq.PnhaJXRto(lHyiuRpvRLKBqfyHe))
						{
							if (aPGPYItuxe.Count > 1)
							{
								StringBuilder stringBuilder = new StringBuilder(enumerator.Current.Value.ParameterName);
								stringBuilder.Append(MnxsD0lrg8kZaUPt2I.OPAImF4404(2094));
								stringBuilder.Append(lHyiuRpvRLKBqfyHe.VaDrxUe24c);
								stringBuilder.Append(MnxsD0lrg8kZaUPt2I.OPAImF4404(2100));
								row = dUE1ZJqxBb.AddItem(stringBuilder.ToString());
							}
							else
							{
								row = dUE1ZJqxBb.AddItem(enumerator.Current.Value.ParameterName);
							}
							row.IsNode = true;
							P_1++;
							dUE1ZJqxBb.Rows[P_1].UserData = lHyiuRpvRLKBqfyHe.aaYrcWlA7H;
							dUE1ZJqxBb.Rows[P_1].Node.Level = 4;
						}
					}
				}
				catch
				{
				}
			}
			return P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private int uAYPh6PGe1(tRGdbuxbKrY7YZL3Sn P_0, int P_1)
		{
			int result = -1;
			switch (P_0)
			{
			case (tRGdbuxbKrY7YZL3Sn)0:
				result = dUE1ZJqxBb.Rows[P_1].Node.Level;
				break;
			case (tRGdbuxbKrY7YZL3Sn)1:
				result = hoi1EdNhJs.Rows[P_1].Node.Level;
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void l84P5NJ3GD()
		{
			if (RiuP6RvRLK() && vepP97xugH())
			{
				int num = -1;
				num = dUE1ZJqxBb.Row;
				string key = (string)dUE1ZJqxBb.Rows[num].UserData;
				lHyiuRpvRLKBqfyHe9 value = D0DPzW6gWA[key];
				int num2 = hoi1EdNhJs.Rows.Count - 1;
				string text = dUE1ZJqxBb[num, 0].ToString();
				int index = dUE1ZJqxBb.Rows[num].Node.GetNode(NodeTypeEnum.Parent).Row.Index;
				string text2 = (string)dUE1ZJqxBb.Rows[index].UserData;
				if (aPGPYItuxe.Count > 1 && !text.Contains(MnxsD0lrg8kZaUPt2I.OPAImF4404(2106)))
				{
					hoi1EdNhJs.AddItem(text + MnxsD0lrg8kZaUPt2I.OPAImF4404(2112) + text2 + MnxsD0lrg8kZaUPt2I.OPAImF4404(2118));
				}
				else
				{
					hoi1EdNhJs.AddItem(text);
				}
				num2++;
				hoi1EdNhJs.Rows[num2].UserData = value.aaYrcWlA7H;
				hoi1EdNhJs.AutoSizeCols();
				hoi1EdNhJs.AutoSizeRows();
				lkZPBaUPt2.Add(value.aaYrcWlA7H, value);
			}
			afYPDULCTT((tRGdbuxbKrY7YZL3Sn)0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void LLAPbi6d0D()
		{
			int num = -1;
			num = hoi1EdNhJs.Row;
			if (num >= 1)
			{
				string key = (string)hoi1EdNhJs.Rows[num].UserData;
				lkZPBaUPt2.Remove(key);
				hoi1EdNhJs.RemoveItem(num);
			}
			afYPDULCTT((tRGdbuxbKrY7YZL3Sn)1);
			afYPDULCTT((tRGdbuxbKrY7YZL3Sn)0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void KWMPUq48MP()
		{
			if (lio177cPPu == (XRbgaoKmn16bImAki0)1)
			{
				gBcPTsyoeP.Clear();
			}
			if (uve1I8GjYR == null)
			{
				uve1I8GjYR = new Dictionary<string, lHyiuRpvRLKBqfyHe9>();
			}
			uve1I8GjYR.Clear();
			Dictionary<string, lHyiuRpvRLKBqfyHe9>.Enumerator enumerator = gBcPTsyoeP.GetEnumerator();
			while (enumerator.MoveNext())
			{
				if (!lkZPBaUPt2.ContainsKey(enumerator.Current.Key))
				{
					uve1I8GjYR.Add(enumerator.Current.Key, enumerator.Current.Value);
				}
			}
			if (MCm1cwkivw == null)
			{
				MCm1cwkivw = new Dictionary<string, lHyiuRpvRLKBqfyHe9>();
			}
			MCm1cwkivw.Clear();
			Dictionary<string, lHyiuRpvRLKBqfyHe9>.Enumerator enumerator2 = lkZPBaUPt2.GetEnumerator();
			while (enumerator2.MoveNext())
			{
				if (!gBcPTsyoeP.ContainsKey(enumerator2.Current.Key))
				{
					MCm1cwkivw.Add(enumerator2.Current.Key, enumerator2.Current.Value);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void afYPDULCTT(tRGdbuxbKrY7YZL3Sn P_0)
		{
			if (P_0 == (tRGdbuxbKrY7YZL3Sn)0)
			{
				if (RiuP6RvRLK() && vepP97xugH())
				{
					((Control)QF81ogbUsq).Enabled = true;
				}
				else
				{
					((Control)QF81ogbUsq).Enabled = false;
				}
			}
			else if (lkZPBaUPt2.Count <= 0)
			{
				((Control)uJ61wfsfsX).Enabled = false;
			}
			if (RiuP6RvRLK())
			{
				((Control)dUE1ZJqxBb).BackColor = Color.White;
			}
			else
			{
				((Control)dUE1ZJqxBb).BackColor = Color.LightGray;
			}
			if (lkZPBaUPt2.Count > 0)
			{
				((Control)sU119kbZbQ).Enabled = false;
				((Control)Iek1x3wMlM).Enabled = true;
			}
			else
			{
				((Control)sU119kbZbQ).Enabled = true;
				((Control)Iek1x3wMlM).Enabled = false;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void rVWPKOmvGF()
		{
			int num = 0;
			int num2 = 0;
			int num3 = 0;
			int num4 = 0;
			V6PGe1R884NJ3GD2LA key = ewqjA30Ig7KglKlcHq.DWO8lBx5F(oHQ11ILeLc, out num, out num2, out num3, out num4);
			((ListControl)NLm1dLDt5c).SelectedIndex = S6L10aXiP7[key];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void NVhPVhnh7X()
		{
			dtP1s0swCI.Clear();
			S6L10aXiP7.Clear();
			dtP1s0swCI.Add(OvNPlOBH39.GetLocalizedString((LLwdmNZAEG00aiD7e6)902), V6PGe1R884NJ3GD2LA.MilliSecs);
			dtP1s0swCI.Add(OvNPlOBH39.GetLocalizedString((LLwdmNZAEG00aiD7e6)903), V6PGe1R884NJ3GD2LA.Secs);
			dtP1s0swCI.Add(OvNPlOBH39.GetLocalizedString((LLwdmNZAEG00aiD7e6)904), V6PGe1R884NJ3GD2LA.Mins);
			dtP1s0swCI.Add(OvNPlOBH39.GetLocalizedString((LLwdmNZAEG00aiD7e6)905), V6PGe1R884NJ3GD2LA.Hour);
			Dictionary<string, V6PGe1R884NJ3GD2LA>.Enumerator enumerator = dtP1s0swCI.GetEnumerator();
			NLm1dLDt5c.Items.Clear();
			while (enumerator.MoveNext())
			{
				S6L10aXiP7.Add(enumerator.Current.Value, NLm1dLDt5c.Items.Add((object)enumerator.Current.Key));
			}
			rVWPKOmvGF();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool j5jP4RQbBV()
		{
			bool flag = false;
			if (int.TryParse(((Control)gHl1aN99tY).Text, out var result))
			{
				string key = (string)NLm1dLDt5c.Items[((ListControl)NLm1dLDt5c).SelectedIndex];
				V6PGe1R884NJ3GD2LA v6PGe1R884NJ3GD2LA = dtP1s0swCI[key];
				int num = 1;
				int num2 = 1;
				switch (v6PGe1R884NJ3GD2LA)
				{
				case V6PGe1R884NJ3GD2LA.Hour:
					num = (num2 = 1);
					break;
				case V6PGe1R884NJ3GD2LA.Secs:
				case V6PGe1R884NJ3GD2LA.Mins:
					num = 1;
					num2 = 59;
					break;
				case V6PGe1R884NJ3GD2LA.MilliSecs:
					num = 20;
					num2 = 999;
					break;
				}
				if (result < num || result > num2)
				{
					return false;
				}
				return true;
			}
			return false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public long lPIPGGTZwp()
		{
			return oHQ11ILeLc;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public void eGwPLjw6qL(long P_0)
		{
			oHQ11ILeLc = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public void OVaP2txEhH(XRbgaoKmn16bImAki0 P_0)
		{
			lio177cPPu = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public XRbgaoKmn16bImAki0 ET2PjUKedp()
		{
			return lio177cPPu;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public string Mt9Pfm92EA()
		{
			return kQ91rKhySF;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public QH6UkVcfudxA5A7qRi(object P_0, object P_1, object P_2, long P_3, LocalizedStringProvider P_4)
		{
			JmLDt5P0cahRebTiifG.LYav19NzXHLb9();
			((Form)this)..ctor();
			gp9Pv2IPGD();
			MnxPJsD0rg = Factory.CreateInstance<IContextSensitiveHelpProvider>();
			MnxPJsD0rg.Initialize(P_0, P_1);
			D3wPuD00vc = (ICachedDMLAvailableGroups)P_2;
			aPGPYItuxe = D3wPuD00vc.ModuleNames;
			OvNPlOBH39 = P_4;
			lkZPBaUPt2 = new Dictionary<string, lHyiuRpvRLKBqfyHe9>(6);
			gBcPTsyoeP = new Dictionary<string, lHyiuRpvRLKBqfyHe9>(6);
			oHQ11ILeLc = ((P_3 < 20) ? 20 : P_3);
			dtP1s0swCI = new Dictionary<string, V6PGe1R884NJ3GD2LA>();
			S6L10aXiP7 = new Dictionary<V6PGe1R884NJ3GD2LA, int>();
			kQ91rKhySF = string.Empty;
			lio177cPPu = (XRbgaoKmn16bImAki0)0;
			D0DPzW6gWA = new Dictionary<string, lHyiuRpvRLKBqfyHe9>();
			Xax1PosHZj = false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void EWxPnB3NFu(IBSTRCollection P_0)
		{
			try
			{
				lkZPBaUPt2.Clear();
				NXV1HyEJw3 = P_0;
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void y84Pe6Ztkb()
		{
			if (NXV1HyEJw3 == null)
			{
				return;
			}
			SortedDictionary<string, lHyiuRpvRLKBqfyHe9> sortedDictionary = new SortedDictionary<string, lHyiuRpvRLKBqfyHe9>();
			for (int i = 1; i <= NXV1HyEJw3.Count; i++)
			{
				string key = NXV1HyEJw3.get_Item(i);
				try
				{
					lHyiuRpvRLKBqfyHe9 lHyiuRpvRLKBqfyHe = D0DPzW6gWA[key];
					if (!ewqjA30Ig7KglKlcHq.PnhaJXRto(lHyiuRpvRLKBqfyHe))
					{
						StringBuilder stringBuilder = new StringBuilder(lHyiuRpvRLKBqfyHe.A46rwSBvbY);
						stringBuilder.Append(lHyiuRpvRLKBqfyHe.s7drXicJ9m);
						stringBuilder.Append(lHyiuRpvRLKBqfyHe.VaDrxUe24c);
						sortedDictionary.Add(stringBuilder.ToString(), lHyiuRpvRLKBqfyHe);
					}
				}
				catch
				{
				}
			}
			SortedDictionary<string, lHyiuRpvRLKBqfyHe9>.Enumerator enumerator = sortedDictionary.GetEnumerator();
			while (enumerator.MoveNext() && RiuP6RvRLK())
			{
				lkZPBaUPt2.Add(enumerator.Current.Value.aaYrcWlA7H, enumerator.Current.Value);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void GxcPFYiZjf(out Dictionary<string, lHyiuRpvRLKBqfyHe9> P_0, out Dictionary<string, lHyiuRpvRLKBqfyHe9> P_1)
		{
			P_0 = MCm1cwkivw;
			P_1 = uve1I8GjYR;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Ko0Pp7PcI8(bool P_0)
		{
			((Control)NLm1dLDt5c).Enabled = P_0;
			((Control)gHl1aN99tY).Enabled = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Dispose(bool P_0)
		{
			if (P_0 && a1V1Xk8c73 != null)
			{
				a1V1Xk8c73.Dispose();
			}
			((Form)this).Dispose(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void gp9Pv2IPGD()
		{
			//IL_0023: Unknown result type (might be due to invalid IL or missing references)
			//IL_002d: Expected O, but got Unknown
			//IL_002e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0038: Expected O, but got Unknown
			//IL_0039: Unknown result type (might be due to invalid IL or missing references)
			//IL_0043: Expected O, but got Unknown
			//IL_0044: Unknown result type (might be due to invalid IL or missing references)
			//IL_004e: Expected O, but got Unknown
			//IL_004f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0059: Expected O, but got Unknown
			//IL_005a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0064: Expected O, but got Unknown
			//IL_0065: Unknown result type (might be due to invalid IL or missing references)
			//IL_006f: Expected O, but got Unknown
			//IL_0086: Unknown result type (might be due to invalid IL or missing references)
			//IL_0090: Expected O, but got Unknown
			//IL_0091: Unknown result type (might be due to invalid IL or missing references)
			//IL_009b: Expected O, but got Unknown
			//IL_009c: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a6: Expected O, but got Unknown
			//IL_00a7: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b1: Expected O, but got Unknown
			//IL_00b8: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c2: Expected O, but got Unknown
			//IL_00c9: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d3: Expected O, but got Unknown
			//IL_061e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0628: Expected O, but got Unknown
			//IL_0ae7: Unknown result type (might be due to invalid IL or missing references)
			//IL_0af1: Expected O, but got Unknown
			//IL_0b47: Unknown result type (might be due to invalid IL or missing references)
			//IL_0b51: Expected O, but got Unknown
			//IL_0b59: Unknown result type (might be due to invalid IL or missing references)
			//IL_0b63: Expected O, but got Unknown
			a1V1Xk8c73 = new Container();
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(QH6UkVcfudxA5A7qRi));
			Iek1x3wMlM = new Button();
			QF81ogbUsq = new Button();
			uJ61wfsfsX = new Button();
			vZg1gsVZrn = new TextBox();
			A0P18661f1 = new Button();
			NLm1dLDt5c = new ComboBox();
			thR1kebTii = new GroupBox();
			dUE1ZJqxBb = new C1FlexGrid();
			hoi1EdNhJs = new C1FlexGrid();
			NGp13PU5lG = new GroupBox();
			gHl1aN99tY = new DomainUpDown();
			utd1MR7quT = new Button();
			sU119kbZbQ = new Button();
			D1q16u5crK = new ToolTip(a1V1Xk8c73);
			zDF1ObPMLi = new ToolTip(a1V1Xk8c73);
			((Control)thR1kebTii).SuspendLayout();
			((ISupportInitialize)dUE1ZJqxBb).BeginInit();
			((ISupportInitialize)hoi1EdNhJs).BeginInit();
			((Control)NGp13PU5lG).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)Iek1x3wMlM).Location = new Point(141, 479);
			((Control)Iek1x3wMlM).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(2124);
			((Control)Iek1x3wMlM).Size = new Size(100, 26);
			((Control)Iek1x3wMlM).TabIndex = 1;
			((Control)Iek1x3wMlM).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(2144);
			((ButtonBase)Iek1x3wMlM).UseVisualStyleBackColor = true;
			((Control)Iek1x3wMlM).Click += a6bPcImAki;
			((Control)QF81ogbUsq).Location = new Point(290, 130);
			((Control)QF81ogbUsq).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(2152);
			((Control)QF81ogbUsq).Size = new Size(113, 24);
			((Control)QF81ogbUsq).TabIndex = 0;
			((Control)QF81ogbUsq).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(2170);
			((ButtonBase)QF81ogbUsq).UseVisualStyleBackColor = true;
			((Control)QF81ogbUsq).Click += dpJPXi4bIZ;
			((Control)uJ61wfsfsX).Location = new Point(290, 204);
			((Control)uJ61wfsfsX).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(2176);
			((Control)uJ61wfsfsX).Size = new Size(113, 24);
			((Control)uJ61wfsfsX).TabIndex = 1;
			((Control)uJ61wfsfsX).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(2200);
			((ButtonBase)uJ61wfsfsX).UseVisualStyleBackColor = true;
			((Control)uJ61wfsfsX).Click += CYcPxPuwrR;
			((TextBoxBase)vZg1gsVZrn).BorderStyle = (BorderStyle)0;
			((Control)vZg1gsVZrn).Location = new Point(23, 27);
			((TextBoxBase)vZg1gsVZrn).Multiline = true;
			((Control)vZg1gsVZrn).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(2206);
			((TextBoxBase)vZg1gsVZrn).ReadOnly = true;
			vZg1gsVZrn.ScrollBars = (ScrollBars)2;
			((Control)vZg1gsVZrn).Size = new Size(636, 43);
			((Control)vZg1gsVZrn).TabIndex = 0;
			((Control)vZg1gsVZrn).TabStop = false;
			A0P18661f1.DialogResult = (DialogResult)2;
			((Control)A0P18661f1).Location = new Point(288, 479);
			((Control)A0P18661f1).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(2242);
			((Control)A0P18661f1).Size = new Size(111, 26);
			((Control)A0P18661f1).TabIndex = 2;
			((Control)A0P18661f1).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(2266);
			((ButtonBase)A0P18661f1).UseVisualStyleBackColor = true;
			((Control)A0P18661f1).Click += TSfPdqh2IX;
			NLm1dLDt5c.AutoCompleteMode = (AutoCompleteMode)1;
			NLm1dLDt5c.AutoCompleteSource = (AutoCompleteSource)256;
			NLm1dLDt5c.DropDownStyle = (ComboBoxStyle)2;
			((ListControl)NLm1dLDt5c).FormattingEnabled = true;
			NLm1dLDt5c.Items.AddRange(new object[4]
			{
				MnxsD0lrg8kZaUPt2I.OPAImF4404(2282),
				MnxsD0lrg8kZaUPt2I.OPAImF4404(2310),
				MnxsD0lrg8kZaUPt2I.OPAImF4404(2326),
				MnxsD0lrg8kZaUPt2I.OPAImF4404(2342)
			});
			((Control)NLm1dLDt5c).Location = new Point(153, 36);
			((Control)NLm1dLDt5c).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(2354);
			((Control)NLm1dLDt5c).Size = new Size(140, 21);
			((Control)NLm1dLDt5c).TabIndex = 1;
			((Control)thR1kebTii).Controls.Add((Control)(object)dUE1ZJqxBb);
			((Control)thR1kebTii).Controls.Add((Control)(object)hoi1EdNhJs);
			((Control)thR1kebTii).Controls.Add((Control)(object)NGp13PU5lG);
			((Control)thR1kebTii).Controls.Add((Control)(object)vZg1gsVZrn);
			((Control)thR1kebTii).Controls.Add((Control)(object)uJ61wfsfsX);
			((Control)thR1kebTii).Controls.Add((Control)(object)QF81ogbUsq);
			((Control)thR1kebTii).Location = new Point(16, 16);
			((Control)thR1kebTii).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(2386);
			((Control)thR1kebTii).Size = new Size(680, 397);
			((Control)thR1kebTii).TabIndex = 17;
			thR1kebTii.TabStop = false;
			((Control)thR1kebTii).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(2426);
			dUE1ZJqxBb.BorderStyle = C1.Win.C1FlexGrid.Util.BaseControls.BorderStyleEnum.FixedSingle;
			dUE1ZJqxBb.ColumnInfo = MnxsD0lrg8kZaUPt2I.OPAImF4404(2470);
			((Control)dUE1ZJqxBb).Location = new Point(6, 86);
			((Control)dUE1ZJqxBb).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(2518);
			dUE1ZJqxBb.Rows.DefaultSize = 17;
			((Control)dUE1ZJqxBb).Size = new Size(217, 253);
			((Control)dUE1ZJqxBb).TabIndex = 1;
			dUE1ZJqxBb.AfterSelChange += Jk7P0eb8B6;
			((Control)dUE1ZJqxBb).MouseMove += new MouseEventHandler(aYuP7Bca9I);
			((Control)dUE1ZJqxBb).DoubleClick += e0jPsT1r1w;
			hoi1EdNhJs.BorderStyle = C1.Win.C1FlexGrid.Util.BaseControls.BorderStyleEnum.FixedSingle;
			hoi1EdNhJs.ColumnInfo = MnxsD0lrg8kZaUPt2I.OPAImF4404(2554);
			((Control)hoi1EdNhJs).Location = new Point(420, 86);
			((Control)hoi1EdNhJs).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(2628);
			hoi1EdNhJs.Rows.DefaultSize = 17;
			hoi1EdNhJs.ScrollBars = (ScrollBars)1;
			((Control)hoi1EdNhJs).Size = new Size(206, 253);
			((Control)hoi1EdNhJs).TabIndex = 0;
			hoi1EdNhJs.AfterSelChange += XRbPIgaomn;
			((Control)hoi1EdNhJs).DoubleClick += ilTPrwe33U;
			((Control)NGp13PU5lG).Controls.Add((Control)(object)gHl1aN99tY);
			((Control)NGp13PU5lG).Controls.Add((Control)(object)NLm1dLDt5c);
			((Control)NGp13PU5lG).Location = new Point(173, 309);
			((Control)NGp13PU5lG).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(2668);
			((Control)NGp13PU5lG).Size = new Size(312, 76);
			((Control)NGp13PU5lG).TabIndex = 18;
			NGp13PU5lG.TabStop = false;
			((Control)NGp13PU5lG).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(2710);
			((ArrayList)(object)gHl1aN99tY.Items).Add((object?)MnxsD0lrg8kZaUPt2I.OPAImF4404(2776));
			((ArrayList)(object)gHl1aN99tY.Items).Add((object?)MnxsD0lrg8kZaUPt2I.OPAImF4404(2782));
			((ArrayList)(object)gHl1aN99tY.Items).Add((object?)MnxsD0lrg8kZaUPt2I.OPAImF4404(2788));
			((ArrayList)(object)gHl1aN99tY.Items).Add((object?)MnxsD0lrg8kZaUPt2I.OPAImF4404(2794));
			((ArrayList)(object)gHl1aN99tY.Items).Add((object?)MnxsD0lrg8kZaUPt2I.OPAImF4404(2800));
			((ArrayList)(object)gHl1aN99tY.Items).Add((object?)MnxsD0lrg8kZaUPt2I.OPAImF4404(2806));
			((ArrayList)(object)gHl1aN99tY.Items).Add((object?)MnxsD0lrg8kZaUPt2I.OPAImF4404(2812));
			((ArrayList)(object)gHl1aN99tY.Items).Add((object?)MnxsD0lrg8kZaUPt2I.OPAImF4404(2818));
			((ArrayList)(object)gHl1aN99tY.Items).Add((object?)MnxsD0lrg8kZaUPt2I.OPAImF4404(2824));
			((ArrayList)(object)gHl1aN99tY.Items).Add((object?)MnxsD0lrg8kZaUPt2I.OPAImF4404(2830));
			((Control)gHl1aN99tY).Location = new Point(16, 36);
			((Control)gHl1aN99tY).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(2838);
			((Control)gHl1aN99tY).Size = new Size(116, 20);
			((Control)gHl1aN99tY).TabIndex = 0;
			((Control)gHl1aN99tY).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(2876);
			gHl1aN99tY.Wrap = true;
			((Control)gHl1aN99tY).Leave += ioaP8kDxeC;
			((Control)gHl1aN99tY).Enter += HUvPgyIadP;
			((Control)utd1MR7quT).Location = new Point(454, 479);
			((Control)utd1MR7quT).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(2882);
			((Control)utd1MR7quT).Size = new Size(106, 26);
			((Control)utd1MR7quT).TabIndex = 3;
			((Control)utd1MR7quT).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(2902);
			((ButtonBase)utd1MR7quT).UseVisualStyleBackColor = true;
			((Control)utd1MR7quT).Click += OUyP3uMNi4;
			((Control)sU119kbZbQ).Location = new Point(288, 426);
			((Control)sU119kbZbQ).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(2914);
			((Control)sU119kbZbQ).Size = new Size(113, 32);
			((Control)sU119kbZbQ).TabIndex = 4;
			((Control)sU119kbZbQ).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(2938);
			((ButtonBase)sU119kbZbQ).UseVisualStyleBackColor = true;
			((Control)sU119kbZbQ).Click += JLGPkQpqCf;
			((ContainerControl)this).AutoScaleMode = (AutoScaleMode)3;
			((Form)this).CancelButton = (IButtonControl)(object)A0P18661f1;
			((Form)this).ClientSize = new Size(717, 520);
			((Control)this).Controls.Add((Control)(object)sU119kbZbQ);
			((Control)this).Controls.Add((Control)(object)utd1MR7quT);
			((Control)this).Controls.Add((Control)(object)A0P18661f1);
			((Control)this).Controls.Add((Control)(object)Iek1x3wMlM);
			((Control)this).Controls.Add((Control)(object)thR1kebTii);
			((Form)this).FormBorderStyle = (FormBorderStyle)1;
			((Form)this).Icon = (Icon)componentResourceManager.GetObject(MnxsD0lrg8kZaUPt2I.OPAImF4404(2954));
			((Form)this).MaximizeBox = false;
			((Form)this).MinimizeBox = false;
			((Control)this).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(2978);
			((Form)this).SizeGripStyle = (SizeGripStyle)2;
			((Form)this).StartPosition = (FormStartPosition)1;
			((Control)this).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(3040);
			((Form)this).Load += jfEzN6lv1;
			((Form)this).FormClosing += new FormClosingEventHandler(auiPPDQYy7);
			((Control)this).HelpRequested += new HelpEventHandler(qwcP1ljFb2);
			((Control)thR1kebTii).ResumeLayout(false);
			((Control)thR1kebTii).PerformLayout();
			((ISupportInitialize)dUE1ZJqxBb).EndInit();
			((ISupportInitialize)hoi1EdNhJs).EndInit();
			((Control)NGp13PU5lG).ResumeLayout(false);
			((Control)this).ResumeLayout(false);
		}
	}
}
namespace nMh7lew5PoYBfLBVLL
{
	[Guid("390B039E-51FB-4fc0-BEAA-6482A181DF2B")]
	internal sealed class xJXRtoo1hkZNIY6u3D : Form, IHelpInformation
	{
		private const uint HyFstI8Ef5 = 64u;

		private const long Li6sq2VjGA = 1000L;

		private const string NSxsNOABEW = ".elf";

		private const string fCZshQAZOt = ".prp";

		private const string ILbs5sf3RY = ".log";

		private object NoVsbTVoMJ;

		private object tLFsU6OH7W;

		private LocalizedStringProvider BdxsD3E0CU;

		private IMonitorManager B9hsKgTiVK;

		private QH6UkVcfudxA5A7qRi FkusVqaffY;

		private Dictionary<int, Dictionary<long, lHyiuRpvRLKBqfyHe9>> Rqms4etUL2;

		private Gu5846fZtkbFxcYiZj V7jsnU86XY;

		private z270jTU1r1wLk7eb8B qa3seIbW6M;

		private XRbgaoKmn16bImAki0 WX2sFF9TnD;

		private bool xcSspmGMTT;

		private double atnsvLenHe;

		private x2IXLLeGQpqCfCUyuM zcVsG4b7hp;

		private long fD5sLwMkOr;

		private string tcfsRCC834;

		private DateTime aGCsjKggK6;

		private bool RRns2cv9b4;

		private HyN0of5EN6lv1IdeFn jXKsmdP0xa;

		private IErrorDisplay Gc0sfg7q6E;

		private IContextSensitiveHelpProvider MbjsC6cPIx;

		private IDMLLogFileConverter rywsWZc2ft;

		private System.Timers.Timer KCisSJL3Z0;

		private VqmdxqdVZK2wuuCkmX TILsyPR2y2;

		private long Enrsi68fPj;

		private System.Timers.Timer ovvsA32TDW;

		private IContainer CVBsQn4cSc;

		private MenuStrip a0usuURYwJ;

		private ToolStripMenuItem cLqsYMvHlQ;

		private ToolStripMenuItem yf0slmcCq3;

		private ToolStripMenuItem GSKsJ6ZZQx;

		private ToolStripMenuItem DaesBwbyjq;

		private ToolStripMenuItem IYAsTLSjEt;

		private ToolStripMenuItem iXwszvAQFQ;

		private ToolStripMenuItem F130Hg3MDZ;

		private ToolStripMenuItem d0E0PclwlM;

		private ToolStripMenuItem NS401njn0g;

		private ToolStripMenuItem aYD0sk70Zk;

		private ToolStripMenuItem S5T0022a2p;

		private ToolStripMenuItem SnS07JKTZ0;

		private ToolStripMenuItem aJm0rp73YG;

		private ToolStripMenuItem Qin0IhexpS;

		private ToolStripMenuItem VZx0c6PVcF;

		private ToolStripMenuItem ioU0XUScqq;

		private ToolStripMenuItem MFV0xR3e42;

		private ToolStripMenuItem xkh0ouN23J;

		private ToolStripStatusLabel C970wPxyMU;

		private ToolStripMenuItem VNv0g569Q4;

		Guid IHelpInformation.GUID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ((object)this).GetType().GUID;
			}
		}

		[DllImport("user32.dll", EntryPoint = "MessageBeep")]
		private static extern void TqW1tUkwT5(uint P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		public xJXRtoo1hkZNIY6u3D()
		{
			JmLDt5P0cahRebTiifG.LYav19NzXHLb9();
			((Form)this)..ctor();
			PK6sMCvH7W();
			BdxsD3E0CU = (LocalizedStringProvider)Factory.CreateInstance<ILocalizedStringProvider>();
			BdxsD3E0CU.Initialize(MnxsD0lrg8kZaUPt2I.OPAImF4404(3078));
			NoVsbTVoMJ = null;
			tLFsU6OH7W = null;
			Gc0sfg7q6E = null;
			MbjsC6cPIx = null;
			rywsWZc2ft = null;
			B9hsKgTiVK = null;
			FkusVqaffY = null;
			Rqms4etUL2 = null;
			V7jsnU86XY = null;
			qa3seIbW6M = (z270jTU1r1wLk7eb8B)2;
			WX2sFF9TnD = (XRbgaoKmn16bImAki0)0;
			xcSspmGMTT = false;
			atnsvLenHe = 0.0;
			zcVsG4b7hp = (x2IXLLeGQpqCfCUyuM)0;
			fD5sLwMkOr = 1000L;
			tcfsRCC834 = string.Empty;
			RRns2cv9b4 = false;
			jXKsmdP0xa = (HyN0of5EN6lv1IdeFn)0;
			Rqms4etUL2 = new Dictionary<int, Dictionary<long, lHyiuRpvRLKBqfyHe9>>();
			KCisSJL3Z0 = new System.Timers.Timer();
			KCisSJL3Z0.Elapsed += U5s1RwW4QT;
			ovvsA32TDW = new System.Timers.Timer();
			ovvsA32TDW.Enabled = false;
			ovvsA32TDW.Interval = 500.0;
			ovvsA32TDW.Elapsed += HwD1WaN9Sw;
			Hoc1UGxdya();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void xm71q0Gso5(MonitoredParameterCollection P_0)
		{
			atnsvLenHe += 1.0;
			for (int i = 0; i < P_0.Count; i++)
			{
				try
				{
					P_0.GetParameterInfo(i, out var ModuleId, out var ParameterId, out var _, out var RawValue);
					V7jsnU86XY.gKUrJZLcuM(Rqms4etUL2[ModuleId][ParameterId].yYErdkWprd, atnsvLenHe, RawValue);
					RRns2cv9b4 = true;
				}
				catch
				{
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void dRp1NQEc9X(object P_0, JCTT6V2WOmvGFmVhhn P_1)
		{
			switch (P_1.yN7r3b3xCA())
			{
			case (FWcKfcGWl7hhTBulZY)1:
				c6s1QIEgmk();
				V7jsnU86XY.EKdIH450L6(true);
				zcVsG4b7hp = (x2IXLLeGQpqCfCUyuM)3;
				break;
			case (FWcKfcGWl7hhTBulZY)2:
				G1J1uSU90t();
				zcVsG4b7hp = (x2IXLLeGQpqCfCUyuM)4;
				break;
			case (FWcKfcGWl7hhTBulZY)3:
				GEHsXZu7c2(this, null);
				break;
			case (FWcKfcGWl7hhTBulZY)4:
				aPv1jdAt8R();
				break;
			}
			xIb1VKLY1Z();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void jqR1hVZ1jy(Dictionary<string, lHyiuRpvRLKBqfyHe9> addedParams, Dictionary<string, lHyiuRpvRLKBqfyHe9> removedParams)
		{
			Dictionary<string, lHyiuRpvRLKBqfyHe9>.Enumerator enumerator = removedParams.GetEnumerator();
			while (enumerator.MoveNext())
			{
				lHyiuRpvRLKBqfyHe9 value = enumerator.Current.Value;
				Rqms4etUL2[value.VaDrxUe24c].Remove(value.s7drXicJ9m);
				B9hsKgTiVK.RemoveMonitoredParameter(value.s7drXicJ9m.ToString(), value.VaDrxUe24c);
				Tbs1K8H4RH(value, false);
			}
			Dictionary<string, lHyiuRpvRLKBqfyHe9>.Enumerator enumerator2 = addedParams.GetEnumerator();
			while (enumerator2.MoveNext())
			{
				lHyiuRpvRLKBqfyHe9 value2 = enumerator2.Current.Value;
				if (!Rqms4etUL2.ContainsKey(value2.VaDrxUe24c))
				{
					Rqms4etUL2.Add(value2.VaDrxUe24c, new Dictionary<long, lHyiuRpvRLKBqfyHe9>());
				}
				if (!Rqms4etUL2[value2.VaDrxUe24c].ContainsKey(value2.s7drXicJ9m))
				{
					value2 = Tbs1K8H4RH(value2, true);
					Rqms4etUL2[value2.VaDrxUe24c].Add(value2.s7drXicJ9m, value2);
					B9hsKgTiVK.AddMonitoredParameter(value2.s7drXicJ9m.ToString(), value2.VaDrxUe24c);
				}
			}
			if (zcVsG4b7hp == (x2IXLLeGQpqCfCUyuM)1 && Rqms4etUL2.Count > 0)
			{
				zcVsG4b7hp = (x2IXLLeGQpqCfCUyuM)2;
				xIb1VKLY1Z();
			}
			else if (zcVsG4b7hp == (x2IXLLeGQpqCfCUyuM)3)
			{
				V7jsnU86XY.EKdIH450L6(true);
			}
			rXH15Rlkor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void rXH15Rlkor()
		{
			if (WX2sFF9TnD == (XRbgaoKmn16bImAki0)0)
			{
				if (FkusVqaffY != null)
				{
					fD5sLwMkOr = FkusVqaffY.lPIPGGTZwp();
				}
				B9hsKgTiVK.SamplingRate = fD5sLwMkOr;
				V7jsnU86XY.cvYrBdIfgr();
				Kv01vSJ3Zp();
				((Control)this).Text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)100);
			}
			else
			{
				((Control)this).Text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)100) + MnxsD0lrg8kZaUPt2I.OPAImF4404(3152) + Path.GetFileName(tcfsRCC834);
			}
			LgM1bqbF8a();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void LgM1bqbF8a()
		{
			if (V7jsnU86XY != null)
			{
				V7jsnU86XY.m1nruZuJjC(aak1FXNa6F());
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Hoc1UGxdya()
		{
			((ToolStripItem)cLqsYMvHlQ).Text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)210);
			((ToolStripItem)yf0slmcCq3).Text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)212);
			((ToolStripItem)GSKsJ6ZZQx).Text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)217);
			((ToolStripItem)DaesBwbyjq).Text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)230);
			((ToolStripItem)IYAsTLSjEt).Text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)232);
			((ToolStripItem)iXwszvAQFQ).Text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)231);
			((ToolStripItem)F130Hg3MDZ).Text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)220);
			((ToolStripItem)d0E0PclwlM).Text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)221);
			((ToolStripItem)NS401njn0g).Text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)240);
			((ToolStripItem)aYD0sk70Zk).Text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)241);
			((ToolStripItem)S5T0022a2p).Text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)242);
			((ToolStripItem)SnS07JKTZ0).Text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)222);
			((ToolStripItem)aJm0rp73YG).Text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)213);
			((ToolStripItem)Qin0IhexpS).Text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)211);
			((ToolStripItem)VZx0c6PVcF).Text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)250);
			((ToolStripItem)xkh0ouN23J).Text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)251);
			((ToolStripItem)ioU0XUScqq).Text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)216);
			((ToolStripItem)MFV0xR3e42).Text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)215);
			((ToolStripItem)VNv0g569Q4).Text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)1101);
			((ToolStripItem)GSKsJ6ZZQx).Click += MexssOPN6u;
			((ToolStripItem)d0E0PclwlM).Click += GEHsXZu7c2;
			((ToolStripItem)SnS07JKTZ0).Click += BOHsxYZEu0;
			((ToolStripItem)IYAsTLSjEt).Click += M1LswxOtqC;
			IYAsTLSjEt.CheckOnClick = true;
			((ToolStripItem)iXwszvAQFQ).Click += HKIsgVBgRS;
			iXwszvAQFQ.CheckOnClick = true;
			((ToolStripItem)aYD0sk70Zk).Click += v0Vsd22Ev1;
			((ToolStripItem)S5T0022a2p).Click += gCOs82O4Vu;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Ioh1DvIEVs()
		{
			if (Rqms4etUL2.Count <= 0)
			{
				return;
			}
			Dictionary<int, Dictionary<long, lHyiuRpvRLKBqfyHe9>> dictionary = new Dictionary<int, Dictionary<long, lHyiuRpvRLKBqfyHe9>>();
			Dictionary<int, Dictionary<long, lHyiuRpvRLKBqfyHe9>>.Enumerator enumerator = Rqms4etUL2.GetEnumerator();
			while (enumerator.MoveNext())
			{
				dictionary.Add(enumerator.Current.Key, new Dictionary<long, lHyiuRpvRLKBqfyHe9>());
				Dictionary<long, lHyiuRpvRLKBqfyHe9>.Enumerator enumerator2 = enumerator.Current.Value.GetEnumerator();
				while (enumerator2.MoveNext())
				{
					lHyiuRpvRLKBqfyHe9 lHyiuRpvRLKBqfyHe = Rqms4etUL2[enumerator.Current.Key][enumerator2.Current.Key];
					lHyiuRpvRLKBqfyHe = Tbs1K8H4RH(lHyiuRpvRLKBqfyHe, true);
					dictionary[enumerator.Current.Key].Add(lHyiuRpvRLKBqfyHe.s7drXicJ9m, lHyiuRpvRLKBqfyHe);
				}
			}
			Rqms4etUL2 = dictionary;
			zcVsG4b7hp = (x2IXLLeGQpqCfCUyuM)2;
			xIb1VKLY1Z();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private lHyiuRpvRLKBqfyHe9 Tbs1K8H4RH(lHyiuRpvRLKBqfyHe9 P_0, bool P_1)
		{
			if (xcSspmGMTT)
			{
				P_0.yYErdkWprd = ewqjA30Ig7KglKlcHq.Jm4xRb6lj(P_0);
				if (P_1)
				{
					V7jsnU86XY.AddChannel(P_0.yYErdkWprd, P_0.zK4rgN7EmU);
				}
				else
				{
					V7jsnU86XY.RemoveChannel(P_0.yYErdkWprd);
				}
			}
			return P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void xIb1VKLY1Z()
		{
			bool flag = false;
			bool flag2 = false;
			bool flag3 = true;
			bool flag4 = true;
			switch (zcVsG4b7hp)
			{
			case (x2IXLLeGQpqCfCUyuM)0:
				flag3 = false;
				break;
			case (x2IXLLeGQpqCfCUyuM)2:
			case (x2IXLLeGQpqCfCUyuM)4:
				flag = true;
				break;
			case (x2IXLLeGQpqCfCUyuM)3:
				flag2 = true;
				flag4 = false;
				break;
			case (x2IXLLeGQpqCfCUyuM)5:
				flag3 = false;
				break;
			}
			((ToolStripItem)aYD0sk70Zk).Enabled = flag && flag3;
			((ToolStripItem)S5T0022a2p).Enabled = flag2 && flag3;
			((ToolStripItem)aJm0rp73YG).Enabled = RRns2cv9b4;
			((ToolStripItem)SnS07JKTZ0).Enabled = flag4;
			((ToolStripItem)VNv0g569Q4).Enabled = flag4;
			((ToolStripItem)IYAsTLSjEt).Enabled = flag3;
			((ToolStripItem)iXwszvAQFQ).Enabled = flag3;
			if (V7jsnU86XY != null)
			{
				V7jsnU86XY.XWSrzoXW6U((FWcKfcGWl7hhTBulZY)1, flag && flag3);
				V7jsnU86XY.XWSrzoXW6U((FWcKfcGWl7hhTBulZY)2, flag2 && flag3);
				V7jsnU86XY.XWSrzoXW6U((FWcKfcGWl7hhTBulZY)4, flag4);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool nxT14MF1Hw(z270jTU1r1wLk7eb8B P_0, bool P_1)
		{
			//IL_005d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0063: Invalid comparison between Unknown and I4
			bool flag = false;
			if (xcSspmGMTT && (P_0 != qa3seIbW6M || P_1))
			{
				if (zcVsG4b7hp == (x2IXLLeGQpqCfCUyuM)3 && (int)MessageBox.Show(BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)601), BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)703), (MessageBoxButtons)4) != 6)
				{
					return false;
				}
				G1J1uSU90t();
				((Control)this).Controls.Remove((Control)(object)V7jsnU86XY);
				V7jsnU86XY = null;
				xcSspmGMTT = false;
				iPG1etZ463(P_0);
				Ioh1DvIEVs();
				rXH15Rlkor();
			}
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Kvp1nJwYjD()
		{
			bool flag = false;
			bool flag2 = false;
			if (WX2sFF9TnD == (XRbgaoKmn16bImAki0)1)
			{
				IYAsTLSjEt.Checked = false;
				iXwszvAQFQ.Checked = false;
				((ToolStripItem)IYAsTLSjEt).Enabled = false;
				((ToolStripItem)iXwszvAQFQ).Enabled = false;
				return;
			}
			switch (qa3seIbW6M)
			{
			case (z270jTU1r1wLk7eb8B)1:
				flag = true;
				break;
			case (z270jTU1r1wLk7eb8B)2:
				flag2 = true;
				break;
			}
			IYAsTLSjEt.Checked = flag;
			iXwszvAQFQ.Checked = flag2;
			((ToolStripItem)IYAsTLSjEt).Enabled = !flag;
			((ToolStripItem)iXwszvAQFQ).Enabled = !flag2;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void iPG1etZ463(z270jTU1r1wLk7eb8B P_0)
		{
			if (V7jsnU86XY == null)
			{
				qa3seIbW6M = P_0;
				V7jsnU86XY = hIlFMOAYll4OnUq4sH.TPUIjyu1KH(P_0, BdxsD3E0CU);
				V7jsnU86XY.GoxIXfyvru += dRp1NQEc9X;
				Control v7jsnU86XY = (Control)(object)V7jsnU86XY;
				v7jsnU86XY.Dock = (DockStyle)5;
				((Control)this).Controls.Remove((Control)(object)a0usuURYwJ);
				((Control)this).Controls.Add(v7jsnU86XY);
				((Control)this).Controls.Add((Control)(object)a0usuURYwJ);
				Kvp1nJwYjD();
				atnsvLenHe = 0.0;
			}
			if (xcSspmGMTT)
			{
				((Form)this).Activate();
				return;
			}
			((Control)this).Show();
			xcSspmGMTT = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string aak1FXNa6F()
		{
			string result = "";
			if (WX2sFF9TnD != (XRbgaoKmn16bImAki0)1)
			{
				if (Rqms4etUL2.Count == 0)
				{
					result = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)600);
				}
				else
				{
					IConnection connection = ((IECMServices)NoVsbTVoMJ).Connections.get_Item((object)((IECMServices)NoVsbTVoMJ).ActiveConnectionID);
					result = connection.System.Name;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void j5u1ppDvK0(XRbgaoKmn16bImAki0 P_0)
		{
			WX2sFF9TnD = P_0;
			switch (WX2sFF9TnD)
			{
			case (XRbgaoKmn16bImAki0)1:
				zcVsG4b7hp = (x2IXLLeGQpqCfCUyuM)5;
				xIb1VKLY1Z();
				nxT14MF1Hw((z270jTU1r1wLk7eb8B)2, true);
				break;
			case (XRbgaoKmn16bImAki0)0:
				zcVsG4b7hp = (x2IXLLeGQpqCfCUyuM)1;
				xIb1VKLY1Z();
				nxT14MF1Hw((z270jTU1r1wLk7eb8B)2, true);
				break;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Kv01vSJ3Zp()
		{
			int num;
			int num2;
			int num3;
			int num4;
			V6PGe1R884NJ3GD2LA v6PGe1R884NJ3GD2LA = ewqjA30Ig7KglKlcHq.DWO8lBx5F(fD5sLwMkOr, out num, out num2, out num3, out num4);
			int num5 = num;
			if (num5 == 0)
			{
				num5 = num2;
			}
			if (num5 == 0)
			{
				num5 = num3;
			}
			if (num5 == 0)
			{
				num5 = num4;
			}
			string text = MnxsD0lrg8kZaUPt2I.OPAImF4404(3162) + num5 + MnxsD0lrg8kZaUPt2I.OPAImF4404(3190) + v6PGe1R884NJ3GD2LA;
			if (V7jsnU86XY != null)
			{
				V7jsnU86XY.rVcrT9A4QX(text);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Jep1GiNkbR(string P_0)
		{
			string text = P_0.Replace(MnxsD0lrg8kZaUPt2I.OPAImF4404(3196), MnxsD0lrg8kZaUPt2I.OPAImF4404(3208));
			string text2 = P_0.Replace(MnxsD0lrg8kZaUPt2I.OPAImF4404(3220), MnxsD0lrg8kZaUPt2I.OPAImF4404(3232));
			Stream stream = ewqjA30Ig7KglKlcHq.tSv9vx2mM(P_0, text);
			Stream stream2 = ewqjA30Ig7KglKlcHq.tSv9vx2mM(P_0, text2);
			Rqms4etUL2.Clear();
			tcfsRCC834 = P_0;
			j5u1ppDvK0((XRbgaoKmn16bImAki0)1);
			V7jsnU86XY.INRrQsFllt(stream2);
			V7jsnU86XY.eAprynsGZd(stream);
			V7jsnU86XY.zv6I1o9cqn();
			V7jsnU86XY.guDIsN0BMo();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void WCR1LrYgCN()
		{
			B9hsKgTiVK = Factory.CreateInstance<IMonitorManager>();
			B9hsKgTiVK.Initialize(NoVsbTVoMJ, 0, 0);
			B9hsKgTiVK.OnDataUpdated += xm71q0Gso5;
			B9hsKgTiVK.NotificationTriggerType = NotificationTriggerType.Timer;
			B9hsKgTiVK.EnableLogging = true;
			B9hsKgTiVK.ClientContextInfo = ClientContextInfo.DML;
			B9hsKgTiVK.AddMonitoredParameter(MnxsD0lrg8kZaUPt2I.OPAImF4404(3244), 0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void U5s1RwW4QT(object P_0, ElapsedEventArgs P_1)
		{
			atnsvLenHe += 1.0;
			V7jsnU86XY.q7aI70UeMC(atnsvLenHe);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void aPv1jdAt8R()
		{
			//IL_000d: Unknown result type (might be due to invalid IL or missing references)
			((Form)TILsyPR2y2).ShowDialog();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void UyT120efXA()
		{
			//IL_00b4: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ba: Invalid comparison between Unknown and I4
			if (zcVsG4b7hp != (x2IXLLeGQpqCfCUyuM)3 || !TILsyPR2y2.EventMarkerEnabled)
			{
				return;
			}
			TqW1tUkwT5(64u);
			Enrsi68fPj++;
			q6X1msRdcn();
			kuN1fVWXga();
			B9hsKgTiVK.AddEventMarker(Enrsi68fPj);
			if (TILsyPR2y2.hgu0AZ1Am0())
			{
				juqL6KgOSNssTC0yia juqL6KgOSNssTC0yia = new juqL6KgOSNssTC0yia(BdxsD3E0CU, NoVsbTVoMJ, tLFsU6OH7W);
				juqL6KgOSNssTC0yia.zsm0567i5W(BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)1100) + MnxsD0lrg8kZaUPt2I.OPAImF4404(3250) + Enrsi68fPj);
				if ((int)((Form)juqL6KgOSNssTC0yia).ShowDialog() == 1)
				{
					B9hsKgTiVK.AddEventDescription(Enrsi68fPj, juqL6KgOSNssTC0yia.MtZ0tnbsLv());
				}
			}
			DT41CfTqE6();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void q6X1msRdcn()
		{
			((ToolStripItem)C970wPxyMU).Visible = true;
			((ToolStripItem)C970wPxyMU).Text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)1100) + MnxsD0lrg8kZaUPt2I.OPAImF4404(3256) + Enrsi68fPj;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void kuN1fVWXga()
		{
			ovvsA32TDW.Start();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void DT41CfTqE6()
		{
			ovvsA32TDW.Stop();
			q6X1msRdcn();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void HwD1WaN9Sw(object P_0, ElapsedEventArgs P_1)
		{
			if (string.IsNullOrEmpty(((ToolStripItem)C970wPxyMU).Text))
			{
				q6X1msRdcn();
			}
			else
			{
				((ToolStripItem)C970wPxyMU).Text = string.Empty;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void qCE1Sg0vcp(object P_0, object P_1, object P_2)
		{
			NoVsbTVoMJ = P_0;
			tLFsU6OH7W = P_1;
			Gc0sfg7q6E = Factory.CreateInstance<IErrorDisplay>();
			Gc0sfg7q6E.Initialize(tLFsU6OH7W, BdxsD3E0CU);
			try
			{
				MbjsC6cPIx = Factory.CreateInstance<IContextSensitiveHelpProvider>();
				MbjsC6cPIx.Initialize(NoVsbTVoMJ, tLFsU6OH7W);
				FkusVqaffY = new QH6UkVcfudxA5A7qRi(NoVsbTVoMJ, tLFsU6OH7W, P_2, fD5sLwMkOr, BdxsD3E0CU);
				ewqjA30Ig7KglKlcHq.ku8PGVh7n(NoVsbTVoMJ);
				zcVsG4b7hp = (x2IXLLeGQpqCfCUyuM)1;
				xIb1VKLY1Z();
				WCR1LrYgCN();
				TILsyPR2y2 = new VqmdxqdVZK2wuuCkmX(BdxsD3E0CU, NoVsbTVoMJ, tLFsU6OH7W);
			}
			catch
			{
				if (Gc0sfg7q6E != null)
				{
					Gc0sfg7q6E.DisplayError((d78MYpNQLCKwkS1VcZ)1000);
				}
				throw;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void QHv1y3MbV3()
		{
			if (B9hsKgTiVK != null)
			{
				((IDisposable)B9hsKgTiVK).Dispose();
				B9hsKgTiVK = null;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void BRT1iD6e7J()
		{
			//IL_0018: Unknown result type (might be due to invalid IL or missing references)
			//IL_001e: Invalid comparison between Unknown and I4
			try
			{
				if (!xcSspmGMTT && (int)((Form)FkusVqaffY).ShowDialog() == 1)
				{
					iXwszvAQFQ.Checked = true;
					iPG1etZ463((z270jTU1r1wLk7eb8B)2);
				}
			}
			catch (Exception)
			{
				if (Gc0sfg7q6E != null)
				{
					Gc0sfg7q6E.DisplayError((d78MYpNQLCKwkS1VcZ)1000);
				}
				throw;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public bool uMss9O9eY4()
		{
			return xcSspmGMTT;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void yHk1ALpFVG(object P_0)
		{
			try
			{
				if (!xcSspmGMTT && P_0 != null)
				{
					FkusVqaffY.EWxPnB3NFu((IBSTRCollection)P_0);
				}
			}
			catch
			{
				if (Gc0sfg7q6E != null)
				{
					Gc0sfg7q6E.DisplayError((d78MYpNQLCKwkS1VcZ)1000);
				}
				throw;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public void HfcsOe8ptR(HyN0of5EN6lv1IdeFn P_0)
		{
			jXKsmdP0xa = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public x2IXLLeGQpqCfCUyuM jA7sZ3Nqk6()
		{
			return zcVsG4b7hp;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void c6s1QIEgmk()
		{
			if (Rqms4etUL2.Count > 0 && zcVsG4b7hp != (x2IXLLeGQpqCfCUyuM)3)
			{
				Dictionary<string, string> dictionary = ewqjA30Ig7KglKlcHq.U3DEkMh7l();
				dictionary.Add(MnxsD0lrg8kZaUPt2I.OPAImF4404(3264), fD5sLwMkOr.ToString());
				dictionary.Add(MnxsD0lrg8kZaUPt2I.OPAImF4404(3292), "");
				B9hsKgTiVK.SetLogFileHeader(dictionary);
				aGCsjKggK6 = DateTime.Now;
				B9hsKgTiVK.StartMonitoring();
				V7jsnU86XY.mUOrY8Vp38();
				zcVsG4b7hp = (x2IXLLeGQpqCfCUyuM)3;
				xIb1VKLY1Z();
				if (TILsyPR2y2.EventMarkerEnabled)
				{
					q6X1msRdcn();
				}
				RRns2cv9b4 = true;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void G1J1uSU90t()
		{
			if (zcVsG4b7hp == (x2IXLLeGQpqCfCUyuM)3)
			{
				V7jsnU86XY.omrrlajOOy();
				B9hsKgTiVK.StopMonitoring();
				zcVsG4b7hp = (x2IXLLeGQpqCfCUyuM)4;
				xIb1VKLY1Z();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void lN41YbCgkG()
		{
			V7jsnU86XY.PWLI0Uflam(atnsvLenHe);
			KCisSJL3Z0.Interval = fD5sLwMkOr;
			KCisSJL3Z0.Start();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void OcT1lyYLs4()
		{
			KCisSJL3Z0.Stop();
			V7jsnU86XY.PWLI0Uflam(atnsvLenHe + 1.0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void mJZ1JdBInh()
		{
			//IL_0049: Unknown result type (might be due to invalid IL or missing references)
			//IL_004f: Invalid comparison between Unknown and I4
			//IL_005f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0065: Expected O, but got Unknown
			//IL_00b2: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b8: Invalid comparison between Unknown and I4
			//IL_0143: Unknown result type (might be due to invalid IL or missing references)
			//IL_014a: Expected O, but got Unknown
			//IL_019c: Unknown result type (might be due to invalid IL or missing references)
			//IL_01a2: Invalid comparison between Unknown and I4
			bool flag = false;
			flag = ((TILsyPR2y2.EventMarkerEnabled && Enrsi68fPj > 0) ? true : false);
			HTeX8Irfapx2F2XE6d hTeX8Irfapx2F2XE6d = new HTeX8Irfapx2F2XE6d(BdxsD3E0CU, NoVsbTVoMJ, tLFsU6OH7W, flag);
			if ((int)((Form)hTeX8Irfapx2F2XE6d).ShowDialog() != 2)
			{
				if (hTeX8Irfapx2F2XE6d.kdmCNAEG0() == (MuZSd846qSL8CEOpUv)0)
				{
					SaveFileDialog val = new SaveFileDialog();
					((FileDialog)val).Title = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)700);
					((FileDialog)val).Filter = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)502);
					((FileDialog)val).InitialDirectory = ewqjA30Ig7KglKlcHq.F2XgE6dCb();
					((FileDialog)val).FileName = ewqjA30Ig7KglKlcHq.h8Iwfapx2();
					if ((int)((CommonDialog)val).ShowDialog() == 1)
					{
						string fileName = ((FileDialog)val).FileName;
						string text = fileName.Replace(MnxsD0lrg8kZaUPt2I.OPAImF4404(3324), MnxsD0lrg8kZaUPt2I.OPAImF4404(3336));
						string text2 = fileName.Replace(MnxsD0lrg8kZaUPt2I.OPAImF4404(3348), MnxsD0lrg8kZaUPt2I.OPAImF4404(3360));
						V7jsnU86XY.GLErWoeWDq(text);
						V7jsnU86XY.c5NriO30TD(text2);
						ewqjA30Ig7KglKlcHq.nVLMZejdy(new string[2] { text, text2 }, fileName);
					}
				}
				else if (hTeX8Irfapx2F2XE6d.kdmCNAEG0() == (MuZSd846qSL8CEOpUv)1)
				{
					SaveFileDialog val2 = new SaveFileDialog();
					((FileDialog)val2).Title = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)701);
					((FileDialog)val2).Filter = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)501);
					((FileDialog)val2).InitialDirectory = ewqjA30Ig7KglKlcHq.F2XgE6dCb();
					((FileDialog)val2).FileName = ewqjA30Ig7KglKlcHq.h8Iwfapx2();
					if ((int)((CommonDialog)val2).ShowDialog() == 1)
					{
						string text3 = Path.Combine(Path.GetTempPath(), Path.GetFileNameWithoutExtension(((FileDialog)val2).FileName) + MnxsD0lrg8kZaUPt2I.OPAImF4404(3372));
						B9hsKgTiVK.SaveLogFile(text3);
						string delimitingCharacter = "";
						if (((FileDialog)val2).FileName.EndsWith(MnxsD0lrg8kZaUPt2I.OPAImF4404(3384)))
						{
							delimitingCharacter = MnxsD0lrg8kZaUPt2I.OPAImF4404(3396);
						}
						else if (((FileDialog)val2).FileName.EndsWith(MnxsD0lrg8kZaUPt2I.OPAImF4404(3402)))
						{
							delimitingCharacter = MnxsD0lrg8kZaUPt2I.OPAImF4404(3414);
						}
						else
						{
							switch (((FileDialog)val2).FilterIndex)
							{
							case 1:
								((FileDialog)val2).FileName = ((FileDialog)val2).FileName + MnxsD0lrg8kZaUPt2I.OPAImF4404(3420);
								delimitingCharacter = MnxsD0lrg8kZaUPt2I.OPAImF4404(3432);
								break;
							case 2:
								((FileDialog)val2).FileName = ((FileDialog)val2).FileName + MnxsD0lrg8kZaUPt2I.OPAImF4404(3438);
								delimitingCharacter = MnxsD0lrg8kZaUPt2I.OPAImF4404(3450);
								break;
							}
						}
						if (rywsWZc2ft == null)
						{
							rywsWZc2ft = (IDMLLogFileConverter)new DMLLogFileConverter();
						}
						rywsWZc2ft.Initialize(ewqjA30Ig7KglKlcHq.O0yhiaph2());
						rywsWZc2ft.ConvertLogFile(text3, ((FileDialog)val2).FileName, delimitingCharacter);
					}
				}
			}
			RRns2cv9b4 = false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void a5K1BCR5Fl(object P_0, EventArgs P_1)
		{
			try
			{
				((Control)this).Text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)100);
				((ToolStripItem)C970wPxyMU).Visible = false;
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Hd41T6NBjN(object P_0, EventArgs P_1)
		{
			try
			{
				if (FkusVqaffY != null)
				{
					if (FkusVqaffY.ET2PjUKedp() == (XRbgaoKmn16bImAki0)0)
					{
						FkusVqaffY.GxcPFYiZjf(out var addedParams, out var removedParams);
						jqR1hVZ1jy(addedParams, removedParams);
					}
					else
					{
						Jep1GiNkbR(FkusVqaffY.Mt9Pfm92EA());
					}
				}
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Yhh1zTwLg1(object P_0, FormClosingEventArgs P_1)
		{
			//IL_003a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0073: Unknown result type (might be due to invalid IL or missing references)
			//IL_00bf: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c0: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c5: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c6: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c8: Invalid comparison between Unknown and I4
			//IL_008c: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d9: Unknown result type (might be due to invalid IL or missing references)
			//IL_00db: Invalid comparison between Unknown and I4
			try
			{
				if (KCisSJL3Z0 != null)
				{
					KCisSJL3Z0.Stop();
				}
				if (WX2sFF9TnD == (XRbgaoKmn16bImAki0)0 && RRns2cv9b4)
				{
					string text = string.Empty;
					MessageBoxButtons val = (MessageBoxButtons)3;
					if (jXKsmdP0xa == (HyN0of5EN6lv1IdeFn)1)
					{
						G1J1uSU90t();
						text = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)606) + Environment.NewLine + Environment.NewLine;
						val = (MessageBoxButtons)4;
					}
					else if (jXKsmdP0xa == (HyN0of5EN6lv1IdeFn)2)
					{
						G1J1uSU90t();
						val = (MessageBoxButtons)4;
					}
					text += BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)602);
					DialogResult val2 = MessageBox.Show(text, BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)704), val);
					if ((int)val2 == 2)
					{
						((CancelEventArgs)(object)P_1).Cancel = true;
					}
					else if ((int)val2 != 7)
					{
						CHSs73Lk1j(this, null);
					}
				}
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void mnVsHujEZu(object P_0, FormClosedEventArgs P_1)
		{
			try
			{
				if (V7jsnU86XY != null)
				{
					V7jsnU86XY.omrrlajOOy();
					V7jsnU86XY = null;
				}
				if (B9hsKgTiVK != null && zcVsG4b7hp == (x2IXLLeGQpqCfCUyuM)3)
				{
					B9hsKgTiVK.StopMonitoring();
				}
				if (Rqms4etUL2 != null)
				{
					Rqms4etUL2.Clear();
				}
				xcSspmGMTT = false;
				zcVsG4b7hp = (x2IXLLeGQpqCfCUyuM)0;
				ewqjA30Ig7KglKlcHq.mQ21ORqMv();
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void sMQsPWvc30(object P_0, HelpEventArgs P_1)
		{
			try
			{
				MbjsC6cPIx.ShowHelp(this);
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void QSTs138M69()
		{
			try
			{
				GEHsXZu7c2(null, null);
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void MexssOPN6u(object P_0, EventArgs P_1)
		{
			try
			{
				((Form)this).Close();
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void sNqs0Ksivp(object P_0, EventArgs P_1)
		{
			try
			{
				V7jsnU86XY.lCGrCSWlCj();
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void CHSs73Lk1j(object P_0, EventArgs P_1)
		{
			try
			{
				mJZ1JdBInh();
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void ImEsr2XBnp(object P_0, EventArgs P_1)
		{
			try
			{
				V7jsnU86XY.LgJIPRFYlE(true);
			}
			catch
			{
				if (Gc0sfg7q6E != null)
				{
					Gc0sfg7q6E.DisplayError((d78MYpNQLCKwkS1VcZ)1001);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void BZqsIth0y2(object P_0, EventArgs P_1)
		{
			try
			{
				V7jsnU86XY.LgJIPRFYlE(false);
			}
			catch
			{
				if (Gc0sfg7q6E != null)
				{
					Gc0sfg7q6E.DisplayError((d78MYpNQLCKwkS1VcZ)1001);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void N0wscrMKGa(object P_0, EventArgs P_1)
		{
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			//IL_000d: Expected O, but got Unknown
			//IL_004f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0055: Invalid comparison between Unknown and I4
			//IL_0091: Unknown result type (might be due to invalid IL or missing references)
			//IL_0097: Invalid comparison between Unknown and I4
			try
			{
				OpenFileDialog val = new OpenFileDialog();
				((FileDialog)val).Title = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)702);
				((FileDialog)val).Filter = BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)502);
				((FileDialog)val).InitialDirectory = ewqjA30Ig7KglKlcHq.F2XgE6dCb();
				if ((int)((CommonDialog)val).ShowDialog() != 1)
				{
					return;
				}
				if (zcVsG4b7hp == (x2IXLLeGQpqCfCUyuM)3)
				{
					if ((int)MessageBox.Show(BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)603), BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)702), (MessageBoxButtons)4) == 7)
					{
						return;
					}
					mJZ1JdBInh();
					G1J1uSU90t();
				}
				FkusVqaffY.OVaP2txEhH((XRbgaoKmn16bImAki0)1);
				Jep1GiNkbR(((FileDialog)val).FileName);
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void GEHsXZu7c2(object P_0, EventArgs P_1)
		{
			//IL_004d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0053: Invalid comparison between Unknown and I4
			//IL_009e: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a4: Invalid comparison between Unknown and I4
			//IL_011f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0125: Invalid comparison between Unknown and I4
			try
			{
				if (WX2sFF9TnD == (XRbgaoKmn16bImAki0)0 && RRns2cv9b4 && (int)MessageBox.Show(ewqjA30Ig7KglKlcHq.iA53A7qRi(BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)608)), BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)705), (MessageBoxButtons)1) == 1)
				{
					mJZ1JdBInh();
				}
				FkusVqaffY.eGwPLjw6qL(fD5sLwMkOr);
				if (zcVsG4b7hp == (x2IXLLeGQpqCfCUyuM)3)
				{
					FkusVqaffY.Ko0Pp7PcI8(false);
				}
				else
				{
					FkusVqaffY.Ko0Pp7PcI8(true);
				}
				if ((int)((Form)FkusVqaffY).ShowDialog() != 1)
				{
					return;
				}
				if (FkusVqaffY.ET2PjUKedp() == (XRbgaoKmn16bImAki0)0)
				{
					if (WX2sFF9TnD == (XRbgaoKmn16bImAki0)1)
					{
						j5u1ppDvK0((XRbgaoKmn16bImAki0)0);
					}
					FkusVqaffY.GxcPFYiZjf(out var addedParams, out var removedParams);
					jqR1hVZ1jy(addedParams, removedParams);
					return;
				}
				if (zcVsG4b7hp == (x2IXLLeGQpqCfCUyuM)3)
				{
					if ((int)MessageBox.Show(BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)603), BdxsD3E0CU.GetLocalizedString((LLwdmNZAEG00aiD7e6)702), (MessageBoxButtons)4) == 7)
					{
						return;
					}
					mJZ1JdBInh();
					G1J1uSU90t();
				}
				Jep1GiNkbR(FkusVqaffY.Mt9Pfm92EA());
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void BOHsxYZEu0(object P_0, EventArgs P_1)
		{
			try
			{
				GEHsXZu7c2(P_0, P_1);
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void vWNso8JrXb(object P_0, EventArgs P_1)
		{
			aPv1jdAt8R();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void M1LswxOtqC(object P_0, EventArgs P_1)
		{
			try
			{
				if (!nxT14MF1Hw((z270jTU1r1wLk7eb8B)1, false))
				{
					IYAsTLSjEt.Checked = false;
					iXwszvAQFQ.Checked = true;
				}
				else
				{
					IYAsTLSjEt.Checked = true;
					iXwszvAQFQ.Checked = false;
				}
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void HKIsgVBgRS(object P_0, EventArgs P_1)
		{
			try
			{
				if (!nxT14MF1Hw((z270jTU1r1wLk7eb8B)2, false))
				{
					iXwszvAQFQ.Checked = false;
					IYAsTLSjEt.Checked = true;
				}
				else
				{
					iXwszvAQFQ.Checked = true;
					IYAsTLSjEt.Checked = false;
				}
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void gCOs82O4Vu(object P_0, EventArgs P_1)
		{
			try
			{
				G1J1uSU90t();
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void v0Vsd22Ev1(object P_0, EventArgs P_1)
		{
			try
			{
				c6s1QIEgmk();
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Ce4skpU00L(object P_0, EventArgs P_1)
		{
			try
			{
				MbjsC6cPIx.ShowHelp(this);
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void cmjs3wDwSI(object P_0, KeyEventArgs P_1)
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_000f: Invalid comparison between Unknown and I4
			if ((int)P_1.KeyCode == 32)
			{
				UyT120efXA();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Dispose(bool P_0)
		{
			QHv1y3MbV3();
			if (P_0 && CVBsQn4cSc != null)
			{
				CVBsQn4cSc.Dispose();
			}
			((Form)this).Dispose(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void PK6sMCvH7W()
		{
			//IL_0019: Unknown result type (might be due to invalid IL or missing references)
			//IL_0023: Expected O, but got Unknown
			//IL_0024: Unknown result type (might be due to invalid IL or missing references)
			//IL_002e: Expected O, but got Unknown
			//IL_002f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0039: Expected O, but got Unknown
			//IL_003a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0044: Expected O, but got Unknown
			//IL_0045: Unknown result type (might be due to invalid IL or missing references)
			//IL_004f: Expected O, but got Unknown
			//IL_0050: Unknown result type (might be due to invalid IL or missing references)
			//IL_005a: Expected O, but got Unknown
			//IL_005b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0065: Expected O, but got Unknown
			//IL_0066: Unknown result type (might be due to invalid IL or missing references)
			//IL_0070: Expected O, but got Unknown
			//IL_0071: Unknown result type (might be due to invalid IL or missing references)
			//IL_007b: Expected O, but got Unknown
			//IL_007c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0086: Expected O, but got Unknown
			//IL_0087: Unknown result type (might be due to invalid IL or missing references)
			//IL_0091: Expected O, but got Unknown
			//IL_0092: Unknown result type (might be due to invalid IL or missing references)
			//IL_009c: Expected O, but got Unknown
			//IL_009d: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a7: Expected O, but got Unknown
			//IL_00a8: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b2: Expected O, but got Unknown
			//IL_00b3: Unknown result type (might be due to invalid IL or missing references)
			//IL_00bd: Expected O, but got Unknown
			//IL_00be: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c8: Expected O, but got Unknown
			//IL_00c9: Unknown result type (might be due to invalid IL or missing references)
			//IL_00d3: Expected O, but got Unknown
			//IL_00d4: Unknown result type (might be due to invalid IL or missing references)
			//IL_00de: Expected O, but got Unknown
			//IL_00df: Unknown result type (might be due to invalid IL or missing references)
			//IL_00e9: Expected O, but got Unknown
			//IL_00ea: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f4: Expected O, but got Unknown
			//IL_00f5: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ff: Expected O, but got Unknown
			//IL_00ff: Unknown result type (might be due to invalid IL or missing references)
			//IL_0105: Expected O, but got Unknown
			//IL_0105: Unknown result type (might be due to invalid IL or missing references)
			//IL_010b: Expected O, but got Unknown
			//IL_010b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0111: Expected O, but got Unknown
			//IL_0111: Unknown result type (might be due to invalid IL or missing references)
			//IL_0117: Expected O, but got Unknown
			//IL_09f2: Unknown result type (might be due to invalid IL or missing references)
			//IL_09fc: Expected O, but got Unknown
			//IL_0a62: Unknown result type (might be due to invalid IL or missing references)
			//IL_0a6c: Expected O, but got Unknown
			//IL_0a74: Unknown result type (might be due to invalid IL or missing references)
			//IL_0a7e: Expected O, but got Unknown
			//IL_0a86: Unknown result type (might be due to invalid IL or missing references)
			//IL_0a90: Expected O, but got Unknown
			//IL_0a98: Unknown result type (might be due to invalid IL or missing references)
			//IL_0aa2: Expected O, but got Unknown
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(xJXRtoo1hkZNIY6u3D));
			C970wPxyMU = new ToolStripStatusLabel();
			a0usuURYwJ = new MenuStrip();
			cLqsYMvHlQ = new ToolStripMenuItem();
			Qin0IhexpS = new ToolStripMenuItem();
			yf0slmcCq3 = new ToolStripMenuItem();
			aJm0rp73YG = new ToolStripMenuItem();
			ioU0XUScqq = new ToolStripMenuItem();
			MFV0xR3e42 = new ToolStripMenuItem();
			GSKsJ6ZZQx = new ToolStripMenuItem();
			F130Hg3MDZ = new ToolStripMenuItem();
			d0E0PclwlM = new ToolStripMenuItem();
			SnS07JKTZ0 = new ToolStripMenuItem();
			DaesBwbyjq = new ToolStripMenuItem();
			iXwszvAQFQ = new ToolStripMenuItem();
			IYAsTLSjEt = new ToolStripMenuItem();
			NS401njn0g = new ToolStripMenuItem();
			aYD0sk70Zk = new ToolStripMenuItem();
			S5T0022a2p = new ToolStripMenuItem();
			VZx0c6PVcF = new ToolStripMenuItem();
			xkh0ouN23J = new ToolStripMenuItem();
			VNv0g569Q4 = new ToolStripMenuItem();
			ToolStripSeparator val = new ToolStripSeparator();
			ToolStripSeparator val2 = new ToolStripSeparator();
			ToolStripSeparator val3 = new ToolStripSeparator();
			StatusStrip val4 = new StatusStrip();
			((Control)val4).SuspendLayout();
			((Control)a0usuURYwJ).SuspendLayout();
			((Control)this).SuspendLayout();
			((ToolStripItem)val).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(3456);
			((ToolStripItem)val).Size = new Size(150, 6);
			((ToolStripItem)val2).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(3498);
			((ToolStripItem)val2).Size = new Size(150, 6);
			((ToolStripItem)val3).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(3540);
			((ToolStripItem)val3).Size = new Size(150, 6);
			((ToolStrip)val4).Items.AddRange((ToolStripItem[])(object)new ToolStripItem[1] { (ToolStripItem)C970wPxyMU });
			((Control)val4).Location = new Point(0, 477);
			((Control)val4).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(3582);
			((Control)val4).RightToLeft = (RightToLeft)1;
			((Control)val4).Size = new Size(854, 22);
			((Control)val4).TabIndex = 1;
			((Control)val4).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(3610);
			((ToolStripItem)C970wPxyMU).AutoSize = false;
			((ToolStripItem)C970wPxyMU).BackColor = Color.Lime;
			((ToolStripItem)C970wPxyMU).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(3638);
			((ToolStripItem)C970wPxyMU).Size = new Size(109, 17);
			((ToolStripItem)C970wPxyMU).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(3694);
			((ToolStrip)a0usuURYwJ).Items.AddRange((ToolStripItem[])(object)new ToolStripItem[5]
			{
				(ToolStripItem)cLqsYMvHlQ,
				(ToolStripItem)F130Hg3MDZ,
				(ToolStripItem)DaesBwbyjq,
				(ToolStripItem)NS401njn0g,
				(ToolStripItem)VZx0c6PVcF
			});
			((Control)a0usuURYwJ).Location = new Point(0, 0);
			((Control)a0usuURYwJ).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(3740);
			((Control)a0usuURYwJ).Size = new Size(854, 24);
			((Control)a0usuURYwJ).TabIndex = 0;
			((Control)a0usuURYwJ).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(3762);
			((ToolStripDropDownItem)cLqsYMvHlQ).DropDownItems.AddRange((ToolStripItem[])(object)new ToolStripItem[9]
			{
				(ToolStripItem)Qin0IhexpS,
				(ToolStripItem)val,
				(ToolStripItem)yf0slmcCq3,
				(ToolStripItem)aJm0rp73YG,
				(ToolStripItem)val2,
				(ToolStripItem)ioU0XUScqq,
				(ToolStripItem)MFV0xR3e42,
				(ToolStripItem)val3,
				(ToolStripItem)GSKsJ6ZZQx
			});
			((ToolStripItem)cLqsYMvHlQ).ImageScaling = (ToolStripItemImageScaling)0;
			((ToolStripItem)cLqsYMvHlQ).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(3786);
			((ToolStripItem)cLqsYMvHlQ).Size = new Size(35, 20);
			((ToolStripItem)cLqsYMvHlQ).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(3834);
			((ToolStripItem)Qin0IhexpS).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(3846);
			((ToolStripItem)Qin0IhexpS).Size = new Size(153, 22);
			((ToolStripItem)Qin0IhexpS).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(3912);
			((ToolStripItem)Qin0IhexpS).Click += N0wscrMKGa;
			((ToolStripItem)yf0slmcCq3).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(3946);
			((ToolStripItem)yf0slmcCq3).Size = new Size(153, 22);
			((ToolStripItem)yf0slmcCq3).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(4012);
			((ToolStripItem)yf0slmcCq3).Click += sNqs0Ksivp;
			((ToolStripItem)aJm0rp73YG).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(4046);
			((ToolStripItem)aJm0rp73YG).Size = new Size(153, 22);
			((ToolStripItem)aJm0rp73YG).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(4106);
			((ToolStripItem)aJm0rp73YG).Click += CHSs73Lk1j;
			((ToolStripItem)ioU0XUScqq).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(4142);
			((ToolStripItem)ioU0XUScqq).Size = new Size(153, 22);
			((ToolStripItem)ioU0XUScqq).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(4206);
			((ToolStripItem)ioU0XUScqq).Click += ImEsr2XBnp;
			((ToolStripItem)MFV0xR3e42).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(4236);
			((ToolStripItem)MFV0xR3e42).Size = new Size(153, 22);
			((ToolStripItem)MFV0xR3e42).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(4286);
			((ToolStripItem)MFV0xR3e42).Click += BZqsIth0y2;
			((ToolStripItem)GSKsJ6ZZQx).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(4300);
			((ToolStripItem)GSKsJ6ZZQx).Size = new Size(153, 22);
			((ToolStripItem)GSKsJ6ZZQx).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(4348);
			((ToolStripDropDownItem)F130Hg3MDZ).DropDownItems.AddRange((ToolStripItem[])(object)new ToolStripItem[3]
			{
				(ToolStripItem)d0E0PclwlM,
				(ToolStripItem)SnS07JKTZ0,
				(ToolStripItem)VNv0g569Q4
			});
			((ToolStripItem)F130Hg3MDZ).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(4362);
			((ToolStripItem)F130Hg3MDZ).Size = new Size(37, 20);
			((ToolStripItem)F130Hg3MDZ).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(4410);
			((ToolStripItem)d0E0PclwlM).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(4422);
			((ToolStripItem)d0E0PclwlM).Size = new Size(200, 22);
			((ToolStripItem)d0E0PclwlM).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(4500);
			((ToolStripItem)SnS07JKTZ0).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(4550);
			((ToolStripItem)SnS07JKTZ0).Size = new Size(200, 22);
			((ToolStripItem)SnS07JKTZ0).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(4620);
			((ToolStripDropDownItem)DaesBwbyjq).DropDownItems.AddRange((ToolStripItem[])(object)new ToolStripItem[2]
			{
				(ToolStripItem)iXwszvAQFQ,
				(ToolStripItem)IYAsTLSjEt
			});
			((ToolStripItem)DaesBwbyjq).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(4658);
			((ToolStripItem)DaesBwbyjq).Size = new Size(41, 20);
			((ToolStripItem)DaesBwbyjq).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(4706);
			((ToolStripItem)iXwszvAQFQ).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(4718);
			((ToolStripItem)iXwszvAQFQ).Size = new Size(156, 22);
			((ToolStripItem)iXwszvAQFQ).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(4778);
			((ToolStripItem)IYAsTLSjEt).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(4804);
			((ToolStripItem)IYAsTLSjEt).Size = new Size(156, 22);
			((ToolStripItem)IYAsTLSjEt).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(4872);
			((ToolStripDropDownItem)NS401njn0g).DropDownItems.AddRange((ToolStripItem[])(object)new ToolStripItem[2]
			{
				(ToolStripItem)aYD0sk70Zk,
				(ToolStripItem)S5T0022a2p
			});
			((ToolStripItem)NS401njn0g).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(4906);
			((ToolStripItem)NS401njn0g).Size = new Size(62, 20);
			((ToolStripItem)NS401njn0g).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(4962);
			((ToolStripItem)aYD0sk70Zk).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(4982);
			((ToolStripItem)aYD0sk70Zk).Size = new Size(144, 22);
			((ToolStripItem)aYD0sk70Zk).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(5048);
			((ToolStripItem)S5T0022a2p).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(5080);
			((ToolStripItem)S5T0022a2p).Size = new Size(144, 22);
			((ToolStripItem)S5T0022a2p).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(5144);
			((ToolStripDropDownItem)VZx0c6PVcF).DropDownItems.AddRange((ToolStripItem[])(object)new ToolStripItem[1] { (ToolStripItem)xkh0ouN23J });
			((ToolStripItem)VZx0c6PVcF).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(5174);
			((ToolStripItem)VZx0c6PVcF).Size = new Size(40, 20);
			((ToolStripItem)VZx0c6PVcF).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(5222);
			((ToolStripItem)xkh0ouN23J).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(5234);
			((ToolStripItem)xkh0ouN23J).Size = new Size(118, 22);
			((ToolStripItem)xkh0ouN23J).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(5290);
			((ToolStripItem)xkh0ouN23J).Click += Ce4skpU00L;
			((ToolStripItem)VNv0g569Q4).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(5310);
			((ToolStripItem)VNv0g569Q4).Size = new Size(200, 22);
			((ToolStripItem)VNv0g569Q4).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(5382);
			((ToolStripItem)VNv0g569Q4).Click += vWNso8JrXb;
			((ContainerControl)this).AutoScaleDimensions = new SizeF(6f, 13f);
			((ContainerControl)this).AutoScaleMode = (AutoScaleMode)1;
			((Form)this).ClientSize = new Size(854, 499);
			((Control)this).Controls.Add((Control)(object)val4);
			((Control)this).Controls.Add((Control)(object)a0usuURYwJ);
			((Form)this).Icon = (Icon)componentResourceManager.GetObject(MnxsD0lrg8kZaUPt2I.OPAImF4404(5422));
			((Form)this).KeyPreview = true;
			((Form)this).MainMenuStrip = a0usuURYwJ;
			((Control)this).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(5446);
			((Form)this).StartPosition = (FormStartPosition)1;
			((Control)this).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(5494);
			((Form)this).Load += a5K1BCR5Fl;
			((Form)this).Shown += Hd41T6NBjN;
			((Form)this).FormClosed += new FormClosedEventHandler(mnVsHujEZu);
			((Control)this).KeyUp += new KeyEventHandler(cmjs3wDwSI);
			((Form)this).FormClosing += new FormClosingEventHandler(Yhh1zTwLg1);
			((Control)this).HelpRequested += new HelpEventHandler(sMQsPWvc30);
			((Control)val4).ResumeLayout(false);
			((Control)val4).PerformLayout();
			((Control)a0usuURYwJ).ResumeLayout(false);
			((Control)a0usuURYwJ).PerformLayout();
			((Control)this).ResumeLayout(false);
			((Control)this).PerformLayout();
		}
	}
}
namespace Gh2OwS8aCsjfBiV4u9
{
	[Guid("29E9AFD2-5579-40a5-AFA1-E7F7C503305C")]
	internal class juqL6KgOSNssTC0yia : Form, IHelpInformation
	{
		private IContainer wDa0U8t59O;

		private Label akJ0D5BmRP;

		private TextBox wTx0K5IWKT;

		private Button aRi0VU7swF;

		private LocalizedStringProvider AD104pvhHZ;

		private IContextSensitiveHelpProvider rLI0nx9V6k;

		private bool S7h0eGUTKU;

		private long rL40FJorKG;

		private string p3L0pD0u9b;

		private string oVT0vP6HeX;

		Guid IHelpInformation.GUID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ((object)this).GetType().GUID;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Dispose(bool P_0)
		{
			if (P_0 && wDa0U8t59O != null)
			{
				wDa0U8t59O.Dispose();
			}
			((Form)this).Dispose(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void aYV08gFcLl()
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_0012: Expected O, but got Unknown
			//IL_0013: Unknown result type (might be due to invalid IL or missing references)
			//IL_001d: Expected O, but got Unknown
			//IL_001e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			//IL_0231: Unknown result type (might be due to invalid IL or missing references)
			//IL_023b: Expected O, but got Unknown
			//IL_0243: Unknown result type (might be due to invalid IL or missing references)
			//IL_024d: Expected O, but got Unknown
			akJ0D5BmRP = new Label();
			wTx0K5IWKT = new TextBox();
			aRi0VU7swF = new Button();
			((Control)this).SuspendLayout();
			((Control)akJ0D5BmRP).AutoSize = true;
			((Control)akJ0D5BmRP).Location = new Point(38, 33);
			((Control)akJ0D5BmRP).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(5530);
			((Control)akJ0D5BmRP).Size = new Size(35, 13);
			((Control)akJ0D5BmRP).TabIndex = 0;
			((Control)akJ0D5BmRP).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(5568);
			((Control)wTx0K5IWKT).Location = new Point(38, 61);
			((TextBoxBase)wTx0K5IWKT).Multiline = true;
			((Control)wTx0K5IWKT).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(5584);
			((Control)wTx0K5IWKT).Size = new Size(488, 85);
			((Control)wTx0K5IWKT).TabIndex = 1;
			((Control)aRi0VU7swF).Location = new Point(242, 165);
			((Control)aRi0VU7swF).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(5620);
			((Control)aRi0VU7swF).Size = new Size(88, 26);
			((Control)aRi0VU7swF).TabIndex = 2;
			((Control)aRi0VU7swF).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(5636);
			((ButtonBase)aRi0VU7swF).UseVisualStyleBackColor = true;
			((Control)aRi0VU7swF).Click += eeP0MLLF5C;
			((ContainerControl)this).AutoScaleDimensions = new SizeF(6f, 13f);
			((ContainerControl)this).AutoScaleMode = (AutoScaleMode)1;
			((Form)this).ClientSize = new Size(572, 215);
			((Control)this).Controls.Add((Control)(object)aRi0VU7swF);
			((Control)this).Controls.Add((Control)(object)wTx0K5IWKT);
			((Control)this).Controls.Add((Control)(object)akJ0D5BmRP);
			((Form)this).FormBorderStyle = (FormBorderStyle)3;
			((Form)this).MaximizeBox = false;
			((Form)this).MinimizeBox = false;
			((Control)this).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(5644);
			((Form)this).StartPosition = (FormStartPosition)1;
			((Control)this).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(5690);
			((Form)this).Load += LIh0dNLipY;
			((Form)this).FormClosing += new FormClosingEventHandler(VFn0kBgDXD);
			((Control)this).HelpRequested += new HelpEventHandler(TEV033L6h1);
			((Control)this).ResumeLayout(false);
			((Control)this).PerformLayout();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public juqL6KgOSNssTC0yia(LocalizedStringProvider P_0, object P_1, object P_2)
		{
			JmLDt5P0cahRebTiifG.LYav19NzXHLb9();
			((Form)this)..ctor();
			aYV08gFcLl();
			AD104pvhHZ = P_0;
			rLI0nx9V6k = Factory.CreateInstance<IContextSensitiveHelpProvider>();
			rLI0nx9V6k.Initialize(P_1, P_2);
			S7h0eGUTKU = true;
			rL40FJorKG = 64L;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public bool NYq09Y8p5J()
		{
			return S7h0eGUTKU;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public void cFq064CEO7(bool P_0)
		{
			S7h0eGUTKU = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public long faw0a6Rusm()
		{
			return rL40FJorKG;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public void OD90ZljFU0(long P_0)
		{
			rL40FJorKG = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public string MtZ0tnbsLv()
		{
			return p3L0pD0u9b;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public void qHH0quvd3A(string P_0)
		{
			p3L0pD0u9b = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public string BJF0hCEqSf()
		{
			return oVT0vP6HeX;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public void zsm0567i5W(string P_0)
		{
			oVT0vP6HeX = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void LIh0dNLipY(object P_0, EventArgs P_1)
		{
			((Control)this).Text = AD104pvhHZ.GetLocalizedString((LLwdmNZAEG00aiD7e6)706);
			((Control)akJ0D5BmRP).Text = AD104pvhHZ.GetLocalizedString((LLwdmNZAEG00aiD7e6)1102) + oVT0vP6HeX;
			((TextBoxBase)wTx0K5IWKT).Multiline = S7h0eGUTKU;
			((TextBoxBase)wTx0K5IWKT).MaxLength = (int)rL40FJorKG;
			((Control)wTx0K5IWKT).Text = p3L0pD0u9b;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void VFn0kBgDXD(object P_0, FormClosingEventArgs P_1)
		{
			((Control)wTx0K5IWKT).Text = "";
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void TEV033L6h1(object P_0, HelpEventArgs P_1)
		{
			rLI0nx9V6k.ShowHelp(this);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void eeP0MLLF5C(object P_0, EventArgs P_1)
		{
			p3L0pD0u9b = ((Control)wTx0K5IWKT).Text;
			((Form)this).DialogResult = (DialogResult)1;
			((Form)this).Close();
		}
	}
}
namespace SGAXiskxPaDHEOHCNF
{
	[Guid("973CB728-A8FA-4f0d-BFA5-901A99DAC1AF")]
	internal class VqmdxqdVZK2wuuCkmX : Form, IHelpInformation
	{
		private IContainer K4Q0YYxAnJ;

		private CheckBox fTd0lAsu7Q;

		private CheckBox g2l0JkgZAm;

		private Button eGR0BeDybH;

		private readonly string FbJ0TARb5j;

		private readonly string oer0zQaIqm;

		private readonly string dZH7HH1QAQ;

		private LocalizedStringProvider clp7P9Q3Ye;

		private IContextSensitiveHelpProvider jtq71jVpui;

		private bool f6o7siqiNS;

		private bool KSm70AeHlg;

		public bool EventMarkerEnabled
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return f6o7siqiNS;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				f6o7siqiNS = flag;
			}
		}

		Guid IHelpInformation.GUID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ((object)this).GetType().GUID;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Dispose(bool P_0)
		{
			if (P_0 && K4Q0YYxAnJ != null)
			{
				K4Q0YYxAnJ.Dispose();
			}
			((Form)this).Dispose(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void qOn0G5h3Pf()
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_0012: Expected O, but got Unknown
			//IL_0013: Unknown result type (might be due to invalid IL or missing references)
			//IL_001d: Expected O, but got Unknown
			//IL_001e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			//IL_028d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0297: Expected O, but got Unknown
			//IL_029f: Unknown result type (might be due to invalid IL or missing references)
			//IL_02a9: Expected O, but got Unknown
			fTd0lAsu7Q = new CheckBox();
			g2l0JkgZAm = new CheckBox();
			eGR0BeDybH = new Button();
			((Control)this).SuspendLayout();
			((Control)fTd0lAsu7Q).AutoSize = true;
			((Control)fTd0lAsu7Q).Location = new Point(33, 29);
			((Control)fTd0lAsu7Q).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(5728);
			((Control)fTd0lAsu7Q).Size = new Size(126, 17);
			((Control)fTd0lAsu7Q).TabIndex = 0;
			((Control)fTd0lAsu7Q).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(5768);
			((ButtonBase)fTd0lAsu7Q).UseVisualStyleBackColor = true;
			fTd0lAsu7Q.CheckedChanged += xyc0RYrbIR;
			((Control)g2l0JkgZAm).AutoSize = true;
			((Control)g2l0JkgZAm).Location = new Point(85, 78);
			((Control)g2l0JkgZAm).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(5810);
			((Control)g2l0JkgZAm).Size = new Size(146, 17);
			((Control)g2l0JkgZAm).TabIndex = 1;
			((Control)g2l0JkgZAm).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(5860);
			((ButtonBase)g2l0JkgZAm).UseVisualStyleBackColor = true;
			g2l0JkgZAm.CheckedChanged += iS50j3adQd;
			((Control)eGR0BeDybH).Location = new Point(126, 127);
			((Control)eGR0BeDybH).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(5912);
			((Control)eGR0BeDybH).Size = new Size(79, 24);
			((Control)eGR0BeDybH).TabIndex = 2;
			((Control)eGR0BeDybH).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(5934);
			((ButtonBase)eGR0BeDybH).UseVisualStyleBackColor = true;
			((Control)eGR0BeDybH).Click += LGU0fhkV56;
			((ContainerControl)this).AutoScaleDimensions = new SizeF(6f, 13f);
			((ContainerControl)this).AutoScaleMode = (AutoScaleMode)1;
			((Form)this).ClientSize = new Size(355, 171);
			((Control)this).Controls.Add((Control)(object)eGR0BeDybH);
			((Control)this).Controls.Add((Control)(object)g2l0JkgZAm);
			((Control)this).Controls.Add((Control)(object)fTd0lAsu7Q);
			((Form)this).FormBorderStyle = (FormBorderStyle)2;
			((Form)this).MaximizeBox = false;
			((Form)this).MinimizeBox = false;
			((Control)this).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(5942);
			((Form)this).ShowInTaskbar = false;
			((Form)this).StartPosition = (FormStartPosition)1;
			((Control)this).Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(5990);
			((Form)this).Load += Ml00LOTNB6;
			((Form)this).FormClosing += new FormClosingEventHandler(uhu026RPV5);
			((Control)this).HelpRequested += new HelpEventHandler(fGQ0mUwREu);
			((Control)this).ResumeLayout(false);
			((Control)this).PerformLayout();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public VqmdxqdVZK2wuuCkmX(LocalizedStringProvider P_0, object P_1, object P_2)
		{
			JmLDt5P0cahRebTiifG.LYav19NzXHLb9();
			FbJ0TARb5j = MnxsD0lrg8kZaUPt2I.OPAImF4404(6030);
			oer0zQaIqm = MnxsD0lrg8kZaUPt2I.OPAImF4404(6234);
			dZH7HH1QAQ = MnxsD0lrg8kZaUPt2I.OPAImF4404(6274);
			((Form)this)..ctor();
			qOn0G5h3Pf();
			f6o7siqiNS = true;
			KSm70AeHlg = true;
			clp7P9Q3Ye = P_0;
			jtq71jVpui = Factory.CreateInstance<IContextSensitiveHelpProvider>();
			jtq71jVpui.Initialize(P_1, P_2);
			JJ80Sl3k6h();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public bool hgu0AZ1Am0()
		{
			return KSm70AeHlg;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public void kO80QRoARb(bool P_0)
		{
			KSm70AeHlg = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Ml00LOTNB6(object P_0, EventArgs P_1)
		{
			((Control)this).Text = clp7P9Q3Ye.GetLocalizedString((LLwdmNZAEG00aiD7e6)1101);
			((Control)fTd0lAsu7Q).Text = clp7P9Q3Ye.GetLocalizedString((LLwdmNZAEG00aiD7e6)1103);
			((Control)g2l0JkgZAm).Text = clp7P9Q3Ye.GetLocalizedString((LLwdmNZAEG00aiD7e6)1104);
			((Control)eGR0BeDybH).Text = clp7P9Q3Ye.GetLocalizedString((LLwdmNZAEG00aiD7e6)900);
			dN10CUHiR8();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void xyc0RYrbIR(object P_0, EventArgs P_1)
		{
			f6o7siqiNS = fTd0lAsu7Q.Checked;
			dN10CUHiR8();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void iS50j3adQd(object P_0, EventArgs P_1)
		{
			KSm70AeHlg = g2l0JkgZAm.Checked;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void uhu026RPV5(object P_0, FormClosingEventArgs P_1)
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void fGQ0mUwREu(object P_0, HelpEventArgs P_1)
		{
			jtq71jVpui.ShowHelp(this);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void LGU0fhkV56(object P_0, EventArgs P_1)
		{
			f6o7siqiNS = fTd0lAsu7Q.Checked;
			KSm70AeHlg = g2l0JkgZAm.Checked;
			qOK0W7CHfu();
			((Form)this).DialogResult = (DialogResult)1;
			((Form)this).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void dN10CUHiR8()
		{
			fTd0lAsu7Q.Checked = f6o7siqiNS;
			((Control)g2l0JkgZAm).Enabled = f6o7siqiNS;
			g2l0JkgZAm.Checked = KSm70AeHlg;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void qOK0W7CHfu()
		{
			using RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(FbJ0TARb5j, writable: true);
			int num = (f6o7siqiNS ? 1 : 0);
			int num2 = (KSm70AeHlg ? 1 : 0);
			try
			{
				registryKey.SetValue(oer0zQaIqm, num);
				registryKey.SetValue(dZH7HH1QAQ, num2);
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void JJ80Sl3k6h()
		{
			bool flag = true;
			bool kSm70AeHlg = true;
			using (RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(FbJ0TARb5j))
			{
				string s = MnxsD0lrg8kZaUPt2I.OPAImF4404(6336);
				string s2 = MnxsD0lrg8kZaUPt2I.OPAImF4404(6342);
				try
				{
					s = registryKey.GetValue(oer0zQaIqm, null).ToString();
					s2 = registryKey.GetValue(dZH7HH1QAQ, null).ToString();
				}
				catch
				{
				}
				if (int.Parse(s) == 0)
				{
					flag = false;
				}
				if (int.Parse(s2) == 0)
				{
					kSm70AeHlg = false;
				}
			}
			f6o7siqiNS = flag;
			KSm70AeHlg = kSm70AeHlg;
		}
	}
}
namespace Cummins.INSITE.CNL.GraphicalMonitoring
{
	[Guid("FAAA2BF8-AE2A-4cfc-BEC4-8BB5BFB10B9D")]
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("Cummins.INSITE.CNL.GraphicalMonitoring.GraphicalMonitor.1")]
	public sealed class GraphicalMonitor : IGraphicalMonitor
	{
		private xJXRtoo1hkZNIY6u3D yoJ7xnWfry;

		private object d887odrwrX;

		private object KRw7wOo2DU;

		private object jRR7g0WjDm;

		private object wp278ekXHo;

		private IEventSubscriber vCY7dT03Mk;

		private IConnectionLostEventsProxy x0x7kQBQ4U;

		private bool ohh739J5vg;

		bool IGraphicalMonitor.GraphDisplayed
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				bool flag = false;
				if (yoJ7xnWfry != null)
				{
					return yoJ7xnWfry.uMss9O9eY4();
				}
				return false;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public GraphicalMonitor()
		{
			JmLDt5P0cahRebTiifG.LYav19NzXHLb9();
			base..ctor();
			yoJ7xnWfry = null;
			d887odrwrX = null;
			KRw7wOo2DU = null;
			jRR7g0WjDm = null;
			wp278ekXHo = null;
			vCY7dT03Mk = null;
			x0x7kQBQ4U = null;
			ohh739J5vg = false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void sMK775s84B()
		{
			yoJ7xnWfry = null;
			yoJ7xnWfry = new xJXRtoo1hkZNIY6u3D();
			yoJ7xnWfry.qCE1Sg0vcp(d887odrwrX, KRw7wOo2DU, jRR7g0WjDm);
			yoJ7xnWfry.yHk1ALpFVG(wp278ekXHo);
			yoJ7xnWfry.BRT1iD6e7J();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void JoL7reBV5p()
		{
			try
			{
				yoJ7xnWfry.QHv1y3MbV3();
				yoJ7xnWfry = null;
				d887odrwrX = null;
				jRR7g0WjDm = null;
				wp278ekXHo = null;
				if (vCY7dT03Mk != null)
				{
					vCY7dT03Mk.UnsubscribeFromEvents(ComponentIds.ConnectionManagerWorker, EventIDs.ConnectionLostEvents);
					vCY7dT03Mk = null;
				}
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void aXC7IV47eR(bool P_0)
		{
			try
			{
				if (yoJ7xnWfry != null && ((Control)yoJ7xnWfry).IsHandleCreated)
				{
					if (P_0)
					{
						((Control)yoJ7xnWfry).Invoke((Delegate)new i0ScqWObbNrTjNtH8O(((Form)yoJ7xnWfry).Close));
					}
					else
					{
						((Control)yoJ7xnWfry).BeginInvoke((Delegate)new i0ScqWObbNrTjNtH8O(((Form)yoJ7xnWfry).Close));
					}
				}
			}
			finally
			{
				JoL7reBV5p();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void eMb7cAvEOK(object P_0, EventArgs P_1)
		{
			if (yoJ7xnWfry != null && yoJ7xnWfry.jA7sZ3Nqk6() == (x2IXLLeGQpqCfCUyuM)3)
			{
				yoJ7xnWfry.HfcsOe8ptR((HyN0of5EN6lv1IdeFn)1);
				yoJ7xnWfry.G1J1uSU90t();
				ohh739J5vg = true;
				yoJ7xnWfry.lN41YbCgkG();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void LUD7XyHcFy(object P_0, EventArgs P_1)
		{
			if (yoJ7xnWfry != null && ohh739J5vg)
			{
				yoJ7xnWfry.OcT1lyYLs4();
				yoJ7xnWfry.HfcsOe8ptR((HyN0of5EN6lv1IdeFn)0);
				yoJ7xnWfry.c6s1QIEgmk();
				ohh739J5vg = false;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IGraphicalMonitor.Initialize(object kernel, object shell, object availableGroups)
		{
			try
			{
				d887odrwrX = kernel;
				KRw7wOo2DU = shell;
				jRR7g0WjDm = availableGroups;
				vCY7dT03Mk = Cummins.INSITE.CNL.Factory.Factory.CreateInstance<IEventSubscriber>();
				vCY7dT03Mk.Initialize(d887odrwrX, this);
				x0x7kQBQ4U = Cummins.INSITE.CNL.Factory.Factory.CreateInstance<IConnectionLostEventsProxy>();
				x0x7kQBQ4U.ECMConnectionInterrupted += eMb7cAvEOK;
				x0x7kQBQ4U.ECMConnectionRestored += LUD7XyHcFy;
				vCY7dT03Mk.SubscribeToEvents(ComponentIds.ConnectionManagerWorker, EventIDs.ConnectionLostEvents, x0x7kQBQ4U);
			}
			catch (Exception)
			{
				throw;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IGraphicalMonitor.DisplayGraph()
		{
			if (yoJ7xnWfry == null)
			{
				sMK775s84B();
			}
			else if (!yoJ7xnWfry.uMss9O9eY4())
			{
				sMK775s84B();
			}
			else
			{
				((Control)yoJ7xnWfry).Focus();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IGraphicalMonitor.SetInitialSelection(object parameters)
		{
			wp278ekXHo = parameters;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IGraphicalMonitor.CloseGraph()
		{
			if (yoJ7xnWfry != null)
			{
				yoJ7xnWfry.HfcsOe8ptR((HyN0of5EN6lv1IdeFn)2);
			}
			aXC7IV47eR(true);
		}
	}
}
namespace dmuvY6MFkuQ2wt5kOy
{
	internal class q10BcS3EFwfVXwir4X : Dictionary<string, UiYLuk97VhDbAf3Vhs>
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public UiYLuk97VhDbAf3Vhs km87MjxNFV(string P_0)
		{
			UiYLuk97VhDbAf3Vhs result = null;
			Enumerator enumerator = GetEnumerator();
			while (enumerator.MoveNext())
			{
				if (enumerator.Current.Value.FZb7ETxAa1() == P_0)
				{
					result = enumerator.Current.Value;
					break;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int ubN799GdbF(string P_0)
		{
			int num = base[P_0].cZq7K9qjXV();
			int num2 = 0;
			Enumerator enumerator = GetEnumerator();
			while (enumerator.MoveNext())
			{
				if (enumerator.Current.Value.cZq7K9qjXV() == num)
				{
					num2++;
				}
			}
			return num2;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public q10BcS3EFwfVXwir4X()
		{
			JmLDt5P0cahRebTiifG.LYav19NzXHLb9();
			base..ctor();
		}
	}
}
namespace jxemMG6xsMfsxpqCJc
{
	internal class UiYLuk97VhDbAf3Vhs
	{
		public static readonly string FXl7AYqwAW;

		private string wlG7QFciHM;

		private string K2H7uNQ6Pd;

		private bool FUe7Y9VX4a;

		private Color X507lyh9Ma;

		private int uki7JFqMgp;

		private PlotChannelBase xGh7B2iSjv;

		private int zPF7TfVUQb;

		private PlotDataView Yux7z89G43;

		private int EZNrHHtvT0;

		private PlotLegendBase NZhrP9Wl84;

		private int M5Tr1jugf8;

		private PlotXAxis sXWrsprbJJ;

		private int EXyr0xAe0X;

		private PlotYAxis uMRr7iwA4B;

		private int cMjrrKp89O;

		private PlotDataCursorBase m1wrIHM79K;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public UiYLuk97VhDbAf3Vhs(string P_0, string P_1, bool P_2, Color P_3, int P_4, PlotChannelBase P_5, int P_6, PlotDataView P_7, int P_8, PlotLegendBase P_9, int P_10, PlotXAxis P_11, int P_12, PlotYAxis P_13, int P_14, PlotDataCursorBase P_15)
		{
			JmLDt5P0cahRebTiifG.LYav19NzXHLb9();
			base..ctor();
			wlG7QFciHM = P_0;
			K2H7uNQ6Pd = P_1;
			FUe7Y9VX4a = P_2;
			X507lyh9Ma = P_3;
			uki7JFqMgp = P_4;
			xGh7B2iSjv = P_5;
			zPF7TfVUQb = P_6;
			Yux7z89G43 = P_7;
			EZNrHHtvT0 = P_8;
			NZhrP9Wl84 = P_9;
			M5Tr1jugf8 = P_10;
			sXWrsprbJJ = P_11;
			EXyr0xAe0X = P_12;
			uMRr7iwA4B = P_13;
			cMjrrKp89O = P_14;
			m1wrIHM79K = P_15;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public UiYLuk97VhDbAf3Vhs QwU76gSbV3(string P_0, int P_1, PlotChannelBase P_2)
		{
			UiYLuk97VhDbAf3Vhs uiYLuk97VhDbAf3Vhs = (UiYLuk97VhDbAf3Vhs)MemberwiseClone();
			uiYLuk97VhDbAf3Vhs.wlG7QFciHM = P_0;
			uiYLuk97VhDbAf3Vhs.uki7JFqMgp = P_1;
			uiYLuk97VhDbAf3Vhs.xGh7B2iSjv = P_2;
			uiYLuk97VhDbAf3Vhs.X507lyh9Ma = P_2.Color;
			return uiYLuk97VhDbAf3Vhs;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public UiYLuk97VhDbAf3Vhs MNi7OeDCfg(string P_0, int P_1, PlotChannelBase P_2, int P_3, PlotYAxis P_4)
		{
			UiYLuk97VhDbAf3Vhs uiYLuk97VhDbAf3Vhs = (UiYLuk97VhDbAf3Vhs)MemberwiseClone();
			uiYLuk97VhDbAf3Vhs.wlG7QFciHM = P_0;
			uiYLuk97VhDbAf3Vhs.uki7JFqMgp = P_1;
			uiYLuk97VhDbAf3Vhs.xGh7B2iSjv = P_2;
			uiYLuk97VhDbAf3Vhs.uMRr7iwA4B = P_4;
			uiYLuk97VhDbAf3Vhs.EXyr0xAe0X = P_3;
			return uiYLuk97VhDbAf3Vhs;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public string ieA7ag0aGL()
		{
			return wlG7QFciHM;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public string FZb7ETxAa1()
		{
			return K2H7uNQ6Pd;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public bool Jfj7qnh01D()
		{
			return FUe7Y9VX4a;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public int nLk7huhFVj()
		{
			return uki7JFqMgp;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public void U9i75lYCVw(int P_0)
		{
			uki7JFqMgp = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public PlotChannelBase eIV7U9JZXu()
		{
			return xGh7B2iSjv;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public int cZq7K9qjXV()
		{
			return zPF7TfVUQb;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public PlotDataView sf174sRfk6()
		{
			return Yux7z89G43;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public int vKr7eYGNfF()
		{
			return EZNrHHtvT0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public PlotLegendBase qG07pMhs5O()
		{
			return NZhrP9Wl84;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public int aup7Gj8lWq()
		{
			return M5Tr1jugf8;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public PlotXAxis trB7RoePBR()
		{
			return sXWrsprbJJ;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public int nt972XDDfb()
		{
			return EXyr0xAe0X;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public PlotYAxis z9V7f9ZxhX()
		{
			return uMRr7iwA4B;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public int OoJ7Wj4d8F()
		{
			return cMjrrKp89O;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public PlotDataCursorBase Iab7y9IJMq()
		{
			return m1wrIHM79K;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static UiYLuk97VhDbAf3Vhs()
		{
			JmLDt5P0cahRebTiifG.LYav19NzXHLb9();
			FXl7AYqwAW = MnxsD0lrg8kZaUPt2I.OPAImF4404(6348);
		}
	}
}
namespace AqLHMMamOWxUktS9Ta
{
	internal delegate void i0ScqWObbNrTjNtH8O();
}
namespace Hu7X4gEroD3jDTyOIL
{
	internal enum LLwdmNZAEG00aiD7e6
	{

	}
}
namespace i2PRXtqo4Z5bQ3WRIJ
{
	internal enum FecrPet4bUAESlKRSs
	{

	}
}
namespace C2iZ1GhDJdOoXi2YMd
{
	internal enum d78MYpNQLCKwkS1VcZ
	{

	}
}
namespace MRtHuibDQYy79wcljF
{
	internal enum HyN0of5EN6lv1IdeFn
	{

	}
}
namespace qPYuBcDa9IXlTwe33U
{
	internal enum z270jTU1r1wLk7eb8B
	{

	}
}
namespace GJi4bIVZKYcPuwrRga
{
	internal enum XRbgaoKmn16bImAki0
	{

	}
}
namespace QIadPxnoakDxeCQSfq
{
	internal enum MuZSd846qSL8CEOpUv
	{

	}
}
namespace wi4XrPFQChoQqep7xu
{
	internal enum x2IXLLeGQpqCfCUyuM
	{

	}
}
namespace ng8J85vBrHbAuEp2Ea
{
	internal struct lHyiuRpvRLKBqfyHe9
	{
		public string aaYrcWlA7H;

		public long s7drXicJ9m;

		public int VaDrxUe24c;

		public int s5rro9rTp8;

		public string A46rwSBvbY;

		public string zK4rgN7EmU;

		public int V0vr8F8xS1;

		public string yYErdkWprd;

		public bool F3prkKJTTG;
	}
}
namespace HmIhwNLoVkWZe5vvEA
{
	internal enum FWcKfcGWl7hhTBulZY
	{

	}
}
namespace R6d0DRjWMq48MPPfYU
{
	internal enum V6PGe1R884NJ3GD2LA
	{
		MilliSecs,
		Secs,
		Mins,
		Hour
	}
}
namespace x7Xx5jmRQbBVnWxB3N
{
	internal class JCTT6V2WOmvGFmVhhn : EventArgs
	{
		private readonly FWcKfcGWl7hhTBulZY B3ur9kHPUf;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public JCTT6V2WOmvGFmVhhn(FWcKfcGWl7hhTBulZY P_0)
		{
			JmLDt5P0cahRebTiifG.LYav19NzXHLb9();
			base..ctor();
			B3ur9kHPUf = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public FWcKfcGWl7hhTBulZY yN7r3b3xCA()
		{
			return B3ur9kHPUf;
		}
	}
}
namespace NRo07PCcI8Ip92IPGD
{
	internal abstract class Gu5846fZtkbFxcYiZj : UserControl
	{
		private IContainer Q2EIxEaZqN;

		private Plot cwTIo8cwlD;

		private PlotToolBarStandard aUJIwv64Ly;

		private PlotToolBarButton BDQIgRt2xI;

		private PlotToolBarButton VirI87nEw5;

		private PlotToolBarButton vZZIdfKXoP;

		private PlotToolBarButton rBZIkBTTxY;

		private PlotToolBarButton FmEI328e5a;

		private PlotToolBarButton ClSIMP2VXP;

		private PlotToolBarButton m28I96iWhN;

		private PlotToolBarButton SNZI6GxNkC;

		private PlotToolBarButton zU9IO34J6h;

		private PlotToolBarButton cbPIaylrfX;

		private PlotToolBarButton iEEIZaQM0J;

		private PlotToolBarButton JgVIE3OQlq;

		private PlotToolBarButton RLiItEmkFl;

		private PlotToolBarButton aYGIqiXK3H;

		private PlotToolBarButton QEWINsiVlY;

		private PlotToolBarButton ag9IhfNYo0;

		private ImageList wKaI5c4YLk;

		private Timer CFJIbls9Jy;

		private static Color[] IOKIUeMi8A;

		private EventHandler<JCTT6V2WOmvGFmVhhn> xKSIDruN2d;

		protected Dictionary<Color, bool> sXXIKbG3Jf;

		protected q10BcS3EFwfVXwir4X majIVAtorX;

		protected bool fcaI4y8qJA;

		protected PlotLabelBase Nv6InnrU7I;

		protected PlotLabelBase SleIe45C5K;

		protected PlotLabelBase aBrIFJ0LCr;

		protected EventWaitHandle GoxIp6YRP4;

		protected LocalizedStringProvider vRuIv1Oyhy;

		private int OooIGB2yiw;

		private double oG5ILWY8SH;

		private FecrPet4bUAESlKRSs iT9IRehWPq;

		public event EventHandler<JCTT6V2WOmvGFmVhhn> GoxIXfyvru
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				EventHandler<JCTT6V2WOmvGFmVhhn> eventHandler = xKSIDruN2d;
				EventHandler<JCTT6V2WOmvGFmVhhn> eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler<JCTT6V2WOmvGFmVhhn> value2 = (EventHandler<JCTT6V2WOmvGFmVhhn>)Delegate.Combine(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref xKSIDruN2d, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				EventHandler<JCTT6V2WOmvGFmVhhn> eventHandler = xKSIDruN2d;
				EventHandler<JCTT6V2WOmvGFmVhhn> eventHandler2;
				do
				{
					eventHandler2 = eventHandler;
					EventHandler<JCTT6V2WOmvGFmVhhn> value2 = (EventHandler<JCTT6V2WOmvGFmVhhn>)Delegate.Remove(eventHandler2, value);
					eventHandler = Interlocked.CompareExchange(ref xKSIDruN2d, value2, eventHandler2);
				}
				while ((object)eventHandler != eventHandler2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void dOXr6c38id(object P_0, EventArgs P_1)
		{
			//IL_00ba: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c4: Expected O, but got Unknown
			cwTIo8cwlD.BackColor = Color.White;
			cwTIo8cwlD.DefaultGridLineColor = Color.Black;
			cwTIo8cwlD.ContextMenusEnabled = false;
			((ToolBar)aUJIwv64Ly).DropDownArrows = false;
			((ToolBarButton)BDQIgRt2xI).Style = (ToolBarButtonStyle)1;
			BDQIgRt2xI.Command = PlotToolBarCommandStyle.None;
			VirI87nEw5.Command = PlotToolBarCommandStyle.None;
			((ToolBarButton)VirI87nEw5).ImageIndex = 14;
			((ToolBarButton)QEWINsiVlY).ImageIndex = 15;
			cbPIaylrfX.Command = PlotToolBarCommandStyle.None;
			JgVIE3OQlq.Command = PlotToolBarCommandStyle.None;
			((ToolBarButton)iEEIZaQM0J).Visible = false;
			((ToolBarButton)iEEIZaQM0J).Enabled = false;
			((ToolBar)aUJIwv64Ly).ButtonClick += new ToolBarButtonClickEventHandler(QuLrOVdjpU);
			((ToolBarButton)BDQIgRt2xI).ToolTipText = vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)300);
			((ToolBarButton)VirI87nEw5).ToolTipText = vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)301);
			((ToolBarButton)vZZIdfKXoP).ToolTipText = vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)302);
			((ToolBarButton)rBZIkBTTxY).ToolTipText = vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)303);
			((ToolBarButton)FmEI328e5a).ToolTipText = vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)304);
			((ToolBarButton)ClSIMP2VXP).ToolTipText = vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)305);
			((ToolBarButton)m28I96iWhN).ToolTipText = vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)306);
			((ToolBarButton)SNZI6GxNkC).ToolTipText = vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)307);
			((ToolBarButton)zU9IO34J6h).ToolTipText = vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)308);
			((ToolBarButton)cbPIaylrfX).ToolTipText = vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)309);
			((ToolBarButton)iEEIZaQM0J).ToolTipText = vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)310);
			((ToolBarButton)JgVIE3OQlq).ToolTipText = vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)311);
			((ToolBarButton)RLiItEmkFl).ToolTipText = vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)215);
			((ToolBarButton)aYGIqiXK3H).ToolTipText = vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)313);
			((ToolBarButton)QEWINsiVlY).ToolTipText = vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)314);
			((ToolBarButton)ag9IhfNYo0).ToolTipText = vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)1101);
			CFJIbls9Jy.Interval = 500;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void QuLrOVdjpU(object P_0, ToolBarButtonClickEventArgs P_1)
		{
			//IL_0130: Unknown result type (might be due to invalid IL or missing references)
			//IL_00f7: Unknown result type (might be due to invalid IL or missing references)
			EventHandler<JCTT6V2WOmvGFmVhhn> eventHandler = xKSIDruN2d;
			if (P_1.Button.Name == ((ToolBarButton)JgVIE3OQlq).Name)
			{
				lCGrCSWlCj();
				return;
			}
			if (P_1.Button.Name == ((ToolBarButton)RLiItEmkFl).Name)
			{
				LgJIPRFYlE(false);
				return;
			}
			if (P_1.Button.Name == ((ToolBarButton)aYGIqiXK3H).Name)
			{
				LgJIPRFYlE(true);
				return;
			}
			if (P_1.Button.Name == ((ToolBarButton)QEWINsiVlY).Name)
			{
				try
				{
					if (PrinterSettings.InstalledPrinters.Count >= 1)
					{
						cwTIo8cwlD.PrintAdapter.PrintPageSetup();
					}
					else
					{
						MessageBox.Show(vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)610), vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)707), (MessageBoxButtons)0, (MessageBoxIcon)64);
					}
					return;
				}
				catch (Win32Exception)
				{
					MessageBox.Show(vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)610), vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)707), (MessageBoxButtons)0, (MessageBoxIcon)64);
					return;
				}
			}
			FWcKfcGWl7hhTBulZY fWcKfcGWl7hhTBulZY = (FWcKfcGWl7hhTBulZY)0;
			if (((ToolBarButton)BDQIgRt2xI).Name == P_1.Button.Name)
			{
				fWcKfcGWl7hhTBulZY = (FWcKfcGWl7hhTBulZY)1;
			}
			else if (((ToolBarButton)VirI87nEw5).Name == P_1.Button.Name)
			{
				fWcKfcGWl7hhTBulZY = (FWcKfcGWl7hhTBulZY)2;
			}
			else if (((ToolBarButton)cbPIaylrfX).Name == P_1.Button.Name)
			{
				fWcKfcGWl7hhTBulZY = (FWcKfcGWl7hhTBulZY)3;
			}
			else if (((ToolBarButton)ag9IhfNYo0).Name == P_1.Button.Name)
			{
				fWcKfcGWl7hhTBulZY = (FWcKfcGWl7hhTBulZY)4;
			}
			if (eventHandler != null && fWcKfcGWl7hhTBulZY != 0)
			{
				eventHandler(this, new JCTT6V2WOmvGFmVhhn(fWcKfcGWl7hhTBulZY));
			}
			else if (P_1.Button.Name == ((ToolBarButton)zU9IO34J6h).Name || P_1.Button.Name == ((ToolBarButton)m28I96iWhN).Name)
			{
				EKdIH450L6(true);
			}
			else
			{
				EKdIH450L6(false);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void SdXraLt5NY(object P_0, MouseEventArgs P_1)
		{
			if (!(cwTIo8cwlD.XAxes[0].Min <= 0.0))
			{
				iT9IRehWPq = (FecrPet4bUAESlKRSs)1;
				F2wrRFQ1fF();
				CFJIbls9Jy.Start();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void G5irZe4NZ4(object P_0, MouseEventArgs P_1)
		{
			if (!(cwTIo8cwlD.XAxes[0].Max >= oG5ILWY8SH))
			{
				iT9IRehWPq = (FecrPet4bUAESlKRSs)2;
				F2wrRFQ1fF();
				CFJIbls9Jy.Start();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void It1rEaMsmO(object P_0, MouseEventArgs P_1)
		{
			iT9IRehWPq = (FecrPet4bUAESlKRSs)0;
			CFJIbls9Jy.Stop();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void ahvrt6akAo(object P_0, MouseEventArgs P_1)
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			if ((int)P_1.Button != 0)
			{
				EKdIH450L6(false);
				Qd0r2VemXf();
				tuIrLmin2c();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void uehrq7cFy2(object P_0, MouseEventArgs P_1)
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			if ((int)P_1.Button != 0)
			{
				MnHrmPuevA(((PlotDataCursorBase)P_0).Pointer1.Position);
				EKdIH450L6(false);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void K1WrNyIS2m(object P_0, EventArgs P_1)
		{
			F2wrRFQ1fF();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected Color YiDrhcHwKZ()
		{
			Color result = Color.Black;
			Color[] iOKIUeMi8A = IOKIUeMi8A;
			foreach (Color color in iOKIUeMi8A)
			{
				if (sXXIKbG3Jf[color])
				{
					result = color;
					sXXIKbG3Jf[color] = false;
					break;
				}
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void FB7r5MSykG()
		{
			((Control)cwTIo8cwlD).SuspendLayout();
			if (fcaI4y8qJA)
			{
				GoxIp6YRP4.WaitOne();
				GoxIp6YRP4.Reset();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void Yf7rbgwmVC()
		{
			((Control)cwTIo8cwlD).ResumeLayout(false);
			if (fcaI4y8qJA)
			{
				GoxIp6YRP4.Set();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected int vaKrUn0V0T(out PlotDataView P_0)
		{
			P_0 = new PlotDataView();
			P_0.DockSide = AlignmentQuadSide.Top;
			P_0.DockOrder = ++OooIGB2yiw;
			return cwTIo8cwlD.DataViews.Add(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected int DnIrDI3GC9(int P_0, out PlotLegendBase P_1)
		{
			P_1 = new PlotLegendBasic();
			P_1.DockDataViewName = cwTIo8cwlD.DataViews[P_0].Name;
			P_1.DockStyle = PlotDockStyleAll.DataView;
			P_1.DockOrder = 0;
			((PlotLegendBasic)P_1).Spacing = 3.0;
			P_1.ForeColor = Color.Black;
			return cwTIo8cwlD.Legends.Add(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected int K0RrKqA7y8(int P_0, bool P_1, out PlotXAxis P_2)
		{
			//IL_0044: Unknown result type (might be due to invalid IL or missing references)
			//IL_004e: Expected O, but got Unknown
			P_2 = new PlotXAxis();
			P_2.Color = Color.Black;
			P_2.Visible = true;
			P_2.ScaleDisplay.Visible = P_1;
			P_2.Color = Color.Black;
			P_2.MouseMove += new MouseEventHandler(ahvrt6akAo);
			P_2.DockDataViewName = cwTIo8cwlD.DataViews[P_0].Name;
			P_2.Span = 20.0;
			return cwTIo8cwlD.XAxes.Add(P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected int yDGrVo3hMP(int P_0, string P_1, out PlotYAxis P_2)
		{
			P_2 = new PlotYAxis();
			P_2.Color = Color.Black;
			P_2.Title.Visible = true;
			P_2.Visible = true;
			P_2.Title.Color = Color.Black;
			P_2.DockDataViewName = cwTIo8cwlD.DataViews[P_0].Name;
			P_2.Span = 20.0;
			int num = cwTIo8cwlD.YAxes.Add(P_2);
			cwTIo8cwlD.YAxes[num].Title.Text = P_1;
			return num;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected int DkRr4RFCTu(int P_0, int P_1, out PlotDataCursorBase P_2)
		{
			//IL_0051: Unknown result type (might be due to invalid IL or missing references)
			//IL_005b: Expected O, but got Unknown
			P_2 = new PlotDataCursorChannels();
			P_2.XAxisName = cwTIo8cwlD.XAxes[P_0].Name;
			P_2.YAxisName = cwTIo8cwlD.YAxes[P_1].Name;
			P_2.MouseMove += new MouseEventHandler(uehrq7cFy2);
			((PlotDataCursorChannels)P_2).SnapToPoint = false;
			return cwTIo8cwlD.DataCursors.Add(P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected int eJ6rnRIAqT(string P_0, bool P_1, int P_2, int P_3, int P_4, out PlotChannelBase P_5)
		{
			if (P_1)
			{
				P_5 = new PlotChannelDifferential();
			}
			else
			{
				P_5 = new PlotChannelTrace();
			}
			P_5.LegendName = cwTIo8cwlD.Legends[P_2].Name;
			P_5.Name = P_0;
			P_5.XAxisName = cwTIo8cwlD.XAxes[P_3].Name;
			P_5.YAxisName = cwTIo8cwlD.YAxes[P_4].Name;
			P_5.SendXAxisTrackingData = true;
			P_5.SendYAxisTrackingData = true;
			int num = cwTIo8cwlD.Channels.Add(P_5);
			cwTIo8cwlD.Channels[num].Color = YiDrhcHwKZ();
			string titleText = ewqjA30Ig7KglKlcHq.a6UkkVfud(ewqjA30Ig7KglKlcHq.hLCoPQpTe(P_0), 30);
			cwTIo8cwlD.Channels[num].TitleText = titleText;
			if (P_1)
			{
				cwTIo8cwlD.Channels.Differential[num].Terminated = true;
				cwTIo8cwlD.Channels.Differential[num].Trace.Thickness = 3.0;
				cwTIo8cwlD.YAxes[P_4].Span = 20.0;
			}
			else
			{
				cwTIo8cwlD.Channels.Trace[num].Trace.Thickness = 3.0;
			}
			return num;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void xZTreDDuKD(PlotDataView P_0)
		{
			cwTIo8cwlD.DataViews.Remove(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void Ym5rFQhbiS(PlotLegendBase P_0)
		{
			cwTIo8cwlD.Legends.Remove(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void wEqrp7KmJR(PlotXAxis P_0)
		{
			cwTIo8cwlD.XAxes.Remove(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void LnCrvyCYXB(PlotYAxis P_0)
		{
			cwTIo8cwlD.YAxes.Remove(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected void lp3rGVIPMC(string P_0)
		{
			cwTIo8cwlD.Channels.Remove(majIVAtorX[P_0].eIV7U9JZXu());
			sXXIKbG3Jf[majIVAtorX[P_0].eIV7U9JZXu().Color] = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void tuIrLmin2c()
		{
			if (SleIe45C5K != null && aBrIFJ0LCr != null)
			{
				PlotXAxis plotXAxis = cwTIo8cwlD.XAxes[0];
				if (plotXAxis.Min <= 0.0)
				{
					SleIe45C5K.ForeColor = Color.Gray;
				}
				else
				{
					SleIe45C5K.ForeColor = Color.Black;
				}
				if (plotXAxis.Max >= oG5ILWY8SH)
				{
					aBrIFJ0LCr.ForeColor = Color.Gray;
				}
				else
				{
					aBrIFJ0LCr.ForeColor = Color.Black;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void F2wrRFQ1fF()
		{
			if (iT9IRehWPq != 0)
			{
				if (iT9IRehWPq == (FecrPet4bUAESlKRSs)1)
				{
					cwTIo8cwlD.XAxes[0].Min -= 1.0;
				}
				else if (iT9IRehWPq == (FecrPet4bUAESlKRSs)2)
				{
					cwTIo8cwlD.XAxes[0].Min += 1.0;
				}
				EKdIH450L6(false);
				Qd0r2VemXf();
				tuIrLmin2c();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void lkErjVj3R8()
		{
			for (int i = 0; i < cwTIo8cwlD.XAxes.Count; i++)
			{
				cwTIo8cwlD.XAxes[i].Min = 0.0;
				cwTIo8cwlD.XAxes[i].Visible = true;
				cwTIo8cwlD.XAxes[i].ScaleDisplay.Visible = true;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Qd0r2VemXf()
		{
			for (int i = 1; i < cwTIo8cwlD.XAxes.Count; i++)
			{
				cwTIo8cwlD.XAxes[i].Min = cwTIo8cwlD.XAxes[0].Min;
				cwTIo8cwlD.XAxes[i].Span = cwTIo8cwlD.XAxes[0].Span;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void MnHrmPuevA(double P_0)
		{
			Dictionary<string, UiYLuk97VhDbAf3Vhs>.Enumerator enumerator = majIVAtorX.GetEnumerator();
			while (enumerator.MoveNext())
			{
				enumerator.Current.Value.Iab7y9IJMq().Pointer1.Position = P_0;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Dispose(bool P_0)
		{
			if (P_0 && Q2EIxEaZqN != null)
			{
				Q2EIxEaZqN.Dispose();
			}
			((ContainerControl)this).Dispose(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void mQ6rflsrdY()
		{
			//IL_00f0: Unknown result type (might be due to invalid IL or missing references)
			//IL_00fa: Expected O, but got Unknown
			//IL_0101: Unknown result type (might be due to invalid IL or missing references)
			//IL_010b: Expected O, but got Unknown
			//IL_0a53: Unknown result type (might be due to invalid IL or missing references)
			//IL_0a5d: Expected O, but got Unknown
			Q2EIxEaZqN = new Container();
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(Gu5846fZtkbFxcYiZj));
			cwTIo8cwlD = new Plot();
			aUJIwv64Ly = new PlotToolBarStandard();
			BDQIgRt2xI = new PlotToolBarButton();
			VirI87nEw5 = new PlotToolBarButton();
			vZZIdfKXoP = new PlotToolBarButton();
			rBZIkBTTxY = new PlotToolBarButton();
			FmEI328e5a = new PlotToolBarButton();
			ClSIMP2VXP = new PlotToolBarButton();
			m28I96iWhN = new PlotToolBarButton();
			SNZI6GxNkC = new PlotToolBarButton();
			zU9IO34J6h = new PlotToolBarButton();
			cbPIaylrfX = new PlotToolBarButton();
			iEEIZaQM0J = new PlotToolBarButton();
			JgVIE3OQlq = new PlotToolBarButton();
			RLiItEmkFl = new PlotToolBarButton();
			aYGIqiXK3H = new PlotToolBarButton();
			QEWINsiVlY = new PlotToolBarButton();
			ag9IhfNYo0 = new PlotToolBarButton();
			wKaI5c4YLk = new ImageList(Q2EIxEaZqN);
			CFJIbls9Jy = new Timer(Q2EIxEaZqN);
			PlotToolBarButton plotToolBarButton = new PlotToolBarButton();
			PlotToolBarButton plotToolBarButton2 = new PlotToolBarButton();
			PlotToolBarButton plotToolBarButton3 = new PlotToolBarButton();
			PlotToolBarButton plotToolBarButton4 = new PlotToolBarButton();
			PlotToolBarButton plotToolBarButton5 = new PlotToolBarButton();
			PlotToolBarButton plotToolBarButton6 = new PlotToolBarButton();
			((Control)this).SuspendLayout();
			plotToolBarButton.LoadingBegin();
			plotToolBarButton.Command = PlotToolBarCommandStyle.Separator;
			((ToolBarButton)plotToolBarButton).Enabled = false;
			((ToolBarButton)plotToolBarButton).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(6376);
			((ToolBarButton)plotToolBarButton).Style = (ToolBarButtonStyle)3;
			plotToolBarButton.LoadingEnd();
			plotToolBarButton2.LoadingBegin();
			plotToolBarButton2.Command = PlotToolBarCommandStyle.Separator;
			((ToolBarButton)plotToolBarButton2).Enabled = false;
			((ToolBarButton)plotToolBarButton2).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(6416);
			((ToolBarButton)plotToolBarButton2).Style = (ToolBarButtonStyle)3;
			plotToolBarButton2.LoadingEnd();
			plotToolBarButton3.LoadingBegin();
			plotToolBarButton3.Command = PlotToolBarCommandStyle.Separator;
			((ToolBarButton)plotToolBarButton3).Enabled = false;
			((ToolBarButton)plotToolBarButton3).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(6456);
			((ToolBarButton)plotToolBarButton3).Style = (ToolBarButtonStyle)3;
			plotToolBarButton3.LoadingEnd();
			plotToolBarButton4.LoadingBegin();
			plotToolBarButton4.Command = PlotToolBarCommandStyle.Separator;
			((ToolBarButton)plotToolBarButton4).Enabled = false;
			((ToolBarButton)plotToolBarButton4).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(6496);
			((ToolBarButton)plotToolBarButton4).Style = (ToolBarButtonStyle)3;
			plotToolBarButton4.LoadingEnd();
			plotToolBarButton5.LoadingBegin();
			plotToolBarButton5.Command = PlotToolBarCommandStyle.Separator;
			((ToolBarButton)plotToolBarButton5).Enabled = false;
			((ToolBarButton)plotToolBarButton5).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(6538);
			((ToolBarButton)plotToolBarButton5).Style = (ToolBarButtonStyle)3;
			plotToolBarButton5.LoadingEnd();
			plotToolBarButton6.LoadingBegin();
			plotToolBarButton6.Command = PlotToolBarCommandStyle.Separator;
			((ToolBarButton)plotToolBarButton6).Enabled = false;
			((ToolBarButton)plotToolBarButton6).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(6580);
			((ToolBarButton)plotToolBarButton6).Style = (ToolBarButtonStyle)3;
			plotToolBarButton6.LoadingEnd();
			cwTIo8cwlD.LoadingBegin();
			((Control)cwTIo8cwlD).Dock = (DockStyle)5;
			((Control)cwTIo8cwlD).Location = new Point(0, 28);
			((Control)cwTIo8cwlD).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(6622);
			cwTIo8cwlD.Size = new Size(687, 475);
			((Control)cwTIo8cwlD).TabIndex = 0;
			cwTIo8cwlD.LoadingEnd();
			aUJIwv64Ly.LoadingBegin();
			((ToolBar)aUJIwv64Ly).Appearance = (ToolBarAppearance)1;
			((ToolBar)aUJIwv64Ly).Buttons.AddRange((ToolBarButton[])(object)new ToolBarButton[22]
			{
				BDQIgRt2xI, VirI87nEw5, plotToolBarButton, vZZIdfKXoP, rBZIkBTTxY, plotToolBarButton2, FmEI328e5a, ClSIMP2VXP, plotToolBarButton3, m28I96iWhN,
				SNZI6GxNkC, zU9IO34J6h, plotToolBarButton4, cbPIaylrfX, plotToolBarButton5, iEEIZaQM0J, JgVIE3OQlq, plotToolBarButton6, RLiItEmkFl, aYGIqiXK3H,
				QEWINsiVlY, ag9IhfNYo0
			});
			((ToolBar)aUJIwv64Ly).DropDownArrows = true;
			((ToolBar)aUJIwv64Ly).ImageList = wKaI5c4YLk;
			((Control)aUJIwv64Ly).Location = new Point(0, 0);
			((Control)aUJIwv64Ly).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(6636);
			aUJIwv64Ly.Plot = cwTIo8cwlD;
			((ToolBar)aUJIwv64Ly).ShowToolTips = true;
			((Control)aUJIwv64Ly).Size = new Size(687, 28);
			((Control)aUJIwv64Ly).TabIndex = 1;
			aUJIwv64Ly.LoadingEnd();
			BDQIgRt2xI.LoadingBegin();
			((ToolBarButton)BDQIgRt2xI).Enabled = false;
			((ToolBarButton)BDQIgRt2xI).ImageIndex = 0;
			((ToolBarButton)BDQIgRt2xI).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(6664);
			((ToolBarButton)BDQIgRt2xI).ToolTipText = MnxsD0lrg8kZaUPt2I.OPAImF4404(6732);
			BDQIgRt2xI.LoadingEnd();
			VirI87nEw5.LoadingBegin();
			VirI87nEw5.Command = PlotToolBarCommandStyle.TrackingPause;
			((ToolBarButton)VirI87nEw5).Enabled = false;
			((ToolBarButton)VirI87nEw5).ImageIndex = 14;
			((ToolBarButton)VirI87nEw5).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(6766);
			((ToolBarButton)VirI87nEw5).ToolTipText = MnxsD0lrg8kZaUPt2I.OPAImF4404(6832);
			VirI87nEw5.LoadingEnd();
			vZZIdfKXoP.LoadingBegin();
			vZZIdfKXoP.Command = PlotToolBarCommandStyle.AxesScroll;
			((ToolBarButton)vZZIdfKXoP).ImageIndex = 2;
			((ToolBarButton)vZZIdfKXoP).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(6864);
			((ToolBarButton)vZZIdfKXoP).Pushed = true;
			((ToolBarButton)vZZIdfKXoP).ToolTipText = MnxsD0lrg8kZaUPt2I.OPAImF4404(6924);
			vZZIdfKXoP.LoadingEnd();
			rBZIkBTTxY.LoadingBegin();
			rBZIkBTTxY.Command = PlotToolBarCommandStyle.AxesZoom;
			((ToolBarButton)rBZIkBTTxY).ImageIndex = 3;
			((ToolBarButton)rBZIkBTTxY).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(6950);
			((ToolBarButton)rBZIkBTTxY).ToolTipText = MnxsD0lrg8kZaUPt2I.OPAImF4404(7006);
			rBZIkBTTxY.LoadingEnd();
			FmEI328e5a.LoadingBegin();
			FmEI328e5a.Command = PlotToolBarCommandStyle.ZoomOut;
			((ToolBarButton)FmEI328e5a).ImageIndex = 4;
			((ToolBarButton)FmEI328e5a).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(7028);
			((ToolBarButton)FmEI328e5a).ToolTipText = MnxsD0lrg8kZaUPt2I.OPAImF4404(7082);
			FmEI328e5a.LoadingEnd();
			ClSIMP2VXP.LoadingBegin();
			ClSIMP2VXP.Command = PlotToolBarCommandStyle.ZoomIn;
			((ToolBarButton)ClSIMP2VXP).ImageIndex = 5;
			((ToolBarButton)ClSIMP2VXP).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(7102);
			((ToolBarButton)ClSIMP2VXP).ToolTipText = MnxsD0lrg8kZaUPt2I.OPAImF4404(7154);
			ClSIMP2VXP.LoadingEnd();
			m28I96iWhN.LoadingBegin();
			m28I96iWhN.Command = PlotToolBarCommandStyle.Select;
			((ToolBarButton)m28I96iWhN).ImageIndex = 6;
			((ToolBarButton)m28I96iWhN).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(7172);
			((ToolBarButton)m28I96iWhN).Pushed = true;
			((ToolBarButton)m28I96iWhN).ToolTipText = MnxsD0lrg8kZaUPt2I.OPAImF4404(7224);
			m28I96iWhN.LoadingEnd();
			SNZI6GxNkC.LoadingBegin();
			SNZI6GxNkC.Command = PlotToolBarCommandStyle.ZoomBox;
			((ToolBarButton)SNZI6GxNkC).ImageIndex = 7;
			((ToolBarButton)SNZI6GxNkC).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(7240);
			((ToolBarButton)SNZI6GxNkC).ToolTipText = MnxsD0lrg8kZaUPt2I.OPAImF4404(7294);
			SNZI6GxNkC.LoadingEnd();
			zU9IO34J6h.LoadingBegin();
			zU9IO34J6h.Command = PlotToolBarCommandStyle.DataCursor;
			((ToolBarButton)zU9IO34J6h).ImageIndex = 8;
			((ToolBarButton)zU9IO34J6h).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(7314);
			((ToolBarButton)zU9IO34J6h).ToolTipText = MnxsD0lrg8kZaUPt2I.OPAImF4404(7374);
			zU9IO34J6h.LoadingEnd();
			cbPIaylrfX.LoadingBegin();
			cbPIaylrfX.Command = PlotToolBarCommandStyle.Edit;
			((ToolBarButton)cbPIaylrfX).ImageIndex = 9;
			((ToolBarButton)cbPIaylrfX).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(7400);
			((ToolBarButton)cbPIaylrfX).ToolTipText = MnxsD0lrg8kZaUPt2I.OPAImF4404(7448);
			cbPIaylrfX.LoadingEnd();
			iEEIZaQM0J.LoadingBegin();
			iEEIZaQM0J.Command = PlotToolBarCommandStyle.Copy;
			((ToolBarButton)iEEIZaQM0J).ImageIndex = 10;
			((ToolBarButton)iEEIZaQM0J).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(7460);
			((ToolBarButton)iEEIZaQM0J).ToolTipText = MnxsD0lrg8kZaUPt2I.OPAImF4404(7508);
			iEEIZaQM0J.LoadingEnd();
			JgVIE3OQlq.LoadingBegin();
			JgVIE3OQlq.Command = PlotToolBarCommandStyle.Save;
			((ToolBarButton)JgVIE3OQlq).ImageIndex = 11;
			((ToolBarButton)JgVIE3OQlq).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(7546);
			((ToolBarButton)JgVIE3OQlq).ToolTipText = MnxsD0lrg8kZaUPt2I.OPAImF4404(7594);
			JgVIE3OQlq.LoadingEnd();
			RLiItEmkFl.LoadingBegin();
			RLiItEmkFl.Command = PlotToolBarCommandStyle.None;
			((ToolBarButton)RLiItEmkFl).ImageIndex = 12;
			((ToolBarButton)RLiItEmkFl).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(7606);
			((ToolBarButton)RLiItEmkFl).ToolTipText = MnxsD0lrg8kZaUPt2I.OPAImF4404(7656);
			((ToolBarButton)RLiItEmkFl).Enabled = true;
			RLiItEmkFl.LoadingEnd();
			aYGIqiXK3H.LoadingBegin();
			aYGIqiXK3H.Command = PlotToolBarCommandStyle.None;
			((ToolBarButton)aYGIqiXK3H).ImageIndex = 13;
			((ToolBarButton)aYGIqiXK3H).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(7670);
			((ToolBarButton)aYGIqiXK3H).ToolTipText = MnxsD0lrg8kZaUPt2I.OPAImF4404(7724);
			((ToolBarButton)aYGIqiXK3H).Enabled = true;
			aYGIqiXK3H.LoadingEnd();
			QEWINsiVlY.LoadingBegin();
			QEWINsiVlY.Command = PlotToolBarCommandStyle.None;
			((ToolBarButton)QEWINsiVlY).ImageIndex = 15;
			((ToolBarButton)QEWINsiVlY).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(7742);
			((ToolBarButton)QEWINsiVlY).ToolTipText = MnxsD0lrg8kZaUPt2I.OPAImF4404(7800);
			((ToolBarButton)QEWINsiVlY).Enabled = true;
			QEWINsiVlY.LoadingEnd();
			ag9IhfNYo0.LoadingBegin();
			ag9IhfNYo0.Command = PlotToolBarCommandStyle.None;
			((ToolBarButton)ag9IhfNYo0).ImageIndex = 16;
			((ToolBarButton)ag9IhfNYo0).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(7824);
			((ToolBarButton)ag9IhfNYo0).ToolTipText = MnxsD0lrg8kZaUPt2I.OPAImF4404(7896);
			ag9IhfNYo0.LoadingEnd();
			wKaI5c4YLk.ImageStream = (ImageListStreamer)componentResourceManager.GetObject(MnxsD0lrg8kZaUPt2I.OPAImF4404(7936));
			wKaI5c4YLk.TransparentColor = Color.Transparent;
			wKaI5c4YLk.Images.SetKeyName(0, "");
			wKaI5c4YLk.Images.SetKeyName(1, "");
			wKaI5c4YLk.Images.SetKeyName(2, "");
			wKaI5c4YLk.Images.SetKeyName(3, "");
			wKaI5c4YLk.Images.SetKeyName(4, "");
			wKaI5c4YLk.Images.SetKeyName(5, "");
			wKaI5c4YLk.Images.SetKeyName(6, "");
			wKaI5c4YLk.Images.SetKeyName(7, "");
			wKaI5c4YLk.Images.SetKeyName(8, "");
			wKaI5c4YLk.Images.SetKeyName(9, "");
			wKaI5c4YLk.Images.SetKeyName(10, "");
			wKaI5c4YLk.Images.SetKeyName(11, "");
			wKaI5c4YLk.Images.SetKeyName(12, "");
			wKaI5c4YLk.Images.SetKeyName(13, "");
			wKaI5c4YLk.Images.SetKeyName(14, MnxsD0lrg8kZaUPt2I.OPAImF4404(7984));
			wKaI5c4YLk.Images.SetKeyName(15, MnxsD0lrg8kZaUPt2I.OPAImF4404(8004));
			wKaI5c4YLk.Images.SetKeyName(16, MnxsD0lrg8kZaUPt2I.OPAImF4404(8034));
			CFJIbls9Jy.Tick += K1WrNyIS2m;
			((ContainerControl)this).AutoScaleDimensions = new SizeF(6f, 13f);
			((ContainerControl)this).AutoScaleMode = (AutoScaleMode)1;
			((Control)this).Controls.Add((Control)(object)cwTIo8cwlD);
			((Control)this).Controls.Add((Control)(object)aUJIwv64Ly);
			((Control)this).Name = MnxsD0lrg8kZaUPt2I.OPAImF4404(8078);
			((Control)this).Size = new Size(687, 503);
			((UserControl)this).Load += dOXr6c38id;
			((Control)this).ResumeLayout(false);
			((Control)this).PerformLayout();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected Gu5846fZtkbFxcYiZj(LocalizedStringProvider P_0)
		{
			JmLDt5P0cahRebTiifG.LYav19NzXHLb9();
			OooIGB2yiw = -1;
			((UserControl)this)..ctor();
			mQ6rflsrdY();
			fcaI4y8qJA = false;
			Nv6InnrU7I = null;
			SleIe45C5K = null;
			aBrIFJ0LCr = null;
			OooIGB2yiw = -1;
			oG5ILWY8SH = 0.0;
			majIVAtorX = new q10BcS3EFwfVXwir4X();
			GoxIp6YRP4 = new EventWaitHandle(initialState: true, EventResetMode.ManualReset);
			vRuIv1Oyhy = P_0;
			sXXIKbG3Jf = new Dictionary<Color, bool>(6);
			Color[] iOKIUeMi8A = IOKIUeMi8A;
			foreach (Color key in iOKIUeMi8A)
			{
				sXXIKbG3Jf.Add(key, value: true);
			}
		}

		public abstract int AddChannel(string P_0, string P_1);

		public abstract void RemoveChannel(string P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void lCGrCSWlCj()
		{
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			//IL_000d: Expected O, but got Unknown
			//IL_004f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0055: Invalid comparison between Unknown and I4
			SaveFileDialog val = new SaveFileDialog();
			((FileDialog)val).Title = vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)212);
			((FileDialog)val).Filter = vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)500);
			((FileDialog)val).InitialDirectory = ewqjA30Ig7KglKlcHq.F2XgE6dCb();
			if ((int)((CommonDialog)val).ShowDialog() == 1)
			{
				cwTIo8cwlD.SnapShot.Save(((FileDialog)val).FileName);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void GLErWoeWDq(string P_0)
		{
			if (P_0.EndsWith(MnxsD0lrg8kZaUPt2I.OPAImF4404(8100)))
			{
				cwTIo8cwlD.FileDeliminator = PlotFileDeliminator.Comma;
			}
			else
			{
				cwTIo8cwlD.FileDeliminator = PlotFileDeliminator.Tab;
			}
			string[] array = new string[10];
			for (int i = 0; i < cwTIo8cwlD.Channels.Count; i++)
			{
				array[i] = cwTIo8cwlD.Channels[i].TitleText;
				cwTIo8cwlD.Channels[i].TitleText = ewqjA30Ig7KglKlcHq.hLCoPQpTe(cwTIo8cwlD.Channels[i].Name);
			}
			cwTIo8cwlD.SaveDataToFile(P_0);
			for (int j = 0; j < cwTIo8cwlD.Channels.Count; j++)
			{
				cwTIo8cwlD.Channels[j].TitleText = array[j];
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public StreamWriter qKVrSSD5Ti(Stream P_0, PlotFileDeliminator P_1)
		{
			string[] array = new string[10];
			for (int i = 0; i < cwTIo8cwlD.Channels.Count; i++)
			{
				array[i] = cwTIo8cwlD.Channels[i].TitleText;
				cwTIo8cwlD.Channels[i].TitleText = ewqjA30Ig7KglKlcHq.hLCoPQpTe(cwTIo8cwlD.Channels[i].Name);
			}
			cwTIo8cwlD.FileDeliminator = P_1;
			cwTIo8cwlD.SaveDataToStream(P_0, out var streamWriter);
			for (int j = 0; j < cwTIo8cwlD.Channels.Count; j++)
			{
				cwTIo8cwlD.Channels[j].TitleText = array[j];
			}
			return streamWriter;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void eAprynsGZd(Stream P_0)
		{
			cwTIo8cwlD.LoadDataFromStream(P_0);
			oG5ILWY8SH = cwTIo8cwlD.Channels[0].GetX(cwTIo8cwlD.Channels[0].IndexLast);
			lkErjVj3R8();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void c5NriO30TD(string P_0)
		{
			string[] array = new string[10];
			for (int i = 0; i < cwTIo8cwlD.Channels.Count; i++)
			{
				array[i] = cwTIo8cwlD.Channels[i].TitleText;
				cwTIo8cwlD.Channels[i].TitleText = ewqjA30Ig7KglKlcHq.hLCoPQpTe(cwTIo8cwlD.Channels[i].Name);
			}
			cwTIo8cwlD.SavePropertiesToFile(P_0);
			for (int j = 0; j < cwTIo8cwlD.Channels.Count; j++)
			{
				cwTIo8cwlD.Channels[j].TitleText = array[j];
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void sl6rACws5e(string P_0)
		{
			//IL_0032: Unknown result type (might be due to invalid IL or missing references)
			//IL_003c: Expected O, but got Unknown
			cwTIo8cwlD.LoadPropertiesFromFile(P_0);
			for (int i = 0; i < cwTIo8cwlD.XAxes.Count; i++)
			{
				cwTIo8cwlD.XAxes[i].MouseMove += new MouseEventHandler(ahvrt6akAo);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void INRrQsFllt(Stream P_0)
		{
			cwTIo8cwlD.LoadPropertiesFromStream(new StreamReader(P_0));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void m1nruZuJjC(string P_0)
		{
			if (Nv6InnrU7I == null)
			{
				if (cwTIo8cwlD.Labels.Count > 0)
				{
					Nv6InnrU7I = cwTIo8cwlD.Labels[0];
				}
				else
				{
					Nv6InnrU7I = new PlotLabelBasic();
					Nv6InnrU7I.Text = "";
					Nv6InnrU7I.ForeColor = Color.Black;
					cwTIo8cwlD.Labels.Add(Nv6InnrU7I);
				}
			}
			Nv6InnrU7I.Text = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void mUOrY8Vp38()
		{
			if (!fcaI4y8qJA)
			{
				GoxIp6YRP4.Set();
				fcaI4y8qJA = true;
				((ToolBarButton)VirI87nEw5).Enabled = true;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void omrrlajOOy()
		{
			if (fcaI4y8qJA)
			{
				GoxIp6YRP4.WaitOne();
				GoxIp6YRP4.Reset();
				fcaI4y8qJA = false;
				((ToolBarButton)BDQIgRt2xI).Enabled = true;
				((ToolBarButton)VirI87nEw5).Enabled = false;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void gKUrJZLcuM(string P_0, double P_1, double P_2)
		{
			oG5ILWY8SH = P_1;
			majIVAtorX[P_0].eIV7U9JZXu().AddXY(P_1, P_2);
			if (P_1 < 3.0)
			{
				majIVAtorX[P_0].z9V7f9ZxhX().Span = 20.0;
				majIVAtorX[P_0].z9V7f9ZxhX().Min = P_2 - majIVAtorX[P_0].z9V7f9ZxhX().Span / 2.0;
			}
			if (majIVAtorX[P_0].trB7RoePBR().Tracking.Enabled)
			{
				majIVAtorX[P_0].trB7RoePBR().Min = ((oG5ILWY8SH < 20.0) ? 0.0 : (oG5ILWY8SH - 20.0));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void cvYrBdIfgr()
		{
			if (cwTIo8cwlD.XAxes.Count >= 1)
			{
				cwTIo8cwlD.XAxes[0].ScaleDisplay.Visible = true;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void rVcrT9A4QX(string P_0)
		{
			if (cwTIo8cwlD.XAxes.Count >= 1)
			{
				cwTIo8cwlD.XAxes[0].Title.Text = P_0;
				cwTIo8cwlD.XAxes[0].Title.Visible = true;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void XWSrzoXW6U(FWcKfcGWl7hhTBulZY P_0, bool P_1)
		{
			switch (P_0)
			{
			case (FWcKfcGWl7hhTBulZY)1:
				((ToolBarButton)BDQIgRt2xI).Enabled = P_1;
				break;
			case (FWcKfcGWl7hhTBulZY)2:
				((ToolBarButton)VirI87nEw5).Enabled = P_1;
				break;
			case (FWcKfcGWl7hhTBulZY)3:
				((ToolBarButton)cbPIaylrfX).Enabled = P_1;
				break;
			case (FWcKfcGWl7hhTBulZY)4:
				((ToolBarButton)ag9IhfNYo0).Enabled = P_1;
				break;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void EKdIH450L6(bool P_0)
		{
			for (int i = 0; i < cwTIo8cwlD.XAxes.Count; i++)
			{
				cwTIo8cwlD.XAxes[i].Tracking.Enabled = P_0;
			}
			if (fcaI4y8qJA)
			{
				((ToolBarButton)BDQIgRt2xI).Enabled = !P_0;
				((ToolBarButton)VirI87nEw5).Enabled = P_0;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void LgJIPRFYlE(bool P_0)
		{
			//IL_0094: Unknown result type (might be due to invalid IL or missing references)
			//IL_0100: Unknown result type (might be due to invalid IL or missing references)
			//IL_00e5: Unknown result type (might be due to invalid IL or missing references)
			//IL_00cb: Unknown result type (might be due to invalid IL or missing references)
			//IL_0079: Unknown result type (might be due to invalid IL or missing references)
			string empty = string.Empty;
			string empty2 = string.Empty;
			empty = vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)707);
			empty2 = vRuIv1Oyhy.GetLocalizedString((LLwdmNZAEG00aiD7e6)610);
			if (P_0)
			{
				try
				{
					if (PrinterSettings.InstalledPrinters.Count >= 1)
					{
						cwTIo8cwlD.PrintAdapter.PrintPreview();
					}
					else
					{
						MessageBox.Show(empty2.ToString(), empty.ToString(), (MessageBoxButtons)0, (MessageBoxIcon)64);
					}
					return;
				}
				catch (Win32Exception)
				{
					MessageBox.Show(empty2.ToString(), empty.ToString(), (MessageBoxButtons)0, (MessageBoxIcon)64);
					return;
				}
			}
			try
			{
				if (PrinterSettings.InstalledPrinters.Count >= 1)
				{
					cwTIo8cwlD.PrintAdapter.ShowPrintDialog = true;
					cwTIo8cwlD.PrintAdapter.Print();
				}
				else
				{
					MessageBox.Show(empty2.ToString(), empty.ToString(), (MessageBoxButtons)0, (MessageBoxIcon)64);
				}
			}
			catch (Win32Exception)
			{
				MessageBox.Show(empty2.ToString(), empty.ToString(), (MessageBoxButtons)0, (MessageBoxIcon)64);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void zv6I1o9cqn()
		{
			//IL_00dd: Unknown result type (might be due to invalid IL or missing references)
			//IL_00e7: Expected O, but got Unknown
			//IL_00f4: Unknown result type (might be due to invalid IL or missing references)
			//IL_00fe: Expected O, but got Unknown
			//IL_011c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0126: Expected O, but got Unknown
			//IL_01fc: Unknown result type (might be due to invalid IL or missing references)
			//IL_0206: Expected O, but got Unknown
			//IL_0213: Unknown result type (might be due to invalid IL or missing references)
			//IL_021d: Expected O, but got Unknown
			//IL_023b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0245: Expected O, but got Unknown
			if (SleIe45C5K == null)
			{
				SleIe45C5K = new PlotLabelBasic();
				SleIe45C5K.Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(8112);
				SleIe45C5K.ForeColor = Color.Black;
				cwTIo8cwlD.Labels.Add(SleIe45C5K);
				SleIe45C5K.DockOrder = 0;
				SleIe45C5K.DockPercentStart = 0.0;
				SleIe45C5K.DockPercentStop = 0.5;
				SleIe45C5K.DockDataViewName = cwTIo8cwlD.DataViews[0].Name;
				SleIe45C5K.DockSide = AlignmentQuadSide.Bottom;
				SleIe45C5K.TextLayout.AlignmentHorizontal.Style = (StringAlignment)0;
				SleIe45C5K.MouseLeft += new MouseEventHandler(SdXraLt5NY);
				SleIe45C5K.MouseUp += new MouseEventHandler(It1rEaMsmO);
				Font font = SleIe45C5K.Font;
				SleIe45C5K.Font = new Font(font.FontFamily, 12f, (FontStyle)1);
			}
			if (aBrIFJ0LCr == null)
			{
				aBrIFJ0LCr = new PlotLabelBasic();
				aBrIFJ0LCr.Text = MnxsD0lrg8kZaUPt2I.OPAImF4404(8120);
				aBrIFJ0LCr.ForeColor = Color.Black;
				cwTIo8cwlD.Labels.Add(aBrIFJ0LCr);
				aBrIFJ0LCr.DockOrder = 0;
				aBrIFJ0LCr.DockPercentStart = 0.5;
				aBrIFJ0LCr.DockPercentStop = 1.0;
				aBrIFJ0LCr.DockDataViewName = cwTIo8cwlD.DataViews[0].Name;
				aBrIFJ0LCr.DockSide = AlignmentQuadSide.Bottom;
				aBrIFJ0LCr.TextLayout.AlignmentHorizontal.Style = (StringAlignment)2;
				aBrIFJ0LCr.MouseLeft += new MouseEventHandler(G5irZe4NZ4);
				aBrIFJ0LCr.MouseUp += new MouseEventHandler(It1rEaMsmO);
				Font font2 = aBrIFJ0LCr.Font;
				aBrIFJ0LCr.Font = new Font(font2.FontFamily, 12f, (FontStyle)1);
			}
			tuIrLmin2c();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void guDIsN0BMo()
		{
			for (int i = 0; i < cwTIo8cwlD.XAxes.Count; i++)
			{
				cwTIo8cwlD.XAxes[i].Color = Color.Black;
			}
			for (int j = 0; j < cwTIo8cwlD.YAxes.Count; j++)
			{
				cwTIo8cwlD.YAxes[j].Color = Color.Black;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void PWLI0Uflam(double P_0)
		{
			oG5ILWY8SH = P_0;
			for (int i = 0; i < cwTIo8cwlD.Channels.Count; i++)
			{
				PlotLimitLineX plotLimitLineX = null;
				plotLimitLineX = new PlotLimitLineX();
				plotLimitLineX.ClippingStyle = PlotClippingStyle.DataView;
				plotLimitLineX.XAxisName = cwTIo8cwlD.Channels[i].XAxisName;
				plotLimitLineX.YAxisName = cwTIo8cwlD.Channels[i].YAxisName;
				plotLimitLineX.XReference = oG5ILWY8SH;
				plotLimitLineX.Color = Color.Gray;
				plotLimitLineX.Line.Thickness = 3.0;
				plotLimitLineX.Line.Style = PlotPenStyle.Dash;
				cwTIo8cwlD.Limits.Add(plotLimitLineX);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void q7aI70UeMC(double P_0)
		{
			oG5ILWY8SH = P_0;
			for (int i = 0; i < cwTIo8cwlD.Channels.Count; i++)
			{
				cwTIo8cwlD.Channels[i].AddNull(P_0);
				if (cwTIo8cwlD.Channels[i].XAxis.Tracking.Enabled)
				{
					cwTIo8cwlD.Channels[i].XAxis.Min = ((oG5ILWY8SH < 20.0) ? 0.0 : (oG5ILWY8SH - 20.0));
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static Gu5846fZtkbFxcYiZj()
		{
			JmLDt5P0cahRebTiifG.LYav19NzXHLb9();
			IOKIUeMi8A = new Color[6]
			{
				Color.Red,
				Color.Blue,
				Color.Green,
				Color.Violet,
				Color.Brown,
				Color.Black
			};
		}
	}
}
namespace fVqwGUSBnT2UKedpWV
{
	internal class lPIGTZWwp0Gwjw6qLs : Gu5846fZtkbFxcYiZj
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public lPIGTZWwp0Gwjw6qLs(LocalizedStringProvider P_0)
		{
			JmLDt5P0cahRebTiifG.LYav19NzXHLb9();
			base..ctor(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override int AddChannel(string P_0, string P_1)
		{
			int num = -1;
			PlotChannelBase plotChannelBase = null;
			FB7r5MSykG();
			UiYLuk97VhDbAf3Vhs uiYLuk97VhDbAf3Vhs = majIVAtorX.km87MjxNFV(P_1);
			if (uiYLuk97VhDbAf3Vhs == null)
			{
				PlotDataView plotDataView = null;
				PlotLegendBase plotLegendBase = null;
				PlotXAxis plotXAxis = null;
				PlotYAxis plotYAxis = null;
				PlotDataCursorBase plotDataCursorBase = null;
				int num2 = vaKrUn0V0T(out plotDataView);
				int num3 = DnIrDI3GC9(num2, out plotLegendBase);
				int num4 = K0RrKqA7y8(num2, false, out plotXAxis);
				int num5 = yDGrVo3hMP(num2, P_1, out plotYAxis);
				int num6 = DkRr4RFCTu(num4, num5, out plotDataCursorBase);
				bool flag = ((P_1 == UiYLuk97VhDbAf3Vhs.FXl7AYqwAW) ? true : false);
				num = eJ6rnRIAqT(P_0, flag, num3, num4, num5, out plotChannelBase);
				uiYLuk97VhDbAf3Vhs = new UiYLuk97VhDbAf3Vhs(P_0, P_1, flag, plotChannelBase.Color, num, plotChannelBase, num2, plotDataView, num3, plotLegendBase, num4, plotXAxis, num5, plotYAxis, num6, plotDataCursorBase);
				majIVAtorX.Add(P_0, uiYLuk97VhDbAf3Vhs);
			}
			else
			{
				num = eJ6rnRIAqT(P_0, uiYLuk97VhDbAf3Vhs.Jfj7qnh01D(), uiYLuk97VhDbAf3Vhs.vKr7eYGNfF(), uiYLuk97VhDbAf3Vhs.aup7Gj8lWq(), uiYLuk97VhDbAf3Vhs.nt972XDDfb(), out plotChannelBase);
				majIVAtorX.Add(P_0, uiYLuk97VhDbAf3Vhs.QwU76gSbV3(P_0, num, plotChannelBase));
			}
			Yf7rbgwmVC();
			return num;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void RemoveChannel(string P_0)
		{
			FB7r5MSykG();
			if (majIVAtorX.ubN799GdbF(P_0) == 1)
			{
				lp3rGVIPMC(P_0);
				wEqrp7KmJR(majIVAtorX[P_0].trB7RoePBR());
				LnCrvyCYXB(majIVAtorX[P_0].z9V7f9ZxhX());
				Ym5rFQhbiS(majIVAtorX[P_0].qG07pMhs5O());
				xZTreDDuKD(majIVAtorX[P_0].sf174sRfk6());
			}
			else
			{
				lp3rGVIPMC(P_0);
			}
			majIVAtorX.Remove(P_0);
			Yf7rbgwmVC();
		}
	}
}
namespace N92EARiGPWWybrZNel
{
	internal class stxEhHyj9TZk1R0mt9 : Gu5846fZtkbFxcYiZj
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public stxEhHyj9TZk1R0mt9(LocalizedStringProvider P_0)
		{
			JmLDt5P0cahRebTiifG.LYav19NzXHLb9();
			base..ctor(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override int AddChannel(string P_0, string P_1)
		{
			int num = -1;
			PlotChannelBase plotChannelBase = null;
			UiYLuk97VhDbAf3Vhs uiYLuk97VhDbAf3Vhs = null;
			FB7r5MSykG();
			PlotDataView plotDataView = null;
			PlotLegendBase plotLegendBase = null;
			PlotXAxis plotXAxis = null;
			PlotYAxis plotYAxis = null;
			PlotDataCursorBase plotDataCursorBase = null;
			int num2 = vaKrUn0V0T(out plotDataView);
			int num3 = DnIrDI3GC9(num2, out plotLegendBase);
			int num4 = K0RrKqA7y8(num2, false, out plotXAxis);
			int num5 = yDGrVo3hMP(num2, P_1, out plotYAxis);
			int num6 = DkRr4RFCTu(num4, num5, out plotDataCursorBase);
			bool flag = ((P_1 == UiYLuk97VhDbAf3Vhs.FXl7AYqwAW) ? true : false);
			num = eJ6rnRIAqT(P_0, flag, num3, num4, num5, out plotChannelBase);
			uiYLuk97VhDbAf3Vhs = new UiYLuk97VhDbAf3Vhs(P_0, P_1, flag, plotChannelBase.Color, num, plotChannelBase, num2, plotDataView, num3, plotLegendBase, num4, plotXAxis, num5, plotYAxis, num6, plotDataCursorBase);
			majIVAtorX.Add(P_0, uiYLuk97VhDbAf3Vhs);
			Yf7rbgwmVC();
			return num;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override void RemoveChannel(string P_0)
		{
			FB7r5MSykG();
			lp3rGVIPMC(P_0);
			wEqrp7KmJR(majIVAtorX[P_0].trB7RoePBR());
			LnCrvyCYXB(majIVAtorX[P_0].z9V7f9ZxhX());
			Ym5rFQhbiS(majIVAtorX[P_0].qG07pMhs5O());
			xZTreDDuKD(majIVAtorX[P_0].sf174sRfk6());
			majIVAtorX.Remove(P_0);
			Yf7rbgwmVC();
		}
	}
}
namespace Cummins.INSITE.CNL.GraphicalMonitoring.Properties
{
	[CompilerGenerated]
	[DebuggerNonUserCode]
	[GeneratedCode("System.Resources.Tools.StronglyTypedResourceBuilder", "2.0.0.0")]
	internal class Resources
	{
		private static ResourceManager resourceMan;

		private static CultureInfo resourceCulture;

		[EditorBrowsable(EditorBrowsableState.Advanced)]
		internal static ResourceManager ResourceManager
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				if (object.ReferenceEquals(resourceMan, null))
				{
					ResourceManager resourceManager = new ResourceManager("Cummins.INSITE.CNL.GraphicalMonitoring.Properties.Resources", typeof(Resources).Assembly);
					resourceMan = resourceManager;
				}
				return resourceMan;
			}
		}

		[EditorBrowsable(EditorBrowsableState.Advanced)]
		internal static CultureInfo Culture
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return resourceCulture;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				resourceCulture = value;
			}
		}

		internal static Icon Graph
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				//IL_0022: Unknown result type (might be due to invalid IL or missing references)
				//IL_0028: Expected O, but got Unknown
				object obj = ResourceManager.GetObject(MnxsD0lrg8kZaUPt2I.OPAImF4404(8128), resourceCulture);
				return (Icon)obj;
			}
		}

		internal static Icon PageSetup
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				//IL_0022: Unknown result type (might be due to invalid IL or missing references)
				//IL_0028: Expected O, but got Unknown
				object obj = ResourceManager.GetObject(MnxsD0lrg8kZaUPt2I.OPAImF4404(8142), resourceCulture);
				return (Icon)obj;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal Resources()
		{
			JmLDt5P0cahRebTiifG.LYav19NzXHLb9();
			base..ctor();
		}
	}
}
namespace o4psuUQwqEwg9nhGLU
{
	internal static class hIlFMOAYll4OnUq4sH
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public static Gu5846fZtkbFxcYiZj TPUIjyu1KH(z270jTU1r1wLk7eb8B P_0, LocalizedStringProvider P_1)
		{
			Gu5846fZtkbFxcYiZj gu5846fZtkbFxcYiZj = null;
			return P_0 switch
			{
				(z270jTU1r1wLk7eb8B)1 => new stxEhHyj9TZk1R0mt9(P_1), 
				(z270jTU1r1wLk7eb8B)2 => new lPIGTZWwp0Gwjw6qLs(P_1), 
				_ => throw new ArgumentException(MnxsD0lrg8kZaUPt2I.OPAImF4404(8164)), 
			};
		}
	}
}
internal class <Module>{56AA9401-FFF6-4DD2-ACFA-1B0FA9E11C2D}
{
}
namespace hHPGItYuxeCvNOBH39
{
	internal class pghXc0urlQvV3wD00v
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module yGCI2tTH90;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void IKgv19NN1c0nf(int typemdt)
		{
			Type type = yGCI2tTH90.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)yGCI2tTH90.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public pghXc0urlQvV3wD00v()
		{
			JmLDt5P0cahRebTiifG.LYav19NzXHLb9();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static pghXc0urlQvV3wD00v()
		{
			JmLDt5P0cahRebTiifG.LYav19NzXHLb9();
			yGCI2tTH90 = typeof(pghXc0urlQvV3wD00v).Assembly.ManifestModule;
		}
	}
}
namespace YcsyoeJPV0DW6gWAfX
{
	internal class MnxsD0lrg8kZaUPt2I
	{
		internal class CyEJw3BBaxosHZj3HQ : Attribute
		{
			internal class gLeLc0TtP0swCIA6La<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public gLeLc0TtP0swCIA6La()
				{
					JmLDt5P0cahRebTiifG.LYav19NzXHLb9();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[CyEJw3BBaxosHZj3HQ(typeof(MnxsD0lrg8kZaUPt2I/CyEJw3BBaxosHZj3HQ/gLeLc0TtP0swCIA6La<object>[]))]
			public CyEJw3BBaxosHZj3HQ(object P_0)
			{
				JmLDt5P0cahRebTiifG.LYav19NzXHLb9();
				base..ctor();
			}
		}

		internal class hiP7gizo7cPPuwQ9Kh
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CyEJw3BBaxosHZj3HQ(typeof(MnxsD0lrg8kZaUPt2I/CyEJw3BBaxosHZj3HQ/gLeLc0TtP0swCIA6La<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (NeXcDgd1HW(Convert.ToBase64String(typeof(MnxsD0lrg8kZaUPt2I).Assembly.GetName().GetPublicKeyToken()), MnxsD0lrg8kZaUPt2I.OPAImF4404(8222)) != MnxsD0lrg8kZaUPt2I.OPAImF4404(8228))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[CyEJw3BBaxosHZj3HQ(typeof(MnxsD0lrg8kZaUPt2I/CyEJw3BBaxosHZj3HQ/gLeLc0TtP0swCIA6La<object>[]))]
			internal static string NeXcDgd1HW(string P_0, string P_1)
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
			public hiP7gizo7cPPuwQ9Kh()
			{
				JmLDt5P0cahRebTiifG.LYav19NzXHLb9();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint QSFtvePH8GjYR2Cmwki([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr Hw11VkPP8c73Gek3wMl();

		internal struct pSF8gbP1UsqEJ6fsfsX
		{
			internal bool d1scKIXYxG;

			internal byte[] f3ucVrxBUa;
		}

		[Flags]
		private enum vZgsVZPsrnU0P661f1f
		{

		}

		private static byte[] sVLco0pwcr;

		private static byte[] yVQcwlbYI9;

		private static int w5Fc9ieIl2;

		private static bool SVrc65Myfl;

		private static int dnpcaAvrOv;

		internal static QSFtvePH8GjYR2Cmwki RdscEIkhdK;

		internal static QSFtvePH8GjYR2Cmwki vgvctCxp2t;

		private static int zINcN6mpW2;

		private static bool LVfchxlET1;

		private static int Swvc5qNK4y;

		private static IntPtr vblcbuJFA8;

		internal static Hashtable xeXcUmR8p6;

		private static byte[] envcgwL4rP;

		private static byte[] wJpc8vo6og;

		private static object P6Ec3IppNB;

		private static int[] uHUcMQERZA;

		private static long ySMcZKhrdH;

		private static IntPtr Uvgcko67Nd;

		private static long PsWcq9Fen4;

		private static IntPtr onhcdYeV2b;

		private static SortedList HZVcO4AgnT;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static MnxsD0lrg8kZaUPt2I()
		{
			sVLco0pwcr = new byte[0];
			yVQcwlbYI9 = new byte[0];
			envcgwL4rP = new byte[0];
			wJpc8vo6og = new byte[0];
			onhcdYeV2b = IntPtr.Zero;
			Uvgcko67Nd = IntPtr.Zero;
			P6Ec3IppNB = new string[0];
			uHUcMQERZA = new int[0];
			w5Fc9ieIl2 = 1;
			SVrc65Myfl = false;
			HZVcO4AgnT = new SortedList();
			dnpcaAvrOv = 0;
			ySMcZKhrdH = 0L;
			RdscEIkhdK = null;
			vgvctCxp2t = null;
			PsWcq9Fen4 = 0L;
			zINcN6mpW2 = 0;
			LVfchxlET1 = false;
			Swvc5qNK4y = 0;
			vblcbuJFA8 = IntPtr.Zero;
			xeXcUmR8p6 = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void iW0v19NFDeDyV()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CyEJw3BBaxosHZj3HQ(typeof(MnxsD0lrg8kZaUPt2I/CyEJw3BBaxosHZj3HQ/gLeLc0TtP0swCIA6La<object>[]))]
		static string OPAImF4404(int P_0)
		{
			int num = 122;
			int num5 = default(int);
			byte[] array2 = default(byte[]);
			byte[] array = default(byte[]);
			int num3 = default(int);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			MemoryStream memoryStream = default(MemoryStream);
			byte[] array4 = default(byte[]);
			byte[] array5 = default(byte[]);
			int num2 = default(int);
			byte[] array6 = default(byte[]);
			BinaryReader binaryReader = default(BinaryReader);
			CryptoStream cryptoStream = default(CryptoStream);
			byte[] array3 = default(byte[]);
			ICryptoTransform transform = default(ICryptoTransform);
			while (true)
			{
				int num6;
				int num4;
				switch (num)
				{
				case 32:
					num5 = 161 - 53;
					num6 = 33;
					goto IL_07c8;
				case 25:
					array2[30] = (byte)num5;
					num = 278;
					break;
				case 138:
					array[10] = (byte)num3;
					num4 = 178;
					if (false)
					{
						goto case 50;
					}
					goto IL_07cc;
				case 50:
					array2[21] = (byte)num5;
					num6 = 265;
					goto IL_07c8;
				case 336:
					array2[21] = 130;
					num4 = 238;
					if (WMf9RCU7UsZovPbvKT())
					{
						goto case 321;
					}
					goto IL_07cc;
				case 321:
					array2[20] = 128;
					num6 = 23;
					goto IL_07c8;
				case 14:
					array2[30] = 150;
					num4 = 281;
					goto IL_07cc;
				case 237:
					num5 = 191 - 63;
					num = 60;
					break;
				case 18:
					num5 = 36 + 43;
					num4 = 166;
					if (1 == 0)
					{
						goto case 73;
					}
					goto IL_07cc;
				case 73:
					array2[3] = 108;
					num6 = 335;
					goto IL_07c8;
				case 38:
					array[8] = 118;
					num = 183;
					break;
				case 27:
					num3 = 100 + 13;
					num = 212;
					break;
				case 127:
					array2[25] = (byte)num5;
					num6 = 120;
					goto IL_07c8;
				case 26:
					num5 = 49 + 18;
					num4 = 21;
					if (!WMf9RCU7UsZovPbvKT())
					{
						goto IL_07cc;
					}
					goto case 215;
				case 80:
					array[7] = (byte)num3;
					num = 143;
					break;
				case 158:
					array2[23] = (byte)num5;
					num6 = 330;
					goto IL_07c8;
				case 189:
					num5 = 193 - 64;
					num = 341;
					break;
				case 292:
					array2[27] = 169;
					num4 = 139;
					if (!cOjh92Ab9OGhcJc4ik())
					{
						goto case 192;
					}
					goto IL_07cc;
				case 192:
					num5 = 9 + 98;
					num4 = 70;
					if (!cOjh92Ab9OGhcJc4ik())
					{
						goto case 241;
					}
					goto IL_07cc;
				case 241:
					num5 = 216 - 72;
					num = 328;
					break;
				case 234:
					array2[20] = 140;
					num = 321;
					break;
				case 322:
					jXUFNw4VdY4IDX1xSf(rijndaelManaged, CipherMode.CBC);
					num6 = 239;
					goto IL_07c8;
				case 212:
					array[15] = (byte)num3;
					num = 45;
					break;
				case 224:
					array2[2] = 92;
					num = 40;
					break;
				case 7:
					array[0] = (byte)num3;
					num4 = 214;
					goto IL_07cc;
				case 326:
					mSIucY1QE2u3wnMIDC(memoryStream);
					num4 = 39;
					if (1 == 0)
					{
						goto case 106;
					}
					goto IL_07cc;
				case 106:
					num3 = 28 + 92;
					num6 = 76;
					goto IL_07c8;
				case 160:
					array[0] = 122;
					num6 = 286;
					goto IL_07c8;
				case 283:
					array2[19] = 215;
					num4 = 256;
					if (1 == 0)
					{
						goto case 124;
					}
					goto IL_07cc;
				case 124:
					array2[26] = (byte)num5;
					num = 259;
					break;
				case 223:
					num3 = 46 + 113;
					num4 = 267;
					if (cOjh92Ab9OGhcJc4ik())
					{
						goto IL_07cc;
					}
					goto case 174;
				case 325:
					num5 = 222 - 74;
					num = 127;
					break;
				case 105:
					array2[0] = (byte)num5;
					num4 = 154;
					goto IL_07cc;
				case 119:
					envcgwL4rP = (byte[])KVHiH9m5dRCTWcur4Q(memoryStream);
					num4 = 326;
					if (!cOjh92Ab9OGhcJc4ik())
					{
						goto case 139;
					}
					goto IL_07cc;
				case 101:
					array[14] = 174;
					num4 = 95;
					if (!cOjh92Ab9OGhcJc4ik())
					{
						goto case 137;
					}
					goto IL_07cc;
				case 137:
					array[14] = (byte)num3;
					num6 = 17;
					goto IL_07c8;
				case 302:
					num5 = 121 - 39;
					num = 90;
					break;
				case 64:
					array2[1] = 116;
					num4 = 263;
					if (cOjh92Ab9OGhcJc4ik())
					{
						goto IL_07cc;
					}
					goto case 337;
				case 43:
					num5 = 165 - 55;
					num4 = 294;
					if (WMf9RCU7UsZovPbvKT())
					{
						goto case 122;
					}
					goto IL_07cc;
				case 122:
					if (envcgwL4rP.Length != 0)
					{
						goto case 69;
					}
					num4 = 31;
					if (!WMf9RCU7UsZovPbvKT())
					{
						goto IL_07cc;
					}
					goto case 159;
				case 293:
					array2[11] = (byte)num5;
					num4 = 247;
					if (false)
					{
						goto case 247;
					}
					goto IL_07cc;
				case 247:
					num5 = 175 - 58;
					num6 = 228;
					goto IL_07c8;
				case 22:
					array2[20] = 124;
					num6 = 234;
					goto IL_07c8;
				case 94:
					array2[4] = (byte)num5;
					num4 = 246;
					goto IL_07cc;
				case 20:
					array[12] = (byte)num3;
					num4 = 87;
					if (false)
					{
						goto case 275;
					}
					goto IL_07cc;
				case 275:
					array2[28] = 112;
					num = 317;
					break;
				case 225:
					array2[28] = 99;
					num6 = 275;
					goto IL_07c8;
				case 300:
					array2[4] = (byte)num5;
					num4 = 56;
					goto IL_07cc;
				case 213:
					array2[15] = (byte)num5;
					num4 = 344;
					goto IL_07cc;
				case 45:
					array[15] = 111;
					num4 = 255;
					if (cOjh92Ab9OGhcJc4ik())
					{
						goto IL_07cc;
					}
					goto case 125;
				case 57:
					array4[5] = array5[2];
					num4 = 250;
					if (1 == 0)
					{
						goto case 186;
					}
					goto IL_07cc;
				case 186:
					array2[15] = (byte)num5;
					num = 296;
					break;
				case 341:
					array2[6] = (byte)num5;
					num4 = 117;
					goto IL_07cc;
				case 243:
					array2[26] = 236;
					num4 = 74;
					if (false)
					{
						goto case 340;
					}
					goto IL_07cc;
				case 340:
					num3 = 166 + 24;
					num4 = 232;
					if (1 == 0)
					{
						goto case 6;
					}
					goto IL_07cc;
				case 6:
					array2[31] = 131;
					num = 131;
					break;
				case 194:
					array2[14] = (byte)num5;
					num = 302;
					break;
				case 236:
					array2[16] = 125;
					num4 = 182;
					if (cOjh92Ab9OGhcJc4ik())
					{
						goto IL_07cc;
					}
					goto case 214;
				case 46:
					num5 = 146 - 73;
					num6 = 16;
					goto IL_07c8;
				case 139:
					num5 = 109 - 46;
					num4 = 310;
					if (false)
					{
						goto case 17;
					}
					goto IL_07cc;
				case 17:
					array[14] = 112;
					num = 27;
					break;
				case 171:
					array[3] = (byte)num3;
					num4 = 111;
					if (1 == 0)
					{
						goto case 144;
					}
					goto IL_07cc;
				case 144:
					array2[7] = (byte)num5;
					num6 = 9;
					goto IL_07c8;
				case 148:
					array2[14] = 96;
					num6 = 338;
					goto IL_07c8;
				case 11:
					num5 = 96 + 65;
					num4 = 123;
					if (1 == 0)
					{
						goto case 28;
					}
					goto IL_07cc;
				case 28:
					num5 = 49 + 81;
					goto case 184;
				default:
					num = 184;
					break;
				case 199:
					array2[18] = 201;
					num4 = 260;
					goto IL_07cc;
				case 97:
					array2[4] = 92;
					num6 = 55;
					goto IL_07c8;
				case 195:
					array2[9] = 130;
					num6 = 198;
					goto IL_07c8;
				case 21:
					array2[7] = (byte)num5;
					num4 = 115;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 176;
				case 176:
					num5 = 7 + 49;
					num4 = 274;
					if (!cOjh92Ab9OGhcJc4ik())
					{
						goto case 340;
					}
					goto IL_07cc;
				case 269:
					array[15] = (byte)num3;
					num4 = 266;
					goto IL_07cc;
				case 191:
					array2[31] = (byte)num5;
					num4 = 147;
					goto IL_07cc;
				case 131:
					array2[31] = 216;
					num6 = 32;
					goto IL_07c8;
				case 107:
					array[11] = (byte)num3;
					num4 = 196;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 69;
				case 69:
					num2 = Mf90bh7qkynsHSoCDv(envcgwL4rP, P_0);
					num4 = 347;
					if (!cOjh92Ab9OGhcJc4ik())
					{
						goto case 138;
					}
					goto IL_07cc;
				case 76:
					array[1] = (byte)num3;
					num = 282;
					break;
				case 156:
					array2[2] = 161;
					num6 = 224;
					goto IL_07c8;
				case 288:
					array6 = (byte[])PrgQpxQdJaY9ZG8uC3(binaryReader, (int)Iy9oaaLG1fpEKkXaFQ(mBDXbai8QfGBPMBHVM(binaryReader)));
					num = 301;
					break;
				case 315:
					array2[24] = (byte)num5;
					num4 = 28;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 256;
				case 256:
					array2[19] = 160;
					num4 = 289;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 83;
				case 83:
					array2[14] = (byte)num5;
					num = 75;
					break;
				case 328:
					array2[16] = (byte)num5;
					num4 = 236;
					if (cOjh92Ab9OGhcJc4ik())
					{
						goto IL_07cc;
					}
					goto case 274;
				case 175:
					array = new byte[16];
					num = 160;
					break;
				case 286:
					num3 = 186 - 62;
					num = 7;
					break;
				case 210:
					array2[0] = 191;
					num4 = 81;
					goto IL_07cc;
				case 323:
					array2[28] = (byte)num5;
					num = 225;
					break;
				case 309:
					array[12] = (byte)num3;
					num6 = 132;
					goto IL_07c8;
				case 294:
					array2[22] = (byte)num5;
					num = 190;
					break;
				case 60:
					array2[12] = (byte)num5;
					num4 = 179;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 188;
				case 188:
					array[6] = 129;
					num = 37;
					break;
				case 272:
					array2[13] = 114;
					num4 = 276;
					goto IL_07cc;
				case 273:
					zXpDGMY3SnBxi7fdBy(binaryReader);
					num4 = 69;
					if (!WMf9RCU7UsZovPbvKT())
					{
						goto IL_07cc;
					}
					goto case 99;
				case 99:
					array2[5] = (byte)num5;
					num4 = 189;
					if (cOjh92Ab9OGhcJc4ik())
					{
						goto IL_07cc;
					}
					goto case 91;
				case 91:
					array[8] = 23;
					num4 = 38;
					goto IL_07cc;
				case 208:
					array[2] = 191;
					num4 = 332;
					goto IL_07cc;
				case 316:
					num5 = 210 - 70;
					num4 = 114;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 318;
				case 318:
					array4[11] = array5[5];
					num6 = 257;
					goto IL_07c8;
				case 182:
					num5 = 217 - 120;
					num4 = 205;
					goto IL_07cc;
				case 230:
					num5 = 221 - 73;
					num = 268;
					break;
				case 116:
					array2[18] = (byte)num5;
					num6 = 254;
					goto IL_07c8;
				case 185:
					num5 = 143 - 47;
					num4 = 270;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 67;
				case 67:
					array[3] = 148;
					num4 = 146;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 307;
				case 307:
					num5 = 157 - 52;
					num = 227;
					break;
				case 203:
					array2[6] = (byte)num5;
					num4 = 312;
					if (cOjh92Ab9OGhcJc4ik())
					{
						goto IL_07cc;
					}
					goto case 339;
				case 339:
					num3 = 128 - 42;
					num4 = 107;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 133;
				case 133:
					array[4] = (byte)num3;
					num4 = 85;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 123;
				case 123:
					array2[18] = (byte)num5;
					num4 = 59;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 154;
				case 154:
					array2[0] = 132;
					num = 210;
					break;
				case 266:
					array[15] = 147;
					num4 = 41;
					goto IL_07cc;
				case 61:
					num3 = 163 - 54;
					num4 = 109;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 260;
				case 260:
					num5 = 46 + 70;
					WMf9RCU7UsZovPbvKT();
					if (cOjh92Ab9OGhcJc4ik())
					{
						num4 = 152;
						goto IL_07cc;
					}
					num6 = 125;
					goto IL_07c8;
				case 166:
					array2[6] = (byte)num5;
					num6 = 218;
					goto IL_07c8;
				case 42:
					array2[20] = (byte)num5;
					num6 = 142;
					goto IL_07c8;
				case 205:
					array2[16] = (byte)num5;
					num4 = 209;
					goto IL_07cc;
				case 10:
					array2[20] = 162;
					num6 = 140;
					goto IL_07c8;
				case 150:
					array2[8] = 163;
					num6 = 126;
					goto IL_07c8;
				case 198:
					num5 = 140 - 46;
					num4 = 211;
					if (!WMf9RCU7UsZovPbvKT())
					{
						goto IL_07cc;
					}
					goto case 62;
				case 62:
					num5 = 81 + 89;
					num4 = 249;
					if (cOjh92Ab9OGhcJc4ik())
					{
						goto IL_07cc;
					}
					goto case 8;
				case 8:
					juwENl9oCAflD5gade(cryptoStream);
					num = 119;
					break;
				case 3:
					array[8] = 144;
					num6 = 91;
					goto IL_07c8;
				case 346:
					array2[10] = 20;
					num6 = 12;
					goto IL_07c8;
				case 219:
					array2[9] = 135;
					num4 = 280;
					if (!WMf9RCU7UsZovPbvKT())
					{
						goto IL_07cc;
					}
					goto case 179;
				case 179:
					array2[12] = 26;
					num = 272;
					break;
				case 263:
					num5 = 133 - 97;
					num = 202;
					break;
				case 279:
					array2[15] = (byte)num5;
					num4 = 63;
					goto IL_07cc;
				case 178:
					num3 = 170 - 56;
					num = 177;
					break;
				case 222:
					array2[3] = 167;
					num6 = 73;
					goto IL_07c8;
				case 303:
					num5 = 159 - 53;
					num4 = 323;
					if (cOjh92Ab9OGhcJc4ik())
					{
						goto IL_07cc;
					}
					goto case 149;
				case 149:
					array[4] = (byte)num3;
					num6 = 72;
					goto IL_07c8;
				case 66:
					num3 = 170 - 56;
					num6 = 80;
					goto IL_07c8;
				case 93:
					array[7] = (byte)num3;
					num = 66;
					break;
				case 190:
					array2[22] = 98;
					num4 = 113;
					goto IL_07cc;
				case 96:
					array2[11] = (byte)num5;
					num6 = 108;
					goto IL_07c8;
				case 33:
					array2[31] = (byte)num5;
					num = 253;
					break;
				case 235:
					num3 = 111 - 7;
					num4 = 193;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 51;
				case 51:
					array[12] = (byte)num3;
					num4 = 102;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 343;
				case 343:
					num5 = 222 - 74;
					num6 = 96;
					goto IL_07c8;
				case 183:
					num3 = 36 + 117;
					num = 100;
					break;
				case 344:
					array2[15] = 6;
					num4 = 241;
					goto IL_07cc;
				case 90:
					array2[14] = (byte)num5;
					num4 = 314;
					goto IL_07cc;
				case 128:
					num5 = 50 - 32;
					num = 141;
					break;
				case 329:
					cOIlNqgladgPpugEuY(cryptoStream, array6, 0, array6.Length);
					num = 8;
					break;
				case 332:
					array[3] = 41;
					num = 67;
					break;
				case 56:
					num5 = 133 + 63;
					num4 = 78;
					goto IL_07cc;
				case 36:
					num5 = 37 + 33;
					num6 = 172;
					goto IL_07c8;
				case 267:
					array[10] = (byte)num3;
					num6 = 340;
					goto IL_07c8;
				case 296:
					num5 = 103 + 23;
					num = 34;
					break;
				case 196:
					num3 = 11 + 114;
					num = 121;
					break;
				case 92:
					array[13] = 134;
					num = 130;
					break;
				case 214:
					array[0] = 61;
					num = 106;
					break;
				case 142:
					num5 = 228 - 76;
					num6 = 157;
					goto IL_07c8;
				case 147:
					array3 = array2;
					num4 = 175;
					goto IL_07cc;
				case 159:
					NpMgc2kuldlm2RCI9h(mBDXbai8QfGBPMBHVM(binaryReader), 0L);
					num6 = 299;
					goto IL_07c8;
				case 218:
					array2[6] = 147;
					num4 = 320;
					goto IL_07cc;
				case 126:
					num5 = 43 + 94;
					num4 = 153;
					goto IL_07cc;
				case 35:
					if (array5.Length <= 0)
					{
						goto case 251;
					}
					num = 264;
					break;
				case 170:
					array2[17] = 170;
					num6 = 2;
					goto IL_07c8;
				case 281:
					array2[30] = 95;
					num = 62;
					break;
				case 187:
					array2[14] = (byte)num5;
					num4 = 148;
					if (!WMf9RCU7UsZovPbvKT())
					{
						goto IL_07cc;
					}
					goto case 218;
				case 240:
					num3 = 246 - 82;
					num4 = 295;
					if (!cOjh92Ab9OGhcJc4ik())
					{
						goto case 106;
					}
					goto IL_07cc;
				case 108:
					array2[11] = 191;
					num6 = 128;
					goto IL_07c8;
				case 47:
					array2[12] = 102;
					num = 237;
					break;
				case 299:
					OQQZwmGZp7jtAQqIJH(true);
					num6 = 288;
					goto IL_07c8;
				case 85:
					array[5] = 107;
					num = 271;
					break;
				case 285:
					array[15] = (byte)num3;
					num4 = 48;
					goto IL_07cc;
				case 306:
					num5 = 117 + 109;
					num = 124;
					break;
				case 207:
					array2[24] = 144;
					num = 345;
					break;
				case 84:
					array4[9] = array5[4];
					num4 = 318;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 65;
				case 65:
					array2[10] = 158;
					num = 346;
					break;
				case 330:
					num5 = 107 - 96;
					num = 29;
					break;
				case 250:
					array4[7] = array5[3];
					num4 = 84;
					goto IL_07cc;
				case 100:
					array[8] = (byte)num3;
					num = 240;
					break;
				case 88:
					array2[8] = 99;
					num4 = 180;
					goto IL_07cc;
				case 255:
					num3 = 38 + 115;
					num6 = 269;
					goto IL_07c8;
				case 204:
					array[2] = 102;
					num6 = 245;
					goto IL_07c8;
				case 161:
					array2[22] = 207;
					num6 = 174;
					goto IL_07c8;
				case 121:
					array[11] = (byte)num3;
					num4 = 61;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 78;
				case 78:
					array2[4] = (byte)num5;
					num = 36;
					break;
				case 63:
					num5 = 134 - 44;
					num = 186;
					break;
				case 282:
					array[1] = 206;
					num6 = 231;
					goto IL_07c8;
				case 168:
					array2[18] = (byte)num5;
					num4 = 11;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 248;
				case 248:
					num5 = 194 - 64;
					num6 = 277;
					goto IL_07c8;
				case 2:
					array2[18] = 65;
					num4 = 242;
					goto IL_07cc;
				case 135:
					array[13] = (byte)num3;
					num4 = 262;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 132;
				case 132:
					num3 = 53 + 27;
					num4 = 135;
					if (!WMf9RCU7UsZovPbvKT())
					{
						goto IL_07cc;
					}
					goto case 268;
				case 268:
					array2[3] = (byte)num5;
					num = 15;
					break;
				case 75:
					num5 = 100 + 13;
					num6 = 194;
					goto IL_07c8;
				case 217:
					array[9] = 126;
					num4 = 235;
					if (cOjh92Ab9OGhcJc4ik())
					{
						goto IL_07cc;
					}
					goto case 140;
				case 140:
					num5 = 169 - 56;
					num = 244;
					break;
				case 39:
					mSIucY1QE2u3wnMIDC(cryptoStream);
					num4 = 273;
					if (!WMf9RCU7UsZovPbvKT())
					{
						goto IL_07cc;
					}
					goto case 24;
				case 24:
					array[5] = 161;
					num6 = 86;
					goto IL_07c8;
				case 211:
					array2[9] = (byte)num5;
					num = 54;
					break;
				case 59:
					array2[18] = 136;
					num4 = 199;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 280;
				case 280:
					array2[10] = 94;
					num4 = 65;
					if (cOjh92Ab9OGhcJc4ik())
					{
						goto IL_07cc;
					}
					goto case 146;
				case 146:
					num3 = 115 - 31;
					num = 171;
					break;
				case 338:
					num5 = 154 - 51;
					num = 83;
					break;
				case 229:
					array[5] = (byte)num3;
					num6 = 24;
					goto IL_07c8;
				case 174:
					array2[23] = 109;
					num4 = 185;
					if (!WMf9RCU7UsZovPbvKT())
					{
						goto IL_07cc;
					}
					goto case 129;
				case 129:
					array[11] = (byte)num3;
					num = 339;
					break;
				case 71:
					array5 = (byte[])iBYFJitdLpcATNUbXT(npRCpEpSZqQw7OJoxU(C1FWkSqZUc1DXXBp2Y(typeof(MnxsD0lrg8kZaUPt2I).TypeHandle).Assembly));
					num4 = 290;
					if (cOjh92Ab9OGhcJc4ik())
					{
						goto IL_07cc;
					}
					goto case 263;
				case 181:
					array2[9] = (byte)num5;
					num6 = 195;
					goto IL_07c8;
				case 111:
					num3 = 12 + 32;
					num4 = 149;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 4;
				case 4:
					array2[6] = (byte)num5;
					num = 18;
					break;
				case 319:
					num5 = 159 - 53;
					num6 = 279;
					goto IL_07c8;
				case 202:
					array2[1] = (byte)num5;
					num4 = 156;
					goto IL_07cc;
				case 206:
					array4[3] = array5[1];
					num4 = 57;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 197;
				case 197:
					num5 = 107 + 90;
					num4 = 25;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 87;
				case 87:
					num3 = 145 + 14;
					num4 = 309;
					goto IL_07cc;
				case 41:
					num3 = 170 - 56;
					num4 = 285;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 58;
				case 58:
					array2[27] = (byte)num5;
					num4 = 292;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 238;
				case 238:
					num5 = 92 + 20;
					num4 = 50;
					goto IL_07cc;
				case 265:
					array2[21] = 136;
					num6 = 43;
					goto IL_07c8;
				case 259:
					num5 = 206 - 68;
					num4 = 200;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 72;
				case 72:
					array[4] = 156;
					num4 = 337;
					goto IL_07cc;
				case 40:
					array2[2] = 51;
					num = 230;
					break;
				case 200:
					array2[26] = (byte)num5;
					num = 243;
					break;
				case 54:
					array2[9] = 114;
					num4 = 219;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 103;
				case 103:
					array2[29] = (byte)num5;
					num = 46;
					break;
				case 104:
					num5 = 224 - 74;
					num6 = 342;
					goto IL_07c8;
				case 327:
					num5 = 57 + 41;
					num6 = 158;
					goto IL_07c8;
				case 333:
					array2[5] = 126;
					num4 = 49;
					if (!WMf9RCU7UsZovPbvKT())
					{
						goto IL_07cc;
					}
					goto case 102;
				case 102:
					num3 = 53 + 32;
					num6 = 20;
					goto IL_07c8;
				case 220:
					array[13] = 127;
					num6 = 334;
					goto IL_07c8;
				case 290:
					if (array5 == null)
					{
						goto case 251;
					}
					num = 35;
					break;
				case 52:
					array2[25] = 201;
					num4 = 77;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 1;
				case 1:
					num3 = 85 + 94;
					num6 = 133;
					goto IL_07c8;
				case 125:
				case 261:
					array[7] = 99;
					num6 = 3;
					goto IL_07c8;
				case 249:
					array2[30] = (byte)num5;
					num4 = 6;
					goto IL_07cc;
				case 193:
					array[9] = (byte)num3;
					num4 = 252;
					goto IL_07cc;
				case 177:
					array[10] = (byte)num3;
					num6 = 223;
					goto IL_07c8;
				case 278:
					array2[30] = 222;
					num = 14;
					break;
				case 262:
					array[13] = 128;
					num4 = 220;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 232;
				case 232:
					array[10] = (byte)num3;
					num6 = 284;
					goto IL_07c8;
				case 16:
					array2[29] = (byte)num5;
					num4 = 197;
					if (!WMf9RCU7UsZovPbvKT())
					{
						goto IL_07cc;
					}
					goto case 308;
				case 308:
					num5 = 150 - 50;
					num = 315;
					break;
				case 12:
					num5 = 192 - 64;
					num6 = 293;
					goto IL_07c8;
				case 162:
					array2[13] = (byte)num5;
					num6 = 98;
					goto IL_07c8;
				case 221:
					num5 = 182 - 60;
					num4 = 105;
					goto IL_07cc;
				case 169:
					num5 = 243 - 81;
					num4 = 181;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 136;
				case 136:
					num5 = 216 - 115;
					num4 = 162;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 209;
				case 209:
					num5 = 176 - 58;
					num4 = 298;
					goto IL_07cc;
				case 227:
					array2[4] = (byte)num5;
					num = 97;
					break;
				case 55:
					num5 = 10 + 104;
					num4 = 94;
					goto IL_07cc;
				case 167:
					array2[15] = (byte)num5;
					num4 = 319;
					if (cOjh92Ab9OGhcJc4ik())
					{
						goto IL_07cc;
					}
					goto case 284;
				case 284:
					array[11] = 91;
					num4 = 311;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 253;
				case 253:
					num5 = 114 + 64;
					num = 191;
					break;
				case 345:
					array2[24] = 140;
					num4 = 215;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 113;
				case 113:
					num5 = 109 + 34;
					num4 = 164;
					goto IL_07cc;
				case 141:
					array2[11] = (byte)num5;
					num4 = 44;
					if (cOjh92Ab9OGhcJc4ik())
					{
						goto IL_07cc;
					}
					goto case 98;
				case 98:
					num5 = 52 + 122;
					num6 = 187;
					goto IL_07c8;
				case 9:
					num5 = 237 - 79;
					num4 = 145;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 79;
				case 79:
					array2[26] = 45;
					num = 306;
					break;
				case 134:
				case 152:
					array2[19] = (byte)num5;
					num6 = 283;
					goto IL_07c8;
				case 274:
					array2[8] = (byte)num5;
					num4 = 150;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 81;
				case 81:
					array2[1] = 184;
					num6 = 104;
					goto IL_07c8;
				case 112:
					array2[27] = (byte)num5;
					num4 = 287;
					if (!WMf9RCU7UsZovPbvKT())
					{
						goto IL_07cc;
					}
					goto case 31;
				case 118:
					array[12] = 62;
					num4 = 305;
					goto IL_07cc;
				case 143:
					num3 = 92 + 83;
					num4 = 5;
					if (cOjh92Ab9OGhcJc4ik())
					{
						goto IL_07cc;
					}
					goto case 266;
				case 110:
					array4[15] = array5[7];
					num = 251;
					break;
				case 48:
					array[15] = 114;
					num = 68;
					break;
				case 334:
					array[13] = 168;
					num = 92;
					break;
				case 23:
					num5 = 88 - 75;
					num4 = 42;
					if (!WMf9RCU7UsZovPbvKT())
					{
						goto IL_07cc;
					}
					goto case 0;
				case 0:
					array2[4] = (byte)num5;
					num4 = 307;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 31;
				case 31:
					binaryReader = new BinaryReader((Stream)N2di2gTimk32B5UAwc(C1FWkSqZUc1DXXBp2Y(typeof(MnxsD0lrg8kZaUPt2I).TypeHandle).Assembly, "nrE7O7ysNCV8cLXNxD.caYMqFe2JACkueUHEd"));
					num6 = 159;
					goto IL_07c8;
				case 145:
					array2[8] = (byte)num5;
					num = 88;
					break;
				case 337:
					array[4] = 124;
					num6 = 173;
					goto IL_07c8;
				case 254:
					num5 = 42 + 110;
					num4 = 168;
					if (!cOjh92Ab9OGhcJc4ik())
					{
						goto case 225;
					}
					goto IL_07cc;
				case 163:
					array[2] = 200;
					num4 = 233;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 231;
				case 231:
					array[1] = 150;
					num4 = 297;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 252;
				case 252:
					num3 = 233 - 77;
					num6 = 138;
					goto IL_07c8;
				case 312:
					array2[7] = 23;
					num6 = 26;
					goto IL_07c8;
				case 173:
					array[4] = 121;
					num4 = 1;
					goto IL_07cc;
				case 314:
					num5 = 38 + 115;
					num4 = 167;
					goto IL_07cc;
				case 30:
					array[1] = (byte)num3;
					num4 = 163;
					if (!WMf9RCU7UsZovPbvKT())
					{
						goto IL_07cc;
					}
					goto case 228;
				case 228:
					array2[11] = (byte)num5;
					num6 = 343;
					goto IL_07c8;
				case 311:
					num3 = 89 + 43;
					num4 = 129;
					if (!WMf9RCU7UsZovPbvKT())
					{
						goto IL_07cc;
					}
					goto case 157;
				case 317:
					array2[28] = 230;
					num = 192;
					break;
				case 297:
					num3 = 154 + 13;
					num6 = 30;
					goto IL_07c8;
				case 114:
					array2[21] = (byte)num5;
					num4 = 336;
					goto IL_07cc;
				case 44:
					array2[12] = 62;
					num6 = 47;
					goto IL_07c8;
				case 335:
					array2[3] = 132;
					num = 216;
					break;
				case 295:
					array[9] = (byte)num3;
					num4 = 324;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 287;
				case 287:
					num5 = 70 + 78;
					num4 = 58;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 264;
				case 264:
					array4[1] = array5[0];
					num4 = 206;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 215;
				case 215:
					array2[24] = 108;
					num4 = 52;
					if (!WMf9RCU7UsZovPbvKT())
					{
						goto IL_07cc;
					}
					goto case 89;
				case 89:
					array[13] = (byte)num3;
					num6 = 101;
					goto IL_07c8;
				case 120:
					array2[25] = 92;
					num = 79;
					break;
				case 258:
					num5 = 216 - 72;
					num6 = 165;
					goto IL_07c8;
				case 172:
					array2[5] = (byte)num5;
					num4 = 333;
					if (!WMf9RCU7UsZovPbvKT())
					{
						goto IL_07cc;
					}
					goto case 53;
				case 68:
					array4 = array;
					num = 71;
					break;
				case 15:
					array2[3] = 88;
					num4 = 222;
					goto IL_07cc;
				case 130:
					num3 = 75 + 115;
					num4 = 89;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 313;
				case 313:
					array2[6] = (byte)num5;
					num4 = 155;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 226;
				case 226:
					array[6] = (byte)num3;
					num4 = 188;
					if (cOjh92Ab9OGhcJc4ik())
					{
						goto IL_07cc;
					}
					goto case 77;
				case 77:
					array2[25] = 138;
					num4 = 325;
					goto IL_07cc;
				case 165:
					array2[22] = (byte)num5;
					num6 = 161;
					goto IL_07c8;
				case 86:
					num3 = 243 - 81;
					num6 = 226;
					goto IL_07c8;
				case 180:
					array2[8] = 106;
					num4 = 176;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 277;
				case 277:
					array2[17] = (byte)num5;
					num = 170;
					break;
				case 342:
					array2[1] = (byte)num5;
					num4 = 64;
					goto IL_07cc;
				case 276:
					array2[13] = 91;
					num6 = 136;
					goto IL_07c8;
				case 34:
					array2[15] = (byte)num5;
					num4 = 151;
					if (WMf9RCU7UsZovPbvKT())
					{
						goto case 19;
					}
					goto IL_07cc;
				case 305:
					num3 = 97 + 79;
					num4 = 51;
					goto IL_07cc;
				case 115:
					num5 = 89 - 66;
					num4 = 144;
					if (!WMf9RCU7UsZovPbvKT())
					{
						goto IL_07cc;
					}
					goto case 281;
				case 5:
					array[7] = (byte)num3;
					goto case 125;
				case 184:
					array2[24] = (byte)num5;
					num4 = 207;
					goto IL_07cc;
				case 155:
					num5 = 113 + 88;
					num4 = 203;
					goto IL_07cc;
				case 82:
					num3 = 69 + 64;
					num6 = 53;
					goto IL_07c8;
				case 29:
					array2[23] = (byte)num5;
					num4 = 308;
					if (cOjh92Ab9OGhcJc4ik())
					{
						goto IL_07cc;
					}
					goto case 310;
				case 310:
					array2[27] = (byte)num5;
					num4 = 303;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 257;
				case 257:
					array4[13] = array5[6];
					num4 = 110;
					if (cOjh92Ab9OGhcJc4ik())
					{
						goto IL_07cc;
					}
					goto case 151;
				case 151:
					num5 = 223 - 74;
					num = 213;
					break;
				case 70:
					array2[29] = (byte)num5;
					num = 13;
					break;
				case 289:
					array2[19] = 84;
					num4 = 10;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 164;
				case 164:
					array2[22] = (byte)num5;
					num6 = 258;
					goto IL_07c8;
				case 324:
					num3 = 78 + 16;
					num6 = 304;
					goto IL_07c8;
				case 53:
					array[11] = (byte)num3;
					num6 = 118;
					goto IL_07c8;
				case 304:
					array[9] = (byte)num3;
					num4 = 217;
					goto IL_07cc;
				case 291:
					cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
					num = 329;
					break;
				case 320:
					num5 = 157 - 52;
					num4 = 313;
					goto IL_07cc;
				case 298:
					array2[17] = (byte)num5;
					num = 248;
					break;
				case 95:
					num3 = 18 + 108;
					num6 = 137;
					goto IL_07c8;
				case 245:
					array[2] = 12;
					num = 208;
					break;
				case 242:
					num5 = 55 + 24;
					num4 = 116;
					if (WMf9RCU7UsZovPbvKT())
					{
						goto case 302;
					}
					goto IL_07cc;
				case 301:
					array2 = new byte[32];
					num6 = 221;
					goto IL_07c8;
				case 109:
					array[11] = (byte)num3;
					num4 = 82;
					goto IL_07cc;
				case 271:
					do
					{
						num3 = 169 - 56;
						num4 = 229;
					}
					while (!cOjh92Ab9OGhcJc4ik());
					goto IL_07cc;
				case 117:
					num5 = 209 - 69;
					num4 = 4;
					if (!WMf9RCU7UsZovPbvKT())
					{
						goto IL_07cc;
					}
					goto case 37;
				case 37:
					array[6] = 230;
					num4 = 201;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 239;
				case 239:
					transform = (ICryptoTransform)IitY52svdFecEv8SER(rijndaelManaged, array3, array4);
					num4 = 19;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 244;
				case 244:
					array2[20] = (byte)num5;
					num6 = 22;
					goto IL_07c8;
				case 331:
					array2[21] = 152;
					num4 = 316;
					goto IL_07cc;
				case 201:
					num3 = 167 - 55;
					num = 93;
					break;
				case 270:
					array2[23] = (byte)num5;
					num6 = 327;
					goto IL_07c8;
				case 13:
					num5 = 164 - 54;
					num4 = 103;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 233;
				case 233:
					array[2] = 81;
					num = 204;
					break;
				case 216:
					num5 = 159 - 53;
					num4 = 0;
					if (0 == 0)
					{
						goto IL_07cc;
					}
					goto case 246;
				case 246:
					num5 = 59 + 57;
					num4 = 300;
					if (WMf9RCU7UsZovPbvKT())
					{
						goto case 283;
					}
					goto IL_07cc;
				case 153:
					array2[9] = (byte)num5;
					num4 = 169;
					if (true)
					{
						goto IL_07cc;
					}
					goto case 74;
				case 74:
					num5 = 171 - 57;
					num6 = 112;
					goto IL_07c8;
				case 157:
					array2[21] = (byte)num5;
					num = 331;
					break;
				case 49:
					num5 = 48 + 113;
					num6 = 99;
					goto IL_07c8;
				case 347:
					try
					{
						return (string)d39bNOesKchYKJbZiM(LdinlYx04OaQEvaCwv(), envcgwL4rP, P_0 + 4, num2);
					}
					catch
					{
					}
					return "";
				case 251:
					rijndaelManaged = new RijndaelManaged();
					num6 = 322;
					goto IL_07c8;
				case 19:
					{
						memoryStream = new MemoryStream();
						num4 = 291;
						if (0 == 0)
						{
							goto IL_07cc;
						}
						goto case 167;
					}
					IL_07c8:
					num4 = num6;
					goto IL_07cc;
					IL_07cc:
					num = num4;
					break;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CyEJw3BBaxosHZj3HQ(typeof(MnxsD0lrg8kZaUPt2I/CyEJw3BBaxosHZj3HQ/gLeLc0TtP0swCIA6La<object>[]))]
		internal static string qmrIf1iNXG(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void HteICrABM5(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int JYjIWKYJcT(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr dGnISe5X1V(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void mnrIy1kvRB()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void QS6IirMgpJ()
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
		internal static object jnQIADx9bI(object P_0)
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
		public static extern IntPtr GmiIQk7Rdj(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr BwGIuAi5vg(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int d3qIY4YukC(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int PjOIlL9pNc(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int ejjIJU2lFW(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr CTxIBU3YjT(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int NCUITbfI6M(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CyEJw3BBaxosHZj3HQ(typeof(MnxsD0lrg8kZaUPt2I/CyEJw3BBaxosHZj3HQ/gLeLc0TtP0swCIA6La<object>[]))]
		private static byte[] GHkIzUsvsJ(string P_0)
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
		[CyEJw3BBaxosHZj3HQ(typeof(MnxsD0lrg8kZaUPt2I/CyEJw3BBaxosHZj3HQ/gLeLc0TtP0swCIA6La<object>[]))]
		private static byte[] Ko7cHNYTEa(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				129, 167, 77, 38, 142, 141, 163, 86, 154, 101,
				0, 228, 160, 9, 243, 132, 12, 166, 190, 13,
				58, 15, 50, 174, 105, 207, 133, 202, 105, 2,
				242, 169
			};
			rijndael.IV = new byte[16]
			{
				171, 176, 226, 104, 229, 10, 104, 168, 150, 4,
				125, 86, 115, 234, 39, 25
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] AljcPTZSt3()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] Vkgc1BESTc()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] hOPcsK2gph()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] HFoc0grr8X()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] k77c7G0ce2()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] jOWcrDxtbt()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] mDScIksr8o()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] FMUccrm6Ma()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] a4kcXYrmCa()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] aSXcxa6eKI()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public MnxsD0lrg8kZaUPt2I()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type C1FWkSqZUc1DXXBp2Y(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object N2di2gTimk32B5UAwc(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object mBDXbai8QfGBPMBHVM(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void NpMgc2kuldlm2RCI9h(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void OQQZwmGZp7jtAQqIJH(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long Iy9oaaLG1fpEKkXaFQ(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object PrgQpxQdJaY9ZG8uC3(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object npRCpEpSZqQw7OJoxU(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object iBYFJitdLpcATNUbXT(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void jXUFNw4VdY4IDX1xSf(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object IitY52svdFecEv8SER(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void cOIlNqgladgPpugEuY(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void juwENl9oCAflD5gade(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object KVHiH9m5dRCTWcur4Q(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void mSIucY1QE2u3wnMIDC(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void zXpDGMY3SnBxi7fdBy(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int Mf90bh7qkynsHSoCDv(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object LdinlYx04OaQEvaCwv()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object d39bNOesKchYKJbZiM(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool cOjh92Ab9OGhcJc4ik()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool WMf9RCU7UsZovPbvKT()
		{
			return false;
		}
	}
}
namespace HPU5lGP7EtdR7quTaU1
{
	internal class JmLDt5P0cahRebTiifG
	{
		private static bool Pq4c4MNsaN;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void LYav19NzXHLb9()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public JmLDt5P0cahRebTiifG()
		{
		}
	}
}
