using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.ConstrainedExecution;
using System.Runtime.InteropServices;
using System.Runtime.Serialization.Formatters.Binary;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using System.Xml;
using Cummins.INSITE.Kernel.ECMServicesAPI;
using eIOTCwgtN7fvJXNYMS;
using eoP53YVgQa1lbB0Xy6;

[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyTitle("Cummins.INSITE.Kernel.ECMServicesCommonTypes")]
[assembly: Guid("0aa9fcd3-be2f-4d83-98fe-3d481d0cc818")]
[assembly: AssemblyProduct("Cummins.INSITE.Kernel.ECMServicesCommonTypes")]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyDelaySign(false)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: InternalsVisibleTo("ECMServicesCommonTypesUnitTest")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyDescription("")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: ComVisible(true)]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyVersion("7.6.0.272")]
internal static class JGqnVyUC9BvSVWMRgE
{
}
namespace Cummins.INSITE.Kernel.ECMServicesCommonTypes
{
	public enum Protocol
	{
		Image,
		ICL,
		CC,
		PJ1939,
		UDS,
		PCL
	}
	public class ECMServicesConfiguration
	{
		private static ECMServicesConfiguration P6HVLhvmP;

		private XmlDocument SQBBrt9nR;

		public static ECMServicesConfiguration Configuration
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return P6HVLhvmP;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private ECMServicesConfiguration()
		{
			//IL_0013: Unknown result type (might be due to invalid IL or missing references)
			//IL_001d: Expected O, but got Unknown
			eGujxxQN0KjsXHehk2.DrWxTdOztANlU();
			base..ctor();
			SQBBrt9nR = new XmlDocument();
			SQBBrt9nR.Load(Path.Combine(Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location), emYpxP33xAq8jO8oJ1.eopWKtZX1(0)));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public string GetConfigurationValue(string key)
		{
			string result = string.Empty;
			XmlNode val = ((XmlNode)SQBBrt9nR.DocumentElement).SelectSingleNode(emYpxP33xAq8jO8oJ1.eopWKtZX1(60) + key);
			if (val != null)
			{
				result = val.InnerText;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public T GetConfigurationValue<T>(string key, T defaultValue = default(T))
		{
			T result = defaultValue;
			XmlNode val = ((XmlNode)SQBBrt9nR.DocumentElement).SelectSingleNode(emYpxP33xAq8jO8oJ1.eopWKtZX1(68) + key);
			if (val != null)
			{
				string innerText = val.InnerText;
				result = (T)Convert.ChangeType(innerText, typeof(T));
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static ECMServicesConfiguration()
		{
			eGujxxQN0KjsXHehk2.DrWxTdOztANlU();
			P6HVLhvmP = new ECMServicesConfiguration();
		}
	}
	public interface ISystemProperties : ICollection<IECUProperties>, IList<IECUProperties>, IEnumerable, IEnumerable<IECUProperties>
	{
		int ConnectionId { get; }
	}
	public class SystemProperties : List<IECUProperties>, IList<IECUProperties>, ISystemProperties, ICollection<IECUProperties>, IEnumerable, IEnumerable<IECUProperties>
	{
		private int KVn9OL6jb;

		public int ConnectionId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return KVn9OL6jb;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public SystemProperties(int connectionId)
		{
			eGujxxQN0KjsXHehk2.DrWxTdOztANlU();
			base..ctor();
			KVn9OL6jb = connectionId;
		}
	}
	public abstract class DisposableObject : CriticalFinalizerObject, IDisposable
	{
		private object X4cjgMAym;

		private bool Mkpup2W2X;

		protected bool Disposed
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				lock (X4cjgMAym)
				{
					return Mkpup2W2X;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected DisposableObject()
		{
			eGujxxQN0KjsXHehk2.DrWxTdOztANlU();
			base..ctor();
			X4cjgMAym = new object();
			Mkpup2W2X = false;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void CleanUp()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		~DisposableObject()
		{
			lock (X4cjgMAym)
			{
				try
				{
					if (!Mkpup2W2X)
					{
						CleanUp();
						Mkpup2W2X = true;
					}
				}
				catch
				{
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Dispose()
		{
			lock (X4cjgMAym)
			{
				try
				{
					if (!Mkpup2W2X)
					{
						CleanUp();
						Mkpup2W2X = true;
						GC.SuppressFinalize(this);
					}
				}
				catch
				{
				}
			}
		}
	}
	public interface IECUProperties
	{
		string ProductId { get; set; }

		double ECMVersion { get; set; }

		string ECUId { get; set; }

		int SourceAddress { get; set; }

		RunLocation RunLocation { get; set; }

		int DetectType { get; set; }

		GTISLevel GTISLevel { get; set; }

		ECUHierarchy HierarchyState { get; set; }

		int HarnessKeyECMInstance { get; set; }

		int HarnessKeyStatus { get; set; }

		string ECMPhase { get; set; }

		bool Consumed { get; set; }
	}
	public interface IParameterValues : ICollection<IParameterValue>, IList<IParameterValue>, IEnumerable, IEnumerable<IParameterValue>
	{
	}
	public class ParameterValues : List<IParameterValue>, IList<IParameterValue>, IParameterValues, ICollection<IParameterValue>, IEnumerable, IEnumerable<IParameterValue>
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public ParameterValues()
		{
			eGujxxQN0KjsXHehk2.DrWxTdOztANlU();
			base..ctor();
		}
	}
	public enum AccessType
	{
		Read,
		Write,
		All
	}
	public enum RuleType
	{
		True,
		False,
		Lower,
		Upper
	}
	public enum BlockType
	{
		NotBlocking,
		Blocking,
		Undetermined
	}
	public enum ValueConversionfactor
	{
		ForRead,
		ForWrite
	}
	public class Tracer
	{
		private static Tracer UZsMnByVS;

		private static string id2TH4QGv;

		private int vE0WF57Kj;

		public static Tracer ExecutionTracer
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return UZsMnByVS;
			}
		}

		public static string TraceFileName
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return id2TH4QGv;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				id2TH4QGv = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private Tracer()
		{
			eGujxxQN0KjsXHehk2.DrWxTdOztANlU();
			base..ctor();
			Trace.AutoFlush = true;
			Trace.IndentSize = 3;
			vE0WF57Kj = ECMServicesConfiguration.Configuration.GetConfigurationValue(emYpxP33xAq8jO8oJ1.eopWKtZX1(76), 1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[Conditional("TRACING_ON")]
		public void LogMethodEntry(params object[] inArgs)
		{
			try
			{
				StackFrame frame = new StackTrace(fNeedFileInfo: true).GetFrame(1);
				MethodBase method = frame.GetMethod();
				string value = string.Format(emYpxP33xAq8jO8oJ1.eopWKtZX1(118), frame.GetFileName(), frame.GetFileLineNumber().ToString(), "", method.DeclaringType.ToString(), method.Name);
				StringBuilder stringBuilder = new StringBuilder(emYpxP33xAq8jO8oJ1.eopWKtZX1(188));
				stringBuilder.Append(value);
				stringBuilder.Append(emYpxP33xAq8jO8oJ1.eopWKtZX1(214));
				if (vE0WF57Kj >= 2)
				{
					int num = method.GetParameters().Length;
					int num2 = 0;
					ParameterInfo[] parameters = method.GetParameters();
					foreach (ParameterInfo parameterInfo in parameters)
					{
						if (!parameterInfo.IsOut)
						{
							stringBuilder.Append(parameterInfo.ParameterType.ToString());
							stringBuilder.Append(emYpxP33xAq8jO8oJ1.eopWKtZX1(220));
							stringBuilder.Append(parameterInfo.Name);
							stringBuilder.Append(emYpxP33xAq8jO8oJ1.eopWKtZX1(226));
							try
							{
								stringBuilder.Append(inArgs[parameterInfo.Position]);
							}
							catch
							{
								stringBuilder.Append(emYpxP33xAq8jO8oJ1.eopWKtZX1(236));
							}
							if (num2 < num - 1)
							{
								stringBuilder.Append(emYpxP33xAq8jO8oJ1.eopWKtZX1(256));
							}
						}
						num2++;
					}
				}
				stringBuilder.Append(emYpxP33xAq8jO8oJ1.eopWKtZX1(264));
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[Conditional("TRACING_ON")]
		public void LogMethodExit(params object[] outArgs)
		{
			try
			{
				StackFrame frame = new StackTrace(fNeedFileInfo: true).GetFrame(1);
				MethodBase method = frame.GetMethod();
				string value = string.Format(emYpxP33xAq8jO8oJ1.eopWKtZX1(270), frame.GetFileName(), frame.GetFileLineNumber().ToString(), "", method.DeclaringType.ToString(), method.Name);
				StringBuilder stringBuilder = new StringBuilder(emYpxP33xAq8jO8oJ1.eopWKtZX1(340));
				stringBuilder.Append(value);
				stringBuilder.Append(emYpxP33xAq8jO8oJ1.eopWKtZX1(364));
				int num = method.GetParameters().Length;
				int num2 = 0;
				ParameterInfo[] parameters = method.GetParameters();
				foreach (ParameterInfo parameterInfo in parameters)
				{
					if (parameterInfo.IsOut | parameterInfo.IsRetval)
					{
						stringBuilder.Append(parameterInfo.ParameterType.ToString());
						stringBuilder.Append(emYpxP33xAq8jO8oJ1.eopWKtZX1(370));
						stringBuilder.Append(parameterInfo.Name);
						stringBuilder.Append(emYpxP33xAq8jO8oJ1.eopWKtZX1(376));
						try
						{
							stringBuilder.Append(outArgs[parameterInfo.Position]);
						}
						catch
						{
							stringBuilder.Append(emYpxP33xAq8jO8oJ1.eopWKtZX1(386));
						}
						if (num2 < num - 1)
						{
							stringBuilder.Append(emYpxP33xAq8jO8oJ1.eopWKtZX1(406));
						}
					}
					num2++;
				}
				stringBuilder.Append(emYpxP33xAq8jO8oJ1.eopWKtZX1(414));
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[Conditional("TRACING_ON")]
		public void LogException(Exception ex)
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[Conditional("TRACING_ON")]
		public void LogString(string message)
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static Tracer()
		{
			eGujxxQN0KjsXHehk2.DrWxTdOztANlU();
			UZsMnByVS = new Tracer();
		}
	}
	public interface IParameterValue
	{
		ParameterValueType ValueType { get; }

		int Index { get; }

		int ChildCount { get; }

		IEnumerable<IParameterValue> Child { get; }

		ECMServicesErrorCodes ReadStatus { get; }

		ECMServicesErrorCodes WriteStatus { get; }

		T ParameterAs<T>();

		T ValueAs<T>();

		IEnumerable<T> ValueAsCollection<T>();

		IParameterValue CreateClone();
	}
	[Serializable]
	public class ParameterValue : IParameterValue
	{
		private static readonly string[] GY1h1n18F;

		private object mKVG10a23;

		private ParameterValueType Hi21KULNo;

		private object cYpiqt8dJ;

		private int dgaPZ1ojt;

		private List<IParameterValue> csP3cYME9;

		private ECMServicesErrorCodes IDGsi3dwN;

		private ECMServicesErrorCodes zgby5mR2O;

		public ParameterValueType ValueType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return Hi21KULNo;
			}
		}

		public int Index
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return dgaPZ1ojt;
			}
		}

		public int ChildCount
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return csP3cYME9.Count;
			}
		}

		public IEnumerable<IParameterValue> Child
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return csP3cYME9.AsReadOnly();
			}
		}

		public ECMServicesErrorCodes ReadStatus
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return IDGsi3dwN;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				IDGsi3dwN = value;
			}
		}

		public ECMServicesErrorCodes WriteStatus
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return zgby5mR2O;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				zgby5mR2O = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static bool AreEqual(IParameterValue lhs, IParameterValue rhs)
		{
			bool result = false;
			if (lhs == null && rhs == null)
			{
				result = true;
			}
			if (lhs != null && rhs != null)
			{
				if (lhs.ParameterAs<string>() == rhs.ParameterAs<string>() && lhs.ValueType == rhs.ValueType && lhs.ValueAs<string>() == rhs.ValueAs<string>())
				{
					result = true;
				}
			}
			else
			{
				result = false;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ParameterValue(object parameter, ParameterValueType valueType, object value, ECMServicesErrorCodes readStatus, ECMServicesErrorCodes writeStatus)
		{
			eGujxxQN0KjsXHehk2.DrWxTdOztANlU();
			base..ctor();
			mKVG10a23 = parameter;
			Hi21KULNo = valueType;
			cYpiqt8dJ = value;
			dgaPZ1ojt = 0;
			csP3cYME9 = new List<IParameterValue>();
			IDGsi3dwN = readStatus;
			zgby5mR2O = writeStatus;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ParameterValue(object parameter, ParameterValueType valueType, object value, ECMServicesErrorCodes readStatus)
		{
			eGujxxQN0KjsXHehk2.DrWxTdOztANlU();
			this..ctor(parameter, valueType, value, readStatus, ECMServicesErrorCodes.NoError);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ParameterValue(object parameter, ParameterValueType valueType, object value)
		{
			eGujxxQN0KjsXHehk2.DrWxTdOztANlU();
			this..ctor(parameter, valueType, value, ECMServicesErrorCodes.NoError, ECMServicesErrorCodes.NoError);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public override string ToString()
		{
			if (cYpiqt8dJ == null)
			{
				return string.Empty;
			}
			return cYpiqt8dJ.ToString();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetParameter(object paramValue)
		{
			mKVG10a23 = paramValue;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void SetValue(object value)
		{
			cYpiqt8dJ = value;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void AddChild(IParameterValue paramValue)
		{
			csP3cYME9.Add(paramValue);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public T ParameterAs<T>()
		{
			if (typeof(T) == typeof(int) || typeof(T) == typeof(string))
			{
				return (T)Convert.ChangeType(mKVG10a23, typeof(T));
			}
			throw new ArgumentException(emYpxP33xAq8jO8oJ1.eopWKtZX1(420), emYpxP33xAq8jO8oJ1.eopWKtZX1(504));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public T ValueAs<T>()
		{
			if (cYpiqt8dJ is IEnumerable<object> && typeof(T) == typeof(string))
			{
				IEnumerable<string> enumerable = ValueAsCollection<string>();
				StringBuilder stringBuilder = new StringBuilder();
				foreach (string item in enumerable)
				{
					stringBuilder.Append(item);
					stringBuilder.Append(emYpxP33xAq8jO8oJ1.eopWKtZX1(510));
				}
				return (T)(object)stringBuilder.ToString();
			}
			return (T)Convert.ChangeType(cYpiqt8dJ, typeof(T));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IEnumerable<T> ValueAsCollection<T>()
		{
			List<object> list = null;
			if (cYpiqt8dJ is string)
			{
				string text = cYpiqt8dJ as string;
				list = ((!string.IsNullOrEmpty(text)) ? new List<string>(text.Split(GY1h1n18F, StringSplitOptions.RemoveEmptyEntries)).ConvertAll((Converter<string, object>)([MethodImpl(MethodImplOptions.NoInlining)] (string P_0) => P_0)) : new List<object>());
			}
			else
			{
				list = new List<object>(cYpiqt8dJ as IEnumerable<object>);
			}
			return list.ConvertAll([MethodImpl(MethodImplOptions.NoInlining)] (object P_0) => (T)Convert.ChangeType(P_0, typeof(T)));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IParameterValue CreateClone()
		{
			using MemoryStream memoryStream = new MemoryStream();
			BinaryFormatter binaryFormatter = new BinaryFormatter();
			binaryFormatter.Serialize(memoryStream, this);
			memoryStream.Position = 0L;
			return (IParameterValue)binaryFormatter.Deserialize(memoryStream);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CompilerGenerated]
		private static object gk9S6sTW3<T>(string P_0)
		{
			return P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[CompilerGenerated]
		private static T RsnIegKca<T>(object P_0)
		{
			return (T)Convert.ChangeType(P_0, typeof(T));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static ParameterValue()
		{
			eGujxxQN0KjsXHehk2.DrWxTdOztANlU();
			GY1h1n18F = new string[1] { emYpxP33xAq8jO8oJ1.eopWKtZX1(516) };
		}
	}
	public static class Constants
	{
		public const int UnitFamilyHHMMSS = 30;

		public const int UnitFamilyHHHHHHMM = 167;

		public const int EnumerationNotAvailable = 1001;

		public const int EnumerationNotSet = 1002;

		public const int RawValueNotAvailable = 0;

		public const int UnitFamilyMMSS = 27;

		public const int UnitFamilyHHMM = 26;
	}
	public static class Base64
	{
		private static char JQn285s4e;

		private static List<char> hbeKvgiUu;

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string Encode(byte[] rawString, int dataSize)
		{
			string empty = string.Empty;
			int num = dataSize / 3 * 4 + ((dataSize % 3 != 0) ? 4 : 0);
			ushort[] array = new ushort[num];
			int num2 = 0;
			int num3 = 0;
			while (num2 + 2 < dataSize)
			{
				array[num3] = hbeKvgiUu[(rawString[num2] >> 2) & 0x3F];
				array[num3 + 1] = hbeKvgiUu[((rawString[num2] << 4) | ((rawString[num2 + 1] >> 4) & 0xF)) & 0x3F];
				array[num3 + 2] = hbeKvgiUu[((rawString[num2 + 1] << 2) | ((rawString[num2 + 2] >> 6) & 3)) & 0x3F];
				array[num3 + 3] = hbeKvgiUu[rawString[num2 + 2] & 0x3F];
				num2 += 3;
				num3 += 4;
			}
			if (dataSize % 3 == 1)
			{
				array[num3] = hbeKvgiUu[(rawString[num2] >> 2) & 0x3F];
				array[num3 + 1] = hbeKvgiUu[(rawString[num2] << 4) & 0x3F];
				array[num3 + 2] = JQn285s4e;
				array[num3 + 3] = JQn285s4e;
			}
			if (dataSize % 3 == 2)
			{
				array[num3] = hbeKvgiUu[(rawString[num2] >> 2) & 0x3F];
				array[num3 + 1] = hbeKvgiUu[((rawString[num2] << 4) | ((rawString[num2 + 1] >> 4) & 0xF)) & 0x3F];
				array[num3 + 2] = hbeKvgiUu[(rawString[num2] << 2) & 0x3F];
				array[num3 + 3] = JQn285s4e;
			}
			byte[] array2 = new byte[array.Length * 2];
			Buffer.BlockCopy(array, 0, array2, 0, array2.Length);
			return Encoding.Unicode.GetString(array2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string Decode(string encodedString)
		{
			CultureInfo cultureInfo = CultureInfo.GetCultureInfo(1033);
			int aNSICodePage = cultureInfo.TextInfo.ANSICodePage;
			string text = string.Empty;
			long num = encodedString.Length / 4 * 3;
			long num2 = encodedString.Length;
			Convert.ToInt32(hbeKvgiUu[0]);
			if (!(num2 % 4).Equals(0L))
			{
				num = -1L;
				return text;
			}
			long num3 = num2 / 4 * 3;
			num3 = ((num < num3) ? num : num3);
			for (int i = 0; i + 3 < num2; i += 4)
			{
				byte[] array = new byte[1];
				char[] array2 = new char[4]
				{
					Convert.ToChar(hbeKvgiUu.IndexOf(encodedString[i])),
					Convert.ToChar(hbeKvgiUu.IndexOf(encodedString[i + 1])),
					Convert.ToChar(hbeKvgiUu.IndexOf(encodedString[i + 2])),
					Convert.ToChar(hbeKvgiUu.IndexOf(encodedString[i + 3]))
				};
				array[0] = Convert.ToByte((int)((uint)array2[0] << 2) | ((int)array2[1] >> 4));
				text += Encoding.GetEncoding(aNSICodePage).GetString(array);
				if (array2[2] == '@')
				{
					break;
				}
				array[0] = Convert.ToByte(((array2[1] & 0xF) << 4) | ((int)array2[2] >> 2));
				text += Encoding.GetEncoding(aNSICodePage).GetString(array);
				if (array2[3] == '@')
				{
					break;
				}
				array[0] = Convert.ToByte(((array2[2] & 3) << 6) | array2[3]);
				text += Encoding.GetEncoding(aNSICodePage).GetString(array);
			}
			return text;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static Base64()
		{
			eGujxxQN0KjsXHehk2.DrWxTdOztANlU();
			JQn285s4e = '=';
			hbeKvgiUu = new List<char>
			{
				'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
				'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
				'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
				'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
				'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
				'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7',
				'8', '9', '+', '/', '='
			};
		}
	}
	public class ECUProperties : IECUProperties
	{
		private int mXTaSEKND;

		private string GppNV9HV9;

		private string ER0o6FpGv;

		private double yAqgP7W5j;

		private RunLocation e22xAPnnd;

		private int FEubu6Ak2;

		private GTISLevel fxLJkoCTS;

		private ECUHierarchy d36Ej5Ura;

		private int XnFFMInUS;

		private int zOBqvj0Gw;

		[CompilerGenerated]
		private string KE56QtbjL;

		[CompilerGenerated]
		private bool e3u0ixj6f;

		public bool Consumed
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return e3u0ixj6f;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				e3u0ixj6f = value;
			}
		}

		public string ProductId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ER0o6FpGv;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				ER0o6FpGv = value;
			}
		}

		public double ECMVersion
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return yAqgP7W5j;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				yAqgP7W5j = value;
			}
		}

		public int SourceAddress
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return mXTaSEKND;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				mXTaSEKND = value;
			}
		}

		public RunLocation RunLocation
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return e22xAPnnd;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				e22xAPnnd = value;
			}
		}

		public int DetectType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return FEubu6Ak2;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				FEubu6Ak2 = value;
			}
		}

		public GTISLevel GTISLevel
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return fxLJkoCTS;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				fxLJkoCTS = value;
			}
		}

		public ECUHierarchy HierarchyState
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return d36Ej5Ura;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				d36Ej5Ura = value;
			}
		}

		public string ECUId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return GppNV9HV9;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				GppNV9HV9 = value;
			}
		}

		public int HarnessKeyStatus
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return XnFFMInUS;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				XnFFMInUS = value;
			}
		}

		public int HarnessKeyECMInstance
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return zOBqvj0Gw;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				zOBqvj0Gw = value;
			}
		}

		public string ECMPhase
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return iwxmQTahi();
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				xL3DU7gsF(value);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		[CompilerGenerated]
		private string iwxmQTahi()
		{
			return KE56QtbjL;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		[CompilerGenerated]
		private void xL3DU7gsF(string value)
		{
			KE56QtbjL = value;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ECUProperties()
		{
			eGujxxQN0KjsXHehk2.DrWxTdOztANlU();
			base..ctor();
		}
	}
	public class DependencyDefinition : IDependencyDefinition
	{
		[CompilerGenerated]
		private int y6M7n2J1F;

		[CompilerGenerated]
		private int hZP5R4lfw;

		[CompilerGenerated]
		private int SRjLSRUMV;

		[CompilerGenerated]
		private int MHklxJ0qT;

		[CompilerGenerated]
		private int Ry6YvNCk2;

		[CompilerGenerated]
		private int auT8Rh1SP;

		public int AccessType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return y6M7n2J1F;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				y6M7n2J1F = value;
			}
		}

		public int DependencyParameterID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return hZP5R4lfw;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				hZP5R4lfw = value;
			}
		}

		public int ID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return SRjLSRUMV;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				SRjLSRUMV = value;
			}
		}

		public int IsBlocking
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return MHklxJ0qT;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				MHklxJ0qT = value;
			}
		}

		public int ParameterID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return Ry6YvNCk2;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				Ry6YvNCk2 = value;
			}
		}

		public int RuleType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			get
			{
				return auT8Rh1SP;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			[CompilerGenerated]
			set
			{
				auT8Rh1SP = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public DependencyDefinition()
		{
			eGujxxQN0KjsXHehk2.DrWxTdOztANlU();
			base..ctor();
		}
	}
}
internal class <Module>{0A00D050-F5F1-4694-B314-304697D40A98}
{
}
namespace eaNnw6oJwxIQQ7FE5G
{
	internal class eILexUWtydOj1ZbkDZ
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module e1WCAykK0;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void AgnxTdOOGjdek(int typemdt)
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
			eGujxxQN0KjsXHehk2.DrWxTdOztANlU();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static eILexUWtydOj1ZbkDZ()
		{
			eGujxxQN0KjsXHehk2.DrWxTdOztANlU();
			e1WCAykK0 = typeof(eILexUWtydOj1ZbkDZ).Assembly.ManifestModule;
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
					eGujxxQN0KjsXHehk2.DrWxTdOztANlU();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			public epk4JLxQrEvWi6AHPc(object P_0)
			{
				eGujxxQN0KjsXHehk2.DrWxTdOztANlU();
				base..ctor();
			}
		}

		internal class eqCW27S8VxFfnK7ae3
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (e1WCAykK0(Convert.ToBase64String(typeof(emYpxP33xAq8jO8oJ1).Assembly.GetName().GetPublicKeyToken()), emYpxP33xAq8jO8oJ1.eopWKtZX1(522)) != emYpxP33xAq8jO8oJ1.eopWKtZX1(528))
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
				eGujxxQN0KjsXHehk2.DrWxTdOztANlU();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint epLVT0LsDNCS2M0vSw([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr anOL6jBbe4cgMAymnk();

		internal struct eMo8xctuZSKRfJjCaO
		{
			internal bool e1WCAykK0;

			internal byte[] eopWKtZX1;
		}

		[Flags]
		private enum Tp2W2X9CZsnByVSId2
		{

		}

		private static byte[] gacVR4NHmS;

		private static object xrMV9REDgB;

		private static int emwVuq8KdF;

		private static bool NPYVMb8V8x;

		private static int UoyVWw75kL;

		internal static epLVT0LsDNCS2M0vSw eWbNGoLe6;

		private static int qDHVhx1XEN;

		private static int XQpV1vJCUH;

		private static byte[] aluePSTLX;

		private static int[] TD6Vj3fYPj;

		private static IntPtr sgYViYTdq0;

		internal static epLVT0LsDNCS2M0vSw ebfRCcJMs;

		private static IntPtr zl0VB7ukRX;

		private static SortedList nnEVTofya2;

		private static long arOVSwHLYF;

		private static IntPtr h5wVVEbWQy;

		private static long CvHVIXvDCc;

		internal static Hashtable e712GIHvk;

		private static byte[] ewyfXpcKg;

		private static bool ALIVGMtiw8;

		private static byte[] Y3hz9yAPr;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static emYpxP33xAq8jO8oJ1()
		{
			aluePSTLX = new byte[0];
			ewyfXpcKg = new byte[0];
			Y3hz9yAPr = new byte[0];
			gacVR4NHmS = new byte[0];
			h5wVVEbWQy = IntPtr.Zero;
			zl0VB7ukRX = IntPtr.Zero;
			xrMV9REDgB = new string[0];
			TD6Vj3fYPj = new int[0];
			emwVuq8KdF = 1;
			NPYVMb8V8x = false;
			nnEVTofya2 = new SortedList();
			UoyVWw75kL = 0;
			arOVSwHLYF = 0L;
			ebfRCcJMs = null;
			eWbNGoLe6 = null;
			CvHVIXvDCc = 0L;
			qDHVhx1XEN = 0;
			ALIVGMtiw8 = false;
			XQpV1vJCUH = 0;
			sgYViYTdq0 = IntPtr.Zero;
			e712GIHvk = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Hy7xTdOMZpEOX()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		static string eopWKtZX1(int P_0)
		{
			int num = 302;
			if (croeYK80FkV53QrPo3())
			{
				goto IL_001a;
			}
			goto IL_014a;
			IL_001a:
			byte[] array = default(byte[]);
			array[15] = 181;
			num = 87;
			if (false)
			{
				goto IL_003e;
			}
			goto IL_014a;
			IL_003e:
			int num2 = 120 + 0;
			int num3 = 145;
			goto IL_014e;
			IL_014e:
			byte[] array2 = default(byte[]);
			int num5 = default(int);
			int num7 = default(int);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			BinaryReader binaryReader = default(BinaryReader);
			CryptoStream cryptoStream = default(CryptoStream);
			MemoryStream memoryStream = default(MemoryStream);
			ICryptoTransform transform = default(ICryptoTransform);
			byte[] array6 = default(byte[]);
			byte[] array3 = default(byte[]);
			byte[] array4 = default(byte[]);
			byte[] array5 = default(byte[]);
			int num4 = default(int);
			while (true)
			{
				int num6;
				switch (num3)
				{
				case 40:
					break;
				case 259:
					goto IL_003e;
				case 229:
					array[18] = (byte)num2;
					num3 = 311;
					continue;
				case 227:
					array2[10] = (byte)num5;
					num3 = 255;
					continue;
				case 230:
					array2[1] = (byte)num5;
					num6 = 263;
					goto IL_0146;
				case 63:
					num2 = 154 + 38;
					num6 = 39;
					goto IL_0146;
				case 91:
					array2[3] = (byte)num5;
					num6 = 252;
					goto IL_0146;
				case 12:
					num7 = 162 - 54;
					num6 = 289;
					goto IL_0146;
				case 306:
					num2 = 217 - 72;
					num = 232;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 261;
				case 139:
					num7 = 33 + 98;
					num = 224;
					if (1 == 0)
					{
						goto case 289;
					}
					goto IL_014a;
				case 289:
					array[26] = (byte)num7;
					goto case 175;
				default:
					num6 = 175;
					goto IL_0146;
				case 323:
					array[10] = (byte)num7;
					num3 = 123;
					continue;
				case 134:
					array[11] = 119;
					num = 183;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 106;
				case 106:
					array2[9] = (byte)num5;
					num3 = 46;
					continue;
				case 213:
					array[4] = (byte)num7;
					num = 241;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 334;
				case 202:
					array2[7] = 136;
					num = 103;
					goto IL_014a;
				case 339:
					num5 = 84 + 96;
					num = 328;
					goto IL_014a;
				case 86:
					array2[5] = 187;
					num3 = 130;
					continue;
				case 22:
					array2[13] = 162;
					num3 = 164;
					continue;
				case 18:
					array[17] = 83;
					num = 82;
					goto IL_014a;
				case 232:
					array[18] = (byte)num2;
					num3 = 298;
					continue;
				case 50:
					BLaTMbXyYlUvfGUZF9(rijndaelManaged, CipherMode.CBC);
					num = 341;
					goto IL_014a;
				case 299:
					num7 = 82 + 82;
					num3 = 188;
					continue;
				case 98:
					array[12] = 132;
					num = 238;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 11;
				case 66:
					array[1] = (byte)num2;
					num3 = 27;
					continue;
				case 48:
					array[25] = (byte)num7;
					num = 12;
					goto IL_014a;
				case 257:
					num2 = 81 + 0;
					num3 = 3;
					continue;
				case 20:
					array[0] = (byte)num7;
					num = 41;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 209;
				case 209:
					nR9bwyJVrdxFTZBJHC(binaryReader);
					num6 = 90;
					goto IL_0146;
				case 135:
					array2[15] = (byte)num5;
					num6 = 64;
					goto IL_0146;
				case 15:
					array2[3] = (byte)num5;
					num = 99;
					if (true)
					{
						goto IL_014a;
					}
					goto case 332;
				case 332:
					array[27] = (byte)num7;
					num6 = 158;
					goto IL_0146;
				case 305:
					array[6] = (byte)num7;
					num = 97;
					if (!croeYK80FkV53QrPo3())
					{
						goto IL_014a;
					}
					goto case 157;
				case 278:
					array[4] = 104;
					num = 237;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 186;
				case 186:
					num5 = 90 - 55;
					num6 = 321;
					goto IL_0146;
				case 170:
					array[16] = (byte)num2;
					num6 = 49;
					goto IL_0146;
				case 177:
					array[15] = 90;
					num = 0;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 340;
				case 340:
					array2[14] = (byte)num5;
					num3 = 307;
					continue;
				case 182:
					array2[1] = 134;
					num = 347;
					if (!croeYK80FkV53QrPo3())
					{
						goto IL_014a;
					}
					goto case 321;
				case 320:
					array[0] = 114;
					num = 313;
					if (true)
					{
						goto IL_014a;
					}
					goto case 211;
				case 211:
					array[2] = (byte)num2;
					num6 = 28;
					goto IL_0146;
				case 245:
					num5 = 22 + 6;
					num = 270;
					if (true)
					{
						goto IL_014a;
					}
					goto case 75;
				case 75:
					num5 = 185 - 61;
					num3 = 138;
					continue;
				case 319:
					num5 = 86 + 7;
					num6 = 239;
					goto IL_0146;
				case 45:
					num7 = 46 + 114;
					num6 = 219;
					goto IL_0146;
				case 194:
					array[23] = (byte)num2;
					num6 = 348;
					goto IL_0146;
				case 337:
					cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
					num = 67;
					if (true)
					{
						goto IL_014a;
					}
					goto case 28;
				case 28:
					num7 = 142 - 47;
					num = 301;
					goto IL_014a;
				case 118:
					num2 = 4 - 3;
					num3 = 160;
					continue;
				case 72:
					array[29] = 104;
					num = 147;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 76;
				case 76:
					num5 = 228 - 76;
					num = 5;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 24;
				case 24:
					num2 = 4 + 41;
					num3 = 285;
					continue;
				case 328:
					array2[6] = (byte)num5;
					num3 = 319;
					continue;
				case 9:
					array2[11] = (byte)num5;
					goto case 195;
				case 313:
					num7 = 251 - 83;
					num3 = 20;
					continue;
				case 183:
					array[11] = 123;
					num = 92;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 193;
				case 193:
					array[30] = (byte)num2;
					num = 291;
					goto IL_014a;
				case 304:
					array2[10] = (byte)num5;
					num3 = 7;
					continue;
				case 250:
					num5 = 112 + 40;
					num = 106;
					if (!croeYK80FkV53QrPo3())
					{
						goto IL_014a;
					}
					goto case 51;
				case 1:
					array2[5] = 123;
					num6 = 198;
					goto IL_0146;
				case 107:
					array[19] = 154;
					num3 = 129;
					continue;
				case 251:
					num5 = 149 - 49;
					num6 = 135;
					goto IL_0146;
				case 198:
					num5 = 205 - 68;
					num3 = 35;
					continue;
				case 36:
					array6 = (byte[])oPwllar7tHTmbpJIC1(binaryReader, (int)yDPLNs5oarOJayMnmS(DInClC2HQFnQRxLGUK(binaryReader)));
					num6 = 217;
					goto IL_0146;
				case 214:
					array2[8] = 144;
					num6 = 76;
					goto IL_0146;
				case 133:
					num7 = 225 - 75;
					num3 = 295;
					continue;
				case 142:
					array2[0] = 110;
					num6 = 344;
					goto IL_0146;
				case 47:
					num2 = 1 + 40;
					num = 141;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 261;
				case 261:
					array2[12] = 104;
					num6 = 78;
					goto IL_0146;
				case 8:
					num7 = 232 - 77;
					num = 300;
					goto IL_014a;
				case 0:
					array[15] = 147;
					num = 40;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 336;
				case 336:
					num7 = 52 + 95;
					num3 = 174;
					continue;
				case 196:
					array[10] = (byte)num7;
					num3 = 266;
					continue;
				case 147:
					array[29] = 136;
					num = 80;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 325;
				case 79:
					num2 = 250 - 83;
					num = 168;
					if (true)
					{
						goto IL_014a;
					}
					goto case 272;
				case 272:
					array2[10] = (byte)num5;
					num = 309;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 73;
				case 73:
					array[3] = 110;
					num = 345;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 208;
				case 208:
					array[17] = 108;
					num3 = 18;
					continue;
				case 284:
					num2 = 38 + 115;
					num3 = 334;
					continue;
				case 32:
					num7 = 107 + 21;
					num6 = 144;
					goto IL_0146;
				case 283:
					array[5] = 75;
					num3 = 124;
					continue;
				case 115:
					array[1] = 64;
					num = 327;
					if (!croeYK80FkV53QrPo3())
					{
						goto IL_014a;
					}
					goto case 246;
				case 44:
					array[5] = 30;
					num = 221;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 228;
				case 228:
					array[30] = (byte)num7;
					num = 178;
					goto IL_014a;
				case 219:
					array[25] = (byte)num7;
					num6 = 236;
					goto IL_0146;
				case 51:
					num7 = 223 - 74;
					num3 = 305;
					continue;
				case 191:
					array[23] = (byte)num2;
					num = 180;
					if (!croeYK80FkV53QrPo3())
					{
						goto IL_014a;
					}
					goto case 284;
				case 156:
					array[21] = (byte)num2;
					num6 = 257;
					goto IL_0146;
				case 348:
					num2 = 222 - 113;
					num6 = 191;
					goto IL_0146;
				case 292:
					num2 = 47 + 3;
					num = 66;
					goto IL_014a;
				case 181:
					num2 = 179 - 59;
					num = 125;
					goto IL_014a;
				case 226:
					num7 = 161 - 86;
					num6 = 199;
					goto IL_0146;
				case 271:
					array2[4] = (byte)num5;
					num6 = 34;
					goto IL_0146;
				case 123:
					array[10] = 154;
					num3 = 349;
					continue;
				case 137:
					array[21] = 40;
					num = 132;
					goto IL_014a;
				case 321:
					array2[12] = (byte)num5;
					num = 189;
					goto IL_014a;
				case 190:
					num2 = 228 + 2;
					num3 = 170;
					continue;
				case 322:
					XrKZPDsirNgHHhy46Z(true);
					num = 36;
					goto IL_014a;
				case 150:
					array[8] = 80;
					num = 79;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 165;
				case 165:
					array[6] = 104;
					num = 308;
					goto IL_014a;
				case 316:
					array[9] = (byte)num2;
					num3 = 6;
					continue;
				case 234:
					array[22] = 113;
					num = 159;
					goto IL_014a;
				case 171:
					array2 = new byte[16];
					num = 167;
					if (!croeYK80FkV53QrPo3())
					{
						goto IL_014a;
					}
					goto case 242;
				case 242:
					array[24] = 147;
					num3 = 63;
					continue;
				case 210:
					num5 = 26 + 18;
					num6 = 317;
					goto IL_0146;
				case 236:
					num2 = 185 - 61;
					num6 = 81;
					goto IL_0146;
				case 334:
					array[13] = (byte)num2;
					num6 = 207;
					goto IL_0146;
				case 128:
					array[1] = (byte)num7;
					num6 = 58;
					goto IL_0146;
				case 308:
					num2 = 236 - 78;
					num3 = 329;
					continue;
				case 329:
					array[6] = (byte)num2;
					num = 51;
					goto IL_014a;
				case 188:
					array[11] = (byte)num7;
					num6 = 98;
					goto IL_0146;
				case 108:
					array2[5] = 100;
					num3 = 86;
					continue;
				case 240:
					array[10] = 191;
					num6 = 264;
					goto IL_0146;
				case 185:
					num2 = 215 - 71;
					num6 = 154;
					goto IL_0146;
				case 298:
					array[18] = 111;
					num6 = 163;
					goto IL_0146;
				case 82:
					num2 = 171 + 77;
					num6 = 122;
					goto IL_0146;
				case 105:
					array[10] = (byte)num7;
					num = 200;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 254;
				case 254:
					num7 = 69 + 81;
					num = 52;
					goto IL_014a;
				case 41:
					array[0] = 188;
					num6 = 292;
					goto IL_0146;
				case 111:
					array[27] = 103;
					num3 = 187;
					continue;
				case 258:
					array[17] = (byte)num2;
					num = 173;
					goto IL_014a;
				case 80:
					array[29] = 66;
					num = 274;
					goto IL_014a;
				case 285:
					array[31] = (byte)num2;
					num3 = 296;
					continue;
				case 62:
					num5 = 216 - 121;
					num6 = 248;
					goto IL_0146;
				case 141:
					array[20] = (byte)num2;
					num = 223;
					goto IL_014a;
				case 138:
					array2[14] = (byte)num5;
					num = 151;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 282;
				case 282:
					num7 = 23 + 43;
					num3 = 228;
					continue;
				case 140:
					array[11] = (byte)num7;
					num3 = 233;
					continue;
				case 201:
					num7 = 35 + 36;
					num3 = 59;
					continue;
				case 222:
					array2[14] = (byte)num5;
					num3 = 62;
					continue;
				case 237:
					num7 = 85 + 10;
					num6 = 213;
					goto IL_0146;
				case 345:
					array[3] = 61;
					num6 = 278;
					goto IL_0146;
				case 315:
					array[29] = (byte)num2;
					num3 = 282;
					continue;
				case 89:
					num5 = 35 + 33;
					num6 = 31;
					goto IL_0146;
				case 175:
					array[26] = 143;
					num6 = 42;
					goto IL_0146;
				case 71:
					array[8] = 150;
					num = 32;
					if (true)
					{
						goto IL_014a;
					}
					goto case 166;
				case 166:
					array[3] = (byte)num7;
					num6 = 73;
					goto IL_0146;
				case 132:
					array[22] = 116;
					num6 = 234;
					goto IL_0146;
				case 200:
					array[10] = 49;
					num3 = 134;
					continue;
				case 216:
					array[18] = (byte)num7;
					num = 120;
					goto IL_014a;
				case 124:
					array[5] = 98;
					num3 = 44;
					continue;
				case 262:
					num2 = 97 + 94;
					num = 331;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 160;
				case 290:
					array3[1] = array4[0];
					num6 = 243;
					goto IL_0146;
				case 16:
					num5 = 201 - 67;
					num3 = 244;
					continue;
				case 233:
					array[11] = 105;
					num = 53;
					if (!croeYK80FkV53QrPo3())
					{
						goto IL_014a;
					}
					goto case 176;
				case 176:
					num5 = 160 - 53;
					num = 15;
					if (true)
					{
						goto IL_014a;
					}
					goto case 180;
				case 180:
					array[24] = 231;
					num6 = 242;
					goto IL_0146;
				case 203:
					num5 = 118 + 54;
					num6 = 84;
					goto IL_0146;
				case 109:
					num2 = 110 - 55;
					num3 = 315;
					continue;
				case 293:
					array2[5] = 111;
					num = 1;
					if (!croeYK80FkV53QrPo3())
					{
						goto IL_014a;
					}
					goto case 22;
				case 87:
					array[16] = 127;
					num = 139;
					goto IL_014a;
				case 154:
					goto IL_16e1;
				case 217:
					array = new byte[32];
					num6 = 19;
					goto IL_0146;
				case 54:
					array2[1] = (byte)num5;
					num = 149;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 312;
				case 312:
					array[16] = (byte)num2;
					num6 = 190;
					goto IL_0146;
				case 235:
					array2[15] = (byte)num5;
					num3 = 245;
					continue;
				case 206:
					num5 = 126 + 87;
					num = 91;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 59;
				case 59:
					array[7] = (byte)num7;
					num3 = 85;
					continue;
				case 60:
					num7 = 169 - 56;
					num = 166;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 83;
				case 83:
					array2[15] = 176;
					num = 104;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 38;
				case 38:
					array2[15] = (byte)num5;
					num = 117;
					goto IL_014a;
				case 6:
					array[9] = 232;
					num6 = 240;
					goto IL_0146;
				case 3:
					array[21] = (byte)num2;
					num = 172;
					if (!croeYK80FkV53QrPo3())
					{
						goto IL_014a;
					}
					goto case 152;
				case 207:
					array[13] = 41;
					num = 61;
					goto IL_014a;
				case 155:
					array[28] = 102;
					num6 = 268;
					goto IL_0146;
				case 174:
					array[28] = (byte)num7;
					num3 = 155;
					continue;
				case 195:
				case 288:
					array2[11] = 100;
					num3 = 303;
					continue;
				case 266:
					num7 = 221 - 73;
					num6 = 105;
					goto IL_0146;
				case 192:
					array2[4] = (byte)num5;
					num = 21;
					if (!croeYK80FkV53QrPo3())
					{
						goto IL_014a;
					}
					goto case 263;
				case 231:
					array2[13] = (byte)num5;
					num3 = 22;
					continue;
				case 303:
					num5 = 124 + 41;
					num = 273;
					goto IL_014a;
				case 10:
					array2[8] = (byte)num5;
					num = 16;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 280;
				case 280:
					num5 = 49 + 42;
					num6 = 222;
					goto IL_0146;
				case 2:
					Lnba9fjU9UvPEJUCXq(memoryStream);
					num3 = 279;
					continue;
				case 104:
					num5 = 101 + 60;
					num3 = 26;
					continue;
				case 113:
					array[23] = 108;
					num3 = 146;
					continue;
				case 275:
					array[20] = 127;
					num = 262;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 23;
				case 23:
					num5 = 57 + 73;
					num6 = 131;
					goto IL_0146;
				case 252:
					num5 = 90 + 76;
					num6 = 271;
					goto IL_0146;
				case 116:
					num2 = 167 - 55;
					num = 316;
					if (!croeYK80FkV53QrPo3())
					{
						goto IL_014a;
					}
					goto case 169;
				case 169:
					array3[13] = array4[6];
					num = 143;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 268;
				case 268:
					array[28] = 118;
					num6 = 72;
					goto IL_0146;
				case 120:
					array[18] = 204;
					num3 = 95;
					continue;
				case 19:
					array[0] = 115;
					num = 320;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 77;
				case 77:
					num5 = 71 + 10;
					num3 = 267;
					continue;
				case 125:
					array[25] = (byte)num2;
					num = 259;
					goto IL_014a;
				case 307:
					num5 = 210 - 70;
					num3 = 287;
					continue;
				case 157:
					num5 = 241 - 80;
					num3 = 235;
					continue;
				case 127:
					array[6] = (byte)num2;
					num = 165;
					goto IL_014a;
				case 160:
					array[26] = (byte)num2;
					num = 111;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 94;
				case 94:
					array2[9] = 87;
					num3 = 250;
					continue;
				case 274:
					array[29] = 229;
					num3 = 162;
					continue;
				case 153:
					array[1] = (byte)num7;
					num6 = 115;
					goto IL_0146;
				case 246:
					array[13] = (byte)num7;
					num = 126;
					if (true)
					{
						goto IL_014a;
					}
					goto case 53;
				case 53:
					array[11] = 125;
					num6 = 299;
					goto IL_0146;
				case 309:
					num5 = 127 + 89;
					num6 = 227;
					goto IL_0146;
				case 327:
					num7 = 75 + 117;
					num6 = 102;
					goto IL_0146;
				case 267:
					array2[3] = (byte)num5;
					num = 176;
					if (!croeYK80FkV53QrPo3())
					{
						goto IL_014a;
					}
					goto case 297;
				case 297:
					array[20] = 8;
					num = 249;
					if (!croeYK80FkV53QrPo3())
					{
						goto IL_014a;
					}
					goto case 24;
				case 99:
					array2[3] = 84;
					num = 206;
					goto IL_014a;
				case 197:
					array[8] = 107;
					num6 = 150;
					goto IL_0146;
				case 317:
					array2[4] = (byte)num5;
					num = 14;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 172;
				case 172:
					array[21] = 138;
					num6 = 137;
					goto IL_0146;
				case 11:
					num2 = 53 + 45;
					num6 = 312;
					goto IL_0146;
				case 84:
					array2[6] = (byte)num5;
					num6 = 339;
					goto IL_0146;
				case 35:
					array2[5] = (byte)num5;
					num3 = 108;
					continue;
				case 256:
					array[12] = (byte)num7;
					num = 326;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 55;
				case 55:
					array4 = (byte[])dgU3wWGkaldsYgJvjD(wEXQCjQ7r9fcAAjMVC(StATr1H6L49r9JNTVf(typeof(emYpxP33xAq8jO8oJ1).TypeHandle).Assembly));
					num = 65;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 173;
				case 173:
					num2 = 136 - 45;
					num = 30;
					if (true)
					{
						goto IL_014a;
					}
					goto case 279;
				case 279:
					Lnba9fjU9UvPEJUCXq(cryptoStream);
					num = 209;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 201;
				case 264:
					num7 = 56 + 16;
					num3 = 323;
					continue;
				case 27:
					num7 = 206 - 68;
					num = 247;
					if (!croeYK80FkV53QrPo3())
					{
						goto IL_014a;
					}
					goto case 80;
				case 143:
					array3[15] = array4[7];
					num = 100;
					goto IL_014a;
				case 218:
					num5 = 195 - 65;
					num = 286;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 283;
				case 199:
					array[14] = (byte)num7;
					num6 = 177;
					goto IL_0146;
				case 78:
					num5 = 207 - 69;
					num = 204;
					if (!croeYK80FkV53QrPo3())
					{
						goto IL_014a;
					}
					goto case 283;
				case 341:
					transform = (ICryptoTransform)TjoYRx74A3mEvyJZKc(rijndaelManaged, array5, array3);
					num3 = 179;
					continue;
				case 130:
					array2[6] = 48;
					num = 203;
					if (true)
					{
						goto IL_014a;
					}
					goto case 42;
				case 42:
					array[26] = 93;
					num6 = 118;
					goto IL_0146;
				case 49:
					num2 = 149 - 49;
					num = 258;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 5;
				case 5:
					array2[8] = (byte)num5;
					num = 314;
					goto IL_014a;
				case 248:
					array2[14] = (byte)num5;
					num6 = 83;
					goto IL_0146;
				case 238:
					array[12] = 206;
					num3 = 96;
					continue;
				case 295:
					array[7] = (byte)num7;
					num3 = 68;
					continue;
				case 112:
					array2[2] = 148;
					num3 = 23;
					continue;
				case 34:
					num5 = 198 - 66;
					num6 = 205;
					goto IL_0146;
				case 239:
					array2[6] = (byte)num5;
					num3 = 276;
					continue;
				case 67:
					si7TvSbmIYSDcny9b5(cryptoStream, array6, 0, array6.Length);
					num3 = 25;
					continue;
				case 247:
					array[1] = (byte)num7;
					num6 = 185;
					goto IL_0146;
				case 255:
					num5 = 44 + 87;
					num = 9;
					goto IL_014a;
				case 29:
					array2[6] = (byte)num5;
					num = 69;
					if (!croeYK80FkV53QrPo3())
					{
						goto IL_014a;
					}
					goto case 105;
				case 39:
					array[24] = (byte)num2;
					num3 = 181;
					continue;
				case 347:
					num5 = 36 + 92;
					num6 = 230;
					goto IL_0146;
				case 324:
					array5 = array;
					num = 171;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 148;
				case 148:
					num5 = 195 + 28;
					num3 = 161;
					continue;
				case 269:
					num7 = 43 - 35;
					num3 = 48;
					continue;
				case 311:
					num7 = 126 - 42;
					num = 216;
					goto IL_014a;
				case 92:
					num7 = 16 + 16;
					num = 140;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 17;
				case 17:
				case 93:
					num7 = 242 - 80;
					num = 128;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 52;
				case 52:
					array[27] = (byte)num7;
					num6 = 260;
					goto IL_0146;
				case 57:
					array[5] = (byte)num2;
					num = 283;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 224;
				case 145:
					array[25] = (byte)num2;
					num3 = 33;
					continue;
				case 4:
					array[9] = 115;
					num = 70;
					if (!croeYK80FkV53QrPo3())
					{
						goto IL_014a;
					}
					goto case 221;
				case 221:
					num2 = 200 - 66;
					num3 = 127;
					continue;
				case 300:
					array[30] = (byte)num7;
					num6 = 310;
					goto IL_0146;
				case 287:
					array2[14] = (byte)num5;
					num3 = 280;
					continue;
				case 344:
					num5 = 7 + 91;
					num6 = 54;
					goto IL_0146;
				case 7:
					num5 = 147 - 49;
					num3 = 272;
					continue;
				case 335:
					Y3hz9yAPr = (byte[])wyJPrqeEt7RTXDPRRU(memoryStream);
					num = 2;
					goto IL_014a;
				case 131:
					array2[2] = (byte)num5;
					num3 = 114;
					continue;
				case 90:
					num4 = tGo7HcM7WkkRdcHGxU(Y3hz9yAPr, P_0);
					num6 = 351;
					goto IL_0146;
				case 281:
					array[23] = 69;
					num = 113;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 64;
				case 64:
					num5 = 97 - 86;
					num3 = 38;
					continue;
				case 187:
					num7 = 38 + 47;
					num3 = 332;
					continue;
				case 25:
					YYlPQJvBaNm4dUCnvB(cryptoStream);
					num = 335;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 65;
				case 65:
					if (array4 != null)
					{
						num = 333;
						goto IL_014a;
					}
					goto case 100;
				case 189:
					num5 = 197 - 65;
					num6 = 231;
					goto IL_0146;
				case 117:
					array3 = array2;
					num6 = 55;
					goto IL_0146;
				case 70:
					num2 = 179 - 59;
					num3 = 277;
					continue;
				case 56:
					array3[7] = array4[3];
					num = 350;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 158;
				case 158:
					num2 = 161 - 53;
					num3 = 294;
					continue;
				case 220:
					array[31] = 125;
					num3 = 324;
					continue;
				case 225:
					array[12] = 141;
					num6 = 101;
					goto IL_0146;
				case 68:
					array[7] = 94;
					num3 = 201;
					continue;
				case 152:
					num2 = 12 + 85;
					num = 212;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 192;
				case 33:
					array[25] = 112;
					num6 = 45;
					goto IL_0146;
				case 301:
					array[2] = (byte)num7;
					num3 = 136;
					continue;
				case 81:
					array[25] = (byte)num2;
					num = 269;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 164;
				case 343:
					num2 = 0 + 57;
					num = 156;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 146;
				case 146:
					num2 = 193 - 64;
					num3 = 194;
					continue;
				case 184:
					array2[9] = (byte)num5;
					num3 = 148;
					continue;
				case 46:
					num5 = 46 + 54;
					num = 184;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 102;
				case 102:
					array[2] = (byte)num7;
					num3 = 13;
					continue;
				case 161:
					array2[9] = (byte)num5;
					num6 = 43;
					goto IL_0146;
				case 88:
					num5 = 247 - 82;
					num3 = 340;
					continue;
				case 129:
					array[19] = 20;
					num6 = 275;
					goto IL_0146;
				case 37:
					array[14] = 34;
					num = 226;
					if (true)
					{
						goto IL_014a;
					}
					goto case 325;
				case 325:
					array3[5] = array4[2];
					num6 = 56;
					goto IL_0146;
				case 149:
					array2[1] = 89;
					num6 = 182;
					goto IL_0146;
				case 260:
					array[28] = 162;
					num6 = 336;
					goto IL_0146;
				case 119:
					array[9] = 118;
					num = 116;
					if (!croeYK80FkV53QrPo3())
					{
						goto IL_014a;
					}
					goto case 273;
				case 273:
					array2[11] = (byte)num5;
					num6 = 89;
					goto IL_0146;
				case 302:
					if (Y3hz9yAPr.Length != 0)
					{
						goto case 90;
					}
					num = 330;
					if (true)
					{
						goto IL_014a;
					}
					goto case 69;
				case 69:
					num5 = 117 + 57;
					num6 = 74;
					goto IL_0146;
				case 95:
					array[19] = 112;
					num = 107;
					if (true)
					{
						goto IL_014a;
					}
					goto case 296;
				case 296:
					array[31] = 49;
					num = 220;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 326;
				case 326:
					array[12] = 17;
					num6 = 284;
					goto IL_0146;
				case 167:
					array2[0] = 106;
					num6 = 218;
					goto IL_0146;
				case 314:
					num5 = 169 + 83;
					num = 318;
					if (true)
					{
						goto IL_014a;
					}
					goto case 223;
				case 223:
					array[20] = 141;
					num6 = 152;
					goto IL_0146;
				case 276:
					num5 = 136 - 21;
					num = 29;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 164;
				case 164:
					num5 = 146 + 52;
					num = 265;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 16;
				case 330:
					binaryReader = new BinaryReader((Stream)l8DRv5obCwvHx4XDW9(StATr1H6L49r9JNTVf(typeof(emYpxP33xAq8jO8oJ1).TypeHandle).Assembly, "6EYxHceMfKLkXIFpoB.58Z9yVxrNL6WowUGv5"));
					num6 = 346;
					goto IL_0146;
				case 331:
					array[20] = (byte)num2;
					num = 47;
					goto IL_014a;
				case 349:
					num7 = 202 - 67;
					num = 196;
					goto IL_014a;
				case 350:
					array3[9] = array4[4];
					num = 215;
					if (!croeYK80FkV53QrPo3())
					{
						goto IL_014a;
					}
					goto case 270;
				case 144:
					array[8] = (byte)num7;
					num3 = 197;
					continue;
				case 277:
					array[9] = (byte)num2;
					num = 119;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 85;
				case 85:
					array[7] = 50;
					num6 = 71;
					goto IL_0146;
				case 286:
					array2[0] = (byte)num5;
					num = 142;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 43;
				case 43:
					num5 = 228 - 76;
					num = 304;
					if (true)
					{
						goto IL_014a;
					}
					goto case 163;
				case 163:
					num2 = 22 + 62;
					num6 = 229;
					goto IL_0146;
				case 74:
					array2[7] = (byte)num5;
					num = 121;
					if (true)
					{
						goto IL_014a;
					}
					goto case 205;
				case 205:
					array2[4] = (byte)num5;
					num = 210;
					if (true)
					{
						goto IL_014a;
					}
					goto case 265;
				case 265:
					array2[13] = (byte)num5;
					num = 75;
					goto IL_014a;
				case 159:
					num2 = 138 - 82;
					num3 = 110;
					continue;
				case 31:
					array2[12] = (byte)num5;
					num = 261;
					goto IL_014a;
				case 13:
					num2 = 180 - 60;
					num = 211;
					if (!croeYK80FkV53QrPo3())
					{
						goto IL_014a;
					}
					goto case 333;
				case 333:
					if (array4.Length <= 0)
					{
						goto case 100;
					}
					num = 290;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 75;
				case 342:
					num5 = 48 + 93;
					num = 10;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 270;
				case 270:
					array2[15] = (byte)num5;
					num6 = 251;
					goto IL_0146;
				case 58:
					num7 = 215 - 71;
					num = 153;
					goto IL_014a;
				case 244:
					array2[8] = (byte)num5;
					num = 214;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 121;
				case 121:
					array2[7] = 124;
					num3 = 202;
					continue;
				case 204:
					array2[12] = (byte)num5;
					num = 186;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 145;
				case 126:
					array[14] = 114;
					num6 = 37;
					goto IL_0146;
				case 136:
					array[2] = 222;
					num6 = 60;
					goto IL_0146;
				case 338:
					num2 = 60 + 6;
					num6 = 57;
					goto IL_0146;
				case 346:
					nsHWuAUZ5XFoZNj7Wi(DInClC2HQFnQRxLGUK(binaryReader), 0L);
					num6 = 322;
					goto IL_0146;
				case 103:
					array2[7] = 158;
					num3 = 253;
					continue;
				case 162:
					array[29] = 112;
					num = 109;
					if (true)
					{
						goto IL_014a;
					}
					goto case 263;
				case 263:
					array2[1] = 86;
					num6 = 112;
					goto IL_0146;
				case 101:
					num7 = 168 - 56;
					num = 256;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 26;
				case 26:
					array2[15] = (byte)num5;
					num6 = 157;
					goto IL_0146;
				case 110:
					array[22] = (byte)num2;
					num3 = 281;
					continue;
				case 30:
					array[17] = (byte)num2;
					num3 = 208;
					continue;
				case 14:
					num5 = 86 + 70;
					num6 = 192;
					goto IL_0146;
				case 241:
					array[4] = 42;
					num6 = 338;
					goto IL_0146;
				case 96:
					array[12] = 138;
					num3 = 225;
					continue;
				case 212:
					array[20] = (byte)num2;
					num = 297;
					if (anDUmDkg6Mw5hbiFOU())
					{
						goto IL_014a;
					}
					goto case 294;
				case 294:
					array[27] = (byte)num2;
					num6 = 254;
					goto IL_0146;
				case 122:
					array[17] = (byte)num2;
					num3 = 306;
					continue;
				case 61:
					num7 = 44 - 10;
					num = 246;
					goto IL_014a;
				case 291:
					array[30] = 141;
					num6 = 24;
					goto IL_0146;
				case 318:
					array2[8] = (byte)num5;
					num = 94;
					if (!croeYK80FkV53QrPo3())
					{
						goto IL_014a;
					}
					goto case 224;
				case 224:
					array[16] = (byte)num7;
					num = 11;
					goto IL_014a;
				case 310:
					num2 = 133 - 44;
					num = 193;
					if (true)
					{
						goto IL_014a;
					}
					goto case 253;
				case 253:
					array2[7] = 95;
					num3 = 342;
					continue;
				case 178:
					array[30] = 108;
					num6 = 8;
					goto IL_0146;
				case 249:
					array[21] = 52;
					num = 343;
					if (0 == 0)
					{
						goto IL_014a;
					}
					goto case 97;
				case 97:
					array[6] = 201;
					num3 = 133;
					continue;
				case 168:
					array[9] = (byte)num2;
					num = 4;
					goto IL_014a;
				case 215:
					array3[11] = array4[5];
					num3 = 169;
					continue;
				case 21:
					array2[4] = 10;
					num6 = 293;
					goto IL_0146;
				case 243:
					array3[3] = array4[1];
					num3 = 325;
					continue;
				case 114:
					array2[2] = 11;
					num3 = 77;
					continue;
				case 151:
					array2[14] = 126;
					num3 = 88;
					continue;
				case 351:
					try
					{
						return (string)gBL2MXWHwcI4dZvRUO(WiphR4LEABn2Je7XeY(), Y3hz9yAPr, P_0 + 4, num4);
					}
					catch
					{
					}
					return "";
				case 179:
					memoryStream = new MemoryStream();
					num = 337;
					goto IL_014a;
				case 100:
					{
						rijndaelManaged = new RijndaelManaged();
						num3 = 50;
						continue;
					}
					IL_0146:
					num = num6;
					goto IL_014a;
				}
				break;
				IL_16e1:
				array[1] = (byte)num2;
				_ = 0;
				if (!anDUmDkg6Mw5hbiFOU())
				{
					num = 195;
					goto IL_014a;
				}
				num3 = 93;
			}
			goto IL_001a;
			IL_014a:
			num3 = num;
			goto IL_014e;
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
		private static extern void jj8HoEbsa(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int VU64N7hwe(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr eQ7GFE5Gm(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void serXFw8ZQ()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void zf8ndW4HQ()
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
		private static extern int m0qwInbAk(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int aVUvhqhLl(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int YLWOLV0VE(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr suNkFLGoK(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int mDqAPikbN(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		private static byte[] ufUZpSn80(string P_0)
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
		private static byte[] f1Btf4TSw(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				88, 123, 15, 20, 177, 151, 79, 94, 198, 148,
				175, 227, 5, 96, 159, 137, 42, 205, 114, 136,
				128, 143, 58, 94, 156, 57, 88, 123, 199, 181,
				83, 49
			};
			rijndael.IV = new byte[16]
			{
				125, 95, 50, 183, 61, 218, 177, 120, 62, 37,
				166, 134, 131, 98, 83, 95
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] rngdP5yTR()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] VxYphvg4T()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] HxmCrQ9su()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] nPqcQtMkS()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] KKqrSeZTu()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] MMZUj9G0Y()
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
		internal static Type StATr1H6L49r9JNTVf(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object l8DRv5obCwvHx4XDW9(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object DInClC2HQFnQRxLGUK(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void nsHWuAUZ5XFoZNj7Wi(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void XrKZPDsirNgHHhy46Z(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long yDPLNs5oarOJayMnmS(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object oPwllar7tHTmbpJIC1(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object wEXQCjQ7r9fcAAjMVC(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object dgU3wWGkaldsYgJvjD(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void BLaTMbXyYlUvfGUZF9(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object TjoYRx74A3mEvyJZKc(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void si7TvSbmIYSDcny9b5(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void YYlPQJvBaNm4dUCnvB(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object wyJPrqeEt7RTXDPRRU(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Lnba9fjU9UvPEJUCXq(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void nR9bwyJVrdxFTZBJHC(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int tGo7HcM7WkkRdcHGxU(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object WiphR4LEABn2Je7XeY()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object gBL2MXWHwcI4dZvRUO(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool anDUmDkg6Mw5hbiFOU()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool croeYK80FkV53QrPo3()
		{
			return false;
		}
	}
}
namespace eoP53YVgQa1lbB0Xy6
{
	internal class eGujxxQN0KjsXHehk2
	{
		private static bool JyHVPvPEP9;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void DrWxTdOztANlU()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public eGujxxQN0KjsXHehk2()
		{
		}
	}
}
