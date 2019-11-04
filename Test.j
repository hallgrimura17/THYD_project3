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
.field static n I
.field static i I
.field static j I
.method public static main : ([Ljava/lang/String;)V
.code stack 10 locals 1
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	getstatic	Field	Test	n	I
	invokevirtual	Method	java/io/PrintStream	println	(I)V
	getstatic	Field	java/lang/System	out	Ljava/io/PrintStream;
	ldc	20
	invokevirtual	Method	java/io/PrintStream	println	(I)V
	return
.end code
.end method
.sourcefile '?'
.end class
