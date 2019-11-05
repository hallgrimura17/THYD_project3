.version 49 0
.class public super Test4
.super java/lang/Object
.method public <init> : ()V
.code stack 1 locals 1
	aload	0
	invokespecial	Method	java/lang/Object	<init>	()V
	return
.end code
.end method
.method public static binomial_coeff : (II)I
.code stack 10 locals 5
	ldc	1
	istore	4
	iload	1
	iload	0
	iload	1
	isub
	if_icmpgt	L1
	ldc	0
	goto	L2
L1:
	ldc	1
L2:
	ifeq	L3
	iload	0
	iload	1
	isub
	istore	1
L3:
	ldc	0
	istore	3
L4:
	iload	3
	iload	1
	if_icmplt	L6
	ldc	0
	goto	L7
L6:
	ldc	1
L7:
	ifeq	L5
	iload	4
	iload	0
	iload	3
	isub
	imul
	istore	4
	iload	4
	iload	3
	ldc	1
	iadd
	idiv
	istore	4
	iload	3
	ldc	1
	iadd
	istore	3
	goto	L4
L5:
	iload	4
	istore	2
	iload	2
	ireturn
.end code
.end method
.method public static print_triangle : (I)V
.code stack 10 locals 3
	ldc	0
	istore	1
L8:
	iload	1
	iload	0
	if_icmplt	L10
	ldc	0
	goto	L11
L10:
	ldc	1
L11:
	ifeq	L9
	ldc	0
	istore	2
L12:
	iload	2
	iload	1
	if_icmple	L14
	ldc	0
	goto	L15
L14:
	ldc	1
L15:
	ifeq	L13
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	iload	1
	iload	2
	invokestatic	Method	Test4	binomial_coeff	(II)I
	invokevirtual	Method	java/io/PrintStream	print	(I)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	' '
	invokevirtual	Method	java/io/PrintStream	print	(Ljava/lang/String;)V
	iload	2
	ldc	1
	iadd
	istore	2
	goto	L12
L13:
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	''
	invokevirtual	Method	java/io/PrintStream	println	(Ljava/lang/String;)V
	iload	1
	ldc	1
	iadd
	istore	1
	goto	L8
L9:
	return
.end code
.end method
.method public static main : ([Ljava/lang/String;)V
.code stack 10 locals 1
	ldc	7
	invokestatic	Method	Test4	print_triangle	(I)V
	return
.end code
.end method
.sourcefile '?'
.end class
