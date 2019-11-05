.version 49 0
.class public super Test
.super java/lang/Object
.method public <init> : ()V
.code stack 1 locals 1
	aload	0
	invokespecial	Method	java/lang/Object	<init>	()V
	return
.end code
.end method
.field static n [I
.field static i I
.field static j I
.method public static main : ([Ljava/lang/String;)V
.code stack 10 locals 1
	getstatic	Field	Test	n	[I
	ldc	1
	ldc	1
	isub
	ldc	10
	iastore
	getstatic	Field	Test	n	[I
	ldc	1
	ldc	1
	isub
	iaload
	ldc	1
	iadd
	putstatic	Field	Test	i	I
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test	n	[I
	ldc	1
	ldc	1
	isub
	iaload
	invokevirtual	Method	java/io/PrintStream	println	(I)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	20
	invokevirtual	Method	java/io/PrintStream	println	(I)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test	i	I
	invokevirtual	Method	java/io/PrintStream	println	(I)V
	ldc	0
	ifne	L3
	ldc	0
	goto	L4
L3:
	ldc	1
L4:
	ifeq	L1
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	20
	invokevirtual	Method	java/io/PrintStream	println	(I)V
	goto	L2
L1:
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	10
	invokevirtual	Method	java/io/PrintStream	println	(I)V
L2:
	return
.end code
.end method
.method static <clinit> : ()V
.code stack 1 locals 1
	ldc	5
	newarray	int
	putstatic	Field	Test	n	[I
	return
.end code
.end method
.sourcefile '?'
.end class
