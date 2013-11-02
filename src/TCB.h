/*
*	TCB.h contains the structure of the TCB and its initialization construct 
*
*	@Authors: Obuli Karthikeyan Sampath & Akshaya Silambaram Chandrabose
*	@Version: 1.3
*	@Date: October 16, 2013
*
*/


#include<ucontext.h>
#include<string.h>

typedef struct TCB
{
	struct TCB *next;
	struct TCB *prev;
	ucontext_t context;
} TCB_t;

/* function to initialize the TCB with the context information */
void init_TCB(TCB_t *tcb, void *function, void *stackP, int stack_size)
{
	memset(tcb, '\0', sizeof(TCB_t));
	getcontext(&tcb->context);
	tcb->context.uc_stack.ss_sp = stackP;
	tcb->context.uc_stack.ss_size = stack_size;
 	makecontext(&tcb->context, function, 0);
}

