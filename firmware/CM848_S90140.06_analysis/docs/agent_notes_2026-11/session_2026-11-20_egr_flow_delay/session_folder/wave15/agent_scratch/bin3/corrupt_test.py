"""Make a corrupted copy of the result file to prove the validator catches errors."""
import json

SRC = "/home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin3.jsonl"
DST = "/home/linux/.claude/jobs/374b0424/tmp/w15/agent_scratch/bin3/corrupt.jsonl"
lines = [json.loads(line) for line in open(SRC)]
lines[0]["code_quote"] = lines[0]["code_quote"].replace("drivetrain_ratio_user_filtered", "drivetrain_ratio_user_filtered_x")  # quote not in cpp
lines[1]["new"] = "governor_setpoint_table_cal"  # exists already
lines[13]["new"] = "j1939_pgn65269_priority"  # missing _cal in the mirror
lines[33]["new"] = lines[13]["new"]  # duplicate name
lines[4]["comment"] += " (was something)"
lines[11]["e2m_note"] = "wrong shape"
lines[20]["address"] = "0x00000000"
with open(DST, "w") as handle:
    handle.write("\n".join(json.dumps(x) for x in lines) + "\n")
print("wrote", DST)
