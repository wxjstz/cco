# C Language coroutine Library(cco)

This is a simple coroutine library.

## Interface

```c
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
void cco_yield	(cco *co);
void cco_release(cco *co);
```

## Build

This library can be buld by linux(i386 amd64) or msys2(mingw32 mingw64).

Use shell to run `build target` 

**target** must be **win-i386** **win-amd64** **linux-i386** **linux-amd64**


