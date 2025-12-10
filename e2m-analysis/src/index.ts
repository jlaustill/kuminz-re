#!/usr/bin/env tsx

// Main entry point for e2m analysis tools
// Run individual analysis tools with npm scripts

console.log('E2M Analysis Tools');
console.log('==================');
console.log('');
console.log('Available commands:');
console.log('  npm run analyze:common     - Find lines common to all files');
console.log('  npm run analyze:unique     - Find lines unique to each file');
console.log('  npm run analyze:differences - Find lines that differ between files');
console.log('  npm run analyze:stats      - Generate column statistics');
console.log('  npm run analyze:all        - Run all analysis tools');
console.log('');
console.log('Output files will be created in the docs/ directory');

export default {};