.version 49 0
.class public super Test3
.super java/lang/Object
.method public <init> : ()V
.code stack 1 locals 1
	aload	0
	invokespecial	Method	java/lang/Object	<init>	()V
	return
.end code
.end method
.field static n I
.method public static fib : (IIII)V
.code stack 10 locals 4
	iload	2
	iload	3
	if_icmplt	L1
	ldc	0
	goto	L2
L1:
	ldc	1
L2:
	ifeq	L3
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	iload	0
	iload	1
	iadd
	invokevirtual	Method	java/io/PrintStream	println	(I)V
	iload	0
	iload	1
	iadd
	iload	0
	iload	2
	ldc	1
	iadd
	iload	3
	invokestatic	Method	Test3	fib	(IIII)V
L3:
	return
.end code
.end method
.method public static main : ([Ljava/lang/String;)V
.code stack 10 locals 1
	ldc	10
	putstatic	Field	Test3	n	I
	ldc	0
	ldc	1
	ldc	0
	getstatic	Field	Test3	n	I
	invokestatic	Method	Test3	fib	(IIII)V
	return
.end code
.end method
.sourcefile '?'
.end class
