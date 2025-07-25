	.file	"static.cpp"
	.text
	.globl	g
	.data
	.align 4
	.type	g, @object
	.size	g, 4
g:
	.long	43
	.align 4
	.type	_ZZ5func1vE1a, @object
	.size	_ZZ5func1vE1a, 4
_ZZ5func1vE1a:
	.long	34
	.text
	.globl	_Z5func1v
	.type	_Z5func1v, @function
_Z5func1v:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	_Z5func1v, .-_Z5func1v
	.local	_ZZ5func2vE1a
	.comm	_ZZ5func2vE1a,4,4
	.globl	_Z5func2v
	.type	_Z5func2v, @function
_Z5func2v:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	_Z5func2v, .-_Z5func2v
	.data
	.align 4
	.type	_ZL5dfasf, @object
	.size	_ZL5dfasf, 4
_ZL5dfasf:
	.long	34
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$34, -4(%rbp)
	call	_Z5func1v
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
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
