program Test5;
var
  data: array[1..30] of Integer;
  i: Integer;
  max: Integer;

procedure sort(l,r: integer);
var
  i,j,x,y: Integer;
begin
  i:=l; j:=r; x:=data[(l+r) div 2];
  while i<=j do
  begin
    while data[i]<x do i:=i+1;
    while x<data[j] do j:=j-1;
    if i<=j then
    begin
      y:=data[i]; data[i]:=data[j]; data[j]:=y;
      i:=i+1; j:=j-1;
    end;
  end;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;

procedure display(l,r: integer);
var
  i: Integer;
begin
  i := 1;
  while i <= max do
  begin
     Write( ' ' );
     Write( data[i] );
     i := i + 1;
  end;
  WriteLn('');
end;

begin {qsort}
  max := 30;
  i := 1;
  while i <= max do
  begin
     data[i] := max - i;
     i := i + 1;
  end;

  display(1,max);
  sort(1,max);
  display(1,max);
end.