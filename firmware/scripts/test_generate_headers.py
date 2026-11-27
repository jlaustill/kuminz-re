#!/usr/bin/env python3
"""Tests for generate_headers.py: a structure_definitions.csv function type row ("function:<return>(<type> <name>;...)")
becomes a function typedef in firmware_types.hpp, not a struct, and a field typed "<name>*" compiles against it."""
import os
import shutil
import subprocess
import sys
import tempfile

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import generate_headers as m  # noqa: E402

failures = []


def check(label, got, expected):
    if got != expected:
        failures.append(f"{label}: got {got!r}, expected {expected!r}")


STRUCTS = """struct_name,address,field_name,type,size,comment,dependency,Status
# a handler table entry and its handler's function type
service_entry_t,,service_id,SERVICE_ID,1,The service byte,,verified
service_entry_t,,pad,byte,1,Unused,,verified
service_entry_t,,handler,service_handler_function_t*,4,"The handler, called with the request",,verified
service_handler_function_t,,,function:byte(request_t* request),0,"A service handler: the request in, the result out",,verified
request_t,,id,dword,4,The identifier,,verified
request_t,,length,word,2,The data length,,verified
request_t,,data_pointer,byte*,4,The data,,verified
builder_function_t,,,function:void(),0,,,verified
two_argument_function_t,,,function:SERVICE_ID(word pgn;request_t *request),0,Two parameters,,verified
"""
ENUMS = """enum_name,value,member_name,comment,size
SERVICE_ID,1,SERVICE_ID_FIRST,The first service,1
"""

with tempfile.TemporaryDirectory() as tmp:
    open(os.path.join(tmp, "structure_definitions.csv"), "w").write(STRUCTS)
    open(os.path.join(tmp, "enums.csv"), "w").write(ENUMS)
    content, stats = m.generate_types_header(tmp)
    check("the function types are counted", stats.get("function_types"), 3)
    check("the function types are not structs", stats.get("structs"), 2)
    check("a function typedef with a struct pointer parameter",
          "typedef uint8_t service_handler_function_t(request_t* request);" in content, True)
    check("its comment is kept", "/* A service handler: the request in, the result out */" in content, True)
    check("a function typedef with no parameters", "typedef void builder_function_t(void);" in content, True)
    check("a function typedef with two parameters and an enum result",
          "typedef SERVICE_ID two_argument_function_t(uint16_t pgn, request_t* request);" in content, True)
    check("no struct is declared for a function type", "struct service_handler_function_t" in content, False)
    check("the field holds a pointer to the function type", "    service_handler_function_t* handler;" in content, True)
    check("the typedef comes after the struct forward declarations",
          content.index("typedef struct request_t request_t;") < content.index("typedef uint8_t service_handler_function_t("), True)
    check("the typedef comes before the struct that uses it",
          content.index("typedef uint8_t service_handler_function_t(") < content.index("struct service_entry_t {"), True)
    compiler = shutil.which("g++")
    if compiler:
        header = os.path.join(tmp, "firmware_types.hpp")
        open(header, "w").write(content)
        source = os.path.join(tmp, "use.cpp")
        open(source, "w").write('#include "firmware_types.hpp"\n'
                                "uint8_t first(request_t *request) { return (uint8_t)request->length; }\n"
                                "uint8_t call(service_entry_t *entry, request_t *request) {\n"
                                "    entry->handler = first;\n"
                                "    return (*entry->handler)(request);\n"
                                "}\n")
        result = subprocess.run([compiler, "-fsyntax-only", "-std=c++17", "-I", tmp, source], capture_output=True, text=True)
        check("the header compiles and the field is callable", result.stderr.strip(), "")

print("\n".join(failures) if failures else "ALL PASS")
sys.exit(1 if failures else 0)
