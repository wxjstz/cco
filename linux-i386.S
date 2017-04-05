    .file   "linux-i386.S"

/* void context_init(void **sp,void *co) */
    .text
    .globl  context_init
context_init:
    push    %eax
    push    %ebx
    push    %ecx

    
    mov     16(%esp),%ecx    /* sp */
    mov     20(%esp),%ebx    /* co */
    mov     %esp,%eax        /* backup sp */
    mov     (%ecx),%esp        /* set target sp */
    
    push    %ebx
    push    $0

    push    $coroutine_entry
    push    $0
    push    $0
    push    $0
    push    $0
    push    $0
    push    $0
    push    $0
    push    $0
    
    mov     %esp,(%ecx)

    mov     %eax,%esp
    pop     %ecx
    pop     %ebx
    pop     %eax
    ret


/* void context_switch(void **sp) */
    .text
    .global context_switch
context_switch:
    push    $context_switch_end
    pushf
    push    %eax
    push    %ebx
    push    %ecx
    push    %edx
    push    %esi
    push    %edi
    push    %ebp
    
    mov     %esp,%ebx
    mov     40(%esp),%eax
    mov     (%eax),%esp
    mov     %ebx,(%eax)

    pop     %ebp
    pop     %edi
    pop     %esi
    pop     %edx
    pop     %ecx
    pop     %ebx
    pop     %eax
    popf
context_switch_end:
    ret

    
    
