#!/usr/bin/env python3
"""
Apply high-confidence cross-firmware matches to function_renames.csv files.

Reads cross_firmware_matches.csv and applies name/rename actions to the
CM550 and CM848 function_renames.csv files.

Usage:
    python3 apply_cross_firmware_matches.py \
        firmware/cross_firmware_matches.csv \
        firmware/CM550_J90350.00_analysis/output/function_renames.csv \
        firmware/CM848_S90140.06_analysis/output/function_renames.csv \
        [--min-score 30] [--dry-run] [--include-review]
"""

import argparse
import csv
import sys


def load_function_renames(csv_path):
    """Load function_renames.csv into (comments, entries_dict).

    Returns:
        comments: list of comment lines (with newlines stripped)
        entries: dict of address -> name
        order: list of addresses in original order
    """
    comments = []
    entries = {}
    order = []
    header_seen = False

    with open(csv_path, 'r') as f:
        for line in f:
            line = line.rstrip('\n').rstrip('\r')
            if line.startswith('#'):
                comments.append(line)
                continue
            if not header_seen:
                # Skip header line
                header_seen = True
                continue
            parts = line.split(',', 1)
            if len(parts) >= 2:
                addr = parts[0].strip()
                name = parts[1].strip()
                entries[addr] = name
                order.append(addr)

    return comments, entries, order


def write_function_renames(csv_path, comments, entries, order):
    """Write function_renames.csv back to disk."""
    with open(csv_path, 'w') as f:
        for comment in comments:
            f.write(comment + '\n')
        f.write('address,name\n')
        # Write existing entries in original order
        written = set()
        for addr in order:
            if addr in entries:
                f.write(f'{addr},{entries[addr]}\n')
                written.add(addr)
        # Write any new entries not in original order (appended)
        for addr in sorted(entries.keys()):
            if addr not in written:
                f.write(f'{addr},{entries[addr]}\n')


def load_matches(csv_path):
    """Load cross_firmware_matches.csv."""
    matches = []
    with open(csv_path, 'r', newline='') as f:
        reader = csv.DictReader(f)
        for row in reader:
            row['score'] = int(row['score'])
            matches.append(row)
    return matches


def parse_action(action_str):
    """Parse action string into (action_type, name).

    Returns:
        (action_type, name) where action_type is one of:
        name_cm550, name_cm848, rename_both, rename_cm550, rename_cm848, review, both_unnamed
    """
    if ':' in action_str:
        action_type, name = action_str.split(':', 1)
        return action_type, name
    return action_str, None


def check_collision(entries, target_addr, target_name):
    """Check if target_name already exists at a DIFFERENT address.

    Returns the conflicting address if collision found, None otherwise.
    """
    for addr, name in entries.items():
        if name == target_name and addr != target_addr:
            return addr
    return None


def apply_entry(entries, order, addr, name, label):
    """Apply a single name to entries dict. Returns (applied, conflict_msg)."""
    collision_addr = check_collision(entries, addr, name)
    if collision_addr:
        return False, f"COLLISION: {name} already at {collision_addr} in {label}"

    if addr in entries:
        old_name = entries[addr]
        entries[addr] = name
        return True, f"  {label}: {addr} {old_name} -> {name}"
    else:
        entries[addr] = name
        order.append(addr)
        return True, f"  {label}: {addr} (new) -> {name}"


def main():
    parser = argparse.ArgumentParser(
        description='Apply cross-firmware matches to function_renames.csv files')
    parser.add_argument('matches_csv', help='cross_firmware_matches.csv')
    parser.add_argument('cm550_csv', help='CM550 function_renames.csv')
    parser.add_argument('cm848_csv', help='CM848 function_renames.csv')
    parser.add_argument('--min-score', type=int, default=30,
                        help='Minimum score to apply (default: 30)')
    parser.add_argument('--dry-run', action='store_true',
                        help='Show what would be done without applying')
    parser.add_argument('--include-review', action='store_true',
                        help='Also apply review items (use with caution)')
    args = parser.parse_args()

    # Load data
    matches = load_matches(args.matches_csv)
    cm550_comments, cm550_entries, cm550_order = load_function_renames(args.cm550_csv)
    cm848_comments, cm848_entries, cm848_order = load_function_renames(args.cm848_csv)

    applied = 0
    collisions = 0
    skipped_review = 0
    skipped_score = 0
    skipped_both_unnamed = 0
    messages = []

    for match in matches:
        score = match['score']
        action_str = match['action']
        action_type, name = parse_action(action_str)

        # Filter by score
        if score < args.min_score:
            skipped_score += 1
            continue

        # Filter review items
        if action_type == 'review' and not args.include_review:
            skipped_review += 1
            continue

        # Skip both_unnamed (nothing to do)
        if action_type == 'both_unnamed':
            skipped_both_unnamed += 1
            continue

        # Skip actions without a name
        if name is None:
            continue

        cm550_addr = match['cm550_addr']
        cm848_addr = match['cm848_addr']

        if action_type == 'name_cm550':
            ok, msg = apply_entry(cm550_entries, cm550_order, cm550_addr, name, 'CM550')
            messages.append(msg)
            if ok:
                applied += 1
            else:
                collisions += 1

        elif action_type == 'name_cm848':
            ok, msg = apply_entry(cm848_entries, cm848_order, cm848_addr, name, 'CM848')
            messages.append(msg)
            if ok:
                applied += 1
            else:
                collisions += 1

        elif action_type == 'rename_cm550':
            ok, msg = apply_entry(cm550_entries, cm550_order, cm550_addr, name, 'CM550')
            messages.append(msg)
            if ok:
                applied += 1
            else:
                collisions += 1

        elif action_type == 'rename_cm848':
            ok, msg = apply_entry(cm848_entries, cm848_order, cm848_addr, name, 'CM848')
            messages.append(msg)
            if ok:
                applied += 1
            else:
                collisions += 1

        elif action_type == 'rename_both':
            ok1, msg1 = apply_entry(cm550_entries, cm550_order, cm550_addr, name, 'CM550')
            ok2, msg2 = apply_entry(cm848_entries, cm848_order, cm848_addr, name, 'CM848')
            messages.append(msg1)
            messages.append(msg2)
            if ok1:
                applied += 1
            else:
                collisions += 1
            if ok2:
                applied += 1
            else:
                collisions += 1

    # Print messages
    for msg in messages:
        print(msg)

    # Summary
    print(f"\n{'='*60}")
    print(f"Applied: {applied}")
    print(f"Collisions: {collisions}")
    print(f"Skipped (review): {skipped_review}")
    print(f"Skipped (score < {args.min_score}): {skipped_score}")
    print(f"Skipped (both_unnamed): {skipped_both_unnamed}")

    if args.dry_run:
        print(f"\n*** DRY RUN - no files modified ***")
    else:
        write_function_renames(args.cm550_csv, cm550_comments, cm550_entries, cm550_order)
        write_function_renames(args.cm848_csv, cm848_comments, cm848_entries, cm848_order)
        print(f"\nUpdated: {args.cm550_csv}")
        print(f"Updated: {args.cm848_csv}")


if __name__ == '__main__':
    main()
