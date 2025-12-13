using System;
using System.Collections;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using ADDINFACTORYAPILib;
using APPLICATIONAPILib;
using CONMANADDINAPILib;
using Cummins.INSITE.CNL.Common;
using ECMSERVICESAPILib;
using ERRORHANDLINGCOMPONENTSLib;
using INFOSERVICEAPILib;
using INFOSERVICELib;
using jCS8XeSmsAbUg8V9iP;
using kl7c6atWrHpmsdbCpF;

[assembly: Guid("e296ef05-d737-457e-b106-ce6c314707e0")]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(true)]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: AssemblyTitle("Cummins.CNL.Help")]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyProduct("INSITE")]
[assembly: AssemblyDescription("Cummins .NET Libraries Help Component")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace jfGotAL1SlDXyNKlkt
{
	internal static class xH86YwhxFpE1xLuRDJ
	{
	}
}
namespace Cummins.INSITE.CNL.Help
{
	public interface IContextSensitiveHelpProvider
	{
		void Initialize(object kernel, object shell);

		void ShowHelp(IHelpInformation helpClient);

		void ShowHelp(ISelectableHelpInformation selectableHelpClient);

		void ShowHelp(IFaultHelpInformation faultHelpClient);

		void ShowHelp(string contextID, enumHelpType helpType);

		bool IsHelpAvailable(string contextID);
	}
	public class ContextSensitiveHelpProvider : IContextSensitiveHelpProvider
	{
		private const int yjOsAkoeP = -1;

		private const int WwUh0W3ob = 9999;

		private const int IEHL86Ywx = 0;

		protected object _kernel;

		protected object _shell;

		protected IHelpDBReader _helpDBReader;

		protected bool _initialized;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Initialize(object kernel, object shell)
		{
			if (shell == null)
			{
				throw new ArgumentNullException(QUtFgI23xduGwR2Mcp.kJCTfGotA(0));
			}
			if (kernel == null)
			{
				throw new ArgumentNullException(QUtFgI23xduGwR2Mcp.kJCTfGotA(14));
			}
			_kernel = kernel;
			_shell = shell;
			_helpDBReader = new HelpDBReaderImplClass();
			_initialized = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ShowHelp(IHelpInformation helpClient)
		{
			if (!_initialized)
			{
				throw new InvalidOperationException(QUtFgI23xduGwR2Mcp.kJCTfGotA(30));
			}
			InternalShowHelp(helpClient.GUID.ToString(), enumHelpType.GENERIC);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ShowHelp(ISelectableHelpInformation selectableHelpClient)
		{
			if (selectableHelpClient == null)
			{
				throw new ArgumentNullException(QUtFgI23xduGwR2Mcp.kJCTfGotA(142));
			}
			if (!_initialized)
			{
				throw new InvalidOperationException(QUtFgI23xduGwR2Mcp.kJCTfGotA(186));
			}
			string empty = string.Empty;
			empty += selectableHelpClient.GUID;
			if (selectableHelpClient.SelectionID.Length != 0)
			{
				empty += '-';
				empty += selectableHelpClient.SelectionID;
			}
			InternalShowHelp(empty, enumHelpType.GENERIC);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ShowHelp(IFaultHelpInformation faultHelpClient)
		{
			if (!_initialized)
			{
				throw new InvalidOperationException(QUtFgI23xduGwR2Mcp.kJCTfGotA(298));
			}
			string text = faultHelpClient.GUID.ToString();
			text = text + '-' + StringConstants.FaultCodeSelectionIdPrefix;
			text += faultHelpClient.SelectedFaultCode;
			_helpDBReader.TopicType = faultHelpClient.TopicType;
			InternalShowHelp(text, enumHelpType.FAULTS);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsHelpAvailable(string contextID)
		{
			if (!_initialized)
			{
				throw new InvalidOperationException(QUtFgI23xduGwR2Mcp.kJCTfGotA(410));
			}
			bool pbHelpLinkAvailable = false;
			int num = -1;
			uint systemType = 9999u;
			try
			{
				IAddInFactory addInFactory = (IAddInFactory)_kernel;
				IConManWorker conManWorker = (IConManWorker)addInFactory.get_Item(EnumUtils.GetStringValue(ComponentIds.ConnectionManagerWorker));
				num = ((!conManWorker.IsSystemROMBooted()) ? conManWorker.GetModuleID() : (-1));
				_helpDBReader.ModuleId = num;
				_helpDBReader.SystemType = systemType;
				_helpDBReader.IsHelpLinkAvailable(contextID, enumHelpType.GENERIC, out pbHelpLinkAvailable);
			}
			catch
			{
			}
			return pbHelpLinkAvailable;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ShowHelp(string contextID, enumHelpType helpType)
		{
			if (!_initialized)
			{
				throw new InvalidOperationException(QUtFgI23xduGwR2Mcp.kJCTfGotA(522));
			}
			InternalShowHelp(contextID, helpType);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void SetConnectionData()
		{
			_helpDBReader.ModuleId = GetModuleID();
			_helpDBReader.SystemType = GetSystemType();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual int GetModuleID()
		{
			IAddInFactory addInFactory = (IAddInFactory)_kernel;
			IConManWorker conManWorker = (IConManWorker)addInFactory.get_Item(EnumUtils.GetStringValue(ComponentIds.ConnectionManagerWorker));
			if (conManWorker.IsSystemROMBooted())
			{
				return -1;
			}
			return conManWorker.GetModuleID();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual uint GetSystemType()
		{
			IECMServices iECMServices = (IECMServices)_kernel;
			string activeConnectionID = iECMServices.ActiveConnectionID;
			IDataService dataService = iECMServices.DataServices.Add(activeConnectionID);
			IParameter parameter = (IParameter)dataService.Read(TokenConstants.SystemType, ReadTypesEnum.RT_Parameter);
			iECMServices.DataServices.Remove(dataService.ID);
			return Convert.ToUInt32(parameter.RawValue);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void InternalShowHelp(string contextID, enumHelpType helpType)
		{
			string pbstrHelpLink = string.Empty;
			SetConnectionData();
			try
			{
				_helpDBReader.GetHelpLink(contextID, helpType, out pbstrHelpLink);
			}
			catch
			{
			}
			if (pbstrHelpLink.Length != 0)
			{
				DisplayHelp(pbstrHelpLink);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void DisplayHelp(string helpLink)
		{
			IShellServiceProvider shellServiceProvider = (IShellServiceProvider)_shell;
			IInfoDisplay infoDisplay = (IInfoDisplay)shellServiceProvider.GetInfoService();
			HelpInfoComponentClass helpInfoComponentClass = new HelpInfoComponentClass();
			helpInfoComponentClass.helpFile = helpLink;
			helpInfoComponentClass.helpCommand = 0;
			infoDisplay.DisplayInfo(helpInfoComponentClass);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ContextSensitiveHelpProvider()
		{
			Cs8ILWy5nat5ndQKyW.HbjIyjWzurQHW();
			base..ctor();
		}
	}
	public interface IHelpInformation
	{
		Guid GUID { get; }
	}
	public interface ISelectableHelpInformation : IHelpInformation
	{
		string SelectionID { get; }
	}
	public interface IFaultHelpInformation : IHelpInformation
	{
		int SelectedFaultCode { get; }

		enumTopicType TopicType { get; }
	}
}
internal class <Module>{DADFC8C3-0231-4A15-8159-B288996FE71C}
{
}
namespace O532HPTbtiHJ5B67No
{
	internal class XdM3MFvQlH5Pha19l2
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module wpEv1xLuR;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void fllIyjWWAuNWg(int typemdt)
		{
			Type type = wpEv1xLuR.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)wpEv1xLuR.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public XdM3MFvQlH5Pha19l2()
		{
			Cs8ILWy5nat5ndQKyW.HbjIyjWzurQHW();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static XdM3MFvQlH5Pha19l2()
		{
			Cs8ILWy5nat5ndQKyW.HbjIyjWzurQHW();
			wpEv1xLuR = typeof(XdM3MFvQlH5Pha19l2).Assembly.ManifestModule;
		}
	}
}
namespace kl7c6atWrHpmsdbCpF
{
	internal class QUtFgI23xduGwR2Mcp
	{
		internal class wVUNnc86S2oJTghcah : Attribute
		{
			internal class Au1Z2N6j4jm8AWtc6a<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public Au1Z2N6j4jm8AWtc6a()
				{
					Cs8ILWy5nat5ndQKyW.HbjIyjWzurQHW();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[wVUNnc86S2oJTghcah(typeof(QUtFgI23xduGwR2Mcp/wVUNnc86S2oJTghcah/Au1Z2N6j4jm8AWtc6a<object>[]))]
			public wVUNnc86S2oJTghcah(object P_0)
			{
				Cs8ILWy5nat5ndQKyW.HbjIyjWzurQHW();
				base..ctor();
			}
		}

		internal class Buh3lCXV9yWacyIhX7
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[wVUNnc86S2oJTghcah(typeof(QUtFgI23xduGwR2Mcp/wVUNnc86S2oJTghcah/Au1Z2N6j4jm8AWtc6a<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (LGINHVp9M(Convert.ToBase64String(typeof(QUtFgI23xduGwR2Mcp).Assembly.GetName().GetPublicKeyToken()), QUtFgI23xduGwR2Mcp.kJCTfGotA(634)) != QUtFgI23xduGwR2Mcp.kJCTfGotA(640))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[wVUNnc86S2oJTghcah(typeof(QUtFgI23xduGwR2Mcp/wVUNnc86S2oJTghcah/Au1Z2N6j4jm8AWtc6a<object>[]))]
			internal static string LGINHVp9M(string P_0, string P_1)
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
			public Buh3lCXV9yWacyIhX7()
			{
				Cs8ILWy5nat5ndQKyW.HbjIyjWzurQHW();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint sRKAb3CAMEu10vBXOS([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr KujNepDLZZRbCXALvY();

		internal struct FNP0Q0ojnypNwRIuui
		{
			internal bool iVmIl4wQc;

			internal byte[] Cj9QBmRxa;
		}

		[Flags]
		private enum NWNfO73oeDd7sjfcbE
		{

		}

		private static byte[] jS8WXemsA;

		private static byte[] iBi98dwN4;

		private static IntPtr dpwbcyo3N;

		private static object GTNKRoKv9;

		private static int[] XFda75j3O;

		private static long HdXZWZ5Ok;

		internal static sRKAb3CAMEu10vBXOS jnR5wTfSG;

		private static int CvukiwGXX;

		private static bool RPslRnfA7;

		internal static sRKAb3CAMEu10vBXOS SBVpXkEwi;

		private static int SMmH4voLf;

		private static int KoURd731L;

		private static int qjBquBCIF;

		private static byte[] MndGQKyWC;

		internal static Hashtable apnxXgyuh;

		private static IntPtr aRq7fmscu;

		private static long twad2NeEa;

		private static IntPtr KUhMtVKv5;

		private static SortedList KSWB2psli;

		private static byte[] FUg18V9iP;

		private static bool QxkeAaIWJ;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static QUtFgI23xduGwR2Mcp()
		{
			MndGQKyWC = new byte[0];
			jS8WXemsA = new byte[0];
			FUg18V9iP = new byte[0];
			iBi98dwN4 = new byte[0];
			aRq7fmscu = IntPtr.Zero;
			dpwbcyo3N = IntPtr.Zero;
			GTNKRoKv9 = new string[0];
			XFda75j3O = new int[0];
			qjBquBCIF = 1;
			QxkeAaIWJ = false;
			KSWB2psli = new SortedList();
			SMmH4voLf = 0;
			HdXZWZ5Ok = 0L;
			jnR5wTfSG = null;
			SBVpXkEwi = null;
			twad2NeEa = 0L;
			CvukiwGXX = 0;
			RPslRnfA7 = false;
			KoURd731L = 0;
			KUhMtVKv5 = IntPtr.Zero;
			apnxXgyuh = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void fukIyjWJoj6R3()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[wVUNnc86S2oJTghcah(typeof(QUtFgI23xduGwR2Mcp/wVUNnc86S2oJTghcah/Au1Z2N6j4jm8AWtc6a<object>[]))]
		static string kJCTfGotA(int P_0)
		{
			int num = 316;
			byte[] array = default(byte[]);
			int num3 = default(int);
			byte[] array2 = default(byte[]);
			CryptoStream cryptoStream = default(CryptoStream);
			int num7 = default(int);
			byte[] array3 = default(byte[]);
			byte[] array4 = default(byte[]);
			BinaryReader binaryReader = default(BinaryReader);
			int num6 = default(int);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array5 = default(byte[]);
			byte[] array6 = default(byte[]);
			ICryptoTransform transform = default(ICryptoTransform);
			MemoryStream memoryStream = default(MemoryStream);
			int num2 = default(int);
			while (true)
			{
				int num4;
				int num5;
				switch (num)
				{
				case 323:
					array[5] = 58;
					num = 268;
					break;
				case 136:
					array[16] = (byte)num3;
					num4 = 94;
					goto IL_290d;
				case 77:
					Y2La2jo0NncRxO8iUl(true);
					num = 345;
					break;
				case 109:
					array[27] = (byte)num3;
					num4 = 243;
					goto IL_290d;
				case 290:
					array2[7] = 114;
					num5 = 85;
					goto IL_2911;
				case 236:
					array[8] = (byte)num3;
					num5 = 126;
					goto IL_2911;
				case 250:
					array[4] = 111;
					num = 11;
					break;
				case 255:
					array[22] = (byte)num3;
					num = 348;
					break;
				case 362:
					kkYp20ew3W7xscPnkg(cryptoStream);
					num5 = 324;
					if (false)
					{
						goto case 208;
					}
					goto IL_2911;
				case 208:
					array[28] = 139;
					num4 = 328;
					goto IL_290d;
				case 284:
					num7 = 212 + 10;
					num = 73;
					break;
				case 43:
					array3[15] = array4[7];
					num4 = 254;
					goto IL_290d;
				case 306:
					array[9] = (byte)num3;
					num = 34;
					break;
				case 89:
					array[9] = (byte)num3;
					num5 = 105;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 163;
					}
					goto IL_2911;
				case 194:
					num3 = 38 + 81;
					num5 = 291;
					goto IL_2911;
				case 129:
					num7 = 19 + 57;
					num5 = 22;
					if (false)
					{
						goto case 182;
					}
					goto IL_2911;
				case 182:
					array2[9] = (byte)num7;
					num5 = 202;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 244;
					}
					goto IL_2911;
				case 150:
					array[19] = 132;
					num4 = 359;
					goto IL_290d;
				case 202:
					num7 = 60 + 111;
					num5 = 40;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 247;
					}
					goto IL_2911;
				case 247:
					array2[1] = (byte)num7;
					num = 233;
					break;
				case 85:
					num7 = 128 - 42;
					num = 286;
					break;
				case 174:
					array[23] = 130;
					num5 = 242;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 127;
					}
					goto IL_2911;
				case 324:
					Hc2ygxmWd8KNQJpMpH(binaryReader);
					num5 = 23;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 83;
					}
					goto IL_2911;
				case 83:
					array[27] = (byte)num3;
					num5 = 100;
					goto IL_2911;
				case 66:
					array[15] = 90;
					num4 = 74;
					goto IL_290d;
				case 280:
					array[6] = (byte)num3;
					num = 59;
					break;
				case 178:
					num3 = 233 - 77;
					num = 57;
					break;
				case 100:
					num3 = 78 + 60;
					num5 = 63;
					if (false)
					{
						goto case 344;
					}
					goto IL_2911;
				case 344:
					array[24] = (byte)num3;
					num4 = 156;
					goto IL_290d;
				case 329:
					array2[1] = (byte)num7;
					num5 = 166;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 131;
					}
					goto IL_2911;
				case 131:
					array[26] = 120;
					num5 = 133;
					goto IL_2911;
				case 293:
					num3 = 121 + 78;
					num5 = 338;
					if (1 == 0)
					{
						goto case 12;
					}
					goto IL_2911;
				case 12:
					if (array4 != null)
					{
						num = 295;
						break;
					}
					goto case 254;
				case 233:
					num6 = 42 + 124;
					num4 = 334;
					goto IL_290d;
				case 130:
					array2[1] = 139;
					num5 = 213;
					goto IL_2911;
				case 310:
					array2[11] = (byte)num6;
					num4 = 336;
					goto IL_290d;
				case 209:
					num3 = 158 - 53;
					num4 = 81;
					goto IL_290d;
				case 303:
					array[29] = (byte)num3;
					num5 = 331;
					goto IL_2911;
				case 90:
					array[17] = (byte)num3;
					num5 = 245;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 142;
					}
					goto IL_2911;
				case 245:
					num3 = 110 + 51;
					num5 = 283;
					goto IL_2911;
				case 189:
					array2[12] = 169;
					num4 = 326;
					goto IL_290d;
				case 11:
					array[4] = 138;
					num4 = 42;
					goto IL_290d;
				case 332:
					array[26] = (byte)num3;
					num4 = 165;
					goto IL_290d;
				case 59:
					num3 = 89 + 103;
					num5 = 32;
					goto IL_2911;
				case 296:
					num3 = 152 - 50;
					num = 28;
					break;
				case 295:
					if (array4.Length > 0)
					{
						num5 = 215;
						if (plQ0qx9OiAm4J1gC8q())
						{
							goto case 125;
						}
						goto IL_2911;
					}
					goto case 254;
				case 125:
					array[22] = 108;
					num = 187;
					break;
				case 187:
					num3 = 23 + 25;
					num = 16;
					break;
				case 105:
					num3 = 144 + 56;
					num5 = 237;
					if (false)
					{
						goto case 355;
					}
					goto IL_2911;
				case 355:
					array[0] = 153;
					num5 = 304;
					if (false)
					{
						goto case 354;
					}
					goto IL_2911;
				case 354:
					array2[4] = (byte)num6;
					num5 = 217;
					if (false)
					{
						goto case 335;
					}
					goto IL_2911;
				case 335:
					num3 = 151 - 50;
					num = 55;
					break;
				case 308:
					num3 = 64 + 81;
					num4 = 236;
					goto IL_290d;
				case 229:
					num3 = 203 + 26;
					num5 = 320;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 199;
					}
					goto IL_2911;
				case 349:
					array[11] = 196;
					num4 = 251;
					goto IL_290d;
				case 330:
					array[27] = 97;
					num = 14;
					break;
				case 92:
					array2[4] = (byte)num6;
					num4 = 167;
					goto IL_290d;
				case 133:
					num3 = 93 + 124;
					num4 = 332;
					goto IL_290d;
				case 19:
					num3 = 181 - 60;
					num5 = 276;
					if (false)
					{
						goto case 226;
					}
					goto IL_2911;
				case 226:
					binaryReader = new BinaryReader((Stream)agm5edjkN9NYg8e4IP(prEpEZEriXNbqOH3J3(typeof(QUtFgI23xduGwR2Mcp).TypeHandle).Assembly, "gDCMIoWJn3Iqu3nKPx.68eIJELQiUJR3oQMlW"));
					num = 343;
					break;
				case 262:
					array[7] = 199;
					num4 = 285;
					goto IL_290d;
				case 298:
					array[31] = 142;
					_ = 0;
					if (QqZIsxled2cQal2qZJ())
					{
						num5 = 53;
						if (false)
						{
							goto case 156;
						}
					}
					else
					{
						num5 = 272;
						if (plQ0qx9OiAm4J1gC8q())
						{
							goto case 137;
						}
					}
					goto IL_2911;
				case 156:
					array[24] = 134;
					num = 209;
					break;
				case 334:
					array2[1] = (byte)num6;
					num5 = 130;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 146;
					}
					goto IL_2911;
				case 65:
					array[20] = 166;
					num = 258;
					break;
				case 84:
					Ja33eV4BhSt7y67fwQ(rijndaelManaged, CipherMode.CBC);
					num = 238;
					break;
				case 193:
					array2[14] = 139;
					num5 = 261;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 319;
					}
					goto IL_2911;
				case 114:
					array[30] = (byte)num3;
					num = 108;
					break;
				case 223:
					array[6] = 111;
					num4 = 50;
					goto IL_290d;
				case 242:
					array[23] = 128;
					num5 = 135;
					goto IL_2911;
				case 258:
					array[20] = 105;
					num = 305;
					break;
				case 281:
					array[25] = (byte)num3;
					num5 = 173;
					if (false)
					{
						goto case 246;
					}
					goto IL_2911;
				case 246:
					array2[9] = 193;
					num = 0;
					break;
				case 285:
					num3 = 54 + 91;
					num = 313;
					break;
				case 149:
					num3 = 51 + 113;
					num5 = 319;
					goto IL_2911;
				case 5:
					array2[0] = 52;
					num5 = 219;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 198;
					}
					goto IL_2911;
				case 198:
					array2[0] = (byte)num6;
					num = 171;
					break;
				case 205:
					num3 = 92 + 28;
					num4 = 255;
					goto IL_290d;
				case 322:
					PJfMnBKJBmEqqiBdVI(cryptoStream);
					num = 44;
					break;
				case 166:
					num7 = 133 + 37;
					num4 = 118;
					goto IL_290d;
				case 71:
					array[31] = 118;
					num = 159;
					break;
				case 31:
					array[1] = 119;
					num = 341;
					break;
				case 353:
					num3 = 211 - 87;
					num5 = 147;
					goto IL_2911;
				case 326:
					num6 = 48 + 92;
					num = 177;
					break;
				case 1:
					num3 = 205 - 68;
					num4 = 68;
					goto IL_290d;
				case 311:
					num3 = 204 - 68;
					num5 = 88;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 39;
					}
					goto IL_2911;
				case 338:
					array[19] = (byte)num3;
					num5 = 65;
					goto IL_2911;
				case 191:
					array[13] = 164;
					num = 19;
					break;
				case 163:
					array[5] = (byte)num3;
					num = 36;
					break;
				case 341:
					num3 = 182 - 60;
					num5 = 269;
					goto IL_2911;
				case 143:
					num7 = 46 + 122;
					num4 = 183;
					goto IL_290d;
				case 15:
					array[1] = 94;
					num = 200;
					break;
				case 200:
					array[1] = 126;
					num = 31;
					break;
				case 142:
					kDQWU1SXRk2ItIZtSf(cryptoStream, array5, 0, array5.Length);
					num5 = 322;
					goto IL_2911;
				case 111:
					array6 = array;
					num = 218;
					break;
				case 188:
					array2[9] = (byte)num6;
					num5 = 207;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 39;
					}
					goto IL_2911;
				case 39:
					array[28] = (byte)num3;
					num4 = 33;
					goto IL_290d;
				case 185:
					num3 = 70 - 32;
					num = 39;
					break;
				case 95:
					num3 = 129 - 107;
					num5 = 253;
					goto IL_2911;
				case 101:
					array2[3] = (byte)num6;
					num5 = 134;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 193;
					}
					goto IL_2911;
				case 117:
					array[10] = (byte)num3;
					num = 260;
					break;
				case 342:
					array[3] = 88;
					num4 = 335;
					goto IL_290d;
				case 80:
					array[21] = (byte)num3;
					num4 = 35;
					goto IL_290d;
				case 115:
					num7 = 109 + 61;
					num5 = 20;
					goto IL_2911;
				case 301:
					array2[3] = 52;
					num4 = 8;
					goto IL_290d;
				case 145:
					array2[15] = (byte)num6;
					num = 121;
					break;
				case 244:
					num3 = 149 - 72;
					num = 152;
					break;
				case 351:
					array[7] = (byte)num3;
					num = 82;
					break;
				case 110:
					array2[15] = (byte)num7;
					num5 = 302;
					goto IL_2911;
				case 361:
					num3 = 234 - 78;
					num = 357;
					break;
				case 126:
					num3 = 24 + 119;
					num4 = 277;
					goto IL_290d;
				case 275:
					num3 = 45 + 2;
					num5 = 180;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 53;
					}
					goto IL_2911;
				case 48:
					array[31] = 150;
					num4 = 111;
					goto IL_290d;
				case 289:
					array2[6] = (byte)num6;
					num5 = 17;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 55;
					}
					goto IL_2911;
				case 55:
					array[3] = (byte)num3;
					num5 = 264;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 336;
					}
					goto IL_2911;
				case 336:
					array2[11] = 204;
					num4 = 141;
					goto IL_290d;
				case 121:
					num7 = 58 - 28;
					num4 = 360;
					goto IL_290d;
				case 38:
					array[9] = (byte)num3;
					num4 = 140;
					goto IL_290d;
				case 337:
					num3 = 223 - 74;
					num5 = 136;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 243;
					}
					goto IL_2911;
				case 158:
					array[0] = (byte)num3;
					num = 58;
					break;
				case 224:
					num3 = 18 + 26;
					num = 231;
					break;
				case 196:
					array[7] = (byte)num3;
					num = 296;
					break;
				case 53:
				case 230:
					array[31] = 112;
					num = 48;
					break;
				case 153:
					num3 = 43 + 81;
					num5 = 45;
					goto IL_2911;
				case 122:
					array[12] = 120;
					num5 = 162;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 179;
					}
					goto IL_2911;
				case 169:
					num6 = 91 + 77;
					num5 = 249;
					if (false)
					{
						goto case 57;
					}
					goto IL_2911;
				case 57:
					array[15] = (byte)num3;
					num5 = 66;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 342;
					}
					goto IL_2911;
				case 228:
					num7 = 12 + 20;
					num5 = 110;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 139;
					}
					goto IL_2911;
				case 139:
					array[5] = 139;
					num4 = 257;
					goto IL_290d;
				case 42:
					array[4] = 95;
					num5 = 339;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 312;
					}
					goto IL_2911;
				case 10:
					array[10] = 154;
					num5 = 232;
					goto IL_2911;
				case 321:
					array2[12] = 146;
					num4 = 107;
					goto IL_290d;
				case 251:
					num3 = 181 - 99;
					num4 = 225;
					goto IL_290d;
				case 37:
					array[17] = (byte)num3;
					num5 = 190;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 297;
					}
					goto IL_2911;
				case 297:
					num3 = 235 - 78;
					num5 = 280;
					goto IL_2911;
				case 41:
					array2[6] = 214;
					num5 = 61;
					if (!plQ0qx9OiAm4J1gC8q())
					{
						goto IL_2911;
					}
					goto case 254;
				case 220:
					array2[9] = (byte)num6;
					num5 = 265;
					if (false)
					{
						goto case 180;
					}
					goto IL_2911;
				case 180:
					array[1] = (byte)num3;
					num4 = 26;
					goto IL_290d;
				case 277:
					array[8] = (byte)num3;
					num4 = 1;
					goto IL_290d;
				case 305:
					num3 = 97 + 50;
					num = 161;
					break;
				case 132:
					array[18] = (byte)num3;
					num5 = 150;
					goto IL_2911;
				case 160:
					array2[14] = (byte)num6;
					num = 228;
					break;
				case 360:
					array2[15] = (byte)num7;
					num4 = 199;
					goto IL_290d;
				case 292:
					array2[11] = 144;
					num = 318;
					break;
				case 350:
					array2[5] = (byte)num6;
					num4 = 239;
					goto IL_290d;
				case 358:
					num3 = 203 - 67;
					num4 = 266;
					goto IL_290d;
				case 183:
					array2[0] = (byte)num7;
					num = 146;
					break;
				case 32:
					array[6] = (byte)num3;
					num5 = 157;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 328;
					}
					goto IL_2911;
				case 40:
					array2[9] = (byte)num7;
					num5 = 3;
					if (false)
					{
						goto case 210;
					}
					goto IL_2911;
				case 210:
					array3[7] = array4[3];
					num = 211;
					break;
				case 52:
					array[0] = (byte)num3;
					num5 = 288;
					if (0 == 0)
					{
						goto IL_2911;
					}
					goto case 254;
				case 260:
					array[10] = 98;
					num = 273;
					break;
				case 24:
					num3 = 177 - 88;
					num5 = 112;
					goto IL_2911;
				case 79:
					array[4] = (byte)num3;
					num = 244;
					break;
				case 363:
					num3 = 123 + 89;
					num5 = 113;
					goto IL_2911;
				case 88:
					array[18] = (byte)num3;
					num5 = 116;
					goto IL_2911;
				case 56:
					num3 = 195 + 54;
					num4 = 216;
					goto IL_290d;
				case 273:
					num3 = 241 - 80;
					num = 30;
					break;
				case 227:
					array2[2] = (byte)num6;
					num4 = 168;
					goto IL_290d;
				case 291:
					array[21] = (byte)num3;
					num5 = 221;
					goto IL_2911;
				case 238:
					transform = (ICryptoTransform)tWcDBoxmf37fSUhbe6(rijndaelManaged, array6, array3);
					num5 = 274;
					goto IL_2911;
				case 325:
					num6 = 246 - 82;
					num5 = 198;
					if (1 == 0)
					{
						goto case 319;
					}
					goto IL_2911;
				case 319:
					array[27] = (byte)num3;
					num5 = 86;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 97;
					}
					goto IL_2911;
				case 279:
					array2[10] = (byte)num7;
					num = 214;
					break;
				case 159:
					array[31] = 128;
					num = 270;
					break;
				case 2:
					num3 = 58 + 118;
					num4 = 158;
					goto IL_290d;
				case 259:
					kkYp20ew3W7xscPnkg(memoryStream);
					num5 = 362;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 331;
					}
					goto IL_2911;
				case 331:
					array[29] = 118;
					num5 = 271;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 245;
					}
					goto IL_2911;
				case 135:
					num3 = 47 + 89;
					num5 = 252;
					if (1 == 0)
					{
						goto case 124;
					}
					goto IL_2911;
				case 124:
					array2[10] = (byte)num7;
					num = 87;
					break;
				case 144:
					array[19] = 64;
					num5 = 293;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 223;
					}
					goto IL_2911;
				case 64:
					num3 = 11 + 14;
					num = 184;
					break;
				case 20:
					array2[2] = (byte)num7;
					num = 315;
					break;
				case 201:
					array2[11] = 124;
					num4 = 292;
					goto IL_290d;
				case 231:
					array[16] = (byte)num3;
					num = 337;
					break;
				case 154:
					array[28] = (byte)num3;
					num = 347;
					break;
				case 192:
					array[22] = (byte)num3;
					num = 174;
					break;
				case 359:
					num3 = 116 + 65;
					num = 340;
					break;
				case 29:
					array2[14] = (byte)num7;
					num5 = 193;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 61;
					}
					goto IL_2911;
				case 93:
					array[16] = (byte)num3;
					num5 = 224;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 340;
					}
					goto IL_2911;
				case 270:
					array[31] = 92;
					num5 = 298;
					if (false)
					{
						goto case 164;
					}
					goto IL_2911;
				case 164:
					array2[5] = (byte)num6;
					num4 = 123;
					goto IL_290d;
				case 118:
					array2[1] = (byte)num7;
					num5 = 129;
					goto IL_2911;
				case 300:
					array[0] = (byte)num3;
					num4 = 99;
					goto IL_290d;
				case 222:
					array[15] = (byte)num3;
					num = 287;
					break;
				case 215:
					array3[1] = array4[0];
					num5 = 204;
					if (false)
					{
						goto case 204;
					}
					goto IL_2911;
				case 204:
					array3[3] = array4[1];
					num5 = 240;
					goto IL_2911;
				case 315:
					num6 = 241 - 80;
					num = 227;
					break;
				case 172:
					num3 = 18 + 35;
					num4 = 196;
					goto IL_290d;
				case 165:
					array[26] = 194;
					num5 = 98;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 337;
					}
					goto IL_2911;
				case 179:
					array[3] = 169;
					num5 = 342;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 216;
					}
					goto IL_2911;
				case 216:
					array[8] = (byte)num3;
					num4 = 181;
					goto IL_290d;
				case 302:
					num6 = 124 + 81;
					num = 145;
					break;
				case 112:
					array[21] = (byte)num3;
					num5 = 125;
					if (1 == 0)
					{
						goto case 212;
					}
					goto IL_2911;
				case 212:
					array4 = (byte[])V7acH6JSykuWfFX3mp(STmJc2XaEWBt6dNBwf(prEpEZEriXNbqOH3J3(typeof(QUtFgI23xduGwR2Mcp).TypeHandle).Assembly));
					num5 = 12;
					if (false)
					{
						goto case 36;
					}
					goto IL_2911;
				case 36:
					array[5] = 182;
					num = 128;
					break;
				case 237:
					array[9] = (byte)num3;
					num5 = 153;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 168;
					}
					goto IL_2911;
				case 168:
					array2[2] = 229;
					num5 = 301;
					goto IL_2911;
				case 167:
					num6 = 140 + 68;
					num5 = 354;
					goto IL_2911;
				case 58:
					num3 = 70 + 41;
					num = 52;
					break;
				case 294:
					array2[0] = 117;
					num = 143;
					break;
				case 267:
					array2[13] = 115;
					num5 = 346;
					goto IL_2911;
				case 27:
					num3 = 53 + 85;
					num = 90;
					break;
				case 96:
					num3 = 71 + 23;
					num5 = 344;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 200;
					}
					goto IL_2911;
				case 155:
					num3 = 113 + 7;
					num = 114;
					break;
				case 343:
					v4toVuRNnNYh58doxv(EOa2reZ8cnxVim6KyH(binaryReader), 0L);
					num5 = 77;
					goto IL_2911;
				case 94:
					array[16] = 107;
					num = 229;
					break;
				case 152:
					array[4] = (byte)num3;
					num4 = 358;
					goto IL_290d;
				case 312:
					array2[8] = 138;
					num5 = 169;
					goto IL_2911;
				case 248:
					array[25] = (byte)num3;
					num4 = 206;
					goto IL_290d;
				case 346:
					num6 = 195 + 37;
					num4 = 69;
					goto IL_290d;
				case 35:
					array[21] = 84;
					num = 24;
					break;
				case 345:
					array5 = (byte[])nPmjE4Uq2iwHdqvnth(binaryReader, (int)E1AKoYQNuccyPkXfhw(EOa2reZ8cnxVim6KyH(binaryReader)));
					num = 91;
					break;
				case 141:
					num6 = 111 + 103;
					num5 = 186;
					if (1 == 0)
					{
						goto case 28;
					}
					goto IL_2911;
				case 28:
					array[7] = (byte)num3;
					num4 = 256;
					goto IL_290d;
				case 309:
					array[14] = (byte)num3;
					num = 104;
					break;
				case 327:
					array[17] = (byte)num3;
					num4 = 299;
					goto IL_290d;
				case 318:
					num6 = 52 + 110;
					num5 = 310;
					goto IL_2911;
				case 190:
					array[17] = 96;
					num4 = 27;
					goto IL_290d;
				case 271:
					num3 = 116 + 121;
					num5 = 72;
					if (false)
					{
						goto case 333;
					}
					goto IL_2911;
				case 333:
					array2[4] = (byte)num6;
					num4 = 6;
					goto IL_290d;
				case 241:
					array3[13] = array4[6];
					num4 = 43;
					goto IL_290d;
				case 69:
					array2[13] = (byte)num6;
					num4 = 352;
					goto IL_290d;
				case 68:
					array[8] = (byte)num3;
					num5 = 56;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 240;
					}
					goto IL_2911;
				case 162:
					num3 = 112 + 41;
					num4 = 203;
					goto IL_290d;
				case 272:
				case 356:
					cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
					num4 = 142;
					goto IL_290d;
				case 21:
					num3 = 27 + 99;
					num5 = 327;
					if (1 == 0)
					{
						goto case 72;
					}
					goto IL_2911;
				case 72:
					array[30] = (byte)num3;
					num5 = 155;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 252;
					}
					goto IL_2911;
				case 252:
					array[23] = (byte)num3;
					num5 = 96;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 317;
					}
					goto IL_2911;
				case 317:
					array[30] = (byte)num3;
					num5 = 103;
					goto IL_2911;
				case 91:
					array = new byte[32];
					num4 = 2;
					goto IL_290d;
				case 304:
					num3 = 122 + 72;
					num5 = 300;
					goto IL_2911;
				case 74:
					array[15] = 126;
					num4 = 120;
					goto IL_290d;
				case 22:
					array2[2] = (byte)num7;
					num = 115;
					break;
				case 256:
					num3 = 165 - 92;
					num5 = 351;
					goto IL_2911;
				case 63:
					array[27] = (byte)num3;
					num5 = 149;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 340;
					}
					goto IL_2911;
				case 340:
					array[19] = (byte)num3;
					num4 = 361;
					goto IL_290d;
				case 14:
					num3 = 104 + 94;
					num = 154;
					break;
				case 128:
					array[5] = 151;
					num5 = 323;
					if (false)
					{
						goto case 119;
					}
					goto IL_2911;
				case 119:
					num3 = 228 - 76;
					num5 = 281;
					goto IL_2911;
				case 102:
					array2[4] = (byte)num6;
					num4 = 197;
					goto IL_290d;
				case 288:
					array[0] = 129;
					num = 355;
					break;
				case 157:
					array[6] = 188;
					num4 = 262;
					goto IL_290d;
				case 7:
					num6 = 114 + 40;
					num4 = 289;
					goto IL_290d;
				case 225:
					array[11] = (byte)num3;
					num = 122;
					break;
				case 253:
					array[14] = (byte)num3;
					num5 = 178;
					if (false)
					{
						goto case 261;
					}
					goto IL_2911;
				case 261:
					num6 = 103 - 5;
					num4 = 160;
					goto IL_290d;
				case 82:
					array[8] = 155;
					num4 = 308;
					goto IL_290d;
				case 61:
					array2[7] = 130;
					num5 = 290;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 90;
					}
					goto IL_2911;
				case 186:
					array2[11] = (byte)num6;
					num5 = 18;
					goto IL_2911;
				case 50:
					array[6] = 13;
					num5 = 297;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 45;
					}
					goto IL_2911;
				case 45:
					array[10] = (byte)num3;
					num5 = 9;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 300;
					}
					goto IL_2911;
				case 127:
					array[13] = 119;
					num5 = 4;
					if (false)
					{
						goto case 197;
					}
					goto IL_2911;
				case 197:
					num6 = 161 - 53;
					num = 92;
					break;
				case 249:
					array2[8] = (byte)num6;
					num4 = 234;
					goto IL_290d;
				case 16:
					array[22] = (byte)num3;
					num5 = 205;
					goto IL_2911;
				case 9:
					num3 = 36 + 97;
					num4 = 117;
					goto IL_290d;
				case 316:
					if (FUg18V9iP.Length != 0)
					{
						goto case 23;
					}
					num4 = 226;
					goto IL_290d;
				case 106:
					array3[11] = array4[5];
					num5 = 241;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 331;
					}
					goto IL_2911;
				case 213:
					array2[1] = 136;
					num = 49;
					break;
				case 235:
					array[20] = 114;
					num5 = 75;
					if (false)
					{
						goto case 268;
					}
					goto IL_2911;
				case 268:
					array[6] = 146;
					num5 = 223;
					if (1 == 0)
					{
						goto case 177;
					}
					goto IL_2911;
				case 177:
					array2[13] = (byte)num6;
					num5 = 364;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 2;
					}
					goto IL_2911;
				case 75:
					array[20] = 225;
					num4 = 194;
					goto IL_290d;
				case 116:
					num3 = 104 + 78;
					num5 = 132;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 26;
					}
					goto IL_2911;
				case 26:
					array[1] = 188;
					num4 = 15;
					goto IL_290d;
				case 134:
					array2[4] = 162;
					num5 = 70;
					if (1 == 0)
					{
						goto case 86;
					}
					goto IL_2911;
				case 86:
					num3 = 57 + 85;
					num5 = 109;
					goto IL_2911;
				case 234:
					num6 = 227 + 6;
					num = 25;
					break;
				case 328:
					num3 = 107 + 104;
					num4 = 175;
					goto IL_290d;
				case 33:
					array[29] = 120;
					num5 = 282;
					if (false)
					{
						goto case 51;
					}
					goto IL_2911;
				case 51:
					num7 = 206 - 68;
					num5 = 29;
					if (1 == 0)
					{
						goto case 67;
					}
					goto IL_2911;
				case 67:
					num3 = 208 - 69;
					num4 = 89;
					goto IL_290d;
				case 211:
					array3[9] = array4[4];
					num = 106;
					break;
				case 73:
					array2[7] = (byte)num7;
					num4 = 148;
					goto IL_290d;
				case 218:
					array2 = new byte[16];
					num = 294;
					break;
				case 176:
					array[12] = 21;
					num4 = 191;
					goto IL_290d;
				case 278:
					array[25] = 101;
					num5 = 119;
					goto IL_2911;
				case 146:
					array2[0] = 121;
					num = 325;
					break;
				case 113:
					array[13] = (byte)num3;
					num = 195;
					break;
				case 352:
					array2[14] = 145;
					num = 51;
					break;
				case 365:
					array[13] = 162;
					num4 = 127;
					goto IL_290d;
				case 87:
					array2[10] = 170;
					num5 = 201;
					goto IL_2911;
				case 98:
					num3 = 220 - 73;
					num = 83;
					break;
				case 171:
					num7 = 197 - 65;
					num = 97;
					break;
				case 364:
					num6 = 110 + 76;
					num = 170;
					break;
				case 195:
					num3 = 251 - 83;
					num5 = 309;
					if (1 == 0)
					{
						goto case 219;
					}
					goto IL_2911;
				case 219:
					num7 = 193 - 64;
					num5 = 247;
					goto IL_2911;
				case 78:
					array[2] = 31;
					num = 353;
					break;
				case 148:
					array2[8] = 89;
					num4 = 312;
					goto IL_290d;
				case 287:
					num3 = 243 - 81;
					num5 = 93;
					if (false)
					{
						goto case 4;
					}
					goto IL_2911;
				case 4:
					array[13] = 161;
					num5 = 363;
					goto IL_2911;
				case 243:
					num3 = 126 - 42;
					num = 263;
					break;
				case 107:
					array2[12] = 180;
					num4 = 189;
					goto IL_290d;
				case 199:
					array3 = array2;
					num = 212;
					break;
				case 283:
					array[18] = (byte)num3;
					num5 = 311;
					goto IL_2911;
				case 81:
					array[24] = (byte)num3;
					num5 = 64;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 339;
					}
					goto IL_2911;
				case 339:
					num3 = 201 - 67;
					num = 79;
					break;
				case 217:
					array2[5] = 108;
					num4 = 60;
					goto IL_290d;
				case 8:
					array2[3] = 124;
					num5 = 151;
					goto IL_2911;
				case 173:
					num3 = 186 - 62;
					num4 = 248;
					goto IL_290d;
				case 147:
					array[2] = (byte)num3;
					num = 179;
					break;
				case 30:
					array[10] = (byte)num3;
					num5 = 10;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 104;
					}
					goto IL_2911;
				case 104:
					num3 = 102 + 101;
					num = 46;
					break;
				case 161:
					array[20] = (byte)num3;
					num5 = 235;
					if (1 == 0)
					{
						goto case 103;
					}
					goto IL_2911;
				case 103:
					array[30] = 162;
					num5 = 137;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 250;
					}
					goto IL_2911;
				case 60:
					num6 = 134 - 44;
					num4 = 164;
					goto IL_290d;
				case 214:
					num7 = 48 + 117;
					num4 = 124;
					goto IL_290d;
				case 18:
					array2[12] = 223;
					num = 321;
					break;
				case 269:
					array[2] = (byte)num3;
					num4 = 76;
					goto IL_290d;
				case 347:
					array[28] = 144;
					num5 = 307;
					goto IL_2911;
				case 175:
					array[28] = (byte)num3;
					num4 = 185;
					goto IL_290d;
				case 99:
					array[1] = 36;
					num = 275;
					break;
				case 34:
					num3 = 15 + 88;
					num5 = 13;
					goto IL_2911;
				case 49:
					num7 = 42 + 46;
					num5 = 329;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 6;
					}
					goto IL_2911;
				case 6:
					num6 = 223 - 74;
					num = 102;
					break;
				case 307:
					array[28] = 154;
					num5 = 208;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 350;
					}
					goto IL_2911;
				case 23:
					num2 = H8tcSq5UuEMRAywqr0(FUg18V9iP, P_0);
					num4 = 366;
					goto IL_290d;
				case 181:
					num3 = 166 - 55;
					num = 38;
					break;
				case 265:
					num7 = 242 - 80;
					num4 = 182;
					goto IL_290d;
				case 3:
					num6 = 101 - 79;
					num4 = 188;
					goto IL_290d;
				case 207:
					num7 = 155 - 51;
					num = 279;
					break;
				case 170:
					array2[13] = (byte)num6;
					num5 = 267;
					if (1 == 0)
					{
						goto case 76;
					}
					goto IL_2911;
				case 76:
					array[2] = 149;
					num = 78;
					break;
				case 97:
					array2[0] = (byte)num7;
					num5 = 5;
					goto IL_2911;
				case 221:
					num3 = 216 - 72;
					num5 = 80;
					goto IL_2911;
				case 313:
					array[7] = (byte)num3;
					num = 172;
					break;
				case 13:
					array[9] = (byte)num3;
					num = 67;
					break;
				case 206:
					array[25] = 247;
					num4 = 131;
					goto IL_290d;
				case 203:
					array[12] = (byte)num3;
					num = 176;
					break;
				case 0:
					num6 = 108 + 6;
					num = 220;
					break;
				case 357:
					array[19] = (byte)num3;
					num5 = 144;
					if (false)
					{
						goto case 140;
					}
					goto IL_2911;
				case 140:
					num3 = 211 - 70;
					num = 306;
					break;
				case 282:
					num3 = 146 - 48;
					num = 303;
					break;
				case 138:
					num3 = 146 - 32;
					num5 = 192;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 77;
					}
					goto IL_2911;
				case 46:
					array[14] = (byte)num3;
					num5 = 95;
					if (1 == 0)
					{
						goto case 47;
					}
					goto IL_2911;
				case 47:
					array[22] = (byte)num3;
					num4 = 138;
					goto IL_290d;
				case 348:
					num3 = 196 - 65;
					num5 = 47;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 61;
					}
					goto IL_2911;
				case 239:
					array2[5] = 109;
					num = 7;
					break;
				case 299:
					num3 = 208 - 69;
					num4 = 37;
					goto IL_290d;
				case 17:
					array2[6] = 126;
					num5 = 54;
					if (1 == 0)
					{
						goto case 263;
					}
					goto IL_2911;
				case 263:
					array[27] = (byte)num3;
					num = 330;
					break;
				case 314:
					array[30] = (byte)num3;
					num4 = 71;
					goto IL_290d;
				case 232:
					num3 = 8 + 111;
					num5 = 62;
					goto IL_2911;
				case 123:
					num6 = 248 - 82;
					num4 = 350;
					goto IL_290d;
				case 257:
					num3 = 247 - 82;
					num5 = 163;
					if (1 == 0)
					{
						goto case 151;
					}
					goto IL_2911;
				case 151:
					num6 = 82 - 51;
					num5 = 101;
					if (1 == 0)
					{
						goto case 120;
					}
					goto IL_2911;
				case 120:
					num3 = 93 + 54;
					num5 = 222;
					if (false)
					{
						goto case 320;
					}
					goto IL_2911;
				case 320:
					array[16] = (byte)num3;
					num5 = 21;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 240;
					}
					goto IL_2911;
				case 240:
					array3[5] = array4[2];
					num5 = 210;
					if (0 == 0)
					{
						goto IL_2911;
					}
					goto case 274;
				case 137:
					num3 = 161 - 121;
					num4 = 314;
					goto IL_290d;
				case 286:
					array2[7] = (byte)num7;
					num4 = 284;
					goto IL_290d;
				case 108:
					num3 = 73 + 6;
					num4 = 317;
					goto IL_290d;
				case 70:
					num6 = 221 - 73;
					num5 = 333;
					if (plQ0qx9OiAm4J1gC8q())
					{
						goto case 251;
					}
					goto IL_2911;
				case 54:
					array2[6] = 88;
					num4 = 41;
					goto IL_290d;
				case 266:
					array[5] = (byte)num3;
					num5 = 139;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 117;
					}
					goto IL_2911;
				case 264:
					array[3] = 214;
					num4 = 250;
					goto IL_290d;
				case 25:
					array2[8] = (byte)num6;
					num5 = 246;
					if (false)
					{
						goto case 184;
					}
					goto IL_2911;
				case 184:
					array[25] = (byte)num3;
					goto case 278;
				default:
					num5 = 278;
					goto IL_2911;
				case 62:
					array[11] = (byte)num3;
					num5 = 349;
					goto IL_2911;
				case 276:
					array[13] = (byte)num3;
					num5 = 365;
					if (!QqZIsxled2cQal2qZJ())
					{
						goto case 193;
					}
					goto IL_2911;
				case 44:
					FUg18V9iP = (byte[])l4uLZgt6CjiSMSeW3q(memoryStream);
					num5 = 259;
					goto IL_2911;
				case 366:
					try
					{
						return (string)oqN8ba3S15TQxFkoRT(Olb2ApFhhbH2jE7DLH(), FUg18V9iP, P_0 + 4, num2);
					}
					catch
					{
					}
					return "";
				case 254:
					rijndaelManaged = new RijndaelManaged();
					num5 = 84;
					goto IL_2911;
				case 274:
					{
						memoryStream = new MemoryStream();
						goto case 272;
					}
					IL_290d:
					num5 = num4;
					goto IL_2911;
					IL_2911:
					num = num5;
					break;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[wVUNnc86S2oJTghcah(typeof(QUtFgI23xduGwR2Mcp/wVUNnc86S2oJTghcah/Au1Z2N6j4jm8AWtc6a<object>[]))]
		internal static string CSl2DXyNK(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void PkttndM3M(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int vQl8H5Pha(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr D9l62k532(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void KPbXtiHJ5()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void J67CNoMUt()
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
		internal static object wgID3xduG(object P_0)
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
		public static extern IntPtr aR2oMcpDl(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr Ec63aWrHp(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int zsdybCpFF(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int qUNSnc6S2(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int lJTOghcah(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr Au10Z2Nj4(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int Ym8JAWtc6(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[wVUNnc86S2oJTghcah(typeof(QUtFgI23xduGwR2Mcp/wVUNnc86S2oJTghcah/Au1Z2N6j4jm8AWtc6a<object>[]))]
		private static byte[] GWuVh3lCV(string P_0)
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
		[wVUNnc86S2oJTghcah(typeof(QUtFgI23xduGwR2Mcp/wVUNnc86S2oJTghcah/Au1Z2N6j4jm8AWtc6a<object>[]))]
		private static byte[] DyWuacyIh(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				127, 115, 143, 117, 61, 9, 252, 139, 76, 25,
				44, 37, 19, 64, 0, 233, 105, 167, 103, 248,
				122, 94, 177, 23, 77, 48, 216, 193, 122, 30,
				26, 7
			};
			rijndael.IV = new byte[16]
			{
				11, 21, 68, 205, 40, 172, 165, 14, 36, 229,
				178, 240, 20, 84, 189, 225
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] i7ggRKAb3()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] YMEcu10vB()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] jOSfZujNe()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] MLZiZRbCX()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] XLvFYbNP0()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] U0jYnypNw()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] QIuEuipWN()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] uO74oeDd7()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] ajfmcbEWs()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] hILrW5nat()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public QUtFgI23xduGwR2Mcp()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type prEpEZEriXNbqOH3J3(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object agm5edjkN9NYg8e4IP(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object EOa2reZ8cnxVim6KyH(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void v4toVuRNnNYh58doxv(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Y2La2jo0NncRxO8iUl(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long E1AKoYQNuccyPkXfhw(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object nPmjE4Uq2iwHdqvnth(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object STmJc2XaEWBt6dNBwf(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object V7acH6JSykuWfFX3mp(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Ja33eV4BhSt7y67fwQ(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object tWcDBoxmf37fSUhbe6(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void kDQWU1SXRk2ItIZtSf(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void PJfMnBKJBmEqqiBdVI(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object l4uLZgt6CjiSMSeW3q(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void kkYp20ew3W7xscPnkg(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Hc2ygxmWd8KNQJpMpH(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int H8tcSq5UuEMRAywqr0(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Olb2ApFhhbH2jE7DLH()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object oqN8ba3S15TQxFkoRT(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool QqZIsxled2cQal2qZJ()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool plQ0qx9OiAm4J1gC8q()
		{
			return false;
		}
	}
}
namespace jCS8XeSmsAbUg8V9iP
{
	internal class Cs8ILWy5nat5ndQKyW
	{
		private static bool SRlP9xS9o;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void HbjIyjWzurQHW()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Cs8ILWy5nat5ndQKyW()
		{
		}
	}
}
