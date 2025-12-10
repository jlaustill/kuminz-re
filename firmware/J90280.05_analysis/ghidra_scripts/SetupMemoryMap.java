// Ghidra Memory Map Setup Script
// Creates memory blocks based on MC68336 architecture from playbook
// @author J90280.05_analysis
// @category Analysis
// @keybinding 
// @menupath 
// @toolbar 

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;

public class SetupMemoryMap extends GhidraScript {
    
    @Override
    public void run() throws Exception {
        Memory memory = currentProgram.getMemory();
        
        // Show existing memory blocks first
        println("📋 Existing memory blocks:");
        for (MemoryBlock block : memory.getBlocks()) {
            println("   " + block.getName() + ": 0x" + 
                   Long.toHexString(block.getStart().getOffset()).toUpperCase() + " - 0x" + 
                   Long.toHexString(block.getEnd().getOffset()).toUpperCase() + 
                   " (" + block.getSize() + " bytes)");
        }
        println();
        
        try {
            // 1. Internal Flash (Code) - Already exists, skip
            
            // 2. MC68336 Peripheral Register Blocks
            // SIM (System Integration Module) - Extended to 0xFFFA50 to cover all variables
            createMemoryBlock(memory, "SIM_Registers", 0xFFFA00, 0x51, 
                            true, true, false, "System Integration Module registers (clock, interrupts, chip selects)");
            
            // QSM (Queued Serial Module) - Extended to 0xFFFB30
            createMemoryBlock(memory, "QSM_Registers", 0xFFFB00, 0x31, 
                            true, true, false, "Queued Serial Module registers (SCI, SPI communication)");
            
            // TPU (Time Processor Unit) - Extended to 0xFFFC30
            createMemoryBlock(memory, "TPU_Registers", 0xFFFC00, 0x31, 
                            true, true, false, "Time Processor Unit registers (timing and control functions)");
            
            // SIM CAN Control Ports - For our discovered CAN switching registers
            createMemoryBlock(memory, "SIM_CAN_Control_Ports", 0xFFD000, 0x20, 
                            true, true, false, "SIM CAN control ports for pin switching (0xFFD004, 0xFFD006)");
            
            // QADC (Queued ADC) - Extended to 0xFFFD20  
            createMemoryBlock(memory, "QADC_Registers", 0xFFFD00, 0x21, 
                            true, true, false, "Queued Analog-to-Digital Converter registers");
            
            // CAN Controllers - Extended to 0xFFFEB0
            createMemoryBlock(memory, "CAN_Registers", 0xFFFE00, 0xB1, 
                            true, true, false, "CAN1 and CAN2 controller registers");
            
            // 3. Timer/System Registers - For hardware_timer_register at 0xFFF404
            createMemoryBlock(memory, "System_Timer_Registers", 0xFFF400, 0x10, 
                            true, true, false, "System timer registers including hardware_timer_register");
            
            // 4. Internal RAM  
            createMemoryBlock(memory, "Internal_RAM", 0xFFFF00, 0x100, 
                            true, true, false, "Internal SRAM for stack/variables");
            
            // 5. CalTerm Table Storage (split to avoid conflicts)
            createMemoryBlock(memory, "CalTerm_Table_Storage", 0x006000, 0x2000, 
                            true, true, false, "CalTerm table storage area for lookup tables and configuration data");
            
            // 6. CalTerm Parameter Memory (split around existing firmware blocks)
            // Block A: Covers 0x040000-0x0FFFFF (wraps around existing firmware)
            createMemoryBlock(memory, "CalTerm_Parameters_A", 0x040000, 0xC0000, 
                            true, true, false, "CalTerm parameter memory - covers 0x008xxxxx range (part A)");
            
            // Block B: Covers 0x100000-0xFFFFFF (0x0080xxxx runtime parameters)
            createMemoryBlock(memory, "CalTerm_Parameters_B", 0x100000, 0xF00000, 
                            true, true, false, "CalTerm parameter memory - covers 0x0080xxxx range (part B)");
            
            // 7. EEPROM Memory (split around existing block at 0x1000080-0x1000389)
            // Block A: Before existing firmware block
            createMemoryBlock(memory, "EEPROM_Data_A", 0x01000000, 0x80, 
                            true, true, false, "EEPROM data plate area (before existing block)");
            
            // Block B: After existing firmware block  
            createMemoryBlock(memory, "EEPROM_Data_B", 0x0100038A, 0x1C76, 
                            true, true, false, "EEPROM data plate area (after existing block)");
            
            println("✓ Memory map configured");
            
        } catch (Exception e) {
            println("Error setting up memory map: " + e.getMessage());
        }
    }
    
    private void createMemoryBlock(Memory memory, String name, long startAddr, long size,
                                 boolean read, boolean write, boolean execute, String comment) {
        try {
            Address start = toAddr(startAddr);
            Address end = toAddr(startAddr + size - 1);
            
            // Remove any overlapping blocks in this range, but preserve code blocks
            MemoryBlock[] blocks = memory.getBlocks();
            for (MemoryBlock block : blocks) {
                if (block.getStart().compareTo(end) <= 0 && block.getEnd().compareTo(start) >= 0) {
                    // Don't remove blocks that contain code (executable blocks with initialized data)
                    if (block.isExecute() && block.isInitialized()) {
                        println("⚠️ Skipping code block: " + block.getName() + " (contains firmware code)");
                        continue;
                    }
                    // Don't remove the main program image
                    if (block.getName().toLowerCase().contains("ram") && 
                        block.getStart().getOffset() < 0x008000) {
                        println("⚠️ Skipping program block: " + block.getName() + " (contains program code)");
                        continue;
                    }
                    println("🗑️ Removing overlapping block: " + block.getName() + " (0x" + 
                           Long.toHexString(block.getStart().getOffset()).toUpperCase() + " - 0x" + 
                           Long.toHexString(block.getEnd().getOffset()).toUpperCase() + ")");
                    memory.removeBlock(block, monitor);
                }
            }
            
            // Create uninitialized memory block
            MemoryBlock block = memory.createUninitializedBlock(name, start, size, false);
            
            // Set permissions
            block.setRead(read);
            block.setWrite(write);
            block.setExecute(execute);
            
            // Set comment
            block.setComment(comment);
            
            /* println("✓ Created " + name + " (0x" + Long.toHexString(startAddr).toUpperCase() + 
                   " - 0x" + Long.toHexString(startAddr + size - 1).toUpperCase() + 
                   "): " + comment); */ // Commented out for clean output
            
        } catch (Exception e) {
            println("✗ Failed to create " + name + ": " + e.getMessage());
        }
    }
}