.version 49 0
.class public super Test5
.super java/lang/Object
.method public <init> : ()V
.code stack 1 locals 1
	aload	0
	invokespecial	Method	java/lang/Object	<init>	()V
	return
.end code
.end method
.field static data [I
.field static i I
.field static max I
.method public static sort : (II)V
.code stack 10 locals 6
	iload	0
	istore	2
	iload	1
	istore	3
	getstatic	Field	Test5	data	[I
	iload	0
	iload	1
	iadd
	ldc	2
	idiv
	ldc	1
	isub
	iaload
	istore	4
L1:
	iload	2
	iload	3
	if_icmple	L3
	ldc	0
	goto	L4
L3:
	ldc	1
L4:
	ifeq	L2
L5:
	getstatic	Field	Test5	data	[I
	iload	2
	ldc	1
	isub
	iaload
	iload	4
	if_icmplt	L7
	ldc	0
	goto	L8
L7:
	ldc	1
L8:
	ifeq	L6
	iload	2
	ldc	1
	iadd
	istore	2
	goto	L5
L6:
L9:
	iload	4
	getstatic	Field	Test5	data	[I
	iload	3
	ldc	1
	isub
	iaload
	if_icmplt	L11
	ldc	0
	goto	L12
L11:
	ldc	1
L12:
	ifeq	L10
	iload	3
	ldc	1
	isub
	istore	3
	goto	L9
L10:
	iload	2
	iload	3
	if_icmple	L13
	ldc	0
	goto	L14
L13:
	ldc	1
L14:
	ifeq	L15
	getstatic	Field	Test5	data	[I
	iload	2
	ldc	1
	isub
	iaload
	istore	5
	getstatic	Field	Test5	data	[I
	iload	2
	ldc	1
	isub
	getstatic	Field	Test5	data	[I
	iload	3
	ldc	1
	isub
	iaload
	iastore
	getstatic	Field	Test5	data	[I
	iload	3
	ldc	1
	isub
	iload	5
	iastore
	iload	2
	ldc	1
	iadd
	istore	2
	iload	3
	ldc	1
	isub
	istore	3
L15:
	goto	L1
L2:
	iload	0
	iload	3
	if_icmplt	L16
	ldc	0
	goto	L17
L16:
	ldc	1
L17:
	ifeq	L18
	iload	0
	iload	3
	invokestatic	Method	Test5	sort	(II)V
L18:
	iload	2
	iload	1
	if_icmplt	L19
	ldc	0
	goto	L20
L19:
	ldc	1
L20:
	ifeq	L21
	iload	2
	iload	1
	invokestatic	Method	Test5	sort	(II)V
L21:
	return
.end code
.end method
.method public static display : (II)V
.code stack 10 locals 3
	ldc	1
	istore	2
L22:
	iload	2
	getstatic	Field	Test5	max	I
	if_icmple	L24
	ldc	0
	goto	L25
L24:
	ldc	1
L25:
	ifeq	L23
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	' '
	invokevirtual	Method	java/io/PrintStream	print	(Ljava/lang/String;)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test5	data	[I
	iload	2
	ldc	1
	isub
	iaload
	invokevirtual	Method	java/io/PrintStream	print	(I)V
	iload	2
	ldc	1
	iadd
	istore	2
	goto	L22
L23:
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	''
	invokevirtual	Method	java/io/PrintStream	println	(Ljava/lang/String;)V
	return
.end code
.end method
.method public static main : ([Ljava/lang/String;)V
.code stack 10 locals 1
	ldc	30
	putstatic	Field	Test5	max	I
	ldc	1
	putstatic	Field	Test5	i	I
L26:
	getstatic	Field	Test5	i	I
	getstatic	Field	Test5	max	I
	if_icmple	L28
	ldc	0
	goto	L29
L28:
	ldc	1
L29:
	ifeq	L27
	getstatic	Field	Test5	data	[I
	getstatic	Field	Test5	i	I
	ldc	1
	isub
	getstatic	Field	Test5	max	I
	getstatic	Field	Test5	i	I
	isub
	iastore
	getstatic	Field	Test5	i	I
	ldc	1
	iadd
	putstatic	Field	Test5	i	I
	goto	L26
L27:
	ldc	1
	getstatic	Field	Test5	max	I
	invokestatic	Method	Test5	display	(II)V
	ldc	1
	getstatic	Field	Test5	max	I
	invokestatic	Method	Test5	sort	(II)V
	ldc	1
	getstatic	Field	Test5	max	I
	invokestatic	Method	Test5	display	(II)V
	return
.end code
.end method
.method static <clinit> : ()V
.code stack 1 locals 1
	ldc	30
	newarray	int
	putstatic	Field	Test5	data	[I
	return
.end code
.end method
.sourcefile '?'
.end class
