// Apply Local Variables Script
// Reads local_variables.csv and applies typed variable names to functions
// Uses HighFunctionDBUtil to properly commit decompiler variable changes
// @author J90350.00_analysis
// @category Analysis
// @keybinding
// @menupath
// @toolbar

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.HashMap;
import java.util.Map;

import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.data.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.LocalVariableImpl;
import ghidra.program.model.listing.Variable;
import ghidra.program.model.listing.VariableStorage;
import ghidra.program.model.pcode.HighFunction;
import ghidra.program.model.pcode.HighFunctionDBUtil;
import ghidra.program.model.pcode.HighSymbol;
import ghidra.program.model.pcode.HighVariable;
import ghidra.program.model.pcode.PcodeOp;
import ghidra.program.model.pcode.PcodeOpAST;
import ghidra.program.model.pcode.Varnode;
import ghidra.program.model.pcode.LocalSymbolMap;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.Symbol;

public class ApplyLocalVariables extends GhidraScript {

    private FunctionManager functionManager;
    private DataTypeManager dtm;
    private DecompInterface decompiler;

    @Override
    public void run() throws Exception {
        println("=".repeat(70));
        println("APPLY LOCAL VARIABLES - J90350.00");
        println("=".repeat(70));
        println("");

        functionManager = currentProgram.getFunctionManager();
        dtm = currentProgram.getDataTypeManager();

        // Initialize decompiler with simplification style that preserves names
        decompiler = new DecompInterface();
        DecompileOptions options = new DecompileOptions();
        decompiler.setOptions(options);
        decompiler.setSimplificationStyle("decompile");
        decompiler.openProgram(currentProgram);

        // Get input file from arguments or use default
        String[] args = getScriptArgs();
        String csvPath;

        if (args.length > 0) {
            csvPath = args[0];
        } else {
            // Navigate from project directory (ghidra/project/J90350.rep) up to analysis root
            // ghidra/project/J90350.rep -> ghidra/project -> ghidra -> J90350.00_analysis
            csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() +
                    "/../../../output/local_variables.csv";
        }

        println("Input file: " + csvPath);
        println("");

        if (!new File(csvPath).exists()) {
            println("ERROR: local_variables.csv not found at: " + csvPath);
            decompiler.dispose();
            return;
        }

        // Phase 1: Parse CSV and collect variable definitions
        println("[Phase 1] Parsing local variable definitions...");
        List<VarDef> vars = parseVariableDefinitions(csvPath);
        println("  Found " + vars.size() + " variable definitions");
        println("");

        // Phase 2: Group by function for batch processing
        Map<Long, List<VarDef>> funcVars = new HashMap<>();
        for (VarDef var : vars) {
            funcVars.computeIfAbsent(var.functionAddress, k -> new ArrayList<>()).add(var);
        }
        println("  Across " + funcVars.size() + " functions");
        println("");

        // Phase 3: Apply variable types and names
        println("[Phase 2] Applying local variable types...");
        ApplyResult result = applyVariables(funcVars);
        println("  Applied: " + result.applied);
        println("  Skipped: " + result.skipped);
        println("  Failed: " + result.failed);
        println("");

        // Show examples of what was applied
        println("[Examples of applied variables]");
        int shown = 0;
        for (VarDef var : vars) {
            if (var.wasApplied && shown < 10) {
                println(String.format("  %s.%s -> %s %s",
                    var.functionName, var.oldName, var.newType, var.newName));
                shown++;
            }
        }

        println("");
        println("=".repeat(70));
        println("LOCAL VARIABLE TYPING COMPLETE!");
        println("Run 'export' to see changes in decompiled output.");
        println("=".repeat(70));

        decompiler.dispose();
    }

    private List<VarDef> parseVariableDefinitions(String csvPath) throws Exception {
        List<VarDef> vars = new ArrayList<>();

        try (BufferedReader reader = new BufferedReader(new FileReader(csvPath))) {
            String line;
            boolean isFirstLine = true;

            while ((line = reader.readLine()) != null) {
                if (isFirstLine) {
                    isFirstLine = false;
                    continue;
                }

                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) {
                    continue;
                }

                String[] parts = ScriptUtils.parseCSVLine(line);
                if (parts.length < 5) {
                    continue;
                }

                String addressStr = parts[0].trim();
                String functionName = parts[1].trim();
                String oldName = parts[2].trim();
                String newName = parts[3].trim();
                String newType = parts[4].trim();
                String comment = parts.length > 5 ? parts[5].trim() : "";
                boolean keepMerged = parts.length > 6 && parts[6].trim().equalsIgnoreCase("yes");

                if (addressStr.isEmpty() || functionName.isEmpty()) {
                    continue;
                }

                try {
                    long address = ScriptUtils.parseAddress(addressStr);

                    VarDef var = new VarDef();
                    var.functionAddress = address;
                    var.functionName = functionName;
                    var.oldName = oldName;
                    var.newName = newName;
                    var.newType = newType;
                    var.comment = comment;
                    var.keepMerged = keepMerged;
                    vars.add(var);
                } catch (Exception e) {
                    println("  Warning: Skipping invalid entry: " + line);
                }
            }
        }

        return vars;
    }

    private ApplyResult applyVariables(Map<Long, List<VarDef>> funcVars) {
        ApplyResult result = new ApplyResult();
        int txId = currentProgram.startTransaction("Apply Local Variables");

        try {
            for (Map.Entry<Long, List<VarDef>> entry : funcVars.entrySet()) {
                long funcAddr = entry.getKey();
                List<VarDef> varList = entry.getValue();

                Address addr = toAddr(funcAddr);
                if (addr == null) {
                    result.failed += varList.size();
                    continue;
                }

                Function function = functionManager.getFunctionAt(addr);
                if (function == null) {
                    println("  Warning: No function at 0x" + Long.toHexString(funcAddr));
                    result.failed += varList.size();
                    continue;
                }

                // Decompile the function to get high-level variables
                DecompileResults decompResults = decompiler.decompileFunction(function, 30, monitor);
                if (!decompResults.decompileCompleted()) {
                    println("  Warning: Decompilation failed for " + function.getName());
                    result.failed += varList.size();
                    continue;
                }

                HighFunction highFunc = decompResults.getHighFunction();
                if (highFunc == null) {
                    println("  Warning: No high function for " + function.getName());
                    result.failed += varList.size();
                    continue;
                }

                LocalSymbolMap localSymbolMap = highFunc.getLocalSymbolMap();

                // Process each variable definition for this function. Register@address rows go first, so the
                // uses they pin are taken before a keep_merged row commits the rest of its variable.
                List<VarDef> ordered = new ArrayList<>();
                for (VarDef var : varList) {
                    if (var.oldName.contains("@")) {
                        ordered.add(var);
                    }
                }
                for (VarDef var : varList) {
                    if (!var.oldName.contains("@")) {
                        ordered.add(var);
                    }
                }
                for (VarDef var : ordered) {
                    if (var.keepMerged || var.oldName.contains("@")) {
                        if (applyMergedRow(function, highFunc, localSymbolMap, var)) {
                            result.applied++;
                            var.wasApplied = true;
                        } else {
                            result.skipped++;
                        }
                        continue;
                    }
                    boolean found = false;

                    // Search for the variable by its old name in decompiler's local symbol map
                    java.util.Iterator<HighSymbol> symbols = localSymbolMap.getSymbols();
                    while (symbols.hasNext()) {
                        HighSymbol symbol = symbols.next();
                        if (symbol.getName().equals(var.oldName)) {
                            try {
                                DataType dataType = getDataType(var.newType);
                                if (dataType == null) {
                                    println("  Error: Unknown type '" + var.newType + "' for " +
                                            var.functionName + "." + var.oldName);
                                    result.failed++;
                                    found = true;
                                    break;
                                }

                                // Commit the variable rename using HighFunctionDBUtil
                                // This creates a database entry that the decompiler will use
                                HighFunctionDBUtil.updateDBVariable(
                                    symbol, var.newName, dataType, SourceType.USER_DEFINED);

                                result.applied++;
                                var.wasApplied = true;
                                found = true;
                                break;

                            } catch (Exception e) {
                                // If HighFunctionDBUtil fails, try direct database symbol approach
                                try {
                                    Symbol dbSymbol = symbol.getSymbol();
                                    if (dbSymbol != null) {
                                        DataType dataType = getDataType(var.newType);
                                        dbSymbol.setName(var.newName, SourceType.USER_DEFINED);
                                        result.applied++;
                                        var.wasApplied = true;
                                    } else {
                                        println("  Note: " + var.functionName + "." + var.oldName +
                                                " - " + e.getMessage());
                                        result.skipped++;
                                    }
                                } catch (Exception e2) {
                                    println("  Error: " + var.functionName + "." + var.oldName +
                                            " - " + e2.getMessage());
                                    result.failed++;
                                }
                                found = true;
                                break;
                            }
                        }
                    }

                    if (!found) {
                        // Try searching in function's committed local variables (stack vars)
                        Variable[] localVars = function.getLocalVariables();
                        for (Variable localVar : localVars) {
                            if (localVar.getName().equals(var.oldName)) {
                                try {
                                    DataType dataType = getDataType(var.newType);
                                    if (dataType != null) {
                                        localVar.setName(var.newName, SourceType.USER_DEFINED);
                                        localVar.setDataType(dataType, SourceType.USER_DEFINED);
                                        result.applied++;
                                        var.wasApplied = true;
                                        found = true;
                                    }
                                } catch (Exception e) {
                                    // Ignore
                                }
                                break;
                            }
                        }
                    }

                    if (!found) {
                        // Fallback: search by new name. Handles incremental re-runs where the
                        // variable was already renamed in a prior session (old name is gone) but
                        // the type needs updating — e.g. after ApplyEnums recreated an enum type.
                        java.util.Iterator<HighSymbol> fallbackSymbols = localSymbolMap.getSymbols();
                        while (fallbackSymbols.hasNext()) {
                            HighSymbol symbol = fallbackSymbols.next();
                            if (symbol.getName().equals(var.newName)) {
                                try {
                                    DataType dataType = getDataType(var.newType);
                                    if (dataType != null) {
                                        HighFunctionDBUtil.updateDBVariable(
                                            symbol, var.newName, dataType, SourceType.USER_DEFINED);
                                        result.applied++;
                                        var.wasApplied = true;
                                        found = true;
                                    }
                                } catch (Exception e) {
                                    // Ignore — best-effort fallback
                                }
                                break;
                            }
                        }
                    }

                    if (!found) {
                        println("  Warning: Variable '" + var.oldName + "' not found in " + var.functionName);
                        result.skipped++;
                    }
                }
            }
        } finally {
            currentProgram.endTransaction(txId, true);
        }

        return result;
    }

    // updateDBVariable records a register local at one first-use address. When the decompiler had merged several
    // uses of registers into one variable (one counter reused by many loops), only the use at that address keeps
    // the name and the rest split off as new unnamed variables. keep_merged=yes rows and register@address rows
    // commit every use instead, as "name", "name$1", "name$2", ...: the decompiler merges such a set back into
    // one variable called name. Rows that share a new_name join one set.
    //   old_name = placeholder (iVar7), keep_merged=yes: every use the decompiler had merged into it.
    //   old_name = register@address (r6@0x0003a6e8): only the value that instruction writes, with the uses
    //   joined to it by loop phis - for a register the compiler reuses for another role in the next loop.
    private boolean applyMergedRow(Function function, HighFunction highFunc, LocalSymbolMap localSymbolMap,
            VarDef var) {
        DataType dataType = getDataType(var.newType);
        if (dataType == null || Undefined.isUndefined(dataType)) {
            println("  Error: keep_merged needs a known, defined type: '" + var.newType + "' for " +
                    var.functionName + "." + var.oldName);
            return false;
        }
        java.util.List<Varnode> uses = new ArrayList<>();
        if (var.oldName.contains("@")) {
            String[] pin = var.oldName.split("@");
            ghidra.program.model.lang.Register register = currentProgram.getRegister(pin[0].trim());
            Address address = toAddr(ScriptUtils.parseAddress(pin[1].trim()));
            Varnode written = null;
            if (register != null) {
                java.util.Iterator<PcodeOpAST> ops = highFunc.getPcodeOps(address);
                while (ops.hasNext()) {
                    Varnode out = ops.next().getOutput();
                    if (out != null && out.getAddress().equals(register.getAddress()) && out.getHigh() != null) {
                        written = out;
                    }
                }
            }
            if (written == null) {
                println("  Warning: no " + var.oldName + " write in " + var.functionName);
                return false;
            }
            uses.addAll(phiConnectedUses(written));
        } else {
            HighVariable high = null;
            java.util.Iterator<HighSymbol> symbols = localSymbolMap.getSymbols();
            while (symbols.hasNext()) {
                HighSymbol symbol = symbols.next();
                if (symbol.getName().equals(var.oldName)) {
                    high = symbol.getHighVariable();
                    break;
                }
            }
            if (high == null) {
                println("  Warning: Variable '" + var.oldName + "' not found in " + var.functionName);
                return false;
            }
            uses.addAll(java.util.Arrays.asList(high.getInstances()));
        }
        java.util.TreeMap<Address, Varnode> pieces = new java.util.TreeMap<>();
        for (Varnode use : uses) {
            Address pc = use.getPCAddress();
            if (use.isRegister() && pc != null && pc != Address.NO_ADDRESS &&
                    use.getSize() == dataType.getLength()) {
                pieces.putIfAbsent(pc, use);
            }
        }
        Address entry = function.getEntryPoint();
        int committed = 0;
        for (Map.Entry<Address, Varnode> piece : pieces.entrySet()) {
            int firstUseOffset = (int) piece.getKey().subtract(entry);
            try {
                VariableStorage storage = new VariableStorage(currentProgram, piece.getValue());
                boolean taken = false;
                for (Variable other : function.getLocalVariables()) {
                    if (other.getFirstUseOffset() == firstUseOffset &&
                            other.getVariableStorage().intersects(storage)) {
                        taken = true;
                        break;
                    }
                }
                if (taken) {
                    continue;
                }
                String name = var.newName;
                for (int index = 1; hasLocalNamed(function, name); index++) {
                    name = var.newName + "$" + index;
                }
                function.addLocalVariable(new LocalVariableImpl(name, firstUseOffset, dataType, storage,
                    currentProgram), SourceType.USER_DEFINED);
                committed++;
            } catch (Exception e) {
                println("  Note: " + var.functionName + "." + var.newName + " use at " + piece.getKey() +
                        " not committed - " + e.getMessage());
            }
        }
        if (committed == 0) {
            println("  Warning: " + var.functionName + "." + var.oldName + " had no uncommitted register use");
            return false;
        }
        return true;
    }

    // The uses of seed's variable joined to it through MULTIEQUAL / INDIRECT ops (one loop's variable), leaving
    // out the uses the decompiler merged in only by copies.
    private java.util.List<Varnode> phiConnectedUses(Varnode seed) {
        HighVariable high = seed.getHigh();
        Map<Varnode, Varnode> parent = new HashMap<>();
        for (Varnode use : high.getInstances()) {
            parent.put(use, use);
        }
        for (Varnode use : high.getInstances()) {
            PcodeOp def = use.getDef();
            if (def == null ||
                    (def.getOpcode() != PcodeOp.MULTIEQUAL && def.getOpcode() != PcodeOp.INDIRECT)) {
                continue;
            }
            for (Varnode input : def.getInputs()) {
                if (parent.containsKey(input)) {
                    parent.put(root(parent, input), root(parent, use));
                }
            }
        }
        Varnode seedRoot = root(parent, seed);
        java.util.List<Varnode> joined = new ArrayList<>();
        for (Varnode use : high.getInstances()) {
            if (root(parent, use) == seedRoot) {
                joined.add(use);
            }
        }
        return joined;
    }

    private static Varnode root(Map<Varnode, Varnode> parent, Varnode node) {
        while (parent.get(node) != node) {
            node = parent.get(node);
        }
        return node;
    }

    private boolean hasLocalNamed(Function function, String name) {
        for (Variable local : function.getLocalVariables()) {
            if (local.getName().equals(name)) {
                return true;
            }
        }
        return false;
    }

    private DataType getDataType(String typeString) {
        // Array: "<element>[<count>]" (byte[6], huffman_tree_node_t[513]), built like ImportAnalysis builds
        // array globals. Before PR #53 round 89 the name lookup below found an array only when something else
        // had created the same array type: CM550's byte[4] local stopped applying once a struct field that
        // happened to be byte[4] became a dword.
        ScriptUtils.ArrayTypeSpec array = ScriptUtils.parseArrayType(typeString);
        if (array != null) {
            DataType element = getDataType(array.elementType);
            if (element == null || element.getLength() <= 0) {
                return null;
            }
            return new ArrayDataType(element, array.count, element.getLength());
        }

        // Handle pointer types
        if (ScriptUtils.isPointerType(typeString)) {
            String baseType = ScriptUtils.stripPointer(typeString);
            DataType baseDataType = getDataType(baseType);

            if (baseDataType == null) {
                baseDataType = findDataTypeByName(baseType);
            }

            if (baseDataType != null) {
                return new PointerDataType(baseDataType);
            }
            return null;
        }

        // Handle primitive types
        switch (typeString.toLowerCase()) {
            case "bool":
                // A 1-byte boolean (the decompiler's own bool). Before PR #53 round 90 it was an unknown type, so a
                // bool row never applied.
                return BooleanDataType.dataType;
            case "uint8_t":
            case "byte":
            case "char":
                return ByteDataType.dataType;
            case "uint16_t":
            case "word":
            case "ushort":
            case "short":
                return WordDataType.dataType;
            case "int32_t":
                // Signed 32-bit. "int" below keeps mapping to unsigned dword so existing rows do not
                // re-render. (ApplyStructures maps "int" / "short" to signed types; ImportAnalysis types
                // globals with its own "i8" / "i16" / "i32" signed keywords.)
                return IntegerDataType.dataType;
            case "uint32_t":
            case "dword":
            case "uint":
            case "int":
                return DWordDataType.dataType;
            case "uint64_t":
            case "qword":
            case "ulong":
            case "long":
                return QWordDataType.dataType;
            case "float":
                return FloatDataType.dataType;
            case "double":
                return DoubleDataType.dataType;
            case "void":
                return VoidDataType.dataType;
            default:
                return findDataTypeByName(typeString);
        }
    }

    private DataType findDataTypeByName(String typeName) {
        java.util.Iterator<DataType> dtIter = dtm.getAllDataTypes();
        while (dtIter.hasNext()) {
            DataType dt = dtIter.next();
            if (dt.getName().equals(typeName)) {
                return dt;
            }
        }
        return null;
    }



    // Helper classes
    private static class VarDef {
        long functionAddress;
        String functionName;
        String oldName;
        String newName;
        String newType;
        String comment;
        boolean keepMerged = false;
        boolean wasApplied = false;
    }

    private static class ApplyResult {
        int applied = 0;
        int skipped = 0;
        int failed = 0;
    }
}
