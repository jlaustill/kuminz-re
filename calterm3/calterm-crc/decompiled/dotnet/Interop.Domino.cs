using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: Guid("29131520-2eed-1069-bf5d-00dd011186b7")]
[assembly: ImportedFromTypeLib("Domino")]
[assembly: TypeLibVersion(1, 2)]
[assembly: AssemblyVersion("1.2.0.0")]
namespace Domino;

[ComImport]
[ClassInterface(0)]
[TypeLibType(2)]
[Guid("29131521-2EED-1069-BF5D-00DD011186B7")]
public class NotesACLClass : IACL, NotesACL
{
	[ComAliasName("Domino.ACLLEVEL")]
	[DispId(1610743808)]
	public virtual extern ACLLEVEL InternetLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: ComAliasName("Domino.ACLLEVEL")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: ComAliasName("Domino.ACLLEVEL")]
		set;
	}

	[DispId(1610743810)]
	public virtual extern NotesDatabase Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743811)]
	public virtual extern object Roles
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743812)]
	public virtual extern bool UniformAccess
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		set;
	}

	[DispId(1610743823)]
	public virtual extern string AdministrationServer
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743825)]
	public virtual extern bool IsAdminNames
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		[param: In]
		set;
	}

	[DispId(1610743827)]
	public virtual extern bool IsAdminReaderAuthor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		[param: In]
		set;
	}

	[DispId(1610743829)]
	public virtual extern bool IsExtendedAccess
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743814)]
	public virtual extern void AddRole([In][MarshalAs(UnmanagedType.BStr)] string pRole);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesACLEntry CreateACLEntry([In][MarshalAs(UnmanagedType.BStr)] string pName, [In][ComAliasName("Domino.ACLLEVEL")] ACLLEVEL lLevel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	public virtual extern void DeleteRole([In][MarshalAs(UnmanagedType.BStr)] string pRole);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743817)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesACLEntry GetEntry([In][MarshalAs(UnmanagedType.BStr)] string pEname);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743818)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesACLEntry GetFirstEntry();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743819)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesACLEntry GetNextEntry([In][MarshalAs(UnmanagedType.Interface)] NotesACLEntry pIEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743820)]
	public virtual extern void RenameRole([In][MarshalAs(UnmanagedType.BStr)] string pOldname, [In][MarshalAs(UnmanagedType.BStr)] string pNewname);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	public virtual extern void RemoveACLEntry([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743822)]
	public virtual extern void Save();
}
[ComImport]
[CoClass(typeof(NotesACLClass))]
[Guid("29131560-2EED-1069-BF5D-00DD011186B7")]
public interface NotesACL : IACL
{
}
[ComImport]
[Guid("29131560-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(4160)]
public interface IACL
{
	[DispId(1610743808)]
	[ComAliasName("Domino.ACLLEVEL")]
	ACLLEVEL InternetLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: ComAliasName("Domino.ACLLEVEL")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: ComAliasName("Domino.ACLLEVEL")]
		set;
	}

	[DispId(1610743810)]
	NotesDatabase Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743811)]
	object Roles
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743812)]
	bool UniformAccess
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743814)]
	void AddRole([In][MarshalAs(UnmanagedType.BStr)] string pRole);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesACLEntry CreateACLEntry([In][MarshalAs(UnmanagedType.BStr)] string pName, [In][ComAliasName("Domino.ACLLEVEL")] ACLLEVEL lLevel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	void DeleteRole([In][MarshalAs(UnmanagedType.BStr)] string pRole);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743817)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesACLEntry GetEntry([In][MarshalAs(UnmanagedType.BStr)] string pEname);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743818)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesACLEntry GetFirstEntry();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743819)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesACLEntry GetNextEntry([In][MarshalAs(UnmanagedType.Interface)] NotesACLEntry pIEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743820)]
	void RenameRole([In][MarshalAs(UnmanagedType.BStr)] string pOldname, [In][MarshalAs(UnmanagedType.BStr)] string pNewname);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	void RemoveACLEntry([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743822)]
	void Save();

	[DispId(1610743823)]
	string AdministrationServer
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743825)]
	bool IsAdminNames
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		[param: In]
		set;
	}

	[DispId(1610743827)]
	bool IsAdminReaderAuthor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		[param: In]
		set;
	}

	[DispId(1610743829)]
	bool IsExtendedAccess
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		[param: In]
		set;
	}
}
public enum ACLLEVEL
{
	ACLLEVEL_NOACCESS,
	ACLLEVEL_DEPOSITOR,
	ACLLEVEL_READER,
	ACLLEVEL_AUTHOR,
	ACLLEVEL_EDITOR,
	ACLLEVEL_DESIGNER,
	ACLLEVEL_MANAGER
}
public enum _ACLLEVEL
{
	ACLLEVEL_NOACCESS,
	ACLLEVEL_DEPOSITOR,
	ACLLEVEL_READER,
	ACLLEVEL_AUTHOR,
	ACLLEVEL_EDITOR,
	ACLLEVEL_DESIGNER,
	ACLLEVEL_MANAGER
}
[ComImport]
[DefaultMember("FilePath")]
[TypeLibType(4160)]
[Guid("29131563-2EED-1069-BF5D-00DD011186B7")]
public interface IDatabase
{
	[DispId(1610743808)]
	NotesACL ACL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743809)]
	NotesDocumentCollection AllDocuments
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743810)]
	object Agents
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743811)]
	string Categories
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743813)]
	object Created
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743814)]
	int CurrentAccessLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
	}

	[DispId(1610743815)]
	bool DelayUpdates
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[param: In]
		set;
	}

	[DispId(1610743817)]
	string DesignTemplateName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743818)]
	string FileName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(0)]
	string FilePath
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743820)]
	bool FolderReferencesEnabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[param: In]
		set;
	}

	[DispId(1610743822)]
	object Forms
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743823)]
	string HttpURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743824)]
	bool IsDirectoryCatalog
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		get;
	}

	[DispId(1610743825)]
	bool IsFTIndexed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		get;
	}

	[DispId(1610743826)]
	bool IsMultiDbSearch
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		get;
	}

	[DispId(1610743827)]
	bool IsOpen
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		get;
	}

	[DispId(1610743828)]
	bool IsPublicAddressBook
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		get;
	}

	[DispId(1610743829)]
	bool IsPrivateAddressBook
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		get;
	}

	[DispId(1610743830)]
	object LastFTIndexed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743831)]
	object LastModified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743831)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743832)]
	object Managers
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743833)]
	double MaxSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743833)]
		get;
	}

	[DispId(1610743834)]
	string NotesURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743834)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743835)]
	NotesSession Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743835)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743836)]
	double PercentUsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743836)]
		get;
	}

	[DispId(1610743837)]
	string ReplicaID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743837)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743838)]
	NotesReplication ReplicationInfo
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743838)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743839)]
	string Server
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743839)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743840)]
	double Size
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743840)]
		get;
	}

	[DispId(1610743841)]
	int SizeQuota
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743841)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743841)]
		[param: In]
		set;
	}

	[DispId(1610743843)]
	string TemplateName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743843)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743844)]
	string Title
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743844)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743844)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743846)]
	NotesDocumentCollection UnprocessedDocuments
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743846)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743847)]
	object Views
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743847)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743848)]
	int Compact();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743849)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDatabase CreateCopy([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pFile, [In] int lMaxsize = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743850)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument CreateDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743851)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDatabase CreateFromTemplate([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pFile, [In] bool bInherit, [In] int lMaxsize = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743852)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesOutline CreateOutline([In][MarshalAs(UnmanagedType.BStr)] string pName, [In] bool bGenDefault = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743853)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDatabase CreateReplica([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pFile);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743854)]
	void EnableFolder([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743855)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument FTDomainSearch([In][MarshalAs(UnmanagedType.BStr)] string pQuery, [In] int lMax, [In][ComAliasName("Domino.FT_TYPES")] FT_TYPES lSortopt = FT_TYPES.FT_SCORES, [In][ComAliasName("Domino.FT_TYPES")] FT_TYPES lOtheropt = (FT_TYPES)0, [In] int lStart = 0, [In] int lCount = 0, [In][MarshalAs(UnmanagedType.BStr)] string pEntryForm = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743856)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocumentCollection FTSearch([In][MarshalAs(UnmanagedType.BStr)] string pQuery, [In] int lMax, [In][ComAliasName("Domino.FT_TYPES")] FT_TYPES lSortopt = FT_TYPES.FT_SCORES, [In][ComAliasName("Domino.FT_TYPES")] FT_TYPES lOtheropt = (FT_TYPES)0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743857)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesAgent GetAgent([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743858)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument GetDocumentByID([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743859)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument GetDocumentByUNID([In][MarshalAs(UnmanagedType.BStr)] string pUnid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743860)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument GetDocumentByURL([In][MarshalAs(UnmanagedType.BStr)] string pURL, [In] int lReload = 0, [In] bool bUrllist = false, [In][MarshalAs(UnmanagedType.BStr)] string pCharset = "", [In][MarshalAs(UnmanagedType.BStr)] string pWebuser = "", [In][MarshalAs(UnmanagedType.BStr)] string pWebpasswd = "", [In][MarshalAs(UnmanagedType.BStr)] string pProxyuser = "", [In][MarshalAs(UnmanagedType.BStr)] string pProxypasswd = "", [In] bool bNowait = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743861)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesForm GetForm([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743862)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesOutline GetOutline([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743863)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument GetProfileDocument([In][MarshalAs(UnmanagedType.BStr)] string pProfile, [In][MarshalAs(UnmanagedType.BStr)] string pProfileuser = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743864)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocumentCollection GetProfileDocCollection([In][MarshalAs(UnmanagedType.BStr)] string pProfileName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743865)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetURLHeaderInfo([In][MarshalAs(UnmanagedType.BStr)] string pURL = "", [In][MarshalAs(UnmanagedType.BStr)] string pHeader = "", [In][MarshalAs(UnmanagedType.BStr)] string pWebuser = "", [In][MarshalAs(UnmanagedType.BStr)] string pWebpasswd = "", [In][MarshalAs(UnmanagedType.BStr)] string pProxyuser = "", [In][MarshalAs(UnmanagedType.BStr)] string pProxypasswd = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743866)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesView GetView([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743867)]
	void GrantAccess([In][MarshalAs(UnmanagedType.BStr)] string pName, [In][ComAliasName("Domino.ACLLEVEL")] ACLLEVEL lLevel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743868)]
	void Open();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743869)]
	[return: ComAliasName("Domino.ACLLEVEL")]
	ACLLEVEL QueryAccess([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743870)]
	void Remove();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743871)]
	bool Replicate([In][MarshalAs(UnmanagedType.BStr)] string pServer);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743872)]
	void RevokeAccess([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743873)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocumentCollection Search([In][MarshalAs(UnmanagedType.BStr)] string pFormula, [In][MarshalAs(UnmanagedType.Interface)] NotesDateTime pIDt, [In] int lMax);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743874)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocumentCollection UnprocessedFTSearch([In][MarshalAs(UnmanagedType.BStr)] string pQuery, [In] int lMax, [In][ComAliasName("Domino.FT_TYPES")] FT_TYPES lSortopt = FT_TYPES.FT_SCORES, [In][ComAliasName("Domino.FT_TYPES")] FT_TYPES lOtheropt = (FT_TYPES)0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743875)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocumentCollection UnprocessedSearch([In][MarshalAs(UnmanagedType.BStr)] string pFormula, [In][MarshalAs(UnmanagedType.Interface)] NotesDateTime pDt, [In] int lMax);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743876)]
	void UpdateFTIndex([In] bool bCreate);

	[DispId(1610743877)]
	object ACLActivityLog
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743877)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743878)]
	[ComAliasName("Domino.FTINDEX_FREQUENCY")]
	FTINDEX_FREQUENCY FTIndexFrequency
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743878)]
		[return: ComAliasName("Domino.FTINDEX_FREQUENCY")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743878)]
		[param: In]
		[param: ComAliasName("Domino.FTINDEX_FREQUENCY")]
		set;
	}

	[DispId(1610743880)]
	bool IsCurrentAccessPublicReader
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743880)]
		get;
	}

	[DispId(1610743881)]
	bool IsCurrentAccessPublicWriter
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743881)]
		get;
	}

	[DispId(1610743882)]
	bool IsInMultiDbIndexing
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743882)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743882)]
		[param: In]
		set;
	}

	[DispId(1610743884)]
	bool IsLink
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743884)]
		get;
	}

	[DispId(1610743885)]
	[ComAliasName("Domino.DATABASE_TYPES")]
	DATABASE_TYPES type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743885)]
		[return: ComAliasName("Domino.DATABASE_TYPES")]
		get;
	}

	[DispId(1610743886)]
	bool IsDocumentLockingEnabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743886)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743886)]
		[param: In]
		set;
	}

	[DispId(1610743888)]
	bool IsDesignLockingEnabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743888)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743888)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743890)]
	int CompactWithOptions([In][MarshalAs(UnmanagedType.Struct)] object cmpcFlags, [In][MarshalAs(UnmanagedType.BStr)] string pSpacethreshhold = "", [In][ComAliasName("Domino.COMPACT_OPTIONS")] COMPACT_OPTIONS unused = COMPACT_OPTIONS.CMPC_IGNORE_COPYSTYLE_ERRORS);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743891)]
	void CreateFTIndex([In][ComAliasName("Domino.FTINDEX_OPTIONS")] FTINDEX_OPTIONS ftiFlags, [In] bool bRecreate);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743892)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocumentCollection FTSearchRange([In][MarshalAs(UnmanagedType.BStr)] string pQuery, [In] int lMax, [In][ComAliasName("Domino.FT_TYPES")] FT_TYPES lSortopt = FT_TYPES.FT_SCORES, [In][ComAliasName("Domino.FT_TYPES")] FT_TYPES lOtheropt = (FT_TYPES)0, [In] int start = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743893)]
	bool OpenByReplicaID([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pReplicaID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743894)]
	bool OpenIfModified([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pDbfile, [In][MarshalAs(UnmanagedType.Interface)] NotesDateTime pITimeModifiedSince);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743895)]
	bool OpenWithFailover([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pDbfile);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743896)]
	[return: ComAliasName("Domino.ACCESS_PRIVILEGES")]
	ACCESS_PRIVILEGES QueryAccessPrivileges([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743897)]
	void RemoveFTIndex();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743898)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocumentCollection UnprocessedFTSearchRange([In][MarshalAs(UnmanagedType.BStr)] string pQuery, [In] int lMax, [In][ComAliasName("Domino.FT_TYPES")] FT_TYPES lSortopt = FT_TYPES.FT_SCORES, [In][ComAliasName("Domino.FT_TYPES")] FT_TYPES lOtheropt = (FT_TYPES)0, [In] int start = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743899)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesView CreateView([In][MarshalAs(UnmanagedType.BStr)] string Title = "", [In][MarshalAs(UnmanagedType.BStr)] string Formula = "", [In][MarshalAs(UnmanagedType.Interface)] NotesView templateView = null, [In] bool noRefresh = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743900)]
	void Fixup([In][ComAliasName("Domino.DBFIXUP_TYPES")] DBFIXUP_TYPES opts = DBFIXUP_TYPES.FIXUP_DEFAULT);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743901)]
	void MarkForDelete();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743902)]
	bool GetOption([In][ComAliasName("Domino.DB_OPTIONS")] DB_OPTIONS bit);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743903)]
	void SetOption([In][ComAliasName("Domino.DB_OPTIONS")] DB_OPTIONS bit, [In] bool bValue);

	[DispId(1610743904)]
	bool IsInService
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743904)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743904)]
		[param: In]
		set;
	}

	[DispId(1610743905)]
	bool IsPendingDelete
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743905)]
		get;
	}

	[DispId(1610743906)]
	bool IsConfigurationDirectory
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743906)]
		get;
	}

	[DispId(1610743907)]
	bool IsClusterReplication
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743907)]
		get;
	}

	[DispId(1610743908)]
	bool ListInDbCatalog
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743908)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743908)]
		[param: In]
		set;
	}

	[DispId(1610743909)]
	NotesDateTime LastFixup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743909)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743910)]
	double LimitRevisions
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743910)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743910)]
		[param: In]
		set;
	}

	[DispId(1610743911)]
	double LimitUpdatedBy
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743911)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743911)]
		[param: In]
		set;
	}

	[DispId(1610743912)]
	int FileFormat
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743912)]
		get;
	}

	[DispId(1610743913)]
	int UndeleteExpireTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743913)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743913)]
		[param: In]
		set;
	}

	[DispId(1610743914)]
	int SizeWarning
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743914)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743914)]
		[param: In]
		set;
	}

	[DispId(1610743919)]
	bool InService
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743919)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743921)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesNoteCollection CreateNoteCollection([In] bool bSelectAll);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743922)]
	void Sign([In][ComAliasName("Domino.DBSIGN_TYPES")] DBSIGN_TYPES lDocumentType = DBSIGN_TYPES.DBSIGN_DOC_ALL, [In] bool bExistingSigsOnly = false, [In][MarshalAs(UnmanagedType.BStr)] string pNameStr = "", [In] bool bNameStrIsNoteID = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743923)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object QueryAccessRoles([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743924)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocumentCollection GetModifiedDocuments([In][MarshalAs(UnmanagedType.Interface)] NotesDateTime pDTSince = null, [In][ComAliasName("Domino.DBMOD_TYPES")] DBMOD_TYPES noteClass = DBMOD_TYPES.DBMOD_DOC_DATA);
}
[ComImport]
[TypeLibType(4160)]
[Guid("29131568-2EED-1069-BF5D-00DD011186B7")]
public interface IDocumentCollection
{
	[DispId(1610743808)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
	}

	[DispId(1610743809)]
	bool IsSorted
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		get;
	}

	[DispId(1610743810)]
	NotesDatabase Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743811)]
	string Query
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743812)]
	void AddDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pIDoc, [In] bool bReserved = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743813)]
	void DeleteDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pIDoc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743814)]
	void FTSearch([In][MarshalAs(UnmanagedType.BStr)] string pQuery, [In] int lMaxDocs = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument GetDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pIIndoc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument GetFirstDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743817)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument GetLastDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743818)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument GetNextDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743819)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument GetPrevDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743820)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument GetNthDocument([In] int lN);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	void PutAllInFolder([In][MarshalAs(UnmanagedType.BStr)] string pFolderName, [In] bool bCreateonfail = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743822)]
	void RemoveAll([In] bool bForce);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743823)]
	void RemoveAllFromFolder([In][MarshalAs(UnmanagedType.BStr)] string pFolderName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	void StampAll([In][MarshalAs(UnmanagedType.BStr)] string pItemName, [In][MarshalAs(UnmanagedType.Struct)] object Value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	void UpdateAll();

	[DispId(1610743826)]
	NotesDateTime UntilTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}
}
[ComImport]
[DefaultMember("UniversalID")]
[Guid("29131567-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(4160)]
public interface IDocument
{
	[DispId(1610743808)]
	object Authors
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743809)]
	object ColumnValues
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743810)]
	object Created
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743811)]
	object EmbeddedObjects
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743812)]
	object EncryptionKeys
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1610743814)]
	bool EncryptOnSend
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		set;
	}

	[DispId(1610743816)]
	object FolderReferences
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743817)]
	int FTSearchScore
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		get;
	}

	[DispId(1610743818)]
	bool HasEmbedded
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
	}

	[DispId(1610743819)]
	string HttpURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743820)]
	bool IsDeleted
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		get;
	}

	[DispId(1610743821)]
	bool IsNewNote
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		get;
	}

	[DispId(1610743822)]
	bool IsProfile
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		get;
	}

	[DispId(1610743823)]
	bool IsResponse
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		get;
	}

	[DispId(1610743824)]
	bool IsSigned
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		get;
	}

	[DispId(1610743825)]
	bool IsUIDocOpen
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		get;
	}

	[DispId(1610743826)]
	bool IsValid
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		get;
	}

	[DispId(1610743827)]
	object Items
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743828)]
	string Key
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743829)]
	object LastAccessed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743830)]
	object LastModified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743831)]
	string NameOfProfile
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743831)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743832)]
	string NoteID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743833)]
	string NotesURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743833)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743834)]
	NotesDatabase ParentDatabase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743834)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743835)]
	string ParentDocumentUNID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743835)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743836)]
	NotesView ParentView
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743836)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743837)]
	NotesDocumentCollection Responses
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743837)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743838)]
	bool SaveMessageOnSend
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743838)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743838)]
		[param: In]
		set;
	}

	[DispId(1610743840)]
	bool SentByAgent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743840)]
		get;
	}

	[DispId(1610743841)]
	string Signer
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743841)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743842)]
	bool SignOnSend
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743842)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743842)]
		[param: In]
		set;
	}

	[DispId(1610743844)]
	int Size
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743844)]
		get;
	}

	[DispId(0)]
	string UniversalID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743847)]
	string Verifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743847)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743848)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesItem AppendItemValue([In][MarshalAs(UnmanagedType.BStr)] string pName, [In][MarshalAs(UnmanagedType.Struct)] object Value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743849)]
	bool ComputeWithForm([In] bool bDodatatypes, [In] bool bRaiseerror);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743850)]
	void CopyAllItems([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pIDoc, [In] bool bReplace = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743851)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesItem CopyItem([In][MarshalAs(UnmanagedType.Interface)] NotesItem pIItem, [In][MarshalAs(UnmanagedType.BStr)] string pNewname);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743852)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument CopyToDatabase([In][MarshalAs(UnmanagedType.Interface)] NotesDatabase pIDb);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743853)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument CreateReplyMessage([In] bool bToall);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743854)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesRichTextItem CreateRichTextItem([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743855)]
	void Encrypt();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743856)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesEmbeddedObject GetAttachment([In][MarshalAs(UnmanagedType.BStr)] string pFilename);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743857)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesItem GetFirstItem([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743858)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object GetItemValue([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743859)]
	bool HasItem([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743860)]
	void MakeResponse([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pIDoc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743861)]
	void PutInFolder([In][MarshalAs(UnmanagedType.BStr)] string pName, [In] bool bCreateonfail = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743862)]
	bool Remove([In] bool bForce);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743863)]
	void RemoveFromFolder([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743864)]
	void RemoveItem([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743865)]
	bool RenderToRTItem([In][MarshalAs(UnmanagedType.Interface)] NotesRichTextItem pIRTItem);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743866)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesItem ReplaceItemValue([In][MarshalAs(UnmanagedType.BStr)] string pName, [In][MarshalAs(UnmanagedType.Struct)] object Value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743867)]
	bool Save([In] bool bForce, [In] bool bMakeresponse, [In] bool bMarkread = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743868)]
	void Send([In] bool bAttachform, [Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pRecipients);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743869)]
	void Sign();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743870)]
	bool CloseMIMEEntities([In] bool bSavechanges = false, [In][MarshalAs(UnmanagedType.BStr)] string pName = "Body");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743871)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesMIMEEntity CreateMIMEEntity([In][MarshalAs(UnmanagedType.BStr)] string pName = "Body");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743872)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesMIMEEntity GetMIMEEntity([In][MarshalAs(UnmanagedType.BStr)] string pName = "Body");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743873)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object GetItemValueCustomDataBytes([In][MarshalAs(UnmanagedType.BStr)] string pItemName, [In][MarshalAs(UnmanagedType.BStr)] string pDatatypeName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743874)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object GetItemValueDateTimeArray([In][MarshalAs(UnmanagedType.BStr)] string pItemName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743875)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object GetReceivedItemText();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743876)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesItem ReplaceItemValueCustomDataBytes([In][MarshalAs(UnmanagedType.BStr)] string pItemName, [In][MarshalAs(UnmanagedType.BStr)] string pDatatypeName, [In][MarshalAs(UnmanagedType.Struct)] object CustomData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743877)]
	bool RemovePermanently([In] bool bForce);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743878)]
	bool Lock([Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pName, [In] bool bProvisionalOK = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743879)]
	bool LockProvisional([Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743880)]
	void Unlock();

	[DispId(1610743881)]
	object LockHolders
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743881)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743882)]
	bool IsEncrypted
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743882)]
		get;
	}
}
[ComImport]
[Guid("29131579-2EED-1069-BF5D-00DD011186B7")]
[DefaultMember("Name")]
[TypeLibType(4160)]
public interface IView
{
	[DispId(1610743808)]
	object Aliases
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1610743809)]
	NotesViewEntryCollection AllEntries
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743810)]
	bool AutoUpdate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	[ComAliasName("Domino.COLORS")]
	COLORS BackgroundColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: ComAliasName("Domino.COLORS")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		set;
	}

	[DispId(1610743813)]
	int ColumnCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		get;
	}

	[DispId(1610743814)]
	object ColumnNames
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743815)]
	object Columns
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743816)]
	object Created
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743817)]
	int HeaderLines
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		get;
	}

	[DispId(1610743818)]
	string HttpURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743819)]
	bool IsCalendar
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		get;
	}

	[DispId(1610743820)]
	bool IsCategorized
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		get;
	}

	[DispId(1610743821)]
	bool IsConflict
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		get;
	}

	[DispId(1610743822)]
	bool IsDefaultView
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[param: In]
		set;
	}

	[DispId(1610743823)]
	bool IsFolder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		get;
	}

	[DispId(1610743824)]
	bool IsHierarchical
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		get;
	}

	[DispId(1610743825)]
	bool IsModified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		get;
	}

	[DispId(1610743826)]
	bool IsPrivate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		get;
	}

	[DispId(1610743827)]
	object LastModified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(0)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743829)]
	string NotesURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743830)]
	NotesDatabase Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743831)]
	bool ProtectReaders
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743831)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743831)]
		[param: In]
		set;
	}

	[DispId(1610743833)]
	object Readers
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743833)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743833)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1610743835)]
	int RowLines
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743835)]
		get;
	}

	[ComAliasName("Domino.SPACING")]
	[DispId(1610743836)]
	SPACING SPACING
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743836)]
		[return: ComAliasName("Domino.SPACING")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743836)]
		[param: In]
		set;
	}

	[DispId(1610743837)]
	int TopLevelEntryCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743837)]
		get;
	}

	[DispId(1610743838)]
	string UniversalID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743838)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743839)]
	void Clear();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743840)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewNavigator CreateViewNav([In] int lCacheSize = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743841)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewNavigator CreateViewNavMaxLevel([In] int lLevel, [In] int lCacheSize = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743842)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewNavigator CreateViewNavFrom([In][MarshalAs(UnmanagedType.IUnknown)] object pIUnk, [In] int lCacheSize = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743843)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewNavigator CreateViewNavFromCategory([In][MarshalAs(UnmanagedType.BStr)] string pName, [In] int lCacheSize = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743844)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewNavigator CreateViewNavFromChildren([In][MarshalAs(UnmanagedType.IUnknown)] object pIUnk, [In] int lCacheSize = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743845)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewNavigator CreateViewNavFromDescendants([In][MarshalAs(UnmanagedType.IUnknown)] object pIUnk, [In] int lCacheSize = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743846)]
	int FTSearch([In][MarshalAs(UnmanagedType.BStr)] string pQuery, [In] int lMaxDocs = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743847)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocumentCollection GetAllDocumentsByKey([In][MarshalAs(UnmanagedType.Struct)] object Keys, [In] bool bExact = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743848)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntryCollection GetAllEntriesByKey([In][MarshalAs(UnmanagedType.Struct)] object Keys, [In] bool bExact = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743849)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument GetChild([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743850)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewColumn GetColumn([In] int lColumnNumber);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743851)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument GetDocumentByKey([In][MarshalAs(UnmanagedType.Struct)] object Keys, [In] bool bExact = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743852)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetEntryByKey([In][MarshalAs(UnmanagedType.Struct)] object Keys, [In] bool bExact = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743853)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument GetFirstDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743854)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument GetLastDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743855)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument GetNextDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743856)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument GetNextSibling([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743857)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument GetNthDocument([In] int lN);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743858)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument GetParentDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743859)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument GetPrevDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743860)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument GetPrevSibling([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743861)]
	void Refresh();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743862)]
	void Remove();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743863)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewColumn CreateColumn([In] int pos = -1, [In][MarshalAs(UnmanagedType.BStr)] string Name = "", [In][MarshalAs(UnmanagedType.BStr)] string Formula = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743864)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewColumn CopyColumn([In][MarshalAs(UnmanagedType.Struct)] object nameIndexObj, [In] int dst = -1);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743865)]
	void RemoveColumn([In][MarshalAs(UnmanagedType.Struct)] object nameIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743867)]
	void SetAliases([In][MarshalAs(UnmanagedType.BStr)] string Aliases = "");

	[DispId(1610743868)]
	bool IsProhibitDesignRefresh
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743868)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743868)]
		[param: In]
		set;
	}

	[DispId(1610743874)]
	string SelectionFormula
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743874)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743874)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743876)]
	int EntryCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743876)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743877)]
	bool Lock([Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pName, [In] bool bProvisionalOK = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743878)]
	bool LockProvisional([Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743879)]
	void Unlock();

	[DispId(1610743880)]
	object LockHolders
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743880)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743881)]
	string ViewInheritedName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743881)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[Guid("2913157C-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(4160)]
public interface IViewEntryCollection
{
	[DispId(1610743808)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
	}

	[DispId(1610743809)]
	NotesView Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743810)]
	string Query
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743811)]
	void AddEntry([In][MarshalAs(UnmanagedType.IUnknown)] object pIObj, [In] bool bReserved = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743812)]
	void DeleteEntry([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743813)]
	void FTSearch([In][MarshalAs(UnmanagedType.BStr)] string pQuery, [In] int lMaxDocs = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743814)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetEntry([In][MarshalAs(UnmanagedType.IUnknown)] object pIObj);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetFirstEntry();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetLastEntry();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743817)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetNextEntry([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743818)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetNthEntry([In] int lN);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743819)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetPrevEntry([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743820)]
	void PutAllInFolder([In][MarshalAs(UnmanagedType.BStr)] string pFolderName, [In] bool bCreateonfail = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	void RemoveAll([In] bool bForce);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743822)]
	void RemoveAllFromFolder([In][MarshalAs(UnmanagedType.BStr)] string pFolderName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743823)]
	void StampAll([In][MarshalAs(UnmanagedType.BStr)] string pItemName, [In][MarshalAs(UnmanagedType.Struct)] object Value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	void UpdateAll();
}
[ComImport]
[Guid("2913157B-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(4160)]
public interface IViewEntry
{
	[DispId(1610743808)]
	int ChildCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
	}

	[DispId(1610743809)]
	int ColumnIndentLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		get;
	}

	[DispId(1610743810)]
	object ColumnValues
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743811)]
	int DescendantCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		get;
	}

	[DispId(1610743812)]
	NotesDocument Document
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743813)]
	int FTSearchScore
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		get;
	}

	[DispId(1610743814)]
	int IndentLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
	}

	[DispId(1610743815)]
	bool IsCategory
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		get;
	}

	[DispId(1610743816)]
	bool IsConflict
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
	}

	[DispId(1610743817)]
	bool IsDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		get;
	}

	[DispId(1610743818)]
	bool IsTotal
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
	}

	[DispId(1610743819)]
	bool IsValid
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		get;
	}

	[DispId(1610743820)]
	string NoteID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743821)]
	object Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		get;
	}

	[DispId(1610743822)]
	int SiblingCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		get;
	}

	[DispId(1610743823)]
	string UniversalID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetPosition([In][MarshalAs(UnmanagedType.BStr)] string pSeparator);
}
public enum COLORS
{
	COLOR_BLACK,
	COLOR_WHITE,
	COLOR_RED,
	COLOR_GREEN,
	COLOR_BLUE,
	COLOR_MAGENTA,
	COLOR_YELLOW,
	COLOR_CYAN,
	COLOR_DARK_RED,
	COLOR_DARK_GREEN,
	COLOR_DARK_BLUE,
	COLOR_DARK_MAGENTA,
	COLOR_DARK_YELLOW,
	COLOR_DARK_CYAN,
	COLOR_GRAY,
	COLOR_LIGHT_GRAY
}
public enum _COLORS
{
	COLOR_BLACK,
	COLOR_WHITE,
	COLOR_RED,
	COLOR_GREEN,
	COLOR_BLUE,
	COLOR_MAGENTA,
	COLOR_YELLOW,
	COLOR_CYAN,
	COLOR_DARK_RED,
	COLOR_DARK_GREEN,
	COLOR_DARK_BLUE,
	COLOR_DARK_MAGENTA,
	COLOR_DARK_YELLOW,
	COLOR_DARK_CYAN,
	COLOR_GRAY,
	COLOR_LIGHT_GRAY
}
public enum SPACING
{
	SPACING_SINGLE = 0,
	SPACING_DOUBLE = 2,
	SPACING_ONE_POINT_25 = 3,
	SPACING_ONE_POINT_50 = 1,
	SPACING_ONE_POINT_75 = 4,
	VW_SPACING_SINGLE = 0,
	VW_SPACING_DOUBLE = 2,
	VW_SPACING_ONE_POINT_25 = 3,
	VW_SPACING_ONE_POINT_50 = 1,
	VW_SPACING_ONE_POINT_75 = 4
}
public enum _SPACING
{
	SPACING_SINGLE = 0,
	SPACING_DOUBLE = 2,
	SPACING_ONE_POINT_25 = 3,
	SPACING_ONE_POINT_50 = 1,
	SPACING_ONE_POINT_75 = 4,
	VW_SPACING_SINGLE = 0,
	VW_SPACING_DOUBLE = 2,
	VW_SPACING_ONE_POINT_25 = 3,
	VW_SPACING_ONE_POINT_50 = 1,
	VW_SPACING_ONE_POINT_75 = 4
}
[ComImport]
[Guid("2913157D-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(4160)]
public interface IViewNavigator
{
	[DispId(1610743808)]
	int CacheSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		set;
	}

	[DispId(1610743810)]
	int MaxLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	NotesView ParentView
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743813)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetChild([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743814)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetEntry([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetCurrent();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetFirst();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743817)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetFirstDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743818)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetLast();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743819)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetLastDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743820)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetNext([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetNextCategory([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743822)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetNextDocument([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743823)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetNextSibling([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetNth([In] int lN);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetParent([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743826)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetPos([In][MarshalAs(UnmanagedType.BStr)] string pPos, [In][MarshalAs(UnmanagedType.BStr)] string pSeparator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743827)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetPrev([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743828)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetPrevCategory([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743829)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetPrevDocument([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743830)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesViewEntry GetPrevSibling([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743831)]
	void GotoChild([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIViewEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743832)]
	void GotoEntry([In][MarshalAs(UnmanagedType.IUnknown)] object pIObj);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743833)]
	void GotoFirst();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743834)]
	void GotoFirstDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743835)]
	void GotoLast();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743836)]
	void GotoLastDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743837)]
	void GotoNext([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIViewEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743838)]
	void GotoNextCategory([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIViewEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743839)]
	void GotoNextDocument([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIViewEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743840)]
	void GotoNextSibling([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIViewEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743841)]
	void GotoParent([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIViewEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743842)]
	void GotoPos([In][MarshalAs(UnmanagedType.BStr)] string pPos, [In][MarshalAs(UnmanagedType.BStr)] string pSeparator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743843)]
	void GotoPrev([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIViewEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743844)]
	void GotoPrevCategory([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIViewEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743845)]
	void GotoPrevDocument([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIViewEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743846)]
	void GotoPrevSibling([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIViewEntry);

	[DispId(1610743847)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743847)]
		get;
	}
}
[ComImport]
[DefaultMember("Title")]
[Guid("2913157A-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(4160)]
public interface IViewColumn
{
	[DispId(1610743808)]
	[ComAliasName("Domino.VC_ALIGN")]
	VC_ALIGN Alignment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: ComAliasName("Domino.VC_ALIGN")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		set;
	}

	[DispId(1610743809)]
	[ComAliasName("Domino.VC_DATEFMT")]
	VC_DATEFMT DateFmt
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: ComAliasName("Domino.VC_DATEFMT")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[param: In]
		set;
	}

	[DispId(1610743810)]
	[ComAliasName("Domino.COLORS")]
	COLORS FontColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: ComAliasName("Domino.COLORS")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743811)]
	string FontFace
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743812)]
	int FontPointSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		set;
	}

	[DispId(1610743813)]
	[ComAliasName("Domino.VC_FONTSTYLE")]
	VC_FONTSTYLE FontStyle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[return: ComAliasName("Domino.VC_FONTSTYLE")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[param: In]
		set;
	}

	[DispId(1610743814)]
	string Formula
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[ComAliasName("Domino.VC_ALIGN")]
	[DispId(1610743815)]
	VC_ALIGN HeaderAlignment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[return: ComAliasName("Domino.VC_ALIGN")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[param: In]
		set;
	}

	[DispId(1610743816)]
	bool IsAccentSensitiveSort
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[param: In]
		set;
	}

	[DispId(1610743817)]
	bool IsCaseSensitiveSort
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[param: In]
		set;
	}

	[DispId(1610743818)]
	bool IsCategory
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
	}

	[DispId(1610743819)]
	bool IsField
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		get;
	}

	[DispId(1610743820)]
	bool IsFormula
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		get;
	}

	[DispId(1610743821)]
	bool IsHidden
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[param: In]
		set;
	}

	[DispId(1610743822)]
	bool IsHideDetail
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[param: In]
		set;
	}

	[DispId(1610743823)]
	bool IsIcon
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		get;
	}

	[DispId(1610743824)]
	bool IsResize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[param: In]
		set;
	}

	[DispId(1610743825)]
	bool IsResortAscending
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		[param: In]
		set;
	}

	[DispId(1610743826)]
	bool IsResortDescending
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[param: In]
		set;
	}

	[DispId(1610743827)]
	bool IsResortToView
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		[param: In]
		set;
	}

	[DispId(1610743828)]
	bool IsResponse
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		get;
	}

	[DispId(1610743829)]
	bool IsSecondaryResort
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		[param: In]
		set;
	}

	[DispId(1610743830)]
	bool IsSecondaryResortDescending
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		[param: In]
		set;
	}

	[DispId(1610743831)]
	bool IsShowTwistie
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743831)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743831)]
		[param: In]
		set;
	}

	[DispId(1610743832)]
	bool IsSortDescending
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[param: In]
		set;
	}

	[DispId(1610743833)]
	bool IsSorted
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743833)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743833)]
		[param: In]
		set;
	}

	[DispId(1610743834)]
	string ItemName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743834)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("Domino.VC_SEP")]
	[DispId(1610743835)]
	VC_SEP ListSep
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743835)]
		[return: ComAliasName("Domino.VC_SEP")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743835)]
		[param: In]
		set;
	}

	[DispId(1610743836)]
	[ComAliasName("Domino.VC_NUMATTR")]
	VC_NUMATTR NumberAttrib
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743836)]
		[return: ComAliasName("Domino.VC_NUMATTR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743836)]
		[param: In]
		set;
	}

	[DispId(1610743837)]
	int NumberDigits
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743837)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743837)]
		[param: In]
		set;
	}

	[ComAliasName("Domino.VC_NUMFMT")]
	[DispId(1610743838)]
	VC_NUMFMT NumberFormat
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743838)]
		[return: ComAliasName("Domino.VC_NUMFMT")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743838)]
		[param: In]
		set;
	}

	[DispId(1610743839)]
	NotesView Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743839)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743840)]
	int Position
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743840)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743840)]
		[param: In]
		set;
	}

	[DispId(1610743841)]
	[ComAliasName("Domino.VC_TDFMT")]
	VC_TDFMT TimeDateFmt
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743841)]
		[return: ComAliasName("Domino.VC_TDFMT")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743841)]
		[param: In]
		set;
	}

	[ComAliasName("Domino.VC_TIMEFMT")]
	[DispId(1610743842)]
	VC_TIMEFMT TimeFmt
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743842)]
		[return: ComAliasName("Domino.VC_TIMEFMT")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743842)]
		[param: In]
		set;
	}

	[DispId(1610743843)]
	[ComAliasName("Domino.VC_TIMEZONEFMT")]
	VC_TIMEZONEFMT TimeZoneFmt
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743843)]
		[return: ComAliasName("Domino.VC_TIMEZONEFMT")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743843)]
		[param: In]
		set;
	}

	[DispId(0)]
	string Title
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743845)]
	int Width
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743845)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743845)]
		[param: In]
		set;
	}

	[DispId(1610743846)]
	int HeaderFontColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743846)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743846)]
		[param: In]
		set;
	}

	[DispId(1610743847)]
	string HeaderFontFace
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743847)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743847)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743848)]
	int HeaderFontPointSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743848)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743848)]
		[param: In]
		set;
	}

	[DispId(1610743849)]
	int HeaderFontStyle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743849)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743849)]
		[param: In]
		set;
	}

	[DispId(1610743850)]
	int SecondaryResortColumnIndex
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743850)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743850)]
		[param: In]
		set;
	}

	[DispId(1610743851)]
	bool IsFontBold
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743851)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743851)]
		[param: In]
		set;
	}

	[DispId(1610743852)]
	bool IsFontItalic
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743852)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743852)]
		[param: In]
		set;
	}

	[DispId(1610743853)]
	bool IsFontUnderline
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743853)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743853)]
		[param: In]
		set;
	}

	[DispId(1610743854)]
	bool IsFontStrikethrough
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743854)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743854)]
		[param: In]
		set;
	}

	[DispId(1610743855)]
	bool IsHeaderFontBold
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743855)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743855)]
		[param: In]
		set;
	}

	[DispId(1610743856)]
	bool IsHeaderFontItalic
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743856)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743856)]
		[param: In]
		set;
	}

	[DispId(1610743857)]
	bool IsHeaderFontUnderline
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743857)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743857)]
		[param: In]
		set;
	}

	[DispId(1610743858)]
	bool IsHeaderFontStrikethrough
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743858)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743858)]
		[param: In]
		set;
	}

	[DispId(1610743859)]
	bool IsNumberAttribParens
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743859)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743859)]
		[param: In]
		set;
	}

	[DispId(1610743860)]
	bool IsNumberAttribPunctuated
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743860)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743860)]
		[param: In]
		set;
	}

	[DispId(1610743861)]
	bool IsNumberAttribPercent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743861)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743861)]
		[param: In]
		set;
	}

	[DispId(1610743862)]
	string ResortToViewName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743862)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743862)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}
}
public enum VC_ALIGN
{
	VC_ALIGN_LEFT,
	VC_ALIGN_RIGHT,
	VC_ALIGN_CENTER
}
public enum _VC_ALIGN
{
	VC_ALIGN_LEFT,
	VC_ALIGN_RIGHT,
	VC_ALIGN_CENTER
}
public enum VC_DATEFMT
{
	VC_FMT_YMD = 0,
	VC_FMT_MD = 2,
	VC_FMT_YM = 3,
	VC_FMT_Y4M = 6
}
public enum _VC_DATEFMT
{
	VC_FMT_YMD = 0,
	VC_FMT_MD = 2,
	VC_FMT_YM = 3,
	VC_FMT_Y4M = 6
}
public enum VC_FONTSTYLE
{
	VC_FONT_BOLD = 1,
	VC_FONT_ITALIC = 2,
	VC_FONT_UNDERLINE = 4,
	VC_FONT_STRIKEOUT = 8,
	VC_FONT_STRIKETHROUGH = 8
}
public enum _VC_FONTSTYLE
{
	VC_FONT_BOLD = 1,
	VC_FONT_ITALIC = 2,
	VC_FONT_UNDERLINE = 4,
	VC_FONT_STRIKEOUT = 8,
	VC_FONT_STRIKETHROUGH = 8
}
public enum VC_SEP
{
	VC_SEP_SPACE = 1,
	VC_SEP_COMMA,
	VC_SEP_SEMICOLON,
	VC_SEP_NEWLINE
}
public enum _VC_SEP
{
	VC_SEP_SPACE = 1,
	VC_SEP_COMMA,
	VC_SEP_SEMICOLON,
	VC_SEP_NEWLINE
}
public enum VC_NUMATTR
{
	VC_ATTR_PUNCTUATED = 1,
	VC_ATTR_PARENS = 2,
	VC_ATTR_PERCENT = 4
}
public enum _VC_NUMATTR
{
	VC_ATTR_PUNCTUATED = 1,
	VC_ATTR_PARENS = 2,
	VC_ATTR_PERCENT = 4
}
public enum VC_NUMFMT
{
	VC_FMT_GENERAL,
	VC_FMT_FIXED,
	VC_FMT_SCIENTIFIC,
	VC_FMT_CURRENCY
}
public enum _VC_NUMFMT
{
	VC_FMT_GENERAL,
	VC_FMT_FIXED,
	VC_FMT_SCIENTIFIC,
	VC_FMT_CURRENCY
}
public enum VC_TDFMT
{
	VC_FMT_DATE,
	VC_FMT_TIME,
	VC_FMT_DATETIME,
	VC_FMT_TODAYTIME
}
public enum _VC_TDFMT
{
	VC_FMT_DATE,
	VC_FMT_TIME,
	VC_FMT_DATETIME,
	VC_FMT_TODAYTIME
}
public enum VC_TIMEFMT
{
	VC_FMT_HMS,
	VC_FMT_HM,
	VC_FMT_H,
	VC_FMT_ALL
}
public enum _VC_TIMEFMT
{
	VC_FMT_HMS,
	VC_FMT_HM,
	VC_FMT_H,
	VC_FMT_ALL
}
public enum VC_TIMEZONEFMT
{
	VC_FMT_NEVER,
	VC_FMT_SOMETIMES,
	VC_FMT_ALWAYS
}
public enum _VC_TIMEZONEFMT
{
	VC_FMT_NEVER,
	VC_FMT_SOMETIMES,
	VC_FMT_ALWAYS
}
[ComImport]
[TypeLibType(4160)]
[Guid("2913158A-2EED-1069-BF5D-00DD011186B7")]
[DefaultMember("Name")]
public interface IItem2 : IItem
{
	[DispId(1610743808)]
	new NotesDateTime DateTimeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1610743810)]
	new bool IsAuthors
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	new bool IsEncrypted
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		set;
	}

	[DispId(1610743814)]
	new bool IsNames
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		set;
	}

	[DispId(1610743816)]
	new bool IsProtected
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[param: In]
		set;
	}

	[DispId(1610743818)]
	new bool IsReaders
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[param: In]
		set;
	}

	[DispId(1610743820)]
	new bool IsSigned
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[param: In]
		set;
	}

	[DispId(1610743822)]
	new bool IsSummary
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[param: In]
		set;
	}

	[DispId(1610743824)]
	new object LastModified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(0)]
	new string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743826)]
	new NotesDocument Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743827)]
	new bool SaveToDisk
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		[param: In]
		set;
	}

	[DispId(1610743829)]
	new string Text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743830)]
	[ComAliasName("Domino.IT_TYPE")]
	new IT_TYPE type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		[return: ComAliasName("Domino.IT_TYPE")]
		get;
	}

	[DispId(1610743831)]
	new int ValueLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743831)]
		get;
	}

	[DispId(1610743832)]
	new object Values
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743834)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string Abstract([In] int lMaxlen, [In] bool bDropvowels, [In] bool bUsedict);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743835)]
	new void AppendToTextList([In][MarshalAs(UnmanagedType.Struct)] object Values);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743836)]
	new bool Contains([In][MarshalAs(UnmanagedType.Struct)] object Value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743837)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new NotesItem CopyItemToDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pIDoc, [In][MarshalAs(UnmanagedType.BStr)] string pNewname);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743838)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new NotesMIMEEntity GetMIMEEntity();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743839)]
	new void Remove();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809344)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object GetValueCustomDataBytes([In][MarshalAs(UnmanagedType.BStr)] string pDatatypeName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809345)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object GetValueDateTimeArray();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809346)]
	void SetValueCustomDataBytes([In][MarshalAs(UnmanagedType.BStr)] string pDatatypeName, [In][MarshalAs(UnmanagedType.Struct)] object CustomData);
}
[ComImport]
[Guid("2913156B-2EED-1069-BF5D-00DD011186B7")]
[DefaultMember("Name")]
[TypeLibType(4160)]
public interface IItem
{
	[DispId(1610743808)]
	NotesDateTime DateTimeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1610743810)]
	bool IsAuthors
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	bool IsEncrypted
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		set;
	}

	[DispId(1610743814)]
	bool IsNames
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		set;
	}

	[DispId(1610743816)]
	bool IsProtected
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[param: In]
		set;
	}

	[DispId(1610743818)]
	bool IsReaders
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[param: In]
		set;
	}

	[DispId(1610743820)]
	bool IsSigned
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[param: In]
		set;
	}

	[DispId(1610743822)]
	bool IsSummary
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[param: In]
		set;
	}

	[DispId(1610743824)]
	object LastModified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(0)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743826)]
	NotesDocument Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743827)]
	bool SaveToDisk
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		[param: In]
		set;
	}

	[DispId(1610743829)]
	string Text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("Domino.IT_TYPE")]
	[DispId(1610743830)]
	IT_TYPE type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		[return: ComAliasName("Domino.IT_TYPE")]
		get;
	}

	[DispId(1610743831)]
	int ValueLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743831)]
		get;
	}

	[DispId(1610743832)]
	object Values
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743834)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string Abstract([In] int lMaxlen, [In] bool bDropvowels, [In] bool bUsedict);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743835)]
	void AppendToTextList([In][MarshalAs(UnmanagedType.Struct)] object Values);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743836)]
	bool Contains([In][MarshalAs(UnmanagedType.Struct)] object Value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743837)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesItem CopyItemToDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pIDoc, [In][MarshalAs(UnmanagedType.BStr)] string pNewname);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743838)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesMIMEEntity GetMIMEEntity();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743839)]
	void Remove();
}
[ComImport]
[Guid("29131564-2EED-1069-BF5D-00DD011186B7")]
[DefaultMember("LocalTime")]
[TypeLibType(4160)]
public interface IDateTime
{
	[DispId(1610743808)]
	string DateOnly
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	string GMTTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743810)]
	bool IsDST
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
	}

	[DispId(1610743811)]
	bool IsValidDate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		get;
	}

	[DispId(0)]
	string LocalTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743814)]
	object LSGMTTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743815)]
	object LSLocalTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1610743817)]
	NotesSession Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743818)]
	string TimeOnly
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743819)]
	int TimeZone
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		get;
	}

	[DispId(1610743820)]
	string ZoneTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	void AdjustDay([In] int lAdjust, [In] bool bPreserveLocalTime = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743822)]
	void AdjustHour([In] int lAdjust, [In] bool bPreserveLocalTime = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743823)]
	void AdjustMinute([In] int lAdjust, [In] bool bPreserveLocalTime = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	void AdjustMonth([In] int lAdjust, [In] bool bPreserveLocalTime = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	void AdjustSecond([In] int lAdjust, [In] bool bPreserveLocalTime = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743826)]
	void AdjustYear([In] int lAdjust, [In] bool bPreserveLocalTime = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743827)]
	void ConvertToZone([In] int lNewzone, [In] bool bDst);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743828)]
	void SetAnyDate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743829)]
	void SetAnyTime();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743830)]
	void SetNow();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743831)]
	int TimeDifference([In][MarshalAs(UnmanagedType.Interface)] NotesDateTime pIDt);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743832)]
	double TimeDifferenceDouble([In][MarshalAs(UnmanagedType.Interface)] NotesDateTime pIDt);
}
[ComImport]
[Guid("29131578-2EED-1069-BF5D-00DD011186B7")]
[DefaultMember("UserName")]
[TypeLibType(4160)]
public interface ISession
{
	[DispId(1610743808)]
	object AddressBooks
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743809)]
	string CommonUserName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743810)]
	NotesAgent CurrentAgent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743811)]
	NotesDatabase CurrentDatabase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743812)]
	NotesDocument DocumentContext
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743813)]
	string EffectiveUserName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743814)]
	string HttpURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743815)]
	NotesInternational International
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743816)]
	bool ConvertMime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[param: In]
		set;
	}

	[DispId(1610743818)]
	bool IsOnServer
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
	}

	[DispId(1610743819)]
	int LastExitStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		get;
	}

	[DispId(1610743820)]
	object LastRun
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743821)]
	int NotesBuildVersion
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		get;
	}

	[DispId(1610743822)]
	string NotesURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743823)]
	string NotesVersion
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743824)]
	string Platform
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743825)]
	NotesDocument SavedData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743826)]
	string ServerName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(0)]
	string UserName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743828)]
	object UserNameList
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743829)]
	NotesName UserNameObject
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743830)]
	NotesDatabase URLDatabase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743831)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDateRange CreateDateRange();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743832)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDateTime CreateDateTime([In][MarshalAs(UnmanagedType.BStr)] string pDate);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743833)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesLog CreateLog([In][MarshalAs(UnmanagedType.BStr)] string Name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743834)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesName CreateName([In][MarshalAs(UnmanagedType.BStr)] string pName, [In][MarshalAs(UnmanagedType.BStr)] string pLang = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743835)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesNewsletter CreateNewsletter([In][MarshalAs(UnmanagedType.Interface)] NotesDocumentCollection pIDc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743836)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesRegistration CreateRegistration();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743837)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesRichTextParagraphStyle CreateRichTextParagraphStyle();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743838)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesRichTextStyle CreateRichTextStyle();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743839)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object Evaluate([In][MarshalAs(UnmanagedType.BStr)] string pFormula, [In][MarshalAs(UnmanagedType.Interface)] NotesDocument pIDoc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743840)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object FreeTimeSearch([In][MarshalAs(UnmanagedType.Interface)] NotesDateRange pIWindow, [In] int iDuration, [In][MarshalAs(UnmanagedType.Struct)] object Names, [In] bool bFirstfit = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743841)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDatabase GetDatabase([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pFile, [In] bool bCreateonfail = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743842)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDbDirectory GetDbDirectory([In][MarshalAs(UnmanagedType.BStr)] string pServer);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743843)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetEnvironmentString([In][MarshalAs(UnmanagedType.BStr)] string pName, [In] bool bisSystem = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743844)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object GetEnvironmentValue([In][MarshalAs(UnmanagedType.BStr)] string pName, [In] bool bisSystem = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743845)]
	void Initialize([In][MarshalAs(UnmanagedType.BStr)] string pPassword = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743846)]
	void InitializeUsingNotesUserName([In][MarshalAs(UnmanagedType.BStr)] string pUser = "", [In][MarshalAs(UnmanagedType.BStr)] string pPassword = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743847)]
	void SetEnvironmentVar([In][MarshalAs(UnmanagedType.BStr)] string pName, [In][MarshalAs(UnmanagedType.Struct)] object Value, [In] bool bisSystem = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743848)]
	void UpdateProcessedDoc([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pIDoc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743849)]
	[return: MarshalAs(UnmanagedType.IUnknown)]
	object Resolve([In][MarshalAs(UnmanagedType.BStr)] string pURL);

	[DispId(1610743850)]
	object UserGroupNameList
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743850)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743851)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesAdministrationProcess CreateAdministrationProcess([In][MarshalAs(UnmanagedType.BStr)] string pServer);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743852)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesStream CreateStream();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743853)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string SendConsoleCommand([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pCommand);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743854)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesColorObject CreateColorObject();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743855)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDXLExporter CreateDXLExporter();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743856)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDXLImporter CreateDXLImporter();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743857)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument GetUserPolicySettings([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pName, [In][ComAliasName("Domino.SESS_POLICY")] SESS_POLICY lType, [In][MarshalAs(UnmanagedType.BStr)] string pExplicitPolicy = "", [In][MarshalAs(UnmanagedType.BStr)] string pReserved = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743858)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string HashPassword([In][MarshalAs(UnmanagedType.BStr)] string pPassword);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743859)]
	bool VerifyPassword([In][MarshalAs(UnmanagedType.BStr)] string pPassword, [In][MarshalAs(UnmanagedType.BStr)] string pHashedPassword);

	[DispId(1610743860)]
	string OrgDirectoryPath
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743860)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[DefaultMember("Name")]
[Guid("29131562-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(4160)]
public interface IAgent
{
	[DispId(1610743808)]
	string Comment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	string CommonOwner
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743810)]
	bool HasRunSinceModified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
	}

	[DispId(1610743811)]
	string HttpURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743812)]
	bool IsEnabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		set;
	}

	[DispId(1610743814)]
	bool IsNotesAgent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
	}

	[DispId(1610743815)]
	bool IsPublic
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		get;
	}

	[DispId(1610743816)]
	bool IsWebAgent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
	}

	[DispId(1610743817)]
	object LastRun
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(0)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743819)]
	string NotesURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743820)]
	string Owner
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743821)]
	string ParameterDocID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743822)]
	NotesDatabase Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743823)]
	string Query
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743824)]
	string ServerName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[ComAliasName("Domino.AG_TARGET")]
	[DispId(1610743826)]
	AG_TARGET Target
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[return: ComAliasName("Domino.AG_TARGET")]
		get;
	}

	[DispId(1610743827)]
	[ComAliasName("Domino.AG_TRIGGER")]
	AG_TRIGGER Trigger
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		[return: ComAliasName("Domino.AG_TRIGGER")]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743828)]
	void Remove();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743829)]
	void Run([In][MarshalAs(UnmanagedType.BStr)] string pNoteid = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743830)]
	void RunOnServer([In][MarshalAs(UnmanagedType.BStr)] string pNoteid = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743831)]
	void Save();

	[DispId(1610743832)]
	string OnBehalfOf
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743833)]
	bool Lock([Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pName, [In] bool bProvisionalOK = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743834)]
	bool LockProvisional([Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743835)]
	void Unlock();

	[DispId(1610743836)]
	object LockHolders
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743836)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743837)]
	bool IsActivatable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743837)]
		get;
	}
}
public enum AG_TARGET
{
	TARGET_NONE,
	TARGET_ALL_DOCS,
	TARGET_NEW_DOCS,
	TARGET_NEW_OR_MODIFIED_DOCS,
	TARGET_SELECTED_DOCS,
	TARGET_ALL_DOCS_IN_VIEW,
	TARGET_UNREAD_DOCS_IN_VIEW
}
public enum _AG_TARGET
{
	TARGET_NONE,
	TARGET_ALL_DOCS,
	TARGET_NEW_DOCS,
	TARGET_NEW_OR_MODIFIED_DOCS,
	TARGET_SELECTED_DOCS,
	TARGET_ALL_DOCS_IN_VIEW,
	TARGET_UNREAD_DOCS_IN_VIEW
}
public enum AG_TRIGGER
{
	TRIGGER_NONE,
	TRIGGER_SCHEDULED,
	TRIGGER_AFTER_MAIL_DELIVERY,
	TRIGGER_DOC_PASTED,
	TRIGGER_MANUAL,
	TRIGGER_UPDATE,
	TRIGGER_BEFORE_MAIL_DELIVERY
}
public enum _AG_TRIGGER
{
	TRIGGER_NONE,
	TRIGGER_SCHEDULED,
	TRIGGER_AFTER_MAIL_DELIVERY,
	TRIGGER_DOC_PASTED,
	TRIGGER_MANUAL,
	TRIGGER_UPDATE,
	TRIGGER_BEFORE_MAIL_DELIVERY
}
[ComImport]
[TypeLibType(4160)]
[Guid("2913156C-2EED-1069-BF5D-00DD011186B7")]
public interface IInternational
{
	[DispId(1610743808)]
	string AMString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	int CurrencyDigits
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		get;
	}

	[DispId(1610743810)]
	string CurrencySymbol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743811)]
	string DateSep
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743812)]
	string DecimalSep
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743813)]
	bool IsCurrencySpace
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		get;
	}

	[DispId(1610743814)]
	bool IsCurrencySuffix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
	}

	[DispId(1610743815)]
	bool IsCurrencyZero
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		get;
	}

	[DispId(1610743816)]
	bool IsDateDMY
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
	}

	[DispId(1610743817)]
	bool IsDateMDY
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		get;
	}

	[DispId(1610743818)]
	bool IsDateYMD
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
	}

	[DispId(1610743819)]
	bool IsDST
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		get;
	}

	[DispId(1610743820)]
	bool IsTime24Hour
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		get;
	}

	[DispId(1610743821)]
	NotesSession Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743822)]
	string PMString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743823)]
	string ThousandsSep
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743824)]
	string TimeSep
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743825)]
	int TimeZone
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		get;
	}

	[DispId(1610743826)]
	string Today
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743827)]
	string Tomorrow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743828)]
	string Yesterday
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[DefaultMember("Canonical")]
[Guid("2913156E-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(4160)]
public interface IName
{
	[DispId(1610743808)]
	string Abbreviated
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	string Addr821
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743810)]
	string Addr822Comment1
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743811)]
	string Addr822Comment2
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743812)]
	string Addr822Comment3
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743813)]
	string Addr822LocalPart
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743814)]
	string Addr822Phrase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743815)]
	string ADMD
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(0)]
	string Canonical
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743817)]
	string Common
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743818)]
	string Country
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743819)]
	string Generation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743820)]
	string Given
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743821)]
	string Initials
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743822)]
	bool IsHierarchical
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		get;
	}

	[DispId(1610743823)]
	string Keyword
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743824)]
	string Language
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743825)]
	string Organization
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743826)]
	string OrgUnit1
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743827)]
	string OrgUnit2
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743828)]
	string OrgUnit3
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743829)]
	string OrgUnit4
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743830)]
	NotesSession Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743831)]
	string PRMD
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743831)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743832)]
	string Surname
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[DefaultMember("Text")]
[Guid("29131565-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(4160)]
public interface IDateRange
{
	[DispId(1610743808)]
	NotesDateTime EndDateTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1610743810)]
	NotesSession Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743811)]
	NotesDateTime StartDateTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(0)]
	string Text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}
}
[ComImport]
[DefaultMember("ProgramName")]
[TypeLibType(4160)]
[Guid("2913156D-2EED-1069-BF5D-00DD011186B7")]
public interface ILog
{
	[DispId(1610743808)]
	bool LogActions
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		set;
	}

	[DispId(1610743810)]
	bool LogErrors
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	int NumActions
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
	}

	[DispId(1610743813)]
	int NumErrors
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		get;
	}

	[DispId(1610743814)]
	bool OverwriteFile
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		set;
	}

	[DispId(0)]
	string ProgramName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743818)]
	NotesSession Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743819)]
	void Close();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743820)]
	void LogAction([In][MarshalAs(UnmanagedType.BStr)] string pAction);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	void LogError([In] int lCode, [In][MarshalAs(UnmanagedType.BStr)] string pText);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743822)]
	void LogEvent([In][MarshalAs(UnmanagedType.BStr)] string pText, [In][MarshalAs(UnmanagedType.BStr)] string pQueue, [In][ComAliasName("Domino.LOG_EVENTS")] LOG_EVENTS lEvent, [In][ComAliasName("Domino.LOG_SEVERITY")] LOG_SEVERITY lSeverity);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743823)]
	void OpenAgentLog();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	void OpenFileLog([In][MarshalAs(UnmanagedType.BStr)] string pFilepath);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	void OpenMailLog([In][MarshalAs(UnmanagedType.Struct)] object Recipients, [In][MarshalAs(UnmanagedType.BStr)] string pSubject);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743826)]
	void OpenNotesLog([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pDatabase);
}
public enum LOG_EVENTS
{
	EV_UNKNOWN,
	EV_COMM,
	EV_SECURITY,
	EV_MAIL,
	EV_REPLICA,
	EV_RESOURCE,
	EV_MISC,
	EV_SERVER,
	EV_ALARM,
	EV_UPDATE
}
public enum _LOG_EVENTS
{
	EV_UNKNOWN,
	EV_COMM,
	EV_SECURITY,
	EV_MAIL,
	EV_REPLICA,
	EV_RESOURCE,
	EV_MISC,
	EV_SERVER,
	EV_ALARM,
	EV_UPDATE
}
public enum LOG_SEVERITY
{
	SEV_UNKNOWN,
	SEV_FATAL,
	SEV_FAILURE,
	SEV_WARNING1,
	SEV_WARNING2,
	SEV_NORMAL
}
public enum _LOG_SEVERITY
{
	SEV_UNKNOWN,
	SEV_FATAL,
	SEV_FAILURE,
	SEV_WARNING1,
	SEV_WARNING2,
	SEV_NORMAL
}
[ComImport]
[TypeLibType(4160)]
[Guid("2913156F-2EED-1069-BF5D-00DD011186B7")]
public interface INewsletter
{
	[DispId(1610743808)]
	bool DoScore
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		set;
	}

	[DispId(1610743810)]
	bool DoSubject
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	NotesSession Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743813)]
	string SubjectItemName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument FormatDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDatabase pIDb, [In] int lIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDocument FormatMsgWithDoclinks([In][MarshalAs(UnmanagedType.Interface)] NotesDatabase pIDb);
}
[ComImport]
[TypeLibType(4160)]
[Guid("29131572-2EED-1069-BF5D-00DD011186B7")]
public interface IRegistration
{
	[DispId(1610743808)]
	string CertifierIDFile
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743810)]
	bool CreateMailDb
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	object Expiration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[ComAliasName("Domino.REG_TYPE")]
	[DispId(1610743814)]
	REG_TYPE IDType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[return: ComAliasName("Domino.REG_TYPE")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		[param: ComAliasName("Domino.REG_TYPE")]
		set;
	}

	[DispId(1610743816)]
	bool IsNorthAmerican
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[param: In]
		set;
	}

	[DispId(1610743818)]
	int MinPasswordLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[param: In]
		set;
	}

	[DispId(1610743820)]
	string OrgUnit
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743822)]
	string RegistrationLog
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743824)]
	string RegistrationServer
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743826)]
	bool StoreIDInAddressBook
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[param: In]
		set;
	}

	[DispId(1610743828)]
	bool UpdateAddressBook
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743830)]
	void AddCertifierToAddressBook([In][MarshalAs(UnmanagedType.BStr)] string pIdfile, [In][MarshalAs(UnmanagedType.BStr)] string pPassword = "", [In][MarshalAs(UnmanagedType.BStr)] string pLocation = "", [In][MarshalAs(UnmanagedType.BStr)] string pComment = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743831)]
	void AddServerToAddressBook([In][MarshalAs(UnmanagedType.BStr)] string pIdfile, [In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pDomain, [In][MarshalAs(UnmanagedType.BStr)] string pUserpw = "", [In][MarshalAs(UnmanagedType.BStr)] string pNetwork = "", [In][MarshalAs(UnmanagedType.BStr)] string pAdminname = "", [In][MarshalAs(UnmanagedType.BStr)] string pTitle = "", [In][MarshalAs(UnmanagedType.BStr)] string pLocation = "", [In][MarshalAs(UnmanagedType.BStr)] string pComment = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743832)]
	void AddUserProfile([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In][MarshalAs(UnmanagedType.BStr)] string pProfile);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743833)]
	void AddUserToAddressBook([In][MarshalAs(UnmanagedType.BStr)] string pIdfile, [In][MarshalAs(UnmanagedType.BStr)] string pFullname, [In][MarshalAs(UnmanagedType.BStr)] string pLastn, [In][MarshalAs(UnmanagedType.BStr)] string pUserpw = "", [In][MarshalAs(UnmanagedType.BStr)] string pFirstn = "", [In][MarshalAs(UnmanagedType.BStr)] string pMiddle = "", [In][MarshalAs(UnmanagedType.BStr)] string pMailserv = "", [In][MarshalAs(UnmanagedType.BStr)] string pMailfilepath = "", [In][MarshalAs(UnmanagedType.BStr)] string pFwdaddr = "", [In][MarshalAs(UnmanagedType.BStr)] string pLocation = "", [In][MarshalAs(UnmanagedType.BStr)] string pComment = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743834)]
	void CrossCertify([In][MarshalAs(UnmanagedType.BStr)] string pIdfile, [In][MarshalAs(UnmanagedType.BStr)] string pCertpw = "", [In][MarshalAs(UnmanagedType.BStr)] string pComment = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743835)]
	void DeleteIDOnServer([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In] bool bIsserverid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743836)]
	void GetIDFromServer([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In][MarshalAs(UnmanagedType.BStr)] string pFilepath, [In] bool bIsserverid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743837)]
	void GetUserInfo([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [Optional][DefaultParameterValue("0")][MarshalAs(UnmanagedType.BStr)] out string ppMailserver, [Optional][DefaultParameterValue("0")][MarshalAs(UnmanagedType.BStr)] out string ppMailfile, [Optional][DefaultParameterValue("0")][MarshalAs(UnmanagedType.BStr)] out string ppMaildomain, [Optional][DefaultParameterValue(0)] out int pMailsystem, [Optional][DefaultParameterValue(0)][MarshalAs(UnmanagedType.Struct)] out object pProfile);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743838)]
	void Recertify([In][MarshalAs(UnmanagedType.BStr)] string pIdfile, [In][MarshalAs(UnmanagedType.BStr)] string pCertpw = "", [In][MarshalAs(UnmanagedType.BStr)] string pComment = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743839)]
	void RegisterNewCertifier([In][MarshalAs(UnmanagedType.BStr)] string pOrg, [In][MarshalAs(UnmanagedType.BStr)] string pIdfile, [In][MarshalAs(UnmanagedType.BStr)] string pCertpw, [In][MarshalAs(UnmanagedType.BStr)] string pCountry = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743840)]
	void RegisterNewServer([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pIdfile, [In][MarshalAs(UnmanagedType.BStr)] string pDomain, [In][MarshalAs(UnmanagedType.BStr)] string pServerpw = "", [In][MarshalAs(UnmanagedType.BStr)] string pCertpw = "", [In][MarshalAs(UnmanagedType.BStr)] string pLocation = "", [In][MarshalAs(UnmanagedType.BStr)] string pComment = "", [In][MarshalAs(UnmanagedType.BStr)] string pNetwork = "", [In][MarshalAs(UnmanagedType.BStr)] string pAdminname = "", [In][MarshalAs(UnmanagedType.BStr)] string pTitle = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743841)]
	void RegisterNewUser([In][MarshalAs(UnmanagedType.BStr)] string pLastn, [In][MarshalAs(UnmanagedType.BStr)] string pIdfile, [In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pFirstn = "", [In][MarshalAs(UnmanagedType.BStr)] string pMiddle = "", [In][MarshalAs(UnmanagedType.BStr)] string pCertpw = "", [In][MarshalAs(UnmanagedType.BStr)] string pLocation = "", [In][MarshalAs(UnmanagedType.BStr)] string pComment = "", [In][MarshalAs(UnmanagedType.BStr)] string pMaildbpath = "", [In][MarshalAs(UnmanagedType.BStr)] string pForward = "", [In][MarshalAs(UnmanagedType.BStr)] string pUserpw = "", [In][MarshalAs(UnmanagedType.BStr)] string pAltName = "", [In][MarshalAs(UnmanagedType.BStr)] string pAltLang = "", [In][ComAliasName("Domino.USER_TYPE")] USER_TYPE type = USER_TYPE.NOTES_FULL_CLIENT);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743842)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string SwitchToID([In][MarshalAs(UnmanagedType.BStr)] string pIdfile, [In][MarshalAs(UnmanagedType.BStr)] string pUserpw = "");

	[DispId(1610743843)]
	string CertifierName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743843)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743843)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743845)]
	string MailACLManager
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743845)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743845)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743847)]
	string MailInternetAddress
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743847)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743847)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743849)]
	string MailTemplateName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743849)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743849)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743851)]
	string PolicyName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743851)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743851)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743853)]
	string RoamingServer
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743853)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743853)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743855)]
	string RoamingSubdir
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743855)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743855)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743857)]
	string ShortName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743857)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743857)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743859)]
	bool EnforceUniqueShortName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743859)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743859)]
		[param: In]
		set;
	}

	[DispId(1610743861)]
	bool IsRoamingUser
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743861)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743861)]
		[param: In]
		set;
	}

	[DispId(1610743863)]
	bool MailCreateFTIndex
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743863)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743863)]
		[param: In]
		set;
	}

	[DispId(1610743865)]
	bool NoIDFile
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743865)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743865)]
		[param: In]
		set;
	}

	[DispId(1610743867)]
	bool StoreIDInMailfile
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743867)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743867)]
		[param: In]
		set;
	}

	[DispId(1610743869)]
	bool SynchInternetPassword
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743869)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743869)]
		[param: In]
		set;
	}

	[DispId(1610743871)]
	bool UseCertificateAuthority
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743871)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743871)]
		[param: In]
		set;
	}

	[DispId(1610743873)]
	[ComAliasName("Domino.REG_MAILOWNACL")]
	REG_MAILOWNACL MailOwnerAccess
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743873)]
		[return: ComAliasName("Domino.REG_MAILOWNACL")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743873)]
		[param: In]
		[param: ComAliasName("Domino.REG_MAILOWNACL")]
		set;
	}

	[ComAliasName("Domino.REG_MAILTYPE")]
	[DispId(1610743875)]
	REG_MAILTYPE MailSystem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743875)]
		[return: ComAliasName("Domino.REG_MAILTYPE")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743875)]
		[param: In]
		[param: ComAliasName("Domino.REG_MAILTYPE")]
		set;
	}

	[ComAliasName("Domino.REG_ROAMCLEANUP")]
	[DispId(1610743877)]
	REG_ROAMCLEANUP RoamingCleanupSetting
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743877)]
		[return: ComAliasName("Domino.REG_ROAMCLEANUP")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743877)]
		[param: In]
		[param: ComAliasName("Domino.REG_ROAMCLEANUP")]
		set;
	}

	[DispId(1610743879)]
	int MailQuotaSizeLimit
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743879)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743879)]
		[param: In]
		set;
	}

	[DispId(1610743881)]
	int MailQuotaWarningThreshold
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743881)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743881)]
		[param: In]
		set;
	}

	[DispId(1610743883)]
	int RoamingCleanupPeriod
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743883)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743883)]
		[param: In]
		set;
	}

	[DispId(1610743885)]
	object GroupList
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743885)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743885)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1610743887)]
	object MailReplicaServers
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743887)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743887)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1610743889)]
	object AltOrgUnit
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743889)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743889)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1610743891)]
	object AltOrgUnitLang
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743891)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743891)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}
}
public enum REG_TYPE
{
	ID_FLAT = 171,
	ID_HIERARCHICAL,
	ID_CERTIFIER
}
public enum _REG_TYPE
{
	ID_FLAT = 171,
	ID_HIERARCHICAL,
	ID_CERTIFIER
}
public enum USER_TYPE
{
	NOTES_LIMITED_CLIENT = 174,
	NOTES_DESKTOP_CLIENT,
	NOTES_FULL_CLIENT
}
public enum _USER_TYPE
{
	NOTES_LIMITED_CLIENT = 174,
	NOTES_DESKTOP_CLIENT,
	NOTES_FULL_CLIENT
}
public enum REG_MAILOWNACL
{
	REG_MAIL_OWNER_ACL_MANAGER,
	REG_MAIL_OWNER_ACL_DESIGNER,
	REG_MAIL_OWNER_ACL_EDITOR
}
public enum _REG_MAILOWNACL
{
	REG_MAIL_OWNER_ACL_MANAGER,
	REG_MAIL_OWNER_ACL_DESIGNER,
	REG_MAIL_OWNER_ACL_EDITOR
}
public enum REG_MAILTYPE
{
	REG_MAILSYSTEM_NOTES,
	REG_MAILSYSTEM_POP,
	REG_MAILSYSTEM_IMAP,
	REG_MAILSYSTEM_INOTES,
	REG_MAILSYSTEM_INTERNET,
	REG_MAILSYSTEM_OTHER,
	REG_MAILSYSTEM_NONE
}
public enum _REG_MAILTYPE
{
	REG_MAILSYSTEM_NOTES,
	REG_MAILSYSTEM_POP,
	REG_MAILSYSTEM_IMAP,
	REG_MAILSYSTEM_INOTES,
	REG_MAILSYSTEM_INTERNET,
	REG_MAILSYSTEM_OTHER,
	REG_MAILSYSTEM_NONE
}
public enum REG_ROAMCLEANUP
{
	REG_ROAMING_CLEANUP_NEVER,
	REG_ROAMING_CLEANUP_EVERY_NDAYS,
	REG_ROAMING_CLEANUP_AT_SHUTDOWN,
	REG_ROAMING_CLEANUP_PROMPT
}
public enum _REG_ROAMCLEANUP
{
	REG_ROAMING_CLEANUP_NEVER,
	REG_ROAMING_CLEANUP_EVERY_NDAYS,
	REG_ROAMING_CLEANUP_AT_SHUTDOWN,
	REG_ROAMING_CLEANUP_PROMPT
}
[ComImport]
[TypeLibType(4160)]
[Guid("29131576-2EED-1069-BF5D-00DD011186B7")]
public interface IRichTextParagraphStyle
{
	[ComAliasName("Domino.RT_ALIGN")]
	[DispId(1610743808)]
	RT_ALIGN Alignment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: ComAliasName("Domino.RT_ALIGN")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: ComAliasName("Domino.RT_ALIGN")]
		set;
	}

	[DispId(1610743810)]
	int FirstLineLeftMargin
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[ComAliasName("Domino.SPACING")]
	[DispId(1610743812)]
	SPACING InterLineSpacing
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: ComAliasName("Domino.SPACING")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		[param: ComAliasName("Domino.SPACING")]
		set;
	}

	[DispId(1610743814)]
	int LeftMargin
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		set;
	}

	[DispId(1610743816)]
	[ComAliasName("Domino.RT_PAGINATE")]
	RT_PAGINATE Pagination
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[return: ComAliasName("Domino.RT_PAGINATE")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[param: In]
		[param: ComAliasName("Domino.RT_PAGINATE")]
		set;
	}

	[DispId(1610743818)]
	int RightMargin
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[param: In]
		set;
	}

	[DispId(1610743820)]
	[ComAliasName("Domino.SPACING")]
	SPACING SpacingAbove
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[return: ComAliasName("Domino.SPACING")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[param: In]
		[param: ComAliasName("Domino.SPACING")]
		set;
	}

	[DispId(1610743822)]
	[ComAliasName("Domino.SPACING")]
	SPACING SpacingBelow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[return: ComAliasName("Domino.SPACING")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[param: In]
		[param: ComAliasName("Domino.SPACING")]
		set;
	}

	[DispId(1610743824)]
	object Tabs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	void ClearAllTabs();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743826)]
	void SetTab([In] int lPosition, [In][ComAliasName("Domino.RT_TAB")] RT_TAB lType = RT_TAB.TAB_LEFT);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743827)]
	void SetTabs([In] int lCount, [In] int lPosition, [In] int lInterval = 1, [In][ComAliasName("Domino.RT_TAB")] RT_TAB lType = RT_TAB.TAB_LEFT);
}
public enum RT_ALIGN
{
	ALIGN_LEFT = 0,
	ALIGN_RIGHT = 1,
	ALIGN_CENTER = 3,
	ALIGN_FULL = 2,
	ALIGN_NOWRAP = 4
}
public enum _RT_ALIGN
{
	ALIGN_LEFT = 0,
	ALIGN_RIGHT = 1,
	ALIGN_CENTER = 3,
	ALIGN_FULL = 2,
	ALIGN_NOWRAP = 4
}
public enum RT_PAGINATE
{
	PAGINATE_DEFAULT = 0,
	PAGINATE_BEFORE = 1,
	PAGINATE_KEEP_WITH_NEXT = 2,
	PAGINATE_KEEP_TOGETHER = 4
}
public enum _RT_PAGINATE
{
	PAGINATE_DEFAULT = 0,
	PAGINATE_BEFORE = 1,
	PAGINATE_KEEP_WITH_NEXT = 2,
	PAGINATE_KEEP_TOGETHER = 4
}
public enum RT_TAB
{
	TAB_LEFT,
	TAB_RIGHT,
	TAB_DECIMAL,
	TAB_CENTER
}
public enum _RT_TAB
{
	TAB_LEFT,
	TAB_RIGHT,
	TAB_DECIMAL,
	TAB_CENTER
}
[ComImport]
[Guid("29131575-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(4160)]
public interface IRichTextStyle
{
	[DispId(1610743808)]
	int Bold
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		set;
	}

	[ComAliasName("Domino.RT_EFFECTS")]
	[DispId(1610743810)]
	RT_EFFECTS Effects
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: ComAliasName("Domino.RT_EFFECTS")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		[param: ComAliasName("Domino.RT_EFFECTS")]
		set;
	}

	[DispId(1610743812)]
	int FontSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		set;
	}

	[DispId(1610743814)]
	int Italic
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		set;
	}

	[DispId(1610743816)]
	[ComAliasName("Domino.COLORS")]
	COLORS NotesColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[return: ComAliasName("Domino.COLORS")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[param: In]
		[param: ComAliasName("Domino.COLORS")]
		set;
	}

	[ComAliasName("Domino.RT_FONTS")]
	[DispId(1610743818)]
	RT_FONTS NotesFont
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[return: ComAliasName("Domino.RT_FONTS")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[param: In]
		[param: ComAliasName("Domino.RT_FONTS")]
		set;
	}

	[DispId(1610743820)]
	int PassThruHTML
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[param: In]
		set;
	}

	[DispId(1610743822)]
	int StrikeThrough
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[param: In]
		set;
	}

	[DispId(1610743824)]
	int Underline
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[param: In]
		set;
	}

	[DispId(1610743826)]
	NotesSession Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743827)]
	bool IsDefault
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		get;
	}
}
public enum RT_EFFECTS
{
	EFFECTS_NONE,
	EFFECTS_SUPERSCRIPT,
	EFFECTS_SUBSCRIPT,
	EFFECTS_SHADOW,
	EFFECTS_EMBOSS,
	EFFECTS_EXTRUDE
}
public enum _RT_EFFECTS
{
	EFFECTS_NONE,
	EFFECTS_SUPERSCRIPT,
	EFFECTS_SUBSCRIPT,
	EFFECTS_SHADOW,
	EFFECTS_EMBOSS,
	EFFECTS_EXTRUDE
}
public enum RT_FONTS
{
	FONT_ROMAN = 0,
	FONT_HELV = 1,
	FONT_COURIER = 4
}
public enum _RT_FONTS
{
	FONT_ROMAN = 0,
	FONT_HELV = 1,
	FONT_COURIER = 4
}
[ComImport]
[TypeLibType(4160)]
[Guid("29131566-2EED-1069-BF5D-00DD011186B7")]
[DefaultMember("Name")]
public interface IDbDirectory
{
	[DispId(0)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	NotesSession Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743810)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDatabase CreateDatabase([In][MarshalAs(UnmanagedType.BStr)] string pDbfile, [In] bool bOpen = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743811)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDatabase GetFirstDatabase([In][ComAliasName("Domino.DB_TYPES")] DB_TYPES lFiletype);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743812)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDatabase GetNextDatabase();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743813)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDatabase OpenDatabase([In][MarshalAs(UnmanagedType.BStr)] string pDbfile, [In] bool bFailover = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743814)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDatabase OpenDatabaseIfModified([In][MarshalAs(UnmanagedType.BStr)] string pDbfile, [In][MarshalAs(UnmanagedType.Interface)] NotesDateTime pITime);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDatabase OpenMailDatabase();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesDatabase OpenDatabaseByReplicaID([In][MarshalAs(UnmanagedType.BStr)] string pRid);
}
public enum DB_TYPES
{
	REPLICA_CANDIDATE = 1245,
	TEMPLATE_CANDIDATE = 1246,
	DATABASE = 1247,
	NOTES_DATABASE = 1247,
	TEMPLATE = 1248
}
public enum _DB_TYPES
{
	REPLICA_CANDIDATE = 1245,
	TEMPLATE_CANDIDATE = 1246,
	DATABASE = 1247,
	NOTES_DATABASE = 1247,
	TEMPLATE = 1248
}
[ComImport]
[TypeLibType(4160)]
[Guid("29131581-2EED-1069-BF5D-00DD011186B7")]
public interface IAdministrationProcess
{
	[DispId(1610743808)]
	string CertificateAuthorityOrg
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743810)]
	string CertifierFile
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743812)]
	string CertifierPassword
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743814)]
	bool IsCertificateAuthorityAvailable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
	}

	[DispId(1610743815)]
	bool UseCertificateAuthority
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[param: In]
		set;
	}

	[DispId(1610743817)]
	NotesDateTime CertificateExpiration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743819)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string AddGroupMembers([In][MarshalAs(UnmanagedType.BStr)] string pGroup, [In][MarshalAs(UnmanagedType.Struct)] object Members);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743820)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string AddInternetCertificateToUser([In][MarshalAs(UnmanagedType.BStr)] string pUser, [In][MarshalAs(UnmanagedType.BStr)] string pKeyRingFile, [In][MarshalAs(UnmanagedType.BStr)] string pKeyRingPassword, [In][MarshalAs(UnmanagedType.Interface)] NotesDateTime Expiration = null);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string AddServerToCluster([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pCluster);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743822)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string ApproveDeletePersonInDirectory([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743823)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string ApproveDeleteServerInDirectory([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string ApproveDesignElementDeletion([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string ApproveMailFileDeletion([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743826)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string ApproveMovedReplicaDeletion([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743827)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string ApproveNameChangeRetraction([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743828)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string ApproveRenamePersonInDirectory([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743829)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string ApproveRenameServerInDirectory([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743830)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string ApproveReplicaDeletion([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743831)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string ApproveResourceDeletion([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743832)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string ChangeHTTPPassword([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In][MarshalAs(UnmanagedType.BStr)] string pOldPassword, [In][MarshalAs(UnmanagedType.BStr)] string pNewPassword);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743833)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string ConfigureMailAgent([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In][MarshalAs(UnmanagedType.BStr)] string pAgentName, [In] bool bActivatable = true, [In] bool bEnable = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743834)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string CreateReplica([In][MarshalAs(UnmanagedType.BStr)] string pSourceServer, [In][MarshalAs(UnmanagedType.BStr)] string pSourceDBFile, [In][MarshalAs(UnmanagedType.BStr)] string pDestServer, [In][MarshalAs(UnmanagedType.BStr)] string pDestDBFile = "", [In] bool bCopyACL = true, [In] bool bCreateFTIndex = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743835)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string MoveReplica([In][MarshalAs(UnmanagedType.BStr)] string pSourceServer, [In][MarshalAs(UnmanagedType.BStr)] string pSourceDBFile, [In][MarshalAs(UnmanagedType.BStr)] string pDestServer, [In][MarshalAs(UnmanagedType.BStr)] string pDestDBFile = "", [In] bool bCopyACL = true, [In] bool bCreateFTIndex = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743836)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string DeleteReplicas([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pDbfile);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743837)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string DeleteGroup([In][MarshalAs(UnmanagedType.BStr)] string pGroupName, [In] bool bImmediate, [In] bool bDeleteWindowsGroup = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743838)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string DeleteServer([In][MarshalAs(UnmanagedType.BStr)] string pServerName, [In] bool bImmediate);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743839)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string DeleteUser([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In] bool bImmediate, [In][ComAliasName("Domino.ADMP_MAILDEL")] ADMP_MAILDEL lMailFileAction, [In][MarshalAs(UnmanagedType.BStr)] string pDenyGroup, [In] bool bDeleteWindowsGroup = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743840)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string FindGroupInDomain([In][MarshalAs(UnmanagedType.BStr)] string pGroup);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743841)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string FindServerInDomain([In][MarshalAs(UnmanagedType.BStr)] string pServer);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743842)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string FindUserInDomain([In][MarshalAs(UnmanagedType.BStr)] string pUser);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743843)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string MoveMailUser([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In][MarshalAs(UnmanagedType.BStr)] string pNewHomeServer, [In][MarshalAs(UnmanagedType.BStr)] string pNewHomeServerMailPath, [In] bool bUseSCOS = false, [In][MarshalAs(UnmanagedType.Struct)] object NewClusterReplicaArray = 0, [In] bool bDeleteOldClusterReplicas = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743844)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string MoveRoamingUser([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In][MarshalAs(UnmanagedType.BStr)] string pDestServer, [In][MarshalAs(UnmanagedType.BStr)] string pDestServerPath);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743845)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string MoveUserInHierarchyRequest([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In][MarshalAs(UnmanagedType.BStr)] string pTargetCertifier, [In] bool bAllowPrimaryNameChange = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743846)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string MoveUserInHierarchyComplete([In][MarshalAs(UnmanagedType.BStr)] string pRequestNoteID, [In][MarshalAs(UnmanagedType.BStr)] string pLastName = "*", [In][MarshalAs(UnmanagedType.BStr)] string pFirstName = "*", [In][MarshalAs(UnmanagedType.BStr)] string pMiddleInitial = "*", [In][MarshalAs(UnmanagedType.BStr)] string pOrgUnit = "*", [In][MarshalAs(UnmanagedType.BStr)] string pAltCommonName = "*", [In][MarshalAs(UnmanagedType.BStr)] string pAltOrgUnit = "*", [In][MarshalAs(UnmanagedType.BStr)] string pAltLanguage = "*", [In] bool bRenameWindowsUser = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743847)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string RecertifyServer([In][MarshalAs(UnmanagedType.BStr)] string pServer);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743848)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string RecertifyUser([In][MarshalAs(UnmanagedType.BStr)] string pUsername);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743849)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string RemoveServerFromCluster([In][MarshalAs(UnmanagedType.BStr)] string pServer);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743850)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string RenameGroup([In][MarshalAs(UnmanagedType.BStr)] string pGroup, [In][MarshalAs(UnmanagedType.BStr)] string pNewGroup);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743851)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string RenameNotesUser([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In][MarshalAs(UnmanagedType.BStr)] string pLastName = "*", [In][MarshalAs(UnmanagedType.BStr)] string pFirstName = "*", [In][MarshalAs(UnmanagedType.BStr)] string pMiddleInitial = "*", [In][MarshalAs(UnmanagedType.BStr)] string pOrgUnit = "*", [In][MarshalAs(UnmanagedType.BStr)] string pAltCommonName = "*", [In][MarshalAs(UnmanagedType.BStr)] string pAltOrgUnit = "*", [In][MarshalAs(UnmanagedType.BStr)] string pAltLanguage = "*", [In] bool bRenameWindowsUser = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743852)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string RenameWebUser([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In][MarshalAs(UnmanagedType.BStr)] string pNewUserName, [In][MarshalAs(UnmanagedType.BStr)] string pNewLastName = "*", [In][MarshalAs(UnmanagedType.BStr)] string pNewFirstName = "*", [In][MarshalAs(UnmanagedType.BStr)] string pNewMiddleInitial = "*", [In][MarshalAs(UnmanagedType.BStr)] string pNewShortname = "*", [In][MarshalAs(UnmanagedType.BStr)] string pNewInternetAddress = "*");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743853)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string SetServerDirectoryAssistanceSettings([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pDbfile);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743854)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string SignDatabaseWithServerID([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pDbfile, [In] bool bUpdateOnly = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743855)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string UpgradeUserToHierarchical([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In][MarshalAs(UnmanagedType.BStr)] string pOrgUnit = "", [In][MarshalAs(UnmanagedType.BStr)] string pAltCommonName = "", [In][MarshalAs(UnmanagedType.BStr)] string pAltOrgUnit = "", [In][MarshalAs(UnmanagedType.BStr)] string pAltLanguage = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743856)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string SetUserPasswordSettings([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In][MarshalAs(UnmanagedType.Struct)] object NotesPasswordCheckSetting = "nochange", [In][MarshalAs(UnmanagedType.Struct)] object NotesPasswordChangeInterval = "nochange", [In][MarshalAs(UnmanagedType.Struct)] object NotesPasswordGracePeriod = "nochange", [In][MarshalAs(UnmanagedType.Struct)] object InternetPasswordForceChange = "nochange", [In][ComAliasName("Domino.ADMP_PWDCHK")] ADMP_PWDCHK NotUsed = ADMP_PWDCHK.PWD_CHK_DONTCHECKPASSWORD);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743857)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string ApproveHostedOrgStorageDeletion([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);
}
public enum ADMP_MAILDEL
{
	MAILDELNONE,
	MAILDELHOME,
	MAILDELALL
}
public enum _ADMP_MAILDEL
{
	MAILDELNONE,
	MAILDELHOME,
	MAILDELALL
}
public enum ADMP_PWDCHK
{
	PWD_CHK_DONTCHECKPASSWORD,
	PWD_CHK_CHECKPASSWORD,
	PWD_CHK_LOCKOUT
}
public enum _ADMP_PWDCHK
{
	PWD_CHK_DONTCHECKPASSWORD,
	PWD_CHK_CHECKPASSWORD,
	PWD_CHK_LOCKOUT
}
[ComImport]
[TypeLibType(4160)]
[Guid("29131580-2EED-1069-BF5D-00DD011186B7")]
public interface INotesStream
{
	[DispId(1610743808)]
	string Charset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	bool IsEOS
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		get;
	}

	[DispId(1610743810)]
	int Position
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	int Bytes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
	}

	[DispId(1610743813)]
	bool IsReadOnly
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		get;
	}

	[DispId(1610743814)]
	NotesSession Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	void Close();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	bool Open([In][MarshalAs(UnmanagedType.BStr)] string pName, [In][MarshalAs(UnmanagedType.BStr)] string pCharset = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743817)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object Read([In] int lLength = -1);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743818)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string ReadText([In][ComAliasName("Domino.STMREAD_LEN")] STMREAD_LEN lLength = (STMREAD_LEN)(-1), [In][ComAliasName("Domino.EOL_TYPE")] EOL_TYPE lEOL = EOL_TYPE.EOL_CRLF);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743819)]
	void Truncate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743820)]
	int Write([In][MarshalAs(UnmanagedType.Struct)] object vByteArray);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	int WriteText([In][MarshalAs(UnmanagedType.BStr)] string pText, [In][ComAliasName("Domino.EOL_TYPE")] EOL_TYPE lEOL = EOL_TYPE.EOL_NONE);
}
public enum STMREAD_LEN
{
	STMREAD_LINE
}
public enum _STMREAD_LEN
{
	STMREAD_LINE
}
public enum EOL_TYPE
{
	EOL_CRLF,
	EOL_LF,
	EOL_CR,
	EOL_PLATFORM,
	EOL_ANY,
	EOL_NONE
}
public enum _EOL_TYPE
{
	EOL_CRLF,
	EOL_LF,
	EOL_CR,
	EOL_PLATFORM,
	EOL_ANY,
	EOL_NONE
}
[ComImport]
[TypeLibType(4160)]
[Guid("29131583-2EED-1069-BF5D-00DD011186B7")]
public interface IColorObject
{
	[DispId(1610743808)]
	int Red
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
	}

	[DispId(1610743809)]
	int Green
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		get;
	}

	[DispId(1610743810)]
	int Blue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
	}

	[DispId(1610743811)]
	int Hue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		get;
	}

	[DispId(1610743812)]
	int Saturation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
	}

	[DispId(1610743813)]
	int Luminance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		get;
	}

	[DispId(1610743814)]
	int NotesColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	int SetRGB([In] int Red, [In] int Green, [In] int Blue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	int SetHSL([In] int Hue, [In] int Saturation, [In] int Luminance);
}
[ComImport]
[Guid("29131590-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(4160)]
public interface IDXLExporter
{
	[DispId(1610743808)]
	string Log
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	string LogComment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743811)]
	bool ExitOnFirstFatalError
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[param: In]
		set;
	}

	[DispId(1610743813)]
	bool ForceNoteFormat
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[param: In]
		set;
	}

	[DispId(1610743815)]
	bool OutputDOCTYPE
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[param: In]
		set;
	}

	[DispId(1610743817)]
	string DoctypeSYSTEM
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743819)]
	bool ConvertNotesbitmapsToGIF
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string Export([In][MarshalAs(UnmanagedType.Struct)] object Input);
}
[ComImport]
[Guid("29131591-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(4160)]
public interface IDXLImporter
{
	[DispId(1610743808)]
	string Log
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	string LogComment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743811)]
	bool ExitOnFirstFatalError
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[param: In]
		set;
	}

	[ComAliasName("Domino.DXLIMPORTOPTION")]
	[DispId(1610743813)]
	DXLIMPORTOPTION ACLImportOption
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[return: ComAliasName("Domino.DXLIMPORTOPTION")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[param: In]
		[param: ComAliasName("Domino.DXLIMPORTOPTION")]
		set;
	}

	[ComAliasName("Domino.DXLIMPORTOPTION")]
	[DispId(1610743815)]
	DXLIMPORTOPTION DesignImportOption
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[return: ComAliasName("Domino.DXLIMPORTOPTION")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[param: In]
		[param: ComAliasName("Domino.DXLIMPORTOPTION")]
		set;
	}

	[ComAliasName("Domino.DXLIMPORTOPTION")]
	[DispId(1610743817)]
	DXLIMPORTOPTION DocumentImportOption
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[return: ComAliasName("Domino.DXLIMPORTOPTION")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[param: In]
		[param: ComAliasName("Domino.DXLIMPORTOPTION")]
		set;
	}

	[DispId(1610743819)]
	bool ReplaceDBProperties
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		[param: In]
		set;
	}

	[ComAliasName("Domino.VALIDATIONOPTION")]
	[DispId(1610743821)]
	VALIDATIONOPTION InputValidationOption
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[return: ComAliasName("Domino.VALIDATIONOPTION")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[param: In]
		[param: ComAliasName("Domino.VALIDATIONOPTION")]
		set;
	}

	[DispId(1610743823)]
	bool CreateFTIndex
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		[param: In]
		set;
	}

	[DispId(1610743825)]
	int ImportedNoteCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		get;
	}

	[DispId(1610743826)]
	bool ReplicaRequiredForReplaceOrUpdate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[param: In]
		set;
	}

	[DispId(1610743828)]
	[ComAliasName("Domino.DXLLOGOPTION")]
	DXLLOGOPTION UnknownTokenLogOption
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		[return: ComAliasName("Domino.DXLLOGOPTION")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		[param: In]
		[param: ComAliasName("Domino.DXLLOGOPTION")]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743830)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetFirstImportedNoteId();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743831)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetNextImportedNoteId([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743832)]
	void Import([In][MarshalAs(UnmanagedType.Struct)] object Input, [In][MarshalAs(UnmanagedType.Struct)] object importDB);
}
public enum DXLIMPORTOPTION
{
	DXLIMPORTOPTION_IGNORE = 1,
	DXLIMPORTOPTION_CREATE = 2,
	DXLIMPORTOPTION_REPLACE_ELSE_IGNORE = 5,
	DXLIMPORTOPTION_REPLACE_ELSE_CREATE = 6,
	DXLIMPORTOPTION_UPDATE_ELSE_IGNORE = 9,
	DXLIMPORTOPTION_UPDATE_ELSE_CREATE = 10
}
public enum _DXLIMPORTOPTION
{
	DXLIMPORTOPTION_IGNORE = 1,
	DXLIMPORTOPTION_CREATE = 2,
	DXLIMPORTOPTION_REPLACE_ELSE_IGNORE = 5,
	DXLIMPORTOPTION_REPLACE_ELSE_CREATE = 6,
	DXLIMPORTOPTION_UPDATE_ELSE_IGNORE = 9,
	DXLIMPORTOPTION_UPDATE_ELSE_CREATE = 10
}
public enum VALIDATIONOPTION
{
	VALIDATE_NEVER,
	VALIDATE_ALWAYS,
	VALIDATE_AUTO
}
public enum _VALIDATIONOPTION
{
	VALIDATE_NEVER,
	VALIDATE_ALWAYS,
	VALIDATE_AUTO
}
public enum DXLLOGOPTION
{
	DXLLOGOPTION_IGNORE = 1,
	DXLLOGOPTION_WARNING,
	DXLLOGOPTION_ERROR,
	DXLLOGOPTION_FATALERROR
}
public enum _DXLLOGOPTION
{
	DXLLOGOPTION_IGNORE = 1,
	DXLLOGOPTION_WARNING,
	DXLLOGOPTION_ERROR,
	DXLLOGOPTION_FATALERROR
}
public enum SESS_POLICY
{
	POLICYSETTINGS_ARCHIVE = 2,
	POLICYSETTINGS_DESKTOP = 4,
	POLICYSETTINGS_REGISTRATION = 0,
	POLICYSETTINGS_SECURITY = 3,
	POLICYSETTINGS_SETUP = 1,
	POLICYSETTINGS_MAIL = 5
}
public enum _SESS_POLICY
{
	POLICYSETTINGS_ARCHIVE = 2,
	POLICYSETTINGS_DESKTOP = 4,
	POLICYSETTINGS_REGISTRATION = 0,
	POLICYSETTINGS_SECURITY = 3,
	POLICYSETTINGS_SETUP = 1,
	POLICYSETTINGS_MAIL = 5
}
public enum IT_TYPE
{
	ERRORITEM = 256,
	UNAVAILABLE = 512,
	Text = 1280,
	NUMBERS = 768,
	DATETIMES = 1024,
	Names = 1074,
	Readers = 1075,
	Authors = 1076,
	RICHTEXT = 1,
	USERID = 1792,
	Formula = 1536,
	COLLATION = 2,
	NOTEREFS = 4,
	NOTELINKS = 7,
	ATTACHMENT = 1084,
	OTHEROBJECT = 1085,
	UNKNOWN = 0,
	ICON = 6,
	SIGNATURE = 8,
	USERDATA = 14,
	EMBEDDEDOBJECT = 1090,
	QUERYCD = 15,
	ACTIONCD = 16,
	ASSISTANTINFO = 17,
	VIEWMAPDATA = 18,
	VIEWMAPLAYOUT = 19,
	LSOBJECT = 20,
	HTML = 21,
	MIME_PART = 25,
	RFC822TEXT = 1282
}
public enum _IT_TYPE
{
	ERRORITEM = 256,
	UNAVAILABLE = 512,
	Text = 1280,
	NUMBERS = 768,
	DATETIMES = 1024,
	Names = 1074,
	Readers = 1075,
	Authors = 1076,
	RICHTEXT = 1,
	USERID = 1792,
	Formula = 1536,
	COLLATION = 2,
	NOTEREFS = 4,
	NOTELINKS = 7,
	ATTACHMENT = 1084,
	OTHEROBJECT = 1085,
	UNKNOWN = 0,
	ICON = 6,
	SIGNATURE = 8,
	USERDATA = 14,
	EMBEDDEDOBJECT = 1090,
	QUERYCD = 15,
	ACTIONCD = 16,
	ASSISTANTINFO = 17,
	VIEWMAPDATA = 18,
	VIEWMAPLAYOUT = 19,
	LSOBJECT = 20,
	HTML = 21,
	MIME_PART = 25,
	RFC822TEXT = 1282
}
[ComImport]
[Guid("2913157E-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(4160)]
public interface IMIMEEntity
{
	[DispId(1610743808)]
	string ContentSubType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	string ContentType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743810)]
	string ContentAsText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743811)]
	string Headers
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743812)]
	NotesDocument ParentDoc
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743813)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesMIMEEntity GetFirstChildEntity();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743814)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesMIMEEntity GetNextSibling();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesMIMEEntity GetParentEntity();

	[DispId(1610743816)]
	string BoundaryStart
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743817)]
	string BoundaryEnd
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743818)]
	string Charset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743819)]
	[ComAliasName("Domino.MIME_ENCODING")]
	MIME_ENCODING Encoding
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		[return: ComAliasName("Domino.MIME_ENCODING")]
		get;
	}

	[DispId(1610743820)]
	object HeaderObjects
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743821)]
	string Preamble
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743823)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesMIMEEntity CreateChildEntity([In][MarshalAs(UnmanagedType.Interface)] NotesMIMEEntity pNextSiblingIMIMEEntity = null);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesMIMEHeader CreateHeader([In][MarshalAs(UnmanagedType.BStr)] string pHeaderName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesMIMEEntity CreateParentEntity();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743826)]
	void DecodeContent();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743827)]
	void EncodeContent([In][ComAliasName("Domino.MIME_ENCODING")] MIME_ENCODING lEnc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743828)]
	void GetContentAsBytes([In][MarshalAs(UnmanagedType.Interface)] NotesStream pINotesStream, [In] bool bDecoded = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743829)]
	void GetContentAsText([In][MarshalAs(UnmanagedType.Interface)] NotesStream pINotesStream, [In] bool bDecoded = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743830)]
	void GetEntityAsText([In][MarshalAs(UnmanagedType.Interface)] NotesStream pINotesStream, [Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pHeaderFilters, [In] bool bInclusive = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743831)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesMIMEEntity GetNextEntity([In][ComAliasName("Domino.SEARCH_PATH")] SEARCH_PATH lSearchPath = SEARCH_PATH.SEARCH_DEPTH);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743832)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesMIMEHeader GetNthHeader([In][MarshalAs(UnmanagedType.BStr)] string pHeaderName, [In] int lNth = 1);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743833)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesMIMEEntity GetPrevEntity([In][ComAliasName("Domino.SEARCH_PATH")] SEARCH_PATH lSearchPath = SEARCH_PATH.SEARCH_DEPTH);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743834)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesMIMEEntity GetPrevSibling();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743835)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetSomeHeaders([Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pHeaderFilters, [In] bool bInclusive = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743836)]
	void Remove();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743837)]
	void SetContentFromBytes([In][MarshalAs(UnmanagedType.Interface)] NotesStream pINotesStream, [In][MarshalAs(UnmanagedType.BStr)] string pContentType, [In][ComAliasName("Domino.MIME_ENCODING")] MIME_ENCODING lEnc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743838)]
	void SetContentFromText([In][MarshalAs(UnmanagedType.Interface)] NotesStream pINotesStream, [In][MarshalAs(UnmanagedType.BStr)] string pContentType, [In][ComAliasName("Domino.MIME_ENCODING")] MIME_ENCODING lEnc);
}
public enum MIME_ENCODING
{
	ENC_NONE = 1725,
	ENC_QUOTED_PRINTABLE,
	ENC_BASE64,
	ENC_IDENTITY_7BIT,
	ENC_IDENTITY_8BIT,
	ENC_IDENTITY_BINARY,
	ENC_EXTENSION
}
public enum _MIME_ENCODING
{
	ENC_NONE = 1725,
	ENC_QUOTED_PRINTABLE,
	ENC_BASE64,
	ENC_IDENTITY_7BIT,
	ENC_IDENTITY_8BIT,
	ENC_IDENTITY_BINARY,
	ENC_EXTENSION
}
[ComImport]
[Guid("2913157F-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(4160)]
public interface IMIMEHeader
{
	[DispId(1610743808)]
	string HeaderName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	NotesMIMEEntity Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743810)]
	bool AddValText([In][MarshalAs(UnmanagedType.BStr)] string pValueText, [In][MarshalAs(UnmanagedType.BStr)] string pRfc2047Charset = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743811)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetHeaderVal([In] bool bFolded = false, [In] bool bDecoded = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743812)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetHeaderValAndParams([In] bool bFolded = false, [In] bool bDecoded = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743813)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetParamVal([In][MarshalAs(UnmanagedType.BStr)] string pParamName, [In] bool bFolded = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743814)]
	void Remove();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	bool SetHeaderVal([In][MarshalAs(UnmanagedType.BStr)] string pHeaderVal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	bool SetHeaderValAndParams([In][MarshalAs(UnmanagedType.BStr)] string pHeaderValParams);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743817)]
	bool SetParamVal([In][MarshalAs(UnmanagedType.BStr)] string pParamName, [In][MarshalAs(UnmanagedType.BStr)] string pParamVal);
}
public enum SEARCH_PATH
{
	SEARCH_DEPTH = 1723,
	SEARCH_BREADTH
}
public enum _SEARCH_PATH
{
	SEARCH_DEPTH = 1723,
	SEARCH_BREADTH
}
[ComImport]
[TypeLibType(4160)]
[DefaultMember("Name")]
[Guid("29131574-2EED-1069-BF5D-00DD011186B7")]
public interface IRichTextItem : IItem
{
	[DispId(1610743808)]
	new NotesDateTime DateTimeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1610743810)]
	new bool IsAuthors
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	new bool IsEncrypted
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		set;
	}

	[DispId(1610743814)]
	new bool IsNames
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		set;
	}

	[DispId(1610743816)]
	new bool IsProtected
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[param: In]
		set;
	}

	[DispId(1610743818)]
	new bool IsReaders
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[param: In]
		set;
	}

	[DispId(1610743820)]
	new bool IsSigned
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[param: In]
		set;
	}

	[DispId(1610743822)]
	new bool IsSummary
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[param: In]
		set;
	}

	[DispId(1610743824)]
	new object LastModified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(0)]
	new string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743826)]
	new NotesDocument Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743827)]
	new bool SaveToDisk
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		[param: In]
		set;
	}

	[DispId(1610743829)]
	new string Text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743830)]
	[ComAliasName("Domino.IT_TYPE")]
	new IT_TYPE type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		[return: ComAliasName("Domino.IT_TYPE")]
		get;
	}

	[DispId(1610743831)]
	new int ValueLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743831)]
		get;
	}

	[DispId(1610743832)]
	new object Values
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743834)]
	[return: MarshalAs(UnmanagedType.BStr)]
	new string Abstract([In] int lMaxlen, [In] bool bDropvowels, [In] bool bUsedict);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743835)]
	new void AppendToTextList([In][MarshalAs(UnmanagedType.Struct)] object Values);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743836)]
	new bool Contains([In][MarshalAs(UnmanagedType.Struct)] object Value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743837)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new NotesItem CopyItemToDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pIDoc, [In][MarshalAs(UnmanagedType.BStr)] string pNewname);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743838)]
	[return: MarshalAs(UnmanagedType.Interface)]
	new NotesMIMEEntity GetMIMEEntity();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743839)]
	new void Remove();

	[DispId(1610809344)]
	object EmbeddedObjects
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610809344)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809345)]
	void AddNewLine([In] int lCount = 1, [In] bool bNewparagraph = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809346)]
	void AddPageBreak([In][MarshalAs(UnmanagedType.Interface)] NotesRichTextParagraphStyle pIStyle);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809347)]
	void AddTab([In] int lCount = 1);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809348)]
	void AppendDocLink([In][MarshalAs(UnmanagedType.IUnknown)] object pIObj, [In][MarshalAs(UnmanagedType.BStr)] string pComment, [In][MarshalAs(UnmanagedType.BStr)] string pHotspottext = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809349)]
	void AppendParagraphStyle([In][MarshalAs(UnmanagedType.Interface)] NotesRichTextParagraphStyle pIStyle);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809350)]
	void AppendRTItem([In][MarshalAs(UnmanagedType.Interface)] NotesRichTextItem pIRTItem);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809351)]
	void AppendStyle([In][MarshalAs(UnmanagedType.Interface)] NotesRichTextStyle pIStyle);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809352)]
	void AppendText([In][MarshalAs(UnmanagedType.BStr)] string pText);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809353)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesEmbeddedObject EmbedObject([In][ComAliasName("Domino.EMBED_TYPE")] EMBED_TYPE lType, [In][MarshalAs(UnmanagedType.BStr)] string pClass, [In][MarshalAs(UnmanagedType.BStr)] string pSource, [In][MarshalAs(UnmanagedType.BStr)] string pName = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809354)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesEmbeddedObject GetEmbeddedObject([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809355)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetFormattedText([In] bool bTabstrip, [In] int lLinelen);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809356)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesRichTextNavigator CreateNavigator();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809357)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesRichTextRange CreateRange();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809358)]
	void AppendTable([In] int lRowCount = 0, [In] int lColumnCount = 0, [Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pRowLabels, [In] int lLeftMargin = 1440, [Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pRTPStyleArray);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809359)]
	void BeginInsert([In][MarshalAs(UnmanagedType.Struct)] ref object pElement, [In] bool bAfter = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809360)]
	void EndInsert();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809361)]
	void BeginSection([In][MarshalAs(UnmanagedType.BStr)] string pTitle, [In][MarshalAs(UnmanagedType.Interface)] NotesRichTextStyle pTitleStyle = null, [In][MarshalAs(UnmanagedType.Interface)] NotesColorObject pBarColor = null, [In] bool bExpand = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809362)]
	void EndSection();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809363)]
	int GetNotesFont([In][MarshalAs(UnmanagedType.BStr)] string pFaceName, [In] bool bAddOnFail = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809364)]
	void Update();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809365)]
	void Compact();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809366)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetUnformattedText();
}
public enum EMBED_TYPE
{
	EMBED_OBJECTLINK = 1452,
	EMBED_OBJECT,
	EMBED_ATTACHMENT
}
public enum _EMBED_TYPE
{
	EMBED_OBJECTLINK = 1452,
	EMBED_OBJECT,
	EMBED_ATTACHMENT
}
[ComImport]
[Guid("29131569-2EED-1069-BF5D-00DD011186B7")]
[DefaultMember("Name")]
[TypeLibType(4160)]
public interface IEmbeddedObject
{
	[DispId(1610743808)]
	string Class
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	int FileSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		get;
	}

	[DispId(1610743810)]
	bool FitBelowFields
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	bool FitToWindow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		set;
	}

	[DispId(0)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743815)]
	object Object
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743816)]
	NotesRichTextItem Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743817)]
	bool RunReadOnly
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[param: In]
		set;
	}

	[DispId(1610743819)]
	string Source
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("Domino.EMBED_TYPE")]
	[DispId(1610743820)]
	EMBED_TYPE type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[return: ComAliasName("Domino.EMBED_TYPE")]
		get;
	}

	[DispId(1610743821)]
	object Verbs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743822)]
	[return: MarshalAs(UnmanagedType.IDispatch)]
	object Activate([In] bool bShow);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743823)]
	void DoVerb([In][MarshalAs(UnmanagedType.BStr)] string pVerb);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	void ExtractFile([In][MarshalAs(UnmanagedType.BStr)] string pPath);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	void Remove();
}
[ComImport]
[Guid("29131584-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(4160)]
public interface IRichTextNavigator
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743808)]
	bool FindNthElement([In][ComAliasName("Domino.RT_ELEM")] RT_ELEM lType, [In] int lOccurrence = 1);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743809)]
	bool FindFirstElement([In][ComAliasName("Domino.RT_ELEM")] RT_ELEM lType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743810)]
	bool FindNextElement([In][ComAliasName("Domino.RT_ELEM")] RT_ELEM lType = (RT_ELEM)65535, [In] int lOccurrence = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743811)]
	bool FindLastElement([In][ComAliasName("Domino.RT_ELEM")] RT_ELEM lType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743812)]
	bool FindFirstString([In][MarshalAs(UnmanagedType.BStr)] string pTarget, [In] int lOptions = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743813)]
	bool FindNextString([In][MarshalAs(UnmanagedType.BStr)] string pTarget, [In] int lOptions = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743814)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object GetElement();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object GetFirstElement([In][ComAliasName("Domino.RT_ELEM")] RT_ELEM lType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object GetNextElement([In][ComAliasName("Domino.RT_ELEM")] RT_ELEM lType = (RT_ELEM)65535, [In] int lOccurrence = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743817)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object GetNthElement([In][ComAliasName("Domino.RT_ELEM")] RT_ELEM lType, [In] int lOccurrence = 1);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743818)]
	[return: MarshalAs(UnmanagedType.Struct)]
	object GetLastElement([In][ComAliasName("Domino.RT_ELEM")] RT_ELEM lType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743819)]
	void SetPosition([In][MarshalAs(UnmanagedType.Struct)] object pIRTElement);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743820)]
	void SetPositionAtEnd([In][MarshalAs(UnmanagedType.Struct)] object pIRTElement);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	void SetCharOffset([In] int lOffset);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743822)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesRichTextNavigator Clone();
}
public enum RT_ELEM
{
	RTELEM_TYPE_TABLE = 1,
	RTELEM_TYPE_TEXTRUN = 3,
	RTELEM_TYPE_TEXTPARAGRAPH = 4,
	RTELEM_TYPE_DOCLINK = 5,
	RTELEM_TYPE_SECTION = 6,
	RTELEM_TYPE_TABLECELL = 7,
	RTELEM_TYPE_FILEATTACHMENT = 8,
	RTELEM_TYPE_OLE = 9,
	RTELEM_TYPE_TEXTPOSITION = 10,
	RTELEM_TYPE_TEXTSTRING = 11
}
public enum _RT_ELEM
{
	RTELEM_TYPE_TABLE = 1,
	RTELEM_TYPE_TEXTRUN = 3,
	RTELEM_TYPE_TEXTPARAGRAPH = 4,
	RTELEM_TYPE_DOCLINK = 5,
	RTELEM_TYPE_SECTION = 6,
	RTELEM_TYPE_TABLECELL = 7,
	RTELEM_TYPE_FILEATTACHMENT = 8,
	RTELEM_TYPE_OLE = 9,
	RTELEM_TYPE_TEXTPOSITION = 10,
	RTELEM_TYPE_TEXTSTRING = 11
}
[ComImport]
[Guid("29131585-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(4160)]
public interface IRichTextRange
{
	[ComAliasName("Domino.RT_ELEM")]
	[DispId(1610743808)]
	RT_ELEM type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: ComAliasName("Domino.RT_ELEM")]
		get;
	}

	[DispId(1610743809)]
	string TextRun
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743810)]
	string TextParagraph
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743811)]
	NotesRichTextStyle Style
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743812)]
	NotesRichTextNavigator Navigator
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743813)]
	void SetStyle([In][MarshalAs(UnmanagedType.Interface)] NotesRichTextStyle pIRTStyle);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743814)]
	void SetBegin([In][MarshalAs(UnmanagedType.Struct)] object ppIRTElement);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	void SetEnd([In][MarshalAs(UnmanagedType.Struct)] object ppIRTElement);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	void Reset([In] bool bBegin, [In] bool bEnd);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743817)]
	void Remove();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743818)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesRichTextRange Clone();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743819)]
	int FindandReplace([In][MarshalAs(UnmanagedType.BStr)] string pFindString, [In][MarshalAs(UnmanagedType.BStr)] string pReplString, [In] int lOptions);
}
[ComImport]
[Guid("29131573-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(4160)]
public interface IReplication
{
	[DispId(1610743808)]
	bool Abstract
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		set;
	}

	[DispId(1610743810)]
	object CutoffDate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743811)]
	bool CutoffDelete
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[param: In]
		set;
	}

	[DispId(1610743813)]
	int CutoffInterval
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[param: In]
		set;
	}

	[DispId(1610743815)]
	bool Disabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[param: In]
		set;
	}

	[DispId(1610743817)]
	bool IgnoreDeletes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[param: In]
		set;
	}

	[DispId(1610743819)]
	bool IgnoreDestDeletes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		[param: In]
		set;
	}

	[ComAliasName("Domino.RP_PRIORITY")]
	[DispId(1610743821)]
	RP_PRIORITY Priority
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[return: ComAliasName("Domino.RP_PRIORITY")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[param: In]
		[param: ComAliasName("Domino.RP_PRIORITY")]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743823)]
	void ClearHistory();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	void Save();

	[DispId(1610743826)]
	bool DontSendLocalSecurityUpdates
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743828)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesReplicationEntry GetEntry([In][MarshalAs(UnmanagedType.BStr)] string pSourceServer, [In][MarshalAs(UnmanagedType.BStr)] string pDestinationServer, [In] bool bCreate = false);
}
public enum RP_PRIORITY
{
	DB_REPLICATION_PRIORITY_LOW = 1547,
	DB_REPLICATION_PRIORITY_MED = 1548,
	DB_REPLICATION_PRIORITY_HIGH = 1549,
	DB_REPLICATION_PRIORITY_NOTSET = 1565
}
public enum _RP_PRIORITY
{
	DB_REPLICATION_PRIORITY_LOW = 1547,
	DB_REPLICATION_PRIORITY_MED = 1548,
	DB_REPLICATION_PRIORITY_HIGH = 1549,
	DB_REPLICATION_PRIORITY_NOTSET = 1565
}
[ComImport]
[Guid("29131582-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(4160)]
public interface IReplicationEntry
{
	[DispId(1610743808)]
	string Source
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	string Destination
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743810)]
	string Formula
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743812)]
	string Views
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743814)]
	bool IsIncludeForms
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		set;
	}

	[DispId(1610743816)]
	bool IsIncludeAgents
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[param: In]
		set;
	}

	[DispId(1610743818)]
	bool IsIncludeFormulas
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[param: In]
		set;
	}

	[DispId(1610743820)]
	bool IsIncludeDocuments
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[param: In]
		set;
	}

	[DispId(1610743822)]
	bool IsIncludeACL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	int Remove();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	int Save();
}
[ComImport]
[Guid("29131570-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(4160)]
public interface IOutline
{
	[DispId(1610743808)]
	string Alias
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743810)]
	string Comment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743812)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743814)]
	NotesDatabase ParentDatabase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesOutlineEntry CreateEntry([In][MarshalAs(UnmanagedType.BStr)] string pEntryName, [In][MarshalAs(UnmanagedType.Interface)] NotesOutlineEntry pRefEntry, [In] bool bAfter = true, [In] bool bAsChild = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesOutlineEntry CreateEntryFrom([In][MarshalAs(UnmanagedType.Interface)] NotesOutlineEntry pFromEntry, [In][MarshalAs(UnmanagedType.Interface)] NotesOutlineEntry pRefEntry, [In] bool bAfter = true, [In] bool bAsChild = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743817)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesOutlineEntry GetFirst();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743818)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesOutlineEntry GetLast();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743819)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesOutlineEntry GetParent([In][MarshalAs(UnmanagedType.Interface)] NotesOutlineEntry pIEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743820)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesOutlineEntry GetNext([In][MarshalAs(UnmanagedType.Interface)] NotesOutlineEntry pIEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesOutlineEntry GetNextSibling([In][MarshalAs(UnmanagedType.Interface)] NotesOutlineEntry pIEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743822)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesOutlineEntry GetPrev([In][MarshalAs(UnmanagedType.Interface)] NotesOutlineEntry pIEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743823)]
	[return: MarshalAs(UnmanagedType.Interface)]
	NotesOutlineEntry GetPrevSibling([In][MarshalAs(UnmanagedType.Interface)] NotesOutlineEntry pIEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	void MoveEntry([In][MarshalAs(UnmanagedType.Interface)] NotesOutlineEntry pIEntry, [In][MarshalAs(UnmanagedType.Interface)] NotesOutlineEntry pIRefEntry, [In] bool bAfter = true, [In] bool bAsChild = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	void RemoveEntry([In][MarshalAs(UnmanagedType.Interface)] NotesOutlineEntry pIEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743826)]
	void Save();
}
[ComImport]
[Guid("29131571-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(4160)]
public interface IOutlineEntry
{
	[DispId(1610743808)]
	string Alias
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743810)]
	NotesDatabase DATABASE
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743811)]
	NotesDocument Document
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[ComAliasName("Domino.OE_CLASS")]
	[DispId(1610743812)]
	OE_CLASS EntryClass
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: ComAliasName("Domino.OE_CLASS")]
		get;
	}

	[DispId(1610743813)]
	string FrameText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743815)]
	string Formula
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743816)]
	bool HasChildren
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
	}

	[DispId(1610743817)]
	string HideFormula
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743819)]
	string ImagesText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743821)]
	bool IsHiddenFromNotes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[param: In]
		set;
	}

	[DispId(1610743823)]
	bool IsHiddenFromWeb
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		[param: In]
		set;
	}

	[DispId(1610743825)]
	bool IsInThisDB
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		get;
	}

	[DispId(1610743826)]
	bool IsPrivate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		get;
	}

	[DispId(1610743827)]
	bool KeepSelectionFocus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		[param: In]
		set;
	}

	[DispId(1610743829)]
	string Label
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743831)]
	int Level
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743831)]
		get;
	}

	[DispId(1610743832)]
	string NamedElement
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743833)]
	NotesOutline Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743833)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743834)]
	[ComAliasName("Domino.OE_TYPE")]
	OE_TYPE type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743834)]
		[return: ComAliasName("Domino.OE_TYPE")]
		get;
	}

	[DispId(1610743835)]
	string URL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743835)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743836)]
	bool UseHideFormula
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743836)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743836)]
		[param: In]
		set;
	}

	[DispId(1610743838)]
	NotesView View
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743838)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743839)]
	void SetAction([In][MarshalAs(UnmanagedType.BStr)] string pFormula);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743840)]
	void SetNamedElement([In][MarshalAs(UnmanagedType.Interface)] NotesDatabase pIDb, [In][MarshalAs(UnmanagedType.BStr)] string pElementName, [In][ComAliasName("Domino.OE_CLASS")] OE_CLASS lClass);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743841)]
	void SetNoteLink([In][MarshalAs(UnmanagedType.IUnknown)] object pIObj);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743842)]
	void SetURL([In][MarshalAs(UnmanagedType.BStr)] string pURL);
}
public enum OE_CLASS
{
	OUTLINE_CLASS_UNKNOWN = 2189,
	OUTLINE_CLASS_DOCUMENT,
	OUTLINE_CLASS_VIEW,
	OUTLINE_CLASS_FORM,
	OUTLINE_CLASS_NAVIGATOR,
	OUTLINE_CLASS_DATABASE,
	OUTLINE_CLASS_FRAMESET,
	OUTLINE_CLASS_PAGE,
	OUTLINE_CLASS_FOLDER
}
public enum _OE_CLASS
{
	OUTLINE_CLASS_UNKNOWN = 2189,
	OUTLINE_CLASS_DOCUMENT,
	OUTLINE_CLASS_VIEW,
	OUTLINE_CLASS_FORM,
	OUTLINE_CLASS_NAVIGATOR,
	OUTLINE_CLASS_DATABASE,
	OUTLINE_CLASS_FRAMESET,
	OUTLINE_CLASS_PAGE,
	OUTLINE_CLASS_FOLDER
}
public enum OE_TYPE
{
	OUTLINE_TYPE_URL = 2185,
	OUTLINE_TYPE_NOTELINK = 2186,
	OUTLINE_TYPE_NAMEDELEMENT = 2187,
	OUTLINE_TYPE_ACTION = 2188,
	OUTLINE_OTHER_VIEWS_TYPE = 1588,
	OUTLINE_OTHER_FOLDERS_TYPE = 1589,
	OUTLINE_OTHER_UNKNOWN_TYPE = 1591
}
public enum _OE_TYPE
{
	OUTLINE_TYPE_URL = 2185,
	OUTLINE_TYPE_NOTELINK = 2186,
	OUTLINE_TYPE_NAMEDELEMENT = 2187,
	OUTLINE_TYPE_ACTION = 2188,
	OUTLINE_OTHER_VIEWS_TYPE = 1588,
	OUTLINE_OTHER_FOLDERS_TYPE = 1589,
	OUTLINE_OTHER_UNKNOWN_TYPE = 1591
}
public enum FT_TYPES
{
	FT_SCORES = 8,
	FT_DATE_DES = 32,
	FT_DATE_ASC = 64,
	FT_STEMS = 512,
	FT_THESAURUS = 1024,
	FT_DATECREATED_DES = 1542,
	FT_DATECREATED_ASC = 1543,
	FT_FILESYSTEM = 4096,
	FT_DATABASE = 8192,
	FT_FUZZY = 16384
}
public enum _FT_TYPES
{
	FT_SCORES = 8,
	FT_DATE_DES = 32,
	FT_DATE_ASC = 64,
	FT_STEMS = 512,
	FT_THESAURUS = 1024,
	FT_DATECREATED_DES = 1542,
	FT_DATECREATED_ASC = 1543,
	FT_FILESYSTEM = 4096,
	FT_DATABASE = 8192,
	FT_FUZZY = 16384
}
[ComImport]
[Guid("2913156A-2EED-1069-BF5D-00DD011186B7")]
[DefaultMember("Name")]
[TypeLibType(4160)]
public interface IForm
{
	[DispId(1610743808)]
	object Aliases
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743809)]
	object Fields
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743810)]
	object FormUsers
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1610743812)]
	string HttpURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743813)]
	bool IsSubForm
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		get;
	}

	[DispId(0)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743815)]
	string NotesURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743816)]
	NotesDatabase Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743817)]
	bool ProtectReaders
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[param: In]
		set;
	}

	[DispId(1610743819)]
	bool ProtectUsers
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		[param: In]
		set;
	}

	[DispId(1610743821)]
	object Readers
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743823)]
	[return: ComAliasName("Domino.FIELD_TYPE")]
	FIELD_TYPE GetFieldType([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	void Remove();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	bool Lock([Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pName, [In] bool bProvisionalOK = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743826)]
	bool LockProvisional([Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743827)]
	void Unlock();

	[DispId(1610743828)]
	object LockHolders
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}
}
public enum FIELD_TYPE
{
	FORM_OBJECTLINK = 1452,
	FORM_OBJECT = 1453,
	FORM_ATTACHMENT = 1454,
	FIELD_UNKNOWN = 0,
	FIELD_RICHTEXT = 1,
	FIELD_NUMBERS = 768,
	FIELD_DATETIMES = 1024,
	FIELD_TEXT = 1280,
	FIELD_TEXTMULTI = 1281,
	FIELD_FORMULA = 1536,
	FIELD_USERID = 1792
}
public enum _FIELD_TYPE
{
	FORM_OBJECTLINK = 1452,
	FORM_OBJECT = 1453,
	FORM_ATTACHMENT = 1454,
	FIELD_UNKNOWN = 0,
	FIELD_RICHTEXT = 1,
	FIELD_NUMBERS = 768,
	FIELD_DATETIMES = 1024,
	FIELD_TEXT = 1280,
	FIELD_TEXTMULTI = 1281,
	FIELD_FORMULA = 1536,
	FIELD_USERID = 1792
}
public enum FTINDEX_FREQUENCY
{
	FTINDEX_DAILY = 1,
	FTINDEX_SCHEDULED,
	FTINDEX_HOURLY,
	FTINDEX_IMMEDIATE
}
public enum _FTIDX_FREQ
{
	FTINDEX_DAILY = 1,
	FTINDEX_SCHEDULED,
	FTINDEX_HOURLY,
	FTINDEX_IMMEDIATE
}
public enum DATABASE_TYPES
{
	DBTYPE_WEB_APP = 1,
	DBTYPE_MAILFILE,
	DBTYPE_MAILBOX,
	DBTYPE_SUBSCRIPTIONS,
	DBTYPE_NEWS_SVR_PROXY,
	DBTYPE_IMAP_SVR_PROXY,
	DBTYPE_PORTFOLIO,
	DBTYPE_MULTIDB_SRCH,
	DBTYPE_LIGHT_ADDR_BOOK,
	DBTYPE_ADDR_BOOK,
	DBTYPE_PERS_JOURNAL,
	DBTYPE_LIBRARY,
	DBTYPE_STANDARD
}
public enum _DATABASE_TYPES
{
	DBTYPE_WEB_APP = 1,
	DBTYPE_MAILFILE,
	DBTYPE_MAILBOX,
	DBTYPE_SUBSCRIPTIONS,
	DBTYPE_NEWS_SVR_PROXY,
	DBTYPE_IMAP_SVR_PROXY,
	DBTYPE_PORTFOLIO,
	DBTYPE_MULTIDB_SRCH,
	DBTYPE_LIGHT_ADDR_BOOK,
	DBTYPE_ADDR_BOOK,
	DBTYPE_PERS_JOURNAL,
	DBTYPE_LIBRARY,
	DBTYPE_STANDARD
}
public enum COMPACT_OPTIONS
{
	CMPC_ARCHIVE_DELETE_COMPACT = 1,
	CMPC_ARCHIVE_DELETE_ONLY = 2,
	CMPC_RECOVER_REDUCE_INPLACE = 4,
	CMPC_RECOVER_INPLACE = 8,
	CMPC_COPYSTYLE = 0x10,
	CMPC_DISCARD_VIEW_INDICES = 0x20,
	CMPC_ENABLE_DOCTBLBIT_OPTMZN = 0x40,
	CMPC_DISABLE_DOCTBLBIT_OPTMZN = 0x80,
	CMPC_ENABLE_RESPONSE_INFO = 0x100,
	CMPC_DISABLE_RESPONSE_INFO = 0x200,
	CMPC_IGNORE_COPYSTYLE_ERRORS = 0x400,
	CMPC_ENABLE_LARGE_UNKTBL = 0x800,
	CMPC_DISABLE_LARGE_UNKTBL = 0x1000,
	CMPC_NO_LOCKOUT = 0x2000,
	CMPC_MAX_4GB = 0x4000,
	CMPC_CHK_OVERLAP = 0x8000,
	CMPC_REVERT_FILEFORMAT = 0x10000,
	CMPC_ENABLE_TRANSACTIONLOGGING = 0x20000,
	CMPC_DISABLE_TRANSACTIONLOGGING = 0x40000,
	CMPC_ENABLE_UNREAD_MARKS = 0x80000,
	CMPC_DISABLE_UNREAD_MARKS = 0x100000
}
public enum _CMPC_OPTS
{
	CMPC_ARCHIVE_DELETE_COMPACT = 1,
	CMPC_ARCHIVE_DELETE_ONLY = 2,
	CMPC_RECOVER_REDUCE_INPLACE = 4,
	CMPC_RECOVER_INPLACE = 8,
	CMPC_COPYSTYLE = 0x10,
	CMPC_DISCARD_VIEW_INDICES = 0x20,
	CMPC_ENABLE_DOCTBLBIT_OPTMZN = 0x40,
	CMPC_DISABLE_DOCTBLBIT_OPTMZN = 0x80,
	CMPC_ENABLE_RESPONSE_INFO = 0x100,
	CMPC_DISABLE_RESPONSE_INFO = 0x200,
	CMPC_IGNORE_COPYSTYLE_ERRORS = 0x400,
	CMPC_ENABLE_LARGE_UNKTBL = 0x800,
	CMPC_DISABLE_LARGE_UNKTBL = 0x1000,
	CMPC_NO_LOCKOUT = 0x2000,
	CMPC_MAX_4GB = 0x4000,
	CMPC_CHK_OVERLAP = 0x8000,
	CMPC_REVERT_FILEFORMAT = 0x10000,
	CMPC_ENABLE_TRANSACTIONLOGGING = 0x20000,
	CMPC_DISABLE_TRANSACTIONLOGGING = 0x40000,
	CMPC_ENABLE_UNREAD_MARKS = 0x80000,
	CMPC_DISABLE_UNREAD_MARKS = 0x100000
}
public enum FTINDEX_OPTIONS
{
	FTINDEX_ATTACHED_FILES = 1,
	FTINDEX_ENCRYPTED_FIELDS = 2,
	FTINDEX_ALL_BREAKS = 4,
	FTINDEX_CASE_SENSITIVE = 8,
	FTINDEX_ATTACHED_BIN_FILES = 0x10
}
public enum _FTIDX_OPTS
{
	FTINDEX_ATTACHED_FILES = 1,
	FTINDEX_ENCRYPTED_FIELDS = 2,
	FTINDEX_ALL_BREAKS = 4,
	FTINDEX_CASE_SENSITIVE = 8,
	FTINDEX_ATTACHED_BIN_FILES = 0x10
}
public enum ACCESS_PRIVILEGES
{
	DBACL_CREATE_DOCS = 1,
	DBACL_DELETE_DOCS = 2,
	DBACL_CREATE_PRIV_AGENTS = 4,
	DBACL_CREATE_PRIV_FOLDERS_VIEWS = 8,
	DBACL_CREATE_SHARED_FOLDERS_VIEWS = 0x10,
	DBACL_CREATE_SCRIPT_AGENTS = 0x20,
	DBACL_READ_PUBLIC_DOCS = 0x40,
	DBACL_WRITE_PUBLIC_DOCS = 0x80,
	DBACL_REPLICATE_COPY_DOCS = 0x100
}
public enum _DBACL_PRIVS
{
	DBACL_CREATE_DOCS = 1,
	DBACL_DELETE_DOCS = 2,
	DBACL_CREATE_PRIV_AGENTS = 4,
	DBACL_CREATE_PRIV_FOLDERS_VIEWS = 8,
	DBACL_CREATE_SHARED_FOLDERS_VIEWS = 0x10,
	DBACL_CREATE_SCRIPT_AGENTS = 0x20,
	DBACL_READ_PUBLIC_DOCS = 0x40,
	DBACL_WRITE_PUBLIC_DOCS = 0x80,
	DBACL_REPLICATE_COPY_DOCS = 0x100
}
public enum DBFIXUP_TYPES
{
	FIXUP_DEFAULT = 0,
	FIXUP_VERIFY = 1,
	FIXUP_QUICK = 2,
	FIXUP_INCREMENTAL = 4,
	FIXUP_TXLOGGED = 8,
	FIXUP_NODELETE = 0x10,
	FIXUP_REVERT = 0x20,
	FIXUP_NOVIEWS = 0x40
}
public enum _DBFIXUP_TYPES
{
	FIXUP_DEFAULT = 0,
	FIXUP_VERIFY = 1,
	FIXUP_QUICK = 2,
	FIXUP_INCREMENTAL = 4,
	FIXUP_TXLOGGED = 8,
	FIXUP_NODELETE = 0x10,
	FIXUP_REVERT = 0x20,
	FIXUP_NOVIEWS = 0x40
}
public enum DB_OPTIONS
{
	DBOPT_LZCOMPRESSION = 65,
	DBOPT_MAINTAINLASTACCESSED = 44,
	DBOPT_MOREFIELDS = 54,
	DBOPT_NOHEADLINEMONITORS = 46,
	DBOPT_NOOVERWRITE = 36,
	DBOPT_NORESPONSEINFO = 38,
	DBOPT_NOTRANSACTIONLOGGING = 45,
	DBOPT_NOUNREAD = 37,
	DBOPT_OPTIMIZATION = 41,
	DBOPT_SOFTDELETE = 49,
	DBOPT_REPLICATEUNREADMARKSTOCLUSTER = 70,
	DBOPT_REPLICATEUNREADMARKSTOANY = 71
}
public enum _DB_OPTIONS
{
	DBOPT_LZCOMPRESSION = 65,
	DBOPT_MAINTAINLASTACCESSED = 44,
	DBOPT_MOREFIELDS = 54,
	DBOPT_NOHEADLINEMONITORS = 46,
	DBOPT_NOOVERWRITE = 36,
	DBOPT_NORESPONSEINFO = 38,
	DBOPT_NOTRANSACTIONLOGGING = 45,
	DBOPT_NOUNREAD = 37,
	DBOPT_OPTIMIZATION = 41,
	DBOPT_SOFTDELETE = 49,
	DBOPT_REPLICATEUNREADMARKSTOCLUSTER = 70,
	DBOPT_REPLICATEUNREADMARKSTOANY = 71
}
[ComImport]
[TypeLibType(4160)]
[Guid("29131589-2EED-1069-BF5D-00DD011186B7")]
public interface INoteCollection
{
	[DispId(1610743808)]
	bool SelectDocuments
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		set;
	}

	[DispId(1610743810)]
	bool SelectProfiles
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	bool SelectForms
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		set;
	}

	[DispId(1610743814)]
	bool SelectSubforms
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		set;
	}

	[DispId(1610743816)]
	bool SelectActions
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[param: In]
		set;
	}

	[DispId(1610743818)]
	bool SelectFramesets
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[param: In]
		set;
	}

	[DispId(1610743820)]
	bool SelectPages
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[param: In]
		set;
	}

	[DispId(1610743822)]
	bool SelectImageResources
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[param: In]
		set;
	}

	[DispId(1610743824)]
	bool SelectStyleSheetResources
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[param: In]
		set;
	}

	[DispId(1610743826)]
	bool SelectJavaResources
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[param: In]
		set;
	}

	[DispId(1610743828)]
	bool SelectMiscFormatElements
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		[param: In]
		set;
	}

	[DispId(1610743830)]
	bool SelectViews
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		[param: In]
		set;
	}

	[DispId(1610743832)]
	bool SelectFolders
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[param: In]
		set;
	}

	[DispId(1610743834)]
	bool SelectNavigators
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743834)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743834)]
		[param: In]
		set;
	}

	[DispId(1610743836)]
	bool SelectMiscIndexElements
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743836)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743836)]
		[param: In]
		set;
	}

	[DispId(1610743838)]
	bool SelectIcon
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743838)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743838)]
		[param: In]
		set;
	}

	[DispId(1610743840)]
	bool SelectAgents
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743840)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743840)]
		[param: In]
		set;
	}

	[DispId(1610743842)]
	bool SelectOutlines
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743842)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743842)]
		[param: In]
		set;
	}

	[DispId(1610743844)]
	bool SelectDatabaseScript
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743844)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743844)]
		[param: In]
		set;
	}

	[DispId(1610743846)]
	bool SelectScriptLibraries
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743846)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743846)]
		[param: In]
		set;
	}

	[DispId(1610743848)]
	bool SelectDataConnections
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743848)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743848)]
		[param: In]
		set;
	}

	[DispId(1610743850)]
	bool SelectMiscCodeElements
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743850)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743850)]
		[param: In]
		set;
	}

	[DispId(1610743852)]
	bool SelectSharedFields
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743852)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743852)]
		[param: In]
		set;
	}

	[DispId(1610743854)]
	bool SelectHelpAbout
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743854)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743854)]
		[param: In]
		set;
	}

	[DispId(1610743856)]
	bool SelectHelpUsing
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743856)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743856)]
		[param: In]
		set;
	}

	[DispId(1610743858)]
	bool SelectHelpIndex
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743858)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743858)]
		[param: In]
		set;
	}

	[DispId(1610743860)]
	bool SelectReplicationFormulas
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743860)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743860)]
		[param: In]
		set;
	}

	[DispId(1610743862)]
	bool SelectACL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743862)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743862)]
		[param: In]
		set;
	}

	[DispId(1610743864)]
	string SelectionFormula
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743864)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743864)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743866)]
	object SinceTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743866)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743866)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1610743868)]
	object LastBuildTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743868)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743869)]
	int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743869)]
		get;
	}

	[DispId(1610743870)]
	NotesDatabase Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743870)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743871)]
	void SelectAllNotes([In] bool bFlag);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743872)]
	void SelectAllDataNotes([In] bool bFlag);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743873)]
	void SelectAllAdminNotes([In] bool bFlag);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743874)]
	void SelectAllDesignElements([In] bool bFlag);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743875)]
	void SelectAllFormatElements([In] bool bFlag);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743876)]
	void SelectAllIndexElements([In] bool bFlag);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743877)]
	void SelectAllCodeElements([In] bool bFlag);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743878)]
	void BuildCollection();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743879)]
	void ClearCollection();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743880)]
	void Add([In][MarshalAs(UnmanagedType.Struct)] object NoteIds);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743881)]
	void Remove([In][MarshalAs(UnmanagedType.Struct)] object NoteIds);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743882)]
	void Intersect([In][MarshalAs(UnmanagedType.Struct)] object NoteIds);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743883)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetFirstNoteId();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743884)]
	[return: MarshalAs(UnmanagedType.BStr)]
	string GetNextNoteId([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);
}
public enum DBSIGN_TYPES
{
	DBSIGN_DOC_FORM = 4,
	DBSIGN_DOC_VIEW = 8,
	DBSIGN_DOC_ICON = 16,
	DBSIGN_DOC_ACL = 64,
	DBSIGN_DOC_DATA = 1,
	DBSIGN_DOC_HELP = 256,
	DBSIGN_DOC_AGENT = 512,
	DBSIGN_DOC_SHAREDFIELD = 1024,
	DBSIGN_DOC_REPLFORMULA = 2048,
	DBSIGN_DOC_ALL = 32767
}
public enum _DBSIGN_TYPES
{
	DBSIGN_DOC_FORM = 4,
	DBSIGN_DOC_VIEW = 8,
	DBSIGN_DOC_ICON = 16,
	DBSIGN_DOC_ACL = 64,
	DBSIGN_DOC_DATA = 1,
	DBSIGN_DOC_HELP = 256,
	DBSIGN_DOC_AGENT = 512,
	DBSIGN_DOC_SHAREDFIELD = 1024,
	DBSIGN_DOC_REPLFORMULA = 2048,
	DBSIGN_DOC_ALL = 32767
}
public enum DBMOD_TYPES
{
	DBMOD_DOC_FORM = 4,
	DBMOD_DOC_VIEW = 8,
	DBMOD_DOC_ICON = 16,
	DBMOD_DOC_ACL = 64,
	DBMOD_DOC_DATA = 1,
	DBMOD_DOC_HELP = 256,
	DBMOD_DOC_AGENT = 512,
	DBMOD_DOC_SHAREDFIELD = 1024,
	DBMOD_DOC_REPLFORMULA = 2048,
	DBMOD_DOC_ALL = 32767
}
public enum _DBMOD_TYPES
{
	DBMOD_DOC_FORM = 4,
	DBMOD_DOC_VIEW = 8,
	DBMOD_DOC_ICON = 16,
	DBMOD_DOC_ACL = 64,
	DBMOD_DOC_DATA = 1,
	DBMOD_DOC_HELP = 256,
	DBMOD_DOC_AGENT = 512,
	DBMOD_DOC_SHAREDFIELD = 1024,
	DBMOD_DOC_REPLFORMULA = 2048,
	DBMOD_DOC_ALL = 32767
}
[ComImport]
[Guid("29131561-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(4160)]
[DefaultMember("Name")]
public interface IACLEntry
{
	[DispId(1610743808)]
	bool CanCreateDocuments
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		set;
	}

	[DispId(1610743810)]
	bool CanCreateLSOrJavaAgent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	bool CanCreatePersonalAgent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		set;
	}

	[DispId(1610743814)]
	bool CanCreatePersonalFolder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		set;
	}

	[DispId(1610743816)]
	bool CanCreateSharedFolder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[param: In]
		set;
	}

	[DispId(1610743818)]
	bool CanDeleteDocuments
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[param: In]
		set;
	}

	[DispId(1610743820)]
	bool IsAdminReaderAuthor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[param: In]
		set;
	}

	[DispId(1610743822)]
	bool IsAdminServer
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[param: In]
		set;
	}

	[DispId(1610743824)]
	bool IsGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[param: In]
		set;
	}

	[DispId(1610743826)]
	bool IsPerson
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[param: In]
		set;
	}

	[DispId(1610743828)]
	bool IsPublicReader
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		[param: In]
		set;
	}

	[DispId(1610743830)]
	bool IsPublicWriter
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		[param: In]
		set;
	}

	[DispId(1610743832)]
	bool IsServer
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[param: In]
		set;
	}

	[DispId(1610743834)]
	[ComAliasName("Domino.ACLLEVEL")]
	ACLLEVEL Level
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743834)]
		[return: ComAliasName("Domino.ACLLEVEL")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743834)]
		[param: In]
		[param: ComAliasName("Domino.ACLLEVEL")]
		set;
	}

	[DispId(0)]
	string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743838)]
	NotesName NameObject
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743838)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743839)]
	NotesACL Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743839)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743840)]
	object Roles
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743840)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[ComAliasName("Domino.LSXBE_ACLTYPE")]
	[DispId(1610743841)]
	LSXBE_ACLTYPE UserType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743841)]
		[return: ComAliasName("Domino.LSXBE_ACLTYPE")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743841)]
		[param: In]
		[param: ComAliasName("Domino.LSXBE_ACLTYPE")]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743843)]
	void DisableRole([In][MarshalAs(UnmanagedType.BStr)] string pRole);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743844)]
	void EnableRole([In][MarshalAs(UnmanagedType.BStr)] string pRole);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743845)]
	bool IsRoleEnabled([In][MarshalAs(UnmanagedType.BStr)] string pRole);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743846)]
	void Remove();

	[DispId(1610743847)]
	bool CanReplicateOrCopyDocuments
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743847)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743847)]
		[param: In]
		set;
	}
}
public enum LSXBE_ACLTYPE
{
	ACLTYPE_UNSPECIFIED,
	ACLTYPE_PERSON,
	ACLTYPE_SERVER,
	ACLTYPE_MIXEDGROUP,
	ACLTYPE_PERSONGROUP,
	ACLTYPE_SERVERGROUP
}
public enum _LSXBE_ACLTYPE
{
	ACLTYPE_UNSPECIFIED,
	ACLTYPE_PERSON,
	ACLTYPE_SERVER,
	ACLTYPE_MIXEDGROUP,
	ACLTYPE_PERSONGROUP,
	ACLTYPE_SERVERGROUP
}
[ComImport]
[TypeLibType(2)]
[Guid("29131522-2EED-1069-BF5D-00DD011186B7")]
[DefaultMember("Name")]
[ClassInterface(0)]
public class NotesACLEntryClass : IACLEntry, NotesACLEntry
{
	[DispId(1610743808)]
	public virtual extern bool CanCreateDocuments
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		set;
	}

	[DispId(1610743810)]
	public virtual extern bool CanCreateLSOrJavaAgent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	public virtual extern bool CanCreatePersonalAgent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		set;
	}

	[DispId(1610743814)]
	public virtual extern bool CanCreatePersonalFolder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		set;
	}

	[DispId(1610743816)]
	public virtual extern bool CanCreateSharedFolder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[param: In]
		set;
	}

	[DispId(1610743818)]
	public virtual extern bool CanDeleteDocuments
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[param: In]
		set;
	}

	[DispId(1610743820)]
	public virtual extern bool IsAdminReaderAuthor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[param: In]
		set;
	}

	[DispId(1610743822)]
	public virtual extern bool IsAdminServer
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[param: In]
		set;
	}

	[DispId(1610743824)]
	public virtual extern bool IsGroup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[param: In]
		set;
	}

	[DispId(1610743826)]
	public virtual extern bool IsPerson
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[param: In]
		set;
	}

	[DispId(1610743828)]
	public virtual extern bool IsPublicReader
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		[param: In]
		set;
	}

	[DispId(1610743830)]
	public virtual extern bool IsPublicWriter
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		[param: In]
		set;
	}

	[DispId(1610743832)]
	public virtual extern bool IsServer
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[param: In]
		set;
	}

	[DispId(1610743834)]
	[ComAliasName("Domino.ACLLEVEL")]
	public virtual extern ACLLEVEL Level
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743834)]
		[return: ComAliasName("Domino.ACLLEVEL")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743834)]
		[param: In]
		[param: ComAliasName("Domino.ACLLEVEL")]
		set;
	}

	[DispId(0)]
	public virtual extern string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743838)]
	public virtual extern NotesName NameObject
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743838)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743839)]
	public virtual extern NotesACL Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743839)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743840)]
	public virtual extern object Roles
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743840)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[ComAliasName("Domino.LSXBE_ACLTYPE")]
	[DispId(1610743841)]
	public virtual extern LSXBE_ACLTYPE UserType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743841)]
		[return: ComAliasName("Domino.LSXBE_ACLTYPE")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743841)]
		[param: In]
		[param: ComAliasName("Domino.LSXBE_ACLTYPE")]
		set;
	}

	[DispId(1610743847)]
	public virtual extern bool CanReplicateOrCopyDocuments
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743847)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743847)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743843)]
	public virtual extern void DisableRole([In][MarshalAs(UnmanagedType.BStr)] string pRole);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743844)]
	public virtual extern void EnableRole([In][MarshalAs(UnmanagedType.BStr)] string pRole);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743845)]
	public virtual extern bool IsRoleEnabled([In][MarshalAs(UnmanagedType.BStr)] string pRole);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743846)]
	public virtual extern void Remove();
}
[ComImport]
[CoClass(typeof(NotesACLEntryClass))]
[Guid("29131561-2EED-1069-BF5D-00DD011186B7")]
public interface NotesACLEntry : IACLEntry
{
}
[ComImport]
[Guid("29131523-2EED-1069-BF5D-00DD011186B7")]
[DefaultMember("Name")]
[TypeLibType(2)]
[ClassInterface(0)]
public class NotesAgentClass : IAgent, NotesAgent
{
	[DispId(1610743808)]
	public virtual extern string Comment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	public virtual extern string CommonOwner
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743810)]
	public virtual extern bool HasRunSinceModified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
	}

	[DispId(1610743811)]
	public virtual extern string HttpURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743812)]
	public virtual extern bool IsEnabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		set;
	}

	[DispId(1610743814)]
	public virtual extern bool IsNotesAgent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
	}

	[DispId(1610743815)]
	public virtual extern bool IsPublic
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		get;
	}

	[DispId(1610743816)]
	public virtual extern bool IsWebAgent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
	}

	[DispId(1610743817)]
	public virtual extern object LastRun
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(0)]
	public virtual extern string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743819)]
	public virtual extern string NotesURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743820)]
	public virtual extern string Owner
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743821)]
	public virtual extern string ParameterDocID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743822)]
	public virtual extern NotesDatabase Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743823)]
	public virtual extern string Query
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743824)]
	public virtual extern string ServerName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743826)]
	[ComAliasName("Domino.AG_TARGET")]
	public virtual extern AG_TARGET Target
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[return: ComAliasName("Domino.AG_TARGET")]
		get;
	}

	[DispId(1610743827)]
	[ComAliasName("Domino.AG_TRIGGER")]
	public virtual extern AG_TRIGGER Trigger
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		[return: ComAliasName("Domino.AG_TRIGGER")]
		get;
	}

	[DispId(1610743832)]
	public virtual extern string OnBehalfOf
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743836)]
	public virtual extern object LockHolders
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743836)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743837)]
	public virtual extern bool IsActivatable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743837)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743828)]
	public virtual extern void Remove();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743829)]
	public virtual extern void Run([In][MarshalAs(UnmanagedType.BStr)] string pNoteid = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743830)]
	public virtual extern void RunOnServer([In][MarshalAs(UnmanagedType.BStr)] string pNoteid = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743831)]
	public virtual extern void Save();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743833)]
	public virtual extern bool Lock([Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pName, [In] bool bProvisionalOK = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743834)]
	public virtual extern bool LockProvisional([Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743835)]
	public virtual extern void Unlock();
}
[ComImport]
[CoClass(typeof(NotesAgentClass))]
[Guid("29131562-2EED-1069-BF5D-00DD011186B7")]
public interface NotesAgent : IAgent
{
}
[ComImport]
[DefaultMember("FilePath")]
[Guid("29131524-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(2)]
[ClassInterface(0)]
public class NotesDatabaseClass : IDatabase, NotesDatabase
{
	[DispId(1610743808)]
	public virtual extern NotesACL ACL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743809)]
	public virtual extern NotesDocumentCollection AllDocuments
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743810)]
	public virtual extern object Agents
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743811)]
	public virtual extern string Categories
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743813)]
	public virtual extern object Created
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743814)]
	public virtual extern int CurrentAccessLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
	}

	[DispId(1610743815)]
	public virtual extern bool DelayUpdates
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[param: In]
		set;
	}

	[DispId(1610743817)]
	public virtual extern string DesignTemplateName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743818)]
	public virtual extern string FileName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(0)]
	public virtual extern string FilePath
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743820)]
	public virtual extern bool FolderReferencesEnabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[param: In]
		set;
	}

	[DispId(1610743822)]
	public virtual extern object Forms
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743823)]
	public virtual extern string HttpURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743824)]
	public virtual extern bool IsDirectoryCatalog
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		get;
	}

	[DispId(1610743825)]
	public virtual extern bool IsFTIndexed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		get;
	}

	[DispId(1610743826)]
	public virtual extern bool IsMultiDbSearch
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		get;
	}

	[DispId(1610743827)]
	public virtual extern bool IsOpen
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		get;
	}

	[DispId(1610743828)]
	public virtual extern bool IsPublicAddressBook
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		get;
	}

	[DispId(1610743829)]
	public virtual extern bool IsPrivateAddressBook
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		get;
	}

	[DispId(1610743830)]
	public virtual extern object LastFTIndexed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743831)]
	public virtual extern object LastModified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743831)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743832)]
	public virtual extern object Managers
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743833)]
	public virtual extern double MaxSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743833)]
		get;
	}

	[DispId(1610743834)]
	public virtual extern string NotesURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743834)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743835)]
	public virtual extern NotesSession Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743835)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743836)]
	public virtual extern double PercentUsed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743836)]
		get;
	}

	[DispId(1610743837)]
	public virtual extern string ReplicaID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743837)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743838)]
	public virtual extern NotesReplication ReplicationInfo
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743838)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743839)]
	public virtual extern string Server
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743839)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743840)]
	public virtual extern double Size
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743840)]
		get;
	}

	[DispId(1610743841)]
	public virtual extern int SizeQuota
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743841)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743841)]
		[param: In]
		set;
	}

	[DispId(1610743843)]
	public virtual extern string TemplateName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743843)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743844)]
	public virtual extern string Title
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743844)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743844)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743846)]
	public virtual extern NotesDocumentCollection UnprocessedDocuments
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743846)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743847)]
	public virtual extern object Views
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743847)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743877)]
	public virtual extern object ACLActivityLog
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743877)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[ComAliasName("Domino.FTINDEX_FREQUENCY")]
	[DispId(1610743878)]
	public virtual extern FTINDEX_FREQUENCY FTIndexFrequency
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743878)]
		[return: ComAliasName("Domino.FTINDEX_FREQUENCY")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743878)]
		[param: In]
		[param: ComAliasName("Domino.FTINDEX_FREQUENCY")]
		set;
	}

	[DispId(1610743880)]
	public virtual extern bool IsCurrentAccessPublicReader
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743880)]
		get;
	}

	[DispId(1610743881)]
	public virtual extern bool IsCurrentAccessPublicWriter
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743881)]
		get;
	}

	[DispId(1610743882)]
	public virtual extern bool IsInMultiDbIndexing
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743882)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743882)]
		[param: In]
		set;
	}

	[DispId(1610743884)]
	public virtual extern bool IsLink
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743884)]
		get;
	}

	[ComAliasName("Domino.DATABASE_TYPES")]
	[DispId(1610743885)]
	public virtual extern DATABASE_TYPES type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743885)]
		[return: ComAliasName("Domino.DATABASE_TYPES")]
		get;
	}

	[DispId(1610743886)]
	public virtual extern bool IsDocumentLockingEnabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743886)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743886)]
		[param: In]
		set;
	}

	[DispId(1610743888)]
	public virtual extern bool IsDesignLockingEnabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743888)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743888)]
		[param: In]
		set;
	}

	[DispId(1610743904)]
	public virtual extern bool IsInService
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743904)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743904)]
		[param: In]
		set;
	}

	[DispId(1610743905)]
	public virtual extern bool IsPendingDelete
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743905)]
		get;
	}

	[DispId(1610743906)]
	public virtual extern bool IsConfigurationDirectory
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743906)]
		get;
	}

	[DispId(1610743907)]
	public virtual extern bool IsClusterReplication
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743907)]
		get;
	}

	[DispId(1610743908)]
	public virtual extern bool ListInDbCatalog
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743908)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743908)]
		[param: In]
		set;
	}

	[DispId(1610743909)]
	public virtual extern NotesDateTime LastFixup
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743909)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743910)]
	public virtual extern double LimitRevisions
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743910)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743910)]
		[param: In]
		set;
	}

	[DispId(1610743911)]
	public virtual extern double LimitUpdatedBy
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743911)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743911)]
		[param: In]
		set;
	}

	[DispId(1610743912)]
	public virtual extern int FileFormat
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743912)]
		get;
	}

	[DispId(1610743913)]
	public virtual extern int UndeleteExpireTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743913)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743913)]
		[param: In]
		set;
	}

	[DispId(1610743914)]
	public virtual extern int SizeWarning
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743914)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743914)]
		[param: In]
		set;
	}

	[DispId(1610743919)]
	public virtual extern bool InService
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743919)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743848)]
	public virtual extern int Compact();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743849)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDatabase CreateCopy([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pFile, [In] int lMaxsize = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743850)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument CreateDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743851)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDatabase CreateFromTemplate([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pFile, [In] bool bInherit, [In] int lMaxsize = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743852)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesOutline CreateOutline([In][MarshalAs(UnmanagedType.BStr)] string pName, [In] bool bGenDefault = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743853)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDatabase CreateReplica([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pFile);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743854)]
	public virtual extern void EnableFolder([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743855)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument FTDomainSearch([In][MarshalAs(UnmanagedType.BStr)] string pQuery, [In] int lMax, [In][ComAliasName("Domino.FT_TYPES")] FT_TYPES lSortopt = FT_TYPES.FT_SCORES, [In][ComAliasName("Domino.FT_TYPES")] FT_TYPES lOtheropt = (FT_TYPES)0, [In] int lStart = 0, [In] int lCount = 0, [In][MarshalAs(UnmanagedType.BStr)] string pEntryForm = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743856)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocumentCollection FTSearch([In][MarshalAs(UnmanagedType.BStr)] string pQuery, [In] int lMax, [In][ComAliasName("Domino.FT_TYPES")] FT_TYPES lSortopt = FT_TYPES.FT_SCORES, [In][ComAliasName("Domino.FT_TYPES")] FT_TYPES lOtheropt = (FT_TYPES)0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743857)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesAgent GetAgent([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743858)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument GetDocumentByID([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743859)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument GetDocumentByUNID([In][MarshalAs(UnmanagedType.BStr)] string pUnid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743860)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument GetDocumentByURL([In][MarshalAs(UnmanagedType.BStr)] string pURL, [In] int lReload = 0, [In] bool bUrllist = false, [In][MarshalAs(UnmanagedType.BStr)] string pCharset = "", [In][MarshalAs(UnmanagedType.BStr)] string pWebuser = "", [In][MarshalAs(UnmanagedType.BStr)] string pWebpasswd = "", [In][MarshalAs(UnmanagedType.BStr)] string pProxyuser = "", [In][MarshalAs(UnmanagedType.BStr)] string pProxypasswd = "", [In] bool bNowait = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743861)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesForm GetForm([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743862)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesOutline GetOutline([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743863)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument GetProfileDocument([In][MarshalAs(UnmanagedType.BStr)] string pProfile, [In][MarshalAs(UnmanagedType.BStr)] string pProfileuser = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743864)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocumentCollection GetProfileDocCollection([In][MarshalAs(UnmanagedType.BStr)] string pProfileName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743865)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetURLHeaderInfo([In][MarshalAs(UnmanagedType.BStr)] string pURL = "", [In][MarshalAs(UnmanagedType.BStr)] string pHeader = "", [In][MarshalAs(UnmanagedType.BStr)] string pWebuser = "", [In][MarshalAs(UnmanagedType.BStr)] string pWebpasswd = "", [In][MarshalAs(UnmanagedType.BStr)] string pProxyuser = "", [In][MarshalAs(UnmanagedType.BStr)] string pProxypasswd = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743866)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesView GetView([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743867)]
	public virtual extern void GrantAccess([In][MarshalAs(UnmanagedType.BStr)] string pName, [In][ComAliasName("Domino.ACLLEVEL")] ACLLEVEL lLevel);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743868)]
	public virtual extern void Open();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743869)]
	[return: ComAliasName("Domino.ACLLEVEL")]
	public virtual extern ACLLEVEL QueryAccess([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743870)]
	public virtual extern void Remove();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743871)]
	public virtual extern bool Replicate([In][MarshalAs(UnmanagedType.BStr)] string pServer);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743872)]
	public virtual extern void RevokeAccess([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743873)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocumentCollection Search([In][MarshalAs(UnmanagedType.BStr)] string pFormula, [In][MarshalAs(UnmanagedType.Interface)] NotesDateTime pIDt, [In] int lMax);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743874)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocumentCollection UnprocessedFTSearch([In][MarshalAs(UnmanagedType.BStr)] string pQuery, [In] int lMax, [In][ComAliasName("Domino.FT_TYPES")] FT_TYPES lSortopt = FT_TYPES.FT_SCORES, [In][ComAliasName("Domino.FT_TYPES")] FT_TYPES lOtheropt = (FT_TYPES)0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743875)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocumentCollection UnprocessedSearch([In][MarshalAs(UnmanagedType.BStr)] string pFormula, [In][MarshalAs(UnmanagedType.Interface)] NotesDateTime pDt, [In] int lMax);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743876)]
	public virtual extern void UpdateFTIndex([In] bool bCreate);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743890)]
	public virtual extern int CompactWithOptions([In][MarshalAs(UnmanagedType.Struct)] object cmpcFlags, [In][MarshalAs(UnmanagedType.BStr)] string pSpacethreshhold = "", [In][ComAliasName("Domino.COMPACT_OPTIONS")] COMPACT_OPTIONS unused = COMPACT_OPTIONS.CMPC_IGNORE_COPYSTYLE_ERRORS);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743891)]
	public virtual extern void CreateFTIndex([In][ComAliasName("Domino.FTINDEX_OPTIONS")] FTINDEX_OPTIONS ftiFlags, [In] bool bRecreate);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743892)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocumentCollection FTSearchRange([In][MarshalAs(UnmanagedType.BStr)] string pQuery, [In] int lMax, [In][ComAliasName("Domino.FT_TYPES")] FT_TYPES lSortopt = FT_TYPES.FT_SCORES, [In][ComAliasName("Domino.FT_TYPES")] FT_TYPES lOtheropt = (FT_TYPES)0, [In] int start = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743893)]
	public virtual extern bool OpenByReplicaID([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pReplicaID);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743894)]
	public virtual extern bool OpenIfModified([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pDbfile, [In][MarshalAs(UnmanagedType.Interface)] NotesDateTime pITimeModifiedSince);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743895)]
	public virtual extern bool OpenWithFailover([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pDbfile);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743896)]
	[return: ComAliasName("Domino.ACCESS_PRIVILEGES")]
	public virtual extern ACCESS_PRIVILEGES QueryAccessPrivileges([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743897)]
	public virtual extern void RemoveFTIndex();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743898)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocumentCollection UnprocessedFTSearchRange([In][MarshalAs(UnmanagedType.BStr)] string pQuery, [In] int lMax, [In][ComAliasName("Domino.FT_TYPES")] FT_TYPES lSortopt = FT_TYPES.FT_SCORES, [In][ComAliasName("Domino.FT_TYPES")] FT_TYPES lOtheropt = (FT_TYPES)0, [In] int start = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743899)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesView CreateView([In][MarshalAs(UnmanagedType.BStr)] string Title = "", [In][MarshalAs(UnmanagedType.BStr)] string Formula = "", [In][MarshalAs(UnmanagedType.Interface)] NotesView templateView = null, [In] bool noRefresh = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743900)]
	public virtual extern void Fixup([In][ComAliasName("Domino.DBFIXUP_TYPES")] DBFIXUP_TYPES opts = DBFIXUP_TYPES.FIXUP_DEFAULT);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743901)]
	public virtual extern void MarkForDelete();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743902)]
	public virtual extern bool GetOption([In][ComAliasName("Domino.DB_OPTIONS")] DB_OPTIONS bit);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743903)]
	public virtual extern void SetOption([In][ComAliasName("Domino.DB_OPTIONS")] DB_OPTIONS bit, [In] bool bValue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743921)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesNoteCollection CreateNoteCollection([In] bool bSelectAll);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743922)]
	public virtual extern void Sign([In][ComAliasName("Domino.DBSIGN_TYPES")] DBSIGN_TYPES lDocumentType = DBSIGN_TYPES.DBSIGN_DOC_ALL, [In] bool bExistingSigsOnly = false, [In][MarshalAs(UnmanagedType.BStr)] string pNameStr = "", [In] bool bNameStrIsNoteID = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743923)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object QueryAccessRoles([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743924)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocumentCollection GetModifiedDocuments([In][MarshalAs(UnmanagedType.Interface)] NotesDateTime pDTSince = null, [In][ComAliasName("Domino.DBMOD_TYPES")] DBMOD_TYPES noteClass = DBMOD_TYPES.DBMOD_DOC_DATA);
}
[ComImport]
[Guid("29131563-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesDatabaseClass))]
public interface NotesDatabase : IDatabase
{
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("29131525-2EED-1069-BF5D-00DD011186B7")]
[DefaultMember("Text")]
public class NotesDateRangeClass : IDateRange, NotesDateRange
{
	[DispId(1610743808)]
	public virtual extern NotesDateTime EndDateTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1610743810)]
	public virtual extern NotesSession Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743811)]
	public virtual extern NotesDateTime StartDateTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(0)]
	public virtual extern string Text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}
}
[ComImport]
[Guid("29131565-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesDateRangeClass))]
public interface NotesDateRange : IDateRange
{
}
[ComImport]
[DefaultMember("LocalTime")]
[Guid("29131526-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(2)]
[ClassInterface(0)]
public class NotesDateTimeClass : IDateTime, NotesDateTime
{
	[DispId(1610743808)]
	public virtual extern string DateOnly
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	public virtual extern string GMTTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743810)]
	public virtual extern bool IsDST
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
	}

	[DispId(1610743811)]
	public virtual extern bool IsValidDate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		get;
	}

	[DispId(0)]
	public virtual extern string LocalTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743814)]
	public virtual extern object LSGMTTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743815)]
	public virtual extern object LSLocalTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1610743817)]
	public virtual extern NotesSession Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743818)]
	public virtual extern string TimeOnly
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743819)]
	public virtual extern int TimeZone
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		get;
	}

	[DispId(1610743820)]
	public virtual extern string ZoneTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	public virtual extern void AdjustDay([In] int lAdjust, [In] bool bPreserveLocalTime = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743822)]
	public virtual extern void AdjustHour([In] int lAdjust, [In] bool bPreserveLocalTime = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743823)]
	public virtual extern void AdjustMinute([In] int lAdjust, [In] bool bPreserveLocalTime = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	public virtual extern void AdjustMonth([In] int lAdjust, [In] bool bPreserveLocalTime = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	public virtual extern void AdjustSecond([In] int lAdjust, [In] bool bPreserveLocalTime = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743826)]
	public virtual extern void AdjustYear([In] int lAdjust, [In] bool bPreserveLocalTime = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743827)]
	public virtual extern void ConvertToZone([In] int lNewzone, [In] bool bDst);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743828)]
	public virtual extern void SetAnyDate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743829)]
	public virtual extern void SetAnyTime();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743830)]
	public virtual extern void SetNow();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743831)]
	public virtual extern int TimeDifference([In][MarshalAs(UnmanagedType.Interface)] NotesDateTime pIDt);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743832)]
	public virtual extern double TimeDifferenceDouble([In][MarshalAs(UnmanagedType.Interface)] NotesDateTime pIDt);
}
[ComImport]
[Guid("29131564-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesDateTimeClass))]
public interface NotesDateTime : IDateTime
{
}
[ComImport]
[ClassInterface(0)]
[Guid("29131527-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(2)]
[DefaultMember("Name")]
public class NotesDbDirectoryClass : IDbDirectory, NotesDbDirectory
{
	[DispId(0)]
	public virtual extern string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	public virtual extern NotesSession Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743810)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDatabase CreateDatabase([In][MarshalAs(UnmanagedType.BStr)] string pDbfile, [In] bool bOpen = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743811)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDatabase GetFirstDatabase([In][ComAliasName("Domino.DB_TYPES")] DB_TYPES lFiletype);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743812)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDatabase GetNextDatabase();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743813)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDatabase OpenDatabase([In][MarshalAs(UnmanagedType.BStr)] string pDbfile, [In] bool bFailover = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743814)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDatabase OpenDatabaseIfModified([In][MarshalAs(UnmanagedType.BStr)] string pDbfile, [In][MarshalAs(UnmanagedType.Interface)] NotesDateTime pITime);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDatabase OpenMailDatabase();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDatabase OpenDatabaseByReplicaID([In][MarshalAs(UnmanagedType.BStr)] string pRid);
}
[ComImport]
[Guid("29131566-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesDbDirectoryClass))]
public interface NotesDbDirectory : IDbDirectory
{
}
[ComImport]
[Guid("29131528-2EED-1069-BF5D-00DD011186B7")]
[DefaultMember("UniversalID")]
[ClassInterface(0)]
[TypeLibType(2)]
public class NotesDocumentClass : IDocument, NotesDocument
{
	[DispId(1610743808)]
	public virtual extern object Authors
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743809)]
	public virtual extern object ColumnValues
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743810)]
	public virtual extern object Created
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743811)]
	public virtual extern object EmbeddedObjects
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743812)]
	public virtual extern object EncryptionKeys
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1610743814)]
	public virtual extern bool EncryptOnSend
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		set;
	}

	[DispId(1610743816)]
	public virtual extern object FolderReferences
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743817)]
	public virtual extern int FTSearchScore
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		get;
	}

	[DispId(1610743818)]
	public virtual extern bool HasEmbedded
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
	}

	[DispId(1610743819)]
	public virtual extern string HttpURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743820)]
	public virtual extern bool IsDeleted
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		get;
	}

	[DispId(1610743821)]
	public virtual extern bool IsNewNote
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		get;
	}

	[DispId(1610743822)]
	public virtual extern bool IsProfile
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		get;
	}

	[DispId(1610743823)]
	public virtual extern bool IsResponse
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		get;
	}

	[DispId(1610743824)]
	public virtual extern bool IsSigned
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		get;
	}

	[DispId(1610743825)]
	public virtual extern bool IsUIDocOpen
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		get;
	}

	[DispId(1610743826)]
	public virtual extern bool IsValid
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		get;
	}

	[DispId(1610743827)]
	public virtual extern object Items
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743828)]
	public virtual extern string Key
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743829)]
	public virtual extern object LastAccessed
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743830)]
	public virtual extern object LastModified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743831)]
	public virtual extern string NameOfProfile
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743831)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743832)]
	public virtual extern string NoteID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743833)]
	public virtual extern string NotesURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743833)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743834)]
	public virtual extern NotesDatabase ParentDatabase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743834)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743835)]
	public virtual extern string ParentDocumentUNID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743835)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743836)]
	public virtual extern NotesView ParentView
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743836)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743837)]
	public virtual extern NotesDocumentCollection Responses
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743837)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743838)]
	public virtual extern bool SaveMessageOnSend
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743838)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743838)]
		[param: In]
		set;
	}

	[DispId(1610743840)]
	public virtual extern bool SentByAgent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743840)]
		get;
	}

	[DispId(1610743841)]
	public virtual extern string Signer
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743841)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743842)]
	public virtual extern bool SignOnSend
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743842)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743842)]
		[param: In]
		set;
	}

	[DispId(1610743844)]
	public virtual extern int Size
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743844)]
		get;
	}

	[DispId(0)]
	public virtual extern string UniversalID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743847)]
	public virtual extern string Verifier
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743847)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743881)]
	public virtual extern object LockHolders
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743881)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743882)]
	public virtual extern bool IsEncrypted
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743882)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743848)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesItem AppendItemValue([In][MarshalAs(UnmanagedType.BStr)] string pName, [In][MarshalAs(UnmanagedType.Struct)] object Value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743849)]
	public virtual extern bool ComputeWithForm([In] bool bDodatatypes, [In] bool bRaiseerror);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743850)]
	public virtual extern void CopyAllItems([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pIDoc, [In] bool bReplace = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743851)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesItem CopyItem([In][MarshalAs(UnmanagedType.Interface)] NotesItem pIItem, [In][MarshalAs(UnmanagedType.BStr)] string pNewname);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743852)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument CopyToDatabase([In][MarshalAs(UnmanagedType.Interface)] NotesDatabase pIDb);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743853)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument CreateReplyMessage([In] bool bToall);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743854)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesRichTextItem CreateRichTextItem([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743855)]
	public virtual extern void Encrypt();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743856)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesEmbeddedObject GetAttachment([In][MarshalAs(UnmanagedType.BStr)] string pFilename);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743857)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesItem GetFirstItem([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743858)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object GetItemValue([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743859)]
	public virtual extern bool HasItem([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743860)]
	public virtual extern void MakeResponse([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pIDoc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743861)]
	public virtual extern void PutInFolder([In][MarshalAs(UnmanagedType.BStr)] string pName, [In] bool bCreateonfail = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743862)]
	public virtual extern bool Remove([In] bool bForce);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743863)]
	public virtual extern void RemoveFromFolder([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743864)]
	public virtual extern void RemoveItem([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743865)]
	public virtual extern bool RenderToRTItem([In][MarshalAs(UnmanagedType.Interface)] NotesRichTextItem pIRTItem);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743866)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesItem ReplaceItemValue([In][MarshalAs(UnmanagedType.BStr)] string pName, [In][MarshalAs(UnmanagedType.Struct)] object Value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743867)]
	public virtual extern bool Save([In] bool bForce, [In] bool bMakeresponse, [In] bool bMarkread = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743868)]
	public virtual extern void Send([In] bool bAttachform, [Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pRecipients);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743869)]
	public virtual extern void Sign();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743870)]
	public virtual extern bool CloseMIMEEntities([In] bool bSavechanges = false, [In][MarshalAs(UnmanagedType.BStr)] string pName = "Body");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743871)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesMIMEEntity CreateMIMEEntity([In][MarshalAs(UnmanagedType.BStr)] string pName = "Body");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743872)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesMIMEEntity GetMIMEEntity([In][MarshalAs(UnmanagedType.BStr)] string pName = "Body");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743873)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object GetItemValueCustomDataBytes([In][MarshalAs(UnmanagedType.BStr)] string pItemName, [In][MarshalAs(UnmanagedType.BStr)] string pDatatypeName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743874)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object GetItemValueDateTimeArray([In][MarshalAs(UnmanagedType.BStr)] string pItemName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743875)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object GetReceivedItemText();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743876)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesItem ReplaceItemValueCustomDataBytes([In][MarshalAs(UnmanagedType.BStr)] string pItemName, [In][MarshalAs(UnmanagedType.BStr)] string pDatatypeName, [In][MarshalAs(UnmanagedType.Struct)] object CustomData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743877)]
	public virtual extern bool RemovePermanently([In] bool bForce);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743878)]
	public virtual extern bool Lock([Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pName, [In] bool bProvisionalOK = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743879)]
	public virtual extern bool LockProvisional([Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743880)]
	public virtual extern void Unlock();
}
[ComImport]
[CoClass(typeof(NotesDocumentClass))]
[Guid("29131567-2EED-1069-BF5D-00DD011186B7")]
public interface NotesDocument : IDocument
{
}
[ComImport]
[Guid("29131529-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(2)]
[ClassInterface(0)]
public class NotesDocumentCollectionClass : IDocumentCollection, NotesDocumentCollection
{
	[DispId(1610743808)]
	public virtual extern int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
	}

	[DispId(1610743809)]
	public virtual extern bool IsSorted
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		get;
	}

	[DispId(1610743810)]
	public virtual extern NotesDatabase Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743811)]
	public virtual extern string Query
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743826)]
	public virtual extern NotesDateTime UntilTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743812)]
	public virtual extern void AddDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pIDoc, [In] bool bReserved = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743813)]
	public virtual extern void DeleteDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pIDoc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743814)]
	public virtual extern void FTSearch([In][MarshalAs(UnmanagedType.BStr)] string pQuery, [In] int lMaxDocs = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument GetDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pIIndoc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument GetFirstDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743817)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument GetLastDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743818)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument GetNextDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743819)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument GetPrevDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743820)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument GetNthDocument([In] int lN);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	public virtual extern void PutAllInFolder([In][MarshalAs(UnmanagedType.BStr)] string pFolderName, [In] bool bCreateonfail = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743822)]
	public virtual extern void RemoveAll([In] bool bForce);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743823)]
	public virtual extern void RemoveAllFromFolder([In][MarshalAs(UnmanagedType.BStr)] string pFolderName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	public virtual extern void StampAll([In][MarshalAs(UnmanagedType.BStr)] string pItemName, [In][MarshalAs(UnmanagedType.Struct)] object Value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	public virtual extern void UpdateAll();
}
[ComImport]
[Guid("29131568-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesDocumentCollectionClass))]
public interface NotesDocumentCollection : IDocumentCollection
{
}
[ComImport]
[Guid("2913152A-2EED-1069-BF5D-00DD011186B7")]
[DefaultMember("Name")]
[TypeLibType(2)]
[ClassInterface(0)]
public class NotesEmbeddedObjectClass : IEmbeddedObject, NotesEmbeddedObject
{
	[DispId(1610743808)]
	public virtual extern string Class
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	public virtual extern int FileSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		get;
	}

	[DispId(1610743810)]
	public virtual extern bool FitBelowFields
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	public virtual extern bool FitToWindow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		set;
	}

	[DispId(0)]
	public virtual extern string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743815)]
	public virtual extern object Object
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743816)]
	public virtual extern NotesRichTextItem Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743817)]
	public virtual extern bool RunReadOnly
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[param: In]
		set;
	}

	[DispId(1610743819)]
	public virtual extern string Source
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743820)]
	[ComAliasName("Domino.EMBED_TYPE")]
	public virtual extern EMBED_TYPE type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[return: ComAliasName("Domino.EMBED_TYPE")]
		get;
	}

	[DispId(1610743821)]
	public virtual extern object Verbs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743822)]
	[return: MarshalAs(UnmanagedType.IDispatch)]
	public virtual extern object Activate([In] bool bShow);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743823)]
	public virtual extern void DoVerb([In][MarshalAs(UnmanagedType.BStr)] string pVerb);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	public virtual extern void ExtractFile([In][MarshalAs(UnmanagedType.BStr)] string pPath);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	public virtual extern void Remove();
}
[ComImport]
[Guid("29131569-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesEmbeddedObjectClass))]
public interface NotesEmbeddedObject : IEmbeddedObject
{
}
[ComImport]
[Guid("2913152B-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(2)]
[ClassInterface(0)]
[DefaultMember("Name")]
public class NotesFormClass : IForm, NotesForm
{
	[DispId(1610743808)]
	public virtual extern object Aliases
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743809)]
	public virtual extern object Fields
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743810)]
	public virtual extern object FormUsers
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1610743812)]
	public virtual extern string HttpURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743813)]
	public virtual extern bool IsSubForm
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		get;
	}

	[DispId(0)]
	public virtual extern string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743815)]
	public virtual extern string NotesURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743816)]
	public virtual extern NotesDatabase Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743817)]
	public virtual extern bool ProtectReaders
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[param: In]
		set;
	}

	[DispId(1610743819)]
	public virtual extern bool ProtectUsers
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		[param: In]
		set;
	}

	[DispId(1610743821)]
	public virtual extern object Readers
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1610743828)]
	public virtual extern object LockHolders
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743823)]
	[return: ComAliasName("Domino.FIELD_TYPE")]
	public virtual extern FIELD_TYPE GetFieldType([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	public virtual extern void Remove();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	public virtual extern bool Lock([Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pName, [In] bool bProvisionalOK = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743826)]
	public virtual extern bool LockProvisional([Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743827)]
	public virtual extern void Unlock();
}
[ComImport]
[Guid("2913156A-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesFormClass))]
public interface NotesForm : IForm
{
}
[ComImport]
[Guid("2913152C-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(2)]
[ClassInterface(0)]
[DefaultMember("Name")]
public class NotesItemClass : IItem2, NotesItem, IItem
{
	[DispId(1610743808)]
	public virtual extern NotesDateTime DateTimeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1610743810)]
	public virtual extern bool IsAuthors
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	public virtual extern bool IsEncrypted
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		set;
	}

	[DispId(1610743814)]
	public virtual extern bool IsNames
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		set;
	}

	[DispId(1610743816)]
	public virtual extern bool IsProtected
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[param: In]
		set;
	}

	[DispId(1610743818)]
	public virtual extern bool IsReaders
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[param: In]
		set;
	}

	[DispId(1610743820)]
	public virtual extern bool IsSigned
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[param: In]
		set;
	}

	[DispId(1610743822)]
	public virtual extern bool IsSummary
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[param: In]
		set;
	}

	[DispId(1610743824)]
	public virtual extern object LastModified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(0)]
	public virtual extern string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743826)]
	public virtual extern NotesDocument Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743827)]
	public virtual extern bool SaveToDisk
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		[param: In]
		set;
	}

	[DispId(1610743829)]
	public virtual extern string Text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("Domino.IT_TYPE")]
	[DispId(1610743830)]
	public virtual extern IT_TYPE type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		[return: ComAliasName("Domino.IT_TYPE")]
		get;
	}

	[DispId(1610743831)]
	public virtual extern int ValueLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743831)]
		get;
	}

	[DispId(1610743832)]
	public virtual extern object Values
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	public virtual extern NotesDateTime IItem_DateTimeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	public virtual extern bool IItem_IsAuthors
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern bool IItem_IsEncrypted
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern bool IItem_IsNames
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern bool IItem_IsProtected
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern bool IItem_IsReaders
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern bool IItem_IsSigned
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern bool IItem_IsSummary
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern object IItem_LastModified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	public virtual extern string IItem_Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	public virtual extern NotesDocument IItem_Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	public virtual extern bool IItem_SaveToDisk
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		set;
	}

	public virtual extern string IItem_Text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("Domino.IT_TYPE")]
	public virtual extern IT_TYPE IItem_type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: ComAliasName("Domino.IT_TYPE")]
		get;
	}

	public virtual extern int IItem_ValueLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		get;
	}

	public virtual extern object IItem_Values
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743834)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string Abstract([In] int lMaxlen, [In] bool bDropvowels, [In] bool bUsedict);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743835)]
	public virtual extern void AppendToTextList([In][MarshalAs(UnmanagedType.Struct)] object Values);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743836)]
	public virtual extern bool Contains([In][MarshalAs(UnmanagedType.Struct)] object Value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743837)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesItem CopyItemToDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pIDoc, [In][MarshalAs(UnmanagedType.BStr)] string pNewname);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743838)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesMIMEEntity GetMIMEEntity();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743839)]
	public virtual extern void Remove();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809344)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object GetValueCustomDataBytes([In][MarshalAs(UnmanagedType.BStr)] string pDatatypeName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809345)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object GetValueDateTimeArray();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809346)]
	public virtual extern void SetValueCustomDataBytes([In][MarshalAs(UnmanagedType.BStr)] string pDatatypeName, [In][MarshalAs(UnmanagedType.Struct)] object CustomData);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string IItem_Abstract([In] int lMaxlen, [In] bool bDropvowels, [In] bool bUsedict);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IItem_AppendToTextList([In][MarshalAs(UnmanagedType.Struct)] object Values);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern bool IItem_Contains([In][MarshalAs(UnmanagedType.Struct)] object Value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesItem IItem_CopyItemToDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pIDoc, [In][MarshalAs(UnmanagedType.BStr)] string pNewname);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesMIMEEntity IItem_GetMIMEEntity();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	public virtual extern void IItem_Remove();
}
[ComImport]
[CoClass(typeof(NotesItemClass))]
[Guid("2913158A-2EED-1069-BF5D-00DD011186B7")]
public interface NotesItem : IItem2
{
}
[ComImport]
[Guid("2913152D-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(2)]
[ClassInterface(0)]
public class NotesInternationalClass : IInternational, NotesInternational
{
	[DispId(1610743808)]
	public virtual extern string AMString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	public virtual extern int CurrencyDigits
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		get;
	}

	[DispId(1610743810)]
	public virtual extern string CurrencySymbol
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743811)]
	public virtual extern string DateSep
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743812)]
	public virtual extern string DecimalSep
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743813)]
	public virtual extern bool IsCurrencySpace
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		get;
	}

	[DispId(1610743814)]
	public virtual extern bool IsCurrencySuffix
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
	}

	[DispId(1610743815)]
	public virtual extern bool IsCurrencyZero
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		get;
	}

	[DispId(1610743816)]
	public virtual extern bool IsDateDMY
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
	}

	[DispId(1610743817)]
	public virtual extern bool IsDateMDY
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		get;
	}

	[DispId(1610743818)]
	public virtual extern bool IsDateYMD
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
	}

	[DispId(1610743819)]
	public virtual extern bool IsDST
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		get;
	}

	[DispId(1610743820)]
	public virtual extern bool IsTime24Hour
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		get;
	}

	[DispId(1610743821)]
	public virtual extern NotesSession Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743822)]
	public virtual extern string PMString
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743823)]
	public virtual extern string ThousandsSep
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743824)]
	public virtual extern string TimeSep
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743825)]
	public virtual extern int TimeZone
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		get;
	}

	[DispId(1610743826)]
	public virtual extern string Today
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743827)]
	public virtual extern string Tomorrow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743828)]
	public virtual extern string Yesterday
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[Guid("2913156C-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesInternationalClass))]
public interface NotesInternational : IInternational
{
}
[ComImport]
[Guid("2913152E-2EED-1069-BF5D-00DD011186B7")]
[ClassInterface(0)]
[DefaultMember("ProgramName")]
[TypeLibType(2)]
public class NotesLogClass : ILog, NotesLog
{
	[DispId(1610743808)]
	public virtual extern bool LogActions
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		set;
	}

	[DispId(1610743810)]
	public virtual extern bool LogErrors
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	public virtual extern int NumActions
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
	}

	[DispId(1610743813)]
	public virtual extern int NumErrors
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		get;
	}

	[DispId(1610743814)]
	public virtual extern bool OverwriteFile
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		set;
	}

	[DispId(0)]
	public virtual extern string ProgramName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743818)]
	public virtual extern NotesSession Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743819)]
	public virtual extern void Close();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743820)]
	public virtual extern void LogAction([In][MarshalAs(UnmanagedType.BStr)] string pAction);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	public virtual extern void LogError([In] int lCode, [In][MarshalAs(UnmanagedType.BStr)] string pText);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743822)]
	public virtual extern void LogEvent([In][MarshalAs(UnmanagedType.BStr)] string pText, [In][MarshalAs(UnmanagedType.BStr)] string pQueue, [In][ComAliasName("Domino.LOG_EVENTS")] LOG_EVENTS lEvent, [In][ComAliasName("Domino.LOG_SEVERITY")] LOG_SEVERITY lSeverity);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743823)]
	public virtual extern void OpenAgentLog();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	public virtual extern void OpenFileLog([In][MarshalAs(UnmanagedType.BStr)] string pFilepath);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	public virtual extern void OpenMailLog([In][MarshalAs(UnmanagedType.Struct)] object Recipients, [In][MarshalAs(UnmanagedType.BStr)] string pSubject);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743826)]
	public virtual extern void OpenNotesLog([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pDatabase);
}
[ComImport]
[Guid("2913156D-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesLogClass))]
public interface NotesLog : ILog
{
}
[ComImport]
[ClassInterface(0)]
[DefaultMember("Canonical")]
[Guid("2913152F-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(2)]
public class NotesNameClass : IName, NotesName
{
	[DispId(1610743808)]
	public virtual extern string Abbreviated
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	public virtual extern string Addr821
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743810)]
	public virtual extern string Addr822Comment1
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743811)]
	public virtual extern string Addr822Comment2
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743812)]
	public virtual extern string Addr822Comment3
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743813)]
	public virtual extern string Addr822LocalPart
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743814)]
	public virtual extern string Addr822Phrase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743815)]
	public virtual extern string ADMD
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(0)]
	public virtual extern string Canonical
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743817)]
	public virtual extern string Common
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743818)]
	public virtual extern string Country
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743819)]
	public virtual extern string Generation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743820)]
	public virtual extern string Given
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743821)]
	public virtual extern string Initials
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743822)]
	public virtual extern bool IsHierarchical
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		get;
	}

	[DispId(1610743823)]
	public virtual extern string Keyword
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743824)]
	public virtual extern string Language
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743825)]
	public virtual extern string Organization
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743826)]
	public virtual extern string OrgUnit1
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743827)]
	public virtual extern string OrgUnit2
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743828)]
	public virtual extern string OrgUnit3
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743829)]
	public virtual extern string OrgUnit4
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743830)]
	public virtual extern NotesSession Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743831)]
	public virtual extern string PRMD
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743831)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743832)]
	public virtual extern string Surname
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}
}
[ComImport]
[Guid("2913156E-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesNameClass))]
public interface NotesName : IName
{
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("29131530-2EED-1069-BF5D-00DD011186B7")]
public class NotesNewsletterClass : INewsletter, NotesNewsletter
{
	[DispId(1610743808)]
	public virtual extern bool DoScore
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		set;
	}

	[DispId(1610743810)]
	public virtual extern bool DoSubject
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	public virtual extern NotesSession Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743813)]
	public virtual extern string SubjectItemName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument FormatDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDatabase pIDb, [In] int lIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument FormatMsgWithDoclinks([In][MarshalAs(UnmanagedType.Interface)] NotesDatabase pIDb);
}
[ComImport]
[CoClass(typeof(NotesNewsletterClass))]
[Guid("2913156F-2EED-1069-BF5D-00DD011186B7")]
public interface NotesNewsletter : INewsletter
{
}
[ComImport]
[Guid("29131531-2EED-1069-BF5D-00DD011186B7")]
[ClassInterface(0)]
[TypeLibType(2)]
public class NotesOutlineClass : IOutline, NotesOutline
{
	[DispId(1610743808)]
	public virtual extern string Alias
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743810)]
	public virtual extern string Comment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743812)]
	public virtual extern string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743814)]
	public virtual extern NotesDatabase ParentDatabase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesOutlineEntry CreateEntry([In][MarshalAs(UnmanagedType.BStr)] string pEntryName, [In][MarshalAs(UnmanagedType.Interface)] NotesOutlineEntry pRefEntry, [In] bool bAfter = true, [In] bool bAsChild = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesOutlineEntry CreateEntryFrom([In][MarshalAs(UnmanagedType.Interface)] NotesOutlineEntry pFromEntry, [In][MarshalAs(UnmanagedType.Interface)] NotesOutlineEntry pRefEntry, [In] bool bAfter = true, [In] bool bAsChild = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743817)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesOutlineEntry GetFirst();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743818)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesOutlineEntry GetLast();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743819)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesOutlineEntry GetParent([In][MarshalAs(UnmanagedType.Interface)] NotesOutlineEntry pIEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743820)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesOutlineEntry GetNext([In][MarshalAs(UnmanagedType.Interface)] NotesOutlineEntry pIEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesOutlineEntry GetNextSibling([In][MarshalAs(UnmanagedType.Interface)] NotesOutlineEntry pIEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743822)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesOutlineEntry GetPrev([In][MarshalAs(UnmanagedType.Interface)] NotesOutlineEntry pIEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743823)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesOutlineEntry GetPrevSibling([In][MarshalAs(UnmanagedType.Interface)] NotesOutlineEntry pIEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	public virtual extern void MoveEntry([In][MarshalAs(UnmanagedType.Interface)] NotesOutlineEntry pIEntry, [In][MarshalAs(UnmanagedType.Interface)] NotesOutlineEntry pIRefEntry, [In] bool bAfter = true, [In] bool bAsChild = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	public virtual extern void RemoveEntry([In][MarshalAs(UnmanagedType.Interface)] NotesOutlineEntry pIEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743826)]
	public virtual extern void Save();
}
[ComImport]
[Guid("29131570-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesOutlineClass))]
public interface NotesOutline : IOutline
{
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("29131532-2EED-1069-BF5D-00DD011186B7")]
public class NotesOutlineEntryClass : IOutlineEntry, NotesOutlineEntry
{
	[DispId(1610743808)]
	public virtual extern string Alias
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743810)]
	public virtual extern NotesDatabase DATABASE
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743811)]
	public virtual extern NotesDocument Document
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[ComAliasName("Domino.OE_CLASS")]
	[DispId(1610743812)]
	public virtual extern OE_CLASS EntryClass
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: ComAliasName("Domino.OE_CLASS")]
		get;
	}

	[DispId(1610743813)]
	public virtual extern string FrameText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743815)]
	public virtual extern string Formula
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743816)]
	public virtual extern bool HasChildren
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
	}

	[DispId(1610743817)]
	public virtual extern string HideFormula
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743819)]
	public virtual extern string ImagesText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743821)]
	public virtual extern bool IsHiddenFromNotes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[param: In]
		set;
	}

	[DispId(1610743823)]
	public virtual extern bool IsHiddenFromWeb
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		[param: In]
		set;
	}

	[DispId(1610743825)]
	public virtual extern bool IsInThisDB
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		get;
	}

	[DispId(1610743826)]
	public virtual extern bool IsPrivate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		get;
	}

	[DispId(1610743827)]
	public virtual extern bool KeepSelectionFocus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		[param: In]
		set;
	}

	[DispId(1610743829)]
	public virtual extern string Label
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743831)]
	public virtual extern int Level
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743831)]
		get;
	}

	[DispId(1610743832)]
	public virtual extern string NamedElement
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743833)]
	public virtual extern NotesOutline Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743833)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[ComAliasName("Domino.OE_TYPE")]
	[DispId(1610743834)]
	public virtual extern OE_TYPE type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743834)]
		[return: ComAliasName("Domino.OE_TYPE")]
		get;
	}

	[DispId(1610743835)]
	public virtual extern string URL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743835)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743836)]
	public virtual extern bool UseHideFormula
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743836)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743836)]
		[param: In]
		set;
	}

	[DispId(1610743838)]
	public virtual extern NotesView View
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743838)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743839)]
	public virtual extern void SetAction([In][MarshalAs(UnmanagedType.BStr)] string pFormula);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743840)]
	public virtual extern void SetNamedElement([In][MarshalAs(UnmanagedType.Interface)] NotesDatabase pIDb, [In][MarshalAs(UnmanagedType.BStr)] string pElementName, [In][ComAliasName("Domino.OE_CLASS")] OE_CLASS lClass);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743841)]
	public virtual extern void SetNoteLink([In][MarshalAs(UnmanagedType.IUnknown)] object pIObj);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743842)]
	public virtual extern void SetURL([In][MarshalAs(UnmanagedType.BStr)] string pURL);
}
[ComImport]
[CoClass(typeof(NotesOutlineEntryClass))]
[Guid("29131571-2EED-1069-BF5D-00DD011186B7")]
public interface NotesOutlineEntry : IOutlineEntry
{
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[DefaultMember("Name")]
[Guid("29131533-2EED-1069-BF5D-00DD011186B7")]
public class NotesRichTextItemClass : IRichTextItem, NotesRichTextItem
{
	[DispId(1610743808)]
	public virtual extern NotesDateTime DateTimeValue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[DispId(1610743810)]
	public virtual extern bool IsAuthors
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	public virtual extern bool IsEncrypted
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		set;
	}

	[DispId(1610743814)]
	public virtual extern bool IsNames
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		set;
	}

	[DispId(1610743816)]
	public virtual extern bool IsProtected
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[param: In]
		set;
	}

	[DispId(1610743818)]
	public virtual extern bool IsReaders
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[param: In]
		set;
	}

	[DispId(1610743820)]
	public virtual extern bool IsSigned
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[param: In]
		set;
	}

	[DispId(1610743822)]
	public virtual extern bool IsSummary
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[param: In]
		set;
	}

	[DispId(1610743824)]
	public virtual extern object LastModified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(0)]
	public virtual extern string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743826)]
	public virtual extern NotesDocument Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743827)]
	public virtual extern bool SaveToDisk
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		[param: In]
		set;
	}

	[DispId(1610743829)]
	public virtual extern string Text
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743830)]
	[ComAliasName("Domino.IT_TYPE")]
	public virtual extern IT_TYPE type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		[return: ComAliasName("Domino.IT_TYPE")]
		get;
	}

	[DispId(1610743831)]
	public virtual extern int ValueLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743831)]
		get;
	}

	[DispId(1610743832)]
	public virtual extern object Values
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1610809344)]
	public virtual extern object EmbeddedObjects
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610809344)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743834)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string Abstract([In] int lMaxlen, [In] bool bDropvowels, [In] bool bUsedict);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743835)]
	public virtual extern void AppendToTextList([In][MarshalAs(UnmanagedType.Struct)] object Values);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743836)]
	public virtual extern bool Contains([In][MarshalAs(UnmanagedType.Struct)] object Value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743837)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesItem CopyItemToDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pIDoc, [In][MarshalAs(UnmanagedType.BStr)] string pNewname);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743838)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesMIMEEntity GetMIMEEntity();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743839)]
	public virtual extern void Remove();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809345)]
	public virtual extern void AddNewLine([In] int lCount = 1, [In] bool bNewparagraph = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809346)]
	public virtual extern void AddPageBreak([In][MarshalAs(UnmanagedType.Interface)] NotesRichTextParagraphStyle pIStyle);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809347)]
	public virtual extern void AddTab([In] int lCount = 1);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809348)]
	public virtual extern void AppendDocLink([In][MarshalAs(UnmanagedType.IUnknown)] object pIObj, [In][MarshalAs(UnmanagedType.BStr)] string pComment, [In][MarshalAs(UnmanagedType.BStr)] string pHotspottext = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809349)]
	public virtual extern void AppendParagraphStyle([In][MarshalAs(UnmanagedType.Interface)] NotesRichTextParagraphStyle pIStyle);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809350)]
	public virtual extern void AppendRTItem([In][MarshalAs(UnmanagedType.Interface)] NotesRichTextItem pIRTItem);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809351)]
	public virtual extern void AppendStyle([In][MarshalAs(UnmanagedType.Interface)] NotesRichTextStyle pIStyle);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809352)]
	public virtual extern void AppendText([In][MarshalAs(UnmanagedType.BStr)] string pText);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809353)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesEmbeddedObject EmbedObject([In][ComAliasName("Domino.EMBED_TYPE")] EMBED_TYPE lType, [In][MarshalAs(UnmanagedType.BStr)] string pClass, [In][MarshalAs(UnmanagedType.BStr)] string pSource, [In][MarshalAs(UnmanagedType.BStr)] string pName = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809354)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesEmbeddedObject GetEmbeddedObject([In][MarshalAs(UnmanagedType.BStr)] string pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809355)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetFormattedText([In] bool bTabstrip, [In] int lLinelen);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809356)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesRichTextNavigator CreateNavigator();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809357)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesRichTextRange CreateRange();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809358)]
	public virtual extern void AppendTable([In] int lRowCount = 0, [In] int lColumnCount = 0, [Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pRowLabels, [In] int lLeftMargin = 1440, [Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pRTPStyleArray);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809359)]
	public virtual extern void BeginInsert([In][MarshalAs(UnmanagedType.Struct)] ref object pElement, [In] bool bAfter = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809360)]
	public virtual extern void EndInsert();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809361)]
	public virtual extern void BeginSection([In][MarshalAs(UnmanagedType.BStr)] string pTitle, [In][MarshalAs(UnmanagedType.Interface)] NotesRichTextStyle pTitleStyle = null, [In][MarshalAs(UnmanagedType.Interface)] NotesColorObject pBarColor = null, [In] bool bExpand = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809362)]
	public virtual extern void EndSection();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809363)]
	public virtual extern int GetNotesFont([In][MarshalAs(UnmanagedType.BStr)] string pFaceName, [In] bool bAddOnFail = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809364)]
	public virtual extern void Update();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809365)]
	public virtual extern void Compact();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610809366)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetUnformattedText();
}
[ComImport]
[Guid("29131574-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesRichTextItemClass))]
public interface NotesRichTextItem : IRichTextItem
{
}
[ComImport]
[Guid("29131534-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(2)]
[ClassInterface(0)]
public class NotesRichTextStyleClass : IRichTextStyle, NotesRichTextStyle
{
	[DispId(1610743808)]
	public virtual extern int Bold
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		set;
	}

	[ComAliasName("Domino.RT_EFFECTS")]
	[DispId(1610743810)]
	public virtual extern RT_EFFECTS Effects
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: ComAliasName("Domino.RT_EFFECTS")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		[param: ComAliasName("Domino.RT_EFFECTS")]
		set;
	}

	[DispId(1610743812)]
	public virtual extern int FontSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		set;
	}

	[DispId(1610743814)]
	public virtual extern int Italic
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		set;
	}

	[DispId(1610743816)]
	[ComAliasName("Domino.COLORS")]
	public virtual extern COLORS NotesColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[return: ComAliasName("Domino.COLORS")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[param: In]
		[param: ComAliasName("Domino.COLORS")]
		set;
	}

	[DispId(1610743818)]
	[ComAliasName("Domino.RT_FONTS")]
	public virtual extern RT_FONTS NotesFont
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[return: ComAliasName("Domino.RT_FONTS")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[param: In]
		[param: ComAliasName("Domino.RT_FONTS")]
		set;
	}

	[DispId(1610743820)]
	public virtual extern int PassThruHTML
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[param: In]
		set;
	}

	[DispId(1610743822)]
	public virtual extern int StrikeThrough
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[param: In]
		set;
	}

	[DispId(1610743824)]
	public virtual extern int Underline
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[param: In]
		set;
	}

	[DispId(1610743826)]
	public virtual extern NotesSession Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743827)]
	public virtual extern bool IsDefault
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		get;
	}
}
[ComImport]
[Guid("29131575-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesRichTextStyleClass))]
public interface NotesRichTextStyle : IRichTextStyle
{
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("29131535-2EED-1069-BF5D-00DD011186B7")]
public class NotesRichTextParagraphStyleClass : IRichTextParagraphStyle, NotesRichTextParagraphStyle
{
	[ComAliasName("Domino.RT_ALIGN")]
	[DispId(1610743808)]
	public virtual extern RT_ALIGN Alignment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: ComAliasName("Domino.RT_ALIGN")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: ComAliasName("Domino.RT_ALIGN")]
		set;
	}

	[DispId(1610743810)]
	public virtual extern int FirstLineLeftMargin
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[ComAliasName("Domino.SPACING")]
	[DispId(1610743812)]
	public virtual extern SPACING InterLineSpacing
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: ComAliasName("Domino.SPACING")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		[param: ComAliasName("Domino.SPACING")]
		set;
	}

	[DispId(1610743814)]
	public virtual extern int LeftMargin
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		set;
	}

	[DispId(1610743816)]
	[ComAliasName("Domino.RT_PAGINATE")]
	public virtual extern RT_PAGINATE Pagination
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[return: ComAliasName("Domino.RT_PAGINATE")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[param: In]
		[param: ComAliasName("Domino.RT_PAGINATE")]
		set;
	}

	[DispId(1610743818)]
	public virtual extern int RightMargin
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[param: In]
		set;
	}

	[ComAliasName("Domino.SPACING")]
	[DispId(1610743820)]
	public virtual extern SPACING SpacingAbove
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[return: ComAliasName("Domino.SPACING")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[param: In]
		[param: ComAliasName("Domino.SPACING")]
		set;
	}

	[ComAliasName("Domino.SPACING")]
	[DispId(1610743822)]
	public virtual extern SPACING SpacingBelow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[return: ComAliasName("Domino.SPACING")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[param: In]
		[param: ComAliasName("Domino.SPACING")]
		set;
	}

	[DispId(1610743824)]
	public virtual extern object Tabs
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	public virtual extern void ClearAllTabs();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743826)]
	public virtual extern void SetTab([In] int lPosition, [In][ComAliasName("Domino.RT_TAB")] RT_TAB lType = RT_TAB.TAB_LEFT);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743827)]
	public virtual extern void SetTabs([In] int lCount, [In] int lPosition, [In] int lInterval = 1, [In][ComAliasName("Domino.RT_TAB")] RT_TAB lType = RT_TAB.TAB_LEFT);
}
[ComImport]
[Guid("29131576-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesRichTextParagraphStyleClass))]
public interface NotesRichTextParagraphStyle : IRichTextParagraphStyle
{
}
[ComImport]
[ClassInterface(0)]
[Guid("29131536-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(2)]
public class NotesRichTextTabClass : IRichTextTab, NotesRichTextTab
{
	[DispId(1610743808)]
	public virtual extern int Position
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
	}

	[DispId(1610743809)]
	[ComAliasName("Domino.RT_TAB")]
	public virtual extern RT_TAB type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: ComAliasName("Domino.RT_TAB")]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743810)]
	public virtual extern void Clear();
}
[ComImport]
[CoClass(typeof(NotesRichTextTabClass))]
[Guid("29131577-2EED-1069-BF5D-00DD011186B7")]
public interface NotesRichTextTab : IRichTextTab
{
}
[ComImport]
[TypeLibType(4160)]
[Guid("29131577-2EED-1069-BF5D-00DD011186B7")]
public interface IRichTextTab
{
	[DispId(1610743808)]
	int Position
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
	}

	[DispId(1610743809)]
	[ComAliasName("Domino.RT_TAB")]
	RT_TAB type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: ComAliasName("Domino.RT_TAB")]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743810)]
	void Clear();
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("29131537-2EED-1069-BF5D-00DD011186B7")]
public class NotesRegistrationClass : IRegistration, NotesRegistration
{
	[DispId(1610743808)]
	public virtual extern string CertifierIDFile
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743810)]
	public virtual extern bool CreateMailDb
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	public virtual extern object Expiration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1610743814)]
	[ComAliasName("Domino.REG_TYPE")]
	public virtual extern REG_TYPE IDType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[return: ComAliasName("Domino.REG_TYPE")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		[param: ComAliasName("Domino.REG_TYPE")]
		set;
	}

	[DispId(1610743816)]
	public virtual extern bool IsNorthAmerican
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[param: In]
		set;
	}

	[DispId(1610743818)]
	public virtual extern int MinPasswordLength
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[param: In]
		set;
	}

	[DispId(1610743820)]
	public virtual extern string OrgUnit
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743822)]
	public virtual extern string RegistrationLog
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743824)]
	public virtual extern string RegistrationServer
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743826)]
	public virtual extern bool StoreIDInAddressBook
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[param: In]
		set;
	}

	[DispId(1610743828)]
	public virtual extern bool UpdateAddressBook
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		[param: In]
		set;
	}

	[DispId(1610743843)]
	public virtual extern string CertifierName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743843)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743843)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743845)]
	public virtual extern string MailACLManager
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743845)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743845)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743847)]
	public virtual extern string MailInternetAddress
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743847)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743847)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743849)]
	public virtual extern string MailTemplateName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743849)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743849)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743851)]
	public virtual extern string PolicyName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743851)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743851)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743853)]
	public virtual extern string RoamingServer
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743853)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743853)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743855)]
	public virtual extern string RoamingSubdir
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743855)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743855)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743857)]
	public virtual extern string ShortName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743857)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743857)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743859)]
	public virtual extern bool EnforceUniqueShortName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743859)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743859)]
		[param: In]
		set;
	}

	[DispId(1610743861)]
	public virtual extern bool IsRoamingUser
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743861)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743861)]
		[param: In]
		set;
	}

	[DispId(1610743863)]
	public virtual extern bool MailCreateFTIndex
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743863)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743863)]
		[param: In]
		set;
	}

	[DispId(1610743865)]
	public virtual extern bool NoIDFile
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743865)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743865)]
		[param: In]
		set;
	}

	[DispId(1610743867)]
	public virtual extern bool StoreIDInMailfile
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743867)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743867)]
		[param: In]
		set;
	}

	[DispId(1610743869)]
	public virtual extern bool SynchInternetPassword
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743869)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743869)]
		[param: In]
		set;
	}

	[DispId(1610743871)]
	public virtual extern bool UseCertificateAuthority
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743871)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743871)]
		[param: In]
		set;
	}

	[DispId(1610743873)]
	[ComAliasName("Domino.REG_MAILOWNACL")]
	public virtual extern REG_MAILOWNACL MailOwnerAccess
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743873)]
		[return: ComAliasName("Domino.REG_MAILOWNACL")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743873)]
		[param: In]
		[param: ComAliasName("Domino.REG_MAILOWNACL")]
		set;
	}

	[DispId(1610743875)]
	[ComAliasName("Domino.REG_MAILTYPE")]
	public virtual extern REG_MAILTYPE MailSystem
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743875)]
		[return: ComAliasName("Domino.REG_MAILTYPE")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743875)]
		[param: In]
		[param: ComAliasName("Domino.REG_MAILTYPE")]
		set;
	}

	[ComAliasName("Domino.REG_ROAMCLEANUP")]
	[DispId(1610743877)]
	public virtual extern REG_ROAMCLEANUP RoamingCleanupSetting
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743877)]
		[return: ComAliasName("Domino.REG_ROAMCLEANUP")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743877)]
		[param: In]
		[param: ComAliasName("Domino.REG_ROAMCLEANUP")]
		set;
	}

	[DispId(1610743879)]
	public virtual extern int MailQuotaSizeLimit
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743879)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743879)]
		[param: In]
		set;
	}

	[DispId(1610743881)]
	public virtual extern int MailQuotaWarningThreshold
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743881)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743881)]
		[param: In]
		set;
	}

	[DispId(1610743883)]
	public virtual extern int RoamingCleanupPeriod
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743883)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743883)]
		[param: In]
		set;
	}

	[DispId(1610743885)]
	public virtual extern object GroupList
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743885)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743885)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1610743887)]
	public virtual extern object MailReplicaServers
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743887)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743887)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1610743889)]
	public virtual extern object AltOrgUnit
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743889)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743889)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1610743891)]
	public virtual extern object AltOrgUnitLang
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743891)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743891)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743830)]
	public virtual extern void AddCertifierToAddressBook([In][MarshalAs(UnmanagedType.BStr)] string pIdfile, [In][MarshalAs(UnmanagedType.BStr)] string pPassword = "", [In][MarshalAs(UnmanagedType.BStr)] string pLocation = "", [In][MarshalAs(UnmanagedType.BStr)] string pComment = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743831)]
	public virtual extern void AddServerToAddressBook([In][MarshalAs(UnmanagedType.BStr)] string pIdfile, [In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pDomain, [In][MarshalAs(UnmanagedType.BStr)] string pUserpw = "", [In][MarshalAs(UnmanagedType.BStr)] string pNetwork = "", [In][MarshalAs(UnmanagedType.BStr)] string pAdminname = "", [In][MarshalAs(UnmanagedType.BStr)] string pTitle = "", [In][MarshalAs(UnmanagedType.BStr)] string pLocation = "", [In][MarshalAs(UnmanagedType.BStr)] string pComment = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743832)]
	public virtual extern void AddUserProfile([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In][MarshalAs(UnmanagedType.BStr)] string pProfile);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743833)]
	public virtual extern void AddUserToAddressBook([In][MarshalAs(UnmanagedType.BStr)] string pIdfile, [In][MarshalAs(UnmanagedType.BStr)] string pFullname, [In][MarshalAs(UnmanagedType.BStr)] string pLastn, [In][MarshalAs(UnmanagedType.BStr)] string pUserpw = "", [In][MarshalAs(UnmanagedType.BStr)] string pFirstn = "", [In][MarshalAs(UnmanagedType.BStr)] string pMiddle = "", [In][MarshalAs(UnmanagedType.BStr)] string pMailserv = "", [In][MarshalAs(UnmanagedType.BStr)] string pMailfilepath = "", [In][MarshalAs(UnmanagedType.BStr)] string pFwdaddr = "", [In][MarshalAs(UnmanagedType.BStr)] string pLocation = "", [In][MarshalAs(UnmanagedType.BStr)] string pComment = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743834)]
	public virtual extern void CrossCertify([In][MarshalAs(UnmanagedType.BStr)] string pIdfile, [In][MarshalAs(UnmanagedType.BStr)] string pCertpw = "", [In][MarshalAs(UnmanagedType.BStr)] string pComment = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743835)]
	public virtual extern void DeleteIDOnServer([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In] bool bIsserverid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743836)]
	public virtual extern void GetIDFromServer([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In][MarshalAs(UnmanagedType.BStr)] string pFilepath, [In] bool bIsserverid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743837)]
	public virtual extern void GetUserInfo([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [Optional][DefaultParameterValue("0")][MarshalAs(UnmanagedType.BStr)] out string ppMailserver, [Optional][DefaultParameterValue("0")][MarshalAs(UnmanagedType.BStr)] out string ppMailfile, [Optional][DefaultParameterValue("0")][MarshalAs(UnmanagedType.BStr)] out string ppMaildomain, [Optional][DefaultParameterValue(0)] out int pMailsystem, [Optional][DefaultParameterValue(0)][MarshalAs(UnmanagedType.Struct)] out object pProfile);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743838)]
	public virtual extern void Recertify([In][MarshalAs(UnmanagedType.BStr)] string pIdfile, [In][MarshalAs(UnmanagedType.BStr)] string pCertpw = "", [In][MarshalAs(UnmanagedType.BStr)] string pComment = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743839)]
	public virtual extern void RegisterNewCertifier([In][MarshalAs(UnmanagedType.BStr)] string pOrg, [In][MarshalAs(UnmanagedType.BStr)] string pIdfile, [In][MarshalAs(UnmanagedType.BStr)] string pCertpw, [In][MarshalAs(UnmanagedType.BStr)] string pCountry = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743840)]
	public virtual extern void RegisterNewServer([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pIdfile, [In][MarshalAs(UnmanagedType.BStr)] string pDomain, [In][MarshalAs(UnmanagedType.BStr)] string pServerpw = "", [In][MarshalAs(UnmanagedType.BStr)] string pCertpw = "", [In][MarshalAs(UnmanagedType.BStr)] string pLocation = "", [In][MarshalAs(UnmanagedType.BStr)] string pComment = "", [In][MarshalAs(UnmanagedType.BStr)] string pNetwork = "", [In][MarshalAs(UnmanagedType.BStr)] string pAdminname = "", [In][MarshalAs(UnmanagedType.BStr)] string pTitle = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743841)]
	public virtual extern void RegisterNewUser([In][MarshalAs(UnmanagedType.BStr)] string pLastn, [In][MarshalAs(UnmanagedType.BStr)] string pIdfile, [In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pFirstn = "", [In][MarshalAs(UnmanagedType.BStr)] string pMiddle = "", [In][MarshalAs(UnmanagedType.BStr)] string pCertpw = "", [In][MarshalAs(UnmanagedType.BStr)] string pLocation = "", [In][MarshalAs(UnmanagedType.BStr)] string pComment = "", [In][MarshalAs(UnmanagedType.BStr)] string pMaildbpath = "", [In][MarshalAs(UnmanagedType.BStr)] string pForward = "", [In][MarshalAs(UnmanagedType.BStr)] string pUserpw = "", [In][MarshalAs(UnmanagedType.BStr)] string pAltName = "", [In][MarshalAs(UnmanagedType.BStr)] string pAltLang = "", [In][ComAliasName("Domino.USER_TYPE")] USER_TYPE type = USER_TYPE.NOTES_FULL_CLIENT);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743842)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string SwitchToID([In][MarshalAs(UnmanagedType.BStr)] string pIdfile, [In][MarshalAs(UnmanagedType.BStr)] string pUserpw = "");
}
[ComImport]
[Guid("29131572-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesRegistrationClass))]
public interface NotesRegistration : IRegistration
{
}
[ComImport]
[ClassInterface(0)]
[Guid("29131538-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(2)]
public class NotesReplicationClass : IReplication, NotesReplication
{
	[DispId(1610743808)]
	public virtual extern bool Abstract
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		set;
	}

	[DispId(1610743810)]
	public virtual extern object CutoffDate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743811)]
	public virtual extern bool CutoffDelete
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[param: In]
		set;
	}

	[DispId(1610743813)]
	public virtual extern int CutoffInterval
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[param: In]
		set;
	}

	[DispId(1610743815)]
	public virtual extern bool Disabled
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[param: In]
		set;
	}

	[DispId(1610743817)]
	public virtual extern bool IgnoreDeletes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[param: In]
		set;
	}

	[DispId(1610743819)]
	public virtual extern bool IgnoreDestDeletes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		[param: In]
		set;
	}

	[ComAliasName("Domino.RP_PRIORITY")]
	[DispId(1610743821)]
	public virtual extern RP_PRIORITY Priority
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[return: ComAliasName("Domino.RP_PRIORITY")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[param: In]
		[param: ComAliasName("Domino.RP_PRIORITY")]
		set;
	}

	[DispId(1610743826)]
	public virtual extern bool DontSendLocalSecurityUpdates
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743823)]
	public virtual extern void ClearHistory();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	public virtual extern void Reset();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	public virtual extern void Save();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743828)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesReplicationEntry GetEntry([In][MarshalAs(UnmanagedType.BStr)] string pSourceServer, [In][MarshalAs(UnmanagedType.BStr)] string pDestinationServer, [In] bool bCreate = false);
}
[ComImport]
[Guid("29131573-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesReplicationClass))]
public interface NotesReplication : IReplication
{
}
[ComImport]
[Guid("29131539-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(2)]
[DefaultMember("UserName")]
[ClassInterface(0)]
public class NotesSessionClass : ISession, NotesSession
{
	[DispId(1610743808)]
	public virtual extern object AddressBooks
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743809)]
	public virtual extern string CommonUserName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743810)]
	public virtual extern NotesAgent CurrentAgent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743811)]
	public virtual extern NotesDatabase CurrentDatabase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743812)]
	public virtual extern NotesDocument DocumentContext
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743813)]
	public virtual extern string EffectiveUserName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743814)]
	public virtual extern string HttpURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743815)]
	public virtual extern NotesInternational International
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743816)]
	public virtual extern bool ConvertMime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[param: In]
		set;
	}

	[DispId(1610743818)]
	public virtual extern bool IsOnServer
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
	}

	[DispId(1610743819)]
	public virtual extern int LastExitStatus
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		get;
	}

	[DispId(1610743820)]
	public virtual extern object LastRun
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743821)]
	public virtual extern int NotesBuildVersion
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		get;
	}

	[DispId(1610743822)]
	public virtual extern string NotesURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743823)]
	public virtual extern string NotesVersion
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743824)]
	public virtual extern string Platform
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743825)]
	public virtual extern NotesDocument SavedData
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743826)]
	public virtual extern string ServerName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(0)]
	public virtual extern string UserName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743828)]
	public virtual extern object UserNameList
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743829)]
	public virtual extern NotesName UserNameObject
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743830)]
	public virtual extern NotesDatabase URLDatabase
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743850)]
	public virtual extern object UserGroupNameList
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743850)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743860)]
	public virtual extern string OrgDirectoryPath
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743860)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743831)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDateRange CreateDateRange();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743832)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDateTime CreateDateTime([In][MarshalAs(UnmanagedType.BStr)] string pDate);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743833)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesLog CreateLog([In][MarshalAs(UnmanagedType.BStr)] string Name);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743834)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesName CreateName([In][MarshalAs(UnmanagedType.BStr)] string pName, [In][MarshalAs(UnmanagedType.BStr)] string pLang = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743835)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesNewsletter CreateNewsletter([In][MarshalAs(UnmanagedType.Interface)] NotesDocumentCollection pIDc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743836)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesRegistration CreateRegistration();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743837)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesRichTextParagraphStyle CreateRichTextParagraphStyle();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743838)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesRichTextStyle CreateRichTextStyle();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743839)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object Evaluate([In][MarshalAs(UnmanagedType.BStr)] string pFormula, [In][MarshalAs(UnmanagedType.Interface)] NotesDocument pIDoc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743840)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object FreeTimeSearch([In][MarshalAs(UnmanagedType.Interface)] NotesDateRange pIWindow, [In] int iDuration, [In][MarshalAs(UnmanagedType.Struct)] object Names, [In] bool bFirstfit = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743841)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDatabase GetDatabase([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pFile, [In] bool bCreateonfail = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743842)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDbDirectory GetDbDirectory([In][MarshalAs(UnmanagedType.BStr)] string pServer);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743843)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetEnvironmentString([In][MarshalAs(UnmanagedType.BStr)] string pName, [In] bool bisSystem = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743844)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object GetEnvironmentValue([In][MarshalAs(UnmanagedType.BStr)] string pName, [In] bool bisSystem = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743845)]
	public virtual extern void Initialize([In][MarshalAs(UnmanagedType.BStr)] string pPassword = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743846)]
	public virtual extern void InitializeUsingNotesUserName([In][MarshalAs(UnmanagedType.BStr)] string pUser = "", [In][MarshalAs(UnmanagedType.BStr)] string pPassword = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743847)]
	public virtual extern void SetEnvironmentVar([In][MarshalAs(UnmanagedType.BStr)] string pName, [In][MarshalAs(UnmanagedType.Struct)] object Value, [In] bool bisSystem = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743848)]
	public virtual extern void UpdateProcessedDoc([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pIDoc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743849)]
	[return: MarshalAs(UnmanagedType.IUnknown)]
	public virtual extern object Resolve([In][MarshalAs(UnmanagedType.BStr)] string pURL);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743851)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesAdministrationProcess CreateAdministrationProcess([In][MarshalAs(UnmanagedType.BStr)] string pServer);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743852)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesStream CreateStream();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743853)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string SendConsoleCommand([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pCommand);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743854)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesColorObject CreateColorObject();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743855)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDXLExporter CreateDXLExporter();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743856)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDXLImporter CreateDXLImporter();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743857)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument GetUserPolicySettings([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pName, [In][ComAliasName("Domino.SESS_POLICY")] SESS_POLICY lType, [In][MarshalAs(UnmanagedType.BStr)] string pExplicitPolicy = "", [In][MarshalAs(UnmanagedType.BStr)] string pReserved = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743858)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string HashPassword([In][MarshalAs(UnmanagedType.BStr)] string pPassword);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743859)]
	public virtual extern bool VerifyPassword([In][MarshalAs(UnmanagedType.BStr)] string pPassword, [In][MarshalAs(UnmanagedType.BStr)] string pHashedPassword);
}
[ComImport]
[CoClass(typeof(NotesSessionClass))]
[Guid("29131578-2EED-1069-BF5D-00DD011186B7")]
public interface NotesSession : ISession
{
}
[ComImport]
[DefaultMember("Name")]
[ClassInterface(0)]
[Guid("2913153A-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(2)]
public class NotesViewClass : IView, NotesView
{
	[DispId(1610743808)]
	public virtual extern object Aliases
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1610743809)]
	public virtual extern NotesViewEntryCollection AllEntries
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743810)]
	public virtual extern bool AutoUpdate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	[ComAliasName("Domino.COLORS")]
	public virtual extern COLORS BackgroundColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: ComAliasName("Domino.COLORS")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		set;
	}

	[DispId(1610743813)]
	public virtual extern int ColumnCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		get;
	}

	[DispId(1610743814)]
	public virtual extern object ColumnNames
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743815)]
	public virtual extern object Columns
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743816)]
	public virtual extern object Created
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743817)]
	public virtual extern int HeaderLines
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		get;
	}

	[DispId(1610743818)]
	public virtual extern string HttpURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743819)]
	public virtual extern bool IsCalendar
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		get;
	}

	[DispId(1610743820)]
	public virtual extern bool IsCategorized
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		get;
	}

	[DispId(1610743821)]
	public virtual extern bool IsConflict
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		get;
	}

	[DispId(1610743822)]
	public virtual extern bool IsDefaultView
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[param: In]
		set;
	}

	[DispId(1610743823)]
	public virtual extern bool IsFolder
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		get;
	}

	[DispId(1610743824)]
	public virtual extern bool IsHierarchical
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		get;
	}

	[DispId(1610743825)]
	public virtual extern bool IsModified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		get;
	}

	[DispId(1610743826)]
	public virtual extern bool IsPrivate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		get;
	}

	[DispId(1610743827)]
	public virtual extern object LastModified
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(0)]
	public virtual extern string Name
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743829)]
	public virtual extern string NotesURL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743830)]
	public virtual extern NotesDatabase Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743831)]
	public virtual extern bool ProtectReaders
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743831)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743831)]
		[param: In]
		set;
	}

	[DispId(1610743833)]
	public virtual extern object Readers
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743833)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743833)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1610743835)]
	public virtual extern int RowLines
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743835)]
		get;
	}

	[DispId(1610743836)]
	[ComAliasName("Domino.SPACING")]
	public virtual extern SPACING SPACING
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743836)]
		[return: ComAliasName("Domino.SPACING")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743836)]
		[param: In]
		set;
	}

	[DispId(1610743837)]
	public virtual extern int TopLevelEntryCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743837)]
		get;
	}

	[DispId(1610743838)]
	public virtual extern string UniversalID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743838)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743868)]
	public virtual extern bool IsProhibitDesignRefresh
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743868)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743868)]
		[param: In]
		set;
	}

	[DispId(1610743874)]
	public virtual extern string SelectionFormula
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743874)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743874)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743876)]
	public virtual extern int EntryCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743876)]
		get;
	}

	[DispId(1610743880)]
	public virtual extern object LockHolders
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743880)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743881)]
	public virtual extern string ViewInheritedName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743881)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743839)]
	public virtual extern void Clear();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743840)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewNavigator CreateViewNav([In] int lCacheSize = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743841)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewNavigator CreateViewNavMaxLevel([In] int lLevel, [In] int lCacheSize = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743842)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewNavigator CreateViewNavFrom([In][MarshalAs(UnmanagedType.IUnknown)] object pIUnk, [In] int lCacheSize = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743843)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewNavigator CreateViewNavFromCategory([In][MarshalAs(UnmanagedType.BStr)] string pName, [In] int lCacheSize = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743844)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewNavigator CreateViewNavFromChildren([In][MarshalAs(UnmanagedType.IUnknown)] object pIUnk, [In] int lCacheSize = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743845)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewNavigator CreateViewNavFromDescendants([In][MarshalAs(UnmanagedType.IUnknown)] object pIUnk, [In] int lCacheSize = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743846)]
	public virtual extern int FTSearch([In][MarshalAs(UnmanagedType.BStr)] string pQuery, [In] int lMaxDocs = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743847)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocumentCollection GetAllDocumentsByKey([In][MarshalAs(UnmanagedType.Struct)] object Keys, [In] bool bExact = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743848)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntryCollection GetAllEntriesByKey([In][MarshalAs(UnmanagedType.Struct)] object Keys, [In] bool bExact = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743849)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument GetChild([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743850)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewColumn GetColumn([In] int lColumnNumber);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743851)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument GetDocumentByKey([In][MarshalAs(UnmanagedType.Struct)] object Keys, [In] bool bExact = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743852)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetEntryByKey([In][MarshalAs(UnmanagedType.Struct)] object Keys, [In] bool bExact = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743853)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument GetFirstDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743854)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument GetLastDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743855)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument GetNextDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743856)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument GetNextSibling([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743857)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument GetNthDocument([In] int lN);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743858)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument GetParentDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743859)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument GetPrevDocument([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743860)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesDocument GetPrevSibling([In][MarshalAs(UnmanagedType.Interface)] NotesDocument pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743861)]
	public virtual extern void Refresh();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743862)]
	public virtual extern void Remove();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743863)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewColumn CreateColumn([In] int pos = -1, [In][MarshalAs(UnmanagedType.BStr)] string Name = "", [In][MarshalAs(UnmanagedType.BStr)] string Formula = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743864)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewColumn CopyColumn([In][MarshalAs(UnmanagedType.Struct)] object nameIndexObj, [In] int dst = -1);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743865)]
	public virtual extern void RemoveColumn([In][MarshalAs(UnmanagedType.Struct)] object nameIndex);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743867)]
	public virtual extern void SetAliases([In][MarshalAs(UnmanagedType.BStr)] string Aliases = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743877)]
	public virtual extern bool Lock([Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pName, [In] bool bProvisionalOK = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743878)]
	public virtual extern bool LockProvisional([Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743879)]
	public virtual extern void Unlock();
}
[ComImport]
[Guid("29131579-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesViewClass))]
public interface NotesView : IView
{
}
[ComImport]
[Guid("2913153B-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(2)]
[ClassInterface(0)]
[DefaultMember("Title")]
public class NotesViewColumnClass : IViewColumn, NotesViewColumn
{
	[ComAliasName("Domino.VC_ALIGN")]
	[DispId(1610743808)]
	public virtual extern VC_ALIGN Alignment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: ComAliasName("Domino.VC_ALIGN")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		set;
	}

	[ComAliasName("Domino.VC_DATEFMT")]
	[DispId(1610743809)]
	public virtual extern VC_DATEFMT DateFmt
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: ComAliasName("Domino.VC_DATEFMT")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[param: In]
		set;
	}

	[ComAliasName("Domino.COLORS")]
	[DispId(1610743810)]
	public virtual extern COLORS FontColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: ComAliasName("Domino.COLORS")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743811)]
	public virtual extern string FontFace
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743812)]
	public virtual extern int FontPointSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		set;
	}

	[DispId(1610743813)]
	[ComAliasName("Domino.VC_FONTSTYLE")]
	public virtual extern VC_FONTSTYLE FontStyle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[return: ComAliasName("Domino.VC_FONTSTYLE")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[param: In]
		set;
	}

	[DispId(1610743814)]
	public virtual extern string Formula
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743815)]
	[ComAliasName("Domino.VC_ALIGN")]
	public virtual extern VC_ALIGN HeaderAlignment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[return: ComAliasName("Domino.VC_ALIGN")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[param: In]
		set;
	}

	[DispId(1610743816)]
	public virtual extern bool IsAccentSensitiveSort
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[param: In]
		set;
	}

	[DispId(1610743817)]
	public virtual extern bool IsCaseSensitiveSort
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[param: In]
		set;
	}

	[DispId(1610743818)]
	public virtual extern bool IsCategory
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
	}

	[DispId(1610743819)]
	public virtual extern bool IsField
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		get;
	}

	[DispId(1610743820)]
	public virtual extern bool IsFormula
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		get;
	}

	[DispId(1610743821)]
	public virtual extern bool IsHidden
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[param: In]
		set;
	}

	[DispId(1610743822)]
	public virtual extern bool IsHideDetail
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[param: In]
		set;
	}

	[DispId(1610743823)]
	public virtual extern bool IsIcon
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		get;
	}

	[DispId(1610743824)]
	public virtual extern bool IsResize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[param: In]
		set;
	}

	[DispId(1610743825)]
	public virtual extern bool IsResortAscending
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		[param: In]
		set;
	}

	[DispId(1610743826)]
	public virtual extern bool IsResortDescending
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[param: In]
		set;
	}

	[DispId(1610743827)]
	public virtual extern bool IsResortToView
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743827)]
		[param: In]
		set;
	}

	[DispId(1610743828)]
	public virtual extern bool IsResponse
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		get;
	}

	[DispId(1610743829)]
	public virtual extern bool IsSecondaryResort
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743829)]
		[param: In]
		set;
	}

	[DispId(1610743830)]
	public virtual extern bool IsSecondaryResortDescending
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		[param: In]
		set;
	}

	[DispId(1610743831)]
	public virtual extern bool IsShowTwistie
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743831)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743831)]
		[param: In]
		set;
	}

	[DispId(1610743832)]
	public virtual extern bool IsSortDescending
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[param: In]
		set;
	}

	[DispId(1610743833)]
	public virtual extern bool IsSorted
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743833)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743833)]
		[param: In]
		set;
	}

	[DispId(1610743834)]
	public virtual extern string ItemName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743834)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743835)]
	[ComAliasName("Domino.VC_SEP")]
	public virtual extern VC_SEP ListSep
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743835)]
		[return: ComAliasName("Domino.VC_SEP")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743835)]
		[param: In]
		set;
	}

	[ComAliasName("Domino.VC_NUMATTR")]
	[DispId(1610743836)]
	public virtual extern VC_NUMATTR NumberAttrib
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743836)]
		[return: ComAliasName("Domino.VC_NUMATTR")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743836)]
		[param: In]
		set;
	}

	[DispId(1610743837)]
	public virtual extern int NumberDigits
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743837)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743837)]
		[param: In]
		set;
	}

	[DispId(1610743838)]
	[ComAliasName("Domino.VC_NUMFMT")]
	public virtual extern VC_NUMFMT NumberFormat
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743838)]
		[return: ComAliasName("Domino.VC_NUMFMT")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743838)]
		[param: In]
		set;
	}

	[DispId(1610743839)]
	public virtual extern NotesView Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743839)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743840)]
	public virtual extern int Position
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743840)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743840)]
		[param: In]
		set;
	}

	[DispId(1610743841)]
	[ComAliasName("Domino.VC_TDFMT")]
	public virtual extern VC_TDFMT TimeDateFmt
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743841)]
		[return: ComAliasName("Domino.VC_TDFMT")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743841)]
		[param: In]
		set;
	}

	[ComAliasName("Domino.VC_TIMEFMT")]
	[DispId(1610743842)]
	public virtual extern VC_TIMEFMT TimeFmt
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743842)]
		[return: ComAliasName("Domino.VC_TIMEFMT")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743842)]
		[param: In]
		set;
	}

	[DispId(1610743843)]
	[ComAliasName("Domino.VC_TIMEZONEFMT")]
	public virtual extern VC_TIMEZONEFMT TimeZoneFmt
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743843)]
		[return: ComAliasName("Domino.VC_TIMEZONEFMT")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743843)]
		[param: In]
		set;
	}

	[DispId(0)]
	public virtual extern string Title
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(0)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743845)]
	public virtual extern int Width
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743845)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743845)]
		[param: In]
		set;
	}

	[DispId(1610743846)]
	public virtual extern int HeaderFontColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743846)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743846)]
		[param: In]
		set;
	}

	[DispId(1610743847)]
	public virtual extern string HeaderFontFace
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743847)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743847)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743848)]
	public virtual extern int HeaderFontPointSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743848)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743848)]
		[param: In]
		set;
	}

	[DispId(1610743849)]
	public virtual extern int HeaderFontStyle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743849)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743849)]
		[param: In]
		set;
	}

	[DispId(1610743850)]
	public virtual extern int SecondaryResortColumnIndex
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743850)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743850)]
		[param: In]
		set;
	}

	[DispId(1610743851)]
	public virtual extern bool IsFontBold
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743851)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743851)]
		[param: In]
		set;
	}

	[DispId(1610743852)]
	public virtual extern bool IsFontItalic
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743852)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743852)]
		[param: In]
		set;
	}

	[DispId(1610743853)]
	public virtual extern bool IsFontUnderline
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743853)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743853)]
		[param: In]
		set;
	}

	[DispId(1610743854)]
	public virtual extern bool IsFontStrikethrough
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743854)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743854)]
		[param: In]
		set;
	}

	[DispId(1610743855)]
	public virtual extern bool IsHeaderFontBold
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743855)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743855)]
		[param: In]
		set;
	}

	[DispId(1610743856)]
	public virtual extern bool IsHeaderFontItalic
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743856)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743856)]
		[param: In]
		set;
	}

	[DispId(1610743857)]
	public virtual extern bool IsHeaderFontUnderline
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743857)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743857)]
		[param: In]
		set;
	}

	[DispId(1610743858)]
	public virtual extern bool IsHeaderFontStrikethrough
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743858)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743858)]
		[param: In]
		set;
	}

	[DispId(1610743859)]
	public virtual extern bool IsNumberAttribParens
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743859)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743859)]
		[param: In]
		set;
	}

	[DispId(1610743860)]
	public virtual extern bool IsNumberAttribPunctuated
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743860)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743860)]
		[param: In]
		set;
	}

	[DispId(1610743861)]
	public virtual extern bool IsNumberAttribPercent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743861)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743861)]
		[param: In]
		set;
	}

	[DispId(1610743862)]
	public virtual extern string ResortToViewName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743862)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743862)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}
}
[ComImport]
[Guid("2913157A-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesViewColumnClass))]
public interface NotesViewColumn : IViewColumn
{
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("2913153C-2EED-1069-BF5D-00DD011186B7")]
public class NotesViewEntryClass : IViewEntry, NotesViewEntry
{
	[DispId(1610743808)]
	public virtual extern int ChildCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
	}

	[DispId(1610743809)]
	public virtual extern int ColumnIndentLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		get;
	}

	[DispId(1610743810)]
	public virtual extern object ColumnValues
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743811)]
	public virtual extern int DescendantCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		get;
	}

	[DispId(1610743812)]
	public virtual extern NotesDocument Document
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743813)]
	public virtual extern int FTSearchScore
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		get;
	}

	[DispId(1610743814)]
	public virtual extern int IndentLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
	}

	[DispId(1610743815)]
	public virtual extern bool IsCategory
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		get;
	}

	[DispId(1610743816)]
	public virtual extern bool IsConflict
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
	}

	[DispId(1610743817)]
	public virtual extern bool IsDocument
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		get;
	}

	[DispId(1610743818)]
	public virtual extern bool IsTotal
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
	}

	[DispId(1610743819)]
	public virtual extern bool IsValid
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		get;
	}

	[DispId(1610743820)]
	public virtual extern string NoteID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743821)]
	public virtual extern object Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[return: MarshalAs(UnmanagedType.IUnknown)]
		get;
	}

	[DispId(1610743822)]
	public virtual extern int SiblingCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		get;
	}

	[DispId(1610743823)]
	public virtual extern string UniversalID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetPosition([In][MarshalAs(UnmanagedType.BStr)] string pSeparator);
}
[ComImport]
[Guid("2913157B-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesViewEntryClass))]
public interface NotesViewEntry : IViewEntry
{
}
[ComImport]
[ClassInterface(0)]
[Guid("2913153D-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(2)]
public class NotesViewEntryCollectionClass : IViewEntryCollection, NotesViewEntryCollection
{
	[DispId(1610743808)]
	public virtual extern int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
	}

	[DispId(1610743809)]
	public virtual extern NotesView Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743810)]
	public virtual extern string Query
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743811)]
	public virtual extern void AddEntry([In][MarshalAs(UnmanagedType.IUnknown)] object pIObj, [In] bool bReserved = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743812)]
	public virtual extern void DeleteEntry([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743813)]
	public virtual extern void FTSearch([In][MarshalAs(UnmanagedType.BStr)] string pQuery, [In] int lMaxDocs = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743814)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetEntry([In][MarshalAs(UnmanagedType.IUnknown)] object pIObj);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetFirstEntry();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetLastEntry();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743817)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetNextEntry([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743818)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetNthEntry([In] int lN);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743819)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetPrevEntry([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743820)]
	public virtual extern void PutAllInFolder([In][MarshalAs(UnmanagedType.BStr)] string pFolderName, [In] bool bCreateonfail = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	public virtual extern void RemoveAll([In] bool bForce);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743822)]
	public virtual extern void RemoveAllFromFolder([In][MarshalAs(UnmanagedType.BStr)] string pFolderName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743823)]
	public virtual extern void StampAll([In][MarshalAs(UnmanagedType.BStr)] string pItemName, [In][MarshalAs(UnmanagedType.Struct)] object Value);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	public virtual extern void UpdateAll();
}
[ComImport]
[Guid("2913157C-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesViewEntryCollectionClass))]
public interface NotesViewEntryCollection : IViewEntryCollection
{
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("2913153E-2EED-1069-BF5D-00DD011186B7")]
public class NotesViewNavigatorClass : IViewNavigator, NotesViewNavigator
{
	[DispId(1610743808)]
	public virtual extern int CacheSize
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		set;
	}

	[DispId(1610743810)]
	public virtual extern int MaxLevel
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	public virtual extern NotesView ParentView
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743847)]
	public virtual extern int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743847)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743813)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetChild([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743814)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetEntry([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetCurrent();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetFirst();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743817)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetFirstDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743818)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetLast();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743819)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetLastDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743820)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetNext([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetNextCategory([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743822)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetNextDocument([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743823)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetNextSibling([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetNth([In] int lN);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetParent([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743826)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetPos([In][MarshalAs(UnmanagedType.BStr)] string pPos, [In][MarshalAs(UnmanagedType.BStr)] string pSeparator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743827)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetPrev([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743828)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetPrevCategory([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743829)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetPrevDocument([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743830)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesViewEntry GetPrevSibling([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pICurrent);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743831)]
	public virtual extern void GotoChild([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIViewEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743832)]
	public virtual extern void GotoEntry([In][MarshalAs(UnmanagedType.IUnknown)] object pIObj);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743833)]
	public virtual extern void GotoFirst();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743834)]
	public virtual extern void GotoFirstDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743835)]
	public virtual extern void GotoLast();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743836)]
	public virtual extern void GotoLastDocument();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743837)]
	public virtual extern void GotoNext([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIViewEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743838)]
	public virtual extern void GotoNextCategory([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIViewEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743839)]
	public virtual extern void GotoNextDocument([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIViewEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743840)]
	public virtual extern void GotoNextSibling([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIViewEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743841)]
	public virtual extern void GotoParent([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIViewEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743842)]
	public virtual extern void GotoPos([In][MarshalAs(UnmanagedType.BStr)] string pPos, [In][MarshalAs(UnmanagedType.BStr)] string pSeparator);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743843)]
	public virtual extern void GotoPrev([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIViewEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743844)]
	public virtual extern void GotoPrevCategory([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIViewEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743845)]
	public virtual extern void GotoPrevDocument([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIViewEntry);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743846)]
	public virtual extern void GotoPrevSibling([In][MarshalAs(UnmanagedType.Interface)] NotesViewEntry pIViewEntry);
}
[ComImport]
[CoClass(typeof(NotesViewNavigatorClass))]
[Guid("2913157D-2EED-1069-BF5D-00DD011186B7")]
public interface NotesViewNavigator : IViewNavigator
{
}
[ComImport]
[ClassInterface(0)]
[Guid("2913153F-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(2)]
public class NotesMIMEEntityClass : IMIMEEntity, NotesMIMEEntity
{
	[DispId(1610743808)]
	public virtual extern string ContentSubType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	public virtual extern string ContentType
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743810)]
	public virtual extern string ContentAsText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743811)]
	public virtual extern string Headers
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743812)]
	public virtual extern NotesDocument ParentDoc
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743816)]
	public virtual extern string BoundaryStart
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743817)]
	public virtual extern string BoundaryEnd
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743818)]
	public virtual extern string Charset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[ComAliasName("Domino.MIME_ENCODING")]
	[DispId(1610743819)]
	public virtual extern MIME_ENCODING Encoding
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		[return: ComAliasName("Domino.MIME_ENCODING")]
		get;
	}

	[DispId(1610743820)]
	public virtual extern object HeaderObjects
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743821)]
	public virtual extern string Preamble
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743813)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesMIMEEntity GetFirstChildEntity();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743814)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesMIMEEntity GetNextSibling();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesMIMEEntity GetParentEntity();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743823)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesMIMEEntity CreateChildEntity([In][MarshalAs(UnmanagedType.Interface)] NotesMIMEEntity pNextSiblingIMIMEEntity = null);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesMIMEHeader CreateHeader([In][MarshalAs(UnmanagedType.BStr)] string pHeaderName);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesMIMEEntity CreateParentEntity();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743826)]
	public virtual extern void DecodeContent();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743827)]
	public virtual extern void EncodeContent([In][ComAliasName("Domino.MIME_ENCODING")] MIME_ENCODING lEnc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743828)]
	public virtual extern void GetContentAsBytes([In][MarshalAs(UnmanagedType.Interface)] NotesStream pINotesStream, [In] bool bDecoded = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743829)]
	public virtual extern void GetContentAsText([In][MarshalAs(UnmanagedType.Interface)] NotesStream pINotesStream, [In] bool bDecoded = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743830)]
	public virtual extern void GetEntityAsText([In][MarshalAs(UnmanagedType.Interface)] NotesStream pINotesStream, [Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pHeaderFilters, [In] bool bInclusive = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743831)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesMIMEEntity GetNextEntity([In][ComAliasName("Domino.SEARCH_PATH")] SEARCH_PATH lSearchPath = SEARCH_PATH.SEARCH_DEPTH);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743832)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesMIMEHeader GetNthHeader([In][MarshalAs(UnmanagedType.BStr)] string pHeaderName, [In] int lNth = 1);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743833)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesMIMEEntity GetPrevEntity([In][ComAliasName("Domino.SEARCH_PATH")] SEARCH_PATH lSearchPath = SEARCH_PATH.SEARCH_DEPTH);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743834)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesMIMEEntity GetPrevSibling();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743835)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetSomeHeaders([Optional][DefaultParameterValue("")][In][MarshalAs(UnmanagedType.Struct)] ref object pHeaderFilters, [In] bool bInclusive = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743836)]
	public virtual extern void Remove();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743837)]
	public virtual extern void SetContentFromBytes([In][MarshalAs(UnmanagedType.Interface)] NotesStream pINotesStream, [In][MarshalAs(UnmanagedType.BStr)] string pContentType, [In][ComAliasName("Domino.MIME_ENCODING")] MIME_ENCODING lEnc);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743838)]
	public virtual extern void SetContentFromText([In][MarshalAs(UnmanagedType.Interface)] NotesStream pINotesStream, [In][MarshalAs(UnmanagedType.BStr)] string pContentType, [In][ComAliasName("Domino.MIME_ENCODING")] MIME_ENCODING lEnc);
}
[ComImport]
[Guid("2913157E-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesMIMEEntityClass))]
public interface NotesMIMEEntity : IMIMEEntity
{
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("29131540-2EED-1069-BF5D-00DD011186B7")]
public class NotesMIMEHeaderClass : IMIMEHeader, NotesMIMEHeader
{
	[DispId(1610743808)]
	public virtual extern string HeaderName
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	public virtual extern NotesMIMEEntity Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743810)]
	public virtual extern bool AddValText([In][MarshalAs(UnmanagedType.BStr)] string pValueText, [In][MarshalAs(UnmanagedType.BStr)] string pRfc2047Charset = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743811)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetHeaderVal([In] bool bFolded = false, [In] bool bDecoded = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743812)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetHeaderValAndParams([In] bool bFolded = false, [In] bool bDecoded = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743813)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetParamVal([In][MarshalAs(UnmanagedType.BStr)] string pParamName, [In] bool bFolded = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743814)]
	public virtual extern void Remove();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	public virtual extern bool SetHeaderVal([In][MarshalAs(UnmanagedType.BStr)] string pHeaderVal);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	public virtual extern bool SetHeaderValAndParams([In][MarshalAs(UnmanagedType.BStr)] string pHeaderValParams);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743817)]
	public virtual extern bool SetParamVal([In][MarshalAs(UnmanagedType.BStr)] string pParamName, [In][MarshalAs(UnmanagedType.BStr)] string pParamVal);
}
[ComImport]
[Guid("2913157F-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesMIMEHeaderClass))]
public interface NotesMIMEHeader : IMIMEHeader
{
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("29131541-2EED-1069-BF5D-00DD011186B7")]
public class NotesStreamClass : INotesStream, NotesStream
{
	[DispId(1610743808)]
	public virtual extern string Charset
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	public virtual extern bool IsEOS
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		get;
	}

	[DispId(1610743810)]
	public virtual extern int Position
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	public virtual extern int Bytes
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
	}

	[DispId(1610743813)]
	public virtual extern bool IsReadOnly
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		get;
	}

	[DispId(1610743814)]
	public virtual extern NotesSession Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	public virtual extern void Close();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	public virtual extern bool Open([In][MarshalAs(UnmanagedType.BStr)] string pName, [In][MarshalAs(UnmanagedType.BStr)] string pCharset = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743817)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object Read([In] int lLength = -1);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743818)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string ReadText([In][ComAliasName("Domino.STMREAD_LEN")] STMREAD_LEN lLength = (STMREAD_LEN)(-1), [In][ComAliasName("Domino.EOL_TYPE")] EOL_TYPE lEOL = EOL_TYPE.EOL_CRLF);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743819)]
	public virtual extern void Truncate();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743820)]
	public virtual extern int Write([In][MarshalAs(UnmanagedType.Struct)] object vByteArray);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	public virtual extern int WriteText([In][MarshalAs(UnmanagedType.BStr)] string pText, [In][ComAliasName("Domino.EOL_TYPE")] EOL_TYPE lEOL = EOL_TYPE.EOL_NONE);
}
[ComImport]
[Guid("29131580-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesStreamClass))]
public interface NotesStream : INotesStream
{
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("29131542-2EED-1069-BF5D-00DD011186B7")]
public class NotesAdministrationProcessClass : IAdministrationProcess, NotesAdministrationProcess
{
	[DispId(1610743808)]
	public virtual extern string CertificateAuthorityOrg
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743810)]
	public virtual extern string CertifierFile
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743812)]
	public virtual extern string CertifierPassword
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743814)]
	public virtual extern bool IsCertificateAuthorityAvailable
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
	}

	[DispId(1610743815)]
	public virtual extern bool UseCertificateAuthority
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[param: In]
		set;
	}

	[DispId(1610743817)]
	public virtual extern NotesDateTime CertificateExpiration
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Interface)]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743819)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string AddGroupMembers([In][MarshalAs(UnmanagedType.BStr)] string pGroup, [In][MarshalAs(UnmanagedType.Struct)] object Members);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743820)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string AddInternetCertificateToUser([In][MarshalAs(UnmanagedType.BStr)] string pUser, [In][MarshalAs(UnmanagedType.BStr)] string pKeyRingFile, [In][MarshalAs(UnmanagedType.BStr)] string pKeyRingPassword, [In][MarshalAs(UnmanagedType.Interface)] NotesDateTime Expiration = null);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string AddServerToCluster([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pCluster);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743822)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string ApproveDeletePersonInDirectory([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743823)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string ApproveDeleteServerInDirectory([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string ApproveDesignElementDeletion([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string ApproveMailFileDeletion([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743826)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string ApproveMovedReplicaDeletion([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743827)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string ApproveNameChangeRetraction([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743828)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string ApproveRenamePersonInDirectory([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743829)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string ApproveRenameServerInDirectory([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743830)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string ApproveReplicaDeletion([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743831)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string ApproveResourceDeletion([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743832)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string ChangeHTTPPassword([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In][MarshalAs(UnmanagedType.BStr)] string pOldPassword, [In][MarshalAs(UnmanagedType.BStr)] string pNewPassword);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743833)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string ConfigureMailAgent([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In][MarshalAs(UnmanagedType.BStr)] string pAgentName, [In] bool bActivatable = true, [In] bool bEnable = true);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743834)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string CreateReplica([In][MarshalAs(UnmanagedType.BStr)] string pSourceServer, [In][MarshalAs(UnmanagedType.BStr)] string pSourceDBFile, [In][MarshalAs(UnmanagedType.BStr)] string pDestServer, [In][MarshalAs(UnmanagedType.BStr)] string pDestDBFile = "", [In] bool bCopyACL = true, [In] bool bCreateFTIndex = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743835)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string MoveReplica([In][MarshalAs(UnmanagedType.BStr)] string pSourceServer, [In][MarshalAs(UnmanagedType.BStr)] string pSourceDBFile, [In][MarshalAs(UnmanagedType.BStr)] string pDestServer, [In][MarshalAs(UnmanagedType.BStr)] string pDestDBFile = "", [In] bool bCopyACL = true, [In] bool bCreateFTIndex = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743836)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string DeleteReplicas([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pDbfile);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743837)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string DeleteGroup([In][MarshalAs(UnmanagedType.BStr)] string pGroupName, [In] bool bImmediate, [In] bool bDeleteWindowsGroup = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743838)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string DeleteServer([In][MarshalAs(UnmanagedType.BStr)] string pServerName, [In] bool bImmediate);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743839)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string DeleteUser([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In] bool bImmediate, [In][ComAliasName("Domino.ADMP_MAILDEL")] ADMP_MAILDEL lMailFileAction, [In][MarshalAs(UnmanagedType.BStr)] string pDenyGroup, [In] bool bDeleteWindowsGroup = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743840)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string FindGroupInDomain([In][MarshalAs(UnmanagedType.BStr)] string pGroup);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743841)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string FindServerInDomain([In][MarshalAs(UnmanagedType.BStr)] string pServer);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743842)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string FindUserInDomain([In][MarshalAs(UnmanagedType.BStr)] string pUser);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743843)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string MoveMailUser([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In][MarshalAs(UnmanagedType.BStr)] string pNewHomeServer, [In][MarshalAs(UnmanagedType.BStr)] string pNewHomeServerMailPath, [In] bool bUseSCOS = false, [In][MarshalAs(UnmanagedType.Struct)] object NewClusterReplicaArray = 0, [In] bool bDeleteOldClusterReplicas = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743844)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string MoveRoamingUser([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In][MarshalAs(UnmanagedType.BStr)] string pDestServer, [In][MarshalAs(UnmanagedType.BStr)] string pDestServerPath);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743845)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string MoveUserInHierarchyRequest([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In][MarshalAs(UnmanagedType.BStr)] string pTargetCertifier, [In] bool bAllowPrimaryNameChange = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743846)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string MoveUserInHierarchyComplete([In][MarshalAs(UnmanagedType.BStr)] string pRequestNoteID, [In][MarshalAs(UnmanagedType.BStr)] string pLastName = "*", [In][MarshalAs(UnmanagedType.BStr)] string pFirstName = "*", [In][MarshalAs(UnmanagedType.BStr)] string pMiddleInitial = "*", [In][MarshalAs(UnmanagedType.BStr)] string pOrgUnit = "*", [In][MarshalAs(UnmanagedType.BStr)] string pAltCommonName = "*", [In][MarshalAs(UnmanagedType.BStr)] string pAltOrgUnit = "*", [In][MarshalAs(UnmanagedType.BStr)] string pAltLanguage = "*", [In] bool bRenameWindowsUser = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743847)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string RecertifyServer([In][MarshalAs(UnmanagedType.BStr)] string pServer);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743848)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string RecertifyUser([In][MarshalAs(UnmanagedType.BStr)] string pUsername);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743849)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string RemoveServerFromCluster([In][MarshalAs(UnmanagedType.BStr)] string pServer);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743850)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string RenameGroup([In][MarshalAs(UnmanagedType.BStr)] string pGroup, [In][MarshalAs(UnmanagedType.BStr)] string pNewGroup);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743851)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string RenameNotesUser([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In][MarshalAs(UnmanagedType.BStr)] string pLastName = "*", [In][MarshalAs(UnmanagedType.BStr)] string pFirstName = "*", [In][MarshalAs(UnmanagedType.BStr)] string pMiddleInitial = "*", [In][MarshalAs(UnmanagedType.BStr)] string pOrgUnit = "*", [In][MarshalAs(UnmanagedType.BStr)] string pAltCommonName = "*", [In][MarshalAs(UnmanagedType.BStr)] string pAltOrgUnit = "*", [In][MarshalAs(UnmanagedType.BStr)] string pAltLanguage = "*", [In] bool bRenameWindowsUser = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743852)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string RenameWebUser([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In][MarshalAs(UnmanagedType.BStr)] string pNewUserName, [In][MarshalAs(UnmanagedType.BStr)] string pNewLastName = "*", [In][MarshalAs(UnmanagedType.BStr)] string pNewFirstName = "*", [In][MarshalAs(UnmanagedType.BStr)] string pNewMiddleInitial = "*", [In][MarshalAs(UnmanagedType.BStr)] string pNewShortname = "*", [In][MarshalAs(UnmanagedType.BStr)] string pNewInternetAddress = "*");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743853)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string SetServerDirectoryAssistanceSettings([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pDbfile);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743854)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string SignDatabaseWithServerID([In][MarshalAs(UnmanagedType.BStr)] string pServer, [In][MarshalAs(UnmanagedType.BStr)] string pDbfile, [In] bool bUpdateOnly = false);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743855)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string UpgradeUserToHierarchical([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In][MarshalAs(UnmanagedType.BStr)] string pOrgUnit = "", [In][MarshalAs(UnmanagedType.BStr)] string pAltCommonName = "", [In][MarshalAs(UnmanagedType.BStr)] string pAltOrgUnit = "", [In][MarshalAs(UnmanagedType.BStr)] string pAltLanguage = "");

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743856)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string SetUserPasswordSettings([In][MarshalAs(UnmanagedType.BStr)] string pUsername, [In][MarshalAs(UnmanagedType.Struct)] object NotesPasswordCheckSetting = "nochange", [In][MarshalAs(UnmanagedType.Struct)] object NotesPasswordChangeInterval = "nochange", [In][MarshalAs(UnmanagedType.Struct)] object NotesPasswordGracePeriod = "nochange", [In][MarshalAs(UnmanagedType.Struct)] object InternetPasswordForceChange = "nochange", [In][ComAliasName("Domino.ADMP_PWDCHK")] ADMP_PWDCHK NotUsed = ADMP_PWDCHK.PWD_CHK_DONTCHECKPASSWORD);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743857)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string ApproveHostedOrgStorageDeletion([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);
}
[ComImport]
[Guid("29131581-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesAdministrationProcessClass))]
public interface NotesAdministrationProcess : IAdministrationProcess
{
}
[ComImport]
[TypeLibType(2)]
[Guid("29131543-2EED-1069-BF5D-00DD011186B7")]
[ClassInterface(0)]
public class NotesReplicationEntryClass : IReplicationEntry, NotesReplicationEntry
{
	[DispId(1610743808)]
	public virtual extern string Source
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	public virtual extern string Destination
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743810)]
	public virtual extern string Formula
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743812)]
	public virtual extern string Views
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743814)]
	public virtual extern bool IsIncludeForms
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		set;
	}

	[DispId(1610743816)]
	public virtual extern bool IsIncludeAgents
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[param: In]
		set;
	}

	[DispId(1610743818)]
	public virtual extern bool IsIncludeFormulas
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[param: In]
		set;
	}

	[DispId(1610743820)]
	public virtual extern bool IsIncludeDocuments
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[param: In]
		set;
	}

	[DispId(1610743822)]
	public virtual extern bool IsIncludeACL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743824)]
	public virtual extern int Remove();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743825)]
	public virtual extern int Save();
}
[ComImport]
[CoClass(typeof(NotesReplicationEntryClass))]
[Guid("29131582-2EED-1069-BF5D-00DD011186B7")]
public interface NotesReplicationEntry : IReplicationEntry
{
}
[ComImport]
[TypeLibType(2)]
[Guid("29131544-2EED-1069-BF5D-00DD011186B7")]
[ClassInterface(0)]
public class NotesColorObjectClass : IColorObject, NotesColorObject
{
	[DispId(1610743808)]
	public virtual extern int Red
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
	}

	[DispId(1610743809)]
	public virtual extern int Green
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		get;
	}

	[DispId(1610743810)]
	public virtual extern int Blue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
	}

	[DispId(1610743811)]
	public virtual extern int Hue
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		get;
	}

	[DispId(1610743812)]
	public virtual extern int Saturation
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
	}

	[DispId(1610743813)]
	public virtual extern int Luminance
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		get;
	}

	[DispId(1610743814)]
	public virtual extern int NotesColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	public virtual extern int SetRGB([In] int Red, [In] int Green, [In] int Blue);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	public virtual extern int SetHSL([In] int Hue, [In] int Saturation, [In] int Luminance);
}
[ComImport]
[CoClass(typeof(NotesColorObjectClass))]
[Guid("29131583-2EED-1069-BF5D-00DD011186B7")]
public interface NotesColorObject : IColorObject
{
}
[ComImport]
[Guid("29131545-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(2)]
[ClassInterface(0)]
public class NotesRichTextNavigatorClass : IRichTextNavigator, NotesRichTextNavigator
{
	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743808)]
	public virtual extern bool FindNthElement([In][ComAliasName("Domino.RT_ELEM")] RT_ELEM lType, [In] int lOccurrence = 1);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743809)]
	public virtual extern bool FindFirstElement([In][ComAliasName("Domino.RT_ELEM")] RT_ELEM lType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743810)]
	public virtual extern bool FindNextElement([In][ComAliasName("Domino.RT_ELEM")] RT_ELEM lType = (RT_ELEM)65535, [In] int lOccurrence = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743811)]
	public virtual extern bool FindLastElement([In][ComAliasName("Domino.RT_ELEM")] RT_ELEM lType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743812)]
	public virtual extern bool FindFirstString([In][MarshalAs(UnmanagedType.BStr)] string pTarget, [In] int lOptions = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743813)]
	public virtual extern bool FindNextString([In][MarshalAs(UnmanagedType.BStr)] string pTarget, [In] int lOptions = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743814)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object GetElement();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object GetFirstElement([In][ComAliasName("Domino.RT_ELEM")] RT_ELEM lType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object GetNextElement([In][ComAliasName("Domino.RT_ELEM")] RT_ELEM lType = (RT_ELEM)65535, [In] int lOccurrence = 0);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743817)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object GetNthElement([In][ComAliasName("Domino.RT_ELEM")] RT_ELEM lType, [In] int lOccurrence = 1);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743818)]
	[return: MarshalAs(UnmanagedType.Struct)]
	public virtual extern object GetLastElement([In][ComAliasName("Domino.RT_ELEM")] RT_ELEM lType);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743819)]
	public virtual extern void SetPosition([In][MarshalAs(UnmanagedType.Struct)] object pIRTElement);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743820)]
	public virtual extern void SetPositionAtEnd([In][MarshalAs(UnmanagedType.Struct)] object pIRTElement);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	public virtual extern void SetCharOffset([In] int lOffset);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743822)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesRichTextNavigator Clone();
}
[ComImport]
[Guid("29131584-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesRichTextNavigatorClass))]
public interface NotesRichTextNavigator : IRichTextNavigator
{
}
[ComImport]
[Guid("29131546-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(2)]
[ClassInterface(0)]
public class NotesRichTextRangeClass : IRichTextRange, NotesRichTextRange
{
	[ComAliasName("Domino.RT_ELEM")]
	[DispId(1610743808)]
	public virtual extern RT_ELEM type
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: ComAliasName("Domino.RT_ELEM")]
		get;
	}

	[DispId(1610743809)]
	public virtual extern string TextRun
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743810)]
	public virtual extern string TextParagraph
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743811)]
	public virtual extern NotesRichTextStyle Style
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743812)]
	public virtual extern NotesRichTextNavigator Navigator
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743813)]
	public virtual extern void SetStyle([In][MarshalAs(UnmanagedType.Interface)] NotesRichTextStyle pIRTStyle);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743814)]
	public virtual extern void SetBegin([In][MarshalAs(UnmanagedType.Struct)] object ppIRTElement);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	public virtual extern void SetEnd([In][MarshalAs(UnmanagedType.Struct)] object ppIRTElement);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	public virtual extern void Reset([In] bool bBegin, [In] bool bEnd);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743817)]
	public virtual extern void Remove();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743818)]
	[return: MarshalAs(UnmanagedType.Interface)]
	public virtual extern NotesRichTextRange Clone();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743819)]
	public virtual extern int FindandReplace([In][MarshalAs(UnmanagedType.BStr)] string pFindString, [In][MarshalAs(UnmanagedType.BStr)] string pReplString, [In] int lOptions);
}
[ComImport]
[Guid("29131585-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesRichTextRangeClass))]
public interface NotesRichTextRange : IRichTextRange
{
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("29131547-2EED-1069-BF5D-00DD011186B7")]
public class NotesRichTextDoclinkClass : IRichTextDoclink, NotesRichTextDoclink
{
	[DispId(1610743808)]
	public virtual extern string DBReplicaID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743810)]
	public virtual extern string ViewUNID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743812)]
	public virtual extern string DocUNID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743814)]
	public virtual extern string DisplayComment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743816)]
	public virtual extern string ServerHint
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743818)]
	public virtual extern string HotSpotText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743820)]
	public virtual extern NotesRichTextStyle HotSpotTextStyle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	public virtual extern void Remove();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743822)]
	public virtual extern void SetHotSpotTextStyle([In][MarshalAs(UnmanagedType.Interface)] NotesRichTextStyle pIRTStyle);
}
[ComImport]
[CoClass(typeof(NotesRichTextDoclinkClass))]
[Guid("29131586-2EED-1069-BF5D-00DD011186B7")]
public interface NotesRichTextDoclink : IRichTextDoclink
{
}
[ComImport]
[Guid("29131586-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(4160)]
public interface IRichTextDoclink
{
	[DispId(1610743808)]
	string DBReplicaID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743810)]
	string ViewUNID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743812)]
	string DocUNID
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743814)]
	string DisplayComment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743816)]
	string ServerHint
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743818)]
	string HotSpotText
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743820)]
	NotesRichTextStyle HotSpotTextStyle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	void Remove();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743822)]
	void SetHotSpotTextStyle([In][MarshalAs(UnmanagedType.Interface)] NotesRichTextStyle pIRTStyle);
}
[ComImport]
[ClassInterface(0)]
[Guid("29131548-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(2)]
public class NotesRichTextSectionClass : IRichTextSection, NotesRichTextSection
{
	[DispId(1610743808)]
	public virtual extern string Title
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743810)]
	public virtual extern bool IsExpanded
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	public virtual extern NotesRichTextStyle TitleStyle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743814)]
	public virtual extern NotesColorObject BarColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743813)]
	public virtual extern void SetTitleStyle([In][MarshalAs(UnmanagedType.Interface)] NotesRichTextStyle pIRTStyle);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	public virtual extern void SetBarColor([In][MarshalAs(UnmanagedType.Interface)] NotesColorObject pIColorObj);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	public virtual extern void Remove();
}
[ComImport]
[Guid("29131587-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesRichTextSectionClass))]
public interface NotesRichTextSection : IRichTextSection
{
}
[ComImport]
[Guid("29131587-2EED-1069-BF5D-00DD011186B7")]
[TypeLibType(4160)]
public interface IRichTextSection
{
	[DispId(1610743808)]
	string Title
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743810)]
	bool IsExpanded
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	NotesRichTextStyle TitleStyle
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743813)]
	void SetTitleStyle([In][MarshalAs(UnmanagedType.Interface)] NotesRichTextStyle pIRTStyle);

	[DispId(1610743814)]
	NotesColorObject BarColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743815)]
	void SetBarColor([In][MarshalAs(UnmanagedType.Interface)] NotesColorObject pIColorObj);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743816)]
	void Remove();
}
[ComImport]
[Guid("29131549-2EED-1069-BF5D-00DD011186B7")]
[ClassInterface(0)]
[TypeLibType(2)]
public class NotesRichTextTableClass : IRichTextTable, NotesRichTextTable
{
	[DispId(1610743808)]
	[ComAliasName("Domino.RT_TBLSTYLE")]
	public virtual extern RT_TBLSTYLE Style
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: ComAliasName("Domino.RT_TBLSTYLE")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: ComAliasName("Domino.RT_TBLSTYLE")]
		set;
	}

	[DispId(1610743809)]
	public virtual extern int RowCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		get;
	}

	[DispId(1610743810)]
	public virtual extern int ColumnCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
	}

	[DispId(1610743811)]
	public virtual extern bool RightToLeft
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[param: In]
		set;
	}

	[DispId(1610743813)]
	public virtual extern object RowLabels
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1610743815)]
	public virtual extern NotesColorObject Color
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743816)]
	public virtual extern NotesColorObject AlternateColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743817)]
	public virtual extern void AddRow([In] int lCount = 65535, [In] int lTargetRow = 65535);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743818)]
	public virtual extern void RemoveRow([In] int lCount = 65535, [In] int lTargetRow = 65535);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743819)]
	public virtual extern void Remove();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743820)]
	public virtual extern void SetColor([In][MarshalAs(UnmanagedType.Interface)] NotesColorObject pIColorObj);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	public virtual extern void SetAlternateColor([In][MarshalAs(UnmanagedType.Interface)] NotesColorObject pIColorObj);
}
[ComImport]
[Guid("29131588-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesRichTextTableClass))]
public interface NotesRichTextTable : IRichTextTable
{
}
[ComImport]
[TypeLibType(4160)]
[Guid("29131588-2EED-1069-BF5D-00DD011186B7")]
public interface IRichTextTable
{
	[DispId(1610743808)]
	[ComAliasName("Domino.RT_TBLSTYLE")]
	RT_TBLSTYLE Style
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: ComAliasName("Domino.RT_TBLSTYLE")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		[param: ComAliasName("Domino.RT_TBLSTYLE")]
		set;
	}

	[DispId(1610743809)]
	int RowCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		get;
	}

	[DispId(1610743810)]
	int ColumnCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
	}

	[DispId(1610743811)]
	bool RightToLeft
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[param: In]
		set;
	}

	[DispId(1610743813)]
	object RowLabels
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1610743815)]
	NotesColorObject Color
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[DispId(1610743816)]
	NotesColorObject AlternateColor
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743817)]
	void AddRow([In] int lCount = 65535, [In] int lTargetRow = 65535);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743818)]
	void RemoveRow([In] int lCount = 65535, [In] int lTargetRow = 65535);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743819)]
	void Remove();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743820)]
	void SetColor([In][MarshalAs(UnmanagedType.Interface)] NotesColorObject pIColorObj);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	void SetAlternateColor([In][MarshalAs(UnmanagedType.Interface)] NotesColorObject pIColorObj);
}
public enum RT_TBLSTYLE
{
	TABLESTYLE_NONE,
	TABLESTYLE_LEFTTOP,
	TABLESTYLE_TOP,
	TABLESTYLE_LEFT,
	TABLESTYLE_ALTERNATINGCOLS,
	TABLESTYLE_ALTERNATINGROWS,
	TABLESTYLE_RIGHTTOP,
	TABLESTYLE_RIGHT,
	TABLESTYLE_SOLID
}
public enum _RT_TBLSTYLE
{
	TABLESTYLE_NONE,
	TABLESTYLE_LEFTTOP,
	TABLESTYLE_TOP,
	TABLESTYLE_LEFT,
	TABLESTYLE_ALTERNATINGCOLS,
	TABLESTYLE_ALTERNATINGROWS,
	TABLESTYLE_RIGHTTOP,
	TABLESTYLE_RIGHT,
	TABLESTYLE_SOLID
}
[ComImport]
[TypeLibType(2)]
[ClassInterface(0)]
[Guid("29131550-2EED-1069-BF5D-00DD011186B7")]
public class NotesNoteCollectionClass : INoteCollection, NotesNoteCollection
{
	[DispId(1610743808)]
	public virtual extern bool SelectDocuments
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[param: In]
		set;
	}

	[DispId(1610743810)]
	public virtual extern bool SelectProfiles
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743810)]
		[param: In]
		set;
	}

	[DispId(1610743812)]
	public virtual extern bool SelectForms
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743812)]
		[param: In]
		set;
	}

	[DispId(1610743814)]
	public virtual extern bool SelectSubforms
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743814)]
		[param: In]
		set;
	}

	[DispId(1610743816)]
	public virtual extern bool SelectActions
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743816)]
		[param: In]
		set;
	}

	[DispId(1610743818)]
	public virtual extern bool SelectFramesets
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743818)]
		[param: In]
		set;
	}

	[DispId(1610743820)]
	public virtual extern bool SelectPages
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743820)]
		[param: In]
		set;
	}

	[DispId(1610743822)]
	public virtual extern bool SelectImageResources
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743822)]
		[param: In]
		set;
	}

	[DispId(1610743824)]
	public virtual extern bool SelectStyleSheetResources
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743824)]
		[param: In]
		set;
	}

	[DispId(1610743826)]
	public virtual extern bool SelectJavaResources
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[param: In]
		set;
	}

	[DispId(1610743828)]
	public virtual extern bool SelectMiscFormatElements
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		[param: In]
		set;
	}

	[DispId(1610743830)]
	public virtual extern bool SelectViews
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743830)]
		[param: In]
		set;
	}

	[DispId(1610743832)]
	public virtual extern bool SelectFolders
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743832)]
		[param: In]
		set;
	}

	[DispId(1610743834)]
	public virtual extern bool SelectNavigators
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743834)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743834)]
		[param: In]
		set;
	}

	[DispId(1610743836)]
	public virtual extern bool SelectMiscIndexElements
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743836)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743836)]
		[param: In]
		set;
	}

	[DispId(1610743838)]
	public virtual extern bool SelectIcon
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743838)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743838)]
		[param: In]
		set;
	}

	[DispId(1610743840)]
	public virtual extern bool SelectAgents
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743840)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743840)]
		[param: In]
		set;
	}

	[DispId(1610743842)]
	public virtual extern bool SelectOutlines
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743842)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743842)]
		[param: In]
		set;
	}

	[DispId(1610743844)]
	public virtual extern bool SelectDatabaseScript
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743844)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743844)]
		[param: In]
		set;
	}

	[DispId(1610743846)]
	public virtual extern bool SelectScriptLibraries
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743846)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743846)]
		[param: In]
		set;
	}

	[DispId(1610743848)]
	public virtual extern bool SelectDataConnections
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743848)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743848)]
		[param: In]
		set;
	}

	[DispId(1610743850)]
	public virtual extern bool SelectMiscCodeElements
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743850)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743850)]
		[param: In]
		set;
	}

	[DispId(1610743852)]
	public virtual extern bool SelectSharedFields
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743852)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743852)]
		[param: In]
		set;
	}

	[DispId(1610743854)]
	public virtual extern bool SelectHelpAbout
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743854)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743854)]
		[param: In]
		set;
	}

	[DispId(1610743856)]
	public virtual extern bool SelectHelpUsing
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743856)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743856)]
		[param: In]
		set;
	}

	[DispId(1610743858)]
	public virtual extern bool SelectHelpIndex
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743858)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743858)]
		[param: In]
		set;
	}

	[DispId(1610743860)]
	public virtual extern bool SelectReplicationFormulas
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743860)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743860)]
		[param: In]
		set;
	}

	[DispId(1610743862)]
	public virtual extern bool SelectACL
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743862)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743862)]
		[param: In]
		set;
	}

	[DispId(1610743864)]
	public virtual extern string SelectionFormula
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743864)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743864)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743866)]
	public virtual extern object SinceTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743866)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743866)]
		[param: In]
		[param: MarshalAs(UnmanagedType.Struct)]
		set;
	}

	[DispId(1610743868)]
	public virtual extern object LastBuildTime
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743868)]
		[return: MarshalAs(UnmanagedType.Struct)]
		get;
	}

	[DispId(1610743869)]
	public virtual extern int Count
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743869)]
		get;
	}

	[DispId(1610743870)]
	public virtual extern NotesDatabase Parent
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743870)]
		[return: MarshalAs(UnmanagedType.Interface)]
		get;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743871)]
	public virtual extern void SelectAllNotes([In] bool bFlag);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743872)]
	public virtual extern void SelectAllDataNotes([In] bool bFlag);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743873)]
	public virtual extern void SelectAllAdminNotes([In] bool bFlag);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743874)]
	public virtual extern void SelectAllDesignElements([In] bool bFlag);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743875)]
	public virtual extern void SelectAllFormatElements([In] bool bFlag);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743876)]
	public virtual extern void SelectAllIndexElements([In] bool bFlag);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743877)]
	public virtual extern void SelectAllCodeElements([In] bool bFlag);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743878)]
	public virtual extern void BuildCollection();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743879)]
	public virtual extern void ClearCollection();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743880)]
	public virtual extern void Add([In][MarshalAs(UnmanagedType.Struct)] object NoteIds);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743881)]
	public virtual extern void Remove([In][MarshalAs(UnmanagedType.Struct)] object NoteIds);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743882)]
	public virtual extern void Intersect([In][MarshalAs(UnmanagedType.Struct)] object NoteIds);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743883)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetFirstNoteId();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743884)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetNextNoteId([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);
}
[ComImport]
[CoClass(typeof(NotesNoteCollectionClass))]
[Guid("29131589-2EED-1069-BF5D-00DD011186B7")]
public interface NotesNoteCollection : INoteCollection
{
}
[ComImport]
[Guid("29131551-2EED-1069-BF5D-00DD011186B7")]
[ClassInterface(0)]
[TypeLibType(2)]
public class NotesDXLExporterClass : IDXLExporter, NotesDXLExporter
{
	[DispId(1610743808)]
	public virtual extern string Log
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	public virtual extern string LogComment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743811)]
	public virtual extern bool ExitOnFirstFatalError
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[param: In]
		set;
	}

	[DispId(1610743813)]
	public virtual extern bool ForceNoteFormat
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[param: In]
		set;
	}

	[DispId(1610743815)]
	public virtual extern bool OutputDOCTYPE
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[param: In]
		set;
	}

	[DispId(1610743817)]
	public virtual extern string DoctypeSYSTEM
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743819)]
	public virtual extern bool ConvertNotesbitmapsToGIF
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		[param: In]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743821)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string Export([In][MarshalAs(UnmanagedType.Struct)] object Input);
}
[ComImport]
[Guid("29131590-2EED-1069-BF5D-00DD011186B7")]
[CoClass(typeof(NotesDXLExporterClass))]
public interface NotesDXLExporter : IDXLExporter
{
}
[ComImport]
[ClassInterface(0)]
[TypeLibType(2)]
[Guid("29131552-2EED-1069-BF5D-00DD011186B7")]
public class NotesDXLImporterClass : IDXLImporter, NotesDXLImporter
{
	[DispId(1610743808)]
	public virtual extern string Log
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743808)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
	}

	[DispId(1610743809)]
	public virtual extern string LogComment
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[return: MarshalAs(UnmanagedType.BStr)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743809)]
		[param: In]
		[param: MarshalAs(UnmanagedType.BStr)]
		set;
	}

	[DispId(1610743811)]
	public virtual extern bool ExitOnFirstFatalError
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743811)]
		[param: In]
		set;
	}

	[DispId(1610743813)]
	[ComAliasName("Domino.DXLIMPORTOPTION")]
	public virtual extern DXLIMPORTOPTION ACLImportOption
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[return: ComAliasName("Domino.DXLIMPORTOPTION")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743813)]
		[param: In]
		[param: ComAliasName("Domino.DXLIMPORTOPTION")]
		set;
	}

	[ComAliasName("Domino.DXLIMPORTOPTION")]
	[DispId(1610743815)]
	public virtual extern DXLIMPORTOPTION DesignImportOption
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[return: ComAliasName("Domino.DXLIMPORTOPTION")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		[param: In]
		[param: ComAliasName("Domino.DXLIMPORTOPTION")]
		set;
	}

	[DispId(1610743817)]
	[ComAliasName("Domino.DXLIMPORTOPTION")]
	public virtual extern DXLIMPORTOPTION DocumentImportOption
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[return: ComAliasName("Domino.DXLIMPORTOPTION")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743817)]
		[param: In]
		[param: ComAliasName("Domino.DXLIMPORTOPTION")]
		set;
	}

	[DispId(1610743819)]
	public virtual extern bool ReplaceDBProperties
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743819)]
		[param: In]
		set;
	}

	[DispId(1610743821)]
	[ComAliasName("Domino.VALIDATIONOPTION")]
	public virtual extern VALIDATIONOPTION InputValidationOption
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[return: ComAliasName("Domino.VALIDATIONOPTION")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743821)]
		[param: In]
		[param: ComAliasName("Domino.VALIDATIONOPTION")]
		set;
	}

	[DispId(1610743823)]
	public virtual extern bool CreateFTIndex
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743823)]
		[param: In]
		set;
	}

	[DispId(1610743825)]
	public virtual extern int ImportedNoteCount
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743825)]
		get;
	}

	[DispId(1610743826)]
	public virtual extern bool ReplicaRequiredForReplaceOrUpdate
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743826)]
		[param: In]
		set;
	}

	[DispId(1610743828)]
	[ComAliasName("Domino.DXLLOGOPTION")]
	public virtual extern DXLLOGOPTION UnknownTokenLogOption
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		[return: ComAliasName("Domino.DXLLOGOPTION")]
		get;
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743828)]
		[param: In]
		[param: ComAliasName("Domino.DXLLOGOPTION")]
		set;
	}

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743830)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetFirstImportedNoteId();

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743831)]
	[return: MarshalAs(UnmanagedType.BStr)]
	public virtual extern string GetNextImportedNoteId([In][MarshalAs(UnmanagedType.BStr)] string pNoteid);

	[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
	[DispId(1610743832)]
	public virtual extern void Import([In][MarshalAs(UnmanagedType.Struct)] object Input, [In][MarshalAs(UnmanagedType.Struct)] object importDB);
}
[ComImport]
[CoClass(typeof(NotesDXLImporterClass))]
[Guid("29131591-2EED-1069-BF5D-00DD011186B7")]
public interface NotesDXLImporter : IDXLImporter
{
}
public enum NOTES_ERRORS
{
	ERR_NOTES_ERROR = -2147217504,
	ERR_SYS_OUT_OF_MEMORY = -2147217503,
	ERR_SYS_LOAD_OUT_OF_MEM = -2147217502,
	ERR_SYS_FILE_NOT_FOUND = -2147217501,
	ERR_SYS_DICT_NOT_ON_PATH = -2147217500,
	ERR_NOTES_ERROR2 = -2147217499,
	ERR_SYS_RESOURCE_NOT_FOUND = -2147217496,
	ERR_SYS_LOADING_RESOURCE = -2147217495,
	ERR_SYS_LOCKING_RESOURCE = -2147217494,
	ERR_SYS_FREEING_RESOURCE = -2147217493,
	ERR_SYS_NOSUCH_RESOURCE = -2147217492,
	ERR_SYS_WARNING_TITLE = -2147217488,
	ERR_MAIL_COPEN_FAILED = -2147217478,
	ERR_MAIL_PAOPEN_FAILED = -2147217477,
	ERR_MAIL_LAOPEN_FAILED = -2147217476,
	ERR_MAIL_VIM_MESSAGE = -2147217475,
	ERR_MAIL_CANT_CREATE = -2147217474,
	ERR_MAIL_UNKNOWN_PROP = -2147217473,
	ERR_MAIL_INVALID_MSG = -2147217472,
	ERR_MAIL_NOPUBLIC_GRP = -2147217471,
	ERR_MAIL_NOPRIVATE_GRP = -2147217470,
	ERR_MAIL_GRPCREATE_FAILED = -2147217469,
	ERR_MAIL_GROUP_DELETED = -2147217468,
	ERR_MAIL_NAME_REQUIRED = -2147217467,
	ERR_NOTES_FAILURE = -2147217466,
	ERR_NOTES_NOSUCH_VIEW = -2147217465,
	ERR_NOTES_NOFTINDEX = -2147217464,
	ERR_NOTES_DBCREATE_FAILED = -2147217463,
	ERR_NOTES_DBDELETE_FAILED = -2147217462,
	ERR_NOTES_DBOPEN_FAILED = -2147217461,
	ERR_NOTES_INVALID_FORMULA = -2147217460,
	ERR_NOTES_INVALID_DATE = -2147217459,
	ERR_NOTES_COPY_FAILED = -2147217458,
	ERR_NOTES_VIEWOPEN_FAILED = -2147217457,
	ERR_NOTES_NOTEDEL_FAILED = -2147217456,
	ERR_NOTES_NEXTITEM_FAILED = -2147217455,
	ERR_NOTES_FINDITEM_FAILED = -2147217454,
	ERR_NOTES_MODLOAD_FAILED = -2147217453,
	ERR_NOTES_PROCFIND_FAILED = -2147217452,
	ERR_NOTES_RTWRITE_FAILED = -2147217451,
	ERR_NOTES_RTCONVERT_FAILED = -2147217450,
	ERR_NOTES_FTSRCH_FAILED = -2147217449,
	ERR_NOTES_QUERY_FAILED = -2147217448,
	ERR_NOTES_DOCSEARCH_FAILED = -2147217447,
	ERR_NOTES_ITEMCOPY_FAILED = -2147217446,
	ERR_NOTES_CREATENOTE_FAILED = -2147217445,
	ERR_NOTES_DBNOACCESS = -2147217444,
	ERR_NOTES_UNAME_LOOKUP = -2147217443,
	ERR_NOTES_SESOPEN_FAILED = -2147217442,
	ERR_NOTES_DATABASE_NOTOPEN = -2147217441,
	ERR_NOTES_SESSION_DATECONV = -2147217440,
	ERR_NOTES_SESSION_VALNOTSUPP = -2147217439,
	ERR_NOTES_CANT_GETNTH = -2147217438,
	ERR_NOTES_ATTACH_FAILED = -2147217437,
	ERR_NOTES_DETACH_FAILED = -2147217436,
	ERR_NOTES_EXTRACT_FAILED = -2147217435,
	ERR_NOTES_DIRSEARCH_FAILED = -2147217434,
	ERR_NOTES_BAD_INDEX = -2147217433,
	ERR_NOTES_NOSUCH_DIRECTORY = -2147217432,
	ERR_CDTEXTCREATE_FAILED = -2147217431,
	ERR_CDASSIM_FAILED = -2147217430,
	ERR_NOT_RT_ITEM = -2147217429,
	ERR_NOTES_FORMCOMP_FAILED = -2147217428,
	ERR_NOTES_FORMEVAL_FAILED = -2147217427,
	ERR_NOTES_ITEMCREATE_FAILED = -2147217426,
	ERR_NOTES_DECRYPT_FAILED = -2147217425,
	ERR_NOTES_NOTLOCAL_IDX = -2147217424,
	ERR_NOTES_FTIDX_FAILED = -2147217423,
	ERR_NOTES_NOTEOPEN_FAILED = -2147217422,
	ERR_NOTES_RENDER_FAILED = -2147217421,
	ERR_NOTES_FILENOTFOUND = -2147217420,
	ERR_NOTES_UNKNOWN_TYPE = -2147217419,
	ERR_NOTES_FILEOPEN_FAILED = -2147217418,
	ERR_NOTES_FILEWRITE_FAILED = -2147217417,
	ERR_NOTES_DATE_NOTSET = -2147217416,
	ERR_NOTES_NODBNAME = -2147217415,
	ERR_NOTES_TEMPLCOPY_FAILED = -2147217414,
	ERR_NOTES_BAD_UNID = -2147217413,
	ERR_NOTES_UNAME_REQ = -2147217412,
	ERR_NOTES_GETACL_FAILED = -2147217411,
	ERR_NOTES_ACLENTRY_FAILED = -2147217410,
	ERR_NOTES_ACL_INVALID = -2147217409,
	ERR_NOTES_QUERYACL_FAILED = -2147217408,
	ERR_NOTES_REFRESH_FAILED = -2147217407,
	ERR_NOTES_OLEPKG_FAILED = -2147217406,
	ERR_NOTES_TMPFILE_FAILED = -2147217405,
	ERR_NOTES_READFILE_FAILED = -2147217404,
	ERR_NOTES_RTRENDER_FAILED = -2147217403,
	ERR_NOTES_WRONG_CLASS = -2147217402,
	ERR_NOTES_INVALID_ID = -2147217401,
	ERR_NOTES_INVALID_AGENT = -2147217400,
	ERR_NOTES_VIEWCLONE_FAILED = -2147217399,
	ERR_NOTES_NOVIEWNAME = -2147217398,
	ERR_NOTES_NEWSGROUPDB_FAILED = -2147217397,
	ERR_NOTES_NONEWSGROUPNAME = -2147217396,
	ERR_NOTES_ARC_NOT_ENABLED = -2147217395,
	ERR_NOTES_ARC_INCORRECT_PROFILE = -2147217394,
	ERR_NOTES_ARC_REQ_SRC_ACCESS = -2147217393,
	ERR_NOTES_ARC_REQ_ARC_ACCESS = -2147217392,
	ERR_NOTES_ARC_INCORRECT_SVR = -2147217391,
	ERR_NOTES_ARC_ARCFILE_NOT_ON_SVR = -2147217390,
	ERR_NOTES_ARC_FAILED = -2147217389,
	ERR_NOTES_ARC_SERVER_ARCHIVING = -2147217388,
	ERR_NOTES_ARC_SETTINGS_SIGNATURE = -2147217387,
	ERR_NOTES_ARC_REQ_SRC_USER_ACCESS = -2147217386,
	ERR_NOTES_ARC_REQ_ARC_USER_ACCESS = -2147217385,
	ERR_NOTES_ARC_PROHIBITED = -2147217384,
	ERR_LOG_DBOPEN_FAILED = -2147217369,
	ERR_LOG_FOPEN_FAILED = -2147217368,
	ERR_LOG_CDCREATE_FAILED = -2147217367,
	ERR_LOG_MAILLOG_FAILED = -2147217366,
	ERR_MEM_HVPOOLFULL = -2147217365,
	ERR_NOTES_COPYACL_FAILED = -2147217354,
	ERR_NOTES_DOC_NOTINVIEW = -2147217353,
	ERR_NOTES_NOFTQUERY = -2147217352,
	ERR_NOTES_NOITEMNAME = -2147217351,
	ERR_NOTES_NOTEUPDATE_FAILED = -2147217350,
	ERR_NOTES_NOTELOCATE_FAILED = -2147217349,
	ERR_NOTES_VIEWDEL_FAILED = -2147217348,
	ERR_LOG_CONSTRUCT_FAILED = -2147217347,
	ERR_SEM_ALLOC_FAILED = -2147217346,
	ERR_NOTES_LOOKUP_FAILED = -2147217345,
	ERR_NOTES_SEND_FAILED = -2147217344,
	ERR_NOTES_NCREATE_FAILED = -2147217343,
	ERR_MACRO_IDTBL_FAILED = -2147217342,
	ERR_MACRO_RUN_FAILED = -2147217341,
	ERR_NOTES_DBOPEN_NOTLOCAL = -2147217340,
	ERR_NOTES_SIGN_NOPERM = -2147217339,
	ERR_NOTES_ENCRYPT_NOPERM = -2147217338,
	ERR_NOTES_ENCRYPT_FAILED = -2147217337,
	ERR_NOTES_NOSENDTO = -2147217336,
	ERR_LOG_EVENTPUT_FAILED = -2147217335,
	ERR_LOG_INVALID_EVTYPE = -2147217334,
	ERR_LOG_INVALID_SEVERITY = -2147217333,
	ERR_NOTES_NO_NEWSLETTERDOCS = -2147217332,
	ERR_NOTES_MAILDBOPEN_FAILED = -2147217331,
	ERR_NOTES_NEWSLETTER_FAILED = -2147217330,
	ERR_NOTES_DFLT_VID_FAILED = -2147217329,
	ERR_NOTES_KEYFIND_FAILED = -2147217328,
	ERR_NOTES_RTTEXT_FAILED = -2147217327,
	ERR_NOTES_RTDOCLINK_FAILED = -2147217326,
	ERR_NOTES_NOPERM_DISKIO = -2147217325,
	ERR_NOTES_NOPERM_SIGN = -2147217324,
	ERR_NOTES_NOPERM_ENCRYPT = -2147217323,
	ERR_NOTES_NOPERM_ENVIRON = -2147217322,
	ERR_NOTES_NOPERM_ANY = -2147217321,
	ERR_NOTES_NOSERV_DB = -2147217320,
	ERR_NOTES_INVALID_DB = -2147217319,
	ERR_NOTES_INVALID_CREDEL = -2147217318,
	ERR_NOTES_INVALID_DOC = -2147217317,
	ERR_NOTES_DBS_MUST_MATCH = -2147217316,
	ERR_NOTES_RESPONSE_FAILED = -2147217315,
	ERR_NOTES_NOLISTS = -2147217314,
	ERR_NOTES_CONTAINS_FAILED = -2147217313,
	ERR_NOTES_MUSTBE_STRING = -2147217312,
	ERR_NOTES_DESVIEW_FAILED = -2147217311,
	ERR_NOTES_ITEMARR_FAILED = -2147217310,
	ERR_NOTES_SRVSEARCH_FAILED = -2147217309,
	ERR_NOTES_UNKNOWN_SRCHTYPE = -2147217308,
	ERR_NOTES_MUSTCALL_FIRSTDB = -2147217307,
	ERR_NOTES_ALLDOCS_FAILED = -2147217306,
	ERR_NOTES_ITYPENOT_TEXT = -2147217305,
	ERR_NOTES_INVALID_ITYPE = -2147217304,
	ERR_NOTES_NOSUCH_FOLDER = -2147217303,
	ERR_NOTES_ADDRBOOK_FAILED = -2147217302,
	ERR_NOTES_NOTCONTEXT_DB = -2147217301,
	ERR_NOTES_LTDACCESS_FAILED = -2147217300,
	ERR_NOTES_LTDUPDATE_FAILED = -2147217299,
	ERR_NOTES_BADVIEW_VERSION = -2147217298,
	ERR_NOTES_NEED_ADT = -2147217297,
	ERR_NOTES_ACLWRITE_FAILED = -2147217296,
	ERR_NOTES_RENAME_FAILED = -2147217295,
	ERR_NOTES_NOSUCH_ROLENAME = -2147217294,
	ERR_NOTES_PRIVNAME_FAILED = -2147217293,
	ERR_NOTES_READPRIV_FAILED = -2147217292,
	ERR_NOTES_DELPRIV_FAILED = -2147217291,
	ERR_NOTES_DELENTRY_FAILED = -2147217290,
	ERR_NOTES_NOSERV_EVENTS = -2147217289,
	ERR_NOTES_INVALID_ACLENTRYNAME = -2147217288,
	ERR_NOTES_ENTRYNAME_FAILED = -2147217287,
	ERR_NOTES_NOTLOCAL_REPL = -2147217286,
	ERR_NOTES_REPL_FAILED = -2147217285,
	ERR_NOTES_NOTLOCAL_COMPACT = -2147217284,
	ERR_NOTES_COMPACT_FAILED = -2147217283,
	ERR_NOTES_TIMEADJUST_FAILED = -2147217282,
	ERR_NOTES_NOSUCH_EMBED = -2147217281,
	ERR_NOTES_NOSUCH_EOFILE = -2147217280,
	ERR_NOTES_NOSUCH_PATH = -2147217279,
	ERR_NOTES_EMBEDARR_FAILED = -2147217278,
	ERR_NOTES_NOADDRS_FOUND = -2147217277,
	ERR_NOTES_DUP_ROLENAME = -2147217276,
	ERR_NOTES_CANTCREATE_FOLDER = -2147217275,
	ERR_NOTERENDER_FAILED = -2147217274,
	ERR_NOFROMFIELD = -2147217273,
	ERR_TEXTLIST_FAILED = -2147217272,
	ERR_NOTES_NOTA_DOCUMENT = -2147217271,
	ERR_NOTES_VALIDATE_FAILED = -2147217270,
	ERR_NOTES_ABSTRACT_BUFFER = -2147217269,
	ERR_NOTES_ABSTRACTING_TEXT = -2147217268,
	ERR_NOTES_DESAGENT_FAILED = -2147217267,
	ERR_NOTES_MIXED_ARRAY = -2147217266,
	ERR_NOTES_INVALID_DOCLINK = -2147217265,
	ERR_TEXTLIST_BAD_INPUT = -2147217264,
	ERR_NOTES_CANTREMOVE = -2147217263,
	ERR_NOTES_CANTENCRYPT = -2147217262,
	ERR_NOTES_CANTCLOSEDB = -2147217261,
	ERR_NOTES_CANTRUN_OLEOBJ = -2147217260,
	ERR_NOTES_CANTSHOW_OLEOBJ = -2147217259,
	ERR_NOTES_NOEMBEDDED_OBJ = -2147217258,
	ERR_NOTES_NOSUCH_EMBEDCLASS = -2147217257,
	ERR_NOTES_CANTGET_DBSUMMARY = -2147217256,
	ERR_NOTES_CANTCOPY_ITEMTYPE = -2147217255,
	ERR_NOTES_NEED_DB = -2147217254,
	ERR_NOTES_NEED_NOTE = -2147217253,
	ERR_NOTES_CANT_LINK_OLE1 = -2147217252,
	ERR_NOTES_ROLENAME_TOOBIG = -2147217251,
	ERR_NOTES_EOARRAY_FAILED = -2147217250,
	ERR_NOTES_ATTACHINFO_FAILED = -2147217249,
	ERR_NOTES_QUOTAINFO_FAILED = -2147217248,
	ERR_NOTES_DOCNOTSAVED = -2147217247,
	ERR_NOTES_ACLNEXT_INVALID = -2147217246,
	ERR_NOTES_NOTAFILE = -2147217245,
	ERR_NOTES_CANTFIND_ATTACHMENT = -2147217244,
	ERR_NOTES_NOSUCH_VERB = -2147217243,
	ERR_NOTES_DOVERB_FAILED = -2147217242,
	ERR_NOTES_INVALID_ADTTYPE = -2147217241,
	ERR_NOTES_FTQUERY_FAILED = -2147217240,
	ERR_NOTES_NOSUCH_DBID = -2147217239,
	ERR_NOTES_OPENBYRID_FAILED = -2147217238,
	ERR_NOTES_BAD_UNPROCFT = -2147217237,
	ERR_AGENT_NO_RECURSION = -2147217236,
	ERR_NOTES_CANTGET_MAILSERVER = -2147217235,
	ERR_NOTES_BAD_NOTEID = -2147217234,
	ERR_NOTES_DBSECURITY = -2147217233,
	ERR_NOTES_DELETE_AGENT = -2147217232,
	ERR_NOTES_RUN_AGENT = -2147217231,
	ERR_NOTES_NOSUCH_DOCINDEX = -2147217230,
	ERR_NOTES_BAD_SOURCE_CLASS = -2147217229,
	ERR_NOTES_CANT_CHANGE_DEFACL = -2147217228,
	ERR_NOTES_LINKNOCLASS = -2147217227,
	ERR_NOTES_CANTDO_ARRAYOFARRAY = -2147217226,
	ERR_NOTES_SESSION_CLOSED = -2147217225,
	ERR_NOTES_CANTOPEN_URLDB = -2147217224,
	ERR_NOTES_NEED_URL = -2147217223,
	ERR_NOTES_INVALID_URL = -2147217222,
	ERR_NOTES_INVALID_URLHEADER = -2147217221,
	ERR_NOTES_NOSUCH_URLHEADER = -2147217220,
	ERR_NOTES_NOUNPROC_DOCS = -2147217219,
	ERR_NOTES_EMBED_FAILED = -2147217218,
	ERR_NOTES_NODEL_CURRENTDB = -2147217217,
	ERR_NOTES_INVALID_TIMEEXPR = -2147217216,
	ERR_NOTES_RECURSIVE_RENDER = -2147217215,
	ERR_NOTES_INVALID_ITEM = -2147217214,
	ERR_NOTES_NOMOVETO_PRIV1STUSE = -2147217213,
	ERR_NOTES_SAMESRV_REPLICA = -2147217212,
	ERR_NOTES_CANT_SIGN = -2147217211,
	ERR_NOTES_NO_MATCH = -2147217210,
	ERR_NOTES_AMBIGUOUS_MATCH = -2147217209,
	ERR_NOTES_DBALREADY_OPEN = -2147217208,
	ERR_NOTES_OLE_NOTAVAIL = -2147217207,
	ERR_NOTES_ARRAY_NOGOOD = -2147217206,
	ERR_NOTES_REGARG_NOTGIVEN = -2147217205,
	ERR_NOTES_MISSING_CERTID = -2147217204,
	ERR_NOTES_NOCERT_CTX = -2147217203,
	ERR_NOTES_REGFAILED = -2147217202,
	ERR_NOTES_SRVREGFAILED = -2147217201,
	ERR_NOTES_CERTREGFAILED = -2147217200,
	ERR_NOTES_XCERTFAILED = -2147217199,
	ERR_NOTES_RECERTFAILED = -2147217198,
	ERR_NOTES_NOSUCH_BOOL = -2147217197,
	ERR_NOTES_CANTSWITCH_ID = -2147217196,
	ERR_NOTES_NOSUCH_MAILPATH = -2147217195,
	ERR_NOTES_BAD_IDFILE = -2147217194,
	ERR_NOTES_CANTADD_USER = -2147217193,
	ERR_NOTES_CANTADD_SERV = -2147217192,
	ERR_NOTES_CANTADD_CERT = -2147217191,
	ERR_NOTES_NOCURRENT_AGENT = -2147217190,
	ERR_NOTES_AGENTLOG_FAILED = -2147217189,
	ERR_NOTES_NOSUCH_CERTIDTYPE = -2147217188,
	ERR_NOTES_NOCURRENT_FTRESULT = -2147217187,
	ERR_NOTES_IDTBL_FAILED = -2147217186,
	ERR_NOTES_PROF_ARG_MISSING = -2147217185,
	ERR_NOTES_NOSUCH_PROFILE = -2147217184,
	ERR_NOTES_PROFUPDATE_FAILED = -2147217183,
	ERR_NOTES_PROFDELETE_FAILED = -2147217182,
	ERR_NOTES_NOSUCH_ARG = -2147217181,
	ERR_NOTES_WRONG_UNID_LEN = -2147217180,
	ERR_NOTES_DESFORM_FAILED = -2147217179,
	ERR_NOTES_FORMDEL_FAILED = -2147217178,
	ERR_NOTES_NOCLOSE_CURRDB = -2147217177,
	ERR_NOTES_FREETIME_FAILED = -2147217176,
	ERR_NOTES_UNIFORM_FAILED = -2147217175,
	ERR_NOTES_GETOPTION_FAILED = -2147217174,
	ERR_NOTES_MARKREAD_FAILED = -2147217173,
	ERR_NOTES_MARKUNREAD_FAILED = -2147217172,
	ERR_NOTES_MULTIDB_FAILED = -2147217171,
	ERR_NOTES_ADDPROF_FAILED = -2147217170,
	ERR_NOTES_ULOOKUP_FAILED = -2147217169,
	ERR_NOTES_INVALID_OBJECT = -2147217168,
	ERR_NOTES_STAMP_FAILED = -2147217167,
	ERR_NOTES_BAD_ORGUNIT = -2147217166,
	ERR_NOTES_BAD_FTSORT = -2147217165,
	ERR_NOTES_NOTCONTEXT_COLLEC = -2147217164,
	ERR_NOTES_ECLACCESS_FAILED = -2147217163,
	ERR_NOTES_W32DOM_FAILED = -2147217162,
	ERR_NOTES_W32DOM_NOFIRSTUSER = -2147217161,
	ERR_NOTES_W32DOM_BADPLATFORM = -2147217160,
	ERR_NOTES_W32DOM_BADNETAPI32 = -2147217159,
	ERR_NOTES_W32DOM_DOMAIN_CONTROLLER = -2147217158,
	ERR_NOTES_TOOMANY_SORT_KEYS = -2147217157,
	ERR_NOTES_BAD_KEYTYPE = -2147217156,
	ERR_NOTES_CANT_SELF_ASSIMILATE = -2147217155,
	ERR_NOTES_CANT_SELF_COPY = -2147217154,
	ERR_NOTES_POP3_FAILED = -2147217153,
	ERR_NOTES_ARRCREATE_FAILED = -2147217152,
	ERR_NOTES_AGSAVE_FAILED = -2147217151,
	ERR_NOTES_CANTREMOVE_AGC = -2147217150,
	ERR_NOTES_CANTENCRYPT_AGC = -2147217149,
	ERR_NOTES_RTSTYLE_CREATEFAILED = -2147217148,
	ERR_NOTES_RTSTYLE_APPENDFAILED = -2147217147,
	ERR_NOTES_RTSTYLE_BADFONT = -2147217146,
	ERR_NOTES_NO_CONTEXTDB = -2147217145,
	ERR_NOTES_NULL_APPENDLIST = -2147217144,
	ERR_NOTES_NOSUCH_JAVA_TYPE = -2147217143,
	ERR_NOTES_INVALID_JARRAY = -2147217142,
	ERR_NOTES_RTSTYLE_BADBOOL = -2147217141,
	ERR_NOTES_RTSTYLE_BADFONTSIZE = -2147217140,
	ERR_NOTES_RTSTYLE_BADCOLOR = -2147217139,
	ERR_NOTES_RTSTYLE_BADEFFECT = -2147217138,
	ERR_NOTES_NOTREMOTE_DB = -2147217137,
	ERR_NOTES_RTITEM_EXISTS = -2147217136,
	ERR_NOTES_NOFORM = -2147217135,
	ERR_NOTES_NOTA_VECTOR = -2147217134,
	ERR_NOTES_SERVER_SWITCH = -2147217133,
	ERR_NOTES_DBDIR_THREAD = -2147217132,
	ERR_NOTES_ACL_CONSTRUCTOR_FAILED = -2147217124,
	ERR_NOTES_ACL_INVALID_TYPE = -2147217123,
	ERR_NOTES_INVALID_TIMEZONE = -2147217121,
	ERR_NOTES_VIEW_STATS = -2147217120,
	ERR_NOTES_VIEW_ENTRY_READ = -2147217119,
	ERR_NOTES_DBFOLDERREFS_NOT_SUPPORTED = -2147217118,
	ERR_NOTES_DBFOLDERREFS_NOT_ENABLED = -2147217117,
	ERR_NOTES_VE_NO_SEPARATOR = -2147217116,
	ERR_NOTES_STRING_TOO_LONG = -2147217115,
	ERR_NOTES_VIEW_FMT_READ = -2147217114,
	ERR_NOTES_VIEW_INVALID_COLUMN = -2147217108,
	ERR_NOTES_NO_COLLECTION = -2147217131,
	ERR_NOTES_NOT_IN_SESSION = -2147217130,
	ERR_NOTES_INVALID_NAME = -2147217129,
	ERR_NOTES_DELETED = -2147217128,
	ERR_NOTES_NOT_LOCAL = -2147217127,
	ERR_NOTES_INVALID_RANGE = -2147217126,
	ERR_NOTES_OBJECT_NOT_FOUND = -2147217125,
	ERR_NOTES_ITEM_CONVERT = -2147217122,
	ERR_NOTES_VIEW_BAD_ENTRY = -2147217113,
	ERR_NOTES_VIEWNAV_BAD_MAX = -2147217112,
	ERR_NOTES_VIEWNAV_BAD_POS = -2147217111,
	ERR_NOTES_VIEWNAV_BAD_PARENT = -2147217110,
	ERR_NOTES_NOT_IMPLEMENTED = -2147217109,
	ERR_NOTES_RTPSTYLE_APPENDFAILED = -2147217107,
	ERR_NOTES_RTPSTYLE_TOOMANYTABS = -2147217106,
	ERR_NOTES_RTPSTYLE_OUTOFRANGE = -2147217105,
	ERR_NOTES_RTPSTYLE_BADALIGN = -2147217104,
	ERR_NOTES_RTPSTYLE_BADSPACING = -2147217103,
	ERR_NOTES_RTPSTYLE_BADPAGINATE = -2147217102,
	ERR_NOTES_ACL_MISSING = -2147217101,
	ERR_NOTES_SESSION_MISSING = -2147217100,
	ERR_NOTES_DATABASE_MISSING = -2147217099,
	ERR_NOTES_DOCUMENT_MISSING = -2147217098,
	ERR_NOTES_VIEW_MISSING = -2147217097,
	ERR_NOTES_PARENT_MISSING = -2147217096,
	ERR_NOTES_NOT_RICHTEXT = -2147217095,
	ERR_NOTES_PSTYPE_MISSING = -2147217094,
	ERR_NOTES_REMOVEALL_FAILED = -2147217093,
	ERR_NOTES_ENTRY_NOT_FROM_COLLECTION = -2147217092,
	ERR_NOTES_NOTE_NOT_FROM_COLLECTION = -2147217091,
	ERR_NOTES_ADDENTRY_DUP = -2147217090,
	ERR_NOTES_ADDENTRY_FAILED = -2147217089,
	ERR_MACRO_SYNCH_ENABLE_FAILED = -2147217088,
	ERR_NOTES_SYNCH_RUN_AGENT = -2147217087,
	ERR_NOTES_SYNCH_NOOLE = -2147217086,
	ERR_NOTES_RTPSTYLE_BADTABTYPE = -2147217085,
	ERR_NOTES_GETALLENTRIES_FAILED = -2147217084,
	ERR_NOTES_EXECUTESETUP_FAILED = -2147217083,
	ERR_NOTES_MAXDBSIZE_EXCEEDED = -2147217082,
	ERR_NOTES_INVALID_NAV = -2147217081,
	ERR_NOTES_SVRACCESS_FAILED = -2147217079,
	ERR_NOTES_NOT_IN_VIEW = -2147217078,
	ERR_NOTES_NOT_IN_DB = -2147217077,
	ERR_NOTES_PROP_NOT_AVAIL = -2147217076,
	ERR_NOTES_NOT_IN_ACL = -2147217075,
	ERR_NOTES_NO_LOGS_OPEN = -2147217074,
	ERR_NOTES_CACHE_SZ_INVALID = -2147217073,
	ERR_NOTES_VIEW_ENTRY_REMOVED = -2147217072,
	ERR_NOTES_VIEW_ENTRY_DELETED = -2147217071,
	ERR_NOTES_DOCUMENT_DELETED = -2147217070,
	ERR_NOTES_SYNCH_INVALIDOP = -2147217069,
	ERR_NOTES_CREATEOUTLINE_FAILED = -2147217068,
	ERR_NOTES_HTML_GENFAILED = -2147217067,
	ERR_NOTES_CREATE_DOCCOLL_FAILED = -2147217066,
	ERR_NOTES_EXECUTESETUP_FAILED2 = -2147217065,
	ERR_NOTES_CANTUPDATE_FOLDER = -2147217064,
	ERR_NOTES_RTITEM_MISSING = -2147217063,
	ERR_NOTES_NO_AUTHORIZATION = -2147217062,
	ERR_NOTES_NAME_MISSING = -2147217061,
	ERR_NOTES_ITEM_MISSING = -2147217060,
	ERR_NOTES_DATERANGE_MISSING = -2147217059,
	ERR_NOTES_VIEWENTRY_MISSING = -2147217058,
	ERR_NOTES_VIEWENTRY_OR_DOC_MISSING = -2147217057,
	ERR_NOTES_OUTLINE_MISSING = -2147217056,
	ERR_NOTES_DATETIME_MISSING = -2147217055,
	ERR_NOTES_VNAV_CAT_PARENT = -2147217054,
	ERR_NOTES_VNAV_CAT_GOTO = -2147217053,
	ERR_NOTES_INVALID_SIZE = -2147217052,
	ERR_NOTES_REGSERVER_NOTSET = -2147217051,
	ERR_NOTES_NOT_ATTACHMENT = -2147217050,
	ERR_NOTES_URL_NOT_RESOLVED = -2147217049,
	ERR_NOTES_INVALID_IOR = -2147217048,
	ERR_NOTES_GETIOR_FAILED = -2147217047,
	ERR_NOTES_INVALID_DATESPEC = -2147217046,
	ERR_NOTES_INVALID_TIMESPEC = -2147217045,
	ERR_NOTES_CANTSAVE_CURRENTAGENT = -2147217044,
	ERR_NOTES_CANTDISABLE_MANUALAGENT = -2147217043,
	ERR_NOTES_BAD_ENTRYDOC = -2147217042,
	ERR_NOTES_UNINITIALIZED_THREAD = -2147217041,
	ERR_NOTES_INVALIDATED_OBJECT = -2147217040,
	ERR_NOTES_ACL_ROLE_INVALID = -2147217039,
	ERR_NOTES_ARG_DELETED = -2147217038,
	ERR_NOTES_ACLENTRY_MISSING = -2147217037,
	ERR_NOTES_INVALID_DATE_NOARG = -2147217036,
	ERR_NOTES_ADDDOC_DUP = -2147217035,
	ERR_NOTES_BADDBSIZE = -2147217034,
	ERR_NOTES_BAD_OUTLINE_ENTRY = -2147217033,
	ERR_NOTES_CANTMODIFY_REMOTE_AGENT = -2147217032,
	ERR_NOTES_CANT_ADD_CHILD_BEFORE_ENTRY = -2147217031,
	ERR_NOTES_NULL_REF_ENTRY = -2147217030,
	ERR_NOTES_REF_ENTRY_NOTINOUTLINE = -2147217029,
	ERR_NOTES_OUTLINE_ADDENTRY_FAILED = -2147217028,
	ERR_NOTES_OUTLINE_MOVEENTRY_FAILED = -2147217027,
	ERR_NOTES_OUTLINE_REMOVEENTRY_FAILED = -2147217026,
	ERR_NOTES_INVALID_PLACEHOLDER_PARENT = -2147217025,
	ERR_NOTES_INVALID_REPLICATION_PRIORITY = -2147217024,
	ERR_NOTES_OUTLINE_INVALID_PRIVATE_VIEW = -2147217023,
	ERR_NOTES_NOT_SUPPORTED = -2147217022,
	ERR_NOTES_NEED_HDRNAME = -2147217021,
	ERR_NOTES_NEED_MIMEENT = -2147217020,
	ERR_NOTES_ITEM_EXISTS = -2147217019,
	ERR_NOTES_INVALID_USERNAME_PASSWD = -2147217018,
	ERR_NOTES_INVALID_USERNAME = -2147217017,
	ERR_NOTES_SERVER_ACCESS_DENIED = -2147217016,
	ERR_NOTES_NO_SERVER = -2147217015,
	ERR_NOTES_SESSION_NOT_INIT = -2147217013,
	ERR_NOTES_SESSION_IS_INIT = -2147217012,
	ERR_NOTES_AGENT_SESSION = -2147217011,
	ERR_NOTES_INVALID_CREDENTIALS = -2147217010,
	ERR_NOTES_INVALID_LTPA = -2147217009,
	ERR_NOTES_CANT_GET_THAT = -2147217008,
	ERR_NOTES_ARRAY_MISMATCH = -2147217007,
	ERR_NOTES_RTCTX_POSITION_INVALID = -2147217006,
	ERR_NOTES_RTTABLE_APPENDFAILED = -2147217005,
	ERR_NOTES_RTTBL_MAXROWS = -2147217004,
	ERR_NOTES_RTTBL_MAXCOLS = -2147217003,
	ERR_NOTES_RTTBL_MINSIZE = -2147217002,
	ERR_NOTES_RTCTX_POSITION_UNDEF = -2147217001,
	ERR_NOTES_RTRNG_RESTRICTED_OPERATION = -2147217000,
	ERR_NOTES_RTEDIT_FAILED = -2147216999,
	ERR_NOTES_RTELEM_TYPEUNKNOWN = -2147216998,
	ERR_NOTES_RT_FIRSTFINISHINSERT = -2147216997,
	ERR_NOTES_METHODNOTAVAILABLE = -2147216996,
	ERR_NOTES_INVALID_VALUE = -2147216995,
	ERR_NOTES_DXLEXPORTER_INPUT_OBJECT = -2147216994,
	ERR_NOTES_DXLEXPORTER_OUTPUT_OBJECT = -2147216993,
	ERR_NOTES_ANADMINP_NOSUCH_CAORG = -2147216992,
	ERR_NOTES_ANADMINP_UNKNOWN = -2147216991,
	ERR_NOTES_RTNAV_INVALID_TYPE = -2147216990,
	ERR_NOTES_TIMEMERGE_FAILED = -2147216989,
	ERR_NOTES_GETFONT_FAILED = -2147216988,
	ERR_NOTES_DXLIMPORTER_INPUT_OBJECT = -2147216987,
	ERR_NOTES_DXLIMPORTER_OUTPUT_OBJECT = -2147216986,
	ERR_NOTES_XSLT_INPUT_OBJECT = -2147216985,
	ERR_NOTES_XSLT_OUTPUT_OBJECT = -2147216984,
	ERR_NOTES_XSLT_STYLESHEET_OBJECT = -2147216983,
	ERR_NOTES_DXLIMPORTER_FAILED = -2147216982,
	ERR_NOTES_DXLIMPORTER_INVALID_OPTION = -2147216981,
	ERR_NOTES_XML_PIPING = -2147216980,
	ERR_NOTES_RT_FIRSTFINISHSECTION = -2147216979,
	ERR_NOTES_DB_POLICYNOTFOUND = -2147216978,
	ERR_NOTES_DB_ARCHIVEINFO = -2147216977,
	ERR_NOTES_SS_ALREADYINUSE = -2147216976,
	ERR_NOTES_FILEREADONLY = -2147216975,
	ERR_NOTES_FILE_NONAME = -2147216974,
	ERR_NOTES_NOTBYTEARRAY = -2147216973,
	ERR_NOTES_NULLSTRING = -2147216972,
	ERR_NOTES_NOTHOTSPOTLINK = -2147216971,
	ERR_NOTES_BADTBLSTYLE = -2147216970,
	ERR_NOTES_ME_ILLEGALXNOTES = -2147216969,
	ERR_NOTES_NON_BODY_MIME = -2147216968,
	ERR_NOTES_NOSUCH_MAILSYSTEM = -2147216967,
	ERR_NOTES_NOSUCH_MAILOWNERACCESS = -2147216966,
	ERR_NOTES_NOSUCH_ROAMINGCLEANUPSETTING = -2147216965,
	ERR_NOTES_BADMAILFILEACTION = -2147216964,
	ERR_NOTES_SMSDEL_FAILED = -2147216963,
	ERR_NOTES_NOSUCH_GROUP = -2147216962,
	ERR_NOTES_SAXPARSER_INPUT_OBJECT = -2147216961,
	ERR_NOTES_SAXPARSER_OUTPUT_OBJECT = -2147216960,
	ERR_NOTES_DOMPARSER_INPUT_OBJECT = -2147216959,
	ERR_NOTES_DOMPARSER_OUTPUT_OBJECT = -2147216958,
	ERR_NOTES_SS_CHARSET_UNKNOWN = -2147216957,
	ERR_NOTES_ATTRIBUTE_NOT_FOUND = -2147216956,
	ERR_NOTES_INVALID_XML_OUTPUT_FORMAT = -2147216955,
	ERR_NOTES_OUTPUT_OBJECT_NOT_SET = -2147216954,
	ERR_NOTES_RTRNG_USESTANDARDNAV = -2147216953,
	ERR_NOTES_POLICY_DOC_FAILED = -2147216952,
	ERR_NOTES_RTNAV_MUSTBETYPETEXT = -2147216951,
	ERR_NOTES_RTNAV_NOOFFSETWITHAFTER = -2147216950,
	ERR_NOTES_NOT_HIER_MAIL_SERVERS = -2147216949,
	ERR_NOTES_SERVER_MUST_BE_R5 = -2147216948,
	ERR_NOTES_NO_CREATE_REPLICA = -2147216947,
	ERR_NOTES_BAD_REPLICA_LIST = -2147216946,
	ERR_NOTES_MAIL_NOMOVE_SAMEPATH = -2147216945,
	ERR_NOTES_NOSUCH_ROAMINGUSER = -2147216944,
	ERR_NOTES_NOT_HIERARCHICAL_SERVER = -2147216943,
	ERR_NOTES_NOT_IN_SAME_DOMAIN = -2147216942,
	ERR_NOTES_ROAMING_NOMOVE_SAMEPATH = -2147216941,
	ERR_NOTES_INVALID_APPROVAL_REQUEST = -2147216940,
	ERR_NOTES_PERSON_NOT_FOUND = -2147216939,
	ERR_NOTES_XMLREFORMATTER_INPUT_OBJECT = -2147216938,
	ERR_NOTES_XMLREFORMATTER_OUTPUT_OBJECT = -2147216937,
	ERR_NOTES_FIRST_ARG_NOT_DOMNODE = -2147216936,
	ERR_NOTES_SECOND_ARG_NOT_DOMNODE = -2147216935,
	ERR_NOTES_NULL_DOMNODE = -2147216934,
	ERR_NOTES_UNSUPPORTED_PLATFORM_OP = -2147216933,
	ERR_NOTES_FIRST_ARG_NOT_ATTR_NODE = -2147216932,
	ERR_NOTES_FIXUP_FAILED = -2147216931,
	ERR_NOTES_NOTLOCAL_FIXUP = -2147216930,
	ERR_NOTES_MUST_BE_NOTESDATETIME = -2147216929,
	ERR_NOTES_DOM_OPERATION = -2147216928,
	ERR_NOTES_CANTHASH = -2147216927,
	ERR_NOTES_UNABLETOLOCK = -2147216926,
	ERR_NOTES_CANTLOCK_NOTEMODIFIED = -2147216925,
	ERR_NOTES_CANTUNLOCK = -2147216924,
	ERR_NOTES_DATATOOBIG = -2147216923,
	ERR_NOTES_DATATYPETOOBIG = -2147216922,
	ERR_NOTES_DATATYPENOMATCH = -2147216921,
	ERR_NOTES_XMLREFORMATTER_CONNECTION = -2147216920,
	ERR_NOTES_XMLREFORMATTER_FAILED = -2147216919,
	ERR_NOTES_ACL_ADMINREADERAUTHOR_FAILED = -2147216918,
	ERR_NOTES_ACL_ADMINNAMES_FAILED = -2147216917,
	ERR_NOTES_ADMINSERVER_FAILED = -2147216916,
	ERR_NOTES_NOFIXEDSTRINGS = -2147216915,
	ERR_NOTES_INVALID_VARIANT_DATATYPE = -2147216914,
	ERR_NOTES_COMPACT_INVALID_OPTION = -2147216913,
	ERR_NOTES_COMPACT_UNSUPPORTED_OPTION = -2147216912,
	ERR_NOTES_BADPWDCHKSETTING = -2147216911,
	ERR_NOTES_CANT_SIGN_DATABASE = -2147216910,
	ERR_NOTES_LOCKED = -2147216909,
	ERR_NOTES_INVALID_NAMELIST = -2147216908,
	ERR_NOTES_CANTCONNECT_MASTERLOCKDB = -2147216907,
	ERR_NOTES_NOMASTERLOCKDB_DOC = -2147216906,
	ERR_NOTES_NOMASTERLOCKDB_DESIGN = -2147216905,
	ERR_NOTES_INVALID_VALIDATION_OPTION = -2147216904,
	ERR_NOTES_DXLEXPORTER_FAILED = -2147216903,
	ERR_NOTES_DOMPARSER_FAILED = -2147216902,
	ERR_NOTES_SAXPARSER_FAILED = -2147216901,
	ERR_NOTES_XSLTRANSFORMER_FAILED = -2147216900,
	ERR_NOTES_EXTENDEDINFO_FAILED = -2147216899,
	ERR_NOTES_NOTA_JBOOLEAN = -2147216898,
	ERR_NOTES_ADMINSERVER_EXISTS = -2147216897,
	ERR_NOTES_SSOTOKEN_GEN = -2147216896,
	ERR_NOTES_SSOTOKEN_AUTH = -2147216895,
	ERR_NOTES_SSOCONFIG = -2147216894,
	ERR_NOTES_SSOTOKEN_INV = -2147216893,
	ERR_NOTES_SSOTOKEN_EXP = -2147216892,
	ERR_NOTES_SERVERCONFIG = -2147216891,
	ERR_NOTES_COOKIE_BADADDR = -2147216890,
	ERR_NOTES_COOKIE_EXP = -2147216889,
	ERR_NOTES_COOKIE_INV = -2147216888,
	ERR_NOTES_PREVIEW_RESTRICTED = -2147216887,
	ERR_NOTES_INCOMPATIBLE_VERSION = -2147216886,
	ERR_NOTES_SS_ALIEN_THREAD_ACCESS = -2147216885,
	ERR_NOTES_SS_TEXTLINE_TOO_LONG = -2147216884,
	ERR_NOTES_SS_INCOMPATIBLE_CHARSETS = -2147216883,
	ERR_NOTES_INVALID_DBSIZE = -2147216882,
	ERR_NOTES_NOSUCH_DESIGN = -2147216881,
	ERR_NOTES_EMBED_IN_PROGRESS = -2147216880,
	ERR_NOTES_EMBED_NOT_STARTED = -2147216879,
	ERR_NOTES_INVALID_RESOLVER_RETVAL = -2147216878,
	ERR_NOTES_DB_MARKED_FOR_DELETE = -2147216877,
	ERR_NOTES_NOTE_NOT_IN_DATABASE = -2147216876,
	ERR_NOTES_CANNOT_SERIALIZE_DOM_TREE = -2147216875,
	ERR_NOTES_NO_CLUSTER_DB = -2147216874,
	ERR_NOTES_NEGATIVE_VALUE = -2147216873,
	ERR_NOTES_USER_NO_SERVER = -2147216872,
	ERR_NOTES_DELETE_NET_USER_FALIED = -2147216871,
	ERR_NOTES_NULL_SERVER_NAME = -2147216870,
	ERR_NOTES_INVALID_VIEW_TEMPLATE = -2147216869,
	ERR_NOTES_ILLEGAL_SERVER_NAME = -2147216868,
	ERR_NOTES_NOT_A_DATE_ITEM = -2147216867,
	ERR_NOTES_RTTBL_BADCOLWIDTH = -2147216866,
	ERR_NOTES_INVALID_RECEIVEDITEM = -2147216865,
	ERR_NOTES_NOTA_JINTEGER = -2147216864,
	ERR_NOTES_DOMOP_INDEX_SIZE = -2147216863,
	ERR_NOTES_DOMOP_XMLSTRING_SIZE = -2147216862,
	ERR_NOTES_DOMOP_HIERARCHY_REQUEST = -2147216861,
	ERR_NOTES_DOMOP_WRONG_DOCUMENT = -2147216860,
	ERR_NOTES_DOMOP_INVALID_CHARACTER = -2147216859,
	ERR_NOTES_DOMOP_NO_DATA_ALLOWED = -2147216858,
	ERR_NOTES_DOMOP_NO_MODIFY_ALLOWED = -2147216857,
	ERR_NOTES_DOMOP_NOT_FOUND = -2147216856,
	ERR_NOTES_DOMOP_NOT_SUPPORTED = -2147216855,
	ERR_NOTES_DOMOP_INUSE_ATTRIBUTE = -2147216854,
	ERR_NOTES_DOMOP_INVALID_STATE = -2147216853,
	ERR_NOTES_DOMOP_SYNTAX = -2147216852,
	ERR_NOTES_DOMOP_INVALID_MODIFICATION = -2147216851,
	ERR_NOTES_DOMOP_NAMESPACE = -2147216850,
	ERR_NOTES_DOMOP_INVALID_ACCESS = -2147216849,
	ERR_NOTES_NOSUCH_DBSIGN = -2147216848,
	ERR_NOTES_FORMEDIT_FAILED = -2147216847,
	ERR_NOTES_ME_DUPLICATEXNOTES_NAME = -2147216846,
	ERR_NOTES_ME_MISSINGXNOTES_NAME = -2147216845,
	ERR_NOTES_NO_OLECONTEXT = -2147216844,
	ERR_NOTES_CANTSIGN_BYNAME = -2147216843,
	ERR_NOTES_ADMINSERVER_NEXIST = -2147216842,
	ERR_NOTES_COMPACT_I_REQ_C = -2147216841,
	ERR_NOTES_UNDELETENONPOSITIVEVALUE = -2147216840,
	ERR_NOTES_XML_PROCESS_ERROR = -2147216839,
	ERR_NOTES_XML_PIPELINE_LOOP_ERROR = -2147216838,
	ERR_NOTES_STREAM_HAS_BEEN_USED = -2147216837,
	ERR_NOTES_STREAM_HAS_MIXED_CONTENT = -2147216836,
	ERR_NOTES_XML_PROCESSOR_CANNOT_BE_USED = -2147216835,
	ERR_NOTES_DB_BADINDEXFREQUENCY = -2147216832,
	ERR_NOTES_LONG_OVERFLOW = -2147216831,
	ERR_NOTES_INVALID_CREDEL_TEMPLATE = -2147216830,
	ERR_NOTES_BADPLCYSETSTYPE = -2147216829,
	ERR_NOTES_CANTRETNOTEID = -2147216827,
	ERR_NOTES_STALE_COLLECTION = -2147216826,
	ERR_NOTES_EXTENDEDACCESS_FAILED = -2147216825,
	ERR_NOTES_UNIFORM_FAILED_EA = -2147216824,
	ERR_NOTES_NOTEIDFIND_FAILED = -2147216823,
	ERR_NOTES_NOFIXUP_CURRDB = -2147216822,
	ERR_NOTES_NOT_AN_URLDB = -2147216821,
	ERR_NOTES_RTNAV_USE_FINDSTRING = -2147216820,
	ERR_NOTES_UNINITIALIZED_STRUCT = -2147216819,
	ERR_NOTES_UNINITIALIZED_REMOTE_OBJ = -2147216818,
	ERR_NOTES_NEVER_SUPPORTED = -2147216817,
	ERR_NOTES_SS_TRUNCATION_FAILED = -2147216816,
	ERR_NOTES_NEED_STREAM = -2147216815,
	ERR_NOTES_SS_IO_FAILED = -2147216814,
	ERR_NOTES_NO_MEMBERS_REFRESHED = -2147216813,
	ERR_NOTES_SS_NO_LOCAL_STREAM_REPLACE = -2147216812,
	ERR_NOTES_SS_NO_LOCAL_STREAM_CLOSE = -2147216811,
	ERR_NOTES_SS_NO_LOCAL_STREAM_OPEN = -2147216810,
	ERR_NOTES_SS_MAX_SPACE_EXCEEDED = -2147216809,
	ERR_NOTES_DOCUMENTCOLLECTION_MISSING = -2147216808,
	ERR_NOTES_NOTECOLLECTION_MISSING = -2147216807,
	ERR_NOTES_NOSUCH_DBGETMODDOCS = -2147216806,
	ERR_NOTES_BEP_CLASS = -2147216805,
	ERR_NOTES_BEP_METHOD = -2147216804,
	ERR_NOTES_BEP_OPERATION = -2147216803,
	ERR_NOTES_BEP_CALLS = -2147216802,
	ERR_NOTES_BEP_TIME = -2147216801,
	ERR_NOTES_BEP_MEASUREDTIME = -2147216800,
	ERR_NOTES_BEP_METHODSPROFILED = -2147216799,
	ERR_NOTES_BEP_MILLISECONDS = -2147216798,
	ERR_NOTES_BEP_AGENTEXECUTIONTIME = -2147216797,
	ERR_NOTES_BEP_PROFILE = -2147216796,
	ERR_NOTES_AP_CFA_NOADMSRV = -2147216795,
	ERR_NOTES_MAX_THREADSESSIONS = -2147216794,
	ERR_NOTES_TOOMANY_IN_DIR = -2147216793,
	ERR_NOTES_BUSYTIME_FAILED = -2147216792,
	ERR_NOTES_UNREAD_USERNAME = -2147216791,
	ERR_NOTES_UNREAD_READ = -2147216790,
	ERR_NOTES_UNREAD_WRITE = -2147216789,
	ERR_NOTES_DEFAULTVIEW = -2147216788,
	ERR_NOTES_NOSINGLES = -2147216787
}
