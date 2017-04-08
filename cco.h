#ifndef __CCO_H__
#define __CCO_H__

typedef struct cco cco;

typedef void (*cco_handle)(cco *co,void *arg);

struct cco
{
    void *stack;
    void *sp;
    void *arg;
    int  ret;
    cco_handle entry;
};

cco* cco_create (cco_handle entry,long stack_size,void *arg);
int  cco_resume (cco *co);
void cco_yield  (cco *co);
void cco_release(cco *co);

#endif
