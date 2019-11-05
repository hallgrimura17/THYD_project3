program Test3;

  var n: integer;

  procedure fib (a, b, i, n: integer);
  begin
    if i < n then
    begin
      writeln(a + b);
      fib (a + b, a, i + 1, n)
    end;
  end;

begin
  n := 10;
  fib (0, 1, 0, n)
end.