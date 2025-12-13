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
using fXXbNnywvJkJVvYuJc;

[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: Guid("ea550402-030a-4e61-8952-f97ba18d3a64")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyDelaySign(false)]
[assembly: ComVisible(true)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyCompany("Cummins, Inc.")]
[assembly: AssemblyProduct("INSITE")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyTitle("DNL")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace KLFEIT7bxkkwajE7LK
{
	internal static class D0FIfICL2CsRIHveAX
	{
	}
}
namespace Cummins.INSITE.DNL
{
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("Cummins.DNLInitializer.1")]
	[ComVisible(true)]
	[Guid("AAA0B9DE-50D3-4d2b-B793-FBAC0D91B4F6")]
	public class DNLInitializer
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public DNLInitializer()
		{
			Y2rcVxpKuIVkhuGfWv.xEOwMaczYhPPw();
			base..ctor();
		}
	}
}
internal class <Module>{A36666D9-43FA-48AA-B144-2D87D2CD3CF3}
{
}
namespace mZ90D0sZmWCbecEraN
{
	internal class VLxXJE1web6pVcti89
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module CsFX2NLE4;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void uC1wMaccdri0Q(int typemdt)
		{
			Type type = CsFX2NLE4.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)CsFX2NLE4.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public VLxXJE1web6pVcti89()
		{
			Y2rcVxpKuIVkhuGfWv.xEOwMaczYhPPw();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static VLxXJE1web6pVcti89()
		{
			Y2rcVxpKuIVkhuGfWv.xEOwMaczYhPPw();
			CsFX2NLE4 = typeof(VLxXJE1web6pVcti89).Assembly.ManifestModule;
		}
	}
}
namespace eo5jIcPl3RNwiJKq3Z
{
	internal class s2iWBMrDOBbEncFb0a
	{
		internal class Ce3Ia9Ek5kILAOPaaM : Attribute
		{
			internal class d7hs9D8cZx7BUG3yQv<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public d7hs9D8cZx7BUG3yQv()
				{
					Y2rcVxpKuIVkhuGfWv.xEOwMaczYhPPw();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[Ce3Ia9Ek5kILAOPaaM(typeof(s2iWBMrDOBbEncFb0a/Ce3Ia9Ek5kILAOPaaM/d7hs9D8cZx7BUG3yQv<object>[]))]
			public Ce3Ia9Ek5kILAOPaaM(object P_0)
			{
				Y2rcVxpKuIVkhuGfWv.xEOwMaczYhPPw();
				base..ctor();
			}
		}

		internal class xS7V20xlgvEHo2ypDf
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[Ce3Ia9Ek5kILAOPaaM(typeof(s2iWBMrDOBbEncFb0a/Ce3Ia9Ek5kILAOPaaM/d7hs9D8cZx7BUG3yQv<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (XjADEx3J2(Convert.ToBase64String(typeof(s2iWBMrDOBbEncFb0a).Assembly.GetName().GetPublicKeyToken()), s2iWBMrDOBbEncFb0a.koLCW8BQ2(0)) != s2iWBMrDOBbEncFb0a.koLCW8BQ2(6))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[Ce3Ia9Ek5kILAOPaaM(typeof(s2iWBMrDOBbEncFb0a/Ce3Ia9Ek5kILAOPaaM/d7hs9D8cZx7BUG3yQv<object>[]))]
			internal static string XjADEx3J2(string P_0, string P_1)
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
			public xS7V20xlgvEHo2ypDf()
			{
				Y2rcVxpKuIVkhuGfWv.xEOwMaczYhPPw();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint iqpneVii6Xvgtu6d4V([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr OCakvrRiIlpHuNjj1F();

		internal struct G3u9xbTHISw3iIaTg7
		{
			internal bool VVKWU6dG2;

			internal byte[] ReMN7Bx5r;
		}

		[Flags]
		private enum ncGGLm5NMvUnVhtPYN
		{

		}

		private static byte[] ALmmNMvUn;

		private static IntPtr aXbdNnwvJ;

		private static object eokuU729j;

		private static int t6T99udI9;

		private static int AnZwoScfH;

		internal static iqpneVii6Xvgtu6d4V U9XBVQcVg;

		private static long ewSLUPraF;

		private static int wmSgm7lDK;

		private static bool UISnhC3PE;

		internal static iqpneVii6Xvgtu6d4V yvFcPkpLx;

		internal static Hashtable HZDoYcqNy;

		private static byte[] VhtOPYNJ2;

		private static SortedList dPWbyFQqC;

		private static long dmY0T3Nmp;

		private static IntPtr gRxhpgTHq;

		private static IntPtr UJVvvYuJc;

		private static int[] yJBYcDd4j;

		private static bool G71SEmgsr;

		private static byte[] fcVfxKuIV;

		private static int Pfq3xWpSm;

		private static byte[] VhuGGfWvP;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static s2iWBMrDOBbEncFb0a()
		{
			ALmmNMvUn = new byte[0];
			VhtOPYNJ2 = new byte[0];
			fcVfxKuIV = new byte[0];
			VhuGGfWvP = new byte[0];
			aXbdNnwvJ = IntPtr.Zero;
			UJVvvYuJc = IntPtr.Zero;
			eokuU729j = new string[0];
			yJBYcDd4j = new int[0];
			t6T99udI9 = 1;
			G71SEmgsr = false;
			dPWbyFQqC = new SortedList();
			AnZwoScfH = 0;
			dmY0T3Nmp = 0L;
			U9XBVQcVg = null;
			yvFcPkpLx = null;
			ewSLUPraF = 0L;
			wmSgm7lDK = 0;
			UISnhC3PE = false;
			Pfq3xWpSm = 0;
			gRxhpgTHq = IntPtr.Zero;
			HZDoYcqNy = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Q89wMacUsRvCo()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[Ce3Ia9Ek5kILAOPaaM(typeof(s2iWBMrDOBbEncFb0a/Ce3Ia9Ek5kILAOPaaM/d7hs9D8cZx7BUG3yQv<object>[]))]
		static string koLCW8BQ2(int P_0)
		{
			int num = 211;
			byte[] array = default(byte[]);
			int num4 = default(int);
			byte[] array2 = default(byte[]);
			byte[] array3 = default(byte[]);
			byte[] array4 = default(byte[]);
			CryptoStream cryptoStream = default(CryptoStream);
			byte[] array6 = default(byte[]);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			int num6 = default(int);
			int num7 = default(int);
			BinaryReader binaryReader = default(BinaryReader);
			byte[] array5 = default(byte[]);
			MemoryStream memoryStream = default(MemoryStream);
			ICryptoTransform transform = default(ICryptoTransform);
			int num3 = default(int);
			while (true)
			{
				int num2;
				int num5;
				switch (num)
				{
				case 91:
					array[0] = (byte)num4;
					num2 = 231;
					goto IL_060e;
				case 41:
					num4 = 58 - 49;
					num2 = 166;
					if (!e7sUJMN1Av1d6dHRco())
					{
						goto case 269;
					}
					goto IL_060e;
				case 269:
					array2[2] = 166;
					num2 = 298;
					goto IL_060e;
				case 25:
					array[10] = 171;
					num = 297;
					continue;
				case 188:
					num4 = 81 + 95;
					num = 53;
					continue;
				case 331:
					array[14] = (byte)num4;
					num = 80;
					continue;
				case 316:
					num4 = 103 + 90;
					num5 = 342;
					goto IL_060a;
				case 297:
					num4 = 235 - 78;
					num2 = 351;
					if (false)
					{
						goto case 296;
					}
					goto IL_060e;
				case 296:
					num4 = 105 + 120;
					num2 = 85;
					if (false)
					{
						goto case 203;
					}
					goto IL_060e;
				case 203:
					array[2] = 102;
					num = 279;
					continue;
				case 90:
					array[18] = (byte)num4;
					num5 = 284;
					goto IL_060a;
				case 200:
					array3[11] = array4[5];
					num2 = 49;
					goto IL_060e;
				case 219:
					num4 = 136 - 123;
					num = 257;
					continue;
				case 323:
					array[0] = 161;
					num = 223;
					continue;
				case 223:
					num4 = 195 - 65;
					num = 91;
					continue;
				case 228:
					array[20] = 136;
					num2 = 122;
					goto IL_060e;
				case 288:
					pIW6TXaPHFOsCGJN76(cryptoStream, array6, 0, array6.Length);
					num5 = 346;
					goto IL_060a;
				case 146:
					ql0hN4E1FflvdaCBOY(rijndaelManaged, CipherMode.CBC);
					num2 = 55;
					if (!e7sUJMN1Av1d6dHRco())
					{
						goto case 142;
					}
					goto IL_060e;
				case 142:
					array2[11] = (byte)num6;
					num = 179;
					continue;
				case 275:
					num4 = 208 + 18;
					num5 = 310;
					goto IL_060a;
				case 263:
					num4 = 142 - 47;
					num5 = 272;
					goto IL_060a;
				case 177:
					array2[14] = (byte)num6;
					num5 = 101;
					goto IL_060a;
				case 35:
					num4 = 181 - 60;
					num = 271;
					continue;
				case 151:
					num4 = 110 + 30;
					num5 = 86;
					goto IL_060a;
				case 355:
					array[22] = (byte)num4;
					num5 = 18;
					goto IL_060a;
				case 202:
					array[2] = (byte)num4;
					num5 = 319;
					goto IL_060a;
				case 348:
					num4 = 74 + 22;
					num5 = 237;
					goto IL_060a;
				case 92:
					array2[15] = 77;
					num2 = 287;
					goto IL_060e;
				case 236:
					num4 = 53 + 113;
					num2 = 355;
					if (!e7sUJMN1Av1d6dHRco())
					{
						goto case 73;
					}
					goto IL_060e;
				case 73:
					array[26] = 154;
					num5 = 268;
					goto IL_060a;
				case 334:
					num7 = 6 + 94;
					num2 = 96;
					goto IL_060e;
				case 232:
					array[14] = (byte)num4;
					num5 = 348;
					goto IL_060a;
				case 14:
					array3[7] = array4[3];
					num = 172;
					continue;
				case 280:
					array2[10] = (byte)num7;
					num5 = 27;
					goto IL_060a;
				case 147:
					num4 = 112 - 25;
					num2 = 266;
					if (false)
					{
						goto case 354;
					}
					goto IL_060e;
				case 354:
					array[1] = (byte)num4;
					num = 187;
					continue;
				case 290:
					num4 = 26 + 34;
					num2 = 210;
					goto IL_060e;
				case 24:
					array[26] = (byte)num4;
					num5 = 5;
					goto IL_060a;
				case 317:
					num7 = 33 + 66;
					num5 = 314;
					goto IL_060a;
				case 281:
					array2[11] = 159;
					num = 121;
					continue;
				case 199:
					num4 = 250 - 83;
					num2 = 350;
					if (false)
					{
						goto case 338;
					}
					goto IL_060e;
				case 338:
					array2[10] = (byte)num6;
					num = 334;
					continue;
				case 277:
					array6 = (byte[])l99jmLLAwF2Pu27oxd(binaryReader, (int)xqRlSSFHIJLLipDb9H(wFubBF6D4PihCInl4d(binaryReader)));
					num2 = 37;
					if (1 == 0)
					{
						goto case 71;
					}
					goto IL_060e;
				case 71:
					array[25] = (byte)num4;
					num5 = 290;
					goto IL_060a;
				case 112:
					array2[6] = 166;
					num2 = 157;
					goto IL_060e;
				case 72:
					array[18] = (byte)num4;
					num2 = 42;
					if (1 == 0)
					{
						goto case 115;
					}
					goto IL_060e;
				case 115:
					array[13] = 101;
					num2 = 57;
					goto IL_060e;
				case 144:
					array2[10] = 113;
					num5 = 262;
					goto IL_060a;
				case 2:
					array[30] = 12;
					num2 = 188;
					goto IL_060e;
				case 104:
					num4 = 76 + 120;
					num5 = 163;
					goto IL_060a;
				case 87:
					num7 = 157 - 52;
					num2 = 67;
					goto IL_060e;
				case 93:
					num4 = 187 - 103;
					num = 204;
					continue;
				case 266:
					array[3] = (byte)num4;
					num5 = 22;
					goto IL_060a;
				case 153:
					array2[12] = (byte)num7;
					num2 = 317;
					if (1 == 0)
					{
						goto case 329;
					}
					goto IL_060e;
				case 329:
					array[25] = 249;
					goto case 312;
				default:
					num2 = 312;
					if (true)
					{
						goto IL_060e;
					}
					goto case 140;
				case 140:
					array[1] = 147;
					num5 = 194;
					goto IL_060a;
				case 213:
					num4 = 167 - 55;
					num2 = 273;
					if (nm2grPYDKQi2IdGxI5())
					{
						goto case 219;
					}
					goto IL_060e;
				case 201:
					array[6] = 65;
					num2 = 13;
					goto IL_060e;
				case 4:
					num7 = 140 - 46;
					num2 = 229;
					if (e7sUJMN1Av1d6dHRco())
					{
						goto IL_060e;
					}
					goto case 154;
				case 318:
					lGPrh98bjQLLOnZm9H(binaryReader);
					num = 222;
					continue;
				case 1:
					num4 = 194 - 64;
					num2 = 181;
					if (e7sUJMN1Av1d6dHRco())
					{
						goto IL_060e;
					}
					goto case 140;
				case 160:
					array2[12] = (byte)num7;
					num5 = 132;
					goto IL_060a;
				case 270:
					array[30] = 66;
					num = 2;
					continue;
				case 314:
					array2[12] = (byte)num7;
					num = 283;
					continue;
				case 293:
					array[0] = (byte)num4;
					num = 88;
					continue;
				case 120:
					num4 = 181 - 60;
					num2 = 72;
					goto IL_060e;
				case 137:
					array[19] = (byte)num4;
					num2 = 151;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 10;
				case 10:
					num4 = 177 - 59;
					num = 330;
					continue;
				case 349:
					array2[7] = 154;
					num = 321;
					continue;
				case 5:
					array[26] = 84;
					num = 73;
					continue;
				case 324:
					num4 = 210 - 70;
					num5 = 40;
					goto IL_060a;
				case 253:
					array[6] = 143;
					num2 = 201;
					if (nm2grPYDKQi2IdGxI5())
					{
						break;
					}
					goto IL_060e;
				case 210:
					array[25] = (byte)num4;
					num2 = 294;
					if (true)
					{
						goto IL_060e;
					}
					goto case 103;
				case 103:
					array[18] = (byte)num4;
					num2 = 120;
					if (e7sUJMN1Av1d6dHRco())
					{
						goto IL_060e;
					}
					goto case 309;
				case 309:
					array[8] = (byte)num4;
					num2 = 19;
					if (!nm2grPYDKQi2IdGxI5())
					{
						goto IL_060e;
					}
					goto case 130;
				case 130:
					num4 = 227 - 75;
					num2 = 202;
					goto IL_060e;
				case 301:
					array2[9] = (byte)num6;
					num = 299;
					continue;
				case 220:
					array2[11] = 162;
					num = 327;
					continue;
				case 19:
					num4 = 32 + 19;
					num = 322;
					continue;
				case 173:
					array[23] = 160;
					num5 = 212;
					goto IL_060a;
				case 197:
					array[12] = 186;
					num = 119;
					continue;
				case 21:
					array[10] = (byte)num4;
					num5 = 255;
					goto IL_060a;
				case 279:
					num4 = 190 - 95;
					num2 = 139;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 311;
				case 311:
					array[15] = 142;
					num = 8;
					continue;
				case 48:
					array[14] = 69;
					num5 = 311;
					goto IL_060a;
				case 113:
					array[7] = (byte)num4;
					num2 = 23;
					if (!nm2grPYDKQi2IdGxI5())
					{
						goto IL_060e;
					}
					goto case 222;
				case 346:
					OjU9OsCj9DtWmQNWhY(cryptoStream);
					num5 = 206;
					goto IL_060a;
				case 182:
					array2[14] = 36;
					num2 = 47;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 234;
				case 234:
					array[7] = (byte)num4;
					num = 340;
					continue;
				case 22:
					num4 = 46 + 20;
					num2 = 282;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 319;
				case 319:
					array[2] = 159;
					num = 324;
					continue;
				case 237:
					array[14] = (byte)num4;
					num2 = 48;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 75;
				case 75:
					array2[0] = (byte)num7;
					num2 = 335;
					if (!nm2grPYDKQi2IdGxI5())
					{
						goto IL_060e;
					}
					goto case 230;
				case 230:
					num6 = 109 + 121;
					num2 = 320;
					if (e7sUJMN1Av1d6dHRco())
					{
						goto IL_060e;
					}
					goto case 83;
				case 83:
					array[5] = (byte)num4;
					num = 0;
					continue;
				case 320:
					array2[1] = (byte)num6;
					num2 = 118;
					if (e7sUJMN1Av1d6dHRco())
					{
						goto IL_060e;
					}
					goto case 141;
				case 186:
					array2[1] = 0;
					num2 = 303;
					goto IL_060e;
				case 18:
					array[22] = 100;
					num5 = 159;
					goto IL_060a;
				case 0:
					array[5] = 180;
					num = 253;
					continue;
				case 176:
					array[11] = (byte)num4;
					num2 = 76;
					goto IL_060e;
				case 141:
					num4 = 245 - 81;
					num = 353;
					continue;
				case 306:
					num6 = 88 + 85;
					num2 = 154;
					goto IL_060e;
				case 241:
					array2[5] = 7;
					num5 = 82;
					goto IL_060a;
				case 80:
					num4 = 96 + 48;
					num5 = 313;
					goto IL_060a;
				case 335:
					array2[0] = 134;
					num5 = 87;
					goto IL_060a;
				case 108:
					array[21] = 196;
					num2 = 9;
					if (!nm2grPYDKQi2IdGxI5())
					{
						goto IL_060e;
					}
					goto case 207;
				case 172:
					array3[9] = array4[4];
					num5 = 200;
					goto IL_060a;
				case 126:
					array[29] = (byte)num4;
					num2 = 39;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 86;
				case 86:
					array[19] = (byte)num4;
					num = 213;
					continue;
				case 56:
					array[8] = (byte)num4;
					num2 = 224;
					goto IL_060e;
				case 255:
					num4 = 222 - 74;
					num = 6;
					continue;
				case 214:
					array[11] = 177;
					num5 = 344;
					goto IL_060a;
				case 33:
					array[3] = 96;
					num5 = 147;
					goto IL_060a;
				case 189:
					array[16] = (byte)num4;
					num = 158;
					continue;
				case 198:
					array[18] = (byte)num4;
					num2 = 259;
					if (e7sUJMN1Av1d6dHRco())
					{
						goto IL_060e;
					}
					goto case 226;
				case 226:
					num4 = 100 - 72;
					num = 3;
					continue;
				case 50:
					array2[4] = (byte)num7;
					num5 = 208;
					goto IL_060a;
				case 251:
					num7 = 56 + 96;
					num2 = 180;
					if (true)
					{
						goto IL_060e;
					}
					goto case 3;
				case 3:
					array[13] = (byte)num4;
					num5 = 249;
					goto IL_060a;
				case 333:
					array2[7] = (byte)num6;
					num5 = 349;
					goto IL_060a;
				case 252:
					num6 = 191 - 63;
					num = 127;
					continue;
				case 27:
					array2[10] = 112;
					num2 = 144;
					goto IL_060e;
				case 215:
					array[29] = 143;
					num5 = 60;
					goto IL_060a;
				case 138:
					array2[3] = 49;
					num2 = 69;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 258;
				case 258:
					array[27] = (byte)num4;
					num5 = 70;
					goto IL_060a;
				case 216:
					array5 = array;
					num2 = 302;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 122;
				case 122:
					array[20] = 252;
					num = 221;
					continue;
				case 295:
					array2[1] = (byte)num7;
					num2 = 186;
					if (e7sUJMN1Av1d6dHRco())
					{
						goto IL_060e;
					}
					goto case 216;
				case 98:
					num4 = 31 + 74;
					num2 = 189;
					goto IL_060e;
				case 345:
					num7 = 174 - 58;
					num = 135;
					continue;
				case 94:
					num6 = 126 - 42;
					num5 = 338;
					goto IL_060a;
				case 239:
					array[13] = (byte)num4;
					num = 115;
					continue;
				case 342:
					array[15] = (byte)num4;
					num2 = 207;
					if (true)
					{
						goto IL_060e;
					}
					goto case 307;
				case 307:
					num4 = 184 - 61;
					num2 = 258;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 233;
				case 233:
					array3[15] = array4[7];
					num = 46;
					continue;
				case 11:
					num4 = 57 - 23;
					num = 81;
					continue;
				case 34:
					array2[3] = 88;
					num2 = 116;
					if (!nm2grPYDKQi2IdGxI5())
					{
						goto IL_060e;
					}
					goto case 163;
				case 163:
					array[8] = (byte)num4;
					num2 = 164;
					if (true)
					{
						goto IL_060e;
					}
					goto case 164;
				case 164:
					num4 = 241 - 80;
					num2 = 309;
					if (true)
					{
						goto IL_060e;
					}
					goto case 29;
				case 29:
					num4 = 50 + 83;
					num = 84;
					continue;
				case 267:
					array2[7] = (byte)num6;
					num = 4;
					continue;
				case 78:
					num6 = 140 - 123;
					num = 61;
					continue;
				case 77:
					array2[2] = 223;
					num2 = 62;
					goto IL_060e;
				case 218:
					array2[1] = (byte)num7;
					num5 = 339;
					goto IL_060a;
				case 155:
					array[9] = (byte)num4;
					num = 219;
					continue;
				case 171:
					num4 = 129 - 63;
					num = 110;
					continue;
				case 206:
					fcVfxKuIV = (byte[])jPmAr24doPdGdLw8X4(memoryStream);
					num5 = 356;
					goto IL_060a;
				case 175:
					array[29] = (byte)num4;
					num5 = 141;
					goto IL_060a;
				case 310:
					array[28] = (byte)num4;
					num5 = 215;
					goto IL_060a;
				case 321:
					num6 = 192 - 64;
					num5 = 267;
					goto IL_060a;
				case 159:
					num4 = 17 + 57;
					num2 = 106;
					if (true)
					{
						goto IL_060e;
					}
					goto case 328;
				case 328:
					array[28] = 114;
					num5 = 134;
					goto IL_060a;
				case 260:
					array[25] = (byte)num4;
					num2 = 329;
					goto IL_060e;
				case 273:
					array[19] = (byte)num4;
					num2 = 278;
					goto IL_060e;
				case 105:
					array[21] = 112;
					num5 = 108;
					goto IL_060a;
				case 298:
					num6 = 225 - 75;
					num5 = 192;
					goto IL_060a;
				case 28:
					array[12] = 49;
					num = 123;
					continue;
				case 283:
					num7 = 149 - 103;
					num2 = 160;
					goto IL_060e;
				case 286:
					num7 = 243 - 81;
					num2 = 153;
					if (!nm2grPYDKQi2IdGxI5())
					{
						goto IL_060e;
					}
					goto case 248;
				case 107:
					array2[3] = (byte)num6;
					num2 = 30;
					goto IL_060e;
				case 227:
					array[16] = 242;
					num2 = 263;
					goto IL_060e;
				case 38:
					array[11] = 154;
					num = 214;
					continue;
				case 184:
					num4 = 142 - 46;
					num = 109;
					continue;
				case 268:
					array[27] = 130;
					num2 = 307;
					if (e7sUJMN1Av1d6dHRco())
					{
						goto IL_060e;
					}
					goto case 118;
				case 195:
					cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
					num2 = 288;
					goto IL_060e;
				case 358:
					array[26] = 120;
					num2 = 326;
					goto IL_060e;
				case 168:
					num4 = 151 - 50;
					num = 113;
					continue;
				case 55:
					transform = (ICryptoTransform)ww8ma0ZBFbEkoG7RAj(rijndaelManaged, array5, array3);
					num2 = 336;
					goto IL_060e;
				case 166:
					array[17] = (byte)num4;
					num2 = 352;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 325;
				case 325:
					num4 = 116 + 17;
					num2 = 265;
					goto IL_060e;
				case 133:
					num4 = 147 - 49;
					num = 274;
					continue;
				case 211:
					if (fcVfxKuIV.Length == 0)
					{
						num = 357;
						continue;
					}
					goto case 222;
				case 74:
					array2[15] = 135;
					num2 = 92;
					if (e7sUJMN1Av1d6dHRco())
					{
						goto IL_060e;
					}
					goto case 229;
				case 123:
					num4 = 172 - 57;
					num2 = 239;
					goto IL_060e;
				case 16:
					array[31] = 157;
					num2 = 246;
					goto IL_060e;
				case 247:
					array[15] = (byte)num4;
					num = 98;
					continue;
				case 308:
					num7 = 46 + 14;
					num5 = 50;
					goto IL_060a;
				case 114:
					array3[3] = array4[1];
					num2 = 7;
					if (e7sUJMN1Av1d6dHRco())
					{
						goto IL_060e;
					}
					goto case 190;
				case 190:
					num4 = 144 - 48;
					num5 = 155;
					goto IL_060a;
				case 312:
					array[26] = 157;
					num2 = 358;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 235;
				case 235:
					num7 = 117 + 60;
					num5 = 75;
					goto IL_060a;
				case 99:
					array[12] = (byte)num4;
					num2 = 28;
					if (e7sUJMN1Av1d6dHRco())
					{
						goto IL_060e;
					}
					goto case 125;
				case 125:
					num4 = 127 + 41;
					num = 234;
					continue;
				case 69:
					num6 = 248 - 82;
					goto case 238;
				case 242:
					array[17] = 119;
					num = 41;
					continue;
				case 63:
					if (array4.Length <= 0)
					{
						break;
					}
					num = 256;
					continue;
				case 322:
					array[8] = (byte)num4;
					num5 = 341;
					goto IL_060a;
				case 185:
					array[31] = (byte)num4;
					num2 = 11;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 262;
				case 262:
					array2[10] = 193;
					num2 = 220;
					goto IL_060e;
				case 313:
					array[14] = (byte)num4;
					num2 = 240;
					goto IL_060e;
				case 36:
					igQ2QpUQqCgTZMP6ut(wFubBF6D4PihCInl4d(binaryReader), 0L);
					num = 64;
					continue;
				case 129:
					array2[6] = 86;
					num = 148;
					continue;
				case 165:
					num4 = 6 + 83;
					num2 = 183;
					goto IL_060e;
				case 31:
					array2[8] = (byte)num6;
					num = 143;
					continue;
				case 118:
					array2[1] = 73;
					num2 = 305;
					if (true)
					{
						goto IL_060e;
					}
					goto case 274;
				case 274:
					array[12] = (byte)num4;
					num2 = 197;
					goto IL_060e;
				case 229:
					array2[7] = (byte)num7;
					num5 = 66;
					goto IL_060a;
				case 68:
					array[18] = (byte)num4;
					num5 = 156;
					goto IL_060a;
				case 32:
					num4 = 216 - 72;
					num5 = 24;
					goto IL_060a;
				case 85:
					array[1] = (byte)num4;
					num = 244;
					continue;
				case 135:
					array2[8] = (byte)num7;
					num = 117;
					continue;
				case 256:
					array3[1] = array4[0];
					num2 = 114;
					if (true)
					{
						goto IL_060e;
					}
					goto case 272;
				case 272:
					array[17] = (byte)num4;
					num2 = 242;
					if (e7sUJMN1Av1d6dHRco())
					{
						goto IL_060e;
					}
					goto case 50;
				case 40:
					array[2] = (byte)num4;
					num5 = 203;
					goto IL_060a;
				case 167:
					num4 = 147 - 49;
					num = 276;
					continue;
				case 53:
					array[31] = (byte)num4;
					num = 16;
					continue;
				case 121:
					array2[11] = 67;
					num2 = 286;
					if (!nm2grPYDKQi2IdGxI5())
					{
						goto IL_060e;
					}
					goto case 157;
				case 54:
					num4 = 145 - 48;
					num2 = 347;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 278;
				case 278:
					array[19] = 156;
					num2 = 45;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 15;
				case 15:
					array[20] = 79;
					num2 = 199;
					goto IL_060e;
				case 61:
					array2[9] = (byte)num6;
					num = 94;
					continue;
				case 109:
					array[6] = (byte)num4;
					num5 = 1;
					goto IL_060a;
				case 150:
					num4 = 166 - 73;
					num = 43;
					continue;
				case 225:
					array[2] = (byte)num4;
					num5 = 130;
					goto IL_060a;
				case 217:
					num6 = 157 - 52;
					num = 209;
					continue;
				case 170:
					array2[8] = (byte)num7;
					num5 = 251;
					goto IL_060a;
				case 117:
					num7 = 240 - 80;
					num2 = 170;
					goto IL_060e;
				case 357:
					binaryReader = new BinaryReader((Stream)aDarQrpgOCQA2sSlbP(V2aPrpuvwBJgYM2NDs(typeof(s2iWBMrDOBbEncFb0a).TypeHandle).Assembly, "OPiDmr2cIjwNUeENG9.nTe4ixIrg7BWdCYZO2"));
					num2 = 36;
					if (e7sUJMN1Av1d6dHRco())
					{
						goto IL_060e;
					}
					goto case 306;
				case 148:
					array2[6] = 142;
					num2 = 112;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 285;
				case 285:
					num4 = 6 + 97;
					num = 162;
					continue;
				case 84:
					array[28] = (byte)num4;
					num2 = 97;
					if (e7sUJMN1Av1d6dHRco())
					{
						goto IL_060e;
					}
					goto case 218;
				case 96:
					array2[10] = (byte)num7;
					num2 = 152;
					if (true)
					{
						goto IL_060e;
					}
					goto case 79;
				case 79:
					num4 = 69 + 2;
					num5 = 225;
					goto IL_060a;
				case 340:
					array[8] = 152;
					num5 = 104;
					goto IL_060a;
				case 152:
					num7 = 181 - 60;
					num = 280;
					continue;
				case 157:
					num6 = 71 + 13;
					num5 = 333;
					goto IL_060a;
				case 60:
					num4 = 157 - 52;
					num2 = 126;
					if (true)
					{
						goto IL_060e;
					}
					goto case 128;
				case 128:
					num7 = 119 + 12;
					num2 = 218;
					if (!nm2grPYDKQi2IdGxI5())
					{
						goto IL_060e;
					}
					goto case 17;
				case 70:
					num4 = 23 + 58;
					num5 = 332;
					goto IL_060a;
				case 44:
					num4 = 209 - 69;
					num = 83;
					continue;
				case 174:
					num6 = 23 + 112;
					num5 = 177;
					goto IL_060a;
				case 194:
					array[1] = 118;
					num2 = 171;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 134;
				case 134:
					array[28] = 88;
					num2 = 29;
					if (!nm2grPYDKQi2IdGxI5())
					{
						goto IL_060e;
					}
					goto case 205;
				case 205:
					array2[13] = (byte)num6;
					num2 = 178;
					if (true)
					{
						goto IL_060e;
					}
					goto case 100;
				case 100:
					array2[5] = 121;
					num2 = 95;
					goto IL_060e;
				case 110:
					array[1] = (byte)num4;
					num = 79;
					continue;
				case 97:
					array[28] = 97;
					num = 275;
					continue;
				case 88:
					array[0] = 15;
					num2 = 296;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 238;
				case 238:
				case 250:
					array2[3] = (byte)num6;
					num2 = 34;
					goto IL_060e;
				case 132:
					num6 = 8 + 36;
					num = 205;
					continue;
				case 145:
					array2[15] = (byte)num6;
					num2 = 74;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 347;
				case 347:
					array[24] = (byte)num4;
					num2 = 245;
					if (e7sUJMN1Av1d6dHRco())
					{
						goto IL_060e;
					}
					goto case 221;
				case 221:
					array[21] = 51;
					num5 = 105;
					goto IL_060a;
				case 276:
					array[4] = (byte)num4;
					num = 35;
					continue;
				case 187:
					array[1] = 84;
					num2 = 140;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 284;
				case 284:
					num4 = 246 - 82;
					num = 103;
					continue;
				case 66:
					array2[7] = 247;
					num5 = 345;
					goto IL_060a;
				case 315:
					S189cUvQiSuueGnwGp(cryptoStream);
					num = 318;
					continue;
				case 204:
					array[11] = (byte)num4;
					num = 133;
					continue;
				case 183:
					array[30] = (byte)num4;
					num = 270;
					continue;
				case 240:
					num4 = 248 - 82;
					num2 = 232;
					if (e7sUJMN1Av1d6dHRco())
					{
						goto IL_060e;
					}
					goto case 206;
				case 149:
					array2[9] = 198;
					num5 = 78;
					goto IL_060a;
				case 261:
					num6 = 24 + 29;
					num = 145;
					continue;
				case 95:
					array2[5] = 152;
					num5 = 241;
					goto IL_060a;
				case 131:
					array2[6] = (byte)num7;
					num = 129;
					continue;
				case 62:
					num6 = 149 - 49;
					num2 = 107;
					goto IL_060e;
				case 9:
					array[21] = 135;
					num = 236;
					continue;
				case 49:
					array3[13] = array4[6];
					num5 = 233;
					goto IL_060a;
				case 154:
					array2[2] = (byte)num6;
					num2 = 269;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 207;
				case 207:
					num4 = 121 + 10;
					num2 = 247;
					if (e7sUJMN1Av1d6dHRco())
					{
						goto IL_060e;
					}
					goto case 95;
				case 59:
					array2[0] = 37;
					num5 = 128;
					goto IL_060a;
				case 8:
					array[15] = 84;
					num2 = 316;
					goto IL_060e;
				case 265:
					array[20] = (byte)num4;
					num5 = 228;
					goto IL_060a;
				case 169:
					array[7] = 163;
					num5 = 125;
					goto IL_060a;
				case 162:
					array[20] = (byte)num4;
					num2 = 325;
					if (!nm2grPYDKQi2IdGxI5())
					{
						goto IL_060e;
					}
					goto case 128;
				case 300:
					if (array4 == null)
					{
						break;
					}
					num5 = 63;
					goto IL_060a;
				case 343:
					array2[11] = (byte)num7;
					num2 = 281;
					goto IL_060e;
				case 330:
					array[5] = (byte)num4;
					num5 = 44;
					goto IL_060a;
				case 271:
					array[4] = (byte)num4;
					num2 = 150;
					if (true)
					{
						goto IL_060e;
					}
					goto case 332;
				case 332:
					array[27] = (byte)num4;
					num2 = 20;
					goto IL_060e;
				case 193:
					num7 = 33 + 58;
					num = 343;
					continue;
				case 209:
					array2[15] = (byte)num6;
					num2 = 261;
					if (e7sUJMN1Av1d6dHRco())
					{
						goto IL_060e;
					}
					goto case 272;
				case 179:
					array2[11] = 67;
					num2 = 193;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 156;
				case 156:
					array[18] = 87;
					num2 = 337;
					if (e7sUJMN1Av1d6dHRco())
					{
						goto IL_060e;
					}
					goto case 352;
				case 352:
					num4 = 165 - 55;
					num = 90;
					continue;
				case 224:
					array[8] = 253;
					num2 = 304;
					if (e7sUJMN1Av1d6dHRco())
					{
						goto IL_060e;
					}
					goto case 185;
				case 102:
					array2[0] = (byte)num7;
					num5 = 59;
					goto IL_060a;
				case 294:
					num4 = 28 + 16;
					num5 = 260;
					goto IL_060a;
				case 351:
					array[11] = (byte)num4;
					num5 = 38;
					goto IL_060a;
				case 350:
					array[20] = (byte)num4;
					num = 285;
					continue;
				case 259:
					num4 = 25 + 41;
					num5 = 68;
					goto IL_060a;
				case 42:
					num4 = 38 + 89;
					num5 = 198;
					goto IL_060a;
				case 231:
					num4 = 19 + 47;
					num5 = 293;
					goto IL_060a;
				case 222:
					num3 = rqx4sTO4x9YqedPyK5(fcVfxKuIV, P_0);
					num2 = 359;
					goto IL_060e;
				case 356:
					S189cUvQiSuueGnwGp(memoryStream);
					num2 = 315;
					if (!nm2grPYDKQi2IdGxI5())
					{
						goto IL_060e;
					}
					goto case 244;
				case 244:
					num4 = 238 - 79;
					num2 = 354;
					goto IL_060e;
				case 47:
					array2[15] = 188;
					num5 = 217;
					goto IL_060a;
				case 302:
					array2 = new byte[16];
					num5 = 235;
					goto IL_060a;
				case 287:
					array3 = array2;
					num = 89;
					continue;
				case 337:
					num4 = 232 - 77;
					num2 = 137;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 196;
				case 196:
					array2[13] = 231;
					num = 174;
					continue;
				case 124:
					array2[4] = (byte)num7;
					num2 = 252;
					goto IL_060e;
				case 353:
					array[30] = (byte)num4;
					num = 289;
					continue;
				case 65:
					array2[4] = 83;
					num5 = 100;
					goto IL_060a;
				case 111:
					array[22] = 46;
					num2 = 161;
					if (e7sUJMN1Av1d6dHRco())
					{
						goto IL_060e;
					}
					goto case 181;
				case 181:
					array[7] = (byte)num4;
					num = 168;
					continue;
				case 291:
					num6 = 122 - 90;
					num5 = 31;
					goto IL_060a;
				case 20:
					array[27] = 148;
					num5 = 328;
					goto IL_060a;
				case 64:
					Q0rk16JBmJMrndEMB7(true);
					num2 = 277;
					goto IL_060e;
				case 13:
					array[6] = 164;
					num2 = 184;
					if (true)
					{
						goto IL_060e;
					}
					goto case 45;
				case 45:
					num4 = 188 + 15;
					num = 264;
					continue;
				case 76:
					array[11] = 59;
					num5 = 93;
					goto IL_060a;
				case 191:
					num4 = 200 - 66;
					num = 71;
					continue;
				case 180:
					array2[8] = (byte)num7;
					num = 291;
					continue;
				case 39:
					num4 = 155 - 85;
					num2 = 175;
					goto IL_060e;
				case 341:
					num4 = 16 + 63;
					num5 = 56;
					goto IL_060a;
				case 127:
					array2[4] = (byte)num6;
					num5 = 65;
					goto IL_060a;
				case 212:
					array[23] = 132;
					num2 = 54;
					goto IL_060e;
				case 52:
					array2[4] = (byte)num7;
					num2 = 308;
					if (!nm2grPYDKQi2IdGxI5())
					{
						goto IL_060e;
					}
					goto case 245;
				case 245:
					array[24] = 73;
					num2 = 254;
					if (e7sUJMN1Av1d6dHRco())
					{
						goto IL_060e;
					}
					goto case 293;
				case 12:
					array2[13] = 54;
					num2 = 196;
					if (!nm2grPYDKQi2IdGxI5())
					{
						goto IL_060e;
					}
					goto case 119;
				case 119:
					num4 = 38 + 40;
					num2 = 99;
					goto IL_060e;
				case 344:
					num4 = 242 - 80;
					num5 = 176;
					goto IL_060a;
				case 23:
					array[7] = 115;
					num2 = 169;
					goto IL_060e;
				case 292:
					num7 = 203 - 67;
					num = 52;
					continue;
				case 178:
					array2[13] = 102;
					num2 = 12;
					if (true)
					{
						goto IL_060e;
					}
					goto case 116;
				case 116:
					array2[3] = 93;
					num = 292;
					continue;
				case 299:
					array2[9] = 98;
					num2 = 149;
					goto IL_060e;
				case 136:
					num4 = 152 - 50;
					num5 = 21;
					goto IL_060a;
				case 82:
					num7 = 64 + 10;
					num = 131;
					continue;
				case 249:
					num4 = 240 - 80;
					num = 331;
					continue;
				case 6:
					array[10] = (byte)num4;
					num5 = 25;
					goto IL_060a;
				case 326:
					array[26] = 90;
					num5 = 32;
					goto IL_060a;
				case 43:
					array[4] = (byte)num4;
					num5 = 10;
					goto IL_060a;
				case 101:
					array2[14] = 186;
					num2 = 182;
					goto IL_060e;
				case 208:
					num7 = 36 + 111;
					num = 124;
					continue;
				case 17:
					num7 = 242 - 80;
					num5 = 102;
					goto IL_060a;
				case 254:
					array[24] = 183;
					num = 191;
					continue;
				case 51:
					array[3] = 115;
					num2 = 33;
					if (e7sUJMN1Av1d6dHRco())
					{
						goto IL_060e;
					}
					goto case 89;
				case 89:
					array4 = (byte[])zKRMZHo2AhonbyNSua(Rp19CISWDFp6Z9cOBk(V2aPrpuvwBJgYM2NDs(typeof(s2iWBMrDOBbEncFb0a).TypeHandle).Assembly));
					num5 = 300;
					goto IL_060a;
				case 37:
					array = new byte[32];
					num = 323;
					continue;
				case 26:
				case 243:
					array2[2] = 134;
					num2 = 77;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 7;
				case 7:
					array3[5] = array4[2];
					num5 = 14;
					goto IL_060a;
				case 264:
					array[19] = (byte)num4;
					num2 = 15;
					if (0 == 0)
					{
						goto IL_060e;
					}
					goto case 305;
				case 305:
					num7 = 158 - 52;
					num5 = 295;
					goto IL_060a;
				case 303:
					array2[2] = 143;
					num = 306;
					continue;
				case 30:
					array2[3] = 139;
					num = 138;
					continue;
				case 339:
					array2[1] = 89;
					num2 = 230;
					if (!nm2grPYDKQi2IdGxI5())
					{
						goto IL_060e;
					}
					goto case 304;
				case 143:
					num6 = 120 + 93;
					num2 = 58;
					goto IL_060e;
				case 304:
					array[9] = 128;
					num2 = 190;
					goto IL_060e;
				case 161:
					array[23] = 120;
					num2 = 173;
					goto IL_060e;
				case 289:
					array[30] = 119;
					num5 = 165;
					goto IL_060a;
				case 106:
					array[22] = (byte)num4;
					num = 111;
					continue;
				case 282:
					array[4] = (byte)num4;
					num5 = 167;
					goto IL_060a;
				case 139:
					array[2] = (byte)num4;
					num5 = 51;
					goto IL_060a;
				case 327:
					num6 = 134 - 44;
					num2 = 142;
					if (true)
					{
						goto IL_060e;
					}
					goto case 246;
				case 246:
					num4 = 5 + 104;
					num5 = 185;
					goto IL_060a;
				case 192:
					array2[2] = (byte)num6;
					_ = 1;
					if (nm2grPYDKQi2IdGxI5())
					{
						num2 = 238;
						goto IL_060e;
					}
					num5 = 26;
					goto IL_060a;
				case 67:
					array2[0] = (byte)num7;
					num5 = 17;
					goto IL_060a;
				case 81:
					array[31] = (byte)num4;
					num5 = 216;
					goto IL_060a;
				case 58:
					array2[9] = (byte)num6;
					num = 248;
					continue;
				case 257:
					array[9] = (byte)num4;
					num5 = 136;
					goto IL_060a;
				case 57:
					array[13] = 160;
					num = 226;
					continue;
				case 158:
					array[16] = 84;
					num2 = 227;
					goto IL_060e;
				case 248:
					num6 = 134 - 44;
					num5 = 301;
					goto IL_060a;
				case 359:
					try
					{
						return (string)LoTWTes7D15GOSuYN6(xgaZSh71v3XJEh4hTZ(), fcVfxKuIV, P_0 + 4, num3);
					}
					catch
					{
					}
					return "";
				case 46:
					break;
				case 336:
					{
						memoryStream = new MemoryStream();
						num2 = 195;
						if (e7sUJMN1Av1d6dHRco())
						{
							goto IL_060e;
						}
						goto case 141;
					}
					IL_060e:
					num = num2;
					continue;
					IL_060a:
					num2 = num5;
					goto IL_060e;
				}
				rijndaelManaged = new RijndaelManaged();
				num = 146;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[Ce3Ia9Ek5kILAOPaaM(typeof(s2iWBMrDOBbEncFb0a/Ce3Ia9Ek5kILAOPaaM/d7hs9D8cZx7BUG3yQv<object>[]))]
		internal static string fv07FIfIL(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void vCs1RIHve(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int xXLsLFEIT(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr HxkrkwajE(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void dLKPkLxXJ()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void hweEb6pVc()
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
		internal static object si8895Z90(object P_0)
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
		public static extern IntPtr Q0ZxmWCbe(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr KEriaNt2i(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int RBMRDOBbE(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int NcFTb0aso(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int mjI5cl3RN(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr IiJpKq3Zd(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int o3Iya9k5k(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[Ce3Ia9Ek5kILAOPaaM(typeof(s2iWBMrDOBbEncFb0a/Ce3Ia9Ek5kILAOPaaM/d7hs9D8cZx7BUG3yQv<object>[]))]
		private static byte[] qLAeOPaaM(string P_0)
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
		[Ce3Ia9Ek5kILAOPaaM(typeof(s2iWBMrDOBbEncFb0a/Ce3Ia9Ek5kILAOPaaM/d7hs9D8cZx7BUG3yQv<object>[]))]
		private static byte[] d7hHs9DcZ(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				15, 190, 163, 204, 39, 181, 206, 28, 201, 69,
				165, 251, 11, 166, 142, 123, 32, 233, 168, 134,
				6, 125, 206, 119, 242, 72, 44, 81, 239, 214,
				155, 19
			};
			rijndael.IV = new byte[16]
			{
				218, 197, 147, 30, 96, 124, 237, 221, 193, 19,
				250, 33, 110, 144, 200, 2
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] i7BlUG3yQ()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] CASI7V20l()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] MvEtHo2yp()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] QfxKqpneV()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] j6Xqvgtu6()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] B4VF3Cakv()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] fiI2lpHuN()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] Tj1MFb3u9()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] ibHZISw3i()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] raTAg7ycG()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public s2iWBMrDOBbEncFb0a()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type V2aPrpuvwBJgYM2NDs(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object aDarQrpgOCQA2sSlbP(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object wFubBF6D4PihCInl4d(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void igQ2QpUQqCgTZMP6ut(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Q0rk16JBmJMrndEMB7(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long xqRlSSFHIJLLipDb9H(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object l99jmLLAwF2Pu27oxd(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Rp19CISWDFp6Z9cOBk(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object zKRMZHo2AhonbyNSua(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void ql0hN4E1FflvdaCBOY(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object ww8ma0ZBFbEkoG7RAj(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void pIW6TXaPHFOsCGJN76(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void OjU9OsCj9DtWmQNWhY(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object jPmAr24doPdGdLw8X4(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void S189cUvQiSuueGnwGp(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void lGPrh98bjQLLOnZm9H(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int rqx4sTO4x9YqedPyK5(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object xgaZSh71v3XJEh4hTZ()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object LoTWTes7D15GOSuYN6(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool e7sUJMN1Av1d6dHRco()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool nm2grPYDKQi2IdGxI5()
		{
			return false;
		}
	}
}
namespace fXXbNnywvJkJVvYuJc
{
	internal class Y2rcVxpKuIVkhuGfWv
	{
		private static bool EmdUxTveI;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void xEOwMaczYhPPw()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Y2rcVxpKuIVkhuGfWv()
		{
		}
	}
}
