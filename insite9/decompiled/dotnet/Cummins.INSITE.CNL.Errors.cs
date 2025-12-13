using System;
using System.Collections;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using APPLICATIONAPILib;
using Cummins.INSITE.CNL.Common;
using Cummins.INSITE.CNL.Localization;
using INFOSERVICEAPILib;
using Microsoft.VisualStudio.Shell.Interop;
using VSPY5GrKy04poVZRBN;
using tVUokn0jhIoNgRQDkm;

[assembly: Guid("99ea8b9a-dab8-4130-b796-3ac8981b53fa")]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(true)]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: AssemblyTitle("Cummins.CNL.Errors")]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyProduct("INSITE")]
[assembly: AssemblyDescription("Cummins .NET Libraries Errors Component")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace H7OUE7GQZ5ip619Ir4
{
	internal static class DaqkoO8bN2pj6rGcx5
	{
	}
}
namespace Cummins.INSITE.CNL.Errors
{
	public sealed class ErrorInfo : IErrorInfo
	{
		private string wttk0ZNOr;

		public string Description
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return wttk0ZNOr;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				wttk0ZNOr = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		int IErrorInfo.GetDescription(out string pbstrDescription)
		{
			pbstrDescription = wttk0ZNOr;
			return 0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		int IErrorInfo.GetGuid(out Guid pGuid)
		{
			pGuid = new Guid(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
			return 0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		int IErrorInfo.GetHelpContext(out uint pdwHelpContext)
		{
			pdwHelpContext = 0u;
			return 0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		int IErrorInfo.GetHelpFile(out string pBstrHelpFile)
		{
			pBstrHelpFile = string.Empty;
			return 0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		int IErrorInfo.GetSource(out string pBstrSource)
		{
			pBstrSource = string.Empty;
			return 0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ErrorInfo()
		{
			gQpMUo9BaRmomVY8Y6.iFpI5mkzQBkBs();
			base..ctor();
		}
	}
	public static class ErrorConstants
	{
		public static readonly int E_TEST_PRECONDITION_FAIL;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static ErrorConstants()
		{
			gQpMUo9BaRmomVY8Y6.iFpI5mkzQBkBs();
			E_TEST_PRECONDITION_FAIL = -2147481599;
		}
	}
	public interface IErrorDisplay
	{
		void Initialize(object shell, ILocalizedStringProvider stringProvider);

		void DisplayError(Enum error);

		void DisplayError(int errorCode);
	}
	public class ErrorDisplay : IErrorDisplay
	{
		protected IInfoDisplay _infoDisplay;

		protected ILocalizedStringProvider _stringProvider;

		protected bool _initialized;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Initialize(object shell, ILocalizedStringProvider stringProvider)
		{
			if (shell == null)
			{
				throw new ArgumentNullException(IDT5L2gGT4LqxN5AMo.svaGqkoOb(0));
			}
			if (stringProvider == null)
			{
				throw new ArgumentNullException(IDT5L2gGT4LqxN5AMo.svaGqkoOb(14));
			}
			IShellServiceProvider shellServiceProvider = (IShellServiceProvider)shell;
			_infoDisplay = shellServiceProvider.GetInfoService() as IInfoDisplay;
			_stringProvider = stringProvider;
			_initialized = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void DisplayError(Enum error)
		{
			if (!_initialized)
			{
				throw new InvalidOperationException(IDT5L2gGT4LqxN5AMo.svaGqkoOb(46));
			}
			InternalDisplayError(Convert.ToInt32(error));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void DisplayError(int errorCode)
		{
			if (!_initialized)
			{
				throw new InvalidOperationException(IDT5L2gGT4LqxN5AMo.svaGqkoOb(184));
			}
			InternalDisplayError(errorCode);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void InternalDisplayError(int errorCode)
		{
			try
			{
				string text = _stringProvider.GetLocalizedString(errorCode);
				if (text == null)
				{
					text = string.Format(StringConstants.DefaultErrorXMLString, errorCode);
				}
				ErrorInfo errorInfo = new ErrorInfo();
				errorInfo.Description = text;
				_infoDisplay.DisplayInfo(errorInfo);
			}
			catch (Exception)
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ErrorDisplay()
		{
			gQpMUo9BaRmomVY8Y6.iFpI5mkzQBkBs();
			base..ctor();
		}
	}
}
internal class <Module>{FC9043A0-EA63-43EB-9044-0859024665D7}
{
}
namespace ktCOxF3BgXlinysp2C
{
	internal class G8dk97Ofn7mpOqsv2l
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module MaF8PWg8l;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void tV5I5mkkTk8Zm(int typemdt)
		{
			Type type = MaF8PWg8l.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)MaF8PWg8l.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public G8dk97Ofn7mpOqsv2l()
		{
			gQpMUo9BaRmomVY8Y6.iFpI5mkzQBkBs();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static G8dk97Ofn7mpOqsv2l()
		{
			gQpMUo9BaRmomVY8Y6.iFpI5mkzQBkBs();
			MaF8PWg8l = typeof(G8dk97Ofn7mpOqsv2l).Assembly.ManifestModule;
		}
	}
}
namespace VSPY5GrKy04poVZRBN
{
	internal class IDT5L2gGT4LqxN5AMo
	{
		internal class Mf3UrmESbsW5fOWrC4 : Attribute
		{
			internal class kRHXL45P9Bs0gWeAvJ<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public kRHXL45P9Bs0gWeAvJ()
				{
					gQpMUo9BaRmomVY8Y6.iFpI5mkzQBkBs();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[Mf3UrmESbsW5fOWrC4(typeof(IDT5L2gGT4LqxN5AMo/Mf3UrmESbsW5fOWrC4/kRHXL45P9Bs0gWeAvJ<object>[]))]
			public Mf3UrmESbsW5fOWrC4(object P_0)
			{
				gQpMUo9BaRmomVY8Y6.iFpI5mkzQBkBs();
				base..ctor();
			}
		}

		internal class N6HPFAcG0Tx5cHn523
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[Mf3UrmESbsW5fOWrC4(typeof(IDT5L2gGT4LqxN5AMo/Mf3UrmESbsW5fOWrC4/kRHXL45P9Bs0gWeAvJ<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (f37KyFiXu(Convert.ToBase64String(typeof(IDT5L2gGT4LqxN5AMo).Assembly.GetName().GetPublicKeyToken()), IDT5L2gGT4LqxN5AMo.svaGqkoOb(322)) != IDT5L2gGT4LqxN5AMo.svaGqkoOb(328))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[Mf3UrmESbsW5fOWrC4(typeof(IDT5L2gGT4LqxN5AMo/Mf3UrmESbsW5fOWrC4/kRHXL45P9Bs0gWeAvJ<object>[]))]
			internal static string f37KyFiXu(string P_0, string P_1)
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
			public N6HPFAcG0Tx5cHn523()
			{
				gQpMUo9BaRmomVY8Y6.iFpI5mkzQBkBs();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint Wn9O2yIrF2M7gQa6ls([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr yxdMixUutCJtugA6nc();

		internal struct OAHOf6bO9Zf7op6OyS
		{
			internal bool qyndTuQjq;

			internal byte[] dtJJmmAaB;
		}

		[Flags]
		private enum VFeHumCJXo8kP7weGH
		{

		}

		private static byte[] aMUXoBaRm;

		private static int DdLZhYPSl;

		private static long LvPF85QRD;

		internal static Wn9O2yIrF2M7gQa6ls mL9j6UGGo;

		private static int jKaMr3Ztc;

		private static bool IauTPbM3s;

		private static int mgOaQH0nv;

		private static SortedList vuhSXNcEQ;

		private static byte[] xUoLknjhI;

		private static long FqxA9ncjd;

		private static int[] EF2WDYSRl;

		private static bool nBVundVpI;

		internal static Hashtable QyAsHBpHj;

		private static object kKtmFLytf;

		private static byte[] tmVRY8Y6o;

		internal static Wn9O2yIrF2M7gQa6ls I5bBM363d;

		private static IntPtr hUqvBxLHV;

		private static IntPtr tNgQRQDkm;

		private static int tJotyHFiS;

		private static byte[] q7wqeGHrQ;

		private static IntPtr nPcxDvtun;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static IDT5L2gGT4LqxN5AMo()
		{
			q7wqeGHrQ = new byte[0];
			aMUXoBaRm = new byte[0];
			tmVRY8Y6o = new byte[0];
			xUoLknjhI = new byte[0];
			tNgQRQDkm = IntPtr.Zero;
			hUqvBxLHV = IntPtr.Zero;
			kKtmFLytf = new string[0];
			EF2WDYSRl = new int[0];
			DdLZhYPSl = 1;
			nBVundVpI = false;
			vuhSXNcEQ = new SortedList();
			tJotyHFiS = 0;
			LvPF85QRD = 0L;
			mL9j6UGGo = null;
			I5bBM363d = null;
			FqxA9ncjd = 0L;
			jKaMr3Ztc = 0;
			IauTPbM3s = false;
			mgOaQH0nv = 0;
			nPcxDvtun = IntPtr.Zero;
			QyAsHBpHj = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Vc2I5mkKBbq0b()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[Mf3UrmESbsW5fOWrC4(typeof(IDT5L2gGT4LqxN5AMo/Mf3UrmESbsW5fOWrC4/kRHXL45P9Bs0gWeAvJ<object>[]))]
		static string svaGqkoOb(int P_0)
		{
			int num = 319;
			int num5 = default(int);
			byte[] array = default(byte[]);
			int num4 = default(int);
			byte[] array2 = default(byte[]);
			byte[] array4 = default(byte[]);
			byte[] array5 = default(byte[]);
			BinaryReader binaryReader = default(BinaryReader);
			ICryptoTransform transform = default(ICryptoTransform);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array6 = default(byte[]);
			CryptoStream cryptoStream = default(CryptoStream);
			MemoryStream memoryStream = default(MemoryStream);
			byte[] array3 = default(byte[]);
			int num3 = default(int);
			while (true)
			{
				int num2 = num;
				while (true)
				{
					int num6;
					switch (num2)
					{
					case 249:
						num5 = 57 + 10;
						num6 = 146;
						goto IL_03be;
					case 294:
						array[27] = (byte)num4;
						num2 = 285;
						continue;
					case 142:
						num4 = 221 - 73;
						num = 233;
						break;
					case 77:
						array[7] = 120;
						num6 = 103;
						goto IL_03be;
					case 160:
						array[18] = (byte)num4;
						num2 = 58;
						continue;
					case 96:
						array[22] = (byte)num4;
						num = 360;
						if (true)
						{
							break;
						}
						goto case 133;
					case 315:
						array[23] = (byte)num4;
						num6 = 128;
						goto IL_03be;
					case 311:
						array[13] = (byte)num4;
						num2 = 108;
						continue;
					case 329:
						array2[6] = (byte)num5;
						num6 = 297;
						goto IL_03be;
					case 145:
						array[17] = 154;
						num = 266;
						if (true)
						{
							break;
						}
						goto case 32;
					case 32:
						num4 = 161 - 53;
						num2 = 247;
						continue;
					case 98:
						array2[0] = (byte)num5;
						num2 = 41;
						continue;
					case 261:
						num5 = 197 - 65;
						num = 125;
						if (true)
						{
							break;
						}
						goto case 168;
					case 168:
						num4 = 194 - 64;
						num = 310;
						break;
					case 242:
						array2[4] = 137;
						num = 256;
						if (!AeyaBV4h449xOIC7LQ())
						{
							break;
						}
						goto case 36;
					case 36:
						num4 = 91 + 103;
						num = 46;
						if (0 == 0)
						{
							break;
						}
						goto case 360;
					case 360:
						num4 = 71 + 47;
						num = 315;
						if (true)
						{
							break;
						}
						goto case 297;
					case 297:
						num5 = 34 + 119;
						num6 = 85;
						goto IL_03be;
					case 130:
						num4 = 128 - 101;
						num2 = 70;
						continue;
					case 202:
						num5 = 182 - 60;
						num2 = 337;
						continue;
					case 121:
						array4[9] = array5[4];
						num = 326;
						if (!AeyaBV4h449xOIC7LQ())
						{
							break;
						}
						goto case 91;
					case 91:
						array2 = new byte[16];
						num2 = 301;
						continue;
					case 195:
						num4 = 233 - 77;
						num2 = 150;
						continue;
					case 348:
						array2[10] = (byte)num5;
						num2 = 61;
						continue;
					case 318:
						array[29] = (byte)num4;
						num = 309;
						break;
					case 20:
						num5 = 96 + 33;
						num = 8;
						if (true)
						{
							break;
						}
						goto case 62;
					case 62:
						array2[2] = 231;
						num = 273;
						if (0 == 0)
						{
							break;
						}
						goto case 143;
					case 143:
						num5 = 151 - 50;
						num = 350;
						break;
					case 292:
						array4[3] = array5[1];
						num = 268;
						if (!AeyaBV4h449xOIC7LQ())
						{
							break;
						}
						goto case 68;
					case 68:
						num5 = 183 + 39;
						num = 209;
						break;
					case 179:
						array[31] = 221;
						num6 = 138;
						goto IL_03be;
					case 89:
						array[20] = 160;
						num2 = 188;
						continue;
					case 285:
						num4 = 113 + 101;
						goto case 80;
					default:
						num6 = 80;
						goto IL_03be;
					case 194:
						num4 = 139 - 15;
						num6 = 153;
						goto IL_03be;
					case 124:
						array[28] = (byte)num4;
						num2 = 335;
						continue;
					case 324:
						num4 = 122 + 111;
						num = 94;
						break;
					case 177:
						array[5] = 48;
						num6 = 353;
						goto IL_03be;
					case 37:
						array[4] = (byte)num4;
						num2 = 30;
						continue;
					case 171:
						array[14] = 127;
						num = 194;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 127;
					case 127:
						array[16] = 109;
						num2 = 157;
						continue;
					case 346:
						array[18] = (byte)num4;
						num6 = 220;
						goto IL_03be;
					case 333:
						array[16] = 145;
						num = 237;
						break;
					case 241:
						array[5] = 125;
						num = 177;
						if (!AeyaBV4h449xOIC7LQ())
						{
							break;
						}
						goto case 260;
					case 260:
						array[30] = (byte)num4;
						num = 265;
						if (true)
						{
							break;
						}
						goto case 95;
					case 95:
						num4 = 134 - 108;
						num6 = 291;
						goto IL_03be;
					case 136:
						array2[15] = (byte)num5;
						num6 = 182;
						goto IL_03be;
					case 282:
						num5 = 187 - 62;
						num = 341;
						break;
					case 43:
						array2[14] = (byte)num5;
						num = 104;
						if (!AeyaBV4h449xOIC7LQ())
						{
							break;
						}
						goto case 323;
					case 323:
						array2[7] = 121;
						num6 = 33;
						goto IL_03be;
					case 313:
						array[25] = (byte)num4;
						num2 = 155;
						continue;
					case 21:
						array[0] = 138;
						num6 = 99;
						goto IL_03be;
					case 189:
						array[17] = 161;
						num = 145;
						break;
					case 182:
						num5 = 164 - 54;
						num2 = 16;
						continue;
					case 308:
						num5 = 15 + 92;
						num6 = 43;
						goto IL_03be;
					case 94:
						array[9] = (byte)num4;
						num = 224;
						break;
					case 192:
						array[17] = (byte)num4;
						num = 189;
						break;
					case 225:
						binaryReader = new BinaryReader((Stream)cWLusJFCpErU59U9Qy(rX53WqDaAqMTPpAWqC(typeof(IDT5L2gGT4LqxN5AMo).TypeHandle).Assembly, "Rp8CSLtAP9GrGZBEBh.lRkSaohNKYuO7bZmh9"));
						num2 = 205;
						continue;
					case 204:
						num4 = 233 - 77;
						num = 279;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 114;
					case 5:
						num5 = 91 + 61;
						num = 289;
						if (0 == 0)
						{
							break;
						}
						goto case 193;
					case 193:
						array[7] = (byte)num4;
						num2 = 278;
						continue;
					case 283:
						array[5] = (byte)num4;
						num = 241;
						break;
					case 341:
						array2[1] = (byte)num5;
						num = 181;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 188;
					case 188:
						num4 = 90 - 40;
						num2 = 93;
						continue;
					case 0:
						array2[3] = (byte)num5;
						num6 = 199;
						goto IL_03be;
					case 48:
						array[2] = (byte)num4;
						num = 66;
						break;
					case 310:
						array[7] = (byte)num4;
						num = 3;
						break;
					case 339:
						array2[15] = 108;
						num6 = 54;
						goto IL_03be;
					case 50:
					case 60:
						num4 = 166 - 55;
						num = 214;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 323;
					case 116:
						num4 = 95 + 10;
						num2 = 317;
						continue;
					case 252:
						array4[1] = array5[0];
						num6 = 292;
						goto IL_03be;
					case 53:
						array[30] = (byte)num4;
						num = 162;
						if (!AeyaBV4h449xOIC7LQ())
						{
							break;
						}
						goto case 198;
					case 198:
						array[18] = 156;
						num = 6;
						break;
					case 262:
						array[13] = 65;
						num2 = 235;
						continue;
					case 328:
						num4 = 128 + 80;
						num = 287;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 223;
					case 16:
						array2[15] = (byte)num5;
						num = 339;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 221;
					case 303:
						num5 = 145 + 27;
						num = 106;
						break;
					case 244:
						array[12] = 175;
						num6 = 201;
						goto IL_03be;
					case 296:
						array[23] = (byte)num4;
						num = 175;
						break;
					case 259:
						array2[11] = (byte)num5;
						num6 = 361;
						goto IL_03be;
					case 226:
						num4 = 61 + 85;
						num2 = 107;
						continue;
					case 103:
						num4 = 158 - 52;
						num6 = 158;
						goto IL_03be;
					case 67:
						array2[14] = 159;
						num = 303;
						break;
					case 123:
						array[15] = 138;
						num6 = 284;
						goto IL_03be;
					case 248:
						num5 = 42 + 42;
						num2 = 12;
						continue;
					case 206:
						array[2] = 173;
						num = 299;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 19;
					case 19:
						num4 = 123 - 50;
						num6 = 311;
						goto IL_03be;
					case 349:
						array4[7] = array5[3];
						num6 = 121;
						goto IL_03be;
					case 162:
						array[31] = 144;
						num = 167;
						if (true)
						{
							break;
						}
						goto case 266;
					case 266:
						num4 = 113 + 6;
						num2 = 144;
						continue;
					case 110:
						transform = (ICryptoTransform)XV9xFtu1jYUBQlaGCy(rijndaelManaged, array6, array4);
						num6 = 133;
						goto IL_03be;
					case 231:
						num4 = 34 - 23;
						num6 = 296;
						goto IL_03be;
					case 84:
						num5 = 68 + 5;
						num2 = 286;
						continue;
					case 361:
						num5 = 69 + 106;
						num = 139;
						break;
					case 301:
						num5 = 146 - 48;
						num = 98;
						if (true)
						{
							break;
						}
						goto case 299;
					case 299:
						array[2] = 1;
						num2 = 18;
						continue;
					case 211:
						array2[3] = 126;
						num = 51;
						if (!AeyaBV4h449xOIC7LQ())
						{
							break;
						}
						goto case 167;
					case 167:
						array[31] = 115;
						num6 = 179;
						goto IL_03be;
					case 210:
						array[21] = 168;
						num6 = 134;
						goto IL_03be;
					case 85:
						array2[6] = (byte)num5;
						num2 = 236;
						continue;
					case 222:
						array[15] = 142;
						num6 = 123;
						goto IL_03be;
					case 41:
						array2[0] = 160;
						num = 200;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 257;
					case 78:
						num5 = 10 + 7;
						num6 = 40;
						goto IL_03be;
					case 273:
						array2[2] = 246;
						num6 = 249;
						goto IL_03be;
					case 12:
						array2[15] = (byte)num5;
						num = 345;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 254;
					case 284:
						array[15] = 78;
						num = 258;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 158;
					case 158:
						array[8] = (byte)num4;
						OwI9G5p5M435BjvSaY();
						if (!AeyaBV4h449xOIC7LQ())
						{
							num2 = 50;
							continue;
						}
						num = 97;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 224;
					case 3:
						array[7] = 122;
						num = 77;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 125;
					case 166:
						array2[6] = (byte)num5;
						num = 232;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 272;
					case 272:
						num5 = 7 + 38;
						num2 = 28;
						continue;
					case 342:
						cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
						num6 = 336;
						goto IL_03be;
					case 66:
						num4 = 27 + 101;
						num6 = 92;
						goto IL_03be;
					case 314:
						Yca7smlbFltn8SFZCw(memoryStream);
						num6 = 253;
						goto IL_03be;
					case 300:
						array[4] = (byte)num4;
						num = 15;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 337;
					case 337:
						array2[12] = (byte)num5;
						num = 212;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 122;
					case 122:
						num4 = 13 + 0;
						num = 352;
						break;
					case 128:
						array[23] = 111;
						num6 = 231;
						goto IL_03be;
					case 38:
						num4 = 158 - 119;
						num = 96;
						if (0 == 0)
						{
							break;
						}
						goto case 44;
					case 44:
						num4 = 19 + 76;
						num6 = 318;
						goto IL_03be;
					case 34:
						array[24] = (byte)num4;
						num = 170;
						break;
					case 338:
						array[13] = (byte)num4;
						num = 262;
						break;
					case 175:
						array[24] = 128;
						num = 63;
						break;
					case 180:
						num4 = 182 - 75;
						num6 = 230;
						goto IL_03be;
					case 164:
						num5 = 1 + 15;
						num2 = 234;
						continue;
					case 304:
						num5 = 15 + 63;
						num2 = 228;
						continue;
					case 344:
						num5 = 64 + 32;
						num6 = 354;
						goto IL_03be;
					case 45:
						num4 = 41 - 16;
						num6 = 184;
						goto IL_03be;
					case 153:
						array[14] = (byte)num4;
						num = 222;
						if (0 == 0)
						{
							break;
						}
						goto case 331;
					case 331:
						array[30] = (byte)num4;
						num2 = 351;
						continue;
					case 234:
						array2[8] = (byte)num5;
						num6 = 243;
						goto IL_03be;
					case 13:
						array[26] = (byte)num4;
						num = 340;
						break;
					case 317:
						array[9] = (byte)num4;
						num6 = 257;
						goto IL_03be;
					case 265:
						array[30] = 149;
						num2 = 254;
						continue;
					case 302:
						num5 = 43 + 32;
						num2 = 111;
						continue;
					case 291:
						array[11] = (byte)num4;
						num6 = 102;
						goto IL_03be;
					case 321:
						array[1] = 226;
						num = 31;
						if (!AeyaBV4h449xOIC7LQ())
						{
							break;
						}
						goto case 201;
					case 201:
						num4 = 84 + 97;
						num6 = 105;
						goto IL_03be;
					case 18:
						num4 = 41 + 62;
						num = 39;
						if (!AeyaBV4h449xOIC7LQ())
						{
							break;
						}
						goto case 280;
					case 230:
						array[3] = (byte)num4;
						num = 197;
						if (!AeyaBV4h449xOIC7LQ())
						{
							break;
						}
						goto case 184;
					case 184:
						array[8] = (byte)num4;
						num6 = 263;
						goto IL_03be;
					case 271:
						num4 = 190 - 80;
						num6 = 57;
						goto IL_03be;
					case 4:
						array2[13] = 128;
						num = 147;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 40;
					case 40:
						array2[8] = (byte)num5;
						num2 = 164;
						continue;
					case 33:
						num5 = 103 + 67;
						num6 = 114;
						goto IL_03be;
					case 151:
						num4 = 141 - 47;
						num6 = 73;
						goto IL_03be;
					case 306:
						num4 = 15 + 12;
						num6 = 269;
						goto IL_03be;
					case 29:
						num4 = 140 + 38;
						num = 270;
						break;
					case 1:
						array2[1] = (byte)num5;
						num6 = 174;
						goto IL_03be;
					case 157:
						array[16] = 169;
						num6 = 333;
						goto IL_03be;
					case 305:
						num4 = 72 + 59;
						num = 124;
						if (!AeyaBV4h449xOIC7LQ())
						{
							break;
						}
						goto case 312;
					case 322:
						array[19] = (byte)num4;
						num2 = 306;
						continue;
					case 327:
						array[2] = 162;
						num = 206;
						if (true)
						{
							break;
						}
						goto case 247;
					case 247:
						array[29] = (byte)num4;
						num = 44;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 94;
					case 286:
						array2[9] = (byte)num5;
						num2 = 119;
						continue;
					case 356:
						array3 = (byte[])cvFC1e57j9QcRPBR5l(binaryReader, (int)lvrHWPiv73klwsCs4n(TdPH43Zn7kjMiXJl8x(binaryReader)));
						num6 = 276;
						goto IL_03be;
					case 187:
						array[10] = 152;
						num = 358;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 24;
					case 24:
						array[14] = (byte)num4;
						num2 = 140;
						continue;
					case 267:
						array[1] = 125;
						num6 = 113;
						goto IL_03be;
					case 149:
						array[9] = 156;
						num6 = 116;
						goto IL_03be;
					case 69:
						num5 = 5 + 85;
						num2 = 191;
						continue;
					case 208:
						array2[15] = 118;
						num = 248;
						if (true)
						{
							break;
						}
						goto case 351;
					case 351:
						num4 = 152 - 50;
						num = 217;
						break;
					case 81:
						num5 = 181 - 60;
						num6 = 47;
						goto IL_03be;
					case 170:
						array[25] = 139;
						num = 117;
						break;
					case 154:
						array2[14] = (byte)num5;
						num2 = 245;
						continue;
					case 238:
						num5 = 205 - 68;
						num6 = 275;
						goto IL_03be;
					case 138:
						num4 = 14 + 31;
						num = 334;
						if (0 == 0)
						{
							break;
						}
						goto case 86;
					case 86:
						array2[7] = 122;
						num6 = 302;
						goto IL_03be;
					case 350:
						array2[4] = (byte)num5;
						num = 242;
						break;
					case 25:
						array[28] = 121;
						num = 305;
						if (true)
						{
							break;
						}
						goto case 115;
					case 115:
						array[6] = 175;
						num6 = 328;
						goto IL_03be;
					case 307:
						array[26] = 223;
						num = 90;
						if (!AeyaBV4h449xOIC7LQ())
						{
							break;
						}
						goto case 295;
					case 295:
						num4 = 124 - 120;
						num2 = 34;
						continue;
					case 332:
						array[31] = 93;
						num = 9;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 150;
					case 147:
						num5 = 101 - 41;
						num = 264;
						break;
					case 105:
						array[12] = (byte)num4;
						num6 = 255;
						goto IL_03be;
					case 352:
						array[22] = (byte)num4;
						num6 = 11;
						goto IL_03be;
					case 54:
						array4 = array2;
						num6 = 343;
						goto IL_03be;
					case 277:
						num5 = 185 - 61;
						num = 348;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 273;
					case 114:
						array2[8] = (byte)num5;
						num6 = 344;
						goto IL_03be;
					case 132:
						array[19] = 100;
						num2 = 2;
						continue;
					case 250:
						num4 = 206 - 68;
						num2 = 26;
						continue;
					case 274:
						array[31] = (byte)num4;
						num = 219;
						break;
					case 159:
						r70nrsyP5qPtuhbscc(cryptoStream);
						num6 = 118;
						goto IL_03be;
					case 312:
						num4 = 159 - 53;
						num = 239;
						if (!AeyaBV4h449xOIC7LQ())
						{
							break;
						}
						goto case 309;
					case 309:
						array[29] = 130;
						num = 56;
						break;
					case 190:
						num5 = 166 - 55;
						num6 = 169;
						goto IL_03be;
					case 229:
						array[21] = 142;
						num6 = 280;
						goto IL_03be;
					case 10:
						num4 = 38 + 40;
						num2 = 27;
						continue;
					case 263:
						num4 = 158 - 52;
						num = 72;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 272;
					case 155:
						array[25] = 165;
						num6 = 204;
						goto IL_03be;
					case 174:
						array2[1] = 123;
						num2 = 148;
						continue;
					case 7:
						array2[11] = 42;
						num2 = 126;
						continue;
					case 221:
						array[29] = 108;
						num2 = 29;
						continue;
					case 111:
						array2[7] = (byte)num5;
						num2 = 190;
						continue;
					case 281:
						num4 = 184 - 61;
						num = 193;
						break;
					case 56:
						array[29] = 184;
						num = 221;
						if (true)
						{
							break;
						}
						goto case 205;
					case 205:
						R2siRKbedWu1d0KrEq(TdPH43Zn7kjMiXJl8x(binaryReader), 0L);
						num = 357;
						break;
					case 131:
						array2[12] = 150;
						num6 = 203;
						goto IL_03be;
					case 135:
						array[11] = 124;
						num2 = 161;
						continue;
					case 173:
						array[24] = 85;
						num = 295;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 155;
					case 80:
						array[27] = (byte)num4;
						num6 = 142;
						goto IL_03be;
					case 106:
						array2[14] = (byte)num5;
						num = 109;
						break;
					case 31:
						array[1] = 141;
						num6 = 65;
						goto IL_03be;
					case 289:
						array2[9] = (byte)num5;
						num2 = 298;
						continue;
					case 125:
						array2[1] = (byte)num5;
						num2 = 68;
						continue;
					case 30:
						num4 = 208 - 69;
						num6 = 283;
						goto IL_03be;
					case 228:
						array2[5] = (byte)num5;
						num2 = 272;
						continue;
					case 176:
						array[0] = 148;
						num = 21;
						if (true)
						{
							break;
						}
						goto case 197;
					case 197:
						num4 = 131 - 43;
						num6 = 300;
						goto IL_03be;
					case 270:
						array[29] = (byte)num4;
						num2 = 288;
						continue;
					case 70:
						array[16] = (byte)num4;
						num6 = 227;
						goto IL_03be;
					case 82:
						array2[5] = (byte)num5;
						num6 = 215;
						goto IL_03be;
					case 325:
						array2[2] = 110;
						num = 251;
						if (0 == 0)
						{
							break;
						}
						goto case 199;
					case 199:
						num5 = 203 - 67;
						num6 = 347;
						goto IL_03be;
					case 240:
						num4 = 111 - 87;
						num2 = 37;
						continue;
					case 236:
						num5 = 153 - 35;
						num = 166;
						break;
					case 216:
						num5 = 93 + 30;
						num = 259;
						break;
					case 354:
						array2[8] = (byte)num5;
						num2 = 49;
						continue;
					case 255:
						num4 = 219 - 73;
						num2 = 338;
						continue;
					case 52:
						tVuscj2PQ6EkjhChR8(binaryReader);
						num6 = 185;
						goto IL_03be;
					case 119:
						array2[9] = 149;
						num = 5;
						if (true)
						{
							break;
						}
						goto case 42;
					case 42:
						num4 = 230 - 76;
						num = 192;
						if (AeyaBV4h449xOIC7LQ())
						{
							goto case 133;
						}
						break;
					case 72:
						array[9] = (byte)num4;
						num = 149;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 268;
					case 209:
						array2[1] = (byte)num5;
						num = 325;
						break;
					case 140:
						array[14] = 128;
						num = 171;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 294;
					case 203:
						num5 = 212 - 70;
						num = 359;
						break;
					case 14:
						if (array5.Length <= 0)
						{
							goto case 246;
						}
						num2 = 252;
						continue;
					case 100:
						array[18] = 171;
						num6 = 213;
						goto IL_03be;
					case 330:
						num5 = 4 + 57;
						num6 = 329;
						goto IL_03be;
					case 150:
						array[6] = (byte)num4;
						num2 = 10;
						continue;
					case 320:
						array[4] = (byte)num4;
						num6 = 240;
						goto IL_03be;
					case 268:
						array4[5] = array5[2];
						num = 349;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 53;
					case 245:
						num5 = 237 - 79;
						num = 186;
						break;
					case 117:
						num4 = 99 + 41;
						num6 = 313;
						goto IL_03be;
					case 97:
					case 152:
						array[22] = (byte)num4;
						num6 = 122;
						goto IL_03be;
					case 161:
						array[11] = 69;
						num = 95;
						if (true)
						{
							break;
						}
						goto case 288;
					case 288:
						num4 = 38 + 99;
						num = 260;
						if (true)
						{
							break;
						}
						goto case 358;
					case 358:
						array[10] = 205;
						num6 = 74;
						goto IL_03be;
					case 47:
						array2[10] = (byte)num5;
						num = 277;
						if (true)
						{
							break;
						}
						goto case 355;
					case 355:
						array[11] = 121;
						num6 = 135;
						goto IL_03be;
					case 215:
						array2[5] = 43;
						num = 238;
						if (0 == 0)
						{
							break;
						}
						goto case 46;
					case 46:
						array[8] = (byte)num4;
						num2 = 45;
						continue;
					case 93:
						array[20] = (byte)num4;
						num = 79;
						break;
					case 146:
						array2[3] = (byte)num5;
						num = 211;
						break;
					case 232:
						array2[7] = 130;
						num = 86;
						if (0 == 0)
						{
							break;
						}
						goto case 212;
					case 212:
						array2[12] = 165;
						num = 131;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 15;
					case 15:
						array[4] = 120;
						num6 = 293;
						goto IL_03be;
					case 63:
						array[24] = 136;
						num6 = 173;
						goto IL_03be;
					case 276:
						array = new byte[32];
						num2 = 87;
						continue;
					case 239:
						array[14] = (byte)num4;
						num = 163;
						if (true)
						{
							break;
						}
						goto case 172;
					case 172:
						array2[0] = 198;
						num2 = 282;
						continue;
					case 343:
						array5 = (byte[])SR7A6vLewE82DLmQ2O(gSZRx07U6KsmDghCex(rX53WqDaAqMTPpAWqC(typeof(IDT5L2gGT4LqxN5AMo).TypeHandle).Assembly));
						num6 = 196;
						goto IL_03be;
					case 219:
						array6 = array;
						num6 = 91;
						goto IL_03be;
					case 196:
						if (array5 == null)
						{
							goto case 246;
						}
						num2 = 14;
						continue;
					case 49:
						array2[8] = 134;
						num2 = 78;
						continue;
					case 8:
						array2[13] = (byte)num5;
						num = 4;
						if (0 == 0)
						{
							break;
						}
						goto case 113;
					case 113:
						array[1] = 49;
						num2 = 321;
						continue;
					case 17:
						array4[13] = array5[6];
						num2 = 76;
						continue;
					case 218:
						array[20] = 101;
						num2 = 89;
						continue;
					case 353:
						array[6] = 94;
						num2 = 195;
						continue;
					case 293:
						num4 = 241 - 80;
						num = 320;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 137;
					case 137:
						rFefkPQyf2grZbxTu6(rijndaelManaged, CipherMode.CBC);
						num = 110;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 178;
					case 290:
						array2[5] = 165;
						num6 = 88;
						goto IL_03be;
					case 61:
						array2[10] = 3;
						num2 = 55;
						continue;
					case 326:
						array4[11] = array5[5];
						num = 17;
						break;
					case 163:
						num4 = 192 - 64;
						num = 24;
						if (0 == 0)
						{
							break;
						}
						goto case 76;
					case 76:
						array4[15] = array5[7];
						num = 246;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 134;
					case 134:
						array[21] = 99;
						num = 229;
						if (0 == 0)
						{
							break;
						}
						goto case 169;
					case 169:
						array2[7] = (byte)num5;
						num2 = 323;
						continue;
					case 335:
						array[28] = 149;
						num6 = 32;
						goto IL_03be;
					case 55:
						array2[11] = 180;
						num6 = 216;
						goto IL_03be;
					case 298:
						array2[9] = 132;
						num = 81;
						if (!AeyaBV4h449xOIC7LQ())
						{
							break;
						}
						goto case 277;
					case 316:
						array2[14] = (byte)num5;
						num = 67;
						if (0 == 0)
						{
							break;
						}
						goto case 214;
					case 214:
						array[8] = (byte)num4;
						num = 36;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 240;
					case 102:
						array[12] = 104;
						num6 = 244;
						goto IL_03be;
					case 336:
						jKG24SUR8VOt0B4M7J(cryptoStream, array3, 0, array3.Length);
						num = 159;
						if (true)
						{
							break;
						}
						goto case 88;
					case 88:
						array2[5] = 207;
						num6 = 304;
						goto IL_03be;
					case 74:
						array[10] = 203;
						num6 = 226;
						goto IL_03be;
					case 191:
						array2[4] = (byte)num5;
						num = 143;
						if (0 == 0)
						{
							break;
						}
						goto case 254;
					case 254:
						num4 = 155 - 51;
						num6 = 331;
						goto IL_03be;
					case 144:
						array[17] = (byte)num4;
						num = 75;
						if (!AeyaBV4h449xOIC7LQ())
						{
							break;
						}
						goto case 280;
					case 280:
						num4 = 219 + 25;
						num6 = 23;
						goto IL_03be;
					case 223:
						array[1] = (byte)num4;
						num6 = 178;
						goto IL_03be;
					case 256:
						array2[4] = 202;
						num2 = 290;
						continue;
					case 269:
						array[19] = (byte)num4;
						num = 183;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 287;
					case 287:
						array[6] = (byte)num4;
						num2 = 281;
						continue;
					case 58:
						num4 = 88 + 87;
						num = 346;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 9;
					case 9:
						num4 = 112 + 53;
						num = 274;
						if (0 == 0)
						{
							break;
						}
						goto case 200;
					case 200:
						num5 = 54 + 48;
						num6 = 71;
						goto IL_03be;
					case 118:
						tmVRY8Y6o = (byte[])IPZZvOrKxVIsao5yyW(memoryStream);
						num = 314;
						if (0 == 0)
						{
							break;
						}
						goto case 319;
					case 319:
						if (tmVRY8Y6o.Length != 0)
						{
							goto case 185;
						}
						num = 225;
						if (!AeyaBV4h449xOIC7LQ())
						{
							break;
						}
						goto case 64;
					case 359:
						array2[13] = (byte)num5;
						num = 20;
						break;
					case 227:
						array[17] = 92;
						num6 = 42;
						goto IL_03be;
					case 57:
						array[27] = (byte)num4;
						num2 = 25;
						continue;
					case 39:
						array[3] = (byte)num4;
						num2 = 250;
						continue;
					case 347:
						array2[4] = (byte)num5;
						num6 = 69;
						goto IL_03be;
					case 181:
						num5 = 163 - 54;
						num = 1;
						if (!AeyaBV4h449xOIC7LQ())
						{
							break;
						}
						goto case 142;
					case 107:
						array[11] = (byte)num4;
						num2 = 355;
						continue;
					case 178:
						num4 = 39 + 85;
						num2 = 48;
						continue;
					case 11:
						array[22] = 79;
						num6 = 38;
						goto IL_03be;
					case 22:
						num5 = 168 - 56;
						num = 154;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 101;
					case 101:
						array[14] = (byte)num4;
						num = 312;
						break;
					case 278:
						num4 = 34 + 119;
						num = 120;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 65;
					case 112:
						array2[8] = (byte)num5;
						num = 362;
						if (!AeyaBV4h449xOIC7LQ())
						{
							break;
						}
						goto case 243;
					case 213:
						num4 = 144 - 48;
						num = 141;
						if (true)
						{
							break;
						}
						goto case 217;
					case 217:
						array[30] = (byte)num4;
						num = 156;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 237;
					case 237:
						array[16] = 122;
						num6 = 130;
						goto IL_03be;
					case 235:
						num4 = 175 - 58;
						num = 59;
						if (true)
						{
							break;
						}
						goto case 26;
					case 26:
						array[3] = (byte)num4;
						num = 180;
						if (0 == 0)
						{
							break;
						}
						goto case 99;
					case 99:
						array[1] = 170;
						num2 = 267;
						continue;
					case 129:
						num4 = 161 - 53;
						num2 = 35;
						continue;
					case 165:
						num4 = 156 - 52;
						goto case 97;
					case 224:
						array[10] = 125;
						num2 = 187;
						continue;
					case 257:
						array[9] = 153;
						num6 = 151;
						goto IL_03be;
					case 220:
						array[18] = 88;
						num2 = 132;
						continue;
					case 264:
						array2[13] = (byte)num5;
						num = 22;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 156;
					case 65:
						num4 = 189 - 69;
						num2 = 223;
						continue;
					case 357:
						JEIBNxnLnLlNkv27dE(true);
						num = 356;
						break;
					case 253:
						Yca7smlbFltn8SFZCw(cryptoStream);
						num = 52;
						break;
					case 185:
						num3 = MSCCqlRCqipLNQwkaJ(tmVRY8Y6o, P_0);
						num = 363;
						break;
					case 75:
						array[17] = 6;
						num = 100;
						break;
					case 92:
						array[2] = (byte)num4;
						num2 = 327;
						continue;
					case 27:
						array[6] = (byte)num4;
						num = 115;
						break;
					case 251:
						array2[2] = 154;
						num = 62;
						if (!AeyaBV4h449xOIC7LQ())
						{
							break;
						}
						goto case 64;
					case 64:
						array2[15] = (byte)num5;
						num = 208;
						if (0 == 0)
						{
							break;
						}
						goto case 73;
					case 73:
						array[9] = (byte)num4;
						num6 = 324;
						goto IL_03be;
					case 35:
						array[7] = (byte)num4;
						num = 168;
						if (!AeyaBV4h449xOIC7LQ())
						{
							break;
						}
						goto case 258;
					case 258:
						array[16] = 85;
						num6 = 127;
						goto IL_03be;
					case 275:
						array2[6] = (byte)num5;
						num2 = 330;
						continue;
					case 2:
						num4 = 83 + 105;
						num = 322;
						break;
					case 79:
						array[21] = 119;
						num = 210;
						break;
					case 334:
						array[31] = (byte)num4;
						num2 = 332;
						continue;
					case 109:
						num5 = 123 + 74;
						num = 64;
						break;
					case 156:
						num4 = 92 - 52;
						num6 = 53;
						goto IL_03be;
					case 104:
						num5 = 156 - 52;
						num2 = 316;
						continue;
					case 279:
						array[26] = (byte)num4;
						num2 = 307;
						continue;
					case 120:
						array[7] = (byte)num4;
						num = 129;
						break;
					case 51:
						num5 = 69 + 78;
						num = 0;
						break;
					case 141:
						array[18] = (byte)num4;
						num = 198;
						break;
					case 6:
						num4 = 115 + 40;
						num = 160;
						if (!AeyaBV4h449xOIC7LQ())
						{
							break;
						}
						goto case 362;
					case 362:
						array2[9] = 140;
						num = 84;
						if (true)
						{
							break;
						}
						goto case 340;
					case 340:
						num4 = 177 - 59;
						num = 294;
						break;
					case 59:
						array[13] = (byte)num4;
						num2 = 19;
						continue;
					case 139:
						array2[11] = (byte)num5;
						num = 7;
						if (true)
						{
							break;
						}
						goto case 207;
					case 207:
						num5 = 228 - 76;
						num2 = 82;
						continue;
					case 345:
						num5 = 182 - 60;
						num = 136;
						break;
					case 126:
						array2[12] = 136;
						num2 = 202;
						continue;
					case 148:
						array2[1] = 97;
						num2 = 261;
						continue;
					case 87:
						array[0] = 99;
						num = 176;
						if (true)
						{
							break;
						}
						goto case 90;
					case 90:
						array[26] = 102;
						num = 83;
						break;
					case 243:
						num5 = 74 + 111;
						num = 112;
						break;
					case 233:
						array[27] = (byte)num4;
						num2 = 271;
						continue;
					case 186:
						array2[14] = (byte)num5;
						num2 = 308;
						continue;
					case 183:
						array[19] = 171;
						num2 = 218;
						continue;
					case 83:
						num4 = 93 - 87;
						num = 13;
						if (OwI9G5p5M435BjvSaY())
						{
							break;
						}
						goto case 23;
					case 23:
						array[21] = (byte)num4;
						num = 165;
						break;
					case 108:
						num4 = 195 - 65;
						num = 101;
						break;
					case 28:
						array2[5] = (byte)num5;
						num = 207;
						if (!AeyaBV4h449xOIC7LQ())
						{
							break;
						}
						goto case 109;
					case 71:
						array2[0] = (byte)num5;
						num6 = 172;
						goto IL_03be;
					case 363:
						try
						{
							return (string)WKArrpEd7ZqTl6O1e0(i8gDOeIkpachhRE6JB(), tmVRY8Y6o, P_0 + 4, num3);
						}
						catch
						{
						}
						return "";
					case 133:
						memoryStream = new MemoryStream();
						num6 = 342;
						goto IL_03be;
					case 246:
						{
							rijndaelManaged = new RijndaelManaged();
							num = 137;
							if (0 == 0)
							{
								break;
							}
							goto case 159;
						}
						IL_03be:
						num = num6;
						break;
					}
					break;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[Mf3UrmESbsW5fOWrC4(typeof(IDT5L2gGT4LqxN5AMo/Mf3UrmESbsW5fOWrC4/kRHXL45P9Bs0gWeAvJ<object>[]))]
		internal static string v2pOj6rGc(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void P5u37OUE7(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int CZ5gip619(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr jr4ru8dk9(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void xfnE7mpOq()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void Qv25lUtCO()
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
		internal static object PFBcgXlin(object P_0)
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
		public static extern IntPtr uspI2CSDT(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr hL2UGT4Lq(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int PN5bAMoDS(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int rY5CGKy04(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int aoV9ZRBNM(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr W3U0rmSbs(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int F5fwOWrC4(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[Mf3UrmESbsW5fOWrC4(typeof(IDT5L2gGT4LqxN5AMo/Mf3UrmESbsW5fOWrC4/kRHXL45P9Bs0gWeAvJ<object>[]))]
		private static byte[] kRHhXL4P9(string P_0)
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
		[Mf3UrmESbsW5fOWrC4(typeof(IDT5L2gGT4LqxN5AMo/Mf3UrmESbsW5fOWrC4/kRHXL45P9Bs0gWeAvJ<object>[]))]
		private static byte[] Ks04gWeAv(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				108, 154, 125, 158, 68, 72, 116, 234, 0, 169,
				81, 62, 17, 183, 148, 196, 179, 88, 10, 173,
				49, 199, 234, 17, 182, 117, 189, 235, 41, 209,
				210, 118
			};
			rijndael.IV = new byte[16]
			{
				115, 105, 59, 176, 105, 209, 227, 112, 114, 112,
				240, 142, 83, 199, 243, 151
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] ST6PHPFAG()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] nTxY5cHn5()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] U3fln9O2y()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] gF2oM7gQa()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] Vlsy7xdMi()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] PutNCJtug()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] L6nicaAHO()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] W6OV9Zf7o()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] a6O7yS6Fe()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] YumnJXo8k()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IDT5L2gGT4LqxN5AMo()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type rX53WqDaAqMTPpAWqC(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object cWLusJFCpErU59U9Qy(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object TdPH43Zn7kjMiXJl8x(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void R2siRKbedWu1d0KrEq(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void JEIBNxnLnLlNkv27dE(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long lvrHWPiv73klwsCs4n(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object cvFC1e57j9QcRPBR5l(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object gSZRx07U6KsmDghCex(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object SR7A6vLewE82DLmQ2O(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void rFefkPQyf2grZbxTu6(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object XV9xFtu1jYUBQlaGCy(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void jKG24SUR8VOt0B4M7J(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void r70nrsyP5qPtuhbscc(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object IPZZvOrKxVIsao5yyW(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Yca7smlbFltn8SFZCw(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void tVuscj2PQ6EkjhChR8(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int MSCCqlRCqipLNQwkaJ(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object i8gDOeIkpachhRE6JB()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object WKArrpEd7ZqTl6O1e0(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool OwI9G5p5M435BjvSaY()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool AeyaBV4h449xOIC7LQ()
		{
			return false;
		}
	}
}
namespace tVUokn0jhIoNgRQDkm
{
	internal class gQpMUo9BaRmomVY8Y6
	{
		private static bool nJueLf05G;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void iFpI5mkzQBkBs()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public gQpMUo9BaRmomVY8Y6()
		{
		}
	}
}
