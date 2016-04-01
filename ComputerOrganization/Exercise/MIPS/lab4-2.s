#lab 4 Homework 2
# lab4-2.s
# Author: ZHANG YUSHAN

	.data
msg: .asciiz "\nEnter positive integer y: \n"
msg1: .asciiz "\nEnter positive integer x: \n"

	.text 
main:	la $a0, msg
	li $v0, 4
	syscall
	li $v0,5	#read y
	syscall
	move $a1,$v0
	la $a0, msg1
	li $v0, 4
	syscall
	li $v0,5	#read x
	syscall
	move $a0,$v0
	slt $t0, $a1, $zero
	bne $t0, $zero, main	# if y <0, branch
	move $a0,$v0
	slt $t0, $a0, $zero	
	bne $t0, $zero, main	# if x<0, branch
	
call:	jal A	#call method Ackermann's funtion
	
	move $a0, $a0	# print x
	li $v0, 1
	syscall
	
	move $a0,$a1	# print y (return result of Ackermann's call)
	li $v0, 1
	syscall
		
	li $v0, 10	# exit
	syscall
	
A:	subi $sp, $sp, 12	#new stack frame
	sw $ra, 0($sp)
	sw $a0, 4($sp)
	sw $a1, 8($sp)
	bne $a0, $zero, y	# when x!=0 branch
	addi $a1, $a1, 1
	lw $ra, 0($sp)
	jr $ra
	
y:	subi $sp, $sp, 12	#new stack frame
	sw $ra, 0($sp)
	sw $a0, 4($sp)
	sw $ra, 8($sp)
	bne $a1, $zero, other	# when y!= 0 branch
	subi $a0, $a0, 1
	ori $a1, 1
	jal A
	addi $sp, $sp, 12
	lw $ra, 0($sp)
	jr $ra
	
other:	sub $sp, $sp, 12	#new stack frame
	sw $ra, 0($sp)
	sw $a0, 4($sp)
	sw $ra, 8($sp)
	subi $a1, $a1, 1
	jal A	# Recurse to calculte y
	addi $sp, $sp,12
	lw $a0, 4($sp)	# load x 
	sub $a0, $a0, 1
	jal A	# Revcurse call
	
