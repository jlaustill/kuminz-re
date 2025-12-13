using System;
using System.Collections;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using System.Xml;
using B1l7w8POQuKHtUCols;
using BWA9ANgCc3X3ynNEP5;
using Cummins.INSITE.CNL.Factory;
using Cummins.INSITE.CNL.Localization;
using Cummins.INSITE.Kernel.DataServices;
using Cummins.INSITE.Kernel.ECMServicesAPI;
using DVCe0niPU43Ss0oJTa;
using DataMonitorLoggerAPILib;
using ECMSERVICESAPILib;
using ECMServicesAdapter.MetadataServicesAdapter;
using ShAw8OCiYmjRblCUqg;
using WCAfv8XUFHF0sLJrRc;
using l43OgbFaD4WUp22o03;
using tkOAUUIP7K6F2M9KbY;
using wFugkd6xN67h5mhXxl;
using zalv2G2SsnARgR31J0;

[assembly: AssemblyTrademark("")]
[assembly: ComVisible(true)]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyProduct("DMLLogFileConverter")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: Guid("fb6fde7e-0cce-471e-929f-097e2cf6e06a")]
[assembly: AssemblyDelaySign(false)]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: AssemblyTitle("DMLLogFileConverter")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace jqYVUQQr2OoNCJp9nd
{
	internal static class zc8ZhVnZExSFBsPYEr
	{
	}
}
namespace tkOAUUIP7K6F2M9KbY
{
	internal static class k0KHPqSeqjLIAypfo8
	{
		private static Dictionary<string, int> XfoP8HkOA;

		private static string[] oUPq7K6F2;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static k0KHPqSeqjLIAypfo8()
		{
			F1TW9EoVrvRILSscdn.D9BoUTjzdJlSt();
			oUPq7K6F2 = new string[4]
			{
				okiBYmytZBf443ggmg.RcDQFZA1u2(0),
				okiBYmytZBf443ggmg.RcDQFZA1u2(6),
				okiBYmytZBf443ggmg.RcDQFZA1u2(12),
				okiBYmytZBf443ggmg.RcDQFZA1u2(18)
			};
			XfoP8HkOA = new Dictionary<string, int>();
			XfoP8HkOA.Add(okiBYmytZBf443ggmg.RcDQFZA1u2(24), 1);
			XfoP8HkOA.Add(okiBYmytZBf443ggmg.RcDQFZA1u2(34), 2);
			XfoP8HkOA.Add(okiBYmytZBf443ggmg.RcDQFZA1u2(44), 3);
			XfoP8HkOA.Add(okiBYmytZBf443ggmg.RcDQFZA1u2(54), 4);
			XfoP8HkOA.Add(okiBYmytZBf443ggmg.RcDQFZA1u2(64), 5);
			XfoP8HkOA.Add(okiBYmytZBf443ggmg.RcDQFZA1u2(74), 6);
			XfoP8HkOA.Add(okiBYmytZBf443ggmg.RcDQFZA1u2(84), 7);
			XfoP8HkOA.Add(okiBYmytZBf443ggmg.RcDQFZA1u2(94), 8);
			XfoP8HkOA.Add(okiBYmytZBf443ggmg.RcDQFZA1u2(104), 9);
			XfoP8HkOA.Add(okiBYmytZBf443ggmg.RcDQFZA1u2(114), 10);
			XfoP8HkOA.Add(okiBYmytZBf443ggmg.RcDQFZA1u2(124), 11);
			XfoP8HkOA.Add(okiBYmytZBf443ggmg.RcDQFZA1u2(134), 12);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static DateTime aAwcgueFW(string P_0, string P_1)
		{
			string[] array = P_0.Split(oUPq7K6F2, StringSplitOptions.RemoveEmptyEntries);
			string[] array2 = P_1.Split(oUPq7K6F2, StringSplitOptions.RemoveEmptyEntries);
			return new DateTime(int.Parse(array[2]), XfoP8HkOA[array[1]], int.Parse(array[0]), int.Parse(array2[0]), int.Parse(array2[1]), int.Parse(array2[2]), int.Parse(array2[3]));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static DateTime gJsnMAr0p(string P_0)
		{
			string[] separator = new string[1] { okiBYmytZBf443ggmg.RcDQFZA1u2(144) };
			string[] array = P_0.Split(separator, StringSplitOptions.RemoveEmptyEntries);
			string[] array2 = array[0].Split(oUPq7K6F2, StringSplitOptions.RemoveEmptyEntries);
			string[] array3 = array[1].Split(oUPq7K6F2, StringSplitOptions.RemoveEmptyEntries);
			return new DateTime(int.Parse(array2[2]), XfoP8HkOA[array2[1]], int.Parse(array2[0]), int.Parse(array3[0]), int.Parse(array3[1]), int.Parse(array3[2]), int.Parse(array3[3]));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static TimeSpan ihcQ8ZhVZ(string P_0)
		{
			try
			{
				string[] array = P_0.Split(oUPq7K6F2, StringSplitOptions.RemoveEmptyEntries);
				return new TimeSpan(0, int.Parse(array[0]), int.Parse(array[1]), int.Parse(array[2]), int.Parse(array[3]));
			}
			catch
			{
			}
			return TimeSpan.MinValue;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string DxSSFBsPY(DateTime P_0, string P_1)
		{
			return P_0.ToString(okiBYmytZBf443ggmg.RcDQFZA1u2(150) + P_1 + okiBYmytZBf443ggmg.RcDQFZA1u2(176));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string Dr2IqYVUQ(string P_0)
		{
			string text = P_0.Replace(okiBYmytZBf443ggmg.RcDQFZA1u2(204), okiBYmytZBf443ggmg.RcDQFZA1u2(210));
			return text.Replace(okiBYmytZBf443ggmg.RcDQFZA1u2(216), okiBYmytZBf443ggmg.RcDQFZA1u2(222));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string V2OloNCJp(string P_0, string P_1)
		{
			if (okiBYmytZBf443ggmg.RcDQFZA1u2(228) == P_1)
			{
				return okiBYmytZBf443ggmg.RcDQFZA1u2(234) + P_0 + okiBYmytZBf443ggmg.RcDQFZA1u2(240);
			}
			return P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string Nnd610KHP(ECMSERVICESAPILib.IParameterDefinition P_0, string P_1)
		{
			string result = P_1;
			try
			{
				ParameterDefinitionAdapter parameterDefinitionAdapter = P_0 as ParameterDefinitionAdapter;
				Cummins.INSITE.Kernel.ECMServicesAPI.IParameterDefinition adaptee = parameterDefinitionAdapter.Adaptee;
				result = ValueConverter.GetDisplayValue(adaptee, P_1, 0, 0);
			}
			catch
			{
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string ieqJjLIAy(TimeSpan P_0)
		{
			return P_0.ToString(okiBYmytZBf443ggmg.RcDQFZA1u2(246));
		}
	}
}
namespace Cummins.INSITE.CNL.DMLLogFileConverter
{
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("Cummins.INSITE.CNL.DMLLogFileConverter.DMLLogFileConverter.1")]
	[ComVisible(true)]
	[Guid("190AF476-F44B-49cf-B9A6-64076E344114")]
	public class DMLLogFileConverter : IDMLLogFileConverter
	{
		private ECMSERVICESAPILib.IParameterDefinitions OgkbdxN67;

		private ILocalizedStringProvider z5mFhXxlD;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DMLLogFileConverter()
		{
			F1TW9EoVrvRILSscdn.D9BoUTjzdJlSt();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IDMLLogFileConverter.Initialize(object pParameterDefinitions)
		{
			OgkbdxN67 = pParameterDefinitions as ECMSERVICESAPILib.IParameterDefinitions;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		void IDMLLogFileConverter.ConvertLogFile(string sourceFileName, string destinationFileName, string delimitingCharacter)
		{
			//IL_0032: Unknown result type (might be due to invalid IL or missing references)
			//IL_0038: Expected O, but got Unknown
			if (z5mFhXxlD == null)
			{
				z5mFhXxlD = Cummins.INSITE.CNL.Factory.Factory.CreateInstance<ILocalizedStringProvider>();
				z5mFhXxlD.Initialize(okiBYmytZBf443ggmg.RcDQFZA1u2(252));
			}
			XmlDocument val = new XmlDocument();
			try
			{
				val.Load(sourceFileName);
			}
			catch (Exception)
			{
				sourceFileName = R9K2bYlJM(sourceFileName);
			}
			finally
			{
				val = null;
			}
			XdUcWVmFJ8ETSn8QKJ xdUcWVmFJ8ETSn8QKJ = FPM1WOWMv(sourceFileName);
			xdUcWVmFJ8ETSn8QKJ.Delimiter = delimitingCharacter;
			xdUcWVmFJ8ETSn8QKJ.ParameterDefinitions = OgkbdxN67;
			xdUcWVmFJ8ETSn8QKJ.StringProvider = z5mFhXxlD;
			xdUcWVmFJ8ETSn8QKJ.Parse(sourceFileName);
			xdUcWVmFJ8ETSn8QKJ.WriteToFile(destinationFileName);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string R9K2bYlJM(string P_0)
		{
			//IL_0016: Unknown result type (might be due to invalid IL or missing references)
			//IL_001c: Expected O, but got Unknown
			string tempFileName = Path.GetTempFileName();
			using StreamReader streamReader = new StreamReader(P_0);
			XmlTextWriter val = new XmlTextWriter(tempFileName, (Encoding)null);
			((XmlWriter)val).WriteStartElement(okiBYmytZBf443ggmg.RcDQFZA1u2(326));
			((XmlWriter)val).WriteRaw(streamReader.ReadToEnd());
			((XmlWriter)val).WriteEndElement();
			((XmlWriter)val).Close();
			return tempFileName;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private XdUcWVmFJ8ETSn8QKJ FPM1WOWMv(string P_0)
		{
			XdUcWVmFJ8ETSn8QKJ xdUcWVmFJ8ETSn8QKJ = null;
			if (EvaiXKFLF(P_0))
			{
				return new LegacyLogFileConverter();
			}
			return new LogFileConverter();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool EvaiXKFLF(string P_0)
		{
			//IL_0021: Unknown result type (might be due to invalid IL or missing references)
			//IL_0027: Expected O, but got Unknown
			//IL_0033: Unknown result type (might be due to invalid IL or missing references)
			//IL_0038: Unknown result type (might be due to invalid IL or missing references)
			//IL_003a: Unknown result type (might be due to invalid IL or missing references)
			//IL_003d: Unknown result type (might be due to invalid IL or missing references)
			//IL_004f: Expected I4, but got Unknown
			string[] separator = new string[1] { okiBYmytZBf443ggmg.RcDQFZA1u2(344) };
			XmlTextReader val = new XmlTextReader(P_0);
			try
			{
				string text = string.Empty;
				while (((XmlReader)val).Read())
				{
					XmlNodeType nodeType = ((XmlReader)val).NodeType;
					switch (nodeType - 1)
					{
					case 0:
						text = ((XmlReader)val).Name;
						break;
					case 2:
						if (text == okiBYmytZBf443ggmg.RcDQFZA1u2(350))
						{
							string value = ((XmlReader)val).Value;
							string[] array = value.Split(separator, StringSplitOptions.RemoveEmptyEntries);
							if (array.Length < 2)
							{
								return false;
							}
							int num = int.Parse(array[0]);
							int num2 = int.Parse(array[1]);
							if (num < 7)
							{
								return true;
							}
							if (num == 7 && num2 < 6)
							{
								return true;
							}
							return false;
						}
						break;
					}
				}
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
			return false;
		}
	}
}
namespace wFugkd6xN67h5mhXxl
{
	internal struct fJMjPMlWOWMvDvaXKF
	{
		public bool BpitXe8Lw;

		public string B1lk7w8OQ;

		public string OKHvtUCol;

		public string yDLmpTNn0;

		public string aWPXeIrvj;

		public string WLhaalv2G;

		public string esnHARgR3;

		public List<string> kJ0yiYUB0;

		public List<string> e8kgIk18N;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void wYFU1RJkL()
		{
			BpitXe8Lw = false;
			B1lk7w8OQ = string.Empty;
			OKHvtUCol = string.Empty;
			yDLmpTNn0 = string.Empty;
			aWPXeIrvj = string.Empty;
			WLhaalv2G = string.Empty;
			esnHARgR3 = string.Empty;
			if (kJ0yiYUB0 != null)
			{
				kJ0yiYUB0.Clear();
			}
			if (e8kgIk18N != null)
			{
				e8kgIk18N.Clear();
			}
		}
	}
}
namespace B1l7w8POQuKHtUCols
{
	internal struct ELYF1RJJkLwpiXe8Lw
	{
		public DateTime OuJ3oEVCe;

		public DateTime TnPLU43Ss;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ELYF1RJJkLwpiXe8Lw(string P_0, string P_1)
		{
			F1TW9EoVrvRILSscdn.D9BoUTjzdJlSt();
			OuJ3oEVCe = k0KHPqSeqjLIAypfo8.gJsnMAr0p(P_0);
			TnPLU43Ss = OuJ3oEVCe + k0KHPqSeqjLIAypfo8.ihcQ8ZhVZ(P_1);
		}
	}
}
namespace zalv2G2SsnARgR31J0
{
	internal struct ELpTNnq05WPeIrvjdL
	{
		public DateTime ToJfTaYDo;

		public DateTime xhxsDqP25;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ELpTNnq05WPeIrvjdL(string P_0, string P_1, string P_2)
		{
			F1TW9EoVrvRILSscdn.D9BoUTjzdJlSt();
			ToJfTaYDo = DateTime.ParseExact(P_0, P_2, CultureInfo.InvariantCulture);
			xhxsDqP25 = ToJfTaYDo + TimeSpan.Parse(P_1);
		}
	}
}
namespace DVCe0niPU43Ss0oJTa
{
	internal struct kYUB0I18kIk18NuuJo
	{
		public string vOgGbaD4W;

		public string op2w2o03o;

		public string kA3oio1uX;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Db7h0vab4()
		{
			vOgGbaD4W = string.Empty;
			op2w2o03o = string.Empty;
			kA3oio1uX = string.Empty;
		}
	}
}
namespace l43OgbFaD4WUp22o03
{
	internal enum NDofhxbDqP25Eb70va
	{

	}
}
namespace g5Qd2otO4fpjgAKg3j
{
	internal static class B1A3ioU1uX0g6RpxJo
	{
		public static class CT3R3jk5LjOOUsCkwu
		{
			public const string z6VVQNtVP = "sample";

			public const string aT8AedUcW = "addedParameter";

			public const string HFJW8ETSn = "removedParameter";

			public const string YQKKJpCAf = "parameterID";

			public const string q8URFHF0s = "parameterValue";

			public const string xJr4RcLtl = "date";

			public const string FoG9pgf9L = "time";

			public const string v9QY28IQk = "sourceAddress";

			public const string eOSuNNjCx = "OutOfLimits";

			public const string lK2OLs4it = "companyName";

			public const string piBTYmtZB = "productName";

			public const string y44M3ggmg = "toolVersion";

			public const string BWAZ9ANCc = "toolLevel";

			public const string wX3NynNEP = "customerName";

			public const string alr0RhTVa = "vehicleUnitNumber";

			public const string EevxHFxRZ = "engineModel";

			public const string RwirHZvjb = "engineSerialNumber";

			public const string POFdBM6J1 = "ecmPartNumber";

			public const string wBBpLgGTN = "samplingRate";

			public const string nyTeFWXFr = "comments";

			public const string wr38UV9gm = "sourceFileName";

			public const string pi9zZKY0p = "startDate";

			public const string SqMc57X43m = "startTime";

			public const string r3uccWLXgG = "totalLogTime";

			public const string CNocnhEK9r = "pause";

			public const string gJ8cQi3ix0 = "duration";

			public const string TNScSFChvt = "Events";

			public const string eBEcI3jCYJ = "Event";

			public const string FLdclaBGHD = "EventId";

			public const string F1Tc6W9EVr = "EventTimestamp";

			public const string qRIcJLSscd = "EventDescription";
		}

		public static class TI5oIJvh6VQNtVPnT8
		{
			public const string cNhcPAw8Oi = "Sample";

			public const string NmjcqRblCU = "addedParameter";

			public const string igUc26rUH5 = "RemovedParameter";

			public const string lc0c1kIU3Q = "ParameterId";

			public const string V48ciUZUyG = "ParameterValue";

			public const string HqqcbwuH5r = "date";

			public const string L04cFkpOsy = "time";

			public const string UvLcUNnMIV = "TimeStamp";

			public const string gE2ctvvZYl = "SourceAddress";

			public const string kwvck7juSa = "OutOfLimits";

			public const string EjKcv4g206 = "companyName";

			public const string c6XcmSp09j = "productName";

			public const string l5KcXrXRBa = "toolVersion";

			public const string lLEcaVw3sj = "toolLevel";

			public const string uOocH1j43e = "customerName";

			public const string rIQcyIsHw2 = "vehicleUnitNumber";

			public const string ELtcgxJVrB = "engineModel";

			public const string c17c3WlH4D = "engineSerialNumber";

			public const string M4gcL9333k = "ecmPartNumber";

			public const string mcKcfnkhJ0 = "samplingRate";

			public const string cwUcsSsY8l = "comments";

			public const string qHFchGjDRD = "sourceFileName";

			public const string XY3cGpL3PK = "startDate";

			public const string nyHcw8vJcx = "startTime";

			public const string srHco1cHAT = "totalLogTime";

			public const string ATCcCvCLZ5 = "Pause";

			public const string tV1cEDrl6H = "Duration";

			public const string n75cD73HAo = "Events";

			public const string PCScBZyAap = "Event";

			public const string jCUcjY3arL = "EventId";

			public const string OX3c7g7IAv = "EventTimestamp";

			public const string tgZcVuVCDK = "EventDescription";

			public const string Bh9cAtojyR = "StartTime";

			public const string J2mcWYGvmx = "StopTime";

			public const string AbhcKr558U = "TimestampFormat";

			public const string nlKcRFIQ3N = "ECU";

			public const string Lqsc4xuX6p = "DetectType";

			public const string aQjc9XLVJ3 = "PauseTime";
		}

		public const string Tg6CRpxJo = "RemovedParameter";

		public const string g5QEd2oO4 = "RealTime";

		public const string xpjDgAKg3 = "Snapshot";

		public const string FoTB3R3j5 = "|";

		public const string wjOjOUsCk = "0";

		public const string Au07I5oIJ = ":";
	}
}
namespace WCAfv8XUFHF0sLJrRc
{
	internal interface XdUcWVmFJ8ETSn8QKJ
	{
		ILocalizedStringProvider StringProvider { get; set; }

		string Delimiter { get; set; }

		ECMSERVICESAPILib.IParameterDefinitions ParameterDefinitions { get; set; }

		void Parse(string P_0);

		void WriteToFile(string P_0);
	}
}
namespace Cummins.INSITE.CNL.DMLLogFileConverter
{
	public class LegacyLogFileConverter : XdUcWVmFJ8ETSn8QKJ
	{
		private Dictionary<string, string> o3un2cxgbk;

		private List<string> oA1n1VVP3S;

		private List<string> qBenicHNF8;

		private string oO5nbPR68j;

		private fJMjPMlWOWMvDvaXKF d20nFIgFP6;

		private string s8jnUycxGK;

		private string qUQntV51VK;

		private List<ELYF1RJJkLwpiXe8Lw> OPRnk1YiPf;

		private Dictionary<string, Dictionary<string, fJMjPMlWOWMvDvaXKF>> Eu3nvJaBoM;

		private Dictionary<string, kYUB0I18kIk18NuuJo> NhvnmeyoI9;

		private kYUB0I18kIk18NuuJo qCnnXSZrKK;

		private bool FCZnag85Yb;

		private ILocalizedStringProvider d6JnHG4EmC;

		private ECMSERVICESAPILib.IParameterDefinitions RsgnyqBl13;

		public ILocalizedStringProvider StringProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return d6JnHG4EmC;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				d6JnHG4EmC = value;
			}
		}

		public string Delimiter
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return oO5nbPR68j;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				oO5nbPR68j = value;
			}
		}

		public ECMSERVICESAPILib.IParameterDefinitions ParameterDefinitions
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return RsgnyqBl13;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				RsgnyqBl13 = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public LegacyLogFileConverter()
		{
			F1TW9EoVrvRILSscdn.D9BoUTjzdJlSt();
			base..ctor();
			o3un2cxgbk = new Dictionary<string, string>();
			oA1n1VVP3S = new List<string>();
			qBenicHNF8 = new List<string>();
			oO5nbPR68j = string.Empty;
			d20nFIgFP6 = default(fJMjPMlWOWMvDvaXKF);
			s8jnUycxGK = string.Empty;
			qUQntV51VK = string.Empty;
			OPRnk1YiPf = new List<ELYF1RJJkLwpiXe8Lw>();
			Eu3nvJaBoM = new Dictionary<string, Dictionary<string, fJMjPMlWOWMvDvaXKF>>();
			NhvnmeyoI9 = new Dictionary<string, kYUB0I18kIk18NuuJo>();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Parse(string logFileName)
		{
			RN7cYCaGwC(logFileName);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void WriteToFile(string destinationFileName)
		{
			LxOnnnP1D4(destinationFileName);
			HwWnquuJLd();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void RN7cYCaGwC(string P_0)
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_000e: Expected O, but got Unknown
			//IL_0017: Unknown result type (might be due to invalid IL or missing references)
			//IL_001c: Unknown result type (might be due to invalid IL or missing references)
			//IL_001d: Unknown result type (might be due to invalid IL or missing references)
			//IL_001f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0031: Expected I4, but got Unknown
			//IL_0031: Unknown result type (might be due to invalid IL or missing references)
			//IL_0034: Invalid comparison between Unknown and I4
			XmlTextReader val = new XmlTextReader(P_0);
			long num = 0L;
			while (((XmlReader)val).Read())
			{
				XmlNodeType nodeType = ((XmlReader)val).NodeType;
				switch (nodeType - 1)
				{
				default:
					if ((int)nodeType == 15 && ((XmlReader)val).Name == okiBYmytZBf443ggmg.RcDQFZA1u2(436))
					{
						k8Qc8KOW93(null);
					}
					break;
				case 0:
					s8jnUycxGK = ((XmlReader)val).Name;
					if (s8jnUycxGK == okiBYmytZBf443ggmg.RcDQFZA1u2(376))
					{
						num++;
						BK5cp2riSX(val);
					}
					else if (s8jnUycxGK == okiBYmytZBf443ggmg.RcDQFZA1u2(392))
					{
						num++;
						kWhcdexTCW(val);
					}
					else if (s8jnUycxGK == okiBYmytZBf443ggmg.RcDQFZA1u2(406))
					{
						k8Qc8KOW93(val);
					}
					else if (s8jnUycxGK == okiBYmytZBf443ggmg.RcDQFZA1u2(420))
					{
						TOlceVJGt1(val);
					}
					break;
				case 2:
				{
					string key;
					if ((key = s8jnUycxGK) == null)
					{
						break;
					}
					if (<PrivateImplementationDetails>{8C9FD5F6-BCC5-4777-A483-3D87C27EAAA0}.$$method0x6000025-1 == null)
					{
						<PrivateImplementationDetails>{8C9FD5F6-BCC5-4777-A483-3D87C27EAAA0}.$$method0x6000025-1 = new Dictionary<string, int>(26)
						{
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(452),
								0
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(484),
								1
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(520),
								2
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(546),
								3
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(578),
								4
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(590),
								5
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(602),
								6
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(632),
								7
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(658),
								8
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(684),
								9
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(710),
								10
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(736),
								11
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(758),
								12
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(786),
								13
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(824),
								14
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(850),
								15
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(890),
								16
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(920),
								17
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(948),
								18
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(968),
								19
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(1000),
								20
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(1022),
								21
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(1044),
								22
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(1072),
								23
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(1090),
								24
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(1122),
								25
							}
						};
					}
					if (<PrivateImplementationDetails>{8C9FD5F6-BCC5-4777-A483-3D87C27EAAA0}.$$method0x6000025-1.TryGetValue(key, out var value))
					{
						switch (value)
						{
						case 0:
							pZHcOpTxTQ(val);
							break;
						case 1:
							MN1cTFQ6e1(val);
							break;
						case 2:
							kV2cMX45dB(val);
							break;
						case 3:
							HVWcZPS2j8(val);
							break;
						case 4:
							uW4cNE5WKY(val);
							break;
						case 5:
							weHc0h5Lul(val);
							break;
						case 6:
							VC4cxHyvuq(val);
							break;
						case 7:
							M6gcrQpGkk(val);
							break;
						case 8:
						case 9:
						case 10:
						case 11:
						case 12:
						case 13:
						case 14:
						case 15:
						case 16:
						case 17:
						case 18:
						case 19:
						case 20:
						case 21:
						case 22:
							aYQcua9QDs(val);
							break;
						case 23:
							qrvczQARPZ(val);
							break;
						case 24:
							GGBn5mZ4YW(val);
							break;
						case 25:
							juknc92KqN(val);
							break;
						}
					}
					break;
				}
				case 1:
					break;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void aYQcua9QDs(XmlTextReader P_0)
		{
			o3un2cxgbk.Add(s8jnUycxGK, ((XmlReader)P_0).Value);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void pZHcOpTxTQ(XmlTextReader P_0)
		{
			if (d20nFIgFP6.kJ0yiYUB0 == null)
			{
				d20nFIgFP6.kJ0yiYUB0 = new List<string>();
			}
			d20nFIgFP6.kJ0yiYUB0.Add(((XmlReader)P_0).Value);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void MN1cTFQ6e1(XmlTextReader P_0)
		{
			if (d20nFIgFP6.e8kgIk18N == null)
			{
				d20nFIgFP6.e8kgIk18N = new List<string>();
			}
			d20nFIgFP6.B1lk7w8OQ = okiBYmytZBf443ggmg.RcDQFZA1u2(1158);
			d20nFIgFP6.e8kgIk18N.Add(((XmlReader)P_0).Value);
			d20nFIgFP6.BpitXe8Lw = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void kV2cMX45dB(XmlTextReader P_0)
		{
			d20nFIgFP6.B1lk7w8OQ = ((XmlReader)P_0).Value;
			d20nFIgFP6.BpitXe8Lw = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void HVWcZPS2j8(XmlTextReader P_0)
		{
			d20nFIgFP6.yDLmpTNn0 = ((XmlReader)P_0).Value;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void uW4cNE5WKY(XmlTextReader P_0)
		{
			d20nFIgFP6.aWPXeIrvj = ((XmlReader)P_0).Value;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void weHc0h5Lul(XmlTextReader P_0)
		{
			StringBuilder stringBuilder = new StringBuilder(d20nFIgFP6.aWPXeIrvj);
			stringBuilder.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(1194));
			stringBuilder.Append(((XmlReader)P_0).Value);
			d20nFIgFP6.aWPXeIrvj = stringBuilder.ToString();
			qUQntV51VK = d20nFIgFP6.aWPXeIrvj;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void VC4cxHyvuq(XmlTextReader P_0)
		{
			d20nFIgFP6.WLhaalv2G = ((XmlReader)P_0).Value;
			if (!qBenicHNF8.Contains(((XmlReader)P_0).Value))
			{
				qBenicHNF8.Add(((XmlReader)P_0).Value);
			}
			StringBuilder stringBuilder = new StringBuilder(d20nFIgFP6.B1lk7w8OQ);
			stringBuilder.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(1200));
			stringBuilder.Append(((XmlReader)P_0).Value);
			string item = stringBuilder.ToString();
			if (!oA1n1VVP3S.Contains(item))
			{
				oA1n1VVP3S.Add(item);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void M6gcrQpGkk(XmlTextReader P_0)
		{
			d20nFIgFP6.esnHARgR3 = ((XmlReader)P_0).Value;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void kWhcdexTCW(XmlTextReader P_0)
		{
			OPRnk1YiPf.Add(new ELYF1RJJkLwpiXe8Lw(qUQntV51VK, ((XmlReader)P_0).GetAttribute(okiBYmytZBf443ggmg.RcDQFZA1u2(1206))));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void BK5cp2riSX(XmlTextReader P_0)
		{
			if (!d20nFIgFP6.BpitXe8Lw)
			{
				return;
			}
			if (!Eu3nvJaBoM.ContainsKey(d20nFIgFP6.aWPXeIrvj))
			{
				Eu3nvJaBoM.Add(d20nFIgFP6.aWPXeIrvj, new Dictionary<string, fJMjPMlWOWMvDvaXKF>());
			}
			if (!Eu3nvJaBoM[d20nFIgFP6.aWPXeIrvj].ContainsKey(d20nFIgFP6.B1lk7w8OQ))
			{
				StringBuilder stringBuilder = new StringBuilder(d20nFIgFP6.B1lk7w8OQ);
				stringBuilder.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(1226));
				stringBuilder.Append(d20nFIgFP6.WLhaalv2G);
				try
				{
					Eu3nvJaBoM[d20nFIgFP6.aWPXeIrvj].Add(stringBuilder.ToString(), d20nFIgFP6);
				}
				catch (ArgumentException)
				{
				}
			}
			StringBuilder stringBuilder2 = new StringBuilder(d20nFIgFP6.B1lk7w8OQ);
			stringBuilder2.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(1232));
			stringBuilder2.Append(d6JnHG4EmC.GetLocalizedString((NDofhxbDqP25Eb70va)21));
			stringBuilder2.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(1238));
			stringBuilder2.Append(d20nFIgFP6.WLhaalv2G);
			string text = stringBuilder2.ToString();
			if (!string.IsNullOrEmpty(d20nFIgFP6.esnHARgR3))
			{
				if (!oA1n1VVP3S.Contains(text))
				{
					oA1n1VVP3S.Add(text);
				}
				fJMjPMlWOWMvDvaXKF value = new fJMjPMlWOWMvDvaXKF
				{
					B1lk7w8OQ = text,
					yDLmpTNn0 = d20nFIgFP6.esnHARgR3
				};
				try
				{
					Eu3nvJaBoM[d20nFIgFP6.aWPXeIrvj].Add(text, value);
				}
				catch (ArgumentException)
				{
				}
			}
			else if (oA1n1VVP3S.Contains(text))
			{
				fJMjPMlWOWMvDvaXKF value2 = default(fJMjPMlWOWMvDvaXKF);
				if (value2.e8kgIk18N == null)
				{
					value2.e8kgIk18N = new List<string>();
				}
				value2.B1lk7w8OQ = okiBYmytZBf443ggmg.RcDQFZA1u2(1244);
				value2.aWPXeIrvj = d20nFIgFP6.aWPXeIrvj;
				value2.WLhaalv2G = d20nFIgFP6.WLhaalv2G;
				value2.e8kgIk18N.Add(text);
				value2.BpitXe8Lw = true;
				try
				{
					Eu3nvJaBoM[d20nFIgFP6.aWPXeIrvj].Add(text, value2);
				}
				catch (ArgumentException)
				{
				}
			}
			d20nFIgFP6.wYFU1RJkL();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void TOlceVJGt1(XmlTextReader P_0)
		{
			BK5cp2riSX(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void k8Qc8KOW93(XmlTextReader P_0)
		{
			if (!string.IsNullOrEmpty(qCnnXSZrKK.vOgGbaD4W))
			{
				NhvnmeyoI9.Add(qCnnXSZrKK.op2w2o03o, qCnnXSZrKK);
				qCnnXSZrKK.Db7h0vab4();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void qrvczQARPZ(XmlTextReader P_0)
		{
			qCnnXSZrKK.vOgGbaD4W = ((XmlReader)P_0).Value;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void GGBn5mZ4YW(XmlTextReader P_0)
		{
			qCnnXSZrKK.op2w2o03o = ((XmlReader)P_0).Value.Replace(okiBYmytZBf443ggmg.RcDQFZA1u2(1280), okiBYmytZBf443ggmg.RcDQFZA1u2(1286));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void juknc92KqN(XmlTextReader P_0)
		{
			qCnnXSZrKK.kA3oio1uX = ((XmlReader)P_0).Value;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void LxOnnnP1D4(string P_0)
		{
			StreamWriter streamWriter = new StreamWriter(P_0, append: false, Encoding.Default);
			streamWriter.WriteLine(eUwnQ6OcVl(P_0));
			bool flag = false;
			if (qBenicHNF8.Count > 1)
			{
				flag = true;
			}
			oA1n1VVP3S.Sort();
			StringBuilder stringBuilder = new StringBuilder();
			if (NhvnmeyoI9.Count > 0)
			{
				FCZnag85Yb = true;
				stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(d6JnHG4EmC.GetLocalizedString((NDofhxbDqP25Eb70va)23), oO5nbPR68j));
				stringBuilder.Append(oO5nbPR68j);
			}
			else
			{
				FCZnag85Yb = false;
			}
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(d6JnHG4EmC.GetLocalizedString((NDofhxbDqP25Eb70va)17), oO5nbPR68j));
			stringBuilder.Append(oO5nbPR68j);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(d6JnHG4EmC.GetLocalizedString((NDofhxbDqP25Eb70va)18), oO5nbPR68j));
			stringBuilder.Append(oO5nbPR68j);
			foreach (string oA1n1VVP in oA1n1VVP3S)
			{
				stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(aDrnlGi5kf(oA1n1VVP, flag), oO5nbPR68j));
				stringBuilder.Append(oO5nbPR68j);
			}
			streamWriter.WriteLine(stringBuilder.ToString());
			DateTime dateTime = DateTime.MinValue;
			if (o3un2cxgbk.ContainsKey(okiBYmytZBf443ggmg.RcDQFZA1u2(1292)) && o3un2cxgbk.ContainsKey(okiBYmytZBf443ggmg.RcDQFZA1u2(1314)))
			{
				dateTime = k0KHPqSeqjLIAypfo8.aAwcgueFW(o3un2cxgbk[okiBYmytZBf443ggmg.RcDQFZA1u2(1336)], o3un2cxgbk[okiBYmytZBf443ggmg.RcDQFZA1u2(1358)]);
			}
			TimeSpan timeSpan = TimeSpan.MinValue;
			if (o3un2cxgbk.ContainsKey(okiBYmytZBf443ggmg.RcDQFZA1u2(1380)))
			{
				timeSpan = k0KHPqSeqjLIAypfo8.ihcQ8ZhVZ(o3un2cxgbk[okiBYmytZBf443ggmg.RcDQFZA1u2(1408)]);
			}
			DateTime dateTime2 = DateTime.MinValue;
			if (dateTime != DateTime.MinValue && timeSpan != TimeSpan.MinValue)
			{
				dateTime2 = dateTime + timeSpan;
			}
			double result = 0.0;
			string text = cXVn6KrmE5(okiBYmytZBf443ggmg.RcDQFZA1u2(1436));
			if (!double.TryParse(text, out result))
			{
				result = ((text == okiBYmytZBf443ggmg.RcDQFZA1u2(1464)) ? 1000.0 : ((!(text == okiBYmytZBf443ggmg.RcDQFZA1u2(1484))) ? 1000.0 : 5000.0));
			}
			Dictionary<string, string> parameterLastValue = new Dictionary<string, string>(oA1n1VVP3S.Count);
			Dictionary<string, Dictionary<string, fJMjPMlWOWMvDvaXKF>>.Enumerator enumerator2 = Eu3nvJaBoM.GetEnumerator();
			DateTime dateTime3 = DateTime.MinValue;
			while (enumerator2.MoveNext())
			{
				DateTime dateTime4 = k0KHPqSeqjLIAypfo8.gJsnMAr0p(enumerator2.Current.Key);
				DateTime minValue = DateTime.MinValue;
				Dictionary<string, fJMjPMlWOWMvDvaXKF> value = enumerator2.Current.Value;
				if (dateTime3 != DateTime.MinValue)
				{
					minValue = dateTime3.AddMilliseconds(result);
					while (dateTime4 > minValue)
					{
						if (!mXQnPlxCUr(minValue))
						{
							string value2 = qN3nI0MrxB(k0KHPqSeqjLIAypfo8.DxSSFBsPY(minValue, oO5nbPR68j), parameterLastValue, null);
							streamWriter.WriteLine(value2);
							dateTime3 = minValue;
							minValue = dateTime3.AddMilliseconds(result);
						}
						else
						{
							dateTime3 = minValue;
							minValue = wndnJr3nmb(minValue);
						}
					}
				}
				kYUB0I18kIk18NuuJo kYUB0I18kIk18NuuJo = default(kYUB0I18kIk18NuuJo);
				if (NhvnmeyoI9.ContainsKey(enumerator2.Current.Key))
				{
					kYUB0I18kIk18NuuJo = NhvnmeyoI9[enumerator2.Current.Key];
				}
				string value3 = TW8nSH6JW8(k0KHPqSeqjLIAypfo8.DxSSFBsPY(dateTime4, oO5nbPR68j), parameterLastValue, value, kYUB0I18kIk18NuuJo);
				streamWriter.WriteLine(value3);
				dateTime3 = dateTime4;
			}
			if (dateTime2 != DateTime.MinValue)
			{
				DateTime dateTime5 = dateTime3.AddMilliseconds(result);
				while (dateTime5 < dateTime2)
				{
					if (!mXQnPlxCUr(dateTime5))
					{
						string value4 = qN3nI0MrxB(k0KHPqSeqjLIAypfo8.DxSSFBsPY(dateTime5, oO5nbPR68j), parameterLastValue, null);
						streamWriter.WriteLine(value4);
						dateTime5 = dateTime5.AddMilliseconds(result);
					}
					else
					{
						dateTime5 = wndnJr3nmb(dateTime5);
					}
				}
			}
			streamWriter.Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string eUwnQ6OcVl(string P_0)
		{
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(((okiBYmytZBf443ggmg.RcDQFZA1u2(1504) == oO5nbPR68j) ? okiBYmytZBf443ggmg.RcDQFZA1u2(1510) : "") + cXVn6KrmE5(okiBYmytZBf443ggmg.RcDQFZA1u2(1516)));
			stringBuilder.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(1542));
			stringBuilder.Append(cXVn6KrmE5(okiBYmytZBf443ggmg.RcDQFZA1u2(1548)));
			stringBuilder.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(1570));
			stringBuilder.AppendLine(cXVn6KrmE5(okiBYmytZBf443ggmg.RcDQFZA1u2(1576)) + ((okiBYmytZBf443ggmg.RcDQFZA1u2(1602) == oO5nbPR68j) ? okiBYmytZBf443ggmg.RcDQFZA1u2(1608) : ""));
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(cXVn6KrmE5(okiBYmytZBf443ggmg.RcDQFZA1u2(1614)), oO5nbPR68j));
			stringBuilder.AppendLine(string.Empty);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(d6JnHG4EmC.GetLocalizedString((NDofhxbDqP25Eb70va)14), oO5nbPR68j));
			stringBuilder.Append(oO5nbPR68j);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(d6JnHG4EmC.GetLocalizedString((NDofhxbDqP25Eb70va)8), oO5nbPR68j));
			stringBuilder.Append(oO5nbPR68j);
			stringBuilder.Append(cXVn6KrmE5(okiBYmytZBf443ggmg.RcDQFZA1u2(1640)));
			stringBuilder.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(1662));
			stringBuilder.AppendLine(cXVn6KrmE5(okiBYmytZBf443ggmg.RcDQFZA1u2(1668)));
			stringBuilder.Append(oO5nbPR68j);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(d6JnHG4EmC.GetLocalizedString((NDofhxbDqP25Eb70va)9), oO5nbPR68j));
			stringBuilder.Append(oO5nbPR68j);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(cXVn6KrmE5(okiBYmytZBf443ggmg.RcDQFZA1u2(1690)), oO5nbPR68j));
			stringBuilder.Append(oO5nbPR68j);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(d6JnHG4EmC.GetLocalizedString((NDofhxbDqP25Eb70va)7), oO5nbPR68j));
			stringBuilder.Append(oO5nbPR68j);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(cXVn6KrmE5(okiBYmytZBf443ggmg.RcDQFZA1u2(1718)), oO5nbPR68j));
			stringBuilder.Append(oO5nbPR68j);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(d6JnHG4EmC.GetLocalizedString((NDofhxbDqP25Eb70va)19), oO5nbPR68j));
			stringBuilder.Append(oO5nbPR68j);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(Path.GetDirectoryName(P_0), oO5nbPR68j));
			stringBuilder.Append(oO5nbPR68j);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(d6JnHG4EmC.GetLocalizedString((NDofhxbDqP25Eb70va)5), oO5nbPR68j));
			stringBuilder.Append(oO5nbPR68j);
			if (cXVn6KrmE5(okiBYmytZBf443ggmg.RcDQFZA1u2(1750)).ToUpper() == okiBYmytZBf443ggmg.RcDQFZA1u2(1778))
			{
				stringBuilder.AppendLine(((okiBYmytZBf443ggmg.RcDQFZA1u2(1798) == oO5nbPR68j) ? okiBYmytZBf443ggmg.RcDQFZA1u2(1804) : "") + d6JnHG4EmC.GetLocalizedString((NDofhxbDqP25Eb70va)20) + ((okiBYmytZBf443ggmg.RcDQFZA1u2(1810) == oO5nbPR68j) ? okiBYmytZBf443ggmg.RcDQFZA1u2(1816) : ""));
			}
			else
			{
				double result = 0.0;
				double.TryParse(cXVn6KrmE5(okiBYmytZBf443ggmg.RcDQFZA1u2(1822)), out result);
				double num = result / 1000.0;
				stringBuilder.Append(((okiBYmytZBf443ggmg.RcDQFZA1u2(1850) == oO5nbPR68j) ? okiBYmytZBf443ggmg.RcDQFZA1u2(1856) : "") + num);
				stringBuilder.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(1862));
				stringBuilder.AppendLine(d6JnHG4EmC.GetLocalizedString((NDofhxbDqP25Eb70va)1) + ((okiBYmytZBf443ggmg.RcDQFZA1u2(1868) == oO5nbPR68j) ? okiBYmytZBf443ggmg.RcDQFZA1u2(1874) : ""));
			}
			stringBuilder.Append(oO5nbPR68j);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(d6JnHG4EmC.GetLocalizedString((NDofhxbDqP25Eb70va)2), oO5nbPR68j));
			stringBuilder.Append(oO5nbPR68j);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(cXVn6KrmE5(okiBYmytZBf443ggmg.RcDQFZA1u2(1880)), oO5nbPR68j));
			stringBuilder.AppendLine(string.Empty);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(d6JnHG4EmC.GetLocalizedString((NDofhxbDqP25Eb70va)12), oO5nbPR68j));
			stringBuilder.Append(oO5nbPR68j);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(d6JnHG4EmC.GetLocalizedString((NDofhxbDqP25Eb70va)3), oO5nbPR68j));
			stringBuilder.Append(oO5nbPR68j);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(cXVn6KrmE5(okiBYmytZBf443ggmg.RcDQFZA1u2(1900)), oO5nbPR68j));
			stringBuilder.Append(oO5nbPR68j);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(d6JnHG4EmC.GetLocalizedString((NDofhxbDqP25Eb70va)10), oO5nbPR68j));
			stringBuilder.Append(oO5nbPR68j);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(cXVn6KrmE5(okiBYmytZBf443ggmg.RcDQFZA1u2(1928)), oO5nbPR68j));
			stringBuilder.AppendLine(string.Empty);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(d6JnHG4EmC.GetLocalizedString((NDofhxbDqP25Eb70va)13), oO5nbPR68j));
			stringBuilder.Append(oO5nbPR68j);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(d6JnHG4EmC.GetLocalizedString((NDofhxbDqP25Eb70va)4), oO5nbPR68j));
			stringBuilder.Append(oO5nbPR68j);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(cXVn6KrmE5(okiBYmytZBf443ggmg.RcDQFZA1u2(1966)), oO5nbPR68j));
			stringBuilder.Append(oO5nbPR68j);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(d6JnHG4EmC.GetLocalizedString((NDofhxbDqP25Eb70va)6), oO5nbPR68j));
			stringBuilder.Append(oO5nbPR68j);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(cXVn6KrmE5(okiBYmytZBf443ggmg.RcDQFZA1u2(1992)), oO5nbPR68j));
			stringBuilder.Append(oO5nbPR68j);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(d6JnHG4EmC.GetLocalizedString((NDofhxbDqP25Eb70va)16), oO5nbPR68j));
			stringBuilder.Append(oO5nbPR68j);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(cXVn6KrmE5(okiBYmytZBf443ggmg.RcDQFZA1u2(2032)), oO5nbPR68j));
			return stringBuilder.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string TW8nSH6JW8(string P_0, Dictionary<string, string> parameterLastValue, Dictionary<string, fJMjPMlWOWMvDvaXKF> values, kYUB0I18kIk18NuuJo P_3)
		{
			StringBuilder stringBuilder = new StringBuilder();
			if (FCZnag85Yb)
			{
				if (string.IsNullOrEmpty(P_3.vOgGbaD4W))
				{
					stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(okiBYmytZBf443ggmg.RcDQFZA1u2(2062), oO5nbPR68j));
				}
				else
				{
					stringBuilder.Append(((okiBYmytZBf443ggmg.RcDQFZA1u2(2068) == oO5nbPR68j) ? okiBYmytZBf443ggmg.RcDQFZA1u2(2074) : "") + d6JnHG4EmC.GetLocalizedString((NDofhxbDqP25Eb70va)22));
					stringBuilder.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(2080));
					stringBuilder.Append(P_3.vOgGbaD4W);
					if (!string.IsNullOrEmpty(P_3.kA3oio1uX))
					{
						stringBuilder.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(2086));
						stringBuilder.Append(k0KHPqSeqjLIAypfo8.Dr2IqYVUQ(P_3.kA3oio1uX) + ((okiBYmytZBf443ggmg.RcDQFZA1u2(2092) == oO5nbPR68j) ? okiBYmytZBf443ggmg.RcDQFZA1u2(2098) : ""));
					}
					else
					{
						stringBuilder.Append((okiBYmytZBf443ggmg.RcDQFZA1u2(2104) == oO5nbPR68j) ? okiBYmytZBf443ggmg.RcDQFZA1u2(2110) : "");
					}
				}
				stringBuilder.Append(oO5nbPR68j);
			}
			stringBuilder.Append(P_0);
			stringBuilder.Append(oO5nbPR68j);
			for (int i = 0; i < oA1n1VVP3S.Count; i++)
			{
				if (values.ContainsKey(oA1n1VVP3S[i]))
				{
					string key = oA1n1VVP3S[i];
					fJMjPMlWOWMvDvaXKF fJMjPMlWOWMvDvaXKF = values[key];
					stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(fJMjPMlWOWMvDvaXKF.yDLmpTNn0, oO5nbPR68j));
					if (!parameterLastValue.ContainsKey(key))
					{
						parameterLastValue.Add(key, string.Empty);
					}
					parameterLastValue[key] = fJMjPMlWOWMvDvaXKF.yDLmpTNn0;
				}
				else
				{
					if (values.ContainsKey(okiBYmytZBf443ggmg.RcDQFZA1u2(2116)))
					{
						foreach (string item in values[okiBYmytZBf443ggmg.RcDQFZA1u2(2152)].e8kgIk18N)
						{
							parameterLastValue[item] = string.Empty;
						}
					}
					string text = string.Empty;
					if (parameterLastValue.ContainsKey(oA1n1VVP3S[i]))
					{
						text = parameterLastValue[oA1n1VVP3S[i]];
					}
					stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(text, oO5nbPR68j));
				}
				stringBuilder.Append(oO5nbPR68j);
			}
			return stringBuilder.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string qN3nI0MrxB(string P_0, Dictionary<string, string> parameterLastValue, Dictionary<string, fJMjPMlWOWMvDvaXKF> values)
		{
			StringBuilder stringBuilder = new StringBuilder();
			if (FCZnag85Yb)
			{
				stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(okiBYmytZBf443ggmg.RcDQFZA1u2(2188), oO5nbPR68j));
				stringBuilder.Append(oO5nbPR68j);
			}
			stringBuilder.Append(P_0);
			stringBuilder.Append(oO5nbPR68j);
			for (int i = 0; i < oA1n1VVP3S.Count; i++)
			{
				if (values != null && values.ContainsKey(okiBYmytZBf443ggmg.RcDQFZA1u2(2194)))
				{
					foreach (string item in values[okiBYmytZBf443ggmg.RcDQFZA1u2(2230)].e8kgIk18N)
					{
						parameterLastValue[item] = string.Empty;
					}
				}
				string text = string.Empty;
				if (parameterLastValue.ContainsKey(oA1n1VVP3S[i]))
				{
					text = parameterLastValue[oA1n1VVP3S[i]];
				}
				stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(text, oO5nbPR68j));
				stringBuilder.Append(oO5nbPR68j);
			}
			return stringBuilder.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string aDrnlGi5kf(string P_0, bool P_1)
		{
			string[] separator = new string[1] { okiBYmytZBf443ggmg.RcDQFZA1u2(2266) };
			string[] array = P_0.Split(separator, StringSplitOptions.RemoveEmptyEntries);
			if (P_1)
			{
				StringBuilder stringBuilder = new StringBuilder(array[0]);
				stringBuilder.Append(d6JnHG4EmC.GetLocalizedString((NDofhxbDqP25Eb70va)15));
				stringBuilder.Append(array[1]);
				return stringBuilder.ToString();
			}
			return array[0];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string cXVn6KrmE5(string P_0)
		{
			string result = string.Empty;
			if (o3un2cxgbk.ContainsKey(P_0))
			{
				result = o3un2cxgbk[P_0];
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private DateTime wndnJr3nmb(DateTime P_0)
		{
			foreach (ELYF1RJJkLwpiXe8Lw item in OPRnk1YiPf)
			{
				if (P_0 < item.TnPLU43Ss)
				{
					return item.TnPLU43Ss;
				}
			}
			return DateTime.MinValue;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool mXQnPlxCUr(DateTime P_0)
		{
			foreach (ELYF1RJJkLwpiXe8Lw item in OPRnk1YiPf)
			{
				if (P_0 > item.OuJ3oEVCe && P_0 < item.TnPLU43Ss)
				{
					return true;
				}
			}
			return false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void HwWnquuJLd()
		{
			try
			{
				o3un2cxgbk.Clear();
				oA1n1VVP3S.Clear();
				qBenicHNF8.Clear();
				oO5nbPR68j = string.Empty;
				d20nFIgFP6.wYFU1RJkL();
				s8jnUycxGK = string.Empty;
				qUQntV51VK = string.Empty;
				OPRnk1YiPf.Clear();
				Eu3nvJaBoM.Clear();
				NhvnmeyoI9.Clear();
			}
			catch
			{
			}
		}
	}
	public class LogFileConverter : XdUcWVmFJ8ETSn8QKJ
	{
		private Dictionary<string, string> eOZnrKbeQT;

		private List<string> CKmndrMLDb;

		private List<string> xvNnpEGbAC;

		private string i5DnesGv8v;

		private fJMjPMlWOWMvDvaXKF xWcn8Iu0wq;

		private string X04nzWeKn8;

		private string ImqQ5iMTAS;

		private List<ELpTNnq05WPeIrvjdL> wkyQce1S3r;

		private Dictionary<string, Dictionary<string, fJMjPMlWOWMvDvaXKF>> uIsQnA55oC;

		private SortedDictionary<string, kYUB0I18kIk18NuuJo> GPqQQJf3bA;

		private kYUB0I18kIk18NuuJo QpsQS94c1s;

		private bool BMlQIROeHE;

		private ILocalizedStringProvider PsXQleZ3Gx;

		private ECMSERVICESAPILib.IParameterDefinitions KURQ6CgG7K;

		private string gA1QJV4dfZ;

		private Dictionary<int, int> T6sQPfEolr;

		private TimeSpan sSMQqh8DrL;

		private TimeSpan aPDQ2NrPae;

		private DateTime jklQ155o9r;

		private Dictionary<string, string> dp1QiMUpB3;

		public ILocalizedStringProvider StringProvider
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return PsXQleZ3Gx;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				PsXQleZ3Gx = value;
			}
		}

		public string Delimiter
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return i5DnesGv8v;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				i5DnesGv8v = value;
			}
		}

		public ECMSERVICESAPILib.IParameterDefinitions ParameterDefinitions
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return KURQ6CgG7K;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				KURQ6CgG7K = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public LogFileConverter()
		{
			F1TW9EoVrvRILSscdn.D9BoUTjzdJlSt();
			base..ctor();
			eOZnrKbeQT = new Dictionary<string, string>();
			CKmndrMLDb = new List<string>();
			xvNnpEGbAC = new List<string>();
			i5DnesGv8v = string.Empty;
			xWcn8Iu0wq = default(fJMjPMlWOWMvDvaXKF);
			X04nzWeKn8 = string.Empty;
			ImqQ5iMTAS = string.Empty;
			wkyQce1S3r = new List<ELpTNnq05WPeIrvjdL>();
			uIsQnA55oC = new Dictionary<string, Dictionary<string, fJMjPMlWOWMvDvaXKF>>();
			GPqQQJf3bA = new SortedDictionary<string, kYUB0I18kIk18NuuJo>();
			T6sQPfEolr = new Dictionary<int, int>();
			gA1QJV4dfZ = okiBYmytZBf443ggmg.RcDQFZA1u2(2272);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Parse(string logFileName)
		{
			OoungGSKT6(logFileName);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void WriteToFile(string destinationFileName)
		{
			Ayun4fWVXC(destinationFileName);
			zHKnxZD0rt();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void OoungGSKT6(string P_0)
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_000e: Expected O, but got Unknown
			//IL_002d: Unknown result type (might be due to invalid IL or missing references)
			//IL_0032: Unknown result type (might be due to invalid IL or missing references)
			//IL_0033: Unknown result type (might be due to invalid IL or missing references)
			//IL_0035: Unknown result type (might be due to invalid IL or missing references)
			//IL_0047: Expected I4, but got Unknown
			//IL_0047: Unknown result type (might be due to invalid IL or missing references)
			//IL_004a: Invalid comparison between Unknown and I4
			XmlTextReader val = new XmlTextReader(P_0);
			long num = 0L;
			bool flag = true;
			while (flag)
			{
				try
				{
					flag = ((XmlReader)val).Read();
				}
				catch (Exception)
				{
					flag = false;
				}
				XmlNodeType nodeType = ((XmlReader)val).NodeType;
				switch (nodeType - 1)
				{
				case 0:
					X04nzWeKn8 = ((XmlReader)val).Name;
					if (X04nzWeKn8 == okiBYmytZBf443ggmg.RcDQFZA1u2(2278))
					{
						num++;
					}
					else if (X04nzWeKn8 == okiBYmytZBf443ggmg.RcDQFZA1u2(2294))
					{
						num++;
						mQ6nBHZCbS(val);
					}
					else if (X04nzWeKn8 == okiBYmytZBf443ggmg.RcDQFZA1u2(2308))
					{
						Kvun7rbx11(val);
					}
					else if (X04nzWeKn8 == okiBYmytZBf443ggmg.RcDQFZA1u2(2324))
					{
						vFVn3VD7QW(val);
					}
					else if (X04nzWeKn8 == okiBYmytZBf443ggmg.RcDQFZA1u2(2334))
					{
						KZinsMZJs8(val);
					}
					continue;
				case 2:
				{
					string x04nzWeKn;
					if ((x04nzWeKn = X04nzWeKn8) == null)
					{
						continue;
					}
					if (<PrivateImplementationDetails>{8C9FD5F6-BCC5-4777-A483-3D87C27EAAA0}.$$method0x6000048-1 == null)
					{
						<PrivateImplementationDetails>{8C9FD5F6-BCC5-4777-A483-3D87C27EAAA0}.$$method0x6000048-1 = new Dictionary<string, int>(30)
						{
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(2400),
								0
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(2432),
								1
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(2468),
								2
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(2494),
								3
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(2526),
								4
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(2538),
								5
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(2550),
								6
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(2572),
								7
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(2602),
								8
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(2628),
								9
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(2662),
								10
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(2688),
								11
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(2714),
								12
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(2740),
								13
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(2762),
								14
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(2790),
								15
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(2828),
								16
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(2854),
								17
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(2894),
								18
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(2924),
								19
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(2952),
								20
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(2972),
								21
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(3004),
								22
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(3026),
								23
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(3048),
								24
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(3076),
								25
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(3098),
								26
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(3118),
								27
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(3136),
								28
							},
							{
								okiBYmytZBf443ggmg.RcDQFZA1u2(3168),
								29
							}
						};
					}
					if (<PrivateImplementationDetails>{8C9FD5F6-BCC5-4777-A483-3D87C27EAAA0}.$$method0x6000048-1.TryGetValue(x04nzWeKn, out var value))
					{
						switch (value)
						{
						case 0:
							jSunfs5OuP(val);
							break;
						case 1:
							KZinsMZJs8(val);
							break;
						case 2:
							HsZnhrIvF8(val);
							break;
						case 3:
							YRTnGShQrY(val);
							break;
						case 4:
							rsnnwNZPeG(val);
							break;
						case 5:
							CZAnosaD5q(val);
							break;
						case 6:
							X5unC29cHK(val);
							break;
						case 7:
							WxInEkd1kf(val);
							break;
						case 8:
							Dr4nDhViPb(val);
							break;
						case 9:
							gA1QJV4dfZ = ((XmlReader)val).Value;
							break;
						case 10:
						case 11:
						case 12:
						case 13:
						case 14:
						case 15:
						case 16:
						case 17:
						case 18:
						case 19:
						case 20:
						case 21:
						case 22:
						case 23:
						case 24:
						case 25:
						case 26:
							R2ynLxweoy(val);
							break;
						case 27:
							GMpnAeZH6R(val);
							break;
						case 28:
							qpanW2e9Ag(val);
							break;
						case 29:
							OlFnKolncY(val);
							break;
						}
					}
					continue;
				}
				case 1:
					continue;
				}
				if ((int)nodeType == 15)
				{
					if (((XmlReader)val).Name == okiBYmytZBf443ggmg.RcDQFZA1u2(2370))
					{
						kt3njE8hH2(null);
					}
					else if (((XmlReader)val).Name == okiBYmytZBf443ggmg.RcDQFZA1u2(2386))
					{
						FyGnVMDRHL(null);
					}
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void vFVn3VD7QW(XmlTextReader P_0)
		{
			string attribute = ((XmlReader)P_0).GetAttribute(okiBYmytZBf443ggmg.RcDQFZA1u2(3204));
			string attribute2 = ((XmlReader)P_0).GetAttribute(okiBYmytZBf443ggmg.RcDQFZA1u2(3234));
			if (T6sQPfEolr.ContainsKey(int.Parse(attribute)))
			{
				T6sQPfEolr[int.Parse(attribute)] = int.Parse(attribute2);
			}
			else
			{
				T6sQPfEolr.Add(int.Parse(attribute), int.Parse(attribute2));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void R2ynLxweoy(XmlTextReader P_0)
		{
			if (eOZnrKbeQT.ContainsKey(X04nzWeKn8))
			{
				eOZnrKbeQT[X04nzWeKn8] = ((XmlReader)P_0).Value;
			}
			else
			{
				eOZnrKbeQT.Add(X04nzWeKn8, ((XmlReader)P_0).Value);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void jSunfs5OuP(XmlTextReader P_0)
		{
			if (xWcn8Iu0wq.kJ0yiYUB0 == null)
			{
				xWcn8Iu0wq.kJ0yiYUB0 = new List<string>();
			}
			xWcn8Iu0wq.kJ0yiYUB0.Add(((XmlReader)P_0).Value);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void KZinsMZJs8(XmlTextReader P_0)
		{
			if (xWcn8Iu0wq.BpitXe8Lw)
			{
				wsHnRVMTWx();
			}
			if (xWcn8Iu0wq.e8kgIk18N == null)
			{
				xWcn8Iu0wq.e8kgIk18N = new List<string>();
			}
			xWcn8Iu0wq.OKHvtUCol = okiBYmytZBf443ggmg.RcDQFZA1u2(3258);
			xWcn8Iu0wq.e8kgIk18N.Add(((XmlReader)P_0).GetAttribute(okiBYmytZBf443ggmg.RcDQFZA1u2(3294)));
			xWcn8Iu0wq.WLhaalv2G = ((XmlReader)P_0).GetAttribute(okiBYmytZBf443ggmg.RcDQFZA1u2(3320));
			xWcn8Iu0wq.aWPXeIrvj = ((XmlReader)P_0).GetAttribute(okiBYmytZBf443ggmg.RcDQFZA1u2(3350));
			xWcn8Iu0wq.BpitXe8Lw = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void HsZnhrIvF8(XmlTextReader P_0)
		{
			xWcn8Iu0wq.B1lk7w8OQ = ((XmlReader)P_0).Value;
			xWcn8Iu0wq.BpitXe8Lw = true;
			string text = a73nTTmWP6(xWcn8Iu0wq.B1lk7w8OQ, xWcn8Iu0wq.WLhaalv2G);
			xWcn8Iu0wq.OKHvtUCol = text;
			StringBuilder stringBuilder = new StringBuilder(text);
			stringBuilder.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(3372));
			stringBuilder.Append(xWcn8Iu0wq.WLhaalv2G);
			string item = stringBuilder.ToString();
			if (!CKmndrMLDb.Contains(item))
			{
				CKmndrMLDb.Add(item);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void YRTnGShQrY(XmlTextReader P_0)
		{
			int moduleType = T6sQPfEolr[int.Parse(xWcn8Iu0wq.WLhaalv2G)];
			ECMSERVICESAPILib.IParameterDefinition parameterDefinition = KURQ6CgG7K.GetParameterDefinition(xWcn8Iu0wq.B1lk7w8OQ, moduleType);
			xWcn8Iu0wq.yDLmpTNn0 = k0KHPqSeqjLIAypfo8.Nnd610KHP(parameterDefinition, ((XmlReader)P_0).Value);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void rsnnwNZPeG(XmlTextReader P_0)
		{
			xWcn8Iu0wq.aWPXeIrvj = ((XmlReader)P_0).Value;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void CZAnosaD5q(XmlTextReader P_0)
		{
			StringBuilder stringBuilder = new StringBuilder(xWcn8Iu0wq.aWPXeIrvj);
			stringBuilder.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(3378));
			stringBuilder.Append(((XmlReader)P_0).Value);
			xWcn8Iu0wq.aWPXeIrvj = stringBuilder.ToString();
			ImqQ5iMTAS = xWcn8Iu0wq.aWPXeIrvj;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void X5unC29cHK(XmlTextReader P_0)
		{
			xWcn8Iu0wq.aWPXeIrvj = ((XmlReader)P_0).Value;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void WxInEkd1kf(XmlTextReader P_0)
		{
			xWcn8Iu0wq.WLhaalv2G = ((XmlReader)P_0).Value;
			if (!xvNnpEGbAC.Contains(((XmlReader)P_0).Value))
			{
				xvNnpEGbAC.Add(((XmlReader)P_0).Value);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Dr4nDhViPb(XmlTextReader P_0)
		{
			xWcn8Iu0wq.esnHARgR3 = ((XmlReader)P_0).Value;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void mQ6nBHZCbS(XmlTextReader P_0)
		{
			string attribute = ((XmlReader)P_0).GetAttribute(okiBYmytZBf443ggmg.RcDQFZA1u2(3384));
			string attribute2 = ((XmlReader)P_0).GetAttribute(okiBYmytZBf443ggmg.RcDQFZA1u2(3406));
			wkyQce1S3r.Add(new ELpTNnq05WPeIrvjdL(attribute, attribute2, gA1QJV4dfZ));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void kt3njE8hH2(XmlTextReader P_0)
		{
			wsHnRVMTWx();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Kvun7rbx11(XmlTextReader P_0)
		{
			kt3njE8hH2(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void FyGnVMDRHL(XmlTextReader P_0)
		{
			if (!string.IsNullOrEmpty(QpsQS94c1s.vOgGbaD4W))
			{
				GPqQQJf3bA.Add(QpsQS94c1s.op2w2o03o, QpsQS94c1s);
				QpsQS94c1s.Db7h0vab4();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void GMpnAeZH6R(XmlTextReader P_0)
		{
			QpsQS94c1s.vOgGbaD4W = ((XmlReader)P_0).Value;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void qpanW2e9Ag(XmlTextReader P_0)
		{
			QpsQS94c1s.op2w2o03o = ((XmlReader)P_0).Value.Replace(okiBYmytZBf443ggmg.RcDQFZA1u2(3426), okiBYmytZBf443ggmg.RcDQFZA1u2(3432));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void OlFnKolncY(XmlTextReader P_0)
		{
			QpsQS94c1s.kA3oio1uX = ((XmlReader)P_0).Value;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void wsHnRVMTWx()
		{
			if (!xWcn8Iu0wq.BpitXe8Lw)
			{
				return;
			}
			if (!uIsQnA55oC.ContainsKey(xWcn8Iu0wq.aWPXeIrvj))
			{
				uIsQnA55oC.Add(xWcn8Iu0wq.aWPXeIrvj, new Dictionary<string, fJMjPMlWOWMvDvaXKF>());
			}
			if (!uIsQnA55oC[xWcn8Iu0wq.aWPXeIrvj].ContainsKey(xWcn8Iu0wq.OKHvtUCol))
			{
				StringBuilder stringBuilder = new StringBuilder(xWcn8Iu0wq.OKHvtUCol);
				stringBuilder.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(3438));
				stringBuilder.Append(xWcn8Iu0wq.WLhaalv2G);
				try
				{
					uIsQnA55oC[xWcn8Iu0wq.aWPXeIrvj].Add(stringBuilder.ToString(), xWcn8Iu0wq);
				}
				catch (ArgumentException)
				{
				}
			}
			StringBuilder stringBuilder2 = new StringBuilder(xWcn8Iu0wq.OKHvtUCol);
			stringBuilder2.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(3444));
			stringBuilder2.Append(PsXQleZ3Gx.GetLocalizedString((NDofhxbDqP25Eb70va)21));
			stringBuilder2.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(3450));
			stringBuilder2.Append(xWcn8Iu0wq.WLhaalv2G);
			string text = stringBuilder2.ToString();
			if (!string.IsNullOrEmpty(xWcn8Iu0wq.esnHARgR3))
			{
				if (!CKmndrMLDb.Contains(text))
				{
					CKmndrMLDb.Add(text);
				}
				fJMjPMlWOWMvDvaXKF value = new fJMjPMlWOWMvDvaXKF
				{
					OKHvtUCol = text,
					yDLmpTNn0 = xWcn8Iu0wq.esnHARgR3
				};
				try
				{
					uIsQnA55oC[xWcn8Iu0wq.aWPXeIrvj].Add(text, value);
				}
				catch (ArgumentException)
				{
				}
			}
			else if (CKmndrMLDb.Contains(text))
			{
				fJMjPMlWOWMvDvaXKF value2 = default(fJMjPMlWOWMvDvaXKF);
				if (value2.e8kgIk18N == null)
				{
					value2.e8kgIk18N = new List<string>();
				}
				value2.OKHvtUCol = okiBYmytZBf443ggmg.RcDQFZA1u2(3456);
				value2.aWPXeIrvj = xWcn8Iu0wq.aWPXeIrvj;
				value2.WLhaalv2G = xWcn8Iu0wq.WLhaalv2G;
				value2.e8kgIk18N.Add(text);
				value2.BpitXe8Lw = true;
				try
				{
					uIsQnA55oC[xWcn8Iu0wq.aWPXeIrvj].Add(text, value2);
				}
				catch (ArgumentException)
				{
				}
			}
			xWcn8Iu0wq.wYFU1RJkL();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Ayun4fWVXC(string P_0)
		{
			StreamWriter streamWriter = new StreamWriter(P_0, append: false, Encoding.Default);
			streamWriter.WriteLine(NYDnYKJhnH(P_0));
			bool flag = false;
			if (xvNnpEGbAC.Count > 1)
			{
				flag = true;
			}
			CKmndrMLDb.Sort();
			StringBuilder stringBuilder = new StringBuilder();
			if (GPqQQJf3bA.Count > 0)
			{
				BMlQIROeHE = true;
				stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(PsXQleZ3Gx.GetLocalizedString((NDofhxbDqP25Eb70va)23), i5DnesGv8v));
				stringBuilder.Append(i5DnesGv8v);
			}
			else
			{
				BMlQIROeHE = false;
			}
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(PsXQleZ3Gx.GetLocalizedString((NDofhxbDqP25Eb70va)17), i5DnesGv8v));
			stringBuilder.Append(i5DnesGv8v);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(PsXQleZ3Gx.GetLocalizedString((NDofhxbDqP25Eb70va)18), i5DnesGv8v));
			stringBuilder.Append(i5DnesGv8v);
			foreach (string item in CKmndrMLDb)
			{
				stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(fTQnM4hy3Q(item, flag), i5DnesGv8v));
				stringBuilder.Append(i5DnesGv8v);
			}
			streamWriter.WriteLine(stringBuilder.ToString());
			string s = QMOnZcYf7s(okiBYmytZBf443ggmg.RcDQFZA1u2(3492));
			DateTime.ParseExact(s, okiBYmytZBf443ggmg.RcDQFZA1u2(3514), CultureInfo.InvariantCulture);
			string text = QMOnZcYf7s(okiBYmytZBf443ggmg.RcDQFZA1u2(3520));
			if (string.Empty == text)
			{
				List<string> list = new List<string>(uIsQnA55oC.Keys);
				list.Sort();
				text = list[list.Count - 1];
			}
			DateTime dateTime = DateTime.ParseExact(text, okiBYmytZBf443ggmg.RcDQFZA1u2(3540), CultureInfo.InvariantCulture);
			double result = 0.0;
			string text2 = QMOnZcYf7s(okiBYmytZBf443ggmg.RcDQFZA1u2(3546));
			if (!double.TryParse(text2, out result))
			{
				result = ((text2 == okiBYmytZBf443ggmg.RcDQFZA1u2(3574)) ? 1000.0 : ((!(text2 == okiBYmytZBf443ggmg.RcDQFZA1u2(3594))) ? 1000.0 : 5000.0));
			}
			Dictionary<string, string> parameterLastValue = new Dictionary<string, string>(CKmndrMLDb.Count);
			foreach (string key in GPqQQJf3bA.Keys)
			{
				if (!uIsQnA55oC.ContainsKey(key))
				{
					uIsQnA55oC.Add(key, new Dictionary<string, fJMjPMlWOWMvDvaXKF>());
				}
			}
			Dictionary<string, Dictionary<string, fJMjPMlWOWMvDvaXKF>>.Enumerator enumerator3 = uIsQnA55oC.GetEnumerator();
			DateTime dateTime2 = DateTime.MinValue;
			if (uIsQnA55oC.Count == 0)
			{
				dateTime2 = dateTime;
			}
			dp1QiMUpB3 = new Dictionary<string, string>();
			jklQ155o9r = DateTime.MinValue;
			sSMQqh8DrL = TimeSpan.FromMilliseconds(result);
			aPDQ2NrPae = TimeSpan.FromMilliseconds(result / 2.0);
			while (enumerator3.MoveNext())
			{
				DateTime dateTime3 = DateTime.ParseExact(enumerator3.Current.Key, okiBYmytZBf443ggmg.RcDQFZA1u2(3614), CultureInfo.InvariantCulture);
				DateTime minValue = DateTime.MinValue;
				Dictionary<string, fJMjPMlWOWMvDvaXKF> value = enumerator3.Current.Value;
				if (dateTime2 != DateTime.MinValue)
				{
					minValue = dateTime2.AddMilliseconds(result);
					while (dateTime3 > minValue)
					{
						if (!jBhn06Bsx5(minValue))
						{
							string text3 = vcqnOephq7(parameterLastValue, null, default(kYUB0I18kIk18NuuJo));
							Qmmn9Fr8jC(minValue, text3);
							dateTime2 = minValue;
							minValue = dateTime2.AddMilliseconds(result);
						}
						else
						{
							dateTime2 = minValue;
							minValue = kwSnNSOp2h(minValue);
						}
					}
				}
				kYUB0I18kIk18NuuJo kYUB0I18kIk18NuuJo = default(kYUB0I18kIk18NuuJo);
				if (GPqQQJf3bA.ContainsKey(enumerator3.Current.Key))
				{
					kYUB0I18kIk18NuuJo = GPqQQJf3bA[enumerator3.Current.Key];
					GPqQQJf3bA.Remove(enumerator3.Current.Key);
				}
				string text4 = OrwnuMPoWU(parameterLastValue, value, kYUB0I18kIk18NuuJo);
				Qmmn9Fr8jC(dateTime3, text4);
				dateTime2 = dateTime3;
			}
			if (dateTime != DateTime.MinValue)
			{
				DateTime dateTime4 = dateTime2.AddMilliseconds(result);
				while (dateTime4 < dateTime)
				{
					if (!jBhn06Bsx5(dateTime4))
					{
						SortedDictionary<string, kYUB0I18kIk18NuuJo>.Enumerator enumerator4 = new SortedDictionary<string, kYUB0I18kIk18NuuJo>(GPqQQJf3bA).GetEnumerator();
						while (enumerator4.MoveNext())
						{
							DateTime dateTime5 = DateTime.ParseExact(enumerator4.Current.Key, okiBYmytZBf443ggmg.RcDQFZA1u2(3620), CultureInfo.InvariantCulture);
							if (dateTime5 < dateTime4)
							{
								string text5 = vcqnOephq7(parameterLastValue, null, enumerator4.Current.Value);
								Qmmn9Fr8jC(dateTime5, text5);
								GPqQQJf3bA.Remove(enumerator4.Current.Key);
							}
						}
						string text6 = vcqnOephq7(parameterLastValue, null, default(kYUB0I18kIk18NuuJo));
						Qmmn9Fr8jC(dateTime4, text6);
						dateTime4 = dateTime4.AddMilliseconds(result);
					}
					else
					{
						dateTime4 = kwSnNSOp2h(dateTime4);
					}
				}
			}
			foreach (string value2 in dp1QiMUpB3.Values)
			{
				streamWriter.WriteLine(value2);
			}
			streamWriter.Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Qmmn9Fr8jC(DateTime P_0, string P_1)
		{
			string text = k0KHPqSeqjLIAypfo8.DxSSFBsPY(P_0, i5DnesGv8v);
			if (dp1QiMUpB3.ContainsKey(text))
			{
				string localizedString = PsXQleZ3Gx.GetLocalizedString(22);
				if (P_1.Contains(localizedString) && !dp1QiMUpB3[text].Contains(localizedString))
				{
					P_1 = string.Format(P_1, text);
					dp1QiMUpB3[text] = P_1;
				}
				jklQ155o9r = P_0;
				return;
			}
			if (jklQ155o9r == DateTime.MinValue)
			{
				text = k0KHPqSeqjLIAypfo8.DxSSFBsPY(P_0, i5DnesGv8v);
				P_1 = string.Format(P_1, text);
				if (dp1QiMUpB3.ContainsKey(text))
				{
					dp1QiMUpB3[text] = P_1;
				}
				else
				{
					dp1QiMUpB3.Add(text, P_1);
				}
				jklQ155o9r = P_0;
				return;
			}
			TimeSpan timeSpan = P_0 - jklQ155o9r;
			if (timeSpan < aPDQ2NrPae)
			{
				text = k0KHPqSeqjLIAypfo8.DxSSFBsPY(jklQ155o9r, i5DnesGv8v);
				string localizedString2 = PsXQleZ3Gx.GetLocalizedString(22);
				if (P_1.Contains(localizedString2) && !dp1QiMUpB3[text].Contains(localizedString2))
				{
					P_1 = string.Format(P_1, text);
					dp1QiMUpB3[text] = P_1;
				}
				return;
			}
			P_0 = jklQ155o9r.Add(sSMQqh8DrL);
			text = k0KHPqSeqjLIAypfo8.DxSSFBsPY(P_0, i5DnesGv8v);
			if (dp1QiMUpB3.ContainsKey(text))
			{
				jklQ155o9r = P_0;
				return;
			}
			P_1 = string.Format(P_1, text);
			dp1QiMUpB3.Add(text, P_1);
			jklQ155o9r = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string NYDnYKJhnH(string P_0)
		{
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append(((okiBYmytZBf443ggmg.RcDQFZA1u2(3626) == i5DnesGv8v) ? okiBYmytZBf443ggmg.RcDQFZA1u2(3632) : "") + QMOnZcYf7s(okiBYmytZBf443ggmg.RcDQFZA1u2(3638)));
			stringBuilder.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(3664));
			stringBuilder.Append(QMOnZcYf7s(okiBYmytZBf443ggmg.RcDQFZA1u2(3670)));
			stringBuilder.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(3692));
			stringBuilder.AppendLine(QMOnZcYf7s(okiBYmytZBf443ggmg.RcDQFZA1u2(3698)) + ((okiBYmytZBf443ggmg.RcDQFZA1u2(3724) == i5DnesGv8v) ? okiBYmytZBf443ggmg.RcDQFZA1u2(3730) : ""));
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(QMOnZcYf7s(okiBYmytZBf443ggmg.RcDQFZA1u2(3736)), i5DnesGv8v));
			stringBuilder.AppendLine(string.Empty);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(PsXQleZ3Gx.GetLocalizedString((NDofhxbDqP25Eb70va)14), i5DnesGv8v));
			stringBuilder.Append(i5DnesGv8v);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(PsXQleZ3Gx.GetLocalizedString((NDofhxbDqP25Eb70va)8), i5DnesGv8v));
			stringBuilder.Append(i5DnesGv8v);
			string s = QMOnZcYf7s(okiBYmytZBf443ggmg.RcDQFZA1u2(3762));
			DateTime dateTime = DateTime.ParseExact(s, okiBYmytZBf443ggmg.RcDQFZA1u2(3784), CultureInfo.InvariantCulture);
			string text = QMOnZcYf7s(okiBYmytZBf443ggmg.RcDQFZA1u2(3790));
			if (string.Empty == text)
			{
				List<string> list = new List<string>(uIsQnA55oC.Keys);
				list.Sort();
				text = list[list.Count - 1];
			}
			DateTime dateTime2 = DateTime.ParseExact(text, okiBYmytZBf443ggmg.RcDQFZA1u2(3810), CultureInfo.InvariantCulture);
			TimeSpan timeSpan = dateTime2 - dateTime;
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(k0KHPqSeqjLIAypfo8.DxSSFBsPY(dateTime, i5DnesGv8v), i5DnesGv8v));
			stringBuilder.Append(i5DnesGv8v);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(PsXQleZ3Gx.GetLocalizedString((NDofhxbDqP25Eb70va)9), i5DnesGv8v));
			stringBuilder.Append(i5DnesGv8v);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(k0KHPqSeqjLIAypfo8.ieqJjLIAy(timeSpan), i5DnesGv8v));
			stringBuilder.Append(i5DnesGv8v);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(PsXQleZ3Gx.GetLocalizedString((NDofhxbDqP25Eb70va)7), i5DnesGv8v));
			stringBuilder.Append(i5DnesGv8v);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(QMOnZcYf7s(okiBYmytZBf443ggmg.RcDQFZA1u2(3816)), i5DnesGv8v));
			stringBuilder.Append(i5DnesGv8v);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(PsXQleZ3Gx.GetLocalizedString((NDofhxbDqP25Eb70va)19), i5DnesGv8v));
			stringBuilder.Append(i5DnesGv8v);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(Path.GetDirectoryName(P_0), i5DnesGv8v));
			stringBuilder.Append(i5DnesGv8v);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(PsXQleZ3Gx.GetLocalizedString((NDofhxbDqP25Eb70va)5), i5DnesGv8v));
			stringBuilder.Append(i5DnesGv8v);
			if (QMOnZcYf7s(okiBYmytZBf443ggmg.RcDQFZA1u2(3848)).ToUpper() == okiBYmytZBf443ggmg.RcDQFZA1u2(3876))
			{
				stringBuilder.AppendLine(((okiBYmytZBf443ggmg.RcDQFZA1u2(3896) == i5DnesGv8v) ? okiBYmytZBf443ggmg.RcDQFZA1u2(3902) : "") + PsXQleZ3Gx.GetLocalizedString((NDofhxbDqP25Eb70va)20) + ((okiBYmytZBf443ggmg.RcDQFZA1u2(3908) == i5DnesGv8v) ? okiBYmytZBf443ggmg.RcDQFZA1u2(3914) : ""));
			}
			else
			{
				double result = 0.0;
				double.TryParse(QMOnZcYf7s(okiBYmytZBf443ggmg.RcDQFZA1u2(3920)), out result);
				double num = result / 1000.0;
				stringBuilder.Append(((okiBYmytZBf443ggmg.RcDQFZA1u2(3948) == i5DnesGv8v) ? okiBYmytZBf443ggmg.RcDQFZA1u2(3954) : "") + num);
				stringBuilder.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(3960));
				stringBuilder.AppendLine(PsXQleZ3Gx.GetLocalizedString((NDofhxbDqP25Eb70va)1) + ((okiBYmytZBf443ggmg.RcDQFZA1u2(3966) == i5DnesGv8v) ? okiBYmytZBf443ggmg.RcDQFZA1u2(3972) : ""));
			}
			stringBuilder.Append(i5DnesGv8v);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(PsXQleZ3Gx.GetLocalizedString((NDofhxbDqP25Eb70va)2), i5DnesGv8v));
			stringBuilder.Append(i5DnesGv8v);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(QMOnZcYf7s(okiBYmytZBf443ggmg.RcDQFZA1u2(3978)), i5DnesGv8v));
			stringBuilder.AppendLine(string.Empty);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(PsXQleZ3Gx.GetLocalizedString((NDofhxbDqP25Eb70va)12), i5DnesGv8v));
			stringBuilder.Append(i5DnesGv8v);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(PsXQleZ3Gx.GetLocalizedString((NDofhxbDqP25Eb70va)3), i5DnesGv8v));
			stringBuilder.Append(i5DnesGv8v);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(QMOnZcYf7s(okiBYmytZBf443ggmg.RcDQFZA1u2(3998)), i5DnesGv8v));
			stringBuilder.Append(i5DnesGv8v);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(PsXQleZ3Gx.GetLocalizedString((NDofhxbDqP25Eb70va)10), i5DnesGv8v));
			stringBuilder.Append(i5DnesGv8v);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(QMOnZcYf7s(okiBYmytZBf443ggmg.RcDQFZA1u2(4026)), i5DnesGv8v));
			stringBuilder.AppendLine(string.Empty);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(PsXQleZ3Gx.GetLocalizedString((NDofhxbDqP25Eb70va)13), i5DnesGv8v));
			stringBuilder.Append(i5DnesGv8v);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(PsXQleZ3Gx.GetLocalizedString((NDofhxbDqP25Eb70va)4), i5DnesGv8v));
			stringBuilder.Append(i5DnesGv8v);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(QMOnZcYf7s(okiBYmytZBf443ggmg.RcDQFZA1u2(4064)), i5DnesGv8v));
			stringBuilder.Append(i5DnesGv8v);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(PsXQleZ3Gx.GetLocalizedString((NDofhxbDqP25Eb70va)6), i5DnesGv8v));
			stringBuilder.Append(i5DnesGv8v);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(QMOnZcYf7s(okiBYmytZBf443ggmg.RcDQFZA1u2(4090)), i5DnesGv8v));
			stringBuilder.Append(i5DnesGv8v);
			stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(PsXQleZ3Gx.GetLocalizedString((NDofhxbDqP25Eb70va)16), i5DnesGv8v));
			stringBuilder.Append(i5DnesGv8v);
			stringBuilder.AppendLine(k0KHPqSeqjLIAypfo8.V2OloNCJp(QMOnZcYf7s(okiBYmytZBf443ggmg.RcDQFZA1u2(4130)), i5DnesGv8v));
			return stringBuilder.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string OrwnuMPoWU(Dictionary<string, string> parameterLastValue, Dictionary<string, fJMjPMlWOWMvDvaXKF> values, kYUB0I18kIk18NuuJo P_2)
		{
			StringBuilder stringBuilder = new StringBuilder();
			if (BMlQIROeHE)
			{
				if (string.IsNullOrEmpty(P_2.vOgGbaD4W))
				{
					stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(okiBYmytZBf443ggmg.RcDQFZA1u2(4160), i5DnesGv8v));
				}
				else
				{
					stringBuilder.Append(((okiBYmytZBf443ggmg.RcDQFZA1u2(4166) == i5DnesGv8v) ? okiBYmytZBf443ggmg.RcDQFZA1u2(4172) : "") + PsXQleZ3Gx.GetLocalizedString((NDofhxbDqP25Eb70va)22));
					stringBuilder.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(4178));
					stringBuilder.Append(P_2.vOgGbaD4W);
					if (!string.IsNullOrEmpty(P_2.kA3oio1uX))
					{
						stringBuilder.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(4184));
						stringBuilder.Append(k0KHPqSeqjLIAypfo8.Dr2IqYVUQ(P_2.kA3oio1uX) + ((okiBYmytZBf443ggmg.RcDQFZA1u2(4190) == i5DnesGv8v) ? okiBYmytZBf443ggmg.RcDQFZA1u2(4196) : ""));
					}
					else
					{
						stringBuilder.Append((okiBYmytZBf443ggmg.RcDQFZA1u2(4202) == i5DnesGv8v) ? okiBYmytZBf443ggmg.RcDQFZA1u2(4208) : "");
					}
				}
				stringBuilder.Append(i5DnesGv8v);
			}
			stringBuilder.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(4214));
			stringBuilder.Append(i5DnesGv8v);
			for (int i = 0; i < CKmndrMLDb.Count; i++)
			{
				if (values.ContainsKey(CKmndrMLDb[i]))
				{
					string key = CKmndrMLDb[i];
					fJMjPMlWOWMvDvaXKF fJMjPMlWOWMvDvaXKF = values[key];
					stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(fJMjPMlWOWMvDvaXKF.yDLmpTNn0, i5DnesGv8v));
					if (!parameterLastValue.ContainsKey(key))
					{
						parameterLastValue.Add(key, string.Empty);
					}
					parameterLastValue[key] = fJMjPMlWOWMvDvaXKF.yDLmpTNn0;
				}
				else
				{
					if (values.ContainsKey(okiBYmytZBf443ggmg.RcDQFZA1u2(4224)))
					{
						foreach (string item in values[okiBYmytZBf443ggmg.RcDQFZA1u2(4260)].e8kgIk18N)
						{
							parameterLastValue[item] = string.Empty;
						}
					}
					string text = string.Empty;
					if (parameterLastValue.ContainsKey(CKmndrMLDb[i]))
					{
						text = parameterLastValue[CKmndrMLDb[i]];
					}
					stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(text, i5DnesGv8v));
				}
				stringBuilder.Append(i5DnesGv8v);
			}
			return stringBuilder.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string vcqnOephq7(Dictionary<string, string> parameterLastValue, Dictionary<string, fJMjPMlWOWMvDvaXKF> values, kYUB0I18kIk18NuuJo P_2)
		{
			StringBuilder stringBuilder = new StringBuilder();
			if (BMlQIROeHE)
			{
				if (string.IsNullOrEmpty(P_2.vOgGbaD4W))
				{
					stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(okiBYmytZBf443ggmg.RcDQFZA1u2(4296), i5DnesGv8v));
					stringBuilder.Append(i5DnesGv8v);
				}
				else
				{
					stringBuilder.Append(((okiBYmytZBf443ggmg.RcDQFZA1u2(4302) == i5DnesGv8v) ? okiBYmytZBf443ggmg.RcDQFZA1u2(4308) : "") + PsXQleZ3Gx.GetLocalizedString((NDofhxbDqP25Eb70va)22));
					stringBuilder.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(4314));
					stringBuilder.Append(P_2.vOgGbaD4W);
					if (!string.IsNullOrEmpty(P_2.kA3oio1uX))
					{
						stringBuilder.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(4320));
						stringBuilder.Append(k0KHPqSeqjLIAypfo8.Dr2IqYVUQ(P_2.kA3oio1uX) + ((okiBYmytZBf443ggmg.RcDQFZA1u2(4326) == i5DnesGv8v) ? okiBYmytZBf443ggmg.RcDQFZA1u2(4332) : ""));
					}
					else
					{
						stringBuilder.Append((okiBYmytZBf443ggmg.RcDQFZA1u2(4338) == i5DnesGv8v) ? okiBYmytZBf443ggmg.RcDQFZA1u2(4344) : "");
					}
					stringBuilder.Append(i5DnesGv8v);
				}
			}
			stringBuilder.Append(okiBYmytZBf443ggmg.RcDQFZA1u2(4350));
			stringBuilder.Append(i5DnesGv8v);
			for (int i = 0; i < CKmndrMLDb.Count; i++)
			{
				if (values != null && values.ContainsKey(okiBYmytZBf443ggmg.RcDQFZA1u2(4360)))
				{
					foreach (string item in values[okiBYmytZBf443ggmg.RcDQFZA1u2(4396)].e8kgIk18N)
					{
						parameterLastValue[item] = string.Empty;
					}
				}
				string text = string.Empty;
				if (parameterLastValue.ContainsKey(CKmndrMLDb[i]))
				{
					text = parameterLastValue[CKmndrMLDb[i]];
				}
				stringBuilder.Append(k0KHPqSeqjLIAypfo8.V2OloNCJp(text, i5DnesGv8v));
				stringBuilder.Append(i5DnesGv8v);
			}
			return stringBuilder.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string a73nTTmWP6(string P_0, string P_1)
		{
			int moduleType = T6sQPfEolr[int.Parse(P_1)];
			ECMSERVICESAPILib.IParameterDefinition parameterDefinition = KURQ6CgG7K.GetParameterDefinition(P_0, moduleType);
			return parameterDefinition.Name;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string fTQnM4hy3Q(string P_0, bool P_1)
		{
			string[] separator = new string[1] { okiBYmytZBf443ggmg.RcDQFZA1u2(4432) };
			string[] array = P_0.Split(separator, StringSplitOptions.RemoveEmptyEntries);
			if (P_1)
			{
				StringBuilder stringBuilder = new StringBuilder(array[0]);
				stringBuilder.Append(PsXQleZ3Gx.GetLocalizedString((NDofhxbDqP25Eb70va)15));
				stringBuilder.Append(array[1]);
				return stringBuilder.ToString();
			}
			return array[0];
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string QMOnZcYf7s(string P_0)
		{
			string result = string.Empty;
			if (eOZnrKbeQT.ContainsKey(P_0))
			{
				result = eOZnrKbeQT[P_0];
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private DateTime kwSnNSOp2h(DateTime P_0)
		{
			foreach (ELpTNnq05WPeIrvjdL item in wkyQce1S3r)
			{
				if (P_0 < item.xhxsDqP25)
				{
					return item.xhxsDqP25;
				}
			}
			return DateTime.MinValue;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private bool jBhn06Bsx5(DateTime P_0)
		{
			foreach (ELpTNnq05WPeIrvjdL item in wkyQce1S3r)
			{
				if (P_0 > item.ToJfTaYDo && P_0 < item.xhxsDqP25)
				{
					return true;
				}
			}
			return false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void zHKnxZD0rt()
		{
			try
			{
				eOZnrKbeQT.Clear();
				CKmndrMLDb.Clear();
				xvNnpEGbAC.Clear();
				i5DnesGv8v = string.Empty;
				xWcn8Iu0wq.wYFU1RJkL();
				X04nzWeKn8 = string.Empty;
				ImqQ5iMTAS = string.Empty;
				wkyQce1S3r.Clear();
				uIsQnA55oC.Clear();
				GPqQQJf3bA.Clear();
				KURQ6CgG7K = null;
				T6sQPfEolr.Clear();
			}
			catch
			{
			}
		}
	}
}
namespace DataMonitorLoggerAPILib
{
	[ComImport]
	[TypeIdentifier]
	[CompilerGenerated]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	[Guid("87C8380E-FB35-4B66-A402-06CC254B9F42")]
	public interface IDMLLogFileConverter
	{
		void ConvertLogFile([In][MarshalAs(UnmanagedType.BStr)] string sourceFileName, [In][MarshalAs(UnmanagedType.BStr)] string destinationFileName, [In][MarshalAs(UnmanagedType.BStr)] string delimitingCharacter);

		void Initialize([In][MarshalAs(UnmanagedType.IUnknown)] object pParameterDefinitions);
	}
}
namespace ECMSERVICESAPILib
{
	[ComImport]
	[CompilerGenerated]
	[TypeIdentifier]
	[Guid("9A6B734A-4210-4276-A9BE-6763F1AFC98B")]
	public interface IParameterDefinition
	{
		void _VtblGap1_4();

		string Name
		{
			[DispId(5)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}
	}
	[ComImport]
	[CompilerGenerated]
	[TypeIdentifier]
	[Guid("14483239-A3A3-4C11-8A19-183FC64F9E67")]
	public interface IParameterDefinitions
	{
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.Interface)]
		IParameterDefinition GetParameterDefinition([In][MarshalAs(UnmanagedType.BStr)] string ParameterID, [In] int ModuleType);
	}
}
internal class <Module>{3D00AC45-CFD6-4005-ABB7-C732F8FF4893}
{
}
namespace ckSOSNHNjCxiK2Ls4i
{
	internal class xtlBoGapgf9L39Q28I
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module CEkQbNHAkR;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void vhGoUTjjMSo7H(int typemdt)
		{
			Type type = CEkQbNHAkR.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)CEkQbNHAkR.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public xtlBoGapgf9L39Q28I()
		{
			F1TW9EoVrvRILSscdn.D9BoUTjzdJlSt();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static xtlBoGapgf9L39Q28I()
		{
			F1TW9EoVrvRILSscdn.D9BoUTjzdJlSt();
			CEkQbNHAkR = typeof(xtlBoGapgf9L39Q28I).Assembly.ManifestModule;
		}
	}
}
namespace BWA9ANgCc3X3ynNEP5
{
	internal class okiBYmytZBf443ggmg
	{
		internal class frRhTV3aDevHFxRZMw : Attribute
		{
			internal class lHZvjbLOOFBM6J13BB<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public lHZvjbLOOFBM6J13BB()
				{
					F1TW9EoVrvRILSscdn.D9BoUTjzdJlSt();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[frRhTV3aDevHFxRZMw(typeof(okiBYmytZBf443ggmg/frRhTV3aDevHFxRZMw/lHZvjbLOOFBM6J13BB<object>[]))]
			public frRhTV3aDevHFxRZMw(object P_0)
			{
				F1TW9EoVrvRILSscdn.D9BoUTjzdJlSt();
				base..ctor();
			}
		}

		internal class xgGTNUfyTFWXFr3r3U
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[frRhTV3aDevHFxRZMw(typeof(okiBYmytZBf443ggmg/frRhTV3aDevHFxRZMw/lHZvjbLOOFBM6J13BB<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (HSGScWQNIs(Convert.ToBase64String(typeof(okiBYmytZBf443ggmg).Assembly.GetName().GetPublicKeyToken()), okiBYmytZBf443ggmg.RcDQFZA1u2(4438)) != okiBYmytZBf443ggmg.RcDQFZA1u2(4444))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[frRhTV3aDevHFxRZMw(typeof(okiBYmytZBf443ggmg/frRhTV3aDevHFxRZMw/lHZvjbLOOFBM6J13BB<object>[]))]
			internal static string HSGScWQNIs(string P_0, string P_1)
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
			public xgGTNUfyTFWXFr3r3U()
			{
				F1TW9EoVrvRILSscdn.D9BoUTjzdJlSt();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint H9gmkis9ZKY0pZqM7X([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr M3mm3uhWLXgGCNohEK();

		internal struct NrJJ8iG3ix00NSFChv
		{
			internal bool p6xSnHmVfP;

			internal byte[] U6BSQWXtJ8;
		}

		[Flags]
		private enum oSBE3jwCYJBLdaBGHD
		{

		}

		private static byte[] hvSQR37vWl;

		private static byte[] TV2Q4Tj2wp;

		private static IntPtr vWMQYJtw0k;

		private static int pwyQTIJrDf;

		private static bool QFWQMuIrkP;

		private static long f5IQdMaYpH;

		internal static Hashtable d8uS5gd4nE;

		private static SortedList T6YQZMAUPI;

		private static int VAoQ83ZG1a;

		private static IntPtr kguQ90veyM;

		private static IntPtr sitQzsIvA2;

		private static bool vc3QeewLv2;

		private static byte[] xE9QKh77qu;

		private static byte[] Jx2QWUH4Hu;

		private static int ohqQNviw1K;

		internal static H9gmkis9ZKY0pZqM7X ebUQxkJQHb;

		private static int[] ScaQOxsYgi;

		private static long JIlQ0H78d8;

		internal static H9gmkis9ZKY0pZqM7X NptQrnBMtI;

		private static object eNGQuFMA81;

		private static int l9oQp5Me8b;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static okiBYmytZBf443ggmg()
		{
			Jx2QWUH4Hu = new byte[0];
			xE9QKh77qu = new byte[0];
			hvSQR37vWl = new byte[0];
			TV2Q4Tj2wp = new byte[0];
			kguQ90veyM = IntPtr.Zero;
			vWMQYJtw0k = IntPtr.Zero;
			eNGQuFMA81 = new string[0];
			ScaQOxsYgi = new int[0];
			pwyQTIJrDf = 1;
			QFWQMuIrkP = false;
			T6YQZMAUPI = new SortedList();
			ohqQNviw1K = 0;
			JIlQ0H78d8 = 0L;
			ebUQxkJQHb = null;
			NptQrnBMtI = null;
			f5IQdMaYpH = 0L;
			l9oQp5Me8b = 0;
			vc3QeewLv2 = false;
			VAoQ83ZG1a = 0;
			sitQzsIvA2 = IntPtr.Zero;
			d8uS5gd4nE = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void vlJoUTjsIr3LV()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[frRhTV3aDevHFxRZMw(typeof(okiBYmytZBf443ggmg/frRhTV3aDevHFxRZMw/lHZvjbLOOFBM6J13BB<object>[]))]
		static string RcDQFZA1u2(int P_0)
		{
			int num = 24;
			byte[] array2 = default(byte[]);
			int num7 = default(int);
			CryptoStream cryptoStream = default(CryptoStream);
			int num6 = default(int);
			byte[] array3 = default(byte[]);
			int num5 = default(int);
			int num8 = default(int);
			byte[] array6 = default(byte[]);
			byte[] array5 = default(byte[]);
			BinaryReader binaryReader = default(BinaryReader);
			MemoryStream memoryStream = default(MemoryStream);
			ICryptoTransform transform = default(ICryptoTransform);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array4 = default(byte[]);
			byte[] array = default(byte[]);
			int num2 = default(int);
			while (true)
			{
				int num3;
				int num4;
				switch (num)
				{
				case 35:
					array2[17] = (byte)num7;
					num3 = 253;
					goto IL_15c2;
				case 193:
					kWxWoSmf27YQWThqkj(cryptoStream);
					num3 = 67;
					if (zifGxiL8BncgdAr5Et())
					{
						goto case 260;
					}
					goto IL_15c2;
				case 0:
					num6 = 15 + 91;
					num = 217;
					break;
				case 9:
					array2[26] = (byte)num7;
					num4 = 176;
					goto IL_15be;
				case 313:
					num7 = 205 - 68;
					num3 = 35;
					if (false)
					{
						goto case 320;
					}
					goto IL_15c2;
				case 320:
					array2[29] = 15;
					num = 186;
					break;
				case 144:
					array2[22] = (byte)num6;
					num3 = 315;
					if (zifGxiL8BncgdAr5Et())
					{
						goto case 305;
					}
					goto IL_15c2;
				case 305:
					array2[0] = (byte)num6;
					num4 = 8;
					goto IL_15be;
				case 158:
					array3[11] = (byte)num5;
					num3 = 79;
					goto IL_15c2;
				case 197:
					num6 = 82 + 65;
					num3 = 314;
					if (!F9MSdpWg9I3uOoVfNd())
					{
						goto case 251;
					}
					goto IL_15c2;
				case 251:
					array3[8] = (byte)num8;
					num4 = 26;
					goto IL_15be;
				case 107:
					num6 = 254 - 84;
					num = 51;
					break;
				case 7:
					array2[13] = 53;
					num = 108;
					break;
				case 121:
					array2[1] = 61;
					num3 = 283;
					if (1 == 0)
					{
						goto case 326;
					}
					goto IL_15c2;
				case 326:
					array2[14] = (byte)num7;
					num4 = 141;
					goto IL_15be;
				case 90:
					num5 = 155 - 51;
					num = 65;
					break;
				case 138:
					array3[3] = (byte)num5;
					num3 = 295;
					if (!F9MSdpWg9I3uOoVfNd())
					{
						goto case 98;
					}
					goto IL_15c2;
				case 234:
					array3[2] = (byte)num5;
					num3 = 207;
					goto IL_15c2;
				case 210:
				case 227:
					num5 = 153 - 51;
					num3 = 234;
					goto IL_15c2;
				case 169:
					array3[6] = 224;
					num3 = 212;
					if (1 == 0)
					{
						goto case 325;
					}
					goto IL_15c2;
				case 325:
					array2[20] = (byte)num6;
					num4 = 205;
					goto IL_15be;
				case 341:
					array3[9] = 95;
					num = 334;
					break;
				case 172:
					array2[28] = (byte)num7;
					num = 73;
					break;
				case 34:
					array3 = new byte[16];
					num4 = 164;
					goto IL_15be;
				case 299:
					num6 = 137 - 45;
					num3 = 165;
					if (!zifGxiL8BncgdAr5Et())
					{
						goto IL_15c2;
					}
					goto case 311;
				case 143:
					array2[18] = 113;
					num = 308;
					break;
				case 45:
					array2[9] = (byte)num6;
					num3 = 161;
					goto IL_15c2;
				case 94:
					array3[15] = 137;
					num4 = 254;
					goto IL_15be;
				case 12:
					array6[9] = array5[4];
					num = 1;
					break;
				case 98:
					num7 = 41 + 2;
					num = 172;
					break;
				case 49:
					binaryReader = new BinaryReader((Stream)AR4fukR0t5ivAKRy2A(jLvhaHj8PYEuYQCjin(typeof(okiBYmytZBf443ggmg).TypeHandle).Assembly, "S3cG7Mclb1e2ghFyt9.O6pPqYvFIssajttMig"));
					num3 = 259;
					if (zifGxiL8BncgdAr5Et())
					{
						goto case 196;
					}
					goto IL_15c2;
				case 196:
					array2[26] = 109;
					num4 = 323;
					goto IL_15be;
				case 135:
					array2[23] = (byte)num7;
					num3 = 331;
					if (!F9MSdpWg9I3uOoVfNd())
					{
						goto case 26;
					}
					goto IL_15c2;
				case 26:
					num8 = 131 - 43;
					num = 199;
					break;
				case 54:
					array3[15] = (byte)num8;
					num4 = 279;
					goto IL_15be;
				case 256:
					array2[13] = 187;
					num4 = 246;
					goto IL_15be;
				case 306:
					array3[0] = (byte)num8;
					num = 33;
					break;
				case 150:
					cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
					num4 = 157;
					goto IL_15be;
				case 177:
					array2[12] = (byte)num6;
					num = 63;
					break;
				case 265:
					array2[23] = (byte)num7;
					num3 = 3;
					goto IL_15c2;
				case 316:
					num7 = 82 - 40;
					num3 = 126;
					goto IL_15c2;
				case 85:
					num7 = 181 - 60;
					num3 = 82;
					if (false)
					{
						goto case 75;
					}
					goto IL_15c2;
				case 75:
					num7 = 42 + 27;
					num4 = 13;
					goto IL_15be;
				case 342:
					array2[6] = 104;
					num = 201;
					break;
				case 214:
					num8 = 186 - 62;
					num4 = 96;
					goto IL_15be;
				case 290:
					num8 = 185 - 61;
					num4 = 232;
					goto IL_15be;
				case 217:
					array2[11] = (byte)num6;
					num3 = 17;
					if (false)
					{
						goto case 315;
					}
					goto IL_15c2;
				case 315:
					num6 = 229 - 76;
					num3 = 105;
					goto IL_15c2;
				case 226:
					array3[1] = 69;
					goto case 210;
				case 219:
					array6[1] = array5[0];
					num3 = 129;
					goto IL_15c2;
				case 4:
					num5 = 55 + 103;
					num4 = 134;
					goto IL_15be;
				case 230:
					array2[7] = 125;
					num3 = 268;
					goto IL_15c2;
				case 52:
					array3[7] = 102;
					num3 = 64;
					goto IL_15c2;
				case 137:
					array2[7] = (byte)num6;
					num = 83;
					break;
				case 212:
					array3[6] = 151;
					num3 = 52;
					if (1 == 0)
					{
						goto case 298;
					}
					goto IL_15c2;
				case 298:
					array2[14] = 31;
					num4 = 171;
					goto IL_15be;
				case 1:
					array6[11] = array5[5];
					num = 224;
					break;
				case 68:
					num5 = 232 - 110;
					num = 151;
					break;
				case 146:
					array2[3] = 103;
					num4 = 274;
					goto IL_15be;
				case 40:
					array3[0] = 40;
					num = 344;
					break;
				case 314:
					array2[25] = (byte)num6;
					num = 125;
					break;
				case 73:
					array2[28] = 125;
					num3 = 19;
					if (zifGxiL8BncgdAr5Et())
					{
						goto case 222;
					}
					goto IL_15c2;
				case 222:
					array3[7] = 93;
					num3 = 257;
					if (zifGxiL8BncgdAr5Et())
					{
						goto case 38;
					}
					goto IL_15c2;
				case 79:
					array3[11] = 166;
					num = 228;
					break;
				case 334:
					array3[9] = 220;
					num = 90;
					break;
				case 36:
					array2[17] = (byte)num7;
					num = 313;
					break;
				case 51:
					array2[24] = (byte)num6;
					num = 102;
					break;
				case 176:
					array2[27] = 201;
					num3 = 294;
					goto IL_15c2;
				case 112:
					array2[13] = (byte)num7;
					num3 = 256;
					goto IL_15c2;
				case 183:
					array3[6] = (byte)num5;
					num4 = 169;
					goto IL_15be;
				case 104:
					num6 = 154 - 51;
					num3 = 20;
					if (zifGxiL8BncgdAr5Et())
					{
						goto case 163;
					}
					goto IL_15c2;
				case 163:
					array3[5] = 88;
					num3 = 41;
					if (zifGxiL8BncgdAr5Et())
					{
						goto case 12;
					}
					goto IL_15c2;
				case 261:
					num7 = 82 + 65;
					num = 135;
					break;
				case 109:
					array3[5] = 133;
					num3 = 238;
					goto IL_15c2;
				case 228:
					array3[11] = 64;
					num = 132;
					break;
				case 250:
					num5 = 174 - 58;
					num3 = 174;
					if (!F9MSdpWg9I3uOoVfNd())
					{
						goto case 258;
					}
					goto IL_15c2;
				case 258:
					array2[30] = 164;
					num = 299;
					break;
				case 276:
					array2[5] = (byte)num7;
					num4 = 6;
					goto IL_15be;
				case 128:
					array3[12] = 106;
					num = 76;
					break;
				case 203:
					array2[10] = 132;
					num3 = 245;
					goto IL_15c2;
				case 263:
					num5 = 98 + 10;
					num = 56;
					break;
				case 120:
					array2[25] = 70;
					num3 = 91;
					goto IL_15c2;
				case 25:
					num7 = 211 - 70;
					num3 = 110;
					if (!zifGxiL8BncgdAr5Et())
					{
						goto IL_15c2;
					}
					goto case 331;
				case 190:
					FCKetEJTk4N7AmOlyx(memoryStream);
					num3 = 149;
					if (1 == 0)
					{
						goto case 118;
					}
					goto IL_15c2;
				case 118:
					array2[4] = 102;
					num3 = 148;
					goto IL_15c2;
				case 249:
					array3[14] = (byte)num5;
					num = 185;
					break;
				case 53:
					array3[13] = 177;
					num3 = 123;
					goto IL_15c2;
				case 200:
					num7 = 62 + 21;
					num4 = 153;
					goto IL_15be;
				case 123:
					num5 = 214 - 71;
					num3 = 343;
					if (1 == 0)
					{
						goto case 243;
					}
					goto IL_15c2;
				case 243:
					num6 = 115 + 22;
					num3 = 133;
					if (1 == 0)
					{
						goto case 240;
					}
					goto IL_15c2;
				case 240:
					array2[20] = 112;
					num = 304;
					break;
				case 57:
					array2[24] = (byte)num7;
					num3 = 69;
					if (1 == 0)
					{
						goto case 39;
					}
					goto IL_15c2;
				case 39:
					array2[21] = (byte)num6;
					num3 = 66;
					if (zifGxiL8BncgdAr5Et())
					{
						goto case 221;
					}
					goto IL_15c2;
				case 221:
					num7 = 130 - 43;
					num4 = 36;
					goto IL_15be;
				case 232:
					array3[13] = (byte)num8;
					num3 = 27;
					goto IL_15c2;
				case 15:
					num6 = 232 - 77;
					num4 = 144;
					goto IL_15be;
				case 164:
					num8 = 104 + 46;
					num3 = 159;
					goto IL_15c2;
				case 105:
					array2[22] = (byte)num6;
					num3 = 318;
					if (1 == 0)
					{
						goto case 99;
					}
					goto IL_15c2;
				case 99:
					num6 = 219 - 73;
					num4 = 71;
					goto IL_15be;
				case 82:
					array2[20] = (byte)num7;
					num3 = 240;
					goto IL_15c2;
				case 343:
					array3[14] = (byte)num5;
					num = 116;
					break;
				case 8:
					array2[0] = 66;
					num3 = 239;
					if (!F9MSdpWg9I3uOoVfNd())
					{
						goto case 272;
					}
					goto IL_15c2;
				case 272:
					array2[27] = (byte)num6;
					num3 = 345;
					goto IL_15c2;
				case 113:
					array2[26] = (byte)num7;
					num4 = 196;
					goto IL_15be;
				case 215:
					array2[4] = (byte)num6;
					num = 296;
					break;
				case 29:
					array2[0] = 156;
					num3 = 124;
					goto IL_15c2;
				case 283:
					num6 = 232 - 77;
					num4 = 10;
					goto IL_15be;
				case 74:
					num6 = 45 + 30;
					num = 45;
					break;
				case 246:
					num7 = 114 + 58;
					num4 = 269;
					goto IL_15be;
				case 27:
					array3[13] = 53;
					num4 = 53;
					goto IL_15be;
				case 291:
					num6 = 71 + 3;
					num3 = 166;
					if (1 == 0)
					{
						goto case 101;
					}
					goto IL_15c2;
				case 101:
					array3[12] = (byte)num5;
					num3 = 192;
					if (1 == 0)
					{
						goto case 20;
					}
					goto IL_15c2;
				case 20:
					array2[4] = (byte)num6;
					num3 = 216;
					if (zifGxiL8BncgdAr5Et())
					{
						goto case 205;
					}
					goto IL_15c2;
				case 242:
					num5 = 62 + 47;
					num = 303;
					break;
				case 333:
					num6 = 148 - 49;
					num3 = 145;
					if (1 == 0)
					{
						goto case 317;
					}
					goto IL_15c2;
				case 317:
					array3[5] = (byte)num5;
					num = 109;
					break;
				case 337:
					array2[5] = 90;
					num4 = 106;
					goto IL_15be;
				case 278:
					array2[18] = (byte)num6;
					num3 = 143;
					if (zifGxiL8BncgdAr5Et())
					{
						goto case 131;
					}
					goto IL_15c2;
				case 131:
					if (array5.Length > 0)
					{
						num3 = 219;
						goto IL_15c2;
					}
					goto case 48;
				case 281:
					array2[1] = 84;
					num3 = 152;
					if (!F9MSdpWg9I3uOoVfNd())
					{
						goto case 207;
					}
					goto IL_15c2;
				case 93:
					array6[5] = array5[2];
					num4 = 229;
					goto IL_15be;
				case 148:
					num6 = 62 + 47;
					num4 = 338;
					goto IL_15be;
				case 11:
					num7 = 97 - 8;
					num = 22;
					break;
				case 271:
					num7 = 124 + 38;
					num3 = 198;
					goto IL_15c2;
				case 141:
					array2[14] = 162;
					num3 = 336;
					if (false)
					{
						goto case 22;
					}
					goto IL_15c2;
				case 22:
					array2[22] = (byte)num7;
					num3 = 209;
					if (zifGxiL8BncgdAr5Et())
					{
						goto case 86;
					}
					goto IL_15c2;
				case 86:
					if (array5 != null)
					{
						num = 131;
						break;
					}
					goto case 48;
				case 59:
					array3[14] = 200;
					num = 30;
					break;
				case 289:
					array2[19] = 149;
					num4 = 225;
					goto IL_15be;
				case 129:
					array6[3] = array5[1];
					num = 93;
					break;
				case 236:
					num5 = 3 + 117;
					num = 81;
					break;
				case 136:
					num6 = 97 - 37;
					num = 215;
					break;
				case 220:
					num6 = 136 - 45;
					num3 = 305;
					if (false)
					{
						goto case 206;
					}
					goto IL_15c2;
				case 206:
					num8 = 155 - 51;
					num = 47;
					break;
				case 247:
					array2[9] = (byte)num6;
					num4 = 243;
					goto IL_15be;
				case 100:
					array3[13] = 98;
					num4 = 233;
					goto IL_15be;
				case 88:
					array2[2] = 131;
					num4 = 117;
					goto IL_15be;
				case 89:
					array3[12] = 16;
					num4 = 100;
					goto IL_15be;
				case 259:
					zMHv4SlQi7TOrESf7U(notKm6rpFajRKALdV3(binaryReader), 0L);
					num4 = 179;
					goto IL_15be;
				case 159:
					array3[0] = (byte)num8;
					num = 40;
					break;
				case 213:
					array2[3] = (byte)num6;
					num3 = 92;
					if (!F9MSdpWg9I3uOoVfNd())
					{
						goto case 79;
					}
					goto IL_15c2;
				case 78:
					num5 = 12 + 22;
					num4 = 189;
					goto IL_15be;
				case 336:
					array2[14] = 38;
					num4 = 333;
					goto IL_15be;
				case 24:
					if (hvSQR37vWl.Length == 0)
					{
						num = 49;
						break;
					}
					goto case 46;
				case 207:
					num5 = 199 - 66;
					num = 122;
					break;
				case 209:
					array2[23] = 130;
					num4 = 115;
					goto IL_15be;
				case 91:
					array2[25] = 165;
					num4 = 197;
					goto IL_15be;
				case 165:
					array2[31] = (byte)num6;
					num3 = 248;
					goto IL_15c2;
				case 303:
					array3[4] = (byte)num5;
					num3 = 332;
					if (false)
					{
						goto case 255;
					}
					goto IL_15c2;
				case 255:
					array2[15] = (byte)num7;
					num = 77;
					break;
				case 56:
					array3[3] = (byte)num5;
					num3 = 260;
					if (zifGxiL8BncgdAr5Et())
					{
						goto case 295;
					}
					goto IL_15c2;
				case 295:
					array3[4] = 102;
					num = 242;
					break;
				case 205:
					num7 = 171 - 57;
					num = 327;
					break;
				case 260:
					array3[3] = 103;
					num = 250;
					break;
				case 225:
					array2[19] = 83;
					num4 = 329;
					goto IL_15be;
				case 61:
					num7 = 224 - 74;
					num3 = 223;
					if (!zifGxiL8BncgdAr5Et())
					{
						goto IL_15c2;
					}
					goto case 229;
				case 202:
					Y08QQ951VTPWy2k7a7(rijndaelManaged, CipherMode.CBC);
					num3 = 182;
					goto IL_15c2;
				case 182:
					transform = (ICryptoTransform)n7G4evxSYIsmPS3etv(rijndaelManaged, array4, array6);
					num3 = 5;
					goto IL_15c2;
				case 204:
				case 285:
					num6 = 158 - 52;
					num = 237;
					break;
				case 241:
					array2[6] = (byte)num6;
					num4 = 287;
					goto IL_15be;
				case 133:
					array2[9] = (byte)num6;
					num = 194;
					break;
				case 83:
					array2[7] = 122;
					num4 = 72;
					goto IL_15be;
				case 328:
					array2[5] = 111;
					num4 = 337;
					goto IL_15be;
				case 114:
					array2[8] = (byte)num6;
					num = 74;
					break;
				case 274:
					num6 = 174 - 58;
					num3 = 213;
					goto IL_15c2;
				case 161:
					num6 = 171 - 57;
					num4 = 247;
					goto IL_15be;
				case 297:
					array3[10] = 92;
					num = 236;
					break;
				case 130:
					array3[3] = 28;
					num3 = 60;
					goto IL_15c2;
				case 280:
					num6 = 98 + 96;
					num = 114;
					break;
				case 178:
					num5 = 156 - 52;
					num4 = 317;
					goto IL_15be;
				case 134:
					array3[1] = (byte)num5;
					num = 226;
					break;
				case 152:
					array2[1] = 191;
					num = 121;
					break;
				case 277:
					array2[22] = (byte)num6;
					num4 = 15;
					goto IL_15be;
				case 125:
					num7 = 60 + 41;
					num4 = 113;
					goto IL_15be;
				case 270:
					array3[12] = 99;
					num = 89;
					break;
				case 324:
					array2[8] = 166;
					num3 = 280;
					goto IL_15c2;
				case 30:
					num8 = 165 - 55;
					num3 = 54;
					if (zifGxiL8BncgdAr5Et())
					{
						goto case 170;
					}
					goto IL_15c2;
				case 170:
					num7 = 53 + 52;
					num3 = 326;
					if (false)
					{
						goto case 67;
					}
					goto IL_15c2;
				case 67:
					hvSQR37vWl = (byte[])Vh9X5hUnc3BEsGpoGs(memoryStream);
					num3 = 190;
					if (zifGxiL8BncgdAr5Et())
					{
						goto case 178;
					}
					goto IL_15c2;
				case 235:
					array2[24] = 66;
					num4 = 120;
					goto IL_15be;
				case 294:
					num6 = 18 + 59;
					num3 = 87;
					goto IL_15c2;
				case 50:
					array2[16] = (byte)num7;
					num3 = 221;
					if (false)
					{
						goto case 28;
					}
					goto IL_15c2;
				case 28:
					num7 = 190 - 63;
					num = 112;
					break;
				case 38:
					array2 = new byte[32];
					num3 = 29;
					goto IL_15c2;
				case 155:
					num5 = 2 + 22;
					num4 = 264;
					goto IL_15be;
				case 308:
					array2[18] = 86;
					num = 18;
					break;
				case 332:
					array3[4] = 82;
					num3 = 178;
					if (true)
					{
						goto IL_15c2;
					}
					goto case 5;
				case 304:
					num6 = 126 + 60;
					num3 = 325;
					if (!F9MSdpWg9I3uOoVfNd())
					{
						goto case 276;
					}
					goto IL_15c2;
				case 10:
					array2[2] = (byte)num6;
					num = 75;
					break;
				case 69:
					array2[24] = 117;
					goto case 235;
				default:
					num3 = 235;
					if (true)
					{
						goto IL_15c2;
					}
					goto case 254;
				case 254:
					array3[15] = 143;
					num3 = 175;
					goto IL_15c2;
				case 81:
					array3[10] = (byte)num5;
					num3 = 244;
					if (true)
					{
						goto IL_15c2;
					}
					goto case 329;
				case 329:
					array2[20] = 121;
					num4 = 85;
					goto IL_15be;
				case 266:
					num6 = 89 + 83;
					num3 = 272;
					if (true)
					{
						goto IL_15c2;
					}
					goto case 145;
				case 145:
					array2[14] = (byte)num6;
					num = 271;
					break;
				case 331:
					num6 = 235 - 78;
					num3 = 300;
					goto IL_15c2;
				case 307:
					array2[8] = 140;
					num = 324;
					break;
				case 244:
					array3[10] = 95;
					num3 = 286;
					goto IL_15c2;
				case 106:
					num7 = 120 + 10;
					num = 276;
					break;
				case 21:
					array2[16] = 156;
					num = 84;
					break;
				case 65:
					array3[10] = (byte)num5;
					num4 = 155;
					goto IL_15be;
				case 76:
					num5 = 57 + 94;
					num3 = 180;
					goto IL_15c2;
				case 338:
					array2[4] = (byte)num6;
					num3 = 136;
					if (F9MSdpWg9I3uOoVfNd())
					{
						goto IL_15c2;
					}
					goto case 102;
				case 102:
					num7 = 60 + 98;
					num3 = 57;
					if (!zifGxiL8BncgdAr5Et())
					{
						goto IL_15c2;
					}
					goto case 322;
				case 322:
					array6[15] = array5[7];
					num = 48;
					break;
				case 248:
					array2[31] = 151;
					num = 211;
					break;
				case 16:
					num5 = 180 - 60;
					num3 = 23;
					if (F9MSdpWg9I3uOoVfNd())
					{
						goto IL_15c2;
					}
					goto case 264;
				case 264:
					array3[10] = (byte)num5;
					num4 = 297;
					goto IL_15be;
				case 47:
					array3[6] = (byte)num8;
					num3 = 154;
					if (!zifGxiL8BncgdAr5Et())
					{
						goto IL_15c2;
					}
					goto case 151;
				case 151:
					array3[2] = (byte)num5;
					num4 = 263;
					goto IL_15be;
				case 62:
					num8 = 67 + 92;
					num3 = 181;
					if (true)
					{
						goto IL_15c2;
					}
					goto case 288;
				case 288:
					num6 = 204 - 68;
					num4 = 177;
					goto IL_15be;
				case 96:
					array3[8] = (byte)num8;
					num3 = 262;
					if (!zifGxiL8BncgdAr5Et())
					{
						goto IL_15c2;
					}
					goto case 132;
				case 132:
					num5 = 47 + 104;
					num3 = 101;
					if (F9MSdpWg9I3uOoVfNd())
					{
						goto IL_15c2;
					}
					goto case 194;
				case 194:
					array2[10] = 57;
					num3 = 140;
					if (!zifGxiL8BncgdAr5Et())
					{
						goto IL_15c2;
					}
					goto case 224;
				case 231:
					array2[12] = (byte)num6;
					num = 28;
					break;
				case 14:
					array2[29] = (byte)num7;
					num = 25;
					break;
				case 115:
					num7 = 83 + 80;
					num4 = 265;
					goto IL_15be;
				case 211:
					num7 = 97 + 37;
					num3 = 252;
					if (true)
					{
						goto IL_15c2;
					}
					goto case 43;
				case 43:
					array3[5] = 143;
					num3 = 163;
					goto IL_15c2;
				case 287:
					array2[6] = 236;
					num3 = 97;
					goto IL_15c2;
				case 122:
					array3[2] = (byte)num5;
					num3 = 68;
					if (true)
					{
						goto IL_15c2;
					}
					goto case 175;
				case 175:
					array6 = array3;
					num3 = 339;
					if (true)
					{
						goto IL_15c2;
					}
					goto case 180;
				case 180:
					array3[12] = (byte)num5;
					num = 270;
					break;
				case 139:
					array3[15] = 168;
					num3 = 16;
					goto IL_15c2;
				case 339:
					array5 = (byte[])HejnRj7xPI3KkxgYSa(Y7K1CMpPA2g5ceSDAG(jLvhaHj8PYEuYQCjin(typeof(okiBYmytZBf443ggmg).TypeHandle).Assembly));
					num3 = 86;
					goto IL_15c2;
				case 147:
					array2[19] = 49;
					num = 289;
					break;
				case 301:
					array2[10] = 218;
					num3 = 275;
					goto IL_15c2;
				case 23:
					array3[15] = (byte)num5;
					num4 = 94;
					goto IL_15be;
				case 253:
					array2[17] = 94;
					num = 195;
					break;
				case 124:
					array2[0] = 135;
					num3 = 220;
					goto IL_15c2;
				case 31:
					ydKeAwhERI7T7aavJb(binaryReader);
					num4 = 46;
					goto IL_15be;
				case 97:
					array2[7] = 147;
					num4 = 230;
					goto IL_15be;
				case 229:
					array6[7] = array5[3];
					num4 = 12;
					goto IL_15be;
				case 44:
					array3[3] = 166;
					num3 = 130;
					if (0 == 0)
					{
						goto IL_15c2;
					}
					goto case 318;
				case 318:
					num7 = 47 + 0;
					num3 = 2;
					if (0 == 0)
					{
						goto IL_15c2;
					}
					goto case 162;
				case 162:
					num7 = 181 - 77;
					num3 = 50;
					goto IL_15c2;
				case 3:
					array2[23] = 86;
					num = 200;
					break;
				case 310:
					num6 = 151 + 84;
					num = 231;
					break;
				case 19:
					num7 = 40 + 75;
					num4 = 14;
					goto IL_15be;
				case 323:
					num7 = 107 - 41;
					num = 9;
					break;
				case 282:
					array2[12] = (byte)num6;
					num = 310;
					break;
				case 321:
					num8 = 152 - 50;
					num3 = 273;
					if (F9MSdpWg9I3uOoVfNd())
					{
						goto IL_15c2;
					}
					goto case 87;
				case 87:
					array2[27] = (byte)num6;
					num = 266;
					break;
				case 119:
					array2[19] = 167;
					num3 = 147;
					if (F9MSdpWg9I3uOoVfNd())
					{
						goto IL_15c2;
					}
					goto case 145;
				case 262:
					num8 = 103 + 106;
					num = 251;
					break;
				case 302:
					array2[15] = 189;
					num = 316;
					break;
				case 72:
					array2[8] = 138;
					num4 = 307;
					goto IL_15be;
				case 275:
					array2[11] = 57;
					num3 = 61;
					if (F9MSdpWg9I3uOoVfNd())
					{
						goto IL_15c2;
					}
					goto case 65;
				case 189:
					array3[14] = (byte)num5;
					num4 = 59;
					goto IL_15be;
				case 41:
					array3[5] = 193;
					num4 = 206;
					goto IL_15be;
				case 37:
					array2[11] = 122;
					num3 = 0;
					if (true)
					{
						goto IL_15c2;
					}
					goto case 103;
				case 103:
					num6 = 85 + 1;
					num4 = 278;
					goto IL_15be;
				case 92:
					array2[3] = 166;
					num3 = 160;
					if (0 == 0)
					{
						goto IL_15c2;
					}
					goto case 71;
				case 71:
					array2[10] = (byte)num6;
					num = 203;
					break;
				case 160:
					array2[3] = 75;
					num = 104;
					break;
				case 179:
					rscJjK2RggdLFoPEgi(true);
					num3 = 184;
					goto IL_15c2;
				case 279:
					array3[15] = 98;
					num4 = 139;
					goto IL_15be;
				case 80:
					array2[12] = 105;
					num3 = 288;
					if (true)
					{
						goto IL_15c2;
					}
					goto case 166;
				case 166:
					array2[2] = (byte)num6;
					num = 88;
					break;
				case 66:
					num6 = 84 + 50;
					num = 167;
					break;
				case 335:
					num6 = 68 + 86;
					num4 = 39;
					goto IL_15be;
				case 174:
					array3[3] = (byte)num5;
					num = 44;
					break;
				case 84:
					array2[16] = 64;
					num = 162;
					break;
				case 245:
					array2[10] = 161;
					num4 = 301;
					goto IL_15be;
				case 42:
					array2[15] = 137;
					num4 = 302;
					goto IL_15be;
				case 32:
					array2[17] = 122;
					num3 = 111;
					if (!F9MSdpWg9I3uOoVfNd())
					{
						goto case 155;
					}
					goto IL_15c2;
				case 309:
					array2[29] = 89;
					num = 320;
					break;
				case 269:
					array2[13] = (byte)num7;
					num = 7;
					break;
				case 154:
					num5 = 223 - 74;
					num3 = 183;
					if (F9MSdpWg9I3uOoVfNd())
					{
						goto IL_15c2;
					}
					goto case 327;
				case 327:
					array2[21] = (byte)num7;
					num4 = 267;
					goto IL_15be;
				case 171:
					num7 = 23 + 59;
					num3 = 255;
					if (true)
					{
						goto IL_15c2;
					}
					goto case 111;
				case 111:
					array2[17] = 113;
					num3 = 103;
					if (true)
					{
						goto IL_15c2;
					}
					goto case 292;
				case 292:
					array2[28] = 163;
					num4 = 208;
					goto IL_15be;
				case 311:
					array3[1] = (byte)num8;
					num3 = 4;
					if (true)
					{
						goto IL_15c2;
					}
					goto case 273;
				case 273:
					array3[8] = (byte)num8;
					num3 = 214;
					if (F9MSdpWg9I3uOoVfNd())
					{
						goto IL_15c2;
					}
					goto case 119;
				case 223:
					array2[11] = (byte)num7;
					num3 = 37;
					if (!F9MSdpWg9I3uOoVfNd())
					{
						goto case 277;
					}
					goto IL_15c2;
				case 110:
					array2[29] = (byte)num7;
					num3 = 187;
					if (!zifGxiL8BncgdAr5Et())
					{
						goto IL_15c2;
					}
					goto case 208;
				case 208:
					array2[28] = 86;
					num = 98;
					break;
				case 186:
					array2[30] = 151;
					num = 168;
					break;
				case 142:
					array2[17] = (byte)num6;
					num = 32;
					break;
				case 293:
					array2[15] = (byte)num7;
					num = 42;
					break;
				case 117:
					array2[2] = 62;
					num3 = 146;
					goto IL_15c2;
				case 345:
					array2[28] = 120;
					num = 292;
					break;
				case 149:
					FCKetEJTk4N7AmOlyx(cryptoStream);
					num4 = 31;
					goto IL_15be;
				case 33:
					array3[0] = 251;
					num3 = 55;
					goto IL_15c2;
				case 296:
					array2[5] = 46;
					num4 = 328;
					goto IL_15be;
				case 237:
					array2[30] = (byte)num6;
					num = 258;
					break;
				case 191:
					num6 = 205 - 68;
					num4 = 277;
					goto IL_15be;
				case 168:
					array2[30] = 123;
					zifGxiL8BncgdAr5Et();
					if (!F9MSdpWg9I3uOoVfNd())
					{
						num3 = 210;
						if (1 == 0)
						{
							goto case 219;
						}
					}
					else
					{
						num3 = 285;
						if (false)
						{
							goto case 13;
						}
					}
					goto IL_15c2;
				case 13:
					array2[2] = (byte)num7;
					num3 = 291;
					if (F9MSdpWg9I3uOoVfNd())
					{
						goto IL_15c2;
					}
					goto case 63;
				case 63:
					num6 = 126 - 42;
					num3 = 282;
					goto IL_15c2;
				case 195:
					num6 = 120 + 66;
					num4 = 142;
					goto IL_15be;
				case 192:
					array3[12] = 130;
					num3 = 128;
					if (true)
					{
						goto IL_15c2;
					}
					goto case 157;
				case 157:
					NVDNCE8JfsNvR82CYI(cryptoStream, array, 0, array.Length);
					num3 = 193;
					if (0 == 0)
					{
						goto IL_15c2;
					}
					goto case 153;
				case 153:
					array2[23] = (byte)num7;
					num4 = 261;
					goto IL_15be;
				case 330:
					array2[13] = (byte)num7;
					num = 170;
					break;
				case 239:
					array2[1] = 164;
					num3 = 281;
					if (!F9MSdpWg9I3uOoVfNd())
					{
						goto case 241;
					}
					goto IL_15c2;
				case 257:
					array3[8] = 121;
					num4 = 321;
					goto IL_15be;
				case 319:
					array2[7] = (byte)num7;
					num3 = 156;
					goto IL_15c2;
				case 185:
					array3[14] = 142;
					num3 = 78;
					if (!zifGxiL8BncgdAr5Et())
					{
						goto IL_15c2;
					}
					goto case 218;
				case 218:
					array3[9] = 119;
					num3 = 341;
					if (!zifGxiL8BncgdAr5Et())
					{
						goto IL_15c2;
					}
					goto case 340;
				case 340:
					array2[18] = (byte)num6;
					num = 119;
					break;
				case 286:
					array3[10] = 76;
					num3 = 127;
					goto IL_15c2;
				case 238:
					array3[5] = 144;
					num = 43;
					break;
				case 224:
					array6[13] = array5[6];
					num3 = 322;
					if (true)
					{
						goto IL_15c2;
					}
					goto case 55;
				case 55:
					num8 = 115 + 76;
					num3 = 311;
					if (true)
					{
						goto IL_15c2;
					}
					goto case 300;
				case 300:
					array2[24] = (byte)num6;
					num = 107;
					break;
				case 199:
					array3[9] = (byte)num8;
					num3 = 218;
					goto IL_15c2;
				case 181:
					array3[13] = (byte)num8;
					num3 = 290;
					goto IL_15c2;
				case 95:
					array2[16] = 143;
					num3 = 21;
					if (0 == 0)
					{
						goto IL_15c2;
					}
					goto case 268;
				case 268:
					num7 = 63 + 68;
					num3 = 319;
					if (!zifGxiL8BncgdAr5Et())
					{
						goto IL_15c2;
					}
					goto case 126;
				case 126:
					array2[15] = (byte)num7;
					num4 = 95;
					goto IL_15be;
				case 64:
					array3[7] = 154;
					num = 222;
					break;
				case 187:
					array2[29] = 228;
					num = 312;
					break;
				case 201:
					num6 = 94 + 82;
					num3 = 241;
					if (F9MSdpWg9I3uOoVfNd())
					{
						goto IL_15c2;
					}
					goto case 284;
				case 284:
					array3[0] = (byte)num8;
					num4 = 188;
					goto IL_15be;
				case 116:
					num5 = 52 + 124;
					num3 = 249;
					if (!F9MSdpWg9I3uOoVfNd())
					{
						goto case 101;
					}
					goto IL_15c2;
				case 140:
					array2[10] = 231;
					num = 99;
					break;
				case 46:
					num2 = HrtfyIMZlU7aIDtZSG(hvSQR37vWl, P_0);
					num3 = 346;
					if (true)
					{
						goto IL_15c2;
					}
					goto case 2;
				case 2:
					array2[22] = (byte)num7;
					num3 = 11;
					goto IL_15c2;
				case 6:
					array2[6] = 94;
					num4 = 342;
					goto IL_15be;
				case 198:
					array2[14] = (byte)num7;
					num = 298;
					break;
				case 167:
					array2[22] = (byte)num6;
					num = 191;
					break;
				case 188:
					num8 = 1 + 47;
					num4 = 306;
					goto IL_15be;
				case 173:
					array4 = array2;
					num3 = 34;
					goto IL_15c2;
				case 233:
					num8 = 62 + 7;
					num3 = 58;
					if (true)
					{
						goto IL_15c2;
					}
					goto case 70;
				case 70:
					array2[4] = (byte)num6;
					num = 118;
					break;
				case 344:
					num8 = 196 - 65;
					num3 = 284;
					if (F9MSdpWg9I3uOoVfNd())
					{
						goto IL_15c2;
					}
					goto case 300;
				case 58:
					array3[13] = (byte)num8;
					num = 62;
					break;
				case 17:
					array2[11] = 1;
					num3 = 80;
					if (!zifGxiL8BncgdAr5Et())
					{
						goto IL_15c2;
					}
					goto case 312;
				case 312:
					array2[29] = 157;
					num3 = 309;
					goto IL_15c2;
				case 108:
					num7 = 84 - 11;
					num = 330;
					break;
				case 267:
					array2[21] = 192;
					num = 335;
					break;
				case 77:
					num7 = 45 + 53;
					num3 = 293;
					if (F9MSdpWg9I3uOoVfNd())
					{
						goto IL_15c2;
					}
					goto case 23;
				case 252:
					array2[31] = (byte)num7;
					num = 173;
					break;
				case 184:
					array = (byte[])A893iVEgB3fbDTQgyV(binaryReader, (int)GREuoq0XjcDBUh1qGQ(notKm6rpFajRKALdV3(binaryReader)));
					num4 = 38;
					goto IL_15be;
				case 156:
					num6 = 112 + 26;
					num3 = 137;
					if (true)
					{
						goto IL_15c2;
					}
					goto case 216;
				case 216:
					num6 = 248 - 82;
					num3 = 70;
					goto IL_15c2;
				case 18:
					num6 = 113 + 59;
					num = 340;
					break;
				case 60:
					num5 = 165 - 118;
					num4 = 138;
					goto IL_15be;
				case 127:
					num5 = 70 + 71;
					num4 = 158;
					goto IL_15be;
				case 346:
					try
					{
						return (string)zRcQXZs2Z3GvJTf2Z5(Jjd7ohugWU7LBQlmXn(), hvSQR37vWl, P_0 + 4, num2);
					}
					catch
					{
					}
					return "";
				case 5:
					memoryStream = new MemoryStream();
					num3 = 150;
					if (!zifGxiL8BncgdAr5Et())
					{
						goto IL_15c2;
					}
					goto case 264;
				case 48:
					{
						rijndaelManaged = new RijndaelManaged();
						num3 = 202;
						if (!F9MSdpWg9I3uOoVfNd())
						{
							goto case 91;
						}
						goto IL_15c2;
					}
					IL_15be:
					num3 = num4;
					goto IL_15c2;
					IL_15c2:
					num = num3;
					break;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[frRhTV3aDevHFxRZMw(typeof(okiBYmytZBf443ggmg/frRhTV3aDevHFxRZMw/lHZvjbLOOFBM6J13BB<object>[]))]
		internal static string VVAQUbqjpo(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void EybQtOghU1(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int FZsQkYd46A(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr vIJQvuguC9(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void FGMQmjEdEM()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void tCpQXya5nL()
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
		internal static object rPlQaHPqWO(object P_0)
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
		public static extern IntPtr DyqQHwuQD3(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr uyhQytuTwJ(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int joSQg7bTx7(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int shcQ3Uvjtx(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int NiHQLlIhCd(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr GYgQfEON1A(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int BlVQsHD2SE(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[frRhTV3aDevHFxRZMw(typeof(okiBYmytZBf443ggmg/frRhTV3aDevHFxRZMw/lHZvjbLOOFBM6J13BB<object>[]))]
		private static byte[] PrLQhHWqrW(string P_0)
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
		[frRhTV3aDevHFxRZMw(typeof(okiBYmytZBf443ggmg/frRhTV3aDevHFxRZMw/lHZvjbLOOFBM6J13BB<object>[]))]
		private static byte[] pmjQGuIiZa(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				88, 9, 150, 9, 138, 15, 197, 30, 80, 39,
				69, 253, 19, 87, 49, 136, 24, 13, 243, 82,
				167, 144, 16, 174, 251, 168, 53, 65, 69, 249,
				164, 98
			};
			rijndael.IV = new byte[16]
			{
				95, 125, 46, 164, 119, 197, 248, 100, 219, 116,
				235, 154, 100, 43, 8, 98
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] NDkQwohryS()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] AUiQoPwCwp()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] DcfQCIm4HM()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] jIWQElBZrT()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] zNfQD70MiI()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] PZ2QBVww5G()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] s3KQj8g59c()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] LHlQ7Nc26B()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] HXhQVCu7BJ()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] XbtQAT7Cdk()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public okiBYmytZBf443ggmg()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type jLvhaHj8PYEuYQCjin(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object AR4fukR0t5ivAKRy2A(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object notKm6rpFajRKALdV3(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void zMHv4SlQi7TOrESf7U(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void rscJjK2RggdLFoPEgi(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long GREuoq0XjcDBUh1qGQ(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object A893iVEgB3fbDTQgyV(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Y7K1CMpPA2g5ceSDAG(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object HejnRj7xPI3KkxgYSa(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Y08QQ951VTPWy2k7a7(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object n7G4evxSYIsmPS3etv(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void NVDNCE8JfsNvR82CYI(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void kWxWoSmf27YQWThqkj(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Vh9X5hUnc3BEsGpoGs(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void FCKetEJTk4N7AmOlyx(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void ydKeAwhERI7T7aavJb(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int HrtfyIMZlU7aIDtZSG(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Jjd7ohugWU7LBQlmXn()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object zRcQXZs2Z3GvJTf2Z5(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool F9MSdpWg9I3uOoVfNd()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool zifGxiL8BncgdAr5Et()
		{
			return false;
		}
	}
}
namespace ShAw8OCiYmjRblCUqg
{
	internal class F1TW9EoVrvRILSscdn
	{
		private static bool IyRSSdV89i;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void D9BoUTjzdJlSt()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public F1TW9EoVrvRILSscdn()
		{
		}
	}
}
