	.text
.globl zfunction
zfunction:
	pushl %ebp
	movl %esp, %ebp
	movl 8(%ebp), %eax
	andl $0xff803fff, %eax
	sall $4, %eax
	leave
	ret

