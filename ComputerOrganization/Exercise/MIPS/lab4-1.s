# Lab 4 Homework1
# a Nonleaf Subroutine
# Author: ZHANG YUSHAN

	.data 
msg:	.asciiz "\nInput an integer:\n"
msg1: 	.asciiz "\nEnter One Integer: \n"
msg2:	.asciiz "\nThe Result is: "


	.text
main:  	or $t1, $t1, 0		#loop control
	addi $sp, $sp, -36
	j opt
	
opt:	la $a0,msg1	#enter first operands c
	li $v0,4
	syscall 
	li $v0, 5
	syscall
	move $t5, $v0
	sw $t5, 0($sp)
	la $a0, msg1	#enter second operands d
	li $v0,4
	syscall
	li $v0,5
	syscall
	move $t5, $v0
	sw $t5, 4($sp)
	j loop	#start enter array elements
	
loop:	beq $t1,8 , g	#loop starts
	add $sp, $sp, 4	
	la $a0, msg
	li $v0, 4
	syscall		
	li $v0, 5
	syscall		
	move $v0, $sp
	addi $t1, $t1, 1	#counter increment 1
	j loop
		
g:	addi $sp, $sp, -36
	lw $t0, 0($sp)
	lw $t1, 4($sp)
	lw $s0, 8($sp)	# first element in array	
	jal Fx		
	addi $sp, $sp, 8
	lw $s0, 12($sp)	# second element in array	
	jal Fx
	# jr $ra  (when this method is called)
	
	la $a0, msg2
	li $v0, 4
	syscall
	move $a0, $t4
	li $v0, 1
	syscall
	# Exit from this programm. 
	# If there is no calling method, we have to find ways.
	li $v0, 10
	syscall
			
Fx:	addi $sp, $sp, -8 	
	sw  $ra, 0($sp)
	sub $t2, $t0, $s0	# e = c - a
	sub $t3, $t1, $s0	# f = d - a
	add $t4, $t2, $t3	# r = e + f
	sw  $t4, 4($sp)		# store r
	lw  $ra, 0($sp)		# lw $ra and return
	jr  $ra	
