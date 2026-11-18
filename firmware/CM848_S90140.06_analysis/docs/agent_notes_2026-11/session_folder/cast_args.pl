local $/; my $s = <>;
my @stack; my %c; my %g;
while ($s =~ /\G(?:(\(word \*\)&([A-Za-z_][A-Za-z0-9_]*))|([A-Za-z_][A-Za-z0-9_]*)\s*\(|(\()|(\))|(,)|[^(),A-Za-z_]+|[A-Za-z_][A-Za-z0-9_]*)/gc) {
  if (defined $1) { for (my $i=$#stack;$i>=0;$i--){ if ($stack[$i][0] ne '('){ my $k="$stack[$i][0] arg$stack[$i][1]"; $c{$k}++; $g{$k}{$2}=1; last } } }
  elsif (defined $3) { push @stack, [($3 =~ /^(if|while|for|switch|return)$/ ? '(' : $3), 0]; }
  elsif (defined $4) { push @stack, ['(', 0]; }
  elsif (defined $5) { pop @stack; }
  elsif (defined $6) { $stack[-1][1]++ if @stack; }
}
for (sort { $c{$b} <=> $c{$a} } keys %c) { printf "%5d casts %4d globals  %s\n", $c{$_}, scalar(keys %{$g{$_}}), $_ }
