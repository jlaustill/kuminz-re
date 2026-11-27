"""Round 96, after the Q1 / Q2 / Q4 apply (stage F). Exact-line edits; each must match once; keeps line endings.
CM550
- global 0x803631: the Q1 judge's documentation row j1939_pgn65249_payload.retarder_control_method (empty type; the
  apply refuses a dotted name, so the element was dropped there).
- function_definitions: the four prototypes the Q2 judge confirmed (registerJ1939PgnRequestHandler 0x2f47e, the DM3 /
  DM7 receive handlers 0x2ef1c / 0x2ef4a, dispatchTsc1ByDestinationAddress 0x2fb70); 0x2ef4a's stale 'msg_ptr int'
  row goes. Parameter names are spelled out (request_message / message / handler).
CM848
- function_definitions: 0x23b38's first param-0 row (rx_msg) goes; the later row (msg) is the one the build applies,
  so the render keeps its parameter. 0x2cd8's rows 224 / 225 repeat rows 109 / 110 exactly and go.
- global 0x3fa9a2: typed j1939_pgn_handler_entry_t[32] like its CM550 twin 0x801d5a (the Q2 judge's lead: the
  registrar compares the count with 32, and 0x3fa9a2 + 32 x 6 = 0x3faa62 = j1939_pgn_handler_count); the rows inside
  it go: the documentation rows 0x3fa9a3 / 0x3fa9a4 and the type-only pointer row 0x3fa9aa (entry 1's handler).
usage: post_apply_r96_q124.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
C550 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
C848 = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")


def edit(path, pairs):
    t = open(path, newline="").read()
    E = "\r\n" if "\r\n" in t else "\n"
    lines = t.split(E)
    for old, new in pairs:
        hits = [k for k, l in enumerate(lines) if l == old]
        assert len(hits) == 1, (path, old[:80], len(hits))
        k = hits[0]
        lines[k:k + 1] = new
    open(path, "w", newline="").write(E.join(lines))


def delete_nth(path, line, nth):
    """delete the nth (1-based) exact occurrence of a line"""
    t = open(path, newline="").read()
    E = "\r\n" if "\r\n" in t else "\n"
    lines = t.split(E)
    hits = [k for k, l in enumerate(lines) if l == line]
    assert len(hits) >= nth, (path, line[:80], len(hits))
    del lines[hits[nth - 1]]
    open(path, "w", newline="").write(E.join(lines))


R = "(PR #53 round 96)"
edit(os.path.join(C550, "global_variables.csv"), [
    ("0x00803631,engine_brake_cylinders_per_step,undefined,",
     ["0x00803631,j1939_pgn65249_payload.retarder_control_method,,RC byte 2, SPN 557 retarder control method: 0xff / 6 / 3 / 2 / 1 for 0 / 1 / 2 / 3 / 6 cylinders per engine brake driver (0x808200, e2m 13D8 +2 JCDR1NCY), written by cm550_buildPgn65249RetarderConfigurationMessage; a field of j1939_pgn65249_payload (was engine_brake_cylinders_per_step; PR #53 round 96)."]),
])
DISPATCH = "0x0002f4be,cm550_dispatchJ1939PgnRequest,0,rx_msg,can_std_rx_desc_t*,"
t550 = open(os.path.join(C550, "function_definitions.csv"), newline="").read()
dispatch_line = next(l for l in t550.replace("\r\n", "\n").split("\n") if l.startswith(DISPATCH))
edit(os.path.join(C550, "function_definitions.csv"), [
    ("0x0002ef4a,cm550_receivePgn58112Dm7CommandNonContinuouslyMonitoredTestMessage,0,msg_ptr,int,Pointer to diagnostic message structure",
     [f"0x0002ef1c,cm550_j1939HandlePgn65228Dm3ClearInactiveFaults,return,,void,Returns nothing: the body ends with the acknowledgement call {R}",
      f"0x0002ef1c,cm550_j1939HandlePgn65228Dm3ClearInactiveFaults,0,request_message,can_std_rx_desc_t*,The PGN 59904 request that cm550_dispatchJ1939PgnRequest passes: the long at +4 (movea.l (0x4;a7);a0) - handed to cm550_diagnosticCanResponseSender for the acknowledgement {R}",
      f"0x0002ef4a,cm550_receivePgn58112Dm7CommandNonContinuouslyMonitoredTestMessage,return,,void,Returns nothing {R}",
      f"0x0002ef4a,cm550_receivePgn58112Dm7CommandNonContinuouslyMonitoredTestMessage,0,request_message,can_std_rx_desc_t*,The received DM7 frame: the long at +4 (movea.l (0x10;a7);a2 after saving 3 registers); data_pointer (+6) byte 0 is the test identifier - the frame goes to cm550_diagnosticCanResponseSender for the negative acknowledgement (was msg_ptr int) {R}"]),
    (dispatch_line,
     [dispatch_line,
      f"0x0002f47e,registerJ1939PgnRequestHandler,return,,byte,1 when the table is full and nothing was registered (moveq #1;d0 with j1939_pgn_handler_count = 32) - else 0 (clr.b d0) after appending the entry {R}",
      f"0x0002f47e,registerJ1939PgnRequestHandler,0,pgn,ushort,The requested PGN's low 16 bits (e.g. 0xfee4 for PGN 65252): the word at +4 (move.w (0x8;a7) after the a2 push) - stored at the entry's +0 with the PDU format byte first {R}",
      f"0x0002f47e,registerJ1939PgnRequestHandler,1,handler,void*,The request handler: the long at +6 (move.l (0xa;a7)) - stored at the entry's +2; cm550_dispatchJ1939PgnRequest calls it with the request {R}",
      f"0x0002fb70,dispatchTsc1ByDestinationAddress,return,,void,Returns nothing {R}",
      f"0x0002fb70,dispatchTsc1ByDestinationAddress,0,message,can_std_rx_desc_t*,The received TSC1 frame: the long at +4 (movea.l (0xc;a7);a2 after saving 2 registers); ID byte 2 is the destination address - the frame goes on to the engine and retarder processors {R}"]),
])
G = os.path.join(C848, "function_definitions.csv")
edit(G, [("0x00023b38,dispatchTsc1ByDestinationAddress,0,rx_msg,j1939_received_message_t*,Pointer to received J1939 message for address filtering", [])])
delete_nth(G, "0x00002cd8,cm848_registerPgnEf00Handler,0,sub_id,byte,Sub-identifier for PGN 0xEF00 filtering", 2)
delete_nth(G, "0x00002cd8,cm848_registerPgnEf00Handler,1,handler_func,void*,Function pointer for handler callback", 2)
edit(os.path.join(C848, "global_variables.csv"), [
    ("0x003fa9a2,j1939_pgn_dispatch_table,j1939_pgn_handler_entry_t,",
     ["0x003fa9a2,j1939_pgn_dispatch_table,j1939_pgn_handler_entry_t[32],The PGN 59904 request handler table: 32 entries of 6 bytes (+0 / +1 the requested PGN's low 16 bits with the PDU format byte first; +2 the handler). registerJ1939PgnRequestHandler appends an entry while j1939_pgn_handler_count is below 32 and cm848_dispatchJ1939PgnRequest searches the first j1939_pgn_handler_count entries; the table ends at j1939_pgn_handler_count 0x3faa62. CM550's twin table is 0x801d5a (PR #53 round 96: one entry -> the 32-entry array)."]),
    ("0x003fa9a3,j1939_pgn_dispatch_table.pgn_byte_0,,", []),
    ("0x003fa9a4,j1939_pgn_dispatch_table.handler_func,,", []),
    ("0x003fa9aa,,pointer,", []),
])
print("ok")
