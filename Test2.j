.version 49 0
.class public super Test2
.super java/lang/Object
.method public <init> : ()V
.code stack 1 locals 1
	aload	0
	invokespecial	Method	java/lang/Object	<init>	()V
	return
.end code
.end method
.field static n I
.field static r F
.field static b Z
.field static an [I
.field static ar [F
.field static ab [Z
.method public static Display : (IFZIFZ)V
.code stack 10 locals 6
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	iload	0
	invokevirtual	Method	java/io/PrintStream	print	(I)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	' '
	invokevirtual	Method	java/io/PrintStream	print	(Ljava/lang/String;)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	fload	1
	invokevirtual	Method	java/io/PrintStream	print	(F)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	' '
	invokevirtual	Method	java/io/PrintStream	print	(Ljava/lang/String;)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	iload	2
	invokevirtual	Method	java/io/PrintStream	print	(Z)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	' '
	invokevirtual	Method	java/io/PrintStream	print	(Ljava/lang/String;)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	iload	3
	invokevirtual	Method	java/io/PrintStream	print	(I)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	' '
	invokevirtual	Method	java/io/PrintStream	print	(Ljava/lang/String;)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	fload	4
	invokevirtual	Method	java/io/PrintStream	print	(F)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	' '
	invokevirtual	Method	java/io/PrintStream	print	(Ljava/lang/String;)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	iload	5
	invokevirtual	Method	java/io/PrintStream	println	(Z)V
	return
.end code
.end method
.method public static Foo : ()V
.code stack 10 locals 6
	ldc	5
	newarray	int
	astore	3
	ldc	5
	newarray	float
	astore	4
	ldc	5
	newarray	boolean
	astore	5
	ldc	1
	istore	0
	ldc	2.300000f
	fstore	1
	ldc	1
	istore	2
L1:
	iload	0
	ldc	5
	if_icmple	L3
	ldc	0
	goto	L4
L3:
	ldc	1
L4:
	ifeq	L2
	aload	3
	iload	0
	ldc	1
	isub
	iload	0
	iastore
	aload	4
	iload	0
	ldc	1
	isub
	aload	3
	iload	0
	ldc	1
	isub
	iaload
	i2f
	fastore
	iload	2
	ifeq	L5
	ldc	0
	goto	L6
L5:
	ldc	1
L6:
	istore	2
	aload	5
	iload	0
	ldc	1
	isub
	iload	2
	bastore
	iload	0
	fload	1
	iload	2
	aload	3
	iload	0
	ldc	1
	isub
	iaload
	aload	4
	iload	0
	ldc	1
	isub
	faload
	aload	5
	iload	0
	ldc	1
	isub
	baload
	invokestatic	Method	Test2	Display	(IFZIFZ)V
	iload	0
	ldc	1
	iadd
	istore	0
	goto	L1
L2:
	return
.end code
.end method
.method public static Factorial : (I)I
.code stack 10 locals 2
	iload	0
	ldc	1
	if_icmple	L9
	ldc	0
	goto	L10
L9:
	ldc	1
L10:
	ifeq	L7
	ldc	1
	istore	1
	goto	L8
L7:
	iload	0
	iload	0
	ldc	1
	isub
	invokestatic	Method	Test2	Factorial	(I)I
	imul
	istore	1
L8:
	iload	1
	ireturn
.end code
.end method
.method public static main : ([Ljava/lang/String;)V
.code stack 10 locals 1
	ldc	1
	putstatic	Field	Test2	n	I
	ldc	2.300000f
	putstatic	Field	Test2	r	F
	ldc	1
	putstatic	Field	Test2	b	Z
L11:
	getstatic	Field	Test2	n	I
	ldc	5
	if_icmple	L13
	ldc	0
	goto	L14
L13:
	ldc	1
L14:
	ifeq	L12
	getstatic	Field	Test2	an	[I
	getstatic	Field	Test2	n	I
	ldc	1
	isub
	getstatic	Field	Test2	n	I
	iastore
	getstatic	Field	Test2	ar	[F
	getstatic	Field	Test2	n	I
	ldc	1
	isub
	getstatic	Field	Test2	an	[I
	getstatic	Field	Test2	n	I
	ldc	1
	isub
	iaload
	i2f
	fastore
	getstatic	Field	Test2	b	Z
	ifeq	L15
	ldc	0
	goto	L16
L15:
	ldc	1
L16:
	putstatic	Field	Test2	b	Z
	getstatic	Field	Test2	ab	[Z
	getstatic	Field	Test2	n	I
	ldc	1
	isub
	getstatic	Field	Test2	b	Z
	bastore
	getstatic	Field	Test2	n	I
	getstatic	Field	Test2	r	F
	getstatic	Field	Test2	b	Z
	getstatic	Field	Test2	an	[I
	getstatic	Field	Test2	n	I
	ldc	1
	isub
	iaload
	getstatic	Field	Test2	ar	[F
	getstatic	Field	Test2	n	I
	ldc	1
	isub
	faload
	getstatic	Field	Test2	ab	[Z
	getstatic	Field	Test2	n	I
	ldc	1
	isub
	baload
	invokestatic	Method	Test2	Display	(IFZIFZ)V
	getstatic	Field	Test2	n	I
	ldc	1
	iadd
	putstatic	Field	Test2	n	I
	goto	L11
L12:
	invokestatic	Method	Test2	Foo	()V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	4
	invokestatic	Method	Test2	Factorial	(I)I
	invokevirtual	Method	java/io/PrintStream	println	(I)V
	return
.end code
.end method
.method static <clinit> : ()V
.code stack 1 locals 1
	ldc	5
	newarray	int
	putstatic	Field	Test2	an	[I
	ldc	5
	newarray	float
	putstatic	Field	Test2	ar	[F
	ldc	5
	newarray	boolean
	putstatic	Field	Test2	ab	[Z
	return
.end code
.end method
.sourcefile '?'
.end class
