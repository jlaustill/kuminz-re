using System.Collections;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: Guid("36f7af8a-5dde-48e6-9995-ffce2ae6649d")]
[assembly: PrimaryInteropAssembly(1, 0)]
[assembly: TypeLibVersion(1, 0)]
[assembly: ImportedFromTypeLib("CILMetadata")]
[assembly: AssemblyVersion("3.0.5.17102")]
namespace Cummins.Interop.MetadataComponent;

public enum MetadataMsgEnum
{
	MSG_DIAG_INFO_NOTAVAILABLE = 1,
	MSG_DIAG_FILE_DOES_NOTMATCH_SCHEMA = 2,
	MSG_DIAG_LOADING_DEFAULT_DATASTRUCTURE_DEFINITIONS = 3,
	MSG_PROG_READFILE_STARTED = 101,
	MSG_PROG_READFILE_COMPLETED = 102
}
public enum tagMetadataMsgEnum
{
	MSG_DIAG_INFO_NOTAVAILABLE = 1,
	MSG_DIAG_FILE_DOES_NOTMATCH_SCHEMA = 2,
	MSG_DIAG_LOADING_DEFAULT_DATASTRUCTURE_DEFINITIONS = 3,
	MSG_PROG_READFILE_STARTED = 101,
	MSG_PROG_READFILE_COMPLETED = 102
}
[ComImport]
[TypeLibType(4160)]
[Guid("68637035-AE08-4950-B92E-89E359DEBDE4")]
public interface ICIAssignMsgGroup
{
	[DispId(1)]
	int Group
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[param: In]
		set;
	}
}
[ComImport]
[Guid("B77C0D91-7042-43A4-871A-C835C5711185")]
[TypeLibType(4160)]
public interface ICICollection : IEnumerable
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(-4)]
	[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
	new IEnumerator GetEnumerator();

	[DispId(1)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		get;
	}

	[DispId(0)]
	object this[[In][MarshalAs(UnmanagedType.Struct)] object loc]
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void Add([In][MarshalAs(UnmanagedType.Struct)] object Item);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	void Insert([In][MarshalAs(UnmanagedType.Struct)] object loc, [In][MarshalAs(UnmanagedType.Struct)] object Item);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(4)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object Remove([In][MarshalAs(UnmanagedType.Struct)] object loc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	void Clear();
}
[ComImport]
[TypeLibType(4160)]
[Guid("A3A57D8E-A1EB-406A-B097-9428EF6FEB3D")]
public interface ICIProductInfo
{
	[DispId(1)]
	string ProductID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	[ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
	CIByteOrderEnum ByteOrder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
		get;
	}

	[DispId(3)]
	int WordSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
	}

	[DispId(4)]
	ICICollection DeviceProtocols
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ICICollection GetInstructionProtocols([In][ComAliasName("Cummins.Interop.MetadataComponent.CIDeviceProtocolEnum")] CIDeviceProtocolEnum deviceProtocol);

	[DispId(6)]
	int SupportsWriteDevMem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	[return: ComAliasName("Cummins.Interop.MetadataComponent.CIWriteMethodsEnum")]
	CIWriteMethodsEnum GetProductionWriteMethod([In][ComAliasName("Cummins.Interop.MetadataComponent.CIInstProtocolEnum")] CIInstProtocolEnum instructionProtocol);

	[DispId(8)]
	ICICollection PhasesSupported
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	[ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
	CIPhaseClassEnum PhaseClass
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
		get;
	}

	[DispId(10)]
	ICICollection SupportedECM_IDs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	string BootGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(12)]
	string ApplicationGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(13)]
	[ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
	CIGTISLevelEnum GTISLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	void GetParameterInfo([In][MarshalAs(UnmanagedType.BStr)] string groupID, [In][MarshalAs(UnmanagedType.BStr)] string bstrParameterName, out int lLocation, out int lOffset, out int lLength, [ComAliasName("Cummins.Interop.MetadataComponent.CIParameterDiscriminatorEnum")] out CIParameterDiscriminatorEnum discriminator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ICICollection GetPhaseRules();

	[DispId(16)]
	string DefaultPhase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ICICollection GetSupportedApplicationIDs();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(18)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ICICollection GetSupportedDataStructures([In][MarshalAs(UnmanagedType.BStr)] string bstrPhase);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	CIDetectionRule GetDetectionRule();

	[DispId(20)]
	string CUDLDownloadAlgorithm
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(20)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(21)]
	int NonProductionDownloadPacketSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		get;
	}
}
public enum CIByteOrderEnum
{
	BYTEORDER_INTEL = 1,
	BYTEORDER_MOTOROLA,
	BYTEORDER_NA
}
public enum tagCIMTDByteOrder
{
	BYTEORDER_INTEL = 1,
	BYTEORDER_MOTOROLA,
	BYTEORDER_NA
}
public enum CIDeviceProtocolEnum
{
	DEVICE_PROTOCOL_J1939 = 1,
	DEVICE_PROTOCOL_J1708,
	DEVICE_PROTOCOL_ISO15765,
	DEVICE_PROTOCOL_NA
}
public enum tagCIDeviceProtocols
{
	DEVICE_PROTOCOL_J1939 = 1,
	DEVICE_PROTOCOL_J1708,
	DEVICE_PROTOCOL_ISO15765,
	DEVICE_PROTOCOL_NA
}
public enum CIInstProtocolEnum
{
	INSTRUCTION_PROTOCOL_CPPJ1708_16 = 1,
	INSTRUCTION_PROTOCOL_CPPJ1708_16_NOCRC,
	INSTRUCTION_PROTOCOL_CPPJ1708_32,
	INSTRUCTION_PROTOCOL_CPPJ1939,
	INSTRUCTION_PROTOCOL_CLIP,
	INSTRUCTION_PROTOCOL_UDS,
	INSTRUCTION_PROTOCOL_NA
}
public enum tagCIInstProtocolEnum
{
	INSTRUCTION_PROTOCOL_CPPJ1708_16 = 1,
	INSTRUCTION_PROTOCOL_CPPJ1708_16_NOCRC,
	INSTRUCTION_PROTOCOL_CPPJ1708_32,
	INSTRUCTION_PROTOCOL_CPPJ1939,
	INSTRUCTION_PROTOCOL_CLIP,
	INSTRUCTION_PROTOCOL_UDS,
	INSTRUCTION_PROTOCOL_NA
}
public enum CIWriteMethodsEnum
{
	MODE_CPP_WRITE_SECURE_DATA = 1,
	MODE_CPP_WRITE_SCRATCH_MEM,
	MODE_CPP_WRITE_SCRATCH_CRC_SWAP,
	MODE_CPP_WRITE_AUTOMATIC,
	MODE_CPP_WRITE_DEV_MEM
}
public enum tagCIWriteMethods
{
	MODE_CPP_WRITE_SECURE_DATA = 1,
	MODE_CPP_WRITE_SCRATCH_MEM,
	MODE_CPP_WRITE_SCRATCH_CRC_SWAP,
	MODE_CPP_WRITE_AUTOMATIC,
	MODE_CPP_WRITE_DEV_MEM
}
public enum CIPhaseClassEnum
{
	PHASECLASS_SSPH = 1,
	PHASECLASS_CHR,
	PHASECLASS_GTIS45,
	PHASECLASS_ECMB,
	PHASECLASS_NULL
}
public enum tagCIPhaseClass
{
	PHASECLASS_SSPH = 1,
	PHASECLASS_CHR,
	PHASECLASS_GTIS45,
	PHASECLASS_ECMB,
	PHASECLASS_NULL
}
public enum CIGTISLevelEnum
{
	PREGTIS = 1,
	GTIS20,
	GTIS38,
	GTIS45,
	GTISNA
}
public enum tagCIGTISLevelEnum
{
	PREGTIS = 1,
	GTIS20,
	GTIS38,
	GTIS45,
	GTISNA
}
public enum CIParameterDiscriminatorEnum
{
	PARAMETERDISCRIMINATOR_ADDRESS = 1,
	PARAMETERDISCRIMINATOR_NTN,
	PARAMETERDISCRIMINATOR_ITN,
	PARAMETERDISCRIMINATOR_PARAMETERID
}
public enum tagCIParameterDiscriminator
{
	PARAMETERDISCRIMINATOR_ADDRESS = 1,
	PARAMETERDISCRIMINATOR_NTN,
	PARAMETERDISCRIMINATOR_ITN,
	PARAMETERDISCRIMINATOR_PARAMETERID
}
[ComImport]
[Guid("E5A42348-2082-4534-974A-10C9CB9D4343")]
[TypeLibType(4160)]
public interface ICIDetectionRule
{
	[ComAliasName("Cummins.Interop.MetadataComponent.CIDetectionModeEnum")]
	[DispId(1)]
	CIDetectionModeEnum DetectionMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIDetectionModeEnum")]
		get;
	}

	[DispId(2)]
	ICICollection StaticAddresses
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
public enum CIDetectionModeEnum
{
	DETECTIONMODE_J1939_DDR_AM_STATIC = 1,
	DETECTIONMODE_J1939_DDR_AM_DYNAMIC = 2,
	DETECTIONMODE_J1939_DDR_AM_STATIC_DYNAMIC = 4,
	DETECTIONMODE_J1939_DDR_AM_DYNAMIC_STATIC = 8
}
public enum tagCIDetectionMode
{
	DETECTIONMODE_J1939_DDR_AM_STATIC = 1,
	DETECTIONMODE_J1939_DDR_AM_DYNAMIC = 2,
	DETECTIONMODE_J1939_DDR_AM_STATIC_DYNAMIC = 4,
	DETECTIONMODE_J1939_DDR_AM_DYNAMIC_STATIC = 8
}
[ComImport]
[Guid("A4DFE494-0BE9-4FF3-B8F2-EC5EF63EBCB2")]
[TypeLibType(4160)]
public interface ICIProductInfo2 : ICIProductInfo
{
	[DispId(1)]
	new string ProductID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
	[DispId(2)]
	new CIByteOrderEnum ByteOrder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
		get;
	}

	[DispId(3)]
	new int WordSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
	}

	[DispId(4)]
	new ICICollection DeviceProtocols
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ICICollection GetInstructionProtocols([In][ComAliasName("Cummins.Interop.MetadataComponent.CIDeviceProtocolEnum")] CIDeviceProtocolEnum deviceProtocol);

	[DispId(6)]
	new int SupportsWriteDevMem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	[return: ComAliasName("Cummins.Interop.MetadataComponent.CIWriteMethodsEnum")]
	new CIWriteMethodsEnum GetProductionWriteMethod([In][ComAliasName("Cummins.Interop.MetadataComponent.CIInstProtocolEnum")] CIInstProtocolEnum instructionProtocol);

	[DispId(8)]
	new ICICollection PhasesSupported
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	[ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
	new CIPhaseClassEnum PhaseClass
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
		get;
	}

	[DispId(10)]
	new ICICollection SupportedECM_IDs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new string BootGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(12)]
	new string ApplicationGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(13)]
	[ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
	new CIGTISLevelEnum GTISLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	new void GetParameterInfo([In][MarshalAs(UnmanagedType.BStr)] string groupID, [In][MarshalAs(UnmanagedType.BStr)] string bstrParameterName, out int lLocation, out int lOffset, out int lLength, [ComAliasName("Cummins.Interop.MetadataComponent.CIParameterDiscriminatorEnum")] out CIParameterDiscriminatorEnum discriminator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ICICollection GetPhaseRules();

	[DispId(16)]
	new string DefaultPhase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ICICollection GetSupportedApplicationIDs();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(18)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ICICollection GetSupportedDataStructures([In][MarshalAs(UnmanagedType.BStr)] string bstrPhase);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new CIDetectionRule GetDetectionRule();

	[DispId(20)]
	new string CUDLDownloadAlgorithm
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(20)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(21)]
	new int NonProductionDownloadPacketSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(22)]
	int GetDataCollectorBaseRate([In][MarshalAs(UnmanagedType.BStr)] string bstrPhase);
}
[ComImport]
[Guid("E9D0C3E8-C15A-467E-92AE-9B4EFEABEEDF")]
[TypeLibType(4160)]
public interface ICIProductInfo3 : ICIProductInfo2
{
	[DispId(1)]
	new string ProductID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
	[DispId(2)]
	new CIByteOrderEnum ByteOrder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
		get;
	}

	[DispId(3)]
	new int WordSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
	}

	[DispId(4)]
	new ICICollection DeviceProtocols
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ICICollection GetInstructionProtocols([In][ComAliasName("Cummins.Interop.MetadataComponent.CIDeviceProtocolEnum")] CIDeviceProtocolEnum deviceProtocol);

	[DispId(6)]
	new int SupportsWriteDevMem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	[return: ComAliasName("Cummins.Interop.MetadataComponent.CIWriteMethodsEnum")]
	new CIWriteMethodsEnum GetProductionWriteMethod([In][ComAliasName("Cummins.Interop.MetadataComponent.CIInstProtocolEnum")] CIInstProtocolEnum instructionProtocol);

	[DispId(8)]
	new ICICollection PhasesSupported
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
	[DispId(9)]
	new CIPhaseClassEnum PhaseClass
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
		get;
	}

	[DispId(10)]
	new ICICollection SupportedECM_IDs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new string BootGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(12)]
	new string ApplicationGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
	[DispId(13)]
	new CIGTISLevelEnum GTISLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	new void GetParameterInfo([In][MarshalAs(UnmanagedType.BStr)] string groupID, [In][MarshalAs(UnmanagedType.BStr)] string bstrParameterName, out int lLocation, out int lOffset, out int lLength, [ComAliasName("Cummins.Interop.MetadataComponent.CIParameterDiscriminatorEnum")] out CIParameterDiscriminatorEnum discriminator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ICICollection GetPhaseRules();

	[DispId(16)]
	new string DefaultPhase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ICICollection GetSupportedApplicationIDs();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(18)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ICICollection GetSupportedDataStructures([In][MarshalAs(UnmanagedType.BStr)] string bstrPhase);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new CIDetectionRule GetDetectionRule();

	[DispId(20)]
	new string CUDLDownloadAlgorithm
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(20)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(21)]
	new int NonProductionDownloadPacketSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(22)]
	new int GetDataCollectorBaseRate([In][MarshalAs(UnmanagedType.BStr)] string bstrPhase);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(23)]
	int GetNonProductionDownLoadPacketSizeByProtocol([In][ComAliasName("Cummins.Interop.MetadataComponent.CIDeviceProtocolEnum")] CIDeviceProtocolEnum deviceProtocol);
}
[ComImport]
[TypeLibType(4160)]
[Guid("06759A82-3B2C-4389-BB8D-CA59D76FF660")]
public interface ICIProductInfo4 : ICIProductInfo3
{
	[DispId(1)]
	new string ProductID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
	[DispId(2)]
	new CIByteOrderEnum ByteOrder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
		get;
	}

	[DispId(3)]
	new int WordSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
	}

	[DispId(4)]
	new ICICollection DeviceProtocols
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ICICollection GetInstructionProtocols([In][ComAliasName("Cummins.Interop.MetadataComponent.CIDeviceProtocolEnum")] CIDeviceProtocolEnum deviceProtocol);

	[DispId(6)]
	new int SupportsWriteDevMem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	[return: ComAliasName("Cummins.Interop.MetadataComponent.CIWriteMethodsEnum")]
	new CIWriteMethodsEnum GetProductionWriteMethod([In][ComAliasName("Cummins.Interop.MetadataComponent.CIInstProtocolEnum")] CIInstProtocolEnum instructionProtocol);

	[DispId(8)]
	new ICICollection PhasesSupported
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
	[DispId(9)]
	new CIPhaseClassEnum PhaseClass
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
		get;
	}

	[DispId(10)]
	new ICICollection SupportedECM_IDs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new string BootGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(12)]
	new string ApplicationGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(13)]
	[ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
	new CIGTISLevelEnum GTISLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	new void GetParameterInfo([In][MarshalAs(UnmanagedType.BStr)] string groupID, [In][MarshalAs(UnmanagedType.BStr)] string bstrParameterName, out int lLocation, out int lOffset, out int lLength, [ComAliasName("Cummins.Interop.MetadataComponent.CIParameterDiscriminatorEnum")] out CIParameterDiscriminatorEnum discriminator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ICICollection GetPhaseRules();

	[DispId(16)]
	new string DefaultPhase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ICICollection GetSupportedApplicationIDs();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(18)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ICICollection GetSupportedDataStructures([In][MarshalAs(UnmanagedType.BStr)] string bstrPhase);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new CIDetectionRule GetDetectionRule();

	[DispId(20)]
	new string CUDLDownloadAlgorithm
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(20)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(21)]
	new int NonProductionDownloadPacketSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(22)]
	new int GetDataCollectorBaseRate([In][MarshalAs(UnmanagedType.BStr)] string bstrPhase);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(23)]
	new int GetNonProductionDownLoadPacketSizeByProtocol([In][ComAliasName("Cummins.Interop.MetadataComponent.CIDeviceProtocolEnum")] CIDeviceProtocolEnum deviceProtocol);

	[DispId(24)]
	string ECMName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(25)]
	string MarketingName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(26)]
	string EngineeringName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(27)]
	string ReleaseMethod
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(28)]
	int IsSPEEDSupported
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(28)]
		get;
	}

	[DispId(29)]
	string ParentProductID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(29)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(30)]
	ICICollection ChildProductIDs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(30)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(31)]
	int NumberOfECMs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	ICICollection Groups
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[Guid("C1492EA8-B268-4FA9-8F30-9D67C96168EA")]
[TypeLibType(4160)]
public interface ICIProductInfo5 : ICIProductInfo4
{
	[DispId(1)]
	new string ProductID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
	[DispId(2)]
	new CIByteOrderEnum ByteOrder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
		get;
	}

	[DispId(3)]
	new int WordSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
	}

	[DispId(4)]
	new ICICollection DeviceProtocols
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ICICollection GetInstructionProtocols([In][ComAliasName("Cummins.Interop.MetadataComponent.CIDeviceProtocolEnum")] CIDeviceProtocolEnum deviceProtocol);

	[DispId(6)]
	new int SupportsWriteDevMem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	[return: ComAliasName("Cummins.Interop.MetadataComponent.CIWriteMethodsEnum")]
	new CIWriteMethodsEnum GetProductionWriteMethod([In][ComAliasName("Cummins.Interop.MetadataComponent.CIInstProtocolEnum")] CIInstProtocolEnum instructionProtocol);

	[DispId(8)]
	new ICICollection PhasesSupported
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
	[DispId(9)]
	new CIPhaseClassEnum PhaseClass
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
		get;
	}

	[DispId(10)]
	new ICICollection SupportedECM_IDs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new string BootGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(12)]
	new string ApplicationGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(13)]
	[ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
	new CIGTISLevelEnum GTISLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	new void GetParameterInfo([In][MarshalAs(UnmanagedType.BStr)] string groupID, [In][MarshalAs(UnmanagedType.BStr)] string bstrParameterName, out int lLocation, out int lOffset, out int lLength, [ComAliasName("Cummins.Interop.MetadataComponent.CIParameterDiscriminatorEnum")] out CIParameterDiscriminatorEnum discriminator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ICICollection GetPhaseRules();

	[DispId(16)]
	new string DefaultPhase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ICICollection GetSupportedApplicationIDs();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(18)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ICICollection GetSupportedDataStructures([In][MarshalAs(UnmanagedType.BStr)] string bstrPhase);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new CIDetectionRule GetDetectionRule();

	[DispId(20)]
	new string CUDLDownloadAlgorithm
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(20)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(21)]
	new int NonProductionDownloadPacketSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(22)]
	new int GetDataCollectorBaseRate([In][MarshalAs(UnmanagedType.BStr)] string bstrPhase);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(23)]
	new int GetNonProductionDownLoadPacketSizeByProtocol([In][ComAliasName("Cummins.Interop.MetadataComponent.CIDeviceProtocolEnum")] CIDeviceProtocolEnum deviceProtocol);

	[DispId(24)]
	new string ECMName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(25)]
	new string MarketingName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(26)]
	new string EngineeringName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(27)]
	new string ReleaseMethod
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(28)]
	new int IsSPEEDSupported
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(28)]
		get;
	}

	[DispId(29)]
	new string ParentProductID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(29)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(30)]
	new ICICollection ChildProductIDs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(30)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(31)]
	new int NumberOfECMs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new ICICollection Groups
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIEngineTypeEnum")]
	[DispId(35)]
	CIEngineTypeEnum EngineType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(35)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIEngineTypeEnum")]
		get;
	}
}
public enum CIEngineTypeEnum
{
	NA,
	INLINE,
	CUMMINS_V,
	SAE_J824_V
}
public enum tagCIEngineTypeEnum
{
	NA,
	INLINE,
	CUMMINS_V,
	SAE_J824_V
}
[ComImport]
[TypeLibType(4160)]
[Guid("C12E7139-2303-4EF0-96FA-31E3F0A97D39")]
public interface ICIProductInfo6 : ICIProductInfo5
{
	[DispId(1)]
	new string ProductID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
	[DispId(2)]
	new CIByteOrderEnum ByteOrder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
		get;
	}

	[DispId(3)]
	new int WordSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
	}

	[DispId(4)]
	new ICICollection DeviceProtocols
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ICICollection GetInstructionProtocols([In][ComAliasName("Cummins.Interop.MetadataComponent.CIDeviceProtocolEnum")] CIDeviceProtocolEnum deviceProtocol);

	[DispId(6)]
	new int SupportsWriteDevMem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	[return: ComAliasName("Cummins.Interop.MetadataComponent.CIWriteMethodsEnum")]
	new CIWriteMethodsEnum GetProductionWriteMethod([In][ComAliasName("Cummins.Interop.MetadataComponent.CIInstProtocolEnum")] CIInstProtocolEnum instructionProtocol);

	[DispId(8)]
	new ICICollection PhasesSupported
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(9)]
	[ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
	new CIPhaseClassEnum PhaseClass
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
		get;
	}

	[DispId(10)]
	new ICICollection SupportedECM_IDs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	new string BootGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(12)]
	new string ApplicationGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(13)]
	[ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
	new CIGTISLevelEnum GTISLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	new void GetParameterInfo([In][MarshalAs(UnmanagedType.BStr)] string groupID, [In][MarshalAs(UnmanagedType.BStr)] string bstrParameterName, out int lLocation, out int lOffset, out int lLength, [ComAliasName("Cummins.Interop.MetadataComponent.CIParameterDiscriminatorEnum")] out CIParameterDiscriminatorEnum discriminator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ICICollection GetPhaseRules();

	[DispId(16)]
	new string DefaultPhase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ICICollection GetSupportedApplicationIDs();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(18)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ICICollection GetSupportedDataStructures([In][MarshalAs(UnmanagedType.BStr)] string bstrPhase);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new CIDetectionRule GetDetectionRule();

	[DispId(20)]
	new string CUDLDownloadAlgorithm
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(20)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(21)]
	new int NonProductionDownloadPacketSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(22)]
	new int GetDataCollectorBaseRate([In][MarshalAs(UnmanagedType.BStr)] string bstrPhase);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(23)]
	new int GetNonProductionDownLoadPacketSizeByProtocol([In][ComAliasName("Cummins.Interop.MetadataComponent.CIDeviceProtocolEnum")] CIDeviceProtocolEnum deviceProtocol);

	[DispId(24)]
	new string ECMName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(24)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(25)]
	new string MarketingName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(25)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(26)]
	new string EngineeringName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(26)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(27)]
	new string ReleaseMethod
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(27)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(28)]
	new int IsSPEEDSupported
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(28)]
		get;
	}

	[DispId(29)]
	new string ParentProductID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(29)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(30)]
	new ICICollection ChildProductIDs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(30)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(31)]
	new int NumberOfECMs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(31)]
		get;
	}

	[DispId(32)]
	new ICICollection Groups
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(32)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(35)]
	[ComAliasName("Cummins.Interop.MetadataComponent.CIEngineTypeEnum")]
	new CIEngineTypeEnum EngineType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(35)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIEngineTypeEnum")]
		get;
	}

	[DispId(37)]
	string ECMCodePrefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(37)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[TypeLibType(4160)]
[Guid("FCF2A3BA-70B1-46AD-8D22-B227D56EC879")]
public interface ICIPhaseRule
{
	[DispId(1)]
	string Phase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	object Version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(3)]
	string ECM_ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[Guid("BD1A18C0-64CA-4CEB-9EF9-68173C4195B2")]
[TypeLibType(4160)]
public interface ICIApplicationID
{
	[DispId(1)]
	string ApplicationID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void GetApplicationIDDetails(out int lLocation, out int lOffset, out int lLength);
}
[ComImport]
[Guid("7711B383-D1B6-44E4-A125-26AC2C6E7C4F")]
[TypeLibType(4160)]
public interface ICIDataStructure
{
	[DispId(1)]
	string Phase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	string ParameterDefinition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	string BitMapping
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(4)]
	string Location
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[TypeLibType(4160)]
[Guid("6982CA46-610A-4EF3-9EAC-717453C55407")]
public interface ICIMetaData
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	[return: MarshalAs(UnmanagedType.Interface)]
	CIProductInfo GetProductInfo([In][MarshalAs(UnmanagedType.BStr)] string bstrProductID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ICICollection GetAllProductInfo();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ICICollection GetSupportedProductIDs();
}
[ComImport]
[TypeLibType(4160)]
[Guid("B7870F42-590A-4D48-9645-F0670C62B90D")]
public interface ICIMetaData2 : ICIMetaData
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new CIProductInfo GetProductInfo([In][MarshalAs(UnmanagedType.BStr)] string bstrProductID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ICICollection GetAllProductInfo();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new ICICollection GetSupportedProductIDs();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(33)]
	[return: MarshalAs(UnmanagedType.Interface)]
	ICICollection GetProductIDsByGroup([In][MarshalAs(UnmanagedType.BStr)] string bstrProductGroup);

	[DispId(34)]
	ICICollection SupportedGroups
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(34)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[Guid("8310E706-77DE-4EA7-B47E-F08B9555E74C")]
[TypeLibType(4096)]
public interface ICIFile
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReadFile([In][MarshalAs(UnmanagedType.BStr)] string bstrFilename);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void WriteFile([In][MarshalAs(UnmanagedType.BStr)] string bstrFilename, [In] int bOverwrite);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReadFileDescription([In][MarshalAs(UnmanagedType.BStr)] string bstrFilename, [MarshalAs(UnmanagedType.BStr)] out string pbstrDescription);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void VerifyFile([In][MarshalAs(UnmanagedType.BStr)] string bstrFilename, [In][MarshalAs(UnmanagedType.BStr)] string bstrVersion);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	void ReadFileVersion([In][MarshalAs(UnmanagedType.BStr)] string bstrFilename, [MarshalAs(UnmanagedType.BStr)] out string pbstrVersion);

	[DispId(906)]
	object FileExtensions
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(907)]
	string Configuration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(908)]
	string FileDescription
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(909)]
	string FileVersion
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(910)]
	string Description
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(911)]
	string Version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(912)]
	int CanRead
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	[DispId(913)]
	int CanWrite
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}
}
[ComImport]
[Guid("728ADD32-879B-473D-8959-18A2AAA7EE7B")]
[TypeLibType(4160)]
public interface ICIGenericConfigFile
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetGenericConfigFileForDownload([In][ComAliasName("Cummins.Interop.MetadataComponent.CIGTISConfigLevelEnum")] CIGTISConfigLevelEnum gtisConfigLevel);
}
public enum CIGTISConfigLevelEnum
{
	GTISCONFIGLEVEL_ECMC,
	GTISCONFIGLEVEL_ECMB,
	GTISCONFIGLEVEL_CM400,
	GTISCONFIGLEVEL_CM420,
	GTISCONFIGLEVEL_GTIS20,
	GTISCONFIGLEVEL_GTIS38
}
public enum tagCIGTISConfigLevel
{
	GTISCONFIGLEVEL_ECMC,
	GTISCONFIGLEVEL_ECMB,
	GTISCONFIGLEVEL_CM400,
	GTISCONFIGLEVEL_CM420,
	GTISCONFIGLEVEL_GTIS20,
	GTISCONFIGLEVEL_GTIS38
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("ED36D53B-223A-42AD-8083-62C1AAE73411")]
public class CIMetadataClass : ICIMetaData, CIMetadata, ICIMetaData2
{
	public virtual extern ICICollection SupportedGroups
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern CIProductInfo GetProductInfo([In][MarshalAs(UnmanagedType.BStr)] string bstrProductID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection GetAllProductInfo();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(3)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection GetSupportedProductIDs();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern CIProductInfo ICIMetaData2_GetProductInfo([In][MarshalAs(UnmanagedType.BStr)] string bstrProductID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection ICIMetaData2_GetAllProductInfo();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection ICIMetaData2_GetSupportedProductIDs();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection GetProductIDsByGroup([In][MarshalAs(UnmanagedType.BStr)] string bstrProductGroup);
}
[ComImport]
[Guid("6982CA46-610A-4EF3-9EAC-717453C55407")]
[CoClass(typeof(CIMetadataClass))]
public interface CIMetadata : ICIMetaData
{
}
[ComImport]
[Guid("2080631B-4EE2-4F77-BA72-F14AB5B45C54")]
[ClassInterface(0)]
public class CIProductInfoClass : ICIProductInfo, CIProductInfo, ICIAssignMsgGroup, ICIProductInfo2, ICIProductInfo3, ICIProductInfo4, ICIProductInfo5, ICIProductInfo6
{
	[DispId(1)]
	public virtual extern string ProductID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	[ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
	public virtual extern CIByteOrderEnum ByteOrder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
		get;
	}

	[DispId(3)]
	public virtual extern int WordSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		get;
	}

	[DispId(4)]
	public virtual extern ICICollection DeviceProtocols
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(6)]
	public virtual extern int SupportsWriteDevMem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(6)]
		get;
	}

	[DispId(8)]
	public virtual extern ICICollection PhasesSupported
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(8)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
	[DispId(9)]
	public virtual extern CIPhaseClassEnum PhaseClass
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(9)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
		get;
	}

	[DispId(10)]
	public virtual extern ICICollection SupportedECM_IDs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(10)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(11)]
	public virtual extern string BootGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(11)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(12)]
	public virtual extern string ApplicationGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(12)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(13)]
	[ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
	public virtual extern CIGTISLevelEnum GTISLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(13)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
		get;
	}

	[DispId(16)]
	public virtual extern string DefaultPhase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(16)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(20)]
	public virtual extern string CUDLDownloadAlgorithm
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(20)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(21)]
	public virtual extern int NonProductionDownloadPacketSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(21)]
		get;
	}

	public virtual extern int Group
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern string ICIProductInfo2_ProductID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
	public virtual extern CIByteOrderEnum ICIProductInfo2_ByteOrder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
		get;
	}

	public virtual extern int ICIProductInfo2_WordSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern ICICollection ICIProductInfo2_DeviceProtocols
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	public virtual extern int ICIProductInfo2_SupportsWriteDevMem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern ICICollection ICIProductInfo2_PhasesSupported
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
	public virtual extern CIPhaseClassEnum ICIProductInfo2_PhaseClass
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
		get;
	}

	public virtual extern ICICollection ICIProductInfo2_SupportedECM_IDs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	public virtual extern string ICIProductInfo2_BootGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIProductInfo2_ApplicationGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
	public virtual extern CIGTISLevelEnum ICIProductInfo2_GTISLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
		get;
	}

	public virtual extern string ICIProductInfo2_DefaultPhase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIProductInfo2_CUDLDownloadAlgorithm
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern int ICIProductInfo2_NonProductionDownloadPacketSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern string ICIProductInfo3_ProductID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
	public virtual extern CIByteOrderEnum ICIProductInfo3_ByteOrder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
		get;
	}

	public virtual extern int ICIProductInfo3_WordSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern ICICollection ICIProductInfo3_DeviceProtocols
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	public virtual extern int ICIProductInfo3_SupportsWriteDevMem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern ICICollection ICIProductInfo3_PhasesSupported
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
	public virtual extern CIPhaseClassEnum ICIProductInfo3_PhaseClass
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
		get;
	}

	public virtual extern ICICollection ICIProductInfo3_SupportedECM_IDs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	public virtual extern string ICIProductInfo3_BootGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIProductInfo3_ApplicationGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
	public virtual extern CIGTISLevelEnum ICIProductInfo3_GTISLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
		get;
	}

	public virtual extern string ICIProductInfo3_DefaultPhase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIProductInfo3_CUDLDownloadAlgorithm
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern int ICIProductInfo3_NonProductionDownloadPacketSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern string ICIProductInfo4_ProductID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
	public virtual extern CIByteOrderEnum ICIProductInfo4_ByteOrder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
		get;
	}

	public virtual extern int ICIProductInfo4_WordSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern ICICollection ICIProductInfo4_DeviceProtocols
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	public virtual extern int ICIProductInfo4_SupportsWriteDevMem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern ICICollection ICIProductInfo4_PhasesSupported
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
	public virtual extern CIPhaseClassEnum ICIProductInfo4_PhaseClass
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
		get;
	}

	public virtual extern ICICollection ICIProductInfo4_SupportedECM_IDs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	public virtual extern string ICIProductInfo4_BootGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIProductInfo4_ApplicationGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
	public virtual extern CIGTISLevelEnum ICIProductInfo4_GTISLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
		get;
	}

	public virtual extern string ICIProductInfo4_DefaultPhase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIProductInfo4_CUDLDownloadAlgorithm
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern int ICIProductInfo4_NonProductionDownloadPacketSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern string ECMName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string MarketingName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string EngineeringName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ReleaseMethod
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern int IsSPEEDSupported
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern string ParentProductID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern ICICollection ChildProductIDs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	public virtual extern int NumberOfECMs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern ICICollection Groups
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	public virtual extern string ICIProductInfo5_ProductID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
	public virtual extern CIByteOrderEnum ICIProductInfo5_ByteOrder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
		get;
	}

	public virtual extern int ICIProductInfo5_WordSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern ICICollection ICIProductInfo5_DeviceProtocols
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	public virtual extern int ICIProductInfo5_SupportsWriteDevMem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern ICICollection ICIProductInfo5_PhasesSupported
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
	public virtual extern CIPhaseClassEnum ICIProductInfo5_PhaseClass
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
		get;
	}

	public virtual extern ICICollection ICIProductInfo5_SupportedECM_IDs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	public virtual extern string ICIProductInfo5_BootGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIProductInfo5_ApplicationGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
	public virtual extern CIGTISLevelEnum ICIProductInfo5_GTISLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
		get;
	}

	public virtual extern string ICIProductInfo5_DefaultPhase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIProductInfo5_CUDLDownloadAlgorithm
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern int ICIProductInfo5_NonProductionDownloadPacketSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern string ICIProductInfo5_ECMName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIProductInfo5_MarketingName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIProductInfo5_EngineeringName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIProductInfo5_ReleaseMethod
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern int ICIProductInfo5_IsSPEEDSupported
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern string ICIProductInfo5_ParentProductID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern ICICollection ICIProductInfo5_ChildProductIDs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	public virtual extern int ICIProductInfo5_NumberOfECMs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern ICICollection ICIProductInfo5_Groups
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIEngineTypeEnum")]
	public virtual extern CIEngineTypeEnum EngineType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIEngineTypeEnum")]
		get;
	}

	public virtual extern string ICIProductInfo6_ProductID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
	public virtual extern CIByteOrderEnum ICIProductInfo6_ByteOrder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIByteOrderEnum")]
		get;
	}

	public virtual extern int ICIProductInfo6_WordSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern ICICollection ICIProductInfo6_DeviceProtocols
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	public virtual extern int ICIProductInfo6_SupportsWriteDevMem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern ICICollection ICIProductInfo6_PhasesSupported
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
	public virtual extern CIPhaseClassEnum ICIProductInfo6_PhaseClass
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIPhaseClassEnum")]
		get;
	}

	public virtual extern ICICollection ICIProductInfo6_SupportedECM_IDs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	public virtual extern string ICIProductInfo6_BootGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIProductInfo6_ApplicationGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
	public virtual extern CIGTISLevelEnum ICIProductInfo6_GTISLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIGTISLevelEnum")]
		get;
	}

	public virtual extern string ICIProductInfo6_DefaultPhase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIProductInfo6_CUDLDownloadAlgorithm
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern int ICIProductInfo6_NonProductionDownloadPacketSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern string ICIProductInfo6_ECMName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIProductInfo6_MarketingName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIProductInfo6_EngineeringName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern string ICIProductInfo6_ReleaseMethod
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern int ICIProductInfo6_IsSPEEDSupported
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern string ICIProductInfo6_ParentProductID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern ICICollection ICIProductInfo6_ChildProductIDs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	public virtual extern int ICIProductInfo6_NumberOfECMs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern ICICollection ICIProductInfo6_Groups
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[ComAliasName("Cummins.Interop.MetadataComponent.CIEngineTypeEnum")]
	public virtual extern CIEngineTypeEnum ICIProductInfo6_EngineType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIEngineTypeEnum")]
		get;
	}

	public virtual extern string ECMCodePrefix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(5)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection GetInstructionProtocols([In][ComAliasName("Cummins.Interop.MetadataComponent.CIDeviceProtocolEnum")] CIDeviceProtocolEnum deviceProtocol);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(7)]
	[return: ComAliasName("Cummins.Interop.MetadataComponent.CIWriteMethodsEnum")]
	public virtual extern CIWriteMethodsEnum GetProductionWriteMethod([In][ComAliasName("Cummins.Interop.MetadataComponent.CIInstProtocolEnum")] CIInstProtocolEnum instructionProtocol);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(14)]
	public virtual extern void GetParameterInfo([In][MarshalAs(UnmanagedType.BStr)] string groupID, [In][MarshalAs(UnmanagedType.BStr)] string bstrParameterName, out int lLocation, out int lOffset, out int lLength, [ComAliasName("Cummins.Interop.MetadataComponent.CIParameterDiscriminatorEnum")] out CIParameterDiscriminatorEnum discriminator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(15)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection GetPhaseRules();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(17)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection GetSupportedApplicationIDs();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(18)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection GetSupportedDataStructures([In][MarshalAs(UnmanagedType.BStr)] string bstrPhase);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(19)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern CIDetectionRule GetDetectionRule();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection ICIProductInfo2_GetInstructionProtocols([In][ComAliasName("Cummins.Interop.MetadataComponent.CIDeviceProtocolEnum")] CIDeviceProtocolEnum deviceProtocol);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Cummins.Interop.MetadataComponent.CIWriteMethodsEnum")]
	public virtual extern CIWriteMethodsEnum ICIProductInfo2_GetProductionWriteMethod([In][ComAliasName("Cummins.Interop.MetadataComponent.CIInstProtocolEnum")] CIInstProtocolEnum instructionProtocol);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ICIProductInfo2_GetParameterInfo([In][MarshalAs(UnmanagedType.BStr)] string groupID, [In][MarshalAs(UnmanagedType.BStr)] string bstrParameterName, out int lLocation, out int lOffset, out int lLength, [ComAliasName("Cummins.Interop.MetadataComponent.CIParameterDiscriminatorEnum")] out CIParameterDiscriminatorEnum discriminator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection ICIProductInfo2_GetPhaseRules();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection ICIProductInfo2_GetSupportedApplicationIDs();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection ICIProductInfo2_GetSupportedDataStructures([In][MarshalAs(UnmanagedType.BStr)] string bstrPhase);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern CIDetectionRule ICIProductInfo2_GetDetectionRule();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int GetDataCollectorBaseRate([In][MarshalAs(UnmanagedType.BStr)] string bstrPhase);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection ICIProductInfo3_GetInstructionProtocols([In][ComAliasName("Cummins.Interop.MetadataComponent.CIDeviceProtocolEnum")] CIDeviceProtocolEnum deviceProtocol);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Cummins.Interop.MetadataComponent.CIWriteMethodsEnum")]
	public virtual extern CIWriteMethodsEnum ICIProductInfo3_GetProductionWriteMethod([In][ComAliasName("Cummins.Interop.MetadataComponent.CIInstProtocolEnum")] CIInstProtocolEnum instructionProtocol);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ICIProductInfo3_GetParameterInfo([In][MarshalAs(UnmanagedType.BStr)] string groupID, [In][MarshalAs(UnmanagedType.BStr)] string bstrParameterName, out int lLocation, out int lOffset, out int lLength, [ComAliasName("Cummins.Interop.MetadataComponent.CIParameterDiscriminatorEnum")] out CIParameterDiscriminatorEnum discriminator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection ICIProductInfo3_GetPhaseRules();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection ICIProductInfo3_GetSupportedApplicationIDs();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection ICIProductInfo3_GetSupportedDataStructures([In][MarshalAs(UnmanagedType.BStr)] string bstrPhase);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern CIDetectionRule ICIProductInfo3_GetDetectionRule();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int ICIProductInfo3_GetDataCollectorBaseRate([In][MarshalAs(UnmanagedType.BStr)] string bstrPhase);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int GetNonProductionDownLoadPacketSizeByProtocol([In][ComAliasName("Cummins.Interop.MetadataComponent.CIDeviceProtocolEnum")] CIDeviceProtocolEnum deviceProtocol);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection ICIProductInfo4_GetInstructionProtocols([In][ComAliasName("Cummins.Interop.MetadataComponent.CIDeviceProtocolEnum")] CIDeviceProtocolEnum deviceProtocol);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Cummins.Interop.MetadataComponent.CIWriteMethodsEnum")]
	public virtual extern CIWriteMethodsEnum ICIProductInfo4_GetProductionWriteMethod([In][ComAliasName("Cummins.Interop.MetadataComponent.CIInstProtocolEnum")] CIInstProtocolEnum instructionProtocol);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ICIProductInfo4_GetParameterInfo([In][MarshalAs(UnmanagedType.BStr)] string groupID, [In][MarshalAs(UnmanagedType.BStr)] string bstrParameterName, out int lLocation, out int lOffset, out int lLength, [ComAliasName("Cummins.Interop.MetadataComponent.CIParameterDiscriminatorEnum")] out CIParameterDiscriminatorEnum discriminator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection ICIProductInfo4_GetPhaseRules();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection ICIProductInfo4_GetSupportedApplicationIDs();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection ICIProductInfo4_GetSupportedDataStructures([In][MarshalAs(UnmanagedType.BStr)] string bstrPhase);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern CIDetectionRule ICIProductInfo4_GetDetectionRule();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int ICIProductInfo4_GetDataCollectorBaseRate([In][MarshalAs(UnmanagedType.BStr)] string bstrPhase);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int ICIProductInfo4_GetNonProductionDownLoadPacketSizeByProtocol([In][ComAliasName("Cummins.Interop.MetadataComponent.CIDeviceProtocolEnum")] CIDeviceProtocolEnum deviceProtocol);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection ICIProductInfo5_GetInstructionProtocols([In][ComAliasName("Cummins.Interop.MetadataComponent.CIDeviceProtocolEnum")] CIDeviceProtocolEnum deviceProtocol);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Cummins.Interop.MetadataComponent.CIWriteMethodsEnum")]
	public virtual extern CIWriteMethodsEnum ICIProductInfo5_GetProductionWriteMethod([In][ComAliasName("Cummins.Interop.MetadataComponent.CIInstProtocolEnum")] CIInstProtocolEnum instructionProtocol);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ICIProductInfo5_GetParameterInfo([In][MarshalAs(UnmanagedType.BStr)] string groupID, [In][MarshalAs(UnmanagedType.BStr)] string bstrParameterName, out int lLocation, out int lOffset, out int lLength, [ComAliasName("Cummins.Interop.MetadataComponent.CIParameterDiscriminatorEnum")] out CIParameterDiscriminatorEnum discriminator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection ICIProductInfo5_GetPhaseRules();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection ICIProductInfo5_GetSupportedApplicationIDs();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection ICIProductInfo5_GetSupportedDataStructures([In][MarshalAs(UnmanagedType.BStr)] string bstrPhase);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern CIDetectionRule ICIProductInfo5_GetDetectionRule();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int ICIProductInfo5_GetDataCollectorBaseRate([In][MarshalAs(UnmanagedType.BStr)] string bstrPhase);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int ICIProductInfo5_GetNonProductionDownLoadPacketSizeByProtocol([In][ComAliasName("Cummins.Interop.MetadataComponent.CIDeviceProtocolEnum")] CIDeviceProtocolEnum deviceProtocol);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection ICIProductInfo6_GetInstructionProtocols([In][ComAliasName("Cummins.Interop.MetadataComponent.CIDeviceProtocolEnum")] CIDeviceProtocolEnum deviceProtocol);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: ComAliasName("Cummins.Interop.MetadataComponent.CIWriteMethodsEnum")]
	public virtual extern CIWriteMethodsEnum ICIProductInfo6_GetProductionWriteMethod([In][ComAliasName("Cummins.Interop.MetadataComponent.CIInstProtocolEnum")] CIInstProtocolEnum instructionProtocol);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void ICIProductInfo6_GetParameterInfo([In][MarshalAs(UnmanagedType.BStr)] string groupID, [In][MarshalAs(UnmanagedType.BStr)] string bstrParameterName, out int lLocation, out int lOffset, out int lLength, [ComAliasName("Cummins.Interop.MetadataComponent.CIParameterDiscriminatorEnum")] out CIParameterDiscriminatorEnum discriminator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection ICIProductInfo6_GetPhaseRules();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection ICIProductInfo6_GetSupportedApplicationIDs();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern ICICollection ICIProductInfo6_GetSupportedDataStructures([In][MarshalAs(UnmanagedType.BStr)] string bstrPhase);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern CIDetectionRule ICIProductInfo6_GetDetectionRule();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int ICIProductInfo6_GetDataCollectorBaseRate([In][MarshalAs(UnmanagedType.BStr)] string bstrPhase);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern int ICIProductInfo6_GetNonProductionDownLoadPacketSizeByProtocol([In][ComAliasName("Cummins.Interop.MetadataComponent.CIDeviceProtocolEnum")] CIDeviceProtocolEnum deviceProtocol);
}
[ComImport]
[Guid("A3A57D8E-A1EB-406A-B097-9428EF6FEB3D")]
[CoClass(typeof(CIProductInfoClass))]
public interface CIProductInfo : ICIProductInfo
{
}
[ComImport]
[ClassInterface(0)]
[Guid("991E0147-9F5E-4D50-AD59-4BE7B725D52D")]
public class CIDetectionRuleClass : ICIDetectionRule, CIDetectionRule
{
	[ComAliasName("Cummins.Interop.MetadataComponent.CIDetectionModeEnum")]
	[DispId(1)]
	public virtual extern CIDetectionModeEnum DetectionMode
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: ComAliasName("Cummins.Interop.MetadataComponent.CIDetectionModeEnum")]
		get;
	}

	[DispId(2)]
	public virtual extern ICICollection StaticAddresses
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[Guid("E5A42348-2082-4534-974A-10C9CB9D4343")]
[CoClass(typeof(CIDetectionRuleClass))]
public interface CIDetectionRule : ICIDetectionRule
{
}
[ComImport]
[Guid("08822FC9-B1DC-4912-9360-3085B91264DF")]
[ClassInterface(0)]
public class CIPhaseRuleClass : ICIPhaseRule, CIPhaseRule
{
	[DispId(1)]
	public virtual extern string Phase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	public virtual extern object Version
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(3)]
	public virtual extern string ECM_ID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[Guid("FCF2A3BA-70B1-46AD-8D22-B227D56EC879")]
[CoClass(typeof(CIPhaseRuleClass))]
public interface CIPhaseRule : ICIPhaseRule
{
}
[ComImport]
[Guid("313A4663-B605-4FC2-9DFC-AF1D40715C40")]
[ClassInterface(0)]
public class CIApplicationIDClass : ICIApplicationID, CIApplicationID
{
	[DispId(1)]
	public virtual extern string ApplicationID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	public virtual extern void GetApplicationIDDetails(out int lLocation, out int lOffset, out int lLength);
}
[ComImport]
[CoClass(typeof(CIApplicationIDClass))]
[Guid("BD1A18C0-64CA-4CEB-9EF9-68173C4195B2")]
public interface CIApplicationID : ICIApplicationID
{
}
[ComImport]
[Guid("74952C24-F4FA-403B-81E3-91C861EE2607")]
[ClassInterface(0)]
public class CIDataStructureClass : ICIDataStructure, CIDataStructure
{
	[DispId(1)]
	public virtual extern string Phase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(2)]
	public virtual extern string ParameterDefinition
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(3)]
	public virtual extern string BitMapping
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(3)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(4)]
	public virtual extern string Location
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(4)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[Guid("7711B383-D1B6-44E4-A125-26AC2C6E7C4F")]
[CoClass(typeof(CIDataStructureClass))]
public interface CIDataStructure : ICIDataStructure
{
}
[ComImport]
[ClassInterface(0)]
[Guid("739077DB-501C-46A0-9162-858101439E33")]
[TypeLibType(2)]
public class CIGenericConfigFileClass : ICIGenericConfigFile, CIGenericConfigFile
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetGenericConfigFileForDownload([In][ComAliasName("Cummins.Interop.MetadataComponent.CIGTISConfigLevelEnum")] CIGTISConfigLevelEnum gtisConfigLevel);
}
[ComImport]
[CoClass(typeof(CIGenericConfigFileClass))]
[Guid("728ADD32-879B-473D-8959-18A2AAA7EE7B")]
public interface CIGenericConfigFile : ICIGenericConfigFile
{
}
