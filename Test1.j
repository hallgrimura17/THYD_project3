.version 49 0
.class public super Test1
.super java/lang/Object
.method public <init> : ()V
.code stack 1 locals 1
	aload	0
	invokespecial	Method	java/lang/Object	<init>	()V
	return
.end code
.end method
.field static n I
.field static a I
.field static b I
.field static r F
.method public static Print : ()V
.code stack 10 locals 0
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	'Hello world!'
	invokevirtual	Method	java/io/PrintStream	println	(Ljava/lang/String;)V
	return
.end code
.end method
.method public static main : ([Ljava/lang/String;)V
.code stack 10 locals 1
	invokestatic	Method	Test1	Print	()V
	ldc	1
	ldc	2
	iadd
	putstatic	Field	Test1	a	I
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test1	a	I
	invokevirtual	Method	java/io/PrintStream	println	(I)V
	ldc	3
	getstatic	Field	Test1	a	I
	imul
	ldc	2
	idiv
	putstatic	Field	Test1	b	I
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test1	b	I
	invokevirtual	Method	java/io/PrintStream	println	(I)V
	getstatic	Field	Test1	a	I
	getstatic	Field	Test1	b	I
	if_icmpeq	L3
	ldc	0
	goto	L4
L3:
	ldc	1
L4:
	ifeq	L1
	getstatic	Field	Test1	a	I
	ineg
	putstatic	Field	Test1	a	I
	goto	L2
L1:
	getstatic	Field	Test1	a	I
	ineg
	putstatic	Field	Test1	b	I
L2:
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test1	a	I
	invokevirtual	Method	java/io/PrintStream	println	(I)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test1	b	I
	invokevirtual	Method	java/io/PrintStream	println	(I)V
	getstatic	Field	Test1	a	I
	i2f
	putstatic	Field	Test1	r	F
	ldc	1
	putstatic	Field	Test1	n	I
L5:
	getstatic	Field	Test1	n	I
	ldc	4
	if_icmplt	L7
	ldc	0
	goto	L8
L7:
	ldc	1
L8:
	ifeq	L6
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test1	n	I
	invokevirtual	Method	java/io/PrintStream	println	(I)V
	getstatic	Field	Test1	r	F
	ldc	1
	i2f
	fadd
	ldc	3
	i2f
	fdiv
	putstatic	Field	Test1	r	F
	getstatic	Field	Test1	b	I
	ldc	1
	isub
	putstatic	Field	Test1	b	I
	getstatic	Field	Test1	n	I
	ldc	1
	iadd
	putstatic	Field	Test1	n	I
	goto	L5
L6:
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test1	r	F
	invokevirtual	Method	java/io/PrintStream	println	(F)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test1	b	I
	invokevirtual	Method	java/io/PrintStream	println	(I)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test1	n	I
	invokevirtual	Method	java/io/PrintStream	println	(I)V
	return
.end code
.end method
.sourcefile '?'
.end class
