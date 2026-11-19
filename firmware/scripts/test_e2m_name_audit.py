#!/usr/bin/env python3
"""Tests for e2m_name_audit.py helpers: e2m word splitting / abbreviation expansion, the overlap score, row widths."""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import e2m_name_audit as m  # noqa: E402

failures = []


def check(label, got, expected):
    if got != expected:
        failures.append(f"{label}: got {got!r}, expected {expected!r}")


check("words: prefix and abbreviations", m.words("C_EMO_Extreme_Amb_AECD_Off_Thd"),
      ["extreme", "ambient", "aecd", "off", "threshold"])
check("words: camel case and digits", m.words("PTO_Remote_Speed_2"), ["power", "take", "off", "remote", "speed", "2"])
check("words: snake name", m.words("extreme_ambient_overheat_protection_off_coolant_temperature"),
      ["extreme", "ambient", "overheat", "protection", "off", "coolant", "temperature"])
check("overlap: full", m.token_overlap("CBO_Fuel_Ref", "fuel_quantity_compensated_reference"), "1.00")
check("overlap: none", m.token_overlap("Ambient_Air_Tmptr", "boost_fuel_demand_blend_a"), "0.00")
check("overlap: no current name", m.token_overlap("Ambient_Air_Tmptr", ""), "")
check("width: scalar", m.width("word"), 2)
check("width: array", m.width("word[17]"), 34)
check("width: byte array", m.width("byte[5]"), 5)
check("width: struct (unknown)", m.width("ema_filter_state_t"), 0)

print("\n".join(failures) if failures else "ALL PASS")
sys.exit(1 if failures else 0)
