
# This progrm print my student ID to console.
# IDoutput.s
# Author: ZHANG YUSHAN

.data
msg:	.asciiz    "\n This is my student ID: \n"	#string1
id: 	.asciiz    "\n 11310380\n"	#string2

.text
main:	     	
		la     $a0, id 		#load address to $a0
		li     $v0, 4		#load operation number to $v0
		syscall				#call to print
		li 		$v0, 10		#load operation number to $v0
		syscall				#call to exit

