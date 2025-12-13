using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: ImportedFromTypeLib("MENUBAREVENTSLib")]
[assembly: TypeLibVersion(1, 0)]
[assembly: Guid("BD88875F-49BD-403A-9804-BC0384CC5E22")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace MENUBAREVENTSLib;

[ComImport]
[Guid("EE830910-62E8-4D83-A26F-67D02BE16348")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface IMenuBarEvents
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void FireMenuEvent([In] int nMenuID);
}
