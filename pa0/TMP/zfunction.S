	.text
.globl zfunction
zfunction:
	pushl %ebp
	movl %esp, %ebp
	movl 8(%ebp), %eax
	andl $0xff803fff, %eax
	shll $4, %eax
	leave
	ret

