// compact J1939 lookups for the retarder leads
function show(pgnNumber, standard) {
  const filter = { number: pgnNumber };
  if (standard) filter.standards = standard;
  db.pgns.find(filter).forEach(function (doc) {
    print('PGN ' + doc.number + ' ' + doc.acronym + ' ' + doc.name + ' len=' + doc.data_length + ' rate=' + doc.transmission_rate + ' std=' + JSON.stringify(doc.standards));
    (doc.parameters || []).forEach(function (p) {
      print('   pos ' + p.start_position + ' len ' + p.length + ' SPN ' + p.spn_number + ' ' + p.name);
    });
  });
}
function spn(number) {
  const seen = {};
  db.pgns.find({ 'spns.number': number }, { spns: 1, number: 1, standards: 1 }).forEach(function (doc) {
    doc.spns.forEach(function (s) {
      if (s.number === number && !seen[s.name]) {
        seen[s.name] = 1;
        print('SPN ' + s.number + ' ' + s.name + ' | res ' + s.resolution + ' | off ' + s.offset + ' | ' + (s.description || '').substring(0, 700).replace(/\n/g, ' '));
      }
    });
  });
}
show(65249, 'J1939-71');
[901, 902, 903, 900, 973, 695, 897, 696, 518, 574, 573].forEach(spn);
show(61440, 'J1939-71');
show(0, 'J1939-71');
