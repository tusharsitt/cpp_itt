	.file	"switchImp.cpp"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$34, -4(%rbp)
	cmpl	$23432424, -4(%rbp)
	je	.L11
	cmpl	$23432424, -4(%rbp)
	jg	.L12
	cmpl	$23424, -4(%rbp)
	je	.L13
	cmpl	$23424, -4(%rbp)
	jg	.L12
	cmpl	$424, -4(%rbp)
	je	.L14
	cmpl	$424, -4(%rbp)
	jg	.L12
	cmpl	$4, -4(%rbp)
	je	.L15
	cmpl	$4, -4(%rbp)
	jg	.L12
	cmpl	$-23424, -4(%rbp)
	je	.L16
	cmpl	$0, -4(%rbp)
	je	.L17
	jmp	.L12
.L11:
	nop
	jmp	.L9
.L12:
	nop
	jmp	.L9
.L13:
	nop
	jmp	.L9
.L14:
	nop
	jmp	.L9
.L15:
	nop
	jmp	.L9
.L16:
	nop
	jmp	.L9
.L17:
	nop
.L9:
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
