	.file	"2dArray.cpp"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA0
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$16, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movl	$2, -28(%rbp)
	movl	-28(%rbp), %eax
	movslq	%eax, %rbx
	movabsq	$768614336404564650, %rax
	cmpq	%rax, %rbx
	ja	.L2
	movq	%rbx, %rax
	addq	%rax, %rax
	addq	%rbx, %rax
	salq	$2, %rax
	movq	%rax, %rdi
.LEHB0:
	call	_Znam@PLT
	movq	%rax, %r12
	movq	%r12, %rax
	leaq	-1(%rbx), %rdx
	testq	%rdx, %rdx
	jg	.L4
	jmp	.L10
.L2:
	call	__cxa_throw_bad_array_new_length@PLT
.LEHE0:
.L10:
.LEHB1:
	call	__cxa_throw_bad_array_new_length@PLT
.LEHE1:
.L4:
	movl	$23, (%rax)
	movl	$4, 4(%rax)
	movl	$578, 8(%rax)
	addq	$12, %rax
	subq	$1, %rdx
	movl	$9, (%rax)
	movl	$3, 4(%rax)
	movl	$6, 8(%rax)
	addq	$12, %rax
	subq	$1, %rdx
	jmp	.L5
.L6:
	movq	$0, (%rax)
	movl	$0, 8(%rax)
	addq	$12, %rax
	subq	$1, %rdx
.L5:
	testq	%rdx, %rdx
	jns	.L6
	movq	%r12, -24(%rbp)
	movl	$0, %eax
	jmp	.L11
.L9:
	endbr64
	movq	%rax, %rbx
	movq	%r12, %rdi
	call	_ZdaPv@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB2:
	call	_Unwind_Resume@PLT
.LEHE2:
.L11:
	addq	$16, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA0:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE0-.LLSDACSB0
.LLSDACSB0:
	.uleb128 .LEHB0-.LFB0
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB0
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L9-.LFB0
	.uleb128 0
	.uleb128 .LEHB2-.LFB0
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE0:
	.text
	.size	main, .-main
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
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
