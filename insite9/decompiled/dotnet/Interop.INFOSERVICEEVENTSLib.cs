using System.Reflection;
using System.Runtime.InteropServices;

[assembly: ImportedFromTypeLib("INFOSERVICEEVENTSLib")]
[assembly: TypeLibVersion(1, 0)]
[assembly: Guid("91644138-6440-4CD3-8404-82FE201287A7")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace INFOSERVICEEVENTSLib;

[ComImport]
[Guid("2BF76846-BA6D-4055-AE8A-0DF40E6F42F2")]
[TypeLibType(TypeLibTypeFlags.FDispatchable)]
[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
public interface _IInformationServiceEvents
{
}
