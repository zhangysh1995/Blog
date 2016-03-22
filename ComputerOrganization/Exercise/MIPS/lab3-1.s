# Lab 3 Homework1
# lab3_1.s
# Author: ZHANG YUSHAN

.data
var1:	.word	0
var2:	.word 	8
var3:	.word 	5

.text
main:	lw $t1, var1
		lw $t2, var2
		lw $t3, var3
		addi $t0, $t0, -5
		beq $t1,$t2,else
		move $t1,$t3
		move $t2,$t3
else:	move $t0,$t1
		move $t1,$t2
		move $t2,$t0
		li $v0, 10
		syscall
