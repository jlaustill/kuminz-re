# Single pass: keep a stack of open-paren owners; attribute each "(word *)&" cast to the
# innermost enclosing call. A cast's own "(word *)" parens are skipped by matching it first.
local $/; my $s = <>;
my @stack; my %c; my %t; my $total = 0;
while ($s =~ /\G(?:(\(word \*\)&([A-Za-z_][A-Za-z0-9_]*))|([A-Za-z_][A-Za-z0-9_]*)\s*\(|(\()|(\))|[^()A-Za-z_]+|[A-Za-z_][A-Za-z0-9_]*)/gc) {
  if (defined $1) { $total++; my $owner = 'NONE'; for (my $i=$#stack;$i>=0;$i--){ if ($stack[$i] ne '('){ $owner=$stack[$i]; last } } $c{$owner}++; $t{$owner}{$2}=1; }
  elsif (defined $3) { my $f=$3; push @stack, ($f =~ /^(if|while|for|switch|return)$/ ? '(' : $f); }
  elsif (defined $4) { push @stack, '('; }
  elsif (defined $5) { pop @stack; }
}
print "total casts: $total\n";
my $i=0; for (sort { $c{$b} <=> $c{$a} } keys %c) { printf "%5d casts  %4d distinct globals  %s\n", $c{$_}, scalar(keys %{$t{$_}}), $_; last if ++$i >= 14 }
