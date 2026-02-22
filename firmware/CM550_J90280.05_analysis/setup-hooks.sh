#!/bin/bash

# Setup script for J90280.05 analysis Git hooks
# Run this once after cloning the repository

echo "🔧 Setting up Git hooks for J90280.05 analysis..."

# Configure Git to use our custom hooks directory
git config core.hooksPath .githooks

echo "✅ Git hooks configured!"
echo ""
echo "📋 Available hooks:"
echo "  • pre-commit: Auto-sorts CSV files to prevent merge conflicts"
echo ""
echo "🎯 Benefits:"
echo "  • Automatic CSV sorting by address/struct/enum rules"
echo "  • Zero merge conflicts during collaborative reverse engineering"
echo "  • Consistent file organization across team members"
echo ""
echo "🚀 You're all set! CSV files will be automatically sorted on every commit."