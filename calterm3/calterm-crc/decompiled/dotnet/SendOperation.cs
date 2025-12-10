using System;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.Versioning;
using System.Threading;
using System.Windows.Forms;
using Cummins.AddressRepresentation;
using Cummins.Calibration;
using Cummins.EventLog;
using Cummins.MessageDialog;
using Cummins.Module;
using Cummins.Services;
using Cummins.Widgets;

[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyProduct("Calterm III - SendOperation")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyTitle("Poodle")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc., 2017")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyVersion("3.17.0.0")]
namespace Cummins.SendOperation;

public class CommandFactory
{
	private CommandModel commandModel;

	private CommandView operationEditView;

	public CommandModel CommandModel => commandModel;

	public CommandView CommandView => operationEditView;

	public CommandFactory(InstructionLayerCommandType commandType, ICLIPService clipService)
	{
		switch (commandType)
		{
		case InstructionLayerCommandType.ExecuteOperation:
			operationEditView = new ExecuteOperationView((ExecuteOperation)(commandModel = new ExecuteOperation(clipService)));
			break;
		case InstructionLayerCommandType.GetAddressByParameterID:
			operationEditView = new GetAddressByParameterIDView((GetAddressByParameterID)(commandModel = new GetAddressByParameterID(clipService)));
			break;
		case InstructionLayerCommandType.GetDataByAddress:
			operationEditView = new GetDataByAddressView((GetDataByAddress)(commandModel = new GetDataByAddress(clipService)));
			break;
		case InstructionLayerCommandType.GetParameterByID:
			operationEditView = new GetParameteByIDView((GetParametersByID)(commandModel = new GetParametersByID(clipService)));
			break;
		case InstructionLayerCommandType.SetDataByAddress:
			operationEditView = new SetDataByAddressView((SetDataByAddress)(commandModel = new SetDataByAddress(clipService)));
			break;
		case InstructionLayerCommandType.SetParameterByID:
			operationEditView = new SetParameterByIDView((SetParametersByID)(commandModel = new SetParametersByID(clipService)));
			break;
		default:
			commandModel = null;
			operationEditView = null;
			throw new CommandTypeNotSupportedException(SendOperationMessageId.CommandTypeNotSupported, "Command Not Supported");
		}
	}
}
public abstract class CommandModel
{
	protected internal ICLIPService clipService;

	protected internal ExecutionResult receivedData;

	protected internal string sentData;

	public ExecutionResult ReceivedData => receivedData;

	public string SendData => sentData;

	public ICalibrationECM CalibrationECM
	{
		get
		{
			return clipService.CalibrationECM;
		}
		set
		{
			clipService.CalibrationECM = value;
		}
	}

	protected CommandModel(ICLIPService clipService)
	{
		this.clipService = clipService;
	}

	public abstract void Execute();
}
public class ExecuteOperation : CommandModel
{
	private int instruction;

	private byte[] arguments;

	public int Instruction
	{
		get
		{
			return instruction;
		}
		set
		{
			instruction = value;
		}
	}

	public byte[] Arguments
	{
		get
		{
			if (arguments == null)
			{
				arguments = new byte[0];
			}
			return arguments;
		}
		set
		{
			arguments = value;
		}
	}

	public ExecuteOperation(ICLIPService clipService)
		: base(clipService)
	{
	}

	public override void Execute()
	{
		sentData = Instruction.ToString("X4") + " ";
		for (int i = 0; i < Arguments.Length; i++)
		{
			sentData = sentData + Arguments[i].ToString("X2") + " ";
		}
		receivedData = clipService.ExecuteOperation(Instruction, Arguments);
	}
}
public class GetAddressByParameterID : CommandModel
{
	private int parameterID;

	public int ParameterID
	{
		get
		{
			return parameterID;
		}
		set
		{
			parameterID = value;
		}
	}

	public GetAddressByParameterID(ICLIPService clipService)
		: base(clipService)
	{
	}

	public override void Execute()
	{
		sentData = ParameterID.ToString("X8");
		receivedData = clipService.GetAddressByParameterID(ParameterID);
	}
}
public class GetDataByAddress : CommandModel
{
	private int address;

	private short length;

	public int Address
	{
		get
		{
			return address;
		}
		set
		{
			address = value;
		}
	}

	public short Length
	{
		get
		{
			return length;
		}
		set
		{
			length = value;
		}
	}

	public GetDataByAddress(ICLIPService clipService)
		: base(clipService)
	{
	}

	public override void Execute()
	{
		sentData = Address.ToString("X8") + " " + Length.ToString("X4");
		receivedData = clipService.GetDataByAddress(Address, Length);
	}
}
public class GetParametersByID : CommandModel
{
	private int[] parameterID;

	public int[] ParameterID
	{
		get
		{
			if (parameterID == null)
			{
				parameterID = new int[1];
				parameterID[0] = 0;
			}
			return parameterID;
		}
		set
		{
			parameterID = value;
		}
	}

	public GetParametersByID(ICLIPService clipService)
		: base(clipService)
	{
	}

	public override void Execute()
	{
		sentData = "";
		for (int i = 0; i < ParameterID.Length; i++)
		{
			sentData = sentData + ParameterID[i].ToString("X8") + " ";
		}
		receivedData = clipService.GetParametersByID(ParameterID);
	}
}
public class SetDataByAddress : CommandModel
{
	private int address;

	private short length;

	private byte[] data;

	public int Address
	{
		get
		{
			return address;
		}
		set
		{
			address = value;
		}
	}

	public short Length
	{
		get
		{
			return length;
		}
		set
		{
			length = value;
		}
	}

	public byte[] Data
	{
		get
		{
			if (data == null)
			{
				data = new byte[1];
				data[0] = 0;
			}
			return data;
		}
		set
		{
			data = value;
		}
	}

	public SetDataByAddress(ICLIPService clipService)
		: base(clipService)
	{
	}

	public override void Execute()
	{
		sentData = Address.ToString("X8") + " " + Length.ToString("X4") + " ";
		for (int i = 0; i < Data.Length; i++)
		{
			sentData = sentData + Data[i].ToString("X2") + " ";
		}
		receivedData = clipService.SetDataByAddress(Address, Length, Data);
	}
}
public class SetParametersByID : CommandModel
{
	private int[] parameterID;

	private byte[] data;

	public int[] ParameterID
	{
		get
		{
			if (parameterID == null)
			{
				parameterID = new int[1];
				parameterID[0] = 0;
			}
			return parameterID;
		}
		set
		{
			parameterID = value;
		}
	}

	public byte[] Data
	{
		get
		{
			if (data == null)
			{
				data = new byte[1];
				data[0] = 0;
			}
			return data;
		}
		set
		{
			data = value;
		}
	}

	public SetParametersByID(ICLIPService clipService)
		: base(clipService)
	{
	}

	public override void Execute()
	{
		sentData = "";
		for (int i = 0; i < ParameterID.Length; i++)
		{
			sentData = sentData + ParameterID[i].ToString("X8") + " ";
		}
		for (int j = 0; j < Data.Length; j++)
		{
			sentData = sentData + Data[j].ToString("X2") + " ";
		}
		receivedData = clipService.SetParametersByID(ParameterID, Data);
	}
}
public class CommandView : UserControl
{
	private Container components;

	protected CommandModel commandModel;

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		((ContainerControl)this).Dispose(disposing);
	}

	private void InitializeComponent()
	{
		((Control)this).Name = "OperationEditPane";
		((Control)this).Size = new Size(456, 64);
	}

	public CommandView()
	{
		InitializeComponent();
	}

	public CommandView(CommandModel commandModel)
	{
		InitializeComponent();
		this.commandModel = commandModel;
	}
}
public enum SendOperationMessageId
{
	ModuleIsNotConnected,
	CommandTypeNotSupported
}
public class SendOperationException : BaseException
{
	public SendOperationException()
		: base(Facility.SendOperation, 0)
	{
	}

	public SendOperationException(SendOperationMessageId errorID, string message)
		: base(Facility.SendOperation, (short)errorID, message)
	{
	}

	public SendOperationException(SendOperationMessageId errorID, string message, Exception inner)
		: base(Facility.SendOperation, (short)errorID, message, inner)
	{
	}
}
public class CalibrationECMException : SendOperationException
{
	public CalibrationECMException()
	{
	}

	public CalibrationECMException(SendOperationMessageId errorID, string message)
		: base(errorID, message)
	{
	}

	public CalibrationECMException(SendOperationMessageId errorID, string message, Exception inner)
		: base(errorID, message, inner)
	{
	}
}
public class CommandTypeNotSupportedException : SendOperationException
{
	public CommandTypeNotSupportedException()
	{
	}

	public CommandTypeNotSupportedException(SendOperationMessageId errorID, string message)
		: base(errorID, message)
	{
	}

	public CommandTypeNotSupportedException(SendOperationMessageId errorID, string message, Exception inner)
		: base(errorID, message, inner)
	{
	}
}
public class ExecuteOperationView : CommandView
{
	private HexTextBox argumentHexTextBox;

	private HexTextBox operationIDHexTextBox;

	private Label labelOperationID;

	private Label labelArguments;

	private IContainer components;

	private ExecuteOperation executeOperation;

	public ExecuteOperationView(ExecuteOperation executeOperation)
		: base(executeOperation)
	{
		InitializeComponent();
		this.executeOperation = executeOperation;
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		base.Dispose(disposing);
	}

	private void InitializeComponent()
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_000b: Expected O, but got Unknown
		//IL_000c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0016: Expected O, but got Unknown
		labelOperationID = new Label();
		labelArguments = new Label();
		operationIDHexTextBox = new HexTextBox();
		argumentHexTextBox = new HexTextBox();
		((Control)this).SuspendLayout();
		((Control)labelOperationID).Location = new Point(17, 8);
		((Control)labelOperationID).Name = "labelOperationID";
		((Control)labelOperationID).Size = new Size(70, 14);
		((Control)labelOperationID).TabIndex = 0;
		((Control)labelOperationID).Text = "OperationID";
		((Control)labelArguments).Location = new Point(142, 8);
		((Control)labelArguments).Name = "labelArguments";
		((Control)labelArguments).Size = new Size(70, 14);
		((Control)labelArguments).TabIndex = 5;
		((Control)labelArguments).Text = "Arguments";
		((Control)operationIDHexTextBox).Location = new Point(16, 32);
		((Control)operationIDHexTextBox).Name = "operationIDHexTextBox";
		((Control)operationIDHexTextBox).TabIndex = 2;
		((Control)operationIDHexTextBox).Text = "";
		((Control)operationIDHexTextBox).TextChanged += operationIDHexTextBox_TextChanged;
		((Control)argumentHexTextBox).AccessibleRole = (AccessibleRole)0;
		((Control)argumentHexTextBox).Anchor = (AnchorStyles)15;
		((Control)argumentHexTextBox).Location = new Point(136, 32);
		((Control)argumentHexTextBox).Name = "argumentHexTextBox";
		((Control)argumentHexTextBox).Size = new Size(280, 20);
		((Control)argumentHexTextBox).TabIndex = 3;
		((Control)argumentHexTextBox).Text = "";
		((Control)argumentHexTextBox).TextChanged += argumentHexTextBox_TextChanged;
		((Control)this).Controls.Add((Control)(object)argumentHexTextBox);
		((Control)this).Controls.Add((Control)(object)operationIDHexTextBox);
		((Control)this).Controls.Add((Control)(object)labelArguments);
		((Control)this).Controls.Add((Control)(object)labelOperationID);
		((Control)this).Name = "ExecuteOperationView";
		((Control)this).ResumeLayout(false);
	}

	private void operationIDHexTextBox_TextChanged(object sender, EventArgs e)
	{
		try
		{
			if (((Control)operationIDHexTextBox).Text.Length != 0)
			{
				executeOperation.Instruction = int.Parse(((Control)operationIDHexTextBox).Text, NumberStyles.HexNumber);
			}
			else
			{
				executeOperation.Instruction = 0;
			}
		}
		catch
		{
			executeOperation.Instruction = 0;
		}
	}

	private void argumentHexTextBox_TextChanged(object sender, EventArgs e)
	{
		char[] separator = new char[2] { ' ', ',' };
		try
		{
			byte[] array2;
			if (((Control)argumentHexTextBox).Text.Length != 0)
			{
				string[] array = ((Control)argumentHexTextBox).Text.Split(separator);
				array2 = new byte[array.Length];
				for (int i = 0; i < array.Length; i++)
				{
					array2[i] = byte.Parse(array[i], NumberStyles.HexNumber);
				}
			}
			else
			{
				array2 = new byte[0];
			}
			executeOperation.Arguments = array2;
		}
		catch
		{
			byte[] array2 = new byte[0];
			executeOperation.Arguments = array2;
		}
	}

	protected override bool ProcessCmdKey(ref Message m, Keys keyData)
	{
		//IL_0004: Unknown result type (might be due to invalid IL or missing references)
		//IL_0005: Invalid comparison between I4 and Unknown
		//IL_003d: Unknown result type (might be due to invalid IL or missing references)
		bool flag = false;
		if (9 == (int)keyData && ((ContainerControl)this).ActiveControl != null)
		{
			if (((Control)operationIDHexTextBox).Focused)
			{
				((Control)argumentHexTextBox).Focus();
				flag = true;
			}
			else
			{
				((ContainerControl)this).ParentForm.TabStop = true;
			}
		}
		if (!flag)
		{
			flag = ((ContainerControl)this).ProcessCmdKey(ref m, keyData);
		}
		return flag;
	}
}
public class GetAddressByParameterIDView : CommandView
{
	private IContainer components;

	private HexTextBox parameterIDHexTextBox;

	private Label labelParameterIDs;

	private GetAddressByParameterID getAddressByParameterID;

	public GetAddressByParameterIDView(GetAddressByParameterID getAddressByParameterID)
	{
		InitializeComponent();
		this.getAddressByParameterID = getAddressByParameterID;
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		base.Dispose(disposing);
	}

	private void InitializeComponent()
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_000b: Expected O, but got Unknown
		labelParameterIDs = new Label();
		parameterIDHexTextBox = new HexTextBox();
		((Control)this).SuspendLayout();
		((Control)labelParameterIDs).Location = new Point(17, 8);
		((Control)labelParameterIDs).Name = "labelParameterIDs";
		((Control)labelParameterIDs).Size = new Size(100, 14);
		((Control)labelParameterIDs).TabIndex = 0;
		((Control)labelParameterIDs).Text = "Parameter IDs";
		((Control)parameterIDHexTextBox).Anchor = (AnchorStyles)15;
		((Control)parameterIDHexTextBox).Location = new Point(16, 32);
		((Control)parameterIDHexTextBox).Name = "parameterIDHexTextBox";
		((Control)parameterIDHexTextBox).Size = new Size(416, 20);
		((Control)parameterIDHexTextBox).TabIndex = 2;
		((Control)parameterIDHexTextBox).Text = "";
		((Control)parameterIDHexTextBox).TextChanged += parameterIDHexTextBox_TextChanged;
		((Control)this).Controls.Add((Control)(object)parameterIDHexTextBox);
		((Control)this).Controls.Add((Control)(object)labelParameterIDs);
		((Control)this).Name = "GetAddressByParameterIDView";
		((Control)this).ResumeLayout(false);
	}

	private void parameterIDHexTextBox_TextChanged(object sender, EventArgs e)
	{
		try
		{
			if (((Control)parameterIDHexTextBox).Text.Length != 0)
			{
				getAddressByParameterID.ParameterID = int.Parse(((Control)parameterIDHexTextBox).Text, NumberStyles.HexNumber);
			}
			else
			{
				getAddressByParameterID.ParameterID = 0;
			}
		}
		catch
		{
			getAddressByParameterID.ParameterID = 0;
		}
	}
}
public class GetDataByAddressView : CommandView
{
	private IContainer components;

	private HexTextBox addressHexTextBox;

	private HexTextBox lengthHexTextBox;

	private Label labelAddress;

	private Label labelLength;

	private GetDataByAddress getDataByAddress;

	public GetDataByAddressView(GetDataByAddress getDataByAddress)
	{
		InitializeComponent();
		this.getDataByAddress = getDataByAddress;
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		base.Dispose(disposing);
	}

	private void InitializeComponent()
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_000b: Expected O, but got Unknown
		//IL_000c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0016: Expected O, but got Unknown
		labelAddress = new Label();
		labelLength = new Label();
		addressHexTextBox = new HexTextBox();
		lengthHexTextBox = new HexTextBox();
		((Control)this).SuspendLayout();
		((Control)labelAddress).Location = new Point(16, 8);
		((Control)labelAddress).Name = "labelAddress";
		((Control)labelAddress).Size = new Size(40, 14);
		((Control)labelAddress).TabIndex = 0;
		((Control)labelAddress).Text = "Address";
		((Control)labelLength).Location = new Point(144, 8);
		((Control)labelLength).Name = "labelLength";
		((Control)labelLength).Size = new Size(40, 14);
		((Control)labelLength).TabIndex = 2;
		((Control)labelLength).Text = "Length";
		((Control)addressHexTextBox).Location = new Point(16, 32);
		((Control)addressHexTextBox).Name = "addressHexTextBox";
		((Control)addressHexTextBox).TabIndex = 3;
		((Control)addressHexTextBox).Text = "";
		((Control)addressHexTextBox).TextChanged += addressHexTextBox_TextChanged;
		((Control)lengthHexTextBox).Anchor = (AnchorStyles)15;
		((Control)lengthHexTextBox).Location = new Point(144, 32);
		((Control)lengthHexTextBox).Name = "lengthHexTextBox";
		((Control)lengthHexTextBox).Size = new Size(280, 20);
		((Control)lengthHexTextBox).TabIndex = 4;
		((Control)lengthHexTextBox).Text = "";
		((Control)lengthHexTextBox).TextChanged += lengthHexTextBox_TextChanged;
		((Control)this).Controls.Add((Control)(object)lengthHexTextBox);
		((Control)this).Controls.Add((Control)(object)addressHexTextBox);
		((Control)this).Controls.Add((Control)(object)labelLength);
		((Control)this).Controls.Add((Control)(object)labelAddress);
		((Control)this).Name = "GetDataByAddressView";
		((Control)this).ResumeLayout(false);
	}

	private void addressHexTextBox_TextChanged(object sender, EventArgs e)
	{
		try
		{
			if (((Control)addressHexTextBox).Text.Length != 0)
			{
				getDataByAddress.Address = int.Parse(((Control)addressHexTextBox).Text, NumberStyles.HexNumber);
			}
			else
			{
				getDataByAddress.Address = 0;
			}
		}
		catch
		{
			getDataByAddress.Address = 0;
		}
	}

	private void lengthHexTextBox_TextChanged(object sender, EventArgs e)
	{
		try
		{
			if (((Control)lengthHexTextBox).Text.Length != 0)
			{
				getDataByAddress.Length = short.Parse(((Control)lengthHexTextBox).Text, NumberStyles.HexNumber);
			}
			else
			{
				getDataByAddress.Length = 0;
			}
		}
		catch
		{
			getDataByAddress.Length = 0;
		}
	}

	protected override bool ProcessCmdKey(ref Message m, Keys keyData)
	{
		//IL_0004: Unknown result type (might be due to invalid IL or missing references)
		//IL_0005: Invalid comparison between I4 and Unknown
		//IL_003d: Unknown result type (might be due to invalid IL or missing references)
		bool flag = false;
		if (9 == (int)keyData && ((ContainerControl)this).ActiveControl != null)
		{
			if (((Control)addressHexTextBox).Focused)
			{
				((Control)lengthHexTextBox).Focus();
				flag = true;
			}
			else
			{
				((ContainerControl)this).ParentForm.TabStop = true;
			}
		}
		if (!flag)
		{
			flag = ((ContainerControl)this).ProcessCmdKey(ref m, keyData);
		}
		return flag;
	}
}
public class GetParameteByIDView : CommandView
{
	private IContainer components;

	private HexTextBox hexTextBox1;

	private Label labelParameterID;

	private GetParametersByID getParametersByID;

	public GetParameteByIDView(GetParametersByID getParametersByID)
	{
		InitializeComponent();
		this.getParametersByID = getParametersByID;
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		base.Dispose(disposing);
	}

	private void InitializeComponent()
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_000b: Expected O, but got Unknown
		labelParameterID = new Label();
		hexTextBox1 = new HexTextBox();
		((Control)this).SuspendLayout();
		((Control)labelParameterID).Location = new Point(24, 8);
		((Control)labelParameterID).Name = "labelParameterID";
		((Control)labelParameterID).Size = new Size(72, 14);
		((Control)labelParameterID).TabIndex = 0;
		((Control)labelParameterID).Text = "Parameter ID";
		((Control)hexTextBox1).Anchor = (AnchorStyles)15;
		((Control)hexTextBox1).Location = new Point(16, 32);
		((Control)hexTextBox1).Name = "hexTextBox1";
		((Control)hexTextBox1).Size = new Size(416, 20);
		((Control)hexTextBox1).TabIndex = 1;
		((Control)hexTextBox1).Text = "";
		((Control)hexTextBox1).TextChanged += hexTextBox1_TextChanged;
		((Control)this).Controls.Add((Control)(object)hexTextBox1);
		((Control)this).Controls.Add((Control)(object)labelParameterID);
		((Control)this).Name = "GetParameteByIDView";
		((Control)this).ResumeLayout(false);
	}

	private void hexTextBox1_TextChanged(object sender, EventArgs e)
	{
		char[] separator = new char[2] { ' ', ',' };
		int[] array2;
		try
		{
			if (((Control)hexTextBox1).Text.Length != 0)
			{
				string[] array = ((Control)hexTextBox1).Text.Split(separator);
				array2 = new int[array.Length];
				for (int i = 0; i < array.Length; i++)
				{
					array2[i] = int.Parse(array[i], NumberStyles.HexNumber);
				}
			}
			else
			{
				array2 = new int[0];
			}
		}
		catch
		{
			array2 = new int[0];
		}
		getParametersByID.ParameterID = array2;
	}
}
public delegate void UpdateViewInvoker(Response response);
public class SendOperation : UserControl
{
	private SendOperationModel sendOperationModel;

	private SendOperationController sendOperationController;

	private CheckBox synchronous;

	private Button sendButton;

	private ContextMenu operationContextMenu;

	private MenuItem menuItemSave;

	private MenuItem menuItemCopy;

	private MenuItem menuItemSelectAll;

	private IAddressValue sourceAddress;

	private Panel panelSynchronous;

	private Panel panelOperationEditSendBtn;

	private Panel panelSendButton;

	private Panel panelOperationLog;

	private Panel panelOperationEdit;

	private ListView operationLogListView;

	private ColumnHeader command;

	private ColumnHeader requestID;

	private ColumnHeader deviceAddr;

	private Label label1;

	private ComboBox operationComboBox;

	private CommandView operationEditPanel;

	private ColumnHeader sentData;

	private ColumnHeader responseID;

	private ColumnHeader returnCode;

	private ColumnHeader returnParameter;

	private ColumnHeader responseDescription;

	private Panel panel1;

	private Container components;

	public IAddressValue SourceAddress
	{
		set
		{
			sourceAddress = value;
			sendOperationController.SourceAddress = value;
		}
	}

	public IModuleNetwork Module
	{
		set
		{
			sendOperationModel.Module = value;
		}
	}

	public SendOperation()
	{
		InitializeComponent();
		operationComboBox.Items.AddRange((object[])Enum.GetNames(typeof(InstructionLayerCommandType)));
		sendOperationModel = new SendOperationModel();
		sendOperationController = new SendOperationController(sendOperationModel);
		synchronous.CheckState = (CheckState)1;
		synchronous.Checked = false;
		InitializeEventHandler();
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		((ContainerControl)this).Dispose(disposing);
	}

	protected override bool ProcessCmdKey(ref Message m, Keys keyData)
	{
		//IL_0002: Unknown result type (might be due to invalid IL or missing references)
		//IL_0005: Invalid comparison between Unknown and I4
		//IL_0021: Unknown result type (might be due to invalid IL or missing references)
		//IL_0024: Invalid comparison between Unknown and I4
		//IL_00a5: Unknown result type (might be due to invalid IL or missing references)
		bool flag = false;
		if ((int)keyData == 13)
		{
			if (((Control)sendButton).Enabled)
			{
				sendButton_Click(this, null);
			}
		}
		else if ((int)keyData == 9 && ((ContainerControl)this).ActiveControl != null)
		{
			if (((Control)operationComboBox).Focused)
			{
				((Control)operationEditPanel).Focus();
				flag = true;
			}
			else if (((Control)operationEditPanel).ContainsFocus)
			{
				((Control)sendButton).Focus();
				flag = true;
			}
			else if (((Control)sendButton).Focused)
			{
				((Control)synchronous).Focus();
				flag = true;
			}
			else if (((Control)synchronous).Focused)
			{
				((Control)operationComboBox).Focus();
				flag = true;
			}
		}
		if (!flag)
		{
			flag = ((ContainerControl)this).ProcessCmdKey(ref m, keyData);
		}
		return flag;
	}

	private void InitializeComponent()
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_000b: Expected O, but got Unknown
		//IL_000c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0016: Expected O, but got Unknown
		//IL_0017: Unknown result type (might be due to invalid IL or missing references)
		//IL_0021: Expected O, but got Unknown
		//IL_0022: Unknown result type (might be due to invalid IL or missing references)
		//IL_002c: Expected O, but got Unknown
		//IL_002d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0037: Expected O, but got Unknown
		//IL_0038: Unknown result type (might be due to invalid IL or missing references)
		//IL_0042: Expected O, but got Unknown
		//IL_0043: Unknown result type (might be due to invalid IL or missing references)
		//IL_004d: Expected O, but got Unknown
		//IL_004e: Unknown result type (might be due to invalid IL or missing references)
		//IL_0058: Expected O, but got Unknown
		//IL_0059: Unknown result type (might be due to invalid IL or missing references)
		//IL_0063: Expected O, but got Unknown
		//IL_0064: Unknown result type (might be due to invalid IL or missing references)
		//IL_006e: Expected O, but got Unknown
		//IL_007a: Unknown result type (might be due to invalid IL or missing references)
		//IL_0084: Expected O, but got Unknown
		//IL_0085: Unknown result type (might be due to invalid IL or missing references)
		//IL_008f: Expected O, but got Unknown
		//IL_0090: Unknown result type (might be due to invalid IL or missing references)
		//IL_009a: Expected O, but got Unknown
		//IL_009b: Unknown result type (might be due to invalid IL or missing references)
		//IL_00a5: Expected O, but got Unknown
		//IL_00a6: Unknown result type (might be due to invalid IL or missing references)
		//IL_00b0: Expected O, but got Unknown
		//IL_00b1: Unknown result type (might be due to invalid IL or missing references)
		//IL_00bb: Expected O, but got Unknown
		//IL_00bc: Unknown result type (might be due to invalid IL or missing references)
		//IL_00c6: Expected O, but got Unknown
		//IL_00c7: Unknown result type (might be due to invalid IL or missing references)
		//IL_00d1: Expected O, but got Unknown
		//IL_00d2: Unknown result type (might be due to invalid IL or missing references)
		//IL_00dc: Expected O, but got Unknown
		//IL_00dd: Unknown result type (might be due to invalid IL or missing references)
		//IL_00e7: Expected O, but got Unknown
		//IL_00e8: Unknown result type (might be due to invalid IL or missing references)
		//IL_00f2: Expected O, but got Unknown
		//IL_00f3: Unknown result type (might be due to invalid IL or missing references)
		//IL_00fd: Expected O, but got Unknown
		//IL_00fe: Unknown result type (might be due to invalid IL or missing references)
		//IL_0108: Expected O, but got Unknown
		//IL_023b: Unknown result type (might be due to invalid IL or missing references)
		//IL_0245: Expected O, but got Unknown
		//IL_02bb: Unknown result type (might be due to invalid IL or missing references)
		//IL_02c5: Expected O, but got Unknown
		operationContextMenu = new ContextMenu();
		menuItemSave = new MenuItem();
		menuItemCopy = new MenuItem();
		menuItemSelectAll = new MenuItem();
		synchronous = new CheckBox();
		sendButton = new Button();
		panelSynchronous = new Panel();
		panelOperationEditSendBtn = new Panel();
		panelSendButton = new Panel();
		panelOperationEdit = new Panel();
		operationEditPanel = new CommandView();
		operationComboBox = new ComboBox();
		panel1 = new Panel();
		label1 = new Label();
		panelOperationLog = new Panel();
		operationLogListView = new ListView();
		deviceAddr = new ColumnHeader();
		command = new ColumnHeader();
		requestID = new ColumnHeader();
		sentData = new ColumnHeader();
		responseID = new ColumnHeader();
		returnCode = new ColumnHeader();
		returnParameter = new ColumnHeader();
		responseDescription = new ColumnHeader();
		((Control)panelSynchronous).SuspendLayout();
		((Control)panelOperationEditSendBtn).SuspendLayout();
		((Control)panelSendButton).SuspendLayout();
		((Control)panelOperationEdit).SuspendLayout();
		((Control)panel1).SuspendLayout();
		((Control)panelOperationLog).SuspendLayout();
		((Control)this).SuspendLayout();
		((Menu)operationContextMenu).MenuItems.AddRange((MenuItem[])(object)new MenuItem[3] { menuItemSave, menuItemCopy, menuItemSelectAll });
		menuItemSave.Index = 0;
		menuItemSave.Text = "Save";
		menuItemSave.Click += menuItemSave_Click;
		menuItemCopy.Index = 1;
		menuItemCopy.Text = "Copy";
		menuItemCopy.Click += menuItemCopy_Click;
		menuItemSelectAll.Index = 2;
		menuItemSelectAll.Text = "Select All";
		menuItemSelectAll.Click += menuItemSelectAll_Click;
		((Control)synchronous).Dock = (DockStyle)4;
		((Control)synchronous).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
		((Control)synchronous).Location = new Point(456, 0);
		((Control)synchronous).Name = "synchronous";
		((Control)synchronous).Size = new Size(96, 32);
		((Control)synchronous).TabIndex = 6;
		((Control)synchronous).Text = "Synchronous";
		((Control)sendButton).Anchor = (AnchorStyles)15;
		((Control)sendButton).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
		((Control)sendButton).Location = new Point(8, 40);
		((Control)sendButton).Name = "sendButton";
		((Control)sendButton).Size = new Size(64, 24);
		((Control)sendButton).TabIndex = 5;
		((Control)sendButton).Text = "Send";
		((Control)sendButton).Click += sendButton_Click;
		((Control)panelSynchronous).Controls.Add((Control)(object)synchronous);
		((Control)panelSynchronous).Dock = (DockStyle)1;
		((Control)panelSynchronous).Location = new Point(0, 0);
		((Control)panelSynchronous).Name = "panelSynchronous";
		((Control)panelSynchronous).Size = new Size(552, 32);
		((Control)panelSynchronous).TabIndex = 9;
		((Control)panelOperationEditSendBtn).Controls.Add((Control)(object)panelSendButton);
		((Control)panelOperationEditSendBtn).Controls.Add((Control)(object)panelOperationEdit);
		((Control)panelOperationEditSendBtn).Dock = (DockStyle)2;
		((Control)panelOperationEditSendBtn).Location = new Point(0, 248);
		((Control)panelOperationEditSendBtn).Name = "panelOperationEditSendBtn";
		((Control)panelOperationEditSendBtn).Size = new Size(552, 80);
		((Control)panelOperationEditSendBtn).TabIndex = 6;
		((Control)panelSendButton).Controls.Add((Control)(object)sendButton);
		((Control)panelSendButton).Dock = (DockStyle)4;
		((Control)panelSendButton).Location = new Point(464, 0);
		((Control)panelSendButton).Name = "panelSendButton";
		((Control)panelSendButton).Size = new Size(88, 80);
		((Control)panelSendButton).TabIndex = 8;
		((Control)panelOperationEdit).Controls.Add((Control)(object)operationEditPanel);
		((Control)panelOperationEdit).Controls.Add((Control)(object)operationComboBox);
		((Control)panelOperationEdit).Controls.Add((Control)(object)panel1);
		((Control)panelOperationEdit).Dock = (DockStyle)5;
		((Control)panelOperationEdit).Location = new Point(0, 0);
		((Control)panelOperationEdit).Name = "panelOperationEdit";
		((Control)panelOperationEdit).Size = new Size(552, 80);
		((Control)panelOperationEdit).TabIndex = 5;
		((Control)operationEditPanel).Anchor = (AnchorStyles)15;
		((Control)operationEditPanel).Location = new Point(176, 8);
		((Control)operationEditPanel).Name = "operationEditPanel";
		((Control)operationEditPanel).Size = new Size(288, 64);
		((Control)operationEditPanel).TabIndex = 1;
		operationComboBox.DropDownStyle = (ComboBoxStyle)2;
		((Control)operationComboBox).Location = new Point(16, 40);
		((Control)operationComboBox).Name = "operationComboBox";
		((Control)operationComboBox).Size = new Size(136, 21);
		((Control)operationComboBox).TabIndex = 0;
		operationComboBox.SelectedIndexChanged += operationComboBox_SelectedIndexChanged;
		((Control)panel1).Controls.Add((Control)(object)label1);
		((Control)panel1).Location = new Point(8, 0);
		((Control)panel1).Name = "panel1";
		((Control)panel1).Size = new Size(160, 72);
		((Control)panel1).TabIndex = 6;
		((Control)label1).Location = new Point(16, 13);
		((Control)label1).Name = "label1";
		((Control)label1).Size = new Size(91, 16);
		((Control)label1).TabIndex = 10;
		((Control)label1).Text = "Select Command";
		((Control)panelOperationLog).Controls.Add((Control)(object)operationLogListView);
		((Control)panelOperationLog).Dock = (DockStyle)5;
		((Control)panelOperationLog).Location = new Point(0, 32);
		((Control)panelOperationLog).Name = "panelOperationLog";
		((Control)panelOperationLog).Size = new Size(552, 216);
		((Control)panelOperationLog).TabIndex = 7;
		((Control)operationLogListView).Anchor = (AnchorStyles)15;
		operationLogListView.Columns.AddRange((ColumnHeader[])(object)new ColumnHeader[8] { deviceAddr, command, requestID, sentData, responseID, returnCode, returnParameter, responseDescription });
		((Control)operationLogListView).ContextMenu = operationContextMenu;
		operationLogListView.FullRowSelect = true;
		operationLogListView.GridLines = true;
		((Control)operationLogListView).Location = new Point(16, 8);
		((Control)operationLogListView).Name = "operationLogListView";
		((Control)operationLogListView).Size = new Size(520, 192);
		operationLogListView.Sorting = (SortOrder)1;
		((Control)operationLogListView).TabIndex = 7;
		operationLogListView.View = (View)1;
		deviceAddr.Text = "Device Addr";
		deviceAddr.Width = 50;
		command.Text = "Cmd";
		command.Width = 50;
		requestID.Text = "Req ID";
		requestID.Width = 50;
		sentData.Text = "Data Sent";
		sentData.Width = 100;
		responseID.Text = "Response ID";
		responseID.Width = 85;
		returnCode.Text = "Return Code";
		returnCode.Width = 70;
		returnParameter.Text = "Return Parameter";
		returnParameter.Width = 89;
		responseDescription.Text = "Description";
		responseDescription.Width = 100;
		((Control)this).Controls.Add((Control)(object)panelOperationLog);
		((Control)this).Controls.Add((Control)(object)panelOperationEditSendBtn);
		((Control)this).Controls.Add((Control)(object)panelSynchronous);
		((Control)this).Name = "SendOperation";
		((Control)this).Size = new Size(552, 328);
		((Control)panelSynchronous).ResumeLayout(false);
		((Control)panelOperationEditSendBtn).ResumeLayout(false);
		((Control)panelSendButton).ResumeLayout(false);
		((Control)panelOperationEdit).ResumeLayout(false);
		((Control)panel1).ResumeLayout(false);
		((Control)panelOperationLog).ResumeLayout(false);
		((Control)this).ResumeLayout(false);
	}

	private void InitializeEventHandler()
	{
		sendOperationModel.CommandCreatedEvent += OnCommandCreated;
		sendOperationModel.CommandExecutedEvent += OnCommandExecuted;
		sendOperationModel.ExecutionFailedEvent += OnExecutionFailed;
		sendOperationModel.CreationFailedEvent += OnCreationFailed;
		sendOperationModel.SynchronousStartedEvent += OnSynchronousStarted;
		sendOperationModel.SynchronousStopedEvent += OnSynchronousStoped;
	}

	private void UpdateListView(Response receivedData)
	{
		//IL_0000: Unknown result type (might be due to invalid IL or missing references)
		//IL_0006: Expected O, but got Unknown
		try
		{
			ListViewItem val = new ListViewItem();
			val.SubItems.Clear();
			val.SubItems.Add(receivedData.address.DisplayId);
			val.SubItems.Add(receivedData.commandType.ToString());
			val.SubItems.Add(receivedData.requestID.ToString());
			val.SubItems.Add(receivedData.sentData);
			val.SubItems.Add(receivedData.receivedData.responseID);
			val.SubItems.Add(receivedData.receivedData.returnCode.ToString());
			if (receivedData.receivedData.returnCode == CommandReturnType.Succeed && receivedData.receivedData.returnParameter != null)
			{
				string text = "";
				byte[] array = (byte[])receivedData.receivedData.returnParameter;
				for (int i = 0; i < array.Length; i++)
				{
					text = text + array[i].ToString("X2") + " ";
				}
				val.SubItems.Add(text);
			}
			else
			{
				val.SubItems.Add("----");
			}
			val.SubItems.RemoveAt(0);
			val.SubItems.Add(receivedData.receivedData.responseDescription);
			operationLogListView.Items.Add(val);
			operationLogListView.EnsureVisible(operationLogListView.Items.Count - 1);
		}
		catch (Exception ex)
		{
			EventLogger.Info("Send Operation", ex.Message);
		}
	}

	private void OnCommandCreated(object source, CommandCreatedEventArgs e)
	{
		((Control)synchronous).Enabled = true;
		((Control)panelOperationEdit).Controls.Remove((Control)(object)operationEditPanel);
		operationEditPanel = e.CommandFactory.CommandView;
		((Control)operationEditPanel).Location = new Point(176, 8);
		((Control)operationEditPanel).TabIndex = 2;
		((Control)operationEditPanel).Anchor = (AnchorStyles)15;
		((Control)panelOperationEdit).Controls.Add((Control)(object)operationEditPanel);
	}

	private void OnCommandExecuted(object source, CommandExecutedEventArgs commandExecutedEventArgs)
	{
		lock (this)
		{
			Response receivedData = commandExecutedEventArgs.ReceivedData;
			object[] array = new object[1] { receivedData };
			((Control)this).BeginInvoke((Delegate)new UpdateViewInvoker(UpdateListView), array);
		}
	}

	private void OnExecutionFailed(object source, ExecutionFailedEventArgs executionFailedEventArgs)
	{
		lock (this)
		{
			Response receivedData = executionFailedEventArgs.ReceivedData;
			object[] array = new object[1] { receivedData };
			((Control)this).BeginInvoke((Delegate)new UpdateViewInvoker(UpdateListView), array);
		}
	}

	private void OnCreationFailed(object source, CreationFailedEventArgs creationFailedEventArgs)
	{
		//IL_001e: Unknown result type (might be due to invalid IL or missing references)
		IMessageDialog caltermMessageDialog = MessageDialogComponent.CaltermMessageDialog;
		caltermMessageDialog.Show("Unable to create command: " + Environment.NewLine + creationFailedEventArgs.Message, MessageDialogButtons.OK, MessageDialogIcon.Information);
	}

	private void OnSynchronousStarted(object sender, EventArgs e)
	{
		((Control)sendButton).Enabled = false;
	}

	private void OnSynchronousStoped(object sender, EventArgs e)
	{
		((Control)sendButton).Enabled = true;
	}

	private void operationComboBox_SelectedIndexChanged(object sender, EventArgs e)
	{
		InstructionLayerCommandType commandType = (InstructionLayerCommandType)Enum.Parse(typeof(InstructionLayerCommandType), ((Control)operationComboBox).Text, ignoreCase: true);
		sendOperationController.CreateCommand(commandType, sourceAddress);
	}

	private void sendButton_Click(object sender, EventArgs e)
	{
		sendOperationController.AddOperation(synchronous.Checked);
		((Control)operationEditPanel).Focus();
	}

	private void menuItemSave_Click(object sender, EventArgs e)
	{
		string text = "";
		if (operationLogListView.Items.Count > 0)
		{
			for (int i = 0; i < operationLogListView.Items.Count; i++)
			{
				if (!operationLogListView.Items[i].Selected)
				{
					continue;
				}
				for (int j = 0; j < operationLogListView.Items[i].SubItems.Count; j++)
				{
					text += operationLogListView.Items[i].SubItems[j].Text.Trim();
					if (j < operationLogListView.Items[i].SubItems.Count - 1)
					{
						text += " : ";
					}
				}
				text += Environment.NewLine;
			}
		}
		sendOperationController.Save(text);
	}

	private void menuItemCopy_Click(object sender, EventArgs e)
	{
		string text = "";
		try
		{
			if (operationLogListView.Items.Count <= 0)
			{
				return;
			}
			SafeClipBoard safeClipBoard = new SafeClipBoard();
			for (int i = 0; i < operationLogListView.Items.Count; i++)
			{
				if (!operationLogListView.Items[i].Selected)
				{
					continue;
				}
				for (int j = 0; j < operationLogListView.Items[i].SubItems.Count; j++)
				{
					text += operationLogListView.Items[i].SubItems[j].Text.Trim();
					if (j < operationLogListView.Items[i].SubItems.Count - 1)
					{
						text += " : ";
					}
				}
				text += Environment.NewLine;
			}
			safeClipBoard.SetDataToClipBoard(text);
		}
		catch
		{
		}
	}

	private void menuItemSelectAll_Click(object sender, EventArgs e)
	{
		for (int i = 0; i < operationLogListView.Items.Count; i++)
		{
			operationLogListView.Items[i].Selected = true;
		}
	}
}
public class CopyInfo
{
	private string operationLog;

	public string OperationLog
	{
		get
		{
			return operationLog;
		}
		set
		{
			operationLog = value;
		}
	}

	public void CopyToClipboard()
	{
		if (operationLog.Length != 0)
		{
			Clipboard.SetDataObject((object)operationLog, true);
		}
	}
}
public class SendOperationController
{
	private SendOperationModel sendOperationModel;

	public IAddressValue SourceAddress
	{
		set
		{
			sendOperationModel.SourceAddress = value;
		}
	}

	public SendOperationController(SendOperationModel sendOperationModel)
	{
		if (sendOperationModel != null)
		{
			this.sendOperationModel = sendOperationModel;
			return;
		}
		throw new ArgumentNullException("sendOperationModel");
	}

	public void AddOperation(bool synchronise)
	{
		sendOperationModel.AddCommand(synchronise);
	}

	public void Save(string operationLog)
	{
		sendOperationModel.Save(operationLog);
	}

	public void CreateCommand(InstructionLayerCommandType commandType, IAddressValue sourceAddress)
	{
		sendOperationModel.CreateCommand(commandType, sourceAddress);
	}
}
public class SendOperationDlg : Form
{
	private Container components;

	private ComboBox SourceAddresses;

	private SendOperation sendOperation;

	private Panel panelSendOperationUserControl;

	private Label sourceAddress;

	public SendOperationDlg(IModuleNetwork module)
	{
		InitializeComponent();
		string text = "";
		sendOperation.Module = module;
		if (module.Modules.Count != 0)
		{
			for (int i = 0; i < module.Modules.Count; i++)
			{
				IAddressValue addressValue = (IAddressValue)module.Modules.GetKey(i);
				ICalibrationOnline calibrationOnline = (ICalibrationOnline)module.Modules[addressValue];
				if (calibrationOnline.CalibrationDataServer != null && calibrationOnline.CalibrationDataServer.GTISLevel == GTISVersion.GTIS45)
				{
					SourceAddresses.Items.Add((object)addressValue.Value);
				}
			}
			if (SourceAddresses.Items.Count != 0)
			{
				((ListControl)SourceAddresses).SelectedIndex = 0;
				text = SourceAddresses.SelectedItem.ToString();
				sendOperation.SourceAddress = AddressFactory.ProductAddressValue(text);
			}
		}
		else
		{
			((Control)SourceAddresses).Enabled = false;
			sendOperation.SourceAddress = AddressFactory.ProductAddressValue(Convert.ToByte("-1").ToString("X2"));
		}
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		((Form)this).Dispose(disposing);
	}

	protected override bool ProcessCmdKey(ref Message m, Keys keyData)
	{
		//IL_0000: Unknown result type (might be due to invalid IL or missing references)
		//IL_0003: Invalid comparison between Unknown and I4
		//IL_000e: Unknown result type (might be due to invalid IL or missing references)
		//IL_0011: Invalid comparison between Unknown and I4
		//IL_0071: Unknown result type (might be due to invalid IL or missing references)
		if ((int)keyData == 27)
		{
			((Form)this).DialogResult = (DialogResult)2;
		}
		else if ((int)keyData == 9 && ((ContainerControl)this).ActiveControl != null)
		{
			if (((object)((ContainerControl)this).ActiveControl).GetType() == typeof(ComboBox))
			{
				((Control)sendOperation).Focus();
				return true;
			}
			if (((object)((ContainerControl)this).ActiveControl).GetType() == typeof(SendOperation))
			{
				((Control)SourceAddresses).Focus();
				return true;
			}
		}
		return ((Form)this).ProcessCmdKey(ref m, keyData);
	}

	private void InitializeComponent()
	{
		//IL_0011: Unknown result type (might be due to invalid IL or missing references)
		//IL_001b: Expected O, but got Unknown
		//IL_001c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0026: Expected O, but got Unknown
		//IL_0032: Unknown result type (might be due to invalid IL or missing references)
		//IL_003c: Expected O, but got Unknown
		//IL_00cc: Unknown result type (might be due to invalid IL or missing references)
		//IL_00d6: Expected O, but got Unknown
		//IL_0260: Unknown result type (might be due to invalid IL or missing references)
		//IL_026a: Expected O, but got Unknown
		ResourceManager resourceManager = new ResourceManager(typeof(SendOperationDlg));
		SourceAddresses = new ComboBox();
		sourceAddress = new Label();
		sendOperation = new SendOperation();
		panelSendOperationUserControl = new Panel();
		((Control)panelSendOperationUserControl).SuspendLayout();
		((Control)this).SuspendLayout();
		SourceAddresses.DropDownStyle = (ComboBoxStyle)2;
		((Control)SourceAddresses).Location = new Point(128, 8);
		((Control)SourceAddresses).Name = "SourceAddresses";
		((Control)SourceAddresses).Size = new Size(136, 21);
		((Control)SourceAddresses).TabIndex = 2;
		SourceAddresses.SelectedIndexChanged += SourceAddresses_SelectedIndexChanged;
		((Control)sourceAddress).Font = new Font("Microsoft Sans Serif", 8.25f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
		((Control)sourceAddress).Location = new Point(16, 11);
		((Control)sourceAddress).Name = "sourceAddress";
		((Control)sourceAddress).Size = new Size(96, 16);
		((Control)sourceAddress).TabIndex = 5;
		((Control)sourceAddress).Text = "Device Address  :";
		((ScrollableControl)sendOperation).AutoScroll = true;
		((Control)sendOperation).Dock = (DockStyle)5;
		((Control)sendOperation).Location = new Point(0, 0);
		((Control)sendOperation).Name = "sendOperation";
		((Control)sendOperation).Size = new Size(616, 357);
		((Control)sendOperation).TabIndex = 1;
		((Control)panelSendOperationUserControl).Controls.Add((Control)(object)SourceAddresses);
		((Control)panelSendOperationUserControl).Controls.Add((Control)(object)sourceAddress);
		((Control)panelSendOperationUserControl).Controls.Add((Control)(object)sendOperation);
		((Control)panelSendOperationUserControl).Dock = (DockStyle)5;
		((Control)panelSendOperationUserControl).Location = new Point(0, 0);
		((Control)panelSendOperationUserControl).Name = "panelSendOperationUserControl";
		((Control)panelSendOperationUserControl).Size = new Size(616, 357);
		((Control)panelSendOperationUserControl).TabIndex = 0;
		((Form)this).AutoScaleBaseSize = new Size(5, 13);
		((Form)this).ClientSize = new Size(616, 357);
		((Control)this).Controls.Add((Control)(object)panelSendOperationUserControl);
		((Form)this).Icon = (Icon)resourceManager.GetObject("$this.Icon");
		((Control)this).MinimumSize = new Size(624, 384);
		((Control)this).Name = "SendOperationDlg";
		((Control)this).Text = "Send Operation";
		((Control)panelSendOperationUserControl).ResumeLayout(false);
		((Control)this).ResumeLayout(false);
	}

	private void SourceAddresses_SelectedIndexChanged(object sender, EventArgs e)
	{
		string address = SourceAddresses.SelectedItem.ToString();
		sendOperation.SourceAddress = AddressFactory.ProductAddressValue(address);
	}
}
public class CommandCreatedEventArgs : EventArgs
{
	private CommandFactory commandFactory;

	public CommandFactory CommandFactory => commandFactory;

	public CommandCreatedEventArgs(CommandFactory commandFactory)
	{
		this.commandFactory = commandFactory;
	}
}
public class CommandExecutedEventArgs : EventArgs
{
	private Response response;

	public Response ReceivedData => response;

	public CommandExecutedEventArgs(Response response)
	{
		this.response = response;
	}
}
public class ExecutionFailedEventArgs : EventArgs
{
	private Response response;

	public Response ReceivedData => response;

	public ExecutionFailedEventArgs(Response response)
	{
		this.response = response;
	}
}
public class CreationFailedEventArgs : EventArgs
{
	private string message;

	public string Message => message;

	public CreationFailedEventArgs(string message)
	{
		this.message = message;
	}
}
public enum InstructionLayerCommandType
{
	GetParameterByID = 10,
	SetParameterByID,
	ExecuteOperation,
	GetDataByAddress,
	SetDataByAddress,
	GetAddressByParameterID
}
public struct Response
{
	public IAddressValue address;

	public InstructionLayerCommandType commandType;

	public int requestID;

	public string sentData;

	public ExecutionResult receivedData;
}
public delegate void CommandCreatedEventHandler(object source, CommandCreatedEventArgs commandCreatedEventArgs);
public delegate void CommandExecutedEventHandler(object source, CommandExecutedEventArgs commandCreatedEventArgs);
public delegate void ExecutionFailedEventHandler(object source, ExecutionFailedEventArgs executionFailedEventArgs);
public delegate void CreationFailedEventHandler(object source, CreationFailedEventArgs creationFailedEventArgs);
public class SendOperationModel
{
	private struct CommandArray
	{
		public CommandModel commandModel;

		public IAddressValue address;

		public InstructionLayerCommandType commandType;

		public int requestID;

		public bool synchronous;
	}

	private IModuleNetwork moduleNetwork;

	private Queue executionQueue;

	private ManualResetEvent manualResetEvent;

	private Response response;

	private CommandArray commandArray;

	private int requestID;

	private Thread executeOperation;

	public IModuleNetwork Module
	{
		set
		{
			moduleNetwork = value;
		}
	}

	public IAddressValue SourceAddress
	{
		set
		{
			try
			{
				ICalibrationECM calibrationECM = GetCalibrationECM(value);
				if (commandArray.commandModel != null)
				{
					commandArray.commandModel.CalibrationECM = calibrationECM;
					commandArray.address = value;
				}
			}
			catch (CalibrationECMException ex)
			{
				RaiseCreationFailedEvent(ex.Message);
			}
		}
	}

	public event CommandCreatedEventHandler CommandCreatedEvent;

	public event CommandExecutedEventHandler CommandExecutedEvent;

	public event ExecutionFailedEventHandler ExecutionFailedEvent;

	public event CreationFailedEventHandler CreationFailedEvent;

	public event EventHandler SynchronousStartedEvent;

	public event EventHandler SynchronousStopedEvent;

	public SendOperationModel()
	{
		executionQueue = new Queue();
		manualResetEvent = new ManualResetEvent(initialState: false);
		ThreadStart start = SendOperationToModule;
		executeOperation = new Thread(start);
		executeOperation.Name = "ExecuteOperation";
		executeOperation.IsBackground = true;
		executeOperation.Start();
	}

	public void CreateCommand(InstructionLayerCommandType commandType, IAddressValue sourceAddress)
	{
		lock (this)
		{
			try
			{
				ICalibrationECM calibrationECM = GetCalibrationECM(sourceAddress);
				ICLIPService clipService = new CLIPService(calibrationECM);
				CommandFactory commandFactory = new CommandFactory(commandType, clipService);
				commandArray.commandModel = commandFactory.CommandModel;
				commandArray.address = sourceAddress;
				commandArray.commandType = commandType;
				RaiseCommandCreatedEvent(commandFactory);
			}
			catch (CalibrationECMException ex)
			{
				RaiseCreationFailedEvent("Cannot created a command." + ex.Message);
			}
			catch (CommandNotSupportedException ex2)
			{
				RaiseCreationFailedEvent("Cannot created a command." + ex2.Message);
			}
		}
	}

	public void AddCommand(bool synchronise)
	{
		lock (this)
		{
			if (commandArray.commandModel == null)
			{
				return;
			}
			try
			{
				commandArray.requestID = requestID++;
				commandArray.synchronous = synchronise;
				executionQueue.Enqueue(commandArray);
				if (commandArray.synchronous)
				{
					RaiseSynchronousStartedEvent();
				}
				manualResetEvent.Set();
			}
			catch (Exception ex)
			{
				RaiseCreationFailedEvent(ex.Message);
			}
		}
	}

	public void Save(string operations)
	{
		Monitor.Enter(this);
		TextWriter textWriter = null;
		try
		{
			IAppConfigService appConfigService = (IAppConfigService)ServiceManager.Services.GetService(typeof(IAppConfigService));
			string appSetting = appConfigService.GetAppSetting(ApplicationSettings.LastProduct);
			IDirectoryService directoryService = (IDirectoryService)ServiceManager.Services.GetService(typeof(IDirectoryService));
			string path = directoryService.FolderName(FolderType.Product, appSetting);
			string text = Utility.FindAvailableFilename("operation", ".txt", path);
			textWriter = new StreamWriter(text);
			if (textWriter == null)
			{
				throw new Exception($"Unable to open file {text}");
			}
			textWriter.WriteLine("Source Address : Command : Request ID : Data Sent : Response ID : Return Code : Return Parameter : Response Description ");
			textWriter.Write(operations);
			EventLogger.Info("Send Operation", "Operation log file saved sucessfully to " + text);
			textWriter.Close();
			Monitor.Exit(this);
		}
		catch (Exception)
		{
			EventLogger.Info("Send Operation", "Unable to Save operation log file");
		}
	}

	protected void RaiseCreationFailedEvent(string message)
	{
		if (this.CreationFailedEvent != null)
		{
			CreationFailedEventArgs creationFailedEventArgs = new CreationFailedEventArgs(message);
			this.CreationFailedEvent(this, creationFailedEventArgs);
		}
	}

	protected void RaiseCommandCreatedEvent(CommandFactory commandFactory)
	{
		if (this.CommandCreatedEvent != null)
		{
			CommandCreatedEventArgs commandCreatedEventArgs = new CommandCreatedEventArgs(commandFactory);
			this.CommandCreatedEvent(this, commandCreatedEventArgs);
		}
	}

	protected void RaiseCommandExecutedEvent(Response response)
	{
		if (this.CommandExecutedEvent != null)
		{
			CommandExecutedEventArgs commandCreatedEventArgs = new CommandExecutedEventArgs(response);
			this.CommandExecutedEvent(this, commandCreatedEventArgs);
		}
	}

	protected void RaiseExecutionFailedEvent(Response response)
	{
		if (this.ExecutionFailedEvent != null)
		{
			ExecutionFailedEventArgs executionFailedEventArgs = new ExecutionFailedEventArgs(response);
			this.ExecutionFailedEvent(this, executionFailedEventArgs);
		}
	}

	protected void RaiseSynchronousStartedEvent()
	{
		if (this.SynchronousStartedEvent != null)
		{
			this.SynchronousStartedEvent(this, null);
		}
	}

	protected void RaiseSynchronousStopedEvent()
	{
		if (this.SynchronousStopedEvent != null)
		{
			this.SynchronousStopedEvent(this, null);
		}
	}

	private void SendOperationToModule()
	{
		while (manualResetEvent.WaitOne())
		{
			lock (this)
			{
				manualResetEvent.Reset();
				if (executionQueue.Count == 0 && executionQueue == null)
				{
					continue;
				}
				for (int i = 0; i < executionQueue.Count; i++)
				{
					CommandArray commandArray = (CommandArray)executionQueue.Dequeue();
					try
					{
						commandArray.commandModel.Execute();
						StoreResponseData(commandArray, commandExecutedSucessfully: true);
						RaiseCommandExecutedEvent(response);
						manualResetEvent.Set();
						if (commandArray.synchronous)
						{
							RaiseSynchronousStopedEvent();
						}
					}
					catch (Exception ex)
					{
						manualResetEvent.Reset();
						string text = "Unable to execute command on ECM";
						EventLogger.Warn("Send Operation", text, ex);
						StoreResponseData(commandArray, commandExecutedSucessfully: false);
						response.receivedData.responseDescription = text + " " + ex.Message;
						RaiseExecutionFailedEvent(response);
						if (commandArray.synchronous)
						{
							RaiseSynchronousStopedEvent();
						}
					}
				}
			}
		}
	}

	private ICalibrationECM GetCalibrationECM(IAddressValue sourceAddress)
	{
		ICalibrationECM calibrationECM = null;
		if (sourceAddress.Type == AddressType.ECM)
		{
			calibrationECM = (ICalibrationECM)moduleNetwork.GetCalibration(sourceAddress);
			if (calibrationECM == null || !calibrationECM.Connected)
			{
				throw new CalibrationECMException(SendOperationMessageId.ModuleIsNotConnected, "Module is not connected.");
			}
		}
		return calibrationECM;
	}

	private void StoreResponseData(CommandArray commandArray, bool commandExecutedSucessfully)
	{
		response.address = commandArray.address;
		response.commandType = commandArray.commandType;
		response.requestID = commandArray.requestID;
		response.sentData = commandArray.commandModel.SendData;
		if (commandExecutedSucessfully)
		{
			response.receivedData = commandArray.commandModel.ReceivedData;
			return;
		}
		response.receivedData.returnCode = CommandReturnType.Failed;
		response.receivedData.responseID = "--";
		response.receivedData.returnParameter = "";
	}
}
public class SetDataByAddressView : CommandView
{
	private IContainer components;

	private HexTextBox addressHexTextBox;

	private HexTextBox lengthHexTextBox;

	private HexTextBox dataHexTextBox;

	private Label labelAddress;

	private Label labelLength;

	private Label labelData;

	private SetDataByAddress setDataByAddress;

	public SetDataByAddressView(SetDataByAddress setDataByAddress)
	{
		InitializeComponent();
		this.setDataByAddress = setDataByAddress;
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		base.Dispose(disposing);
	}

	private void InitializeComponent()
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_000b: Expected O, but got Unknown
		//IL_000c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0016: Expected O, but got Unknown
		//IL_0017: Unknown result type (might be due to invalid IL or missing references)
		//IL_0021: Expected O, but got Unknown
		labelAddress = new Label();
		labelLength = new Label();
		labelData = new Label();
		addressHexTextBox = new HexTextBox();
		lengthHexTextBox = new HexTextBox();
		dataHexTextBox = new HexTextBox();
		((Control)this).SuspendLayout();
		((Control)labelAddress).Location = new Point(17, 8);
		((Control)labelAddress).Name = "labelAddress";
		((Control)labelAddress).Size = new Size(48, 14);
		((Control)labelAddress).TabIndex = 0;
		((Control)labelAddress).Text = "Address";
		((Control)labelLength).Location = new Point(128, 8);
		((Control)labelLength).Name = "labelLength";
		((Control)labelLength).Size = new Size(48, 14);
		((Control)labelLength).TabIndex = 2;
		((Control)labelLength).Text = "Length";
		((Control)labelData).Location = new Point(248, 8);
		((Control)labelData).Name = "labelData";
		((Control)labelData).Size = new Size(32, 14);
		((Control)labelData).TabIndex = 4;
		((Control)labelData).Text = "Data";
		((Control)addressHexTextBox).Location = new Point(16, 32);
		((Control)addressHexTextBox).Name = "addressHexTextBox";
		((Control)addressHexTextBox).TabIndex = 2;
		((Control)addressHexTextBox).Text = "";
		((Control)addressHexTextBox).TextChanged += addressHexTextBox_TextChanged;
		((Control)lengthHexTextBox).Location = new Point(128, 32);
		((Control)lengthHexTextBox).Name = "lengthHexTextBox";
		((Control)lengthHexTextBox).TabIndex = 3;
		((Control)lengthHexTextBox).Text = "";
		((Control)lengthHexTextBox).TextChanged += lengthHexTextBox_TextChanged;
		((Control)dataHexTextBox).Anchor = (AnchorStyles)15;
		((Control)dataHexTextBox).Location = new Point(240, 32);
		((Control)dataHexTextBox).Name = "dataHexTextBox";
		((Control)dataHexTextBox).Size = new Size(192, 20);
		((Control)dataHexTextBox).TabIndex = 4;
		((Control)dataHexTextBox).Text = "";
		((Control)dataHexTextBox).TextChanged += dataHexTextBox_TextChanged;
		((Control)this).Controls.Add((Control)(object)dataHexTextBox);
		((Control)this).Controls.Add((Control)(object)lengthHexTextBox);
		((Control)this).Controls.Add((Control)(object)addressHexTextBox);
		((Control)this).Controls.Add((Control)(object)labelData);
		((Control)this).Controls.Add((Control)(object)labelLength);
		((Control)this).Controls.Add((Control)(object)labelAddress);
		((Control)this).Name = "SetDataByAddressView";
		((Control)this).ResumeLayout(false);
	}

	private void addressHexTextBox_TextChanged(object sender, EventArgs e)
	{
		if (((Control)addressHexTextBox).Text.Length != 0)
		{
			try
			{
				setDataByAddress.Address = int.Parse(((Control)addressHexTextBox).Text, NumberStyles.HexNumber);
				return;
			}
			catch
			{
				setDataByAddress.Address = 0;
				return;
			}
		}
		setDataByAddress.Address = 0;
	}

	private void lengthHexTextBox_TextChanged(object sender, EventArgs e)
	{
		if (((Control)lengthHexTextBox).Text.Length != 0)
		{
			try
			{
				setDataByAddress.Length = short.Parse(((Control)lengthHexTextBox).Text, NumberStyles.HexNumber);
				return;
			}
			catch
			{
				setDataByAddress.Length = 0;
				return;
			}
		}
		setDataByAddress.Length = 0;
	}

	private void dataHexTextBox_TextChanged(object sender, EventArgs e)
	{
		char[] separator = new char[2] { ' ', ',' };
		byte[] array2;
		try
		{
			if (((Control)dataHexTextBox).Text.Length != 0)
			{
				string[] array = ((Control)dataHexTextBox).Text.Split(separator);
				array2 = new byte[array.Length];
				try
				{
					for (int i = 0; i < array.Length; i++)
					{
						array2[i] = byte.Parse(array[i], NumberStyles.HexNumber);
					}
				}
				catch
				{
					array2 = new byte[0];
				}
			}
			else
			{
				array2 = new byte[0];
			}
		}
		catch
		{
			array2 = new byte[0];
		}
		setDataByAddress.Data = array2;
	}

	protected override bool ProcessCmdKey(ref Message m, Keys keyData)
	{
		//IL_0004: Unknown result type (might be due to invalid IL or missing references)
		//IL_0005: Invalid comparison between I4 and Unknown
		//IL_005a: Unknown result type (might be due to invalid IL or missing references)
		bool flag = false;
		if (9 == (int)keyData && ((ContainerControl)this).ActiveControl != null)
		{
			if (((Control)addressHexTextBox).Focused)
			{
				((Control)lengthHexTextBox).Focus();
				flag = true;
			}
			else if (((Control)lengthHexTextBox).Focused)
			{
				((Control)dataHexTextBox).Focus();
				flag = true;
			}
			else
			{
				((ContainerControl)this).ParentForm.TabStop = true;
			}
		}
		if (!flag)
		{
			flag = ((ContainerControl)this).ProcessCmdKey(ref m, keyData);
		}
		return flag;
	}
}
public class SetParameterByIDView : CommandView
{
	private IContainer components;

	private HexTextBox parameterHexTextBox;

	private HexTextBox dataHexTextBox;

	private Label labelParameterId;

	private Label labelData;

	private SetParametersByID setParametersByID;

	public SetParameterByIDView(SetParametersByID setParametersByID)
	{
		InitializeComponent();
		this.setParametersByID = setParametersByID;
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		base.Dispose(disposing);
	}

	private void InitializeComponent()
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_000b: Expected O, but got Unknown
		//IL_000c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0016: Expected O, but got Unknown
		labelParameterId = new Label();
		labelData = new Label();
		parameterHexTextBox = new HexTextBox();
		dataHexTextBox = new HexTextBox();
		((Control)this).SuspendLayout();
		((Control)labelParameterId).Location = new Point(16, 8);
		((Control)labelParameterId).Name = "labelParameterId";
		((Control)labelParameterId).Size = new Size(70, 14);
		((Control)labelParameterId).TabIndex = 0;
		((Control)labelParameterId).Text = "Parameter Id";
		((Control)labelData).Location = new Point(136, 8);
		((Control)labelData).Name = "labelData";
		((Control)labelData).Size = new Size(56, 14);
		((Control)labelData).TabIndex = 2;
		((Control)labelData).Text = "Data";
		((Control)parameterHexTextBox).Location = new Point(16, 32);
		((Control)parameterHexTextBox).Name = "parameterHexTextBox";
		((Control)parameterHexTextBox).TabIndex = 3;
		((Control)parameterHexTextBox).Text = "";
		((Control)parameterHexTextBox).TextChanged += parameterHexTextBox_TextChanged;
		((Control)dataHexTextBox).Anchor = (AnchorStyles)15;
		((Control)dataHexTextBox).Location = new Point(128, 32);
		((Control)dataHexTextBox).Name = "dataHexTextBox";
		((Control)dataHexTextBox).Size = new Size(304, 20);
		((Control)dataHexTextBox).TabIndex = 4;
		((Control)dataHexTextBox).Text = "";
		((Control)dataHexTextBox).TextChanged += dataHexTextBox_TextChanged;
		((Control)this).Controls.Add((Control)(object)dataHexTextBox);
		((Control)this).Controls.Add((Control)(object)parameterHexTextBox);
		((Control)this).Controls.Add((Control)(object)labelData);
		((Control)this).Controls.Add((Control)(object)labelParameterId);
		((Control)this).Name = "SetParameterByIDView";
		((Control)this).ResumeLayout(false);
	}

	private void parameterHexTextBox_TextChanged(object sender, EventArgs e)
	{
		char[] separator = new char[2] { ' ', ',' };
		int[] array2;
		if (((Control)parameterHexTextBox).Text.Length != 0)
		{
			string[] array = ((Control)parameterHexTextBox).Text.Split(separator);
			array2 = new int[array.Length];
			try
			{
				for (int i = 0; i < array2.Length; i++)
				{
					array2[i] = int.Parse(array[i], NumberStyles.HexNumber);
				}
			}
			catch
			{
				array2 = new int[0];
			}
		}
		else
		{
			array2 = new int[0];
		}
		setParametersByID.ParameterID = array2;
	}

	private void dataHexTextBox_TextChanged(object sender, EventArgs e)
	{
		char[] separator = new char[2] { ' ', ',' };
		byte[] array2;
		if (((Control)dataHexTextBox).Text.Length != 0)
		{
			string[] array = ((Control)dataHexTextBox).Text.Split(separator);
			array2 = new byte[array.Length];
			try
			{
				for (int i = 0; i < array.Length; i++)
				{
					array2[i] = byte.Parse(array[i], NumberStyles.HexNumber);
				}
			}
			catch
			{
				array2 = new byte[1];
			}
		}
		else
		{
			array2 = new byte[1];
		}
		setParametersByID.Data = array2;
	}

	protected override bool ProcessCmdKey(ref Message m, Keys keyData)
	{
		//IL_0004: Unknown result type (might be due to invalid IL or missing references)
		//IL_0005: Invalid comparison between I4 and Unknown
		//IL_003d: Unknown result type (might be due to invalid IL or missing references)
		bool flag = false;
		if (9 == (int)keyData && ((ContainerControl)this).ActiveControl != null)
		{
			if (((Control)parameterHexTextBox).Focused)
			{
				((Control)dataHexTextBox).Focus();
				flag = true;
			}
			else
			{
				((ContainerControl)this).ParentForm.TabStop = true;
			}
		}
		if (!flag)
		{
			flag = ((ContainerControl)this).ProcessCmdKey(ref m, keyData);
		}
		return flag;
	}
}
