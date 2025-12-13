using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using Cummins.INSITE.CNL.Common.Files;
using Cummins.INSITE.CNL.Common.Registry;
using Cummins.INSITE.CNL.Errors;
using Cummins.INSITE.CNL.Events;
using Cummins.INSITE.CNL.Events.Proxies;
using Cummins.INSITE.CNL.Help;
using Cummins.INSITE.CNL.Localization;
using Cummins.INSITE.CNL.Monitors;
using YZVo48nD27HR7IesJt;
using xBLVZJJVbfFxZ4AaFR;

[assembly: ComVisible(true)]
[assembly: Guid("39930981-1989-40ef-895b-86bfa9f7b070")]
[assembly: AssemblyProduct("INSITE")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyDelaySign(false)]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyTitle("Cummins.INSITE.CNL.Factory")]
[assembly: AssemblyDescription("Cummins .NET Libraries Factory Component")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace iBYH0EDgQ7XSfJnvIE
{
	internal static class D6Htgd4Ib0R7yokD9t
	{
	}
}
namespace Cummins.INSITE.CNL.Factory
{
	public static class Factory
	{
		private static Dictionary<Type, object> zxlpuFw8D;

		private static bool VqZ4WyPA1;

		public static bool TestMode
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return VqZ4WyPA1;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				VqZ4WyPA1 = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static void SetInstanceOverride<T>(object instance) where T : class
		{
			if (!TestMode)
			{
				throw new InvalidOperationException(pZBBYBCsPuqQtRXJTl.P0R57yokD(0));
			}
			if (instance != null)
			{
				if (zxlpuFw8D.ContainsKey(typeof(T)))
				{
					zxlpuFw8D[typeof(T)] = instance;
				}
				else
				{
					zxlpuFw8D.Add(typeof(T), instance);
				}
			}
			else
			{
				zxlpuFw8D.Remove(typeof(T));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static T CreateInstance<T>() where T : class
		{
			if (TestMode && zxlpuFw8D.ContainsKey(typeof(T)))
			{
				return (T)zxlpuFw8D[typeof(T)];
			}
			if (typeof(T) == typeof(IErrorDisplay))
			{
				IErrorDisplay errorDisplay = new ErrorDisplay();
				return (T)errorDisplay;
			}
			if (typeof(T) == typeof(ILocalizedStringProvider))
			{
				LocalMachineRegistryReader registryReader = new LocalMachineRegistryReader();
				FileReader fileReader = new FileReader();
				ILocalizedStringProvider localizedStringProvider = new LocalizedStringProvider(registryReader, fileReader);
				return (T)localizedStringProvider;
			}
			if (typeof(T) == typeof(IContextSensitiveHelpProvider))
			{
				IContextSensitiveHelpProvider contextSensitiveHelpProvider = new ContextSensitiveHelpProvider();
				return (T)contextSensitiveHelpProvider;
			}
			if (typeof(T) == typeof(IMonitorManager))
			{
				IMonitorManager monitorManager = new MonitorManager();
				return (T)monitorManager;
			}
			if (typeof(T) == typeof(IEventSubscriber))
			{
				IEventSubscriber eventSubscriber = new EventSubscriber();
				return (T)eventSubscriber;
			}
			if (typeof(T) == typeof(IEventPublisher))
			{
				IEventPublisher eventPublisher = new EventPublisher();
				return (T)eventPublisher;
			}
			if (typeof(T) == typeof(IConnectionLostEventsProxy))
			{
				IConnectionLostEventsProxy connectionLostEventsProxy = new ConnectionLostEventsProxy();
				return (T)connectionLostEventsProxy;
			}
			if (typeof(T) == typeof(IConnectionEventsProxy))
			{
				IConnectionEventsProxy connectionEventsProxy = new ConnectionEventsProxy();
				return (T)connectionEventsProxy;
			}
			if (typeof(T) == typeof(IPrefDispEventsProxy))
			{
				IPrefDispEventsProxy prefDispEventsProxy = new PrefDispEventsProxy();
				return (T)prefDispEventsProxy;
			}
			if (typeof(T) == typeof(IToolSecurityEventsProxy))
			{
				IToolSecurityEventsProxy toolSecurityEventsProxy = new ToolSecurityEventsProxy();
				return (T)toolSecurityEventsProxy;
			}
			if (typeof(T) == typeof(IConManEventForFnPProxy))
			{
				IConManEventForFnPProxy conManEventForFnPProxy = new ConManEventForFnPProxy();
				return (T)conManEventForFnPProxy;
			}
			throw new ArgumentException(pZBBYBCsPuqQtRXJTl.P0R57yokD(114));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static Factory()
		{
			nfdw4lTyMetKrw77wd.jJaS6jTzKOkTY();
			zxlpuFw8D = new Dictionary<Type, object>();
		}
	}
}
namespace ECMSERVICESEVENTSLib
{
	[ComImport]
	[TypeIdentifier]
	[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
	[CompilerGenerated]
	[Guid("DD9F8B57-6CC2-421E-A507-06FB388FB059")]
	public interface IMonitorEvents
	{
	}
	[ComImport]
	[CompilerGenerated]
	[TypeIdentifier]
	[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
	[Guid("C2593369-FB36-48E2-BFD9-5543D6CC628D")]
	public interface IMonitorDataChangedEvent
	{
	}
}
internal class <Module>{8DF9986F-8251-4DC0-A6AB-1D3C2B06B0E6}
{
}
namespace NioEI2Y2G547VlMUQw
{
	internal class QSicFJ5vR10OCChJvZ
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module sh6DHtgdI;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void wx6S6jTTEu3CE(int typemdt)
		{
			Type type = sh6DHtgdI.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)sh6DHtgdI.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public QSicFJ5vR10OCChJvZ()
		{
			nfdw4lTyMetKrw77wd.jJaS6jTzKOkTY();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static QSicFJ5vR10OCChJvZ()
		{
			nfdw4lTyMetKrw77wd.jJaS6jTzKOkTY();
			sh6DHtgdI = typeof(QSicFJ5vR10OCChJvZ).Assembly.ManifestModule;
		}
	}
}
namespace YZVo48nD27HR7IesJt
{
	internal class pZBBYBCsPuqQtRXJTl
	{
		internal class Yko1SZPbrboHs8umBt : Attribute
		{
			internal class e6fy4LtuEMMckC6ept<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public e6fy4LtuEMMckC6ept()
				{
					nfdw4lTyMetKrw77wd.jJaS6jTzKOkTY();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[Yko1SZPbrboHs8umBt(typeof(pZBBYBCsPuqQtRXJTl/Yko1SZPbrboHs8umBt/e6fy4LtuEMMckC6ept<object>[]))]
			public Yko1SZPbrboHs8umBt(object P_0)
			{
				nfdw4lTyMetKrw77wd.jJaS6jTzKOkTY();
				base..ctor();
			}
		}

		internal class IOKg0MGUudEm0xKKtv
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[Yko1SZPbrboHs8umBt(typeof(pZBBYBCsPuqQtRXJTl/Yko1SZPbrboHs8umBt/e6fy4LtuEMMckC6ept<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (PaksQs0n2(Convert.ToBase64String(typeof(pZBBYBCsPuqQtRXJTl).Assembly.GetName().GetPublicKeyToken()), pZBBYBCsPuqQtRXJTl.P0R57yokD(246)) != pZBBYBCsPuqQtRXJTl.P0R57yokD(252))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[Yko1SZPbrboHs8umBt(typeof(pZBBYBCsPuqQtRXJTl/Yko1SZPbrboHs8umBt/e6fy4LtuEMMckC6ept<object>[]))]
			internal static string PaksQs0n2(string P_0, string P_1)
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
			public IOKg0MGUudEm0xKKtv()
			{
				nfdw4lTyMetKrw77wd.jJaS6jTzKOkTY();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint YOIIM2MOQv8uNTsKXb([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr OZ7tqv8AtYJBeGCbM8();

		internal struct m2IY6COgrVhctBOq6o
		{
			internal bool uikQ7ngsQ;

			internal byte[] d4f9ArMTZ;
		}

		[Flags]
		private enum LJgXMm6u1pZ9k6RXgE
		{

		}

		private static byte[] Crwk77wd7;

		private static IntPtr Py11Xfs5i;

		private static bool rTW0UYFUG;

		private static SortedList fbkARJj5U;

		private static long XQqFiwO4Q;

		private static int xa9BjhGX4;

		private static IntPtr hKuIuOMkV;

		private static bool L3EvWkCDG;

		internal static YOIIM2MOQv8uNTsKXb e5AllUt5I;

		private static byte[] MxZK4AaFR;

		private static int gOKUlyuVp;

		internal static YOIIM2MOQv8uNTsKXb iT3X2xVc0;

		private static IntPtr K9RhhKY3J;

		private static object hS4N2Pnw2;

		private static int p13bvQ98h;

		private static int[] wYsx6U2dB;

		private static int guToWXxyK;

		private static byte[] NLV3ZJVbf;

		private static long pgFeuxqd8;

		private static byte[] Ww4flyMet;

		internal static Hashtable un2wyLEq7;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static pZBBYBCsPuqQtRXJTl()
		{
			Ww4flyMet = new byte[0];
			Crwk77wd7 = new byte[0];
			NLV3ZJVbf = new byte[0];
			MxZK4AaFR = new byte[0];
			K9RhhKY3J = IntPtr.Zero;
			Py11Xfs5i = IntPtr.Zero;
			hS4N2Pnw2 = new string[0];
			wYsx6U2dB = new int[0];
			gOKUlyuVp = 1;
			rTW0UYFUG = false;
			fbkARJj5U = new SortedList();
			guToWXxyK = 0;
			pgFeuxqd8 = 0L;
			e5AllUt5I = null;
			iT3X2xVc0 = null;
			XQqFiwO4Q = 0L;
			xa9BjhGX4 = 0;
			L3EvWkCDG = false;
			p13bvQ98h = 0;
			hKuIuOMkV = IntPtr.Zero;
			un2wyLEq7 = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void tj3S6jTxetlby()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[Yko1SZPbrboHs8umBt(typeof(pZBBYBCsPuqQtRXJTl/Yko1SZPbrboHs8umBt/e6fy4LtuEMMckC6ept<object>[]))]
		static string P0R57yokD(int P_0)
		{
			int num = 124;
			byte[] array = default(byte[]);
			int num6 = default(int);
			int num5 = default(int);
			byte[] array2 = default(byte[]);
			int num4 = default(int);
			int num7 = default(int);
			int num8 = default(int);
			BinaryReader binaryReader = default(BinaryReader);
			byte[] array3 = default(byte[]);
			byte[] array4 = default(byte[]);
			CryptoStream cryptoStream = default(CryptoStream);
			byte[] array6 = default(byte[]);
			MemoryStream memoryStream = default(MemoryStream);
			ICryptoTransform transform = default(ICryptoTransform);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array5 = default(byte[]);
			while (true)
			{
				int num3;
				int num2;
				switch (num)
				{
				case 162:
					array[14] = 154;
					num = 164;
					continue;
				case 27:
					num6 = 230 - 76;
					num = 294;
					continue;
				case 25:
					array[16] = 91;
					num3 = 218;
					goto IL_015d;
				case 202:
					num5 = 168 + 64;
					num2 = 286;
					goto IL_0159;
				case 119:
					num6 = 119 - 48;
					num3 = 75;
					if (1 == 0)
					{
						goto case 171;
					}
					goto IL_015d;
				case 171:
					array[6] = 172;
					num3 = 56;
					goto IL_015d;
				case 301:
					array2[7] = 237;
					num3 = 230;
					if (false)
					{
						goto case 59;
					}
					goto IL_015d;
				case 59:
					num5 = 216 - 72;
					num2 = 8;
					goto IL_0159;
				case 49:
					array[3] = (byte)num5;
					num = 304;
					continue;
				case 177:
					array[9] = 37;
					num = 206;
					continue;
				case 215:
					array[24] = 232;
					goto case 97;
				default:
					num3 = 97;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 189;
				case 189:
					array[29] = 54;
					num = 201;
					continue;
				case 132:
					array[5] = (byte)num5;
					num3 = 53;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 47;
				case 47:
					num4 = ecbaHFli16Jq5ivEHs(NLV3ZJVbf, P_0);
					num3 = 316;
					if (true)
					{
						goto IL_015d;
					}
					goto case 224;
				case 224:
					array[10] = (byte)num5;
					num2 = 101;
					goto IL_0159;
				case 159:
					num5 = 193 - 64;
					num3 = 88;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 211;
				case 211:
				case 217:
					array2[2] = 244;
					num3 = 89;
					if (!n7ab6pnk2A64Dty4Zp())
					{
						goto IL_015d;
					}
					goto case 14;
				case 14:
					array[27] = (byte)num7;
					num = 63;
					continue;
				case 95:
					array2 = new byte[16];
					num2 = 199;
					goto IL_0159;
				case 242:
					array2[12] = (byte)num6;
					num2 = 27;
					goto IL_0159;
				case 220:
					array[21] = 108;
					num3 = 29;
					if (true)
					{
						goto IL_015d;
					}
					goto case 115;
				case 115:
					array2[14] = (byte)num8;
					num = 116;
					continue;
				case 60:
					aWOg3JX8LvN4CITXqM(eLyW9OHXnJ1uDuREd4(binaryReader), 0L);
					num = 223;
					continue;
				case 26:
					num7 = 88 + 48;
					num3 = 62;
					goto IL_015d;
				case 136:
					array3[7] = array4[3];
					num2 = 7;
					goto IL_0159;
				case 184:
					array[17] = (byte)num7;
					num = 48;
					continue;
				case 193:
					array2[4] = 194;
					num3 = 249;
					goto IL_015d;
				case 151:
					array[17] = (byte)num7;
					num3 = 173;
					if (true)
					{
						goto IL_015d;
					}
					goto case 82;
				case 82:
					array2[15] = 104;
					num3 = 311;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 128;
				case 75:
					array2[10] = (byte)num6;
					num = 226;
					continue;
				case 93:
					array[19] = 74;
					num3 = 212;
					goto IL_015d;
				case 8:
					array[2] = (byte)num5;
					num3 = 219;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 36;
				case 36:
					array2[9] = 46;
					num3 = 12;
					if (true)
					{
						goto IL_015d;
					}
					goto case 121;
				case 121:
					array[29] = 49;
					num = 182;
					continue;
				case 182:
					array[29] = 111;
					num3 = 189;
					if (true)
					{
						goto IL_015d;
					}
					goto case 183;
				case 183:
					array[22] = 96;
					num = 238;
					continue;
				case 19:
					array2[3] = (byte)num8;
					num2 = 107;
					goto IL_0159;
				case 296:
					array[24] = (byte)num7;
					num2 = 267;
					goto IL_0159;
				case 169:
					num6 = 252 - 84;
					num3 = 302;
					goto IL_015d;
				case 281:
					array[2] = 100;
					num3 = 139;
					goto IL_015d;
				case 152:
					array[2] = (byte)num7;
					num = 275;
					continue;
				case 228:
					array2[3] = 89;
					num2 = 265;
					goto IL_0159;
				case 63:
					num5 = 96 + 57;
					num = 174;
					continue;
				case 56:
					array[6] = 129;
					num2 = 138;
					goto IL_0159;
				case 225:
					array[14] = 67;
					num = 23;
					continue;
				case 272:
					array[23] = 4;
					num2 = 180;
					goto IL_0159;
				case 173:
					num7 = 81 + 42;
					num3 = 176;
					goto IL_015d;
				case 147:
					array[25] = 89;
					num3 = 305;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 75;
				case 280:
					array[9] = 109;
					num = 33;
					continue;
				case 187:
					num8 = 242 - 80;
					num2 = 192;
					goto IL_0159;
				case 105:
					array[26] = 130;
					num3 = 34;
					if (true)
					{
						goto IL_015d;
					}
					goto case 3;
				case 3:
					Ft8pGWMd5uQQ7O1uk3(cryptoStream, array6, 0, array6.Length);
					num2 = 2;
					goto IL_0159;
				case 179:
					array[10] = 148;
					num2 = 65;
					goto IL_0159;
				case 133:
					num7 = 83 + 113;
					num3 = 277;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 97;
				case 97:
					array[25] = 121;
					num = 163;
					continue;
				case 233:
					array[26] = 131;
					num3 = 94;
					goto IL_015d;
				case 234:
					num7 = 42 - 41;
					num2 = 17;
					goto IL_0159;
				case 90:
					array2[9] = (byte)num6;
					num2 = 36;
					goto IL_0159;
				case 230:
					array2[8] = 55;
					num2 = 103;
					goto IL_0159;
				case 38:
					array[8] = 97;
					num3 = 166;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 298;
				case 298:
					num7 = 131 - 43;
					num = 120;
					continue;
				case 248:
					num7 = 30 + 87;
					num3 = 112;
					if (!n7ab6pnk2A64Dty4Zp())
					{
						goto IL_015d;
					}
					goto case 109;
				case 22:
					num5 = 99 + 101;
					num3 = 153;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 141;
				case 141:
					array[1] = (byte)num5;
					num2 = 59;
					goto IL_0159;
				case 172:
					array[24] = (byte)num7;
					num3 = 149;
					if (true)
					{
						goto IL_015d;
					}
					goto case 149;
				case 149:
					array[24] = 117;
					num3 = 215;
					if (true)
					{
						goto IL_015d;
					}
					goto case 208;
				case 208:
					array[0] = (byte)num7;
					num3 = 54;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 117;
				case 165:
					num8 = 141 - 47;
					num = 253;
					continue;
				case 262:
					array = new byte[32];
					num = 292;
					continue;
				case 285:
					array2[5] = 112;
					goto case 104;
				case 218:
					array[17] = 131;
					num = 16;
					continue;
				case 39:
					array2[0] = (byte)num8;
					num3 = 129;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 236;
				case 52:
					array[28] = 68;
					num = 191;
					continue;
				case 99:
					array[14] = (byte)num5;
					num = 225;
					continue;
				case 81:
					array2[1] = 161;
					num = 247;
					continue;
				case 192:
					array2[5] = (byte)num8;
					num = 285;
					continue;
				case 61:
					array[19] = (byte)num7;
					num = 93;
					continue;
				case 206:
					array[9] = 120;
					num = 243;
					continue;
				case 251:
					array6 = (byte[])D3uepav9VVguvvj2Bp(binaryReader, (int)PZqCajKeiSGxJ7qrYx(eLyW9OHXnJ1uDuREd4(binaryReader)));
					num3 = 262;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 258;
				case 258:
					array[3] = 89;
					num2 = 51;
					goto IL_0159;
				case 15:
					num5 = 70 + 67;
					num3 = 135;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 246;
				case 246:
					num7 = 25 + 105;
					num = 157;
					continue;
				case 9:
					num6 = 120 + 104;
					num = 158;
					continue;
				case 5:
					if (array4.Length <= 0)
					{
						break;
					}
					num3 = 45;
					goto IL_015d;
				case 219:
					num7 = 168 - 56;
					num2 = 266;
					goto IL_0159;
				case 34:
					num7 = 9 + 17;
					num3 = 14;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 273;
				case 273:
					array2[14] = (byte)num8;
					num = 125;
					continue;
				case 310:
					array3 = array2;
					num2 = 118;
					goto IL_0159;
				case 270:
					num5 = 133 - 122;
					num3 = 141;
					if (!n7ab6pnk2A64Dty4Zp())
					{
						goto IL_015d;
					}
					goto case 37;
				case 37:
					array[18] = 104;
					num = 227;
					continue;
				case 278:
					array[11] = 238;
					num3 = 126;
					if (true)
					{
						goto IL_015d;
					}
					goto case 261;
				case 261:
					num8 = 249 - 83;
					num3 = 115;
					goto IL_015d;
				case 164:
					num5 = 137 - 45;
					num3 = 99;
					if (!n7ab6pnk2A64Dty4Zp())
					{
						goto IL_015d;
					}
					goto case 204;
				case 204:
					array[20] = 142;
					num3 = 203;
					goto IL_015d;
				case 259:
					array[22] = (byte)num7;
					num = 128;
					continue;
				case 148:
					array3[13] = array4[6];
					num3 = 67;
					if (!n7ab6pnk2A64Dty4Zp())
					{
						goto IL_015d;
					}
					goto case 125;
				case 116:
					num8 = 67 + 17;
					num = 273;
					continue;
				case 42:
					num8 = 44 + 22;
					num3 = 32;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 48;
				case 48:
					num7 = 190 - 116;
					num2 = 151;
					goto IL_0159;
				case 180:
					num7 = 242 - 80;
					num2 = 296;
					goto IL_0159;
				case 186:
					num8 = 190 - 63;
					num3 = 35;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 261;
				case 168:
					array2[1] = 203;
					num2 = 295;
					goto IL_0159;
				case 155:
					num6 = 152 - 50;
					num3 = 10;
					if (!n7ab6pnk2A64Dty4Zp())
					{
						goto IL_015d;
					}
					goto case 313;
				case 250:
					array[5] = (byte)num7;
					num = 231;
					continue;
				case 269:
					array[8] = 163;
					num2 = 26;
					goto IL_0159;
				case 35:
					array2[15] = (byte)num8;
					num3 = 82;
					if (!n7ab6pnk2A64Dty4Zp())
					{
						goto IL_015d;
					}
					goto case 106;
				case 106:
					array[31] = (byte)num7;
					num2 = 234;
					goto IL_0159;
				case 7:
					array3[9] = array4[4];
					num = 114;
					continue;
				case 203:
					array[20] = 132;
					num = 237;
					continue;
				case 2:
					fCgE2SJlYaEP7Q2ann(cryptoStream);
					num = 197;
					continue;
				case 73:
					array[12] = (byte)num7;
					num = 248;
					continue;
				case 307:
					array[23] = (byte)num5;
					num2 = 272;
					goto IL_0159;
				case 267:
					array[24] = 100;
					num3 = 291;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 254;
				case 254:
					array2[10] = 114;
					num3 = 260;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 275;
				case 275:
					num7 = 172 - 57;
					num = 239;
					continue;
				case 313:
					array[16] = (byte)num7;
					num3 = 22;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 54;
				case 54:
					array[0] = 87;
					num3 = 84;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 264;
				case 264:
					array2[7] = 125;
					num = 21;
					continue;
				case 153:
					array[16] = (byte)num5;
					num = 25;
					continue;
				case 306:
					num6 = 121 + 45;
					num3 = 282;
					if (true)
					{
						goto IL_015d;
					}
					goto case 252;
				case 252:
					array2[15] = (byte)num8;
					num = 310;
					continue;
				case 302:
					array2[6] = (byte)num6;
					num3 = 195;
					goto IL_015d;
				case 145:
					num7 = 246 - 82;
					num = 208;
					continue;
				case 227:
					num7 = 99 + 80;
					num2 = 146;
					goto IL_0159;
				case 247:
					num6 = 193 - 64;
					num3 = 142;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 300;
				case 300:
					num7 = 126 - 42;
					num3 = 74;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 255;
				case 255:
					num6 = 106 + 20;
					num = 90;
					continue;
				case 311:
					num8 = 29 + 109;
					num2 = 252;
					goto IL_0159;
				case 114:
					array3[11] = array4[5];
					num = 148;
					continue;
				case 86:
					array2[12] = 163;
					num3 = 198;
					goto IL_015d;
				case 277:
					array[21] = (byte)num7;
					num3 = 220;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 84;
				case 84:
					array[1] = 66;
					num = 213;
					continue;
				case 166:
					num7 = 48 + 60;
					num2 = 31;
					goto IL_0159;
				case 195:
					num6 = 145 - 48;
					num3 = 244;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 303;
				case 303:
					array[18] = (byte)num5;
					num3 = 79;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 154;
				case 154:
					array[1] = (byte)num5;
					num3 = 270;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 42;
				case 223:
					vZs7qk6KsPKZbXnuHV(true);
					num2 = 251;
					goto IL_0159;
				case 68:
					array[5] = (byte)num7;
					num3 = 171;
					goto IL_015d;
				case 109:
					array2[5] = (byte)num6;
					num = 169;
					continue;
				case 197:
					NLV3ZJVbf = (byte[])CDp7xIOCL5MSU5ZYht(memoryStream);
					num2 = 117;
					goto IL_0159;
				case 150:
					array[31] = (byte)num7;
					num3 = 271;
					if (true)
					{
						goto IL_015d;
					}
					goto case 253;
				case 253:
					array2[15] = (byte)num8;
					num = 209;
					continue;
				case 191:
					array[28] = 30;
					num2 = 283;
					goto IL_0159;
				case 89:
					array2[3] = 19;
					num3 = 155;
					goto IL_015d;
				case 43:
					RSVBYBGSTvvuBjyD5p(cryptoStream);
					num = 221;
					continue;
				case 146:
					array[18] = (byte)num7;
					num = 263;
					continue;
				case 201:
					array[30] = 145;
					num3 = 276;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 135;
				case 135:
					array[13] = (byte)num5;
					num2 = 162;
					goto IL_0159;
				case 312:
					num7 = 179 - 59;
					num3 = 150;
					if (true)
					{
						goto IL_015d;
					}
					goto case 134;
				case 134:
					array2[12] = (byte)num6;
					num2 = 77;
					goto IL_0159;
				case 283:
					num5 = 97 + 119;
					num2 = 80;
					goto IL_0159;
				case 209:
					array2[15] = 168;
					num = 186;
					continue;
				case 263:
					num5 = 43 + 118;
					num2 = 303;
					goto IL_0159;
				case 239:
					array[2] = (byte)num7;
					num2 = 58;
					goto IL_0159;
				case 213:
					num5 = 35 + 52;
					num = 154;
					continue;
				case 62:
					array[8] = (byte)num7;
					num3 = 280;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 158;
				case 124:
					if (NLV3ZJVbf.Length == 0)
					{
						num2 = 288;
						goto IL_0159;
					}
					goto case 47;
				case 126:
					array[12] = 152;
					num3 = 96;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 12;
				case 12:
					array2[10] = 176;
					num2 = 207;
					goto IL_0159;
				case 231:
					num5 = 231 - 77;
					num3 = 132;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 291;
				case 291:
					num7 = 250 - 83;
					num = 172;
					continue;
				case 20:
					array[7] = (byte)num5;
					num2 = 140;
					goto IL_0159;
				case 130:
					if (array4 == null)
					{
						break;
					}
					num2 = 5;
					goto IL_0159;
				case 260:
					num6 = 6 + 37;
					num = 28;
					continue;
				case 51:
					num5 = 35 - 22;
					num2 = 49;
					goto IL_0159;
				case 163:
					array[25] = 164;
					num3 = 147;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 131;
				case 131:
					array3[5] = array4[2];
					num = 136;
					continue;
				case 210:
					array2[2] = 89;
					num3 = 194;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 0;
				case 0:
					num6 = 230 - 76;
					num = 134;
					continue;
				case 76:
					array2[14] = (byte)num6;
					num2 = 181;
					goto IL_0159;
				case 198:
					array2[13] = 167;
					num3 = 69;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 4;
				case 4:
					num5 = 6 + 37;
					num2 = 70;
					goto IL_0159;
				case 64:
					array2[9] = 38;
					num2 = 255;
					goto IL_0159;
				case 286:
					array[14] = (byte)num5;
					num = 160;
					continue;
				case 294:
					array2[12] = (byte)num6;
					num = 0;
					continue;
				case 71:
					array[7] = 143;
					num = 46;
					continue;
				case 196:
					array[11] = (byte)num5;
					num3 = 278;
					goto IL_015d;
				case 72:
					array[13] = (byte)num7;
					num2 = 15;
					goto IL_0159;
				case 284:
					transform = (ICryptoTransform)aNsBaaEYY82wUW0Cy0(rijndaelManaged, array5, array3);
					num3 = 18;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 156;
				case 156:
					array[11] = (byte)num5;
					num = 4;
					continue;
				case 120:
					array[26] = (byte)num7;
					num2 = 105;
					goto IL_0159;
				case 216:
					array2[0] = 164;
					num3 = 229;
					goto IL_015d;
				case 199:
					array2[0] = 114;
					num3 = 42;
					goto IL_015d;
				case 138:
					array[6] = 129;
					num2 = 315;
					goto IL_0159;
				case 1:
					array[28] = 95;
					num3 = 257;
					if (true)
					{
						goto IL_015d;
					}
					goto case 16;
				case 16:
					num7 = 9 + 20;
					num3 = 222;
					goto IL_015d;
				case 214:
					array[17] = (byte)num7;
					num2 = 85;
					goto IL_0159;
				case 140:
					array[8] = 86;
					num = 66;
					continue;
				case 295:
					array2[1] = 138;
					num3 = 44;
					if (!n7ab6pnk2A64Dty4Zp())
					{
						goto IL_015d;
					}
					goto case 178;
				case 178:
					array5 = array;
					num3 = 95;
					if (!n7ab6pnk2A64Dty4Zp())
					{
						goto IL_015d;
					}
					goto case 297;
				case 297:
					array[0] = 99;
					num3 = 145;
					goto IL_015d;
				case 123:
					array[9] = (byte)num7;
					num3 = 179;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 88;
				case 88:
					array[3] = (byte)num5;
					num3 = 258;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 194;
				case 194:
					array2[2] = 76;
					_ = 1;
					num = ((!n7ab6pnk2A64Dty4Zp()) ? 211 : 104);
					continue;
				case 30:
					num7 = 207 - 69;
					num2 = 214;
					goto IL_0159;
				case 157:
					array[30] = (byte)num7;
					num3 = 312;
					goto IL_015d;
				case 66:
					array[8] = 88;
					num2 = 38;
					goto IL_0159;
				case 170:
					num7 = 185 + 63;
					num = 259;
					continue;
				case 31:
					array[8] = (byte)num7;
					num = 269;
					continue;
				case 161:
					array[4] = 94;
					num3 = 205;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 26;
				case 238:
					array[22] = 168;
					num3 = 170;
					if (!n7ab6pnk2A64Dty4Zp())
					{
						goto IL_015d;
					}
					goto case 117;
				case 117:
					RSVBYBGSTvvuBjyD5p(memoryStream);
					num3 = 43;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 236;
				case 236:
					num5 = 185 - 61;
					num3 = 289;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 60;
				case 101:
					num5 = 171 - 57;
					num = 156;
					continue;
				case 46:
					num5 = 142 + 41;
					num = 20;
					continue;
				case 77:
					array2[12] = 144;
					num3 = 86;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 200;
				case 200:
					array[19] = 123;
					num3 = 13;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 311;
				case 174:
					array[27] = (byte)num5;
					num3 = 240;
					if (!n7ab6pnk2A64Dty4Zp())
					{
						goto IL_015d;
					}
					goto case 37;
				case 79:
					array[19] = 92;
					num = 78;
					continue;
				case 265:
					num8 = 100 + 77;
					num3 = 19;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 268;
				case 268:
					array2[13] = 97;
					num3 = 261;
					if (!n7ab6pnk2A64Dty4Zp())
					{
						goto IL_015d;
					}
					goto case 153;
				case 24:
					num5 = 174 - 58;
					num3 = 6;
					goto IL_015d;
				case 181:
					array2[14] = 110;
					num3 = 165;
					goto IL_015d;
				case 87:
					num7 = 26 + 3;
					num2 = 72;
					goto IL_0159;
				case 40:
					array2[5] = (byte)num6;
					num3 = 187;
					goto IL_015d;
				case 13:
					num7 = 18 + 1;
					num2 = 61;
					goto IL_0159;
				case 58:
					array[2] = 4;
					num = 159;
					continue;
				case 142:
					array2[2] = (byte)num6;
					num3 = 210;
					goto IL_015d;
				case 237:
					array[20] = 153;
					num2 = 133;
					goto IL_0159;
				case 221:
					epGdua48JR9CVFiJyJ(binaryReader);
					num3 = 47;
					if (true)
					{
						goto IL_015d;
					}
					goto case 94;
				case 94:
					array[26] = 138;
					num3 = 298;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 245;
				case 245:
					nDlmC2SLTiFnttJh3R(rijndaelManaged, CipherMode.CBC);
					num3 = 284;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 53;
				case 53:
					num7 = 212 + 14;
					num = 68;
					continue;
				case 241:
					array[21] = 56;
					num = 183;
					continue;
				case 276:
					array[30] = 69;
					num2 = 246;
					goto IL_0159;
				case 185:
					array[0] = 138;
					num3 = 297;
					goto IL_015d;
				case 102:
					num5 = 98 + 51;
					num = 55;
					continue;
				case 96:
					num5 = 74 + 20;
					num3 = 290;
					goto IL_015d;
				case 257:
					num7 = 75 + 115;
					num3 = 188;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 309;
				case 309:
					array[15] = 223;
					num = 92;
					continue;
				case 91:
					num5 = 88 - 8;
					num = 224;
					continue;
				case 118:
					array4 = (byte[])pP5ZyQ254R5eIu1a8g(AWHa1w1lm7qRcoI3id(nBqHkKPY6bgkDVTxIr(typeof(pZBBYBCsPuqQtRXJTl).TypeHandle).Assembly));
					num = 130;
					continue;
				case 266:
					array[2] = (byte)num7;
					num3 = 281;
					if (!n7ab6pnk2A64Dty4Zp())
					{
						goto IL_015d;
					}
					goto case 288;
				case 288:
					binaryReader = new BinaryReader((Stream)MwV2tDuc1bWL2VSiF5(nBqHkKPY6bgkDVTxIr(typeof(pZBBYBCsPuqQtRXJTl).TypeHandle).Assembly, "Q6OmAKPP3p7eEhYqRr.NyxImw1INle2QsukB4"));
					num2 = 60;
					goto IL_0159;
				case 229:
					num8 = 29 + 3;
					num = 39;
					continue;
				case 293:
					array[23] = (byte)num5;
					num2 = 287;
					goto IL_0159;
				case 10:
					array2[3] = (byte)num6;
					num2 = 9;
					goto IL_0159;
				case 299:
					array2[1] = 132;
					num2 = 168;
					goto IL_0159;
				case 137:
					num7 = 238 - 79;
					num3 = 106;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 305;
				case 305:
					num5 = 49 + 110;
					num3 = 110;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 143;
				case 143:
					array2[6] = (byte)num6;
					num2 = 264;
					goto IL_0159;
				case 175:
					cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
					num3 = 3;
					if (true)
					{
						goto IL_015d;
					}
					goto case 32;
				case 32:
					array2[0] = (byte)num8;
					num2 = 216;
					goto IL_0159;
				case 41:
					array[16] = (byte)num7;
					num = 98;
					continue;
				case 271:
					array[31] = 102;
					num3 = 137;
					goto IL_015d;
				case 290:
					array[12] = (byte)num5;
					num = 127;
					continue;
				case 292:
					array[0] = 144;
					num3 = 185;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 78;
				case 78:
					array[19] = 144;
					num2 = 200;
					goto IL_0159;
				case 65:
					array[10] = 165;
					num = 91;
					continue;
				case 125:
					num6 = 233 - 77;
					num3 = 76;
					if (true)
					{
						goto IL_015d;
					}
					goto case 57;
				case 57:
					array2[10] = (byte)num6;
					num2 = 254;
					goto IL_0159;
				case 176:
					array[18] = (byte)num7;
					num = 37;
					continue;
				case 128:
					num5 = 1 + 117;
					num = 293;
					continue;
				case 45:
					array3[1] = array4[0];
					num3 = 108;
					goto IL_015d;
				case 158:
					array2[3] = (byte)num6;
					num3 = 228;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 188;
				case 188:
					array[28] = (byte)num7;
					num3 = 52;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 104;
				case 104:
				case 235:
					num6 = 191 + 39;
					num3 = 109;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 33;
				case 33:
					array[9] = 117;
					num3 = 177;
					goto IL_015d;
				case 110:
					array[26] = (byte)num5;
					num3 = 279;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 226;
				case 226:
					array2[11] = 123;
					num3 = 308;
					goto IL_015d;
				case 207:
					num6 = 50 + 8;
					num2 = 57;
					goto IL_0159;
				case 50:
					num8 = 157 - 52;
					num3 = 111;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 21;
				case 21:
					array2[7] = 115;
					num2 = 301;
					goto IL_0159;
				case 29:
					array[21] = 108;
					num3 = 241;
					if (!n7ab6pnk2A64Dty4Zp())
					{
						goto IL_015d;
					}
					goto case 113;
				case 113:
					array2[8] = 109;
					num = 64;
					continue;
				case 111:
					array2[4] = (byte)num8;
					num = 193;
					continue;
				case 55:
					array[17] = (byte)num5;
					num3 = 30;
					if (true)
					{
						goto IL_015d;
					}
					goto case 232;
				case 232:
					array2[0] = (byte)num8;
					num2 = 83;
					goto IL_0159;
				case 249:
					num6 = 9 + 116;
					num2 = 40;
					goto IL_0159;
				case 139:
					num7 = 154 - 51;
					num3 = 152;
					goto IL_015d;
				case 98:
					num7 = 45 + 73;
					num = 313;
					continue;
				case 129:
					num8 = 149 - 49;
					num2 = 232;
					goto IL_0159;
				case 80:
					array[29] = (byte)num5;
					num2 = 121;
					goto IL_0159;
				case 212:
					array[19] = 224;
					num = 204;
					continue;
				case 69:
					array2[13] = 86;
					num3 = 268;
					if (true)
					{
						goto IL_015d;
					}
					goto case 167;
				case 167:
					array[7] = (byte)num5;
					num = 71;
					continue;
				case 44:
					array2[1] = 140;
					num = 306;
					continue;
				case 274:
					num6 = 136 - 106;
					num3 = 143;
					goto IL_015d;
				case 314:
					array[5] = 124;
					num3 = 100;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 112;
				case 112:
					array[13] = (byte)num7;
					num3 = 236;
					if (true)
					{
						goto IL_015d;
					}
					goto case 107;
				case 107:
					array2[4] = 184;
					num3 = 50;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 103;
				case 103:
					array2[8] = 145;
					num2 = 113;
					goto IL_0159;
				case 308:
					array2[11] = 163;
					num = 144;
					continue;
				case 279:
					array[26] = 110;
					num3 = 233;
					if (true)
					{
						goto IL_015d;
					}
					goto case 17;
				case 17:
					array[31] = (byte)num7;
					num3 = 178;
					if (true)
					{
						goto IL_015d;
					}
					goto case 144;
				case 144:
					array2[11] = 159;
					num = 190;
					continue;
				case 287:
					num5 = 123 + 30;
					num2 = 307;
					goto IL_0159;
				case 28:
					array2[10] = (byte)num6;
					num = 119;
					continue;
				case 67:
					array3[15] = array4[7];
					num2 = 256;
					goto IL_0159;
				case 244:
					array2[6] = (byte)num6;
					num2 = 274;
					goto IL_0159;
				case 222:
					array[17] = (byte)num7;
					num2 = 102;
					goto IL_0159;
				case 304:
					array[4] = 93;
					num = 161;
					continue;
				case 122:
					array[14] = 127;
					num3 = 202;
					if (true)
					{
						goto IL_015d;
					}
					goto case 23;
				case 23:
					array[14] = 100;
					num3 = 122;
					goto IL_015d;
				case 92:
					num7 = 72 + 60;
					num3 = 41;
					goto IL_015d;
				case 289:
					array[13] = (byte)num5;
					num3 = 87;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 100;
				case 100:
					num7 = 139 - 46;
					num = 250;
					continue;
				case 127:
					num7 = 112 + 17;
					num3 = 73;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 70;
				case 70:
					array[11] = (byte)num5;
					num3 = 24;
					if (0 == 0)
					{
						goto IL_015d;
					}
					goto case 108;
				case 108:
					array3[3] = array4[1];
					num3 = 131;
					goto IL_015d;
				case 315:
					num5 = 116 + 94;
					num3 = 167;
					goto IL_015d;
				case 243:
					num7 = 41 - 20;
					num3 = 123;
					goto IL_015d;
				case 6:
					array[11] = (byte)num5;
					num = 11;
					continue;
				case 282:
					array2[1] = (byte)num6;
					num = 81;
					continue;
				case 85:
					num7 = 249 - 83;
					num3 = 184;
					goto IL_015d;
				case 83:
					array2[0] = 146;
					num3 = 299;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 74;
				case 74:
					array[15] = (byte)num7;
					num2 = 309;
					goto IL_0159;
				case 240:
					array[27] = 121;
					num3 = 1;
					goto IL_015d;
				case 190:
					num6 = 202 - 67;
					num2 = 242;
					goto IL_0159;
				case 205:
					array[4] = 0;
					num2 = 314;
					goto IL_0159;
				case 11:
					num5 = 102 + 21;
					num3 = 196;
					goto IL_015d;
				case 160:
					array[15] = 141;
					num3 = 300;
					if (V5iixqcL4bGii0hhu0())
					{
						goto IL_015d;
					}
					goto case 316;
				case 316:
					try
					{
						return (string)jcyliTkNV0v2Ocrbtm(zosUc4AS9Ptb56hO5s(), NLV3ZJVbf, P_0 + 4, num4);
					}
					catch
					{
					}
					return "";
				case 18:
					memoryStream = new MemoryStream();
					num2 = 175;
					goto IL_0159;
				case 256:
					break;
					IL_0159:
					num3 = num2;
					goto IL_015d;
					IL_015d:
					num = num3;
					continue;
				}
				rijndaelManaged = new RijndaelManaged();
				num = 245;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[Yko1SZPbrboHs8umBt(typeof(pZBBYBCsPuqQtRXJTl/Yko1SZPbrboHs8umBt/e6fy4LtuEMMckC6ept<object>[]))]
		internal static string TtGYBYH0E(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void wQ7CXSfJn(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int OIEnISicF(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr nvRP10OCC(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void DJvtZBioE()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void P22GG547V()
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
		internal static object KMUMQwuZB(object P_0)
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
		public static extern IntPtr NYB8sPuqQ(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr hRXOJTlVZ(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int Yo468D27H(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int W7ITesJtq(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int Bo1JSZbrb(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr JHsy8umBt(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int e6fuy4LuE(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[Yko1SZPbrboHs8umBt(typeof(pZBBYBCsPuqQtRXJTl/Yko1SZPbrboHs8umBt/e6fy4LtuEMMckC6ept<object>[]))]
		private static byte[] jMcWkC6ep(string P_0)
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
		[Yko1SZPbrboHs8umBt(typeof(pZBBYBCsPuqQtRXJTl/Yko1SZPbrboHs8umBt/e6fy4LtuEMMckC6ept<object>[]))]
		private static byte[] iAOHKg0MU(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				23, 238, 246, 213, 122, 232, 143, 200, 146, 208,
				65, 41, 155, 233, 143, 83, 83, 223, 113, 249,
				221, 0, 205, 193, 163, 22, 42, 239, 71, 88,
				127, 172
			};
			rijndael.IV = new byte[16]
			{
				54, 43, 120, 242, 166, 144, 41, 51, 74, 220,
				60, 203, 135, 83, 3, 228
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] pdELm0xKK()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] ivVZOIIM2()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] lQvE8uNTs()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] CXbjvZ7tq()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] OAt2YJBeG()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] fbMg862IY()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] mCgrrVhct()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] NOq76oXJg()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] MMmSu1pZ9()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] B6RiXgETf()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public pZBBYBCsPuqQtRXJTl()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type nBqHkKPY6bgkDVTxIr(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object MwV2tDuc1bWL2VSiF5(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object eLyW9OHXnJ1uDuREd4(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void aWOg3JX8LvN4CITXqM(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void vZs7qk6KsPKZbXnuHV(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long PZqCajKeiSGxJ7qrYx(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object D3uepav9VVguvvj2Bp(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object AWHa1w1lm7qRcoI3id(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object pP5ZyQ254R5eIu1a8g(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void nDlmC2SLTiFnttJh3R(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object aNsBaaEYY82wUW0Cy0(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Ft8pGWMd5uQQ7O1uk3(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void fCgE2SJlYaEP7Q2ann(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object CDp7xIOCL5MSU5ZYht(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void RSVBYBGSTvvuBjyD5p(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void epGdua48JR9CVFiJyJ(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int ecbaHFli16Jq5ivEHs(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object zosUc4AS9Ptb56hO5s()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object jcyliTkNV0v2Ocrbtm(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool V5iixqcL4bGii0hhu0()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool n7ab6pnk2A64Dty4Zp()
		{
			return false;
		}
	}
}
namespace xBLVZJJVbfFxZ4AaFR
{
	internal class nfdw4lTyMetKrw77wd
	{
		private static bool dEmaw1eFZ;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void jJaS6jTzKOkTY()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public nfdw4lTyMetKrw77wd()
		{
		}
	}
}
