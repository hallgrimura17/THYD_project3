Program Test;
var
    n: Integer;
    a, b: Integer;
    r: Real;

    procedure Print;
    begin
        WriteLn('Hello world!')
    end;

begin
    Print;
    a := 1 + 2;
    WriteLn( a );
    b := 3 * a div 2;
    WriteLn( b );
    if a = b then
        a := -a
    else
        b := -a;
    WriteLn( a );
    WriteLn( b );
    r := a;
    n := 1;
    while n < 4 do
    begin
        WriteLn( n );
        r := (r + 1) / 3;
        b := b - 1;
        n := n + 1;
    end;
    WriteLn( r );
    WriteLn( b );
    WriteLn( n );
end.
