	.text
	.file	"2dArray.cpp"
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$2, -4(%rbp)
	movslq	-4(%rbp), %rax
	cmpq	$2, %rax
	setb	%cl
	movl	$12, %edx
	mulq	%rdx
	movq	%rax, %rdi
	seto	%al
	orb	%al, %cl
	movq	$-1, %rax
	testb	$1, %cl
	cmovneq	%rax, %rdi
	movq	%rdi, -32(%rbp)                 # 8-byte Spill
	callq	_Znam@PLT
	movq	-32(%rbp), %rdx                 # 8-byte Reload
	movq	%rax, %rdi
	movq	%rdi, -24(%rbp)                 # 8-byte Spill
	movl	$23, (%rax)
	movl	$4, 4(%rax)
	movl	$578, 8(%rax)                   # imm = 0x242
	addq	$12, %rdi
	movl	$9, 12(%rax)
	movl	$3, 16(%rax)
	movl	$6, 20(%rax)
	addq	$12, %rdi
	subq	$24, %rdx
	xorl	%esi, %esi
	callq	memset@PLT
	movq	-24(%rbp), %rax                 # 8-byte Reload
	movq	%rax, -16(%rbp)
	xorl	%eax, %eax
	addq	$32, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 14.0.0-1ubuntu1.1"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym _Znam
