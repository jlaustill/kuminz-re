using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using System.Xml;
using CILCompressionUtilitiesLib;
using Cummins.INSITE.Kernel.ECMServicesAPI;
using Cummins.INSITE.Kernel.ECMServicesCommonTypes;
using eIOTCwgtN7fvJXNYMS;
using eoP53YVgQa1lbB0Xy6;

[assembly: Guid("1cd22335-20c9-4459-8d0f-fd0fcfd74efa")]
[assembly: InternalsVisibleTo("INSITEImageReaderUnitTest")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyKeyName("")]
[assembly: SuppressIldasm]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyDelaySign(false)]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Cummins.INSITE.Kernel.INSITEImageReader")]
[assembly: AssemblyTitle("Cummins.INSITE.Kernel.INSITEImageReader")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyVersion("7.6.0.272")]
internal static class 82o2QciXFh8XowetkB
{
}
namespace Cummins.INSITE.Kernel.INSITEImageReader
{
	public interface IINSITEImageReader
	{
		IINSITEImage OpenImage(string imageFilename);

		void CloseImage(string imageFilename);
	}
	public class INSITEImageReader : IINSITEImageReader
	{
		private static INSITEImageReader TCp5DM0Ut;

		private Dictionary<string, INSITEImage> wQSql8bZr;

		private Dictionary<string, int> aGsSkS6TG;

		private ICICompression Up77m9rQ3;

		public static IINSITEImageReader ImageReader
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return TCp5DM0Ut;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private INSITEImageReader()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.Pyq7QFNzjxFmt();
			base..ctor();
			wQSql8bZr = new Dictionary<string, INSITEImage>();
			aGsSkS6TG = new Dictionary<string, int>();
			Up77m9rQ3 = new CompressClass();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IINSITEImage OpenImage(string imageFilename)
		{
			//IL_0093: Unknown result type (might be due to invalid IL or missing references)
			//IL_0099: Expected O, but got Unknown
			INSITEImage iNSITEImage = null;
			string fullPath = Path.GetFullPath(imageFilename);
			if (wQSql8bZr.ContainsKey(fullPath))
			{
				aGsSkS6TG[fullPath]++;
				iNSITEImage = wQSql8bZr[fullPath];
			}
			else
			{
				Up77m9rQ3.ArchiveName = fullPath;
				Up77m9rQ3.Password = ECMServicesConfiguration.Configuration.GetConfigurationValue(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(0));
				Up77m9rQ3.FileCleanup = false;
				Up77m9rQ3.ExtractToMemory = true;
				XmlDocument val = new XmlDocument();
				try
				{
					if (Up77m9rQ3.ExtractSingleFile(Path.GetFileName(imageFilename)) != ExtractResultEnum.ExtractSuccess)
					{
						throw new FileLoadException();
					}
				}
				catch (COMException)
				{
					throw new FileLoadException(fullPath + eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(30));
				}
				byte[] buffer = (byte[])Up77m9rQ3.get_MemoryFile();
				MemoryStream memoryStream = new MemoryStream(buffer);
				val.Load((Stream)memoryStream);
				iNSITEImage = new INSITEImage(fullPath, val);
				wQSql8bZr.Add(fullPath, iNSITEImage);
				aGsSkS6TG.Add(fullPath, 1);
			}
			return iNSITEImage;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void CloseImage(string imageFilename)
		{
			string fullPath = Path.GetFullPath(imageFilename);
			if (wQSql8bZr.ContainsKey(fullPath))
			{
				aGsSkS6TG[fullPath]--;
				if (aGsSkS6TG[fullPath] == 0)
				{
					wQSql8bZr[fullPath].Close();
					wQSql8bZr.Remove(fullPath);
					aGsSkS6TG.Remove(fullPath);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static INSITEImageReader()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.Pyq7QFNzjxFmt();
			TCp5DM0Ut = new INSITEImageReader();
		}
	}
	public interface IINSITEImage
	{
		string ImageFilePath { get; }

		bool CanWrite { get; }

		int ECUType { get; }

		int SystemType { get; }

		string Version { get; }

		bool RegionalSettingsApplied { get; }

		bool HasOtherDevices { get; }

		IImageParameter GetParameter(string parameterId, int sourceAddress = 0);

		IImageArray GetArray(string arrayId);

		IDictionary<int, int> GetOtherDevicesInfo();
	}
	internal class INSITEImage : IINSITEImage
	{
		private static readonly string GqIA6FvTO;

		private static readonly string ghSaXX8U3;

		private static readonly string G0lmy5R8l;

		private static readonly string TWknGUdUv;

		protected string _imageFilePath;

		protected XmlDocument _imageDoc;

		protected bool _canWrite;

		protected int _ecuType;

		protected int _systemType;

		protected string _version;

		protected bool _regionalSettingsApplied;

		protected bool _isLegacy;

		protected bool _closed;

		public string ImageFilePath
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _imageFilePath;
			}
		}

		public bool CanWrite
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _canWrite;
			}
		}

		public int ECUType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _ecuType;
			}
		}

		public int SystemType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _systemType;
			}
		}

		public string Version
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _version;
			}
		}

		public bool RegionalSettingsApplied
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _regionalSettingsApplied;
			}
		}

		public bool HasOtherDevices
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				XmlNodeList val = ((XmlNode)_imageDoc.DocumentElement).SelectNodes(G0lmy5R8l);
				if (val.Count > 0)
				{
					return true;
				}
				return false;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public INSITEImage(string imageFilePath, XmlDocument imageDoc)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.Pyq7QFNzjxFmt();
			base..ctor();
			_closed = false;
			_imageFilePath = imageFilePath;
			_imageDoc = imageDoc;
			loadImage();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void Close()
		{
			_closed = true;
			_imageDoc = null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IImageParameter GetParameter(string parameterId, int sourceAddress = 0)
		{
			if (_closed)
			{
				throw new InvalidOperationException(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(80));
			}
			string text = hxmLy09nW(parameterId, sourceAddress);
			XmlNode val = ((XmlNode)_imageDoc.DocumentElement).SelectSingleNode(text);
			if (val == null)
			{
				throw new ECMServicesException(ECMServicesErrorCodes.ParameterReadBlocked);
			}
			ImageParameter imageParameter = ((!(parameterId == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(124))) ? new ImageParameter(val, _isLegacy) : new ImageTisIdParameter(val, _isLegacy));
			if (imageParameter.Value == eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(144))
			{
				throw new ECMServicesException(ECMServicesErrorCodes.ParameterReadBlocked);
			}
			return imageParameter;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IImageArray GetArray(string arrayId)
		{
			if (_closed)
			{
				throw new InvalidOperationException(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(158));
			}
			string text = string.Format(ghSaXX8U3, arrayId);
			XmlNode val = ((XmlNode)_imageDoc.DocumentElement).SelectSingleNode(text);
			if (val == null)
			{
				throw new ArgumentException(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(202), eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(238));
			}
			return new ImageArray(val, _isLegacy);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IDictionary<int, int> GetOtherDevicesInfo()
		{
			//IL_0043: Unknown result type (might be due to invalid IL or missing references)
			//IL_0049: Expected O, but got Unknown
			Dictionary<int, int> dictionary = new Dictionary<int, int>();
			XmlNodeList val = ((XmlNode)_imageDoc.DocumentElement).SelectNodes(G0lmy5R8l);
			if (val.Count > 0)
			{
				foreach (XmlNode item in val)
				{
					XmlNode val2 = item;
					int key = int.Parse(((XmlNode)val2.Attributes[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(256)]).Value);
					int value = int.Parse(((XmlNode)val2.Attributes[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(286)]).Value);
					dictionary.Add(key, value);
				}
			}
			return dictionary;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected virtual void loadImage()
		{
			int num = int.Parse(((XmlNode)((XmlNode)_imageDoc.DocumentElement).Attributes[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(304)]).Value);
			_canWrite = num == 1;
			_version = ((XmlNode)((XmlNode)_imageDoc.DocumentElement).Attributes[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(324)]).Value;
			_ecuType = int.Parse(((XmlNode)((XmlNode)_imageDoc.DocumentElement).Attributes[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(352)]).Value);
			_systemType = int.Parse(((XmlNode)((XmlNode)_imageDoc.DocumentElement).Attributes[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(370)]).Value);
			try
			{
				int num2 = int.Parse(((XmlNode)((XmlNode)_imageDoc.DocumentElement).Attributes[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(388)]).Value);
				_regionalSettingsApplied = num2 == 1;
			}
			catch
			{
				_regionalSettingsApplied = true;
			}
			string text;
			try
			{
				text = ((XmlNode)((XmlNode)_imageDoc.DocumentElement).Attributes[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(426)]).Value;
			}
			catch
			{
				text = _version;
			}
			string[] separator = new string[1] { eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(460) };
			string[] array = text.Split(separator, StringSplitOptions.RemoveEmptyEntries);
			if (array.Length >= 2)
			{
				if (int.Parse(array[0]) >= 7)
				{
					if (int.Parse(array[1]) >= 6)
					{
						_isLegacy = false;
					}
					else
					{
						_isLegacy = true;
					}
				}
				else
				{
					_isLegacy = true;
				}
			}
			else
			{
				_isLegacy = true;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private string hxmLy09nW(string P_0, int P_1)
		{
			if (P_1 == 0)
			{
				return string.Format(GqIA6FvTO, P_0);
			}
			return string.Format(TWknGUdUv, P_1, P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static INSITEImage()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.Pyq7QFNzjxFmt();
			GqIA6FvTO = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(466);
			ghSaXX8U3 = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(520);
			G0lmy5R8l = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(566);
			TWknGUdUv = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(622);
		}
	}
	public interface IImageParameterDependency
	{
		int DependencyParameterId { get; }

		RuleType RuleType { get; }

		AccessType AccessType { get; }

		BlockType BlockType { get; }
	}
	internal class ImageParameterDependency : IImageParameterDependency
	{
		private int lo8EVQ2D2;

		private RuleType KZdZPEOxu;

		private AccessType MKwPcorc9;

		private BlockType nbHKRLMsC;

		public int DependencyParameterId
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return lo8EVQ2D2;
			}
		}

		public RuleType RuleType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return KZdZPEOxu;
			}
		}

		public AccessType AccessType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return MKwPcorc9;
			}
		}

		public BlockType BlockType
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return nbHKRLMsC;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ImageParameterDependency(XmlNode dependencyNode)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.Pyq7QFNzjxFmt();
			base..ctor();
			lo8EVQ2D2 = int.Parse(((XmlNode)dependencyNode.Attributes[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(770)]).Value);
			KZdZPEOxu = Utilities.GetRuleType(((XmlNode)dependencyNode.Attributes[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(778)]).Value);
			MKwPcorc9 = Utilities.GetAccessType(((XmlNode)dependencyNode.Attributes[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(784)]).Value);
			nbHKRLMsC = Utilities.GetBlockType(((XmlNode)dependencyNode.Attributes[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(790)]).Value);
		}
	}
	public interface IImageParameter
	{
		string Id { get; }

		bool IsReadable { get; }

		int Status { get; }

		string Value { get; }

		IList<IImageParameterDependency> GetDependencies();
	}
	internal class ImageParameter : IImageParameter
	{
		protected static string GetDependenciesQuery;

		protected XmlNode _parameterNode;

		protected string _Id;

		protected bool _isReadable;

		protected int _status;

		protected string _value;

		protected List<IImageParameterDependency> _dependencies;

		public string Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _Id;
			}
		}

		public bool IsReadable
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _isReadable;
			}
		}

		public int Status
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _status;
			}
		}

		public virtual string Value
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ImageParameter(XmlNode parameterNode, bool isLegacy)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.Pyq7QFNzjxFmt();
			base..ctor();
			_parameterNode = parameterNode;
			_Id = ((XmlNode)parameterNode.Attributes[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(796)]).Value;
			_value = ((XmlNode)parameterNode.Attributes[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(804)]).Value;
			_status = int.Parse(((XmlNode)parameterNode.Attributes[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(810)]).Value);
			if (_status == 1)
			{
				_isReadable = true;
			}
			else
			{
				_isReadable = false;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IList<IImageParameterDependency> GetDependencies()
		{
			//IL_0046: Unknown result type (might be due to invalid IL or missing references)
			//IL_004c: Expected O, but got Unknown
			if (_dependencies == null)
			{
				_dependencies = new List<IImageParameterDependency>();
				XmlNodeList val = _parameterNode.SelectNodes(GetDependenciesQuery);
				if (val != null)
				{
					foreach (XmlNode item in val)
					{
						XmlNode dependencyNode = item;
						_dependencies.Add(new ImageParameterDependency(dependencyNode));
					}
				}
			}
			return _dependencies;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static ImageParameter()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.Pyq7QFNzjxFmt();
			GetDependenciesQuery = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(816);
		}
	}
	internal class ImageTisIdParameter : ImageParameter
	{
		public override string Value
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return _value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ImageTisIdParameter(XmlNode parameterNode, bool isLegacy)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.Pyq7QFNzjxFmt();
			base..ctor(parameterNode, isLegacy);
			_value = Utilities.GetDecodedTisIDs(_value);
		}
	}
	internal static class Utilities
	{
		[MethodImpl(MethodImplOptions.NoInlining)]
		public static RuleType GetRuleType(string imageRuleType)
		{
			RuleType result = RuleType.True;
			switch (int.Parse(imageRuleType))
			{
			case 0:
				result = RuleType.True;
				break;
			case 1:
				result = RuleType.False;
				break;
			case 2:
				result = RuleType.Lower;
				break;
			case 3:
				result = RuleType.Upper;
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static AccessType GetAccessType(string imageAccessType)
		{
			AccessType result = AccessType.Read;
			switch (int.Parse(imageAccessType))
			{
			case 0:
				result = AccessType.Read;
				break;
			case 1:
				result = AccessType.Write;
				break;
			case 2:
				result = AccessType.All;
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static BlockType GetBlockType(string imageBlockType)
		{
			BlockType result = BlockType.NotBlocking;
			switch (int.Parse(imageBlockType))
			{
			case 0:
				result = BlockType.NotBlocking;
				break;
			case 1:
				result = BlockType.Blocking;
				break;
			case 2:
				result = BlockType.Undetermined;
				break;
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public static string GetDecodedTisIDs(string encodedTisIDs)
		{
			string text = "";
			try
			{
				string text2 = Base64.Decode(encodedTisIDs);
				int i = 0;
				string text3 = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(830);
				for (; i < text2.Length; i += 2)
				{
					string text4 = Convert.ToInt32(text2[i]).ToString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(836));
					string text5 = Convert.ToInt32(text2[i + 1]).ToString(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(842));
					if (text4 == text3 && text5 == text3)
					{
						break;
					}
					if (text4.Length == 1)
					{
						text4 = text3 + text4;
					}
					if (text5.Length == 1)
					{
						text5 = text3 + text5;
					}
					int num = int.Parse(text5 + text4, NumberStyles.HexNumber);
					text = text + Convert.ToString(num) + eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(848);
				}
				if (text.Length > 1)
				{
					text = text.Remove(text.Length - 1);
				}
			}
			catch
			{
			}
			return text;
		}
	}
	public interface IImageArray
	{
		int Id { get; }

		int Dimension { get; }

		IList<IImageParameter> this[int dim, int row, int column = 0] { get; }

		int GetElementCount(int dimension, int IndexNum);
	}
	internal class ImageArray : IImageArray
	{
		private static string sLCQIHyJE;

		private static string XroJWTFK0;

		private static string ylE3TlR4K;

		private static string JlxyJvheR;

		private XmlNode xluucEEE4;

		private bool Op882skaP;

		private int MHSwbneYj;

		private int oPxfL47LE;

		public int Id
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return MHSwbneYj;
			}
		}

		public int Dimension
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return oPxfL47LE;
			}
		}

		public IList<IImageParameter> this[int dim, int row, int column = 0]
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				//IL_0084: Unknown result type (might be due to invalid IL or missing references)
				//IL_008a: Expected O, but got Unknown
				if (dim > Dimension)
				{
					throw new ArgumentOutOfRangeException();
				}
				string empty = string.Empty;
				empty = ((Dimension != 1) ? string.Format(XroJWTFK0, row, column) : string.Format(sLCQIHyJE, row));
				XmlNode val = xluucEEE4.SelectSingleNode(empty);
				List<IImageParameter> list = new List<IImageParameter>();
				foreach (XmlNode childNode in val.ChildNodes)
				{
					XmlNode parameterNode = childNode;
					ImageParameter item = new ImageParameter(parameterNode, Op882skaP);
					list.Add(item);
				}
				return list;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ImageArray(XmlNode arrayNode, bool isLegacy)
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.Pyq7QFNzjxFmt();
			base..ctor();
			if (arrayNode != null)
			{
				Op882skaP = isLegacy;
				xluucEEE4 = arrayNode;
				MHSwbneYj = int.Parse(((XmlNode)arrayNode.Attributes[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(854)]).Value);
				oPxfL47LE = int.Parse(((XmlNode)arrayNode.ChildNodes[0].Attributes[eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(862)]).Value);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int GetElementCount(int dimension, int IndexNum)
		{
			if (dimension > Dimension)
			{
				throw new ArgumentOutOfRangeException();
			}
			string empty = string.Empty;
			empty = ((dimension != 1) ? string.Format(JlxyJvheR, IndexNum) : ylE3TlR4K);
			XmlNodeList val = xluucEEE4.SelectNodes(empty);
			if (val != null)
			{
				return val.Count;
			}
			return 0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static ImageArray()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.Pyq7QFNzjxFmt();
			sLCQIHyJE = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(872);
			XroJWTFK0 = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(914);
			ylE3TlR4K = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(992);
			JlxyJvheR = eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1010);
		}
	}
}
namespace Cummins.INSITE.Kernel.Image
{
	internal static class ImageConstants
	{
		public const string Image = "Image";

		public const string CanWrite = "CanWrite";

		public const string ECUType = "ModType";

		public const string DetectType = "DetectType";

		public const string SystemType = "SysType";

		public const string ImageVersion = "ImageVersion";

		public const string CreationVersion = "CreationVersion";

		public const string AppliedRegionalSetting = "AppliedRgnSetting";

		public const string XmlNamespace = "xmlns:xsi";

		public const string XmlNamespaceValue = "http://www.w3.org/2001/XMLSchema-instance";

		public const string PCID = "PCID";

		public const string Parameters = "Parameters";

		public const string Parameter = "P";

		public const string Dependency = "Dep";

		public const string Id = "ID";

		public const string ReadStatus = "R";

		public const string WriteStatus = "W";

		public const string Value = "V";

		public const string Error = "ERROR";

		public const string RuleType = "R";

		public const string AccessType = "T";

		public const string BlockType = "B";

		public const string Arrays = "Arrays";

		public const string Array = "A";

		public const string Dimension = "Dim";

		public const string Index = "I";

		public const string Number = "Num";

		public const string Blocked = "B";

		public const string Name = "N";

		public const string Unit = "U";

		public const string DisplayValue = "DV";

		public const string LongUnit = "LU";

		public const string OtherDevices = "OtherDevices";

		public const string OtherDevice = "OtherDevice";

		public const string SourceAddress = "SourceAddress";

		public const string OBDLogs = "OBDLogs";

		public const string CVNLogs = "CalibrationVerificationNumber";

		public const string Usages = "Usages";

		public const string Usage = "U";

		public const string Maps = "MAPS";

		public const string Map = "MAP";

		public const string MapId = "mapID";

		public const string Features = "FEATURES";

		public const string Feature = "FEATURE";

		public const string FeatureId = "featureID";

		public const string SubFeatures = "SUBFEATURES";

		public const string SubFeature = "SUBFEATURE";

		public const string SubFeatureId = "subFeatureID";

		public const string MapParameters = "PARAMETERS";

		public const string MapParameter = "PARAMETER";

		public const string MapParameterId = "parameterID";

		public const string FeatureEnable = "featureEnable";

		public const string SubFeatureEnable = "subFeatureEnable";

		public const string Template = "Template";

		public const string TemplateVersion = "TemplateVersion";

		public const string GTISLocked = "GTISLocked";

		public const int NORMAL_ADJUSTABLE_PARAMETERS_USAGE = 3;

		public const int NORMAL_ADJUSTABLE_FEATURES_USAGE = 4;

		public const int NON_TEMPLATE_PARAMETERS_USAGE = 28;

		public const int OEM_PARAMETERS_USAGE = 23;

		public const int OEM2_PARAMETERS_USAGE = 34;

		public const int SafeToWriteToken = 2;
	}
}
internal class <Module>{A4BF3F6B-6003-4F10-9B94-2624E24A8373}
{
}
namespace eaNnw6oJwxIQQ7FE5G
{
	internal class eILexUWtydOj1ZbkDZ
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module e1WCAykK0;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void l9l7QFNN5tp0g(int typemdt)
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
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.Pyq7QFNzjxFmt();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static eILexUWtydOj1ZbkDZ()
		{
			eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.Pyq7QFNzjxFmt();
			e1WCAykK0 = typeof(eaNnw6oJwxIQQ7FE5G.eILexUWtydOj1ZbkDZ).Assembly.ManifestModule;
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
					eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.Pyq7QFNzjxFmt();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			public epk4JLxQrEvWi6AHPc(object P_0)
			{
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.Pyq7QFNzjxFmt();
				base..ctor();
			}
		}

		internal class eqCW27S8VxFfnK7ae3
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (e1WCAykK0(Convert.ToBase64String(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).Assembly.GetName().GetPublicKeyToken()), eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1084)) != eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1.eopWKtZX1(1090))
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
				eoP53YVgQa1lbB0Xy6.eGujxxQN0KjsXHehk2.Pyq7QFNzjxFmt();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint epLVT0LsDNCS2M0vSw([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr HskS6TqGUp7m9rQ3nx();

		internal struct eMo8xctuZSKRfJjCaO
		{
			internal bool e1WCAykK0;

			internal byte[] eopWKtZX1;
		}

		[Flags]
		private enum gy09nWS6qI6FvTOahS
		{

		}

		private static byte[] a8CGV6xv5;

		private static IntPtr KFQrF8Pls;

		private static int[] ENtTG49Ik;

		private static int Xe3D9rM43;

		internal static epLVT0LsDNCS2M0vSw eWbNGoLe6;

		private static int OsAU8jFrP;

		internal static epLVT0LsDNCS2M0vSw ebfRCcJMs;

		private static bool cxiMdkCia;

		private static long G08jVy32P;

		private static byte[] H20bYmaZU;

		private static SortedList ucOdY7VEC;

		private static IntPtr N88eAJpdr;

		private static bool TqEVEI81A;

		private static byte[] p8u2ixr6h;

		private static int Mktv1eK4Y;

		private static long rSoX7ZjGt;

		private static int mAUNsbsyT;

		internal static Hashtable e712GIHvk;

		private static object sXcIMnWih;

		private static IntPtr m6mWF2usj;

		private static byte[] MZ74Fekmc;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static emYpxP33xAq8jO8oJ1()
		{
			p8u2ixr6h = new byte[0];
			a8CGV6xv5 = new byte[0];
			H20bYmaZU = new byte[0];
			MZ74Fekmc = new byte[0];
			KFQrF8Pls = IntPtr.Zero;
			m6mWF2usj = IntPtr.Zero;
			sXcIMnWih = new string[0];
			ENtTG49Ik = new int[0];
			Mktv1eK4Y = 1;
			TqEVEI81A = false;
			ucOdY7VEC = new SortedList();
			Xe3D9rM43 = 0;
			G08jVy32P = 0L;
			ebfRCcJMs = null;
			eWbNGoLe6 = null;
			rSoX7ZjGt = 0L;
			mAUNsbsyT = 0;
			cxiMdkCia = false;
			OsAU8jFrP = 0;
			N88eAJpdr = IntPtr.Zero;
			e712GIHvk = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void ooo7QFNvu1IIW()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		static string eopWKtZX1(int P_0)
		{
			int num = 187;
			if (1 == 0)
			{
				goto IL_0016;
			}
			goto IL_0e86;
			IL_0016:
			byte[] array = default(byte[]);
			int num2 = default(int);
			array[0] = (byte)num2;
			int num3 = 90;
			goto IL_0e82;
			IL_0e82:
			num = num3;
			goto IL_0e86;
			IL_0e86:
			byte[] array2 = default(byte[]);
			int num7 = default(int);
			int num8 = default(int);
			int num6 = default(int);
			BinaryReader binaryReader = default(BinaryReader);
			byte[] array4 = default(byte[]);
			byte[] array5 = default(byte[]);
			MemoryStream memoryStream = default(MemoryStream);
			int num5 = default(int);
			CryptoStream cryptoStream = default(CryptoStream);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array6 = default(byte[]);
			ICryptoTransform transform = default(ICryptoTransform);
			byte[] array3 = default(byte[]);
			while (true)
			{
				IL_0e86_2:
				int num4 = num;
				while (true)
				{
					switch (num4)
					{
					case 172:
						break;
					case 102:
						goto IL_002e;
					case 329:
						goto IL_0051;
					case 164:
						array2[28] = (byte)num7;
						num4 = 78;
						continue;
					case 264:
						goto IL_0082;
					case 95:
						goto IL_00a4;
					case 193:
						array[0] = (byte)num8;
						num4 = 163;
						continue;
					case 71:
						num8 = 182 - 60;
						num4 = 197;
						continue;
					case 166:
						goto IL_00ed;
					case 108:
						goto IL_0106;
					case 152:
						array2[16] = 187;
						num = 24;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 37;
					case 37:
						array2 = new byte[32];
						num = 364;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 296;
					case 296:
						num2 = 236 - 78;
						num = 33;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 335;
					case 335:
						array2[1] = (byte)num6;
						num3 = 357;
						goto IL_0e82;
					case 222:
						array2[11] = (byte)num6;
						num3 = 106;
						goto IL_0e82;
					case 275:
						num2 = 98 + 14;
						num = 181;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 218;
					case 195:
						array2[27] = 95;
						num = 8;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 161;
					case 161:
						num7 = 78 + 87;
						num = 164;
						goto IL_0e86_2;
					case 257:
						num6 = 206 - 68;
						num4 = 362;
						continue;
					case 107:
						num7 = 63 + 50;
						num4 = 155;
						continue;
					case 169:
						array2[27] = (byte)num7;
						num = 342;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 344;
					case 0:
						array2[17] = 147;
						num4 = 32;
						continue;
					case 214:
						num6 = 123 + 46;
						num3 = 348;
						goto IL_0e82;
					case 206:
						num6 = 123 + 72;
						num3 = 202;
						goto IL_0e82;
					case 56:
						binaryReader = new BinaryReader((Stream)IZvOHTTQJnSDY3eKXi(BZ7gyyHnTLMWDPeSn5(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).TypeHandle).Assembly, "aOVetQMRaTFMRpREQj.t3H6SgY3Z5mEi0Bn65"));
						num3 = 147;
						goto IL_0e82;
					case 279:
						array[14] = (byte)num2;
						num3 = 360;
						goto IL_0e82;
					case 255:
						num8 = 9 + 60;
						num4 = 193;
						continue;
					case 190:
					case 347:
						array4[7] = array5[3];
						num = 175;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 36;
					case 63:
						array2[7] = 216;
						num3 = 116;
						goto IL_0e82;
					case 321:
						array2[0] = (byte)num7;
						num4 = 241;
						continue;
					case 23:
						array[15] = (byte)num8;
						num3 = 358;
						goto IL_0e82;
					case 90:
						array[0] = 18;
						num = 127;
						goto IL_0e86_2;
					case 83:
						num2 = 98 + 33;
						num3 = 172;
						goto IL_0e82;
					case 328:
						H20bYmaZU = (byte[])M55ymbiRAug1lVGVAi(memoryStream);
						num4 = 236;
						continue;
					case 223:
						num5 = rNyFooIKu5UjIlVVLU(H20bYmaZU, P_0);
						num4 = 366;
						continue;
					case 145:
						array[7] = 55;
						num3 = 29;
						goto IL_0e82;
					case 124:
						array2[10] = (byte)num6;
						num4 = 87;
						continue;
					case 213:
						num6 = 127 - 42;
						num = 196;
						goto IL_0e86_2;
					case 288:
						num2 = 99 + 6;
						num3 = 30;
						goto IL_0e82;
					case 336:
						array[10] = 187;
						num = 244;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 75;
					case 75:
						num6 = 35 + 97;
						num3 = 119;
						goto IL_0e82;
					case 59:
						num7 = 126 - 42;
						num4 = 207;
						continue;
					case 315:
						array2[4] = 68;
						num = 86;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 189;
					case 298:
						array2[31] = (byte)num7;
						num = 339;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 148;
					case 148:
						array[13] = 128;
						num = 132;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 353;
					case 353:
						num6 = 210 - 103;
						num4 = 142;
						continue;
					case 262:
						array2[4] = (byte)num7;
						num3 = 211;
						goto IL_0e82;
					case 73:
						array2[28] = 151;
						num4 = 18;
						continue;
					case 346:
						array2[5] = 116;
						num = 326;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 36;
					case 36:
						num7 = 61 + 114;
						num3 = 344;
						goto IL_0e82;
					case 55:
						num6 = 249 - 83;
						num = 41;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 215;
					case 215:
						array2[4] = (byte)num7;
						num3 = 354;
						goto IL_0e82;
					case 204:
						array2[29] = (byte)num7;
						num = 2;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 320;
					case 320:
						array[2] = (byte)num2;
						num = 141;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 119;
					case 119:
						array2[24] = (byte)num6;
						num = 258;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 129;
					case 129:
						array2[17] = (byte)num7;
						num4 = 329;
						continue;
					case 14:
						array[9] = (byte)num2;
						num4 = 173;
						continue;
					case 259:
						array[10] = 62;
						num = 336;
						goto IL_0e86_2;
					case 123:
						array[12] = (byte)num8;
						num = 44;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 325;
					case 325:
						array[13] = 62;
						num = 148;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 89;
					case 89:
						array[11] = 90;
						num3 = 99;
						goto IL_0e82;
					case 232:
						array2[3] = 104;
						num = 72;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 46;
					case 46:
						vNFY8YGBOdy843GR19(cryptoStream);
						num = 12;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 4;
					case 4:
						array[5] = (byte)num8;
						num3 = 318;
						goto IL_0e82;
					case 349:
						if (array5.Length > 0)
						{
							num = 149;
							if (0 == 0)
							{
								goto IL_0e86_2;
							}
							goto case 33;
						}
						goto case 263;
					case 33:
						array[4] = (byte)num2;
						num4 = 94;
						continue;
					case 80:
						array[11] = 126;
						num4 = 89;
						continue;
					case 221:
						array2[22] = (byte)num6;
						num3 = 327;
						goto IL_0e82;
					case 300:
						num6 = 165 - 55;
						num3 = 220;
						goto IL_0e82;
					case 186:
						array[6] = 98;
						num3 = 102;
						goto IL_0e82;
					case 217:
						num2 = 23 + 33;
						num = 276;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 201;
					case 201:
						array2[24] = (byte)num6;
						num = 359;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 178;
					case 178:
						num2 = 247 - 82;
						num4 = 194;
						continue;
					case 308:
						array2[16] = (byte)num6;
						num = 199;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 267;
					case 267:
						array[8] = 97;
						num3 = 316;
						goto IL_0e82;
					case 53:
						array2[18] = 170;
						num = 121;
						goto IL_0e86_2;
					case 358:
						num8 = 153 + 78;
						num3 = 84;
						goto IL_0e82;
					case 98:
						array4[5] = array5[2];
						goto case 190;
					case 147:
						M5nXyBpNoGel1Y2Gl8(yKiFWAP6FwlZAXWEKw(binaryReader), 0L);
						num = 61;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 345;
					case 345:
						array2[14] = (byte)num6;
						num3 = 305;
						goto IL_0e82;
					case 21:
						array[4] = (byte)num2;
						num4 = 296;
						continue;
					case 43:
						array2[7] = (byte)num6;
						num = 230;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 24;
					case 24:
						array2[16] = 114;
						num3 = 353;
						goto IL_0e82;
					case 269:
						num8 = 222 - 74;
						num4 = 103;
						continue;
					case 17:
						num6 = 25 + 111;
						num3 = 153;
						goto IL_0e82;
					case 180:
						num7 = 172 + 37;
						num = 215;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 240;
					case 240:
						num6 = 121 + 44;
						num = 246;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 305;
					case 305:
						num7 = 230 - 76;
						num3 = 179;
						goto IL_0e82;
					case 333:
						array2[9] = (byte)num7;
						num3 = 105;
						goto IL_0e82;
					case 88:
						num2 = 31 + 122;
						num = 136;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 6;
					case 6:
						num7 = 189 - 63;
						num = 298;
						goto IL_0e86_2;
					case 354:
						array2[5] = 89;
						num = 54;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 279;
					case 114:
						array2[14] = (byte)num6;
						num = 280;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 11;
					case 11:
						array2[2] = 140;
						num3 = 330;
						goto IL_0e82;
					case 210:
						array[6] = 41;
						num3 = 186;
						goto IL_0e82;
					case 224:
						array2[8] = (byte)num6;
						num = 203;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 330;
					case 330:
						array2[2] = 128;
						num = 96;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 127;
					case 127:
						num2 = 213 - 71;
						num4 = 58;
						continue;
					case 81:
						num6 = 118 + 122;
						num4 = 351;
						continue;
					case 126:
						array[6] = 112;
						num4 = 292;
						continue;
					case 103:
						array[9] = (byte)num8;
						num = 65;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 4;
					case 28:
						num6 = 234 - 78;
						num4 = 157;
						continue;
					case 196:
						array2[30] = (byte)num6;
						num3 = 205;
						goto IL_0e82;
					case 106:
						array2[11] = 205;
						num4 = 251;
						continue;
					case 54:
						array2[5] = 96;
						num3 = 352;
						goto IL_0e82;
					case 322:
						num6 = 136 - 24;
						num = 299;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 16;
					case 16:
						num6 = 231 - 77;
						num = 177;
						goto IL_0e86_2;
					case 313:
						num7 = 175 + 47;
						num = 129;
						goto IL_0e86_2;
					case 120:
						num6 = 159 - 53;
						num3 = 114;
						goto IL_0e82;
					case 199:
						array2[16] = 151;
						num4 = 152;
						continue;
					case 162:
						array2[0] = (byte)num6;
						num = 337;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 361;
					case 310:
						array2[15] = 105;
						num3 = 242;
						goto IL_0e82;
					case 132:
						array[14] = 117;
						num = 26;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 216;
					case 216:
						array2[18] = (byte)num7;
						num3 = 214;
						goto IL_0e82;
					case 82:
						array2[22] = (byte)num6;
						num = 322;
						goto IL_0e86_2;
					case 174:
						array2[10] = 179;
						num3 = 50;
						goto IL_0e82;
					case 175:
						array4[9] = array5[4];
						num3 = 268;
						goto IL_0e82;
					case 146:
						array2[7] = (byte)num6;
						num = 42;
						goto IL_0e86_2;
					case 171:
						num2 = 132 - 44;
						num = 237;
						goto IL_0e86_2;
					case 1:
						array[6] = 110;
						num = 126;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 252;
					case 252:
						array2[3] = (byte)num7;
						num = 315;
						goto IL_0e86_2;
					case 268:
						array4[11] = array5[5];
						num = 131;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 211;
					case 211:
						num6 = 161 - 53;
						num = 191;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 79;
					case 79:
						num6 = 134 - 44;
						num = 130;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 96;
					case 96:
						array2[3] = 121;
						num4 = 232;
						continue;
					case 93:
						array2[25] = 128;
						goto case 218;
					default:
						num = 218;
						goto IL_0e86_2;
					case 235:
						array2[21] = 106;
						num = 240;
						goto IL_0e86_2;
					case 360:
						array[14] = 132;
						num = 154;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 232;
					case 200:
						array2[10] = 102;
						num = 174;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 287;
					case 287:
						if (array5 != null)
						{
							num = 349;
							if (true)
							{
								goto IL_0e86_2;
							}
							goto case 31;
						}
						goto case 263;
					case 31:
						num6 = 166 - 110;
						num4 = 66;
						continue;
					case 271:
						array2[15] = 158;
						num = 97;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 230;
					case 230:
						num6 = 172 - 57;
						num3 = 146;
						goto IL_0e82;
					case 228:
						array2[5] = (byte)num6;
						num4 = 346;
						continue;
					case 265:
						num6 = 129 - 43;
						num3 = 302;
						goto IL_0e82;
					case 297:
						array2[30] = (byte)num7;
						num = 213;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 247;
					case 247:
						num6 = 13 + 80;
						num = 289;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 301;
					case 301:
						array[7] = 119;
						num = 145;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 47;
					case 47:
						array2[20] = (byte)num6;
						num3 = 188;
						goto IL_0e82;
					case 49:
						array4 = array;
						num = 113;
						goto IL_0e86_2;
					case 307:
						array = new byte[16];
						num = 83;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 280;
					case 280:
						array2[14] = 146;
						num3 = 20;
						goto IL_0e82;
					case 194:
						array[13] = (byte)num2;
						num4 = 57;
						continue;
					case 239:
						array2[8] = 104;
						num = 68;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 283;
					case 283:
						array2[26] = (byte)num6;
						num4 = 233;
						continue;
					case 10:
						array2[13] = 240;
						num4 = 249;
						continue;
					case 236:
						vNFY8YGBOdy843GR19(memoryStream);
						num = 46;
						goto IL_0e86_2;
					case 35:
						array2[16] = 133;
						num = 260;
						goto IL_0e86_2;
					case 128:
						array[10] = (byte)num2;
						num = 80;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 55;
					case 253:
						array[15] = (byte)num2;
						num3 = 122;
						goto IL_0e82;
					case 294:
						array2[30] = (byte)num7;
						num = 27;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 301;
					case 293:
						array2[24] = 220;
						num = 238;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 91;
					case 91:
						num2 = 42 + 76;
						num3 = 165;
						goto IL_0e82;
					case 142:
						array2[16] = (byte)num6;
						num3 = 0;
						goto IL_0e82;
					case 284:
						array2[24] = (byte)num7;
						num3 = 293;
						goto IL_0e82;
					case 177:
						array2[2] = (byte)num6;
						num = 11;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 261;
					case 261:
						array[7] = (byte)num8;
						num4 = 160;
						continue;
					case 179:
						array2[14] = (byte)num7;
						num = 120;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 314;
					case 314:
						num2 = 54 + 109;
						num3 = 253;
						goto IL_0e82;
					case 249:
						array2[14] = 166;
						_ = 1;
						if (T5dOsPdh33kwFn0lTy())
						{
							num = 190;
							if (sChhE4xw6NWK7uXkCs())
							{
								goto IL_0e86_2;
							}
							goto case 74;
						}
						num = 317;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 204;
					case 331:
						num2 = 182 - 120;
						num4 = 118;
						continue;
					case 276:
						array[1] = (byte)num2;
						num4 = 91;
						continue;
					case 343:
						array2[25] = 109;
						num = 93;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 362;
					case 165:
						array[1] = (byte)num2;
						num = 70;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 72;
					case 72:
						num7 = 37 + 17;
						num3 = 226;
						goto IL_0e82;
					case 117:
						SIV7C4o2kWnvnGbRD3(cryptoStream);
						num3 = 328;
						goto IL_0e82;
					case 84:
						array[15] = (byte)num8;
						num4 = 49;
						continue;
					case 250:
						num7 = 99 + 24;
						num3 = 312;
						goto IL_0e82;
					case 355:
						array[15] = 151;
						num3 = 314;
						goto IL_0e82;
					case 340:
						array2[21] = 142;
						num = 235;
						goto IL_0e86_2;
					case 361:
						array2[29] = (byte)num7;
						num4 = 248;
						continue;
					case 339:
						array2[31] = 105;
						num = 277;
						goto IL_0e86_2;
					case 332:
						num7 = 166 - 101;
						num4 = 256;
						continue;
					case 62:
						num7 = 4 + 57;
						num = 286;
						goto IL_0e86_2;
					case 86:
						array2[4] = 126;
						num4 = 62;
						continue;
					case 38:
						array2[23] = 111;
						num3 = 247;
						goto IL_0e82;
					case 260:
						num6 = 207 - 69;
						num3 = 308;
						goto IL_0e82;
					case 243:
						array[14] = (byte)num8;
						num = 9;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 304;
					case 304:
						array[5] = 122;
						num4 = 52;
						continue;
					case 334:
						num6 = 205 - 68;
						num = 335;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 106;
					case 356:
						array[8] = 227;
						num = 264;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 104;
					case 105:
						array2[10] = 12;
						num = 200;
						goto IL_0e86_2;
					case 5:
						num6 = 26 + 35;
						num = 43;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 61;
					case 61:
						SYbUsNqJVF8FaXZ5Dy(true);
						num = 278;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 139;
					case 254:
						num6 = 126 - 42;
						num = 162;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 91;
					case 51:
						array[9] = (byte)num2;
						num4 = 269;
						continue;
					case 303:
						array2[9] = 33;
						num3 = 166;
						goto IL_0e82;
					case 113:
						array5 = (byte[])g7M6k6FSyLm4owKKpG(T25OyXhKRDecMDHlEY(BZ7gyyHnTLMWDPeSn5(typeof(eIOTCwgtN7fvJXNYMS.emYpxP33xAq8jO8oJ1).TypeHandle).Assembly));
						num4 = 287;
						continue;
					case 118:
						array[3] = (byte)num2;
						num = 171;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 183;
					case 183:
						array2[13] = 160;
						num4 = 140;
						continue;
					case 77:
						array2[19] = 187;
						num4 = 7;
						continue;
					case 130:
						array2[28] = (byte)num6;
						num4 = 161;
						continue;
					case 229:
						num6 = 173 - 57;
						num4 = 309;
						continue;
					case 185:
						num7 = 194 - 112;
						num4 = 252;
						continue;
					case 184:
						array2[21] = 242;
						num4 = 266;
						continue;
					case 92:
						num7 = 114 + 65;
						num = 168;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 157;
					case 157:
						array2[31] = (byte)num6;
						num4 = 6;
						continue;
					case 110:
						num6 = 211 - 70;
						num = 222;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 151;
					case 151:
						array2[6] = 143;
						num = 17;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 348;
					case 348:
						array2[19] = (byte)num6;
						num = 257;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 112;
					case 112:
						array2[7] = (byte)num7;
						num = 63;
						goto IL_0e86_2;
					case 19:
						num6 = 10 + 67;
						num3 = 82;
						goto IL_0e82;
					case 220:
						array2[27] = (byte)num6;
						num3 = 74;
						goto IL_0e82;
					case 15:
						array[5] = (byte)num2;
						num3 = 1;
						goto IL_0e82;
					case 176:
						num7 = 142 - 47;
						num3 = 284;
						goto IL_0e82;
					case 39:
						array[11] = (byte)num8;
						num4 = 231;
						continue;
					case 143:
						num2 = 172 + 47;
						num = 128;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 198;
					case 198:
						array2[26] = 247;
						num3 = 300;
						goto IL_0e82;
					case 9:
						array[15] = 162;
						num = 355;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 245;
					case 245:
						num6 = 68 + 0;
						num = 139;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 177;
					case 153:
						array2[6] = (byte)num6;
						num = 36;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 149;
					case 149:
						array4[1] = array5[0];
						num = 319;
						goto IL_0e86_2;
					case 302:
						array2[20] = (byte)num6;
						num4 = 34;
						continue;
					case 29:
						num8 = 250 - 83;
						num = 261;
						goto IL_0e86_2;
					case 237:
						array[4] = (byte)num2;
						num3 = 275;
						goto IL_0e82;
					case 319:
						array4[3] = array5[1];
						num = 98;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 22;
					case 22:
						num6 = 3 + 110;
						num3 = 273;
						goto IL_0e82;
					case 68:
						num6 = 130 - 43;
						num = 224;
						goto IL_0e86_2;
					case 159:
						array2[27] = (byte)num7;
						num = 55;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 303;
					case 66:
						array2[5] = (byte)num6;
						num3 = 250;
						goto IL_0e82;
					case 25:
						num2 = 173 - 57;
						num = 320;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 78;
					case 78:
						num7 = 86 + 77;
						num4 = 361;
						continue;
					case 13:
						array2[23] = 96;
						num3 = 92;
						goto IL_0e82;
					case 99:
						num8 = 139 + 53;
						num3 = 39;
						goto IL_0e82;
					case 138:
						array[6] = (byte)num2;
						num3 = 144;
						goto IL_0e82;
					case 40:
						array2[18] = (byte)num7;
						num = 107;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 86;
					case 42:
						array2[7] = 124;
						num3 = 311;
						goto IL_0e82;
					case 50:
						num6 = 117 - 16;
						num = 124;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 48;
					case 48:
						array[13] = 88;
						num = 325;
						goto IL_0e86_2;
					case 154:
						num8 = 142 + 104;
						num = 243;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 285;
					case 285:
						num7 = 95 + 101;
						num = 204;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 7;
					case 7:
						num6 = 82 + 0;
						num3 = 324;
						goto IL_0e82;
					case 122:
						num8 = 19 + 68;
						num = 23;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 285;
					case 226:
						array2[3] = (byte)num7;
						num = 81;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 192;
					case 192:
						array[12] = (byte)num8;
						num4 = 178;
						continue;
					case 234:
						array2[30] = 154;
						num4 = 206;
						continue;
					case 136:
						array[3] = (byte)num2;
						num3 = 331;
						goto IL_0e82;
					case 8:
						array2[28] = 109;
						num = 245;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 323;
					case 359:
						array2[25] = 92;
						num = 343;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 197;
					case 197:
						array[3] = (byte)num8;
						num4 = 88;
						continue;
					case 87:
						array2[11] = 205;
						num3 = 110;
						goto IL_0e82;
					case 30:
						array[10] = (byte)num2;
						num4 = 143;
						continue;
					case 219:
						array2[21] = 214;
						num3 = 340;
						goto IL_0e82;
					case 277:
						array2[31] = 219;
						num = 341;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 289;
					case 289:
						array2[23] = (byte)num6;
						num = 109;
						goto IL_0e86_2;
					case 34:
						num6 = 39 + 10;
						num = 47;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 142;
					case 74:
						num7 = 213 - 71;
						num4 = 169;
						continue;
					case 133:
						array2[11] = (byte)num7;
						num3 = 274;
						goto IL_0e82;
					case 282:
						array[8] = (byte)num8;
						num = 76;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 241;
					case 241:
						array2[0] = 111;
						num4 = 254;
						continue;
					case 140:
						array2[13] = 90;
						num4 = 10;
						continue;
					case 60:
						num2 = 172 - 57;
						num4 = 21;
						continue;
					case 209:
						num8 = 192 - 64;
						num4 = 123;
						continue;
					case 150:
						array2[20] = (byte)num7;
						num4 = 219;
						continue;
					case 139:
						array2[28] = (byte)num6;
						num = 73;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 323;
					case 323:
						array2[12] = (byte)num7;
						num = 22;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 74;
					case 141:
						array[2] = 86;
						num4 = 100;
						continue;
					case 26:
						num2 = 18 + 99;
						num4 = 279;
						continue;
					case 156:
						array2[23] = 86;
						num4 = 13;
						continue;
					case 44:
						num8 = 115 - 108;
						num = 192;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 326;
					case 326:
						array2[5] = 101;
						num4 = 31;
						continue;
					case 327:
						array2[22] = 144;
						num = 19;
						goto IL_0e86_2;
					case 189:
						num7 = 128 - 42;
						num4 = 262;
						continue;
					case 121:
						num7 = 125 + 77;
						num = 216;
						goto IL_0e86_2;
					case 306:
						hFFnPyUmfwlRULxQNn(rijndaelManaged, CipherMode.CBC);
						num3 = 137;
						goto IL_0e82;
					case 246:
						array2[21] = (byte)num6;
						num = 184;
						goto IL_0e86_2;
					case 115:
						array2[20] = 121;
						num = 281;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 131;
					case 131:
						array4[13] = array5[6];
						num3 = 365;
						goto IL_0e82;
					case 225:
						num7 = 111 - 34;
						num = 333;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 155;
					case 155:
						array2[18] = (byte)num7;
						num4 = 53;
						continue;
					case 188:
						num7 = 145 + 107;
						num3 = 150;
						goto IL_0e82;
					case 248:
						array2[29] = 199;
						num4 = 285;
						continue;
					case 94:
						array[4] = 34;
						num = 304;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 163;
					case 163:
						array[0] = 195;
						num3 = 217;
						goto IL_0e82;
					case 167:
						num6 = 68 + 86;
						num3 = 283;
						goto IL_0e82;
					case 207:
						array2[1] = (byte)num7;
						num4 = 334;
						continue;
					case 65:
						num8 = 55 + 36;
						num3 = 64;
						goto IL_0e82;
					case 2:
						array2[29] = 152;
						num = 234;
						goto IL_0e86_2;
					case 32:
						array2[17] = 102;
						num = 313;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 18;
					case 18:
						array2[28] = 178;
						num4 = 79;
						continue;
					case 187:
						if (H20bYmaZU.Length == 0)
						{
							num4 = 56;
							continue;
						}
						goto case 223;
					case 111:
						array2[13] = 118;
						num = 183;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 58;
					case 58:
						array[0] = (byte)num2;
						num4 = 255;
						continue;
					case 324:
						array2[20] = (byte)num6;
						num3 = 115;
						goto IL_0e82;
					case 158:
						array2[30] = 168;
						num = 350;
						goto IL_0e86_2;
					case 208:
						array[2] = (byte)num8;
						num3 = 71;
						goto IL_0e82;
					case 203:
						array2[8] = 98;
						num = 303;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 170;
					case 170:
						num7 = 46 + 9;
						num = 321;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 5;
					case 309:
						array2[6] = (byte)num6;
						num = 151;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 247;
					case 233:
						array2[26] = 159;
						num3 = 198;
						goto IL_0e82;
					case 290:
						array[10] = 146;
						num = 288;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 337;
					case 337:
						array2[0] = 92;
						num = 332;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 292;
					case 292:
						num2 = 114 + 99;
						num4 = 138;
						continue;
					case 299:
						array2[22] = (byte)num6;
						num4 = 38;
						continue;
					case 67:
						g13VLYKB3i87Gol05s(cryptoStream, array6, 0, array6.Length);
						num = 117;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 270;
					case 270:
						array2[11] = (byte)num6;
						num3 = 338;
						goto IL_0e82;
					case 281:
						array2[20] = 111;
						num4 = 265;
						continue;
					case 57:
						array[13] = 146;
						num4 = 48;
						continue;
					case 3:
						array2[15] = 87;
						num4 = 310;
						continue;
					case 266:
						num6 = 228 - 76;
						num = 221;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 272;
					case 272:
						array[8] = (byte)num2;
						num4 = 212;
						continue;
					case 357:
						num6 = 191 - 110;
						num = 95;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 168;
					case 168:
						array2[23] = (byte)num7;
						num = 75;
						goto IL_0e86_2;
					case 20:
						array2[15] = 96;
						num3 = 3;
						goto IL_0e82;
					case 364:
						array2[0] = 118;
						num3 = 170;
						goto IL_0e82;
					case 116:
						array2[8] = 133;
						num = 239;
						goto IL_0e86_2;
					case 45:
						array2[25] = (byte)num7;
						num = 167;
						goto IL_0e86_2;
					case 27:
						num6 = 246 - 82;
						num = 85;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 286;
					case 286:
						array2[4] = (byte)num7;
						num3 = 189;
						goto IL_0e82;
					case 218:
						num7 = 189 + 40;
						num4 = 45;
						continue;
					case 316:
						array[8] = 91;
						num = 363;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 338;
					case 338:
						num7 = 45 + 19;
						num4 = 323;
						continue;
					case 295:
						array[9] = 138;
						num4 = 259;
						continue;
					case 291:
						num6 = 97 - 39;
						num = 270;
						goto IL_0e86_2;
					case 258:
						array2[24] = 129;
						num = 176;
						goto IL_0e86_2;
					case 351:
						array2[3] = (byte)num6;
						num4 = 185;
						continue;
					case 278:
						array6 = (byte[])dEIku1rA9pbsfpBqNS(binaryReader, (int)O2dS2lkeC4yxO03oBv(yKiFWAP6FwlZAXWEKw(binaryReader)));
						num3 = 37;
						goto IL_0e82;
					case 205:
						num7 = 194 + 50;
						num3 = 294;
						goto IL_0e82;
					case 363:
						num2 = 207 - 69;
						num4 = 272;
						continue;
					case 100:
						num8 = 80 - 21;
						num = 208;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 274;
					case 274:
						array2[11] = 101;
						num = 291;
						goto IL_0e86_2;
					case 125:
						cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
						num4 = 67;
						continue;
					case 273:
						array2[12] = (byte)num6;
						num = 108;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 161;
					case 231:
						num2 = 17 + 83;
						num3 = 69;
						goto IL_0e82;
					case 70:
						array[1] = 73;
						num = 25;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 52;
					case 52:
						num8 = 248 - 82;
						num = 4;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 173;
					case 173:
						num2 = 164 - 54;
						num = 51;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 137;
					case 137:
						transform = (ICryptoTransform)D942AheKpad5Hg43Qu(rijndaelManaged, array3, array4);
						num4 = 182;
						continue;
					case 365:
						array4[15] = array5[7];
						num = 263;
						if (sChhE4xw6NWK7uXkCs())
						{
							goto IL_0e86_2;
						}
						goto case 193;
					case 251:
						num7 = 166 - 55;
						num4 = 133;
						continue;
					case 12:
						juTQTPA7HG590y2QIA(binaryReader);
						num4 = 223;
						continue;
					case 76:
						array[8] = 110;
						num4 = 356;
						continue;
					case 312:
						array2[6] = (byte)num7;
						num3 = 229;
						goto IL_0e82;
					case 64:
						array[9] = (byte)num8;
						num4 = 295;
						continue;
					case 160:
						array[7] = 183;
						num = 267;
						goto IL_0e86_2;
					case 134:
						num6 = 227 + 0;
						num = 227;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 126;
					case 202:
						array2[30] = (byte)num6;
						num = 158;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 242;
					case 242:
						array2[15] = 98;
						num3 = 271;
						goto IL_0e82;
					case 256:
						array2[0] = (byte)num7;
						num = 59;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 41;
					case 41:
						array2[27] = (byte)num6;
						num = 195;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 97;
					case 97:
						array2[15] = 137;
						num = 35;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 135;
					case 135:
						array2[9] = (byte)num6;
						num4 = 225;
						continue;
					case 342:
						num7 = 197 - 65;
						num3 = 159;
						goto IL_0e82;
					case 144:
						array[6] = 104;
						num3 = 210;
						goto IL_0e82;
					case 350:
						num7 = 235 - 78;
						num = 297;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 181;
					case 181:
						array[4] = (byte)num2;
						num3 = 60;
						goto IL_0e82;
					case 104:
					case 317:
						num6 = 139 - 46;
						num4 = 345;
						continue;
					case 352:
						num6 = 249 - 83;
						num4 = 228;
						continue;
					case 318:
						num2 = 154 - 77;
						num = 15;
						goto IL_0e86_2;
					case 212:
						num8 = 141 - 47;
						num = 282;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 362;
					case 362:
						array2[19] = (byte)num6;
						num3 = 77;
						goto IL_0e82;
					case 311:
						num7 = 209 - 69;
						num = 112;
						goto IL_0e86_2;
					case 244:
						array[10] = 146;
						num4 = 290;
						continue;
					case 344:
						array2[7] = (byte)num7;
						num = 5;
						if (!T5dOsPdh33kwFn0lTy())
						{
							goto IL_0e86_2;
						}
						goto case 141;
					case 109:
						array2[23] = 149;
						num = 156;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 191;
					case 191:
						array2[4] = (byte)num6;
						num3 = 180;
						goto IL_0e82;
					case 69:
						array[12] = (byte)num2;
						num4 = 209;
						continue;
					case 85:
						array2[31] = (byte)num6;
						num = 101;
						if (0 == 0)
						{
							goto IL_0e86_2;
						}
						goto case 238;
					case 238:
						num6 = 3 - 3;
						num4 = 201;
						continue;
					case 227:
						array2[12] = (byte)num6;
						num4 = 111;
						continue;
					case 341:
						array3 = array2;
						num3 = 307;
						goto IL_0e82;
					case 101:
						array2[31] = 107;
						num4 = 28;
						continue;
					case 366:
						try
						{
							return (string)cG9cDk8CWRQGI3RJli(AhGB19QimuTtFjyd9A(), H20bYmaZU, P_0 + 4, num5);
						}
						catch
						{
						}
						return "";
					case 263:
						rijndaelManaged = new RijndaelManaged();
						num = 306;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 50;
					case 182:
						memoryStream = new MemoryStream();
						num = 125;
						if (true)
						{
							goto IL_0e86_2;
						}
						goto case 218;
					}
					break;
					IL_0106:
					array2[12] = 161;
					num3 = 134;
					goto IL_0e82;
					IL_00ed:
					num6 = 169 - 56;
					num3 = 135;
					goto IL_0e82;
					IL_0082:
					num2 = 213 - 71;
					num = 14;
					if (!T5dOsPdh33kwFn0lTy())
					{
						goto IL_0e86_2;
					}
					goto IL_00a4;
					IL_00a4:
					array2[1] = (byte)num6;
					num3 = 16;
					goto IL_0e82;
					IL_0051:
					num7 = 40 + 46;
					num3 = 40;
					goto IL_0e82;
					IL_002e:
					array[7] = 92;
					num = 301;
					goto IL_0e86_2;
				}
				break;
			}
			goto IL_0016;
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
		private static extern void zUCOcy5n9(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int cOkHV7Qab(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr eQ7GFE5Gm(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void OXpBhqE0c()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void LPdcu8o8d()
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
		private static extern int dQX1wVK0c(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int f6WgaHuHV(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int HreY9QfxV(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr XlpFVWtGv(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int ICKRqFux2(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[epk4JLxQrEvWi6AHPc(typeof(emYpxP33xAq8jO8oJ1/epk4JLxQrEvWi6AHPc/eUElArGanLR6DFu5tm<object>[]))]
		private static byte[] fdEiJqgM2(string P_0)
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
		private static byte[] oPosjxx65(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				57, 99, 66, 59, 238, 18, 68, 183, 49, 226,
				18, 195, 93, 52, 252, 68, 210, 163, 101, 24,
				147, 149, 183, 215, 40, 26, 171, 25, 108, 164,
				212, 151
			};
			rijndael.IV = new byte[16]
			{
				188, 159, 241, 120, 120, 27, 246, 183, 49, 159,
				225, 71, 199, 176, 72, 245
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] wZ10Qdk0m()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] cYftKPnnr()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] WZNo2ndf3()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] LqThIeN2v()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] IS5lxB16f()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] aBk6Bqwvm()
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
		internal static Type BZ7gyyHnTLMWDPeSn5(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object IZvOHTTQJnSDY3eKXi(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object yKiFWAP6FwlZAXWEKw(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void M5nXyBpNoGel1Y2Gl8(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void SYbUsNqJVF8FaXZ5Dy(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long O2dS2lkeC4yxO03oBv(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object dEIku1rA9pbsfpBqNS(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object T25OyXhKRDecMDHlEY(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object g7M6k6FSyLm4owKKpG(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void hFFnPyUmfwlRULxQNn(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object D942AheKpad5Hg43Qu(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void g13VLYKB3i87Gol05s(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void SIV7C4o2kWnvnGbRD3(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object M55ymbiRAug1lVGVAi(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void vNFY8YGBOdy843GR19(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void juTQTPA7HG590y2QIA(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int rNyFooIKu5UjIlVVLU(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object AhGB19QimuTtFjyd9A()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object cG9cDk8CWRQGI3RJli(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool sChhE4xw6NWK7uXkCs()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool T5dOsPdh33kwFn0lTy()
		{
			return false;
		}
	}
}
namespace eoP53YVgQa1lbB0Xy6
{
	internal class eGujxxQN0KjsXHehk2
	{
		private static bool sEPCx2BNf;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void Pyq7QFNzjxFmt()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public eGujxxQN0KjsXHehk2()
		{
		}
	}
}
