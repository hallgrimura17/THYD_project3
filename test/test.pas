Program Test;
var
    n: array [1 .. 5] of Integer;
    i,j: Integer;
begin
    n[1] := 10;
    i := n[1] + 1;
    WriteLn( n[1] );
    WriteLn( 20 );
    WriteLn( i );
    if false or false then
        WriteLn( 20 )
    else
        WriteLn( 10 );
end.