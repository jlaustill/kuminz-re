// Disassemble the given ranges (start-end pairs, hex) by flow from each start and print the listing.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import java.io.*;

public class ListRanges extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String out = args[0];
        PrintWriter pw = new PrintWriter(new FileWriter(out));
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        for (int i = 1; i + 1 < args.length; i += 2) {
            long s = Long.parseLong(args[i], 16);
            Address a = sp.getAddress(s);
            DisassembleCommand cmd = new DisassembleCommand(a, null, true);
            cmd.applyTo(currentProgram, monitor);
        }
        for (int i = 1; i + 1 < args.length; i += 2) {
            long s = Long.parseLong(args[i], 16), e = Long.parseLong(args[i + 1], 16);
            pw.println("==== range " + args[i] + "-" + args[i + 1]);
            Address a = sp.getAddress(s);
            Address end = sp.getAddress(e);
            Listing l = currentProgram.getListing();
            CodeUnitIterator it = l.getCodeUnits(new AddressSet(a, end), true);
            while (it.hasNext()) {
                CodeUnit cu = it.next();
                StringBuilder b = new StringBuilder();
                byte[] bytes = cu.getBytes();
                for (byte x : bytes) b.append(String.format("%02x", x & 0xff));
                pw.println(String.format("%08x  %-24s %s", cu.getAddress().getOffset(), b.toString(), cu.toString()));
            }
        }
        pw.close();
    }
}
