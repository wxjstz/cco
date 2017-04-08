#include <stdio.h>
#include "cco.h"



void routine(cco *co,void *arg)
{
    int i=0;
    printf("%s step %d\n",(char*)arg,i++);
    cco_yield(co);
    printf("%s step %d\n",(char*)arg,i++);
    cco_yield(co);
    printf("%s step %d\n",(char*)arg,i++);
    cco_yield(co);
}



int main()
{
    cco *r1 = cco_create(routine,1024*1024,"r1");
    while(cco_resume(r1));
    cco_release(r1);

    cco *r2 = cco_create(routine,1024*1024,"r2");
    while(cco_resume(r2));
    cco_release(r2);
    
    
    return 0;
}
