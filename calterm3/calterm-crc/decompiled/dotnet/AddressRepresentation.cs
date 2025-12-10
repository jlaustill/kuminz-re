using System;
using System.Collections;
using System.Diagnostics;
using System.Globalization;
using System.Net;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.Versioning;

[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyTitle("")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.AddressRepresentation;

public class AddressFactory
{
	public static IAddressValue ProductAddressValue(string address)
	{
		if (address.StartsWith("ConfigurationFile : "))
		{
			return new DiskAddressValue(address);
		}
		if (address.StartsWith("R"))
		{
			return IPAddressValue.LookupAddresId(address);
		}
		if (address.Length > 8)
		{
			return new IPAddressValue(address, 0);
		}
		return new AddressValue(address);
	}

	public static IAddressValue ProductAddressValue(ushort address)
	{
		return new AddressValue(((byte)address).ToString("X2"));
	}
}
public class AddressValue : IAddressValue, IComparable
{
	private byte deviceAddress;

	public virtual string Value => deviceAddress.ToString("X2");

	public virtual string DisplayId => Value;

	public virtual AddressType Type => AddressType.ECM;

	public virtual byte DeviceAddress
	{
		get
		{
			return deviceAddress;
		}
		set
		{
			deviceAddress = value;
		}
	}

	protected AddressValue()
	{
	}

	public AddressValue(byte deviceAddress)
	{
		this.deviceAddress = deviceAddress;
	}

	public AddressValue(string deviceAddressString)
	{
		SetDeviceAddressFromString(deviceAddressString);
	}

	public override string ToString()
	{
		return "0x" + Value;
	}

	public int CompareTo(object obj)
	{
		return Value.CompareTo((obj as IAddressValue).Value);
	}

	public byte SetDeviceAddressFromString(string deviceAddressString)
	{
		try
		{
			if (deviceAddressString.ToLower().StartsWith("0x"))
			{
				deviceAddressString = deviceAddressString.Substring(2);
			}
			DeviceAddress = byte.Parse(deviceAddressString, NumberStyles.AllowHexSpecifier);
			return deviceAddress;
		}
		catch
		{
			string message = "Invalid ECM device address '" + deviceAddressString + "'.";
			throw new InvalidDeviceAddressException(AddressRepresentationMessageId.InvalidECMDeviceAddress, message);
		}
	}
}
public class IPAddressValue : AddressValue, IAddressValue, IComparable
{
	private string ipAddress;

	private int port;

	private string displayId;

	private static Hashtable staticAddressIdList = new Hashtable();

	private static Hashtable staticAddressList = new Hashtable();

	private static int staticNextId = 0;

	public override string Value => string.Format("{0}:{1}:{2}", ipAddress, port, DeviceAddress.ToString("X2"));

	public override string DisplayId
	{
		get
		{
			if (displayId == null)
			{
				if (staticAddressIdList.ContainsKey(Value))
				{
					displayId = (string)staticAddressIdList[Value];
				}
				else
				{
					displayId = "R" + staticNextId;
					staticNextId++;
					staticAddressIdList.Add(Value, displayId);
					staticAddressList.Add(displayId, this);
				}
			}
			return displayId;
		}
	}

	public override AddressType Type => AddressType.ASAM;

	public string IPAddress => ipAddress;

	public int Port => port;

	public static IPAddressValue LookupAddresId(string displayId)
	{
		if (displayId.IndexOf("-") > -1)
		{
			displayId = displayId.Substring(0, displayId.IndexOf("-"));
		}
		if (staticAddressList.ContainsKey(displayId))
		{
			return (IPAddressValue)staticAddressList[displayId];
		}
		string message = "Remote Device Id '" + displayId + "' not found in list of valid Ids.";
		throw new InvalidDeviceAddressException(AddressRepresentationMessageId.InvalidIPAddress, message);
	}

	public IPAddressValue(string address, byte deviceAddress)
		: base(deviceAddress)
	{
		try
		{
			string[] array = address.Split(new char[1] { ':' });
			ipAddress = array[0];
			port = int.Parse(array[1]);
			if (array.Length == 3)
			{
				SetDeviceAddressFromString(array[2]);
			}
			System.Net.IPAddress.Parse(ipAddress);
		}
		catch
		{
			string message = "Badly formatted TCP/IP address. Expecting format: '{A.B.C.D}:{Port#}' (decimals).";
			throw new InvalidDeviceAddressException(AddressRepresentationMessageId.BadlyFormattedTCPIPAddress, message);
		}
	}

	public override string ToString()
	{
		return Value;
	}
}
public class DiskAddressValue : AddressValue, IAddressValue, IComparable
{
	private const string ConfigurationFileTab = "ConfigurationFile :";

	private const string DataSourceFileTab = "DataSourceFile :";

	private const string DiskAddressValueFormat = "ConfigurationFile : {0} DataSourceFile : {1}";

	private const string DataSourceNotProvided = "None";

	private string addressValue = string.Empty;

	public override AddressType Type => AddressType.DISK;

	public override string DisplayId => addressValue;

	public override string Value => addressValue;

	public DiskAddressValue()
		: this("None", "None")
	{
	}

	public DiskAddressValue(string addressValue)
	{
		this.addressValue = addressValue;
	}

	public DiskAddressValue(string configFileName, string dataSourceFileName)
	{
		addressValue = $"ConfigurationFile : {configFileName} DataSourceFile : {dataSourceFileName}";
	}

	public override string ToString()
	{
		return Value;
	}
}
public enum AddressRepresentationMessageId
{
	InvalidIPAddress,
	BadlyFormattedTCPIPAddress,
	InvalidECMDeviceAddress,
	InvalidDiskAddress
}
public class AddressException : BaseException
{
	public AddressException()
		: base(Facility.AssemblyInvoker, 0)
	{
	}

	public AddressException(AddressRepresentationMessageId errorID, string message)
		: base(Facility.AssemblyInvoker, (short)errorID, message)
	{
	}

	public AddressException(AddressRepresentationMessageId errorID, string message, Exception inner)
		: base(Facility.AssemblyInvoker, (short)errorID, message, inner)
	{
	}
}
public class InvalidDeviceAddressException : AddressException
{
	private AddressRepresentationMessageId messageID;

	public AddressRepresentationMessageId MessageID => messageID;

	public InvalidDeviceAddressException()
	{
	}

	public InvalidDeviceAddressException(AddressRepresentationMessageId errorID, string message)
		: base(errorID, message)
	{
		messageID = errorID;
	}

	public InvalidDeviceAddressException(AddressRepresentationMessageId errorID, string message, Exception inner)
		: base(errorID, message, inner)
	{
		messageID = errorID;
	}
}
