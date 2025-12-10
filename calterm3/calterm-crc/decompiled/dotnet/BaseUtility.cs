using System;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.Versioning;
using Cummins;
using Cummins.Services;

[assembly: AssemblyTitle("Poodle")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - Base Utility")]
[assembly: AssemblyDelaySign(false)]
[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace BaseUtility;

public class FileVersion
{
	public enum GtisVersion
	{
		GTIS45File,
		GTIS38File,
		GTIS20File,
		Other
	}

	public string GetFileVersion(string fileName)
	{
		DataSourceFileType fileType = Utility.GetFileType(fileName);
		string text = fileType.ToString();
		if (text.IndexOf("45") != -1)
		{
			return GtisVersion.GTIS45File.ToString();
		}
		if (text.IndexOf("38") != -1)
		{
			return GtisVersion.GTIS38File.ToString();
		}
		if (text.IndexOf("20") != -1)
		{
			return GtisVersion.GTIS20File.ToString();
		}
		return GtisVersion.Other.ToString();
	}
}
public class SubfileInfo
{
	private SubfileType subfileType;

	public SubfileType GetSubFileType(string subFileName)
	{
		byte b = 0;
		try
		{
			int startIndex = 4;
			int length = 2;
			TextReader textReader = new StreamReader(subFileName);
			string text = textReader.ReadLine();
			if (text[0] != '*' || text[1] != 'C')
			{
				text = textReader.ReadLine();
			}
			textReader.Close();
			switch (byte.Parse(text.Substring(startIndex, length), NumberStyles.AllowHexSpecifier).ToString())
			{
			case "1":
				subfileType = SubfileType.One;
				break;
			case "2":
				subfileType = SubfileType.Two;
				break;
			case "3":
				subfileType = SubfileType.Three;
				break;
			case "4":
				subfileType = SubfileType.Four;
				break;
			case "5":
				subfileType = SubfileType.Five;
				break;
			case "6":
				subfileType = SubfileType.Six;
				break;
			case "7":
				subfileType = SubfileType.Seven;
				break;
			case "8":
				subfileType = SubfileType.Eight;
				break;
			default:
				subfileType = SubfileType.None;
				break;
			}
		}
		catch
		{
			subfileType = SubfileType.None;
		}
		return subfileType;
	}
}
public enum SubfileType
{
	None,
	One,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight
}
public class SubfileTypeMismatchException : ApplicationException
{
	public SubfileTypeMismatchException(string errorDescription)
		: base(errorDescription)
	{
	}
}
public class CodeSubfileTypeException : ApplicationException
{
	public CodeSubfileTypeException(string errorDescription)
		: base(errorDescription)
	{
	}
}
