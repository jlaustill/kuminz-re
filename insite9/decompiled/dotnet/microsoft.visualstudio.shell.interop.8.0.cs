using System;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Microsoft.VisualStudio.OLE.Interop;
using Microsoft.VisualStudio.TextManager.Interop;

[assembly: ImportedFromTypeLib("VsShell")]
[assembly: Guid("09a411cb-0b94-4dc8-957b-eb5b13edb47c")]
[assembly: TypeLibVersion(8, 0)]
[assembly: AssemblyVersion("8.0.0.0")]
namespace Microsoft.VisualStudio.Shell.Interop
{
	[Guid("73E59688-C7C4-4A85-AF64-A538754784C5")]
	public interface SVSMDCodeDomProvider
	{
	}
	[Guid("74946829-37A0-11D2-A273-00C04F8EF4FF")]
	public interface SVSMDDesignerService
	{
	}
	[Guid("74946810-37A0-11D2-A273-00C04F8EF4FF")]
	public interface SVSMDPropertyBrowser
	{
	}
	[Guid("3411DD99-2445-43C8-918E-99BFBFAF8292")]
	public interface SVSMDTypeResolutionService
	{
	}
	[Guid("5403AC85-C8C8-4967-BDB0-662D485F0C28")]
	public interface SDirList
	{
	}
	[Guid("CA8A686A-0882-4E79-BCA3-AF3F3AB3EB8A")]
	public interface SVsIntegratedHelp
	{
	}
	[Guid("95FC88C3-9FCB-11CF-A405-00AA00C00940")]
	public interface SBuilderWizardManager
	{
	}
}
namespace VSLangProj
{
	[Guid("0B48100A-473E-433C-AB8F-66B9739AB620")]
	public interface SVsProjectItem
	{
	}
}
namespace Microsoft.VisualStudio.OLE.Interop
{
	[Guid("D001F200-EF97-11CE-9BC9-00AA00608E01")]
	public interface SOleUndoManager
	{
	}
	[Guid("B722BE00-4E68-101B-A2BC-00AA00404770")]
	public interface SContainerDispatch
	{
	}
	[Guid("FC4801A1-2BA9-11CF-A229-00AA003D7352")]
	public interface SBindHost
	{
	}
}
namespace Microsoft.VisualStudio.VSHelp
{
	[Guid("4A791148-19E4-11d3-B86B-00C04F79F802")]
	public interface SVsHelp
	{
	}
}
namespace Microsoft.VisualStudio.Shell.Interop
{
	[Guid("CCCECEE2-D225-4294-858E-2B8C3F7D84EA")]
	public interface SWebApplicationCtxSvc
	{
	}
	[Guid("05B4B4B7-6A9D-4A70-BDB1-04CBB26C9248")]
	public interface SWebFileCtxService
	{
	}
	public abstract class ShellGuids80
	{
		[MarshalAs(UnmanagedType.LPStr)]
		public const string SolutionFolderProject = "{2150E333-8FDC-42A3-9474-1A3956D46DE8}";
	}
	public abstract class ToolWindowGuids80
	{
		[MarshalAs(UnmanagedType.LPStr)]
		public const string Autos = "{F2E84780-2AF1-11D1-A7FA-00A0C9110051}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string BookmarkWindow = "{A0C5197D-0AC7-4B63-97CD-8872A789D233}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Breakpoints = "{BE4D7042-BA3F-11D2-840E-00C04F9902C1}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string BrowserDoc = "{6B8E94B4-0949-4D9C-A81F-C1B9B744185C}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string CallBrowserWindow = "{5415EA3A-D813-4948-B51E-562082CE0887}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string CallBrowserSecondaryWindow = "{F78BCC56-71F7-4E7D-8215-F690CAE4F452}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string CallStack = "{0504FF91-9D61-11D0-A794-00A0C9110051}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ClassDetails = "{778B5376-AD77-4751-ACDC-F3D18343F8DD}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ClassView = "{C9C0AE26-AA77-11D2-B3F0-0000F87570EE}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string CodedefinitionWindow = "{588470CC-84F8-4A57-9AC4-86BCA0625FF4}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string CommandWindow = "{28836128-FC2C-11D2-A433-00C04F72D18A}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ConsoleIO = "{FC29E0C0-C1AB-4B30-B5DF-24AA452B9661}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string DataSourceWindow = "{873151D0-CF2E-48CC-B4BF-AD0394F6A3C3}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string DefinitionWindow = "{5B6781C0-E99D-11D0-9954-00A0C91BC8E6}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Disassembly = "{CF577B8C-4134-11D2-83E5-00C04F9902C1}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string DocumentOutline = "{25F7E850-FFA1-11D0-B63F-00A0C922E851}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ContextWindow = "{66DBA47C-61DF-11D2-AA79-00C04F990343}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ErrorList = "{D78612C7-9962-4B83-95D9-268046DAD23A}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Find1 = "{0F887920-C2B6-11D2-9375-0080C747D9A0}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Find2 = "{0F887921-C2B6-11D2-9375-0080C747D9A0}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string FindInFiles = "{E830EC50-C2B5-11D2-9375-0080C747D9A0}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string FindAdvanced = "{E830EC50-C2B5-11D2-9375-0080C747D9A0}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ObjectSearchResultsWindow = "{68487888-204A-11D3-87EB-00C04F7971A5}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ObjectSearchWindow = "{53024D34-0EF5-11D3-87E0-00C04F7971A5}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string FindReplace = "{CF2DDC32-8CAD-11D2-9302-005345000000}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string HelpFavorites = "{57DC5D59-11C2-4955-A7B4-D7699D677E93}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string HelpHowDoI = "{4A78E230-DCCB-44DF-95CF-22EE6E2459BB}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Helpindex = "{73F6DD58-437E-11D3-B88E-00C04F79F802}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string HelpIndexResults = "{73F6DD5B-437E-11D3-B88E-00C04F79F802}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string HelpSearch = "{46C87F81-5A06-43A8-9E25-85D33BAC49F8}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ImmediateWindow = "{ECB7191A-597B-41F5-9843-03A4CF275DDE}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string IVSMDPropertyBrowser = "{74946810-37A0-11D2-A273-00C04F8EF4FF}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string LocalChanges = "{53544C4D-5C18-11D3-AB71-0050040AE094}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Locals = "{4A18F9D0-B838-11D0-93EB-00A0C90F2734}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string MacroExplorer = "{07CD18B4-3BA1-11D2-890A-0060083196C6}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Memory = "{350F9856-A72B-11D2-8AD0-00C04F79E479}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Modules = "{37ABA9BE-445A-11D3-9949-00C04F68FD0A}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ObjectBrowser = "{269A02DC-6AF8-11D3-BDC4-00C04F688E50}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ObjectTestBench = "{FDFFCCF2-5F63-404F-86AD-33693F544948}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Outputwindow = "{34E76E81-EE4A-11D0-AE2E-00A0C90FFFC3}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string PortDetails = "{B869198C-F673-46D2-83AE-64F515277716}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Processes = "{51C76317-9037-4CF2-A20A-6206FD30B4A1}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string PropertiesWindow = "{EEFA5220-E298-11D0-8F78-00A0C9110057}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string PropertySheetManager = "{6B8E94B5-0949-4D9C-A81F-C1B9B744185C}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Registers = "{CA4B8FF5-BFC7-11D2-9929-00C04F68FDAF}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ResourceView = "{2D7728C2-DE0A-45B5-99AA-89B609DFDE73}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string RunningDocuments = "{ECDD9EE0-AC6B-11D0-89F9-00A0C9110055}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string SdmDesignerTransactions = "{6F409264-641B-46E4-99A8-F6B65654AFF4}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ServerExplorer = "{74946827-37A0-11D2-A273-00C04F8EF4FF}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string SettingsandConstraints = "{B8399B49-7330-487B-9235-7D2E969D0A79}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string SolutionExplorer = "{3AE79031-E1BC-11D0-8F78-00A0C9110057}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string StartPage = "{387CB18D-6153-4156-9257-9AC3F9207BBE}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string StyleOrganizerToolWindow = "{A764E899-518D-11D2-9A89-00C04F79EFC3}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string SystemView = "{9F3EC988-1174-4746-A66A-3969715D1FC7}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Tableofcontents = "{4A791147-19E4-11D3-B86B-00C04F79F802}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string TaskList = "{4A9B7E51-AA16-11D0-A8C5-00A0C921A4D2}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Threads = "{E62CE6A0-B439-11D0-A79D-00A0C9110051}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Toolbox = "{B1E99781-AB81-11D0-B683-00AA00A3EE26}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string TrinityDataWindow = "{983CA650-95A7-4A43-822A-2960D4BD0D7D}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string UAMSynchronizations = "{A94C758F-EFB0-4975-BF86-C87B59FDB45D}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string VCColorPalette = "{5B6781C0-E99D-11D0-9954-00A0C91BC8E5}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string VCPropertyManager = "{DE1FC918-F32E-4DD7-A915-1792A051F26B}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Watch = "{90243340-BD7A-11D0-93EF-00A0C90F2734}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string WebBrowserPreviewWindow = "{E8B06F53-6D01-11D2-AA7D-00C04F990343}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string WebBrowserWindow = "{E8B06F52-6D01-11D2-AA7D-00C04F990343}";
	}
	public abstract class ToolWindowGuids
	{
		[MarshalAs(UnmanagedType.LPStr)]
		public const string Toolbox = "{B1E99781-AB81-11D0-B683-00AA00A3EE26}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string PropertyBrowser = "{EEFA5220-E298-11D0-8F78-00A0C9110057}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string SolutionExplorer = "{3AE79031-E1BC-11D0-8F78-00A0C9110057}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Outputwindow = "{34E76E81-EE4A-11D0-AE2E-00A0C90FFFC3}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string DocOutline = "{25F7E850-FFA1-11D0-B63F-00A0C922E851}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string TaskList = "{4A9B7E51-AA16-11D0-A8C5-00A0C921A4D2}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ServerExplorer = "{74946827-37A0-11D2-A273-00C04F8EF4FF}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string MacroExplorer = "{07CD18B4-3BA1-11D2-890A-0060083196C6}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ContextWindow = "{66DBA47C-61DF-11D2-AA79-00C04F990343}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ClassView = "{C9C0AE26-AA77-11D2-B3F0-0000F87570EE}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ResourceView = "{2D7728C2-DE0A-45B5-99AA-89B609DFDE73}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ObjectSearchWindow = "{53024D34-0EF5-11D3-87E0-00C04F7971A5}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string CommandWindow = "{28836128-FC2C-11D2-A433-00C04F72D18A}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ObjectSearchResultsWindow = "{68487888-204A-11D3-87EB-00C04F7971A5}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ObjectBrowser = "{269A02DC-6AF8-11D3-BDC4-00C04F688E50}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string BrowserDoc = "{6B8E94B4-0949-4D9C-A81F-C1B9B744185C}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string FindReplace = "{CF2DDC32-8CAD-11D2-9302-005345000000}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string FindAdvanced = "{E830EC50-C2B5-11D2-9375-0080C747D9A0}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string FindResults1 = "{0F887920-C2B6-11D2-9375-0080C747D9A0}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string FindResults2 = "{0F887921-C2B6-11D2-9375-0080C747D9A0}";
	}
	public abstract class UIContextGuids80
	{
		[MarshalAs(UnmanagedType.LPStr)]
		public const string SolutionBuilding = "{ADFC4E60-0397-11D1-9F4E-00A0C911004F}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Debugging = "{ADFC4E61-0397-11D1-9F4E-00A0C911004F}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Dragging = "{B706F393-2E5B-49E7-9E2E-B1825F639B63}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string FullScreenMode = "{ADFC4E62-0397-11D1-9F4E-00A0C911004F}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string DesignMode = "{ADFC4E63-0397-11D1-9F4E-00A0C911004F}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string NoSolution = "{ADFC4E64-0397-11D1-9F4E-00A0C911004F}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string SolutionExists = "{F1536EF8-92EC-443C-9ED7-FDADF150DA82}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string EmptySolution = "{ADFC4E65-0397-11D1-9F4E-00A0C911004F}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string SolutionHasSingleProject = "{ADFC4E66-0397-11D1-9F4E-00A0C911004F}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string SolutionHasMultipleProjects = "{93694FA0-0397-11D1-9F4E-00A0C911004F}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string CodeWindow = "{8FE2DF1D-E0DA-4EBE-9D5C-415D40E487B5}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string NotBuildingAndNotDebugging = "{48EA4A80-F14E-4107-88FA-8D0016F30B9C}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string SolutionOrProjectUpgrading = "{EF4F870B-7B85-4F29-9D15-CE1ABFBE733B}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string DataSourceWindowSupported = "{95C314C4-660B-4627-9F82-1BAF1C764BBF}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string DataSourceWindowAutoVisible = "{2E78870D-AC7C-4460-A4A1-3FE37D00EF81}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string WindowsFormsDesigner = "{BA09E2AF-9DF2-4068-B2F0-4C7E5CC19E2F}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ToolboxInitialized = "{DC5DB425-F0FD-4403-96A1-F475CDBA9EE0}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string SolutionExistsAndNotBuildingAndNotDebugging = "{D0E4DEEC-1B53-4cda-8559-D454583AD23B}";
	}
	public abstract class UIContextGuids
	{
		[MarshalAs(UnmanagedType.LPStr)]
		public const string SolutionBuilding = "{ADFC4E60-0397-11D1-9F4E-00A0C911004F}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Debugging = "{ADFC4E61-0397-11D1-9F4E-00A0C911004F}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Dragging = "{B706F393-2E5B-49E7-9E2E-B1825F639B63}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string FullScreenMode = "{ADFC4E62-0397-11D1-9F4E-00A0C911004F}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string DesignMode = "{ADFC4E63-0397-11D1-9F4E-00A0C911004F}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string NoSolution = "{ADFC4E64-0397-11D1-9F4E-00A0C911004F}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string SolutionExists = "{F1536EF8-92EC-443C-9ED7-FDADF150DA82}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string EmptySolution = "{ADFC4E65-0397-11D1-9F4E-00A0C911004F}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string SolutionHasSingleProject = "{ADFC4E66-0397-11D1-9F4E-00A0C911004F}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string SolutionHasMultipleProjects = "{93694FA0-0397-11D1-9F4E-00A0C911004F}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string CodeWindow = "{8FE2DF1D-E0DA-4EBE-9D5C-415D40E487B5}";
	}
	public abstract class TaskListViews
	{
		[MarshalAs(UnmanagedType.LPStr)]
		public const string All = "{1880202e-fc20-11d2-8bb1-00c04f8ec28c}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string UserTasks = "{1880202f-fc20-11d2-8bb1-00c04f8ec28c}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ShortcutTasks = "{18802030-fc20-11d2-8bb1-00c04f8ec28c}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string HTMLTasks = "{36ac1c0d-fe86-11d2-8bb1-00c04f8ec28c}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string CompilerTasks = "{18802033-fc20-11d2-8bb1-00c04f8ec28c}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string CommentTasks = "{18802034-fc20-11d2-8bb1-00c04f8ec28c}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string CurrentFileTasks = "{18802035-fc20-11d2-8bb1-00c04f8ec28c}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string CheckedTasks = "{18802036-fc20-11d2-8bb1-00c04f8ec28c}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string UncheckedTasks = "{18802037-fc20-11d2-8bb1-00c04f8ec28c}";
	}
	public abstract class LogicalViewID
	{
		[MarshalAs(UnmanagedType.LPStr)]
		public const string Primary = "{00000000-0000-0000-0000-000000000000}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Any = "{FFFFFFFF-FFFF-FFFF-FFFF-FFFFFFFFFFFF}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Debugging = "{7651A700-06E5-11D1-8EBD-00A0C90F26EA}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Code = "{7651A701-06E5-11D1-8EBD-00A0C90F26EA}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Designer = "{7651A702-06E5-11D1-8EBD-00A0C90F26EA}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string TextView = "{7651A703-06E5-11D1-8EBD-00A0C90F26EA}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string UserChooseView = "{7651A704-06E5-11D1-8EBD-00A0C90F26EA}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ProjectSpecificEditor = "{80A3471A-6B87-433E-A75A-9D461DE0645F}";
	}
	public abstract class BuildOutputGroup
	{
		[MarshalAs(UnmanagedType.LPStr)]
		public const string SourceFiles = "SourceFiles";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Built = "Built";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ContentFiles = "ContentFiles";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string LocalizedResourceDlls = "LocalizedResourceDlls";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Documentation = "Documentation";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Symbols = "Symbols";
	}
	[ComImport]
	[Guid("F1DDC2C2-DF76-4EBB-9DE8-48AD2557062C")]
	[InterfaceType(1)]
	public interface SVsSourceControl
	{
	}
	[ComImport]
	[Guid("8D0AA9CC-8465-42F3-AD6E-DFDE28CCC75D")]
	[InterfaceType(1)]
	public interface SExtensionManager
	{
	}
	[ComImport]
	[Guid("04A72314-32E9-48E2-9B87-A63603454F3E")]
	[InterfaceType(1)]
	public interface SDTE
	{
	}
	public abstract class DTECatID
	{
		[MarshalAs(UnmanagedType.LPStr)]
		public const string Solution = "{52AEFF70-BBD8-11d2-8598-006097C68E81}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string SolutionBrowseObject = "{A2392464-7C22-11d3-BDCA-00C04F688E50}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string MiscFilesProject = "{610d4612-d0d5-11d2-8599-006097c68e81}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string MiscFilesProjectItem = "{610d4613-d0d5-11d2-8599-006097c68e81}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string GenericProject = "{610d4616-d0d5-11d2-8599-006097c68e81}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Document = "{610d4611-d0d5-11d2-8599-006097c68e81}";
	}
	public abstract class FontsAndColorsCategory
	{
		[MarshalAs(UnmanagedType.LPStr)]
		public const string TextOutputToolWindows = "{C34C709B-C855-459e-B38C-3021F162D3B1}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Printer = "{47724E70-AF55-48fb-A928-BB161C1D0C05}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Tooltip = "{A9A5637F-B2A8-422e-8FB5-DFB4625F0111}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string StatementCompletion = "{C1614BB1-734F-4a31-BD42-5AE6275E16D2}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Outputwindow = "{9973EFDF-317D-431c-8BC1-5E88CBFD4F7F}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string FindResults = "{5C48B2CB-0366-4fbf-9786-0BB37E945687}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string CommandWindow = "{EE1BE240-4E81-4beb-8EEA-54322B6B1BF5}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string SystemWindow = "{7E50DA68-A928-4d87-BEA4-E9F88AEC218C}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ImmediateWindow = "{6BB65C5A-2F31-4bde-9F48-8A38DC0C63E7}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string DialogsAndToolWindows = "{1F987C00-E7C4-4869-8A17-23FD602268B0}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string TextEditor = "{A27B4E24-A735-4d1d-B8E7-9716E1E3D8E0}";
	}
	public enum VSErrorCodes80
	{
		VS_E_MIGRATIONREQUIRESRELOAD = -2147213338,
		VS_E_SYNCHRONOUSOPENREQUIRED,
		VS_E_VSSETTINGS_INVALIDVERSION,
		VS_E_DOCUMENTOPENNOTTRUSTED
	}
	public enum __VSFORMATINDEX
	{
		VSFORMATINDEX_UTF8,
		VSFORMATINDEX_MBCS,
		VSFORMATINDEX_UNICODE
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("4C5F0CEB-5AC9-4EA4-85E2-72E088EA75A8")]
	public interface IVsProjectDebugTargetProvider
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SupplyDebugTarget([MarshalAs(UnmanagedType.BStr)] out string pbstrTarget, [MarshalAs(UnmanagedType.BStr)] out string pbstrCommandLine);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("4C5F0CEA-5AC9-4EA4-85E2-72E088EA75A8")]
	public interface IVsRegisterProjectDebugTargetProvider
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddDebugTargetProvider([In][MarshalAs(UnmanagedType.Interface)] IVsProjectDebugTargetProvider pNewDbgTrgtProvider, [MarshalAs(UnmanagedType.Interface)] out IVsProjectDebugTargetProvider ppNextDbgTrgtProvider);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RemoveDebugTargetProvider([In][MarshalAs(UnmanagedType.Interface)] IVsProjectDebugTargetProvider pDbgTrgtProvider);
	}
	[ComImport]
	[Guid("6B25ED7D-E462-4BBA-B181-81D9F73FCD72")]
	[InterfaceType(1)]
	public interface SVsRegisterDebugTargetProvider
	{
	}
	[ComImport]
	[Guid("BC5B644E-7FD7-4A75-98CC-0C2C98AA96F6")]
	[InterfaceType(1)]
	public interface IVsBrowseObject
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetProjectItem([MarshalAs(UnmanagedType.Interface)] out IVsHierarchy pHier, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] out uint pItemid);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("A630CFF5-EB22-40B7-9464-5F8D4B98B1CB")]
	public interface IVsCfgBrowseObject : IVsBrowseObject
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		new int GetProjectItem([MarshalAs(UnmanagedType.Interface)] out IVsHierarchy pHier, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] out uint pItemid);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetCfg([MarshalAs(UnmanagedType.Interface)] out IVsCfg ppCfg);
	}
	public enum __VSHPROPID2
	{
		VSHPROPID_PropertyPagesCLSIDList = -2065,
		VSHPROPID_CfgPropertyPagesCLSIDList = -2066,
		VSHPROPID_ExtObjectCATID = -2067,
		VSHPROPID_BrowseObjectCATID = -2068,
		VSHPROPID_CfgBrowseObjectCATID = -2069,
		VSHPROPID_AddItemTemplatesGuid = -2070,
		VSHPROPID_ChildrenEnumerated = -2071,
		VSHPROPID_StatusBarClientText = -2072,
		VSHPROPID_DebuggeeProcessId = -2073,
		VSHPROPID_IsLinkFile = -2074,
		VSHPROPID_KeepAliveDocument = -2075,
		VSHPROPID_SupportsProjectDesigner = -2076,
		VSHPROPID_IntellisenseUnknown = -2077,
		VSHPROPID_IsUpgradeRequired = -2078,
		VSHPROPID_DesignerHiddenCodeGeneration = -2079,
		VSHPROPID_SuppressOutOfDateMessageOnBuild = -2080,
		VSHPROPID_Container = -2081,
		VSHPROPID_UseInnerHierarchyIconList = -2082,
		VSHPROPID_EnableDataSourceWindow = -2083,
		VSHPROPID_AppTitleBarTopHierarchyName = -2084,
		VSHPROPID_DebuggerSourcePaths = -2085,
		VSHPROPID_CategoryGuid = -2086,
		VSHPROPID_DisableApplicationSettings = -2087,
		VSHPROPID_ProjectDesignerEditor = -2088,
		VSHPROPID_PriorityPropertyPagesCLSIDList = -2089,
		VSHPROPID_NoDefaultNestedHierSorting = -2090,
		VSHPROPID_ExcludeFromExportItemTemplate = -2091,
		VSHPROPID_SupportedMyApplicationTypes = -2092,
		VSHPROPID_FIRST2 = -2092
	}
	public enum __VSDESIGNER_HIDDENCODEGENERATION
	{
		VSDHCG_Declarations = 1,
		VSDHCG_InitMethods = 2,
		VSDHCG_EventMethods = 4
	}
	public enum _ProjectLoadSecurityDialogState
	{
		PLSDS_ShowAgain = 1,
		PLSDS_DontShowAgainBrowse,
		PLSDS_DontShowAgainFullLoad,
		PLSDS_DontShowAgainUnload
	}
	public enum __VSPROPID2
	{
		VSPROPID_IsSolutionNodeHidden = -8017,
		VSPROPID_DeferredSaveSolution = -8018,
		VSPROPID_SimplifiedConfigurations = -8019,
		VSPROPID_IsSolutionClosing = -8020,
		VSPROPID_IsAProjectClosing = -8021,
		VSPROPID_IsSolutionOpeningDocs = -8022,
		VSPROPID_IsOpenNotificationPending = -8023,
		VSPROPID_ProjectLoadSecurityDialogState = -8024,
		VSPROPID_SolutionUserFileCreatedOnThisComputer = -8025,
		VSPROPID_NewProjectDlgPreferredLanguage = -8026,
		VSPROPID_FIRST2 = -8026
	}
	public enum __VSCFGPROPID2
	{
		VSCFGPROPID_HideConfigurations = -16009,
		VSCFGPROPID_FIRST2 = -16009
	}
	[Flags]
	public enum __VSCREATEPROJFLAGS2
	{
		CPF_DEFERREDSAVE = 0x80,
		CPF_OPEN_ASYNCHRONOUSLY = 0x100,
		CPF_OPEN_STANDALONE = 0x200
	}
	[Flags]
	public enum __VSCREATESOLUTIONFLAGS2
	{
		CSF_HIDESOLUTIONNODEALWAYS = 0x10,
		CSF_DEFERREDSAVESOLUTION = 0x20
	}
	public enum __VSSLNOPENOPTIONS2
	{
		SLNOPENOPT_LoadingAsync = 8
	}
	[Flags]
	public enum __VSADDITEMFLAGS2
	{
		VSADDITEM_NoUserTemplateFeatures = 0x1000,
		VSADDITEM_ShowOpenButtonDropDown = 0x40000
	}
	[Flags]
	public enum __VSCREATEEDITORFLAGS2
	{
		CEF_OPENSPECIFIC = 0x10
	}
	[Flags]
	public enum __VSOSEFLAGS2
	{
		OSE_CheckTrustLevelOfWizard = 0x100000
	}
	[Flags]
	public enum __VSOSPEFLAGS2
	{
		OSPE_CheckTrustLevelOfWizard = 0x100000
	}
	public enum __VSWIZARDTRUSTLEVEL
	{
		WTL_Trusted = 1,
		WTL_Untrusted,
		WTL_Unspecified
	}
	public enum __VSEDITORTRUSTLEVEL
	{
		ETL_NeverTrusted,
		ETL_AlwaysTrusted,
		ETL_HasUntrustedLogicalViews
	}
	[ComImport]
	[Guid("42085C99-3F5B-4B61-9737-592479718CEC")]
	[InterfaceType(1)]
	public interface IVsDetermineWizardTrust
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnWizardInitiated([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszTemplateFilename, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidProjectType);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnWizardCompleted();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsWizardRunning([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfWizardRunning);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetRunningWizardTemplateName([MarshalAs(UnmanagedType.BStr)] out string pbstrRunningTemplate);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetWizardTrustLevel([ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSWIZARDTRUSTLEVEL")] out uint pdwWizardTrustLevel);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetWizardTrustLevel([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSWIZARDTRUSTLEVEL")] uint dwWizardTrustLevel);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("9A3B199D-2294-4DA6-9B43-7A4EAFE31FA0")]
	public interface SVsDetermineWizardTrust
	{
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("23EC4D20-54A9-4365-82C8-ABDFBA686ECF")]
	public interface IVsSolutionEvents4
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnAfterRenameProject([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnQueryChangeProjectParent([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy, [In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pNewParentHier, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] ref int pfCancel);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnAfterChangeProjectParent([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnAfterAsynchOpenProject([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fAdded);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("ED6AAB26-108F-4B4F-A57B-14D20982713D")]
	public interface IVsFireSolutionEvents2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FireOnAfterRenameProject([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FireOnQueryChangeProjectParent([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy, [In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pNewParentHier);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FireOnAfterChangeProjectParent([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FireOnAfterAsynchOpenProject([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fAdded);
	}
	[ComImport]
	[Guid("925E8559-17DF-494C-87DA-BBEE251702DE")]
	[InterfaceType(1)]
	public interface IVsPrioritizedSolutionEvents
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int PrioritizedOnAfterOpenProject([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fAdded);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int PrioritizedOnBeforeCloseProject([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fRemoved);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int PrioritizedOnAfterLoadProject([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pStubHierarchy, [In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pRealHierarchy);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int PrioritizedOnBeforeUnloadProject([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pRealHierarchy, [In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pStubHierarchy);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int PrioritizedOnAfterOpenSolution([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkReserved, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fNewSolution);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int PrioritizedOnBeforeCloseSolution([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkReserved);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int PrioritizedOnAfterCloseSolution([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkReserved);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int PrioritizedOnAfterMergeSolution([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkReserved);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int PrioritizedOnBeforeOpeningChildren([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int PrioritizedOnAfterOpeningChildren([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int PrioritizedOnBeforeClosingChildren([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int PrioritizedOnAfterClosingChildren([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int PrioritizedOnAfterRenameProject([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int PrioritizedOnAfterChangeProjectParent([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int PrioritizedOnAfterAsynchOpenProject([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fAdded);
	}
	[ComImport]
	[Guid("8D2EC486-8098-4AFA-AB94-D270A5EF08CE")]
	[InterfaceType(1)]
	public interface IVsPersistSolutionProps2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnSolutionLoadFailure([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszKey);
	}
	[Flags]
	public enum __VSDIRFLAGS2
	{
		VSDIRFLAG_RequiresNewFolder = 0x10,
		VSDIRFLAG_SolutionTemplate = 0x40,
		VSDIRFLAG_DeferredSaveProject = 0x80,
		VSDIRFLAG_DontShowNameLocInfo = 0x100,
		VSDIRFLAG_EnableMasterPage = 0x200,
		VSDIRFLAG_EnableCodeSeparation = 0x400,
		VSDIRFLAG_EnableLangDropdown = 0x800
	}
	public enum VSFRAMEMODE2
	{
		VSFM_AutoHide = 4
	}
	public enum __VSFPROPID2
	{
		VSFPROPID_OverrideDirtyState = -4014,
		VSFPROPID_OLEDocObjectDocument = -4015,
		VSFPROPID_ParentHwnd = -4016,
		VSFPROPID_ParentFrame = -4017,
		VSFPROPID_ToolWindowDocCookie = -4018
	}
	public enum __VSSPROPID2
	{
		VSSPROPID_SccProviderChanged = -9032,
		VSSPROPID_MainWindowSize = -9033,
		VSSPROPID_MainWindowPos = -9034,
		VSSPROPID_IsAcademic = -9035,
		VSSPROPID_IsAppThemed = -9036,
		VSSPROPID_VisualStudioDir = -9037,
		VSSPROPID_VsTemplateUserZipProjectFolder = -9038,
		VSSPROPID_VsTemplateUserZipItemFolder = -9039,
		VSSPROPID_InstallRootDir = -9041,
		VSSPROPID_SolutionExplorerSortingEnabled = -9042,
		VSSPROPID_BuildOutOfDateProjects = -9043,
		VSSPROPID_RunAfterBuildErrors = -9044,
		VSSPROPID_MainWindowVisibility = -9045,
		VSSPROPID_SKUEdition = -9046,
		VSSPROPID_SubSKUEdition = -9047,
		VSSPROPID_WaitingForSecondKeyChord = -9048,
		VSSPROPID_SqmRegistryRoot = -9049,
		VSSPROPID_AutohideToolFrame = -9050,
		VSFPROPID_ToolWindowUsesDocSelection = -9051,
		VSSPROPID_FIRST2 = -9051
	}
	public enum __BUILDOUTOFDATEPROJECTS
	{
		BUILDOUTOFDATEPROJECTS_YES = 0,
		BUILDOUTOFDATEPROJECTS_NO = 1,
		BUILDOUTOFDATEPROJECTS_PROMPT = 2,
		BUILDOUTOFDATEPROJECTS_MAX = 2
	}
	public enum __RUNAFTERBUILDERRORS
	{
		RUNAFTERBUILDERRORS_YES = 0,
		RUNAFTERBUILDERRORS_NO = 1,
		RUNAFTERBUILDERRORS_PROMPT = 2,
		RUNAFTERBUILDERRORS_MAX = 2
	}
	[Flags]
	public enum __VSDBGLAUNCHFLAGS2
	{
		DBGLAUNCH_MergeEnv = 0x80,
		DBGLAUNCH_DesignTimeExprEval = 0x100,
		DBGLAUNCH_StopAtEntryPoint = 0x200,
		DBGLAUNCH_CannotDebugAlone = 0x400
	}
	public enum _DEBUG_LAUNCH_OPERATION2
	{
		DLO_AttachToHostingProcess = 4,
		DLO_StartDebuggingHostingProcess
	}
	public enum __PSFFILEID2
	{
		PSFFILEID_WebSettings = -1002,
		PSFFILEID_AppManifest = -1003,
		PSFFILEID_AppDesigner = -1004,
		PSFFILEID_AppSettings = -1005,
		PSFFILEID_AssemblyResource = -1006,
		PSFFILEID_AssemblyInfo = -1007,
		PSFFILEID_FIRST2 = -1007
	}
	[Flags]
	public enum __PSFFLAGS2
	{
		PSFF_CheckoutIfExists = 4
	}
	public enum __VSEDT_STYLE
	{
		VSEDT_Reserved1 = 1
	}
	public enum __STOP_DEBUGGING_PROCESS_REASON
	{
		SDPR_DETACH,
		SDPR_TERMINATE
	}
	[ComImport]
	[Guid("B8092238-A091-42F1-A945-080B381FBCFC")]
	[InterfaceType(1)]
	public interface IVsEnhancedDataTip
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Show([In] IntPtr hwndOwner, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.POINT")][MarshalAs(UnmanagedType.LPArray)] POINT[] pptTopLeft, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] pHotRect);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetExpression([In][MarshalAs(UnmanagedType.BStr)] string bstrExpression);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetBaseWindowHandle(out IntPtr phwnd);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsErrorTip([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pbIsError);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsOpen([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pbIsOpen);
	}
	[StructLayout(LayoutKind.Sequential, Pack = 4)]
	[ComConversionLoss]
	public struct VsDebugTargetInfo2
	{
		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
		public uint cbSize;

		[ComAliasName("Microsoft.VisualStudio.Shell.Interop.DEBUG_LAUNCH_OPERATION2")]
		public uint dlo;

		[ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSDBGLAUNCHFLAGS2")]
		public uint LaunchFlags;

		[MarshalAs(UnmanagedType.BStr)]
		public string bstrRemoteMachine;

		[MarshalAs(UnmanagedType.BStr)]
		public string bstrExe;

		[MarshalAs(UnmanagedType.BStr)]
		public string bstrArg;

		[MarshalAs(UnmanagedType.BStr)]
		public string bstrCurDir;

		[MarshalAs(UnmanagedType.BStr)]
		public string bstrEnv;

		public Guid guidLaunchDebugEngine;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
		public uint dwDebugEngineCount;

		[ComConversionLoss]
		public IntPtr pDebugEngines;

		public Guid guidPortSupplier;

		[MarshalAs(UnmanagedType.BStr)]
		public string bstrPortName;

		[MarshalAs(UnmanagedType.BStr)]
		public string bstrOptions;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")]
		public uint hStdInput;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")]
		public uint hStdOutput;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")]
		public uint hStdError;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
		public int fSendToOutputWindow;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
		public uint dwProcessId;

		[MarshalAs(UnmanagedType.IUnknown)]
		public object pUnknown;

		public Guid guidProcessLanguage;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
		public uint dwReserved;
	}
	[ComImport]
	[Guid("B33300FB-FEFE-4E00-A74A-17A5EED1B1ED")]
	[InterfaceType(1)]
	public interface IVsDebugger2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LaunchDebugTargets2([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint DebugTargetCount, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VsDebugTargetInfo2")] IntPtr pDebugTargets);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ConfirmStopDebugging([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszMessage);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EnumDebugEngines([MarshalAs(UnmanagedType.Interface)] out IVsEnumGUID ppEnum);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetEngineName([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidEngine, [MarshalAs(UnmanagedType.BStr)] out string pbstrName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsEngineCompatible([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidEngine, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint EngineCount, [In][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] Guid[] pEngineGUIDs);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetConsoleHandlesForProcess([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwPid, out ulong pdwStdInput, out ulong pdwStdOutput, out ulong pdwStdError);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ShowSource([In][MarshalAs(UnmanagedType.IUnknown)] object pUnkDebugDocContext, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fMakeActive, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fAlwaysMoveCaret, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fPromptToFindSource, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fIgnoreIfNotFound, [MarshalAs(UnmanagedType.Interface)] out IVsTextView ppTextView);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CreateDataTip([In][MarshalAs(UnmanagedType.BStr)] string bstrExpression, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSEDT_STYLE")] uint dwStyle, [MarshalAs(UnmanagedType.Interface)] out IVsEnhancedDataTip ppDataTip);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSymbolPath([MarshalAs(UnmanagedType.BStr)] out string pbstrSymbolPath, [MarshalAs(UnmanagedType.BStr)] out string pbstrSymbolCachePath);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetOutputHandleForProcess([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwPid, out ulong pOutputHandle);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int InsertBreakpointByName([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidLanguage, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszCodeLocationText, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int bUseIntellisense);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ToggleUseQuickConsoleOption([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fOnOff);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetUseQuickConsoleOptionSetting([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfValue);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetInternalDebugMode([Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.DBGMODE")][MarshalAs(UnmanagedType.LPArray)] DBGMODE[] pdbgmode);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("23320EFC-7C7A-4C3D-AD85-93A4E620FDD0")]
	public interface IVsDebugProcessNotify
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int BeforeStopDebuggingProcess([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.STOP_DEBUGGING_PROCESS_REASON")] uint Reason);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("CE25FCEE-9E4D-4EC8-856E-38E2BDB2E13B")]
	public interface IVsQueryDebuggableProjectCfg
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int QueryDebugTargets([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSDBGLAUNCHFLAGS")] uint grfLaunch, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cTargets, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VsDebugTargetInfo2")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] VsDebugTargetInfo2[] rgDebugTargetInfo, [Optional][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")][MarshalAs(UnmanagedType.LPArray)] uint[] pcActual);
	}
	public enum __VSOVERLAYICON2
	{
		OVERLAYICON_EXCLUDED = 5,
		OVERLAYICON_NOTONDISK = 6,
		OVERLAYICON_MAXINDEX2 = 6
	}
	public enum __VSMEPROPID2
	{
		VSMEPROPID_ICON = -1012,
		VSMEPROPID_LAST2 = -1012
	}
	public enum __COMMANDWINDOWMODE2
	{
		CWM_DEFAULT = -1
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("E22363B8-E7D3-49B5-B094-7395BB35CE13")]
	public interface IVsCommandWindow2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetMode([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.COMMANDWINDOWMODE2")] uint mode);
	}
	[ComImport]
	[Guid("F22A0AD5-8F51-4F66-A644-EA64770CF8B7")]
	[InterfaceType(1)]
	public interface IVsDeferredDocView
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_DocView(out IntPtr ppUnkDocView);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_CmdUIGuid(out Guid pGuidCmdId);
	}
	[Flags]
	public enum BuildableProjectCfgOpts
	{
		Rebuild = 1,
		BuildSelectionOnly = 2,
		BuildActiveDocumentOnly = 4,
		Private = -65536
	}
	public enum __VSBLDCFGPROPID
	{
		VSBLDCFGPROPID_LAST = -16000,
		VSBLDCFGPROPID_SupportsMTBuild = -16000,
		VSBLDCFGPROPID_FIRST = -16000
	}
	[ComImport]
	[Guid("09857E8E-74CC-43A7-993D-3EC774DCA298")]
	[InterfaceType(1)]
	public interface IVsBuildableProjectCfg2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetBuildCfgProperty([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSBLDCFGPROPID")] int propid, [MarshalAs(UnmanagedType.Struct)] out object pvar);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int StartBuildEx([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwBuildId, [In][MarshalAs(UnmanagedType.Interface)] IVsOutputWindowPane pIVsOutputWindowPane, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwOptions);
	}
	[ComImport]
	[Guid("279398E7-6FC1-40A2-9FB3-C321DB469E9B")]
	[InterfaceType(1)]
	public interface IVsPublishableProjectStatusCallback
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int PublishBegin([In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] ref int pfContinue);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int PublishEnd([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fSuccess);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Tick([In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] ref int pfContinue);
	}
	public enum __VSPUBLISHOPTS
	{
		PUBOPT_PUBLISHCONTEXT = 1
	}
	[ComImport]
	[Guid("816B2FBE-5C62-439E-8F67-8F0D5D82BC67")]
	[InterfaceType(1)]
	public interface IVsPublishableProjectCfg
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AdvisePublishStatusCallback([In][MarshalAs(UnmanagedType.Interface)] IVsPublishableProjectStatusCallback pIVsPublishStatusCallback, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] out uint pdwCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UnadvisePublishStatusCallback([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] uint dwCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int StartPublish([In][MarshalAs(UnmanagedType.Interface)] IVsOutputWindowPane pIVsOutputWindowPane, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwOptions);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int QueryStatusPublish([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfPublishDone);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int StopPublish([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fSync);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ShowPublishPrompt([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfContinue);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int QueryStartPublish([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwOptions, [Optional][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")][MarshalAs(UnmanagedType.LPArray)] int[] pfSupported, [Optional][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")][MarshalAs(UnmanagedType.LPArray)] int[] pfReady);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetPublishProperty([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSPUBLISHOPTS")] uint propid, [MarshalAs(UnmanagedType.Struct)] out object pvar);
	}
	[Flags]
	public enum VSSOLNBUILDUPDATEFLAGS2
	{
		SBF_OPERATION_PUBLISHUI = 0x800000,
		SBF_OPERATION_PUBLISH = 0x1000000
	}
	[ComImport]
	[Guid("7837DF15-0604-4EA1-8515-CD5A30972482")]
	[InterfaceType(1)]
	public interface IVsParseCommandLine2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetACParamOrSwitch(out int piACIndex, out int piACStart, out int pcchACLength, [MarshalAs(UnmanagedType.BStr)] out string pbstrCurSwitch, [MarshalAs(UnmanagedType.BStr)] out string pbstrACParam);
	}
	[ComImport]
	[Guid("615FF029-FEFA-492C-8CD2-C3F66644C3F9")]
	[InterfaceType(1)]
	public interface IVsCommandWindowsCollection
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Create([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.COMMANDWINDOWMODE2")] uint mode, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwToolWindowId, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fShow, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] out uint puCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OpenExistingOrCreateNewCommandWindow([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.COMMANDWINDOWMODE2")] uint mode, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fShow, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] out uint puCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetCommandWindowFromCookie([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] uint uCookie, [MarshalAs(UnmanagedType.IUnknown)] out object ppunkCmdWindow);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetCommandWindowFromMode([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.COMMANDWINDOWMODE2")] uint mode, [MarshalAs(UnmanagedType.IUnknown)] out object ppunkCmdWindow);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetRunningCommandWindowCommand([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] uint uCookie, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fCmdWin);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsOutputWaiting([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] uint uCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Close([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] uint uCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CloseAllCommandWindows();
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("E337F382-3CAB-44A5-AF0E-3DACA541C89A")]
	public interface SVsCommandWindowsCollection
	{
	}
	public enum __VSBACKGROUNDTASKPRIORITY
	{
		VSBACKGROUNDTASKPRIORITY_STANDARD,
		VSBACKGROUNDTASKPRIORITY_IMMEDIATE,
		VSBACKGROUNDTASKPRIORITY_OTHER
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("615FF0FB-A19B-4BC8-B9AF-372EA191BA46")]
	public interface IVsThreadPool
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ScheduleTask([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint pTaskProc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint pvParam, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSBACKGROUNDTASKPRIORITY")] uint priority);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ScheduleWaitableTask([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint hWait, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint pTaskProc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint pvParam);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UnscheduleWaitableTask([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint hWait);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("7482E83D-842A-447C-8DDB-687F7052F7C7")]
	public interface SVsThreadPool
	{
	}
	[StructLayout(LayoutKind.Sequential, Pack = 4)]
	public struct VSNSEBROWSEINFOW
	{
		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
		public uint lStructSize;

		[MarshalAs(UnmanagedType.LPWStr)]
		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")]
		public string pszNamespaceGUID;

		[MarshalAs(UnmanagedType.LPWStr)]
		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")]
		public string pszTrayDisplayName;

		[MarshalAs(UnmanagedType.LPWStr)]
		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")]
		public string pszProtocolPrefix;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
		public int fOnlyShowNSEInTray;
	}
	[StructLayout(LayoutKind.Sequential, Pack = 4)]
	public struct VSSAVETREEITEM
	{
		[ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSRDTSAVEOPTIONS")]
		public uint grfSave;

		[ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")]
		public uint docCookie;

		[MarshalAs(UnmanagedType.Interface)]
		public IVsHierarchy pHier;

		[ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")]
		public uint itemid;
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("F3519E2D-D5D2-4455-B9F4-5F61F993BD66")]
	public interface IVsShell2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LoadPackageStringWithLCID([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidPackage, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint resid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LCID")] uint lcid, [MarshalAs(UnmanagedType.BStr)] out string pbstrOut);
	}
	public enum __VSSYSCOLOREX
	{
		VSCOLOR_ACCENT_BORDER = -5,
		VSCOLOR_ACCENT_DARK = -6,
		VSCOLOR_ACCENT_LIGHT = -7,
		VSCOLOR_ACCENT_MEDIUM = -8,
		VSCOLOR_ACCENT_PALE = -9,
		VSCOLOR_COMMANDBAR_BORDER = -10,
		VSCOLOR_COMMANDBAR_DRAGHANDLE = -11,
		VSCOLOR_COMMANDBAR_DRAGHANDLE_SHADOW = -12,
		VSCOLOR_COMMANDBAR_GRADIENT_BEGIN = -13,
		VSCOLOR_COMMANDBAR_GRADIENT_END = -14,
		VSCOLOR_COMMANDBAR_GRADIENT_MIDDLE = -15,
		VSCOLOR_COMMANDBAR_HOVER = -16,
		VSCOLOR_COMMANDBAR_HOVEROVERSELECTED = -17,
		VSCOLOR_COMMANDBAR_HOVEROVERSELECTEDICON = -18,
		VSCOLOR_COMMANDBAR_HOVEROVERSELECTEDICON_BORDER = -19,
		VSCOLOR_COMMANDBAR_SELECTED = -20,
		VSCOLOR_COMMANDBAR_SHADOW = -21,
		VSCOLOR_COMMANDBAR_TEXT_ACTIVE = -22,
		VSCOLOR_COMMANDBAR_TEXT_HOVER = -23,
		VSCOLOR_COMMANDBAR_TEXT_INACTIVE = -24,
		VSCOLOR_COMMANDBAR_TEXT_SELECTED = -25,
		VSCOLOR_CONTROL_EDIT_HINTTEXT = -26,
		VSCOLOR_CONTROL_EDIT_REQUIRED_BACKGROUND = -27,
		VSCOLOR_CONTROL_EDIT_REQUIRED_HINTTEXT = -28,
		VSCOLOR_CONTROL_LINK_TEXT = -29,
		VSCOLOR_CONTROL_LINK_TEXT_HOVER = -30,
		VSCOLOR_CONTROL_LINK_TEXT_PRESSED = -31,
		VSCOLOR_CONTROL_OUTLINE = -32,
		VSCOLOR_DEBUGGER_DATATIP_ACTIVE_BACKGROUND = -33,
		VSCOLOR_DEBUGGER_DATATIP_ACTIVE_BORDER = -34,
		VSCOLOR_DEBUGGER_DATATIP_ACTIVE_HIGHLIGHT = -35,
		VSCOLOR_DEBUGGER_DATATIP_ACTIVE_HIGHLIGHTTEXT = -36,
		VSCOLOR_DEBUGGER_DATATIP_ACTIVE_SEPARATOR = -37,
		VSCOLOR_DEBUGGER_DATATIP_ACTIVE_TEXT = -38,
		VSCOLOR_DEBUGGER_DATATIP_INACTIVE_BACKGROUND = -39,
		VSCOLOR_DEBUGGER_DATATIP_INACTIVE_BORDER = -40,
		VSCOLOR_DEBUGGER_DATATIP_INACTIVE_HIGHLIGHT = -41,
		VSCOLOR_DEBUGGER_DATATIP_INACTIVE_HIGHLIGHTTEXT = -42,
		VSCOLOR_DEBUGGER_DATATIP_INACTIVE_SEPARATOR = -43,
		VSCOLOR_DEBUGGER_DATATIP_INACTIVE_TEXT = -44,
		VSCOLOR_DESIGNER_BACKGROUND = -45,
		VSCOLOR_DESIGNER_SELECTIONDOTS = -46,
		VSCOLOR_DESIGNER_TRAY = -47,
		VSCOLOR_DESIGNER_WATERMARK = -48,
		VSCOLOR_EDITOR_EXPANSION_BORDER = -49,
		VSCOLOR_EDITOR_EXPANSION_FILL = -50,
		VSCOLOR_EDITOR_EXPANSION_LINK = -51,
		VSCOLOR_EDITOR_EXPANSION_TEXT = -52,
		VSCOLOR_ENVIRONMENT_BACKGROUND = -53,
		VSCOLOR_ENVIRONMENT_BACKGROUND_GRADIENTBEGIN = -54,
		VSCOLOR_ENVIRONMENT_BACKGROUND_GRADIENTEND = -55,
		VSCOLOR_FILETAB_BORDER = -56,
		VSCOLOR_FILETAB_CHANNELBACKGROUND = -57,
		VSCOLOR_FILETAB_GRADIENTDARK = -58,
		VSCOLOR_FILETAB_GRADIENTLIGHT = -59,
		VSCOLOR_FILETAB_SELECTEDBACKGROUND = -60,
		VSCOLOR_FILETAB_SELECTEDBORDER = -61,
		VSCOLOR_FILETAB_SELECTEDTEXT = -62,
		VSCOLOR_FILETAB_TEXT = -63,
		VSCOLOR_FORMSMARTTAG_ACTIONTAG_BORDER = -64,
		VSCOLOR_FORMSMARTTAG_ACTIONTAG_FILL = -65,
		VSCOLOR_FORMSMARTTAG_OBJECTTAG_BORDER = -66,
		VSCOLOR_FORMSMARTTAG_OBJECTTAG_FILL = -67,
		VSCOLOR_GRID_HEADING_BACKGROUND = -68,
		VSCOLOR_GRID_HEADING_TEXT = -69,
		VSCOLOR_GRID_LINE = -70,
		VSCOLOR_HELP_HOWDOI_PANE_BACKGROUND = -71,
		VSCOLOR_HELP_HOWDOI_PANE_LINK = -72,
		VSCOLOR_HELP_HOWDOI_PANE_TEXT = -73,
		VSCOLOR_HELP_HOWDOI_TASK_BACKGROUND = -74,
		VSCOLOR_HELP_HOWDOI_TASK_LINK = -75,
		VSCOLOR_HELP_HOWDOI_TASK_TEXT = -76,
		VSCOLOR_HELP_SEARCH_FRAME_BACKGROUND = -77,
		VSCOLOR_HELP_SEARCH_FRAME_TEXT = -78,
		VSCOLOR_HELP_SEARCH_BORDER = -79,
		VSCOLOR_HELP_SEARCH_FITLER_TEXT = -80,
		VSCOLOR_HELP_SEARCH_FITLER_BACKGROUND = -81,
		VSCOLOR_HELP_SEARCH_FITLER_BORDER = -82,
		VSCOLOR_HELP_SEARCH_PROVIDER_UNSELECTED_BACKGROUND = -83,
		VSCOLOR_HELP_SEARCH_PROVIDER_UNSELECTED_TEXT = -84,
		VSCOLOR_HELP_SEARCH_PROVIDER_SELECTED_BACKGROUND = -85,
		VSCOLOR_HELP_SEARCH_PROVIDER_SELECTED_TEXT = -86,
		VSCOLOR_HELP_SEARCH_PROVIDER_ICON = -87,
		VSCOLOR_HELP_SEARCH_RESULT_LINK_SELECTED = -88,
		VSCOLOR_HELP_SEARCH_RESULT_LINK_UNSELECTED = -89,
		VSCOLOR_HELP_SEARCH_RESULT_SELECTED_BACKGROUND = -90,
		VSCOLOR_HELP_SEARCH_RESULT_SELECTED_TEXT = -91,
		VSCOLOR_HELP_SEARCH_BACKGROUND = -92,
		VSCOLOR_HELP_SEARCH_TEXT = -93,
		VSCOLOR_HELP_SEARCH_PANEL_RULES = -94,
		VSCOLOR_MDICLIENT_BORDER = -95,
		VSCOLOR_PANEL_BORDER = -96,
		VSCOLOR_PANEL_GRADIENTDARK = -97,
		VSCOLOR_PANEL_GRADIENTLIGHT = -98,
		VSCOLOR_PANEL_HOVEROVERCLOSE_BORDER = -99,
		VSCOLOR_PANEL_HOVEROVERCLOSE_FILL = -100,
		VSCOLOR_PANEL_HYPERLINK = -101,
		VSCOLOR_PANEL_HYPERLINK_HOVER = -102,
		VSCOLOR_PANEL_HYPERLINK_PRESSED = -103,
		VSCOLOR_PANEL_SEPARATOR = -104,
		VSCOLOR_PANEL_SUBGROUPSEPARATOR = -105,
		VSCOLOR_PANEL_TEXT = -106,
		VSCOLOR_PANEL_TITLEBAR = -107,
		VSCOLOR_PANEL_TITLEBAR_TEXT = -108,
		VSCOLOR_PANEL_TITLEBAR_UNSELECTED = -109,
		VSCOLOR_PROJECTDESIGNER_BACKGROUND_GRADIENTBEGIN = -110,
		VSCOLOR_PROJECTDESIGNER_BACKGROUND_GRADIENTEND = -111,
		VSCOLOR_PROJECTDESIGNER_BORDER_OUTSIDE = -112,
		VSCOLOR_PROJECTDESIGNER_BORDER_INSIDE = -113,
		VSCOLOR_PROJECTDESIGNER_CONTENTS_BACKGROUND = -114,
		VSCOLOR_PROJECTDESIGNER_TAB_BACKGROUND_GRADIENTBEGIN = -115,
		VSCOLOR_PROJECTDESIGNER_TAB_BACKGROUND_GRADIENTEND = -116,
		VSCOLOR_PROJECTDESIGNER_TAB_SELECTED_INSIDEBORDER = -117,
		VSCOLOR_PROJECTDESIGNER_TAB_SELECTED_BORDER = -118,
		VSCOLOR_PROJECTDESIGNER_TAB_SELECTED_HIGHLIGHT1 = -119,
		VSCOLOR_PROJECTDESIGNER_TAB_SELECTED_HIGHLIGHT2 = -120,
		VSCOLOR_PROJECTDESIGNER_TAB_SELECTED_BACKGROUND = -121,
		VSCOLOR_PROJECTDESIGNER_TAB_SEP_BOTTOM_GRADIENTBEGIN = -122,
		VSCOLOR_PROJECTDESIGNER_TAB_SEP_BOTTOM_GRADIENTEND = -123,
		VSCOLOR_PROJECTDESIGNER_TAB_SEP_TOP_GRADIENTBEGIN = -124,
		VSCOLOR_PROJECTDESIGNER_TAB_SEP_TOP_GRADIENTEND = -125,
		VSCOLOR_SCREENTIP_BORDER = -126,
		VSCOLOR_SCREENTIP_BACKGROUND = -127,
		VSCOLOR_SCREENTIP_TEXT = -128,
		VSCOLOR_SIDEBAR_BACKGROUND = -129,
		VSCOLOR_SIDEBAR_GRADIENTDARK = -130,
		VSCOLOR_SIDEBAR_GRADIENTLIGHT = -131,
		VSCOLOR_SIDEBAR_TEXT = -132,
		VSCOLOR_SMARTTAG_BORDER = -133,
		VSCOLOR_SMARTTAG_FILL = -134,
		VSCOLOR_SMARTTAG_HOVER_BORDER = -135,
		VSCOLOR_SMARTTAG_HOVER_FILL = -136,
		VSCOLOR_SMARTTAG_HOVER_TEXT = -137,
		VSCOLOR_SMARTTAG_TEXT = -138,
		VSCOLOR_SNAPLINES = -139,
		VSCOLOR_SNAPLINES_PADDING = -140,
		VSCOLOR_SNAPLINES_TEXTBASELINE = -141,
		VSCOLOR_SORT_BACKGROUND = -142,
		VSCOLOR_SORT_TEXT = -143,
		VSCOLOR_TASKLIST_GRIDLINES = -144,
		VSCOLOR_TITLEBAR_ACTIVE = -145,
		VSCOLOR_TITLEBAR_ACTIVE_GRADIENTBEGIN = -146,
		VSCOLOR_TITLEBAR_ACTIVE_GRADIENTEND = -147,
		VSCOLOR_TITLEBAR_ACTIVE_TEXT = -148,
		VSCOLOR_TITLEBAR_INACTIVE = -149,
		VSCOLOR_TITLEBAR_INACTIVE_GRADIENTBEGIN = -150,
		VSCOLOR_TITLEBAR_INACTIVE_GRADIENTEND = -151,
		VSCOLOR_TITLEBAR_INACTIVE_TEXT = -152,
		VSCOLOR_TOOLBOX_BACKGROUND = -153,
		VSCOLOR_TOOLBOX_DIVIDER = -154,
		VSCOLOR_TOOLBOX_GRADIENTDARK = -155,
		VSCOLOR_TOOLBOX_GRADIENTLIGHT = -156,
		VSCOLOR_TOOLBOX_HEADINGACCENT = -157,
		VSCOLOR_TOOLBOX_HEADINGBEGIN = -158,
		VSCOLOR_TOOLBOX_HEADINGEND = -159,
		VSCOLOR_TOOLBOX_ICON_HIGHLIGHT = -160,
		VSCOLOR_TOOLBOX_ICON_SHADOW = -161,
		VSCOLOR_TOOLWINDOW_BACKGROUND = -162,
		VSCOLOR_TOOLWINDOW_BORDER = -163,
		VSCOLOR_TOOLWINDOW_BUTTON_DOWN = -164,
		VSCOLOR_TOOLWINDOW_BUTTON_DOWN_BORDER = -165,
		VSCOLOR_TOOLWINDOW_BUTTON_HOVER_ACTIVE = -166,
		VSCOLOR_TOOLWINDOW_BUTTON_HOVER_ACTIVE_BORDER = -167,
		VSCOLOR_TOOLWINDOW_BUTTON_HOVER_INACTIVE = -168,
		VSCOLOR_TOOLWINDOW_BUTTON_HOVER_INACTIVE_BORDER = -169,
		VSCOLOR_TOOLWINDOW_TEXT = -170,
		VSCOLOR_TOOLWINDOW_TAB_SELECTEDTAB = -171,
		VSCOLOR_TOOLWINDOW_TAB_BORDER = -172,
		VSCOLOR_TOOLWINDOW_TAB_GRADIENTBEGIN = -173,
		VSCOLOR_TOOLWINDOW_TAB_GRADIENTEND = -174,
		VSCOLOR_TOOLWINDOW_TAB_TEXT = -175,
		VSCOLOR_TOOLWINDOW_TAB_SELECTEDTEXT = -176,
		VSCOLOR_WIZARD_ORIENTATIONPANEL_BACKGROUND = -177,
		VSCOLOR_WIZARD_ORIENTATIONPANEL_TEXT = -178,
		VSCOLOR_LASTEX = -178
	}
	public enum __GRADIENTTYPE
	{
		VSGRADIENT_FILETAB = 1,
		VSGRADIENT_PANEL_BACKGROUND,
		VSGRADIENT_SHELLBACKGROUND,
		VSGRADIENT_TOOLBOX_HEADING,
		VSGRADIENT_TOOLTAB,
		VSGRADIENT_TOOLWIN_ACTIVE_TITLE_BAR,
		VSGRADIENT_TOOLWIN_INACTIVE_TITLE_BAR,
		VSGRADIENT_TOOLWIN_BACKGROUND
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("FD3F680A-D5C1-437A-8A21-8084310BF037")]
	public interface IVsGradient
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int DrawGradient([In] IntPtr hwnd, [In] IntPtr hdc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] gradientRect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.RECT")][MarshalAs(UnmanagedType.LPArray)] RECT[] sliceRect);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetGradientVector([In] int cVector, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.COLORREF")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)] uint[] rgVector);
	}
	public enum __VSCURSORTYPE
	{
		VSCURSOR_APPSTARTING = 1,
		VSCURSOR_COLUMNSPLIT_EW,
		VSCURSOR_COLUMNSPLIT_NS,
		VSCURSOR_CONTROL_COPY,
		VSCURSOR_CONTROL_DELETE,
		VSCURSOR_CONTROL_MOVE,
		VSCURSOR_CROSS,
		VSCURSOR_DRAGDOCUMENT_MOVE,
		VSCURSOR_DRAGDOCUMENT_NOEFFECT,
		VSCURSOR_DRAGSCRAP_COPY,
		VSCURSOR_DRAGSCRAP_MOVE,
		VSCURSOR_DRAGSCRAP_SCROLL,
		VSCURSOR_HAND,
		VSCURSOR_IBEAM,
		VSCURSOR_ISEARCH,
		VSCURSOR_ISEARCH_UP,
		VSCURSOR_MACRO_RECORD_NO,
		VSCURSOR_NO,
		VSCURSOR_NOMOVE_2D,
		VSCURSOR_NOMOVE_HORIZ,
		VSCURSOR_NOMOVE_VERT,
		VSCURSOR_PAN_EAST,
		VSCURSOR_PAN_NE,
		VSCURSOR_PAN_NORTH,
		VSCURSOR_PAN_NW,
		VSCURSOR_PAN_SE,
		VSCURSOR_PAN_SOUTH,
		VSCURSOR_PAN_SW,
		VSCURSOR_PAN_WEST,
		VSCURSOR_POINTER,
		VSCURSOR_POINTER_REVERSE,
		VSCURSOR_SIZE_NS,
		VSCURSOR_SIZE_EW,
		VSCURSOR_SIZE_NWSE,
		VSCURSOR_SIZE_NESW,
		VSCURSOR_SIZE_ALL,
		VSCURSOR_SPLIT_EW,
		VSCURSOR_SPLIT_NS,
		VSCURSOR_UPARROW,
		VSCURSOR_WAIT
	}
	public enum __BWI_IMAGE_POS
	{
		BWI_IMAGE_POS_LEFT,
		BWI_IMAGE_POS_RIGHT,
		BWI_IMAGE_ONLY
	}
	[StructLayout(LayoutKind.Sequential, Pack = 4)]
	public struct VSDRAWITEMSTRUCT
	{
		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")]
		public uint CtlType;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")]
		public uint CtlID;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")]
		public uint itemid;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")]
		public uint itemAction;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")]
		public uint itemState;

		public IntPtr hwndItem;

		public IntPtr hdc;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.RECT")]
		public RECT rcItem;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")]
		public uint itemData;
	}
	[ComImport]
	[Guid("61DF9CCE-E88E-4FE2-9976-77A4F478E24B")]
	[InterfaceType(1)]
	public interface IVsImageButton
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Draw([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSDRAWITEMSTRUCT")][MarshalAs(UnmanagedType.LPArray)] VSDRAWITEMSTRUCT[] pDrawItemStruct, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fHot);
	}
	[ComImport]
	[Guid("4E6B6EF9-8E3D-4756-99E9-1192BAAD5496")]
	[InterfaceType(1)]
	public interface IVsUIShell2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetOpenFileNameViaDlgEx([In][Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOPENFILENAMEW")][MarshalAs(UnmanagedType.LPArray)] VSOPENFILENAMEW[] pOpenFileName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszHelpTopic);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSaveFileNameViaDlgEx([In][Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSSAVEFILENAMEW")][MarshalAs(UnmanagedType.LPArray)] VSSAVEFILENAMEW[] pSaveFileName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszHelpTopic);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetDirectoryViaBrowseDlgEx([In][Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSBROWSEINFOW")][MarshalAs(UnmanagedType.LPArray)] VSBROWSEINFOW[] pBrowse, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszHelpTopic, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszOpenButtonLabel, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszCeilingDir, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSNSEBROWSEINFOW")][MarshalAs(UnmanagedType.LPArray)] VSNSEBROWSEINFOW[] pNSEBrowseInfo);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SaveItemsViaDlg([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] uint cItems, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSSAVETREEITEM")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)] VSSAVETREEITEM[] rgSaveItems);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetVSSysColorEx([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSSYSCOLOREX")] int dwSysColIndex, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwRGBval);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CreateGradient([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.GRADIENTTYPE")] uint GRADIENTTYPE, [MarshalAs(UnmanagedType.Interface)] out IVsGradient pGradient);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetVSCursor([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCURSORTYPE")] uint cursor, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.HCURSOR")] out IntPtr phIcon);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsAutoRecoverSavingCheckpoints([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfARSaving);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int VsDialogBoxParam([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.HINSTANCE")] uint hinst, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwId, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.DLGPROC")] uint lpDialogFunc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG_PTR")] int lp);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CreateIconImageButton([In] IntPtr hwnd, [In] IntPtr hicon, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.BWI_IMAGE_POS")] uint bwiPos, [MarshalAs(UnmanagedType.Interface)] out IVsImageButton ppImageButton);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CreateGlyphImageButton([In] IntPtr hwnd, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.WCHAR")] ushort chGlyph, [In] int xShift, [In] int yShift, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.BWI_IMAGE_POS")] uint bwiPos, [MarshalAs(UnmanagedType.Interface)] out IVsImageButton ppImageButton);
	}
	[ComImport]
	[Guid("8ABE01DB-4CB1-4BE7-961F-D30B2EF6AEB1")]
	[InterfaceType(1)]
	public interface SVsMainWindowDropTarget
	{
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("2AFA4F74-7A1A-4DEE-8F99-46E74E5A3C0F")]
	public interface IVsSupportItemHandoff2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnBeforeHandoffItem([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid, [In][MarshalAs(UnmanagedType.Interface)] IVsProject3 pProjDest);
	}
	[ComImport]
	[Guid("A9832932-5F3B-487D-A80D-95115EADDAC3")]
	[InterfaceType(1)]
	public interface IVsLaunchPadOutputParser
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ParseOutputStringForInfo([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszOutputString, [Optional][Out][MarshalAs(UnmanagedType.LPArray)] string[] pbstrFilename, [Optional][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")][MarshalAs(UnmanagedType.LPArray)] uint[] pnLineNum, [Optional][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")][MarshalAs(UnmanagedType.LPArray)] uint[] pnPriority, [Optional][Out][MarshalAs(UnmanagedType.LPArray)] string[] pbstrTaskItemText, [Optional][Out][MarshalAs(UnmanagedType.LPArray)] string[] pbstrHelpKeyword);
	}
	[Flags]
	public enum _LAUNCHPAD_FLAGS2
	{
		LPF_TreatOutputAsUnicode = 0x10
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("0DBD685A-0A10-4E25-B88E-02E58E60785E")]
	public interface IVsLaunchPad2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ExecCommandEx([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszApplicationName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszCommandLine, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszWorkingDir, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LAUNCHPAD_FLAGS2")] uint lpf, [In][MarshalAs(UnmanagedType.Interface)] IVsOutputWindowPane pOutputWindowPane, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint nTaskItemCategory, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint nTaskItemBitmap, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszTaskListSubcategory, [In][MarshalAs(UnmanagedType.Interface)] IVsLaunchPadEvents pVsLaunchPadEvents, [In][MarshalAs(UnmanagedType.Interface)] IVsLaunchPadOutputParser pOutputParser, [Optional][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")][MarshalAs(UnmanagedType.LPArray)] uint[] pdwProcessExitCode, [Optional][Out][MarshalAs(UnmanagedType.LPArray)] string[] pbstrOutput);
	}
	[Flags]
	public enum __VSPROJSLNDLGFLAGS
	{
		PSDF_OpenSolutionDialog = 1,
		PSDF_OpenProjectDialog = 2,
		PSDF_AddExistingProjectDialog = 4,
		PSDF_DefaultToAllProjectsFilter = 8,
		PSDF_DirectoryPicker = 0x10
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("09B17094-F50C-40E0-8AB5-57C22A786596")]
	public interface IVsOpenProjectOrSolutionDlg
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OpenProjectOrSolutionViaDlg([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSPROJSLNDLGFLAGS")] uint grfProjSlnDlgFlags, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pwzStartDirectory, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pwzDialogTitle, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid rguidProjectType);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("A3761D3F-7C1E-4526-A8D5-1575631F09FC")]
	public interface SVsOpenProjectOrSolutionDlg
	{
	}
	[ComImport]
	[Guid("84F41718-D169-4567-A0CD-B3CBCF58FF71")]
	[InterfaceType(1)]
	public interface IVsCreateAggregateProject
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CreateAggregateProject([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszProjectTypeGuids, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszFilename, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszLocation, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszName, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCREATEPROJFLAGS")] uint grfCreateFlags, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid iidProject, out IntPtr ppvProject);
	}
	[ComImport]
	[Guid("50B729AD-AC3B-451F-BE03-9EA167F5D637")]
	[InterfaceType(1)]
	public interface SVsCreateAggregateProject
	{
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("FFB2E715-7312-4B93-83D7-D37BCC561C90")]
	public interface IVsAggregatableProject
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetInnerProject([In][MarshalAs(UnmanagedType.IUnknown)] object punkInner);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int InitializeForOuter([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszFilename, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszLocation, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszName, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCREATEPROJFLAGS")] uint grfCreateFlags, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid iidProject, out IntPtr ppvProject, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfCanceled);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnAggregationComplete();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetAggregateProjectTypeGuids([MarshalAs(UnmanagedType.BStr)] out string pbstrProjTypeGuids);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetAggregateProjectTypeGuids([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpstrProjTypeGuids);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("44569501-2AD0-4966-9BAC-12B799A1CED6")]
	public interface IVsAggregatableProjectFactory
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetAggregateProjectType([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszFilename, [MarshalAs(UnmanagedType.BStr)] out string pbstrProjTypeGuid);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int PreCreateForOuter([In][MarshalAs(UnmanagedType.IUnknown)] object punkOuter, [MarshalAs(UnmanagedType.IUnknown)] out object ppunkProject);
	}
	[ComImport]
	[Guid("D63BB7D7-D7A0-4C02-AA85-7E9233797CDB")]
	[InterfaceType(1)]
	public interface IVsParentProject2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CreateNestedProject([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemidLoc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid rguidProjectType, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszMoniker, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszLocation, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszName, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCREATEPROJFLAGS")] uint grfCreateFlags, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid rguidProjectID, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid iidProject, out IntPtr ppProject);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddNestedSolution([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemidLoc, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSSLNOPENOPTIONS")] uint grfOpenOpts, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszFilename);
	}
	public enum _PersistStorageType
	{
		PST_PROJECT_FILE = 1,
		PST_USER_FILE
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("E7355FDF-A118-48F5-9655-7EFD9D2DC352")]
	public interface IVsBuildPropertyStorage
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetPropertyValue([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszPropName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszConfigName, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.PersistStorageType")] uint storage, [MarshalAs(UnmanagedType.BStr)] out string pbstrPropValue);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetPropertyValue([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszPropName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszConfigName, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.PersistStorageType")] uint storage, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszPropValue);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RemoveProperty([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszPropName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszConfigName, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.PersistStorageType")] uint storage);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetItemAttribute([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint item, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszAttributeName, [MarshalAs(UnmanagedType.BStr)] out string pbstrAttributeValue);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetItemAttribute([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint item, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszAttributeName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszAttributeValue);
	}
	[Flags]
	public enum _BuildSystemKindFlags
	{
		BSK_MSBUILD = 1
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("EB0718C0-E050-4657-872B-E845CD4F617B")]
	public interface IVsProjectBuildSystem
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetHostObject([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszTargetName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszTaskName, [In][MarshalAs(UnmanagedType.IUnknown)] object punkHostObject);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int StartBatchEdit();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EndBatchEdit();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CancelBatchEdit();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int BuildTarget([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszTargetName, out bool pbSuccess);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetBuildSystemKind([ComAliasName("Microsoft.VisualStudio.Shell.Interop.BuildSystemKindFlags")] out uint pBuildSystemKind);
	}
	[ComImport]
	[Guid("6B0C8632-6F01-4E54-9645-FFE82A2F4FE9")]
	[InterfaceType(1)]
	public interface IPersistXMLFragment
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int InitNew([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidFlavor, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.PersistStorageType")] uint storage);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsFragmentDirty([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.PersistStorageType")] uint storage, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfDirty);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Load([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidFlavor, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.PersistStorageType")] uint storage, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszXMLFragment);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Save([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidFlavor, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.PersistStorageType")] uint storage, [MarshalAs(UnmanagedType.BStr)] out string pbstrXMLFragment, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fClearDirty);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("3BFFC423-6C82-46C0-AF2A-79A3ED3EDA93")]
	public interface IVsProjectFlavorCfg
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_CfgType([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid iidCfg, out IntPtr ppCfg);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Close();
	}
	[ComImport]
	[Guid("52F50FAC-B245-4A81-9A02-DBF8F115389B")]
	[InterfaceType(1)]
	public interface IVsProjectFlavorCfgOutputGroups
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CustomizeOutputGroup([In][MarshalAs(UnmanagedType.Interface)] IVsOutputGroup pIn, [MarshalAs(UnmanagedType.Interface)] out IVsOutputGroup pOut);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("2B81D5F8-F8BD-4A65-8F51-F3BFCD51A924")]
	public interface IVsProjectFlavorCfgProvider
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CreateProjectFlavorCfg([In][MarshalAs(UnmanagedType.Interface)] IVsCfg pBaseProjectCfg, [MarshalAs(UnmanagedType.Interface)] out IVsProjectFlavorCfg ppFlavorCfg);
	}
	public enum __UPDATE_REFERENCE_REASON
	{
		URR_PROJECT_OPEN,
		URR_BUILD,
		URR_START_DEBUG,
		URR_REFERENCEPATH_CHANGED,
		URR_REFERENCE_ADDED,
		URR_REFERENCE_REMOVED,
		URR_EXPLICIT_USER_ACTION
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("66DB9803-1019-48CA-99F2-DAD69E49532C")]
	public interface IVsProjectFlavorReferences
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int QueryAddProjectReference([In][MarshalAs(UnmanagedType.IUnknown)] object pReferencedProject, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pbCanAdd);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int QueryCanBeReferenced([In][MarshalAs(UnmanagedType.IUnknown)] object pReferencingProject, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pbAllowReferenced);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int QueryRefreshReferences([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.UPDATE_REFERENCE_REASON")] uint Reason, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pbUpdate);
	}
	[Flags]
	public enum __VSTRANSACCELEXFLAGS
	{
		VSTAEXF_Default = 0,
		VSTAEXF_NoFireCommand = 1,
		VSTAEXF_IgnoreActiveKBScopes = 2,
		VSTAEXF_UseTextEditorKBScope = 4,
		VSTAEXF_UseGlobalKBScope = 8,
		VSTAEXF_AllowModalState = 0x10
	}
	[ComImport]
	[Guid("A1FF0D7C-1F51-4A95-B107-EC6FFE2C5794")]
	[InterfaceType(1)]
	public interface IVsFilterKeys2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int TranslateAcceleratorEx([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.lpmsg")][MarshalAs(UnmanagedType.LPArray)] MSG[] pMsg, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTRANSACCELEXFLAGS")] uint dwFlags, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint cKeyBindingScopes, [In][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] Guid[] rgguidKeyBindingScopes, out Guid pguidCmd, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwCmd, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int fCmdTranslated, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfKeyComboStartsChord);
	}
	[Flags]
	public enum __UserSettingsFlags
	{
		USF_None = 0,
		USF_ResetOnImport = 1,
		USF_DisableOptimizations = 2
	}
	public enum __VSSETTINGSERRORTYPES
	{
		vsSettingsErrorTypeSuccess = 0,
		vsSettingsErrorTypeError = 1,
		vsSettingsErrorTypeWarning = 2,
		vsSettingsErrorTypeRestart = 4,
		vsSettingsErrorTypeNotInstalled = 8,
		vsSettingsErrorTypeMask = 15
	}
	[ComImport]
	[Guid("38C38501-1428-4ABB-8B27-2F0E1E6DD757")]
	[InterfaceType(1)]
	public interface IVsSettingsReader
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ReadSettingString([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSettingName, [MarshalAs(UnmanagedType.BStr)] out string pbstrSettingValue);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ReadSettingLong([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSettingName, out int plSettingValue);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ReadSettingBoolean([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSettingName, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfSettingValue);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ReadSettingBytes([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSettingName, [In][Out][ComAliasName("Microsoft.VisualStudio.TextManager.Interop.BYTE")] ref byte pSettingValue, out int plDataLength, [In] int lDataMax);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ReadSettingAttribute([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSettingName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszAttributeName, [MarshalAs(UnmanagedType.BStr)] out string pbstrSettingValue);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ReadSettingXml([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSettingName, [MarshalAs(UnmanagedType.IUnknown)] out object ppIXMLDOMNode);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ReadSettingXmlAsString([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSettingName, [MarshalAs(UnmanagedType.BStr)] out string pbstrXML);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ReadCategoryVersion(out int pnMajor, out int pnMinor, out int pnBuild, out int pnRevision);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ReadFileVersion(out int pnMajor, out int pnMinor, out int pnBuild, out int pnRevision);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ReportError([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszError, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSSETTINGSERRORTYPES")] uint dwErrorType);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("0F1CF980-AFC6-406E-958D-7F24287E3916")]
	public interface IVsSettingsWriter
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int WriteSettingString([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSettingName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSettingValue);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int WriteSettingLong([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSettingName, [In] int lSettingValue);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int WriteSettingBoolean([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSettingName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fSettingValue);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int WriteSettingBytes([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSettingName, [In][ComAliasName("Microsoft.VisualStudio.TextManager.Interop.BYTE")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] byte[] pSettingValue, int lDataLength);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int WriteSettingAttribute([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSettingName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszAttributeName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSettingValue);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int WriteSettingXml([In][MarshalAs(UnmanagedType.IUnknown)] object pIXMLDOMNode);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int WriteSettingXmlFromString([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szXML);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int WriteCategoryVersion([In] int nMajor, [In] int nMinor, [In] int nBuild, [In] int nRevision);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ReportError([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszError, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSSETTINGSERRORTYPES")] uint dwErrorType);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("770E285D-3B7D-4342-B3C4-42BD9F53A300")]
	public interface IVsUserSettings
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ExportSettings([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszCategoryGUID, [In][MarshalAs(UnmanagedType.Interface)] IVsSettingsWriter pSettings);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ImportSettings([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszCategoryGUID, [In][MarshalAs(UnmanagedType.Interface)] IVsSettingsReader pSettings, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.UserSettingsFlags")] uint flags, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] ref int pfRestartRequired);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("7C1BD0D6-2086-46AB-8F07-B9335D0FE7D8")]
	public interface SVsSettingsReader
	{
	}
	[ComImport]
	[Guid("334E1F15-7D97-4231-81B0-998E4A960E69")]
	[InterfaceType(1)]
	public interface IVsUserSettingsQuery
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int NeedExport([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szCategoryGUID, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfNeedExport);
	}
	[ComImport]
	[Guid("8E8E55A9-4111-4808-A0D0-7F067FB3A62F")]
	[InterfaceType(1)]
	public interface IVsProfileSettingsFileInfo
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetFilePath([MarshalAs(UnmanagedType.BStr)] out string pbstrFilePath);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetFileLocation([ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSPROFILELOCATIONS")] out uint pfileLocation);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetFriendlyName([MarshalAs(UnmanagedType.BStr)] out string pbstrFriendlyName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetDescription([MarshalAs(UnmanagedType.BStr)] out string pbstrDescription);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSettingsForImport([MarshalAs(UnmanagedType.Interface)] out IVsProfileSettingsTree ppSettingsTree);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("23B6FED1-C3CB-4006-BAD0-64A7EB61DF39")]
	public interface IVsProfileSettingsTree
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetChildCount(out int pCount);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetChild([In] int index, [MarshalAs(UnmanagedType.Interface)] out IVsProfileSettingsTree ppChildTree);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetEnabledChildCount(out int pCount);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetDisplayName([MarshalAs(UnmanagedType.BStr)] out string pbstrName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetDescription([MarshalAs(UnmanagedType.BStr)] out string pbstrDescription);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetCategory([MarshalAs(UnmanagedType.BStr)] out string pbstrCategory);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetRegisteredName([MarshalAs(UnmanagedType.BStr)] out string pbstrRegisteredName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetNameForID([MarshalAs(UnmanagedType.BStr)] out string pbstrNameForID);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetFullPath([MarshalAs(UnmanagedType.BStr)] out string pbstrFullPath);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetPackage([MarshalAs(UnmanagedType.BStr)] out string pbstrPackage);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetIsAutomationPropBased([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfAutoProp);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetEnabled([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfEnabled);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetEnabled([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fEnabled, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fIncludeChildren);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetVisible([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfVisible);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetAlternatePath([MarshalAs(UnmanagedType.BStr)] out string pbstrAlternatePath);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetIsPlaceholder([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfPlaceholder);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetRepresentedNode([MarshalAs(UnmanagedType.Interface)] out IVsProfileSettingsTree ppRepresentedNode);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSecurityLevel([ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSPROFILECATEGORYSECURITY")] out uint pSecurityLevel);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSensitivityLevel([ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSPROFILECATEGORYSENSITIVITY")] out uint pSensitivityLevel);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FindChildTree([In][MarshalAs(UnmanagedType.BStr)] string bstrNameSearch, [MarshalAs(UnmanagedType.Interface)] out IVsProfileSettingsTree ppChildTree);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddChildTree([In][MarshalAs(UnmanagedType.Interface)] IVsProfileSettingsTree pChildTree);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RevisePlacements([In][MarshalAs(UnmanagedType.Interface)] IVsProfileSettingsTree pTreeRoot, [In][MarshalAs(UnmanagedType.Interface)] IVsProfileSettingsTree pTreeRootBasis, [In][MarshalAs(UnmanagedType.BStr)] string bstrCurrentParent);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("0FAF274A-3898-445A-822F-7D42927EFEF9")]
	public interface IVsProfileSettingsFileCollection
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetCount(out int pCount);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSettingsFile([In] int index, [MarshalAs(UnmanagedType.Interface)] out IVsProfileSettingsFileInfo ppFileInfo);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddBrowseFile([In][MarshalAs(UnmanagedType.BStr)] string bstrFilePath, [MarshalAs(UnmanagedType.Interface)] out IVsProfileSettingsFileInfo ppFileInfo);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("466EFAF6-F832-4079-83CD-4BBB02719C1D")]
	public interface IVsProfileDataManager
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LastResetPoint([MarshalAs(UnmanagedType.BStr)] out string pbstrResetFilename);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSettingsFiles([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSPROFILELOCATIONS")] uint fileLocations, [MarshalAs(UnmanagedType.Interface)] out IVsProfileSettingsFileCollection ppCollection);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetDefaultSettingsLocation([MarshalAs(UnmanagedType.BStr)] out string pbstrSettingsLocation);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetUniqueExportFileName([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSPROFILEGETFILENAME")] uint flags, [MarshalAs(UnmanagedType.BStr)] out string pbstrExportFile);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSettingsFileExtension([MarshalAs(UnmanagedType.BStr)] out string pbstrSettingsFileExtension);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSettingsForExport([MarshalAs(UnmanagedType.Interface)] out IVsProfileSettingsTree ppSettingsTree);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ExportSettings([In][MarshalAs(UnmanagedType.BStr)] string bstrFilePath, [In][MarshalAs(UnmanagedType.Interface)] IVsProfileSettingsTree pSettingsTree, [MarshalAs(UnmanagedType.Interface)] out IVsSettingsErrorInformation ppsettingsErrorInformation);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ImportSettings([In][MarshalAs(UnmanagedType.Interface)] IVsProfileSettingsTree pSettingsTree, [MarshalAs(UnmanagedType.Interface)] out IVsSettingsErrorInformation ppsettingsErrorInformation);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ResetSettings([In][MarshalAs(UnmanagedType.Interface)] IVsProfileSettingsFileInfo pFileInfo, [MarshalAs(UnmanagedType.Interface)] out IVsSettingsErrorInformation ppsettingsErrorInformation);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ExportAllSettings([In][MarshalAs(UnmanagedType.BStr)] string bstrFilePath, [MarshalAs(UnmanagedType.Interface)] out IVsSettingsErrorInformation ppsettingsErrorInformation);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AutoSaveAllSettings([MarshalAs(UnmanagedType.Interface)] out IVsSettingsErrorInformation ppsettingsErrorInformation);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CheckUpdateTeamSettings([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSPROFILETEAMSETTINGSFLAGS")] uint dwFlags);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ReportTeamSettingsChanged([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSPROFILETEAMSETTINGSCHANGEDFLAGS")] uint dwFlags);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ShowProfilesUI();
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("33D90D1C-2665-4EEC-9194-A79AFD63275F")]
	public interface IVsSettingsErrorInformation
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetCompletionStatus([ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSSETTINGSCOMPLETIONSTATUS")] out uint pdwCompletionStatus);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetErrorCount(out int pnErrors);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetErrorInfo([In] int nErrorIndex, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSSETTINGSERRORTYPES")] out uint pdwErrorType, [MarshalAs(UnmanagedType.BStr)] out string pbstrError);
	}
	[ComImport]
	[Guid("D06B7887-893C-439C-A231-8BF3E5335E30")]
	[InterfaceType(1)]
	public interface IVsProfilesManagerUI
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ShowProfilesUI([In][MarshalAs(UnmanagedType.Interface)] IVsProfileDataManager pDataManager);
	}
	public enum __VSPROFILELOCATIONS
	{
		PFL_LocationNone = 0,
		PFL_InstallDir = 1,
		PFL_SettingsDir = 2,
		PFL_Other = 4,
		PFL_AutoSave = 8,
		PFL_All = -1
	}
	[Flags]
	public enum __VSPROFILETEAMSETTINGSFLAGS
	{
		PTSF_CHECKFORUPDATE = 0,
		PTSF_UPDATEALWAYS = 1
	}
	[Flags]
	public enum __VSPROFILETEAMSETTINGSCHANGEDFLAGS
	{
		PTSCF_TEAMFILE_NOCHANGE = 0,
		PTSCF_TEAMFILE_CHANGED = 1,
		PTSCF_TEAMFILE_SAME = 2
	}
	public enum __VSPROFILECATEGORYSECURITY
	{
		PCSEC_SAFE,
		PCSEC_THREAT_VS,
		PCSEC_THREAT_MACHINE
	}
	public enum __VSPROFILECATEGORYSENSITIVITY
	{
		PCSEN_SAFE,
		PCSEN_PRIVACY
	}
	public enum __VSPROFILEGETFILENAME
	{
		PGFN_EXPORT = 1,
		PGFN_SAVECURRENT = 2,
		PGFN_AUTOSAVE = 4
	}
	public enum __VSSETTINGSCOMPLETIONSTATUS
	{
		vsSettingsCompletionStatusNotStarted = 0,
		vsSettingsCompletionStatusIncomplete = 1,
		vsSettingsCompletionStatusComplete = 2,
		vsSettingsCompletionStatusStateMask = 15,
		vsSettingsCompletionStatusSuccess = 0,
		vsSettingsCompletionStatusWarnings = 16,
		vsSettingsCompletionStatusErrors = 32,
		vsSettingsCompletionStatusSuccessMask = 240
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("20945017-0113-4636-BBFC-0716071B5B84")]
	public interface SVsProfileDataManager
	{
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("83B2961F-AC2B-409B-89BD-DCF698E3C402")]
	public interface IVsDeferredSaveProject
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SaveProjectToLocation([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszProjectFilename);
	}
	[Flags]
	public enum __VSCREATENEWPROJVIADLGEXFLAGS
	{
		VNPVDE_ALWAYSNEWSOLUTION = 1,
		VNPVDE_OVERRIDEBROWSEBUTTON = 2,
		VNPVDE_ALWAYSADDTOSOLUTION = 4,
		VNPVDE_ADDNESTEDTOSELECTION = 8,
		VNPVDE_USENEWWEBSITEDLG = 0x10
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("368FC032-AE91-44A2-BE6B-093A8A9E63CC")]
	public interface IVsBrowseProjectLocation
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int BrowseProjectLocation([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszStartDirectory, [MarshalAs(UnmanagedType.BStr)] out string pbstrProjectLocation);
	}
	[Flags]
	public enum __VSSAVEDEFERREDSAVEFLAGS
	{
		VSDSF_HIDEADDTOSOURCECONTROL = 1
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("58DCF7BF-F14E-43EC-A7B2-9F78EDD06418")]
	public interface IVsSolution3
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CreateNewProjectViaDlgEx([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszDlgTitle, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszTemplateDir, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszExpand, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSelect, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszHelpTopic, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCREATENEWPROJVIADLGEXFLAGS")] uint cnpvdeFlags, [In][MarshalAs(UnmanagedType.Interface)] IVsBrowseProjectLocation pBrowse);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetUniqueUINameOfProject([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy, [MarshalAs(UnmanagedType.BStr)] out string pbstrUniqueName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CheckForAndSaveDeferredSaveSolution([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fCloseSolution, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszMessage, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszTitle, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSSAVEDEFERREDSAVEFLAGS")] uint grfFlags);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UpdateProjectFileLocationForUpgrade([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszCurrentLocation, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszUpgradedLocation);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("57F5E77F-75C9-42A3-8DAF-579C3556A0DD")]
	public interface IVsConfigurationManagerDlg
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ShowConfigurationManagerDlg();
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("8F435BAD-95A1-4032-8CD0-DC74F67CB106")]
	public interface SVsConfigurationManagerDlg
	{
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("40025C28-3303-42CA-BED8-0F3BD856BD6D")]
	public interface IVsUpdateSolutionEvents3
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnBeforeActiveSolutionCfgChange([In][MarshalAs(UnmanagedType.Interface)] IVsCfg pOldActiveSlnCfg, [In][MarshalAs(UnmanagedType.Interface)] IVsCfg pNewActiveSlnCfg);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnAfterActiveSolutionCfgChange([In][MarshalAs(UnmanagedType.Interface)] IVsCfg pOldActiveSlnCfg, [In][MarshalAs(UnmanagedType.Interface)] IVsCfg pNewActiveSlnCfg);
	}
	[Flags]
	public enum VsUpToDateCheckFlags
	{
		VSUTDCF_DTEEONLY = 1
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("B6EA87ED-C498-4484-81AC-0BED187E28E6")]
	public interface IVsSolutionBuildManager3
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AdviseUpdateSolutionEvents3([In][MarshalAs(UnmanagedType.Interface)] IVsUpdateSolutionEvents3 pIVsUpdateSolutionEvents3, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] out uint pdwCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UnadviseUpdateSolutionEvents3([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] uint dwCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AreProjectsUpToDate([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwOptions);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int HasHierarchyChangedSinceLastDTEE();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int QueryBuildManagerBusyEx([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwBuildManagerOperation);
	}
	[ComImport]
	[Guid("3ADA7A5D-591E-4C9E-8B87-5E33F8E64AA8")]
	[InterfaceType(1)]
	public interface IVsSingleFileGeneratorFactory
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetDefaultGenerator([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string wszFilename, [MarshalAs(UnmanagedType.BStr)] out string pbstrGenProgID);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CreateGeneratorInstance([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string wszProgId, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pbGeneratesDesignTimeSource, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pbGeneratesSharedDesignTimeSource, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pbUseTempPEFlag, [MarshalAs(UnmanagedType.Interface)] out IVsSingleFileGenerator ppGenerate);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetGeneratorInformation([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string wszProgId, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pbGeneratesDesignTimeSource, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pbGeneratesSharedDesignTimeSource, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pbUseTempPEFlag, out Guid pguidGenerator);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("F5B2C031-7093-447F-8486-514FB2CCAD4F")]
	public interface IVsStartPageDownload
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int StartDownloadService();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int StopDownloadService();
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("A60FCE08-2F9C-4676-86F0-BCD4973FC702")]
	public interface SVsStartPageDownload
	{
	}
	public enum __VSMEINIT2
	{
		MD_ITEMICONSUPPORT = 0x10000
	}
	public enum __MENUEDITOR_TRANSACTION
	{
		MENUEDITOR_TRANSACTION_DISCARD = -1,
		MENUEDITOR_TRANSACTION_ALL,
		MENUEDITOR_TRANSACTION_CUT,
		MENUEDITOR_TRANSACTION_PASTE,
		MENUEDITOR_TRANSACTION_COPY,
		MENUEDITOR_TRANSACTION_DELETE
	}
	[ComImport]
	[Guid("A0E39F2D-1333-4E71-B3AC-FC7BBFD92D9E")]
	[InterfaceType(1)]
	public interface IVsMenuEditorTransactionEvents
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int BeginTransaction([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.MENUEDITOR_TRANSACTION")] uint trans);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EndTransaction([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.MENUEDITOR_TRANSACTION")] uint trans);
	}
	[Flags]
	public enum __VSTWDFLAGS
	{
		VSTWDFLAGS_NOFLAGS = 0,
		VSTWDFLAGS_CANCELLABLE = 1,
		VSTWDFLAGS_TOPMOST = 2
	}
	[ComImport]
	[Guid("E051C7B7-7648-473C-8A7D-2B9554A31F9D")]
	[InterfaceType(1)]
	public interface IVsThreadedWaitDialog
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int StartWaitDialog([In][MarshalAs(UnmanagedType.BStr)] string bstrWaitCaption, [In][MarshalAs(UnmanagedType.BStr)] string bstrWaitMessage, [In][MarshalAs(UnmanagedType.BStr)] string bstrIfTruncateAppend, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTWDFLAGS")] uint dwFlags, [In][MarshalAs(UnmanagedType.Struct)] object varStatusBmpAnim, [In][MarshalAs(UnmanagedType.BStr)] string bstrStatusBarText);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EndWaitDialog([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] ref int pfCancelled);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GiveTimeSlice([In][MarshalAs(UnmanagedType.BStr)] string bstrUpdatedWaitMessage, [In][MarshalAs(UnmanagedType.BStr)] string bstrIfTruncateAppend, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fDisableCancel, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfCancelled);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("1AC64571-85CF-4234-AA00-B57E907E326A")]
	public interface SVsThreadedWaitDialog
	{
	}
	[ComImport]
	[Guid("3B0749FF-31E8-42D8-9CD2-F612148D7BDC")]
	[InterfaceType(1)]
	public interface SVsProfilesManagerUI
	{
	}
	public enum __XMLMEMBERDATA_TAGTYPE
	{
		XMLMEMBERDATA_TAGTYPE_CREF
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("C7AE54AB-ABF2-494A-BC8C-C577ABB874C9")]
	public interface IVsXMLMemberDataCallBack
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetDisplayNameForTag([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.XMLMEMBERDATA_TAGTYPE")] uint nTagType, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string wszBufferIn, [MarshalAs(UnmanagedType.BStr)] out string pbstrBufferOut);
	}
	[ComImport]
	[Guid("B9B17D7E-AAB8-43CB-AB40-B4E26E0B6D48")]
	[InterfaceType(1)]
	public interface IVsXMLMemberDataRegisterCallBack
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RegisterCallBack([In][MarshalAs(UnmanagedType.Interface)] IVsXMLMemberDataCallBack pIVsXMLMemberDataCallBack);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UnregisterCallBack();
	}
	public enum __XMLMEMBERDATA_OPTIONS
	{
		XMLMEMBERDATA_OPTIONS_NONE,
		XMLMEMBERDATA_OPTIONS_PRESERVE_NEWLINES
	}
	[ComImport]
	[Guid("C04165C2-3CAC-4508-B651-DD24906DBD4D")]
	[InterfaceType(1)]
	public interface IVsXMLMemberData3
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetOptions([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.XMLMEMBERDATA_OPTIONS")] uint options);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSummaryText([MarshalAs(UnmanagedType.BStr)] out string pbstrSummary);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetParamCount(out int piParams);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetParamTextAt([In] int iParam, [MarshalAs(UnmanagedType.BStr)] out string pbstrName, [MarshalAs(UnmanagedType.BStr)] out string pbstrText);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetReturnsText([MarshalAs(UnmanagedType.BStr)] out string pbstrReturns);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetRemarksText([MarshalAs(UnmanagedType.BStr)] out string pbstrRemarks);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetExceptionCount(out int piExceptions);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetExceptionTextAt([In] int iException, [MarshalAs(UnmanagedType.BStr)] out string pbstrType, [MarshalAs(UnmanagedType.BStr)] out string pbstrText);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetFilterPriority(out int piFilterPriority);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetCompletionListText([MarshalAs(UnmanagedType.BStr)] out string pbstrCompletionList);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetCompletionListTextAt([In] int iParam, [MarshalAs(UnmanagedType.BStr)] out string pbstrCompletionList);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetPermissionSet([MarshalAs(UnmanagedType.BStr)] out string pbstrPermissionSetXML);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetTypeParamCount(out int piTypeParams);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetTypeParamTextAt([In] int iTypeParam, [MarshalAs(UnmanagedType.BStr)] out string pbstrName, [MarshalAs(UnmanagedType.BStr)] out string pbstrText);
	}
	public enum _LIB_LISTTYPE2
	{
		LLT_NIL = 0,
		LLT_MEMBERHIERARCHY = 0x20
	}
	[Flags]
	public enum _LIB_FLAGS2
	{
		LF_SUPPORTSPROJECTREFERENCES = 0x10,
		LF_SUPPORTSFILTERING = 0x20,
		LF_SUPPORTSFILTERINGWITHEXPANSION = 0x40,
		LF_SUPPORTSCALLBROWSER = 0x80,
		LF_SUPPORTSLISTREFERENCES = 0x100,
		LF_SUPPORTSALWAYSUPDATE = 0x400,
		LF_SUPPORTSBASETYPES = 0x800,
		LF_SUPPORTSDERIVEDTYPES = 0x1000,
		LF_SUPPORTSINHERITEDMEMBERS = 0x2000,
		LF_SUPPORTSPRIVATEMEMBERS = 0x4000,
		LF_SUPPORTSCLASSDESIGNER = 0x8000,
		LF_SHOWFULLNAMESINFINDSYMBOLRESULTS = 0x10000
	}
	[Flags]
	public enum _LIB_LISTCAPABILITIES2
	{
		LLC_ALLOWELEMENTSEARCH = 0x100
	}
	[Flags]
	public enum _VSOBSEARCHOPTIONS2
	{
		VSOBSO_FILTERING = 0x100,
		VSOBSO_EXPANDCHILDREN = 0x200,
		VSOBSO_CALLSTO = 0x400,
		VSOBSO_CALLSFROM = 0x800,
		VSOBSO_LISTREFERENCES = 0x1000
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("61772DB8-2D5B-49CB-9CE8-891459921F7F")]
	public interface IVsNavInfo
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetLibGuid(out Guid pGuid);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSymbolType([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwType);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EnumPresentationNodes([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwFlags, [MarshalAs(UnmanagedType.Interface)] out IVsEnumNavInfoNodes ppEnum);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EnumCanonicalNodes([MarshalAs(UnmanagedType.Interface)] out IVsEnumNavInfoNodes ppEnum);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("D2042A65-5E86-4CFA-AD68-F2D6886628D7")]
	public interface IVsEnumNavInfoNodes
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Next([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.Interface, SizeParamIndex = 0)] IVsNavInfoNode[] rgelt, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pceltFetched);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Skip([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Reset();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Clone([MarshalAs(UnmanagedType.Interface)] out IVsEnumNavInfoNodes ppEnum);
	}
	[ComImport]
	[Guid("1BD1DD01-1246-4694-9DA7-8ADCD9CA3275")]
	[InterfaceType(1)]
	public interface IVsNavInfoNode
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_Type([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pllt);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_Name([MarshalAs(UnmanagedType.BStr)] out string pbstrName);
	}
	[StructLayout(LayoutKind.Sequential, Pack = 4)]
	public struct VSOBSEARCHCRITERIA2
	{
		[MarshalAs(UnmanagedType.LPWStr)]
		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")]
		public string szName;

		[ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBSEARCHTYPE")]
		public VSOBSEARCHTYPE eSrchType;

		[ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBSEARCHOPTIONS2")]
		public uint grfOptions;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
		public uint dwCustom;

		[MarshalAs(UnmanagedType.Interface)]
		public IVsNavInfo pIVsNavInfo;
	}
	[StructLayout(LayoutKind.Sequential, Pack = 4)]
	[ComConversionLoss]
	public struct VSOBNAVNAMEINFONODE2
	{
		[ComConversionLoss]
		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WCHAR")]
		public IntPtr pszName;

		[ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_LISTTYPE2")]
		public uint lltName;

		[ComConversionLoss]
		public IntPtr pNext;
	}
	[StructLayout(LayoutKind.Sequential, Pack = 4)]
	[ComConversionLoss]
	public struct VSOBNAVIGATIONINFO3
	{
		[ComConversionLoss]
		public IntPtr pguidLib;

		[ComConversionLoss]
		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WCHAR")]
		public IntPtr pszLibName;

		[ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBNAVNAMEINFONODE2")]
		[ComConversionLoss]
		public IntPtr pName;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
		public uint dwCustom;
	}
	public enum _LIB_CATEGORY2
	{
		LC_NIL = 0,
		LC_PHYSICALCONTAINERTYPE = 10,
		LC_HIERARCHYTYPE = 11,
		LC_MEMBERINHERITANCE = 12,
		LC_SEARCHMATCHTYPE = 13,
		LC_Last2 = 13
	}
	[Flags]
	public enum _LIBCAT_CLASSTYPE2
	{
		LCCT_TEMPLATE = 0x4000,
		LCCT_GENERIC = 0x8000,
		LCCT_ITERATOR = 0x10000
	}
	[Flags]
	public enum _LIBCAT_MEMBERTYPE2
	{
		LCMT_TEMPLATE = 0x4000,
		LCMT_GENERIC = 0x8000
	}
	[Flags]
	public enum _LIBCAT_PHYSICALCONTAINERTYPE
	{
		LCPT_GLOBAL = 1,
		LCPT_PROJECTREFERENCE = 2,
		LCPT_PROJECT = 4
	}
	[Flags]
	public enum _LIBCAT_HIERARCHYTYPE
	{
		LCHT_UNKNOWN = 1,
		LCHT_FOLDER = 2,
		LCHT_BASESANDINTERFACES = 4,
		LCHT_PROJECTREFERENCES = 8,
		LCHT_DERIVEDTYPES = 0x10,
		LCHT_INFO = 0x20
	}
	[Flags]
	public enum _LIBCAT_MEMBERINHERITANCE
	{
		LCMI_IMMEDIATE = 1,
		LCMI_OVERRIDABLE = 2,
		LCMI_OVERRIDEREQUIRED = 4,
		LCMI_OVERRIDDEN = 8,
		LCMI_NOTOVERRIDABLE = 0x10,
		LCMI_INHERITED = 0x20
	}
	[Flags]
	public enum _LIBCAT_SEARCHMATCHTYPE
	{
		LSMT_WHOLEWORD = 1,
		LSMT_WHOLEWORD_NO_CASE = 2,
		LSMT_LEAF_WHOLEWORD = 4,
		LSMT_LEAF_WHOLEWORD_NO_CASE = 8,
		LSMT_PART_WHOLEWORD = 0x10,
		LSMT_PART_WHOLEWORD_NO_CASE = 0x20,
		LSMT_PRESTRING = 0x40,
		LSMT_PRESTRING_NO_CASE = 0x80,
		LSMT_LEAF_PRESTRING = 0x100,
		LSMT_LEAF_PRESTRING_NO_CASE = 0x200,
		LSMT_PART_PRESTRING = 0x400,
		LSMT_PART_PRESTRING_NO_CASE = 0x800,
		LSMT_SUBSTRING = 0x1000,
		LSMT_SUBSTRING_NO_CASE = 0x2000,
		LSMT_NO_MATCH = 0x4000
	}
	public enum _VSOBJLISTELEMPROPID
	{
		VSOBJLISTELEMPROPID_FIRST = 1,
		VSOBJLISTELEMPROPID_HELPKEYWORD = 1,
		VSOBJLISTELEMPROPID_COMPONENTPATH = 2,
		VSOBJLISTELEMPROPID_CODEDEFVIEWCONTEXT = 3,
		VSOBJLISTELEMPROPID_SUPPORTSCALLSTO = 4,
		VSOBJLISTELEMPROPID_SUPPORTSCALLSFROM = 5,
		VSOBJLISTELEMPROPID_FULLNAME = 6,
		VSOBJLISTELEMPROPID_LEAFNAME = 7,
		VSOBJLISTELEMPROPID_NAME_FOR_RENAME = 8,
		VSOBJLISTELEMPROPID_LAST = 8
	}
	[StructLayout(LayoutKind.Sequential, Pack = 4)]
	public struct SYMBOL_DESCRIPTION_NODE
	{
		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")]
		public uint dwType;

		[MarshalAs(UnmanagedType.LPWStr)]
		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")]
		public string pszName;
	}
	[ComImport]
	[Guid("2BCD7A6A-D251-4286-9A61-BDEDDE91114F")]
	[InterfaceType(1)]
	public interface IVsObjectBrowserDescription3
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddDescriptionText3([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string pText, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBDESCRIPTIONSECTION")] VSOBDESCRIPTIONSECTION obdSect, [In][MarshalAs(UnmanagedType.Interface)] IVsNavInfo pHyperJump);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ClearDescriptionText();
	}
	[ComImport]
	[Guid("E37F46C4-C627-4D88-A091-2992EE33B51D")]
	[InterfaceType(1)]
	public interface IVsObjectList2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetFlags([ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREEFLAGS")] out uint pFlags);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetItemCount([ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pCount);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetExpandedList([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfCanRecurse, [MarshalAs(UnmanagedType.Interface)] out IVsLiteTreeList pptlNode);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LocateExpandedList([In][MarshalAs(UnmanagedType.Interface)] IVsLiteTreeList ExpandedList, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint iIndex);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnClose([Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREECLOSEACTIONS")][MarshalAs(UnmanagedType.LPArray)] VSTREECLOSEACTIONS[] ptca);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetText([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREETEXTOPTIONS")] VSTREETEXTOPTIONS tto, [MarshalAs(UnmanagedType.LPWStr)] out string ppszText);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetTipText([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREETOOLTIPTYPE")] VSTREETOOLTIPTYPE eTipType, [MarshalAs(UnmanagedType.LPWStr)] out string ppszText);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetExpandable([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfExpandable);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetDisplayData([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREEDISPLAYDATA")][MarshalAs(UnmanagedType.LPArray)] VSTREEDISPLAYDATA[] pData);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UpdateCounter([ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pCurUpdate, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREEITEMCHANGESMASK")] out uint pgrfChanges);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetListChanges([In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] ref uint pcChanges, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREELISTITEMCHANGE")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)] VSTREELISTITEMCHANGE[] prgListChanges);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ToggleState([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREESTATECHANGEREFRESH")] out uint ptscr);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetCapabilities2([ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_LISTCAPABILITIES2")] out uint pgrfCapabilities);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetList2([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_LISTTYPE2")] uint ListType, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_LISTFLAGS")] uint flags, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBSEARCHCRITERIA2")][MarshalAs(UnmanagedType.LPArray)] VSOBSEARCHCRITERIA2[] pobSrch, [MarshalAs(UnmanagedType.Interface)] out IVsObjectList2 ppIVsObjectList2);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetCategoryField2([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_CATEGORY2")] int Category, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pfCatField);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetExpandable3([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_LISTTYPE2")] uint ListTypeExcluded, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfExpandable);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetNavigationInfo2([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBNAVIGATIONINFO3")][MarshalAs(UnmanagedType.LPArray)] VSOBNAVIGATIONINFO3[] pobNav);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LocateNavigationInfo2([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBNAVIGATIONINFO3")][MarshalAs(UnmanagedType.LPArray)] VSOBNAVIGATIONINFO3[] pobNav, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBNAVNAMEINFONODE2")][MarshalAs(UnmanagedType.LPArray)] VSOBNAVNAMEINFONODE2[] pobName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fDontUpdate, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfMatchedName, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pIndex);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetBrowseObject([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [MarshalAs(UnmanagedType.IDispatch)] out object ppdispBrowseObj);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetUserContext([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [MarshalAs(UnmanagedType.IUnknown)] out object ppunkUserCtx);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ShowHelp([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSourceContext([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In] IntPtr pszFilename, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pulLineNum);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CountSourceItems([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [MarshalAs(UnmanagedType.Interface)] out IVsHierarchy ppHier, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] out uint pItemid, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcItems);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetMultipleSourceItems([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSGSIFLAGS")] uint grfGSI, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cItems, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMSELECTION")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] VSITEMSELECTION[] rgItemSel);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CanGoToSource([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBJGOTOSRCTYPE")] VSOBJGOTOSRCTYPE SrcType, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfOK);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GoToSource([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBJGOTOSRCTYPE")] VSOBJGOTOSRCTYPE SrcType);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetContextMenu([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, out Guid pclsidActive, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] out int pnMenuId, [MarshalAs(UnmanagedType.Interface)] out IOleCommandTarget ppCmdTrgtActive);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int QueryDragDrop([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][MarshalAs(UnmanagedType.Interface)] IDataObject pDataObject, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfKeyState, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] ref uint pdwEffect);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int DoDragDrop([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][MarshalAs(UnmanagedType.Interface)] IDataObject pDataObject, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfKeyState, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] ref uint pdwEffect);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CanRename([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszNewName, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfOK);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int DoRename([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszNewName, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBJOPFLAGS")] uint grfFlags);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CanDelete([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfOK);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int DoDelete([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBJOPFLAGS")] uint grfFlags);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FillDescription([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBJDESCOPTIONS")] uint grfOptions, [In][MarshalAs(UnmanagedType.Interface)] IVsObjectBrowserDescription2 pobDesc);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FillDescription2([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBJDESCOPTIONS")] uint grfOptions, [In][MarshalAs(UnmanagedType.Interface)] IVsObjectBrowserDescription3 pobDesc);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EnumClipboardFormats([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBJCFFLAGS")] uint grfFlags, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBJCLIPFORMAT")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] VSOBJCLIPFORMAT[] rgcfFormats, [Optional][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")][MarshalAs(UnmanagedType.LPArray)] uint[] pcActual);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetClipboardFormat([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBJCFFLAGS")] uint grfFlags, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FORMATETC")][MarshalAs(UnmanagedType.LPArray)] FORMATETC[] pFormatetc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.STGMEDIUM")][MarshalAs(UnmanagedType.LPArray)] STGMEDIUM[] pMedium);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetExtendedClipboardVariant([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBJCFFLAGS")] uint grfFlags, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBJCLIPFORMAT")][MarshalAs(UnmanagedType.LPArray)] VSOBJCLIPFORMAT[] pcfFormat, [MarshalAs(UnmanagedType.Struct)] out object pvarFormat);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetProperty([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBJLISTELEMPROPID")] int propid, [MarshalAs(UnmanagedType.Struct)] out object pvar);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetNavInfo([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [MarshalAs(UnmanagedType.Interface)] out IVsNavInfo ppNavInfo);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetNavInfoNode([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [MarshalAs(UnmanagedType.Interface)] out IVsNavInfoNode ppNavInfoNode);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LocateNavInfoNode([In][MarshalAs(UnmanagedType.Interface)] IVsNavInfoNode pNavInfoNode, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pulIndex);
	}
	[ComImport]
	[Guid("A0C6D693-8226-4CA6-AB03-557AA5A33F75")]
	[InterfaceType(1)]
	public interface IVsSimpleObjectList2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetFlags([ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREEFLAGS")] out uint pFlags);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetCapabilities2([ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_LISTCAPABILITIES2")] out uint pgrfCapabilities);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UpdateCounter([ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pCurUpdate);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetItemCount([ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pCount);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetDisplayData([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREEDISPLAYDATA")][MarshalAs(UnmanagedType.LPArray)] VSTREEDISPLAYDATA[] pData);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetTextWithOwnership([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREETEXTOPTIONS")] VSTREETEXTOPTIONS tto, [MarshalAs(UnmanagedType.BStr)] out string pbstrText);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetTipTextWithOwnership([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREETOOLTIPTYPE")] VSTREETOOLTIPTYPE eTipType, [MarshalAs(UnmanagedType.BStr)] out string pbstrText);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetCategoryField2([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_CATEGORY2")] int Category, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pfCatField);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetBrowseObject([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [MarshalAs(UnmanagedType.IDispatch)] out object ppdispBrowseObj);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetUserContext([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [MarshalAs(UnmanagedType.IUnknown)] out object ppunkUserCtx);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ShowHelp([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSourceContextWithOwnership([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [MarshalAs(UnmanagedType.BStr)] out string pbstrFilename, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pulLineNum);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CountSourceItems([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [MarshalAs(UnmanagedType.Interface)] out IVsHierarchy ppHier, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] out uint pItemid, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcItems);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetMultipleSourceItems([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSGSIFLAGS")] uint grfGSI, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cItems, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMSELECTION")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] VSITEMSELECTION[] rgItemSel);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CanGoToSource([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBJGOTOSRCTYPE")] VSOBJGOTOSRCTYPE SrcType, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfOK);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GoToSource([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBJGOTOSRCTYPE")] VSOBJGOTOSRCTYPE SrcType);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetContextMenu([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, out Guid pclsidActive, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] out int pnMenuId, [MarshalAs(UnmanagedType.Interface)] out IOleCommandTarget ppCmdTrgtActive);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int QueryDragDrop([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][MarshalAs(UnmanagedType.Interface)] IDataObject pDataObject, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfKeyState, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] ref uint pdwEffect);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int DoDragDrop([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][MarshalAs(UnmanagedType.Interface)] IDataObject pDataObject, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfKeyState, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] ref uint pdwEffect);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CanRename([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszNewName, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfOK);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int DoRename([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszNewName, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBJOPFLAGS")] uint grfFlags);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CanDelete([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfOK);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int DoDelete([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBJOPFLAGS")] uint grfFlags);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FillDescription2([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBJDESCOPTIONS")] uint grfOptions, [In][MarshalAs(UnmanagedType.Interface)] IVsObjectBrowserDescription3 pobDesc);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EnumClipboardFormats([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBJCFFLAGS")] uint grfFlags, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBJCLIPFORMAT")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] VSOBJCLIPFORMAT[] rgcfFormats, [Optional][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")][MarshalAs(UnmanagedType.LPArray)] uint[] pcActual);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetClipboardFormat([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBJCFFLAGS")] uint grfFlags, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.FORMATETC")][MarshalAs(UnmanagedType.LPArray)] FORMATETC[] pFormatetc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.STGMEDIUM")][MarshalAs(UnmanagedType.LPArray)] STGMEDIUM[] pMedium);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetExtendedClipboardVariant([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBJCFFLAGS")] uint grfFlags, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBJCLIPFORMAT")][MarshalAs(UnmanagedType.LPArray)] VSOBJCLIPFORMAT[] pcfFormat, [MarshalAs(UnmanagedType.Struct)] out object pvarFormat);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetProperty([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBJLISTELEMPROPID")] int propid, [MarshalAs(UnmanagedType.Struct)] out object pvar);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetNavInfo([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [MarshalAs(UnmanagedType.Interface)] out IVsNavInfo ppNavInfo);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetNavInfoNode([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [MarshalAs(UnmanagedType.Interface)] out IVsNavInfoNode ppNavInfoNode);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LocateNavInfoNode([In][MarshalAs(UnmanagedType.Interface)] IVsNavInfoNode pNavInfoNode, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pulIndex);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetExpandable3([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_LISTTYPE2")] uint ListTypeExcluded, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfExpandable);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetList2([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_LISTTYPE2")] uint ListType, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_LISTFLAGS")] uint flags, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBSEARCHCRITERIA2")][MarshalAs(UnmanagedType.LPArray)] VSOBSEARCHCRITERIA2[] pobSrch, [MarshalAs(UnmanagedType.Interface)] out IVsSimpleObjectList2 ppIVsSimpleObjectList2);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnClose([Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREECLOSEACTIONS")][MarshalAs(UnmanagedType.LPArray)] VSTREECLOSEACTIONS[] ptca);
	}
	[ComImport]
	[Guid("288F2A0C-B2E5-4799-9B9C-24E6EFCEFBF4")]
	[InterfaceType(1)]
	public interface IVsBrowseContainersList
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetContainerData([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint ulIndex, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOMPONENTSELECTORDATA")][MarshalAs(UnmanagedType.LPArray)] VSCOMPONENTSELECTORDATA[] pData);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FindContainer([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOMPONENTSELECTORDATA")][MarshalAs(UnmanagedType.LPArray)] VSCOMPONENTSELECTORDATA[] pData, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pulIndex);
	}
	[ComImport]
	[Guid("EDD9F8A9-3FFE-4C4C-94F8-610B88E19160")]
	[InterfaceType(1)]
	[ComConversionLoss]
	public interface IVsLibrary2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSupportedCategoryFields2([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_CATEGORY2")] int Category, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pgrfCatField);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetList2([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_LISTTYPE2")] uint ListType, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_LISTFLAGS")] uint flags, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBSEARCHCRITERIA2")][MarshalAs(UnmanagedType.LPArray)] VSOBSEARCHCRITERIA2[] pobSrch, [MarshalAs(UnmanagedType.Interface)] out IVsObjectList2 ppIVsObjectList2);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetLibList([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_PERSISTTYPE")] LIB_PERSISTTYPE lptType, [MarshalAs(UnmanagedType.Interface)] out IVsLiteTreeList ppList);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetLibFlags2([ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_FLAGS2")] out uint pgrfFlags);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UpdateCounter([ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pCurUpdate);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetGuid(out IntPtr ppguidLib);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSeparatorString([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")] IntPtr pszSeparator);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LoadState([In][MarshalAs(UnmanagedType.Interface)] IStream pIStream, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_PERSISTTYPE")] LIB_PERSISTTYPE lptType);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SaveState([In][MarshalAs(UnmanagedType.Interface)] IStream pIStream, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_PERSISTTYPE")] LIB_PERSISTTYPE lptType);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetBrowseContainersForHierarchy([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSBROWSECONTAINER")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] VSBROWSECONTAINER[] rgBrowseContainers, [Optional][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")][MarshalAs(UnmanagedType.LPArray)] uint[] pcActual);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddBrowseContainer([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.PVSCOMPONENTSELECTORDATA")][MarshalAs(UnmanagedType.LPArray)] VSCOMPONENTSELECTORDATA[] pcdComponent, [In][Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_ADDREMOVEOPTIONS")] ref uint pgrfOptions, [Optional][Out][MarshalAs(UnmanagedType.LPArray)] string[] pbstrComponentAdded);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RemoveBrowseContainer([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwReserved, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string pszLibName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CreateNavInfo([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.SYMBOL_DESCRIPTION_NODE")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] SYMBOL_DESCRIPTION_NODE[] rgSymbolNodes, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint ulcNodes, [MarshalAs(UnmanagedType.Interface)] out IVsNavInfo ppNavInfo);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("2F328444-6E74-48B4-8B95-08015F9D65D9")]
	public interface IVsSimpleLibrary2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSupportedCategoryFields2([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_CATEGORY2")] int Category, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pgrfCatField);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetList2([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_LISTTYPE2")] uint ListType, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_LISTFLAGS")] uint flags, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBSEARCHCRITERIA2")][MarshalAs(UnmanagedType.LPArray)] VSOBSEARCHCRITERIA2[] pobSrch, [MarshalAs(UnmanagedType.Interface)] out IVsSimpleObjectList2 ppIVsSimpleObjectList2);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetLibFlags2([ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_FLAGS2")] out uint pgrfFlags);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UpdateCounter([ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pCurUpdate);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetGuid(out Guid pguidLib);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSeparatorStringWithOwnership([MarshalAs(UnmanagedType.BStr)] out string pbstrSeparator);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LoadState([In][MarshalAs(UnmanagedType.Interface)] IStream pIStream, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_PERSISTTYPE")] LIB_PERSISTTYPE lptType);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SaveState([In][MarshalAs(UnmanagedType.Interface)] IStream pIStream, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_PERSISTTYPE")] LIB_PERSISTTYPE lptType);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetBrowseContainersForHierarchy([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSBROWSECONTAINER")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] VSBROWSECONTAINER[] rgBrowseContainers, [Optional][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")][MarshalAs(UnmanagedType.LPArray)] uint[] pcActual);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddBrowseContainer([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.PVSCOMPONENTSELECTORDATA")][MarshalAs(UnmanagedType.LPArray)] VSCOMPONENTSELECTORDATA[] pcdComponent, [In][Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_ADDREMOVEOPTIONS")] ref uint pgrfOptions, [MarshalAs(UnmanagedType.BStr)] out string pbstrComponentAdded);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RemoveBrowseContainer([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwReserved, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string pszLibName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CreateNavInfo([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.SYMBOL_DESCRIPTION_NODE")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] SYMBOL_DESCRIPTION_NODE[] rgSymbolNodes, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint ulcNodes, [MarshalAs(UnmanagedType.Interface)] out IVsNavInfo ppNavInfo);
	}
	[ComImport]
	[Guid("D9C7D24D-7ED2-4A9D-93D1-450426CB27DF")]
	[InterfaceType(1)]
	public interface IVsLibrary2Ex
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ProfileSettingsChanged();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetNavInfoContainerData([In][MarshalAs(UnmanagedType.Interface)] IVsNavInfo pNavInfo, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOMPONENTSELECTORDATA")][MarshalAs(UnmanagedType.LPArray)] VSCOMPONENTSELECTORDATA[] pcsdComponent);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int DoIdle();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetContainerAsUnchanging([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOMPONENTSELECTORDATA")][MarshalAs(UnmanagedType.LPArray)] VSCOMPONENTSELECTORDATA[] pcsdComponent, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fUnchanging);
	}
	[ComImport]
	[Guid("FE2BB01D-6EBA-4796-ADF9-59EC7D100AC2")]
	[InterfaceType(1)]
	public interface IVsEnumLibraries2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Next([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.Interface, SizeParamIndex = 0)] IVsLibrary2[] rgelt, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pceltFetched);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Skip([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Reset();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Clone([MarshalAs(UnmanagedType.Interface)] out IVsEnumLibraries2 ppEnum);
	}
	[ComImport]
	[Guid("8A8921BE-42C7-4984-82E9-C68B12C2B22E")]
	[InterfaceType(1)]
	public interface IVsSelectedSymbols
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetCount([ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcItems);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetItem([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint iItem, [MarshalAs(UnmanagedType.Interface)] out IVsSelectedSymbol ppIVsSelectedSymbol);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EnumSelectedSymbols([MarshalAs(UnmanagedType.Interface)] out IVsEnumSelectedSymbols ppIVsEnumSelectedSymbols);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetItemTypes([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pgrfTypes);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("9D86535E-5FE7-4AAF-8846-F1FB5556109A")]
	public interface IVsSelectedSymbol
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetNavInfo([MarshalAs(UnmanagedType.Interface)] out IVsNavInfo ppNavInfo);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetName([MarshalAs(UnmanagedType.BStr)] out string pbstrName);
	}
	[ComImport]
	[Guid("CAC67C59-301A-415D-B269-790F7D4731BC")]
	[InterfaceType(1)]
	public interface IVsEnumSelectedSymbols
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Next([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.Interface, SizeParamIndex = 0)] IVsSelectedSymbol[] rgpIVsSelectedSymbol, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pceltFetched);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Skip([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Reset();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Clone([MarshalAs(UnmanagedType.Interface)] out IVsEnumSelectedSymbols ppIVsEnumSelectedSymbols);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("804DCBDE-3A63-4C3C-9316-296C4C7E9140")]
	public interface IVsBrowseComponentSet
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int put_ComponentsListOptions([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.BROWSE_COMPONENT_SET_OPTIONS")] uint dwOptions);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_ComponentsListOptions([ComAliasName("Microsoft.VisualStudio.Shell.Interop.BROWSE_COMPONENT_SET_OPTIONS")] out uint pdwOptions);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int put_ChildListOptions([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.BROWSE_COMPONENT_SET_OPTIONS")] uint dwOptions);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_ChildListOptions([ComAliasName("Microsoft.VisualStudio.Shell.Interop.BROWSE_COMPONENT_SET_OPTIONS")] out uint pdwOptions);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetList2([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_LISTTYPE2")] uint ListType, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_LISTFLAGS")] uint flags, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBSEARCHCRITERIA2")][MarshalAs(UnmanagedType.LPArray)] VSOBSEARCHCRITERIA2[] pobSrch, [In][MarshalAs(UnmanagedType.Interface)] IVsObjectList2 pExtraListToCombineWith, [MarshalAs(UnmanagedType.Interface)] out IVsObjectList2 ppIVsObjectList2);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSupportedCategoryFields2([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_CATEGORY2")] int Category, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pgrfCatField);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CreateNavInfo([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidLib, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.SYMBOL_DESCRIPTION_NODE")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] SYMBOL_DESCRIPTION_NODE[] rgSymbolNodes, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint ulcNodes, [MarshalAs(UnmanagedType.Interface)] out IVsNavInfo ppNavInfo);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UpdateCounter([ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pCurUpdate);
	}
	[ComImport]
	[Guid("B027F23C-E6B9-415C-ACF0-3D7CFAFCC662")]
	[InterfaceType(1)]
	public interface IVsSimpleBrowseComponentSet : IVsBrowseComponentSet
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		new int put_ComponentsListOptions([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.BROWSE_COMPONENT_SET_OPTIONS")] uint dwOptions);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		new int get_ComponentsListOptions([ComAliasName("Microsoft.VisualStudio.Shell.Interop.BROWSE_COMPONENT_SET_OPTIONS")] out uint pdwOptions);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		new int put_ChildListOptions([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.BROWSE_COMPONENT_SET_OPTIONS")] uint dwOptions);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		new int get_ChildListOptions([ComAliasName("Microsoft.VisualStudio.Shell.Interop.BROWSE_COMPONENT_SET_OPTIONS")] out uint pdwOptions);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		new int GetList2([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_LISTTYPE2")] uint ListType, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_LISTFLAGS")] uint flags, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBSEARCHCRITERIA2")][MarshalAs(UnmanagedType.LPArray)] VSOBSEARCHCRITERIA2[] pobSrch, [In][MarshalAs(UnmanagedType.Interface)] IVsObjectList2 pExtraListToCombineWith, [MarshalAs(UnmanagedType.Interface)] out IVsObjectList2 ppIVsObjectList2);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		new int GetSupportedCategoryFields2([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_CATEGORY2")] int Category, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pgrfCatField);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		new int CreateNavInfo([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidLib, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.SYMBOL_DESCRIPTION_NODE")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] SYMBOL_DESCRIPTION_NODE[] rgSymbolNodes, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint ulcNodes, [MarshalAs(UnmanagedType.Interface)] out IVsNavInfo ppNavInfo);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		new int UpdateCounter([ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pCurUpdate);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int put_RootNavInfo([In][MarshalAs(UnmanagedType.Interface)] IVsNavInfo pRootNavInfo);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_RootNavInfo([MarshalAs(UnmanagedType.Interface)] out IVsNavInfo pRootNavInfo);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int put_Owner([In][MarshalAs(UnmanagedType.IUnknown)] object pOwner);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_Owner([MarshalAs(UnmanagedType.IUnknown)] out object ppOwner);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FindComponent([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidLib, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOMPONENTSELECTORDATA")][MarshalAs(UnmanagedType.LPArray)] VSCOMPONENTSELECTORDATA[] pcsdComponent, [MarshalAs(UnmanagedType.Interface)] out IVsNavInfo ppRealLibNavInfo, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOMPONENTSELECTORDATA")][MarshalAs(UnmanagedType.LPArray)] VSCOMPONENTSELECTORDATA[] pcsdExistingComponent);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddComponent([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidLib, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOMPONENTSELECTORDATA")][MarshalAs(UnmanagedType.LPArray)] VSCOMPONENTSELECTORDATA[] pcsdComponent, [MarshalAs(UnmanagedType.Interface)] out IVsNavInfo ppRealLibNavInfo, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOMPONENTSELECTORDATA")][MarshalAs(UnmanagedType.LPArray)] VSCOMPONENTSELECTORDATA[] pcsdAddedComponent);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RemoveComponent([In][MarshalAs(UnmanagedType.Interface)] IVsNavInfo pRealLibNavInfo);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RemoveAllComponents();
	}
	[ComImport]
	[Guid("64CBD015-9D4B-4DAF-8801-68EDA90B98C5")]
	[InterfaceType(1)]
	public interface IVsCombinedBrowseComponentSet : IVsBrowseComponentSet
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		new int put_ComponentsListOptions([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.BROWSE_COMPONENT_SET_OPTIONS")] uint dwOptions);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		new int get_ComponentsListOptions([ComAliasName("Microsoft.VisualStudio.Shell.Interop.BROWSE_COMPONENT_SET_OPTIONS")] out uint pdwOptions);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		new int put_ChildListOptions([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.BROWSE_COMPONENT_SET_OPTIONS")] uint dwOptions);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		new int get_ChildListOptions([ComAliasName("Microsoft.VisualStudio.Shell.Interop.BROWSE_COMPONENT_SET_OPTIONS")] out uint pdwOptions);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		new int GetList2([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_LISTTYPE2")] uint ListType, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_LISTFLAGS")] uint flags, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBSEARCHCRITERIA2")][MarshalAs(UnmanagedType.LPArray)] VSOBSEARCHCRITERIA2[] pobSrch, [In][MarshalAs(UnmanagedType.Interface)] IVsObjectList2 pExtraListToCombineWith, [MarshalAs(UnmanagedType.Interface)] out IVsObjectList2 ppIVsObjectList2);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		new int GetSupportedCategoryFields2([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.LIB_CATEGORY2")] int Category, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pgrfCatField);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		new int CreateNavInfo([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidLib, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.SYMBOL_DESCRIPTION_NODE")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] SYMBOL_DESCRIPTION_NODE[] rgSymbolNodes, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint ulcNodes, [MarshalAs(UnmanagedType.Interface)] out IVsNavInfo ppNavInfo);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		new int UpdateCounter([ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pCurUpdate);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddSet([In][MarshalAs(UnmanagedType.Interface)] IVsSimpleBrowseComponentSet pSet);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSetCount([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] ref uint pulCount);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSetAt([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint ulIndex, [MarshalAs(UnmanagedType.Interface)] out IVsSimpleBrowseComponentSet ppSet);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RemoveSetAt([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint ulIndex);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RemoveAllSets();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RemoveOwnerSets([In][MarshalAs(UnmanagedType.IUnknown)] object pOwner);
	}
	public enum _BROWSE_COMPONENT_SET_TYPE
	{
		BCST_EXCLUDE_LIBRARIES,
		BCST_INCLUDE_LIBRARIES
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("6A0392E4-68E8-4FBC-AFCF-85155533E48E")]
	public interface IVsObjectManager2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RegisterLibrary([In][MarshalAs(UnmanagedType.Interface)] IVsLibrary2 pLib, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] out uint pdwCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RegisterSimpleLibrary([In][MarshalAs(UnmanagedType.Interface)] IVsSimpleLibrary2 pLib, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] out uint pdwCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UnregisterLibrary([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] uint dwCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EnumLibraries([MarshalAs(UnmanagedType.Interface)] out IVsEnumLibraries2 ppEnum);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FindLibrary([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidLibrary, [MarshalAs(UnmanagedType.Interface)] out IVsLibrary2 ppLib);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetListAndIndex([In][MarshalAs(UnmanagedType.Interface)] IVsNavInfo pNavInfo, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwFlags, [MarshalAs(UnmanagedType.Interface)] out IVsObjectList2 ppList, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pIndex);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ParseDataObject([In][MarshalAs(UnmanagedType.Interface)] IDataObject pIDataObject, [MarshalAs(UnmanagedType.Interface)] out IVsSelectedSymbols ppSymbols);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CreateSimpleBrowseComponentSet([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.BROWSE_COMPONENT_SET_TYPE")] uint Type, [In][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] Guid[] rgguidLibs, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint ulcLibs, [MarshalAs(UnmanagedType.Interface)] out IVsSimpleBrowseComponentSet ppSet);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CreateProjectReferenceSet([In][MarshalAs(UnmanagedType.IUnknown)] object pProject, [MarshalAs(UnmanagedType.Interface)] out IVsSimpleBrowseComponentSet ppSet);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CreateCombinedBrowseComponentSet([MarshalAs(UnmanagedType.Interface)] out IVsCombinedBrowseComponentSet ppCombinedSet);
	}
	public abstract class BrowseLibraryGuids80
	{
		[MarshalAs(UnmanagedType.LPStr)]
		public const string VB = "{414AC972-9829-4B6A-A8D7-A08152FEB8AA}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string CSharp = "{58f1bad0-2288-45b9-ac3a-d56398f7781d}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string VJSharp = "{7B1DC85B-E430-4187-8177-EF97DD390D9A}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string VC = "{6C1AC90E-09FC-4f23-90FF-87F8CFC2A445}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string BSC = "{26E73A17-0D6C-4a33-B833-22C76C50949F}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Assembly = "{1ec72fd7-c820-4273-9a21-777a5c522e03}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string TypeLib = "{18E32C04-58BA-4a1e-80DE-1C291634166A}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Folder = "{DC534E0E-EFBE-4d0c-8A25-98BF029F15F8}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string ResourceView = "{D22514E7-23AF-4723-B6E5-E17D27626D34}";
	}
	public enum _BROWSE_COMPONENT_SET_OPTIONS
	{
		BCSO_NO_REMOVE = 1,
		BCSO_NO_RENAME = 2,
		BCSO_NO_DRAG_DROP = 4,
		BCSO_PROJECT_REFERENCES = 8
	}
	[ComImport]
	[Guid("FDAEB434-F941-4370-9B89-325249EFEC48")]
	[InterfaceType(1)]
	public interface IVsNavigationTool
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int NavigateToSymbol([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidLib, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.SYMBOL_DESCRIPTION_NODE")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] SYMBOL_DESCRIPTION_NODE[] rgSymbolNodes, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint ulcNodes);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int NavigateToNavInfo([In][MarshalAs(UnmanagedType.Interface)] IVsNavInfo pNavInfo);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSelectedSymbols([MarshalAs(UnmanagedType.Interface)] out IVsSelectedSymbols ppIVsSelectedSymbols);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("7FF85070-4667-4532-B149-63A7B205060B")]
	public interface IVsFindSymbol
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetUserOptions(out Guid pguidScope, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBSEARCHCRITERIA2")][MarshalAs(UnmanagedType.LPArray)] VSOBSEARCHCRITERIA2[] pobSrch);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetUserOptions([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidScope, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBSEARCHCRITERIA2")][MarshalAs(UnmanagedType.LPArray)] VSOBSEARCHCRITERIA2[] pobSrch);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int DoSearch([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidSymbolScope, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBSEARCHCRITERIA2")][MarshalAs(UnmanagedType.LPArray)] VSOBSEARCHCRITERIA2[] pobSrch);
	}
	[ComImport]
	[Guid("18220DBE-1AEB-44EA-A924-F3571D202EF4")]
	[InterfaceType(1)]
	public interface IVsFindSymbolEvents
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnUserOptionsChanged([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidSymbolScope, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOBSEARCHCRITERIA2")][MarshalAs(UnmanagedType.LPArray)] VSOBSEARCHCRITERIA2[] pobSrch);
	}
	public abstract class SymbolScopeGuids80
	{
		[MarshalAs(UnmanagedType.LPStr)]
		public const string All = "{A5A527EA-CF0A-4ABF-B501-EAFE6B3BA5C6}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string OBSelectedComponents = "{41FD0B24-8D2B-48C1-B1DA-AACF13A5570F}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string FSSelectedComponents = "{C2146638-C2FE-4C1E-A49D-64AE971EEF39}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Frameworks = "{3168518C-B7C9-4E0C-BD51-E3321CA7B4D8}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string Solution = "{B1BA9461-FC54-45B3-A484-CB6DD0B95C94}";
	}
	public enum __VSCALLBROWSERMODE
	{
		CBM_CALLSTO,
		CBM_CALLSTO_NEWWINDOW,
		CBM_CALLSFROM,
		CBM_CALLSFROM_NEWWINDOW
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("6ED4E844-A0AF-4D6F-B108-8E655785BC88")]
	public interface IVsCallBrowser
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetRootAtSymbol([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.CALLBROWSERMODE")] int cbMode, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidLib, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.SYMBOL_DESCRIPTION_NODE")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 3)] SYMBOL_DESCRIPTION_NODE[] rgSymbolNodes, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint ulcNodes);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetRootAtNavInfo([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.CALLBROWSERMODE")] int cbMode, [In][MarshalAs(UnmanagedType.Interface)] IVsNavInfo pNavInfo);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CanCreateNewInstance([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfOK);
	}
	[ComImport]
	[Guid("F9D0F5FF-C093-4E80-A886-57610D58A728")]
	[InterfaceType(1)]
	public interface SVsCallBrowser
	{
	}
	[Flags]
	public enum __VSCOMPSELFLAGS2
	{
		VSCOMSEL2_MultiSelectMode = 1,
		VSCOMSEL2_ShowSelectedList = 0x80,
		VSCOMSEL2_ShowAllPagesOfSpecifiedTypes = 0x100
	}
	[ComImport]
	[ComConversionLoss]
	[Guid("2D7CDC3D-FA79-4DF3-9CD2-AACF65A2846E")]
	[InterfaceType(1)]
	public interface IVsComponentSelectorDlg2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ComponentSelectorDlg2([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOMPSELFLAGS2")] uint grfFlags, [In][MarshalAs(UnmanagedType.Interface)] IVsComponentUser pUser, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cComponents, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.PVSCOMPONENTSELECTORDATA")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] IntPtr[] rgpcsdComponents, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszDlgTitle, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszHelpTopic, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] ref uint pxDlgSize, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] ref uint pyDlgSize, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cTabInitializers, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOMPONENTSELECTORTABINIT")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 8)] VSCOMPONENTSELECTORTABINIT[] rgcstiTabInitializers, [In][Out] ref Guid pguidStartOnThisTab, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszBrowseFilters, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string pbstrBrowseLocation);
	}
	[ComImport]
	[Guid("525D42EF-D7F6-412A-9D64-79E787E70E45")]
	[InterfaceType(1)]
	public interface SVsComponentSelectorDlg2
	{
	}
	public abstract class ComponentSelectorGuids80
	{
		[MarshalAs(UnmanagedType.LPStr)]
		public const string BrowseFilesPage = "{2483F435-673D-4fa3-8ADD-B51442F65349}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string MRUPage = "{19B97F03-9594-4c1c-BE28-25FF030113B3}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string COMPlusPage = "{9A341D95-5A64-11d3-BFF9-00C04F990235}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string COMClassicPage = "{9A341D96-5A64-11d3-BFF9-00C04F990235}";

		[MarshalAs(UnmanagedType.LPStr)]
		public const string SolutionPage = "{9A341D97-5A64-11d3-BFF9-00C04F990235}";
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("9015B3AB-9FE2-430D-B79F-E0E581BD5B8B")]
	public interface IVsBuildMacroInfo
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetBuildMacroValue([In][MarshalAs(UnmanagedType.BStr)] string bstrBuildMacroName, [MarshalAs(UnmanagedType.BStr)] out string pbstrBuildMacroValue);
	}
	public enum __PREVIEWCHANGESITEMCHECKSTATE
	{
		PCCS_None,
		PCCS_Unchecked,
		PCCS_PartiallyChecked,
		PCCS_Checked
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("B334F714-993B-4902-89E0-792213B538DB")]
	public interface IVsPreviewChangesList
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetFlags([ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREEFLAGS")] out uint pFlags);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetItemCount([ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pCount);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetExpandedList([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfCanRecurse, [MarshalAs(UnmanagedType.Interface)] out IVsLiteTreeList pptlNode);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LocateExpandedList([In][MarshalAs(UnmanagedType.Interface)] IVsLiteTreeList ExpandedList, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint iIndex);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnClose([Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREECLOSEACTIONS")][MarshalAs(UnmanagedType.LPArray)] VSTREECLOSEACTIONS[] ptca);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetText([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREETEXTOPTIONS")] VSTREETEXTOPTIONS tto, [MarshalAs(UnmanagedType.LPWStr)] out string ppszText);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetTipText([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREETOOLTIPTYPE")] VSTREETOOLTIPTYPE eTipType, [MarshalAs(UnmanagedType.LPWStr)] out string ppszText);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetExpandable([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfExpandable);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetDisplayData([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREEDISPLAYDATA")][MarshalAs(UnmanagedType.LPArray)] VSTREEDISPLAYDATA[] pData);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UpdateCounter([ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pCurUpdate, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREEITEMCHANGESMASK")] out uint pgrfChanges);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetListChanges([In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] ref uint pcChanges, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREELISTITEMCHANGE")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)] VSTREELISTITEMCHANGE[] prgListChanges);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ToggleState([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREESTATECHANGEREFRESH")] out uint ptscr);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnRequestSource([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][MarshalAs(UnmanagedType.IUnknown)] object pIUnknownTextView);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("C42D228E-B275-4FE6-8469-F3184663B883")]
	public interface IVsSimplePreviewChangesList
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetItemCount([ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pCount);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetDisplayData([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREEDISPLAYDATA")][MarshalAs(UnmanagedType.LPArray)] VSTREEDISPLAYDATA[] pData);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetTextWithOwnership([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREETEXTOPTIONS")] VSTREETEXTOPTIONS tto, [MarshalAs(UnmanagedType.BStr)] out string pbstrText);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetTipTextWithOwnership([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREETOOLTIPTYPE")] VSTREETOOLTIPTYPE eTipType, [MarshalAs(UnmanagedType.BStr)] out string pbstrText);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetExpandable([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfExpandable);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetExpandedList([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfCanRecurse, [MarshalAs(UnmanagedType.Interface)] out IVsSimplePreviewChangesList ppIVsSimplePreviewChangesList);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LocateExpandedList([In][MarshalAs(UnmanagedType.Interface)] IVsSimplePreviewChangesList pIVsSimplePreviewChangesListChild, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint piIndex);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ToggleState([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREESTATECHANGEREFRESH")] out uint ptscr);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnRequestSource([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint index, [In][MarshalAs(UnmanagedType.IUnknown)] object pIUnknownTextView);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnClose([Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTREECLOSEACTIONS")][MarshalAs(UnmanagedType.LPArray)] VSTREECLOSEACTIONS[] ptca);
	}
	public enum __PREVIEWCHANGESWARNINGLEVEL
	{
		PCWL_None,
		PCWL_Information,
		PCWL_Warning,
		PCWL_Error
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("6DE3E607-1E2C-4F56-B4A6-BCAF63A0BB9F")]
	public interface IVsPreviewChangesEngine
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetTitle([MarshalAs(UnmanagedType.BStr)] out string pbstrTitle);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetDescription([MarshalAs(UnmanagedType.BStr)] out string pbstrDescription);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetTextViewDescription([MarshalAs(UnmanagedType.BStr)] out string pbstrTextViewDescription);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetWarning([MarshalAs(UnmanagedType.BStr)] out string pbstrWarning, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.PREVIEWCHANGESWARNINGLEVEL")] out int ppcwlWarningLevel);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetHelpContext([MarshalAs(UnmanagedType.BStr)] out string pbstrHelpContext);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetConfirmation([MarshalAs(UnmanagedType.BStr)] out string pbstrConfirmation);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetRootChangesList([MarshalAs(UnmanagedType.IUnknown)] out object ppIUnknownPreviewChangesList);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ApplyChanges();
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("AF142B19-FB37-40C0-9C28-6617ADBFFAC7")]
	public interface IVsPreviewChangesService
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int PreviewChanges([In][MarshalAs(UnmanagedType.Interface)] IVsPreviewChangesEngine pIVsPreviewChangesEngine);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("12143874-DA05-4D05-9F57-2D339C142220")]
	public interface SVsPreviewChangesService
	{
	}
	[ComImport]
	[Guid("E7070F9A-502F-4454-B4A2-FE261C568C37")]
	[InterfaceType(1)]
	public interface IVsCodeDefViewContext
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetCount([ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcItems);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSymbolName([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint iItem, [MarshalAs(UnmanagedType.BStr)] out string pbstrSymbolName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetFileName([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint iItem, [MarshalAs(UnmanagedType.BStr)] out string pbstrFilename);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetLine([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint iItem, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint piLine);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetCol([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint iItem, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint piCol);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("588470CC-84F8-4A57-9AC4-86BCA0625FF4")]
	public interface IVsCodeDefView
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ShowWindow();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int HideWindow();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsVisible();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetContext([In][MarshalAs(UnmanagedType.Interface)] IVsCodeDefViewContext pIVsCodeDefViewContext);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetRefreshDelay([ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcMilliseconds);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ForceIdleProcessing();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsCodeDefView([In][MarshalAs(UnmanagedType.Interface)] IVsTextView pIVsTextView, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfIsCodeDefView);
	}
	[ComImport]
	[Guid("D34E5A63-E990-472A-9852-45FB36AA67AB")]
	[InterfaceType(1)]
	public interface IVsSupportCodeDefView
	{
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("66230816-AC33-49B5-97DB-0F6DF2A83624")]
	public interface SVsCodeDefView
	{
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("47811DA4-330F-4EB5-9D14-BBC82773DA66")]
	public interface IVsCoTaskMemFreeMyStrings
	{
	}
	[Flags]
	public enum _VSRDTFLAGS2
	{
		RDT_Lock_WeakEditLock = 0x800,
		RDT_LOCKUNLOCKMASK = 0xF00
	}
	[Flags]
	public enum __VSRDTSAVEOPTIONS2
	{
		RDTSAVEOPT_SkipNewUnsaved = 0x20,
		RDTSAVEOPT_SaveAllButThis = 0x40,
		RDTSAVEOPT_FSaveAs = 0x20000000
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("CD68D3CF-7124-4D3A-AFED-3E305C2B7D0B")]
	public interface IVsRunningDocumentTable2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CloseDocuments([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.FRAMECLOSE")] uint grfSaveOptions, [In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] uint docCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int QueryCloseRunningDocument([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszMkDocument, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfFoundAndClosed);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FindAndLockDocumentEx([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSRDTFLAGS")] uint grfRDTLockType, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszMkDocument, [In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierPreferred, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemidPreferred, [MarshalAs(UnmanagedType.Interface)] out IVsHierarchy ppHierActual, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] out uint pitemidActual, out IntPtr ppunkDocDataActual, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] out uint pdwCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FindOrRegisterAndLockDocument([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSRDTFLAGS")] uint grfRDTLockType, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszMkDocument, [In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierPreferred, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemidPreferred, [In] IntPtr punkDocData, [MarshalAs(UnmanagedType.Interface)] out IVsHierarchy ppHierActual, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] out uint pitemidActual, out IntPtr ppunkDocDataActual, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] out uint pdwCookie);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("79A342F3-D637-4D54-83DC-DDD511743A49")]
	public interface IVsRunningDocTableEvents4
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnBeforeFirstDocumentLock([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHier, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszMkDocument);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnAfterSaveAll();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnAfterLastDocumentUnlock([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHier, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszMkDocument, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fClosedWithoutSaving);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("653BE2DA-BA98-41B7-8ABC-7A38B0E1C01A")]
	public interface IVsToolboxDataProviderRegistry
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RegisterDataProvider([In][MarshalAs(UnmanagedType.Interface)] IVsToolboxDataProvider pDP, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] out uint pdwProvider);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UnregisterDataProvider([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] uint dwProvider);
	}
	[ComImport]
	[Guid("3AF9E499-91B8-4B54-BD1D-81F414A587C9")]
	[InterfaceType(1)]
	public interface SVsToolboxDataProviderRegistry
	{
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("55D3D8C8-F08C-4B31-B70D-FCC52468A5B2")]
	public interface IVsFontAndColorCacheManager
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CheckCache([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid rguidCategory, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfHasData);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ClearCache([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid rguidCategory);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RefreshCache([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid rguidCategory);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CheckCacheable([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid rguidCategory, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfCacheable);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ClearAllCaches();
	}
	[ComImport]
	[Guid("FB5F088F-1C86-4648-B01C-0A1C40840C51")]
	[InterfaceType(1)]
	public interface SVsFontAndColorCacheManager
	{
	}
	public enum __VSUL_ERRORLEVEL
	{
		VSUL_INFORMATIONAL,
		VSUL_WARNING,
		VSUL_ERROR,
		VSUL_STATUSMSG,
		VSUL_PROJECT_HYPERLINK
	}
	[ComImport]
	[Guid("AE88C42E-B3D6-4FEC-9C63-C9F1B28233EA")]
	[InterfaceType(1)]
	public interface IVsUpgradeLogger
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LogMessage([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSUL_ERRORLEVEL")] uint ErrorLevel, [In][MarshalAs(UnmanagedType.BStr)] string bstrProject, [In][MarshalAs(UnmanagedType.BStr)] string bstrSource, [In][MarshalAs(UnmanagedType.BStr)] string bstrDescription);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Flush();
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("DFB0136F-202E-40B5-872E-AE8289A45B59")]
	public interface SVsUpgradeLogger
	{
	}
	[ComImport]
	[Guid("5D2D55F2-E545-4301-9C22-52BC694CA76C")]
	[InterfaceType(1)]
	public interface IVsFileUpgrade
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UpgradeFile([In][MarshalAs(UnmanagedType.BStr)] string bstrProjectName, [In][MarshalAs(UnmanagedType.BStr)] string bstrFileName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int bNoBackup, [In][MarshalAs(UnmanagedType.Interface)] IVsUpgradeLogger pLogger, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pUpgradeRequired);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UpgradeFile_CheckOnly([In][MarshalAs(UnmanagedType.BStr)] string bstrProjectName, [In][MarshalAs(UnmanagedType.BStr)] string bstrFileName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int bNoBackup, [In][MarshalAs(UnmanagedType.Interface)] IVsUpgradeLogger pLogger, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pUpgradeRequired);
	}
	[Flags]
	public enum __VSPPROJECTUPGRADEVIAFACTORYFLAGS
	{
		PUVFF_SXSBACKUP = 0x20,
		PUVFF_COPYBACKUP = 0x40,
		PUVFF_BACKUPSUPPORTED = 0x80,
		PUVFF_USE_ALT_BACKUP_LOCATION = 0x100
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("0DBA1379-5D67-4A6C-8C06-A5795AF7364B")]
	public interface IVsProjectUpgradeViaFactory
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UpgradeProject([In][MarshalAs(UnmanagedType.BStr)] string bstrFileName, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSPUVF_FLAGS")] uint fUpgradeFlag, [In][MarshalAs(UnmanagedType.BStr)] string bstrCopyLocation, [MarshalAs(UnmanagedType.BStr)] out string pbstrUpgradedFullyQualifiedFileName, [In][MarshalAs(UnmanagedType.Interface)] IVsUpgradeLogger pLogger, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pUpgradeRequired, out Guid pguidNewProjectFactory);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UpgradeProject_CheckOnly([In][MarshalAs(UnmanagedType.BStr)] string bstrFileName, [In][MarshalAs(UnmanagedType.Interface)] IVsUpgradeLogger pLogger, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pUpgradeRequired, out Guid pguidNewProjectFactory, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSPUVF_FLAGS")] out uint pUpgradeProjectCapabilityFlags);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSccInfo([In][MarshalAs(UnmanagedType.BStr)] string bstrProjectFileName, [MarshalAs(UnmanagedType.BStr)] out string pbstrSccProjectName, [MarshalAs(UnmanagedType.BStr)] out string pbstrSccAuxPath, [MarshalAs(UnmanagedType.BStr)] out string pbstrSccLocalPath, [MarshalAs(UnmanagedType.BStr)] out string pbstrProvider);
	}
	[ComImport]
	[Guid("E5F6CFF6-C3E1-45BC-9559-C03F94FDF15B")]
	[InterfaceType(1)]
	public interface IVsProjectUpgradeViaFactory2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnUpgradeProjectCancelled([In][MarshalAs(UnmanagedType.BStr)] string bstrFileName);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("7B1D55C6-4F6A-4865-B9B3-1A696E233065")]
	public interface IVsSolutionEventsProjectUpgrade
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnAfterUpgradeProject([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSPUVF_FLAGS")] uint fUpgradeFlag, [In][MarshalAs(UnmanagedType.BStr)] string bstrCopyLocation, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.SYSTEMTIME")] SYSTEMTIME stUpgradeTime, [In][MarshalAs(UnmanagedType.Interface)] IVsUpgradeLogger pLogger);
	}
	[StructLayout(LayoutKind.Sequential, Pack = 2)]
	public struct SYSTEMTIME
	{
		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
		public ushort wYear;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
		public ushort wMonth;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
		public ushort wDayOfWeek;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
		public ushort wDay;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
		public ushort wHour;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
		public ushort wMinute;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
		public ushort wSecond;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.WORD")]
		public ushort wMilliseconds;
	}
	public enum __ACTIVITYLOG_ENTRYTYPE
	{
		ALE_ERROR = 1,
		ALE_WARNING,
		ALE_INFORMATION
	}
	[ComImport]
	[Guid("76AF73F9-A322-42B0-A515-D4D7553508FE")]
	[InterfaceType(1)]
	public interface IVsActivityLog
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LogEntry([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.ACTIVITYLOG_ENTRYTYPE")] uint actType, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSource, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszDescription);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LogEntryGuid([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.ACTIVITYLOG_ENTRYTYPE")] uint actType, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSource, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszDescription, [In] Guid guid);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LogEntryHr([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.ACTIVITYLOG_ENTRYTYPE")] uint actType, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSource, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszDescription, [In][MarshalAs(UnmanagedType.Error)] int hr);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LogEntryGuidHr([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.ACTIVITYLOG_ENTRYTYPE")] uint actType, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSource, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszDescription, [In] Guid guid, [In][MarshalAs(UnmanagedType.Error)] int hr);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LogEntryPath([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.ACTIVITYLOG_ENTRYTYPE")] uint actType, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSource, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszDescription, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszPath);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LogEntryGuidPath([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.ACTIVITYLOG_ENTRYTYPE")] uint actType, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSource, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszDescription, [In] Guid guid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszPath);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LogEntryHrPath([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.ACTIVITYLOG_ENTRYTYPE")] uint actType, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSource, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszDescription, [In][MarshalAs(UnmanagedType.Error)] int hr, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszPath);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LogEntryGuidHrPath([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.ACTIVITYLOG_ENTRYTYPE")] uint actType, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSource, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszDescription, [In] Guid guid, [In][MarshalAs(UnmanagedType.Error)] int hr, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszPath);
	}
	[ComImport]
	[Guid("24367A32-EF56-405B-A395-5CF2BCCB2283")]
	[InterfaceType(1)]
	public interface SVsActivityLog
	{
	}
	[ComImport]
	[Guid("DEC057F4-46D1-4BD3-9D63-21E5E3F19368")]
	[InterfaceType(1)]
	public interface IVsPersistDocData3
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int HandsOffDocDataStorage();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int HandsOnDocDataStorage();
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("801885A0-9DC6-4E34-B064-1C3228F66794")]
	public interface IVsWindowFrame2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Advise([In][MarshalAs(UnmanagedType.Interface)] IVsWindowFrameNotify pNotify, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] out uint pdwCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Unadvise([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] uint dwCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ActivateOwnerDockedWindow();
	}
	public enum __VSPPPID
	{
		VSPPPID_FIRST = 1,
		VSPPPID_PAGENAME = 1,
		VSPPPID_LAST = 1
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("6FC6A958-B2E7-441B-823C-10EA30B24EEC")]
	public interface IVsPropertyPage2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetProperty([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSPPPID")] uint propid, [MarshalAs(UnmanagedType.Struct)] out object pvar);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetProperty([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSPPPID")] uint propid, [In][MarshalAs(UnmanagedType.Struct)] object var);
	}
	public enum __FRAMESHOW2
	{
		FRAMESHOW_BeforeWinHidden = 10,
		FRAMESHOW_AutoHideSlideEnd
	}
	[ComImport]
	[Guid("8C213AC2-FF13-4361-9FC5-39D368D26CD3")]
	[InterfaceType(1)]
	public interface IVsWindowFrameNotify3
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnShow([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.FRAMESHOW2")] int fShow);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnMove([In] int x, [In] int y, [In] int w, [In] int h);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnSize([In] int x, [In] int y, [In] int w, [In] int h);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnDockableChange([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fDockable, [In] int x, [In] int y, [In] int w, [In] int h);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnClose([In][Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.FRAMECLOSE")] ref uint pgrfSaveOptions);
	}
	[ComImport]
	[Guid("91C30F81-E72A-4997-9B07-A0AECB8C9169")]
	[InterfaceType(1)]
	public interface IVsPackageDynamicToolOwnerEx
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int QueryShowTool([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid rguidPersistenceSlot, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwId, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfShowTool);
	}
	[ComImport]
	[Guid("C0C5974A-288D-4719-AB48-9CB812B5E895")]
	[InterfaceType(1)]
	public interface IVsContextualIntellisenseFilter
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Initialize([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsTypeVisible([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szTypeName, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfVisible);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsMemberVisible([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szMemberSignature, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfVisible);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Close();
	}
	[ComImport]
	[Guid("F7827DCE-0B39-474D-8D48-FE8100C9044C")]
	[InterfaceType(1)]
	public interface IVsContextualIntellisenseFilterProvider
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetFilter([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy, [MarshalAs(UnmanagedType.Interface)] out IVsContextualIntellisenseFilter ppFilter);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("A00C298A-6520-4822-ABD8-C5CD03846599")]
	public interface IVsToolboxActiveUserHook
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int InterceptDataObject([In][MarshalAs(UnmanagedType.Interface)] IDataObject pIn, [MarshalAs(UnmanagedType.Interface)] out IDataObject ppOut);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ToolboxSelectionChanged([In][MarshalAs(UnmanagedType.Interface)] IDataObject pSelected);
	}
	[ComImport]
	[Guid("1749A33B-2099-4A22-B32A-E96ADD887142")]
	[InterfaceType(1)]
	public interface IVsDefaultToolboxTabState
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetDefaultTabExpansion([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszTabID, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfExpanded);
	}
	[Flags]
	public enum __VSPROFILEPATHRESOLVERFLAGS
	{
		VSPPR_None = 0,
		VSPPR_OnlyForProfiles = 1
	}
	[ComImport]
	[Guid("17A4EF87-4472-47F6-B066-FE96036678D0")]
	[InterfaceType(1)]
	public interface IVsPathVariableResolver
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ResolvePath([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string strEncodedPath, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSPROFILEPATHRESOLVERFLAGS")] uint dwFlags, [MarshalAs(UnmanagedType.BStr)] out string pbstrPath);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EncodePath([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string strPath, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSPROFILEPATHRESOLVERFLAGS")] uint dwFlags, [MarshalAs(UnmanagedType.BStr)] out string pbstrEncodedPath);
	}
	[ComImport]
	[Guid("89DB7429-F4A4-4F26-B832-2EB963A19AAA")]
	[InterfaceType(1)]
	public interface SVsPathVariableResolver
	{
	}
	public enum __VSASYNCHOPENPROJECTTYPE
	{
		AOPT_SYNCHRONOUS,
		AOPT_ASYNCHRONOUS
	}
	[ComImport]
	[Guid("55E1A1E1-ECAC-46E0-BDE3-1E35BC68C31C")]
	[InterfaceType(1)]
	public interface IVsProjectFactory2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetAsynchOpenProjectType([ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSASYNCHOPENPROJECTTYPE")] out uint pType);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("C31C30EF-3B22-4F02-93BB-BCDA5FA192AA")]
	public interface IVsAsynchOpenFromSccProjectEvents
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnFilesDownloaded([In] int cFiles, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 0)] string[] rgpszFullPaths);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnLoadComplete();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnLoadFailed();
	}
	[ComImport]
	[Guid("99871A31-DB02-4DA9-98FB-89D8EDC700CE")]
	[InterfaceType(1)]
	public interface IVsAsynchOpenFromScc
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LoadProjectAsynchronously([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszProjectPath, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pReturnValue);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LoadProject([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszProjectPath);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsLoadingContent([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHierarchy, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfIsLoading);
	}
	[ComImport]
	[Guid("78FD1CBD-387B-4262-BD7B-65C34F86356E")]
	[InterfaceType(1)]
	public interface IVsHierarchyDeleteHandler2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ShowSpecificDeleteRemoveMessage([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwDelItemOps, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cDelItems, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] uint[] rgDelItems, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfShowStandardMessage, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSDELETEITEMOPERATION")] out uint pdwDelItemOp);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ShowMultiSelDeleteOrRemoveMessage([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSDELETEITEMOPERATION")] uint dwDelItemOp, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cDelItems, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] uint[] rgDelItems, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfCancelOperation);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("5C67B771-43AD-4BCF-9342-E82CF8E4CBFD")]
	public interface IVsToolbox3
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetIDOfTab([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszTabName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszTabID);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetIDOfTab([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszTabName, [MarshalAs(UnmanagedType.BStr)] out string pbstrTabID);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetTabOfID([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszTabID, [MarshalAs(UnmanagedType.BStr)] out string pbstrTabName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetGeneralTabID([MarshalAs(UnmanagedType.BStr)] out string pbstrTabID);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetItemID([In][MarshalAs(UnmanagedType.Interface)] IDataObject pDO, [MarshalAs(UnmanagedType.BStr)] out string pbstrID);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetItemDisplayName([In][MarshalAs(UnmanagedType.Interface)] IDataObject pDO, [MarshalAs(UnmanagedType.BStr)] out string pbstrName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetLastModifiedTime([Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.SYSTEMTIME")][MarshalAs(UnmanagedType.LPArray)] SYSTEMTIME[] pst);
	}
	[ComImport]
	[Guid("1CD73232-A3C7-48FA-8B0A-2E35804097BF")]
	[InterfaceType(1)]
	public interface IVsToolboxDataProvider2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetPackageGUID(out Guid pguidPkg);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetUniqueID(out Guid pguidID);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetDisplayName([MarshalAs(UnmanagedType.BStr)] out string pbstrName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetItemTipInfo([In][MarshalAs(UnmanagedType.Interface)] IDataObject pDO, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszCurrentName, [In][MarshalAs(UnmanagedType.Interface)] IPropertyBag pStrings);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetProfileData([In][MarshalAs(UnmanagedType.Interface)] IDataObject pDO, [MarshalAs(UnmanagedType.BStr)] out string pbstrData);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetItemID([In][MarshalAs(UnmanagedType.Interface)] IDataObject pDO, [MarshalAs(UnmanagedType.BStr)] out string pbstrID);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ReconstituteItem([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszCurrentName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszID, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszData, [MarshalAs(UnmanagedType.Interface)] out IDataObject ppDO, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.TBXITEMINFO")][MarshalAs(UnmanagedType.LPArray)] TBXITEMINFO[] ptif);
	}
	[ComImport]
	[ComConversionLoss]
	[Guid("F0D7A6F0-C722-4AB6-A5D9-C7FF13027410")]
	[InterfaceType(1)]
	public interface IVsResourceManager
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LoadResourceString([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidPackage, [In] int culture, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszResourceName, [MarshalAs(UnmanagedType.BStr)] out string pbstrValue);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LoadResourceBitmap([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidPackage, [In] int culture, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszResourceName, out IntPtr hbmpValue);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LoadResourceIcon([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidPackage, [In] int culture, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszResourceName, [In] int cx, [In] int cy, out IntPtr hicoValue);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LoadResourceBlob([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid guidPackage, [In] int culture, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszResourceName, [ComAliasName("Microsoft.VisualStudio.TextManager.Interop.BYTE")] out IntPtr pBytes, out int lAllocated);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LoadResourceString2([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszAssemblyPath, [In] int culture, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszResourceName, [MarshalAs(UnmanagedType.BStr)] out string pbstrValue);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LoadResourceBitmap2([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszAssemblyPath, [In] int culture, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szResourceName, out IntPtr hbmpValue);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LoadResourceIcon2([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszAssemblyPath, [In] int culture, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszResourceName, [In] int cx, [In] int cy, out IntPtr hicoValue);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LoadResourceBlob2([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszAssemblyPath, [In] int culture, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszResourceName, [ComAliasName("Microsoft.VisualStudio.TextManager.Interop.BYTE")] out IntPtr pBytes, out int lAllocated);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSatelliteAssemblyPath([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string assemblyPath, [In] int lcid, [MarshalAs(UnmanagedType.BStr)] out string pbstrPath);
	}
	[ComImport]
	[Guid("E9706EF6-4F76-4C6E-8BF0-6E448550470B")]
	[InterfaceType(1)]
	public interface SVsResourceManager
	{
	}
	[Flags]
	public enum __VSADDNEWWEBITEMOPTIONS
	{
		VSADDWEBITEM_SelectMaster = 1,
		VSADDWEBITEM_SeparateCodeFile = 2,
		VSADDWEBITEM_SelectMasterIsValid = int.MinValue,
		VSADDWEBITEM_SeparateCodeFileIsValid = 0x40000000,
		VSADDWEBITEM_IsValidMask = -268435456
	}
	[ComImport]
	[Guid("41F92AB8-98B0-4CF4-907B-C5CE4403A570")]
	[InterfaceType(1)]
	public interface IVsAddNewWebProjectItemDlg
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddNewWebProjectItemDlg([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemidLoc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid rguidProject, [In][MarshalAs(UnmanagedType.Interface)] IVsProject pProject, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszDlgTitle, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszHelpTopic, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszLanguage, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszSelect, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSADDNEWWEBITEMOPTIONS")] uint options);
	}
	[ComImport]
	[Guid("0BD8000A-F537-4889-9FBC-C5F63B313956")]
	[InterfaceType(1)]
	public interface IVsWebProject
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddNewWebItem([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemidLoc, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSADDITEMOPERATION")] VSADDITEMOPERATION dwAddItemOperation, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszItemName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszFileTemplate, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSADDNEWWEBITEMOPTIONS")] uint options, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSelectedLanguage, [In] IntPtr hwndDlgOwner, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSADDRESULT")][MarshalAs(UnmanagedType.LPArray)] VSADDRESULT[] pResult);
	}
	public enum __VSHIERITEMATTRIBUTE
	{
		VSHIERITEMATTRIBUTE_Bold = 1
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("5B8C06A0-4379-4218-A046-B1DC466E5818")]
	public interface IVsUIHierarchyWindow2 : IVsUIHierarchyWindow
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Init([In][MarshalAs(UnmanagedType.Interface)] IVsUIHierarchy pUIH, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.UIHWINFLAGS")] uint grfUIHWF, [MarshalAs(UnmanagedType.IUnknown)] out object ppunkOut);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ExpandItem([In][MarshalAs(UnmanagedType.Interface)] IVsUIHierarchy pUIH, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.EXPANDFLAGS")] EXPANDFLAGS expf);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddUIHierarchy([In][MarshalAs(UnmanagedType.Interface)] IVsUIHierarchy pUIH, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSADDHIEROPTIONS")] uint grfAddOptions);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RemoveUIHierarchy([In][MarshalAs(UnmanagedType.Interface)] IVsUIHierarchy pUIH);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetWindowHelpTopic([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszHelpFile, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwContext);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetItemState([In][MarshalAs(UnmanagedType.Interface)] IVsUIHierarchy pHier, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSHIERARCHYITEMSTATE")] uint dwStateMask, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSHIERARCHYITEMSTATE")] out uint pdwState);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FindCommonSelectedHierarchy([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOMHIEROPTIONS")] uint grfOpt, [MarshalAs(UnmanagedType.Interface)] out IVsUIHierarchy lppCommonUIH);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetCursor([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.HCURSOR")] IntPtr hNewCursor, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.HCURSOR")] out IntPtr phOldCursor);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetCurrentSelection([MarshalAs(UnmanagedType.Interface)] out IVsHierarchy ppHier, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] out uint pitemid, [MarshalAs(UnmanagedType.Interface)] out IVsMultiItemSelect ppMIS);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetItemAttribute([In][MarshalAs(UnmanagedType.Interface)] IVsUIHierarchy pUIH, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSHIERITEMATTRIBUTE")] uint attribute, [In][MarshalAs(UnmanagedType.Struct)] object value);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("8E40D748-F682-4951-B465-16D0C252A69D")]
	public interface IVsProjectDataConnection
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetProjectSqlConnection([MarshalAs(UnmanagedType.IUnknown)] out object pConnection);
	}
	[ComImport]
	[Guid("AFA6B21D-D599-43F9-A3AB-0840359F11C3")]
	[InterfaceType(1)]
	public interface IVsTaskProvider3
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetProviderFlags([ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTASKPROVIDERFLAGS")] out uint tpfFlags);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetProviderName([MarshalAs(UnmanagedType.BStr)] out string pbstrName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetProviderGuid(out Guid pguidProvider);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSurrogateProviderGuid(out Guid pguidProvider);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetProviderToolbar(out Guid pguidGroup, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwID);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetColumnCount(out int pnColumns);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetColumn([In] int iColumn, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTASKCOLUMN")][MarshalAs(UnmanagedType.LPArray)] VSTASKCOLUMN[] pColumn);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnBeginTaskEdit([In][MarshalAs(UnmanagedType.Interface)] IVsTaskItem pItem);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnEndTaskEdit([In][MarshalAs(UnmanagedType.Interface)] IVsTaskItem pItem, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fCommitChanges, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfAllowChanges);
	}
	[StructLayout(LayoutKind.Sequential, Pack = 4)]
	public struct VSTASKCOLUMN
	{
		public int iField;

		[MarshalAs(UnmanagedType.BStr)]
		public string bstrHeading;

		public int iImage;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
		public int fShowSortArrow;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
		public int fAllowUserSort;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
		public int fVisibleByDefault;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
		public int fAllowHide;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
		public int fSizeable;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
		public int fMoveable;

		public int iDefaultSortPriority;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
		public int fDescendingSort;

		public int cxMinWidth;

		public int cxDefaultWidth;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
		public int fDynamicSize;

		[MarshalAs(UnmanagedType.BStr)]
		public string bstrCanonicalName;

		[MarshalAs(UnmanagedType.BStr)]
		public string bstrLocalizedName;

		[MarshalAs(UnmanagedType.BStr)]
		public string bstrTip;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
		public int fFitContent;
	}
	[ComImport]
	[Guid("F353950E-C381-4BA6-BCAA-6BA64E53D252")]
	[InterfaceType(1)]
	public interface IVsTaskItem3
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetTaskProvider([MarshalAs(UnmanagedType.Interface)] out IVsTaskProvider3 ppProvider);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetTaskName([MarshalAs(UnmanagedType.BStr)] out string pbstrName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetColumnValue([In] int iField, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTASKVALUETYPE")] out uint ptvtType, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTASKVALUEFLAGS")] out uint ptvfFlags, [MarshalAs(UnmanagedType.Struct)] out object pvarValue, [MarshalAs(UnmanagedType.BStr)] out string pbstrAccessibilityName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetTipText([In] int iField, [MarshalAs(UnmanagedType.BStr)] out string pbstrTipText);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetColumnValue([In] int iField, [In][MarshalAs(UnmanagedType.Struct)] ref object pvarValue);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsDirty([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfDirty);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetEnumCount([In] int iField, out int pnValues);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetEnumValue([In] int iField, [In] int iValue, [MarshalAs(UnmanagedType.Struct)] out object pvarValue, [MarshalAs(UnmanagedType.BStr)] out string pbstrAccessibilityName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnLinkClicked([In] int iField, [In] int iLinkIndex);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetNavigationStatusText([MarshalAs(UnmanagedType.BStr)] out string pbstrText);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetDefaultEditField(out int piField);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSurrogateProviderGuid(out Guid pguidProvider);
	}
	public enum __VSTASKLISTSELECTIONSCROLLPOS
	{
		TSSP_NOSCROLL,
		TSSP_CENTERCARET,
		TSSP_CARETATTOP,
		TSSP_CARETATBOTTOM,
		TSSP_MINSCROLL,
		TSSP_SHOWALL
	}
	public enum __VSTASKLISTSELECTIONTYPE
	{
		TST_REPLACESEL,
		TST_EXTENDSEL,
		TST_ADDTOSEL
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("62357211-57FD-4425-A9E5-9A6E0D3B731C")]
	public interface IVsTaskList2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSelectionCount(out int pnItems);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetCaretPos([MarshalAs(UnmanagedType.Interface)] out IVsTaskItem ppItem);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EnumSelectedItems([MarshalAs(UnmanagedType.Interface)] out IVsEnumTaskItems ppEnum);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SelectItems([In] int nItems, [In][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.Interface, SizeParamIndex = 0)] IVsTaskItem[] pItems, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTASKLISTSELECTIONTYPE")] uint tsfSelType, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSTASKLISTSELECTIONSCROLLPOS")] uint tsspScrollPos);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int BeginTaskEdit([In][MarshalAs(UnmanagedType.Interface)] IVsTaskItem pItem, [In] int iFocusField);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetActiveProvider([MarshalAs(UnmanagedType.Interface)] out IVsTaskProvider ppProvider);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetActiveProvider([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid rguidProvider);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RefreshOrAddTasks([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] uint vsProviderCookie, [In] int nTasks, [In][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.Interface, SizeParamIndex = 1)] IVsTaskItem[] prgTasks);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RemoveTasks([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] uint vsProviderCookie, [In] int nTasks, [In][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.Interface, SizeParamIndex = 1)] IVsTaskItem[] prgTasks);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RefreshAllProviders();
	}
	[Flags]
	public enum __VSTASKPROVIDERFLAGS
	{
		TPF_ALWAYSVISIBLE = 1,
		TPF_NOAUTOROUTING = 2
	}
	public abstract class TaskProviderGuids
	{
		[MarshalAs(UnmanagedType.LPStr)]
		public const string Comments = "{5A2D2729-ADFF-4a2e-A44F-55EBBF5DF64B}";
	}
	public enum __VSTASKVALUETYPE
	{
		TVT_NULL,
		TVT_TEXT,
		TVT_LINKTEXT,
		TVT_BASE10,
		TVT_IMAGE
	}
	[Flags]
	public enum __VSTASKVALUEFLAGS
	{
		TVF_EDITABLE = 1,
		TVF_ENUM = 2,
		TVF_BINARY_STATE = 4,
		TVF_HORZ_RIGHT = 8,
		TVF_HORZ_CENTER = 0x10,
		TVF_STRIKETHROUGH = 0x20,
		TVF_FILENAME = 0x40
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("D824A797-62D2-4F60-98F8-4423624BC1BF")]
	public interface IVsErrorList
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int BringToFront();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ForceShowErrors();
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("599BCD9E-CAFA-43DF-AA03-129C0004C2BD")]
	public interface SVsErrorList
	{
	}
	public enum __VSERRORCATEGORY
	{
		EC_ERROR,
		EC_WARNING,
		EC_MESSAGE
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("CE3DF110-7630-4D6C-81D5-5CFA12ADDAE6")]
	public interface IVsErrorItem
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetHierarchy([MarshalAs(UnmanagedType.Interface)] out IVsHierarchy ppProject);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetCategory([ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSERRORCATEGORY")] out uint pCategory);
	}
	[ComImport]
	[Guid("072B9701-2F81-4468-8EB6-074206504B62")]
	[InterfaceType(1)]
	public interface IVsWindowPaneCommitFilter
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsCommitCommand([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid pguidCmdGroup, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwCmdID, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfCommitCommand);
	}
	[ComImport]
	[Guid("03AEFCEA-62A9-4606-8E17-7CB0FC13D5E0")]
	[InterfaceType(1)]
	public interface IPreferPropertyPagesWithTreeControl
	{
	}
	[ComImport]
	[Guid("E7E36A24-6435-48FB-8E5B-D2589FC18D72")]
	[InterfaceType(1)]
	public interface IVsSpecifyProjectDesignerPages
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetProjectDesignerPages([Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.CAUUID")][MarshalAs(UnmanagedType.LPArray)] CAUUID[] pPages);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("77F54647-95E6-4033-91A8-51CCD014D945")]
	public interface IVsDeployDependency2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_Property([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szProperty, [MarshalAs(UnmanagedType.Struct)] out object pvar);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("06A3B841-FBEA-46CB-81EA-36DB4D005545")]
	public interface IVsOutputGroup2 : IVsOutputGroup
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_CanonicalName([MarshalAs(UnmanagedType.BStr)] out string pbstrCanonicalName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_DisplayName([MarshalAs(UnmanagedType.BStr)] out string pbstrDisplayName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_KeyOutput([MarshalAs(UnmanagedType.BStr)] out string pbstrCanonicalName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_ProjectCfg([MarshalAs(UnmanagedType.Interface)] out IVsProjectCfg2 ppIVsProjectCfg2);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_Outputs([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.Interface, SizeParamIndex = 0)] IVsOutput2[] rgpcfg, [Optional][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")][MarshalAs(UnmanagedType.LPArray)] uint[] pcActual);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_DeployDependencies([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.Interface, SizeParamIndex = 0)] IVsDeployDependency[] rgpdpd, [Optional][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")][MarshalAs(UnmanagedType.LPArray)] uint[] pcActual);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_Description([MarshalAs(UnmanagedType.BStr)] out string pbstrDescription);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_KeyOutputObject([MarshalAs(UnmanagedType.Interface)] out IVsOutput2 ppKeyOutput);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_Property([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszProperty, [MarshalAs(UnmanagedType.Struct)] out object pvar);
	}
	public enum __VSCOLORTYPE
	{
		CT_INVALID,
		CT_RAW,
		CT_COLORINDEX,
		CT_SYSCOLOR,
		CT_VSCOLOR,
		CT_AUTOMATIC,
		CT_TRACK_FOREGROUND,
		CT_TRACK_BACKGROUND
	}
	public enum __VSCOLORASPECT
	{
		CA_FOREGROUND,
		CA_BACKGROUND
	}
	[ComImport]
	[Guid("A356A017-07EE-4D06-ACDE-FEFDBB49EB50")]
	[InterfaceType(1)]
	public interface IVsFontAndColorUtilities
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EncodeIndexedColor([In][ComAliasName("Microsoft.VisualStudio.TextManager.Interop.COLORINDEX")] COLORINDEX idx, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.COLORREF")] out uint pcrResult);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EncodeSysColor([In] int iSysColor, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.COLORREF")] out uint pcrResult);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EncodeVSColor([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSSYSCOLOREX")] int vsColor, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.COLORREF")] out uint pcrResult);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EncodeTrackedItem([In] int iItemToTrack, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOLORASPECT")] int aspect, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.COLORREF")] out uint pcrResult);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EncodeInvalidColor([ComAliasName("Microsoft.VisualStudio.Shell.Interop.COLORREF")] out uint pcrResult);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EncodeAutomaticColor([ComAliasName("Microsoft.VisualStudio.Shell.Interop.COLORREF")] out uint pcrResult);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetColorType([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.COLORREF")] uint crSource, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOLORTYPE")] out int pctType);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetEncodedIndex([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.COLORREF")] uint crSource, [Out][ComAliasName("Microsoft.VisualStudio.TextManager.Interop.COLORINDEX")][MarshalAs(UnmanagedType.LPArray)] COLORINDEX[] pIdx);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetEncodedSysColor([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.COLORREF")] uint crSource, out int piSysColor);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetEncodedVSColor([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.COLORREF")] uint crSource, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSSYSCOLOREX")] out int pVSColor);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetTrackedItemIndex([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.COLORREF")] uint crSource, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOLORASPECT")] out int pAspect, out int piItem);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetRGBOfIndex([In][ComAliasName("Microsoft.VisualStudio.TextManager.Interop.COLORINDEX")] COLORINDEX idx, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.COLORREF")] out uint pcrResult);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetRGBOfItem([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.AllColorableItemInfo")][MarshalAs(UnmanagedType.LPArray)] AllColorableItemInfo[] pInfo, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid rguidCategory, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.COLORREF")] out uint pcrForeground, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.COLORREF")] out uint pcrBackground);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetRGBOfEncodedColor([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.COLORREF")] uint crSource, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.COLORREF")] uint crAutoColor, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid rguidCategory, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.COLORREF")] out uint pcrResult);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int InitFontInfo([In][Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.FontInfo")][MarshalAs(UnmanagedType.LPArray)] FontInfo[] pInfo);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FreeFontInfo([In][Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.FontInfo")][MarshalAs(UnmanagedType.LPArray)] FontInfo[] pInfo);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CopyFontInfo([In][Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.FontInfo")][MarshalAs(UnmanagedType.LPArray)] FontInfo[] pDest, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.FontInfo")][MarshalAs(UnmanagedType.LPArray)] FontInfo[] pSource);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int InitItemInfo([In][Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.AllColorableItemInfo")][MarshalAs(UnmanagedType.LPArray)] AllColorableItemInfo[] pInfo);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FreeItemInfo([In][Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.AllColorableItemInfo")][MarshalAs(UnmanagedType.LPArray)] AllColorableItemInfo[] pInfo);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CopyItemInfo([In][Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.AllColorableItemInfo")][MarshalAs(UnmanagedType.LPArray)] AllColorableItemInfo[] pDest, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.AllColorableItemInfo")][MarshalAs(UnmanagedType.LPArray)] AllColorableItemInfo[] pSource);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("F4DEB52C-53A3-42FD-A039-3493F09E53FC")]
	public interface IVsOutputWindow2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetActivePaneGUID(out Guid pguidPane);
	}
	[ComImport]
	[Guid("2559D053-417E-4276-A905-193191B5816A")]
	[InterfaceType(1)]
	public interface IVsDebuggableProjectCfg2 : IVsDebuggableProjectCfg
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_DisplayName([MarshalAs(UnmanagedType.BStr)] out string pbstrDisplayName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_IsDebugOnly([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfIsDebugOnly);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_IsReleaseOnly([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfIsReleaseOnly);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EnumOutputs([MarshalAs(UnmanagedType.Interface)] out IVsEnumOutputs ppIVsEnumOutputs);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OpenOutput([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szOutputCanonicalName, [MarshalAs(UnmanagedType.Interface)] out IVsOutput ppIVsOutput);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_ProjectCfgProvider([MarshalAs(UnmanagedType.Interface)] out IVsProjectCfgProvider ppIVsProjectCfgProvider);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_BuildableProjectCfg([MarshalAs(UnmanagedType.Interface)] out IVsBuildableProjectCfg ppIVsBuildableProjectCfg);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_CanonicalName([MarshalAs(UnmanagedType.BStr)] out string pbstrCanonicalName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_Platform(out Guid pguidPlatform);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_IsPackaged([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfIsPackaged);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_IsSpecifyingOutputSupported([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfIsSpecifyingOutputSupported);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_TargetCodePage([ComAliasName("Microsoft.VisualStudio.OLE.Interop.UINT")] out uint puiTargetCodePage);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_UpdateSequenceNumber([Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULARGE_INTEGER")][MarshalAs(UnmanagedType.LPArray)] ULARGE_INTEGER[] puliUSN);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int get_RootURL([MarshalAs(UnmanagedType.BStr)] out string pbstrRootURL);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int DebugLaunch([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSDBGLAUNCHFLAGS")] uint grfLaunch);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int QueryDebugLaunch([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSDBGLAUNCHFLAGS")] uint grfLaunch, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfCanLaunch);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnBeforeDebugLaunch([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSDBGLAUNCHFLAGS")] uint grfLaunch);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("3931DEF1-8200-481F-A6C2-A4740DE84658")]
	public interface IVsProvideUserContext2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetUserContextEx([MarshalAs(UnmanagedType.Interface)] out IVsUserContext ppctx, out int iPriority);
	}
	[ComImport]
	[Guid("A17BE28D-6CDC-4C1E-BE3E-F0ED067EA3E2")]
	[InterfaceType(1)]
	public interface IVsExtensibility3
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetProperties([In][MarshalAs(UnmanagedType.IUnknown)] object pParent, [In][MarshalAs(UnmanagedType.IDispatch)] object pdispPropObj, [MarshalAs(UnmanagedType.IDispatch)] out object ppProperties);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RunWizardFile([In][MarshalAs(UnmanagedType.BStr)] string bstrWizFilename, [In] int hwndOwner, [In][MarshalAs(UnmanagedType.SafeArray, SafeArraySubType = VarEnum.VT_VARIANT)] ref Array vContextParams, out int pResult);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EnterAutomationFunction();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ExitAutomationFunction();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsInAutomationFunction([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfInAutoFunc);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetUserControl(out bool fUserControl);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetUserControl([In] bool fUserControl);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetUserControlUnlatched([In] bool fUserControl);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int LockServer([In] bool __MIDL_0010);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetLockCount(out int pCount);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int TestForShutdown(out bool fShutdown);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetGlobalsObject([In][MarshalAs(UnmanagedType.Struct)] object ExtractFrom, [MarshalAs(UnmanagedType.IUnknown)] out object ppGlobals);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetConfigMgr([In][MarshalAs(UnmanagedType.IUnknown)] object pIVsProject, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] uint itemid, [MarshalAs(UnmanagedType.IUnknown)] out object ppCfgMgr);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FireMacroReset();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetDocumentFromDocCookie([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG_PTR")] int lDocCookie, [MarshalAs(UnmanagedType.IUnknown)] out object ppDoc);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsMethodDisabled([In] ref Guid pGuid, [In] int dispid);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetSuppressUI([In] bool In);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSuppressUI([In][Out] ref bool pOut);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FireProjectsEvent_ItemAdded([In][MarshalAs(UnmanagedType.IUnknown)] object Project);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FireProjectsEvent_ItemRemoved([In][MarshalAs(UnmanagedType.IUnknown)] object Project);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FireProjectsEvent_ItemRenamed([In][MarshalAs(UnmanagedType.IUnknown)] object Project, [In][MarshalAs(UnmanagedType.BStr)] string OldName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FireProjectItemsEvent_ItemAdded([In][MarshalAs(UnmanagedType.IUnknown)] object ProjectItem);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FireProjectItemsEvent_ItemRemoved([In][MarshalAs(UnmanagedType.IUnknown)] object ProjectItem);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FireProjectItemsEvent_ItemRenamed([In][MarshalAs(UnmanagedType.IUnknown)] object ProjectItem, [In][MarshalAs(UnmanagedType.BStr)] string OldName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsFireCodeModelEventNeeded([In][Out] ref bool vbNeeded);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RunWizardFileEx([In][MarshalAs(UnmanagedType.BStr)] string bstrWizFilename, [In] int hwndOwner, [In][MarshalAs(UnmanagedType.SafeArray, SafeArraySubType = VarEnum.VT_VARIANT)] ref Array vContextParams, [In][MarshalAs(UnmanagedType.SafeArray, SafeArraySubType = VarEnum.VT_VARIANT)] ref Array vCustomParams, out int pResult);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FireCodeModelEvent3([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DISPID")] int dispid, [In][MarshalAs(UnmanagedType.IDispatch)] object pParent, [In][MarshalAs(UnmanagedType.IUnknown)] object pElement, [In] int changeKind);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("5447CE90-561E-4C8E-BE70-9FD5F89BCFA7")]
	public interface IVsGlobalsCallback2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int WriteVariablesToData([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pVariableName, [In][MarshalAs(UnmanagedType.Struct)] ref object varData);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ReadData([In][MarshalAs(UnmanagedType.IUnknown)] object pGlobals);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ClearVariables();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int VariableChanged();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CanModifySource();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetParent([MarshalAs(UnmanagedType.IDispatch)] ref object ppOut);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("AC735863-23EF-46ED-A3EC-87B58B3DF5DA")]
	public interface IVsGlobals2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Load();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Save();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Empty();
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("3A83904D-4540-4C51-95A7-618B32A9A9C0")]
	public interface IVsProfferCommands3
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddNamedCommand([In] ref Guid pguidPackage, [In] ref Guid pguidCmdGroup, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszCmdNameCanonical, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwCmdId, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszCmdNameLocalized, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszBtnText, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszCmdTooltip, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSatelliteDLL, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwBitmapResourceId, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwBitmapImageIndex, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwCmdFlagsDefault, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint cUIContexts, [In][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 11)] Guid[] rgguidUIContexts);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RemoveNamedCommand([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszCmdNameCanonical);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RenameNamedCommand([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszCmdNameCanonical, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszCmdNameCanonicalNew, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszCmdNameLocalizedNew);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddCommandBarControl([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszCmdNameCanonical, [In][MarshalAs(UnmanagedType.IDispatch)] object pCmdBarParent, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwIndex, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwCmdType, [MarshalAs(UnmanagedType.IDispatch)] out object ppCmdBarCtrl);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RemoveCommandBarControl([In][MarshalAs(UnmanagedType.IDispatch)] object pCmdBarCtrl);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddCommandBar([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszCmdBarName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwType, [In][MarshalAs(UnmanagedType.IDispatch)] object pCmdBarParent, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwIndex, [MarshalAs(UnmanagedType.IDispatch)] out object ppCmdBar);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RemoveCommandBar([In][MarshalAs(UnmanagedType.IDispatch)] object pCmdBar);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FindCommandBar([In][MarshalAs(UnmanagedType.IUnknown)] object pToolbarSet, [In] ref Guid pguidCmdGroup, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwMenuId, [MarshalAs(UnmanagedType.IDispatch)] out object ppdispCmdBar);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddNamedCommand2([In] ref Guid pguidPackage, [In] ref Guid pguidCmdGroup, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszCmdNameCanonical, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwCmdId, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszCmdNameLocalized, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszBtnText, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszCmdTooltip, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSatelliteDLL, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwBitmapResourceId, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwBitmapImageIndex, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwCmdFlagsDefault, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint cUIContexts, [In][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 11)] Guid[] rgguidUIContexts, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwUIElementType);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("FE5FEE31-C302-4961-876F-F3C8F853E4F8")]
	public interface IVsHierarchyRefactorNotify
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnBeforeGlobalSymbolRenamed([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cItemsAffected, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)] uint[] rgItemsAffected, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cRQNames, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 2)] string[] rglpszRQName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszNewName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int promptContinueOnFail);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnGlobalSymbolRenamed([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cItemsAffected, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)] uint[] rgItemsAffected, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cRQNames, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 2)] string[] rglpszRQName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszNewName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnBeforeReorderParams([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszRQName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cParamIndexes, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] uint[] rgParamIndexes, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int promptContinueOnFail);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnReorderParams([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszRQName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cParamIndexes, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] uint[] rgParamIndexes);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnBeforeRemoveParams([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszRQName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cParamIndexes, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] uint[] rgParamIndexes, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int promptContinueOnFail);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnRemoveParams([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszRQName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cParamIndexes, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] uint[] rgParamIndexes);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnBeforeAddParams([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszRQName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cParams, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] uint[] rgszParamIndexes, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 2)] string[] rgszRQTypeNames, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 2)] string[] rgszParamNames, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int promptContinueOnFail);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnAddParams([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszRQName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cParams, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] uint[] rgszParamIndexes, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 2)] string[] rgszRQTypeNames, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 2)] string[] rgszParamNames);
	}
	[ComImport]
	[Guid("130497E3-5CDB-4F29-9804-A2AF805016D7")]
	[InterfaceType(1)]
	public interface IVsRefactorNotify
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnBeforeGlobalSymbolRenamed([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHier, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cRQNames, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 2)] string[] rglpszRQName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszNewName, [MarshalAs(UnmanagedType.SafeArray, SafeArraySubType = VarEnum.VT_UI4)] out Array prgAdditionalCheckoutVSITEMIDs);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnGlobalSymbolRenamed([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHier, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cRQNames, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 2)] string[] rglpszRQName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszNewName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnBeforeReorderParams([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHier, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszRQName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cParamIndexes, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 3)] uint[] rgParamIndexes, [MarshalAs(UnmanagedType.SafeArray, SafeArraySubType = VarEnum.VT_UI4)] out Array prgAdditionalCheckoutVSITEMIDs);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnReorderParams([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHier, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszRQName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cParamIndexes, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 3)] uint[] rgParamIndexes);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnBeforeRemoveParams([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHier, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszRQName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cParamIndexes, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 3)] uint[] rgParamIndexes, [MarshalAs(UnmanagedType.SafeArray, SafeArraySubType = VarEnum.VT_UI4)] out Array prgAdditionalCheckoutVSITEMIDs);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnRemoveParams([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHier, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszRQName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cParamIndexes, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 3)] uint[] rgParamIndexes);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnBeforeAddParams([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHier, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszRQName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cParams, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 3)] uint[] rgszParamIndexes, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 3)] string[] rgszRQTypeNames, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 3)] string[] rgszParamNames, [MarshalAs(UnmanagedType.SafeArray, SafeArraySubType = VarEnum.VT_UI4)] out Array prgAdditionalCheckoutVSITEMIDs);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnAddParams([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHier, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszRQName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cParams, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 3)] uint[] rgszParamIndexes, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 3)] string[] rgszRQTypeNames, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 3)] string[] rgszParamNames);
	}
	[ComImport]
	[Guid("692E4F21-1EF2-41B1-9116-EED8DAA79E7F")]
	[InterfaceType(1)]
	public interface IVsMonitorSelection2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetElementID([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid rguidElement, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSSELELEMID")] out uint pElementId);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetEmptySelectionContext([MarshalAs(UnmanagedType.Interface)] out IVsTrackSelectionEx ppEmptySelCtxt);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("AE31D40E-CD7A-45CB-8DEF-5EA0E44C688A")]
	public interface IVsToolsOptions
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsToolsOptionsOpen([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfOpen);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RefreshPageVisibility();
	}
	[ComImport]
	[Guid("376208E4-2679-4C9E-B3D5-929EB0F1A1F7")]
	[InterfaceType(1)]
	public interface SVsToolsOptions
	{
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("A981529F-4D0D-46EE-A758-AC26E50E099D")]
	public interface IVsDeployableProjectCfg2 : IVsDeployableProjectCfg
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AdviseDeployStatusCallback([In][MarshalAs(UnmanagedType.Interface)] IVsDeployStatusCallback pIVsDeployStatusCallback, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] out uint pdwCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UnadviseDeployStatusCallback([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] uint dwCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int StartDeploy([In][MarshalAs(UnmanagedType.Interface)] IVsOutputWindowPane pIVsOutputWindowPane, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwOptions);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int QueryStatusDeploy([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfDeployDone);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int StopDeploy([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fSync);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int WaitDeploy([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwMilliseconds, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fTickWhenMessageQNotEmpty);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int QueryStartDeploy([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwOptions, [Optional][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")][MarshalAs(UnmanagedType.LPArray)] int[] pfSupported, [Optional][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")][MarshalAs(UnmanagedType.LPArray)] int[] pfReady);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Commit([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwReserved);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Rollback([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwReserved);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int StartCleanDeploy([In][MarshalAs(UnmanagedType.Interface)] IVsOutputWindowPane pIVsOutputWindowPane, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwOptions);
	}
	[ComImport]
	[Guid("1EE6C79A-B763-42E6-AC95-FD0CC00DE315")]
	[InterfaceType(1)]
	public interface IVsFontAndColorStorage2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RevertFontToDefault();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RevertItemToDefault([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RevertAllItemsToDefault();
	}
	public enum __VSSHOWCONTEXTMENUOPTS
	{
		VSCTXMENU_SELECTFIRSTITEM = 0x10000,
		VSCTXMENU_SHOWUNDERLINES = 0x20000,
		VSCTXMENU_SUPPORTSTYPEAHEAD = 0x40000
	}
	[ComImport]
	[Guid("9EB7079F-3445-4C43-99D8-46EA8CA1D659")]
	[InterfaceType(1)]
	public interface IVsDocOutlineProvider2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int TranslateAccelerator([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.lpmsg")][MarshalAs(UnmanagedType.LPArray)] MSG[] lpMsg);
	}
	public enum __VSCREATEWEBBROWSER2
	{
		VSCWB_NoHistoryThisPage = 1048576,
		VSCWB_NavOptionMask2 = 2031616
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("3411DD99-2445-43C8-918E-99BFBFAF8292")]
	public interface IVSMDTypeResolutionService
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int TypeResolutionService([MarshalAs(UnmanagedType.IDispatch)] out object ppTrs);
	}
	[StructLayout(LayoutKind.Sequential, Pack = 4)]
	public struct VSDEFAULTPREVIEWER
	{
		[MarshalAs(UnmanagedType.BStr)]
		public string bstrDefBrowserPath;

		[MarshalAs(UnmanagedType.BStr)]
		public string bstrDefBrowserDisplayName;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
		public int fIsInternalBrowser;

		[ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")]
		public int fIsSystemBrowser;

		[ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSPREVIEWRESOLUTION")]
		public VSPREVIEWRESOLUTION defRes;
	}
	[ComImport]
	[Guid("0649BDA0-0978-4CA0-AB0B-0F619199BCCA")]
	[InterfaceType(1)]
	public interface IVsUIShellOpenDocument2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetDefaultPreviewers([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSDEFAULTPREVIEWER")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)] VSDEFAULTPREVIEWER[] rgDefaultPreviewers, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcActual);
	}
	[ComImport]
	[Guid("B10EC465-CEC8-41CD-A132-6C1A58F565FB")]
	[InterfaceType(1)]
	public interface IVsFilterNewProjectDlg
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FilterTreeItemByLocalizedName([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszLocalizedName, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfFilter);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FilterTreeItemByTemplateDir([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszTemplateDir, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfFilter);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FilterListItemByLocalizedName([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszLocalizedName, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfFilter);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int FilterListItemByTemplateFile([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszTemplateFile, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfFilter);
	}
	[ComImport]
	[Guid("9455BDB5-2A5A-45F1-A558-72B88A78E6E3")]
	[InterfaceType(1)]
	public interface IVsRegisterNewDialogFilters
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RegisterNewProjectDialogFilter([In][MarshalAs(UnmanagedType.Interface)] IVsFilterNewProjectDlg pFilter, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] out uint pdwFilterCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UnregisterNewProjectDialogFilter([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] uint dwFilterCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RegisterAddNewItemDialogFilter([In][MarshalAs(UnmanagedType.Interface)] IVsFilterAddProjectItemDlg pFilter, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] out uint pdwFilterCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UnregisterAddNewItemDialogFilter([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] uint dwFilterCookie);
	}
	[ComImport]
	[Guid("CB7C5B29-6782-47B7-AA13-21D07026D5E1")]
	[InterfaceType(1)]
	public interface SVsRegisterNewDialogFilters
	{
	}
	[ComImport]
	[Guid("821ABD48-96DC-4315-A2C4-82A7239B8166")]
	[InterfaceType(1)]
	public interface IVsWebBrowserUser2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetWebBrowserContext([MarshalAs(UnmanagedType.Interface)] out Microsoft.VisualStudio.OLE.Interop.IServiceProvider ppServiceProvider);
	}
	[ComImport]
	[Guid("D82269C8-C3DB-4BD9-AF32-AB140BCFDAE3")]
	[InterfaceType(1)]
	public interface IVsHasRelatedSaveItems
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetRelatedSaveTreeItems([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSSAVETREEITEM")] VSSAVETREEITEM saveItem, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSSAVETREEITEM")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] VSSAVETREEITEM[] rgSaveTreeItems, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pcActual);
	}
	[ComImport]
	[Guid("9947783D-B173-4FD9-8E6E-91482CF9E239")]
	[InterfaceType(1)]
	public interface IDiscoveryResult2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int DownloadServiceDocument([In][MarshalAs(UnmanagedType.BStr)] string bstrDestinationPath, [In][MarshalAs(UnmanagedType.BStr)] string bstrDiscomapFileName, [MarshalAs(UnmanagedType.Interface)] out IDiscoveryClientResultCollection ppIDiscoveryClientResultCollection);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("BCEB2C6C-E0D1-4FA5-8DDC-977D68E8D50B")]
	public interface IDiscoveryClientResultCollection
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetResultCount(out int pCount);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetResult([In] int pIndex, [MarshalAs(UnmanagedType.Interface)] out IDiscoveryClientResult ppIDiscoveryClientResult);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("FC5E8B09-FF17-4DA6-BA39-EB8DFC314BC1")]
	public interface IDiscoveryClientResult
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetFileName([MarshalAs(UnmanagedType.BStr)] out string pbstrFilename);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetReferenceTypeName([MarshalAs(UnmanagedType.BStr)] out string pbstrReferenceTypeName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetUrl([MarshalAs(UnmanagedType.BStr)] out string pbstrUrl);
	}
	[Flags]
	public enum __VSQueryEditFlags2
	{
		QEF_AllowUnopenedProjects = 0x80,
		QEF_CheckoutLocalVersion = 0x100,
		QEF_CheckoutLatestVersion = 0x200,
		QEF_DetectAnyChangedFile = 0x400
	}
	[Flags]
	public enum tagVSQueryEditResultFlags2
	{
		QER_Reloaded = 0x200,
		QER_Changed = 0x400
	}
	public enum __HANDSOFFMODE
	{
		HANDSOFFMODE_ReadAccess = 1,
		HANDSOFFMODE_WriteAccess = 2,
		HANDSOFFMODE_DeleteAccess = 4,
		HANDSOFFMODE_AsyncOperation = int.MinValue,
		HANDSOFFMODE_FullAccess = 7,
		HANDSOFFMODE_ReadWriteAccess = 3
	}
	[ComImport]
	[Guid("53544C4D-BD74-4D21-A79F-2C190E38AB6F")]
	[InterfaceType(1)]
	public interface IVsTrackProjectDocumentsEvents3
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnBeginQueryBatch();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnEndQueryBatch([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfActionOK);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnCancelQueryBatch();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnQueryAddFilesEx([In][MarshalAs(UnmanagedType.Interface)] IVsProject pProject, [In] int cFiles, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 1)] string[] rgpszNewMkDocuments, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 1)] string[] rgpszSrcMkDocuments, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSQUERYADDFILEFLAGS")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] VSQUERYADDFILEFLAGS[] rgFlags, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSQUERYADDFILERESULTS")][MarshalAs(UnmanagedType.LPArray)] VSQUERYADDFILERESULTS[] pSummaryResult, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSQUERYADDFILERESULTS")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] VSQUERYADDFILERESULTS[] rgResults);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int HandsOffFiles([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.HANDSOFFMODE")] uint grfRequiredAccess, [In] int cFiles, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 1)] string[] rgpszMkDocuments);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int HandsOnFiles([In] int cFiles, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 0)] string[] rgpszMkDocuments);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("53544C4D-9097-4325-9270-754EB85A6351")]
	public interface IVsTrackProjectDocuments3
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int BeginQueryBatch();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EndQueryBatch([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfActionOK);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CancelQueryBatch();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnQueryAddFilesEx([In][MarshalAs(UnmanagedType.Interface)] IVsProject pProject, [In] int cFiles, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 1)] string[] rgpszNewMkDocuments, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 1)] string[] rgpszSrcMkDocuments, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSQUERYADDFILEFLAGS")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] VSQUERYADDFILEFLAGS[] rgFlags, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSQUERYADDFILERESULTS")][MarshalAs(UnmanagedType.LPArray)] VSQUERYADDFILERESULTS[] pSummaryResult, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSQUERYADDFILERESULTS")][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] VSQUERYADDFILERESULTS[] rgResults);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int HandsOffFiles([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.HANDSOFFMODE")] uint grfRequiredAccess, [In] int cFiles, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 1)] string[] rgpszMkDocuments);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int HandsOnFiles([In] int cFiles, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 0)] string[] rgpszMkDocuments);
	}
	[ComImport]
	[Guid("56BC6B2E-539A-42BA-B7A9-CD9A201B7657")]
	[TypeLibType(528)]
	[InterfaceType(1)]
	public interface IVsTypeLibraryWrapperBatchSupport
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int StartBatch();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int StopBatch();
	}
	[Flags]
	public enum __VSCOMPENUMEXFLAGS
	{
		VSCOMPENUM_IncludeRuntimeInfo = 1
	}
	[ComImport]
	[Guid("0C2B582A-DDB2-440C-A777-3D46C3502337")]
	[InterfaceType(1)]
	public interface IVsComponentEnumeratorFactory3
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetComponentsOfPathEx([In][MarshalAs(UnmanagedType.BStr)] string bstrMachineName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int lEnumType, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int bForceRefresh, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOMPENUMEXFLAGS")] uint grfFlags, [In][MarshalAs(UnmanagedType.BStr)] string bstrPath, [MarshalAs(UnmanagedType.Interface)] out IEnumComponents pEnumerator);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("677D16F2-982E-49E6-ACDB-797991764AD8")]
	public interface IVsSmartOpenScope
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OpenScope([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string wszScope, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwOpenFlags, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riid, [MarshalAs(UnmanagedType.IUnknown)] out object ppIUnk);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("52F0DAB8-99A9-4AEA-A037-42581B7009D2")]
	public interface SVsSmartOpenScope
	{
	}
	[ComImport]
	[Guid("F33D7D20-49CE-47A7-9E3B-DCC9DD19AF00")]
	[InterfaceType(1)]
	public interface IVsAssemblyNameUnification
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetUnifiedAssemblyName([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string wszFrameworkDirectory, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string wszSimpleAssemblyName, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string wszFullAssemblyName, [MarshalAs(UnmanagedType.BStr)] out string pbstrUnifiedAssemblyName);
	}
	[ComImport]
	[Guid("B54B4062-117D-46FC-BE19-CD20F2867D52")]
	[InterfaceType(1)]
	public interface SVsAssemblyNameUnification
	{
	}
	[Flags]
	public enum _SqlReferenceUpdateFlags
	{
		SqlReferenceUpdateFlags_ForceUpdate = 1
	}
	[Flags]
	public enum _SqlAddNewReferenceFlags
	{
		SqlAddNewReferenceFlags_DownloadSelected = 1
	}
	public enum _SqlReferenceUpdateAction
	{
		SqlReferenceUpdateAction_None = 1,
		SqlReferenceUpdateAction_Delete,
		SqlReferenceUpdateAction_Update
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("7E6F344E-52C0-4EDC-814B-16C6DE4AE9B4")]
	public interface IVsSQLCLRReferencesUpdateCallback
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UpdateResult([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string szAssembly, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwPermisionLevel, [In][MarshalAs(UnmanagedType.Error)] int hrUpdateResult, [In][MarshalAs(UnmanagedType.Interface)] IErrorInfo pErrorInfo, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.SqlReferenceUpdateAction")] uint updateAction);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("1CF2B120-547D-101B-8E65-08002B2BD119")]
	public interface IErrorInfo
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetGuid(out Guid pGuid);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSource([MarshalAs(UnmanagedType.BStr)] out string pBstrSource);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetDescription([MarshalAs(UnmanagedType.BStr)] out string pbstrDescription);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetHelpFile([MarshalAs(UnmanagedType.BStr)] out string pBstrHelpFile);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetHelpContext([ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwHelpContext);
	}
	[ComImport]
	[Guid("7E6F344D-52C0-4EDC-814B-16C6DE4AE9B4")]
	[InterfaceType(1)]
	public interface IVsSQLCLRReferences
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int InvokeNewReferencesDlg([In][MarshalAs(UnmanagedType.IUnknown)] object pConnection, [In][MarshalAs(UnmanagedType.IUnknown)] object pAssemblySupport, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.SqlAddNewReferenceFlags")] uint dwAddNewReferenceFlags, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string szLocalCache, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwProjectPermisionLevel, [In][MarshalAs(UnmanagedType.Interface)] IVsComponentUser pComponentUserCallback);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UpdateReferences([In][MarshalAs(UnmanagedType.IUnknown)] object pConnection, [In][MarshalAs(UnmanagedType.IUnknown)] object pAssemblySupport, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.SqlReferenceUpdateFlags")] uint dwReferenceUpdateFlags, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cAssemblyCount, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 3)] string[] rgszAssemblies, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string szLocalCache, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwProjectPermisionLevel, [In][MarshalAs(UnmanagedType.Interface)] IVsSQLCLRReferencesUpdateCallback pCallBack);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("8ED9966C-102F-45B0-8293-BB9F2463A6F2")]
	public interface SVsSQLCLRReferences
	{
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("AF855397-C4DC-478B-ABD4-C3DBB3759E72")]
	public interface IVsEnumCryptoProviderContainers
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Next([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.BStr, SizeParamIndex = 0)] string[] pbstrContainers, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pceltFetched);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Reset();
	}
	[ComImport]
	[Guid("F7FC33A9-10DA-42BE-9F88-9700E583EC33")]
	[InterfaceType(1)]
	public interface IVsEnumCryptoProviders
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Next([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.BStr, SizeParamIndex = 0)] string[] pbstrProviders, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pceltFetched);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Reset();
	}
	[ComImport]
	[Guid("B0DE8148-DABC-4AB9-B418-413E63DF6E6C")]
	[InterfaceType(1)]
	public interface IVsStrongNameKeys
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EnumProviders([MarshalAs(UnmanagedType.Interface)] out IVsEnumCryptoProviders ppEnumProviders);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EnumContainers([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szProvider, [MarshalAs(UnmanagedType.Interface)] out IVsEnumCryptoProviderContainers ppEnumContainers);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CreateNewKey([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szFileLocation, [MarshalAs(UnmanagedType.BStr)] out string pbstrFilename);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CreateNewKeyNoUI([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szFile, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szPassword);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CreateNewKeyWithName([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szFile, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szPassword, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szSubjectName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ImportKeyFromPFX([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szFile, [MarshalAs(UnmanagedType.BStr)] out string pbstrContainerName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ChangePassword([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szPfxFile, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szOldPassword, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string szNewPassword);
	}
	[ComImport]
	[Guid("97BAE668-2CF2-4ED8-A019-D279E3D74C80")]
	[InterfaceType(1)]
	public interface SVsStrongNameKeys
	{
	}
	[ComImport]
	[Guid("B299765F-1FC2-41A7-BEC1-64721D86E658")]
	[InterfaceType(1)]
	public interface IVsIntellisenseProjectManager
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AdviseIntellisenseProjectEvents([In][MarshalAs(UnmanagedType.Interface)] IVsIntellisenseProjectEventSink pSink, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] out uint pdwCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UnadviseIntellisenseProjectEvents([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] uint dwCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetContainedLanguageFactory([In][MarshalAs(UnmanagedType.BStr)] string bstrLanguage, [MarshalAs(UnmanagedType.Interface)] out IVsContainedLanguageFactory ppContainedLanguageFactory);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CloseIntellisenseProject();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnEditorReady();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CompleteIntellisenseProjectLoad();
	}
	[ComImport]
	[Guid("DFB5C0C2-817E-4A19-8C6D-E387FD68B50B")]
	[InterfaceType(1)]
	public interface IVsIntellisenseProjectEventSink
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnStatusChange([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwStatus);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnReferenceChange([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwChangeType, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string pszAssemblyPath);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnConfigChange();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnCodeFileChange([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string pszOldCodeFile, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string pszNewCodeFile);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("C6CF64F7-8863-4E50-9DF1-892AA83D70D7")]
	public interface IVsItemTypeResolutionService
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetSite([In][MarshalAs(UnmanagedType.IUnknown)] object punkVsItemTypeResolutionSite);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int InitializeReferences([In][MarshalAs(UnmanagedType.IUnknown)] object punkCompilerParameters);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ReferenceAdded([In][MarshalAs(UnmanagedType.BStr)] string pszReference);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ReferenceRemoved([In][MarshalAs(UnmanagedType.BStr)] string pszReference);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ReferenceChanged([In][MarshalAs(UnmanagedType.BStr)] string pszReference);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Reset();
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("6C62F743-D2D3-46B3-BFBC-F04B54EE3F79")]
	public interface IVsIntellisenseProjectHost
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetHostProperty([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwPropID, [MarshalAs(UnmanagedType.Struct)] out object pvar);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetCompilerOptions([MarshalAs(UnmanagedType.BStr)] out string pbstrOptions);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetOutputAssembly([MarshalAs(UnmanagedType.BStr)] out string pbstrOutputAssembly);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CreateFileCodeModel([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string pszFilename, [MarshalAs(UnmanagedType.IUnknown)] out object ppCodeModel);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("3B83B579-4969-4E12-A964-11EC19CC1503")]
	public interface IVsIntellisenseProject
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Init([In][MarshalAs(UnmanagedType.Interface)] IVsIntellisenseProjectHost pHost);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Close();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddFile([In][MarshalAs(UnmanagedType.BStr)] string bstrAbsPath, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RemoveFile([In][MarshalAs(UnmanagedType.BStr)] string bstrAbsPath, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RenameFile([In][MarshalAs(UnmanagedType.BStr)] string bstrAbsPath, [In][MarshalAs(UnmanagedType.BStr)] string bstrNewAbsPath, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsCompilableFile([In][MarshalAs(UnmanagedType.BStr)] string bstrFileName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetContainedLanguageFactory([MarshalAs(UnmanagedType.Interface)] out IVsContainedLanguageFactory ppContainedLanguageFactory);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetCompilerReference([MarshalAs(UnmanagedType.IUnknown)] out object ppCompilerReference);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetFileCodeModel([In][MarshalAs(UnmanagedType.IUnknown)] object pProj, [In][MarshalAs(UnmanagedType.IUnknown)] object pProjectItem, [MarshalAs(UnmanagedType.IUnknown)] out object ppCodeModel);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetProjectCodeModel([In][MarshalAs(UnmanagedType.IUnknown)] object pProj, [MarshalAs(UnmanagedType.IUnknown)] out object ppCodeModel);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RefreshCompilerOptions();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetCodeDomProviderName([MarshalAs(UnmanagedType.BStr)] out string pbstrProvider);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsWebFileRequiredByProject([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pbReq);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddAssemblyReference([In][MarshalAs(UnmanagedType.BStr)] string bstrAbsPath);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RemoveAssemblyReference([In][MarshalAs(UnmanagedType.BStr)] string bstrAbsPath);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddP2PReference([In][MarshalAs(UnmanagedType.IUnknown)] object pUnk);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RemoveP2PReference([In][MarshalAs(UnmanagedType.IUnknown)] object pUnk);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int StopIntellisenseEngine();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int StartIntellisenseEngine();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsSupportedP2PReference([In][MarshalAs(UnmanagedType.IUnknown)] object pUnk);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int WaitForIntellisenseReady();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetExternalErrorReporter([MarshalAs(UnmanagedType.Interface)] out IVsReportExternalErrors ppErrorReporter);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SuspendPostedNotifications();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ResumePostedNotifications();
	}
	public enum INTELLIPROJSTATUS
	{
		INTELLIPROJSTATUS_LOADING = 1,
		INTELLIPROJSTATUS_LOADCOMPLETE,
		INTELLIPROJSTATUS_CLOSE,
		INTELLIPROJSTATUS_REFRESH
	}
	public enum HOSTPROPID
	{
		HOSTPROPID_PROJECTNAME = 1,
		HOSTPROPID_HIERARCHY,
		HOSTPROPID_RELURL,
		HOSTPROPID_INTELLISENSECACHE_FILENAME
	}
	public enum REFERENCECHANGETYPE
	{
		REFERENCE_Added = 1,
		REFERENCE_Removed,
		REFERENCE_Changed
	}
	[ComImport]
	[Guid("5CB6B09C-64F5-4579-8593-7720DAB2EF8D")]
	[InterfaceType(1)]
	public interface SVsIntellisenseProjectManager
	{
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("4371079A-47C3-4B7A-93AE-BFB90FEDB8F0")]
	public interface IVsIntellisenseEngine
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Load();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Unload();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SupportsLoad();
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("D380C630-E46F-40E1-B71D-F3D1682C5AA8")]
	public interface SVsIntellisenseEngine
	{
	}
	[ComImport]
	[Guid("45ABED49-8D6E-47B8-A0D6-C9F2405817C6")]
	[InterfaceType(1)]
	public interface IVsItemTypeResolutionSite
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddReference([In][MarshalAs(UnmanagedType.BStr)] string bstrReferencePath);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int WaitForReferencesReady();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsCodeDirectoryAssembly([In][MarshalAs(UnmanagedType.BStr)] string bstrAssembly, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfIsCodeAssembly);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("5D13ECE7-AA1F-400F-B65D-FA2ABD4F1CD4")]
	public interface SVsIntellisenseProjectHost
	{
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("CD138AD4-A0BF-4681-8FA7-B6D57D55C4DB")]
	public interface IVsDataEnvironment
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Initialize([In][MarshalAs(UnmanagedType.Interface)] Microsoft.VisualStudio.OLE.Interop.IServiceProvider pServiceProvider);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Dispose();
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("53544C4D-C1F3-4FA8-BEA7-EA1A8FECFDD9")]
	public interface IVsRegisterScciProvider
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RegisterSourceControlProvider([In] Guid guidProviderService);
	}
	[ComImport]
	[Guid("49440575-E33C-4169-9735-F3FD5AE54D8D")]
	[InterfaceType(1)]
	public interface IVsSccProvider
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetActive();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetInactive();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AnyItemsUnderSourceControl([ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfResult);
	}
	[ComImport]
	[Guid("53544C4D-724A-46C8-8D01-6D4518CA118C")]
	[InterfaceType(1)]
	public interface IVsSccAddWebProjectFromSourceControl
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsAddWebProjectSupported(out bool pfResult);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int BrowseForServerLocation([MarshalAs(UnmanagedType.BStr)] out string pbstrLocationDescription, [MarshalAs(UnmanagedType.BStr)] out string pbstrLocalPath, [MarshalAs(UnmanagedType.BStr)] out string pbstrDatabasePath, [MarshalAs(UnmanagedType.BStr)] out string pbstrAuxiliarPath, [MarshalAs(UnmanagedType.BStr)] out string pbstrProviderName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddWebProjectFromSourceControl([In][MarshalAs(UnmanagedType.BStr)] string bstrLocalPath, [In][MarshalAs(UnmanagedType.BStr)] string bstrDatabasePath, [In][MarshalAs(UnmanagedType.BStr)] string bstrAuxiliarPath, [In][MarshalAs(UnmanagedType.BStr)] string bstrProviderName, [In][MarshalAs(UnmanagedType.BStr)] string bstrDebuggingPath);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("753D3585-2077-4E60-8EC5-96EE793F3D1A")]
	public interface IVsSccControlNewSolution
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddNewSolutionToSourceControl();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetDisplayStringForAction([MarshalAs(UnmanagedType.BStr)] out string pbstrActionName);
	}
	public enum __VSOPENFROMSCCDLG
	{
		VSOFSD_OPENSOLUTIONORPROJECT = 1,
		VSOFSD_ADDEXISTINGITEM
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("A341396A-1B4A-4164-8E6E-BDDC527C861C")]
	public interface IVsSccOpenFromSourceControl
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OpenSolutionFromSourceControl([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszSolutionStoreUrl);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddProjectFromSourceControl([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszProjectStoreUrl);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddItemFromSourceControl([In][MarshalAs(UnmanagedType.Interface)] IVsProject pProject, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemidLoc, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint cFilesToAdd, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 2)] string[] rgpszFilesToAdd, [In] IntPtr hwndDlgOwner, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSSPECIFICEDITORFLAGS")] uint grfEditorFlags, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid rguidEditorType, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszPhysicalView, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid rguidLogicalView, [Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSADDRESULT")][MarshalAs(UnmanagedType.LPArray)] VSADDRESULT[] pResult);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetNamespaceExtensionInformation([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSOPENFROMSCCDLG")] int vsofsdDlg, [MarshalAs(UnmanagedType.BStr)] out string pbstrNamespaceGUID, [MarshalAs(UnmanagedType.BStr)] out string pbstrTrayDisplayName, [MarshalAs(UnmanagedType.BStr)] out string pbstrProtocolPrefix);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("9C82CA77-A583-4FD1-8C15-0B3995D9AB2F")]
	public interface IVsSccGlyphs
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetCustomGlyphList([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint BaseIndex, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG_PTR")] out uint pdwImageListHandle);
	}
	[ComImport]
	[Guid("53544C4D-DF28-406D-81DA-96DEEB800B64")]
	[InterfaceType(1)]
	public interface IVsSccManagerTooltip
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetGlyphTipText([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy phierHierarchy, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemidNode, [MarshalAs(UnmanagedType.BStr)] out string pbstrTooltipText);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("53544C4D-01F8-11D0-8E5E-00A0C911005A")]
	public interface IVsSccEnlistmentPathTranslation
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int TranslateProjectPathToEnlistmentPath([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszProjectPath, [MarshalAs(UnmanagedType.BStr)] out string pbstrEnlistmentPath, [MarshalAs(UnmanagedType.BStr)] out string pbstrEnlistmentPathUNC);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int TranslateEnlistmentPathToProjectPath([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszEnlistmentPath, [MarshalAs(UnmanagedType.BStr)] out string pbstrProjectPath);
	}
	public enum VSSCCENLISTMENTCHOICE
	{
		VSSCC_EC_NEVER,
		VSSCC_EC_OPTIONAL,
		VSSCC_EC_COMPULSORY
	}
	[ComImport]
	[Guid("53544C4D-06F8-11D0-8E5E-00A0C911005A")]
	[InterfaceType(1)]
	public interface IVsSccProjectEnlistmentChoice
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetEnlistmentChoice([Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSSCCENLISTMENTCHOICE")][MarshalAs(UnmanagedType.LPArray)] VSSCCENLISTMENTCHOICE[] pvscecEnlistmentChoice);
	}
	public enum __VSSCCENLISTMENTFACTORYOPTIONS
	{
		VSSCC_EFO_CANBROWSEENLISTMENTPATH = 1,
		VSSCC_EFO_CANEDITENLISTMENTPATH = 2,
		VSSCC_EFO_CANBROWSEDEBUGGINGPATH = 4,
		VSSCC_EFO_CANEDITDEBUGGINGPATH = 8
	}
	[ComImport]
	[Guid("53544C4D-00F8-11D0-8E5E-00A0C911005A")]
	[InterfaceType(1)]
	public interface IVsSccProjectEnlistmentFactory
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetDefaultEnlistment([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszProjectPath, [MarshalAs(UnmanagedType.BStr)] out string pbstrDefaultEnlistment, [MarshalAs(UnmanagedType.BStr)] out string pbstrDefaultEnlistmentUNC);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetEnlistmentFactoryOptions([ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSSCCENLISTMENTFACTORYOPTIONS")] out uint pvscefoOptions);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ValidateEnlistmentEdit([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fQuick, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszProjectPath, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszChosenEnlistment, [MarshalAs(UnmanagedType.BStr)] out string pbstrChosenEnlistmentUNC, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfValidEnlistment);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int BrowseEnlistment([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszProjectPath, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszInitialEnlistment, [MarshalAs(UnmanagedType.BStr)] out string pbstrChosenEnlistment, [MarshalAs(UnmanagedType.BStr)] out string pbstrChosenEnlistmentUNC);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnBeforeEnlistmentCreate([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszProjectPath, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszEnlistment, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszEnlistmentUNC);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnAfterEnlistmentCreate([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszProjectPath, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszEnlistment, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszEnlistmentUNC);
	}
	public enum VSSCCPROVIDERBINDING
	{
		VSSCC_PB_STANDARD,
		VSSCC_PB_CUSTOM_DISABLED,
		VSSCC_PB_CUSTOM,
		VSSCC_PB_STANDARD_DISABLED
	}
	public enum __VSSCCPROVIDERBINDINGOPTIONS
	{
		VSSCC_PBO_CANBROWSESERVERPATH = 1,
		VSSCC_PBO_CANEDITSERVERPATH = 2,
		VSSCC_PBO_CANDISPLAYSERVERPATH = 4
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("53544C4D-02F8-11D0-8E5E-00A0C911005A")]
	public interface IVsSccProjectProviderBinding
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetProviderBinding([Out][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSSCCPROVIDERBINDING")][MarshalAs(UnmanagedType.LPArray)] VSSCCPROVIDERBINDING[] pvscpbBinding);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetProviderService(out Guid pguidService);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetProviderSession([MarshalAs(UnmanagedType.IUnknown)] out object punkSession);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int TranslateEnlistmentPath([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszPath, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfAlternateIsDisplay, [MarshalAs(UnmanagedType.BStr)] out string pbstrAlternatePath);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetProviderBindingOptions([ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSSCCPROVIDERBINDINGOPTIONS")] out uint pvscpboOptions);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ValidateServerPathEdit([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fQuick, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszServerPath, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] out int pfValidServer);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int BrowseServerPath([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string lpszServerPath, [MarshalAs(UnmanagedType.BStr)] out string pbstrNewServerPath);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("53544C4D-0ADC-4F55-BD82-7E8383C02CFB")]
	public interface IVsSccVirtualFolders
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetVirtualFolders([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid, [Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.CALPOLESTR")][MarshalAs(UnmanagedType.LPArray)] CALPOLESTR[] pCaStringsOut);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsItemChildOfVirtualFolder([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszItemName, out bool pfResult);
	}
	public enum SccToolsOptionsEnum
	{
		ksctoAllowReadOnlyFilesNotUnderSccToBeEdited = 1,
		ksctoLast = 1,
		ksctoBad = 2
	}
	public enum __SccToolsOptionsEnum
	{
		ksctoAllowReadOnlyFilesNotUnderSccToBeEdited = 1,
		ksctoLast = 1,
		ksctoBad = 2
	}
	[ComImport]
	[Guid("53544C4D-304B-4D82-AD93-074816C1A0E5")]
	[InterfaceType(1)]
	public interface IVsSccToolsOptions
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetSccToolsOption([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.SccToolsOptionsEnum")] SccToolsOptionsEnum sctoOptionToBeSet, [In][MarshalAs(UnmanagedType.Struct)] object varValueToBeSet);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetSccToolsOption([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.SccToolsOptionsEnum")] SccToolsOptionsEnum sctoOptionToBeSet, [MarshalAs(UnmanagedType.Struct)] out object pvarValueToGet);
	}
	[ComImport]
	[Guid("53544C4D-104B-4D82-AD93-074816C1A0E5")]
	[InterfaceType(1)]
	public interface SVsSccToolsOptions
	{
	}
	[ComImport]
	[Guid("C736666C-6970-4AE7-9B1F-5C0407A30556")]
	[InterfaceType(1)]
	public interface IVsWebServiceProvider
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int WebServices([MarshalAs(UnmanagedType.Interface)] out IEnumWebServices ppIEnumWebServices);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetWebService([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszUrl, [MarshalAs(UnmanagedType.Interface)] out IVsWebService ppIVsWebService);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int StartServer();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AdviseWebServiceProviderEvents([In][MarshalAs(UnmanagedType.Interface)] IVsWebServiceProviderEvents pEvents, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] out uint pdwCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UnadviseWebServiceProviderEvents([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] uint dwCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EnsureServerRunning([MarshalAs(UnmanagedType.BStr)] out string pbstrUrl);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ApplicationUrl([MarshalAs(UnmanagedType.BStr)] out string pbstrUrl);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("4DB4E7D3-5550-41AE-A612-3D28CD0C52A8")]
	public interface IEnumWebServices
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Next([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt, [Out][MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.Interface, SizeParamIndex = 0)] IVsWebService[] rgelt, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] out uint pceltFetched);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Skip([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.ULONG")] uint celt);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Reset();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Clone([MarshalAs(UnmanagedType.Interface)] out IEnumWebServices ppEnum);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("D02603F6-BDB0-410C-9BA8-9E34E5FF4BEC")]
	public interface IVsWebService
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int Url([MarshalAs(UnmanagedType.BStr)] out string bstrUrl);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AppRelativeUrl([MarshalAs(UnmanagedType.BStr)] out string bstrAppUrl);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetProvider([MarshalAs(UnmanagedType.Interface)] out IVsWebServiceProvider ppIVsWebServiceProvider);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AdviseWebServiceEvents([In][MarshalAs(UnmanagedType.Interface)] IVsWebServiceEvents pEvents, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] out uint pdwCookie);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int UnadviseWebServiceEvents([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSCOOKIE")] uint dwCookie);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("8170CB5A-D602-4886-A990-8260A5928133")]
	public interface IVsWebServiceProviderEvents
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnAdded([In][MarshalAs(UnmanagedType.Interface)] IVsWebService pIVsWebReference);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnRemoved([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszUrl);
	}
	[ComImport]
	[Guid("F20AB4A1-4BA3-4842-AC78-2550669F751A")]
	[InterfaceType(1)]
	public interface IVsWebServiceEvents
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnRemoved([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszOldURL);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnRenamed([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszOldURL, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCOLESTR")][MarshalAs(UnmanagedType.LPWStr)] string pszNewURL);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int OnChanged([In][MarshalAs(UnmanagedType.Interface)] IVsWebService pIVsWebReference);
	}
	[ComImport]
	[Guid("CCCECEE2-D225-4294-858E-2B8C3F7D84EA")]
	[InterfaceType(1)]
	public interface IWebApplicationCtxSvc
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetItemContext([In][MarshalAs(UnmanagedType.Interface)] IVsHierarchy pHier, [In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid, [MarshalAs(UnmanagedType.Interface)] out Microsoft.VisualStudio.OLE.Interop.IServiceProvider ppServiceProvider);
	}
	[ComImport]
	[Guid("05B4B4B7-6A9D-4A70-BDB1-04CBB26C9248")]
	[InterfaceType(1)]
	public interface IWebFileCtxService
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddFileToIntellisense([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string pszFilePath, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] out uint pItemid);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EnsureFileOpened([In][ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] uint itemid, [MarshalAs(UnmanagedType.Interface)] out IVsWindowFrame ppFrame);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RemoveFileFromIntellisense([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string pszFilePath);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetWebRootPath([MarshalAs(UnmanagedType.BStr)] out string pbstrWebRootPath);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetIntellisenseProjectName([MarshalAs(UnmanagedType.BStr)] out string pbstrProjectName);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int AddDependentAssemblyFile([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string pszFilePath);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int RemoveDependentAssemblyFile([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string pszFilePath);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ConvertToAppRelPath([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string pszFilePath, [MarshalAs(UnmanagedType.BStr)] out string pbstrAppRelPath);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int CBMCallbackActive();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int WaitForIntellisenseReady();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsDocumentInProject([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPCWSTR")][MarshalAs(UnmanagedType.LPWStr)] string pszFilePath, [ComAliasName("Microsoft.VisualStudio.Shell.Interop.VSITEMID")] out uint pItemid);
	}
	[ComImport]
	[Guid("95FC88C3-9FCB-11CF-A405-00AA00C00940")]
	[InterfaceType(1)]
	public interface IBuilderWizardManager
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int DoesBuilderExist([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid rguidBuilder);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int MapObjectToBuilderCLSID([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFCLSID")] ref Guid rclsidObject, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwPromptOpt, [In] IntPtr hwndPromptOwner, out Guid pclsidBuilder);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int MapBuilderCATIDToCLSID([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid rguidBuilder, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint dwPromptOpt, [In] IntPtr hwndPromptOwner, out Guid pclsidBuilder);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetBuilder([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid rguidBuilder, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] uint grfGetOpt, [In] IntPtr hwndPromptOwner, [MarshalAs(UnmanagedType.IDispatch)] out object ppdispApp, out IntPtr pwndBuilderOwner, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFIID")] ref Guid riidBuilder, [MarshalAs(UnmanagedType.IUnknown)] out object ppunkBuilder);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int EnableModeless([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.BOOL")] int fEnable);
	}
	[ComImport]
	[Guid("33C0C1D8-33CF-11D3-BFF2-00C04F990235")]
	[InterfaceType(1)]
	public interface IProvidePropertyBuilder
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int MapPropertyToBuilder([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int dispid, [In][Out][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] ref int pdwCtlBldType, [In][Out][MarshalAs(UnmanagedType.BStr)] ref string pbstrGuidBldr, out bool pfRetVal);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ExecuteBuilder([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG")] int dispid, [In][MarshalAs(UnmanagedType.BStr)] string bstrGuidBldr, [In][MarshalAs(UnmanagedType.IDispatch)] object pdispApp, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG_PTR")] int hwndBldrOwner, [In][Out][MarshalAs(UnmanagedType.Struct)] ref object pvarValue, out bool pfRetVal);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("33C0C1DA-33CF-11D3-BFF2-00C04F990235")]
	public interface IPerPropertyBrowsing2
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int MapPropertyToBuilder([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DISPID")] int dispid, out Guid pguidBuilder, [ComAliasName("Microsoft.VisualStudio.OLE.Interop.DWORD")] out uint pdwType);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int ExecuteBuilder([In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.DISPID")] int dispid, [In][ComAliasName("Microsoft.VisualStudio.OLE.Interop.REFGUID")] ref Guid rguidBuilder, [In][MarshalAs(UnmanagedType.IDispatch)] object pdispApp, [In] IntPtr hwndBuilderOwner, [In][Out][MarshalAs(UnmanagedType.Struct)] ref object pvarValue);
	}
	[ComImport]
	[Guid("33C0C1DB-33CF-11D3-BFF2-00C04F990235")]
	[InterfaceType(1)]
	public interface IPropertyPageUndoString
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetUndoString([ComAliasName("Microsoft.VisualStudio.OLE.Interop.LPOLESTR")][MarshalAs(UnmanagedType.LPWStr)] out string ppszUndo);
	}
	[ComImport]
	[Guid("33C0C1DC-33CF-11D3-BFF2-00C04F990235")]
	[InterfaceType(1)]
	public interface IProvideRuntimeHTML
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetRuntimeHTML([MarshalAs(UnmanagedType.BStr)] out string pstrRuntimeHTML);
	}
	[ComImport]
	[InterfaceType(1)]
	[Guid("33C0C1DD-33CF-11D3-BFF2-00C04F990235")]
	public interface IProvideAltHTML
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int GetAltHTML([MarshalAs(UnmanagedType.BStr)] out string pstrAltHTML);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int IsAltHTMLEditable(out sbyte pfIsEditable);
	}
	public enum BLDPROMPTOPT
	{
		BLDPROMPTOPT_PROMPTIFMULTIPLE,
		BLDPROMPTOPT_PROMPTALWAYS,
		BLDPROMPTOPT_PROMPTNEVER
	}
	[Flags]
	public enum BLDGETFLAGS
	{
		BLDGETOPT_FAUTOMAPGUID = 1,
		BLDGETOPT_FAUTOMAPENABLEPROMPT = 2,
		BLDGETOPT_FAUTOMAPPROMPTALWAYS = 4,
		BLDGETOPT_FOBJECTBUILDER = 8,
		BLDGETOPT_FNOINTRINSICS = int.MinValue
	}
	public enum CTLBLDTYPE
	{
		CTLBLDTYPE_FSTDPROPBUILDER = 1,
		CTLBLDTYPE_FINTERNALBUILDER = 2,
		CTLBLDTYPE_FEDITSOBJDIRECTLY = 4
	}
	[ComImport]
	[Guid("07F86393-273C-11D7-8BF6-00B0D03DAA06")]
	[InterfaceType(1)]
	public interface IDirListSite
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		int SetSite([In][MarshalAs(UnmanagedType.IUnknown)] object __MIDL_0011);
	}
	[ComImport]
	[Guid("07F86394-273C-11D7-8BF6-00B0D03DAA06")]
	[TypeLibType(4160)]
	public interface IDirListEvents
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		int OnChange();
	}
	[ComImport]
	[TypeLibType(4288)]
	[Guid("07F86395-273C-11D7-8BF6-00B0D03DAA06")]
	public interface IDirList
	{
		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		int get_HWND([ComAliasName("Microsoft.VisualStudio.OLE.Interop.LONG_PTR")] out int phwnd);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		int get_Description([MarshalAs(UnmanagedType.BStr)] out string pbstrDescription);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		int put_Description([In][MarshalAs(UnmanagedType.BStr)] string bstrDescription);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		int get_Title([MarshalAs(UnmanagedType.BStr)] out string pbstrTitle);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		int put_Title([In][MarshalAs(UnmanagedType.BStr)] string bstrTitle);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		int put_ShowTitle([In] bool bShow);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		int put_ShowCheck([In] bool bShow);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		int get_Count(out int nItems);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		int index([In] int nItem, [MarshalAs(UnmanagedType.BStr)] out string pbstrItem);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		int Add([In][MarshalAs(UnmanagedType.BStr)] string bstrItem);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		int Reset();
	}
	[ComImport]
	[Guid("07F86396-273C-11D7-8BF6-00B0D03DAA06")]
	[TypeLibType(4288)]
	public interface IDirAutoCompleteList
	{
	}
}
