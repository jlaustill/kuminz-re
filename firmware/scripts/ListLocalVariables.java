// List Local Variables Script
// Lists all local variable names in functions from a CSV file
// @author J90350.00_analysis
// @category Analysis

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.File;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;

import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.pcode.HighFunction;
import ghidra.program.model.pcode.HighSymbol;
import ghidra.program.model.pcode.LocalSymbolMap;

public class ListLocalVariables extends GhidraScript {

    private FunctionManager functionManager;
    private DecompInterface decompiler;

    @Override
    public void run() throws Exception {
        println("======================================================================");
        println("LIST LOCAL VARIABLES");
        println("======================================================================");
        println("");

        functionManager = currentProgram.getFunctionManager();

        // Initialize decompiler
        decompiler = new DecompInterface();
        DecompileOptions options = new DecompileOptions();
        decompiler.setOptions(options);
        decompiler.setSimplificationStyle("decompile");
        decompiler.openProgram(currentProgram);

        // Get input file from arguments or use default
        String[] args = getScriptArgs();
        String csvPath;
        String outputPath;

        if (args.length > 0) {
            csvPath = args[0];
        } else {
            csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() +
                    "/../../../output/local_variables.csv";
        }

        outputPath = csvPath.replace(".csv", "_actual.csv");

        println("Input file: " + csvPath);
        println("Output file: " + outputPath);
        println("");

        if (!new File(csvPath).exists()) {
            println("ERROR: CSV not found at: " + csvPath);
            decompiler.dispose();
            return;
        }

        // Collect unique function addresses from CSV
        Set<Long> functionAddresses = new HashSet<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(csvPath))) {
            String line;
            boolean isFirstLine = true;
            while ((line = reader.readLine()) != null) {
                if (isFirstLine) {
                    isFirstLine = false;
                    continue;
                }
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;

                String[] parts = line.split(",");
                if (parts.length < 2) continue;

                String addrStr = parts[0].trim();
                if (addrStr.startsWith("0x") || addrStr.startsWith("0X")) {
                    addrStr = addrStr.substring(2);
                }
                try {
                    functionAddresses.add(Long.parseLong(addrStr, 16));
                } catch (NumberFormatException e) {
                    // Skip invalid entries
                }
            }
        }

        println("Found " + functionAddresses.size() + " unique functions");
        println("");

        // Output file with actual variable names
        try (PrintWriter writer = new PrintWriter(outputPath)) {
            writer.println("function_address,function_name,variable_name,variable_type,is_parameter");

            for (Long funcAddr : functionAddresses) {
                Address addr = toAddr(funcAddr);
                if (addr == null) continue;

                Function function = functionManager.getFunctionAt(addr);
                if (function == null) {
                    println("  Warning: No function at 0x" + Long.toHexString(funcAddr));
                    continue;
                }

                // Decompile to get variable names
                DecompileResults results = decompiler.decompileFunction(function, 30, monitor);
                if (!results.decompileCompleted()) {
                    println("  Warning: Decompilation failed for " + function.getName());
                    continue;
                }

                HighFunction highFunc = results.getHighFunction();
                if (highFunc == null) continue;

                LocalSymbolMap localMap = highFunc.getLocalSymbolMap();
                java.util.Iterator<HighSymbol> symbols = localMap.getSymbols();

                println("Function: " + function.getName() + " @ 0x" + Long.toHexString(funcAddr));

                while (symbols.hasNext()) {
                    HighSymbol sym = symbols.next();
                    String varName = sym.getName();
                    String typeName = sym.getDataType() != null ? sym.getDataType().getName() : "unknown";
                    boolean isParam = sym.isParameter();

                    println("  " + (isParam ? "[PARAM] " : "[LOCAL] ") + varName + " : " + typeName);

                    writer.println(String.format("0x%08x,%s,%s,%s,%s",
                        funcAddr, function.getName(), varName, typeName, isParam));
                }
                println("");
            }
        }

        println("======================================================================");
        println("OUTPUT WRITTEN TO: " + outputPath);
        println("======================================================================");

        decompiler.dispose();
    }
}
