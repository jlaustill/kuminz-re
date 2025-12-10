using System;
using System.ComponentModel;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;

[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - InteropComponent")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyTitle("")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyFileVersion("3.15.0.001")]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyVersion("3.15.0.1")]
namespace Cummins.Interop;

public class LicComponent
{
	[ComImport]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	[Guid("B196B28F-BAB4-101A-B69C-00AA00341D07")]
	public interface IClassFactory2
	{
		void CreateInstance([In][MarshalAs(UnmanagedType.Interface)] object unused, [In] ref Guid refiid, [Out][MarshalAs(UnmanagedType.LPArray)] object[] ppunk);

		void LockServer(int fLock);

		void GetLicInfo([Out] IntPtr licInfo);

		void RequestLicKey([In][MarshalAs(UnmanagedType.U4)] int dwReserved, [Out][MarshalAs(UnmanagedType.LPArray)] string[] pBstrKey);

		void CreateInstanceLic([In][MarshalAs(UnmanagedType.Interface)] object pUnkOuter, [In][MarshalAs(UnmanagedType.Interface)] object pUnkReserved, [In] ref Guid riid, [In][MarshalAs(UnmanagedType.BStr)] string bstrKey, [MarshalAs(UnmanagedType.Interface)] out object ppVal);
	}

	private const int INPROC_SERVER = 1;

	public static Guid IID_IUnknown = new Guid("{00000000-0000-0000-C000-000000000046}");

	protected string LicenseKey;

	protected Guid UniqueID;

	protected object ComObjectInstance;

	[DllImport("Ole32.dll", ExactSpelling = true, PreserveSig = false)]
	public static extern IClassFactory2 CoGetClassObject([In] ref Guid clsid, int dwContext, int serverInfo, [In] ref Guid refiid);

	public LicComponent(IContainer container)
	{
		InitializeComponent();
	}

	public LicComponent()
	{
		InitializeComponent();
		ComObjectInstance = 0;
		UniqueID = new Guid("10000000-0000-0000-0000-000000000000");
		LicenseKey = null;
	}

	private void InitializeComponent()
	{
	}

	public void CreateComInstance(Guid uniqueId, string licenseString, out object someCastableObject)
	{
		Guid refiid = typeof(IClassFactory2).GUID;
		Guid clsid = uniqueId;
		IClassFactory2 classFactory = CoGetClassObject(ref clsid, 1, 0, ref refiid);
		classFactory.CreateInstanceLic(null, null, ref IID_IUnknown, licenseString, out var ppVal);
		someCastableObject = ppVal;
	}

	public object GetComInstance()
	{
		if (ComObjectInstance.Equals(0))
		{
			if (UniqueID.Equals("10000000-0000-0000-0000-000000000000") || LicenseKey == null)
			{
				throw new ArgumentOutOfRangeException("uniqueID and licenseKey must have set values");
			}
			CreateComInstance(UniqueID, LicenseKey, out var someCastableObject);
			ComObjectInstance = someCastableObject;
			return ComObjectInstance;
		}
		return ComObjectInstance;
	}
}
public enum ComClassID
{
	DCLDevice,
	CalBinImage,
	ConfigFile,
	DataDefSymbolicData,
	Subfiles,
	CLASS_ID_COUNT
}
public class LicensedComWrapper : LicComponent
{
	protected struct LicensedComClassToken
	{
		public string ClassName;

		public string LicenseKey;

		public Guid UniqueID;

		public LicensedComClassToken(string name, char[] key, Guid guid)
		{
			ClassName = name;
			LicenseKey = new string(key);
			UniqueID = guid;
		}
	}

	private LicensedComClassToken[] ClassList;

	public object ObjectInstance => GetComInstance();

	private LicensedComWrapper()
	{
		LoadClassList();
	}

	public LicensedComWrapper(ComClassID classID)
	{
		LoadClassList();
		if (classID < ComClassID.CLASS_ID_COUNT)
		{
			LicensedComClassToken licensedComClassToken = ClassList[(int)classID];
			LicenseKey = licensedComClassToken.LicenseKey;
			UniqueID = licensedComClassToken.UniqueID;
			GetComInstance();
			return;
		}
		throw new ArgumentOutOfRangeException("Dont use {0} as a parameter.", ComClassID.CLASS_ID_COUNT.ToString());
	}

	private void LoadClassList()
	{
		ClassList = new LicensedComClassToken[5];
		char[] key = new char[9] { '?', '!', '-', ' ', 'P', 'N', 'Z', 'V', 'R' };
		ref LicensedComClassToken reference = ref ClassList[0];
		reference = new LicensedComClassToken("DCLDevice", key, new Guid("BAD58357-C7B8-11D5-9FF6-FFFFFF000000"));
		char[] key2 = new char[11]
		{
			'8', '$', '\\', 'u', ',', '-', '}', 'T', 'Q', 'J',
			'#'
		};
		ref LicensedComClassToken reference2 = ref ClassList[1];
		reference2 = new LicensedComClassToken(ComClassID.CalBinImage.ToString(), key2, new Guid("E07EC490-F301-11D5-A54D-006094EB621F"));
		char[] key3 = new char[19]
		{
			'8', '*', 'Y', 'U', 'P', 'W', '\'', ',', '*', 'H',
			' ', '\\', '(', 'E', 'B', '_', 'T', '*', 'A'
		};
		ref LicensedComClassToken reference3 = ref ClassList[2];
		reference3 = new LicensedComClassToken(ComClassID.ConfigFile.ToString(), key3, new Guid("E7390AEF-C3E5-11D5-A0F1-0004AC9631B0"));
		char[] key4 = new char[19]
		{
			'?', ' ', '6', 'R', 't', 'S', ' ', 'j', ':', '@',
			'!', ')', '.', 'X', 'N', 'p', '\'', 'F', 'T'
		};
		ref LicensedComClassToken reference4 = ref ClassList[3];
		reference4 = new LicensedComClassToken(ComClassID.DataDefSymbolicData.ToString(), key4, new Guid("AB306F9C-CFB1-4F25-B897-CD8887B5796F"));
		char[] key5 = new char[16]
		{
			'(', '6', '$', 'u', '\\', '^', '&', '\'', '*', '@',
			'6', ']', '^', '&', 'C', 'E'
		};
		ref LicensedComClassToken reference5 = ref ClassList[4];
		reference5 = new LicensedComClassToken(ComClassID.Subfiles.ToString(), key5, new Guid("CF352CDE-F20C-11D6-A501-0008A1326F46"));
	}
}
