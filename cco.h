#ifndef __CCO_H__
#define __CCO_H__

typedef struct coroutine coroutine;

typedef void (*coroutine_handle)(coroutine *co,void *arg);


struct coroutine
{
    void *stack;
    void *sp;
    void *arg;
    int  ret;
    coroutine_handle entry;
};



coroutine* coroutine_create (coroutine_handle entry,long stack_size,void *arg);
int        coroutine_resume (coroutine *co);
void       coroutine_yield  (coroutine *co);
void       coroutine_release(coroutine *co);



#endif
