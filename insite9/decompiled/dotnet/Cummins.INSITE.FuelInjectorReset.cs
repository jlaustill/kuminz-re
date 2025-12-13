using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;
using System.Threading;
using System.Windows.Forms;
using ADDINFACTORYAPILib;
using CONMANAPILib;
using Cummins.INSITE.CNL.Errors;
using Cummins.INSITE.CNL.Factory;
using Cummins.INSITE.CNL.Help;
using Cummins.INSITE.CNL.Localization;
using Cummins.INSITE.CNL.Security;
using Cummins.INSITE.CNL.SpecialFeatures;
using Cummins.INSITE.FuelInjectorReset.Properties;
using Cummins.INSITE.Kernel.ECMServicesAPI;
using ECMSERVICESAPILib;
using Evxw7Pb2BvVFUE67hx;
using GLTcrlwyLBJgfodYhN;
using HY7B9pTYMOWGVYCp6H;
using IBNhjJtZ2bZVfgIVV0;
using Qh3ylrhMbbhfCfymy0;
using ToolSecurityServicesAPILib;
using iPMkhH5DwB2Q8yWtoh;

[assembly: Guid("6d1cf513-d74d-41fe-8f25-d7e6dbbc866a")]
[assembly: ComVisible(true)]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyFileVersion("7.6.0.272")]
[assembly: SuppressIldasm]
[assembly: AssemblyKeyName("")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyProduct("FuelInjectorReset")]
[assembly: CompilationRelaxations(8)]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyCopyright("Copyright © Cummins Inc. 1997-2012")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Cummins Inc.")]
[assembly: AssemblyTitle("FuelInjectorReset")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyVersion("7.6.0.272")]
namespace w8gF7G9iyWktelrDBo
{
	internal static class KMuLwCGDxDAwBIMp1m
	{
	}
}
namespace Cummins.INSITE.FuelInjectorReset.Properties
{
	[CompilerGenerated]
	[GeneratedCode("System.Resources.Tools.StronglyTypedResourceBuilder", "2.0.0.0")]
	[DebuggerNonUserCode]
	internal class Resources
	{
		private static ResourceManager resourceMan;

		private static CultureInfo resourceCulture;

		[EditorBrowsable(EditorBrowsableState.Advanced)]
		internal static ResourceManager ResourceManager
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				if (object.ReferenceEquals(resourceMan, null))
				{
					ResourceManager resourceManager = new ResourceManager("Cummins.INSITE.FuelInjectorReset.Properties.Resources", typeof(Resources).Assembly);
					resourceMan = resourceManager;
				}
				return resourceMan;
			}
		}

		[EditorBrowsable(EditorBrowsableState.Advanced)]
		internal static CultureInfo Culture
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return resourceCulture;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				resourceCulture = value;
			}
		}

		internal static Bitmap adv_ecm_
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				//IL_0022: Unknown result type (might be due to invalid IL or missing references)
				//IL_0028: Expected O, but got Unknown
				object obj = ResourceManager.GetObject(ETZxusFl8KUvQCslGf.pasOtyYaWV(0), resourceCulture);
				return (Bitmap)obj;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal Resources()
		{
			IE3dyJf2OKPAA7hD1W.ugrjvXWz48stp();
			base..ctor();
		}
	}
}
namespace Cummins.INSITE.FuelInjectorReset
{
	public interface IFuelInjectorResetEvents
	{
		event EventHandler<FeatureStatusUpdatedEventArgs> FeatureStatusUpdated;
	}
	public interface IFuelInjectorResetHelper
	{
		FeatureSupportedStatus IsFeatureSupported();

		Thread ResetInjectors(List<int> selectedInjectors);
	}
	[Guid("9F01E0F9-F2B6-4b10-BF51-15BEE2411A50")]
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.None)]
	[ProgId("Cummins.FuelInjectorResetLogic.1")]
	public class FuelInjectorResetLogic : ECMPropertyPageHelper, IFuelInjectorResetHelper, IFuelInjectorResetEvents
	{
		private object OKwCY9PPI;

		private EventHandler<FeatureStatusUpdatedEventArgs> vAWkl4lyv;

		private EventHandler<M2hc0EeofuSLih1G95> M2kqUnDnI;

		private int hdrRTYZMB;

		private bool BTbTBmcL5;

		private int[] s7TNvgyue;

		public IAddInFactory addInFactory;

		public int TotalNumberOfInjectors
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return hdrRTYZMB;
			}
		}

		public bool IsDisposed
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return BTbTBmcL5;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				BTbTBmcL5 = value;
			}
		}

		public EventHandler<FeatureStatusUpdatedEventArgs> FeatureStatusUpdated
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return vAWkl4lyv;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				vAWkl4lyv = value;
			}
		}

		event EventHandler<FeatureStatusUpdatedEventArgs> IFuelInjectorResetEvents.FeatureStatusUpdated
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (OKwCY9PPI)
				{
					vAWkl4lyv = (EventHandler<FeatureStatusUpdatedEventArgs>)Delegate.Combine(vAWkl4lyv, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (OKwCY9PPI)
				{
					vAWkl4lyv = (EventHandler<FeatureStatusUpdatedEventArgs>)Delegate.Remove(vAWkl4lyv, value);
				}
			}
		}

		internal event EventHandler<M2hc0EeofuSLih1G95> tMxtx52Gm
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			add
			{
				lock (OKwCY9PPI)
				{
					M2kqUnDnI = (EventHandler<M2hc0EeofuSLih1G95>)Delegate.Combine(M2kqUnDnI, value);
				}
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			remove
			{
				lock (OKwCY9PPI)
				{
					M2kqUnDnI = (EventHandler<M2hc0EeofuSLih1G95>)Delegate.Remove(M2kqUnDnI, value);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FuelInjectorResetLogic()
		{
			IE3dyJf2OKPAA7hD1W.ugrjvXWz48stp();
			base..ctor();
			OKwCY9PPI = new object();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Init(string regKeyPath)
		{
			if (string.IsNullOrEmpty(regKeyPath))
			{
				throw new ArgumentNullException(regKeyPath);
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void UnLoad()
		{
			base.UnLoad();
			IsDisposed = true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		FeatureSupportedStatus IFuelInjectorResetHelper.IsFeatureSupported()
		{
			FeatureSupportedStatus result = FeatureSupportedStatus.False;
			try
			{
				ECMSERVICESAPILib.IParameter parameter = null;
				try
				{
					parameter = base.DataService.Read(ETZxusFl8KUvQCslGf.pasOtyYaWV(20), ReadTypesEnum.RT_Parameter) as ECMSERVICESAPILib.IParameter;
				}
				catch (COMException)
				{
					result = FeatureSupportedStatus.False;
				}
				if (parameter != null)
				{
					if (1 == Convert.ToInt32(parameter.RawValue))
					{
						result = FeatureSupportedStatus.True;
						hdrRTYZMB = ReadInjectorCount();
					}
					else
					{
						result = FeatureSupportedStatus.False;
					}
				}
			}
			catch (COMException)
			{
				result = FeatureSupportedStatus.False;
				pPC0eXv6C((hhKTSbP9bNVQw9TELG)47000);
			}
			return result;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		Thread IFuelInjectorResetHelper.ResetInjectors(List<int> selectedInjectors)
		{
			Thread thread = new Thread(oPhWaioO7);
			try
			{
				s7TNvgyue = new int[selectedInjectors.Count];
				selectedInjectors.CopyTo(s7TNvgyue);
				thread.Start(selectedInjectors);
			}
			catch (COMException)
			{
				thread = null;
			}
			return thread;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void oWkOm13b7(InjectorResetStatus P_0, int P_1)
		{
			vAWkl4lyv?.Invoke(this, new FeatureStatusUpdatedEventArgs(P_0, P_1));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void pPC0eXv6C(hhKTSbP9bNVQw9TELG P_0)
		{
			M2kqUnDnI?.Invoke(this, new M2hc0EeofuSLih1G95(P_0));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void WpJseP4lO(int P_0)
		{
			try
			{
				base.DataService.Write(ETZxusFl8KUvQCslGf.pasOtyYaWV(40), WriteTypesEnum.WT_Parameter, P_0);
			}
			catch (ECMServicesException ex)
			{
				_ = ex.Message;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void oPhWaioO7(object P_0)
		{
			int num = 0;
			bool flag = false;
			try
			{
				ConnectionTypesEnum type = base.DataService.Connection.type;
				if (ConnectionTypesEnum.CT_Physical == type)
				{
					foreach (int item in P_0 as List<int>)
					{
						try
						{
							WpJseP4lO(item - 1);
							ECMSERVICESAPILib.IParameter parameter = base.DataService.Read(ETZxusFl8KUvQCslGf.pasOtyYaWV(58), ReadTypesEnum.RT_Parameter) as ECMSERVICESAPILib.IParameter;
							num = int.Parse(parameter.RawValue.ToString());
						}
						catch (ECMServicesException ex)
						{
							ECMServicesErrorCodes errorCode = ex.ErrorCode;
							num = 65533;
							if (errorCode == ECMServicesErrorCodes.DatalinkError)
							{
								pPC0eXv6C((hhKTSbP9bNVQw9TELG)47001);
							}
							else
							{
								pPC0eXv6C((hhKTSbP9bNVQw9TELG)47000);
							}
						}
						catch (COMException)
						{
							pPC0eXv6C((hhKTSbP9bNVQw9TELG)47000);
						}
						if (num == 0)
						{
							oWkOm13b7(InjectorResetStatus.OperationSuccessful, item);
							flag = true;
						}
						else
						{
							oWkOm13b7(InjectorResetStatus.OperationFail, item);
						}
					}
				}
				else
				{
					flag = true;
					int[] array = s7TNvgyue;
					foreach (int num2 in array)
					{
						oWkOm13b7(InjectorResetStatus.OperationSuccessful, num2);
						Thread.Sleep(2000);
					}
				}
				if (flag)
				{
					ShowKeyOffMessage();
				}
				oWkOm13b7(InjectorResetStatus.OperationCompleted, 0);
			}
			catch (COMException)
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void ShowKeyOffMessage()
		{
			try
			{
				addInFactory = (IAddInFactory)base.Kernel;
				IConManWorker conManWorker = (IConManWorker)addInFactory.get_Item(ETZxusFl8KUvQCslGf.pasOtyYaWV(76));
				conManWorker.ShowKeyMessage(30);
			}
			catch (NullReferenceException)
			{
			}
			catch (COMException)
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public int ReadInjectorCount()
		{
			int result = 0;
			try
			{
				if (base.DataService.Read(ETZxusFl8KUvQCslGf.pasOtyYaWV(156), ReadTypesEnum.RT_Parameter) is ECMSERVICESAPILib.IParameter parameter)
				{
					result = Convert.ToInt32(parameter.RawValue);
				}
			}
			catch (COMException)
			{
				pPC0eXv6C((hhKTSbP9bNVQw9TELG)47000);
			}
			return result;
		}
	}
	[ProgId("Cummins.FuelInjectorResetPage.1")]
	[Guid("D4C15B1B-7BD1-41a3-85F7-21C09B74779C")]
	[ClassInterface(ClassInterfaceType.None)]
	[DesignerCategory("Form")]
	[ComVisible(true)]
	public sealed class FuelInjectorResetPage : ECMPropertyPage, IHelpInformation
	{
		[CompilerGenerated]
		private sealed class <>c__DisplayClass1
		{
			public FuelInjectorResetPage <>4__this;

			public FeatureStatusUpdatedEventArgs e;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass1()
			{
				IE3dyJf2OKPAA7hD1W.ugrjvXWz48stp();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <FeatureLogic_FeatureStatusUpdated>b__0()
			{
				switch (e.Status)
				{
				case InjectorResetStatus.OperationSuccessful:
					<>4__this.NExpettI9((OVo1ODCQZDlsFJm98u)22, e.InjectorNumber);
					break;
				case InjectorResetStatus.OperationFail:
					<>4__this.NExpettI9((OVo1ODCQZDlsFJm98u)24, e.InjectorNumber);
					break;
				case InjectorResetStatus.OperationCompleted:
					<>4__this.NExpettI9((OVo1ODCQZDlsFJm98u)25, 0);
					break;
				}
			}
		}

		[CompilerGenerated]
		private sealed class <>c__DisplayClass4
		{
			public FuelInjectorResetPage <>4__this;

			public OVo1ODCQZDlsFJm98u enumStatusMessage;

			public int injectorNumber;

			[MethodImpl(MethodImplOptions.NoInlining)]
			public <>c__DisplayClass4()
			{
				IE3dyJf2OKPAA7hD1W.ugrjvXWz48stp();
				base..ctor();
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public void <UpdateStatusArea>b__3()
			{
				if ((OVo1ODCQZDlsFJm98u)25 != enumStatusMessage)
				{
					((Control)<>4__this.eW5eSgm5A).Invalidate();
					TextBox eW5eSgm5A = <>4__this.eW5eSgm5A;
					((Control)eW5eSgm5A).Text = ((Control)eW5eSgm5A).Text + string.Format(<>4__this.IJDUxyGnJ.GetLocalizedString(enumStatusMessage), injectorNumber) + Environment.NewLine + Environment.NewLine;
				}
				else
				{
					TextBox eW5eSgm5A2 = <>4__this.eW5eSgm5A;
					((Control)eW5eSgm5A2).Text = ((Control)eW5eSgm5A2).Text + <>4__this.IJDUxyGnJ.GetLocalizedString(enumStatusMessage) + Environment.NewLine + Environment.NewLine;
					<>4__this.hI3OI3rSUP = false;
					<>4__this.BEivL1WJT(true);
					<>4__this.VpyMXTVBN();
				}
				((TextBoxBase)<>4__this.eW5eSgm5A).Select(((Control)<>4__this.eW5eSgm5A).Text.Length - 1, 0);
				((TextBoxBase)<>4__this.eW5eSgm5A).ScrollToCaret();
			}
		}

		private IContainer WFPh7QX0C;

		private PictureBox nwELThPdr;

		private GroupBox HktlglrbK;

		private Button JrIyGggVi;

		private TextBox Kf2us10aS;

		private Button RlgfuHd6f;

		private CheckBox[] RxWaLE0bY;

		private Button Nt822ZEI8;

		private GroupBox kghiSfm69;

		private Label oHFgIxuI9;

		private TextBox hBx8YSd2A;

		private Button IZp7Zu05w;

		private GroupBox s5jdBxOdF;

		private GroupBox KsGYEuLCl;

		private Panel nU0VbQnNc;

		private GroupBox F7PSxGvj9;

		private TextBox eW5eSgm5A;

		private Label adgn24Rr7;

		private Panel F2Fb2W23U;

		private FuelInjectorResetLogic iQ0ERf0pk;

		private ILocalizedStringProvider IJDUxyGnJ;

		private IErrorDisplay IOSQmXB0g;

		private ToolSecurity mnjJxKDhK;

		private IContextSensitiveHelpProvider t6SxtcjC1;

		private FeatureSupportedStatus wJ33UQWio;

		private List<int> ccXrTfy5E;

		private Thread HXnz6Fb2F;

		private bool hI3OI3rSUP;

		Guid IHelpInformation.GUID
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return ((object)this).GetType().GUID;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void ahoPTI8PO(object P_0, M2hc0EeofuSLih1G95 P_1)
		{
			IOSQmXB0g.DisplayError(P_1.T6lOsDC0Kw());
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void qnWwyBX1Y(object P_0, FeatureStatusUpdatedEventArgs P_1)
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			<>c__DisplayClass1 CS$<>8__locals8 = new <>c__DisplayClass1();
			CS$<>8__locals8.e = P_1;
			CS$<>8__locals8.<>4__this = this;
			MethodInvoker val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
			{
				switch (CS$<>8__locals8.e.Status)
				{
				case InjectorResetStatus.OperationSuccessful:
					CS$<>8__locals8.<>4__this.NExpettI9((OVo1ODCQZDlsFJm98u)22, CS$<>8__locals8.e.InjectorNumber);
					break;
				case InjectorResetStatus.OperationFail:
					CS$<>8__locals8.<>4__this.NExpettI9((OVo1ODCQZDlsFJm98u)24, CS$<>8__locals8.e.InjectorNumber);
					break;
				case InjectorResetStatus.OperationCompleted:
					CS$<>8__locals8.<>4__this.NExpettI9((OVo1ODCQZDlsFJm98u)25, 0);
					break;
				}
			});
			if (((Control)this).InvokeRequired)
			{
				((Control)this).BeginInvoke((Delegate)(object)val);
			}
			else
			{
				val.Invoke();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Dispose(bool disposing)
		{
			if (disposing && WFPh7QX0C != null)
			{
				WFPh7QX0C.Dispose();
			}
			((Form)this).Dispose(disposing);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void gVpDABj0g()
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_0012: Expected O, but got Unknown
			//IL_0013: Unknown result type (might be due to invalid IL or missing references)
			//IL_001d: Expected O, but got Unknown
			//IL_001e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Expected O, but got Unknown
			//IL_0029: Unknown result type (might be due to invalid IL or missing references)
			//IL_0033: Expected O, but got Unknown
			//IL_0034: Unknown result type (might be due to invalid IL or missing references)
			//IL_003e: Expected O, but got Unknown
			//IL_003f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0049: Expected O, but got Unknown
			//IL_004a: Unknown result type (might be due to invalid IL or missing references)
			//IL_0054: Expected O, but got Unknown
			//IL_0055: Unknown result type (might be due to invalid IL or missing references)
			//IL_005f: Expected O, but got Unknown
			//IL_0060: Unknown result type (might be due to invalid IL or missing references)
			//IL_006a: Expected O, but got Unknown
			//IL_006b: Unknown result type (might be due to invalid IL or missing references)
			//IL_0075: Expected O, but got Unknown
			//IL_0076: Unknown result type (might be due to invalid IL or missing references)
			//IL_0080: Expected O, but got Unknown
			//IL_0081: Unknown result type (might be due to invalid IL or missing references)
			//IL_008b: Expected O, but got Unknown
			//IL_008c: Unknown result type (might be due to invalid IL or missing references)
			//IL_0096: Expected O, but got Unknown
			//IL_0097: Unknown result type (might be due to invalid IL or missing references)
			//IL_00a1: Expected O, but got Unknown
			//IL_00a2: Unknown result type (might be due to invalid IL or missing references)
			//IL_00ac: Expected O, but got Unknown
			//IL_00ad: Unknown result type (might be due to invalid IL or missing references)
			//IL_00b7: Expected O, but got Unknown
			//IL_00b8: Unknown result type (might be due to invalid IL or missing references)
			//IL_00c2: Expected O, but got Unknown
			//IL_0156: Unknown result type (might be due to invalid IL or missing references)
			//IL_0160: Expected O, but got Unknown
			//IL_01ea: Unknown result type (might be due to invalid IL or missing references)
			//IL_01f4: Expected O, but got Unknown
			//IL_0278: Unknown result type (might be due to invalid IL or missing references)
			//IL_0282: Expected O, but got Unknown
			//IL_04ef: Unknown result type (might be due to invalid IL or missing references)
			//IL_04f9: Expected O, but got Unknown
			//IL_052a: Unknown result type (might be due to invalid IL or missing references)
			//IL_05c8: Unknown result type (might be due to invalid IL or missing references)
			//IL_05d2: Expected O, but got Unknown
			//IL_06b8: Unknown result type (might be due to invalid IL or missing references)
			//IL_06c2: Expected O, but got Unknown
			//IL_0862: Unknown result type (might be due to invalid IL or missing references)
			//IL_0960: Unknown result type (might be due to invalid IL or missing references)
			//IL_096a: Expected O, but got Unknown
			//IL_0a75: Unknown result type (might be due to invalid IL or missing references)
			//IL_0a7f: Expected O, but got Unknown
			kghiSfm69 = new GroupBox();
			oHFgIxuI9 = new Label();
			hBx8YSd2A = new TextBox();
			Nt822ZEI8 = new Button();
			RlgfuHd6f = new Button();
			s5jdBxOdF = new GroupBox();
			F7PSxGvj9 = new GroupBox();
			eW5eSgm5A = new TextBox();
			KsGYEuLCl = new GroupBox();
			nU0VbQnNc = new Panel();
			IZp7Zu05w = new Button();
			HktlglrbK = new GroupBox();
			JrIyGggVi = new Button();
			Kf2us10aS = new TextBox();
			nwELThPdr = new PictureBox();
			adgn24Rr7 = new Label();
			F2Fb2W23U = new Panel();
			((Control)kghiSfm69).SuspendLayout();
			((Control)s5jdBxOdF).SuspendLayout();
			((Control)F7PSxGvj9).SuspendLayout();
			((Control)KsGYEuLCl).SuspendLayout();
			((Control)HktlglrbK).SuspendLayout();
			((ISupportInitialize)nwELThPdr).BeginInit();
			((Control)F2Fb2W23U).SuspendLayout();
			((Control)this).SuspendLayout();
			((Control)kghiSfm69).Controls.Add((Control)(object)oHFgIxuI9);
			((Control)kghiSfm69).Controls.Add((Control)(object)hBx8YSd2A);
			((Control)kghiSfm69).Font = new Font(ETZxusFl8KUvQCslGf.pasOtyYaWV(176), 10f);
			((Control)kghiSfm69).ForeColor = SystemColors.ControlText;
			((Control)kghiSfm69).Location = new Point(16, 5);
			((Control)kghiSfm69).Name = ETZxusFl8KUvQCslGf.pasOtyYaWV(220);
			((Control)kghiSfm69).Size = new Size(947, 84);
			((Control)kghiSfm69).TabIndex = 18;
			kghiSfm69.TabStop = false;
			((Control)oHFgIxuI9).AutoSize = true;
			((Control)oHFgIxuI9).Font = new Font(ETZxusFl8KUvQCslGf.pasOtyYaWV(256), 12f, (FontStyle)1);
			oHFgIxuI9.ImeMode = (ImeMode)0;
			((Control)oHFgIxuI9).Location = new Point(5, 13);
			((Control)oHFgIxuI9).Name = ETZxusFl8KUvQCslGf.pasOtyYaWV(300);
			((Control)oHFgIxuI9).Size = new Size(0, 20);
			((Control)oHFgIxuI9).TabIndex = 1;
			((Control)hBx8YSd2A).BackColor = SystemColors.Control;
			((TextBoxBase)hBx8YSd2A).BorderStyle = (BorderStyle)0;
			((Control)hBx8YSd2A).Font = new Font(ETZxusFl8KUvQCslGf.pasOtyYaWV(330), 10f);
			((Control)hBx8YSd2A).Location = new Point(6, 36);
			((TextBoxBase)hBx8YSd2A).Multiline = true;
			((Control)hBx8YSd2A).Name = ETZxusFl8KUvQCslGf.pasOtyYaWV(374);
			((TextBoxBase)hBx8YSd2A).ReadOnly = true;
			hBx8YSd2A.ScrollBars = (ScrollBars)2;
			((Control)hBx8YSd2A).Size = new Size(475, 39);
			((Control)hBx8YSd2A).TabIndex = 2;
			((Control)Nt822ZEI8).AutoSize = true;
			((Control)Nt822ZEI8).Cursor = Cursors.Arrow;
			((Control)Nt822ZEI8).Enabled = false;
			((ButtonBase)Nt822ZEI8).FlatAppearance.MouseDownBackColor = SystemColors.Control;
			((ButtonBase)Nt822ZEI8).FlatAppearance.MouseOverBackColor = SystemColors.Control;
			((Control)Nt822ZEI8).ForeColor = SystemColors.ControlText;
			((ButtonBase)Nt822ZEI8).ImeMode = (ImeMode)0;
			((Control)Nt822ZEI8).Location = new Point(431, 648);
			((Control)Nt822ZEI8).Name = ETZxusFl8KUvQCslGf.pasOtyYaWV(410);
			((Control)Nt822ZEI8).Size = new Size(91, 33);
			((Control)Nt822ZEI8).TabIndex = 17;
			((Control)Nt822ZEI8).Text = ETZxusFl8KUvQCslGf.pasOtyYaWV(438);
			((ButtonBase)Nt822ZEI8).UseVisualStyleBackColor = true;
			((Control)Nt822ZEI8).Click += zsU1S3299;
			((Control)RlgfuHd6f).Cursor = Cursors.Arrow;
			((Control)RlgfuHd6f).ForeColor = SystemColors.WindowText;
			((ButtonBase)RlgfuHd6f).ImeMode = (ImeMode)0;
			((Control)RlgfuHd6f).Location = new Point(41, 648);
			((Control)RlgfuHd6f).Name = ETZxusFl8KUvQCslGf.pasOtyYaWV(452);
			((Control)RlgfuHd6f).Size = new Size(91, 33);
			((Control)RlgfuHd6f).TabIndex = 16;
			((Control)RlgfuHd6f).Text = ETZxusFl8KUvQCslGf.pasOtyYaWV(478);
			((ButtonBase)RlgfuHd6f).UseVisualStyleBackColor = true;
			((Control)RlgfuHd6f).Click += T69XNqrVZ;
			((Control)s5jdBxOdF).Controls.Add((Control)(object)F7PSxGvj9);
			((Control)s5jdBxOdF).Controls.Add((Control)(object)KsGYEuLCl);
			((Control)s5jdBxOdF).Controls.Add((Control)(object)IZp7Zu05w);
			((Control)s5jdBxOdF).Font = new Font(ETZxusFl8KUvQCslGf.pasOtyYaWV(490), 10f);
			((Control)s5jdBxOdF).ForeColor = SystemColors.ControlText;
			((Control)s5jdBxOdF).Location = new Point(16, 220);
			((Control)s5jdBxOdF).Margin = new Padding(3, 3, 0, 3);
			((Control)s5jdBxOdF).Name = ETZxusFl8KUvQCslGf.pasOtyYaWV(534);
			((Control)s5jdBxOdF).Size = new Size(947, 422);
			((Control)s5jdBxOdF).TabIndex = 15;
			s5jdBxOdF.TabStop = false;
			((Control)s5jdBxOdF).Text = ETZxusFl8KUvQCslGf.pasOtyYaWV(574);
			F7PSxGvj9.AutoSizeMode = (AutoSizeMode)0;
			((Control)F7PSxGvj9).Controls.Add((Control)(object)eW5eSgm5A);
			((Control)F7PSxGvj9).Font = new Font(ETZxusFl8KUvQCslGf.pasOtyYaWV(596), 10f);
			((Control)F7PSxGvj9).ForeColor = SystemColors.WindowText;
			((Control)F7PSxGvj9).Location = new Point(91, 19);
			((Control)F7PSxGvj9).MaximumSize = new Size(850, 360);
			((Control)F7PSxGvj9).MinimumSize = new Size(606, 360);
			((Control)F7PSxGvj9).Name = ETZxusFl8KUvQCslGf.pasOtyYaWV(640);
			((Control)F7PSxGvj9).Size = new Size(850, 360);
			((Control)F7PSxGvj9).TabIndex = 18;
			F7PSxGvj9.TabStop = false;
			((Control)F7PSxGvj9).Text = ETZxusFl8KUvQCslGf.pasOtyYaWV(674);
			((Control)eW5eSgm5A).BackColor = SystemColors.Control;
			((Control)eW5eSgm5A).Dock = (DockStyle)5;
			((Control)eW5eSgm5A).Font = new Font(ETZxusFl8KUvQCslGf.pasOtyYaWV(690), 10f);
			((Control)eW5eSgm5A).Location = new Point(3, 19);
			((TextBoxBase)eW5eSgm5A).Multiline = true;
			((Control)eW5eSgm5A).Name = ETZxusFl8KUvQCslGf.pasOtyYaWV(734);
			((TextBoxBase)eW5eSgm5A).ReadOnly = true;
			((Control)eW5eSgm5A).Size = new Size(844, 338);
			((Control)eW5eSgm5A).TabIndex = 9;
			((Control)KsGYEuLCl).AutoSize = true;
			KsGYEuLCl.AutoSizeMode = (AutoSizeMode)0;
			((Control)KsGYEuLCl).Controls.Add((Control)(object)nU0VbQnNc);
			((Control)KsGYEuLCl).Dock = (DockStyle)3;
			((Control)KsGYEuLCl).Location = new Point(3, 19);
			((Control)KsGYEuLCl).MaximumSize = new Size(329, 360);
			((Control)KsGYEuLCl).MinimumSize = new Size(83, 360);
			((Control)KsGYEuLCl).Name = ETZxusFl8KUvQCslGf.pasOtyYaWV(766);
			((Control)KsGYEuLCl).Size = new Size(83, 360);
			((Control)KsGYEuLCl).TabIndex = 0;
			KsGYEuLCl.TabStop = false;
			((Control)KsGYEuLCl).Text = ETZxusFl8KUvQCslGf.pasOtyYaWV(818);
			((ScrollableControl)nU0VbQnNc).AutoScroll = true;
			((Control)nU0VbQnNc).AutoSize = true;
			nU0VbQnNc.AutoSizeMode = (AutoSizeMode)0;
			((Control)nU0VbQnNc).Dock = (DockStyle)5;
			((Control)nU0VbQnNc).Location = new Point(3, 19);
			((Control)nU0VbQnNc).Name = ETZxusFl8KUvQCslGf.pasOtyYaWV(840);
			((Control)nU0VbQnNc).Padding = new Padding(0, 0, 5, 0);
			((Control)nU0VbQnNc).Size = new Size(77, 338);
			((Control)nU0VbQnNc).TabIndex = 0;
			((Control)IZp7Zu05w).Enabled = false;
			((Control)IZp7Zu05w).Location = new Point(6, 382);
			((Control)IZp7Zu05w).Name = ETZxusFl8KUvQCslGf.pasOtyYaWV(886);
			((Control)IZp7Zu05w).Size = new Size(123, 33);
			((Control)IZp7Zu05w).TabIndex = 19;
			((Control)IZp7Zu05w).Text = ETZxusFl8KUvQCslGf.pasOtyYaWV(934);
			((ButtonBase)IZp7Zu05w).UseVisualStyleBackColor = true;
			((Control)IZp7Zu05w).Click += PVnFlGPnK;
			((Control)HktlglrbK).Controls.Add((Control)(object)JrIyGggVi);
			((Control)HktlglrbK).Controls.Add((Control)(object)Kf2us10aS);
			((Control)HktlglrbK).Font = new Font(ETZxusFl8KUvQCslGf.pasOtyYaWV(970), 10f);
			((Control)HktlglrbK).ForeColor = SystemColors.ControlText;
			((Control)HktlglrbK).Location = new Point(16, 105);
			((Control)HktlglrbK).Name = ETZxusFl8KUvQCslGf.pasOtyYaWV(1014);
			((Control)HktlglrbK).Size = new Size(947, 107);
			((Control)HktlglrbK).TabIndex = 14;
			HktlglrbK.TabStop = false;
			((Control)HktlglrbK).Text = ETZxusFl8KUvQCslGf.pasOtyYaWV(1058);
			((Control)JrIyGggVi).AutoSize = true;
			((Control)JrIyGggVi).Cursor = Cursors.Hand;
			((ButtonBase)JrIyGggVi).FlatAppearance.BorderColor = SystemColors.Control;
			((ButtonBase)JrIyGggVi).FlatAppearance.BorderSize = 0;
			((ButtonBase)JrIyGggVi).FlatAppearance.MouseDownBackColor = SystemColors.Control;
			((ButtonBase)JrIyGggVi).FlatAppearance.MouseOverBackColor = SystemColors.Control;
			((ButtonBase)JrIyGggVi).FlatStyle = (FlatStyle)0;
			((Control)JrIyGggVi).Font = new Font(ETZxusFl8KUvQCslGf.pasOtyYaWV(1086), 10f);
			((ButtonBase)JrIyGggVi).ImeMode = (ImeMode)0;
			((Control)JrIyGggVi).Location = new Point(845, -4);
			((Control)JrIyGggVi).Name = ETZxusFl8KUvQCslGf.pasOtyYaWV(1130);
			((Control)JrIyGggVi).Size = new Size(52, 27);
			((Control)JrIyGggVi).TabIndex = 6;
			((Control)JrIyGggVi).Text = ETZxusFl8KUvQCslGf.pasOtyYaWV(1156);
			((ButtonBase)JrIyGggVi).UseVisualStyleBackColor = true;
			((Control)JrIyGggVi).Click += NrOKhF6VU;
			((Control)Kf2us10aS).BackColor = SystemColors.Control;
			((TextBoxBase)Kf2us10aS).BorderStyle = (BorderStyle)0;
			((Control)Kf2us10aS).ForeColor = SystemColors.WindowText;
			((Control)Kf2us10aS).Location = new Point(4, 14);
			((TextBoxBase)Kf2us10aS).Multiline = true;
			((Control)Kf2us10aS).Name = ETZxusFl8KUvQCslGf.pasOtyYaWV(1168);
			((TextBoxBase)Kf2us10aS).ReadOnly = true;
			Kf2us10aS.ScrollBars = (ScrollBars)2;
			((Control)Kf2us10aS).Size = new Size(937, 80);
			((Control)Kf2us10aS).TabIndex = 5;
			nwELThPdr.Image = (Image)(object)Resources.adv_ecm_;
			nwELThPdr.ImeMode = (ImeMode)0;
			((Control)nwELThPdr).Location = new Point(988, 31);
			((Control)nwELThPdr).Name = ETZxusFl8KUvQCslGf.pasOtyYaWV(1210);
			((Control)nwELThPdr).Size = new Size(32, 31);
			nwELThPdr.TabIndex = 13;
			nwELThPdr.TabStop = false;
			((Control)adgn24Rr7).AutoSize = true;
			((Control)adgn24Rr7).Location = new Point(13, 93);
			((Control)adgn24Rr7).Name = ETZxusFl8KUvQCslGf.pasOtyYaWV(1244);
			((Control)adgn24Rr7).Size = new Size(35, 13);
			((Control)adgn24Rr7).TabIndex = 19;
			((Control)adgn24Rr7).Text = ETZxusFl8KUvQCslGf.pasOtyYaWV(1298);
			((Control)adgn24Rr7).Visible = false;
			((ScrollableControl)F2Fb2W23U).AutoScroll = true;
			((Control)F2Fb2W23U).Controls.Add((Control)(object)adgn24Rr7);
			((Control)F2Fb2W23U).Controls.Add((Control)(object)kghiSfm69);
			((Control)F2Fb2W23U).Controls.Add((Control)(object)Nt822ZEI8);
			((Control)F2Fb2W23U).Controls.Add((Control)(object)RlgfuHd6f);
			((Control)F2Fb2W23U).Controls.Add((Control)(object)s5jdBxOdF);
			((Control)F2Fb2W23U).Controls.Add((Control)(object)HktlglrbK);
			((Control)F2Fb2W23U).Controls.Add((Control)(object)nwELThPdr);
			((Control)F2Fb2W23U).Dock = (DockStyle)5;
			((Control)F2Fb2W23U).Location = new Point(0, 0);
			((Control)F2Fb2W23U).Name = ETZxusFl8KUvQCslGf.pasOtyYaWV(1314);
			((Control)F2Fb2W23U).Size = new Size(1027, 702);
			((Control)F2Fb2W23U).TabIndex = 20;
			((ContainerControl)this).AutoScaleDimensions = new SizeF(6f, 13f);
			((ContainerControl)this).AutoScaleMode = (AutoScaleMode)1;
			((Form)this).ClientSize = new Size(1027, 702);
			((Control)this).Controls.Add((Control)(object)F2Fb2W23U);
			((Form)this).FormBorderStyle = (FormBorderStyle)0;
			((Control)this).Name = ETZxusFl8KUvQCslGf.pasOtyYaWV(1336);
			((Form)this).TopMost = true;
			((Form)this).Load += q0u4qlPoi;
			((Control)kghiSfm69).ResumeLayout(false);
			((Control)kghiSfm69).PerformLayout();
			((Control)s5jdBxOdF).ResumeLayout(false);
			((Control)s5jdBxOdF).PerformLayout();
			((Control)F7PSxGvj9).ResumeLayout(false);
			((Control)F7PSxGvj9).PerformLayout();
			((Control)KsGYEuLCl).ResumeLayout(false);
			((Control)KsGYEuLCl).PerformLayout();
			((Control)HktlglrbK).ResumeLayout(false);
			((Control)HktlglrbK).PerformLayout();
			((ISupportInitialize)nwELThPdr).EndInit();
			((Control)F2Fb2W23U).ResumeLayout(false);
			((Control)F2Fb2W23U).PerformLayout();
			((Control)this).ResumeLayout(false);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FuelInjectorResetPage()
		{
			IE3dyJf2OKPAA7hD1W.ugrjvXWz48stp();
			base..ctor();
			gVpDABj0g();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void OnResize(EventArgs e)
		{
			((Form)this).OnResize(e);
			((Control)kghiSfm69).Invalidate(true);
			((Control)HktlglrbK).Invalidate(true);
			((Control)s5jdBxOdF).Invalidate(true);
			((Control)nwELThPdr).Invalidate();
			((Control)Nt822ZEI8).Invalidate();
			((Control)RlgfuHd6f).Invalidate();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void SetHelper(object pUnkHelper)
		{
			if (pUnkHelper == null)
			{
				throw new ArgumentNullException(pUnkHelper.ToString());
			}
			base.SetHelper(pUnkHelper);
			iQ0ERf0pk = (FuelInjectorResetLogic)base.Helper;
			iQ0ERf0pk.tMxtx52Gm += ahoPTI8PO;
			((IFuelInjectorResetEvents)iQ0ERf0pk).FeatureStatusUpdated += qnWwyBX1Y;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void Init(string regKeyPath)
		{
			if (string.IsNullOrEmpty(regKeyPath))
			{
				throw new ArgumentNullException(regKeyPath);
			}
			IJDUxyGnJ = Factory.CreateInstance<ILocalizedStringProvider>();
			IJDUxyGnJ.Initialize(regKeyPath, ((object)this).GetType().GUID);
			t6SxtcjC1 = Factory.CreateInstance<IContextSensitiveHelpProvider>();
			t6SxtcjC1.Initialize(base.Kernel, base.Shell);
			IOSQmXB0g = Factory.CreateInstance<IErrorDisplay>();
			IOSQmXB0g.Initialize(base.Shell, IJDUxyGnJ);
			ccXrTfy5E = new List<int>();
			mnjJxKDhK = new ToolSecurity();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void GwS5EXFYD()
		{
			CheckBox[] rxWaLE0bY = RxWaLE0bY;
			foreach (CheckBox val in rxWaLE0bY)
			{
				((Control)val).Enabled = false;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		protected override void UnLoad()
		{
			if (HXnz6Fb2F != null)
			{
				HXnz6Fb2F.Abort();
			}
			if (!((Control)this).IsDisposed)
			{
				base.UnLoad();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void q0u4qlPoi(object P_0, EventArgs P_1)
		{
			wJ33UQWio = ((IFuelInjectorResetHelper)iQ0ERf0pk).IsFeatureSupported();
			Qt3jKI7Xh();
			LoadLicenses();
			try
			{
				if (!mnjJxKDhK.IsValid(ETZxusFl8KUvQCslGf.pasOtyYaWV(1382)) || !mnjJxKDhK.IsValid(ETZxusFl8KUvQCslGf.pasOtyYaWV(1432)))
				{
					GwS5EXFYD();
				}
			}
			catch (Exception)
			{
				throw new Exception(ETZxusFl8KUvQCslGf.pasOtyYaWV(1472));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public void LoadLicenses()
		{
			try
			{
				mnjJxKDhK.LoadLicenses(base.Kernel, typeof(FuelInjectorResetLogic).GUID, ETZxusFl8KUvQCslGf.pasOtyYaWV(1534));
			}
			catch (Exception)
			{
				throw new Exception(ETZxusFl8KUvQCslGf.pasOtyYaWV(1614));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void T69XNqrVZ(object P_0, EventArgs P_1)
		{
			t6SxtcjC1.ShowHelp(this);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void zsU1S3299(object P_0, EventArgs P_1)
		{
			//IL_0022: Unknown result type (might be due to invalid IL or missing references)
			//IL_0027: Unknown result type (might be due to invalid IL or missing references)
			//IL_0028: Unknown result type (might be due to invalid IL or missing references)
			//IL_002a: Invalid comparison between Unknown and I4
			if (FeatureSupportedStatus.True == wJ33UQWio)
			{
				YE1Bkwfn0(false);
				ate9D07nD(false);
				DialogResult val = ttQc9N2xG();
				if ((int)val == 6)
				{
					BEivL1WJT(false);
					HXnz6Fb2F = ((IFuelInjectorResetHelper)iQ0ERf0pk).ResetInjectors(ccXrTfy5E);
					hI3OI3rSUP = true;
				}
				else
				{
					YE1Bkwfn0(true);
					ate9D07nD(true);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void NrOKhF6VU(object P_0, EventArgs P_1)
		{
			//IL_0029: Unknown result type (might be due to invalid IL or missing references)
			MessageBox.Show(IJDUxyGnJ.GetLocalizedString((ap0kK7Kxi2Yoeut9lm)3), IJDUxyGnJ.GetLocalizedString((ap0kK7Kxi2Yoeut9lm)4));
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void PVnFlGPnK(object P_0, EventArgs P_1)
		{
			VpyMXTVBN();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void VpyMXTVBN()
		{
			foreach (int item in ccXrTfy5E)
			{
				RxWaLE0bY[item - 1].Checked = false;
			}
			ccXrTfy5E.Clear();
			yGYAjrQnu();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void yqZmGjcGw(object P_0, EventArgs P_1)
		{
			//IL_0008: Unknown result type (might be due to invalid IL or missing references)
			//IL_000e: Expected O, but got Unknown
			//IL_000f: Unknown result type (might be due to invalid IL or missing references)
			//IL_0015: Invalid comparison between Unknown and I4
			CheckBox val = (CheckBox)P_0;
			if ((int)val.CheckState == 1)
			{
				val.Checked = true;
				ccXrTfy5E.Add(Convert.ToInt16(((Control)val).Text));
			}
			else
			{
				ccXrTfy5E.Remove(Convert.ToInt16(((Control)val).Text));
				val.Checked = false;
			}
			yGYAjrQnu();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void yGYAjrQnu()
		{
			if (!hI3OI3rSUP)
			{
				if (ccXrTfy5E.Count == 0)
				{
					YE1Bkwfn0(false);
					ate9D07nD(false);
				}
				else
				{
					YE1Bkwfn0(true);
					ate9D07nD(true);
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void ate9D07nD(bool P_0)
		{
			((Control)IZp7Zu05w).Enabled = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void YE1Bkwfn0(bool P_0)
		{
			((Control)Nt822ZEI8).Enabled = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void Qt3jKI7Xh()
		{
			((Control)oHFgIxuI9).Text = IJDUxyGnJ.GetLocalizedString((ap0kK7Kxi2Yoeut9lm)1);
			((Control)hBx8YSd2A).Text = IJDUxyGnJ.GetLocalizedString((ap0kK7Kxi2Yoeut9lm)2);
			if (wJ33UQWio == FeatureSupportedStatus.True)
			{
				((Control)HktlglrbK).Text = IJDUxyGnJ.GetLocalizedString((ap0kK7Kxi2Yoeut9lm)4);
				((Control)Kf2us10aS).Text = IJDUxyGnJ.GetLocalizedString((ap0kK7Kxi2Yoeut9lm)3);
				((Control)s5jdBxOdF).Text = IJDUxyGnJ.GetLocalizedString((ap0kK7Kxi2Yoeut9lm)6);
				((Control)KsGYEuLCl).Text = IJDUxyGnJ.GetLocalizedString((ap0kK7Kxi2Yoeut9lm)6);
				((Control)F7PSxGvj9).Text = IJDUxyGnJ.GetLocalizedString((ap0kK7Kxi2Yoeut9lm)10);
				((Control)JrIyGggVi).Text = IJDUxyGnJ.GetLocalizedString((ap0kK7Kxi2Yoeut9lm)5);
				((Control)Nt822ZEI8).Text = IJDUxyGnJ.GetLocalizedString((ap0kK7Kxi2Yoeut9lm)11);
				((Control)IZp7Zu05w).Text = IJDUxyGnJ.GetLocalizedString((ap0kK7Kxi2Yoeut9lm)13);
				((Control)RlgfuHd6f).Text = IJDUxyGnJ.GetLocalizedString((ap0kK7Kxi2Yoeut9lm)12);
				LCWGcEC5D();
				HmwZTI2Re();
			}
			else
			{
				((Control)HktlglrbK).Visible = false;
				((Control)s5jdBxOdF).Visible = false;
				((Control)RlgfuHd6f).Visible = false;
				((Control)Nt822ZEI8).Visible = false;
				((Control)adgn24Rr7).Visible = true;
				((Control)adgn24Rr7).Text = IJDUxyGnJ.GetLocalizedString((ap0kK7Kxi2Yoeut9lm)14);
			}
			try
			{
				IToolLevelRegistration toolLevelRegistration = (IToolLevelRegistration)base.Kernel;
				string currentToolLevel = toolLevelRegistration.GetCurrentToolLevel();
				if (currentToolLevel.Equals(ETZxusFl8KUvQCslGf.pasOtyYaWV(1678)))
				{
					GwS5EXFYD();
				}
			}
			catch (Exception)
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void HmwZTI2Re()
		{
			((Control)F7PSxGvj9).Location = new Point(((Control)KsGYEuLCl).Width + 5, ((Control)F7PSxGvj9).Location.Y);
			((Control)F7PSxGvj9).Size = new Size(((Control)s5jdBxOdF).Width - ((Control)KsGYEuLCl).Width - 10, ((Control)F7PSxGvj9).Size.Height);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void LCWGcEC5D()
		{
			//IL_0047: Unknown result type (might be due to invalid IL or missing references)
			//IL_004d: Expected O, but got Unknown
			RxWaLE0bY = (CheckBox[])(object)new CheckBox[iQ0ERf0pk.TotalNumberOfInjectors];
			int num = 10;
			int num2 = 10;
			for (int i = 0; i < iQ0ERf0pk.TotalNumberOfInjectors; i++)
			{
				if (i % 6 == 0 && i != 0)
				{
					num2 += 50;
					num = 10;
				}
				RxWaLE0bY[i] = new CheckBox();
				((Control)RxWaLE0bY[i]).Name = ETZxusFl8KUvQCslGf.pasOtyYaWV(1692) + (i + 1);
				RxWaLE0bY[i].Appearance = (Appearance)1;
				((Control)RxWaLE0bY[i]).Location = new Point(num2, num);
				((Control)RxWaLE0bY[i]).Size = new Size(40, 40);
				((Control)RxWaLE0bY[i]).Text = string.Concat(i + 1);
				((ButtonBase)RxWaLE0bY[i]).TextAlign = (ContentAlignment)32;
				((Control)nU0VbQnNc).Controls.Add((Control)(object)RxWaLE0bY[i]);
				((Control)RxWaLE0bY[i]).Click += yqZmGjcGw;
				num += 50;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void NExpettI9(OVo1ODCQZDlsFJm98u P_0, int P_1)
		{
			//IL_0029: Unknown result type (might be due to invalid IL or missing references)
			//IL_002f: Expected O, but got Unknown
			<>c__DisplayClass4 CS$<>8__locals18 = new <>c__DisplayClass4();
			CS$<>8__locals18.enumStatusMessage = P_0;
			CS$<>8__locals18.injectorNumber = P_1;
			CS$<>8__locals18.<>4__this = this;
			MethodInvoker val = (MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
			{
				if ((OVo1ODCQZDlsFJm98u)25 != CS$<>8__locals18.enumStatusMessage)
				{
					((Control)CS$<>8__locals18.<>4__this.eW5eSgm5A).Invalidate();
					TextBox obj = CS$<>8__locals18.<>4__this.eW5eSgm5A;
					((Control)obj).Text = ((Control)obj).Text + string.Format(CS$<>8__locals18.<>4__this.IJDUxyGnJ.GetLocalizedString(CS$<>8__locals18.enumStatusMessage), CS$<>8__locals18.injectorNumber) + Environment.NewLine + Environment.NewLine;
				}
				else
				{
					TextBox obj2 = CS$<>8__locals18.<>4__this.eW5eSgm5A;
					((Control)obj2).Text = ((Control)obj2).Text + CS$<>8__locals18.<>4__this.IJDUxyGnJ.GetLocalizedString(CS$<>8__locals18.enumStatusMessage) + Environment.NewLine + Environment.NewLine;
					CS$<>8__locals18.<>4__this.hI3OI3rSUP = false;
					CS$<>8__locals18.<>4__this.BEivL1WJT(true);
					CS$<>8__locals18.<>4__this.VpyMXTVBN();
				}
				((TextBoxBase)CS$<>8__locals18.<>4__this.eW5eSgm5A).Select(((Control)CS$<>8__locals18.<>4__this.eW5eSgm5A).Text.Length - 1, 0);
				((TextBoxBase)CS$<>8__locals18.<>4__this.eW5eSgm5A).ScrollToCaret();
			});
			if (((Control)this).InvokeRequired)
			{
				((Control)this).BeginInvoke((Delegate)(object)val);
			}
			else
			{
				val.Invoke();
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void BEivL1WJT(bool P_0)
		{
			foreach (int item in ccXrTfy5E)
			{
				((Control)RxWaLE0bY[item - 1]).Enabled = P_0;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private DialogResult ttQc9N2xG()
		{
			//IL_0138: Unknown result type (might be due to invalid IL or missing references)
			//IL_013d: Unknown result type (might be due to invalid IL or missing references)
			//IL_013f: Unknown result type (might be due to invalid IL or missing references)
			string text = "";
			string text2 = "";
			int count = ccXrTfy5E.Count;
			if (count == 1)
			{
				text += ccXrTfy5E[0];
				text2 = string.Format(IJDUxyGnJ.GetLocalizedString((ap0kK7Kxi2Yoeut9lm)7), text);
			}
			else
			{
				int num = 1;
				ccXrTfy5E.Sort();
				text += ccXrTfy5E[0];
				foreach (int item in ccXrTfy5E)
				{
					if (num != 1)
					{
						text = ((ccXrTfy5E.Count != num) ? (text + ETZxusFl8KUvQCslGf.pasOtyYaWV(1738) + item) : (text + ETZxusFl8KUvQCslGf.pasOtyYaWV(1724) + item));
					}
					num++;
				}
				text2 = string.Format(IJDUxyGnJ.GetLocalizedString((ap0kK7Kxi2Yoeut9lm)15), text);
			}
			return MessageBox.Show(text2, IJDUxyGnJ.GetLocalizedString((ap0kK7Kxi2Yoeut9lm)8), (MessageBoxButtons)4, (MessageBoxIcon)48);
		}
	}
	public class FeatureStatusUpdatedEventArgs : EventArgs
	{
		private InjectorResetStatus mHTOOh29NX;

		private int J1wO0OZmQO;

		public InjectorResetStatus Status
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return mHTOOh29NX;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				mHTOOh29NX = value;
			}
		}

		public int InjectorNumber
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			get
			{
				return J1wO0OZmQO;
			}
			[MethodImpl(MethodImplOptions.NoInlining)]
			set
			{
				J1wO0OZmQO = value;
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public FeatureStatusUpdatedEventArgs(InjectorResetStatus status, int injectorNumber)
		{
			IE3dyJf2OKPAA7hD1W.ugrjvXWz48stp();
			base..ctor();
			Status = status;
			InjectorNumber = injectorNumber;
		}
	}
}
namespace GLTcrlwyLBJgfodYhN
{
	internal class M2hc0EeofuSLih1G95 : EventArgs
	{
		private hhKTSbP9bNVQw9TELG nOlOoOEeVl;

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public hhKTSbP9bNVQw9TELG T6lOsDC0Kw()
		{
			return nOlOoOEeVl;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[SpecialName]
		public void AxOOWLMXRJ(hhKTSbP9bNVQw9TELG P_0)
		{
			nOlOoOEeVl = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public M2hc0EeofuSLih1G95(hhKTSbP9bNVQw9TELG P_0)
		{
			IE3dyJf2OKPAA7hD1W.ugrjvXWz48stp();
			base..ctor();
			AxOOWLMXRJ(P_0);
		}
	}
}
namespace Cummins.INSITE.FuelInjectorReset
{
	public enum FeatureSupportedStatus
	{
		False,
		True
	}
	public enum OperationExecutionStatus
	{
		OperationSuccessful = 0,
		OperationCompleted = 1,
		OperationFailed = 65533
	}
}
namespace HY7B9pTYMOWGVYCp6H
{
	internal enum ap0kK7Kxi2Yoeut9lm
	{

	}
}
namespace IBNhjJtZ2bZVfgIVV0
{
	internal enum OVo1ODCQZDlsFJm98u
	{

	}
}
namespace Cummins.INSITE.FuelInjectorReset
{
	public enum InjectorResetStatus
	{
		OperationSuccessful,
		OperationFail,
		OperationCompleted
	}
}
namespace Qh3ylrhMbbhfCfymy0
{
	internal enum hhKTSbP9bNVQw9TELG
	{

	}
}
namespace Cummins.INSITE.FuelInjectorReset
{
	public static class FuelInjectorResetConstants
	{
		public const int OperationSuccess = 0;

		public const int InvalidApplicationState = 65533;

		public const int OperationCompleted = 2;

		public const int FeatureIsEnabled = 1;

		public const int KeyMessageTime = 30;

		public const int ButtonSpacing = 50;

		public const int StartLocation = 10;

		public const int MaxInjectorsPerColumn = 6;

		public const string LicenseIdUserResetLogs = "FIR_AdvanceECMData";

		public const string LicenseIdPermitECMReset = "FIR_ECMPwd_PermitResets";
	}
	public static class FuelInjectorResetTokens
	{
		public const string InjectorResetEnable = "16824632";

		public const string CylinderCutoutTestNumberOfCylinders = "16788878";

		public const string StartStop = "1040441";

		public const string OperationResponse = "1040454";
	}
	public static class CLSIDs
	{
		public const string ShellAddInCLSId = "{4EA70356-74C3-4493-9E2B-AE26CD904318}";

		public const string ConManWorker = "{052113AD-8285-4E41-83FA-66B61C7458DF}";
	}
}
internal class <Module>{33B3B789-B838-4728-9F7E-495FF5D6A284}
{
}
namespace t1FAsi4QxpdZWgoDj3
{
	internal class QtHpvmN3Rd5R8DXl31
	{
		internal delegate void SFU4mbT3GMret7THonf(object o);

		internal static Module rcFOH8qFAg;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void EJ5jvXWWTRtvy(int typemdt)
		{
			Type type = rcFOH8qFAg.ResolveType(33554432 + typemdt);
			FieldInfo[] fields = type.GetFields();
			foreach (FieldInfo fieldInfo in fields)
			{
				MethodInfo method = (MethodInfo)rcFOH8qFAg.ResolveMethod(fieldInfo.MetadataToken + 100663296);
				fieldInfo.SetValue(null, (MulticastDelegate)Delegate.CreateDelegate(type, method));
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public QtHpvmN3Rd5R8DXl31()
		{
			IE3dyJf2OKPAA7hD1W.ugrjvXWz48stp();
			base..ctor();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		static QtHpvmN3Rd5R8DXl31()
		{
			IE3dyJf2OKPAA7hD1W.ugrjvXWz48stp();
			rcFOH8qFAg = typeof(QtHpvmN3Rd5R8DXl31).Assembly.ManifestModule;
		}
	}
}
namespace Evxw7Pb2BvVFUE67hx
{
	internal class ETZxusFl8KUvQCslGf
	{
		internal class mrqRnf10S5UMFoaEbr : Attribute
		{
			internal class xWG3HGYjHMnQIbC8qs<T>
			{
				[MethodImpl(MethodImplOptions.NoInlining)]
				public xWG3HGYjHMnQIbC8qs()
				{
					IE3dyJf2OKPAA7hD1W.ugrjvXWz48stp();
					base..ctor();
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[mrqRnf10S5UMFoaEbr(typeof(ETZxusFl8KUvQCslGf/mrqRnf10S5UMFoaEbr/xWG3HGYjHMnQIbC8qs<object>[]))]
			public mrqRnf10S5UMFoaEbr(object P_0)
			{
				IE3dyJf2OKPAA7hD1W.ugrjvXWz48stp();
				base..ctor();
			}
		}

		internal class KFrFYGuW8nCwug3o9R
		{
			[MethodImpl(MethodImplOptions.NoInlining)]
			[mrqRnf10S5UMFoaEbr(typeof(ETZxusFl8KUvQCslGf/mrqRnf10S5UMFoaEbr/xWG3HGYjHMnQIbC8qs<object>[]))]
			internal static void ce4DmfsmSrOT856tDgfrkMb()
			{
				if (Y1jOQDOKds(Convert.ToBase64String(typeof(ETZxusFl8KUvQCslGf).Assembly.GetName().GetPublicKeyToken()), ETZxusFl8KUvQCslGf.pasOtyYaWV(1746)) != ETZxusFl8KUvQCslGf.pasOtyYaWV(1752))
				{
					while (true)
					{
						ce4DmfsmSrOT856tDgfrkMb();
					}
				}
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			[mrqRnf10S5UMFoaEbr(typeof(ETZxusFl8KUvQCslGf/mrqRnf10S5UMFoaEbr/xWG3HGYjHMnQIbC8qs<object>[]))]
			internal static string Y1jOQDOKds(string P_0, string P_1)
			{
				byte[] bytes = Encoding.Unicode.GetBytes(P_0);
				byte[] array = bytes;
				byte[] key = new byte[32]
				{
					82, 102, 104, 110, 32, 77, 24, 34, 118, 181,
					51, 17, 18, 51, 12, 109, 10, 32, 77, 24,
					34, 158, 161, 41, 97, 28, 118, 181, 5, 25,
					1, 88
				};
				MD5 mD = new MD5CryptoServiceProvider();
				byte[] iV = mD.ComputeHash(Encoding.Unicode.GetBytes(P_1));
				MemoryStream memoryStream = new MemoryStream();
				Rijndael rijndael = Rijndael.Create();
				rijndael.Key = key;
				rijndael.IV = iV;
				CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateEncryptor(), CryptoStreamMode.Write);
				cryptoStream.Write(array, 0, array.Length);
				cryptoStream.Close();
				return Convert.ToBase64String(memoryStream.ToArray());
			}

			[MethodImpl(MethodImplOptions.NoInlining)]
			public KFrFYGuW8nCwug3o9R()
			{
				IE3dyJf2OKPAA7hD1W.ugrjvXWz48stp();
				base..ctor();
			}
		}

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		internal delegate uint I54drxvS0qn1HqLXvT([MarshalAs(UnmanagedType.U8)] ref ulong classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, ref IntPtr nativeEntry, ref uint nativeSizeOfCode);

		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		private delegate IntPtr JnKCShMyqkYjEOQogc();

		internal struct pbDHi3yiFiQhfu4nl6
		{
			internal bool FaXOJKGP97;

			internal byte[] dFiOxX5Ogr;
		}

		[Flags]
		private enum FRiYj6gHwPnfoAe8Fc
		{

		}

		private static byte[] DoyOlxxYuI;

		private static byte[] hWmOyvG0fy;

		private static IntPtr eLhOuPJgB7;

		private static object ELHOa8fZco;

		private static bool jXHOgh7sYM;

		private static int tgbOexnZZb;

		private static int nubObHD01P;

		internal static I54drxvS0qn1HqLXvT dsvOYFH7s5;

		private static long NQfOSvwC5v;

		private static int gZWOi4xMjI;

		private static bool PObOnLx1Cx;

		private static SortedList cwyO87yMnM;

		private static long GW3OdgJ7VV;

		internal static I54drxvS0qn1HqLXvT AOtOVBooSP;

		private static IntPtr uj3OEXAknp;

		private static int[] LkoO2L1oWO;

		private static byte[] xuaOL2E7Kx;

		internal static Hashtable xJ0OUiA9Rm;

		private static int q6fO75hurt;

		private static IntPtr JnnOflxKvs;

		private static byte[] eDoOhWoWRh;

		[MethodImpl(MethodImplOptions.NoInlining)]
		static ETZxusFl8KUvQCslGf()
		{
			eDoOhWoWRh = new byte[0];
			xuaOL2E7Kx = new byte[0];
			DoyOlxxYuI = new byte[0];
			hWmOyvG0fy = new byte[0];
			eLhOuPJgB7 = IntPtr.Zero;
			JnnOflxKvs = IntPtr.Zero;
			ELHOa8fZco = new string[0];
			LkoO2L1oWO = new int[0];
			gZWOi4xMjI = 1;
			jXHOgh7sYM = false;
			cwyO87yMnM = new SortedList();
			q6fO75hurt = 0;
			GW3OdgJ7VV = 0L;
			dsvOYFH7s5 = null;
			AOtOVBooSP = null;
			NQfOSvwC5v = 0L;
			tgbOexnZZb = 0;
			PObOnLx1Cx = false;
			nubObHD01P = 0;
			uj3OEXAknp = IntPtr.Zero;
			xJ0OUiA9Rm = new Hashtable();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private void gSZjvXWoo7MAW()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[mrqRnf10S5UMFoaEbr(typeof(ETZxusFl8KUvQCslGf/mrqRnf10S5UMFoaEbr/xWG3HGYjHMnQIbC8qs<object>[]))]
		static string pasOtyYaWV(int P_0)
		{
			int num = 103;
			byte[] array2 = default(byte[]);
			int num8 = default(int);
			int num4 = default(int);
			CryptoStream cryptoStream = default(CryptoStream);
			byte[] array6 = default(byte[]);
			int num7 = default(int);
			MemoryStream memoryStream = default(MemoryStream);
			ICryptoTransform transform = default(ICryptoTransform);
			byte[] array = default(byte[]);
			int num6 = default(int);
			byte[] array4 = default(byte[]);
			BinaryReader binaryReader = default(BinaryReader);
			RijndaelManaged rijndaelManaged = default(RijndaelManaged);
			byte[] array3 = default(byte[]);
			byte[] array5 = default(byte[]);
			int num3 = default(int);
			while (true)
			{
				int num5;
				int num2;
				switch (num)
				{
				case 122:
					array2[3] = (byte)num8;
					num5 = 46;
					goto IL_077e;
				case 98:
					num4 = 214 - 71;
					num2 = 160;
					if (!ro8wtY6RHglKCKFknS())
					{
						goto case 26;
					}
					goto IL_0782;
				case 214:
					num4 = 114 + 63;
					num2 = 111;
					goto IL_0782;
				case 307:
					num4 = 26 + 81;
					num2 = 217;
					if (false)
					{
						goto case 2;
					}
					goto IL_0782;
				case 2:
					array2[9] = 142;
					num2 = 153;
					if (1 == 0)
					{
						goto case 311;
					}
					goto IL_0782;
				case 311:
					jdswuN0P0uaYQGk94m(cryptoStream, array6, 0, array6.Length);
					num2 = 138;
					if (!ro8wtY6RHglKCKFknS())
					{
						goto case 27;
					}
					goto IL_0782;
				case 27:
					array2[5] = (byte)num7;
					num2 = 29;
					if (!ro8wtY6RHglKCKFknS())
					{
						goto case 78;
					}
					goto IL_0782;
				case 78:
					array2[12] = 195;
					num5 = 117;
					goto IL_077e;
				case 306:
					cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
					num = 311;
					break;
				case 203:
					num4 = 9 + 97;
					num2 = 9;
					if (ro8wtY6RHglKCKFknS())
					{
						goto IL_0782;
					}
					goto case 96;
				case 167:
					array[15] = 142;
					num = 76;
					break;
				case 80:
					array2[15] = (byte)num7;
					num2 = 256;
					goto IL_0782;
				case 109:
					num6 = 124 + 123;
					num2 = 344;
					goto IL_0782;
				case 254:
					array2[8] = 159;
					num = 221;
					break;
				case 43:
					num7 = 11 + 41;
					num2 = 329;
					if (!fvFwOGq5SY8efUWHZX())
					{
						goto IL_0782;
					}
					goto case 113;
				case 345:
					array[31] = (byte)num6;
					num5 = 30;
					goto IL_077e;
				case 299:
					num8 = 183 - 61;
					num2 = 287;
					goto IL_0782;
				case 50:
					num6 = 62 + 62;
					num2 = 291;
					if (false)
					{
						goto case 148;
					}
					goto IL_0782;
				case 148:
					array[4] = (byte)num6;
					num = 57;
					break;
				case 266:
					array[16] = (byte)num6;
					num = 198;
					break;
				case 108:
					array[11] = 92;
					num2 = 23;
					goto IL_0782;
				case 45:
					if (array4.Length > 0)
					{
						num = 65;
						break;
					}
					goto case 161;
				case 212:
					num8 = 12 - 11;
					num2 = 163;
					if (1 == 0)
					{
						goto case 278;
					}
					goto IL_0782;
				case 278:
					array[8] = 85;
					num5 = 5;
					goto IL_077e;
				case 260:
					array2[4] = 197;
					num = 312;
					break;
				case 158:
					array[8] = 63;
					num2 = 82;
					goto IL_0782;
				case 267:
					array2[0] = (byte)num7;
					num2 = 28;
					if (false)
					{
						goto case 30;
					}
					goto IL_0782;
				case 30:
					num4 = 25 + 99;
					num2 = 12;
					if (ro8wtY6RHglKCKFknS())
					{
						goto IL_0782;
					}
					goto case 23;
				case 344:
					array[30] = (byte)num6;
					num2 = 189;
					goto IL_0782;
				case 170:
					array2[0] = 23;
					num5 = 299;
					goto IL_077e;
				case 97:
					num6 = 160 + 91;
					num5 = 181;
					goto IL_077e;
				case 245:
					array[5] = (byte)num6;
					num2 = 58;
					if (false)
					{
						goto case 330;
					}
					goto IL_0782;
				case 330:
					array[0] = (byte)num6;
					num2 = 319;
					if (1 == 0)
					{
						goto case 202;
					}
					goto IL_0782;
				case 202:
					num6 = 81 + 48;
					num = 283;
					break;
				case 351:
					array6 = (byte[])XEgwdqxK8D7MYZ5SwK(binaryReader, (int)EXWIeMvN9NwgPAlhx2(j5NnY3KbOqb8XoFRvA(binaryReader)));
					num = 90;
					break;
				case 133:
					num7 = 87 + 120;
					num2 = 199;
					goto IL_0782;
				case 68:
					num6 = 134 - 44;
					num = 313;
					break;
				case 42:
					array2[3] = 124;
					num5 = 118;
					goto IL_077e;
				case 198:
					num4 = 163 - 54;
					num2 = 348;
					if (false)
					{
						goto case 3;
					}
					goto IL_0782;
				case 3:
					num4 = 42 + 104;
					num2 = 347;
					if (fvFwOGq5SY8efUWHZX())
					{
						goto case 90;
					}
					goto IL_0782;
				case 90:
					array = new byte[32];
					num = 31;
					break;
				case 208:
					tWp2kSUtaVU1DRSUeS(memoryStream);
					num = 61;
					break;
				case 317:
					num7 = 129 + 23;
					num2 = 354;
					if (1 == 0)
					{
						goto case 87;
					}
					goto IL_0782;
				case 87:
					array2[8] = 210;
					num = 2;
					break;
				case 26:
					array[31] = (byte)num6;
					num2 = 159;
					goto IL_0782;
				case 85:
					array2[10] = (byte)num8;
					num2 = 274;
					if (!ro8wtY6RHglKCKFknS())
					{
						goto case 342;
					}
					goto IL_0782;
				case 342:
					array2[14] = (byte)num7;
					num = 308;
					break;
				case 273:
					array[15] = (byte)num6;
					num2 = 261;
					if (1 == 0)
					{
						goto case 279;
					}
					goto IL_0782;
				case 279:
					array[25] = 136;
					num5 = 219;
					goto IL_077e;
				case 189:
					num4 = 24 + 111;
					num5 = 305;
					goto IL_077e;
				case 32:
					array[4] = 41;
					num5 = 51;
					goto IL_077e;
				case 119:
					num6 = 112 + 56;
					num5 = 328;
					goto IL_077e;
				case 193:
					num7 = 143 - 47;
					num2 = 316;
					if (fvFwOGq5SY8efUWHZX())
					{
						goto case 13;
					}
					goto IL_0782;
				case 13:
					array[21] = (byte)num4;
					num2 = 203;
					goto IL_0782;
				case 51:
					array[4] = 142;
					num2 = 253;
					goto IL_0782;
				case 288:
					num7 = 212 - 70;
					num5 = 80;
					goto IL_077e;
				case 219:
					num6 = 217 - 72;
					num = 226;
					break;
				case 289:
				case 302:
					num7 = 28 + 81;
					num5 = 41;
					goto IL_077e;
				case 261:
					num6 = 145 - 72;
					num5 = 309;
					goto IL_077e;
				case 175:
					num6 = 217 - 72;
					num2 = 345;
					if (false)
					{
						goto case 201;
					}
					goto IL_0782;
				case 201:
					num4 = 110 + 105;
					num5 = 69;
					goto IL_077e;
				case 154:
					num6 = 55 + 71;
					num = 293;
					break;
				case 120:
					array2[11] = 149;
					num5 = 127;
					goto IL_077e;
				case 259:
					array4 = (byte[])IqesVkZEAsFZQGLxQj(Qk2EbBGl7NmVPGW6Or(FxU8baSu1GG9oHdN89(typeof(ETZxusFl8KUvQCslGf).TypeHandle).Assembly));
					num = 269;
					break;
				case 314:
					num4 = 187 - 79;
					goto case 35;
				default:
					num2 = 35;
					goto IL_0782;
				case 130:
					num4 = 236 - 78;
					num = 72;
					break;
				case 271:
					C2na4EHtd4aYqSJCsE(rijndaelManaged, CipherMode.CBC);
					num = 176;
					break;
				case 286:
					num6 = 81 + 98;
					num2 = 266;
					goto IL_0782;
				case 293:
					array[22] = (byte)num6;
					num2 = 257;
					if (true)
					{
						goto IL_0782;
					}
					goto case 192;
				case 192:
					num6 = 51 - 47;
					num = 18;
					break;
				case 269:
					if (array4 != null)
					{
						num5 = 45;
						goto IL_077e;
					}
					goto case 161;
				case 186:
					num4 = 69 + 109;
					num5 = 164;
					goto IL_077e;
				case 352:
					num4 = 180 - 60;
					num2 = 268;
					goto IL_0782;
				case 56:
					array[1] = (byte)num4;
					num = 211;
					break;
				case 347:
					array[17] = (byte)num4;
					num = 152;
					break;
				case 92:
					array[7] = 159;
					num = 75;
					break;
				case 182:
					array[4] = (byte)num4;
					num2 = 327;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 118;
				case 118:
					array2[3] = 28;
					num = 183;
					break;
				case 339:
					array2[15] = 147;
					num5 = 288;
					goto IL_077e;
				case 322:
					array[24] = 148;
					num2 = 121;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 72;
				case 72:
					array[9] = (byte)num4;
					num2 = 156;
					goto IL_0782;
				case 187:
					array3[5] = array4[2];
					num2 = 112;
					goto IL_0782;
				case 355:
					array[27] = 124;
					num2 = 232;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 341;
				case 341:
					num7 = 6 + 36;
					num = 267;
					break;
				case 327:
					array[5] = 168;
					num = 79;
					break;
				case 164:
					array[18] = (byte)num4;
					num2 = 290;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 144;
				case 144:
					num4 = 65 + 107;
					num2 = 239;
					goto IL_0782;
				case 200:
					num4 = 112 + 63;
					num2 = 185;
					goto IL_0782;
				case 172:
				case 297:
					num8 = 224 - 74;
					num2 = 249;
					goto IL_0782;
				case 39:
					array[19] = (byte)num4;
					num2 = 280;
					goto IL_0782;
				case 82:
					array[8] = 125;
					num2 = 149;
					if (true)
					{
						goto IL_0782;
					}
					goto case 149;
				case 149:
					array[9] = 137;
					num2 = 224;
					if (ro8wtY6RHglKCKFknS())
					{
						goto IL_0782;
					}
					goto case 62;
				case 155:
					num6 = 39 + 95;
					num2 = 335;
					goto IL_0782;
				case 76:
					num6 = 208 - 69;
					num5 = 273;
					goto IL_077e;
				case 298:
					num6 = 193 - 64;
					num5 = 14;
					goto IL_077e;
				case 48:
					num8 = 124 + 57;
					num5 = 204;
					goto IL_077e;
				case 141:
					array[18] = 106;
					num2 = 200;
					goto IL_0782;
				case 295:
					num4 = 79 + 112;
					num5 = 353;
					goto IL_077e;
				case 292:
					array[7] = 88;
					num5 = 92;
					goto IL_077e;
				case 91:
					num6 = 11 + 50;
					num5 = 53;
					goto IL_077e;
				case 233:
					array2[13] = (byte)num7;
					num2 = 157;
					goto IL_0782;
				case 316:
					array2[12] = (byte)num7;
					num2 = 78;
					if (ro8wtY6RHglKCKFknS())
					{
						goto IL_0782;
					}
					goto case 76;
				case 308:
					array2[14] = 98;
					num5 = 184;
					goto IL_077e;
				case 4:
					num4 = 65 + 67;
					num5 = 39;
					goto IL_077e;
				case 199:
					array2[10] = (byte)num7;
					ro8wtY6RHglKCKFknS();
					if (!fvFwOGq5SY8efUWHZX())
					{
						num2 = 172;
						if (ro8wtY6RHglKCKFknS())
						{
							goto IL_0782;
						}
						goto case 169;
					}
					num5 = 289;
					goto IL_077e;
				case 71:
					array[10] = 81;
					num5 = 205;
					goto IL_077e;
				case 138:
					eJMJacBmSxEIQBS4mf(cryptoStream);
					num5 = 331;
					goto IL_077e;
				case 136:
					num4 = 60 + 90;
					num5 = 190;
					goto IL_077e;
				case 178:
					array2[1] = (byte)num7;
					num2 = 209;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 169;
				case 169:
					num7 = 67 + 108;
					num5 = 178;
					goto IL_077e;
				case 79:
					array[5] = 122;
					num2 = 143;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 100;
				case 100:
					array2[6] = 148;
					num = 168;
					break;
				case 257:
					array[23] = 169;
					num2 = 21;
					goto IL_0782;
				case 145:
					array[6] = 19;
					num5 = 123;
					goto IL_077e;
				case 191:
					array2[7] = (byte)num7;
					num5 = 54;
					goto IL_077e;
				case 55:
					array[19] = 19;
					num = 202;
					break;
				case 77:
					num8 = 102 + 60;
					num5 = 66;
					goto IL_077e;
				case 40:
					array[17] = (byte)num6;
					num2 = 248;
					if (!ro8wtY6RHglKCKFknS())
					{
						goto case 87;
					}
					goto IL_0782;
				case 234:
					num8 = 92 + 75;
					num2 = 85;
					if (true)
					{
						goto IL_0782;
					}
					goto case 140;
				case 140:
					array[17] = 71;
					num2 = 3;
					if (ro8wtY6RHglKCKFknS())
					{
						goto IL_0782;
					}
					goto case 303;
				case 23:
					array[12] = 204;
					num2 = 220;
					goto IL_0782;
				case 294:
					array[30] = (byte)num4;
					num = 36;
					break;
				case 160:
					array[22] = (byte)num4;
					num2 = 284;
					goto IL_0782;
				case 277:
					array[21] = 64;
					num5 = 263;
					goto IL_077e;
				case 197:
					num7 = 92 + 50;
					num2 = 342;
					if (true)
					{
						goto IL_0782;
					}
					goto case 180;
				case 180:
					array2[10] = (byte)num7;
					num = 318;
					break;
				case 159:
					array5 = array;
					num5 = 128;
					goto IL_077e;
				case 282:
					array[13] = (byte)num4;
					num2 = 252;
					goto IL_0782;
				case 194:
					num7 = 93 + 63;
					num = 131;
					break;
				case 166:
					num6 = 216 - 72;
					num = 330;
					break;
				case 174:
					array[8] = (byte)num4;
					num5 = 15;
					goto IL_077e;
				case 156:
					array[9] = 137;
					num = 151;
					break;
				case 195:
					array[30] = (byte)num4;
					num5 = 74;
					goto IL_077e;
				case 179:
					array2[7] = 140;
					num5 = 105;
					goto IL_077e;
				case 242:
					num4 = 163 - 66;
					num2 = 229;
					if (!ro8wtY6RHglKCKFknS())
					{
						goto case 193;
					}
					goto IL_0782;
				case 283:
					array[20] = (byte)num6;
					num5 = 213;
					goto IL_077e;
				case 11:
					num6 = 195 - 65;
					num5 = 116;
					goto IL_077e;
				case 29:
					num7 = 111 + 122;
					num2 = 37;
					goto IL_0782;
				case 70:
					array3[11] = array4[5];
					num = 237;
					break;
				case 226:
					array[25] = (byte)num6;
					num = 334;
					break;
				case 324:
					array[27] = (byte)num6;
					num2 = 355;
					goto IL_0782;
				case 287:
					array2[0] = (byte)num8;
					num = 341;
					break;
				case 34:
					array2[4] = 108;
					num5 = 260;
					goto IL_077e;
				case 313:
					array[22] = (byte)num6;
					num = 154;
					break;
				case 111:
					array[21] = (byte)num4;
					num5 = 119;
					goto IL_077e;
				case 331:
					DoyOlxxYuI = (byte[])pTT3pHTHIFunbGoWg7(memoryStream);
					num5 = 208;
					goto IL_077e;
				case 128:
					array2 = new byte[16];
					num2 = 48;
					goto IL_0782;
				case 251:
					array[27] = 163;
					num5 = 196;
					goto IL_077e;
				case 276:
					num6 = 92 + 11;
					num = 230;
					break;
				case 150:
					array[13] = 64;
					num = 95;
					break;
				case 0:
					array2[12] = (byte)num8;
					num5 = 333;
					goto IL_077e;
				case 151:
					num4 = 40 + 42;
					num2 = 104;
					goto IL_0782;
				case 329:
					array2[6] = (byte)num7;
					num = 272;
					break;
				case 263:
					array[21] = 145;
					num5 = 81;
					goto IL_077e;
				case 250:
					array[2] = (byte)num6;
					num = 136;
					break;
				case 305:
					array[30] = (byte)num4;
					num2 = 228;
					goto IL_0782;
				case 96:
					array[14] = (byte)num6;
					num2 = 332;
					goto IL_0782;
				case 121:
					array[24] = 78;
					num = 314;
					break;
				case 93:
					num7 = 175 - 58;
					num5 = 191;
					goto IL_077e;
				case 309:
					array[15] = (byte)num6;
					num = 286;
					break;
				case 139:
					num6 = 147 - 49;
					num2 = 96;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 229;
				case 229:
					array[20] = (byte)num4;
					num5 = 73;
					goto IL_077e;
				case 14:
					array[19] = (byte)num6;
					num2 = 218;
					if (!fvFwOGq5SY8efUWHZX())
					{
						goto IL_0782;
					}
					goto case 157;
				case 157:
					num7 = 153 - 51;
					num2 = 300;
					if (true)
					{
						goto IL_0782;
					}
					goto case 356;
				case 356:
					num8 = 132 - 44;
					num2 = 60;
					goto IL_0782;
				case 228:
					num4 = 236 - 78;
					num = 195;
					break;
				case 37:
					array2[5] = (byte)num7;
					num = 337;
					break;
				case 290:
					array[18] = 209;
					num2 = 141;
					if (true)
					{
						goto IL_0782;
					}
					goto case 18;
				case 18:
					array[3] = (byte)num6;
					num2 = 32;
					goto IL_0782;
				case 270:
					num4 = 109 + 0;
					num5 = 86;
					goto IL_077e;
				case 183:
					num8 = 179 - 59;
					num2 = 122;
					if (true)
					{
						goto IL_0782;
					}
					goto case 36;
				case 36:
					num6 = 216 - 72;
					num5 = 6;
					goto IL_077e;
				case 101:
					array[5] = 8;
					num = 241;
					break;
				case 239:
					array[2] = (byte)num4;
					num2 = 102;
					goto IL_0782;
				case 284:
					array[22] = 98;
					num5 = 68;
					goto IL_077e;
				case 99:
					array2[8] = 127;
					num = 194;
					break;
				case 135:
					array[16] = 68;
					num5 = 352;
					goto IL_077e;
				case 346:
					array2[15] = 55;
					num5 = 304;
					goto IL_077e;
				case 66:
					array2[2] = (byte)num8;
					num2 = 210;
					if (true)
					{
						goto IL_0782;
					}
					goto case 332;
				case 332:
					array[14] = 211;
					num2 = 201;
					goto IL_0782;
				case 349:
					array2[4] = 100;
					num5 = 34;
					goto IL_077e;
				case 152:
					num6 = 52 + 122;
					num5 = 40;
					goto IL_077e;
				case 41:
					array2[11] = (byte)num7;
					num2 = 262;
					if (true)
					{
						goto IL_0782;
					}
					goto case 255;
				case 255:
					array3[9] = array4[4];
					num2 = 70;
					if (true)
					{
						goto IL_0782;
					}
					goto case 9;
				case 9:
					array[21] = (byte)num4;
					num5 = 214;
					goto IL_077e;
				case 62:
					num4 = 190 - 63;
					num2 = 174;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 61;
				case 61:
					tWp2kSUtaVU1DRSUeS(cryptoStream);
					num = 115;
					break;
				case 354:
					array2[1] = (byte)num7;
					num5 = 89;
					goto IL_077e;
				case 137:
					num6 = 126 - 42;
					num2 = 171;
					if (!fvFwOGq5SY8efUWHZX())
					{
						goto IL_0782;
					}
					goto case 72;
				case 132:
					do
					{
						num6 = 15 + 93;
						num2 = 250;
					}
					while (!ro8wtY6RHglKCKFknS());
					goto IL_0782;
				case 89:
					num7 = 141 - 47;
					num2 = 8;
					goto IL_0782;
				case 142:
					num6 = 215 - 71;
					num = 222;
					break;
				case 225:
					num7 = 199 - 66;
					num5 = 180;
					goto IL_077e;
				case 126:
					binaryReader = new BinaryReader((Stream)yxQxBB4q1kQa49GQ5A(FxU8baSu1GG9oHdN89(typeof(ETZxusFl8KUvQCslGf).TypeHandle).Assembly, "3KgM4RaApu7NwMMYPo.ThdErDmsRugkQITNVG"));
					num2 = 275;
					goto IL_0782;
				case 163:
					array2[5] = (byte)num8;
					num = 356;
					break;
				case 86:
					array[11] = (byte)num4;
					num = 108;
					break;
				case 117:
					num8 = 146 - 59;
					num5 = 0;
					goto IL_077e;
				case 211:
					array[1] = 29;
					num2 = 64;
					if (ro8wtY6RHglKCKFknS())
					{
						goto IL_0782;
					}
					goto case 253;
				case 253:
					array[4] = 190;
					num5 = 7;
					goto IL_077e;
				case 338:
					array2[1] = (byte)num8;
					num2 = 317;
					goto IL_0782;
				case 104:
					array[10] = (byte)num4;
					num2 = 142;
					if (!ro8wtY6RHglKCKFknS())
					{
						goto case 330;
					}
					goto IL_0782;
				case 105:
					array2[7] = 90;
					num5 = 254;
					goto IL_077e;
				case 265:
					array3[3] = array4[1];
					num5 = 187;
					goto IL_077e;
				case 84:
					jCSa8EaKvNxck1Zxbv(true);
					num2 = 351;
					if (ro8wtY6RHglKCKFknS())
					{
						goto IL_0782;
					}
					goto case 186;
				case 249:
					array2[10] = (byte)num8;
					num5 = 234;
					goto IL_077e;
				case 256:
					array2[15] = 93;
					num = 22;
					break;
				case 333:
					array2[13] = 165;
					num2 = 114;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 83;
				case 83:
					array[8] = (byte)num4;
					num5 = 62;
					goto IL_077e;
				case 272:
					array2[6] = 114;
					num5 = 100;
					goto IL_077e;
				case 310:
					num7 = 151 - 84;
					num5 = 233;
					goto IL_077e;
				case 185:
					array[18] = (byte)num4;
					num5 = 323;
					goto IL_077e;
				case 340:
					num4 = 128 + 59;
					num2 = 16;
					if (true)
					{
						goto IL_0782;
					}
					goto case 177;
				case 177:
					array[28] = 237;
					num5 = 147;
					goto IL_077e;
				case 147:
					array[29] = 150;
					num2 = 33;
					goto IL_0782;
				case 337:
					array2[5] = 145;
					num = 326;
					break;
				case 165:
					array[14] = 142;
					num = 139;
					break;
				case 69:
					array[14] = (byte)num4;
					num2 = 1;
					if (!fvFwOGq5SY8efUWHZX())
					{
						goto IL_0782;
					}
					goto case 272;
				case 22:
					array2[15] = 92;
					num2 = 346;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 38;
				case 38:
					array[23] = 186;
					num = 91;
					break;
				case 21:
					array[23] = 49;
					num2 = 134;
					goto IL_0782;
				case 241:
					num6 = 126 - 41;
					num2 = 245;
					if (true)
					{
						goto IL_0782;
					}
					goto case 275;
				case 275:
					K9ogIGCkqlfUSEy0Mm(j5NnY3KbOqb8XoFRvA(binaryReader), 0L);
					num2 = 84;
					goto IL_0782;
				case 184:
					num8 = 221 - 73;
					num5 = 129;
					goto IL_077e;
				case 224:
					num6 = 90 + 69;
					num = 47;
					break;
				case 134:
					array[23] = 136;
					num = 25;
					break;
				case 49:
					num7 = 143 + 90;
					num = 17;
					break;
				case 173:
					num4 = 140 + 21;
					num2 = 24;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 75;
				case 75:
					array[7] = 232;
					num5 = 278;
					goto IL_077e;
				case 176:
					transform = (ICryptoTransform)dKBxTQNSjxSRuIXhuL(rijndaelManaged, array5, array3);
					num2 = 206;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 190;
				case 190:
					array[2] = (byte)num4;
					num2 = 144;
					if (true)
					{
						goto IL_0782;
					}
					goto case 67;
				case 67:
					array2[4] = (byte)num8;
					num2 = 125;
					goto IL_0782;
				case 350:
					num7 = 43 + 26;
					num2 = 44;
					if (ro8wtY6RHglKCKFknS())
					{
						goto IL_0782;
					}
					goto case 237;
				case 237:
					array3[13] = array4[6];
					num = 315;
					break;
				case 315:
					array3[15] = array4[7];
					num2 = 161;
					goto IL_0782;
				case 63:
					array[29] = (byte)num6;
					num5 = 243;
					goto IL_077e;
				case 213:
					num6 = 170 - 56;
					num2 = 19;
					goto IL_0782;
				case 268:
					array[17] = (byte)num4;
					num2 = 246;
					goto IL_0782;
				case 304:
					array3 = array2;
					num5 = 259;
					goto IL_077e;
				case 248:
					num4 = 64 + 71;
					num = 358;
					break;
				case 146:
					array2[2] = (byte)num8;
					num2 = 223;
					goto IL_0782;
				case 258:
					num6 = 82 + 101;
					num5 = 26;
					goto IL_077e;
				case 280:
					array[19] = 149;
					num = 55;
					break;
				case 52:
					num4 = 127 - 42;
					num2 = 231;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 102;
				case 102:
					array[2] = 144;
					num2 = 50;
					if (true)
					{
						goto IL_0782;
					}
					goto case 15;
				case 15:
					array[8] = 121;
					num5 = 158;
					goto IL_077e;
				case 281:
					array[26] = 146;
					num = 307;
					break;
				case 335:
					array[12] = (byte)num6;
					num5 = 110;
					goto IL_077e;
				case 348:
					array[16] = (byte)num4;
					num5 = 135;
					goto IL_077e;
				case 181:
					array[0] = (byte)num6;
					num2 = 11;
					if (ro8wtY6RHglKCKFknS())
					{
						goto IL_0782;
					}
					goto case 237;
				case 334:
					array[25] = 115;
					num2 = 281;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 47;
				case 47:
					array[9] = (byte)num6;
					num2 = 130;
					if (!fvFwOGq5SY8efUWHZX())
					{
						goto IL_0782;
					}
					goto case 28;
				case 28:
					array2[0] = 172;
					num = 169;
					break;
				case 319:
					num6 = 51 + 6;
					num = 238;
					break;
				case 301:
					num4 = 130 - 43;
					num = 303;
					break;
				case 343:
					num4 = 120 + 98;
					num = 59;
					break;
				case 54:
					array2[7] = 148;
					num5 = 179;
					goto IL_077e;
				case 296:
					array[19] = (byte)num4;
					num = 298;
					break;
				case 95:
					array[14] = 82;
					num2 = 165;
					if (!fvFwOGq5SY8efUWHZX())
					{
						goto IL_0782;
					}
					goto case 236;
				case 236:
					num4 = 171 + 58;
					num = 94;
					break;
				case 230:
					array[5] = (byte)num6;
					num5 = 101;
					goto IL_077e;
				case 326:
					array2[5] = 124;
					num = 212;
					break;
				case 116:
					array[1] = (byte)num6;
					num2 = 285;
					if (!fvFwOGq5SY8efUWHZX())
					{
						goto IL_0782;
					}
					goto case 110;
				case 110:
					num4 = 100 + 85;
					num2 = 282;
					if (ro8wtY6RHglKCKFknS())
					{
						goto IL_0782;
					}
					goto case 56;
				case 321:
					array[13] = (byte)num4;
					num5 = 150;
					goto IL_077e;
				case 125:
					num7 = 107 + 121;
					num2 = 27;
					if (true)
					{
						goto IL_0782;
					}
					goto case 12;
				case 12:
					array[31] = (byte)num4;
					num2 = 258;
					if (true)
					{
						goto IL_0782;
					}
					goto case 60;
				case 60:
					array2[6] = (byte)num8;
					num2 = 43;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 10;
				case 10:
					array[0] = 91;
					num2 = 166;
					if (!fvFwOGq5SY8efUWHZX())
					{
						goto IL_0782;
					}
					goto case 348;
				case 6:
					array[30] = (byte)num6;
					num2 = 109;
					if (!fvFwOGq5SY8efUWHZX())
					{
						goto IL_0782;
					}
					goto case 196;
				case 196:
					num6 = 64 + 23;
					num = 113;
					break;
				case 221:
					array2[8] = 47;
					num = 99;
					break;
				case 127:
					array2[11] = 97;
					num2 = 350;
					goto IL_0782;
				case 57:
					num4 = 113 + 44;
					num = 182;
					break;
				case 223:
					array2[3] = 134;
					num5 = 42;
					goto IL_077e;
				case 107:
					array[27] = 158;
					num = 124;
					break;
				case 131:
					array2[8] = (byte)num7;
					num2 = 87;
					goto IL_0782;
				case 88:
					array[12] = (byte)num4;
					num5 = 20;
					goto IL_077e;
				case 44:
					array2[12] = (byte)num7;
					num2 = 193;
					goto IL_0782;
				case 31:
					num4 = 124 + 57;
					num2 = 207;
					if (!fvFwOGq5SY8efUWHZX())
					{
						goto IL_0782;
					}
					goto case 141;
				case 274:
					array2[11] = 84;
					goto case 289;
				case 244:
					array[3] = (byte)num6;
					num2 = 192;
					goto IL_0782;
				case 53:
					array[24] = (byte)num6;
					num2 = 240;
					goto IL_0782;
				case 64:
					array[2] = 100;
					num = 132;
					break;
				case 243:
					array[29] = 126;
					num2 = 173;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 81;
				case 81:
					array[22] = 87;
					num2 = 295;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 262;
				case 262:
					array2[11] = 146;
					num2 = 120;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 123;
				case 123:
					array[6] = 107;
					num2 = 236;
					if (ro8wtY6RHglKCKFknS())
					{
						goto IL_0782;
					}
					goto case 94;
				case 94:
					array[6] = (byte)num4;
					num5 = 292;
					goto IL_077e;
				case 115:
					XaosKdcegDXPIXAEuc(binaryReader);
					num5 = 359;
					goto IL_077e;
				case 113:
					array[27] = (byte)num6;
					num2 = 216;
					goto IL_0782;
				case 124:
					num6 = 225 - 75;
					num2 = 324;
					if (true)
					{
						goto IL_0782;
					}
					goto case 238;
				case 238:
					array[0] = (byte)num6;
					num5 = 97;
					goto IL_077e;
				case 8:
					array2[2] = (byte)num7;
					num2 = 77;
					if (true)
					{
						goto IL_0782;
					}
					goto case 328;
				case 328:
					array[21] = (byte)num6;
					num = 277;
					break;
				case 103:
					if (DoyOlxxYuI.Length == 0)
					{
						num = 126;
						break;
					}
					goto case 359;
				case 318:
					num7 = 169 - 56;
					num5 = 336;
					goto IL_077e;
				case 7:
					num6 = 24 + 107;
					num2 = 148;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 285;
				case 285:
					num4 = 226 - 75;
					num = 56;
					break;
				case 264:
					array2[9] = 104;
					num2 = 49;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 357;
				case 357:
					num4 = 15 + 43;
					num = 88;
					break;
				case 232:
					num4 = 87 + 74;
					num = 227;
					break;
				case 24:
					array[29] = (byte)num4;
					num2 = 106;
					if (!fvFwOGq5SY8efUWHZX())
					{
						goto IL_0782;
					}
					goto case 135;
				case 323:
					num4 = 140 - 46;
					num2 = 296;
					if (ro8wtY6RHglKCKFknS())
					{
						goto IL_0782;
					}
					goto case 58;
				case 58:
					array[6] = 160;
					num = 145;
					break;
				case 65:
					array3[1] = array4[0];
					num2 = 265;
					goto IL_0782;
				case 73:
					num4 = 106 + 99;
					num = 13;
					break;
				case 112:
					array3[7] = array4[3];
					num5 = 255;
					goto IL_077e;
				case 143:
					array[5] = 113;
					num2 = 276;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 210;
				case 210:
					num8 = 115 - 69;
					num = 146;
					break;
				case 46:
					array2[3] = 8;
					num = 349;
					break;
				case 353:
					array[22] = (byte)num4;
					num2 = 98;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 312;
				case 312:
					num8 = 80 - 32;
					num2 = 67;
					goto IL_0782;
				case 204:
					array2[0] = (byte)num8;
					num5 = 170;
					goto IL_077e;
				case 252:
					array[13] = 157;
					num2 = 247;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 291;
				case 291:
					array[3] = (byte)num6;
					num2 = 52;
					if (true)
					{
						goto IL_0782;
					}
					goto case 153;
				case 153:
					array2[9] = 63;
					num2 = 264;
					goto IL_0782;
				case 235:
					num6 = 237 - 79;
					num5 = 244;
					goto IL_077e;
				case 74:
					array[30] = 206;
					num = 175;
					break;
				case 222:
					array[10] = (byte)num6;
					num2 = 71;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 5;
				case 5:
					num4 = 22 + 6;
					num = 83;
					break;
				case 106:
					num4 = 246 - 82;
					num2 = 294;
					goto IL_0782;
				case 336:
					array2[10] = (byte)num7;
					num = 133;
					break;
				case 162:
					array2[14] = 252;
					num = 325;
					break;
				case 218:
					array[19] = 153;
					num5 = 4;
					goto IL_077e;
				case 114:
					num8 = 189 - 63;
					num2 = 320;
					if (true)
					{
						goto IL_0782;
					}
					goto case 17;
				case 17:
					array2[9] = (byte)num7;
					num2 = 215;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 320;
				case 320:
					array2[13] = (byte)num8;
					num2 = 310;
					if (true)
					{
						goto IL_0782;
					}
					goto case 209;
				case 209:
					num8 = 252 - 84;
					num2 = 338;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 247;
				case 247:
					num4 = 118 + 62;
					num2 = 321;
					if (true)
					{
						goto IL_0782;
					}
					goto case 303;
				case 303:
					array[17] = (byte)num4;
					num5 = 140;
					goto IL_077e;
				case 129:
					array2[14] = (byte)num8;
					num5 = 162;
					goto IL_077e;
				case 358:
					array[18] = (byte)num4;
					num2 = 186;
					if (0 == 0)
					{
						goto IL_0782;
					}
					goto case 240;
				case 240:
					do
					{
						array[24] = 88;
						num2 = 343;
					}
					while (fvFwOGq5SY8efUWHZX());
					goto IL_0782;
				case 35:
					array[24] = (byte)num4;
					num2 = 279;
					if (true)
					{
						goto IL_0782;
					}
					goto case 216;
				case 216:
					array[27] = 207;
					num2 = 107;
					if (ro8wtY6RHglKCKFknS())
					{
						goto IL_0782;
					}
					goto case 215;
				case 215:
					array2[10] = 195;
					num = 225;
					break;
				case 16:
					array[26] = (byte)num4;
					num2 = 251;
					if (true)
					{
						goto IL_0782;
					}
					goto case 359;
				case 359:
					num3 = lLD6NVM3XLv79WtogE(DoyOlxxYuI, P_0);
					num5 = 360;
					goto IL_077e;
				case 300:
					array2[14] = (byte)num7;
					num = 197;
					break;
				case 207:
					array[0] = (byte)num4;
					num = 10;
					break;
				case 188:
					array[12] = (byte)num6;
					num2 = 155;
					if (true)
					{
						goto IL_0782;
					}
					goto case 20;
				case 20:
					num6 = 130 - 43;
					num2 = 188;
					if (ro8wtY6RHglKCKFknS())
					{
						goto IL_0782;
					}
					goto case 242;
				case 171:
					array[28] = (byte)num6;
					num5 = 177;
					goto IL_077e;
				case 325:
					array2[15] = 156;
					num = 339;
					break;
				case 19:
					array[20] = (byte)num6;
					num2 = 242;
					if (ro8wtY6RHglKCKFknS())
					{
						goto IL_0782;
					}
					goto case 205;
				case 205:
					array[11] = 164;
					num5 = 270;
					goto IL_077e;
				case 231:
					array[3] = (byte)num4;
					num5 = 235;
					goto IL_077e;
				case 220:
					array[12] = 129;
					num2 = 357;
					if (ro8wtY6RHglKCKFknS())
					{
						goto IL_0782;
					}
					goto case 165;
				case 168:
					array2[6] = 66;
					num = 93;
					break;
				case 1:
					array[15] = 147;
					num2 = 167;
					if (!fvFwOGq5SY8efUWHZX())
					{
						goto IL_0782;
					}
					goto case 59;
				case 59:
					array[24] = (byte)num4;
					num5 = 322;
					goto IL_077e;
				case 217:
					array[26] = (byte)num4;
					num5 = 340;
					goto IL_077e;
				case 33:
					num6 = 215 - 71;
					num = 63;
					break;
				case 25:
					array[23] = 152;
					num5 = 38;
					goto IL_077e;
				case 246:
					array[17] = 53;
					num2 = 301;
					goto IL_0782;
				case 227:
					array[28] = (byte)num4;
					num5 = 137;
					goto IL_077e;
				case 360:
					try
					{
						return (string)fVv7Q9mmwqMVCQnMA9(YGYcal7TrnP2oUmosD(), DoyOlxxYuI, P_0 + 4, num3);
					}
					catch
					{
					}
					return "";
				case 206:
					memoryStream = new MemoryStream();
					num2 = 306;
					goto IL_0782;
				case 161:
					{
						rijndaelManaged = new RijndaelManaged();
						num5 = 271;
						goto IL_077e;
					}
					IL_077e:
					num2 = num5;
					goto IL_0782;
					IL_0782:
					num = num2;
					break;
				}
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[mrqRnf10S5UMFoaEbr(typeof(ETZxusFl8KUvQCslGf/mrqRnf10S5UMFoaEbr/xWG3HGYjHMnQIbC8qs<object>[]))]
		internal static string pKJOCPcpE0(string P_0)
		{
			"{11111-22222-50001-00000}".Trim();
			byte[] array = Convert.FromBase64String(P_0);
			return Encoding.Unicode.GetString(array, 0, array.Length);
		}

		[DllImport("kernel32.dll", EntryPoint = "RtlZeroMemory")]
		private static extern void FiuOkrJsNi(IntPtr P_0, uint P_1);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect", SetLastError = true)]
		private static extern int Si9OqbP0KA(ref IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "FindResource")]
		public static extern IntPtr XG6ORjU7fb(IntPtr P_0, string P_1, uint P_2);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void ziTOTVQsuk()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static void W5TONxEyGA()
		{
			try
			{
				RSACryptoServiceProvider.UseMachineKeyStore = true;
			}
			catch
			{
			}
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object vVYOPt7IyY(object P_0)
		{
			try
			{
				if (File.Exists(((Assembly)P_0).Location))
				{
					return ((Assembly)P_0).Location;
				}
			}
			catch
			{
			}
			try
			{
				if (File.Exists(((Assembly)P_0).GetName().CodeBase.ToString().Replace("file:///", "")))
				{
					return ((Assembly)P_0).GetName().CodeBase.ToString().Replace("file:///", "");
				}
			}
			catch
			{
			}
			try
			{
				if (File.Exists(P_0.GetType().GetProperty("Location").GetValue(P_0, new object[0])
					.ToString()))
				{
					return P_0.GetType().GetProperty("Location").GetValue(P_0, new object[0])
						.ToString();
				}
			}
			catch
			{
			}
			return "";
		}

		[DllImport("kernel32", EntryPoint = "LoadLibrary")]
		public static extern IntPtr iQoOwJCvVF(string P_0);

		[DllImport("kernel32", CharSet = CharSet.Ansi, EntryPoint = "GetProcAddress")]
		public static extern IntPtr wfcODm8Tpw(IntPtr P_0, string P_1);

		[DllImport("kernel32.dll", EntryPoint = "WriteProcessMemory")]
		private static extern int YWjO5FxZFa(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "ReadProcessMemory")]
		private static extern int GUcO4uIsQJ(IntPtr P_0, IntPtr P_1, [In][Out] byte[] P_2, uint P_3, out IntPtr P_4);

		[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
		private static extern int Q77OXhMqmW(IntPtr P_0, int P_1, int P_2, ref int P_3);

		[DllImport("kernel32.dll", EntryPoint = "OpenProcess")]
		private static extern IntPtr dfMO1oKHdX(uint P_0, int P_1, uint P_2);

		[DllImport("kernel32.dll", EntryPoint = "CloseHandle")]
		private static extern int vm0OKHF7gl(IntPtr P_0);

		[MethodImpl(MethodImplOptions.NoInlining)]
		[mrqRnf10S5UMFoaEbr(typeof(ETZxusFl8KUvQCslGf/mrqRnf10S5UMFoaEbr/xWG3HGYjHMnQIbC8qs<object>[]))]
		private static byte[] ducOFZanIy(string P_0)
		{
			using FileStream fileStream = new FileStream(P_0, FileMode.Open, FileAccess.Read, FileShare.Read);
			int num = 0;
			long length = fileStream.Length;
			int num2 = (int)length;
			byte[] array = new byte[num2];
			while (num2 > 0)
			{
				int num3 = fileStream.Read(array, num, num2);
				num += num3;
				num2 -= num3;
			}
			return array;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		[mrqRnf10S5UMFoaEbr(typeof(ETZxusFl8KUvQCslGf/mrqRnf10S5UMFoaEbr/xWG3HGYjHMnQIbC8qs<object>[]))]
		private static byte[] ALmOM0lxld(byte[] P_0)
		{
			MemoryStream memoryStream = new MemoryStream();
			Rijndael rijndael = Rijndael.Create();
			rijndael.Key = new byte[32]
			{
				110, 128, 80, 194, 116, 19, 107, 80, 72, 70,
				74, 178, 221, 160, 53, 225, 46, 80, 54, 227,
				227, 5, 164, 186, 131, 76, 80, 26, 25, 122,
				11, 18
			};
			rijndael.IV = new byte[16]
			{
				14, 19, 65, 203, 242, 168, 125, 11, 197, 242,
				104, 243, 138, 152, 188, 62
			};
			CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndael.CreateDecryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(P_0, 0, P_0.Length);
			cryptoStream.Close();
			return memoryStream.ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] MWsOmMkrJ7()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] nawOAi94m3()
		{
			return null;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] oSqO9VHYmx()
		{
			string text = "{11111-22222-20001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] j4uOB1KrNm()
		{
			string text = "{11111-22222-20001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] i1GOj7J9D0()
		{
			string text = "{11111-22222-30001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		private byte[] W5cOZbQ93j()
		{
			string text = "{11111-22222-30001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] oiTOGO1uff()
		{
			string text = "{11111-22222-40001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] ep6Opfhh74()
		{
			string text = "{11111-22222-40001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] AY9OvGZwLl()
		{
			string text = "{11111-22222-50001-00001}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal byte[] s4kOcmsGee()
		{
			string text = "{11111-22222-50001-00002}";
			if (text.Length > 0)
			{
				return new byte[2] { 1, 2 };
			}
			return new byte[2] { 1, 2 };
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public ETZxusFl8KUvQCslGf()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static Type FxU8baSu1GG9oHdN89(RuntimeTypeHandle P_0)
		{
			return Type.GetTypeFromHandle(P_0);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object yxQxBB4q1kQa49GQ5A(object P_0, object P_1)
		{
			return ((Assembly)P_0).GetManifestResourceStream((string)P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object j5NnY3KbOqb8XoFRvA(object P_0)
		{
			return ((BinaryReader)P_0).BaseStream;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void K9ogIGCkqlfUSEy0Mm(object P_0, long P_1)
		{
			((Stream)P_0).Position = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void jCSa8EaKvNxck1Zxbv(bool P_0)
		{
			RSACryptoServiceProvider.UseMachineKeyStore = P_0;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static long EXWIeMvN9NwgPAlhx2(object P_0)
		{
			return ((Stream)P_0).Length;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object XEgwdqxK8D7MYZ5SwK(object P_0, int P_1)
		{
			return ((BinaryReader)P_0).ReadBytes(P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object Qk2EbBGl7NmVPGW6Or(object P_0)
		{
			return ((Assembly)P_0).GetName();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object IqesVkZEAsFZQGLxQj(object P_0)
		{
			return ((AssemblyName)P_0).GetPublicKeyToken();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void C2na4EHtd4aYqSJCsE(object P_0, CipherMode P_1)
		{
			((SymmetricAlgorithm)P_0).Mode = P_1;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object dKBxTQNSjxSRuIXhuL(object P_0, object P_1, object P_2)
		{
			return ((SymmetricAlgorithm)P_0).CreateDecryptor((byte[])P_1, (byte[]?)P_2);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void jdswuN0P0uaYQGk94m(object P_0, object P_1, int P_2, int P_3)
		{
			((Stream)P_0).Write((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void eJMJacBmSxEIQBS4mf(object P_0)
		{
			((CryptoStream)P_0).FlushFinalBlock();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object pTT3pHTHIFunbGoWg7(object P_0)
		{
			return ((MemoryStream)P_0).ToArray();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void tWp2kSUtaVU1DRSUeS(object P_0)
		{
			((Stream)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void XaosKdcegDXPIXAEuc(object P_0)
		{
			((BinaryReader)P_0).Close();
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static int lLD6NVM3XLv79WtogE(object P_0, int P_1)
		{
			return BitConverter.ToInt32((byte[])P_0, P_1);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object YGYcal7TrnP2oUmosD()
		{
			return Encoding.Unicode;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static object fVv7Q9mmwqMVCQnMA9(object P_0, object P_1, int P_2, int P_3)
		{
			return ((Encoding)P_0).GetString((byte[])P_1, P_2, P_3);
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool ro8wtY6RHglKCKFknS()
		{
			return true;
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static bool fvFwOGq5SY8efUWHZX()
		{
			return false;
		}
	}
}
namespace iPMkhH5DwB2Q8yWtoh
{
	internal class IE3dyJf2OKPAA7hD1W
	{
		private static bool Ji3O3mxpjy;

		[MethodImpl(MethodImplOptions.NoInlining)]
		internal static void ugrjvXWz48stp()
		{
		}

		[MethodImpl(MethodImplOptions.NoInlining)]
		public IE3dyJf2OKPAA7hD1W()
		{
		}
	}
}
