using System;
using System.Collections.Generic;
using System.Data.Common;
using System.Data.SqlClient;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Text;

[assembly: AssemblyConfiguration("")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyProduct("Cummins.IntegratedCalibrationDevelopment.ExtensionMethods")]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyTitle("Cummins.IntegratedCalibrationDevelopment.ExtensionMethods")]
[assembly: AssemblyDescription("This is string extension method helper class.")]
[assembly: ComVisible(false)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CLSCompliant(true)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2012")]
[assembly: Guid("911222ee-c6a3-4b79-8b92-98efd9c2be8b")]
[assembly: AssemblyFileVersion("1.0.0.4")]
[assembly: NeutralResourcesLanguage("en-US")]
[assembly: AssemblyVersion("1.0.0.4")]
namespace Cummins.IntegratedCalibrationDevelopment.ExtensionMethods;

public static class SqlDataReaderExtension
{
	public static IEnumerable<T> Select<T>(this SqlDataReader reader, Func<SqlDataReader, T> projection)
	{
		while (((DbDataReader)(object)reader).Read())
		{
			yield return projection(reader);
		}
	}
}
public static class StringExtension
{
	public static bool DoesNotStartWith(this string input, string pattern)
	{
		bool result = false;
		if (string.IsNullOrEmpty(pattern) || input.IsNullOrEmptyOrWhiteSpace() || !input.StartsWith(pattern, StringComparison.CurrentCulture))
		{
			result = true;
		}
		return result;
	}

	public static bool DoesNotEndWith(this string input, string pattern)
	{
		bool result = false;
		if (string.IsNullOrEmpty(pattern) || input.IsNullOrEmptyOrWhiteSpace() || !input.EndsWith(pattern, StringComparison.CurrentCulture))
		{
			result = true;
		}
		return result;
	}

	public static bool IsNullOrEmptyOrWhiteSpace(this string input)
	{
		bool result = false;
		if (string.IsNullOrEmpty(input) || string.Compare(input.Trim(), string.Empty, StringComparison.CurrentCulture) == 0)
		{
			result = true;
		}
		return result;
	}

	public static bool IsNotNullOrEmptyOrWhiteSpace(this string input)
	{
		return !input.IsNullOrEmptyOrWhiteSpace();
	}

	public static void ToLog(this string logMessage)
	{
		if (logMessage.IsNullOrEmptyOrWhiteSpace())
		{
			return;
		}
		try
		{
			using StreamWriter streamWriter = File.AppendText("ErrorLog.txt");
			streamWriter.WriteLine(string.Concat(DateTime.Now, " : ", logMessage));
		}
		catch
		{
		}
	}

	public static void ToLog(this Exception exception)
	{
		if (exception != null)
		{
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append("Exception Message : ");
			stringBuilder.Append(exception.Message);
			stringBuilder.Append("Exception StackTrace : ");
			stringBuilder.Append(exception.StackTrace);
			stringBuilder.Append("Exception Source : ");
			stringBuilder.Append(exception.Source);
			stringBuilder.ToString().ToLog();
		}
	}
}
public static class IEnumerableExtensions
{
	public static bool IsNullOrEmpty<TSource>(this IEnumerable<TSource> source)
	{
		bool result = false;
		if (source == null || source.Count() == 0)
		{
			result = true;
		}
		return result;
	}

	public static bool IsNotNullOrEmpty<TSource>(this IEnumerable<TSource> source)
	{
		return !source.IsNullOrEmpty();
	}
}
