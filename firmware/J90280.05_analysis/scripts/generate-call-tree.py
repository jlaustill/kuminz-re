#!/usr/bin/env python3
"""
Generate an interactive HTML call tree from decompiled C code.
Parses function definitions and calls to build a navigable tree view.
"""

import re
import json
from collections import defaultdict
from pathlib import Path

# Entry points for the firmware
ENTRY_POINTS = [
    'main',
    'main_loop',
]

# ISR and timer-driven functions (called by hardware, not by code)
HARDWARE_ENTRY_POINTS = [
    # ISR handlers
    'rpmTimerInterruptHandler',
    'rpmTimerInterruptHandlerAlt',
    'rpmTimerInterruptHandler2',
    'rpmTimerInterruptHandler3',
    'dutyCycleMonitorIsrHandler',
    'dutyCycleMonitorAltIsrHandler',
    'serialPort1IsrHandler',
    'serialPort2IsrHandler',
    'epsPositionSensorIsrHandler',
    'tpuQadcInterruptHandler',
    'interruptCounter1Increment',
    'interruptCounter2Increment',
]

def parse_c_file(filepath):
    """Parse C file to extract function definitions and calls."""
    with open(filepath, 'r') as f:
        content = f.read()

    # Find all function definitions with their bodies
    # Pattern: return_type function_name(params) { body }
    func_pattern = re.compile(
        r'^(?:void|int|uint|ushort|short|byte|word|dword|undefined\d*|ulonglong)\s+'
        r'(\w+)\s*\([^)]*\)\s*\{',
        re.MULTILINE
    )

    functions = {}
    func_starts = []

    for match in func_pattern.finditer(content):
        func_name = match.group(1)
        start_pos = match.start()
        func_starts.append((start_pos, func_name))

    # Sort by position
    func_starts.sort()

    # Extract function bodies and find calls within each
    for i, (start_pos, func_name) in enumerate(func_starts):
        # Find the end of this function (next function start or EOF)
        if i + 1 < len(func_starts):
            end_pos = func_starts[i + 1][0]
        else:
            end_pos = len(content)

        func_body = content[start_pos:end_pos]

        # Find all function calls in the body
        # Pattern: identifier followed by (
        call_pattern = re.compile(r'\b([a-zA-Z_]\w*)\s*\(')
        calls = set()

        for call_match in call_pattern.finditer(func_body):
            called_func = call_match.group(1)
            # Filter out keywords and common non-functions
            if called_func not in {'if', 'while', 'for', 'switch', 'return', 'sizeof',
                                   'typeof', 'case', 'goto', func_name}:
                calls.add(called_func)

        functions[func_name] = {
            'calls': sorted(calls),
            'called_by': []  # Will be populated in second pass
        }

    # Second pass: populate called_by
    for func_name, data in functions.items():
        for called in data['calls']:
            if called in functions:
                functions[called]['called_by'].append(func_name)

    # Sort called_by lists
    for func_name in functions:
        functions[func_name]['called_by'].sort()

    return functions

def build_call_tree(functions, root, visited=None, depth=0, max_depth=50):
    """Build a tree structure starting from root function."""
    if visited is None:
        visited = set()

    if root in visited or depth > max_depth:
        return {'name': root, 'recursive': True, 'children': []}

    visited.add(root)

    if root not in functions:
        return {'name': root, 'external': True, 'children': []}

    children = []
    for called in functions[root]['calls']:
        if called in functions:  # Only include defined functions
            child_tree = build_call_tree(functions, called, visited.copy(), depth + 1, max_depth)
            children.append(child_tree)

    return {
        'name': root,
        'children': children,
        'call_count': len(functions[root]['calls']),
        'caller_count': len(functions[root]['called_by'])
    }

def generate_html(functions, entry_points, hardware_entries, output_path):
    """Generate interactive HTML with collapsible tree view."""

    # Build trees for each entry point
    trees = {}
    for entry in entry_points:
        if entry in functions:
            trees[entry] = build_call_tree(functions, entry)

    hardware_trees = {}
    for entry in hardware_entries:
        if entry in functions:
            hardware_trees[entry] = build_call_tree(functions, entry)

    # Find orphan functions (not called by anyone and not entry points)
    all_entry = set(entry_points) | set(hardware_entries)
    orphans = []
    for func_name, data in functions.items():
        if not data['called_by'] and func_name not in all_entry:
            orphans.append(func_name)
    orphans.sort()

    html = '''<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>CM550 Firmware Call Tree</title>
    <style>
        * { box-sizing: border-box; }
        body {
            font-family: 'Consolas', 'Monaco', monospace;
            font-size: 13px;
            margin: 0;
            padding: 20px;
            background: #1e1e1e;
            color: #d4d4d4;
        }
        h1 { color: #569cd6; margin-bottom: 5px; }
        h2 { color: #4ec9b0; margin-top: 25px; margin-bottom: 10px; }
        h3 { color: #9cdcfe; margin-top: 20px; margin-bottom: 8px; }
        .stats { color: #6a9955; margin-bottom: 20px; }
        .tree { margin-left: 0; }
        .tree ul {
            list-style: none;
            padding-left: 20px;
            margin: 0;
        }
        .tree > ul { padding-left: 0; }
        .tree li {
            position: relative;
            padding: 2px 0;
        }
        .tree li::before {
            content: '';
            position: absolute;
            left: -15px;
            top: 0;
            border-left: 1px solid #404040;
            height: 100%;
        }
        .tree li::after {
            content: '';
            position: absolute;
            left: -15px;
            top: 10px;
            border-top: 1px solid #404040;
            width: 12px;
        }
        .tree li:last-child::before {
            height: 10px;
        }
        .tree > ul > li::before, .tree > ul > li::after { display: none; }

        .func {
            cursor: pointer;
            padding: 2px 6px;
            border-radius: 3px;
            display: inline-block;
        }
        .func:hover { background: #264f78; }
        .func.has-children::before {
            content: '▶ ';
            font-size: 10px;
            color: #808080;
        }
        .func.expanded::before {
            content: '▼ ';
        }
        .func.no-children::before {
            content: '• ';
            color: #808080;
        }
        .func.recursive { color: #f14c4c; }
        .func.recursive::after { content: ' ↻'; }
        .func.external { color: #808080; font-style: italic; }

        .count {
            color: #6a9955;
            font-size: 11px;
            margin-left: 5px;
        }

        .search-box {
            position: fixed;
            top: 10px;
            right: 20px;
            background: #252526;
            padding: 10px;
            border-radius: 5px;
            border: 1px solid #404040;
            z-index: 100;
        }
        .search-box input {
            background: #3c3c3c;
            border: 1px solid #404040;
            color: #d4d4d4;
            padding: 5px 10px;
            font-family: inherit;
            width: 250px;
        }
        .search-box input:focus { outline: 1px solid #569cd6; }

        .highlight { background: #613214 !important; }

        .section {
            margin-bottom: 30px;
            border: 1px solid #404040;
            padding: 15px;
            border-radius: 5px;
            background: #252526;
        }

        .orphan-list {
            column-count: 4;
            column-gap: 20px;
        }
        .orphan-list span {
            display: block;
            padding: 1px 0;
            color: #ce9178;
        }

        .tabs {
            display: flex;
            gap: 5px;
            margin-bottom: 15px;
        }
        .tab {
            padding: 8px 16px;
            background: #2d2d2d;
            border: 1px solid #404040;
            border-radius: 5px 5px 0 0;
            cursor: pointer;
            color: #808080;
        }
        .tab.active {
            background: #252526;
            color: #d4d4d4;
            border-bottom-color: #252526;
        }
        .tab-content { display: none; }
        .tab-content.active { display: block; }

        #callers-panel {
            position: fixed;
            bottom: 20px;
            right: 20px;
            width: 300px;
            max-height: 300px;
            overflow-y: auto;
            background: #252526;
            border: 1px solid #404040;
            border-radius: 5px;
            padding: 10px;
            display: none;
        }
        #callers-panel h4 { margin: 0 0 10px 0; color: #4ec9b0; }
        #callers-panel ul { margin: 0; padding-left: 20px; }
        #callers-panel li { color: #9cdcfe; padding: 2px 0; }
    </style>
</head>
<body>
    <h1>CM550 Firmware Call Tree</h1>
    <div class="stats">''' + f'''
        {len(functions)} functions |
        {len(entry_points)} entry points |
        {len(hardware_entries)} ISR/hardware handlers |
        {len(orphans)} orphan functions
    </div>

    <div class="search-box">
        <input type="text" id="search" placeholder="Search functions..." oninput="searchFunctions(this.value)">
    </div>

    <div class="tabs">
        <div class="tab active" onclick="showTab('main')">Main Entry</div>
        <div class="tab" onclick="showTab('isr')">ISR Handlers</div>
        <div class="tab" onclick="showTab('orphans')">Orphans ({len(orphans)})</div>
        <div class="tab" onclick="showTab('all')">All Functions</div>
    </div>

    <div id="main" class="tab-content active">
        <div class="section">
            <h2>Program Entry Points</h2>
''' + '\n'.join(f'            <h3>{name}()</h3>\n            <div class="tree">{render_tree(trees.get(name, {"name": name, "children": []}))}</div>'
                for name in entry_points if name in functions) + '''
        </div>
    </div>

    <div id="isr" class="tab-content">
        <div class="section">
            <h2>Interrupt Service Routines & Hardware Handlers</h2>
            <p style="color: #6a9955;">These functions are called by hardware interrupts, not by other code.</p>
''' + '\n'.join(f'            <h3>{name}()</h3>\n            <div class="tree">{render_tree(hardware_trees.get(name, {"name": name, "children": []}))}</div>'
                for name in hardware_entries if name in functions) + '''
        </div>
    </div>

    <div id="orphans" class="tab-content">
        <div class="section">
            <h2>Orphan Functions</h2>
            <p style="color: #6a9955;">Functions not called by any other function (may be called via function pointers or lookup tables).</p>
            <div class="orphan-list">
''' + '\n'.join(f'                <span onclick="searchFunctions(\'{name}\')">{name}</span>' for name in orphans) + '''
            </div>
        </div>
    </div>

    <div id="all" class="tab-content">
        <div class="section">
            <h2>All Functions (Alphabetical)</h2>
            <div class="orphan-list">
''' + '\n'.join(f'                <span onclick="searchFunctions(\'{name}\')">{name}</span>' for name in sorted(functions.keys())) + '''
            </div>
        </div>
    </div>

    <div id="callers-panel">
        <h4>Called By:</h4>
        <ul id="callers-list"></ul>
    </div>

    <script>
        const functionData = ''' + json.dumps({k: {'calls': v['calls'], 'called_by': v['called_by']} for k, v in functions.items()}) + ''';

        function toggleNode(el) {
            const li = el.closest('li');
            const ul = li.querySelector(':scope > ul');
            if (ul) {
                ul.style.display = ul.style.display === 'none' ? 'block' : 'none';
                el.classList.toggle('expanded');
            }

            // Show callers panel
            const funcName = el.textContent.replace(/[▶▼• ↻]/g, '').trim().split('(')[0];
            showCallers(funcName);
        }

        function showCallers(funcName) {
            const panel = document.getElementById('callers-panel');
            const list = document.getElementById('callers-list');

            if (functionData[funcName]) {
                const callers = functionData[funcName].called_by;
                if (callers.length > 0) {
                    list.innerHTML = callers.map(c => `<li onclick="searchFunctions('${c}')">${c}</li>`).join('');
                    panel.style.display = 'block';
                } else {
                    list.innerHTML = '<li style="color:#808080">No callers (entry point or orphan)</li>';
                    panel.style.display = 'block';
                }
            } else {
                panel.style.display = 'none';
            }
        }

        function searchFunctions(query) {
            document.getElementById('search').value = query;

            // Remove existing highlights
            document.querySelectorAll('.highlight').forEach(el => el.classList.remove('highlight'));

            if (!query) return;

            // Find and highlight matching functions
            const lowerQuery = query.toLowerCase();
            document.querySelectorAll('.func').forEach(el => {
                const funcName = el.textContent.replace(/[▶▼• ↻]/g, '').trim();
                if (funcName.toLowerCase().includes(lowerQuery)) {
                    el.classList.add('highlight');

                    // Expand parents
                    let parent = el.closest('li');
                    while (parent) {
                        const parentUl = parent.closest('ul');
                        if (parentUl) {
                            parentUl.style.display = 'block';
                            const parentFunc = parentUl.closest('li')?.querySelector(':scope > .func');
                            if (parentFunc) parentFunc.classList.add('expanded');
                        }
                        parent = parentUl?.closest('li');
                    }

                    // Show callers
                    const baseName = funcName.split('(')[0];
                    showCallers(baseName);
                }
            });
        }

        function showTab(tabId) {
            document.querySelectorAll('.tab').forEach(t => t.classList.remove('active'));
            document.querySelectorAll('.tab-content').forEach(t => t.classList.remove('active'));
            document.querySelector(`.tab[onclick="showTab('${tabId}')"]`).classList.add('active');
            document.getElementById(tabId).classList.add('active');
        }

        // Initially collapse all nested lists
        document.querySelectorAll('.tree ul ul').forEach(ul => ul.style.display = 'none');
    </script>
</body>
</html>'''

    with open(output_path, 'w') as f:
        f.write(html)

    print(f"Generated: {output_path}")
    print(f"  - {len(functions)} functions parsed")
    print(f"  - {len(trees)} entry point trees")
    print(f"  - {len(hardware_trees)} ISR trees")
    print(f"  - {len(orphans)} orphan functions")

def render_tree(node, depth=0):
    """Render a tree node as HTML."""
    if depth > 30:  # Prevent infinite recursion in output
        return '<ul><li><span class="func recursive">... (depth limit)</span></li></ul>'

    name = node['name']
    children = node.get('children', [])
    is_recursive = node.get('recursive', False)
    is_external = node.get('external', False)

    classes = ['func']
    if is_recursive:
        classes.append('recursive')
    elif is_external:
        classes.append('external')
    elif children:
        classes.append('has-children')
    else:
        classes.append('no-children')

    counts = ''
    if 'call_count' in node:
        counts = f'<span class="count">→{node["call_count"]} ←{node["caller_count"]}</span>'

    html = f'<ul><li><span class="{" ".join(classes)}" onclick="toggleNode(this)">{name}()</span>{counts}'

    if children and not is_recursive:
        for child in children:
            html += render_tree(child, depth + 1)

    html += '</li></ul>'
    return html


if __name__ == '__main__':
    script_dir = Path(__file__).parent
    project_dir = script_dir.parent

    c_file = project_dir / 'ghidra' / 'CM550.rep' / 'working' / 'J90280.05.ghidra.c'
    output_file = project_dir / 'ghidra' / 'CM550.rep' / 'call-tree.html'

    print(f"Parsing: {c_file}")
    functions = parse_c_file(c_file)

    print(f"Generating call tree...")
    generate_html(functions, ENTRY_POINTS, HARDWARE_ENTRY_POINTS, output_file)

    print(f"\nOpen in browser: {output_file}")
