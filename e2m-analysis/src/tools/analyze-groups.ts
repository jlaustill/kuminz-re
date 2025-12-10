#!/usr/bin/env tsx

import { writeFileSync } from 'fs';
import parseE2MFile from '../utils/e2m-parser.js';

const E2M_FILE = 'originals/v64t6_s.e2m';
const OUTPUT_FILE = 'docs/groups.md';

// Calterm group data provided by user
const CALTERM_GROUPS = [
  {
    name: 'IIMSGR0',
    members: ['ISEKGEN', 'ISTAEN']
  },
  {
    name: 'IDLE_D08',
    members: ['ISAATPEN', 'ISIMOF', 'ISWRTMLM']
  },
  {
    name: 'ACC_INT2',
    members: ['ANEN', 'ANPZ']
  },
  {
    name: 'AECDGP',
    members: ['AECTOFF', 'AECTON', 'AEMTOFF', 'AEMTON', 'BERMRT', 'BETA', 'BETAMX', 'UCBE']
  },
  {
    name: 'AFC',
    members: ['AFCNICTA', 'AFENMAN', 'AFFL', 'AFFLMAN', 'AFICTA']
  }
];

const UNGROUPED_PARAMS = [
  '4DTA01ZA', '4DTA01XA', '4DTA01YA', '5DFL00ZA', '5DFL00XA', '5DFL00YA'
];

function analyzeGroups() {
  console.log('Analyzing Calterm group data vs e2m structure...');
  
  const e2mFile = parseE2MFile(E2M_FILE);
  console.log(`Loaded ${e2mFile.rows.length} parameters from ${E2M_FILE}`);
  
  // Find group members in e2m data
  const groupAnalysis = [];
  
  for (const group of CALTERM_GROUPS) {
    const memberData = [];
    
    for (const memberName of group.members) {
      const param = e2mFile.rows.find(row => row.fullName === memberName);
      if (param) {
        memberData.push({
          name: memberName,
          subfile: param.subfileNumber,
          column3: param.column3,
          column4: param.column4,
          column5: param.column5,
          column7: param.column7,
          column14: param.column14,
          column15: param.column15,
          column16: param.column16,
          type: param.type,
          rawLine: param.rawLine
        });
      } else {
        console.log(`WARNING: ${memberName} not found in e2m file`);
      }
    }
    
    if (memberData.length > 0) {
      groupAnalysis.push({
        groupName: group.name,
        members: memberData,
        patterns: analyzeGroupPatterns(memberData)
      });
    }
  }
  
  // Analyze ungrouped parameters
  const ungroupedData = [];
  for (const paramName of UNGROUPED_PARAMS) {
    const param = e2mFile.rows.find(row => row.fullName === paramName);
    if (param) {
      ungroupedData.push({
        name: paramName,
        subfile: param.subfileNumber,
        column3: param.column3,
        column4: param.column4,
        column5: param.column5,
        column7: param.column7,
        column14: param.column14,
        column15: param.column15,
        column16: param.column16,
        type: param.type,
        rawLine: param.rawLine
      });
    }
  }
  
  // Look for Type G parameters (group headers)
  const typeGParams = e2mFile.rows.filter(row => row.type === 'G');
  console.log(`Found ${typeGParams.length} Type G parameters`);
  
  generateGroupsReport(groupAnalysis, ungroupedData, typeGParams);
}

function analyzeGroupPatterns(members: any[]) {
  const patterns = {
    subfiles: [...new Set(members.map(m => m.subfile))],
    column3Values: [...new Set(members.map(m => m.column3))],
    column4Values: [...new Set(members.map(m => m.column4))],
    column5Values: [...new Set(members.map(m => m.column5))],
    column7Values: [...new Set(members.map(m => m.column7))],
    column14Values: [...new Set(members.map(m => m.column14))],
    column15Values: [...new Set(members.map(m => m.column15))],
    column16Values: [...new Set(members.map(m => m.column16))],
    types: [...new Set(members.map(m => m.type))]
  };
  
  return patterns;
}

function generateGroupsReport(groupAnalysis: any[], ungroupedData: any[], typeGParams: any[]) {
  const lines = [
    '# E2M Group Analysis',
    '',
    `Generated: ${new Date().toISOString()}`,
    `Source: ${E2M_FILE} + Calterm group data`,
    '',
    '## Objective',
    '',
    'Determine which unknown column(s) define parameter grouping by analyzing Calterm group memberships against e2m file structure.',
    '',
    '## Calterm Group Data Analysis',
    '',
    `Found ${groupAnalysis.length} groups with members in e2m file:`,
    ''
  ];
  
  // Analyze each group
  groupAnalysis.forEach((group, index) => {
    lines.push(`### Group ${index + 1}: ${group.groupName} (${group.members.length} members)`);
    lines.push('');
    lines.push('| Parameter | Subfile | Col3 | Col4 | Col5 | Col7 | Col14 | Col15 | Col16 | Type |');
    lines.push('|-----------|---------|------|------|------|------|-------|-------|-------|------|');
    
    group.members.forEach((member: any) => {
      lines.push(`| ${member.name} | ${member.subfile} | ${member.column3} | ${member.column4} | ${member.column5} | ${member.column7} | ${member.column14} | ${member.column15} | ${member.column16 || ''} | ${member.type} |`);
    });
    
    lines.push('');
    lines.push('**Pattern Analysis:**');
    lines.push(`- Subfiles: ${group.patterns.subfiles.join(', ')}`);
    lines.push(`- Column 3: ${group.patterns.column3Values.join(', ')}`);
    lines.push(`- Column 4: ${group.patterns.column4Values.join(', ')}`);
    lines.push(`- Column 5: ${group.patterns.column5Values.join(', ')}`);
    lines.push(`- Column 7: ${group.patterns.column7Values.join(', ')}`);
    lines.push(`- Column 14: ${group.patterns.column14Values.join(', ')}`);
    lines.push(`- Column 15: ${group.patterns.column15Values.join(', ')}`);
    lines.push(`- Column 16: ${group.patterns.column16Values.filter(v => v).join(', ') || 'empty'}`);
    lines.push(`- Types: ${group.patterns.types.join(', ')}`);
    lines.push('');
    
    // Show raw e2m lines
    lines.push('**E2M Lines:**');
    lines.push('```');
    group.members.forEach((member: any) => {
      lines.push(member.rawLine);
    });
    lines.push('```');
    lines.push('');
    lines.push('---');
    lines.push('');
  });
  
  // Cross-group pattern analysis
  lines.push('## Cross-Group Pattern Analysis');
  lines.push('');
  lines.push('### Potential Grouping Columns');
  lines.push('');
  
  // Analyze which columns might define grouping
  const groupingHypotheses = [];
  
  // Check if members of each group share common values in unknown columns
  groupAnalysis.forEach(group => {
    const hypotheses = [];
    
    if (group.patterns.column7Values.length === 1) {
      hypotheses.push(`Column 7 = ${group.patterns.column7Values[0]}`);
    }
    if (group.patterns.column14Values.length === 1) {
      hypotheses.push(`Column 14 = ${group.patterns.column14Values[0]}`);
    }
    if (group.patterns.column15Values.length === 1) {
      hypotheses.push(`Column 15 = ${group.patterns.column15Values[0]}`);
    }
    if (group.patterns.subfiles.length === 1) {
      hypotheses.push(`Subfile = ${group.patterns.subfiles[0]}`);
    }
    
    groupingHypotheses.push({
      group: group.groupName,
      hypotheses
    });
  });
  
  groupingHypotheses.forEach(gh => {
    lines.push(`**${gh.group}**: ${gh.hypotheses.length > 0 ? gh.hypotheses.join(', ') : 'No single-value columns'}`);
  });
  
  lines.push('');
  lines.push('## Ungrouped Parameters Analysis');
  lines.push('');
  lines.push('These parameters appear as "Ungrouped" in Calterm:');
  lines.push('');
  lines.push('| Parameter | Subfile | Col3 | Col4 | Col5 | Col7 | Col14 | Col15 | Col16 | Type |');
  lines.push('|-----------|---------|------|------|------|------|-------|-------|-------|------|');
  
  ungroupedData.forEach(param => {
    lines.push(`| ${param.name} | ${param.subfile} | ${param.column3} | ${param.column4} | ${param.column5} | ${param.column7} | ${param.column14} | ${param.column15} | ${param.column16 || ''} | ${param.type} |`);
  });
  
  lines.push('');
  lines.push('**Ungrouped Pattern Analysis:**');
  const ungroupedPatterns = analyzeGroupPatterns(ungroupedData);
  lines.push(`- Subfiles: ${ungroupedPatterns.subfiles.join(', ')}`);
  lines.push(`- Column 7: ${ungroupedPatterns.column7Values.join(', ')}`);
  lines.push(`- Column 14: ${ungroupedPatterns.column14Values.join(', ')}`);
  lines.push(`- Column 15: ${ungroupedPatterns.column15Values.join(', ')}`);
  lines.push(`- Types: ${ungroupedPatterns.types.join(', ')}`);
  lines.push('');
  
  // Type G analysis
  lines.push('## Type G Parameters (Potential Group Headers)');
  lines.push('');
  lines.push(`Found ${typeGParams.length} parameters with Type G in e2m file:`);
  lines.push('');
  lines.push('| Parameter | Subfile | Col3 | Col4 | Col5 | Col7 | Col14 | Col15 | Col16 | Comment |');
  lines.push('|-----------|---------|------|------|------|------|-------|-------|-------|---------|');
  
  typeGParams.slice(0, 20).forEach(param => { // Show first 20
    const comment = param.comment.substring(0, 50);
    lines.push(`| ${param.fullName} | ${param.subfileNumber} | ${param.column3} | ${param.column4} | ${param.column5} | ${param.column7} | ${param.column14} | ${param.column15} | ${param.column16 || ''} | ${comment}... |`);
  });
  
  if (typeGParams.length > 20) {
    lines.push(`| ... | ... | ... | ... | ... | ... | ... | ... | ... | ${typeGParams.length - 20} more Type G parameters |`);
  }
  
  lines.push('');
  lines.push('## Key Observations');
  lines.push('');
  
  // Generate key observations
  const observations = [];
  
  // Check if any Type G parameters match Calterm group names
  const typeGNames = typeGParams.map(p => p.fullName);
  const caltermGroupNames = groupAnalysis.map(g => g.groupName);
  const matchingNames = typeGNames.filter(name => caltermGroupNames.includes(name));
  
  if (matchingNames.length > 0) {
    observations.push(`**Type G matches Calterm groups**: ${matchingNames.join(', ')}`);
  }
  
  // Check for patterns in unknown columns
  const allGroupMembers = groupAnalysis.flatMap(g => g.members);
  const globalPatterns = analyzeGroupPatterns(allGroupMembers);
  
  if (globalPatterns.column7Values.length <= 3) {
    observations.push(`**Column 7 has limited values**: ${globalPatterns.column7Values.join(', ')} - could be group identifiers`);
  }
  
  if (globalPatterns.column14Values.length <= 10) {
    observations.push(`**Column 14 has limited values**: ${globalPatterns.column14Values.join(', ')} - potential group IDs`);
  }
  
  observations.forEach(obs => lines.push(`- ${obs}`));
  
  lines.push('');
  lines.push('## Hypothesis for Group Membership');
  lines.push('');
  lines.push('Based on the analysis above, the most likely grouping mechanism is:');
  lines.push('');
  lines.push('1. **Type G parameters** define group headers/names');
  lines.push('2. **Unknown Column X** links members to their group');
  lines.push('3. **Ungrouped parameters** have a special value in the grouping column');
  lines.push('');
  lines.push('**Next steps to confirm:**');
  lines.push('1. Find Type G parameters that match Calterm group names');
  lines.push('2. Identify which unknown column consistently groups members');
  lines.push('3. Test hypothesis with additional Calterm group data');
  
  const output = lines.join('\n');
  writeFileSync(OUTPUT_FILE, output);
  console.log(`Groups analysis written to ${OUTPUT_FILE}`);
  console.log(`Analyzed ${groupAnalysis.length} Calterm groups and ${ungroupedData.length} ungrouped parameters`);
}

analyzeGroups();