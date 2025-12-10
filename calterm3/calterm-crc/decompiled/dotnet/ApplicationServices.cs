using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.Versioning;
using System.Windows.Forms;
using Cummins.Services;

[assembly: AssemblyDelaySign(false)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - ApplicationServices")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2011")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc. 2011")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.ApplicationServices;

public class ApplicationInfo
{
	private static Form _mainApplicationForm;

	public static Form MainApplicationForm
	{
		get
		{
			return _mainApplicationForm;
		}
		set
		{
			_mainApplicationForm = value;
		}
	}
}
public interface IPropertyPageProvider
{
	ArrayList Pages { get; }
}
public interface IPropertyPage
{
	string ParentNode { get; set; }

	string CurrentNode { get; set; }

	void Initialize();

	void SetOptions();
}
public class Command
{
	public delegate void UpdateHandler(Command cmd);

	public delegate void ExecuteHandler(Command cmd);

	public class CommandInstanceList : CollectionBase
	{
		private Command command;

		public object this[int index] => base.List[index];

		internal CommandInstanceList(Command acmd)
		{
			command = acmd;
		}

		public void Add(object instance)
		{
			base.List.Add(instance);
		}

		public void Add(object[] items)
		{
			foreach (object instance in items)
			{
				Add(instance);
			}
		}

		public void Remove(object instance)
		{
			base.List.Remove(instance);
		}

		protected override void OnInsertComplete(int index, object value)
		{
			command.Manager.GetCommandExecutor(value).InstanceAdded(value, command);
		}
	}

	private CommandInstanceList commandInstances;

	private CommandManager manager;

	private string strTag;

	protected bool enabled;

	protected bool check;

	protected bool visibled;

	private string strCaption;

	public CommandInstanceList CommandInstances => commandInstances;

	public string Tag => strTag;

	internal CommandManager Manager
	{
		get
		{
			return manager;
		}
		set
		{
			manager = value;
		}
	}

	public string Caption
	{
		set
		{
			strCaption = value;
			foreach (object commandInstance in commandInstances)
			{
				Manager.GetCommandExecutor(commandInstance).Caption(commandInstance, strCaption);
			}
		}
	}

	public bool Enabled
	{
		get
		{
			return enabled;
		}
		set
		{
			enabled = value;
			foreach (object commandInstance in commandInstances)
			{
				Manager.GetCommandExecutor(commandInstance).Enable(commandInstance, enabled);
			}
		}
	}

	public bool Visibled
	{
		get
		{
			return visibled;
		}
		set
		{
			visibled = value;
			foreach (object commandInstance in commandInstances)
			{
				Manager.GetCommandExecutor(commandInstance).Visible(commandInstance, visibled);
			}
		}
	}

	public bool Checked
	{
		get
		{
			return check;
		}
		set
		{
			check = value;
			foreach (object commandInstance in commandInstances)
			{
				Manager.GetCommandExecutor(commandInstance).Check(commandInstance, check);
			}
		}
	}

	public event UpdateHandler OnUpdate;

	public event ExecuteHandler OnExecute;

	public Command(string strTag, ExecuteHandler handlerExecute, UpdateHandler handlerUpdate)
	{
		commandInstances = new CommandInstanceList(this);
		this.strTag = strTag;
		OnUpdate += handlerUpdate;
		OnExecute += handlerExecute;
	}

	public override string ToString()
	{
		return Tag;
	}

	public void Execute()
	{
		if (this.OnExecute != null)
		{
			this.OnExecute(this);
		}
	}

	internal void ProcessUpdates()
	{
		if (this.OnUpdate != null)
		{
			this.OnUpdate(this);
		}
	}
}
public abstract class CommandExecutor
{
	protected Hashtable hashInstances = new Hashtable(60);

	public virtual void InstanceAdded(object item, Command cmd)
	{
		hashInstances.Add(item, cmd);
	}

	protected Command GetCommandForInstance(object item)
	{
		return hashInstances[item] as Command;
	}

	public abstract void Enable(object item, bool bEnable);

	public abstract void Check(object item, bool bCheck);

	public abstract void Visible(object item, bool bVisible);

	public abstract void Caption(object item, string menuCaption);
}
public class MenuCommandExecutor : CommandExecutor
{
	private IActivityLogService _activityLogService;

	private IActivityLogService ActivityLog
	{
		get
		{
			if (_activityLogService == null)
			{
				_activityLogService = ServiceManager.Services.GetService(typeof(IActivityLogService)) as IActivityLogService;
			}
			return _activityLogService;
		}
	}

	public override void InstanceAdded(object item, Command cmd)
	{
		//IL_000f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0015: Expected O, but got Unknown
		if (!hashInstances.Contains(item))
		{
			MenuItem val = (MenuItem)item;
			val.Click += menuItem_Click;
			base.InstanceAdded(item, cmd);
		}
	}

	public override void Enable(object item, bool bEnable)
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_0007: Expected O, but got Unknown
		MenuItem val = (MenuItem)item;
		val.Enabled = bEnable;
	}

	public override void Visible(object item, bool bVisible)
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_0007: Expected O, but got Unknown
		MenuItem val = (MenuItem)item;
		val.Visible = bVisible;
	}

	public override void Check(object item, bool bCheck)
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_0007: Expected O, but got Unknown
		MenuItem val = (MenuItem)item;
		val.Checked = bCheck;
	}

	public override void Caption(object item, string Caption)
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_0007: Expected O, but got Unknown
		MenuItem val = (MenuItem)item;
		val.Text = Caption;
	}

	private void menuItem_Click(object sender, EventArgs e)
	{
		Command commandForInstance = GetCommandForInstance(sender);
		if (ActivityLog.Enabled)
		{
			WriteLogEntry(commandForInstance.Tag);
		}
		commandForInstance.Execute();
	}

	private void WriteLogEntry(string item)
	{
		Dictionary<ELogEntryField, string> dictionary = new Dictionary<ELogEntryField, string>();
		dictionary.Add(ELogEntryField._FEATURE_NAME, "Menu Pick");
		dictionary.Add(ELogEntryField._FEATURE_DETAILS, item);
		ActivityLog.WriteLogEntry(dictionary);
	}
}
public class CaltermMenuCommandExecutor : CommandExecutor
{
	public override void InstanceAdded(object item, Command cmd)
	{
		//IL_000f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0015: Expected O, but got Unknown
		if (!hashInstances.Contains(item))
		{
			MenuItem val = (MenuItem)item;
			val.Click += menuItem_Click;
			base.InstanceAdded(item, cmd);
		}
	}

	public override void Enable(object item, bool bEnable)
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_0007: Expected O, but got Unknown
		MenuItem val = (MenuItem)item;
		val.Enabled = bEnable;
	}

	public override void Visible(object item, bool bVisible)
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_0007: Expected O, but got Unknown
		MenuItem val = (MenuItem)item;
		val.Visible = bVisible;
	}

	public override void Check(object item, bool bCheck)
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_0007: Expected O, but got Unknown
		MenuItem val = (MenuItem)item;
		val.Checked = bCheck;
	}

	public override void Caption(object item, string Caption)
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_0007: Expected O, but got Unknown
		MenuItem val = (MenuItem)item;
		val.Text = Caption;
	}

	private void menuItem_Click(object sender, EventArgs e)
	{
		Command commandForInstance = GetCommandForInstance(sender);
		commandForInstance.Execute();
	}
}
public class ToolbarCommandExecutor : CommandExecutor
{
	public override void InstanceAdded(object item, Command cmd)
	{
		//IL_000f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0015: Expected O, but got Unknown
		//IL_001c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0022: Expected O, but got Unknown
		if (!hashInstances.Contains(item))
		{
			ToolBarButton val = (ToolBarButton)item;
			ToolBarButtonClickEventHandler val2 = new ToolBarButtonClickEventHandler(toolbar_ButtonClick);
			val.Parent.ButtonClick -= val2;
			val.Parent.ButtonClick += val2;
			base.InstanceAdded(item, cmd);
		}
	}

	public override void Enable(object item, bool bEnable)
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_0007: Expected O, but got Unknown
		ToolBarButton val = (ToolBarButton)item;
		val.Enabled = bEnable;
	}

	public override void Visible(object item, bool bVisible)
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_0007: Expected O, but got Unknown
		ToolBarButton val = (ToolBarButton)item;
		val.Visible = bVisible;
	}

	public override void Check(object item, bool bCheck)
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_0007: Expected O, but got Unknown
		ToolBarButton val = (ToolBarButton)item;
		val.Style = (ToolBarButtonStyle)2;
		val.Pushed = bCheck;
	}

	public override void Caption(object item, string Caption)
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_0007: Expected O, but got Unknown
		ToolBarButton val = (ToolBarButton)item;
		val.Text = Caption;
	}

	private void toolbar_ButtonClick(object sender, ToolBarButtonClickEventArgs args)
	{
		Command commandForInstance = GetCommandForInstance(args.Button);
		commandForInstance.Execute();
	}
}
public class CommandManager : Component
{
	public class CommandsList : ICollection, IEnumerable
	{
		private Hashtable hashTable;

		private CommandManager cmdmgr;

		internal CommandManager Manager
		{
			get
			{
				return cmdmgr;
			}
			set
			{
				cmdmgr = value;
			}
		}

		public object SyncRoot => hashTable.SyncRoot;

		public bool IsSynchronized => hashTable.IsSynchronized;

		public int Count => hashTable.Count;

		public Command this[string cmdTag] => hashTable[cmdTag] as Command;

		internal CommandsList(CommandManager amgr)
		{
			cmdmgr = amgr;
			hashTable = new Hashtable(60);
		}

		public void CopyTo(Array array, int index)
		{
			hashTable.CopyTo(array, index);
		}

		public IEnumerator GetEnumerator()
		{
			return hashTable.GetEnumerator();
		}

		public void Add(Command command)
		{
			command.Manager = Manager;
			hashTable.Add(command.ToString(), command);
		}

		public void Remove(string cmdTag)
		{
			hashTable.Remove(cmdTag);
		}

		public bool Contains(string cmdTag)
		{
			return hashTable.Contains(cmdTag);
		}
	}

	private CommandsList commands;

	private Hashtable hashCommandExecutors;

	public CommandsList Commands => commands;

	public CommandManager()
	{
		commands = new CommandsList(this);
		hashCommandExecutors = new Hashtable();
		Application.Idle += OnIdle;
		hashCommandExecutors.Add("System.Windows.Forms.MenuItem", new MenuCommandExecutor());
		hashCommandExecutors.Add("System.Windows.Forms.ToolBarButton", new ToolbarCommandExecutor());
	}

	internal void RegisterCommandExecutor(string strType, CommandExecutor executor)
	{
		hashCommandExecutors.Add(strType, executor);
	}

	internal CommandExecutor GetCommandExecutor(object instance)
	{
		return hashCommandExecutors[instance.GetType().ToString()] as CommandExecutor;
	}

	private void OnIdle(object sender, EventArgs args)
	{
		IDictionaryEnumerator dictionaryEnumerator = (IDictionaryEnumerator)commands.GetEnumerator();
		while (dictionaryEnumerator.MoveNext())
		{
			if (dictionaryEnumerator.Value is Command command)
			{
				command.ProcessUpdates();
			}
		}
	}
}
public enum SelectableFeatures
{
	Unlock,
	ToggleSecurityKey,
	ChangeRunLocation,
	CalibrationEditor,
	ModuleEditor,
	HexEditor,
	SaveFileCalibration,
	SaveModuleCalibration,
	BlockUnBlockFaults,
	Download,
	SecureDownload,
	Export,
	Overlay,
	Assemble,
	Divide,
	CRCFiles,
	SPEEDDownload,
	SPEEDUpload,
	SendOperation,
	TVOTVC,
	StopEngine,
	SubfileTableEdit
}
