/*
*	threads.h contains the utility methods to start, run and yeild a thread.
*
*	@Authors: Obuli Karthikeyan Sampath & Akshaya Silambaram Chandrabose
*	@Version: 1.3
*	@Date: October 16, 2013
*
*/


#include "q.h"
#include <stdlib.h>
#define MAX_STACK_SIZE 8192

struct TCB *RunQ;

/* start_thread initializes the TCB of the current thread and adds it to the Run queue */
 
void start_thread(void *(function))
{
	void * stack = malloc(MAX_STACK_SIZE);
	TCB_t * tcb = (struct TCB *) malloc(sizeof(struct TCB *) * MAX_STACK_SIZE);
	init_TCB(tcb, function, stack, MAX_STACK_SIZE);
	AddQ(&RunQ, tcb);
}

/* run method puts the thread picks the context info of the current thread and loads it into the CPU  */

void run()
{
	ucontext_t parent;
	getcontext(&parent);
	swapcontext(&parent, &(*RunQ).context );
}

/* yield method swaps the context info of the next-in-queue thread with that of current / yeilding thread */
 
void yield()
{
	RotateQ(&RunQ);
	struct TCB *prev_RunQ = RunQ -> prev;
	swapcontext(&(*prev_RunQ).context, &(*RunQ).context);
}
		

