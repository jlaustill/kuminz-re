// find the RC (PGN 65249) SPNs by name
const seen = {};
db.pgns.find({ 'spns.name': { $regex: 'Retarder (Type|Location|Control Method|Speed|Reference|Configuration)|Percent Torque at|Torque at (Idle|Maximum|Point)|Reference Retarder|Maximum Retarder|Retarder Torque', $options: 'i' } }, { spns: 1, number: 1, acronym: 1 }).forEach(function (doc) {
  doc.spns.forEach(function (s) {
    if (/Retarder (Type|Location|Control Method|Speed|Reference)|Percent Torque at|Reference Retarder|Maximum Retarder|Retarder Torque|Torque at/i.test(s.name) && !seen[s.number]) {
      seen[s.number] = 1;
      print('SPN ' + s.number + ' ' + s.name + ' | ' + s.resolution + ' | in PGN ' + JSON.stringify(s.pgn_references) + ' | ' + (s.description || '').substring(0, 260).replace(/\n/g, ' '));
    }
  });
});
db.pgns.find({ number: 65249 }).forEach(function (doc) {
  print('RC spns: ' + doc.spns.map(function (s) { return s.number + ':' + s.name; }).join(' ; '));
  print('RC desc: ' + (doc.description || '').substring(0, 800));
});
