.version 49 0
.class public super Test6
.super java/lang/Object
.method public <init> : ()V
.code stack 1 locals 1
	aload	0
	invokespecial	Method	java/lang/Object	<init>	()V
	return
.end code
.end method
.field static a I
.field static b I
.method public static gcd : (II)I
.code stack 10 locals 3
	iload	0
	ldc	0
	if_icmpeq	L1
	ldc	0
	goto	L2
L1:
	ldc	1
L2:
	ifeq	L4
	iload	1
	istore	2
	goto	L3
L4:
	iload	1
	ldc	0
	if_icmpeq	L5
	ldc	0
	goto	L6
L5:
	ldc	1
L6:
	ifeq	L8
	iload	0
	istore	2
	goto	L7
L8:
	iload	0
	iload	1
	if_icmpeq	L9
	ldc	0
	goto	L10
L9:
	ldc	1
L10:
	ifeq	L12
	iload	0
	istore	2
	goto	L11
L12:
	iload	0
	iload	1
	if_icmpgt	L13
	ldc	0
	goto	L14
L13:
	ldc	1
L14:
	ifeq	L16
	iload	0
	iload	1
	isub
	iload	1
	invokestatic	Method	Test6	gcd	(II)I
	istore	2
	goto	L15
L16:
	iload	0
	iload	1
	iload	0
	isub
	invokestatic	Method	Test6	gcd	(II)I
	istore	2
L15:
L11:
L7:
L3:
	iload	2
	ireturn
.end code
.end method
.method public static main : ([Ljava/lang/String;)V
.code stack 10 locals 1
	ldc	98
	putstatic	Field	Test6	a	I
	ldc	56
	putstatic	Field	Test6	b	I
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	'GCD of '
	invokevirtual	Method	java/io/PrintStream	print	(Ljava/lang/String;)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test6	a	I
	invokevirtual	Method	java/io/PrintStream	print	(I)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	' and '
	invokevirtual	Method	java/io/PrintStream	print	(Ljava/lang/String;)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test6	b	I
	invokevirtual	Method	java/io/PrintStream	print	(I)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	' is '
	invokevirtual	Method	java/io/PrintStream	print	(Ljava/lang/String;)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test6	a	I
	getstatic	Field	Test6	b	I
	invokestatic	Method	Test6	gcd	(II)I
	invokevirtual	Method	java/io/PrintStream	println	(I)V
	return
.end code
.end method
.sourcefile '?'
.end class
