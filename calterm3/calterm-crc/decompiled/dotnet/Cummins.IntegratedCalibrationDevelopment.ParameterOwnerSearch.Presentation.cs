using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using Cummins.IntegratedCalibrationDevelopment.ExtensionMethods;

[assembly: AssemblyProduct("Cummins.IntegratedCalibrationDevelopment.ParameterOwnerSearch")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyTitle("Cummins.IntegratedCalibrationDevelopment.ParameterOwnerSearch.Presentation")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 2012")]
[assembly: AssemblyTrademark("")]
[assembly: CLSCompliant(true)]
[assembly: ComVisible(false)]
[assembly: ThemeInfo(/*Could not decode attribute arguments.*/)]
[assembly: AssemblyFileVersion("1.0.0.4")]
[assembly: NeutralResourcesLanguage("en-US")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyVersion("1.0.0.4")]
namespace Cummins.IntegratedCalibrationDevelopment.ParameterOwnerSearch;

internal enum SortButtonType
{
	Name,
	Location,
	Program
}
public class TunerDetails : UserControl, IComponentConnector
{
	internal Popup TunerCardpopup;

	internal TextBox NameTextBox;

	internal TextBox TitleTextBox;

	internal TextBox EmailTextBox;

	internal TextBox WWIdTextBox;

	internal TextBox PhoneTextBox;

	internal TextBox LocationTextBox;

	private bool _contentLoaded;

	public TunerDetails(string wwId)
	{
		InitializeComponent();
		WWIdTextBox.Text = wwId;
		NameTextBox.Text = RatingSearch.GetUserInformation(InformationType.Name, wwId);
		EmailTextBox.Text = wwId + en_us.AtCumminsDotCom;
		string userInformation = RatingSearch.GetUserInformation(InformationType.Title, wwId);
		TitleTextBox.Text = (string.IsNullOrEmpty(userInformation) ? en_us.NoValuePresent : userInformation);
		string userInformation2 = RatingSearch.GetUserInformation(InformationType.PhoneNumber, wwId);
		PhoneTextBox.Text = (string.IsNullOrEmpty(userInformation2) ? en_us.NoValuePresent : userInformation2);
		string userInformation3 = RatingSearch.GetUserInformation(InformationType.Location, wwId);
		LocationTextBox.Text = (string.IsNullOrEmpty(userInformation3) ? en_us.NoValuePresent : userInformation3);
	}

	[DebuggerNonUserCode]
	public void InitializeComponent()
	{
		if (!_contentLoaded)
		{
			_contentLoaded = true;
			Uri uri = new Uri("/Cummins.IntegratedCalibrationDevelopment.ParameterOwnerSearch.Presentation;component/tunerdetails.xaml", UriKind.Relative);
			Application.LoadComponent((object)this, uri);
		}
	}

	[EditorBrowsable(EditorBrowsableState.Never)]
	[DebuggerNonUserCode]
	void IComponentConnector.Connect(int connectionId, object target)
	{
		//IL_002a: Unknown result type (might be due to invalid IL or missing references)
		//IL_0034: Expected O, but got Unknown
		//IL_0037: Unknown result type (might be due to invalid IL or missing references)
		//IL_0041: Expected O, but got Unknown
		//IL_0044: Unknown result type (might be due to invalid IL or missing references)
		//IL_004e: Expected O, but got Unknown
		//IL_0051: Unknown result type (might be due to invalid IL or missing references)
		//IL_005b: Expected O, but got Unknown
		//IL_005e: Unknown result type (might be due to invalid IL or missing references)
		//IL_0068: Expected O, but got Unknown
		//IL_006b: Unknown result type (might be due to invalid IL or missing references)
		//IL_0075: Expected O, but got Unknown
		//IL_0078: Unknown result type (might be due to invalid IL or missing references)
		//IL_0082: Expected O, but got Unknown
		switch (connectionId)
		{
		case 1:
			TunerCardpopup = (Popup)target;
			break;
		case 2:
			NameTextBox = (TextBox)target;
			break;
		case 3:
			TitleTextBox = (TextBox)target;
			break;
		case 4:
			EmailTextBox = (TextBox)target;
			break;
		case 5:
			WWIdTextBox = (TextBox)target;
			break;
		case 6:
			PhoneTextBox = (TextBox)target;
			break;
		case 7:
			LocationTextBox = (TextBox)target;
			break;
		default:
			_contentLoaded = true;
			break;
		}
	}
}
public class ParameterOwnerSearchWindow : Window, IComponentConnector
{
	private class ErrorMessageSync : IErrorObserver
	{
		private ParameterOwnerSearchWindow _parent;

		public ErrorMessageSync(ParameterOwnerSearchWindow parent)
		{
			_parent = parent;
		}

		public void Update(string message)
		{
			_parent.ErrorMessageLabel.Text = message;
			_parent.ErrorMessageToopTip.Text = message;
		}
	}

	private ErrorMessageSync _errorMessageSync;

	private static bool _isInitializationCompleted;

	private Button _buttonChat;

	private string _previousParameter;

	private bool _close;

	internal Border MainBorder;

	internal Grid MainGrid;

	internal Button ChatSource;

	internal Button EmailSource;

	internal Button ContactSource;

	internal Button SortByName;

	internal ToolTip SortByNameToolTip;

	internal Button SortByLocation;

	internal Button SortByProgram;

	internal ListBox MainListBox;

	internal TextBlock ErrorMessageLabel;

	internal TextBlock ErrorMessageToopTip;

	private bool _contentLoaded;

	private void SortByNameEventHandler(object sender, RoutedEventArgs e)
	{
		if (RatingSearch.OwnersSortedByName == null || RatingSearch.OwnersSortedByName.Count() == 0)
		{
			return;
		}
		RatingSearch.ApplicationErrorState.ClearError();
		((ItemsControl)MainListBox).Items.Clear();
		foreach (string item in RatingSearch.OwnersSortedByName)
		{
			((ItemsControl)MainListBox).Items.Add((object)AddNewParameterOwner(item));
		}
		SetControlsAfterSort(SortButtonType.Name);
	}

	private void SortByLocationEventHandler(object sender, EventArgs e)
	{
		if (RatingSearch.OwnersSortedByName == null || RatingSearch.OwnersSortedByName.Count() == 0)
		{
			return;
		}
		IEnumerable<string> enumerable = RatingSearch.SearchOwnersByLocation();
		if (enumerable == null || enumerable.Count() == 0)
		{
			return;
		}
		RatingSearch.ApplicationErrorState.ClearError();
		((ItemsControl)MainListBox).Items.Clear();
		string text = string.Empty;
		foreach (string item in enumerable)
		{
			string userInformation = RatingSearch.GetUserInformation(InformationType.Location, item);
			if (text != userInformation)
			{
				((ItemsControl)MainListBox).Items.Add((object)AddNewHeader(userInformation));
				text = userInformation;
			}
			((ItemsControl)MainListBox).Items.Add((object)AddNewParameterOwner(item));
		}
		SetControlsAfterSort(SortButtonType.Location);
	}

	private void SortByProgramEventHandler(object sender, EventArgs e)
	{
		//IL_004c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0052: Expected O, but got Unknown
		//IL_00cc: Unknown result type (might be due to invalid IL or missing references)
		//IL_00d3: Expected O, but got Unknown
		//IL_0127: Unknown result type (might be due to invalid IL or missing references)
		//IL_013a: Unknown result type (might be due to invalid IL or missing references)
		//IL_0141: Expected O, but got Unknown
		//IL_0167: Unknown result type (might be due to invalid IL or missing references)
		//IL_019f: Unknown result type (might be due to invalid IL or missing references)
		//IL_01a5: Expected O, but got Unknown
		//IL_01d6: Unknown result type (might be due to invalid IL or missing references)
		//IL_01dd: Expected O, but got Unknown
		//IL_0203: Unknown result type (might be due to invalid IL or missing references)
		if (RatingSearch.OwnersSortedByName == null || RatingSearch.OwnersSortedByName.Count() == 0)
		{
			return;
		}
		IEnumerable<string[]> enumerable = RatingSearch.SearchOwnersByProgram();
		if (enumerable == null || enumerable.Count() == 0)
		{
			return;
		}
		RatingSearch.ApplicationErrorState.ClearError();
		((ItemsControl)MainListBox).Items.Clear();
		string text = string.Empty;
		string text2 = string.Empty;
		StackPanel val = new StackPanel();
		foreach (string[] item in enumerable)
		{
			string text3 = item[0];
			string text4 = item[1];
			string text5 = item[2];
			if (RatingSearch.OwnersSortedByName.Contains(text4))
			{
				string text6 = text3;
				if (text != text6)
				{
					((ItemsControl)MainListBox).Items.Add((object)AddNewHeader(text6));
					text = text6;
					text2 = string.Empty;
				}
				string text7 = text4;
				if (text2 != text7)
				{
					Expander val2 = new Expander();
					((Control)val2).BorderBrush = (Brush)(object)Brushes.Transparent;
					((Control)val2).Background = (Brush)(object)Brushes.White;
					val2.IsExpanded = false;
					Expander val3 = val2;
					DockPanel val4 = AddNewParameterOwner(text4);
					((FrameworkElement)val4).Margin = new Thickness(0.0, 0.0, 0.0, 0.0);
					((HeaderedContentControl)val3).Header = val4;
					TextBox val5 = new TextBox();
					((FrameworkElement)val5).Margin = new Thickness(25.0, 0.0, 0.0, 0.0);
					val5.Text = text5;
					((Control)val5).FontSize = 13.0;
					TextBox val6 = val5;
					((FrameworkElement)val6).SetResourceReference(FrameworkElement.StyleProperty, (object)"ReadOnlyTextStyle");
					val = new StackPanel();
					((Panel)val).Children.Add((UIElement)(object)val6);
					((ContentControl)val3).Content = val;
					((ItemsControl)MainListBox).Items.Add((object)val3);
					text2 = text7;
				}
				else if (val != null)
				{
					TextBox val7 = new TextBox();
					((FrameworkElement)val7).Margin = new Thickness(25.0, 0.0, 0.0, 0.0);
					val7.Text = text5;
					((Control)val7).FontSize = 13.0;
					TextBox val8 = val7;
					((FrameworkElement)val8).SetResourceReference(FrameworkElement.StyleProperty, (object)"ReadOnlyTextStyle");
					((Panel)val).Children.Add((UIElement)(object)val8);
				}
			}
		}
		SetControlsAfterSort(SortButtonType.Program);
	}

	private void PopUpTheChatEventHandler(object sender, EventArgs e)
	{
		Mouse.OverrideCursor = Cursors.Wait;
		RatingSearch.ApplicationErrorState.ClearError();
		string wwId = ((ContentControl)((sender is Button) ? sender : null)).Content.ToString();
		RatingSearch.OpenChatWindow(wwId);
		Mouse.OverrideCursor = null;
	}

	private void PopUpTheEmailEventHandler(object sender, EventArgs e)
	{
		string email = ((ContentControl)((sender is Button) ? sender : null)).Content.ToString();
		RatingSearch.ApplicationErrorState.ClearError();
		RatingSearch.CreateMailDraft(email);
	}

	private void PopUpTheContactCardHandler(object sender, EventArgs e)
	{
		RatingSearch.ApplicationErrorState.ClearError();
		string wwId = ((ContentControl)((sender is Button) ? sender : null)).Content.ToString();
		TunerDetails tunerDetails = new TunerDetails(wwId);
		tunerDetails.TunerCardpopup.IsOpen = true;
		tunerDetails.TunerCardpopup.StaysOpen = false;
	}

	private void OnClosing(object sender, CancelEventArgs e)
	{
		if (!_close)
		{
			e.Cancel = true;
			((UIElement)this).Visibility = (Visibility)1;
			((Window)this).Hide();
		}
	}

	public ParameterOwnerSearchWindow()
	{
		InitializeComponent();
		((UIElement)this).Visibility = (Visibility)1;
		((Window)this).Hide();
		_errorMessageSync = new ErrorMessageSync(this);
		RatingSearch.ApplicationErrorState.Attach(_errorMessageSync);
	}

	public void Initialize()
	{
		RatingSearch.Initialize();
		_isInitializationCompleted = true;
	}

	public void ShowOwners(string parameterName, string userId)
	{
		if (!parameterName.IsNullOrEmptyOrWhiteSpace())
		{
			parameterName = parameterName.Trim();
		}
		RatingSearch.ApplicationErrorState.ClearError();
		if (!_isInitializationCompleted)
		{
			return;
		}
		if (string.Compare(_previousParameter, parameterName, StringComparison.CurrentCulture) != 0)
		{
			((ItemsControl)MainListBox).Items.Clear();
			IEnumerable<string> enumerable = RatingSearch.SearchOwnersByName(parameterName, userId);
			if (enumerable != null && enumerable.Count() > 0)
			{
				foreach (string item in enumerable)
				{
					((ItemsControl)MainListBox).Items.Add((object)AddNewParameterOwner(item));
				}
			}
			_previousParameter = parameterName;
		}
		SetControlsAfterSort(SortButtonType.Name);
		((UIElement)this).Visibility = (Visibility)0;
		((Window)this).Show();
	}

	public void Deinitialize()
	{
		_close = true;
		((Window)this).Close();
	}

	private DockPanel AddNewParameterOwner(string wwId)
	{
		//IL_0000: Unknown result type (might be due to invalid IL or missing references)
		//IL_0007: Expected O, but got Unknown
		//IL_002d: Unknown result type (might be due to invalid IL or missing references)
		//IL_003a: Unknown result type (might be due to invalid IL or missing references)
		//IL_0041: Expected O, but got Unknown
		//IL_0085: Unknown result type (might be due to invalid IL or missing references)
		//IL_00c7: Unknown result type (might be due to invalid IL or missing references)
		//IL_00ce: Expected O, but got Unknown
		//IL_0116: Unknown result type (might be due to invalid IL or missing references)
		//IL_0149: Unknown result type (might be due to invalid IL or missing references)
		//IL_0153: Expected O, but got Unknown
		//IL_0171: Unknown result type (might be due to invalid IL or missing references)
		//IL_0178: Expected O, but got Unknown
		//IL_01c0: Unknown result type (might be due to invalid IL or missing references)
		//IL_01e5: Unknown result type (might be due to invalid IL or missing references)
		//IL_01ef: Expected O, but got Unknown
		//IL_0203: Unknown result type (might be due to invalid IL or missing references)
		//IL_020a: Expected O, but got Unknown
		//IL_0252: Unknown result type (might be due to invalid IL or missing references)
		//IL_0277: Unknown result type (might be due to invalid IL or missing references)
		//IL_0281: Expected O, but got Unknown
		DockPanel val = new DockPanel();
		((FrameworkElement)val).Margin = new Thickness(15.0, 0.0, 0.0, 0.0);
		DockPanel val2 = val;
		TextBox val3 = new TextBox();
		val3.Text = RatingSearch.GetUserInformation(InformationType.Name, wwId);
		((FrameworkElement)val3).Width = 160.0;
		((FrameworkElement)val3).Margin = new Thickness(0.0, 5.0, 0.0, 0.0);
		((Control)val3).FontSize = 14.0;
		TextBox val4 = val3;
		((FrameworkElement)val4).SetResourceReference(FrameworkElement.StyleProperty, (object)"ReadOnlyTextStyle");
		((Panel)val2).Children.Add((UIElement)(object)val4);
		DockPanel.SetDock((UIElement)(object)val4, (Dock)0);
		Button val5 = new Button();
		((ContentControl)val5).Content = wwId;
		((FrameworkElement)val5).HorizontalAlignment = (HorizontalAlignment)2;
		((Control)val5).Background = ((Control)ChatSource).Background;
		((FrameworkElement)val5).Margin = new Thickness(0.0, 0.0, 10.0, 0.0);
		_buttonChat = val5;
		((FrameworkElement)_buttonChat).SetResourceReference(FrameworkElement.StyleProperty, (object)"GridButtonStyle");
		((ButtonBase)_buttonChat).Click += new RoutedEventHandler(PopUpTheChatEventHandler);
		((Panel)val2).Children.Add((UIElement)(object)_buttonChat);
		DockPanel.SetDock((UIElement)(object)_buttonChat, (Dock)0);
		Button val6 = new Button();
		((ContentControl)val6).Content = wwId;
		((FrameworkElement)val6).HorizontalAlignment = (HorizontalAlignment)2;
		((Control)val6).Background = ((Control)EmailSource).Background;
		((FrameworkElement)val6).Margin = new Thickness(0.0, 0.0, 10.0, 0.0);
		Button val7 = val6;
		((FrameworkElement)val7).SetResourceReference(FrameworkElement.StyleProperty, (object)"GridButtonStyle");
		((ButtonBase)val7).Click += new RoutedEventHandler(PopUpTheEmailEventHandler);
		((Panel)val2).Children.Add((UIElement)(object)val7);
		DockPanel.SetDock((UIElement)(object)val7, (Dock)0);
		Button val8 = new Button();
		((ContentControl)val8).Content = wwId;
		((FrameworkElement)val8).HorizontalAlignment = (HorizontalAlignment)2;
		((Control)val8).Background = ((Control)ContactSource).Background;
		((FrameworkElement)val8).Margin = new Thickness(0.0, 0.0, 10.0, 0.0);
		Button val9 = val8;
		((FrameworkElement)val9).SetResourceReference(FrameworkElement.StyleProperty, (object)"GridButtonStyle");
		((ButtonBase)val9).Click += new RoutedEventHandler(PopUpTheContactCardHandler);
		((Panel)val2).Children.Add((UIElement)(object)val9);
		DockPanel.SetDock((UIElement)(object)val9, (Dock)0);
		return val2;
	}

	private StackPanel AddNewHeader(string displayItem)
	{
		//IL_0000: Unknown result type (might be due to invalid IL or missing references)
		//IL_0006: Expected O, but got Unknown
		//IL_0028: Unknown result type (might be due to invalid IL or missing references)
		//IL_004f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0055: Expected O, but got Unknown
		//IL_007d: Unknown result type (might be due to invalid IL or missing references)
		StackPanel val = new StackPanel();
		val.Orientation = (Orientation)0;
		((Panel)val).Background = ((Control)SortByNameToolTip).Background;
		((FrameworkElement)val).Margin = new Thickness(0.0);
		((FrameworkElement)val).Width = ((FrameworkElement)MainGrid).Width - 25.0;
		StackPanel val2 = val;
		TextBox val3 = new TextBox();
		val3.Text = displayItem;
		((Control)val3).FontSize = 14.0;
		((Control)val3).Background = ((Control)SortByNameToolTip).Background;
		((Control)val3).FontWeight = FontWeights.Bold;
		TextBox val4 = val3;
		((FrameworkElement)val4).SetResourceReference(FrameworkElement.StyleProperty, (object)"ReadOnlyTextStyle");
		((Panel)val2).Children.Add((UIElement)(object)val4);
		return val2;
	}

	private void SetControlsAfterSort(SortButtonType button)
	{
		((ButtonBase)SortByName).ClickMode = (ClickMode)0;
		((ButtonBase)SortByLocation).ClickMode = (ClickMode)0;
		((ButtonBase)SortByProgram).ClickMode = (ClickMode)0;
		switch (button)
		{
		case SortButtonType.Location:
			((ButtonBase)SortByLocation).ClickMode = (ClickMode)1;
			break;
		case SortButtonType.Program:
			((ButtonBase)SortByProgram).ClickMode = (ClickMode)1;
			break;
		default:
			((ButtonBase)SortByName).ClickMode = (ClickMode)1;
			break;
		}
		if (((CollectionView)((ItemsControl)MainListBox).Items).Count > 0)
		{
			MainListBox.ScrollIntoView(((ItemsControl)MainListBox).Items[0]);
		}
	}

	[DebuggerNonUserCode]
	public void InitializeComponent()
	{
		if (!_contentLoaded)
		{
			_contentLoaded = true;
			Uri uri = new Uri("/Cummins.IntegratedCalibrationDevelopment.ParameterOwnerSearch.Presentation;component/parameterownersearchwindow.xaml", UriKind.Relative);
			Application.LoadComponent((object)this, uri);
		}
	}

	[DebuggerNonUserCode]
	[EditorBrowsable(EditorBrowsableState.Never)]
	void IComponentConnector.Connect(int connectionId, object target)
	{
		//IL_005d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0067: Expected O, but got Unknown
		//IL_006a: Unknown result type (might be due to invalid IL or missing references)
		//IL_0074: Expected O, but got Unknown
		//IL_0077: Unknown result type (might be due to invalid IL or missing references)
		//IL_0081: Expected O, but got Unknown
		//IL_0084: Unknown result type (might be due to invalid IL or missing references)
		//IL_008e: Expected O, but got Unknown
		//IL_0091: Unknown result type (might be due to invalid IL or missing references)
		//IL_009b: Expected O, but got Unknown
		//IL_009e: Unknown result type (might be due to invalid IL or missing references)
		//IL_00a8: Expected O, but got Unknown
		//IL_00b5: Unknown result type (might be due to invalid IL or missing references)
		//IL_00bf: Expected O, but got Unknown
		//IL_00c2: Unknown result type (might be due to invalid IL or missing references)
		//IL_00cc: Expected O, but got Unknown
		//IL_00cf: Unknown result type (might be due to invalid IL or missing references)
		//IL_00d9: Expected O, but got Unknown
		//IL_00e6: Unknown result type (might be due to invalid IL or missing references)
		//IL_00f0: Expected O, but got Unknown
		//IL_00f3: Unknown result type (might be due to invalid IL or missing references)
		//IL_00fd: Expected O, but got Unknown
		//IL_010a: Unknown result type (might be due to invalid IL or missing references)
		//IL_0114: Expected O, but got Unknown
		//IL_0117: Unknown result type (might be due to invalid IL or missing references)
		//IL_0121: Expected O, but got Unknown
		//IL_0124: Unknown result type (might be due to invalid IL or missing references)
		//IL_012e: Expected O, but got Unknown
		//IL_0131: Unknown result type (might be due to invalid IL or missing references)
		//IL_013b: Expected O, but got Unknown
		switch (connectionId)
		{
		case 1:
			((Window)(ParameterOwnerSearchWindow)target).Closing += OnClosing;
			break;
		case 2:
			MainBorder = (Border)target;
			break;
		case 3:
			MainGrid = (Grid)target;
			break;
		case 4:
			ChatSource = (Button)target;
			break;
		case 5:
			EmailSource = (Button)target;
			break;
		case 6:
			ContactSource = (Button)target;
			break;
		case 7:
			SortByName = (Button)target;
			((ButtonBase)SortByName).Click += new RoutedEventHandler(SortByNameEventHandler);
			break;
		case 8:
			SortByNameToolTip = (ToolTip)target;
			break;
		case 9:
			SortByLocation = (Button)target;
			((ButtonBase)SortByLocation).Click += new RoutedEventHandler(SortByLocationEventHandler);
			break;
		case 10:
			SortByProgram = (Button)target;
			((ButtonBase)SortByProgram).Click += new RoutedEventHandler(SortByProgramEventHandler);
			break;
		case 11:
			MainListBox = (ListBox)target;
			break;
		case 12:
			ErrorMessageLabel = (TextBlock)target;
			break;
		case 13:
			ErrorMessageToopTip = (TextBlock)target;
			break;
		default:
			_contentLoaded = true;
			break;
		}
	}
}
public class POSW
{
	private ParameterOwnerSearchWindow _parameterOwnerSearchWindow;

	public POSW()
	{
		_parameterOwnerSearchWindow = new ParameterOwnerSearchWindow();
	}

	public void ShowOwner(string parameterName, string userId)
	{
		_parameterOwnerSearchWindow.ShowOwners(parameterName, userId);
	}
}
