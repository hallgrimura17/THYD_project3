program pascal_triangle;

    function binomial_coeff( n, k: Integer ) : Integer;
    var
       i, res: Integer;
    begin
        res := 1;
        if k > n - k then
            k := n - k;
        i := 0;
        while i < k do
        begin
            res := res * (n - i);
            res := res div (i + 1);
            i := i + 1;
        end;
        binomial_coeff := res;
    end;

    procedure print_triangle( n: Integer );
    var
        line, i: Integer;
    begin
        line := 0;
        while line < n do
        begin
            i := 0;
            while i <= line do
            begin
                Write( binomial_coeff(line, i) );
                Write( ' ' );
                i := i + 1;
            end;
            WriteLn('');
            line := line + 1;
        end;
    end;

begin
    print_triangle( 7 );
end.