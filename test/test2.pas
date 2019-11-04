Program Test;
var
    n: Integer;
    r: Real;
    b: Boolean;
    an: array [ 1 .. 5 ] of Integer;
    ar: array [ 1 .. 5 ] of Real;
    ab: array [ 1 .. 5 ] of Boolean;

    procedure Display( n: Integer; r: Real; b: Boolean; ni: Integer; ri: Real; bi: Boolean );
    begin
        Write( n );
        Write( ' ' );
        Write( r );
        Write( ' ' );
        Write( b );
        Write( ' ' );
        Write( ni );
        Write( ' ' );
        Write( ri );
        Write( ' ' );
        WriteLn( bi );
    end;

    procedure Foo;
    var
        n: Integer;
        r: Real;
        b: Boolean;
        an: array [ 1 .. 5 ] of Integer;
        ar: array [ 1 .. 5 ] of Real;
        ab: array [ 1 .. 5 ] of Boolean;
    begin
        n := 1;
        r := 2.3;
        b := True;
        while n <= 5 do
        begin
            an[n] := n;
            ar[n] := an[n];
            b := not b;
            ab[n] := b;
            Display( n, r, b, an[n], ar[n], ab[n] );
            n := n + 1
        end;
    end;

    function Factorial( n: Integer ) : Integer;
    begin
        if n <= 1 then
            Factorial := 1
        else
            Factorial := n * Factorial( n - 1 );
    end;

begin
    n := 1;
    r := 2.3;
    b := True;
    while n <= 5 do
    begin
        an[n] := n;
        ar[n] := an[n];
        b := not b;
        ab[n] := b;
        Display( n, r, b, an[n], ar[n], ab[n] );
        n := n + 1
    end;
    Foo;
    WriteLn( Factorial( 4 ) );
end.
