.version 49 0
.class public super Test7
.super java/lang/Object
.method public <init> : ()V
.code stack 1 locals 1
	aload	0
	invokespecial	Method	java/lang/Object	<init>	()V
	return
.end code
.end method
.field static b Z
.method public static satt : ()Z
.code stack 10 locals 1
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	'T'
	invokevirtual	Method	java/io/PrintStream	print	(Ljava/lang/String;)V
	ldc	1
	istore	0
	iload	0
	ireturn
.end code
.end method
.method public static osatt : ()Z
.code stack 10 locals 1
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	'F'
	invokevirtual	Method	java/io/PrintStream	print	(Ljava/lang/String;)V
	ldc	0
	istore	0
	iload	0
	ireturn
.end code
.end method
.method public static main : ([Ljava/lang/String;)V
.code stack 10 locals 1
	ldc	0
	putstatic	Field	Test7	b	Z
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test7	b	Z
	invokevirtual	Method	java/io/PrintStream	println	(Z)V
	ldc	1
	putstatic	Field	Test7	b	Z
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test7	b	Z
	invokevirtual	Method	java/io/PrintStream	println	(Z)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	''
	invokevirtual	Method	java/io/PrintStream	println	(Ljava/lang/String;)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	'NOT'
	invokevirtual	Method	java/io/PrintStream	println	(Ljava/lang/String;)V
	getstatic	Field	Test7	b	Z
	ifeq	L1
	ldc	0
	goto	L2
L1:
	ldc	1
L2:
	putstatic	Field	Test7	b	Z
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test7	b	Z
	invokevirtual	Method	java/io/PrintStream	println	(Z)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	''
	invokevirtual	Method	java/io/PrintStream	println	(Ljava/lang/String;)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	'AND'
	invokevirtual	Method	java/io/PrintStream	println	(Ljava/lang/String;)V
	invokestatic	Method	Test7	osatt	()Z
	ifeq	L3
	invokestatic	Method	Test7	osatt	()Z
	goto	L4
L3:
	ldc	0
L4:
	putstatic	Field	Test7	b	Z
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	''
	invokevirtual	Method	java/io/PrintStream	println	(Ljava/lang/String;)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test7	b	Z
	invokevirtual	Method	java/io/PrintStream	println	(Z)V
	invokestatic	Method	Test7	osatt	()Z
	ifeq	L5
	invokestatic	Method	Test7	satt	()Z
	goto	L6
L5:
	ldc	0
L6:
	putstatic	Field	Test7	b	Z
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	''
	invokevirtual	Method	java/io/PrintStream	println	(Ljava/lang/String;)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test7	b	Z
	invokevirtual	Method	java/io/PrintStream	println	(Z)V
	invokestatic	Method	Test7	satt	()Z
	ifeq	L7
	invokestatic	Method	Test7	osatt	()Z
	goto	L8
L7:
	ldc	0
L8:
	putstatic	Field	Test7	b	Z
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	''
	invokevirtual	Method	java/io/PrintStream	println	(Ljava/lang/String;)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test7	b	Z
	invokevirtual	Method	java/io/PrintStream	println	(Z)V
	invokestatic	Method	Test7	satt	()Z
	ifeq	L9
	invokestatic	Method	Test7	satt	()Z
	goto	L10
L9:
	ldc	0
L10:
	putstatic	Field	Test7	b	Z
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	''
	invokevirtual	Method	java/io/PrintStream	println	(Ljava/lang/String;)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test7	b	Z
	invokevirtual	Method	java/io/PrintStream	println	(Z)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	''
	invokevirtual	Method	java/io/PrintStream	println	(Ljava/lang/String;)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	'OR'
	invokevirtual	Method	java/io/PrintStream	println	(Ljava/lang/String;)V
	invokestatic	Method	Test7	osatt	()Z
	ifne	L11
	invokestatic	Method	Test7	osatt	()Z
	goto	L12
L11:
	ldc	1
L12:
	putstatic	Field	Test7	b	Z
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	''
	invokevirtual	Method	java/io/PrintStream	println	(Ljava/lang/String;)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test7	b	Z
	invokevirtual	Method	java/io/PrintStream	println	(Z)V
	invokestatic	Method	Test7	osatt	()Z
	ifne	L13
	invokestatic	Method	Test7	satt	()Z
	goto	L14
L13:
	ldc	1
L14:
	putstatic	Field	Test7	b	Z
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	''
	invokevirtual	Method	java/io/PrintStream	println	(Ljava/lang/String;)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test7	b	Z
	invokevirtual	Method	java/io/PrintStream	println	(Z)V
	invokestatic	Method	Test7	satt	()Z
	ifne	L15
	invokestatic	Method	Test7	osatt	()Z
	goto	L16
L15:
	ldc	1
L16:
	putstatic	Field	Test7	b	Z
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	''
	invokevirtual	Method	java/io/PrintStream	println	(Ljava/lang/String;)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test7	b	Z
	invokevirtual	Method	java/io/PrintStream	println	(Z)V
	invokestatic	Method	Test7	satt	()Z
	ifne	L17
	invokestatic	Method	Test7	satt	()Z
	goto	L18
L17:
	ldc	1
L18:
	putstatic	Field	Test7	b	Z
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	''
	invokevirtual	Method	java/io/PrintStream	println	(Ljava/lang/String;)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test7	b	Z
	invokevirtual	Method	java/io/PrintStream	println	(Z)V
	return
.end code
.end method
.sourcefile '?'
.end class
