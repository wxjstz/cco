#include <stdio.h>
#include "cco.h"



void routine(coroutine *co,void *arg)
{
    int i=0;
    printf("%s step %d\n",(char*)arg,i++);
    coroutine_yield(co);
    printf("%s step %d\n",(char*)arg,i++);
    coroutine_yield(co);
    printf("%s step %d\n",(char*)arg,i++);
    coroutine_yield(co);
}



int main()
{
    coroutine *r1 = coroutine_create(routine,1024*1024,"r1");
    while(coroutine_resume(r1));
    coroutine_release(r1);

    coroutine *r2 = coroutine_create(routine,1024*1024,"r2");
    while(coroutine_resume(r2));
    coroutine_release(r2);
    
    
    return 0;
}
