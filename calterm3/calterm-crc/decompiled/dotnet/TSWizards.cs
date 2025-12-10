using System;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.Versioning;
using System.Security;
using System.Security.Permissions;
using System.Windows.Forms;

[assembly: CompilationRelaxations(8)]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: TargetFramework(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework 4.5")]
[assembly: AssemblyProduct("Calterm III - TSWizard")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2011")]
[assembly: AssemblyTrademark("Copyright © Cummins Inc. 2011")]
[assembly: AssemblyFileVersion("3.17.0.000")]
[assembly: AssemblyVersion("3.17.0.0")]
namespace TSWizards;

public enum AllowClose
{
	Ask,
	AskIfNotFinish,
	AlwaysAllow
}
[DefaultEvent("ShowStep")]
public class BaseStep : UserControl
{
	private static object stepTitleChanged = new object();

	private static object previousStepChanged = new object();

	private static object nextStepChanged = new object();

	private static object showStep = new object();

	private static object resetStep = new object();

	private static object validateStep = new object();

	public static string FinishStep = "FINISHED";

	private string title = "";

	private BaseWizard wizard;

	private string previousStep = "";

	private string nextStep = "";

	private bool canFinish;

	private string description = "";

	private Container components;

	[DefaultValue("Step Title")]
	[Browsable(true)]
	[Category("Wizard Step")]
	[Description("Gets/Sets the text that will be displayed in the white portion above the step")]
	public string StepTitle
	{
		get
		{
			return title;
		}
		set
		{
			title = value;
			OnStepTitleChanged(EventArgs.Empty);
		}
	}

	[Description("Gets/Sets the previous step in the wizard process")]
	[Browsable(true)]
	[DefaultValue("")]
	[Category("Wizard Step")]
	public string PreviousStep
	{
		get
		{
			return previousStep;
		}
		set
		{
			previousStep = value;
			OnPreviousStepChanged(EventArgs.Empty);
		}
	}

	[Description("Gets/Sets the next step in the wizard process")]
	[Category("Wizard Step")]
	[Browsable(true)]
	[DefaultValue("")]
	public string NextStep
	{
		get
		{
			return nextStep;
		}
		set
		{
			nextStep = value;
			OnNextStepChanged(EventArgs.Empty);
		}
	}

	[Description("Gets/Sets the step description in the wizard process")]
	[DefaultValue("")]
	[Browsable(false)]
	[Category("Wizard Step")]
	public string Description
	{
		get
		{
			return description;
		}
		set
		{
			description = value;
		}
	}

	[Browsable(false)]
	public BaseWizard Wizard
	{
		get
		{
			return wizard;
		}
		set
		{
			if (wizard != null)
			{
				DetachWizard();
			}
			wizard = value;
			if (value != null)
			{
				AttachWizard();
			}
		}
	}

	[Browsable(true)]
	[DefaultValue(false)]
	[Category("Wizard Step")]
	[Description("Gets/Sets whether this is the last step of the wizard")]
	public bool IsFinished
	{
		get
		{
			return nextStep == FinishStep;
		}
		set
		{
			if (value)
			{
				nextStep = FinishStep;
				FinishEnabled = true;
			}
			else
			{
				nextStep = "";
			}
		}
	}

	[Browsable(true)]
	[DefaultValue(false)]
	[Category("Wizard Step")]
	[Description("Gets/Sets whether the Finish button is enabled on this step")]
	public bool FinishEnabled
	{
		get
		{
			return canFinish;
		}
		set
		{
			canFinish = value;
			if (Wizard != null)
			{
				Wizard.FinishEnabled = canFinish;
			}
		}
	}

	[Description("Fired when the NextStep property has changed")]
	[Category("Wizard Step")]
	[Browsable(true)]
	public event EventHandler NextStepChanged
	{
		add
		{
			((Component)this).Events.AddHandler(nextStepChanged, value);
		}
		remove
		{
			((Component)this).Events.RemoveHandler(nextStepChanged, value);
		}
	}

	[Description("Fired when the PreviousStep property has changed")]
	[Browsable(true)]
	[Category("Wizard Step")]
	public event EventHandler PreviousStepChanged
	{
		add
		{
			((Component)this).Events.AddHandler(previousStepChanged, value);
		}
		remove
		{
			((Component)this).Events.RemoveHandler(previousStepChanged, value);
		}
	}

	[Description("Fired when the StepTitle property has changed")]
	[Browsable(true)]
	[Category("Wizard Step")]
	public event EventHandler StepTitleChanged
	{
		add
		{
			((Component)this).Events.AddHandler(stepTitleChanged, value);
		}
		remove
		{
			((Component)this).Events.RemoveHandler(stepTitleChanged, value);
		}
	}

	[Category("Wizard")]
	[Description("Fired every time the step is shown in the wizard")]
	[Browsable(true)]
	public event EventHandler ShowStep
	{
		add
		{
			((Component)this).Events.AddHandler(showStep, value);
		}
		remove
		{
			((Component)this).Events.RemoveHandler(showStep, value);
		}
	}

	[Description("Fired when the step needs to reset itself, this is fired when the wizard is reset and when the wizard is first shown")]
	[Category("Wizard")]
	[Browsable(true)]
	public event EventHandler ResetStep
	{
		add
		{
			((Component)this).Events.AddHandler(resetStep, value);
		}
		remove
		{
			((Component)this).Events.RemoveHandler(resetStep, value);
		}
	}

	[Browsable(true)]
	[Category("Wizard Step")]
	[Description("Fired when moving to the next step")]
	public event CancelEventHandler ValidateStep
	{
		add
		{
			((Component)this).Events.AddHandler(validateStep, value);
		}
		remove
		{
			((Component)this).Events.RemoveHandler(validateStep, value);
		}
	}

	public BaseStep()
	{
		InitializeComponent();
	}

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
		((Control)this).SuspendLayout();
		((Control)this).Name = "BaseStep";
		((Control)this).Size = new Size(472, 236);
		((UserControl)this).Load += BaseStep_Load;
		((Control)this).ResumeLayout(false);
	}

	private void DetachWizard()
	{
		Wizard.NextClicked -= Wizard_OnNextClicked;
		Wizard.BackClicked -= Wizard_OnBackClicked;
		Wizard.FinishClicked -= Wizard_OnFinishClicked;
	}

	private void AttachWizard()
	{
		Wizard.NextClicked += Wizard_OnNextClicked;
		Wizard.BackClicked += Wizard_OnBackClicked;
		Wizard.FinishClicked += Wizard_OnFinishClicked;
		Wizard.FinishEnabled = canFinish;
	}

	protected virtual void OnNextStepChanged(EventArgs e)
	{
		((EventHandler)((Component)this).Events[nextStepChanged])?.Invoke(this, e);
	}

	protected virtual void OnPreviousStepChanged(EventArgs e)
	{
		((EventHandler)((Component)this).Events[previousStepChanged])?.Invoke(this, e);
	}

	protected virtual void OnStepTitleChanged(EventArgs e)
	{
		((EventHandler)((Component)this).Events[stepTitleChanged])?.Invoke(this, e);
	}

	protected virtual void OnShowStep(EventArgs e)
	{
		((EventHandler)((Component)this).Events[showStep])?.Invoke(this, e);
	}

	protected virtual void OnResetStep(EventArgs e)
	{
		((EventHandler)((Component)this).Events[resetStep])?.Invoke(this, e);
	}

	protected virtual void OnValidateStep(CancelEventArgs e)
	{
		((CancelEventHandler)((Component)this).Events[validateStep])?.Invoke(this, e);
	}

	private void Wizard_OnNextClicked(object o, EventArgs e)
	{
		OnNext();
	}

	private void Wizard_OnBackClicked(object o, EventArgs e)
	{
		OnBack();
	}

	private void Wizard_OnFinishClicked(object o, EventArgs e)
	{
		OnFinish();
	}

	private void BaseStep_Load(object sender, EventArgs e)
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_0007: Expected O, but got Unknown
		UIPermission val = new UIPermission((UIPermissionWindow)3);
		((CodeAccessPermission)val).Demand();
	}

	protected virtual void OnNext()
	{
		CancelEventArgs e = new CancelEventArgs();
		OnValidateStep(e);
		if (!e.Cancel)
		{
			Wizard.MoveNext();
		}
	}

	protected virtual void OnBack()
	{
		Wizard.MoveBack();
	}

	protected virtual void OnFinish()
	{
		CancelEventArgs e = new CancelEventArgs();
		OnValidateStep(e);
		if (!e.Cancel)
		{
			((Form)Wizard).DialogResult = (DialogResult)1;
		}
	}

	internal void FireShowEvent()
	{
		OnShowStep(EventArgs.Empty);
	}

	internal void FireResetStepEvent()
	{
		OnResetStep(EventArgs.Empty);
	}
}
[DefaultEvent("LoadSteps")]
public class BaseWizard : Form
{
	private const string StepInfoFormat = "Step {0} of {1}";

	private static object backClicked = new object();

	private static object nextClicked = new object();

	private static object finishClicked = new object();

	private static object loadSteps = new object();

	private BaseStep currentStep;

	private string firstStep = "";

	private WizardStepDictionary steps;

	private AllowClose allowClose = AllowClose.AlwaysAllow;

	private int currentStepNumber = 1;

	protected Panel wizardTop;

	protected Button cancel;

	protected Button back;

	protected Button next;

	protected Panel panelStep;

	protected PictureBox wizardLogo;

	protected LineFrame topLine;

	protected LineFrame bottomLine;

	protected Label wizardTitle;

	protected Button finish;

	protected Label stepInfo;

	private Container components;

	[DefaultValue("Wizard Title")]
	[Description("Gets/Sets the text that is displayed in the white area next to the logo")]
	[Category("Wizard")]
	[Browsable(true)]
	public virtual string Title
	{
		get
		{
			return ((Control)wizardTitle).Text;
		}
		set
		{
			((Control)wizardTitle).Text = value;
		}
	}

	[DefaultValue(typeof(Image), "TSWizards.blank.bmp")]
	[Browsable(true)]
	[Category("Wizard")]
	[Description("Gets/Sets the image that is displayed in the upper-right corner of the wizard")]
	public virtual Image Logo
	{
		get
		{
			return wizardLogo.Image;
		}
		set
		{
			wizardLogo.Image = value;
		}
	}

	[DefaultValue(true)]
	[Browsable(true)]
	[Category("Wizard")]
	[Description("Gets/Sets whether the back button will be enabled")]
	public virtual bool BackEnabled
	{
		get
		{
			return ((Control)back).Enabled;
		}
		set
		{
			((Control)back).Enabled = value;
		}
	}

	[DefaultValue(true)]
	[Description("Gets/Sets whether the next button will be enabled")]
	[Browsable(true)]
	[Category("Wizard")]
	public virtual bool NextEnabled
	{
		get
		{
			return ((Control)next).Enabled;
		}
		set
		{
			((Control)next).Enabled = value;
			if (value)
			{
				((Control)next).Focus();
			}
		}
	}

	[Browsable(true)]
	[Category("Wizard")]
	[Description("Gets/Sets whether the finish button will be enabled")]
	[DefaultValue(false)]
	public virtual bool FinishEnabled
	{
		get
		{
			return ((Control)finish).Enabled;
		}
		set
		{
			((Control)finish).Enabled = value;
		}
	}

	[DefaultValue("")]
	[Description("Gets/Sets the name of the first step of the wizard")]
	[Browsable(true)]
	[Category("Wizard")]
	public virtual string FirstStepName
	{
		get
		{
			return firstStep;
		}
		set
		{
			if (value == null)
			{
				value = "";
			}
			firstStep = value;
		}
	}

	[Browsable(true)]
	[Description("Gets/Sets the kind of closing allowed")]
	[DefaultValue(AllowClose.AlwaysAllow)]
	[Category("Wizard")]
	public virtual AllowClose AllowClose
	{
		get
		{
			return allowClose;
		}
		set
		{
			allowClose = value;
		}
	}

	protected virtual BaseStep CurrentStep => currentStep;

	[Browsable(false)]
	protected virtual WizardStepDictionary Steps => steps;

	[Browsable(false)]
	protected virtual int CurrentStepNumber
	{
		get
		{
			return currentStepNumber;
		}
		set
		{
			currentStepNumber = value;
			((Control)stepInfo).Text = $"Step {currentStepNumber} of {steps.Count}";
		}
	}

	[Browsable(false)]
	internal event EventHandler BackClicked
	{
		add
		{
			((Component)this).Events.AddHandler(backClicked, value);
		}
		remove
		{
			((Component)this).Events.RemoveHandler(backClicked, value);
		}
	}

	[Browsable(false)]
	internal event EventHandler NextClicked
	{
		add
		{
			((Component)this).Events.AddHandler(nextClicked, value);
		}
		remove
		{
			((Component)this).Events.RemoveHandler(nextClicked, value);
		}
	}

	[Browsable(false)]
	internal event EventHandler FinishClicked
	{
		add
		{
			((Component)this).Events.AddHandler(finishClicked, value);
		}
		remove
		{
			((Component)this).Events.RemoveHandler(finishClicked, value);
		}
	}

	[Description("Fired when the wizard should add the initial steps to the wizard")]
	[Browsable(true)]
	[Category("Wizard")]
	public virtual event EventHandler LoadSteps
	{
		add
		{
			((Component)this).Events.AddHandler(loadSteps, value);
		}
		remove
		{
			((Component)this).Events.RemoveHandler(loadSteps, value);
		}
	}

	public BaseWizard()
	{
		//IL_0040: Unknown result type (might be due to invalid IL or missing references)
		//IL_004a: Expected O, but got Unknown
		InitializeComponent();
		steps = new WizardStepDictionary();
		Logo = (Image)new Bitmap(typeof(BaseWizard), "blank.bmp");
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		((Form)this).Dispose(disposing);
	}

	private void InitializeComponent()
	{
		//IL_0011: Unknown result type (might be due to invalid IL or missing references)
		//IL_001b: Expected O, but got Unknown
		//IL_001c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0026: Expected O, but got Unknown
		//IL_0027: Unknown result type (might be due to invalid IL or missing references)
		//IL_0031: Expected O, but got Unknown
		//IL_0032: Unknown result type (might be due to invalid IL or missing references)
		//IL_003c: Expected O, but got Unknown
		//IL_0053: Unknown result type (might be due to invalid IL or missing references)
		//IL_005d: Expected O, but got Unknown
		//IL_005e: Unknown result type (might be due to invalid IL or missing references)
		//IL_0068: Expected O, but got Unknown
		//IL_0069: Unknown result type (might be due to invalid IL or missing references)
		//IL_0073: Expected O, but got Unknown
		//IL_0074: Unknown result type (might be due to invalid IL or missing references)
		//IL_007e: Expected O, but got Unknown
		//IL_007f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0089: Expected O, but got Unknown
		//IL_015b: Unknown result type (might be due to invalid IL or missing references)
		//IL_0165: Expected O, but got Unknown
		//IL_01cb: Unknown result type (might be due to invalid IL or missing references)
		//IL_01d5: Expected O, but got Unknown
		//IL_069f: Unknown result type (might be due to invalid IL or missing references)
		//IL_06a9: Expected O, but got Unknown
		ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(BaseWizard));
		wizardTop = new Panel();
		stepInfo = new Label();
		wizardTitle = new Label();
		wizardLogo = new PictureBox();
		topLine = new LineFrame();
		bottomLine = new LineFrame();
		cancel = new Button();
		back = new Button();
		next = new Button();
		panelStep = new Panel();
		finish = new Button();
		((Control)wizardTop).SuspendLayout();
		((ISupportInitialize)wizardLogo).BeginInit();
		((Control)this).SuspendLayout();
		((Control)wizardTop).BackColor = Color.White;
		((Control)wizardTop).Controls.Add((Control)(object)stepInfo);
		((Control)wizardTop).Controls.Add((Control)(object)wizardTitle);
		((Control)wizardTop).Controls.Add((Control)(object)wizardLogo);
		((Control)wizardTop).Dock = (DockStyle)1;
		((Control)wizardTop).Location = new Point(0, 0);
		((Control)wizardTop).Name = "wizardTop";
		((Control)wizardTop).Size = new Size(488, 64);
		((Control)wizardTop).TabIndex = 0;
		((Control)stepInfo).Font = new Font("Arial", 9.75f, (FontStyle)0, (GraphicsUnit)3, (byte)0);
		((Control)stepInfo).Location = new Point(0, 32);
		((Control)stepInfo).Name = "stepInfo";
		((Control)stepInfo).Size = new Size(432, 32);
		((Control)stepInfo).TabIndex = 0;
		stepInfo.TextAlign = (ContentAlignment)16;
		((Control)wizardTitle).Font = new Font("Arial", 12f, (FontStyle)1, (GraphicsUnit)3, (byte)0);
		((Control)wizardTitle).Location = new Point(0, 0);
		((Control)wizardTitle).Name = "wizardTitle";
		((Control)wizardTitle).Size = new Size(432, 32);
		((Control)wizardTitle).TabIndex = 1;
		wizardTitle.TextAlign = (ContentAlignment)16;
		((Control)wizardLogo).Dock = (DockStyle)4;
		((Control)wizardLogo).Location = new Point(429, 0);
		((Control)wizardLogo).Name = "wizardLogo";
		((Control)wizardLogo).Size = new Size(59, 64);
		wizardLogo.SizeMode = (PictureBoxSizeMode)2;
		wizardLogo.TabIndex = 2;
		wizardLogo.TabStop = false;
		((Control)topLine).Dock = (DockStyle)1;
		((Control)topLine).Location = new Point(0, 64);
		((Control)topLine).Name = "topLine";
		((Control)topLine).Size = new Size(488, 2);
		((Control)topLine).TabIndex = 6;
		((Control)topLine).Text = "lineFrame1";
		((Control)bottomLine).Anchor = (AnchorStyles)14;
		((Control)bottomLine).Location = new Point(0, 316);
		((Control)bottomLine).Name = "bottomLine";
		((Control)bottomLine).Size = new Size(488, 2);
		((Control)bottomLine).TabIndex = 5;
		((Control)bottomLine).Text = "lineFrame2";
		((Control)cancel).Anchor = (AnchorStyles)10;
		((Control)cancel).CausesValidation = false;
		cancel.DialogResult = (DialogResult)2;
		((Control)cancel).Location = new Point(400, 324);
		((Control)cancel).Name = "cancel";
		((Control)cancel).Size = new Size(75, 23);
		((Control)cancel).TabIndex = 2;
		((Control)cancel).Text = "Cancel";
		((Control)cancel).Click += cancel_Click;
		((Control)back).Anchor = (AnchorStyles)10;
		((Control)back).CausesValidation = false;
		((Control)back).Location = new Point(144, 324);
		((Control)back).Name = "back";
		((Control)back).Size = new Size(75, 23);
		((Control)back).TabIndex = 3;
		((Control)back).Text = "< Back";
		((Control)back).Click += back_Click;
		((Control)next).Anchor = (AnchorStyles)10;
		((Control)next).Location = new Point(224, 324);
		((Control)next).Name = "next";
		((Control)next).Size = new Size(75, 23);
		((Control)next).TabIndex = 0;
		((Control)next).Text = "Next >";
		((Control)next).Click += next_Click;
		((Control)panelStep).Anchor = (AnchorStyles)15;
		((Control)panelStep).Location = new Point(8, 72);
		((Control)panelStep).Name = "panelStep";
		((Control)panelStep).Size = new Size(472, 236);
		((Control)panelStep).TabIndex = 4;
		((Control)finish).Anchor = (AnchorStyles)10;
		((Control)finish).Location = new Point(312, 324);
		((Control)finish).Name = "finish";
		((Control)finish).Size = new Size(75, 23);
		((Control)finish).TabIndex = 1;
		((Control)finish).Text = "Finish";
		((Control)finish).Click += finish_Click;
		((Form)this).AcceptButton = (IButtonControl)(object)finish;
		((Form)this).AutoScaleBaseSize = new Size(5, 13);
		((Form)this).CancelButton = (IButtonControl)(object)cancel;
		((Form)this).ClientSize = new Size(488, 355);
		((Control)this).Controls.Add((Control)(object)finish);
		((Control)this).Controls.Add((Control)(object)panelStep);
		((Control)this).Controls.Add((Control)(object)next);
		((Control)this).Controls.Add((Control)(object)back);
		((Control)this).Controls.Add((Control)(object)cancel);
		((Control)this).Controls.Add((Control)(object)bottomLine);
		((Control)this).Controls.Add((Control)(object)topLine);
		((Control)this).Controls.Add((Control)(object)wizardTop);
		((Form)this).FormBorderStyle = (FormBorderStyle)1;
		((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
		((Form)this).MaximizeBox = false;
		((Form)this).MinimizeBox = false;
		((Control)this).MinimumSize = new Size(304, 232);
		((Control)this).Name = "BaseWizard";
		((Form)this).ShowInTaskbar = false;
		((Form)this).StartPosition = (FormStartPosition)4;
		((Control)this).Text = "Wizard Title";
		((Form)this).Load += BaseWizard_Load;
		((Control)wizardTop).ResumeLayout(false);
		((Control)wizardTop).PerformLayout();
		((ISupportInitialize)wizardLogo).EndInit();
		((Control)this).ResumeLayout(false);
	}

	public virtual void MoveNext()
	{
		if (currentStep != null)
		{
			SetCurrentStep(currentStep.NextStep, CurrentStepNumber + 1);
		}
	}

	public virtual void MoveBack()
	{
		if (currentStep != null)
		{
			SetCurrentStep(currentStep.PreviousStep, CurrentStepNumber - 1);
		}
	}

	public virtual void MoveTo(string step, int stepNumber)
	{
		SetCurrentStep(step, stepNumber);
	}

	public virtual void AddStep(string name, BaseStep step)
	{
		Steps[name] = step;
		((Control)stepInfo).Text = $"Step {currentStepNumber} of {steps.Count}";
	}

	public virtual BaseStep GetStep(string name)
	{
		return Steps[name];
	}

	public virtual BaseStep RemoveStep(string name)
	{
		BaseStep baseStep = Steps[name];
		if (baseStep != null)
		{
			Steps.Remove(name);
			((Control)stepInfo).Text = $"Step {currentStepNumber} of {steps.Count}";
		}
		return baseStep;
	}

	public virtual void ResetSteps()
	{
		WizardStepDictionary.WizardStepDictionaryEnumerator enumerator = Steps.GetEnumerator();
		while (enumerator.MoveNext())
		{
			enumerator.Value.FireResetStepEvent();
		}
	}

	public virtual void SetCurrentStep(string name, int stepNumber)
	{
		if (name == null || name == "")
		{
			throw new ArgumentException("Step is null or empty", "step");
		}
		BaseStep baseStep = steps[name];
		if (baseStep == null)
		{
			throw new ArgumentException("Step does not contain the name of a step in the wizard", "name");
		}
		CurrentStepNumber = stepNumber;
		SetCurrentStep(baseStep);
	}

	protected virtual void SetCurrentStep(BaseStep step)
	{
		((Control)this).SuspendLayout();
		if (currentStep != null)
		{
			DetatchStep();
		}
		currentStep = step;
		AttachStep();
		((Control)this).ResumeLayout(true);
		((Control)step).Focus();
	}

	private void DetatchStep()
	{
		currentStep.StepTitleChanged -= OnStepTitleChanged;
		currentStep.NextStepChanged -= OnNextStepChanged;
		currentStep.PreviousStepChanged -= OnPreviousStepChanged;
		((Control)panelStep).Controls.Remove((Control)(object)currentStep);
		currentStep.Wizard = null;
	}

	private void AttachStep()
	{
		currentStep.Wizard = this;
		currentStep.StepTitleChanged += OnStepTitleChanged;
		currentStep.NextStepChanged += OnNextStepChanged;
		currentStep.PreviousStepChanged += OnPreviousStepChanged;
		OnStepTitleChanged(null, EventArgs.Empty);
		((Control)panelStep).Controls.Add((Control)(object)currentStep);
		OnPreviousStepChanged(null, EventArgs.Empty);
		OnNextStepChanged(null, EventArgs.Empty);
		currentStep.FireShowEvent();
	}

	private void OnStepTitleChanged(object o, EventArgs e)
	{
		Title = currentStep.StepTitle;
		Label obj = stepInfo;
		((Control)obj).Text = ((Control)obj).Text + " : " + currentStep.Description;
	}

	private void back_Click(object sender, EventArgs e)
	{
		OnBackClicked(EventArgs.Empty);
	}

	private void next_Click(object sender, EventArgs e)
	{
		OnNextClicked(EventArgs.Empty);
	}

	private void cancel_Click(object sender, EventArgs e)
	{
		((Form)this).DialogResult = (DialogResult)2;
		if (!((Form)this).Modal)
		{
			((Form)this).Close();
		}
	}

	private void finish_Click(object sender, EventArgs e)
	{
		OnFinishClicked(EventArgs.Empty);
	}

	protected override void OnLoad(EventArgs e)
	{
		((Form)this).OnLoad(e);
		if (!((Component)this).DesignMode)
		{
			OnLoadSteps(EventArgs.Empty);
			if (FirstStepName == "")
			{
				throw new InvalidOperationException("FirstStepName must be be a non-empty string.");
			}
			ResetSteps();
			SetCurrentStep(FirstStepName, 1);
		}
	}

	protected override void OnClosing(CancelEventArgs e)
	{
		switch (AllowClose)
		{
		case AllowClose.AskIfNotFinish:
			if (!FinishEnabled)
			{
				e.Cancel = !AskToClose();
			}
			break;
		case AllowClose.Ask:
			e.Cancel = !AskToClose();
			break;
		}
	}

	private bool AskToClose()
	{
		//IL_000d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0012: Unknown result type (might be due to invalid IL or missing references)
		//IL_0013: Unknown result type (might be due to invalid IL or missing references)
		//IL_0015: Invalid comparison between Unknown and I4
		DialogResult val = MessageBox.Show("Do you wish to quit the wizard now?\r\nYour changes won't be saved if you do", "Exit wizard?", (MessageBoxButtons)4, (MessageBoxIcon)32);
		if ((int)val == 6)
		{
			return true;
		}
		return false;
	}

	private void OnPreviousStepChanged(object sender, EventArgs e)
	{
		if (currentStep.PreviousStep == "")
		{
			BackEnabled = false;
		}
		else
		{
			BackEnabled = true;
		}
	}

	private void OnNextStepChanged(object sender, EventArgs e)
	{
		if (currentStep.NextStep == "")
		{
			NextEnabled = false;
		}
		else if (currentStep.NextStep == BaseStep.FinishStep)
		{
			NextEnabled = false;
			FinishEnabled = true;
		}
		else
		{
			NextEnabled = true;
		}
	}

	protected virtual void OnBackClicked(EventArgs e)
	{
		((EventHandler)((Component)this).Events[backClicked])?.Invoke(this, e);
	}

	protected virtual void OnNextClicked(EventArgs e)
	{
		((EventHandler)((Component)this).Events[nextClicked])?.Invoke(this, e);
	}

	protected virtual void OnFinishClicked(EventArgs e)
	{
		((EventHandler)((Component)this).Events[finishClicked])?.Invoke(this, e);
	}

	protected virtual void OnLoadSteps(EventArgs e)
	{
		((EventHandler)((Component)this).Events[loadSteps])?.Invoke(this, e);
	}

	private void BaseWizard_Load(object sender, EventArgs e)
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_0007: Expected O, but got Unknown
		UIPermission val = new UIPermission((UIPermissionWindow)3);
		((CodeAccessPermission)val).Demand();
	}
}
public class WizardStepDictionary : IDictionary, ICollection, IEnumerable, ICloneable
{
	public class WizardStepDictionaryEnumerator : IDictionaryEnumerator, IEnumerator
	{
		private IDictionaryEnumerator innerEnumerator;

		public string Key => (string)innerEnumerator.Key;

		object IDictionaryEnumerator.Key => Key;

		public BaseStep Value => (BaseStep)innerEnumerator.Value;

		object IDictionaryEnumerator.Value => Value;

		public DictionaryEntry Entry => innerEnumerator.Entry;

		object IEnumerator.Current => innerEnumerator.Current;

		public DictionaryEntry Current => Entry;

		internal WizardStepDictionaryEnumerator(WizardStepDictionary enumerable)
		{
			innerEnumerator = enumerable.innerHash.GetEnumerator();
		}

		public void Reset()
		{
			innerEnumerator.Reset();
		}

		public bool MoveNext()
		{
			return innerEnumerator.MoveNext();
		}
	}

	protected Hashtable innerHash;

	public bool IsReadOnly => innerHash.IsReadOnly;

	public BaseStep this[string key]
	{
		get
		{
			return (BaseStep)innerHash[key];
		}
		set
		{
			innerHash[key] = value;
		}
	}

	object IDictionary.this[object key]
	{
		get
		{
			return this[(string)key];
		}
		set
		{
			this[(string)key] = (BaseStep)value;
		}
	}

	public ICollection Values => innerHash.Values;

	public ICollection Keys => innerHash.Keys;

	public bool IsFixedSize => innerHash.IsFixedSize;

	public bool IsSynchronized => innerHash.IsSynchronized;

	public int Count => innerHash.Count;

	public object SyncRoot => innerHash.SyncRoot;

	public WizardStepDictionary()
	{
		innerHash = new Hashtable();
	}

	public WizardStepDictionary(WizardStepDictionary original)
	{
		innerHash = new Hashtable(original.innerHash);
	}

	public WizardStepDictionary(IDictionary dictionary)
	{
		innerHash = new Hashtable(dictionary);
	}

	public WizardStepDictionary(int capacity)
	{
		innerHash = new Hashtable(capacity);
	}

	public WizardStepDictionaryEnumerator GetEnumerator()
	{
		return new WizardStepDictionaryEnumerator(this);
	}

	IDictionaryEnumerator IDictionary.GetEnumerator()
	{
		return new WizardStepDictionaryEnumerator(this);
	}

	IEnumerator IEnumerable.GetEnumerator()
	{
		return GetEnumerator();
	}

	public void Remove(string key)
	{
		innerHash.Remove(key);
	}

	void IDictionary.Remove(object key)
	{
		Remove((string)key);
	}

	public bool Contains(string key)
	{
		return innerHash.Contains(key);
	}

	bool IDictionary.Contains(object key)
	{
		return Contains((string)key);
	}

	public void Clear()
	{
		innerHash.Clear();
	}

	public void Add(string key, BaseStep value)
	{
		innerHash.Add(key, value);
	}

	void IDictionary.Add(object key, object value)
	{
		Add((string)key, (BaseStep)value);
	}

	public void CopyTo(Array array, int index)
	{
		innerHash.CopyTo(array, index);
	}

	public void CopyTo(WizardStepDictionary wsc, int index)
	{
		IEnumerator enumerator = Keys.GetEnumerator();
		IEnumerator enumerator2 = Values.GetEnumerator();
		int count = Count;
		for (int i = 0; i < index; i++)
		{
			enumerator.MoveNext();
			enumerator2.MoveNext();
		}
		for (int j = index; j < count; j++)
		{
			enumerator.MoveNext();
			enumerator2.MoveNext();
			wsc.Add(enumerator.Current as string, enumerator2.Current as BaseStep);
		}
	}

	public WizardStepDictionary Clone()
	{
		WizardStepDictionary wizardStepDictionary = new WizardStepDictionary();
		wizardStepDictionary.innerHash = (Hashtable)innerHash.Clone();
		return wizardStepDictionary;
	}

	object ICloneable.Clone()
	{
		return Clone();
	}

	public bool ContainsKey(string key)
	{
		return innerHash.ContainsKey(key);
	}

	public bool ContainsValue(BaseStep value)
	{
		return innerHash.ContainsValue(value);
	}

	public WizardStepDictionary Synchronized()
	{
		WizardStepDictionary wizardStepDictionary = new WizardStepDictionary();
		wizardStepDictionary.innerHash = Hashtable.Synchronized(innerHash);
		return wizardStepDictionary;
	}
}
public class LineFrame : Control
{
	[DefaultValue(typeof(Size), "75, 2")]
	protected Size Size
	{
		get
		{
			return ((Control)this).Size;
		}
		set
		{
			((Control)this).Size = value;
		}
	}

	[Description("Gets/Sets the width of the line")]
	[Browsable(true)]
	[Category("Layout")]
	public int Width
	{
		get
		{
			return Size.Width;
		}
		set
		{
			Size = new Size(value, 2);
		}
	}

	protected override void OnPaint(PaintEventArgs pe)
	{
		//IL_001b: Unknown result type (might be due to invalid IL or missing references)
		//IL_0021: Expected O, but got Unknown
		Graphics graphics = pe.Graphics;
		Pen val = new Pen(Color.FromArgb(128, 128, 128));
		try
		{
			graphics.DrawLine(val, new Point(0, 0), new Point(Width, 0));
		}
		finally
		{
			((IDisposable)val)?.Dispose();
		}
		graphics.DrawLine(Pens.White, new Point(0, 1), new Point(Width, 1));
		((Control)this).OnPaint(pe);
	}
}
