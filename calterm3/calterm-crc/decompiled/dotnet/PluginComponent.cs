using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using System.Threading;
using Cummins.EventLog;
using Cummins.Services;
using Microsoft.CSharp;

[assembly: AssemblyDelaySign(false)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyTitle("")]
[assembly: AssemblyDescription("PluginComponent")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - PluginComponent")]
[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins;

internal interface iPluginLoader
{
	string LoadPlugin(string fileName);
}
internal class EngineeringPluginLoader : iPluginLoader
{
	private iPluginLoader[] _loaders = new iPluginLoader[2]
	{
		new EngineeringSecurePluginLoader(),
		new FieldEngineeringSecurePluginLoader()
	};

	public string LoadPlugin(string fileName)
	{
		string text = null;
		iPluginLoader[] loaders = _loaders;
		foreach (iPluginLoader iPluginLoader2 in loaders)
		{
			try
			{
				text = iPluginLoader2.LoadPlugin(fileName);
			}
			catch
			{
			}
		}
		if (string.IsNullOrEmpty(text))
		{
			throw new Exception("Could not load plugin: " + fileName);
		}
		return text;
	}
}
public interface iPluginEngine
{
	void Run(string fileName);

	void AddObject(string name, object obj);

	string[] GetErrors();
}
public class PluginEngineCSharp : iPluginEngine
{
	private const string SerialNumberHeader = "// Authorized Serial Numbers:";

	private const string EndDateHeader = "// Valid Through:";

	private const string EnableDebuggingHeader = "// Enable Debugging";

	private const string AdditionalAssembliesHeader = "// Additional Assemblies:";

	private iPluginLoader _pluginLoader;

	private CSharpCodeProvider _codeProvider;

	private CompilerParameters _compilerParameters;

	private CompilerResults _compilerResults;

	private string _assemblyName;

	private string _code;

	private string _fileName;

	private bool _enableDebugging;

	private Dictionary<string, object> _parameters = new Dictionary<string, object>();

	public PluginEngineCSharp()
	{
		//IL_0012: Unknown result type (might be due to invalid IL or missing references)
		//IL_001c: Expected O, but got Unknown
		_codeProvider = new CSharpCodeProvider();
		_pluginLoader = PluginLoaderFactory.GetLoader();
	}

	public void Run(string fileName)
	{
		EventLogger.Info("Plugin", "Beginning to run plugin: " + fileName);
		try
		{
			_code = _pluginLoader.LoadPlugin(fileName);
			_fileName = fileName;
			string[] additionalAssemblies = GetAdditionalAssemblies(_code);
			ValidateSerialNumber(_code);
			ValidateEndDate(_code);
			_enableDebugging = false;
			SetupCompiler(fileName, additionalAssemblies);
			Thread thread = new Thread(ThreadedRun);
			thread.Start();
		}
		catch (Exception ex)
		{
			string[] errors = GetErrors();
			if (errors != null)
			{
				string[] array = errors;
				foreach (string message in array)
				{
					EventLogger.Error("Plugin", message);
				}
			}
			else
			{
				EventLogger.Error("Plugin", ex.Message);
			}
		}
	}

	private void ValidateSerialNumber(string code)
	{
		string[] authorizedSerialNumbers = GetAuthorizedSerialNumbers(code);
		if (authorizedSerialNumbers == null)
		{
			return;
		}
		ISecurityService securityService = (ISecurityService)ServiceManager.Services.GetService(typeof(ISecurityService));
		if (securityService != null)
		{
			string text = securityService.SerialNumber.ToString();
			bool flag = false;
			string[] array = authorizedSerialNumbers;
			foreach (string text2 in array)
			{
				if (text2 == text)
				{
					flag = true;
				}
			}
			if (!flag)
			{
				throw new Exception("This installation of Calterm III is not authorized to run plugin: " + _fileName);
			}
			return;
		}
		throw new Exception("Missing security service!");
	}

	private string[] GetAuthorizedSerialNumbers(string code)
	{
		string[] result = null;
		int num = code.IndexOf("// Authorized Serial Numbers:");
		if (num != -1)
		{
			string text = code.Substring(num + "// Authorized Serial Numbers:".Length);
			num = text.IndexOf('\n');
			if (num != -1)
			{
				text = text.Substring(0, num).Trim();
			}
			result = text.Split(new char[1] { ',' });
		}
		return result;
	}

	private void ValidateEndDate(string code)
	{
		string endDate = GetEndDate(code);
		if (!string.IsNullOrEmpty(endDate))
		{
			DateTime endDate2 = DateTime.Parse(endDate);
			if (!CheckEndDate(endDate2))
			{
				throw new Exception("Plugin: " + _fileName + " has expired.");
			}
		}
	}

	private bool CheckEndDate(DateTime endDate)
	{
		bool result = false;
		DateTime now = DateTime.Now;
		if (now.Year <= endDate.Year && now.DayOfYear <= endDate.DayOfYear)
		{
			result = true;
		}
		return result;
	}

	private string GetEndDate(string code)
	{
		string result = null;
		int num = code.IndexOf("// Valid Through:");
		if (num != -1)
		{
			result = code.Substring(num + "// Valid Through:".Length);
			num = result.IndexOf("\n");
			if (num != -1)
			{
				result = result.Substring(0, num);
			}
			result = result.Trim();
		}
		return result;
	}

	private bool EnableDebugging(string code)
	{
		int num = code.IndexOf("// Enable Debugging");
		return num != -1;
	}

	private string[] GetAdditionalAssemblies(string code)
	{
		string[] result = null;
		int num = code.IndexOf("// Additional Assemblies:");
		if (num != -1)
		{
			string text = code.Substring(num + "// Additional Assemblies:".Length);
			num = text.IndexOf('\n');
			if (num != -1)
			{
				text = text.Substring(0, num).Trim();
			}
			result = ParseList(text);
		}
		return result;
	}

	private string[] ParseList(string assemblyList)
	{
		string[] array = assemblyList.Split(new char[1] { ',' });
		for (int i = 0; i < array.Length; i++)
		{
			array[i] = Environment.ExpandEnvironmentVariables(array[i]);
		}
		return array;
	}

	private void SetupCompiler(string name, string[] additionalAssemblies)
	{
		//IL_00cc: Unknown result type (might be due to invalid IL or missing references)
		//IL_00d6: Expected O, but got Unknown
		string[] array = new string[13]
		{
			"System.dll", "System.Windows.Forms.dll", "System.Drawing.dll", "CaltermApplication.dll", "CRCUtility.dll", "DataSource.dll", "Editor.dll", "Interfaces.dll", "Services.dll", "Interop.CalDataServer.dll",
			"Widgets.dll", "IDLLogger.dll", "MessageDialog.dll"
		};
		string executingDirectory = GetExecutingDirectory();
		Directory.SetCurrentDirectory(executingDirectory);
		if (additionalAssemblies != null && additionalAssemblies.Length > 0)
		{
			int num = array.Length;
			Array.Resize(ref array, num + additionalAssemblies.Length);
			Array.Copy(additionalAssemblies, 0, array, num, additionalAssemblies.Length);
		}
		_assemblyName = FigureAssemblyName(name);
		_compilerParameters = new CompilerParameters(array, _assemblyName);
		_compilerParameters.GenerateExecutable = false;
		if (_enableDebugging)
		{
			_compilerParameters.GenerateInMemory = false;
			_compilerParameters.IncludeDebugInformation = true;
		}
		else
		{
			_compilerParameters.GenerateInMemory = true;
			_compilerParameters.IncludeDebugInformation = false;
		}
		string text = RuntimeEnvironment.GetRuntimeDirectory() + "\\WPF";
		if (Directory.Exists(text))
		{
			_compilerParameters.CompilerOptions = "/lib:" + text;
		}
	}

	private string GetExecutingDirectory()
	{
		string codeBase = Assembly.GetExecutingAssembly().CodeBase;
		codeBase = codeBase.Substring(8);
		return Path.GetDirectoryName(codeBase);
	}

	private string FigureAssemblyName(string name)
	{
		string fileNameWithoutExtension = Path.GetFileNameWithoutExtension(name);
		string text = fileNameWithoutExtension + ".dll";
		bool flag = false;
		int num = 0;
		while (!flag)
		{
			num++;
			if (File.Exists(text))
			{
				text = fileNameWithoutExtension + "_" + num + ".dll";
			}
			else
			{
				flag = true;
			}
		}
		return text;
	}

	private void ThreadedRun()
	{
		CompilerResults val = Compile(_code);
		ClearTempFiles();
		if (!HasErrors(val))
		{
			Assembly compiledAssembly = val.CompiledAssembly;
			BindingFlags bindingAttr = BindingFlags.DeclaredOnly | BindingFlags.Instance | BindingFlags.Static | BindingFlags.Public | BindingFlags.NonPublic;
			Module[] modules = compiledAssembly.GetModules();
			Module[] array = modules;
			foreach (Module module in array)
			{
				if (module.ScopeName == _assemblyName)
				{
					Type[] types = module.GetTypes();
					Type[] array2 = types;
					foreach (Type type in array2)
					{
						if (!(type.Name == "Program"))
						{
							continue;
						}
						MethodInfo[] methods = type.GetMethods(bindingAttr);
						MethodInfo[] array3 = methods;
						foreach (MethodInfo methodInfo in array3)
						{
							if (methodInfo.Name == "PluginStart")
							{
								try
								{
									object obj = Activator.CreateInstance(type);
									methodInfo.Invoke(obj, new object[1] { _parameters });
								}
								catch (Exception ex)
								{
									string message = ((ex.InnerException == null) ? ex.Message : ex.InnerException.Message);
									EventLogger.Error("Plugin Error", message);
								}
							}
						}
					}
				}
				else
				{
					EventLogger.Error("Plugin", "Could not find module: " + _assemblyName);
				}
			}
		}
		else
		{
			string empty = string.Empty;
			for (int l = 0; l < ((CollectionBase)(object)val.Errors).Count; l++)
			{
				empty = l + 1 + ": " + ((object)val.Errors[l]).ToString();
				EventLogger.Error("Plugin", empty);
			}
		}
		EventLogger.Info("Plugin", "Plugin completed");
	}

	private void ClearTempFiles()
	{
		try
		{
			if (!_enableDebugging && File.Exists(_assemblyName))
			{
				File.Delete(_assemblyName);
			}
		}
		catch
		{
		}
	}

	private bool HasErrors(CompilerResults compilerResults)
	{
		bool result = false;
		for (int i = 0; i < ((CollectionBase)(object)compilerResults.Errors).Count; i++)
		{
			if (!compilerResults.Errors[i].IsWarning)
			{
				result = true;
				break;
			}
		}
		return result;
	}

	public void AddObject(string name, object obj)
	{
		_parameters[name] = obj;
	}

	public string[] GetErrors()
	{
		//IL_003b: Unknown result type (might be due to invalid IL or missing references)
		//IL_0041: Expected O, but got Unknown
		string[] array = null;
		if (_compilerResults != null)
		{
			int num = 0;
			array = new string[((CollectionBase)(object)_compilerResults.Errors).Count];
			foreach (CompilerError item in (CollectionBase)(object)_compilerResults.Errors)
			{
				CompilerError val = item;
				array[num] = ((object)val).ToString();
				num++;
			}
		}
		return array;
	}

	private CompilerResults Compile(string code)
	{
		if (_enableDebugging)
		{
			return ((CodeDomProvider)_codeProvider).CompileAssemblyFromFile(_compilerParameters, new string[1] { _fileName });
		}
		return ((CodeDomProvider)_codeProvider).CompileAssemblyFromSource(_compilerParameters, new string[1] { code });
	}
}
public enum PluginType
{
	CSharp
}
public class PluginEngineFactory
{
	public static iPluginEngine CreatePluginEngine(PluginType type)
	{
		iPluginEngine result = null;
		if (type == PluginType.CSharp)
		{
			result = new PluginEngineCSharp();
		}
		return result;
	}
}
internal class PluginLoaderFactory
{
	public static iPluginLoader GetLoader()
	{
		ISecurityService securityService = (ISecurityService)ServiceManager.Services.GetService(typeof(ISecurityService));
		iPluginLoader iPluginLoader2 = null;
		return securityService.ToolFamily switch
		{
			ToolFamily.Engineering => new EngineeringPluginLoader(), 
			_ => new FieldEngineeringSecurePluginLoader(), 
		};
	}
}
internal class SecurePluginLoader : iPluginLoader
{
	public string LoadPlugin(string fileName)
	{
		return DecryptFile(fileName);
	}

	private byte[] SubArray(byte[] data, int start, int length)
	{
		byte[] array = new byte[length];
		Array.Copy(data, start, array, 0, length);
		return array;
	}

	protected virtual byte[] GetKeys()
	{
		throw new Exception("SecureScriptLoader.GetKeys() called");
	}

	private string DecryptFile(string fileName)
	{
		byte[] array3;
		byte[] array4;
		RSACryptoServiceProvider rSACryptoServiceProvider;
		try
		{
			byte[] buffer = ReadFile(fileName);
			MemoryStream memoryStream = new MemoryStream(buffer);
			Rijndael rijndael = Rijndael.Create();
			byte[] keys = GetKeys();
			rijndael.Key = SubArray(keys, 0, 32);
			rijndael.IV = SubArray(keys, 32, 16);
			rijndael.Padding = PaddingMode.ISO10126;
			CryptoStream input = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Read);
			BinaryReader binaryReader = new BinaryReader(input);
			byte[] array = new byte[memoryStream.Length];
			int num = binaryReader.Read(array, 0, (int)memoryStream.Length);
			byte[] array2 = new byte[num];
			Array.Copy(array, array2, num);
			array3 = new byte[64];
			array4 = new byte[array2.Length - 64];
			Array.Copy(array2, array3, 64);
			Array.Copy(array2, 64, array4, 0, array4.Length);
			rSACryptoServiceProvider = new RSACryptoServiceProvider(512);
			rSACryptoServiceProvider.FromXmlString(GetPublicKey());
		}
		catch (Exception innerException)
		{
			throw new Exception("Plugin file corrupted. Please contact Calterm III tech support.", innerException);
		}
		if (rSACryptoServiceProvider.VerifyData(array4, new SHA1CryptoServiceProvider(), array3))
		{
			Encoding aSCII = Encoding.ASCII;
			return aSCII.GetString(array4);
		}
		throw new Exception("This Calterm III license is not authorized to use this plugin.");
	}

	protected virtual string GetPublicKey()
	{
		throw new Exception("SecureScriptLoader.GetPublicKey() called");
	}

	private byte[] ReadFile(string fileName)
	{
		FileStream fileStream = new FileStream(fileName, FileMode.Open, FileAccess.Read);
		BinaryReader binaryReader = new BinaryReader(fileStream);
		long length = fileStream.Length;
		byte[] array = new byte[length];
		long num = 0L;
		for (int num2 = 1024; num < length; num += num2)
		{
			num2 = (int)((length - num < num2) ? (length - num) : num2);
			byte[] sourceArray = binaryReader.ReadBytes(num2);
			Array.Copy(sourceArray, 0L, array, num, num2);
		}
		binaryReader.Close();
		fileStream.Close();
		return array;
	}
}
internal class FieldEngineeringSecurePluginLoader : SecurePluginLoader
{
	protected override byte[] GetKeys()
	{
		byte[] array = new byte[192]
		{
			44, 184, 55, 157, 24, 138, 68, 49, 244, 20,
			195, 170, 25, 100, 46, 2, 150, 82, 120, 209,
			214, 38, 209, 7, 63, 210, 112, 74, 62, 7,
			172, 18, 119, 45, 102, 254, 76, 176, 239, 232,
			203, 40, 244, 89, 117, 138, 105, 47, 153, 133,
			245, 254, 31, 144, 221, 22, 209, 114, 30, 131,
			196, 225, 200, 136, 41, 107, 244, 10, 36, 247,
			121, 100, 185, 45, 193, 205, 76, 170, 60, 30,
			198, 173, 196, 92, 249, 76, 153, 145, 60, 56,
			60, 219, 42, 237, 104, 167, 55, 7, 209, 31,
			66, 145, 250, 51, 32, 131, 100, 76, 75, 18,
			156, 251, 212, 69, 93, 193, 3, 123, 78, 114,
			106, 244, 44, 72, 187, 28, 240, 241, 123, 56,
			112, 4, 203, 121, 227, 201, 224, 74, 136, 33,
			5, 140, 218, 192, 22, 251, 194, 209, 29, 37,
			89, 34, 94, 154, 153, 44, 184, 208, 123, 16,
			238, 179, 138, 57, 187, 96, 9, 70, 147, 49,
			75, 181, 187, 206, 174, 117, 173, 105, 62, 56,
			195, 69, 193, 79, 212, 20, 129, 21, 151, 155,
			238, 154
		};
		int[] array2 = new int[48]
		{
			106, 92, 30, 32, 72, 114, 111, 57, 191, 120,
			66, 141, 144, 119, 145, 139, 166, 77, 21, 149,
			56, 118, 189, 86, 187, 83, 74, 126, 188, 183,
			63, 131, 109, 15, 122, 87, 152, 184, 38, 102,
			36, 98, 133, 69, 39, 49, 50, 165
		};
		int num = array.Length / 4;
		byte[] array3 = new byte[num];
		for (int i = 0; i < num; i++)
		{
			int num2 = array2[i];
			array3[i] = array[num2];
		}
		return array3;
	}

	protected override string GetPublicKey()
	{
		return "<RSAKeyValue><Modulus>xPF5h18HUSbz4zl1P+GLLm3jYKy17uUA9B0HjDBph/jR6N8GXAZU5Wzmwngbvwt2rbYeJvdhtMzXtOQK2rynrQ==</Modulus><Exponent>AQAB</Exponent></RSAKeyValue>";
	}
}
internal class EngineeringSecurePluginLoader : SecurePluginLoader
{
	protected override byte[] GetKeys()
	{
		byte[] array = new byte[192]
		{
			44, 184, 55, 157, 24, 138, 68, 49, 244, 20,
			195, 170, 25, 100, 46, 2, 150, 82, 120, 209,
			214, 38, 209, 7, 63, 210, 112, 74, 62, 7,
			172, 18, 119, 45, 102, 254, 76, 176, 239, 232,
			203, 40, 244, 89, 117, 138, 105, 47, 153, 133,
			245, 254, 31, 144, 221, 22, 209, 114, 30, 131,
			196, 225, 200, 136, 41, 107, 244, 10, 36, 247,
			121, 100, 185, 45, 193, 205, 76, 170, 60, 30,
			198, 173, 196, 92, 249, 76, 153, 145, 60, 56,
			60, 219, 42, 237, 104, 167, 55, 7, 209, 31,
			66, 145, 250, 51, 32, 131, 100, 76, 75, 18,
			156, 251, 212, 69, 93, 193, 3, 123, 78, 114,
			106, 244, 44, 72, 187, 28, 240, 241, 123, 56,
			112, 4, 203, 121, 227, 201, 224, 74, 136, 33,
			5, 140, 218, 192, 22, 251, 194, 209, 29, 37,
			89, 34, 94, 154, 153, 44, 184, 208, 123, 16,
			238, 179, 138, 57, 187, 96, 9, 70, 147, 49,
			75, 181, 187, 206, 174, 117, 173, 105, 62, 56,
			195, 69, 193, 79, 212, 20, 129, 21, 151, 155,
			238, 154
		};
		int[] array2 = new int[48]
		{
			106, 92, 30, 32, 72, 114, 111, 57, 191, 120,
			66, 141, 144, 119, 145, 139, 166, 77, 21, 149,
			56, 118, 189, 86, 187, 83, 74, 126, 188, 183,
			63, 131, 109, 15, 122, 87, 152, 184, 38, 102,
			36, 98, 133, 69, 39, 49, 50, 165
		};
		int num = array.Length / 4;
		byte[] array3 = new byte[num];
		for (int i = 0; i < num; i++)
		{
			int num2 = array2[i];
			array3[i] = array[num2];
		}
		return array3;
	}

	protected override string GetPublicKey()
	{
		return "<RSAKeyValue><Modulus>ricZilffXrxHDUYMBwZR9Q98nWX5vALQyQ+aEEmL/VZujaWmZzf2RETBgQJcSX/fuSN/0gS7Ky3fy34rEDRgjQ==</Modulus><Exponent>AQAB</Exponent></RSAKeyValue>";
	}
}
internal class SimplePluginLoader : iPluginLoader
{
	public string LoadPlugin(string fileName)
	{
		TextReader textReader = new StreamReader(fileName);
		string result = textReader.ReadToEnd();
		textReader.Close();
		return result;
	}
}
