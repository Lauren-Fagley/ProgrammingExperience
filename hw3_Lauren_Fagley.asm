#Homework 3, Lauren Fagley

.data
	list: 
	.word 5
	.word 2
	.word 15
	.word 3
	.word 7
	.word 15
	.word 8
	.word 9
	.word 5
	.word 2
	.word 15
	.word 3
	.word 7
	size: .word 13
	space: .asciiz " "
	newline: .asciiz "\n"
	greaterMsg: .asciiz "bigger.. \n"
	sameMsg: .asciiz "same.. \n"
	lessMsg: .asciiz "smaller.. \n"
	greatestMsg: .asciiz "The largest number is "
	countMsg: .asciiz "The largest number is included "
	periodNewline: .asciiz ". \n"
	times: .asciiz " times. \n"

.text
.globl main

main:
	lw $t3, size #array size
	la $t1, list #array address
	li $t2, 0 #loop counter
print_loop:
	beq $t2, $t3, print_loop_end #check if loop counter = array
		
	lw $a0, 0($t1) #print value at array pointer
	li $v0, 1 #syscall code for print integer
	syscall
	
	li $v0, 4 #syscall code for print string
	la $a0, space #load space character into $a0
	syscall
	
	addi $t2, $t2, 1 #advance loop counter
	addi $t1, $t1, 4 #advance array pointer
	j print_loop #repeat

print_loop_end:
	la $a0, newline #print new line
	syscall

	la $t1, list #reintializing array address for next loop
	li $t2, 0 #reintializing loop counter for next loop
	li $a1, 5 #making the first element of the array default greatest variable

compare_loop:
	beq $t2, $t3, compare_loop_end #check if loop counter = array
	
	lw $a2, 0($t1) #getting value at array pointer
	jal compare #calling compare function
	
	addi $t2, $t2, 1 #advance loop counter
	addi $t1, $t1, 4 #advance array pointer
	
	li $t0, 0
	beq $v1, $t0, greater #testing if return value is 0
	li $t0, 1
	beq $v1, $t0, same #testing if return value is 1
	li $t0, 2
	beq $v1, $t0, less #testing if return value is 2

	greater:
		li $v0, 4 #syscall code for print string
		la $a0, greaterMsg #print greater msg
		syscall
		
		move $a1, $a2 #stores largest varaible
		addi $t4, $zero, 1 #count=1
		j compare_loop
	same:
		li $v0, 4 #syscall code for print string
		la $a0, sameMsg #print same msg
		syscall

		addi $t4, $t4, 1 #count++
		j compare_loop
	less:
		li $v0, 4 #syscall code for print string
		la $a0, lessMsg #print less msg
		syscall
		j compare_loop

	
	
compare:
	sub $v0, $a1, $a2 #subtract greatest value from current 
	#[I tried so hard to make this a function and it would not work and just broke my whole code and i didn't know what to do :( ]
	
	bgtz $v0, return_2 #if $v0 > 0 return 2
	beq $a1, $a2, return_1 #if $a1 = $a2 return 1
	j return_0 #else return 0
	
	return_2:
	addi $v1, $zero, 2
	jr $ra

	return_1:
	addi $v1, $zero, 1
	jr $ra
	
	return_0:
	addi $v1, $zero, 0
	jr $ra


compare_loop_end:
	li $v0, 4 #syscall code for print string
	la $a0, greatestMsg #print greatest msg
	syscall

	move $a0, $a1 #print value at array pointer
	li $v0, 1 #print greatest value
	syscall

	li $v0, 4 #syscall code for print string
	la $a0, periodNewline #print period and newline
	syscall

	li $v0, 4 #syscall code for print string
	la $a0, countMsg #print count msg
	syscall

	move $a0, $t4 #print value at array pointer
	li $v0, 1 #print count
	syscall
	
	li $v0, 4 #syscall code for print string
	la $a0, times #print end of count msg
	syscall

	li $v0, 10 #syscall code for exit
	syscall	
