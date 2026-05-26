#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SCRIPTS_DIR="$(dirname "$SCRIPT_DIR")/scripts"
JUNIT_JAR="$SCRIPT_DIR/junit-platform-console-standalone.jar"
BUILD_DIR="$SCRIPT_DIR/build"

# Download JUnit 5 standalone if not present
if [ ! -f "$JUNIT_JAR" ]; then
    echo "Downloading JUnit 5 standalone..."
    curl -sL -o "$JUNIT_JAR" \
        "https://repo1.maven.org/maven2/org/junit/platform/junit-platform-console-standalone/1.10.2/junit-platform-console-standalone-1.10.2.jar"
fi

mkdir -p "$BUILD_DIR"

echo "Compiling..."
javac -cp "$JUNIT_JAR" \
    -d "$BUILD_DIR" \
    "$SCRIPTS_DIR/ScriptUtils.java" \
    "$SCRIPTS_DIR/CsvCommentIndex.java" \
    "$SCRIPT_DIR/ScriptUtilsTest.java" \
    "$SCRIPT_DIR/CsvCommentIndexTest.java"

echo "Running tests..."
java -jar "$JUNIT_JAR" \
    --class-path "$BUILD_DIR" \
    --select-class ScriptUtilsTest \
    --select-class CsvCommentIndexTest \
    --details=tree
