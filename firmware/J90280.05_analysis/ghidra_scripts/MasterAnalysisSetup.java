// Master Analysis Setup Script
// Runs all bulk analysis scripts in the correct order for complete firmware setup
// @author J90280.05_analysis
// @category Analysis
// @keybinding 
// @menupath 
// @toolbar 

import ghidra.app.script.GhidraScript;

public class MasterAnalysisSetup extends GhidraScript {
    
    @Override
    public void run() throws Exception {
        println("🚀 MASTER ANALYSIS SETUP - COMPLETE FIRMWARE AUTOMATION");
        println("========================================================");
        println("Running all bulk analysis scripts in optimal order...");
        println("");
        
        int totalScripts = 10;
        int currentScript = 0;

        try {
            // Step 1: Setup Memory Map (MUST be first)
            currentScript++;
            println("[" + currentScript + "/" + totalScripts + "] Setting up memory map...");
            runScript("SetupMemoryMap.java");
            println("✓ Memory map configured\n");

            // Step 2: Create Functions
            currentScript++;
            println("[" + currentScript + "/" + totalScripts + "] Creating functions...");
            runScript("BulkFunctionCreator.java");
            println("✓ Functions created\n");

            // Step 3: Rename Functions
            currentScript++;
            println("[" + currentScript + "/" + totalScripts + "] Renaming functions...");
            runScript("BulkFunctionRenamer.java");
            println("✓ Functions renamed\n");

            // Step 4: Create Structures
            currentScript++;
            println("[" + currentScript + "/" + totalScripts + "] Creating structures...");
            runScript("BulkStructureCreator.java");
            println("✓ Structures created\n");

            // Step 5: Rename Function Parameters
            currentScript++;
            println("[" + currentScript + "/" + totalScripts + "] Renaming function parameters...");
            runScript("BulkFunctionParameterRenamer.java");
            println("✓ Function parameters renamed\n");

            // Step 6: Create Enums (must be before global variables for enum types)
            currentScript++;
            println("[" + currentScript + "/" + totalScripts + "] Creating enums...");
            runScript("BulkEnumCreator.java");
            println("✓ Enums created\n");

            // Step 7: Create Global Variables (now after enums so enum types are available)
            currentScript++;
            println("[" + currentScript + "/" + totalScripts + "] Creating global variables...");
            runScript("BulkVariableCreator.java");
            println("✓ Global variables created\n");

            // Step 8: Rename Local Variables (after functions are decompilable)
            currentScript++;
            println("[" + currentScript + "/" + totalScripts + "] Renaming local variables...");
            runScript("BulkLocalVariableRenamer.java");
            println("✓ Local variables renamed\n");

            // Step 9: Create Labels
            currentScript++;
            println("[" + currentScript + "/" + totalScripts + "] Creating labels...");
            runScript("BulkLabelCreator.java");
            println("✓ Labels created\n");

            // Step 10: Document Constants
            currentScript++;
            println("[" + currentScript + "/" + totalScripts + "] Documenting constants...");
            runScript("BulkConstantCreator.java");
            println("✓ Constants documented\n");
            
            println("🎉 MASTER ANALYSIS SETUP COMPLETE!");
            println("========================================");
            println("Your firmware is now fully analyzed with:");
            println("✅ Proper memory layout (MC68336 architecture)");
            println("✅ Named functions with semantic meaning");
            println("✅ Data structures defined with nested types");
            println("✅ Function parameters with proper names and types");
            println("✅ Typed global variables using custom structures");
            println("✅ Meaningful labels for control flow");
            println("✅ Documented constants (no more magic numbers)");
            println("✅ Properly named and typed local variables");
            println("✅ Organized enums for switch statements");
            println("");
            println("🔧 Manual Steps (if needed):");
            println("• Run BulkArrayCreator.java separately if you want arrays");
            println("• Update CSV files with new discoveries");
            println("• Re-run this script on fresh imports");
            println("");
            println("📁 Your CSV files are your knowledge database:");
            println("• function_renames.csv - Function names");
            println("• function_parameters.csv - Function parameter names and types");
            println("• global_variables.csv - Variable definitions");  
            println("• local_variables.csv - Local variable renames and types");
            println("• structure_definitions.csv - Data structures");
            println("• labels.csv - Control flow labels");
            println("• constants.csv - Magic number meanings");
            println("• enums.csv - Enumeration definitions");
            println("• arrays.csv - Array/buffer layouts");
            println("");
            println("🚀 Ready for reverse engineering! Your firmware is now human-readable.");
            
        } catch (Exception e) {
            println("❌ Error during setup: " + e.getMessage());
            println("Some scripts may not have completed successfully.");
            println("Check individual script outputs above for details.");
        }
    }
}