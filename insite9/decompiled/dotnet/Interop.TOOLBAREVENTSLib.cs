using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: ImportedFromTypeLib("TOOLBAREVENTSLib")]
[assembly: TypeLibVersion(1, 0)]
[assembly: Guid("77FC7918-C5BB-4DF4-ADE7-E0873496FD02")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace Cummins.INSITE.Excecutable.ToolBarEvents;

[ComImport]
[Guid("C37B1D45-DD5B-4D54-B3D7-A74DF1773623")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IToolBarEvents
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void FireToolBarEvent([In] int nButtonID);
}
