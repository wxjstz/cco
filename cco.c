#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "cco.h"

void context_switch(void **sp);
void context_init(void **sp,void *co);

#if defined(__unix__) && (defined(__i386__) || defined(__i686__))
    typedef unsigned long machine_word_type;
#elif defined(__unix__) && (defined(__x86_64__) || defined(__amd64__))
    typedef unsigned long machine_word_type;
#elif defined(__MINGW64__)
    typedef unsigned long long machine_word_type;
#elif defined(__MINGW32__)
    typedef unsigned long machine_word_type;
#else
    #error "you have to define `machine_word_type` for you target"
#endif

cco* cco_create(cco_handle entry,long stack_size,void *arg)
{
    cco *co = malloc(sizeof(*co));
    if(co)
    {
        void *stack_top;
        long sz = (stack_size + sizeof(machine_word_type) - 1) - (stack_size + sizeof(machine_word_type) - 1) % sizeof(machine_word_type);
        co->stack = malloc(sz + sizeof(machine_word_type));
        if(co->stack)
        {
            
#ifdef STACK_GROW_UP
            stack_top = co->sp = co->stack;
#else
            stack_top = co->sp = co->stack + sz;
#endif
            context_init(&(co->sp),co);
            co->arg = arg;
            co->entry = entry;
            return co;
        }
        free(co);
    }
    return NULL;
}

void cco_entry(cco *co)
{
    co->entry(co,co->arg);
    co->ret = 0;
    context_switch(&(co->sp));
}

int cco_resume(cco *co)
{
    context_switch(&(co->sp));
    return co->ret;
}

void cco_yield(cco *co)
{
    co->ret = 1;
    context_switch(&(co->sp));
}



void cco_release(cco *co)
{
    free(co->stack);
    free(co);
}
