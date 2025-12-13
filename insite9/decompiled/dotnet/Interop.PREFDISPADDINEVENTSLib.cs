using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: Guid("CCAF00A3-7916-11D4-94AB-005004295E31")]
[assembly: ImportedFromTypeLib("PREFDISPADDINEVENTSLib")]
[assembly: TypeLibVersion(1, 0)]
[assembly: AssemblyVersion("7.6.0.272")]
namespace PREFDISPADDINEVENTSLib;

[ComImport]
[Guid("14542E65-7845-11D4-94AA-005004295E31")]
[TypeLibType(TypeLibTypeFlags.FDual | TypeLibTypeFlags.FDispatchable)]
public interface _IPrefDispEvents
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1)]
	void GroupChanged(int lGroupNum);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(2)]
	void PurgeRequested([MarshalAs(UnmanagedType.BStr)] string identifier, [MarshalAs(UnmanagedType.BStr)] string path);
}
