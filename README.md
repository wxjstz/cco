# C Language coroutine Library(cco)

This is a simple coroutine library.

## Interface

```c
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
int 	   coroutine_resume (coroutine *co);
void	   coroutine_yield	(coroutine *co);
void	   coroutine_release(coroutine *co);
```

## Build

This library can be buld by linux(i386 amd64) or msys2(mingw32 mingw64).

Use shell to run `build target` 

**target** must be **win-i386** **win-amd64** **linux-i386** **linux-amd64**


