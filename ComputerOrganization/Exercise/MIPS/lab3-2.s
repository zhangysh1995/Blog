# Lab3 Homework2
# lab3-2.s
# Author: ZHANG YUSHAN
	.data
	
array:	.space	32
msg:	.asciiz "\nInput an integer:\n"
msg1:	.asciiz "\nSum of negative: "
msg2:	.asciiz "\nSum of positive: "

	.text
main:	la $t0,array
	move $t6, $zero
	move $t2, $zero    	#loop control
	addi $t2, $t2, 7
loop1:	slt  $t6, $t2, $zero	#loop starts
	bgtz $t6, exit1
	la $a0,msg
	li $v0,4
	syscall			#print msg
	li $v0, 5
	syscall			#read integer
	move $t1, $v0
	sw $t1, 0($t0)		#store integer
	addi $t0, $t0, 4	#address increment 4	
	addi $t2, $t2, -1	#counter increment 1
	j loop1
exit1:	move $t2, $zero		# initialize again
	addi $t2, $t2, 7
        or $s0, $s0, $zero
	or $s1, $s1, $zero
	la $t0, array		#read base address
	
loop2:  	slt $t6, $t2,$zero	#control
		bgtz $t6, exit
		lw  $t4, 0($t0)
		#test
		#move $a0, $t4
		#li $v0,1
		#syscall
				
		slt $t5, $zero, $t4		# >0
		bgtz $t5, addPositive
		add $s1, $s1, $t4		#add negative
		
		addi $t0, $t0, 4
		addi $t2, $t2, -1		#counter decrement 1
		j loop2
		
addPositive:	add $s0, $s0, $t4		#add negetive
		addi $t0, $t0, 4
		addi $t2, $t2, -1		#counter decrement 1
		j loop2
		
exit:		la $a0, msg2
		li $v0, 4
		syscall
		move $a0, $s0			
		li $v0, 1
		syscall			#print sum of positve
		la $a0, msg1
		li $v0, 4
		syscall
		move $a0, $s1
		li $v0, 1
		syscall			#print sum of negative
		li $v0, 10
		syscall
# If you want to print ordered numbers first, just branchs the code when deciding negetive or positive. Therefore 
# the code would be longer and more difficult to read.