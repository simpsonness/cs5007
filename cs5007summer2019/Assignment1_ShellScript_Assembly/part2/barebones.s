# Build an executable using the following:
#
# clang barebones.s -o barebones  # clang is another compiler like gcc
#
.text
_barebones:

.data
	
.globl main

main:
					# (1) What are we setting up here?
					# Ans: we are setting up a stack structure
	pushq %rbp			#
	movq  %rsp, %rbp		#

					# (2) What is going on here
					# Ans: literal value 1 moved in rax and rdi
	movq $1, %rax			# 
	movq $1, %rdi			#
	leaq .hello.str,%rsi		#


					# (3) What is syscall? We did not talk about this
					# in class.
					# Ans: the program requests a service from the kerner of the OS it is operating on
	syscall				# Which syscall is being run?
					# Ans: sys_read

					# (4) What would another option be instead of 
					# using a syscall to achieve this?
					# Ans: sysenter

	movq	$60, %rax		# (5) We are again setting up another syscall
	movq	$0, %rdi		# What command is it?
					# Ans:sys_exit
	syscall

	popq %rbp			# (Note we do not really need
					# this command here after the syscall)

.hello.str:
	.string "Hello World!\n"
	.size	.hello.str,13		# (6) Why is there a 13 here?
					# Ans:	there are 13 characters need to be considered
