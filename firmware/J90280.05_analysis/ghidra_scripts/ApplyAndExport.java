// Apply and Export Script
// Combines MasterAnalysisSetup.java + ExportAnalysisResults.java for quick workflow
// Perfect for iterative reverse engineering: Update CSV → Run this → Done!
// Creates a log file at ghidra/CM550.rep/apply_and_export.log for easy review
// @author J90280.05_analysis
// @category Analysis
// @keybinding ctrl shift E
// @menupath Tools.Apply and Export
// @toolbar

import ghidra.app.script.GhidraScript;
import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Date;

public class ApplyAndExport extends GhidraScript {

    private PrintWriter logWriter;
    private String logFilePath;

    @Override
    public void run() throws Exception {
        // Setup log file in the project directory
        String projectDir = getProjectRootFolder().getProjectLocator().getProjectDir().getAbsolutePath();
        logFilePath = projectDir + "/apply_and_export.log";

        // Clear and create new log file
        try {
            logWriter = new PrintWriter(new FileOutputStream(logFilePath, false)); // false = overwrite

            String timestamp = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(new Date());
            log("════════════════════════════════════════════════════════════");
            log("ApplyAndExport Log - " + timestamp);
            log("════════════════════════════════════════════════════════════");
            log("");
            log("Project: " + currentProgram.getName());
            log("Log file: " + logFilePath);
            log("");

        } catch (Exception e) {
            println("⚠ Warning: Could not create log file at " + logFilePath);
            println("  Error: " + e.getMessage());
            println("  Continuing without file logging...");
            logWriter = null;
        }

        try {
            logAndPrint("⚡ QUICK UPDATE: APPLY & EXPORT");
            logAndPrint("================================");
            logAndPrint("Running ClearLocalVariableOverrides + MasterAnalysisSetup + ExportAnalysisResults...");
            logAndPrint("");

            // Step 0: Clear any MCP/manual local variable overrides first
            logAndPrint("🧹 [0/4] Clearing local variable overrides...");
            logAndPrint("────────────────────────────────────────────");
            log(">>> Running ClearLocalVariableOverrides.java...");
            log("    This ensures CSV is the sole source of truth");
            log("");

            runScript("ClearLocalVariableOverrides.java");

            logAndPrint("");
            logAndPrint("✓ Local variable overrides cleared");
            logAndPrint("");

            // Step 1: Apply all CSV changes to Ghidra project
            logAndPrint("📥 [1/4] Applying CSV changes to Ghidra...");
            logAndPrint("─────────────────────────────────────────");
            log(">>> Running MasterAnalysisSetup.java...");
            log("    (Detailed output appears in Ghidra console)");
            log("");

            runScript("MasterAnalysisSetup.java");

            logAndPrint("");
            logAndPrint("✓ CSV changes applied");
            logAndPrint("");

            // Step 2: Export updated analysis for Claude Code
            logAndPrint("📤 [2/4] Exporting analysis for Claude Code...");
            logAndPrint("───────────────────────────────────────────────");
            log(">>> Running ExportAnalysisResults.java...");
            log("    (Detailed output appears in Ghidra console)");
            log("");

            runScript("ExportAnalysisResults.java");

            logAndPrint("");
            logAndPrint("✓ Export complete (.cpp/.asm)");
            logAndPrint("");

            // Step 3: Export compilable C file
            logAndPrint("📤 [3/4] Exporting compilable C file...");
            logAndPrint("────────────────────────────────────────");
            log(">>> Running ExportCompilableC.java...");
            log("    (Detailed output appears in Ghidra console)");
            log("");

            runScript("ExportCompilableC.java");

            logAndPrint("");
            logAndPrint("✓ Compilable C export complete (.c)");
            logAndPrint("");

            // Success summary
            logAndPrint("═══════════════════════════════════════════════");
            logAndPrint("🎉 QUICK UPDATE COMPLETE!");
            logAndPrint("═══════════════════════════════════════════════");
            logAndPrint("");
            logAndPrint("✅ Local variable overrides cleared (MCP safety)");
            logAndPrint("✅ All CSV changes applied to Ghidra");
            logAndPrint("✅ Latest analysis exported to working/");
            logAndPrint("");
            logAndPrint("🔄 Perfect Workflow:");
            logAndPrint("  1. Update CSV files with discoveries");
            logAndPrint("  2. Run ApplyAndExport.java (Ctrl+Shift+E)");
            logAndPrint("  3. Claude Code sees your changes instantly!");
            logAndPrint("");
            logAndPrint("📁 Exported files:");
            logAndPrint("  • working/J90280.05.ghidra.asm");
            logAndPrint("  • working/J90280.05.ghidra.cpp");
            logAndPrint("  • working/J90280.05.ghidra.c (compilable)");
            logAndPrint("");
            logAndPrint("📋 Log file: " + logFilePath);
            logAndPrint("   (Note: Sub-script details are in Ghidra console)");

            log("");
            log("════════════════════════════════════════════════════════════");
            log("END OF LOG");
            log("════════════════════════════════════════════════════════════");

        } catch (Exception e) {
            logAndPrintErr("❌ Error during quick update:");
            logAndPrintErr(e.getMessage());
            log("");
            log("Stack trace:");
            if (logWriter != null) {
                e.printStackTrace(logWriter);
            }
            e.printStackTrace();
            throw e;
        } finally {
            // Always close the log file
            if (logWriter != null) {
                logWriter.flush();
                logWriter.close();
            }
        }
    }

    /**
     * Write to log file only
     */
    private void log(String message) {
        if (logWriter != null) {
            logWriter.println(message);
            logWriter.flush();
        }
    }

    /**
     * Print to both console and log file
     */
    private void logAndPrint(String message) {
        println(message);
        log(message);
    }

    /**
     * Print error to both console and log file
     */
    private void logAndPrintErr(String message) {
        printerr(message);
        if (logWriter != null) {
            logWriter.println("ERROR: " + message);
            logWriter.flush();
        }
    }
}
