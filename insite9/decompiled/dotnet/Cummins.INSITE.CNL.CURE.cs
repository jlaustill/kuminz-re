using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security;
using System.Security.Cryptography;
using System.Security.Permissions;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Interop;
using CURE;
using Cummins.INSITE.CNL.CURE.Interfaces;
using dmnPDia3QpO7eF9mfJ;
using vRlaq0M277CATOnwNp;

[assembly: Guid("13c6e0d3-e581-4053-b124-f4cae977658f")]
[assembly: AssemblyFileVersion("1.0.0.0")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(true)]
[assembly: SuppressIldasm]
[assembly: AssemblyDescription("")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyKeyName("")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyProduct("CURE")]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyTitle("CURE")]
[assembly: SecurityPermission(SecurityAction.RequestMinimum, SkipVerification = true)]
[assembly: AssemblyVersion("1.0.0.0")]
[module: UnverifiableCode]
namespace vavJg5cTPYq6eeMGs6
{
	internal static class iLxh7ZF86FYe4BccVo
	{
	}
}
namespace Cummins.INSITE.CNL.CURE.Interfaces
{
	[ComVisible(true)]
	[Guid("AEF1B9C3-8DBF-43A2-B979-27DD8F8FF371")]
	public interface IPDDDownloadPresenter
	{
		void Initialize(string locale, string toolVersion, string toolInstance);

		void PrepareView(int parentWnd);

		void ProcessMessages(uint msgId);

		void SetDatalinkInfo(int DeviceId, string IniFileName);
	}
}
namespace Cummins.INSITE.CNL.CURE
{
	[ClassInterface(ClassInterfaceType.None)]
	[ComVisible(true)]
	[Guid("0E1838AD-C6D1-41AF-9E09-C02A7648A063")]
	[ProgId("Cummins.INSITE.CNL.CUREControl.CUREControl.1")]
	public class PDDDownloadPresenter : IPDDDownloadPresenter
	{
		public enum PDDDownloadResult
		{
			CalibrationFileNotCompatible,
			DriverError,
			FailToReadCalFile,
			NoCompatibleCalFound,
			NoEcuDetected,
			ReflashFailNack,
			ReflashFailNoResponse,
			ReflashStart,
			ReflashSuccess,
			UnknownError,
			Other
		}

		private const int YCMqs6Mj3 = -16;

		private const int VaoTj9DSF = 524288;

		private const int N4c25c7r7 = 1073741824;

		private const int EeFLHoyBQ = 65536;

		private const int rpEwV0uPM = 12582912;

		private const int ehBan49Hk = 65535;

		private Window KptYFZ8qA;

		private ReflashControl qwJfk0wcx;

		private int hoLso8bbe;

		private IntPtr AKOWj7FAY;

		private Dictionary<string, int> xeJIEAmKe;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Initialize(string locale, string toolVersion, string toolInstance)
		{
			qwJfk0wcx = new ReflashControl();
			qwJfk0wcx.ReflashStatusChanged += jvh7OLv5W;
			if (xeJIEAmKe.ContainsKey(locale.ToUpper()))
			{
				qwJfk0wcx.SetLanguage(xeJIEAmKe[locale]);
			}
			if (toolVersion != "" && toolInstance != "")
			{
				byte[] bytes = Encoding.UTF8.GetBytes(toolVersion);
				byte[] bytes2 = Encoding.UTF8.GetBytes(toolInstance);
				qwJfk0wcx.SetToolInformation(21, bytes, bytes2);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void PrepareView(int parentWnd)
		{
			//IL_000f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0019: Expected O, but got Unknown
			//IL_00d6: Unknown result type (might be due to invalid IL or missing references)
			//IL_00dc: Expected O, but got Unknown
			hoLso8bbe = parentWnd;
			KptYFZ8qA = new Window();
			KptYFZ8qA.ResizeMode = (ResizeMode)0;
			KptYFZ8qA.WindowStyle = (WindowStyle)0;
			CDllImports.SPuoIqxxx(parentWnd, out var cqJR3Aec7nK16yLH2P);
			((FrameworkElement)KptYFZ8qA).Width = cqJR3Aec7nK16yLH2P.IhrHqM3LE - cqJR3Aec7nK16yLH2P.E89KDm5fA;
			((FrameworkElement)KptYFZ8qA).Height = cqJR3Aec7nK16yLH2P.NVfSqAuwi - cqJR3Aec7nK16yLH2P.GQxiEf0cW;
			((FrameworkElement)qwJfk0wcx).Width = ((FrameworkElement)KptYFZ8qA).Width;
			((FrameworkElement)qwJfk0wcx).Height = ((FrameworkElement)KptYFZ8qA).Height;
			((FrameworkElement)qwJfk0wcx).VerticalAlignment = (VerticalAlignment)0;
			((FrameworkElement)qwJfk0wcx).HorizontalAlignment = (HorizontalAlignment)0;
			((ContentControl)KptYFZ8qA).Content = qwJfk0wcx;
			KptYFZ8qA.Show();
			WindowInteropHelper val = new WindowInteropHelper(KptYFZ8qA);
			AKOWj7FAY = val.Handle;
			CDllImports.Cy1nb0WLr(AKOWj7FAY, parentWnd);
			uint num = (uint)(int)CDllImports.GetWindowLongPtr(AKOWj7FAY, -16);
			CDllImports.SetWindowLongPtr(AKOWj7FAY, -16, (IntPtr)((num & -524289) | 0x40000000 | 0x10000));
			CDllImports.JOiZu1oyW(AKOWj7FAY, cqJR3Aec7nK16yLH2P.E89KDm5fA, cqJR3Aec7nK16yLH2P.GQxiEf0cW, (int)((FrameworkElement)KptYFZ8qA).Width, (int)((FrameworkElement)KptYFZ8qA).Height, true);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ProcessMessages(uint msgId)
		{
			CDllImports.SPuoIqxxx(hoLso8bbe, out var cqJR3Aec7nK16yLH2P);
			CDllImports.JOiZu1oyW(AKOWj7FAY, cqJR3Aec7nK16yLH2P.E89KDm5fA, cqJR3Aec7nK16yLH2P.GQxiEf0cW, cqJR3Aec7nK16yLH2P.IhrHqM3LE - cqJR3Aec7nK16yLH2P.E89KDm5fA, cqJR3Aec7nK16yLH2P.NVfSqAuwi - cqJR3Aec7nK16yLH2P.GQxiEf0cW, true);
			((FrameworkElement)qwJfk0wcx).Width = ((FrameworkElement)KptYFZ8qA).Width;
			((FrameworkElement)qwJfk0wcx).Height = ((FrameworkElement)KptYFZ8qA).Height;
			((FrameworkElement)qwJfk0wcx).VerticalAlignment = (VerticalAlignment)0;
			((FrameworkElement)qwJfk0wcx).HorizontalAlignment = (HorizontalAlignment)0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetDatalinkInfo(int DeviceId, string IniFileName)
		{
			qwJfk0wcx.DatalinkConfig.DllName = IniFileName;
			qwJfk0wcx.DatalinkConfig.DeviceId = DeviceId;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void jvh7OLv5W(ReflashStatusInfo P_0)
		{
			if (P_0.Status == ReflashStatusInfo.ReflashStatus.ReflashStart)
			{
				uint msg = 1028u;
				CDllImports.SendNotifyMessage((IntPtr)hoLso8bbe, msg, UIntPtr.Zero, IntPtr.Zero);
				return;
			}
			PDDDownloadResult pDDDownloadResult = P_0.Status switch
			{
				ReflashStatusInfo.ReflashStatus.ReflashSuccess => PDDDownloadResult.ReflashSuccess, 
				ReflashStatusInfo.ReflashStatus.ReflashFailNoResponse => PDDDownloadResult.ReflashFailNoResponse, 
				ReflashStatusInfo.ReflashStatus.ReflashFailNack => PDDDownloadResult.ReflashFailNack, 
				ReflashStatusInfo.ReflashStatus.DriverError => PDDDownloadResult.DriverError, 
				ReflashStatusInfo.ReflashStatus.CalibrationFileNotCompatible => PDDDownloadResult.CalibrationFileNotCompatible, 
				ReflashStatusInfo.ReflashStatus.FailToReadCalFile => PDDDownloadResult.FailToReadCalFile, 
				ReflashStatusInfo.ReflashStatus.NoCompatibleCalFound => PDDDownloadResult.NoCompatibleCalFound, 
				ReflashStatusInfo.ReflashStatus.NoEcuDetected => PDDDownloadResult.NoEcuDetected, 
				ReflashStatusInfo.ReflashStatus.UnknownError => PDDDownloadResult.UnknownError, 
				_ => PDDDownloadResult.Other, 
			};
			uint msg2 = 1029u;
			CDllImports.SendNotifyMessage((IntPtr)hoLso8bbe, msg2, (UIntPtr)(ulong)pDDDownloadResult, IntPtr.Zero);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public PDDDownloadPresenter()
		{
			OMIcTFEK4h0cVq7EVN.uCa5uxgzVwx2G();
			xeJIEAmKe = new Dictionary<string, int>
			{
				{
					Fp1dCKXtZq7MbI3HTI.VZPcdA6ge(0),
					9
				},
				{
					Fp1dCKXtZq7MbI3HTI.VZPcdA6ge(8),
					4
				},
				{
					Fp1dCKXtZq7MbI3HTI.VZPcdA6ge(16),
					6
				},
				{
					Fp1dCKXtZq7MbI3HTI.VZPcdA6ge(24),
					19
				},
				{
					Fp1dCKXtZq7MbI3HTI.VZPcdA6ge(32),
					11
				},
				{
					Fp1dCKXtZq7MbI3HTI.VZPcdA6ge(40),
					12
				},
				{
					Fp1dCKXtZq7MbI3HTI.VZPcdA6ge(48),
					7
				},
				{
					Fp1dCKXtZq7MbI3HTI.VZPcdA6ge(56),
					14
				},
				{
					Fp1dCKXtZq7MbI3HTI.VZPcdA6ge(64),
					33
				},
				{
					Fp1dCKXtZq7MbI3HTI.VZPcdA6ge(72),
					16
				},
				{
					Fp1dCKXtZq7MbI3HTI.VZPcdA6ge(80),
					17
				},
				{
					Fp1dCKXtZq7MbI3HTI.VZPcdA6ge(88),
					18
				},
				{
					Fp1dCKXtZq7MbI3HTI.VZPcdA6ge(96),
					20
				},
				{
					Fp1dCKXtZq7MbI3HTI.VZPcdA6ge(104),
					21
				},
				{
					Fp1dCKXtZq7MbI3HTI.VZPcdA6ge(112),
					22
				},
				{
					Fp1dCKXtZq7MbI3HTI.VZPcdA6ge(120),
					24
				},
				{
					Fp1dCKXtZq7MbI3HTI.VZPcdA6ge(128),
					25
				},
				{
					Fp1dCKXtZq7MbI3HTI.VZPcdA6ge(136),
					10
				},
				{
					Fp1dCKXtZq7MbI3HTI.VZPcdA6ge(144),
					29
				},
				{
					Fp1dCKXtZq7MbI3HTI.VZPcdA6ge(152),
					31
				}
			};
			base..ctor();
		}
	}
	public static class CDllImports
	{
		internal struct CqJR3Aec7nK16yLH2P
		{
			public int E89KDm5fA;

			public int GQxiEf0cW;

			public int IhrHqM3LE;

			public int NVfSqAuwi;
		}

		[DllImport("User32.dll", CharSet = CharSet.Auto, EntryPoint = "SetParent", ExactSpelling = true)]
		internal static extern IntPtr Cy1nb0WLr(IntPtr P_0, int P_1);

		[DllImport("User32.dll")]
		public static extern int FindWindowEx(int hwndParent, int hwndEnfant, int lpClasse, string lpTitre);

		[DllImport("User32.dll", EntryPoint = "GetWindowLong")]
		private static extern IntPtr lBjJLM5Zl(IntPtr P_0, int P_1);

		[DllImport("User32.dll", EntryPoint = "GetWindowLongPtr")]
		private static extern IntPtr KLZgbXeEP(IntPtr P_0, int P_1);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SecurityPermission(SecurityAction.Assert, UnmanagedCode = true)]
		public static IntPtr GetWindowLongPtr(IntPtr hWnd, int nIndex)
		{
			if (IntPtr.Size == 8)
			{
				return KLZgbXeEP(hWnd, nIndex);
			}
			return lBjJLM5Zl(hWnd, nIndex);
		}

		[DllImport("User32.dll", EntryPoint = "SetWindowLong")]
		private static extern int VGMyaJN6o(IntPtr P_0, int P_1, int P_2);

		[DllImport("User32.dll", EntryPoint = "SetWindowLongPtr")]
		private static extern IntPtr JT2xk2WXD(IntPtr P_0, int P_1, IntPtr P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SecurityPermission(SecurityAction.Assert, UnmanagedCode = true)]
		public static IntPtr SetWindowLongPtr(IntPtr hWnd, int nIndex, IntPtr dwNewLong)
		{
			if (IntPtr.Size == 8)
			{
				return JT2xk2WXD(hWnd, nIndex, dwNewLong);
			}
			return new IntPtr(VGMyaJN6o(hWnd, nIndex, dwNewLong.ToInt32()));
		}

		[DllImport("User32.dll", EntryPoint = "GetClientRect")]
		[return: MarshalAs(UnmanagedType.Bool)]
		internal static extern bool SPuoIqxxx(int P_0, out CqJR3Aec7nK16yLH2P P_1);

		[DllImport("User32.dll", EntryPoint = "GetWindowRect")]
		[return: MarshalAs(UnmanagedType.Bool)]
		internal static extern bool a3mVWHYpx(IntPtr P_0, out CqJR3Aec7nK16yLH2P P_1);

		[DllImport("User32.dll", EntryPoint = "MoveWindow")]
		internal static extern void JOiZu1oyW(IntPtr P_0, int P_1, int P_2, int P_3, int P_4, bool P_5);

		[DllImport("User32.dll", EntryPoint = "ShowWindow")]
		private static extern bool SJEh1ysud(IntPtr P_0, uint P_1);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SecurityPermission(SecurityAction.Assert, UnmanagedCode = true)]
		public static bool ShowWindow(IntPtr hWnd, uint nCmdShow)
		{
			return SJEh1ysud(hWnd, nCmdShow);
		}

		[DllImport("User32.dll", CharSet = CharSet.Auto, SetLastError = true)]
		public static extern uint RegisterWindowMessage(string lpString);

		[DllImport("User32.dll", CharSet = CharSet.Auto, SetLastError = true)]
		public static extern bool SendNotifyMessage(IntPtr hWnd, uint Msg, UIntPtr wParam, IntPtr lParam);
	}
}
internal class <Module>{BA8CE18B-5D15-480E-9C9D-7D95AE7B6F9D}
{
}
namespace MqTqFdKtJrENq8MkxN
{
	internal class BtoqlcyqXYmEpqexte
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module fgG8HiKtJ;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void YsR5uxggdxfEC(int typemdt)
		{
			Type type = fgG8HiKtJ.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)fgG8HiKtJ.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public BtoqlcyqXYmEpqexte()
		{
			OMIcTFEK4h0cVq7EVN.uCa5uxgzVwx2G();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static BtoqlcyqXYmEpqexte()
		{
			OMIcTFEK4h0cVq7EVN.uCa5uxgzVwx2G();
			fgG8HiKtJ = typeof(BtoqlcyqXYmEpqexte).Assembly.ManifestModule;
		}
	}
}
namespace vRlaq0M277CATOnwNp
{
	internal class Fp1dCKXtZq7MbI3HTI
	{
		internal class nXn7GSjFJMtXKl9ioJ : Attribute
		{
			internal class nX2TZqOiDQZb40khFg<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public nX2TZqOiDQZb40khFg()
				{
					OMIcTFEK4h0cVq7EVN.uCa5uxgzVwx2G();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[nXn7GSjFJMtXKl9ioJ(typeof(Fp1dCKXtZq7MbI3HTI/nXn7GSjFJMtXKl9ioJ/nX2TZqOiDQZb40khFg<object>[]))]
			public nXn7GSjFJMtXKl9ioJ(object P_0)
			{
				OMIcTFEK4h0cVq7EVN.uCa5uxgzVwx2G();
				base..ctor();
			}
		}

		internal class NxAvnpd3jXPsSFlbv1
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[nXn7GSjFJMtXKl9ioJ(typeof(Fp1dCKXtZq7MbI3HTI/nXn7GSjFJMtXKl9ioJ/nX2TZqOiDQZb40khFg<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (Rxa7nTwHaW(Convert.ToBase64String(typeof(Fp1dCKXtZq7MbI3HTI).Assembly.GetName().GetPublicKeyToken()), Fp1dCKXtZq7MbI3HTI.VZPcdA6ge(160)) != Fp1dCKXtZq7MbI3HTI.VZPcdA6ge(166))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[nXn7GSjFJMtXKl9ioJ(typeof(Fp1dCKXtZq7MbI3HTI/nXn7GSjFJMtXKl9ioJ/nX2TZqOiDQZb40khFg<object>[]))]
			internal static string Rxa7nTwHaW(string P_0, string P_1)
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
			public NxAvnpd3jXPsSFlbv1()
			{
				OMIcTFEK4h0cVq7EVN.uCa5uxgzVwx2G();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint lX6X56CgxyucmfMH5s([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr B229mbUOIC2bOI1ojc();

		internal struct pIKKd26Uk3YQZjWYKl
		{
			internal bool i8h7J0xbQR;

			internal byte[] cmA7gWQe68;
		}

		[Flags]
		private enum B93EAJwVVNHQKOZ2ed
		{

		}

		private static byte[] TSWXWxpDC;

		private static byte[] mWnAB6R5H;

		private static byte[] ImG16XLQT;

		private static int Vt679yWtZx;

		private static bool ldu77j4bLT;

		private static long QeK72ty8O6;

		internal static lX6X56CgxyucmfMH5s tQN7LRRWKx;

		internal static Hashtable rCd7IFlO05;

		private static byte[] nkiRok1mP;

		private static IntPtr FrHBsboFF;

		private static IntPtr s61l7NyGf;

		private static int pGG7sYpGWn;

		private static long NwZ7aHQ4oy;

		private static int Nl87YrUCMZ;

		private static IntPtr rQy7WfJjCi;

		private static object PG3PBB4I3;

		internal static lX6X56CgxyucmfMH5s dhy7wlpUn0;

		private static bool wwp7fQ5ViQ;

		private static int[] kXPzYn7wK;

		private static SortedList Ox57qlviRW;

		private static int eWu7Tqvihm;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static Fp1dCKXtZq7MbI3HTI()
		{
			TSWXWxpDC = new byte[0];
			mWnAB6R5H = new byte[0];
			ImG16XLQT = new byte[0];
			nkiRok1mP = new byte[0];
			FrHBsboFF = IntPtr.Zero;
			s61l7NyGf = IntPtr.Zero;
			PG3PBB4I3 = new string[0];
			kXPzYn7wK = new int[0];
			Vt679yWtZx = 1;
			ldu77j4bLT = false;
			Ox57qlviRW = new SortedList();
			eWu7Tqvihm = 0;
			QeK72ty8O6 = 0L;
			tQN7LRRWKx = null;
			dhy7wlpUn0 = null;
			NwZ7aHQ4oy = 0L;
			Nl87YrUCMZ = 0;
			wwp7fQ5ViQ = false;
			pGG7sYpGWn = 0;
			rQy7WfJjCi = IntPtr.Zero;
			rCd7IFlO05 = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void jcy5uxgqMwJhm()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[nXn7GSjFJMtXKl9ioJ(typeof(Fp1dCKXtZq7MbI3HTI/nXn7GSjFJMtXKl9ioJ/nX2TZqOiDQZb40khFg<object>[]))]
		static string VZPcdA6ge(int P_0)
		{
			int num = 237;
			if (!v43NRpPayHUgPa6YLV())
			{
				goto IL_001a;
			}
			goto IL_2414;
			IL_001a:
			byte[] array = default(byte[]);
			int num2 = default(int);
			array[2] = (byte)num2;
			int num3 = 290;
			goto IL_2410;
			IL_2410:
			num = num3;
			goto IL_2414;
			IL_2414:
			byte[] array2 = default(byte[]);
			int num6 = default(int);
			CryptoStream cryptoStream = default(CryptoStream);
			byte[] array4 = default(byte[]);
			byte[] array5 = default(byte[]);
			byte[] array6 = default(byte[]);
			MemoryStream memoryStream = default(MemoryStream);
			int num5 = default(int);
			BinaryReader binaryReader = default(BinaryReader);
			ICryptoTransform transform = default(ICryptoTransform);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array3 = default(byte[]);
			while (true)
			{
				IL_2414_2:
				int num4 = num;
				while (true)
				{
					switch (num4)
					{
					case 321:
						break;
					case 173:
						array[5] = 94;
						num4 = 272;
						continue;
					case 108:
						goto IL_0051;
					case 315:
						num2 = 35 + 101;
						num4 = 250;
						continue;
					case 96:
						array2[10] = 216;
						num4 = 202;
						continue;
					case 305:
						goto IL_00a1;
					case 6:
						goto IL_00b9;
					case 328:
						array[16] = 100;
						num = 285;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 348;
					case 348:
						num2 = 81 + 58;
						num = 311;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 331;
					case 331:
						num2 = 177 - 59;
						num4 = 264;
						continue;
					case 310:
						array2[12] = 111;
						num = 100;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 134;
					case 134:
						num6 = 102 + 124;
						num4 = 215;
						continue;
					case 204:
						THrNsDdrKZYeVO332l(cryptoStream);
						num4 = 82;
						continue;
					case 49:
						num6 = 179 - 81;
						num = 178;
						goto IL_2414_2;
					case 319:
						array[22] = (byte)num2;
						num4 = 297;
						continue;
					case 171:
						array[9] = 54;
						num = 359;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 209;
					case 266:
						array[21] = 78;
						num4 = 279;
						continue;
					case 16:
						array2[13] = (byte)num6;
						num = 175;
						goto IL_2414_2;
					case 81:
						array[30] = 117;
						num4 = 269;
						continue;
					case 165:
						array[17] = (byte)num2;
						num = 75;
						goto IL_2414_2;
					case 293:
						num2 = 102 + 12;
						num = 240;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 269;
					case 269:
						array[30] = 173;
						num4 = 192;
						continue;
					case 9:
						array[5] = 152;
						num4 = 173;
						continue;
					case 115:
						num2 = 151 - 113;
						num = 258;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 217;
					case 217:
						num2 = 48 + 31;
						num3 = 255;
						goto IL_2410;
					case 143:
						array4[1] = array5[0];
						num = 349;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 175;
					case 175:
						num6 = 216 - 101;
						num = 90;
						goto IL_2414_2;
					case 177:
						array[3] = 154;
						num4 = 141;
						continue;
					case 199:
						array2[11] = 36;
						num = 274;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 66;
					case 66:
						num2 = 240 - 80;
						num = 69;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 84;
					case 181:
						num6 = 43 + 86;
						num4 = 278;
						continue;
					case 150:
						array2[15] = 120;
						num = 114;
						goto IL_2414_2;
					case 285:
						array[16] = 118;
						num3 = 257;
						goto IL_2410;
					case 54:
						num6 = 25 - 11;
						num4 = 19;
						continue;
					case 327:
						num2 = 215 - 109;
						num = 127;
						goto IL_2414_2;
					case 159:
						array[8] = 156;
						num4 = 62;
						continue;
					case 55:
						num2 = 111 + 30;
						num = 3;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 225;
					case 225:
						array2[8] = 47;
						num = 222;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 269;
					case 53:
						num2 = 149 - 49;
						num4 = 21;
						continue;
					case 246:
						V21x9BK2u4SUdxReF9(true);
						num4 = 79;
						continue;
					case 21:
						array[4] = (byte)num2;
						num3 = 123;
						goto IL_2410;
					case 334:
						num2 = 224 - 74;
						num = 207;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 339;
					case 121:
						UgCFsc5f6yXJLNWBw7(cryptoStream);
						num4 = 333;
						continue;
					case 344:
						array[28] = 112;
						num3 = 350;
						goto IL_2410;
					case 61:
						array2 = new byte[16];
						num4 = 238;
						continue;
					case 247:
						array[11] = 84;
						num = 256;
						goto IL_2414_2;
					case 12:
						array2[2] = 134;
						num = 270;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 162;
					case 168:
						num6 = 23 + 75;
						num3 = 102;
						goto IL_2410;
					case 42:
						array[20] = 89;
						num4 = 119;
						continue;
					case 338:
						array[15] = (byte)num2;
						num3 = 312;
						goto IL_2410;
					case 37:
						array[13] = 105;
						num4 = 309;
						continue;
					case 251:
						array[3] = 32;
						num3 = 101;
						goto IL_2410;
					case 187:
						array[19] = 213;
						num3 = 233;
						goto IL_2410;
					case 294:
						num2 = 239 - 79;
						num3 = 118;
						goto IL_2410;
					case 77:
						array2[13] = 154;
						num4 = 195;
						continue;
					case 281:
						num2 = 38 + 6;
						num = 339;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 101;
					case 101:
						array[4] = 133;
						num = 53;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 14;
					case 14:
						num2 = 35 + 95;
						num = 345;
						goto IL_2414_2;
					case 29:
						array[29] = 135;
						num4 = 227;
						continue;
					case 253:
						array[21] = (byte)num2;
						num = 98;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 12;
					case 276:
						num2 = 113 + 115;
						num = 355;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 245;
					case 195:
						num6 = 7 + 47;
						num = 209;
						goto IL_2414_2;
					case 84:
						num2 = 250 - 83;
						num = 63;
						goto IL_2414_2;
					case 302:
						num2 = 252 - 84;
						num3 = 288;
						goto IL_2410;
					case 219:
						array[28] = 136;
						num = 344;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 7;
					case 242:
						array[12] = 102;
						num4 = 140;
						continue;
					case 297:
						array[22] = 167;
						num4 = 360;
						continue;
					case 320:
						array4[7] = array5[3];
						num3 = 316;
						goto IL_2410;
					case 24:
						num6 = 26 + 47;
						num3 = 179;
						goto IL_2410;
					case 258:
						array[23] = (byte)num2;
						num = 5;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 38;
					case 38:
						num2 = 183 - 67;
						num3 = 172;
						goto IL_2410;
					case 46:
						array2[11] = (byte)num6;
						num = 52;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 152;
					case 106:
						array2[15] = 98;
						num = 103;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 313;
					case 313:
						array2[15] = 118;
						num4 = 150;
						continue;
					case 350:
						array[28] = 97;
						num3 = 160;
						goto IL_2410;
					case 180:
						array2[3] = (byte)num6;
						num4 = 307;
						continue;
					case 28:
						num2 = 126 - 42;
						num3 = 10;
						goto IL_2410;
					case 311:
						array[23] = (byte)num2;
						num3 = 139;
						goto IL_2410;
					case 163:
						array2[14] = (byte)num6;
						num = 34;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 102;
					case 169:
						if (array5 != null)
						{
							num = 341;
							if (!j4qeRL0KwZjGCj4k0p())
							{
								goto IL_2414_2;
							}
							goto case 218;
						}
						goto case 105;
					case 270:
						num6 = 46 + 30;
						num4 = 342;
						continue;
					case 191:
						array[27] = 161;
						num = 330;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 349;
					case 349:
						array4[3] = array5[1];
						num4 = 301;
						continue;
					case 255:
						array[2] = (byte)num2;
						num = 76;
						goto IL_2414_2;
					case 295:
						array2[1] = (byte)num6;
						num4 = 1;
						continue;
					case 5:
						num2 = 61 + 56;
						num = 113;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 153;
					case 153:
						num6 = 121 + 8;
						num = 232;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 228;
					case 228:
						array2[3] = 155;
						num4 = 20;
						continue;
					case 353:
						array2[1] = 122;
						num4 = 235;
						continue;
					case 63:
						array[6] = (byte)num2;
						num = 262;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 193;
					case 193:
						u0eHmWyRxUJ3niqAAE(cryptoStream, array6, 0, array6.Length);
						num = 121;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 40;
					case 40:
						num2 = 251 - 83;
						num3 = 273;
						goto IL_2410;
					case 133:
						array[25] = (byte)num2;
						num = 116;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 316;
					case 316:
						array4[9] = array5[4];
						num3 = 212;
						goto IL_2410;
					case 232:
						array2[9] = (byte)num6;
						num = 24;
						goto IL_2414_2;
					case 184:
						array2[3] = (byte)num6;
						num = 58;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 155;
					case 155:
						array2[4] = (byte)num6;
						num = 357;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 171;
					case 23:
						THrNsDdrKZYeVO332l(memoryStream);
						num = 204;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 115;
					case 2:
						array[26] = (byte)num2;
						num3 = 194;
						goto IL_2410;
					case 83:
						array[26] = (byte)num2;
						num4 = 299;
						continue;
					case 172:
						array[15] = (byte)num2;
						num = 281;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 85;
					case 85:
						array[7] = 65;
						num4 = 55;
						continue;
					case 142:
					case 286:
						array[20] = 174;
						num = 352;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 27;
					case 146:
						array2[5] = 120;
						num4 = 197;
						continue;
					case 201:
						array[21] = (byte)num2;
						num3 = 40;
						goto IL_2410;
					case 197:
						array2[5] = 151;
						num = 7;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 322;
					case 124:
						num2 = 125 - 105;
						num4 = 83;
						continue;
					case 114:
						array4 = array2;
						num4 = 198;
						continue;
					case 92:
						array[17] = (byte)num2;
						num = 97;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 282;
					case 282:
						array[26] = 221;
						num = 43;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 284;
					case 284:
						num2 = 84 + 31;
						num = 2;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 277;
					case 277:
						num6 = 41 - 39;
						num = 39;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 157;
					case 157:
						num2 = 145 - 48;
						num4 = 4;
						continue;
					case 216:
						array[0] = 140;
						num = 361;
						goto IL_2414_2;
					case 339:
						array[16] = (byte)num2;
						num = 298;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 113;
					case 113:
						array[24] = (byte)num2;
						num4 = 200;
						continue;
					case 88:
					case 252:
						num6 = 180 - 60;
						num = 138;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 347;
					case 231:
						array[0] = (byte)num2;
						num3 = 72;
						goto IL_2410;
					case 237:
						if (ImG16XLQT.Length == 0)
						{
							num = 351;
							if (v43NRpPayHUgPa6YLV())
							{
								goto IL_2414_2;
							}
							goto case 332;
						}
						goto case 95;
					case 332:
						num6 = 139 + 87;
						num = 245;
						goto IL_2414_2;
					case 154:
						array[15] = 146;
						num4 = 89;
						continue;
					case 110:
						array[12] = (byte)num2;
						num = 334;
						goto IL_2414_2;
					case 263:
						num2 = 131 - 43;
						num = 182;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 287;
					case 287:
						array[5] = (byte)num2;
						num = 6;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 44;
					case 44:
						array2[0] = (byte)num6;
						num = 156;
						goto IL_2414_2;
					case 317:
						num2 = 176 + 16;
						num = 343;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 235;
					case 235:
						num6 = 22 + 79;
						num = 295;
						goto IL_2414_2;
					case 257:
						array[16] = 115;
						num3 = 190;
						goto IL_2410;
					case 162:
						array2[6] = 157;
						num4 = 244;
						continue;
					case 245:
						array2[2] = (byte)num6;
						num4 = 228;
						continue;
					case 57:
						array[10] = 166;
						num3 = 337;
						goto IL_2410;
					case 122:
						num2 = 53 + 112;
						num3 = 51;
						goto IL_2410;
					case 7:
						num6 = 197 - 65;
						num = 108;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 41;
					case 41:
						array2[3] = (byte)num6;
						num = 70;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 49;
					case 22:
						num2 = 44 + 83;
						num = 144;
						goto IL_2414_2;
					case 60:
						num2 = 76 + 42;
						num3 = 87;
						goto IL_2410;
					case 126:
						num2 = 127 - 42;
						num = 203;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 11;
					case 11:
						num6 = 152 - 85;
						num = 176;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 123;
					case 123:
						array[4] = 9;
						num = 9;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 104;
					case 104:
						num2 = 83 + 66;
						num3 = 31;
						goto IL_2410;
					case 149:
						array[22] = (byte)num2;
						num = 22;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 198;
					case 198:
						array5 = (byte[])iSlpxPqt1WFLaKPa1R(B7V8bZiQHnq1Am5g7j(BkJnkPtKB1CK9tehMZ(typeof(Fp1dCKXtZq7MbI3HTI).TypeHandle).Assembly));
						num3 = 169;
						goto IL_2410;
					case 227:
						array[29] = 206;
						num4 = 293;
						continue;
					case 70:
						num6 = 154 + 14;
						num4 = 180;
						continue;
					case 51:
						array[0] = (byte)num2;
						num = 216;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 26;
					case 26:
						num2 = 194 - 64;
						num = 229;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 250;
					case 250:
						array[21] = (byte)num2;
						num3 = 266;
						goto IL_2410;
					case 58:
						array2[3] = 148;
						num = 13;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 197;
					case 309:
						array[13] = 168;
						num3 = 104;
						goto IL_2410;
					case 132:
						array[22] = (byte)num2;
						num = 107;
						goto IL_2414_2;
					case 90:
						array2[13] = (byte)num6;
						num3 = 65;
						goto IL_2410;
					case 354:
						num6 = 126 - 42;
						num = 64;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 56;
					case 56:
						num6 = 110 + 54;
						num = 205;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 188;
					case 188:
						array[3] = 88;
						num3 = 177;
						goto IL_2410;
					case 314:
						num6 = 195 - 65;
						num4 = 16;
						continue;
					case 298:
						array[16] = 62;
						num = 328;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 273;
					case 273:
						array[21] = (byte)num2;
						num3 = 48;
						goto IL_2410;
					case 98:
						num2 = 252 - 84;
						num = 201;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 105;
					case 236:
						array2[15] = (byte)num6;
						num3 = 313;
						goto IL_2410;
					case 35:
						array[28] = (byte)num2;
						num4 = 300;
						continue;
					case 139:
						array[23] = 160;
						num = 115;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 93;
					case 93:
						array2[10] = 108;
						num4 = 96;
						continue;
					case 71:
						array[18] = 135;
						num = 78;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 62;
					case 62:
						array[8] = 156;
						num = 147;
						goto IL_2414_2;
					case 268:
						num2 = 226 - 75;
						num = 35;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 355;
					case 355:
						array[12] = (byte)num2;
						num = 26;
						goto IL_2414_2;
					case 209:
						array2[13] = (byte)num6;
						num3 = 314;
						goto IL_2410;
					case 205:
						array2[7] = (byte)num6;
						num = 189;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 14;
					case 32:
						array[27] = (byte)num2;
						num3 = 74;
						goto IL_2410;
					case 43:
						array[26] = 89;
						num = 318;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 15;
					case 15:
						array[3] = (byte)num2;
						num3 = 28;
						goto IL_2410;
					case 358:
						array[11] = 153;
						num3 = 291;
						goto IL_2410;
					case 20:
						num6 = 184 - 61;
						num3 = 184;
						goto IL_2410;
					case 179:
						array2[9] = (byte)num6;
						num3 = 347;
						goto IL_2410;
					case 341:
						if (array5.Length > 0)
						{
							num = 143;
							if (v43NRpPayHUgPa6YLV())
							{
								goto IL_2414_2;
							}
							goto case 134;
						}
						goto case 105;
					case 299:
						num2 = 111 + 85;
						num = 32;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 73;
					case 73:
						array2[6] = 153;
						num3 = 259;
						goto IL_2410;
					case 67:
						num2 = 74 + 75;
						num3 = 165;
						goto IL_2410;
					case 288:
						array[13] = (byte)num2;
						num4 = 37;
						continue;
					case 127:
						array[19] = (byte)num2;
						num3 = 239;
						goto IL_2410;
					case 300:
						array[28] = 211;
						num = 29;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 241;
					case 241:
						array[31] = 102;
						num = 336;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 323;
					case 323:
						num6 = 139 - 46;
						num = 46;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 33;
					case 33:
						array[17] = 166;
						num = 67;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 310;
					case 322:
						array2[8] = 130;
						num = 225;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 185;
					case 185:
						array[19] = (byte)num2;
						num = 327;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 184;
					case 95:
						num5 = ArlPDWGa2XSWsbfV3h(ImG16XLQT, P_0);
						num4 = 362;
						continue;
					case 343:
						array[25] = (byte)num2;
						num3 = 282;
						goto IL_2410;
					case 1:
						num6 = 217 - 72;
						num4 = 356;
						continue;
					case 140:
						num2 = 183 - 117;
						num = 110;
						goto IL_2414_2;
					case 318:
						num2 = 17 + 70;
						num = 292;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 351;
					case 351:
						binaryReader = new BinaryReader((Stream)cGUr1AJG3qn6RY5SYE(BkJnkPtKB1CK9tehMZ(typeof(Fp1dCKXtZq7MbI3HTI).TypeHandle).Assembly, "1Y9RnFrMDbJgBHUFnj.To7rlmgqyiyNYsnj08"));
						num4 = 112;
						continue;
					case 261:
						array2[10] = (byte)num6;
						num3 = 277;
						goto IL_2410;
					case 129:
						array2[14] = (byte)num6;
						num3 = 296;
						goto IL_2410;
					case 200:
						num2 = 182 - 60;
						num3 = 243;
						goto IL_2410;
					case 304:
						array[14] = (byte)num2;
						num = 14;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 91;
					case 91:
						num2 = 105 + 34;
						num3 = 86;
						goto IL_2410;
					case 156:
						array2[0] = 134;
						num4 = 168;
						continue;
					case 80:
						num2 = 102 + 15;
						num = 174;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 179;
					case 182:
						array[20] = (byte)num2;
						num = 42;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 72;
					case 152:
						array4[13] = array5[6];
						num = 218;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 36;
					case 36:
						array2[14] = (byte)num6;
						num4 = 54;
						continue;
					case 312:
						num2 = 170 - 56;
						num3 = 208;
						goto IL_2410;
					case 39:
						array2[10] = (byte)num6;
						num4 = 323;
						continue;
					case 27:
						array[9] = 114;
						num = 211;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 207;
					case 207:
						array[13] = (byte)num2;
						num3 = 128;
						goto IL_2410;
					case 271:
						array2[7] = 108;
						num3 = 56;
						goto IL_2410;
					case 361:
						array[0] = 116;
						num4 = 224;
						continue;
					case 243:
						array[24] = (byte)num2;
						num = 267;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 109;
					case 213:
						num2 = 51 + 113;
						num4 = 254;
						continue;
					case 125:
						array[19] = (byte)num2;
						num3 = 158;
						goto IL_2410;
					case 120:
						array[10] = 116;
						num4 = 126;
						continue;
					case 52:
						array2[11] = 55;
						num4 = 199;
						continue;
					case 347:
						array2[9] = 148;
						num4 = 49;
						continue;
					case 136:
						array[30] = (byte)num2;
						num = 81;
						goto IL_2414_2;
					case 25:
						array[29] = 220;
						num4 = 294;
						continue;
					case 356:
						array2[1] = (byte)num6;
						num3 = 134;
						goto IL_2410;
					case 107:
						num2 = 249 - 83;
						num4 = 319;
						continue;
					case 189:
						array2[8] = 113;
						num = 322;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 10;
					case 0:
						num6 = 168 - 56;
						num = 305;
						goto IL_2414_2;
					case 192:
						array[30] = 116;
						num = 148;
						goto IL_2414_2;
					case 212:
						array4[11] = array5[5];
						num3 = 152;
						goto IL_2410;
					case 223:
						array[7] = 145;
						num4 = 80;
						continue;
					case 50:
						array[15] = 192;
						num = 38;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 119;
					case 119:
						num2 = 229 - 76;
						num = 253;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 256;
					case 256:
						array[11] = 88;
						num = 358;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 340;
					case 340:
						array[11] = (byte)num2;
						num3 = 276;
						goto IL_2410;
					case 82:
						dASGEXgicfMYUsjcq7(binaryReader);
						num = 95;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 59;
					case 59:
						array[10] = (byte)num2;
						num = 57;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 86;
					case 86:
						array[1] = (byte)num2;
						num = 217;
						goto IL_2414_2;
					case 359:
						num2 = 121 + 70;
						num3 = 59;
						goto IL_2410;
					case 329:
						array[21] = (byte)num2;
						num = 315;
						goto IL_2414_2;
					case 45:
						array2[6] = (byte)num6;
						num = 196;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 97;
					case 97:
						num2 = 196 - 109;
						num4 = 220;
						continue;
					case 148:
						array[31] = 164;
						num3 = 241;
						goto IL_2410;
					case 102:
						array2[1] = (byte)num6;
						num4 = 0;
						continue;
					case 308:
						array[8] = (byte)num2;
						num = 8;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 233;
					case 76:
						array[2] = 156;
						num = 324;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 260;
					case 260:
						array[27] = (byte)num2;
						num = 66;
						goto IL_2414_2;
					case 3:
						array[7] = (byte)num2;
						num4 = 159;
						continue;
					case 267:
						array[24] = 110;
						num = 249;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 112;
					case 112:
						rqFy7WeSHmw9WWhDy6(MkyMID6uDQZW3q1P6N(binaryReader), 0L);
						num = 246;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 194;
					case 194:
						num2 = 124 + 102;
						num4 = 68;
						continue;
					case 145:
						cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
						num4 = 193;
						continue;
					case 89:
						num2 = 163 - 54;
						num3 = 338;
						goto IL_2410;
					case 291:
						array[11] = 102;
						num = 275;
						goto IL_2414_2;
					case 100:
						array2[12] = 106;
						num4 = 170;
						continue;
					case 254:
						array[27] = (byte)num2;
						num = 219;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 354;
					case 117:
						array2[12] = 85;
						num = 77;
						goto IL_2414_2;
					case 166:
						array2[5] = 202;
						num = 73;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 218;
					case 218:
						array4[15] = array5[7];
						num4 = 105;
						continue;
					case 259:
						num6 = 196 - 65;
						num = 45;
						goto IL_2414_2;
					case 18:
						array[13] = 113;
						num3 = 302;
						goto IL_2410;
					case 151:
						num6 = 76 + 64;
						num4 = 155;
						continue;
					case 324:
						num2 = 166 - 55;
						num = 321;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 99;
					case 99:
						array[10] = 1;
						num = 247;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 10;
					case 10:
						array[3] = (byte)num2;
						num = 251;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 226;
					case 226:
						transform = (ICryptoTransform)OPihC2oJHW0LkQVWa6(rijndaelManaged, array3, array4);
						num4 = 131;
						continue;
					case 94:
						Oy9PnFT64bIOcXwyNA(rijndaelManaged, CipherMode.CBC);
						num = 226;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 338;
					case 208:
						array[15] = (byte)num2;
						num3 = 50;
						goto IL_2410;
					case 279:
						num2 = 11 + 70;
						num3 = 132;
						goto IL_2410;
					case 224:
						num2 = 175 + 69;
						num = 231;
						goto IL_2414_2;
					case 147:
						array[8] = 154;
						num3 = 135;
						goto IL_2410;
					case 345:
						array[14] = (byte)num2;
						num = 154;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 105;
					case 65:
						num6 = 87 + 107;
						num = 306;
						goto IL_2414_2;
					case 78:
						array[18] = 90;
						num4 = 283;
						continue;
					case 233:
						num2 = 21 + 82;
						num3 = 125;
						goto IL_2410;
					case 307:
						array2[4] = 136;
						num = 151;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 325;
					case 325:
						num6 = 69 + 2;
						num = 214;
						goto IL_2414_2;
					case 69:
						array[27] = (byte)num2;
						num4 = 213;
						continue;
					case 79:
						array6 = (byte[])eaapV3LKpFPF6Uksv1(binaryReader, (int)DY8Y0k9pFXbZigeKYZ(MkyMID6uDQZW3q1P6N(binaryReader)));
						num4 = 186;
						continue;
					case 214:
						array2[2] = (byte)num6;
						num3 = 12;
						goto IL_2410;
					case 360:
						num2 = 107 + 66;
						num = 149;
						goto IL_2414_2;
					case 210:
						array[27] = (byte)num2;
						num4 = 191;
						continue;
					case 220:
						array[17] = (byte)num2;
						num3 = 71;
						goto IL_2410;
					case 274:
						array2[11] = 206;
						num3 = 11;
						goto IL_2410;
					case 48:
						num2 = 206 - 68;
						num4 = 329;
						continue;
					case 160:
						array[28] = 148;
						num4 = 268;
						continue;
					case 283:
						array[18] = 15;
						num = 109;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 13;
					case 13:
						num6 = 89 + 12;
						num = 41;
						goto IL_2414_2;
					case 158:
						array[19] = 97;
						num = 167;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 81;
					case 109:
						array[19] = 18;
						num3 = 187;
						goto IL_2410;
					case 141:
						num2 = 80 + 40;
						num4 = 15;
						continue;
					case 17:
						array[6] = (byte)num2;
						num = 223;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 75;
					case 118:
						array[29] = (byte)num2;
						num = 130;
						goto IL_2414_2;
					case 265:
						num2 = 26 + 115;
						num = 346;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 31;
					case 31:
						array[14] = (byte)num2;
						num = 111;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 240;
					case 240:
						array[29] = (byte)num2;
						num3 = 25;
						goto IL_2410;
					case 337:
						array[10] = 79;
						num = 120;
						goto IL_2414_2;
					case 238:
						array2[0] = 125;
						num3 = 289;
						goto IL_2410;
					case 301:
						array4[5] = array5[2];
						num = 320;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 306;
					case 306:
						array2[14] = (byte)num6;
						num = 161;
						goto IL_2414_2;
					case 335:
						array[20] = (byte)num2;
						v43NRpPayHUgPa6YLV();
						if (!j4qeRL0KwZjGCj4k0p())
						{
							num = 286;
							if (true)
							{
								goto IL_2414_2;
							}
							goto case 333;
						}
						num = 88;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 164;
					case 333:
						ImG16XLQT = (byte[])xksBb5M6yv78eyaNg7(memoryStream);
						num = 23;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 275;
					case 275:
						num2 = 52 - 21;
						num4 = 340;
						continue;
					case 4:
						array[6] = (byte)num2;
						num = 60;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 278;
					case 278:
						array2[7] = (byte)num6;
						num4 = 271;
						continue;
					case 234:
						array[3] = 155;
						num3 = 188;
						goto IL_2410;
					case 128:
						array[13] = 150;
						num3 = 18;
						goto IL_2410;
					case 229:
						array[12] = (byte)num2;
						num4 = 47;
						continue;
					case 221:
						array[9] = 162;
						num = 265;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 74;
					case 74:
						num2 = 165 - 55;
						num = 210;
						goto IL_2414_2;
					case 161:
						num6 = 215 - 71;
						num3 = 129;
						goto IL_2410;
					case 135:
						array[8] = 133;
						num = 230;
						goto IL_2414_2;
					case 206:
						array[23] = 125;
						num3 = 348;
						goto IL_2410;
					case 116:
						array[25] = 188;
						goto case 317;
					default:
						num = 317;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 239;
					case 239:
						num2 = 23 + 55;
						num = 335;
						goto IL_2414_2;
					case 72:
						num2 = 138 - 46;
						num3 = 164;
						goto IL_2410;
					case 183:
						num2 = 237 - 79;
						num = 303;
						goto IL_2414_2;
					case 262:
						num2 = 170 - 122;
						num = 17;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 109;
					case 130:
						array[29] = 0;
						num = 137;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 280;
					case 280:
						num6 = 52 + 30;
						num = 236;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 176;
					case 176:
						array2[11] = (byte)num6;
						num3 = 310;
						goto IL_2410;
					case 170:
						array2[12] = 125;
						num4 = 117;
						continue;
					case 137:
						num2 = 219 - 73;
						num = 136;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 203;
					case 203:
						array[10] = (byte)num2;
						num = 99;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 248;
					case 248:
						array[31] = 98;
						num4 = 326;
						continue;
					case 202:
						num6 = 130 - 43;
						num3 = 261;
						goto IL_2410;
					case 330:
						num2 = 82 + 31;
						num = 260;
						goto IL_2414_2;
					case 249:
						num2 = 154 - 51;
						num = 133;
						goto IL_2414_2;
					case 138:
						array2[2] = (byte)num6;
						num = 332;
						goto IL_2414_2;
					case 87:
						array[6] = (byte)num2;
						num = 84;
						goto IL_2414_2;
					case 211:
						array[9] = 147;
						num = 221;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 326;
					case 326:
						array3 = array;
						num = 61;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 357;
					case 357:
						array2[4] = 100;
						num4 = 146;
						continue;
					case 215:
						array2[1] = (byte)num6;
						num = 354;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 303;
					case 303:
						array[7] = (byte)num2;
						num3 = 85;
						goto IL_2410;
					case 144:
						array[22] = (byte)num2;
						num3 = 206;
						goto IL_2410;
					case 30:
						array2[6] = (byte)num6;
						num = 181;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 222;
					case 222:
						array2[9] = 121;
						num = 153;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 342;
					case 342:
						array2[2] = (byte)num6;
						goto case 88;
					case 164:
						array[1] = (byte)num2;
						num = 331;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 290;
					case 290:
						array[2] = 11;
						num3 = 234;
						goto IL_2410;
					case 111:
						num2 = 133 - 44;
						num = 304;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 204;
					case 103:
						array2[15] = 172;
						num3 = 280;
						goto IL_2410;
					case 47:
						array[12] = 156;
						num = 242;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 190;
					case 190:
						array[16] = 247;
						num4 = 33;
						continue;
					case 19:
						array2[14] = (byte)num6;
						num3 = 106;
						goto IL_2410;
					case 264:
						array[1] = (byte)num2;
						num = 91;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 178;
					case 178:
						array2[9] = (byte)num6;
						num = 93;
						goto IL_2414_2;
					case 64:
						array2[2] = (byte)num6;
						num4 = 325;
						continue;
					case 167:
						num2 = 241 - 80;
						num = 185;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 107;
					case 244:
						num6 = 151 - 64;
						num = 30;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 292;
					case 292:
						array[26] = (byte)num2;
						num = 284;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 289;
					case 289:
						num6 = 230 - 76;
						num3 = 44;
						goto IL_2410;
					case 346:
						array[9] = (byte)num2;
						num = 171;
						goto IL_2414_2;
					case 352:
						array[20] = 151;
						num3 = 263;
						goto IL_2410;
					case 68:
						array[26] = (byte)num2;
						num = 124;
						if (v43NRpPayHUgPa6YLV())
						{
							goto IL_2414_2;
						}
						goto case 328;
					case 174:
						array[7] = (byte)num2;
						num3 = 183;
						goto IL_2410;
					case 8:
						array[8] = 181;
						num4 = 27;
						continue;
					case 186:
						array = new byte[32];
						num3 = 122;
						goto IL_2410;
					case 75:
						num2 = 124 + 14;
						num4 = 92;
						continue;
					case 272:
						num2 = 93 + 107;
						num4 = 287;
						continue;
					case 230:
						num2 = 187 - 62;
						num = 308;
						if (true)
						{
							goto IL_2414_2;
						}
						goto case 336;
					case 336:
						array[31] = 117;
						num = 248;
						goto IL_2414_2;
					case 196:
						array2[6] = 226;
						num4 = 162;
						continue;
					case 296:
						num6 = 110 + 21;
						num = 163;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 62;
					case 34:
						num6 = 254 - 84;
						num4 = 36;
						continue;
					case 362:
						try
						{
							return (string)T4aMv9FajbbGvdPPu4(IxeCNAkNIvOap8eifR(), ImG16XLQT, P_0 + 4, num5);
						}
						catch
						{
						}
						return "";
					case 131:
						memoryStream = new MemoryStream();
						num = 145;
						if (!j4qeRL0KwZjGCj4k0p())
						{
							goto IL_2414_2;
						}
						goto case 295;
					case 105:
						rijndaelManaged = new RijndaelManaged();
						num = 94;
						if (0 == 0)
						{
							goto IL_2414_2;
						}
						goto case 65;
					}
					break;
					IL_00b9:
					array[6] = 121;
					num = 157;
					goto IL_2414_2;
					IL_00a1:
					array2[1] = (byte)num6;
					num3 = 353;
					goto IL_2410;
					IL_0051:
					array2[5] = (byte)num6;
					num3 = 166;
					goto IL_2410;
				}
				break;
			}
			goto IL_001a;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[nXn7GSjFJMtXKl9ioJ(typeof(Fp1dCKXtZq7MbI3HTI/nXn7GSjFJMtXKl9ioJ/nX2TZqOiDQZb40khFg<object>[]))]
		internal static string MKrbuojiF(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void diPFadtAL(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int rYkNOp1yk(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr JAgUetsYP(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void TrmCMRq9t()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void EKxEMKkre()
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
		internal static object ytqm81neS(object P_0)
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
		public static extern IntPtr JcwtxOtA4(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr yUCkljOs1(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int fAy0QIH6e(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int SOZGlkse9(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int WQpdRdE7Z(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr VvGQdKq2j(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int OjRMyiI4W(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[nXn7GSjFJMtXKl9ioJ(typeof(Fp1dCKXtZq7MbI3HTI/nXn7GSjFJMtXKl9ioJ/nX2TZqOiDQZb40khFg<object>[]))]
		private static byte[] sWteeUppk(string P_0)
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
		[nXn7GSjFJMtXKl9ioJ(typeof(Fp1dCKXtZq7MbI3HTI/nXn7GSjFJMtXKl9ioJ/nX2TZqOiDQZb40khFg<object>[]))]
		private static byte[] Vm5uJiMH4(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				165, 214, 88, 74, 184, 117, 147, 132, 46, 216,
				71, 187, 34, 213, 210, 139, 42, 98, 127, 213,
				175, 21, 30, 55, 122, 61, 1, 29, 128, 193,
				38, 170
			};
			rijndael.IV = new byte[16]
			{
				39, 58, 103, 225, 44, 127, 163, 34, 185, 60,
				182, 220, 27, 232, 212, 167
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] UdMpA6nn5()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] efkOBetTS()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] Rsxvr6ftc()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] aGF3YIPpg()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] YKW6UA06f()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] FjoDueyl5()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] fp9jx6ybV()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] jEg5jDqyO()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] tdI4okQHU()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] IyXrOtaDH()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public Fp1dCKXtZq7MbI3HTI()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type BkJnkPtKB1CK9tehMZ(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object cGUr1AJG3qn6RY5SYE(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object MkyMID6uDQZW3q1P6N(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void rqFy7WeSHmw9WWhDy6(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void V21x9BK2u4SUdxReF9(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long DY8Y0k9pFXbZigeKYZ(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object eaapV3LKpFPF6Uksv1(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object B7V8bZiQHnq1Am5g7j(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object iSlpxPqt1WFLaKPa1R(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Oy9PnFT64bIOcXwyNA(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object OPihC2oJHW0LkQVWa6(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void u0eHmWyRxUJ3niqAAE(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void UgCFsc5f6yXJLNWBw7(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object xksBb5M6yv78eyaNg7(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void THrNsDdrKZYeVO332l(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void dASGEXgicfMYUsjcq7(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int ArlPDWGa2XSWsbfV3h(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object IxeCNAkNIvOap8eifR()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object T4aMv9FajbbGvdPPu4(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool v43NRpPayHUgPa6YLV()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool j4qeRL0KwZjGCj4k0p()
		{
			return false;
		}
	}
}
namespace dmnPDia3QpO7eF9mfJ
{
	internal class OMIcTFEK4h0cVq7EVN
	{
		private static bool wo67yMw8JF;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void uCa5uxgzVwx2G()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public OMIcTFEK4h0cVq7EVN()
		{
		}
	}
}
