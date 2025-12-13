using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Security.Permissions;
using System.Text;
using Microsoft.Win32;
using Mnnne7XnwnG0lVHwNr;
using chcUovt9AW8NKquJTR;

[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: ComVisible(true)]
[assembly: Guid("21ffdbba-f498-4241-b578-786942924228")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyTitle("Cummins.CNL.Constants")]
[assembly: AssemblyDescription("Cummins .NET Libraries Constants Component")]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyProduct("INSITE")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace V050VjcZl5jSYcaVHO
{
	internal static class eT5QxuEsc3Y008fKvb
	{
	}
}
namespace Cummins.INSITE.CNL.Common
{
	public enum ComponentIds
	{
		[StringValue("{052113AD-8285-4E41-83FA-66B61C7458DF}")]
		ConnectionManagerWorker,
		[StringValue("{E0CCF1FC-6E3A-11D4-94A0-005004295E31}")]
		PrefDispUI,
		[StringValue("{EC013572-3CEC-423A-8E6B-B9A6A0DADB6F}")]
		ToolSecurity
	}
	public enum EventIDs
	{
		[StringValue("{2EA12243-B169-4fd7-A8DF-AB5CA9A22701}")]
		ECMTestEvents,
		[StringValue("{5CD1DEEB-ABBE-439F-BB98-1D2B501FC42C}")]
		ECMTestInstructionEvents,
		[StringValue("{66619C53-965C-412A-A5F5-C4ED463E214A}")]
		ECMTestPageButtonEvents,
		[StringValue("{8E5C6E59-E230-41d2-AF46-9936250C796B}")]
		ConnectionEvents,
		[StringValue("{AF1FBD55-1C0C-4c25-B426-ECFF245CB956}")]
		ConnectionLostEvents,
		[StringValue("{DD9F8B57-6CC2-421e-A507-06FB388FB059}")]
		MonitorEvents,
		[StringValue("{C878DEBC-E3C0-4e23-8A80-56E4BA9FB918}")]
		ConManEventForFnP,
		[StringValue("{14542E65-7845-11D4-94AA-005004295E31}")]
		PrefDispEvents,
		[StringValue("{16729E6A-E81C-4AF0-8CD0-BD0B05017D57}")]
		ToolSecurityEvents
	}
	public abstract class DisposableObject : IDisposable
	{
		private object j2UQY5cJn;

		private bool NPbEojwRx;

		protected bool Disposed
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				lock (j2UQY5cJn)
				{
					return NPbEojwRx;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DisposableObject()
		{
			sZ21ktMl2GQIQHFGOV.tyPEtxJz63naO();
			base..ctor();
			j2UQY5cJn = new object();
			NPbEojwRx = false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		~DisposableObject()
		{
			Cleanup();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void Cleanup()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IDisposable.Dispose()
		{
			lock (j2UQY5cJn)
			{
				if (!NPbEojwRx)
				{
					Cleanup();
					NPbEojwRx = true;
					GC.SuppressFinalize(this);
				}
			}
		}
	}
}
namespace Cummins.INSITE.CNL.Common.Files
{
	public interface IFileReader
	{
		bool Exists(string filename);

		string GetContents(string filename);
	}
}
namespace Cummins.INSITE.CNL.Common.Registry
{
	public interface ILocalMachineRegistryReader
	{
		string ReadValue(string keyName, string valueName);
	}
}
namespace Cummins.INSITE.CNL.Common
{
	public static class TokenConstants
	{
		public static readonly string SystemType;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static TokenConstants()
		{
			sZ21ktMl2GQIQHFGOV.tyPEtxJz63naO();
			SystemType = DFgJQeHXspABPxPPUq.PxPsPUqnn(0);
		}
	}
	public static class StringConstants
	{
		public static readonly string FaultCodeSelectionIdPrefix;

		public static readonly string DefaultErrorXMLString;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static StringConstants()
		{
			sZ21ktMl2GQIQHFGOV.tyPEtxJz63naO();
			FaultCodeSelectionIdPrefix = DFgJQeHXspABPxPPUq.PxPsPUqnn(16);
			DefaultErrorXMLString = DFgJQeHXspABPxPPUq.PxPsPUqnn(24);
		}
	}
}
namespace Cummins.INSITE.CNL.Common.Files
{
	public class FileReader : IFileReader
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool Exists(string filename)
		{
			return File.Exists(filename);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetContents(string filename)
		{
			using FileStream stream = new FileStream(filename, FileMode.Open);
			using StreamReader streamReader = new StreamReader(stream);
			return streamReader.ReadToEnd();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FileReader()
		{
			sZ21ktMl2GQIQHFGOV.tyPEtxJz63naO();
			base..ctor();
		}
	}
}
namespace Cummins.INSITE.CNL.Common.Registry
{
	public class LocalMachineRegistryReader : ILocalMachineRegistryReader
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public string ReadValue(string keyName, string valueName)
		{
			RegistryKey registryKey = null;
			RegistryKey registryKey2 = null;
			try
			{
				registryKey = Microsoft.Win32.Registry.LocalMachine;
				registryKey2 = registryKey.OpenSubKey(keyName);
				string result = (string)registryKey2.GetValue(valueName);
				registryKey2.Close();
				registryKey.Close();
				return result;
			}
			finally
			{
				registryKey?.Close();
				registryKey2?.Close();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public LocalMachineRegistryReader()
		{
			sZ21ktMl2GQIQHFGOV.tyPEtxJz63naO();
			base..ctor();
		}
	}
}
namespace Cummins.INSITE.CNL.Common
{
	public static class EnumUtils
	{
		private static Dictionary<Enum, string> zyTc5Qxus;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string GetStringValue(Enum value)
		{
			if (zyTc5Qxus.ContainsKey(value))
			{
				return zyTc5Qxus[value];
			}
			FieldInfo field = value.GetType().GetField(value.ToString());
			StringValueAttribute[] array = (StringValueAttribute[])field.GetCustomAttributes(typeof(StringValueAttribute), inherit: false);
			if (array.Length > 0)
			{
				zyTc5Qxus.Add(value, array[0].Value);
				return zyTc5Qxus[value];
			}
			zyTc5Qxus.Add(value, value.ToString());
			return zyTc5Qxus[value];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static EnumUtils()
		{
			sZ21ktMl2GQIQHFGOV.tyPEtxJz63naO();
			zyTc5Qxus = new Dictionary<Enum, string>();
		}
	}
	public class StringValueAttribute : Attribute
	{
		private string c3Y9008fK;

		public string Value
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return c3Y9008fK;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public StringValueAttribute(string value)
		{
			sZ21ktMl2GQIQHFGOV.tyPEtxJz63naO();
			base..ctor();
			c3Y9008fK = value;
		}
	}
	public static class DllImports
	{
		[DllImport("user32.dll", EntryPoint = "SetParent")]
		private static extern IntPtr kbSy050Vj(IntPtr P_0, IntPtr P_1);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SecurityPermission(SecurityAction.Assert, UnmanagedCode = true)]
		public static IntPtr SetParent(IntPtr hWndChild, IntPtr hWndNewParent)
		{
			return kbSy050Vj(hWndChild, hWndNewParent);
		}

		[DllImport("user32.dll", EntryPoint = "GetWindowLong")]
		private static extern IntPtr ol5HjSYca(IntPtr P_0, int P_1);

		[DllImport("user32.dll", EntryPoint = "GetWindowLongPtr")]
		private static extern IntPtr aHOXNxEVd(IntPtr P_0, int P_1);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SecurityPermission(SecurityAction.Assert, UnmanagedCode = true)]
		public static IntPtr GetWindowLongPtr(IntPtr hWnd, int nIndex)
		{
			if (IntPtr.Size == 8)
			{
				return aHOXNxEVd(hWnd, nIndex);
			}
			return ol5HjSYca(hWnd, nIndex);
		}

		[DllImport("user32.dll", EntryPoint = "SetWindowLong")]
		private static extern int qmU4Ai3nb(IntPtr P_0, int P_1, int P_2);

		[DllImport("user32.dll", EntryPoint = "SetWindowLongPtr")]
		private static extern IntPtr LUJqYhUVV(IntPtr P_0, int P_1, IntPtr P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SecurityPermission(SecurityAction.Assert, UnmanagedCode = true)]
		public static IntPtr SetWindowLongPtr(IntPtr hWnd, int nIndex, IntPtr dwNewLong)
		{
			if (IntPtr.Size == 8)
			{
				return LUJqYhUVV(hWnd, nIndex, dwNewLong);
			}
			return new IntPtr(qmU4Ai3nb(hWnd, nIndex, dwNewLong.ToInt32()));
		}

		[DllImport("user32.dll", EntryPoint = "ShowWindow")]
		private static extern bool twNBmGB8V(IntPtr P_0, uint P_1);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SecurityPermission(SecurityAction.Assert, UnmanagedCode = true)]
		public static bool ShowWindow(IntPtr hWnd, uint nCmdShow)
		{
			return twNBmGB8V(hWnd, nCmdShow);
		}

		[DllImport("user32.dll", EntryPoint = "MoveWindow")]
		private static extern bool eZSeEZ6Fg(IntPtr P_0, int P_1, int P_2, int P_3, int P_4, bool P_5);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SecurityPermission(SecurityAction.Assert, UnmanagedCode = true)]
		public static bool MoveWindow(IntPtr hWnd, int X, int Y, int nWidth, int nHeight, bool bRepaint)
		{
			return eZSeEZ6Fg(hWnd, X, Y, nWidth, nHeight, bRepaint);
		}
	}
	public enum GWL
	{
		GWL_WNDPROC = -4,
		GWL_HINSTANCE = -6,
		GWL_HWNDPARENT = -8,
		GWL_STYLE = -16,
		GWL_EXSTYLE = -20,
		GWL_USERDATA = -21,
		GWL_ID = -12
	}
}
internal class <Module>{F5A32B74-3405-4C9D-AC07-ED3A81045546}
{
}
namespace CUVVCwyNmGB8VyZSEZ
{
	internal class yxEVd19mUAi3nb7UJY
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module XQevXspAB;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void oCaEtxJJKFYKs(int typemdt)
		{
			Type type = XQevXspAB.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)XQevXspAB.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public yxEVd19mUAi3nb7UJY()
		{
			sZ21ktMl2GQIQHFGOV.tyPEtxJz63naO();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static yxEVd19mUAi3nb7UJY()
		{
			sZ21ktMl2GQIQHFGOV.tyPEtxJz63naO();
			XQevXspAB = typeof(yxEVd19mUAi3nb7UJY).Assembly.ManifestModule;
		}
	}
}
namespace Mnnne7XnwnG0lVHwNr
{
	internal class DFgJQeHXspABPxPPUq
	{
		internal class XOUiAM4rqHfQcBLtSy : Attribute
		{
			internal class gvZ5OHqHsruWEdqb3p<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public gvZ5OHqHsruWEdqb3p()
				{
					sZ21ktMl2GQIQHFGOV.tyPEtxJz63naO();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[XOUiAM4rqHfQcBLtSy(typeof(DFgJQeHXspABPxPPUq/XOUiAM4rqHfQcBLtSy/gvZ5OHqHsruWEdqb3p<object>[]))]
			public XOUiAM4rqHfQcBLtSy(object P_0)
			{
				sZ21ktMl2GQIQHFGOV.tyPEtxJz63naO();
				base..ctor();
			}
		}

		internal class ViHWhuBsgT4Mg1DXIg
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[XOUiAM4rqHfQcBLtSy(typeof(DFgJQeHXspABPxPPUq/XOUiAM4rqHfQcBLtSy/gvZ5OHqHsruWEdqb3p<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (x6czTOnpi(Convert.ToBase64String(typeof(DFgJQeHXspABPxPPUq).Assembly.GetName().GetPublicKeyToken()), DFgJQeHXspABPxPPUq.PxPsPUqnn(338)) != DFgJQeHXspABPxPPUq.PxPsPUqnn(344))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[XOUiAM4rqHfQcBLtSy(typeof(DFgJQeHXspABPxPPUq/XOUiAM4rqHfQcBLtSy/gvZ5OHqHsruWEdqb3p<object>[]))]
			internal static string x6czTOnpi(string P_0, string P_1)
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
			public ViHWhuBsgT4Mg1DXIg()
			{
				sZ21ktMl2GQIQHFGOV.tyPEtxJz63naO();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint tPve08e0gPbHxcnSf4([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr NHbeauvEqeXgHup5eT();

		internal struct HIEx1Nsp2x64fJmAeB
		{
			internal bool z0GQVbuQ4b;

			internal byte[] VSKQQgpwWF;
		}

		[Flags]
		private enum OQOjnL5jS6PjHTfPnY
		{

		}

		private static IntPtr D9ZxXEyMM;

		private static SortedList EWHfxall8;

		private static int RBd2rkb9p;

		internal static tPve08e0gPbHxcnSf4 geFkPlr9P;

		private static int agjS56nLk;

		internal static Hashtable KOl3Vj4WT;

		private static byte[] aAWaxgjm4;

		private static byte[] P4mIR4UFI;

		private static byte[] o1s0ki5St;

		private static int mRmO8anpF;

		private static bool UOBAZYGHJ;

		private static bool q0jPDHhsO;

		private static long Fd8L3NBhH;

		private static byte[] uscjTUe1y;

		private static long sIAWj9uwO;

		private static IntPtr N3gJY3QKx;

		private static int BvtlPePdV;

		private static IntPtr jwV7YnPcK;

		internal static tPve08e0gPbHxcnSf4 uQeUSV6c8;

		private static int[] WpFKAoU9w;

		private static object hNDns3CGg;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static DFgJQeHXspABPxPPUq()
		{
			P4mIR4UFI = new byte[0];
			aAWaxgjm4 = new byte[0];
			o1s0ki5St = new byte[0];
			uscjTUe1y = new byte[0];
			jwV7YnPcK = IntPtr.Zero;
			D9ZxXEyMM = IntPtr.Zero;
			hNDns3CGg = new string[0];
			WpFKAoU9w = new int[0];
			BvtlPePdV = 1;
			q0jPDHhsO = false;
			EWHfxall8 = new SortedList();
			RBd2rkb9p = 0;
			Fd8L3NBhH = 0L;
			uQeUSV6c8 = null;
			geFkPlr9P = null;
			sIAWj9uwO = 0L;
			agjS56nLk = 0;
			UOBAZYGHJ = false;
			mRmO8anpF = 0;
			N3gJY3QKx = IntPtr.Zero;
			KOl3Vj4WT = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Hx5EtxJIvgJYn()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[XOUiAM4rqHfQcBLtSy(typeof(DFgJQeHXspABPxPPUq/XOUiAM4rqHfQcBLtSy/gvZ5OHqHsruWEdqb3p<object>[]))]
		static string PxPsPUqnn(int P_0)
		{
			int num = 305;
			if (SwrLBHZf0CVXxyb11Y())
			{
				goto IL_001a;
			}
			goto IL_0cd3;
			IL_001a:
			byte[] array = default(byte[]);
			int num2 = default(int);
			array[5] = (byte)num2;
			int num3 = 267;
			goto IL_0ccf;
			IL_0ccf:
			num = num3;
			goto IL_0cd3;
			IL_0cd3:
			byte[] array2 = default(byte[]);
			int num6 = default(int);
			CryptoStream cryptoStream = default(CryptoStream);
			byte[] array6 = default(byte[]);
			MemoryStream memoryStream = default(MemoryStream);
			byte[] array3 = default(byte[]);
			byte[] array4 = default(byte[]);
			int num5 = default(int);
			byte[] array5 = default(byte[]);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			BinaryReader binaryReader = default(BinaryReader);
			ICryptoTransform transform = default(ICryptoTransform);
			while (true)
			{
				IL_0cd3_2:
				int num4 = num;
				while (true)
				{
					switch (num4)
					{
					case 140:
						break;
					case 246:
						goto IL_0032;
					case 275:
						num2 = 151 - 43;
						num = 209;
						if (0 == 0)
						{
							goto IL_0cd3_2;
						}
						goto case 336;
					case 336:
						array2[7] = (byte)num6;
						num4 = 194;
						continue;
					case 259:
						goto IL_0081;
					case 51:
						array[0] = 90;
						_ = 1;
						if (!SwrLBHZf0CVXxyb11Y())
						{
							goto IL_00b9;
						}
						num = 186;
						if (true)
						{
							goto IL_0cd3_2;
						}
						goto case 60;
					case 294:
						array2[1] = 157;
						num = 266;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 335;
					case 335:
						array[1] = (byte)num2;
						num = 145;
						if (!SwrLBHZf0CVXxyb11Y())
						{
							goto IL_0cd3_2;
						}
						goto case 238;
					case 238:
						num2 = 94 + 101;
						num4 = 268;
						continue;
					case 2:
						num6 = 9 + 69;
						num = 336;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 326;
					case 326:
						array[7] = 47;
						num = 198;
						if (true)
						{
							goto IL_0cd3_2;
						}
						goto case 161;
					case 161:
						c5OmBJr38lTEtu3Eir(cryptoStream, array6, 0, array6.Length);
						num4 = 344;
						continue;
					case 360:
						o1s0ki5St = (byte[])FvWlSwbr8KfNF7yV42(memoryStream);
						num4 = 346;
						continue;
					case 4:
						num2 = 200 - 66;
						num4 = 259;
						continue;
					case 319:
						array2[11] = 195;
						num4 = 130;
						continue;
					case 130:
						goto IL_01d2;
					case 301:
						array2[15] = (byte)num6;
						num = 290;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 350;
					case 232:
						array2[22] = 202;
						num3 = 133;
						goto IL_0ccf;
					case 80:
						array2[15] = 166;
						num = 68;
						goto IL_0cd3_2;
					case 338:
						num6 = 44 + 99;
						num = 82;
						if (true)
						{
							goto IL_0cd3_2;
						}
						goto case 213;
					case 213:
						array2[16] = 126;
						num3 = 105;
						goto IL_0ccf;
					case 325:
						num6 = 38 + 100;
						num = 236;
						if (0 == 0)
						{
							goto IL_0cd3_2;
						}
						goto case 148;
					case 148:
						num6 = 175 + 40;
						num = 283;
						goto IL_0cd3_2;
					case 220:
						array2[25] = (byte)num6;
						num4 = 264;
						continue;
					case 127:
						array2[20] = 186;
						num4 = 12;
						continue;
					case 314:
						num6 = 156 - 52;
						num = 120;
						goto IL_0cd3_2;
					case 270:
						num6 = 26 + 7;
						num4 = 190;
						continue;
					case 321:
						array2[0] = 88;
						num = 158;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 112;
					case 112:
						array3[9] = array4[4];
						num = 101;
						if (!SwrLBHZf0CVXxyb11Y())
						{
							goto IL_0cd3_2;
						}
						goto case 65;
					case 85:
						array2[12] = (byte)num6;
						num3 = 59;
						goto IL_0ccf;
					case 106:
						num6 = 166 - 108;
						num3 = 217;
						goto IL_0ccf;
					case 138:
						array2[23] = (byte)num6;
						num4 = 216;
						continue;
					case 266:
						array2[1] = 132;
						num4 = 250;
						continue;
					case 288:
						array2[23] = (byte)num6;
						num = 94;
						goto IL_0cd3_2;
					case 160:
						array2[1] = (byte)num6;
						num = 79;
						if (true)
						{
							goto IL_0cd3_2;
						}
						goto case 61;
					case 61:
						array2[3] = (byte)num6;
						num = 84;
						goto IL_0cd3_2;
					case 27:
						num6 = 22 + 12;
						num = 288;
						if (true)
						{
							goto IL_0cd3_2;
						}
						goto case 346;
					case 346:
						nhMsqrqmNmjut2qt5H(memoryStream);
						num3 = 67;
						goto IL_0ccf;
					case 210:
						array[14] = (byte)num2;
						num3 = 342;
						goto IL_0ccf;
					case 285:
						num6 = 5 + 24;
						num4 = 15;
						continue;
					case 284:
						num6 = 173 - 57;
						num4 = 139;
						continue;
					case 110:
						num5 = tv7SSeImIpHxLGAUR4(o1s0ki5St, P_0);
						num = 361;
						if (true)
						{
							goto IL_0cd3_2;
						}
						goto case 41;
					case 41:
						array[6] = 194;
						num3 = 136;
						goto IL_0ccf;
					case 153:
						array2[14] = (byte)num6;
						num3 = 36;
						goto IL_0ccf;
					case 146:
						num2 = 16 + 34;
						num = 207;
						if (true)
						{
							goto IL_0cd3_2;
						}
						goto case 163;
					case 163:
						num6 = 13 + 72;
						num4 = 122;
						continue;
					case 341:
						array5 = array2;
						num4 = 351;
						continue;
					case 311:
						array2[30] = (byte)num6;
						num4 = 152;
						continue;
					case 219:
						num6 = 218 - 72;
						num = 299;
						goto IL_0cd3_2;
					case 271:
						array[2] = 62;
						num3 = 201;
						goto IL_0ccf;
					case 58:
						array[11] = 125;
						num = 265;
						goto IL_0cd3_2;
					case 218:
						array2[7] = (byte)num6;
						num = 2;
						if (0 == 0)
						{
							goto IL_0cd3_2;
						}
						goto case 245;
					case 245:
						array2[14] = (byte)num6;
						num = 70;
						goto IL_0cd3_2;
					case 185:
						num6 = 121 + 53;
						num3 = 81;
						goto IL_0ccf;
					case 39:
						num6 = 166 - 55;
						num3 = 187;
						goto IL_0ccf;
					case 135:
						array[6] = (byte)num2;
						num4 = 4;
						continue;
					case 9:
						array2[28] = 161;
						num = 338;
						goto IL_0cd3_2;
					case 171:
						num6 = 207 - 69;
						num = 343;
						if (true)
						{
							goto IL_0cd3_2;
						}
						goto case 223;
					case 223:
						num2 = 134 - 44;
						num = 210;
						if (true)
						{
							goto IL_0cd3_2;
						}
						goto case 212;
					case 65:
						array2[29] = 5;
						num = 243;
						goto IL_0cd3_2;
					case 141:
						array[7] = 114;
						num4 = 29;
						continue;
					case 304:
						array2[2] = 34;
						num3 = 108;
						goto IL_0ccf;
					case 205:
						num6 = 202 - 67;
						num = 220;
						if (!SwrLBHZf0CVXxyb11Y())
						{
							goto IL_0cd3_2;
						}
						goto case 306;
					case 306:
						array2[13] = (byte)num6;
						num = 289;
						goto IL_0cd3_2;
					case 123:
						array2[8] = 35;
						num4 = 43;
						continue;
					case 38:
						array[14] = (byte)num2;
						num = 223;
						goto IL_0cd3_2;
					case 330:
						array2[10] = (byte)num6;
						num = 144;
						goto IL_0cd3_2;
					case 150:
						array2[4] = (byte)num6;
						num4 = 296;
						continue;
					case 92:
						num6 = 22 + 40;
						num3 = 193;
						goto IL_0ccf;
					case 87:
						array3[1] = array4[0];
						num3 = 128;
						goto IL_0ccf;
					case 175:
						array2[6] = 55;
						num = 148;
						if (0 == 0)
						{
							goto IL_0cd3_2;
						}
						goto case 173;
					case 173:
						num6 = 126 - 42;
						num = 300;
						if (true)
						{
							goto IL_0cd3_2;
						}
						goto case 95;
					case 95:
						num6 = 123 + 58;
						num3 = 177;
						goto IL_0ccf;
					case 189:
						array[5] = (byte)num2;
						num = 45;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 159;
					case 159:
						array[6] = (byte)num2;
						num3 = 143;
						goto IL_0ccf;
					case 101:
						array3[11] = array4[5];
						num3 = 253;
						goto IL_0ccf;
					case 144:
						array2[10] = 167;
						num = 49;
						if (0 == 0)
						{
							goto IL_0cd3_2;
						}
						goto case 242;
					case 242:
						array4 = (byte[])U8AkgGn1Gdgoe8QErY(Cd0aY9daoyeYLOFeC3(KykF6uuxvVpBrV0e2L(typeof(DFgJQeHXspABPxPPUq).TypeHandle).Assembly));
						num3 = 64;
						goto IL_0ccf;
					case 235:
						num6 = 28 + 11;
						num = 257;
						goto IL_0cd3_2;
					case 83:
						array2[17] = (byte)num6;
						num = 106;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 155;
					case 155:
						array2[22] = (byte)num6;
						num = 232;
						goto IL_0cd3_2;
					case 116:
						array[15] = (byte)num2;
						num = 6;
						goto IL_0cd3_2;
					case 5:
						num2 = 191 + 6;
						num = 115;
						if (true)
						{
							goto IL_0cd3_2;
						}
						goto case 227;
					case 227:
						array2[3] = (byte)num6;
						num4 = 269;
						continue;
					case 264:
						num6 = 150 - 35;
						num3 = 348;
						goto IL_0ccf;
					case 29:
						array[7] = 132;
						num3 = 326;
						goto IL_0ccf;
					case 152:
						num6 = 150 - 50;
						num = 214;
						if (true)
						{
							goto IL_0cd3_2;
						}
						goto case 183;
					case 183:
						array[13] = 151;
						num4 = 231;
						continue;
					case 23:
						num6 = 159 - 47;
						num = 249;
						if (!SwrLBHZf0CVXxyb11Y())
						{
							goto IL_0cd3_2;
						}
						goto case 322;
					case 257:
						array2[19] = (byte)num6;
						num4 = 119;
						continue;
					case 202:
						num2 = 75 + 93;
						num = 162;
						if (!SwrLBHZf0CVXxyb11Y())
						{
							goto IL_0cd3_2;
						}
						goto case 10;
					case 10:
						array2[11] = (byte)num6;
						num = 347;
						goto IL_0cd3_2;
					case 76:
						array2[18] = 116;
						num3 = 235;
						goto IL_0ccf;
					case 89:
					case 229:
						num2 = 19 + 2;
						num3 = 349;
						goto IL_0ccf;
					case 316:
						fv7ME6lqcnS3rTuY48(rijndaelManaged, CipherMode.CBC);
						num = 20;
						goto IL_0cd3_2;
					case 332:
						array2[26] = 78;
						num4 = 118;
						continue;
					case 273:
						array2[5] = (byte)num6;
						num4 = 309;
						continue;
					case 111:
						array[3] = 89;
						num3 = 167;
						goto IL_0ccf;
					case 222:
						num6 = 57 + 52;
						num = 37;
						if (!SwrLBHZf0CVXxyb11Y())
						{
							goto IL_0cd3_2;
						}
						goto IL_0032;
					case 50:
						array2[11] = (byte)num6;
						num3 = 24;
						goto IL_0ccf;
					case 114:
						array2[0] = 120;
						num4 = 321;
						continue;
					case 255:
						num6 = 163 - 54;
						num3 = 107;
						goto IL_0ccf;
					case 290:
						array2[16] = 208;
						num4 = 318;
						continue;
					case 3:
						num2 = 74 + 79;
						num = 240;
						goto IL_0cd3_2;
					case 132:
						array2[18] = (byte)num6;
						num3 = 334;
						goto IL_0ccf;
					case 98:
						array2[31] = 113;
						num4 = 285;
						continue;
					case 313:
						num2 = 173 - 76;
						num4 = 251;
						continue;
					case 262:
						array6 = (byte[])obOxViHrmgERgBTnim(binaryReader, (int)NuDegVtKoeaUwWLlst(e3XyAR8NFYaojqbgdO(binaryReader)));
						num3 = 48;
						goto IL_0ccf;
					case 260:
						num6 = 239 - 79;
						num4 = 138;
						continue;
					case 208:
						array2[27] = 89;
						num = 126;
						if (0 == 0)
						{
							goto IL_0cd3_2;
						}
						goto case 137;
					case 137:
						array2[13] = (byte)num6;
						num = 176;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 71;
					case 71:
						array2[26] = (byte)num6;
						goto case 178;
					default:
						num4 = 178;
						continue;
					case 102:
						array2[23] = (byte)num6;
						num3 = 27;
						goto IL_0ccf;
					case 195:
						if (array4.Length <= 0)
						{
							goto case 322;
						}
						num4 = 87;
						continue;
					case 355:
						array2[16] = (byte)num6;
						num = 213;
						goto IL_0cd3_2;
					case 237:
						num6 = 133 + 116;
						num = 153;
						goto IL_0cd3_2;
					case 169:
						num6 = 210 + 18;
						num3 = 184;
						goto IL_0ccf;
					case 119:
						array2[19] = 86;
						num = 32;
						goto IL_0cd3_2;
					case 305:
						if (o1s0ki5St.Length == 0)
						{
							num4 = 165;
							continue;
						}
						goto case 110;
					case 353:
						array[13] = (byte)num2;
						num3 = 302;
						goto IL_0ccf;
					case 64:
						if (array4 == null)
						{
							goto case 322;
						}
						num4 = 195;
						continue;
					case 214:
						array2[30] = (byte)num6;
						num3 = 219;
						goto IL_0ccf;
					case 211:
						array2[2] = 109;
						num4 = 13;
						continue;
					case 43:
						array2[8] = 148;
						num = 325;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 48;
					case 14:
						num6 = 9 + 14;
						num = 117;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 91;
					case 91:
						num6 = 188 - 62;
						num3 = 155;
						goto IL_0ccf;
					case 164:
						array2[27] = (byte)num6;
						num = 92;
						goto IL_0cd3_2;
					case 67:
						nhMsqrqmNmjut2qt5H(cryptoStream);
						num3 = 354;
						goto IL_0ccf;
					case 243:
						num6 = 114 + 38;
						num = 311;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 247;
					case 247:
						num6 = 189 - 63;
						num3 = 102;
						goto IL_0ccf;
					case 276:
						array2[21] = (byte)num6;
						num4 = 33;
						continue;
					case 129:
						array2[3] = (byte)num6;
						num4 = 230;
						continue;
					case 225:
						num6 = 131 - 43;
						num3 = 330;
						goto IL_0ccf;
					case 269:
						num6 = 135 - 14;
						num3 = 129;
						goto IL_0ccf;
					case 166:
						array2[26] = (byte)num6;
						num = 124;
						if (true)
						{
							goto IL_0cd3_2;
						}
						goto case 35;
					case 35:
						array[15] = 91;
						num4 = 197;
						continue;
					case 350:
						array2[15] = (byte)num6;
						num3 = 80;
						goto IL_0ccf;
					case 37:
						array2[2] = (byte)num6;
						num = 304;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 163;
					case 28:
						num6 = 248 - 82;
						num3 = 85;
						goto IL_0ccf;
					case 240:
						array[5] = (byte)num2;
						num3 = 310;
						goto IL_0ccf;
					case 156:
						num2 = 215 - 114;
						num4 = 26;
						continue;
					case 265:
						num2 = 172 - 58;
						num = 1;
						goto IL_0cd3_2;
					case 329:
						array[10] = 121;
						num3 = 238;
						goto IL_0ccf;
					case 120:
						array2[13] = (byte)num6;
						num4 = 256;
						continue;
					case 278:
						array2[11] = 99;
						num3 = 317;
						goto IL_0ccf;
					case 292:
						array[9] = 98;
						num3 = 5;
						goto IL_0ccf;
					case 100:
						array2[9] = 142;
						num = 239;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 78;
					case 78:
						array[2] = (byte)num2;
						num3 = 271;
						goto IL_0ccf;
					case 121:
						array2[12] = (byte)num6;
						num = 8;
						goto IL_0cd3_2;
					case 84:
						num6 = 100 + 28;
						num4 = 227;
						continue;
					case 302:
						num2 = 152 - 50;
						num3 = 38;
						goto IL_0ccf;
					case 107:
						array2[17] = (byte)num6;
						num4 = 327;
						continue;
					case 55:
						array[4] = (byte)num2;
						num4 = 202;
						continue;
					case 206:
						array[10] = (byte)num2;
						num4 = 329;
						continue;
					case 174:
						array2[9] = (byte)num6;
						num3 = 225;
						goto IL_0ccf;
					case 221:
						num2 = 14 + 96;
						num = 88;
						if (!SwrLBHZf0CVXxyb11Y())
						{
							goto IL_0cd3_2;
						}
						goto case 258;
					case 258:
						cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
						num4 = 161;
						continue;
					case 317:
						num6 = 213 - 71;
						num = 182;
						goto IL_0cd3_2;
					case 88:
						array[4] = (byte)num2;
						num4 = 313;
						continue;
					case 254:
						array[7] = 144;
						num3 = 141;
						goto IL_0ccf;
					case 261:
						array2[7] = 148;
						num4 = 44;
						continue;
					case 30:
						array3[5] = array4[2];
						num = 320;
						goto IL_0cd3_2;
					case 165:
						binaryReader = new BinaryReader((Stream)voJhrmBV4Fn0hRxSpp(KykF6uuxvVpBrV0e2L(typeof(DFgJQeHXspABPxPPUq).TypeHandle).Assembly, "tYvjbqFLThHtZsVyeo.NqmSWYQYmjZKPTBJND"));
						num = 357;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 179;
					case 179:
						array2[15] = 106;
						num3 = 142;
						goto IL_0ccf;
					case 351:
						array = new byte[16];
						num = 312;
						if (0 == 0)
						{
							goto IL_0cd3_2;
						}
						goto case 69;
					case 69:
						num2 = 100 + 57;
						num4 = 55;
						continue;
					case 167:
						num2 = 136 - 58;
						num = 54;
						if (0 == 0)
						{
							goto IL_0cd3_2;
						}
						goto case 97;
					case 97:
						array2[29] = 118;
						num = 180;
						if (!SwrLBHZf0CVXxyb11Y())
						{
							goto IL_0cd3_2;
						}
						goto case 94;
					case 94:
						array2[23] = 92;
						num3 = 260;
						goto IL_0ccf;
					case 99:
						array[10] = (byte)num2;
						num4 = 25;
						continue;
					case 168:
						array2[19] = (byte)num6;
						num3 = 14;
						goto IL_0ccf;
					case 358:
						array[9] = (byte)num2;
						num = 103;
						goto IL_0cd3_2;
					case 199:
						array2[19] = 113;
						num3 = 340;
						goto IL_0ccf;
					case 40:
						num6 = 160 - 53;
						num = 125;
						goto IL_0cd3_2;
					case 124:
						num6 = 135 - 45;
						num = 72;
						goto IL_0cd3_2;
					case 349:
						array[1] = (byte)num2;
						num4 = 295;
						continue;
					case 298:
						array2[20] = 110;
						num3 = 127;
						goto IL_0ccf;
					case 149:
						array[15] = (byte)num2;
						num4 = 42;
						continue;
					case 327:
						array2[17] = 87;
						num = 215;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 291;
					case 54:
						array[3] = (byte)num2;
						num4 = 69;
						continue;
					case 320:
						array3[7] = array4[3];
						num4 = 112;
						continue;
					case 125:
						array2[24] = (byte)num6;
						num = 147;
						goto IL_0cd3_2;
					case 256:
						num6 = 161 - 60;
						num3 = 137;
						goto IL_0ccf;
					case 117:
						array2[20] = (byte)num6;
						num4 = 298;
						continue;
					case 186:
					case 293:
						num2 = 14 + 22;
						num4 = 99;
						continue;
					case 56:
						array2[7] = 53;
						num4 = 261;
						continue;
					case 12:
						num6 = 139 + 82;
						num4 = 17;
						continue;
					case 47:
						array2[2] = 91;
						num = 222;
						if (!SwrLBHZf0CVXxyb11Y())
						{
							goto IL_0cd3_2;
						}
						goto case 81;
					case 244:
						array2[1] = 141;
						num = 211;
						goto IL_0cd3_2;
					case 207:
						array[2] = (byte)num2;
						num = 19;
						if (true)
						{
							goto IL_0cd3_2;
						}
						goto case 184;
					case 184:
						array2[31] = (byte)num6;
						num = 341;
						if (!SwrLBHZf0CVXxyb11Y())
						{
							goto IL_0cd3_2;
						}
						goto case 156;
					case 0:
						array[12] = 111;
						num = 96;
						goto IL_0cd3_2;
					case 192:
						num2 = 195 - 65;
						num4 = 31;
						continue;
					case 188:
						array2[1] = (byte)num6;
						num4 = 244;
						continue;
					case 63:
						array2[13] = 162;
						num = 314;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 258;
					case 22:
						array[4] = 104;
						num3 = 221;
						goto IL_0ccf;
					case 277:
						num2 = 4 + 40;
						num3 = 93;
						goto IL_0ccf;
					case 73:
						array[15] = (byte)num2;
						num = 35;
						if (0 == 0)
						{
							goto IL_0cd3_2;
						}
						goto case 267;
					case 267:
						num2 = 244 - 81;
						num = 135;
						if (0 == 0)
						{
							goto IL_0cd3_2;
						}
						goto case 46;
					case 46:
						num6 = 37 + 22;
						num3 = 276;
						goto IL_0ccf;
					case 268:
						array[10] = (byte)num2;
						num = 275;
						if (true)
						{
							goto IL_0cd3_2;
						}
						goto case 1;
					case 1:
						array[11] = (byte)num2;
						num = 170;
						if (!SwrLBHZf0CVXxyb11Y())
						{
							goto IL_0cd3_2;
						}
						goto case 176;
					case 176:
						num6 = 33 + 26;
						num = 245;
						if (!SwrLBHZf0CVXxyb11Y())
						{
							goto IL_0cd3_2;
						}
						goto case 357;
					case 357:
						yoa08f7AkcmTiqvOTi(e3XyAR8NFYaojqbgdO(binaryReader), 0L);
						num3 = 307;
						goto IL_0ccf;
					case 236:
						array2[8] = (byte)num6;
						num4 = 270;
						continue;
					case 13:
						array2[2] = 89;
						num = 47;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 342;
					case 342:
						array[14] = 152;
						num = 226;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 183;
					case 209:
						array[10] = (byte)num2;
						num4 = 109;
						continue;
					case 109:
						array[11] = 108;
						num3 = 339;
						goto IL_0ccf;
					case 7:
						array2[5] = (byte)num6;
						num3 = 337;
						goto IL_0ccf;
					case 303:
						array2[11] = 121;
						num = 319;
						if (0 == 0)
						{
							goto IL_0cd3_2;
						}
						goto case 354;
					case 354:
						ajcbW8xup6fciG9SQB(binaryReader);
						num3 = 110;
						goto IL_0ccf;
					case 263:
						array[4] = 97;
						num = 22;
						goto IL_0cd3_2;
					case 6:
						num2 = 82 + 37;
						num = 149;
						if (true)
						{
							goto IL_0cd3_2;
						}
						goto case 21;
					case 21:
						array[8] = (byte)num2;
						num = 181;
						goto IL_0cd3_2;
					case 26:
						array[8] = (byte)num2;
						num4 = 16;
						continue;
					case 115:
						array[9] = (byte)num2;
						num = 77;
						if (0 == 0)
						{
							goto IL_0cd3_2;
						}
						goto case 283;
					case 283:
						array2[6] = (byte)num6;
						num = 56;
						goto IL_0cd3_2;
					case 68:
						num6 = 11 + 61;
						num = 52;
						goto IL_0cd3_2;
					case 113:
						array[8] = (byte)num2;
						num4 = 156;
						continue;
					case 339:
						num2 = 149 - 49;
						num = 151;
						if (!SwrLBHZf0CVXxyb11Y())
						{
							goto IL_0cd3_2;
						}
						goto case 131;
					case 131:
						array3[15] = array4[7];
						num = 322;
						if (!SwrLBHZf0CVXxyb11Y())
						{
							goto IL_0cd3_2;
						}
						goto case 217;
					case 217:
						array2[17] = (byte)num6;
						num = 356;
						goto IL_0cd3_2;
					case 343:
						array2[29] = (byte)num6;
						num = 65;
						if (0 == 0)
						{
							goto IL_0cd3_2;
						}
						goto case 248;
					case 248:
						array2[24] = 154;
						num3 = 40;
						goto IL_0ccf;
					case 157:
						array[6] = (byte)num2;
						num = 277;
						if (0 == 0)
						{
							goto IL_0cd3_2;
						}
						goto case 18;
					case 18:
						array2[28] = 28;
						num4 = 66;
						continue;
					case 359:
						num2 = 178 - 59;
						num3 = 308;
						goto IL_0ccf;
					case 310:
						num2 = 187 - 62;
						num = 189;
						if (0 == 0)
						{
							goto IL_0cd3_2;
						}
						goto case 300;
					case 300:
						array2[9] = (byte)num6;
						num = 100;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 262;
					case 154:
						num6 = 55 - 42;
						num = 301;
						goto IL_0cd3_2;
					case 286:
						array2[14] = 62;
						num3 = 237;
						goto IL_0ccf;
					case 181:
						array[8] = 202;
						num3 = 191;
						goto IL_0ccf;
					case 52:
						array2[15] = (byte)num6;
						num3 = 154;
						goto IL_0ccf;
					case 249:
						array2[24] = (byte)num6;
						num3 = 345;
						goto IL_0ccf;
					case 296:
						array2[5] = 129;
						num = 172;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 291;
					case 291:
						num2 = 26 + 91;
						num4 = 159;
						continue;
					case 215:
						num6 = 175 - 58;
						num4 = 83;
						continue;
					case 15:
						array2[31] = (byte)num6;
						num = 163;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 6;
					case 177:
						array2[12] = (byte)num6;
						num = 28;
						goto IL_0cd3_2;
					case 226:
						array[14] = 205;
						num = 11;
						if (true)
						{
							goto IL_0cd3_2;
						}
						goto case 162;
					case 162:
						array[4] = (byte)num2;
						num = 263;
						goto IL_0cd3_2;
					case 312:
						array[0] = 120;
						num = 233;
						if (0 == 0)
						{
							goto IL_0cd3_2;
						}
						goto case 122;
					case 122:
						array2[31] = (byte)num6;
						num3 = 39;
						goto IL_0ccf;
					case 139:
						array2[26] = (byte)num6;
						num = 332;
						if (0 == 0)
						{
							goto IL_0cd3_2;
						}
						goto case 17;
					case 17:
						array2[20] = (byte)num6;
						num4 = 272;
						continue;
					case 48:
						array2 = new byte[32];
						num = 114;
						goto IL_0cd3_2;
					case 250:
						num6 = 34 + 115;
						num = 160;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 86;
					case 34:
						array[0] = (byte)num2;
						num = 51;
						if (!SwrLBHZf0CVXxyb11Y())
						{
							goto IL_0cd3_2;
						}
						goto case 264;
					case 178:
						num6 = 187 - 62;
						num3 = 166;
						goto IL_0ccf;
					case 53:
						num2 = 79 + 87;
						num4 = 73;
						continue;
					case 281:
						array2[25] = 152;
						num4 = 205;
						continue;
					case 337:
						num6 = 174 - 58;
						num = 273;
						goto IL_0cd3_2;
					case 45:
						num2 = 166 + 14;
						num = 140;
						if (true)
						{
							goto IL_0cd3_2;
						}
						goto case 333;
					case 333:
						array2[29] = (byte)num6;
						num3 = 171;
						goto IL_0ccf;
					case 196:
						num6 = 19 + 120;
						num = 323;
						goto IL_0cd3_2;
					case 324:
						array2[4] = 79;
						num = 282;
						if (!SwrLBHZf0CVXxyb11Y())
						{
							goto IL_0cd3_2;
						}
						goto case 191;
					case 191:
						array[8] = 167;
						num = 246;
						if (0 == 0)
						{
							goto IL_0cd3_2;
						}
						goto case 318;
					case 318:
						num6 = 104 + 36;
						num = 355;
						if (0 == 0)
						{
							goto IL_0cd3_2;
						}
						goto case 307;
					case 307:
						qJr66ELHYLwWIIhRJN(true);
						num4 = 262;
						continue;
					case 228:
						array2[21] = 146;
						num = 46;
						goto IL_0cd3_2;
					case 289:
						array2[13] = 100;
						num = 63;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 87;
					case 198:
						num2 = 53 + 27;
						num3 = 21;
						goto IL_0ccf;
					case 44:
						num6 = 171 - 57;
						num = 218;
						goto IL_0cd3_2;
					case 8:
						num6 = 89 + 0;
						num = 306;
						if (true)
						{
							goto IL_0cd3_2;
						}
						goto case 193;
					case 193:
						array2[28] = (byte)num6;
						num = 9;
						goto IL_0cd3_2;
					case 200:
						num6 = 233 - 77;
						num4 = 71;
						continue;
					case 81:
						array2[24] = (byte)num6;
						num = 248;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 315;
					case 315:
						array2[23] = (byte)num6;
						num4 = 247;
						continue;
					case 230:
						array2[4] = 149;
						num = 204;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 142;
					case 32:
						array2[19] = 105;
						num4 = 196;
						continue;
					case 345:
						array2[25] = 162;
						num4 = 281;
						continue;
					case 204:
						array2[4] = 195;
						num = 324;
						goto IL_0cd3_2;
					case 253:
						array3[13] = array4[6];
						num = 131;
						if (true)
						{
							goto IL_0cd3_2;
						}
						goto case 66;
					case 66:
						num6 = 179 - 59;
						num3 = 86;
						goto IL_0ccf;
					case 77:
						array[10] = 167;
						goto case 186;
					case 60:
						num6 = 160 - 53;
						num4 = 90;
						continue;
					case 108:
						num6 = 87 + 31;
						num4 = 61;
						continue;
					case 103:
						array[9] = 142;
						num4 = 292;
						continue;
					case 42:
						array[15] = 129;
						num = 53;
						if (true)
						{
							goto IL_0cd3_2;
						}
						goto case 201;
					case 201:
						num2 = 66 + 36;
						num = 75;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 220;
					case 323:
						array2[19] = (byte)num6;
						num4 = 199;
						continue;
					case 340:
						num6 = 150 - 105;
						num3 = 168;
						goto IL_0ccf;
					case 328:
						array2[9] = 98;
						num = 280;
						goto IL_0cd3_2;
					case 75:
						array[3] = (byte)num2;
						num = 111;
						if (0 == 0)
						{
							goto IL_0cd3_2;
						}
						goto case 356;
					case 356:
						num6 = 36 + 14;
						num = 132;
						if (!SwrLBHZf0CVXxyb11Y())
						{
							goto IL_0cd3_2;
						}
						goto case 295;
					case 347:
						num6 = 143 + 51;
						num4 = 50;
						continue;
					case 104:
						array2[15] = (byte)num6;
						num4 = 179;
						continue;
					case 82:
						array2[28] = (byte)num6;
						num3 = 18;
						goto IL_0ccf;
					case 272:
						array2[21] = 119;
						num = 228;
						goto IL_0cd3_2;
					case 279:
						array2[16] = (byte)num6;
						num3 = 255;
						goto IL_0ccf;
					case 158:
						num6 = 175 + 19;
						num3 = 274;
						goto IL_0ccf;
					case 251:
						array[4] = (byte)num2;
						num = 74;
						if (!SwrLBHZf0CVXxyb11Y())
						{
							goto IL_0cd3_2;
						}
						goto case 271;
					case 297:
						num6 = 53 - 33;
						num3 = 287;
						goto IL_0ccf;
					case 287:
						array2[30] = (byte)num6;
						num3 = 98;
						goto IL_0ccf;
					case 194:
						num6 = 96 - 60;
						num3 = 62;
						goto IL_0ccf;
					case 70:
						array2[14] = 30;
						num = 286;
						goto IL_0cd3_2;
					case 145:
						array[1] = 165;
						num3 = 146;
						goto IL_0ccf;
					case 348:
						array2[25] = (byte)num6;
						num3 = 200;
						goto IL_0ccf;
					case 31:
						array[13] = (byte)num2;
						num3 = 183;
						goto IL_0ccf;
					case 118:
						array2[27] = 163;
						num3 = 208;
						goto IL_0ccf;
					case 282:
						num6 = 84 - 4;
						num = 150;
						if (!SwrLBHZf0CVXxyb11Y())
						{
							goto IL_0cd3_2;
						}
						goto case 90;
					case 90:
						array2[6] = (byte)num6;
						num4 = 175;
						continue;
					case 299:
						array2[30] = (byte)num6;
						num3 = 297;
						goto IL_0ccf;
					case 25:
						num2 = 213 - 71;
						num = 206;
						goto IL_0cd3_2;
					case 74:
						array[5] = 162;
						num4 = 3;
						continue;
					case 216:
						array2[23] = 184;
						num3 = 185;
						goto IL_0ccf;
					case 142:
						num6 = 183 - 61;
						num4 = 350;
						continue;
					case 280:
						array2[9] = 175;
						num3 = 173;
						goto IL_0ccf;
					case 234:
						array2[12] = (byte)num6;
						num = 95;
						if (yiYdHTNaBNlrUxYyyt())
						{
							goto IL_0cd3_2;
						}
						goto case 147;
					case 72:
						array2[26] = (byte)num6;
						num4 = 284;
						continue;
					case 16:
						array[9] = 149;
						num4 = 352;
						continue;
					case 79:
						num6 = 89 + 111;
						num3 = 188;
						goto IL_0ccf;
					case 190:
						array2[9] = (byte)num6;
						num3 = 328;
						goto IL_0ccf;
					case 133:
						num6 = 44 + 61;
						num3 = 315;
						goto IL_0ccf;
					case 252:
						num6 = 10 + 14;
						num3 = 333;
						goto IL_0ccf;
					case 134:
						array[13] = (byte)num2;
						num3 = 359;
						goto IL_0ccf;
					case 352:
						num2 = 126 - 42;
						num4 = 358;
						continue;
					case 59:
						num6 = 79 - 40;
						num = 121;
						goto IL_0cd3_2;
					case 203:
						array3 = array;
						num4 = 242;
						continue;
					case 24:
						num6 = 150 - 50;
						num4 = 234;
						continue;
					case 96:
						array[12] = 205;
						num4 = 57;
						continue;
					case 187:
						array2[31] = (byte)num6;
						num4 = 169;
						continue;
					case 33:
						array2[21] = 138;
						num4 = 224;
						continue;
					case 11:
						num2 = 10 + 116;
						num = 116;
						if (0 == 0)
						{
							goto IL_0cd3_2;
						}
						goto case 93;
					case 93:
						array[6] = (byte)num2;
						num4 = 41;
						continue;
					case 19:
						num2 = 78 + 89;
						num4 = 78;
						continue;
					case 170:
						array[12] = 166;
						num4 = 0;
						continue;
					case 331:
						num6 = 214 - 71;
						num3 = 241;
						goto IL_0ccf;
					case 172:
						num6 = 148 - 49;
						num4 = 7;
						continue;
					case 197:
						array[15] = 34;
						num = 203;
						if (!SwrLBHZf0CVXxyb11Y())
						{
							goto IL_0cd3_2;
						}
						goto case 49;
					case 49:
						array2[10] = 131;
						num4 = 278;
						continue;
					case 105:
						num6 = 116 - 73;
						num4 = 279;
						continue;
					case 295:
						num2 = 83 + 105;
						num = 335;
						if (0 == 0)
						{
							goto IL_0cd3_2;
						}
						goto case 147;
					case 147:
						array2[24] = 113;
						num = 23;
						if (!SwrLBHZf0CVXxyb11Y())
						{
							goto IL_0cd3_2;
						}
						goto case 143;
					case 143:
						num2 = 37 + 1;
						num4 = 157;
						continue;
					case 151:
						array[11] = (byte)num2;
						num = 58;
						goto IL_0cd3_2;
					case 239:
						num6 = 123 + 21;
						num4 = 174;
						continue;
					case 344:
						ul1LH1fgIgPxp5iByL(cryptoStream);
						num = 360;
						if (true)
						{
							goto IL_0cd3_2;
						}
						goto case 231;
					case 231:
						num2 = 68 - 7;
						num = 353;
						goto IL_0cd3_2;
					case 36:
						num6 = 210 - 70;
						num3 = 104;
						goto IL_0ccf;
					case 126:
						num6 = 80 - 16;
						num4 = 164;
						continue;
					case 180:
						array2[29] = 77;
						num4 = 252;
						continue;
					case 62:
						array2[7] = (byte)num6;
						num = 123;
						goto IL_0cd3_2;
					case 86:
						array2[29] = (byte)num6;
						num = 97;
						if (0 == 0)
						{
							goto IL_0cd3_2;
						}
						goto case 20;
					case 20:
						transform = (ICryptoTransform)p9EP18s5CY9GScAJ1n(rijndaelManaged, array5, array3);
						num4 = 212;
						continue;
					case 182:
						array2[11] = (byte)num6;
						num4 = 303;
						continue;
					case 136:
						array[7] = 120;
						num = 254;
						goto IL_0cd3_2;
					case 128:
						array3[3] = array4[1];
						num3 = 30;
						goto IL_0ccf;
					case 334:
						array2[18] = 215;
						num3 = 76;
						goto IL_0ccf;
					case 233:
						num2 = 149 - 49;
						num = 34;
						if (!SwrLBHZf0CVXxyb11Y())
						{
							goto IL_0cd3_2;
						}
						goto case 152;
					case 309:
						array2[5] = 180;
						num3 = 60;
						goto IL_0ccf;
					case 241:
						array2[1] = (byte)num6;
						num = 294;
						if (true)
						{
							goto IL_0cd3_2;
						}
						goto case 57;
					case 57:
						num2 = 0 + 101;
						num4 = 134;
						continue;
					case 274:
						array2[0] = (byte)num6;
						num = 331;
						goto IL_0cd3_2;
					case 224:
						array2[22] = 154;
						num4 = 91;
						continue;
					case 308:
						array[13] = (byte)num2;
						num3 = 192;
						goto IL_0ccf;
					case 361:
						try
						{
							return (string)J2GmgtpSxXymMQa5J5(otZSi6SJlfVYQJWAyc(), o1s0ki5St, P_0 + 4, num5);
						}
						catch
						{
						}
						return "";
					case 212:
						memoryStream = new MemoryStream();
						num3 = 258;
						goto IL_0ccf;
					case 322:
						rijndaelManaged = new RijndaelManaged();
						num = 316;
						goto IL_0cd3_2;
					}
					break;
					IL_01d2:
					num6 = 43 + 25;
					num3 = 10;
					goto IL_0ccf;
					IL_00b9:
					num3 = 89;
					goto IL_0ccf;
					IL_0081:
					array[6] = (byte)num2;
					num3 = 291;
					goto IL_0ccf;
					IL_0032:
					num2 = 7 + 9;
					num3 = 113;
					goto IL_0ccf;
				}
				break;
			}
			goto IL_001a;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[XOUiAM4rqHfQcBLtSy(typeof(DFgJQeHXspABPxPPUq/XOUiAM4rqHfQcBLtSy/gvZ5OHqHsruWEdqb3p<object>[]))]
		internal static string Nne57nwnG(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void JlVMHwNrJ(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int XUitAMrqH(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr QQcZBLtSy(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void gvZi5OHHs()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void suW1Edqb3()
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
		internal static object qSipHWhus(object P_0)
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
		public static extern IntPtr wT4YMg1DX(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr HgCrPve08(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int JgPCbHxcn(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int Vf4oKHbea(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int FEqmeXgHu(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr q5eFTRIEx(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int qNpg2x64f(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[XOUiAM4rqHfQcBLtSy(typeof(DFgJQeHXspABPxPPUq/XOUiAM4rqHfQcBLtSy/gvZ5OHqHsruWEdqb3p<object>[]))]
		private static byte[] XmAdeBlQO(string P_0)
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
		[XOUiAM4rqHfQcBLtSy(typeof(DFgJQeHXspABPxPPUq/XOUiAM4rqHfQcBLtSy/gvZ5OHqHsruWEdqb3p<object>[]))]
		private static byte[] KnLNjS6Pj(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				202, 21, 238, 156, 237, 79, 160, 197, 80, 74,
				228, 4, 229, 192, 16, 2, 118, 188, 184, 237,
				144, 141, 97, 121, 36, 111, 121, 224, 73, 237,
				229, 132
			};
			rijndael.IV = new byte[16]
			{
				114, 110, 61, 183, 46, 211, 161, 119, 44, 88,
				180, 135, 169, 201, 153, 185
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] fTf8PnYrZ()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] R1kwtl2GQ()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] IQHbFGOVc()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] CcUTov9AW()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] zNKhquJTR()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] cCT6xcI2B()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] NBpGLIdhV()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] e6dupShy8()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] J9TDR6cug()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] VA0RltCNf()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DFgJQeHXspABPxPPUq()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type KykF6uuxvVpBrV0e2L(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object voJhrmBV4Fn0hRxSpp(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object e3XyAR8NFYaojqbgdO(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void yoa08f7AkcmTiqvOTi(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void qJr66ELHYLwWIIhRJN(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long NuDegVtKoeaUwWLlst(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object obOxViHrmgERgBTnim(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Cd0aY9daoyeYLOFeC3(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object U8AkgGn1Gdgoe8QErY(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void fv7ME6lqcnS3rTuY48(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object p9EP18s5CY9GScAJ1n(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void c5OmBJr38lTEtu3Eir(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void ul1LH1fgIgPxp5iByL(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object FvWlSwbr8KfNF7yV42(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void nhMsqrqmNmjut2qt5H(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void ajcbW8xup6fciG9SQB(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int tv7SSeImIpHxLGAUR4(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object otZSi6SJlfVYQJWAyc()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object J2GmgtpSxXymMQa5J5(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool yiYdHTNaBNlrUxYyyt()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool SwrLBHZf0CVXxyb11Y()
		{
			return false;
		}
	}
}
namespace chcUovt9AW8NKquJTR
{
	internal class sZ21ktMl2GQIQHFGOV
	{
		private static bool PbSQE8CcnH;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void tyPEtxJz63naO()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public sZ21ktMl2GQIQHFGOV()
		{
		}
	}
}
