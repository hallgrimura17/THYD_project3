Program Test7;
var
    b: Boolean;

function satt : Boolean;
begin
  Write( 'T' );
  satt := true;
end;

function osatt : Boolean;
begin
  Write( 'F' );
  osatt := false;
end;

begin
    b := False;
    WriteLn(b);
    b := True;
    WriteLn(b);
    WriteLn('');

    WriteLn('NOT');
    b := not b;
    WriteLn(b);
    WriteLn('');

    WriteLn('AND');
    b := osatt and osatt;
    WriteLn(''); WriteLn(b);
    b := osatt and satt;
    WriteLn(''); WriteLn(b);
    b := satt and osatt;
    WriteLn(''); WriteLn(b);
    b := satt and satt;
    WriteLn(''); WriteLn(b);
    WriteLn('');

    WriteLn('OR');
    b := osatt or osatt;
    WriteLn(''); WriteLn(b);
    b := osatt or satt;
    WriteLn(''); WriteLn(b);
    b := satt or osatt;
    WriteLn(''); WriteLn(b);
    b := satt or satt;
    WriteLn(''); WriteLn(b);
end.