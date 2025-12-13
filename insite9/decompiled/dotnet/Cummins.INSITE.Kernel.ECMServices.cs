using System;
using System.Collections;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using Cummins.INSITE.Kernel.CommunicationServices;
using Cummins.INSITE.Kernel.ConnectionServices;
using Cummins.INSITE.Kernel.DataServices;
using Cummins.INSITE.Kernel.ECMServicesAPI;
using Cummins.INSITE.Kernel.ICLServices;
using Cummins.INSITE.Kernel.ImageServices;
using Cummins.INSITE.Kernel.MetadataServices;
using Cummins.INSITE.Kernel.MonitorServices;
using eoP53YVgQa1lbB0Xy6;

[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: Guid("188076bd-b24c-4955-bf87-02d720a0ad33")]
[assembly: InternalsVisibleTo("ECMServicesUnitTest")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyDelaySign(false)]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyTitle("Cummins.INSITE.Kernel.ECMServices")]
[assembly: AssemblyProduct("Cummins.INSITE.Kernel.ECMServices")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyDescription("")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(true)]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyVersion("7.6.0.272")]
internal static class tMTBbwutK6mSNdh5cK
{
}
namespace Cummins.INSITE.Kernel.ECMServices
{
	[ComVisible(true)]
	[Guid("3422C155-E6D9-4A9B-88F1-A25D07BD380C")]
	[ProgId("Cummins.INSITE.Kernel.ECMServices.1")]
	[ClassInterface(ClassInterfaceType.None)]
	public class ECMServices : IECMServices
	{
		private ECMServicesHelper oYAm1lRqJ;

		public IMetadataServices MetadataServices
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return oYAm1lRqJ.MetadataServices;
			}
		}

		public IDataServices DataServices
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return oYAm1lRqJ.DataServices;
			}
		}

		public IConnections Connections
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return oYAm1lRqJ.Connections;
			}
		}

		public IMonitorServices MonitorServices
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return oYAm1lRqJ.MonitorServices;
			}
		}

		public IImageServices ImageServices
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return oYAm1lRqJ.ImageServices;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECMServices()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.LnC5VoYz7rJPV();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Initialize(string metadataDatabasePath, string xmlResourcesFolderPath, string iclDatafilesFolderPath, string configfilePath, string fnpDatabasePath, string dynamicEnumXmlPath)
		{
			oYAm1lRqJ = new ECMServicesHelper(metadataDatabasePath, xmlResourcesFolderPath, iclDatafilesFolderPath, configfilePath, fnpDatabasePath, dynamicEnumXmlPath);
		}
	}
	internal class ECMServicesHelper
	{
		private IICLServices iDhrj4ec9;

		private ICommunicationServices tf4yT3uhG;

		private IMetadataServices sthIuApL4;

		private IConfigMetadataProvider YcMM8PlxQ;

		private IParameterMetadataProvider EqwQMqTT7;

		private ISystemInformationProvider gVEs7lDG8;

		private IConnections MOGKHBemC;

		private IDataServices ok37Vtl8j;

		private IMonitorServices j9DYpUV35;

		private IImageServices qlPJXBEYQ;

		public IConnections Connections
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return MOGKHBemC;
			}
		}

		public IDataServices DataServices
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ok37Vtl8j;
			}
		}

		public IImageServices ImageServices
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return qlPJXBEYQ;
			}
		}

		public IMetadataServices MetadataServices
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return sthIuApL4;
			}
		}

		public IMonitorServices MonitorServices
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return j9DYpUV35;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECMServicesHelper(string metadataDatabasePath, string xmlResourcesFolderPath, string iclDatafilesFolderPath, string configfilePath, string fnpDatabasePath, string dynamicEnumXmlPath)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.LnC5VoYz7rJPV();
			base..ctor();
			mOiaZh6pl(iclDatafilesFolderPath);
			Gn7XUFAEX();
			QxHFxrrcx(metadataDatabasePath, xmlResourcesFolderPath, iclDatafilesFolderPath, configfilePath, fnpDatabasePath, dynamicEnumXmlPath);
			SbC1yLaqZ();
			Gljus0JIp();
			slTp038Li();
			Yc6Z6tZeo();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void mOiaZh6pl(string P_0)
		{
			Cummins.INSITE.Kernel.ICLServices.ICLServices iCLServices = new Cummins.INSITE.Kernel.ICLServices.ICLServices();
			iCLServices.Initialize(P_0);
			iDhrj4ec9 = iCLServices;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void QxHFxrrcx(string P_0, string P_1, string P_2, string P_3, string P_4, string P_5)
		{
			Cummins.INSITE.Kernel.MetadataServices.MetadataServices metadataServices = (Cummins.INSITE.Kernel.MetadataServices.MetadataServices)(sthIuApL4 = new Cummins.INSITE.Kernel.MetadataServices.MetadataServices(P_0, P_1, P_2, P_3, P_4, P_5, tf4yT3uhG.Connector));
			EqwQMqTT7 = metadataServices.ParameterMetadataProvider;
			YcMM8PlxQ = metadataServices.ConfigMetadataProvider;
			gVEs7lDG8 = metadataServices.SystemInformationProvider;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Gn7XUFAEX()
		{
			Cummins.INSITE.Kernel.CommunicationServices.CommunicationServices communicationServices = new Cummins.INSITE.Kernel.CommunicationServices.CommunicationServices();
			tf4yT3uhG = communicationServices;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void SbC1yLaqZ()
		{
			Connections mOGKHBemC = new Connections(tf4yT3uhG.Connector, sthIuApL4, gVEs7lDG8);
			MOGKHBemC = mOGKHBemC;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Gljus0JIp()
		{
			Cummins.INSITE.Kernel.DataServices.DataServices dataServices = new Cummins.INSITE.Kernel.DataServices.DataServices(sthIuApL4, EqwQMqTT7, YcMM8PlxQ, MOGKHBemC, tf4yT3uhG.Connector);
			ok37Vtl8j = dataServices;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void slTp038Li()
		{
			Cummins.INSITE.Kernel.MonitorServices.MonitorServices monitorServices = new Cummins.INSITE.Kernel.MonitorServices.MonitorServices(ok37Vtl8j, MOGKHBemC, tf4yT3uhG.Connector, sthIuApL4, EqwQMqTT7, (ok37Vtl8j as Cummins.INSITE.Kernel.DataServices.DataServices).ParameterFactory);
			j9DYpUV35 = monitorServices;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Yc6Z6tZeo()
		{
			Cummins.INSITE.Kernel.ImageServices.ImageServices imageServices = new Cummins.INSITE.Kernel.ImageServices.ImageServices(sthIuApL4, EqwQMqTT7, MOGKHBemC, ok37Vtl8j);
			qlPJXBEYQ = imageServices;
		}
	}
}
internal class <Module>{39B27463-F20D-48FA-91DE-2942D5A48109}
{
}
namespace eaNnw6oJwxIQQ7FE5G
{
	internal class eILexUWtydOj1ZbkDZ
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module e1WCAykK0;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void iYU5VoYYKalHs(int typemdt)
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
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.LnC5VoYz7rJPV();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static eILexUWtydOj1ZbkDZ()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.LnC5VoYz7rJPV();
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
					eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.LnC5VoYz7rJPV();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			public epk4JLxQrEvWi6AHPc(object P_0)
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.LnC5VoYz7rJPV();
				base..ctor();
			}
		}

		internal class eqCW27S8VxFfnK7ae3
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (e1WCAykK0(Convert.ToBase64String(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).Assembly.GetName().GetPublicKeyToken()), eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(0)) != eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(6))
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
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.LnC5VoYz7rJPV();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint epLVT0LsDNCS2M0vSw([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr sHxrrcaxPn7UFAEX2b();

		internal struct eMo8xctuZSKRfJjCaO
		{
			internal bool e1WCAykK0;

			internal byte[] eopWKtZX1;
		}

		[Flags]
		private enum AyLaqZFPljs0JIpxlT
		{

		}

		private static byte[] tGnvyd5aK;

		private static IntPtr XpQGjS4hQ;

		private static int[] kyMHPsvlX;

		private static long MNZTP5d27;

		private static bool kABEIhXvJ;

		private static IntPtr KTM817kCW;

		private static int uV9iRm486;

		private static object QcGWIcd9u;

		internal static Hashtable e712GIHvk;

		private static SortedList SYt51IolK;

		private static bool lPK3QC9In;

		private static int VMKBwa0Js;

		internal static epLVT0LsDNCS2M0vSw eWbNGoLe6;

		private static int HGj2yMmAK;

		private static IntPtr aSceahkWM;

		private static byte[] aiANbkkD4;

		private static byte[] p1aPwtGnh;

		internal static epLVT0LsDNCS2M0vSw ebfRCcJMs;

		private static int WotfOTDVh;

		private static long TTStY3miJ;

		private static byte[] CmgA1jRZO;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static emYpxP33xAq8jO8oJ1()
		{
			tGnvyd5aK = new byte[0];
			CmgA1jRZO = new byte[0];
			p1aPwtGnh = new byte[0];
			aiANbkkD4 = new byte[0];
			aSceahkWM = IntPtr.Zero;
			XpQGjS4hQ = IntPtr.Zero;
			QcGWIcd9u = new string[0];
			kyMHPsvlX = new int[0];
			uV9iRm486 = 1;
			lPK3QC9In = false;
			SYt51IolK = new SortedList();
			VMKBwa0Js = 0;
			MNZTP5d27 = 0L;
			ebfRCcJMs = null;
			eWbNGoLe6 = null;
			TTStY3miJ = 0L;
			WotfOTDVh = 0;
			kABEIhXvJ = false;
			HGj2yMmAK = 0;
			KTM817kCW = IntPtr.Zero;
			e712GIHvk = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void mt65VoY9JnOgd()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		static string eopWKtZX1(int P_0)
		{
			int num = 295;
			byte[] array2 = default(byte[]);
			int num5 = default(int);
			int num3 = default(int);
			CryptoStream cryptoStream = default(CryptoStream);
			MemoryStream memoryStream = default(MemoryStream);
			ICryptoTransform transform = default(ICryptoTransform);
			byte[] array4 = default(byte[]);
			byte[] array3 = default(byte[]);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array6 = default(byte[]);
			byte[] array = default(byte[]);
			int num4 = default(int);
			BinaryReader binaryReader = default(BinaryReader);
			byte[] array5 = default(byte[]);
			while (true)
			{
				int num2 = num;
				while (true)
				{
					int num6;
					switch (num2)
					{
					case 191:
						array2[20] = (byte)num5;
						num6 = 146;
						goto IL_13fc;
					case 153:
						num3 = 169 - 56;
						num = 201;
						if (0 == 0)
						{
							break;
						}
						goto case 291;
					case 291:
						num3 = 23 + 45;
						num2 = 170;
						continue;
					case 348:
						num5 = 171 - 57;
						num = 77;
						break;
					case 59:
						array2[29] = (byte)num5;
						num2 = 152;
						continue;
					case 103:
						cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
						num = 262;
						break;
					case 318:
						array4[15] = array3[7];
						num = 156;
						if (0 == 0)
						{
							break;
						}
						goto case 60;
					case 60:
						array2[23] = 110;
						num2 = 159;
						continue;
					case 206:
						array2[1] = (byte)num5;
						num6 = 100;
						goto IL_13fc;
					case 194:
						array2[22] = 165;
						num = 75;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 358;
					case 358:
						array4[13] = array3[6];
						num = 318;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 346;
					case 152:
						num5 = 23 + 67;
						num2 = 177;
						continue;
					case 69:
						NvsPq2U7cHS1LNu8a0(memoryStream);
						num = 134;
						break;
					case 38:
						num5 = 223 - 74;
						num6 = 255;
						goto IL_13fc;
					case 350:
						num5 = 115 + 20;
						num = 314;
						break;
					case 5:
						array2[26] = 167;
						num = 275;
						break;
					case 244:
						transform = (ICryptoTransform)Yfnase8k1ctOultCDB(rijndaelManaged, array6, array4);
						num = 209;
						break;
					case 220:
						array2[13] = 142;
						num2 = 320;
						continue;
					case 8:
						array2[24] = 48;
						num = 226;
						if (true)
						{
							break;
						}
						goto case 217;
					case 217:
						KQD333IoIVfHO157OW(cryptoStream);
						num2 = 73;
						continue;
					case 128:
						num5 = 15 + 84;
						num = 92;
						if (true)
						{
							break;
						}
						goto case 343;
					case 343:
						array2[12] = (byte)num5;
						num2 = 3;
						continue;
					case 255:
						array2[27] = (byte)num5;
						num = 83;
						if (0 == 0)
						{
							break;
						}
						goto case 246;
					case 246:
						num3 = 181 - 60;
						num6 = 86;
						goto IL_13fc;
					case 169:
						num5 = 16 + 110;
						num = 59;
						break;
					case 41:
						num3 = 227 + 22;
						num = 199;
						break;
					case 109:
						array2[15] = 216;
						num2 = 357;
						continue;
					case 355:
						array[14] = 175;
						num2 = 102;
						continue;
					case 199:
						array[7] = (byte)num3;
						num2 = 153;
						continue;
					case 290:
						array2[24] = (byte)num5;
						num6 = 120;
						goto IL_13fc;
					case 304:
						array2[20] = 97;
						num2 = 64;
						continue;
					case 24:
						array2[2] = (byte)num5;
						num2 = 197;
						continue;
					case 183:
						array2[14] = (byte)num5;
						num6 = 132;
						goto IL_13fc;
					case 55:
						array2[22] = (byte)num5;
						num = 228;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 260;
					case 260:
						array[2] = (byte)num3;
						num = 20;
						break;
					case 42:
						num3 = 140 + 36;
						num6 = 66;
						goto IL_13fc;
					case 310:
						array2[11] = (byte)num5;
						num = 192;
						if (true)
						{
							break;
						}
						goto case 331;
					case 331:
						array2[8] = 113;
						num2 = 115;
						continue;
					case 17:
						num3 = 136 - 45;
						num = 230;
						break;
					case 269:
						array[6] = (byte)num3;
						num = 249;
						if (0 == 0)
						{
							break;
						}
						goto case 20;
					case 20:
						num3 = 5 + 80;
						num = 315;
						break;
					case 175:
						num5 = 16 + 30;
						num6 = 239;
						goto IL_13fc;
					case 54:
						array2[26] = (byte)num5;
						num = 5;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 205;
					case 280:
						array[13] = 130;
						num2 = 172;
						continue;
					case 13:
						array2[10] = 144;
						num6 = 222;
						goto IL_13fc;
					case 110:
						array2[6] = (byte)num5;
						num6 = 233;
						goto IL_13fc;
					case 340:
						array2[5] = (byte)num5;
						num = 23;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 16;
					case 29:
						array[15] = (byte)num3;
						num = 14;
						break;
					case 121:
						array[6] = (byte)num3;
						num = 258;
						if (0 == 0)
						{
							break;
						}
						goto case 162;
					case 162:
						num4 = KwTFmqcKw8mGqkeqFW(p1aPwtGnh, P_0);
						num = 359;
						if (true)
						{
							break;
						}
						goto case 146;
					case 146:
						array2[20] = 126;
						num2 = 337;
						continue;
					case 108:
						num5 = 121 + 71;
						num2 = 281;
						continue;
					case 326:
						array2[28] = 159;
						num6 = 150;
						goto IL_13fc;
					case 241:
						array2 = new byte[32];
						num2 = 193;
						continue;
					case 213:
						num3 = 188 - 62;
						num6 = 101;
						goto IL_13fc;
					case 176:
						array2[16] = 153;
						num = 319;
						break;
					case 126:
						num5 = 136 + 0;
						num = 218;
						break;
					case 166:
						array = new byte[16];
						num = 341;
						if (0 == 0)
						{
							break;
						}
						goto case 34;
					case 34:
						array[5] = 147;
						num2 = 336;
						continue;
					case 266:
						array2[24] = 138;
						num = 8;
						if (0 == 0)
						{
							break;
						}
						goto case 67;
					case 67:
						array4 = array;
						num = 299;
						if (0 == 0)
						{
							break;
						}
						goto case 155;
					case 155:
						array[6] = 92;
						num = 225;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 203;
					case 203:
						num5 = 192 - 64;
						num6 = 340;
						goto IL_13fc;
					case 140:
						array2[26] = 54;
						num = 124;
						break;
					case 221:
						num3 = 27 + 87;
						num = 89;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 68;
					case 85:
						array2[7] = (byte)num5;
						num2 = 87;
						continue;
					case 263:
						num5 = 155 - 51;
						num2 = 165;
						continue;
					case 4:
						array2[25] = (byte)num5;
						num = 276;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 305;
					case 305:
						num3 = 251 - 83;
						num2 = 117;
						continue;
					case 273:
						num5 = 190 - 63;
						num6 = 253;
						goto IL_13fc;
					case 345:
						binaryReader = new BinaryReader((Stream)NMVdj3iF4wbJe2T3qD(G9Zu8YbjiehBKtKPqZ(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).TypeHandle).Assembly, "SUQkM4xTKYrVvnHrFe.wINfSac1uqL1dIM5tH"));
						num2 = 316;
						continue;
					case 271:
						num5 = 49 - 25;
						num2 = 158;
						continue;
					case 174:
						array2[21] = (byte)num5;
						num6 = 303;
						goto IL_13fc;
					case 7:
						array[3] = 168;
						num = 6;
						if (0 == 0)
						{
							break;
						}
						goto case 52;
					case 52:
						num3 = 58 + 103;
						num = 105;
						if (0 == 0)
						{
							break;
						}
						goto case 115;
					case 115:
						num5 = 49 + 65;
						num = 65;
						if (0 == 0)
						{
							break;
						}
						goto case 212;
					case 212:
						array2[6] = (byte)num5;
						num6 = 263;
						goto IL_13fc;
					case 9:
						array[0] = 254;
						num = 221;
						if (0 == 0)
						{
							break;
						}
						goto case 165;
					case 165:
						array2[6] = (byte)num5;
						num2 = 45;
						continue;
					case 132:
						array2[14] = 163;
						num2 = 113;
						continue;
					case 11:
						array6 = array2;
						num2 = 166;
						continue;
					case 338:
						array2[28] = 150;
						num6 = 326;
						goto IL_13fc;
					case 328:
						array2[6] = (byte)num5;
						num6 = 1;
						goto IL_13fc;
					case 114:
						array2[9] = 144;
						num2 = 154;
						continue;
					case 308:
						array2[4] = (byte)num5;
						num = 19;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 119;
					case 198:
						array2[22] = 96;
						num6 = 229;
						goto IL_13fc;
					case 320:
						array2[13] = 197;
						num = 129;
						if (true)
						{
							break;
						}
						goto case 74;
					case 74:
						array2[31] = (byte)num5;
						num6 = 271;
						goto IL_13fc;
					case 336:
						num3 = 19 + 65;
						num = 312;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 333;
					case 171:
						array2[4] = 89;
						num2 = 130;
						continue;
					case 48:
						array[4] = 161;
						num2 = 231;
						continue;
					case 72:
						array2[2] = (byte)num5;
						num6 = 118;
						goto IL_13fc;
					case 90:
						array4[3] = array3[1];
						num = 180;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 66;
					case 145:
						num5 = 54 + 8;
						num2 = 310;
						continue;
					case 80:
						num5 = 98 + 88;
						num = 27;
						if (true)
						{
							break;
						}
						goto case 332;
					case 332:
						array5 = (byte[])swSlRfaeAtXTpZCt9L(binaryReader, (int)zAZo2RHKqIQw1V1Dm8(Gcal3Ax8fJFiT4ByF5(binaryReader)));
						num2 = 241;
						continue;
					case 314:
						array2[16] = (byte)num5;
						num6 = 186;
						goto IL_13fc;
					case 354:
						array2[8] = 91;
						num = 49;
						break;
					case 3:
						array2[12] = 119;
						num = 68;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 226;
					case 226:
						num5 = 224 - 74;
						num = 333;
						if (true)
						{
							break;
						}
						goto case 31;
					case 31:
						array[6] = (byte)num3;
						num = 84;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 270;
					case 270:
						array2[14] = (byte)num5;
						num = 36;
						break;
					case 294:
						num5 = 90 + 68;
						num6 = 39;
						goto IL_13fc;
					case 218:
						array2[27] = (byte)num5;
						num = 338;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 317;
					case 317:
						array2[30] = 94;
						num2 = 195;
						continue;
					case 293:
						num5 = 147 - 49;
						num = 35;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 229;
					case 229:
						num5 = 204 - 68;
						num2 = 179;
						continue;
					case 116:
						num3 = 200 - 87;
						num6 = 351;
						goto IL_13fc;
					case 77:
						array2[30] = (byte)num5;
						num2 = 71;
						continue;
					case 207:
						array[11] = 142;
						num6 = 246;
						goto IL_13fc;
					case 272:
						num3 = 184 - 112;
						num2 = 215;
						continue;
					case 139:
						num5 = 214 - 71;
						num = 206;
						if (true)
						{
							break;
						}
						goto case 253;
					case 253:
						array2[15] = (byte)num5;
						num = 109;
						if (0 == 0)
						{
							break;
						}
						goto case 28;
					case 28:
						array[15] = 129;
						num2 = 61;
						continue;
					case 284:
						num3 = 88 + 14;
						num2 = 237;
						continue;
					case 185:
						array2[27] = 143;
						num6 = 342;
						goto IL_13fc;
					case 157:
						array2[21] = (byte)num5;
						num = 198;
						break;
					case 188:
						array[15] = (byte)num3;
						num = 67;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 347;
					case 347:
						array2[26] = (byte)num5;
						num = 10;
						break;
					case 283:
						num3 = 130 - 43;
						num2 = 31;
						continue;
					case 53:
						num5 = 138 - 46;
						num = 74;
						break;
					case 182:
						array[14] = 135;
						num2 = 211;
						continue;
					case 352:
						num5 = 99 - 60;
						num = 37;
						break;
					case 193:
						num5 = 189 - 63;
						num = 346;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 241;
					case 239:
						array2[9] = (byte)num5;
						num = 114;
						if (true)
						{
							break;
						}
						goto case 227;
					case 227:
						array2[17] = (byte)num5;
						num6 = 104;
						goto IL_13fc;
					case 89:
						array[1] = (byte)num3;
						num = 144;
						break;
					case 261:
						array[2] = 182;
						c0tfxHPxrkKJ8tCj9H();
						if (!R8XmekETSfteIoOuio())
						{
							num = 62;
							if (!R8XmekETSfteIoOuio())
							{
								break;
							}
							goto case 106;
						}
						num2 = 82;
						continue;
					case 106:
						array[0] = 110;
						num6 = 30;
						goto IL_13fc;
					case 324:
						array2[8] = 3;
						num = 43;
						break;
					case 281:
						array2[31] = (byte)num5;
						num2 = 53;
						continue;
					case 210:
						num5 = 77 - 51;
						num = 72;
						break;
					case 279:
						array[0] = (byte)num3;
						num2 = 106;
						continue;
					case 181:
						num5 = 236 - 78;
						num = 85;
						break;
					case 187:
						array2[30] = 117;
						num2 = 349;
						continue;
					case 75:
						array2[22] = 123;
						num = 33;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 216;
					case 216:
						array2[3] = (byte)num5;
						num = 240;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 15;
					case 15:
						array4[1] = array3[0];
						num2 = 90;
						continue;
					case 136:
						array[13] = (byte)num3;
						num6 = 252;
						goto IL_13fc;
					case 192:
						array2[11] = 187;
						num = 167;
						break;
					case 102:
						num3 = 94 + 94;
						num2 = 29;
						continue;
					case 322:
						array2[16] = 137;
						num2 = 176;
						continue;
					case 46:
						num5 = 110 - 81;
						num6 = 44;
						goto IL_13fc;
					case 84:
						num3 = 26 + 86;
						num = 121;
						if (true)
						{
							break;
						}
						goto case 292;
					case 292:
						array2[20] = (byte)num5;
						num2 = 304;
						continue;
					case 265:
						array2[18] = 11;
						num2 = 293;
						continue;
					case 219:
						num5 = 58 - 8;
						num = 202;
						if (true)
						{
							break;
						}
						goto case 96;
					case 96:
						array[12] = 100;
						num = 57;
						break;
					case 356:
						array2[14] = 64;
						num6 = 160;
						goto IL_13fc;
					case 70:
						array2[29] = 79;
						num = 317;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 241;
					case 100:
						num5 = 173 - 57;
						num2 = 298;
						continue;
					case 163:
						slldBMGfJVL3v6NEjl(rijndaelManaged, CipherMode.CBC);
						num2 = 244;
						continue;
					case 346:
						array2[0] = (byte)num5;
						num = 88;
						break;
					case 323:
						num3 = 15 + 91;
						num2 = 136;
						continue;
					case 230:
						array[7] = (byte)num3;
						num = 214;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 154;
					case 154:
						num5 = 228 - 76;
						num = 78;
						if (true)
						{
							break;
						}
						goto case 211;
					case 211:
						array[14] = 16;
						num = 355;
						if (true)
						{
							break;
						}
						goto case 61;
					case 61:
						num3 = 91 + 112;
						num6 = 188;
						goto IL_13fc;
					case 276:
						array2[26] = 114;
						num = 140;
						break;
					case 288:
						num5 = 236 - 78;
						num2 = 328;
						continue;
					case 161:
						if (array3.Length > 0)
						{
							num2 = 15;
							continue;
						}
						goto case 156;
					case 202:
						array2[17] = (byte)num5;
						num2 = 265;
						continue;
					case 315:
						array[2] = (byte)num3;
						num2 = 234;
						continue;
					case 179:
						array2[22] = (byte)num5;
						num2 = 194;
						continue;
					case 32:
						num5 = 42 + 115;
						num2 = 93;
						continue;
					case 120:
						array2[24] = 145;
						num = 266;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 152;
					case 312:
						array[5] = (byte)num3;
						num6 = 213;
						goto IL_13fc;
					case 215:
						array[12] = (byte)num3;
						num = 323;
						if (0 == 0)
						{
							break;
						}
						goto case 334;
					case 334:
						array4[9] = array3[4];
						num2 = 164;
						continue;
					case 99:
						array2[29] = (byte)num5;
						num = 151;
						if (0 == 0)
						{
							break;
						}
						goto case 129;
					case 129:
						num5 = 171 - 57;
						num = 224;
						if (true)
						{
							break;
						}
						goto case 49;
					case 49:
						array2[8] = 115;
						num6 = 327;
						goto IL_13fc;
					case 95:
						num5 = 207 + 18;
						num = 4;
						if (0 == 0)
						{
							break;
						}
						goto case 201;
					case 201:
						array[8] = (byte)num3;
						num = 254;
						break;
					case 27:
						array2[25] = (byte)num5;
						goto case 95;
					default:
						num6 = 95;
						goto IL_13fc;
					case 122:
						array[9] = 78;
						num = 282;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 134;
					case 134:
						NvsPq2U7cHS1LNu8a0(cryptoStream);
						num = 285;
						if (true)
						{
							break;
						}
						goto case 138;
					case 138:
						array2[25] = 97;
						num2 = 80;
						continue;
					case 124:
						num5 = 36 + 25;
						num = 54;
						break;
					case 222:
						num5 = 103 + 44;
						num = 297;
						break;
					case 66:
						array[11] = (byte)num3;
						num6 = 96;
						goto IL_13fc;
					case 123:
						array[0] = 145;
						num6 = 9;
						goto IL_13fc;
					case 316:
						PX9MUVNtAGoDnLjE5A(Gcal3Ax8fJFiT4ByF5(binaryReader), 0L);
						num = 142;
						break;
					case 25:
						array2[13] = 94;
						num = 137;
						break;
					case 307:
						num5 = 101 + 36;
						num6 = 325;
						goto IL_13fc;
					case 56:
						num5 = 161 - 53;
						num6 = 212;
						goto IL_13fc;
					case 327:
						num5 = 107 + 22;
						num6 = 286;
						goto IL_13fc;
					case 112:
						array[12] = (byte)num3;
						num6 = 272;
						goto IL_13fc;
					case 344:
						array2[27] = (byte)num5;
						num6 = 38;
						goto IL_13fc;
					case 311:
						array2[1] = 144;
						num = 40;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 342;
					case 12:
						array2[16] = 137;
						num6 = 322;
						goto IL_13fc;
					case 148:
						array[13] = 222;
						num2 = 291;
						continue;
					case 257:
						num5 = 247 - 82;
						num6 = 174;
						goto IL_13fc;
					case 159:
						num5 = 136 - 45;
						num = 290;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 252;
					case 252:
						num3 = 245 - 81;
						num6 = 168;
						goto IL_13fc;
					case 282:
						array[10] = 152;
						num = 284;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 93;
					case 93:
						array2[5] = (byte)num5;
						num = 288;
						if (true)
						{
							break;
						}
						goto case 0;
					case 0:
						num3 = 134 - 44;
						num = 18;
						break;
					case 300:
						array2[18] = 67;
						num = 47;
						if (0 == 0)
						{
							break;
						}
						goto case 262;
					case 262:
						YfVv5I6tyckQgKOXDt(cryptoStream, array5, 0, array5.Length);
						num = 217;
						break;
					case 245:
						array2[7] = (byte)num5;
						num = 181;
						if (0 == 0)
						{
							break;
						}
						goto case 18;
					case 18:
						array[10] = (byte)num3;
						num2 = 335;
						continue;
					case 88:
						array2[0] = 150;
						num6 = 307;
						goto IL_13fc;
					case 232:
						array2[17] = (byte)num5;
						num6 = 63;
						goto IL_13fc;
					case 63:
						array2[17] = 109;
						num = 119;
						if (0 == 0)
						{
							break;
						}
						goto case 144;
					case 144:
						array[1] = 79;
						num = 305;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 205;
					case 287:
						num5 = 12 + 46;
						num = 24;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 333;
					case 333:
						array2[25] = (byte)num5;
						num6 = 98;
						goto IL_13fc;
					case 254:
						array[8] = 114;
						num = 278;
						if (true)
						{
							break;
						}
						goto case 302;
					case 302:
						array2[19] = (byte)num5;
						num2 = 296;
						continue;
					case 45:
						num5 = 167 + 86;
						num = 110;
						break;
					case 101:
						array[5] = (byte)num3;
						num = 116;
						if (0 == 0)
						{
							break;
						}
						goto case 321;
					case 321:
						array2[4] = (byte)num5;
						num = 235;
						if (true)
						{
							break;
						}
						goto case 248;
					case 248:
						array2[5] = (byte)num5;
						num2 = 32;
						continue;
					case 208:
						array2[9] = 133;
						num6 = 175;
						goto IL_13fc;
					case 235:
						num5 = 4 + 105;
						num2 = 308;
						continue;
					case 91:
						array[6] = (byte)num3;
						num2 = 155;
						continue;
					case 26:
						array[8] = (byte)num3;
						num6 = 190;
						goto IL_13fc;
					case 150:
						array2[28] = 27;
						num2 = 256;
						continue;
					case 131:
						num3 = 122 + 29;
						num = 112;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 308;
					case 50:
						num3 = 107 + 107;
						num6 = 269;
						goto IL_13fc;
					case 117:
						array[1] = (byte)num3;
						num2 = 97;
						continue;
					case 231:
						num3 = 214 - 71;
						num2 = 79;
						continue;
					case 259:
						num5 = 114 + 118;
						num = 99;
						break;
					case 178:
						array2[19] = (byte)num5;
						num2 = 301;
						continue;
					case 160:
						num5 = 183 - 61;
						num6 = 183;
						goto IL_13fc;
					case 82:
					case 329:
						array[15] = 131;
						num = 28;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 149;
					case 130:
						num5 = 196 - 65;
						num2 = 274;
						continue;
					case 79:
						array[4] = (byte)num3;
						num = 107;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 175;
					case 170:
						array[14] = (byte)num3;
						num = 149;
						if (0 == 0)
						{
							break;
						}
						goto case 43;
					case 43:
						num5 = 37 + 5;
						num2 = 133;
						continue;
					case 275:
						num5 = 211 - 70;
						num = 347;
						break;
					case 251:
						array[0] = (byte)num3;
						num2 = 123;
						continue;
					case 97:
						num3 = 65 - 51;
						num2 = 277;
						continue;
					case 225:
						array[7] = 161;
						num = 17;
						if (true)
						{
							break;
						}
						goto case 184;
					case 184:
						num3 = 156 - 52;
						num6 = 268;
						goto IL_13fc;
					case 186:
						array2[16] = 215;
						num = 12;
						if (0 == 0)
						{
							break;
						}
						goto case 149;
					case 149:
						array[14] = 138;
						num2 = 250;
						continue;
					case 214:
						array[7] = 106;
						num = 41;
						break;
					case 234:
						array[2] = 128;
						num = 261;
						break;
					case 268:
						array[9] = (byte)num3;
						num = 122;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 128;
					case 118:
						array2[3] = 114;
						num = 223;
						break;
					case 39:
						array2[23] = (byte)num5;
						num = 243;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 357;
					case 357:
						array2[16] = 126;
						num6 = 350;
						goto IL_13fc;
					case 58:
						array2[10] = 144;
						num2 = 13;
						continue;
					case 309:
						array2[25] = 109;
						num = 138;
						break;
					case 289:
						num5 = 77 + 10;
						num6 = 216;
						goto IL_13fc;
					case 73:
						p1aPwtGnh = (byte[])zLNZ7mLmj4JrxH5UNt(memoryStream);
						num = 69;
						if (0 == 0)
						{
							break;
						}
						goto case 264;
					case 264:
						array2[4] = (byte)num5;
						num = 143;
						if (true)
						{
							break;
						}
						goto case 94;
					case 94:
						num3 = 115 + 28;
						num = 26;
						break;
					case 200:
						num5 = 77 + 29;
						num = 191;
						break;
					case 177:
						array2[29] = (byte)num5;
						num6 = 259;
						goto IL_13fc;
					case 204:
						num3 = 157 - 105;
						num = 135;
						break;
					case 337:
						num5 = 146 - 48;
						num2 = 292;
						continue;
					case 78:
						array2[10] = (byte)num5;
						num = 58;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 185;
					case 190:
						num3 = 217 - 72;
						num6 = 125;
						goto IL_13fc;
					case 104:
						num5 = 179 - 59;
						num = 232;
						if (true)
						{
							break;
						}
						goto case 168;
					case 168:
						array[13] = (byte)num3;
						num6 = 280;
						goto IL_13fc;
					case 83:
						array2[27] = 116;
						num = 126;
						break;
					case 6:
						num3 = 163 + 45;
						num6 = 313;
						goto IL_13fc;
					case 250:
						array[14] = 172;
						num6 = 182;
						goto IL_13fc;
					case 111:
						array2[23] = 82;
						num2 = 294;
						continue;
					case 47:
						array2[18] = 147;
						num2 = 128;
						continue;
					case 137:
						array2[13] = 102;
						num2 = 220;
						continue;
					case 233:
						num5 = 57 + 46;
						num = 245;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 133;
					case 133:
						array2[9] = (byte)num5;
						num = 208;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 152;
					case 197:
						array2[2] = 182;
						num = 210;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 44;
					case 35:
						array2[18] = (byte)num5;
						num2 = 300;
						continue;
					case 339:
						num3 = 170 - 56;
						num = 260;
						if (0 == 0)
						{
							break;
						}
						goto case 286;
					case 286:
						array2[8] = (byte)num5;
						num2 = 331;
						continue;
					case 65:
						array2[8] = (byte)num5;
						num = 324;
						break;
					case 10:
						num5 = 146 - 92;
						num2 = 147;
						continue;
					case 195:
						num5 = 167 - 55;
						num2 = 189;
						continue;
					case 237:
						array[10] = (byte)num3;
						num = 0;
						break;
					case 256:
						array2[29] = 129;
						num2 = 169;
						continue;
					case 2:
						if (array3 != null)
						{
							num2 = 161;
							continue;
						}
						goto case 156;
					case 240:
						array2[3] = 80;
						num2 = 46;
						continue;
					case 119:
						array2[17] = 185;
						num6 = 219;
						goto IL_13fc;
					case 107:
						array[4] = 95;
						num2 = 204;
						continue;
					case 22:
						num5 = 200 - 66;
						num6 = 264;
						goto IL_13fc;
					case 223:
						array2[3] = 85;
						num = 81;
						if (0 == 0)
						{
							break;
						}
						goto case 135;
					case 135:
						array[4] = (byte)num3;
						num = 330;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 354;
					case 40:
						num5 = 225 + 27;
						num = 16;
						break;
					case 196:
						array2[12] = (byte)num5;
						num = 205;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 55;
					case 335:
						array[10] = 172;
						num = 207;
						break;
					case 98:
						num5 = 44 + 29;
						num = 242;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 173;
					case 173:
						array[3] = (byte)num3;
						num6 = 7;
						goto IL_13fc;
					case 295:
						if (p1aPwtGnh.Length != 0)
						{
							goto case 162;
						}
						num6 = 345;
						goto IL_13fc;
					case 258:
						num3 = 57 + 46;
						num6 = 91;
						goto IL_13fc;
					case 228:
						array2[23] = 89;
						num2 = 111;
						continue;
					case 267:
						array2[11] = (byte)num5;
						num6 = 145;
						goto IL_13fc;
					case 30:
						num3 = 214 - 71;
						num = 251;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 125;
					case 125:
						array[9] = (byte)num3;
						num2 = 184;
						continue;
					case 36:
						array2[15] = 135;
						num = 306;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 105;
					case 180:
						array4[5] = array3[2];
						num = 76;
						break;
					case 243:
						array2[23] = 27;
						num = 60;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 212;
					case 303:
						num5 = 89 - 28;
						num = 157;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 316;
					case 325:
						array2[0] = (byte)num5;
						num = 139;
						break;
					case 1:
						array2[6] = 109;
						num6 = 56;
						goto IL_13fc;
					case 164:
						array4[11] = array3[5];
						num2 = 358;
						continue;
					case 278:
						array[8] = 124;
						num2 = 94;
						continue;
					case 238:
						num5 = 23 + 105;
						num = 178;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 297;
					case 297:
						array2[10] = (byte)num5;
						num = 51;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 330;
					case 330:
						array[5] = 120;
						num = 34;
						if (0 == 0)
						{
							break;
						}
						goto case 158;
					case 158:
						array2[31] = (byte)num5;
						num6 = 11;
						goto IL_13fc;
					case 353:
						array2[29] = (byte)num5;
						num2 = 70;
						continue;
					case 242:
						array2[25] = (byte)num5;
						num6 = 309;
						goto IL_13fc;
					case 249:
						array[6] = 90;
						num2 = 283;
						continue;
					case 16:
						array2[1] = (byte)num5;
						num6 = 287;
						goto IL_13fc;
					case 44:
						array2[3] = (byte)num5;
						num = 22;
						if (0 == 0)
						{
							break;
						}
						goto case 127;
					case 127:
						array2[21] = (byte)num5;
						num2 = 257;
						continue;
					case 167:
						array2[12] = 100;
						num6 = 236;
						goto IL_13fc;
					case 141:
						array2[15] = 202;
						num2 = 273;
						continue;
					case 105:
						array[12] = (byte)num3;
						num2 = 131;
						continue;
					case 341:
						num3 = 61 + 119;
						num6 = 279;
						goto IL_13fc;
					case 33:
						num5 = 53 + 102;
						num6 = 55;
						goto IL_13fc;
					case 113:
						num5 = 45 + 93;
						num2 = 270;
						continue;
					case 76:
						array4[7] = array3[3];
						num2 = 334;
						continue;
					case 296:
						array2[19] = 254;
						num6 = 200;
						goto IL_13fc;
					case 143:
						num5 = 168 - 56;
						num2 = 321;
						continue;
					case 299:
						array3 = (byte[])eeK0yQfxowMUk6xUdj(a4CUilKy9yvHJUbn62(G9Zu8YbjiehBKtKPqZ(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).TypeHandle).Assembly));
						num2 = 2;
						continue;
					case 86:
						array[11] = (byte)num3;
						num2 = 42;
						continue;
					case 51:
						num5 = 212 - 70;
						num = 267;
						break;
					case 37:
						array2[18] = (byte)num5;
						num2 = 238;
						continue;
					case 81:
						array2[3] = 107;
						num = 289;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 351;
					case 351:
						array[5] = (byte)num3;
						num = 50;
						break;
					case 224:
						array2[14] = (byte)num5;
						num6 = 356;
						goto IL_13fc;
					case 68:
						num5 = 29 + 46;
						num = 196;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 10;
					case 189:
						array2[30] = (byte)num5;
						num6 = 187;
						goto IL_13fc;
					case 142:
						axF8S5VQ1XwOs80Rmp(true);
						num2 = 332;
						continue;
					case 172:
						array[13] = 74;
						num = 148;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 248;
					case 301:
						num5 = 205 - 68;
						num6 = 302;
						goto IL_13fc;
					case 306:
						num5 = 5 + 11;
						num2 = 21;
						continue;
					case 147:
						array2[26] = (byte)num5;
						num = 185;
						if (true)
						{
							break;
						}
						goto case 342;
					case 342:
						num5 = 253 - 84;
						num2 = 344;
						continue;
					case 21:
						array2[15] = (byte)num5;
						num = 141;
						break;
					case 57:
						array[12] = 94;
						num2 = 52;
						continue;
					case 274:
						array2[5] = (byte)num5;
						num2 = 203;
						continue;
					case 62:
					case 247:
						num3 = 205 - 68;
						num6 = 173;
						goto IL_13fc;
					case 151:
						num5 = 218 - 72;
						num = 353;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 209;
					case 14:
						array[15] = 102;
						goto case 82;
					case 92:
						array2[18] = (byte)num5;
						num6 = 352;
						goto IL_13fc;
					case 298:
						array2[1] = (byte)num5;
						num6 = 311;
						goto IL_13fc;
					case 64:
						num5 = 217 - 72;
						num = 127;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 108;
					case 71:
						array2[30] = 176;
						num = 108;
						break;
					case 285:
						jEMR1yA9uyH05GwEEm(binaryReader);
						num2 = 162;
						continue;
					case 19:
						array2[4] = 120;
						num6 = 171;
						goto IL_13fc;
					case 349:
						array2[30] = 112;
						num = 348;
						if (true)
						{
							break;
						}
						goto case 236;
					case 236:
						num5 = 15 + 54;
						num6 = 343;
						goto IL_13fc;
					case 23:
						num5 = 60 + 73;
						num = 248;
						if (c0tfxHPxrkKJ8tCj9H())
						{
							break;
						}
						goto case 335;
					case 277:
						array[1] = (byte)num3;
						num = 339;
						if (0 == 0)
						{
							break;
						}
						goto case 87;
					case 87:
						array2[7] = 6;
						num = 354;
						if (0 == 0)
						{
							break;
						}
						goto case 205;
					case 205:
						array2[12] = 242;
						num2 = 25;
						continue;
					case 319:
						num5 = 78 + 11;
						num6 = 227;
						goto IL_13fc;
					case 313:
						array[3] = (byte)num3;
						num = 48;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 359;
					case 359:
						try
						{
							return (string)uWvnjQTBhgRiTtAZDC(HkCo7NgDmVYfpiHvpo(), p1aPwtGnh, P_0 + 4, num4);
						}
						catch
						{
						}
						return "";
					case 156:
						rijndaelManaged = new RijndaelManaged();
						num = 163;
						if (!R8XmekETSfteIoOuio())
						{
							break;
						}
						goto case 16;
					case 209:
						{
							memoryStream = new MemoryStream();
							num = 103;
							break;
						}
						IL_13fc:
						num = num6;
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
		private static extern void QFE6pQtEc(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int hXHhc4Qau(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr eQ7GFE5Gm(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void dRSxPVibT()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void leL97PP6u()
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
		private static extern int NGELXcTLf(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int RwHg4Pqpc(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int CZD03FWaS(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr GG3qyDdrk(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int vlKVTTFRg(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		private static byte[] vAJnCBjCS(string P_0)
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
		private static byte[] IxqOiDNA4(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				238, 160, 153, 110, 29, 2, 250, 85, 218, 59,
				177, 98, 229, 181, 119, 207, 195, 165, 235, 213,
				64, 22, 26, 111, 131, 202, 38, 26, 58, 237,
				106, 107
			};
			rijndael.IV = new byte[16]
			{
				240, 235, 189, 51, 204, 87, 66, 243, 64, 78,
				87, 11, 254, 235, 77, 9
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] HSckVXoAG()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] M0HlbOcpr()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] eQZCGSIrZ()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] dkORlBS5u()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] S7SbPPY7P()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] PxQjX5CHg()
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
		internal static Type G9Zu8YbjiehBKtKPqZ(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object NMVdj3iF4wbJe2T3qD(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Gcal3Ax8fJFiT4ByF5(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void PX9MUVNtAGoDnLjE5A(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void axF8S5VQ1XwOs80Rmp(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long zAZo2RHKqIQw1V1Dm8(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object swSlRfaeAtXTpZCt9L(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object a4CUilKy9yvHJUbn62(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object eeK0yQfxowMUk6xUdj(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void slldBMGfJVL3v6NEjl(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Yfnase8k1ctOultCDB(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void YfVv5I6tyckQgKOXDt(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void KQD333IoIVfHO157OW(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object zLNZ7mLmj4JrxH5UNt(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void NvsPq2U7cHS1LNu8a0(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void jEMR1yA9uyH05GwEEm(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int KwTFmqcKw8mGqkeqFW(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object HkCo7NgDmVYfpiHvpo()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object uWvnjQTBhgRiTtAZDC(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool c0tfxHPxrkKJ8tCj9H()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool R8XmekETSfteIoOuio()
		{
			return false;
		}
	}
}
namespace eoP53YVgQa1lbB0Xy6
{
	internal class eGujxxQN0KjsXHehk2
	{
		private static bool hDMcn6JKm;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void LnC5VoYz7rJPV()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public eGujxxQN0KjsXHehk2()
		{
		}
	}
}
