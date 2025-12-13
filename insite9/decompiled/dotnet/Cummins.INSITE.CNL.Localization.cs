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
using System.Xml;
using Cummins.INSITE.CNL.Common.Files;
using Cummins.INSITE.CNL.Common.Registry;
using IHamRx42Sgxdaarhoa;
using xjBImk8R1v4P4ID9WS;

[assembly: Guid("d8f6e6f7-3cc5-4c68-8a95-f302f5f89570")]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(true)]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: AssemblyTitle("Cummins.CNL.Localization")]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyProduct("INSITE")]
[assembly: AssemblyDescription("Cummins .NET Libraries Localization Component")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace KP0VUVSD5fEBrkOJ6Z
{
	internal static class rwXPYOqLMeKiCQxE9j
	{
	}
}
namespace Cummins.INSITE.CNL.Localization
{
	public interface ILocalizedStringProvider
	{
		void Initialize(string registryKeyPath, Guid clientGuid);

		void Initialize(string resourceFileName);

		string GetLocalizedString(Enum stringId);

		string GetLocalizedString(int stringId);
	}
	public class LocalizedStringProvider : ILocalizedStringProvider
	{
		private const string p9P639Z7h = "XMLResource";

		private const string A9vqPTM3y = "XMLResources";

		private const string BlwSXPYOL = "LanguageExt";

		private const string oeKniCQxE = "SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\CS\\Locale";

		private const string ajhLP0VUV = "SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\CS\\Paths";

		protected string _xmlFilename;

		protected Dictionary<int, string> _stringsDictionary;

		protected bool _initialized;

		protected ILocalMachineRegistryReader _registryReader;

		protected IFileReader _fileReader;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public LocalizedStringProvider(ILocalMachineRegistryReader registryReader, IFileReader fileReader)
		{
			rKli24oOZc79e8M4Kd.sjnYRGUzF0vNu();
			base..ctor();
			_registryReader = registryReader;
			_fileReader = fileReader;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Initialize(string registryKeyPath, Guid clientGuid)
		{
			if (registryKeyPath == null)
			{
				throw new ArgumentNullException(O7I1wwWnHSZSv6qhDj.M6Z8OebEh(0));
			}
			if (registryKeyPath.Length == 0)
			{
				throw new ArgumentException(O7I1wwWnHSZSv6qhDj.M6Z8OebEh(34));
			}
			if (Guid.Empty == clientGuid)
			{
				throw new ArgumentException(O7I1wwWnHSZSv6qhDj.M6Z8OebEh(136));
			}
			_stringsDictionary = new Dictionary<int, string>();
			string keyName = registryKeyPath + clientGuid.ToString(O7I1wwWnHSZSv6qhDj.M6Z8OebEh(228));
			string input = _registryReader.ReadValue(keyName, O7I1wwWnHSZSv6qhDj.M6Z8OebEh(234));
			_xmlFilename = ReplaceLanguageExt(input);
			LoadData();
			_initialized = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Initialize(string resourceFileName)
		{
			if (resourceFileName == null)
			{
				throw new ArgumentNullException(O7I1wwWnHSZSv6qhDj.M6Z8OebEh(260));
			}
			if (resourceFileName.Length == 0)
			{
				throw new ArgumentException(O7I1wwWnHSZSv6qhDj.M6Z8OebEh(296));
			}
			_stringsDictionary = new Dictionary<int, string>();
			string path = _registryReader.ReadValue(O7I1wwWnHSZSv6qhDj.M6Z8OebEh(400), O7I1wwWnHSZSv6qhDj.M6Z8OebEh(522));
			path = Path.Combine(path, resourceFileName);
			_xmlFilename = ReplaceLanguageExt(path);
			LoadData();
			_initialized = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetLocalizedString(Enum stringId)
		{
			if (!_initialized)
			{
				throw new InvalidOperationException(O7I1wwWnHSZSv6qhDj.M6Z8OebEh(550));
			}
			return InternalGetLocalizedString(Convert.ToInt32(stringId));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetLocalizedString(int stringId)
		{
			if (!_initialized)
			{
				throw new InvalidOperationException(O7I1wwWnHSZSv6qhDj.M6Z8OebEh(662));
			}
			return InternalGetLocalizedString(stringId);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual string ReplaceLanguageExt(string input)
		{
			string empty = string.Empty;
			string value = _registryReader.ReadValue(O7I1wwWnHSZSv6qhDj.M6Z8OebEh(774), O7I1wwWnHSZSv6qhDj.M6Z8OebEh(898));
			int num = input.LastIndexOf('_');
			int num2 = input.LastIndexOf('.');
			empty = input.Remove(num + 1, num2 - num - 1);
			return empty.Insert(num + 1, value);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void LoadData()
		{
			//IL_0038: Unknown result type (might be due to invalid IL or missing references)
			//IL_003e: Expected O, but got Unknown
			//IL_0072: Unknown result type (might be due to invalid IL or missing references)
			//IL_0078: Expected O, but got Unknown
			_stringsDictionary.Clear();
			if (!_fileReader.Exists(_xmlFilename))
			{
				throw new FileNotFoundException(O7I1wwWnHSZSv6qhDj.M6Z8OebEh(924));
			}
			try
			{
				XmlDocument val = new XmlDocument();
				val.Load(_xmlFilename);
				foreach (XmlNode item in val.DocumentElement.GetElementsByTagName(O7I1wwWnHSZSv6qhDj.M6Z8OebEh(1008)))
				{
					XmlNode val2 = item;
					try
					{
						int num = -1;
						string empty = string.Empty;
						num = Convert.ToInt32(((XmlNode)val2.Attributes[O7I1wwWnHSZSv6qhDj.M6Z8OebEh(1024)]).Value);
						empty = val2.InnerText;
						_stringsDictionary.Add(num, empty);
					}
					catch
					{
					}
				}
			}
			catch
			{
				_stringsDictionary.Clear();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual string InternalGetLocalizedString(int stringId)
		{
			if (_stringsDictionary.Count == 0)
			{
				LoadData();
			}
			if (_stringsDictionary.ContainsKey(stringId))
			{
				return _stringsDictionary[stringId];
			}
			return null;
		}
	}
}
internal class <Module>{4EAAF9FD-1275-470D-9267-F91716B667C9}
{
}
namespace TCXoJPLyiQ7LqZl5t4
{
	internal class FebEhsnSO49HVnPrX4
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module y5fWEBrkO;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void xLIYRGUU6cXGv(int typemdt)
		{
			Type type = y5fWEBrkO.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)y5fWEBrkO.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FebEhsnSO49HVnPrX4()
		{
			rKli24oOZc79e8M4Kd.sjnYRGUzF0vNu();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static FebEhsnSO49HVnPrX4()
		{
			rKli24oOZc79e8M4Kd.sjnYRGUzF0vNu();
			y5fWEBrkO = typeof(FebEhsnSO49HVnPrX4).Assembly.ManifestModule;
		}
	}
}
namespace xjBImk8R1v4P4ID9WS
{
	internal class O7I1wwWnHSZSv6qhDj
	{
		internal class A8IysnjaY3BunHEA6k : Attribute
		{
			internal class hWmmiKbelFZDEdrmMp<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public hWmmiKbelFZDEdrmMp()
				{
					rKli24oOZc79e8M4Kd.sjnYRGUzF0vNu();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[A8IysnjaY3BunHEA6k(typeof(O7I1wwWnHSZSv6qhDj/A8IysnjaY3BunHEA6k/hWmmiKbelFZDEdrmMp<object>[]))]
			public A8IysnjaY3BunHEA6k(object P_0)
			{
				rKli24oOZc79e8M4Kd.sjnYRGUzF0vNu();
				base..ctor();
			}
		}

		internal class sV7OEgPe2S89Mm6Iap
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[A8IysnjaY3BunHEA6k(typeof(O7I1wwWnHSZSv6qhDj/A8IysnjaY3BunHEA6k/hWmmiKbelFZDEdrmMp<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (ex4TSjBcr(Convert.ToBase64String(typeof(O7I1wwWnHSZSv6qhDj).Assembly.GetName().GetPublicKeyToken()), O7I1wwWnHSZSv6qhDj.M6Z8OebEh(1032)) != O7I1wwWnHSZSv6qhDj.M6Z8OebEh(1038))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[A8IysnjaY3BunHEA6k(typeof(O7I1wwWnHSZSv6qhDj/A8IysnjaY3BunHEA6k/hWmmiKbelFZDEdrmMp<object>[]))]
			internal static string ex4TSjBcr(string P_0, string P_1)
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
			public sV7OEgPe2S89Mm6Iap()
			{
				rKli24oOZc79e8M4Kd.sjnYRGUzF0vNu();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint XoJYrCZf4X42NgrALC([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr tBNAuVXusPamDZDFLC();

		internal struct R5AP6ZdJqSG0VADUhB
		{
			internal bool aXYGWfpNM;

			internal byte[] PiZCPwPas;
		}

		[Flags]
		private enum BaiMO2xwXPlIQsuQes
		{

		}

		private static byte[] uv6ECqa5R;

		private static SortedList AYlhWpwRd;

		private static int dEjJSR4ji;

		private static long oYnpdHYK9;

		private static IntPtr dgtUajYYl;

		internal static Hashtable tHUsUZ5ZF;

		private static IntPtr Q94BMInGO;

		private static byte[] lda5arhoa;

		internal static XoJYrCZf4X42NgrALC Xh9QROTJg;

		private static int[] ag5rHBSxF;

		private static object LItiAfIgo;

		private static bool iS7Yvw3jX;

		private static long mWLv7u2KP;

		private static int QV7An0Hgg;

		private static int UbQeASZGE;

		internal static XoJYrCZf4X42NgrALC JwKKQyJsl;

		private static int YMyfJDc4B;

		private static byte[] wYY2tAuVp;

		private static byte[] XknFxIHa8;

		private static bool T1OVEk4LM;

		private static IntPtr kUeOAvAGr;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static O7I1wwWnHSZSv6qhDj()
		{
			lda5arhoa = new byte[0];
			uv6ECqa5R = new byte[0];
			XknFxIHa8 = new byte[0];
			wYY2tAuVp = new byte[0];
			kUeOAvAGr = IntPtr.Zero;
			Q94BMInGO = IntPtr.Zero;
			LItiAfIgo = new string[0];
			ag5rHBSxF = new int[0];
			UbQeASZGE = 1;
			iS7Yvw3jX = false;
			AYlhWpwRd = new SortedList();
			dEjJSR4ji = 0;
			oYnpdHYK9 = 0L;
			Xh9QROTJg = null;
			JwKKQyJsl = null;
			mWLv7u2KP = 0L;
			YMyfJDc4B = 0;
			T1OVEk4LM = false;
			QV7An0Hgg = 0;
			dgtUajYYl = IntPtr.Zero;
			tHUsUZ5ZF = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void TVLYRGUQaxy6j()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[A8IysnjaY3BunHEA6k(typeof(O7I1wwWnHSZSv6qhDj/A8IysnjaY3BunHEA6k/hWmmiKbelFZDEdrmMp<object>[]))]
		static string M6Z8OebEh(int P_0)
		{
			int num = 84;
			int num5 = default(int);
			byte[] array = default(byte[]);
			byte[] array2 = default(byte[]);
			byte[] array3 = default(byte[]);
			int num4 = default(int);
			int num6 = default(int);
			byte[] array4 = default(byte[]);
			CryptoStream cryptoStream = default(CryptoStream);
			MemoryStream memoryStream = default(MemoryStream);
			ICryptoTransform transform = default(ICryptoTransform);
			byte[] array6 = default(byte[]);
			BinaryReader binaryReader = default(BinaryReader);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array5 = default(byte[]);
			while (true)
			{
				int num2 = num;
				while (true)
				{
					int num3 = num2;
					while (true)
					{
						switch (num3)
						{
						case 284:
							break;
						case 107:
							goto IL_0029;
						case 212:
							goto IL_0045;
						case 327:
							goto IL_0061;
						case 344:
							goto IL_007e;
						case 300:
							num5 = 151 + 57;
							num2 = 85;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 111;
						case 111:
							array[11] = array2[5];
							num2 = 286;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 55;
						case 55:
							num5 = 181 - 60;
							num2 = 96;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 21;
						case 21:
							array3[13] = (byte)num5;
							num2 = 145;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 325;
						case 325:
							num5 = 48 + 105;
							num2 = 107;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 26;
						case 26:
							array3[21] = 104;
							num2 = 305;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 29;
						case 238:
							num4 = hFTJKtgA47BQJDFqcw(XknFxIHa8, P_0);
							num3 = 368;
							continue;
						case 270:
							goto IL_0178;
						case 66:
							num5 = 115 + 7;
							num3 = 13;
							continue;
						case 352:
							num6 = 2 + 104;
							num3 = 173;
							continue;
						case 172:
							num5 = 117 + 82;
							num3 = 314;
							continue;
						case 7:
							goto IL_01db;
						case 161:
							array3[14] = (byte)num5;
							num2 = 265;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 51;
						case 51:
							array4[9] = (byte)num6;
							num = 61;
							goto end_IL_199b;
						case 252:
							array3[31] = (byte)num5;
							num2 = 69;
							goto end_IL_199f;
						case 348:
							array3[11] = (byte)num5;
							num2 = 76;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 226;
						case 89:
							array3[27] = (byte)num5;
							num2 = 139;
							goto end_IL_199f;
						case 72:
							num6 = 247 - 82;
							num2 = 216;
							goto end_IL_199f;
						case 229:
							array4[4] = (byte)num6;
							num2 = 211;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 256;
						case 256:
							array3[20] = (byte)num5;
							num3 = 164;
							continue;
						case 128:
							cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
							num3 = 15;
							continue;
						case 230:
							array4[3] = (byte)num6;
							num2 = 350;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 44;
						case 44:
							array4[14] = 132;
							num2 = 12;
							goto end_IL_199f;
						case 353:
							array3[6] = 125;
							num2 = 129;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 20;
						case 20:
							array3[9] = (byte)num5;
							num2 = 57;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 146;
						case 146:
							num5 = 151 - 50;
							num2 = 302;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 341;
						case 112:
							XknFxIHa8 = (byte[])Wtl2A1wgFppR5xoQtN(memoryStream);
							num3 = 273;
							continue;
						case 148:
							array3[15] = (byte)num5;
							num = 215;
							goto end_IL_199b;
						case 305:
							num5 = 124 + 54;
							num3 = 244;
							continue;
						case 4:
							array4[1] = (byte)num6;
							num = 121;
							goto end_IL_199b;
						case 82:
							array3[12] = 220;
							num3 = 239;
							continue;
						case 152:
							num6 = 157 - 52;
							num2 = 4;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 26;
						case 12:
							num6 = 186 - 62;
							num3 = 354;
							continue;
						case 267:
							num5 = 190 - 70;
							num = 158;
							goto end_IL_199b;
						case 294:
							num5 = 166 - 63;
							num2 = 303;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 171;
						case 171:
							array3[22] = 110;
							num3 = 287;
							continue;
						case 268:
							array3[31] = (byte)num5;
							num3 = 48;
							continue;
						case 65:
							array3[30] = 100;
							num = 269;
							goto end_IL_199b;
						case 204:
							array3[24] = (byte)num5;
							num2 = 24;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 164;
						case 43:
							array3[26] = (byte)num5;
							num3 = 137;
							continue;
						case 36:
							array3[26] = (byte)num5;
							_ = 0;
							if (TwmP5BGbkxnJDo2g8m())
							{
								num = 186;
								goto end_IL_199b;
							}
							num2 = 168;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 130;
						case 169:
							array3[5] = 104;
							num = 346;
							goto end_IL_199b;
						case 81:
							if (array2 != null)
							{
								num3 = 151;
								continue;
							}
							goto case 220;
						case 184:
							num5 = 156 - 52;
							num2 = 231;
							goto end_IL_199f;
						case 202:
							array3[11] = (byte)num5;
							num3 = 327;
							continue;
						case 31:
							array3[17] = 103;
							num2 = 315;
							goto end_IL_199f;
						case 143:
							Yaac44v5cRG4qtd8AK(cryptoStream);
							num2 = 221;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 265;
						case 265:
							array3[14] = 46;
							num2 = 162;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 131;
						case 131:
							num5 = 182 - 60;
							num2 = 130;
							goto end_IL_199f;
						case 351:
							array3[13] = 130;
							num = 11;
							goto end_IL_199b;
						case 179:
							array3[25] = 128;
							num2 = 249;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 222;
						case 222:
							num6 = 110 + 25;
							num2 = 236;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 361;
						case 361:
							array3[16] = (byte)num5;
							num3 = 299;
							continue;
						case 226:
							num6 = 99 + 32;
							num = 266;
							goto end_IL_199b;
						case 86:
							array3[27] = (byte)num5;
							num = 118;
							goto end_IL_199b;
						case 88:
							array3[4] = 189;
							num2 = 35;
							goto end_IL_199f;
						case 33:
							array4[7] = 5;
							num2 = 177;
							goto end_IL_199f;
						case 120:
							num6 = 130 - 117;
							num2 = 232;
							goto end_IL_199f;
						case 5:
							array4[4] = (byte)num6;
							num2 = 288;
							goto end_IL_199f;
						case 190:
							array4[15] = (byte)num6;
							num2 = 30;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 266;
						case 329:
							array3[4] = (byte)num5;
							num2 = 210;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 55;
						case 162:
							array3[14] = 164;
							num2 = 363;
							goto end_IL_199f;
						case 319:
							array4[9] = 132;
							num2 = 126;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 266;
						case 266:
							array4[8] = (byte)num6;
							num2 = 207;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 54;
						case 54:
							array3[15] = (byte)num5;
							num2 = 280;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 246;
						case 246:
							array4[8] = 150;
							num2 = 2;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 18;
						case 18:
							num5 = 80 + 90;
							num = 284;
							goto end_IL_199b;
						case 338:
							num5 = 126 - 42;
							num = 114;
							goto end_IL_199b;
						case 205:
							array3[31] = (byte)num5;
							num3 = 344;
							continue;
						case 30:
							num6 = 190 - 63;
							num3 = 250;
							continue;
						case 215:
							array3[15] = 127;
							num2 = 79;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 233;
						case 233:
							num5 = 122 + 95;
							num2 = 361;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 156;
						case 156:
							array4[12] = 173;
							num2 = 59;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 39;
						case 39:
							array4[9] = (byte)num6;
							num3 = 58;
							continue;
						case 116:
							num6 = 172 - 57;
							num = 188;
							goto end_IL_199b;
						case 163:
							num5 = 196 - 65;
							num2 = 71;
							goto end_IL_199f;
						case 150:
							array4[2] = (byte)num6;
							num2 = 272;
							goto end_IL_199f;
						case 170:
							array3[14] = (byte)num5;
							num2 = 292;
							goto end_IL_199f;
						case 235:
							num5 = 94 - 72;
							num3 = 89;
							continue;
						case 295:
							array3[11] = (byte)num5;
							num2 = 75;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 217;
						case 302:
							array3[13] = (byte)num5;
							num2 = 351;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 158;
						case 158:
							array3[8] = (byte)num5;
							num2 = 331;
							goto end_IL_199f;
						case 138:
							array4[15] = 209;
							num2 = 356;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 137;
						case 145:
							num5 = 13 + 109;
							num = 8;
							goto end_IL_199b;
						case 132:
							num5 = 151 - 50;
							num3 = 223;
							continue;
						case 68:
							array4[12] = (byte)num6;
							num = 209;
							goto end_IL_199b;
						case 260:
							array3[15] = (byte)num5;
							num2 = 233;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 354;
						case 354:
							array4[14] = (byte)num6;
							num2 = 337;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 74;
						case 74:
							num5 = 28 + 35;
							num2 = 42;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 225;
						case 225:
							num5 = 196 - 65;
							num2 = 47;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 15;
						case 15:
							HqpfDmMsX5JJimIFqW(cryptoStream, array6, 0, array6.Length);
							num = 201;
							goto end_IL_199b;
						case 296:
							array[7] = array2[3];
							num2 = 366;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 149;
						case 149:
							num5 = 180 - 60;
							num3 = 67;
							continue;
						case 46:
							array3[25] = (byte)num5;
							num = 297;
							goto end_IL_199b;
						case 98:
							num5 = 199 - 120;
							num2 = 311;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 23;
						case 23:
							array3[12] = 123;
							num2 = 82;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 287;
						case 287:
							num5 = 232 - 77;
							num2 = 304;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 219;
						case 219:
							num6 = 169 - 56;
							num2 = 6;
							goto end_IL_199f;
						case 11:
							num5 = 112 + 51;
							num2 = 161;
							goto end_IL_199f;
						case 335:
							array3[7] = 122;
							num3 = 253;
							continue;
						case 342:
							array3[5] = (byte)num5;
							num3 = 353;
							continue;
						case 77:
							binaryReader = new BinaryReader((Stream)r17QDouXXkVNkXBW2n(lMMBBgk7HjdBcP6cPC(typeof(O7I1wwWnHSZSv6qhDj).TypeHandle).Assembly, "xBTmtfHWuskwx1xsEk.0jfqM42jJDUEy73EWx"));
							num3 = 291;
							continue;
						case 185:
							array[1] = array2[0];
							num3 = 234;
							continue;
						case 93:
							array4[12] = (byte)num6;
							num2 = 156;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 41;
						case 331:
							num5 = 96 + 119;
							num2 = 332;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 71;
						case 71:
							array3[26] = (byte)num5;
							num = 183;
							goto end_IL_199b;
						case 275:
							num5 = 210 - 70;
							num = 41;
							goto end_IL_199b;
						case 67:
							array3[10] = (byte)num5;
							num3 = 74;
							continue;
						case 157:
							array3[20] = (byte)num5;
							num2 = 194;
							goto end_IL_199f;
						case 271:
							array4[2] = 13;
							num3 = 293;
							continue;
						case 196:
							array3[25] = (byte)num5;
							num = 195;
							goto end_IL_199b;
						case 135:
							array3[18] = (byte)num5;
							num2 = 147;
							goto end_IL_199f;
						case 100:
							array4[7] = (byte)num6;
							num2 = 206;
							goto end_IL_199f;
						case 101:
							num6 = 32 + 103;
							num3 = 150;
							continue;
						case 195:
							array3[26] = 154;
							num3 = 324;
							continue;
						case 110:
							array3[12] = (byte)num5;
							num = 23;
							goto end_IL_199b;
						case 122:
							array3[8] = (byte)num5;
							num3 = 267;
							continue;
						case 99:
							array3[2] = (byte)num5;
							num2 = 320;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 48;
						case 48:
							num5 = 122 + 88;
							num = 252;
							goto end_IL_199b;
						case 42:
							array3[10] = (byte)num5;
							num = 227;
							goto end_IL_199b;
						case 365:
							array4[3] = (byte)num6;
							num3 = 343;
							continue;
						case 173:
							array4[1] = (byte)num6;
							num3 = 152;
							continue;
						case 27:
							array4[1] = (byte)num6;
							num3 = 262;
							continue;
						case 207:
							num6 = 156 - 52;
							num2 = 341;
							goto end_IL_199f;
						case 155:
							array3[1] = 69;
							num2 = 316;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 331;
						case 186:
						case 192:
							array3[26] = 204;
							num = 163;
							goto end_IL_199b;
						case 103:
							num5 = 164 - 54;
							num = 254;
							goto end_IL_199b;
						case 178:
							num5 = 159 + 61;
							num2 = 170;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 187;
						case 187:
							num5 = 44 + 67;
							num3 = 56;
							continue;
						case 87:
							array4[8] = (byte)num6;
							num = 226;
							goto end_IL_199b;
						case 53:
							array3[18] = (byte)num5;
							num2 = 132;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 234;
						case 234:
							array[3] = array2[1];
							num2 = 142;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 223;
						case 127:
							array3[20] = 209;
							num2 = 290;
							goto end_IL_199f;
						case 108:
							array4[7] = 131;
							num2 = 33;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 273;
						case 273:
							Yaac44v5cRG4qtd8AK(memoryStream);
							num2 = 143;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 315;
						case 315:
							array3[17] = 92;
							num3 = 189;
							continue;
						case 272:
							array4[2] = 155;
							num = 116;
							goto end_IL_199b;
						case 245:
							array4[10] = 63;
							num2 = 72;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 61;
						case 61:
							array4[9] = 130;
							num2 = 319;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 343;
						case 343:
							num6 = 204 - 68;
							num2 = 203;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 312;
						case 312:
							array4[3] = (byte)num6;
							num3 = 306;
							continue;
						case 288:
							num6 = 54 + 18;
							num = 318;
							goto end_IL_199b;
						case 9:
							array4[4] = (byte)num6;
							num3 = 301;
							continue;
						case 339:
							array4[3] = 110;
							num3 = 224;
							continue;
						case 257:
							array[15] = array2[7];
							num3 = 220;
							continue;
						case 254:
							array3[29] = (byte)num5;
							num3 = 263;
							continue;
						case 301:
							num6 = 4 + 4;
							num = 5;
							goto end_IL_199b;
						case 64:
							array3[28] = 74;
							num2 = 1;
							goto end_IL_199f;
						case 62:
							num5 = 160 + 41;
							num2 = 0;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 10;
						case 140:
							array3[0] = 123;
							num3 = 322;
							continue;
						case 102:
							array3[1] = (byte)num5;
							num3 = 155;
							continue;
						case 240:
							array4[3] = (byte)num6;
							num3 = 198;
							continue;
						case 316:
							num5 = 206 - 68;
							num3 = 99;
							continue;
						case 203:
							array4[3] = (byte)num6;
							num = 339;
							goto end_IL_199b;
						case 73:
							array4[5] = (byte)num6;
							num3 = 120;
							continue;
						case 104:
							Wi0ww8Agm0EdWok7py(true);
							num2 = 45;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 269;
						case 269:
							array3[30] = 166;
							num2 = 98;
							goto end_IL_199f;
						case 255:
							num6 = 131 - 43;
							num3 = 68;
							continue;
						case 224:
							num6 = 149 - 115;
							num2 = 230;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 63;
						case 139:
							num5 = 47 + 12;
							num2 = 119;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 201;
						case 201:
							TC0tegjkUe4waBCRyv(cryptoStream);
							num2 = 112;
							goto end_IL_199f;
						case 250:
							array4[15] = (byte)num6;
							num2 = 138;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 299;
						case 299:
							array3[16] = 165;
							num2 = 123;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 210;
						case 210:
							array3[4] = 150;
							num2 = 125;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 174;
						case 174:
							array3[4] = 157;
							num2 = 88;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 197;
						case 197:
							num6 = 29 + 104;
							num3 = 9;
							continue;
						case 292:
							array3[15] = 229;
							num = 34;
							goto end_IL_199b;
						case 213:
							num5 = 14 + 59;
							num2 = 256;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 183;
						case 183:
							num5 = 65 + 19;
							num3 = 43;
							continue;
						case 251:
							array3[7] = (byte)num5;
							num2 = 274;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 58;
						case 58:
							num6 = 233 - 77;
							num2 = 51;
							goto end_IL_199f;
						case 69:
							num5 = 190 - 63;
							num3 = 205;
							continue;
						case 95:
							num6 = 98 + 5;
							num2 = 39;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 119;
						case 360:
							array4[8] = 168;
							num = 246;
							goto end_IL_199b;
						case 253:
							array3[8] = 16;
							num3 = 117;
							continue;
						case 334:
							array3[10] = 191;
							num3 = 149;
							continue;
						case 364:
							array3[23] = 50;
							num2 = 325;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 227;
						case 227:
							num5 = 130 - 43;
							num2 = 191;
							goto end_IL_199f;
						case 308:
							array4[0] = 110;
							num2 = 281;
							goto end_IL_199f;
						case 19:
							array3[16] = (byte)num5;
							num2 = 91;
							goto end_IL_199f;
						case 303:
							array3[6] = (byte)num5;
							num2 = 105;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 2;
						case 328:
							array3[3] = 96;
							num2 = 258;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 15;
						case 94:
							array3[24] = 148;
							num3 = 362;
							continue;
						case 262:
							num6 = 121 - 68;
							num2 = 330;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 217;
						case 217:
							array3[19] = (byte)num5;
							num = 55;
							goto end_IL_199b;
						case 223:
							array3[18] = (byte)num5;
							num3 = 106;
							continue;
						case 326:
							array4 = new byte[16];
							num2 = 308;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 226;
						case 350:
							num6 = 115 + 73;
							num2 = 181;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 134;
						case 134:
							num5 = 118 + 63;
							num3 = 212;
							continue;
						case 289:
							num5 = 101 + 31;
							num2 = 348;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 282;
						case 282:
							num5 = 29 + 109;
							num = 63;
							goto end_IL_199b;
						case 151:
							if (array2.Length > 0)
							{
								num2 = 185;
								if (true)
								{
									goto end_IL_199f;
								}
								goto case 320;
							}
							goto case 220;
						case 320:
							array3[2] = 155;
							num3 = 338;
							continue;
						case 263:
							array3[29] = 73;
							num = 97;
							goto end_IL_199b;
						case 57:
							array3[9] = 152;
							num2 = 248;
							goto end_IL_199f;
						case 14:
							num6 = 115 + 114;
							num2 = 190;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 332;
						case 332:
							array3[9] = (byte)num5;
							num = 237;
							goto end_IL_199b;
						case 105:
							num5 = 162 - 54;
							num = 251;
							goto end_IL_199b;
						case 228:
							array4[9] = (byte)num6;
							num = 32;
							goto end_IL_199b;
						case 79:
							num5 = 236 - 78;
							num = 54;
							goto end_IL_199b;
						case 346:
							num5 = 185 + 42;
							num = 342;
							goto end_IL_199b;
						case 175:
							array3[10] = 49;
							num = 187;
							goto end_IL_199b;
						case 188:
							array4[2] = (byte)num6;
							num3 = 271;
							continue;
						case 307:
							array4[13] = 184;
							num3 = 44;
							continue;
						case 80:
							num6 = 221 - 73;
							num3 = 270;
							continue;
						case 206:
							num6 = 149 - 49;
							num2 = 298;
							goto end_IL_199f;
						case 41:
							array3[13] = (byte)num5;
							num = 18;
							goto end_IL_199b;
						case 147:
							num5 = 79 + 117;
							num = 217;
							goto end_IL_199b;
						case 221:
							FjwcwMI6HcJ89yRsSW(binaryReader);
							num3 = 238;
							continue;
						case 129:
							num5 = 144 - 48;
							num3 = 218;
							continue;
						case 231:
							array3[10] = (byte)num5;
							num2 = 334;
							goto end_IL_199f;
						case 91:
							array3[17] = 52;
							num2 = 172;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 3;
						case 3:
							array4[11] = 108;
							num3 = 222;
							continue;
						case 193:
							array4[2] = (byte)num6;
							num = 50;
							goto end_IL_199b;
						case 176:
							array3[1] = 47;
							num2 = 29;
							goto end_IL_199f;
						case 125:
							array3[5] = 134;
							num3 = 169;
							continue;
						case 249:
							array3[25] = 153;
							goto case 277;
						default:
							num = 277;
							goto end_IL_199b;
						case 177:
							num6 = 116 + 52;
							num2 = 87;
							goto end_IL_199f;
						case 2:
							num6 = 217 + 28;
							num2 = 16;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 117;
						case 117:
							num5 = 212 - 70;
							num2 = 122;
							goto end_IL_199f;
						case 314:
							array3[17] = (byte)num5;
							num2 = 134;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 277;
						case 118:
							array3[27] = 126;
							num3 = 235;
							continue;
						case 124:
							array3[23] = 53;
							num2 = 37;
							goto end_IL_199f;
						case 160:
							array3[7] = 39;
							num2 = 335;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 236;
						case 236:
							array4[11] = (byte)num6;
							num2 = 255;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 103;
						case 241:
							array4[12] = (byte)num6;
							num = 40;
							goto end_IL_199b;
						case 168:
						case 355:
							R4Sm4CFEtLmivO7T0e(rijndaelManaged, CipherMode.CBC);
							num2 = 141;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 121;
						case 121:
							array4[1] = 84;
							num2 = 247;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 166;
						case 166:
							array3[0] = 186;
							num2 = 333;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 298;
						case 298:
							array4[7] = (byte)num6;
							num2 = 108;
							goto end_IL_199f;
						case 322:
							num5 = 233 - 77;
							num2 = 357;
							goto end_IL_199f;
						case 83:
							array4[0] = 80;
							num2 = 352;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 230;
						case 345:
							array4[6] = (byte)num6;
							num2 = 28;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 159;
						case 142:
							array[5] = array2[2];
							num2 = 296;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 330;
						case 362:
							num5 = 125 - 41;
							num3 = 204;
							continue;
						case 310:
							array3[23] = 76;
							num2 = 49;
							goto end_IL_199f;
						case 242:
							num5 = 31 + 122;
							num3 = 285;
							continue;
						case 293:
							num6 = 92 + 70;
							num3 = 193;
							continue;
						case 311:
							array3[30] = (byte)num5;
							num3 = 358;
							continue;
						case 200:
							num6 = 78 + 80;
							num = 73;
							goto end_IL_199b;
						case 115:
							num6 = 163 - 54;
							num3 = 229;
							continue;
						case 340:
							array3[22] = 149;
							num = 62;
							goto end_IL_199b;
						case 304:
							array3[22] = (byte)num5;
							num = 340;
							goto end_IL_199b;
						case 137:
							num5 = 108 + 82;
							num3 = 17;
							continue;
						case 180:
							num5 = 147 - 49;
							num2 = 86;
							goto end_IL_199f;
						case 194:
							num5 = 49 + 25;
							num2 = 208;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 165;
						case 159:
							array3[1] = 156;
							num2 = 225;
							goto end_IL_199f;
						case 45:
							array6 = (byte[])cVwrbOKDbyEbFdCHm0(binaryReader, (int)cKwvb8WHTTUYvpfxcF(ObjEU8cuSR3Pq103fr(binaryReader)));
							num2 = 78;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 97;
						case 97:
							array3[29] = 43;
							num3 = 65;
							continue;
						case 90:
							num5 = 160 - 53;
							num2 = 309;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 92;
						case 154:
							num5 = 103 + 50;
							num2 = 264;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 85;
						case 109:
							num5 = 90 + 114;
							num2 = 196;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 281;
						case 281:
							num6 = 236 - 78;
							num = 243;
							goto end_IL_199b;
						case 153:
							array3[6] = 109;
							num3 = 294;
							continue;
						case 209:
							num6 = 109 + 53;
							num2 = 279;
							goto end_IL_199f;
						case 363:
							array3[14] = 181;
							num2 = 178;
							goto end_IL_199f;
						case 359:
							array4[6] = (byte)num6;
							num = 336;
							goto end_IL_199b;
						case 276:
							array3[7] = 165;
							num2 = 160;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 242;
						case 358:
							num5 = 201 - 67;
							num2 = 268;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 309;
						case 309:
							array3[17] = (byte)num5;
							num2 = 31;
							goto end_IL_199f;
						case 198:
							num6 = 62 + 57;
							num3 = 312;
							continue;
						case 321:
							array4[2] = 109;
							num3 = 101;
							continue;
						case 248:
							array3[9] = 120;
							num = 184;
							goto end_IL_199b;
						case 96:
							array3[19] = (byte)num5;
							num = 261;
							goto end_IL_199b;
						case 8:
							array3[13] = (byte)num5;
							num2 = 275;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 189;
						case 189:
							array3[18] = 108;
							num2 = 133;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 59;
						case 59:
							array4[12] = 218;
							num = 219;
							goto end_IL_199b;
						case 78:
							array3 = new byte[32];
							num = 349;
							goto end_IL_199b;
						case 285:
							array3[0] = (byte)num5;
							num2 = 166;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 257;
						case 10:
							array2 = (byte[])MC8LgDy8W7UiL8hk6M(uQQO0r3SUjRnq46pLY(lMMBBgk7HjdBcP6cPC(typeof(O7I1wwWnHSZSv6qhDj).TypeHandle).Assembly));
							num2 = 81;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 195;
						case 6:
							array4[13] = (byte)num6;
							num2 = 80;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 19;
						case 232:
							array4[5] = (byte)num6;
							num = 70;
							goto end_IL_199b;
						case 277:
							num5 = 127 - 42;
							num = 46;
							goto end_IL_199b;
						case 136:
							num5 = 133 - 117;
							num2 = 202;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 337;
						case 337:
							num6 = 125 + 61;
							num2 = 165;
							goto end_IL_199f;
						case 144:
							num6 = 44 + 105;
							num3 = 27;
							continue;
						case 37:
							num5 = 20 + 87;
							num = 367;
							goto end_IL_199b;
						case 259:
							array5 = array3;
							num = 326;
							goto end_IL_199b;
						case 278:
							num5 = 245 - 81;
							num2 = 329;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 47;
						case 47:
							array3[1] = (byte)num5;
							num2 = 176;
							goto end_IL_199f;
						case 141:
							transform = (ICryptoTransform)SLNMtHm3xFq7pUcd2o(rijndaelManaged, array5, array);
							num = 313;
							goto end_IL_199b;
						case 16:
							array4[8] = (byte)num6;
							num = 95;
							goto end_IL_199b;
						case 336:
							num6 = 174 - 58;
							num2 = 100;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 1;
						case 1:
							array3[29] = 166;
							num = 103;
							goto end_IL_199b;
						case 330:
							array4[1] = (byte)num6;
							num2 = 321;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 191;
						case 191:
							array3[10] = (byte)num5;
							num = 175;
							goto end_IL_199b;
						case 297:
							array3[25] = 118;
							num2 = 109;
							goto end_IL_199f;
						case 50:
							num6 = 32 + 58;
							num2 = 240;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 216;
						case 216:
							array4[10] = (byte)num6;
							num = 22;
							goto end_IL_199b;
						case 84:
							if (XknFxIHa8.Length != 0)
							{
								goto case 238;
							}
							num2 = 77;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 167;
						case 167:
							array3[0] = (byte)num5;
							num3 = 159;
							continue;
						case 70:
							num6 = 132 - 44;
							num = 323;
							goto end_IL_199b;
						case 318:
							array4[4] = (byte)num6;
							num2 = 115;
							goto end_IL_199f;
						case 35:
							num5 = 164 - 54;
							num3 = 347;
							continue;
						case 280:
							num5 = 76 + 64;
							num2 = 260;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 290;
						case 290:
							num5 = 196 - 65;
							num2 = 283;
							goto end_IL_199f;
						case 22:
							array4[10] = 49;
							num3 = 7;
							continue;
						case 247:
							array4[1] = 168;
							num2 = 144;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 25;
						case 25:
							array3[24] = 135;
							num3 = 179;
							continue;
						case 34:
							num5 = 190 - 63;
							num3 = 148;
							continue;
						case 133:
							num5 = 246 - 82;
							num = 53;
							goto end_IL_199b;
						case 0:
							array3[22] = (byte)num5;
							num2 = 124;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 113;
						case 113:
							num5 = 120 + 85;
							num2 = 135;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 356;
						case 356:
							array = array4;
							num3 = 10;
							continue;
						case 243:
							array4[0] = (byte)num6;
							num3 = 83;
							continue;
						case 237:
							num5 = 116 + 52;
							num2 = 20;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 126;
						case 126:
							num6 = 225 - 75;
							num = 228;
							goto end_IL_199b;
						case 63:
							array3[23] = (byte)num5;
							num = 310;
							goto end_IL_199b;
						case 24:
							array3[24] = 112;
							num3 = 25;
							continue;
						case 333:
							num5 = 66 + 94;
							num3 = 167;
							continue;
						case 349:
							array3[0] = 134;
							num3 = 140;
							continue;
						case 165:
							array4[14] = (byte)num6;
							num3 = 14;
							continue;
						case 76:
							num5 = 97 + 11;
							num2 = 295;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 211;
						case 211:
							array4[4] = 77;
							num = 92;
							goto end_IL_199b;
						case 32:
							array4[9] = 145;
							num3 = 245;
							continue;
						case 182:
							array4[11] = (byte)num6;
							num3 = 3;
							continue;
						case 341:
							array4[8] = (byte)num6;
							num = 360;
							goto end_IL_199b;
						case 357:
							array3[0] = (byte)num5;
							num2 = 242;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 279;
						case 279:
							array4[12] = (byte)num6;
							num2 = 214;
							goto end_IL_199f;
						case 92:
							array4[5] = 155;
							num2 = 200;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 306;
						case 306:
							num6 = 106 + 116;
							num3 = 365;
							continue;
						case 52:
							array3[19] = (byte)num5;
							num = 213;
							goto end_IL_199b;
						case 17:
							array3[26] = (byte)num5;
							num = 180;
							goto end_IL_199b;
						case 40:
							num6 = 5 + 25;
							num = 93;
							goto end_IL_199b;
						case 208:
							array3[21] = (byte)num5;
							num = 66;
							goto end_IL_199b;
						case 13:
							array3[21] = (byte)num5;
							num = 26;
							goto end_IL_199b;
						case 28:
							num6 = 178 + 16;
							num3 = 359;
							continue;
						case 286:
							array[13] = array2[6];
							num = 257;
							goto end_IL_199b;
						case 317:
							num6 = 168 - 56;
							num2 = 345;
							goto end_IL_199f;
						case 130:
							array3[28] = (byte)num5;
							num2 = 64;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 223;
						case 258:
							array3[3] = 92;
							num3 = 300;
							continue;
						case 114:
							array3[2] = (byte)num5;
							num3 = 60;
							continue;
						case 264:
							array3[20] = (byte)num5;
							num2 = 127;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 38;
						case 38:
							num5 = 231 - 112;
							num2 = 157;
							goto end_IL_199f;
						case 366:
							array[9] = array2[4];
							num3 = 111;
							continue;
						case 60:
							array3[2] = 117;
							num = 328;
							goto end_IL_199b;
						case 181:
							array4[4] = (byte)num6;
							num2 = 197;
							if (0 == 0)
							{
								goto end_IL_199f;
							}
							goto case 106;
						case 106:
							array3[18] = 134;
							num2 = 113;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 26;
						case 244:
							array3[21] = (byte)num5;
							num2 = 171;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 164;
						case 164:
							array3[20] = 104;
							num3 = 154;
							continue;
						case 323:
							array4[6] = (byte)num6;
							num2 = 317;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 123;
						case 123:
							num5 = 158 + 12;
							num2 = 19;
							if (!j97uDrTnqXaFLs4tD4())
							{
								goto end_IL_199f;
							}
							goto case 239;
						case 239:
							num5 = 238 - 79;
							num2 = 21;
							goto end_IL_199f;
						case 347:
							array3[4] = (byte)num5;
							num2 = 278;
							goto end_IL_199f;
						case 56:
							array3[11] = (byte)num5;
							num3 = 289;
							continue;
						case 49:
							num5 = 175 - 58;
							num3 = 199;
							continue;
						case 214:
							num6 = 57 + 80;
							num3 = 241;
							continue;
						case 367:
							array3[23] = (byte)num5;
							num = 364;
							goto end_IL_199b;
						case 283:
							array3[20] = (byte)num5;
							num2 = 38;
							goto end_IL_199f;
						case 218:
							array3[6] = (byte)num5;
							num = 153;
							goto end_IL_199b;
						case 29:
							num5 = 103 + 90;
							num2 = 102;
							goto end_IL_199f;
						case 261:
							num5 = 96 + 79;
							num2 = 52;
							if (TwmP5BGbkxnJDo2g8m())
							{
								goto end_IL_199f;
							}
							goto case 85;
						case 85:
							array3[3] = (byte)num5;
							num2 = 174;
							goto end_IL_199f;
						case 119:
							array3[28] = (byte)num5;
							num2 = 131;
							goto end_IL_199f;
						case 324:
							num5 = 75 + 0;
							num2 = 36;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 291;
						case 291:
							f9pUAqYq82C8MtHPBU(ObjEU8cuSR3Pq103fr(binaryReader), 0L);
							num2 = 104;
							goto end_IL_199f;
						case 274:
							array3[7] = 140;
							num3 = 276;
							continue;
						case 75:
							array3[11] = 63;
							num2 = 136;
							goto end_IL_199f;
						case 199:
							array3[24] = (byte)num5;
							num2 = 94;
							goto end_IL_199f;
						case 368:
							try
							{
								return (string)qSFpVYCfkCs77Srv9c(xRtJUtfIvPR3uRq0Qr(), XknFxIHa8, P_0 + 4, num4);
							}
							catch
							{
							}
							return "";
						case 313:
							memoryStream = new MemoryStream();
							num2 = 128;
							if (true)
							{
								goto end_IL_199f;
							}
							goto case 129;
						case 220:
							rijndaelManaged = new RijndaelManaged();
							goto case 168;
						}
						array3[13] = (byte)num5;
						num = 146;
						goto end_IL_199b;
						IL_01db:
						num6 = 207 - 69;
						num = 182;
						goto end_IL_199b;
						IL_0178:
						array4[13] = (byte)num6;
						num = 307;
						goto end_IL_199b;
						IL_007e:
						array3[31] = 95;
						num = 259;
						goto end_IL_199b;
						IL_0061:
						num5 = 151 - 50;
						num2 = 110;
						break;
						IL_0045:
						array3[17] = (byte)num5;
						num2 = 90;
						break;
						IL_0029:
						array3[23] = (byte)num5;
						num2 = 282;
						break;
						continue;
						end_IL_199f:
						break;
					}
					continue;
					end_IL_199b:
					break;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[A8IysnjaY3BunHEA6k(typeof(O7I1wwWnHSZSv6qhDj/A8IysnjaY3BunHEA6k/hWmmiKbelFZDEdrmMp<object>[]))]
		internal static string TSOj49HVn(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void irXb4UCXo(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int LPyPiQ7Lq(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr jl5Zt4Q7I(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void WwwXnHSZS()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void O6qdhDjaj()
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
		internal static object GImxkR1v4(object P_0)
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
		public static extern IntPtr i4IoD9WS7(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr gIy4snaY3(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int HunMHEA6k(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int hWmcmiKel(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int EZD0EdrmM(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr MNVl7OEge(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int FS8u9Mm6I(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[A8IysnjaY3BunHEA6k(typeof(O7I1wwWnHSZSv6qhDj/A8IysnjaY3BunHEA6k/hWmmiKbelFZDEdrmMp<object>[]))]
		private static byte[] xp3NoJYrC(string P_0)
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
		[A8IysnjaY3BunHEA6k(typeof(O7I1wwWnHSZSv6qhDj/A8IysnjaY3BunHEA6k/hWmmiKbelFZDEdrmMp<object>[]))]
		private static byte[] Q4Xk42Ngr(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				106, 135, 130, 187, 71, 231, 120, 82, 148, 1,
				50, 208, 21, 179, 237, 34, 209, 200, 25, 70,
				53, 38, 10, 202, 99, 45, 248, 111, 213, 5,
				111, 2
			};
			rijndael.IV = new byte[16]
			{
				60, 32, 113, 247, 181, 153, 58, 56, 210, 6,
				47, 198, 219, 29, 129, 124
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] RLCmNBNAu()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] RusRPamDZ()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] yFLHCV5AP()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] aZJtqSG0V()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] SDUahBIai()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] oO2DwXPlI()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] NsuyQeslK()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] ri274OZc7()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] ae8gM4Kdi()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] wamIRx2Sg()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public O7I1wwWnHSZSv6qhDj()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type lMMBBgk7HjdBcP6cPC(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object r17QDouXXkVNkXBW2n(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object ObjEU8cuSR3Pq103fr(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void f9pUAqYq82C8MtHPBU(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Wi0ww8Agm0EdWok7py(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long cKwvb8WHTTUYvpfxcF(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object cVwrbOKDbyEbFdCHm0(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object uQQO0r3SUjRnq46pLY(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object MC8LgDy8W7UiL8hk6M(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void R4Sm4CFEtLmivO7T0e(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object SLNMtHm3xFq7pUcd2o(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void HqpfDmMsX5JJimIFqW(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void TC0tegjkUe4waBCRyv(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Wtl2A1wgFppR5xoQtN(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Yaac44v5cRG4qtd8AK(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void FjwcwMI6HcJ89yRsSW(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int hFTJKtgA47BQJDFqcw(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object xRtJUtfIvPR3uRq0Qr()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object qSFpVYCfkCs77Srv9c(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool TwmP5BGbkxnJDo2g8m()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool j97uDrTnqXaFLs4tD4()
		{
			return false;
		}
	}
}
namespace IHamRx42Sgxdaarhoa
{
	internal class rKli24oOZc79e8M4Kd
	{
		private static bool A8v1j3BOg;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void sjnYRGUzF0vNu()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public rKli24oOZc79e8M4Kd()
		{
		}
	}
}
