using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using System.Xml;
using Cummins.INSITE.Addins.SecurityManagerAPI;
using MSXML2;
using Microsoft.Win32;
using ToolSecurityServicesAPILib;
using VXnVuDdj3OCXj6QJV9;
using hAQqhgaNwvI0E0j0mV;

[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: CompilationRelaxations(8)]
[assembly: Guid("5b9bb64b-3abd-41ca-836b-0e2af2f43a8b")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyDelaySign(false)]
[assembly: ComVisible(true)]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyTitle("Security")]
[assembly: AssemblyTrademark("")]
[assembly: CLSCompliant(true)]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyProduct("Security")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace HB4x57TUvSVPqYJrYA
{
	internal static class aVLArWqRgMo1PVqfPu
	{
	}
}
namespace Cummins.INSITE.CNL.Security
{
	public class ToolSecurity : ILicenseLookup
	{
		private MSXML2.IXMLDOMDocument IMoo1PVqf;

		private ILicenseDocVerification FueLB4x57;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void GetLicenses(string bstrLicNames, out string bstrLics)
		{
			//IL_000a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0010: Expected O, but got Unknown
			//IL_003c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0042: Expected O, but got Unknown
			bstrLics = null;
			XmlDocument val = new XmlDocument();
			val.LoadXml(bstrLicNames);
			XmlNodeList elementsByTagName = val.GetElementsByTagName(L7tQalVfTx9dSjJ8wR.OYAayO5YB(0));
			foreach (XmlNode item in elementsByTagName)
			{
				XmlNode val2 = item;
				string innerText = val2.InnerText;
				string queryString = L7tQalVfTx9dSjJ8wR.OYAayO5YB(26) + innerText + L7tQalVfTx9dSjJ8wR.OYAayO5YB(54);
				MSXML2.IXMLDOMNode iXMLDOMNode = IMoo1PVqf.selectSingleNode(queryString);
				bstrLics += iXMLDOMNode.xml;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void LoadLicenses(object kernel, Guid componentClassId, string addinClassId = "")
		{
			FueLB4x57 = kernel as ILicenseDocVerification;
			IMoo1PVqf = new DOMDocumentClass();
			MSXML2.IXMLDOMNode newChild = IMoo1PVqf.createNode(MSXML2.DOMNodeType.NODE_ELEMENT, L7tQalVfTx9dSjJ8wR.OYAayO5YB(62), null);
			MSXML2.IXMLDOMNode iXMLDOMNode = IMoo1PVqf.appendChild(newChild);
			IEnumerator<string> enumerator = null;
			enumerator = (string.IsNullOrEmpty(addinClassId) ? m6EqKwQVw(componentClassId.ToString()) : m6EqKwQVw(componentClassId.ToString(), addinClassId));
			try
			{
				while (enumerator.MoveNext())
				{
					MSXML2.IXMLDOMDocument iXMLDOMDocument = new DOMDocumentClass();
					if (iXMLDOMDocument.load(enumerator.Current))
					{
						MSXML2.IXMLDOMNode iXMLDOMNode2 = iXMLDOMDocument;
						MSXML2.IXMLDOMNode firstChild = iXMLDOMNode2.firstChild;
						for (MSXML2.IXMLDOMNode iXMLDOMNode3 = firstChild.firstChild; iXMLDOMNode3 != null; iXMLDOMNode3 = iXMLDOMNode3.nextSibling)
						{
							MSXML2.IXMLDOMNode newChild2 = iXMLDOMNode3.cloneNode(deep: true);
							iXMLDOMNode.appendChild(newChild2);
						}
					}
				}
			}
			catch (Exception)
			{
				throw new Exception(L7tQalVfTx9dSjJ8wR.OYAayO5YB(88));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool IsValid(string licenseId)
		{
			bool result = false;
			MSXML2.IXMLDOMDocument iXMLDOMDocument = null;
			MSXML2.IXMLDOMNode iXMLDOMNode = null;
			MSXML2.IXMLDOMNode iXMLDOMNode2 = null;
			iXMLDOMNode2 = tqVTLArWR(ref iXMLDOMDocument);
			iXMLDOMNode = EJp7biAOI(iXMLDOMNode2, licenseId);
			FueLB4x57.VerifyLicense(iXMLDOMDocument as ToolSecurityServicesAPILib.IXMLDOMDocument);
			MSXML2.IXMLDOMElement iXMLDOMElement = iXMLDOMNode as MSXML2.IXMLDOMElement;
			object attribute = iXMLDOMElement.getAttribute(L7tQalVfTx9dSjJ8wR.OYAayO5YB(152));
			if (attribute.ToString() == L7tQalVfTx9dSjJ8wR.OYAayO5YB(170))
			{
				result = true;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public bool AreValid(Collection<string> licenseId)
		{
			bool result = true;
			Dictionary<string, bool> dictionary = new Dictionary<string, bool>();
			foreach (string item in licenseId)
			{
				dictionary.Add(item, value: false);
			}
			BatchValidate(dictionary);
			foreach (bool value in dictionary.Values)
			{
				if (!value)
				{
					result = false;
					break;
				}
				result = true;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void BatchValidate(Dictionary<string, bool> licenseBatch)
		{
			MSXML2.IXMLDOMDocument iXMLDOMDocument = null;
			MSXML2.IXMLDOMNode iXMLDOMNode = null;
			iXMLDOMNode = tqVTLArWR(ref iXMLDOMDocument);
			foreach (string key2 in licenseBatch.Keys)
			{
				EJp7biAOI(iXMLDOMNode, key2);
			}
			FueLB4x57.VerifyLicense(iXMLDOMDocument as ToolSecurityServicesAPILib.IXMLDOMDocument);
			MSXML2.IXMLDOMNodeList iXMLDOMNodeList = iXMLDOMDocument.selectNodes(L7tQalVfTx9dSjJ8wR.OYAayO5YB(182));
			foreach (MSXML2.IXMLDOMNode item in iXMLDOMNodeList)
			{
				MSXML2.IXMLDOMElement iXMLDOMElement = item as MSXML2.IXMLDOMElement;
				object attribute = iXMLDOMElement.getAttribute(L7tQalVfTx9dSjJ8wR.OYAayO5YB(212));
				bool value = (bool)attribute;
				object attribute2 = iXMLDOMElement.getAttribute(L7tQalVfTx9dSjJ8wR.OYAayO5YB(230));
				string key = attribute2 as string;
				licenseBatch[key] = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private MSXML2.IXMLDOMNode EJp7biAOI(MSXML2.IXMLDOMNode P_0, string P_1)
		{
			MSXML2.IXMLDOMNode iXMLDOMNode = null;
			string queryString = L7tQalVfTx9dSjJ8wR.OYAayO5YB(240) + P_1 + L7tQalVfTx9dSjJ8wR.OYAayO5YB(264);
			MSXML2.IXMLDOMNode iXMLDOMNode2 = IMoo1PVqf.selectSingleNode(queryString);
			if (iXMLDOMNode2 != null)
			{
				MSXML2.IXMLDOMNode newChild = iXMLDOMNode2.cloneNode(deep: true);
				return P_0.appendChild(newChild);
			}
			throw new InvalidOperationException(L7tQalVfTx9dSjJ8wR.OYAayO5YB(272));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static IEnumerator<string> m6EqKwQVw(string P_0, string P_1 = "")
		{
			Collection<string> collection = new Collection<string>();
			string text = "";
			string text2 = "";
			string text3 = "";
			text = L7tQalVfTx9dSjJ8wR.OYAayO5YB(360) + P_0 + L7tQalVfTx9dSjJ8wR.OYAayO5YB(366);
			if (string.IsNullOrEmpty(P_1))
			{
				text2 = Path.Combine(L7tQalVfTx9dSjJ8wR.OYAayO5YB(372), text);
			}
			else
			{
				text3 = P_1 + L7tQalVfTx9dSjJ8wR.OYAayO5YB(500);
				text2 = Path.Combine(L7tQalVfTx9dSjJ8wR.OYAayO5YB(518) + text3, text);
			}
			using (RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(text2))
			{
				if (registryKey != null)
				{
					string path = registryKey.GetValue(L7tQalVfTx9dSjJ8wR.OYAayO5YB(646)) as string;
					string text4 = registryKey.GetValue(L7tQalVfTx9dSjJ8wR.OYAayO5YB(682)) as string;
					char[] separator = new char[1] { '!' };
					string[] array = text4.Split(separator);
					string[] array2 = array;
					foreach (string path2 in array2)
					{
						string item = Path.Combine(path, path2);
						collection.Add(item);
					}
				}
			}
			return collection.GetEnumerator();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static MSXML2.IXMLDOMNode tqVTLArWR(ref MSXML2.IXMLDOMDocument P_0)
		{
			P_0 = new DOMDocumentClass();
			MSXML2.IXMLDOMNode newChild = P_0.createNode(MSXML2.DOMNodeType.NODE_ELEMENT, L7tQalVfTx9dSjJ8wR.OYAayO5YB(712), null);
			return P_0.appendChild(newChild);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ToolSecurity()
		{
			au5AUfj4kciDygW4iw.OmVjZr3zpGjTm();
			base..ctor();
		}
	}
}
namespace Cummins.INSITE.CNL.Security.Constants
{
	public static class SecurityConstants
	{
		public const string regKeyToOpen = "SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\AIF\\AddIns\\";
	}
}
internal class <Module>{49A4D0BB-6DD4-441F-A19A-DAD7B9BF95B4}
{
}
namespace MkXHXuLjP20JchtCWp
{
	internal class tO5YBgovQSD6CoQA2u
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module rvSVVPqYJ;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Qu9jZr33L47yI(int typemdt)
		{
			Type type = rvSVVPqYJ.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)rvSVVPqYJ.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public tO5YBgovQSD6CoQA2u()
		{
			au5AUfj4kciDygW4iw.OmVjZr3zpGjTm();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static tO5YBgovQSD6CoQA2u()
		{
			au5AUfj4kciDygW4iw.OmVjZr3zpGjTm();
			rvSVVPqYJ = typeof(tO5YBgovQSD6CoQA2u).Assembly.ManifestModule;
		}
	}
}
namespace hAQqhgaNwvI0E0j0mV
{
	internal class L7tQalVfTx9dSjJ8wR
	{
		internal class NBE3EVCGSKCquAOCmd : Attribute
		{
			internal class ealuq50owhNJ9dNRAD<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public ealuq50owhNJ9dNRAD()
				{
					au5AUfj4kciDygW4iw.OmVjZr3zpGjTm();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[NBE3EVCGSKCquAOCmd(typeof(L7tQalVfTx9dSjJ8wR/NBE3EVCGSKCquAOCmd/ealuq50owhNJ9dNRAD<object>[]))]
			public NBE3EVCGSKCquAOCmd(object P_0)
			{
				au5AUfj4kciDygW4iw.OmVjZr3zpGjTm();
				base..ctor();
			}
		}

		internal class qjmFIoRPm2k9hmj7Fb
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[NBE3EVCGSKCquAOCmd(typeof(L7tQalVfTx9dSjJ8wR/NBE3EVCGSKCquAOCmd/ealuq50owhNJ9dNRAD<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (jhOma4lhv(Convert.ToBase64String(typeof(L7tQalVfTx9dSjJ8wR).Assembly.GetName().GetPublicKeyToken()), L7tQalVfTx9dSjJ8wR.OYAayO5YB(738)) != L7tQalVfTx9dSjJ8wR.OYAayO5YB(744))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[NBE3EVCGSKCquAOCmd(typeof(L7tQalVfTx9dSjJ8wR/NBE3EVCGSKCquAOCmd/ealuq50owhNJ9dNRAD<object>[]))]
			internal static string jhOma4lhv(string P_0, string P_1)
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
			public qjmFIoRPm2k9hmj7Fb()
			{
				au5AUfj4kciDygW4iw.OmVjZr3zpGjTm();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint sHdJrjZ93ukaviYo0N([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr KCAjNxYcy3U5qc98QH();

		internal struct Lxth06FSwuunOIi08n
		{
			internal bool l5gXLSLFC;

			internal byte[] l6qwV6QBL;
		}

		[Flags]
		private enum i7boqTcRpPU12xWZAj
		{

		}

		private static byte[] gXj86QJV9;

		private static object yRVn5uJFp;

		private static int rX12Q5v6D;

		private static bool vgatjRTPB;

		private static int v1h1TyhsB;

		internal static sHdJrjZ93ukaviYo0N H9lr0Bk9d;

		private static IntPtr xhHW1e1g6;

		private static byte[] AL2GV6fX9;

		internal static Hashtable Ae7iN5whs;

		private static IntPtr AMVejnYYy;

		private static long afBEV5Qo1;

		private static IntPtr xiXPEaJZJ;

		private static SortedList XhZuRnWZ9;

		private static int[] ytdgt7nR3;

		private static byte[] aqT59ZsUJ;

		private static bool E1vxkU9WX;

		private static int LSDDoK9xQ;

		private static long vTW4lk6dr;

		private static int LV1pVk0c6;

		private static byte[] NyNMSnpPF;

		internal static sHdJrjZ93ukaviYo0N I9DOSWqOH;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static L7tQalVfTx9dSjJ8wR()
		{
			gXj86QJV9 = new byte[0];
			NyNMSnpPF = new byte[0];
			aqT59ZsUJ = new byte[0];
			AL2GV6fX9 = new byte[0];
			xiXPEaJZJ = IntPtr.Zero;
			AMVejnYYy = IntPtr.Zero;
			yRVn5uJFp = new string[0];
			ytdgt7nR3 = new int[0];
			rX12Q5v6D = 1;
			vgatjRTPB = false;
			XhZuRnWZ9 = new SortedList();
			v1h1TyhsB = 0;
			afBEV5Qo1 = 0L;
			I9DOSWqOH = null;
			H9lr0Bk9d = null;
			vTW4lk6dr = 0L;
			LV1pVk0c6 = 0;
			E1vxkU9WX = false;
			LSDDoK9xQ = 0;
			xhHW1e1g6 = IntPtr.Zero;
			Ae7iN5whs = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void k0fjZr31VXaNX()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[NBE3EVCGSKCquAOCmd(typeof(L7tQalVfTx9dSjJ8wR/NBE3EVCGSKCquAOCmd/ealuq50owhNJ9dNRAD<object>[]))]
		static string OYAayO5YB(int P_0)
		{
			int num = 57;
			byte[] array2 = default(byte[]);
			int num6 = default(int);
			byte[] array = default(byte[]);
			int num5 = default(int);
			BinaryReader binaryReader = default(BinaryReader);
			byte[] array3 = default(byte[]);
			byte[] array4 = default(byte[]);
			CryptoStream cryptoStream = default(CryptoStream);
			MemoryStream memoryStream = default(MemoryStream);
			ICryptoTransform transform = default(ICryptoTransform);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array6 = default(byte[]);
			byte[] array5 = default(byte[]);
			int num4 = default(int);
			while (true)
			{
				int num2 = num;
				while (true)
				{
					IL_09ab:
					int num3 = num2;
					while (true)
					{
						switch (num3)
						{
						case 271:
							break;
						case 215:
							array2[3] = (byte)num6;
							num3 = 223;
							continue;
						case 303:
							array[8] = (byte)num5;
							num3 = 61;
							continue;
						case 119:
							goto IL_0064;
						case 192:
							array2[31] = 123;
							num3 = 169;
							continue;
						case 203:
							array[13] = (byte)num5;
							num3 = 59;
							continue;
						case 234:
							num6 = 238 - 79;
							num3 = 29;
							continue;
						case 103:
							goto IL_00d0;
						case 317:
							array2[19] = (byte)num6;
							num2 = 96;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 180;
						case 180:
							num6 = 52 + 104;
							num2 = 250;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 110;
						case 110:
							array2[15] = (byte)num6;
							num = 236;
							goto end_IL_09af;
						case 225:
							num6 = 58 + 122;
							num3 = 68;
							continue;
						case 111:
							num5 = 131 - 43;
							num = 178;
							goto end_IL_09af;
						case 322:
							num5 = 79 + 85;
							num3 = 72;
							continue;
						case 202:
							array2[7] = (byte)num6;
							goto case 58;
						case 90:
							array[15] = 138;
							num = 268;
							goto end_IL_09af;
						case 127:
							num6 = 152 - 117;
							num2 = 23;
							if (ysBTLST6ap0Cv2wmXS())
							{
								goto IL_09ab;
							}
							goto case 94;
						case 60:
							array2[31] = (byte)num6;
							num = 51;
							goto end_IL_09af;
						case 263:
							array2[0] = 134;
							num2 = 25;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 73;
						case 73:
							EY1Dvv1LaHdwPkBIZZ(pxnVJVt06Xux3o71iu(binaryReader), 0L);
							num2 = 46;
							goto IL_09ab;
						case 287:
							array2[20] = 136;
							num3 = 308;
							continue;
						case 1:
							num6 = 60 + 19;
							num = 71;
							goto end_IL_09af;
						case 274:
							num6 = 205 - 68;
							num3 = 239;
							continue;
						case 270:
							array2[30] = (byte)num6;
							num2 = 163;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 297;
						case 297:
							num6 = 35 + 99;
							num2 = 43;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 207;
						case 207:
							array2[20] = (byte)num6;
							num2 = 287;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 37;
						case 37:
							num6 = 89 + 74;
							num = 99;
							goto end_IL_09af;
						case 158:
							num6 = 145 + 7;
							num3 = 100;
							continue;
						case 97:
							array2[30] = (byte)num6;
							num3 = 192;
							continue;
						case 48:
							array2[21] = (byte)num6;
							num2 = 55;
							goto IL_09ab;
						case 123:
							num6 = 96 - 67;
							num2 = 328;
							if (ysBTLST6ap0Cv2wmXS())
							{
								goto IL_09ab;
							}
							goto case 241;
						case 241:
							array2[6] = 108;
							num2 = 251;
							goto IL_09ab;
						case 145:
							array[11] = (byte)num5;
							num3 = 243;
							continue;
						case 168:
							num6 = 15 + 73;
							num3 = 79;
							continue;
						case 18:
						case 272:
							num6 = 183 - 61;
							num2 = 6;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 115;
						case 115:
							array3[13] = array4[6];
							num = 113;
							goto end_IL_09af;
						case 169:
							num6 = 66 + 92;
							num2 = 27;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 200;
						case 200:
							array2[24] = 140;
							num2 = 204;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 118;
						case 14:
							array2[16] = (byte)num6;
							num2 = 295;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 239;
						case 239:
							array2[12] = (byte)num6;
							num2 = 84;
							goto IL_09ab;
						case 249:
							num6 = 111 + 86;
							num3 = 296;
							continue;
						case 31:
							num6 = 68 - 55;
							num2 = 82;
							if (ysBTLST6ap0Cv2wmXS())
							{
								goto IL_09ab;
							}
							goto case 36;
						case 36:
							if (array4.Length > 0)
							{
								num2 = 11;
								if (0 == 0)
								{
									goto IL_09ab;
								}
								goto case 74;
							}
							goto case 341;
						case 74:
							num5 = 26 + 29;
							num2 = 4;
							goto IL_09ab;
						case 99:
							array2[18] = (byte)num6;
							num2 = 114;
							goto IL_09ab;
						case 231:
							array[7] = (byte)num5;
							num2 = 164;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 254;
						case 254:
							array2[20] = 98;
							num3 = 155;
							continue;
						case 113:
							array3[15] = array4[7];
							num2 = 341;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 94;
						case 64:
							num6 = 53 + 62;
							num2 = 60;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 122;
						case 122:
							array2[18] = (byte)num6;
							num = 281;
							goto end_IL_09af;
						case 161:
							array2[24] = (byte)num6;
							num2 = 309;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 199;
						case 199:
							array2 = new byte[32];
							num = 168;
							goto end_IL_09af;
						case 66:
							num6 = 95 + 51;
							num = 215;
							goto end_IL_09af;
						case 191:
							array2[14] = (byte)num6;
							num = 159;
							goto end_IL_09af;
						case 11:
							array3[1] = array4[0];
							num3 = 279;
							continue;
						case 311:
							num5 = 150 - 44;
							num2 = 293;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 216;
						case 216:
							array[3] = (byte)num5;
							num3 = 111;
							continue;
						case 94:
							array[4] = 234;
							num3 = 275;
							continue;
						case 315:
							array[12] = (byte)num5;
							num2 = 310;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 101;
						case 101:
							num6 = 12 + 113;
							num = 146;
							goto end_IL_09af;
						case 289:
							array3[7] = array4[3];
							num = 22;
							goto end_IL_09af;
						case 81:
							array[1] = (byte)num5;
							num2 = 153;
							goto IL_09ab;
						case 39:
							array4 = (byte[])sSI1dpixwhfM1epV5J(KgoxShZCiPeAGmnM48(wq3S5M7oN9QIbjLkMO(typeof(L7tQalVfTx9dSjJ8wR).TypeHandle).Assembly));
							num3 = 144;
							continue;
						case 12:
							num5 = 191 - 63;
							num2 = 303;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 343;
						case 65:
							array[15] = (byte)num5;
							num2 = 90;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 160;
						case 160:
							num6 = 50 + 113;
							num3 = 130;
							continue;
						case 140:
							array2[21] = 175;
							num = 240;
							goto end_IL_09af;
						case 324:
							num6 = 94 + 13;
							num3 = 237;
							continue;
						case 232:
							goto IL_0793;
						case 302:
							cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
							num = 117;
							goto end_IL_09af;
						case 197:
							num6 = 104 + 77;
							num2 = 212;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 22;
						case 22:
							array3[9] = array4[4];
							num2 = 162;
							goto IL_09ab;
						case 292:
							array2[11] = 149;
							num2 = 173;
							goto IL_09ab;
						case 75:
							array2[18] = (byte)num6;
							num2 = 221;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 77;
						case 77:
							num6 = 180 - 60;
							num = 306;
							goto end_IL_09af;
						case 267:
							MqMtddYVBEtVtWCX5n(binaryReader);
							num2 = 135;
							goto IL_09ab;
						case 329:
							num6 = 41 + 99;
							num2 = 257;
							goto IL_09ab;
						case 8:
							array2[3] = 93;
							num3 = 271;
							continue;
						case 195:
							num5 = 49 + 104;
							num2 = 276;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 107;
						case 107:
							num6 = 218 - 72;
							num = 14;
							goto end_IL_09af;
						case 93:
							num5 = 28 + 46;
							num2 = 15;
							if (ysBTLST6ap0Cv2wmXS())
							{
								goto IL_09ab;
							}
							goto case 88;
						case 88:
							num6 = 172 - 57;
							num3 = 128;
							continue;
						case 139:
							array[14] = 250;
							num2 = 278;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 170;
						case 170:
							num5 = 205 - 68;
							num3 = 290;
							continue;
						case 52:
							num5 = 4 + 47;
							num2 = 203;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 282;
						case 282:
							array2[25] = 115;
							goto case 13;
						default:
							num3 = 13;
							continue;
						case 10:
							array[0] = 146;
							num = 49;
							goto end_IL_09af;
						case 89:
							array2[17] = (byte)num6;
							num2 = 31;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 330;
						case 330:
							num6 = 241 - 80;
							num = 229;
							goto end_IL_09af;
						case 211:
							num6 = 217 - 72;
							num2 = 122;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 44;
						case 50:
							array[5] = 119;
							num3 = 116;
							continue;
						case 233:
							num6 = 157 - 52;
							num2 = 70;
							if (ysBTLST6ap0Cv2wmXS())
							{
								goto IL_09ab;
							}
							goto case 6;
						case 6:
							array2[1] = (byte)num6;
							num2 = 286;
							goto IL_09ab;
						case 68:
							array2[31] = (byte)num6;
							num = 175;
							goto end_IL_09af;
						case 210:
							array2[28] = 12;
							num3 = 327;
							continue;
						case 223:
							num6 = 168 - 56;
							num = 171;
							goto end_IL_09af;
						case 194:
							array2[2] = (byte)num6;
							num2 = 8;
							if (ysBTLST6ap0Cv2wmXS())
							{
								goto IL_09ab;
							}
							goto case 231;
						case 331:
							array[9] = 88;
							num3 = 185;
							continue;
						case 209:
							num6 = 160 - 62;
							num = 97;
							goto end_IL_09af;
						case 290:
							array[11] = (byte)num5;
							num2 = 17;
							goto IL_09ab;
						case 305:
							array2[2] = (byte)num6;
							num2 = 238;
							goto IL_09ab;
						case 217:
							array2[30] = (byte)num6;
							num2 = 209;
							goto IL_09ab;
						case 265:
							num6 = 168 - 56;
							num = 201;
							goto end_IL_09af;
						case 20:
							array[1] = 135;
							num2 = 177;
							if (ysBTLST6ap0Cv2wmXS())
							{
								goto IL_09ab;
							}
							goto case 326;
						case 326:
							array2[28] = 72;
							num = 112;
							goto end_IL_09af;
						case 147:
							array2[3] = (byte)num6;
							num2 = 66;
							if (ysBTLST6ap0Cv2wmXS())
							{
								goto IL_09ab;
							}
							goto case 294;
						case 294:
							array2[25] = (byte)num6;
							num = 219;
							goto end_IL_09af;
						case 30:
							array[0] = (byte)num5;
							num2 = 26;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 49;
						case 49:
							num5 = 27 + 50;
							num3 = 30;
							continue;
						case 204:
							num6 = 97 + 109;
							num3 = 161;
							continue;
						case 187:
							array2[13] = (byte)num6;
							num2 = 156;
							goto IL_09ab;
						case 226:
							transform = (ICryptoTransform)pCJirI3ERJ3RSPi5UU(rijndaelManaged, array6, array3);
							num = 152;
							goto end_IL_09af;
						case 236:
							array2[15] = 93;
							num = 101;
							goto end_IL_09af;
						case 319:
							array[9] = 4;
							num3 = 150;
							continue;
						case 235:
							num5 = 9 - 3;
							num = 118;
							goto end_IL_09af;
						case 253:
							array2[5] = (byte)num6;
							num2 = 102;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 78;
						case 78:
							array2[10] = 70;
							num2 = 339;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 321;
						case 154:
							num6 = 203 - 67;
							num = 110;
							goto end_IL_09af;
						case 285:
							array[9] = (byte)num5;
							num2 = 196;
							goto IL_09ab;
						case 133:
							array2[17] = (byte)num6;
							num2 = 45;
							goto IL_09ab;
						case 190:
							array2[10] = 39;
							num = 292;
							goto end_IL_09af;
						case 259:
							array2[9] = 254;
							num = 78;
							goto end_IL_09af;
						case 165:
							num5 = 254 - 84;
							num2 = 216;
							goto IL_09ab;
						case 193:
							array2[27] = 161;
							num2 = 137;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 196;
						case 196:
							array[9] = 92;
							num2 = 319;
							goto IL_09ab;
						case 146:
							array2[15] = (byte)num6;
							num3 = 107;
							continue;
						case 137:
							array2[27] = 224;
							num2 = 210;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 307;
						case 307:
							array2[12] = 110;
							num3 = 346;
							continue;
						case 156:
							array2[13] = 55;
							num2 = 95;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 190;
						case 129:
							array2[4] = (byte)num6;
							num2 = 291;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 3;
						case 346:
							array2[12] = 108;
							num3 = 246;
							continue;
						case 323:
							array2[19] = 108;
							num2 = 176;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 26;
						case 25:
							num6 = 107 + 53;
							num3 = 245;
							continue;
						case 150:
							array[10] = 118;
							num = 83;
							goto end_IL_09af;
						case 208:
							array2[26] = 84;
							num2 = 158;
							goto IL_09ab;
						case 47:
							GYweacOAfakg19uhsi(cryptoStream);
							num3 = 149;
							continue;
						case 251:
							num6 = 124 - 76;
							num2 = 0;
							if (ysBTLST6ap0Cv2wmXS())
							{
								goto IL_09ab;
							}
							goto case 185;
						case 29:
							array2[5] = (byte)num6;
							num2 = 85;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 293;
						case 293:
							array[6] = (byte)num5;
							num2 = 333;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 46;
						case 46:
							Vvstf6QWu6usfYjwYB(true);
							num2 = 213;
							goto IL_09ab;
						case 116:
							num5 = 116 + 47;
							num2 = 244;
							goto IL_09ab;
						case 343:
							array3[5] = array4[2];
							num3 = 289;
							continue;
						case 175:
							array6 = array2;
							num2 = 2;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 15;
						case 15:
							array[12] = (byte)num5;
							num2 = 316;
							goto IL_09ab;
						case 21:
							num5 = 115 + 44;
							num3 = 145;
							continue;
						case 301:
							array2[30] = 132;
							num3 = 180;
							continue;
						case 125:
							array2[8] = (byte)num6;
							num2 = 227;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 188;
						case 188:
							array2[24] = 20;
							num3 = 283;
							continue;
						case 44:
							num6 = 250 - 83;
							num2 = 5;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 41;
						case 41:
							array2[23] = 88;
							num2 = 273;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 19;
						case 82:
							array2[17] = (byte)num6;
							num = 211;
							goto end_IL_09af;
						case 26:
							num5 = 185 + 12;
							num = 91;
							goto end_IL_09af;
						case 149:
							aqT59ZsUJ = (byte[])vUmYwlE2ryqOmDgr5s(memoryStream);
							num3 = 321;
							continue;
						case 55:
							num6 = 26 + 79;
							num2 = 76;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 276;
						case 276:
							array[3] = (byte)num5;
							num2 = 298;
							if (ysBTLST6ap0Cv2wmXS())
							{
								goto IL_09ab;
							}
							goto case 185;
						case 171:
							array2[4] = (byte)num6;
							num = 124;
							goto end_IL_09af;
						case 144:
							if (array4 != null)
							{
								num3 = 36;
								continue;
							}
							goto case 341;
						case 162:
							array3[11] = array4[5];
							num2 = 115;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 309;
						case 198:
							num5 = 8 + 72;
							num2 = 262;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 151;
						case 151:
							array[1] = 136;
							num3 = 9;
							continue;
						case 114:
							num6 = 139 - 46;
							num2 = 75;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 134;
						case 134:
							array2[20] = 202;
							num = 288;
							goto end_IL_09af;
						case 316:
							num5 = 190 - 63;
							num3 = 132;
							continue;
						case 57:
							if (aqT59ZsUJ.Length == 0)
							{
								num = 16;
								goto end_IL_09af;
							}
							goto case 135;
						case 117:
							awwjHk904tTB5pUFPk(cryptoStream, array5, 0, array5.Length);
							num2 = 47;
							goto IL_09ab;
						case 284:
							array2[20] = (byte)num6;
							num = 134;
							goto end_IL_09af;
						case 132:
							array[12] = (byte)num5;
							num3 = 131;
							continue;
						case 252:
							array2[12] = (byte)num6;
							num = 307;
							goto end_IL_09af;
						case 33:
							array2[10] = 21;
							num2 = 190;
							goto IL_09ab;
						case 148:
							num6 = 254 - 84;
							num2 = 207;
							if (ysBTLST6ap0Cv2wmXS())
							{
								goto IL_09ab;
							}
							goto case 219;
						case 335:
							array[7] = (byte)num5;
							num = 34;
							goto end_IL_09af;
						case 54:
							array2[27] = (byte)num6;
							num3 = 193;
							continue;
						case 28:
							array2[4] = 46;
							num3 = 234;
							continue;
						case 240:
							num6 = 93 + 79;
							num2 = 299;
							if (ysBTLST6ap0Cv2wmXS())
							{
								goto IL_09ab;
							}
							goto case 302;
						case 298:
							num5 = 171 + 51;
							num3 = 280;
							continue;
						case 296:
							array2[8] = (byte)num6;
							num2 = 342;
							if (ysBTLST6ap0Cv2wmXS())
							{
								goto IL_09ab;
							}
							goto case 116;
						case 124:
							num6 = 81 + 34;
							num = 129;
							goto end_IL_09af;
						case 92:
							num6 = 232 - 77;
							num2 = 300;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 121;
						case 121:
							array2[9] = (byte)num6;
							num = 80;
							goto end_IL_09af;
						case 278:
							num5 = 153 - 51;
							num = 65;
							goto end_IL_09af;
						case 4:
							array[5] = (byte)num5;
							num = 50;
							goto end_IL_09af;
						case 248:
							array2[19] = (byte)num6;
							num3 = 323;
							continue;
						case 104:
							array[13] = (byte)num5;
							num3 = 32;
							continue;
						case 16:
							binaryReader = new BinaryReader((Stream)R0E8CwyJesRPPt7sPJ(wq3S5M7oN9QIbjLkMO(typeof(L7tQalVfTx9dSjJ8wR).TypeHandle).Assembly, "VMJB17kAuhwb9JZJtV.Pdmbkv8NDxYt7YKLeV"));
							num = 73;
							goto end_IL_09af;
						case 7:
							array[11] = (byte)num5;
							num2 = 21;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 334;
						case 334:
							num6 = 78 + 95;
							num3 = 202;
							continue;
						case 76:
							array2[21] = (byte)num6;
							num3 = 324;
							continue;
						case 23:
							array2[29] = (byte)num6;
							num2 = 182;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 302;
						case 155:
							array2[20] = 95;
							num2 = 148;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 273;
						case 273:
							array2[23] = 170;
							num = 220;
							goto end_IL_09af;
						case 213:
							array5 = (byte[])KXCcCiIrgdseuOsM41(binaryReader, (int)yVrKusRKSMv1wOUM8d(pxnVJVt06Xux3o71iu(binaryReader)));
							num2 = 199;
							goto IL_09ab;
						case 262:
							array[3] = (byte)num5;
							num2 = 195;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 128;
						case 128:
							array2[14] = (byte)num6;
							num2 = 266;
							goto IL_09ab;
						case 102:
							array2[5] = 139;
							num2 = 141;
							goto IL_09ab;
						case 173:
							array2[11] = 111;
							num = 260;
							goto end_IL_09af;
						case 153:
							num5 = 171 - 57;
							num = 261;
							goto end_IL_09af;
						case 308:
							num6 = 40 + 118;
							num2 = 284;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 230;
						case 230:
							array3 = array;
							num3 = 39;
							continue;
						case 13:
							num6 = 74 + 39;
							num3 = 172;
							continue;
						case 108:
							array[14] = 161;
							num2 = 325;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 256;
						case 256:
							array2[5] = (byte)num6;
							num2 = 214;
							goto IL_09ab;
						case 205:
							num6 = 218 - 72;
							num3 = 320;
							continue;
						case 245:
							array2[0] = (byte)num6;
							num2 = 205;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 29;
						case 56:
							num5 = 3 + 2;
							num2 = 258;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 126;
						case 126:
							array[2] = (byte)num5;
							num3 = 67;
							continue;
						case 189:
							num5 = 177 - 59;
							num3 = 126;
							continue;
						case 59:
							num5 = 114 - 67;
							num = 104;
							goto end_IL_09af;
						case 34:
							num5 = 220 - 73;
							num2 = 87;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 79;
						case 79:
							array2[0] = (byte)num6;
							num2 = 44;
							goto IL_09ab;
						case 120:
							array[2] = (byte)num5;
							num2 = 165;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 91;
						case 91:
							array[0] = (byte)num5;
							num2 = 20;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 273;
						case 178:
							array[3] = (byte)num5;
							num2 = 198;
							goto IL_09ab;
						case 345:
							array[0] = (byte)num5;
							num2 = 10;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 166;
						case 166:
							array2[14] = (byte)num6;
							num3 = 88;
							continue;
						case 325:
							num5 = 88 + 82;
							num3 = 69;
							continue;
						case 279:
							array3[3] = array4[1];
							num3 = 343;
							continue;
						case 176:
							num6 = 240 - 80;
							num3 = 317;
							continue;
						case 264:
							array2[29] = (byte)num6;
							num3 = 184;
							continue;
						case 318:
							num6 = 249 - 83;
							num = 143;
							goto end_IL_09af;
						case 344:
							array2[19] = 211;
							num2 = 254;
							if (ysBTLST6ap0Cv2wmXS())
							{
								goto IL_09ab;
							}
							goto case 342;
						case 229:
							array2[4] = (byte)num6;
							num = 28;
							goto end_IL_09af;
						case 291:
							array2[4] = 140;
							num = 330;
							goto end_IL_09af;
						case 224:
							array2[24] = (byte)num6;
							num = 188;
							goto end_IL_09af;
						case 295:
							num6 = 23 + 42;
							num2 = 42;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 227;
						case 83:
							array[10] = 110;
							num2 = 314;
							if (ysBTLST6ap0Cv2wmXS())
							{
								goto IL_09ab;
							}
							goto case 143;
						case 143:
							array2[8] = (byte)num6;
							num2 = 183;
							goto IL_09ab;
						case 214:
							num6 = 192 - 64;
							num3 = 253;
							continue;
						case 106:
							num6 = 179 - 59;
							num2 = 305;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 299;
						case 337:
							MgNm3Nj7lbfmN4U7Tt(cryptoStream);
							num2 = 267;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 109;
						case 109:
							num6 = 135 - 45;
							num2 = 248;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 304;
						case 304:
							array[4] = 116;
							num3 = 94;
							continue;
						case 138:
							array[13] = 27;
							num2 = 52;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 112;
						case 112:
							num6 = 254 - 84;
							num3 = 242;
							continue;
						case 218:
							num5 = 178 - 59;
							num = 53;
							goto end_IL_09af;
						case 69:
							array[14] = (byte)num5;
							num = 139;
							goto end_IL_09af;
						case 96:
							array2[19] = 100;
							num3 = 344;
							continue;
						case 183:
							num6 = 187 - 62;
							num2 = 125;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 299;
						case 299:
							array2[22] = (byte)num6;
							num2 = 160;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 266;
						case 266:
							array2[14] = 180;
							num3 = 154;
							continue;
						case 309:
							num6 = 173 - 57;
							num3 = 224;
							continue;
						case 179:
							array[15] = (byte)num5;
							num3 = 56;
							continue;
						case 40:
							array2[26] = 129;
							num = 208;
							goto end_IL_09af;
						case 24:
							array2[29] = 112;
							num2 = 35;
							goto IL_09ab;
						case 280:
							array[3] = (byte)num5;
							num3 = 218;
							continue;
						case 27:
							array2[31] = (byte)num6;
							num2 = 64;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 5;
						case 5:
							array2[0] = (byte)num6;
							num3 = 329;
							continue;
						case 38:
							array[5] = 117;
							num2 = 74;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 159;
						case 159:
							num6 = 55 + 21;
							num2 = 166;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 45;
						case 45:
							num6 = 182 - 60;
							num2 = 89;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 163;
						case 163:
							array2[30] = 172;
							num2 = 301;
							if (ysBTLST6ap0Cv2wmXS())
							{
								goto IL_09ab;
							}
							goto case 310;
						case 95:
							num6 = 152 - 50;
							num3 = 191;
							continue;
						case 222:
							num5 = 159 + 16;
							num2 = 120;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 257;
						case 257:
							array2[0] = (byte)num6;
							num3 = 263;
							continue;
						case 131:
							num5 = 206 - 68;
							num3 = 315;
							continue;
						case 0:
							array2[6] = (byte)num6;
							num = 334;
							goto end_IL_09af;
						case 67:
							array[2] = 92;
							num2 = 222;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 320;
						case 320:
							array2[1] = (byte)num6;
							num2 = 232;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 246;
						case 246:
							array2[12] = 157;
							num2 = 157;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 275;
						case 275:
							array[5] = 122;
							num2 = 38;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 43;
						case 43:
							array2[21] = (byte)num6;
							num = 140;
							goto end_IL_09af;
						case 206:
							array2[22] = 197;
							num3 = 41;
							continue;
						case 186:
							num5 = 147 - 49;
							num3 = 345;
							continue;
						case 342:
							num6 = 190 - 63;
							num3 = 121;
							continue;
						case 312:
							array2[8] = (byte)num6;
							num2 = 249;
							goto IL_09ab;
						case 300:
							array2[13] = (byte)num6;
							num2 = 313;
							if (ysBTLST6ap0Cv2wmXS())
							{
								goto IL_09ab;
							}
							goto case 250;
						case 250:
							array2[30] = (byte)num6;
							num2 = 247;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 141;
						case 313:
							num6 = 125 - 41;
							num = 187;
							goto end_IL_09af;
						case 87:
							array[7] = (byte)num5;
							num = 322;
							goto end_IL_09af;
						case 269:
							array[8] = 84;
							num2 = 12;
							goto IL_09ab;
						case 105:
							num6 = 235 - 78;
							num = 147;
							goto end_IL_09af;
						case 332:
							array2[25] = 93;
							num2 = 3;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 321;
						case 321:
							MgNm3Nj7lbfmN4U7Tt(memoryStream);
							num = 337;
							goto end_IL_09af;
						case 185:
							num5 = 222 - 74;
							num3 = 285;
							continue;
						case 182:
							num6 = 95 + 47;
							num2 = 270;
							goto IL_09ab;
						case 9:
							num5 = 51 - 32;
							num2 = 119;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 277;
						case 277:
							array[8] = 105;
							num2 = 331;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 3;
						case 3:
							array2[26] = 91;
							num2 = 40;
							goto IL_09ab;
						case 201:
							array2[29] = (byte)num6;
							num = 127;
							goto end_IL_09af;
						case 19:
							array2[6] = 209;
							num2 = 241;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 220;
						case 220:
							array2[23] = 107;
							num = 77;
							goto end_IL_09af;
						case 177:
							num5 = 187 - 62;
							num2 = 81;
							if (ysBTLST6ap0Cv2wmXS())
							{
								goto IL_09ab;
							}
							goto case 155;
						case 306:
							array2[24] = (byte)num6;
							num2 = 200;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 237;
						case 237:
							array2[21] = (byte)num6;
							num2 = 297;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 333;
						case 333:
							num5 = 136 - 45;
							num = 231;
							goto end_IL_09af;
						case 63:
							gXF7yQ5XoDtEqIngxA(rijndaelManaged, CipherMode.CBC);
							num2 = 226;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 260;
						case 260:
							array2[11] = 0;
							num2 = 274;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 72;
						case 72:
							array[7] = (byte)num5;
							num3 = 269;
							continue;
						case 338:
							array2[18] = (byte)num6;
							num2 = 37;
							goto IL_09ab;
						case 86:
							array2[7] = 110;
							num2 = 142;
							goto IL_09ab;
						case 142:
							array2[8] = 120;
							num2 = 318;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 283;
						case 283:
							num6 = 119 + 120;
							num2 = 294;
							goto IL_09ab;
						case 227:
							num6 = 61 + 74;
							num2 = 312;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 333;
						case 164:
							array[7] = 169;
							num2 = 167;
							goto IL_09ab;
						case 340:
							array2[3] = 150;
							num = 105;
							goto end_IL_09af;
						case 71:
							array2[25] = (byte)num6;
							num3 = 282;
							continue;
						case 219:
							array2[25] = 137;
							num3 = 1;
							continue;
						case 42:
							array2[16] = (byte)num6;
							num = 197;
							goto end_IL_09af;
						case 32:
							num5 = 126 - 42;
							num2 = 103;
							goto IL_09ab;
						case 80:
							array2[9] = 155;
							num2 = 259;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 141;
						case 141:
							array2[5] = 114;
							num3 = 19;
							continue;
						case 157:
							array2[13] = 187;
							num3 = 92;
							continue;
						case 268:
							num5 = 17 + 107;
							num2 = 179;
							goto IL_09ab;
						case 244:
							array[5] = (byte)num5;
							num2 = 181;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 53;
						case 53:
							array[4] = (byte)num5;
							num3 = 304;
							continue;
						case 238:
							num6 = 221 + 27;
							num2 = 194;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 98;
						case 98:
							num6 = 211 - 70;
							num2 = 54;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 30;
						case 17:
							num5 = 149 - 49;
							num2 = 7;
							goto IL_09ab;
						case 327:
							array2[28] = 132;
							num2 = 326;
							if (ysBTLST6ap0Cv2wmXS())
							{
								goto IL_09ab;
							}
							goto case 228;
						case 228:
							num6 = 22 + 64;
							num2 = 133;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 118;
						case 118:
							array[15] = (byte)num5;
							num = 230;
							goto end_IL_09af;
						case 255:
							array2[10] = 98;
							num = 33;
							goto end_IL_09af;
						case 281:
							num6 = 92 + 10;
							num2 = 338;
							goto IL_09ab;
						case 242:
							array2[29] = (byte)num6;
							num2 = 24;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 167;
						case 167:
							num5 = 33 + 33;
							num3 = 335;
							continue;
						case 314:
							array[10] = 88;
							num2 = 170;
							if (0 == 0)
							{
								goto IL_09ab;
							}
							goto case 310;
						case 310:
							array[12] = 148;
							num = 138;
							goto end_IL_09af;
						case 84:
							num6 = 203 - 67;
							num = 252;
							goto end_IL_09af;
						case 85:
							num6 = 13 + 93;
							num2 = 256;
							goto IL_09ab;
						case 261:
							array[1] = (byte)num5;
							num3 = 136;
							continue;
						case 135:
							num4 = cZqgCHselvxOdIusdl(aqT59ZsUJ, P_0);
							num3 = 347;
							continue;
						case 130:
							array2[22] = (byte)num6;
							num3 = 206;
							continue;
						case 136:
							array[1] = 111;
							num3 = 151;
							continue;
						case 336:
							array[6] = 167;
							num3 = 311;
							continue;
						case 288:
							num6 = 118 + 82;
							num3 = 48;
							continue;
						case 174:
							array2[29] = (byte)num6;
							num2 = 265;
							goto IL_09ab;
						case 2:
							array = new byte[16];
							num3 = 186;
							continue;
						case 51:
							array2[31] = 145;
							num2 = 225;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 11;
						case 328:
							array2[1] = (byte)num6;
							num3 = 233;
							continue;
						case 61:
							array[8] = 134;
							num2 = 277;
							goto IL_09ab;
						case 184:
							num6 = 191 - 63;
							num2 = 174;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 54;
						case 58:
						case 62:
							array2[7] = 137;
							num = 86;
							goto end_IL_09af;
						case 212:
							array2[16] = (byte)num6;
							num2 = 228;
							if (ysBTLST6ap0Cv2wmXS())
							{
								goto IL_09ab;
							}
							goto case 70;
						case 70:
							array2[2] = (byte)num6;
							num2 = 106;
							goto IL_09ab;
						case 286:
							array2[1] = 163;
							num3 = 123;
							continue;
						case 35:
							num6 = 46 + 119;
							num2 = 264;
							if (!TCKIVCAktupk7eKSF8())
							{
								goto IL_09ab;
							}
							goto case 234;
						case 258:
							array[15] = (byte)num5;
							num2 = 235;
							if (ysBTLST6ap0Cv2wmXS())
							{
								goto IL_09ab;
							}
							goto case 339;
						case 339:
							array2[10] = 124;
							num3 = 255;
							continue;
						case 221:
							array2[18] = 170;
							num = 109;
							goto end_IL_09af;
						case 243:
							array[12] = 99;
							num3 = 93;
							continue;
						case 172:
							array2[25] = (byte)num6;
							num2 = 332;
							if (true)
							{
								goto IL_09ab;
							}
							goto case 181;
						case 181:
							array[6] = 116;
							num3 = 336;
							continue;
						case 247:
							num6 = 57 + 121;
							num3 = 217;
							continue;
						case 100:
							array2[26] = (byte)num6;
							num = 98;
							goto end_IL_09af;
						case 347:
							try
							{
								return (string)RIC7LhoqKRQV3JJnGN(Qqo9ufL4etdOsNhim8(), aqT59ZsUJ, P_0 + 4, num4);
							}
							catch
							{
							}
							return "";
						case 341:
							rijndaelManaged = new RijndaelManaged();
							num3 = 63;
							continue;
						case 152:
							memoryStream = new MemoryStream();
							num = 302;
							goto end_IL_09af;
						}
						array2[3] = 120;
						num2 = 340;
						goto IL_09ab;
						IL_0793:
						array2[1] = 98;
						TCKIVCAktupk7eKSF8();
						num3 = (ysBTLST6ap0Cv2wmXS() ? 272 : 62);
						continue;
						IL_0064:
						array[1] = (byte)num5;
						num2 = 189;
						goto IL_09ab;
						IL_00d0:
						array[14] = (byte)num5;
						num = 108;
						break;
						continue;
						end_IL_09af:
						break;
					}
					break;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[NBE3EVCGSKCquAOCmd(typeof(L7tQalVfTx9dSjJ8wR/NBE3EVCGSKCquAOCmd/ealuq50owhNJ9dNRAD<object>[]))]
		internal static string IvQCSD6Co(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void YA20u1kXH(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int VujRP20Jc(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr wtCZWpu7t(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void YalYfTx9d()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void zjJF8wRCA()
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
		internal static object YqhcgNwvI(object P_0)
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
		public static extern IntPtr hE0jj0mVE(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr vE3dEVGSK(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int hquNAOCmd(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int ealIuq5ow(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int xNJJ9dNRA(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr RJjvmFIoP(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int T2kU9hmj7(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[NBE3EVCGSKCquAOCmd(typeof(L7tQalVfTx9dSjJ8wR/NBE3EVCGSKCquAOCmd/ealuq50owhNJ9dNRAD<object>[]))]
		private static byte[] lbUKHdJrj(string P_0)
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
		[NBE3EVCGSKCquAOCmd(typeof(L7tQalVfTx9dSjJ8wR/NBE3EVCGSKCquAOCmd/ealuq50owhNJ9dNRAD<object>[]))]
		private static byte[] a3uykaviY(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				133, 44, 208, 174, 138, 130, 42, 143, 69, 207,
				216, 235, 36, 118, 53, 221, 249, 241, 16, 219,
				121, 170, 109, 155, 148, 130, 49, 167, 52, 230,
				8, 7
			};
			rijndael.IV = new byte[16]
			{
				134, 154, 201, 67, 186, 32, 53, 131, 40, 154,
				32, 123, 230, 154, 153, 219
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] d0NAtCAjN()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] RcyB3U5qc()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] a8Q3H1xth()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] i6ShwuunO()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] pi0l8n07b()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] eqTfRpPU1()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] JxWSZAj7u()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] EAU6f4kci()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] SygkW4iwX()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] UnVsuDj3O()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public L7tQalVfTx9dSjJ8wR()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type wq3S5M7oN9QIbjLkMO(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object R0E8CwyJesRPPt7sPJ(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object pxnVJVt06Xux3o71iu(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void EY1Dvv1LaHdwPkBIZZ(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Vvstf6QWu6usfYjwYB(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long yVrKusRKSMv1wOUM8d(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object KXCcCiIrgdseuOsM41(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object KgoxShZCiPeAGmnM48(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object sSI1dpixwhfM1epV5J(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void gXF7yQ5XoDtEqIngxA(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object pCJirI3ERJ3RSPi5UU(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void awwjHk904tTB5pUFPk(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void GYweacOAfakg19uhsi(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object vUmYwlE2ryqOmDgr5s(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void MgNm3Nj7lbfmN4U7Tt(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void MqMtddYVBEtVtWCX5n(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int cZqgCHselvxOdIusdl(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Qqo9ufL4etdOsNhim8()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object RIC7LhoqKRQV3JJnGN(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool ysBTLST6ap0Cv2wmXS()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool TCKIVCAktupk7eKSF8()
		{
			return false;
		}
	}
}
namespace VXnVuDdj3OCXj6QJV9
{
	internal class au5AUfj4kciDygW4iw
	{
		private static bool oyXbfjJc5;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void OmVjZr3zpGjTm()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public au5AUfj4kciDygW4iw()
		{
		}
	}
}
