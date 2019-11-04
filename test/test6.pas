program findgcd;
  var
    a, b: Integer;

  function gcd( a,b: Integer ) : Integer;
  begin
    if a = 0 then
       gcd := b
    else if b = 0 then
       gcd := a
    else if a = b then
       gcd := a
    else if a > b then
       gcd := gcd(a-b, b)
    else
       gcd := gcd(a, b-a);
  end;

begin
    a := 98;
    b := 56;
    Write('GCD of '); Write(a); Write(' and '); Write(b); Write(' is '); WriteLn(gcd(a, b));
end.
