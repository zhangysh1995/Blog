
# This programs calculates f=(a+b)+(c-d)
# Calculation.s
# Author: ZHANG YUSHAN

	.data
# initialize strings
msg1:	.asciiz	"\nInput first integer: \n" 
msg2:	.asciiz	"\nInput second integer: \n"
msg3:	.asciiz	"\nInput third integer: \n"
msg4:	.asciiz	"\nInput fourth integer: \n"
msg5:	.asciiz "\n The result of f=(a+b)+(c-d) is: f = "

	.text
main:
   #read first integer
	la $a0, msg1
	li $v0, 4
	syscall
	li $v0, 5
	syscall 
	move $s0, $v0
   #read second integer
	la $a0, msg2
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	move $s1, $v0
   #read third integer
	la $a0, msg3
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	move $s2, $v0
   #read fourth integer
	la $a0, msg4
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	move $s3, $v0
   #print string
	la $a0, msg5
	li $v0, 4
	syscall
   #calculation
	add $t0, $s0, $s1
	sub $t1, $s2, $s3
	add $t2, $t0, $t1
   #print result
	move $a0, $t2
	li $v0, 1
	syscall
   #exit
	li $v0, 10
	syscall
