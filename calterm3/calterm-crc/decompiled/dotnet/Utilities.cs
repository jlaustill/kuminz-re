using System.Diagnostics;
using System.Globalization;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.Versioning;
using System.Text;

[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyTitle("")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - Utilities")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.Utilities;

public class DataUtility
{
	public static string ByteArrayToString(byte[] bytes)
	{
		string text = string.Empty;
		for (int i = 0; i < bytes.Length; i++)
		{
			text += (char)bytes[i];
		}
		return text;
	}

	public static int ConverByteOrder(int littleAddress)
	{
		string littleEndianHexData = littleAddress.ToString("X8");
		string s = ConverByteOrder(littleEndianHexData);
		return int.Parse(s, NumberStyles.HexNumber, new CultureInfo("en-US"));
	}

	public static string ConverByteOrder(string littleEndianHexData)
	{
		StringBuilder stringBuilder = new StringBuilder(littleEndianHexData.Length);
		int num = littleEndianHexData.Length / 8;
		int num2 = littleEndianHexData.Length % 8;
		for (int i = 0; i < num; i++)
		{
			for (int num3 = 7; num3 > 0; num3 -= 2)
			{
				stringBuilder = stringBuilder.Append(littleEndianHexData[i * 8 + num3 - 1]);
				stringBuilder = stringBuilder.Append(littleEndianHexData[i * 8 + num3]);
			}
		}
		for (int num4 = num2 - 1; num4 > 0; num4 -= 2)
		{
			stringBuilder = stringBuilder.Append(littleEndianHexData[num * 8 + num4 - 1]);
			stringBuilder = stringBuilder.Append(littleEndianHexData[num * 8 + num4]);
		}
		return stringBuilder.ToString();
	}
}
public class ErrorHelper
{
	private const int ErrorSourceLength = 3;

	private const int ErrorCodeLength = 4;

	private const string ErrorCodeSeparator = "-";

	private static char CharZero = '0';

	public static string GetErrorCode(ErrorSources source, ushort errorCode)
	{
		int num = (int)source;
		return num.ToString().PadLeft(3, CharZero) + "-" + errorCode.ToString().PadLeft(4, CharZero);
	}
}
