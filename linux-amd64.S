    .file   "linux-amd64.S"

/* void context_init(void **sp,void *co) */
    .text
    .globl  context_init
context_init:
    pushq   %rax
    movq    %rsp,%rax
    movq    (%rdi),%rsp

    pushq   $cco_entry
    pushq   $0
    pushq   $0
    pushq   $0
    pushq   $0
    pushq   $0
    pushq   $0
    pushq   %rsi
    pushq   $0
    pushq   $0
    pushq   $0
    pushq   $0
    pushq   $0
    pushq   $0
    pushq   $0
    pushq   $0
    pushq   $0

    movq    %rsp,(%rdi)
    movq    %rax,%rsp
    popq    %rax
    retq
    
/* void context_switch(void **sp) */
    .text
    .global context_switch
context_switch:
    pushq   $context_switch_end
    pushfq
    pushq   %rax
    pushq   %rbx
    pushq   %rcx
    pushq   %rdx
    pushq   %rsi
    pushq   %rdi
    pushq   %rbp
    pushq   %r8
    pushq   %r9
    pushq   %r10
    pushq   %r11
    pushq   %r12
    pushq   %r13
    pushq   %r14
    pushq   %r15

    movq    (%rdi),%rax
    movq    %rsp,(%rdi)
    movq    %rax,%rsp

    popq    %r15
    popq    %r14
    popq    %r13
    popq    %r12
    popq    %r11
    popq    %r10
    popq    %r9
    popq    %r8
    popq    %rbp
    popq    %rdi
    popq    %rsi
    popq    %rdx
    popq    %rcx
    popq    %rbx
    popq    %rax
    popfq
    retq
context_switch_end:
    retq
