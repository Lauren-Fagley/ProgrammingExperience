#Homework 2, Lauren Fagley

.data
msg:	.asciiz "Here, write what this program does. \n"

.extern foobar 4

.text

main: 
	li $v0, 4 #syscall 4 (print_str)
	la $a0, msg #argument: string
	syscall	#print the string
	lw $t1, foobar

	jr $ra #return to caller

	#li $v0, 10 #terminate program
	#syscall
	