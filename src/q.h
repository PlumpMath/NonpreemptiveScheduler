/*
*	q.h contains the functions required for implementing a circular doubly linked queue 
*
*	@Authors: Obuli Karthikeyan Sampath & Akshaya Silambaram Chandrabose
*	@Version: 1.3
*	@Date: October 16, 2013
*
*/

#include <stdio.h>
#include <stdlib.h>
#include "TCB.h"

struct TCB * InitQ( struct TCB **);
void AddQ ( struct TCB **, struct TCB * ) ;
struct TCB * DelQ( struct TCB ** ) ;
void RotateQ(struct TCB **);
void cirq_display (struct TCB ** ) ;

/* Initialize the head pointer of the queue */
struct TCB * InitQ(struct TCB **q)
{
	return *q =NULL;
}

/* adds a new element at the end of queue */
void AddQ ( struct TCB **head, struct TCB *item )
{
	struct TCB *newNode, *tempNode = NULL;

    /* create new node */
	newNode = item;
	
	/* if the queue is empty, make item to be the first (head) node */
	if( (*head) == NULL)
	{
		newNode -> next = newNode -> prev = newNode;
		(*head) = newNode;
	}
	else
	{
		tempNode = (*head);
		/* traverse to the rear node */
		while(tempNode -> next != (*head))
		{
			tempNode = tempNode -> next;
		}

		/* add node at the end and make it to be the rear node */
		newNode -> prev = tempNode;
		tempNode -> next = newNode;
		newNode -> next = (*head);
	}
}

/* removes an element from front of queue */
struct TCB * DelQ (struct TCB **head )
{
    struct TCB *lastNode, *tempNode;
    ucontext_t item;

	tempNode = *head;

    /* if queue is empty */
	if ( *head == NULL )
        printf ( "TCB queue is empty" ) ;
    else
    {
		/* check if there is only one TCB */
        if ( (*head) -> next == (*head) )
        {
    	    item = ( **head ).context ;
           	return *head;
        }
        else
        {
            /* traverse to the rear node */
			while( tempNode -> next != *head)
			{
				tempNode = tempNode -> next;
			}
	
			/* mark the node for deletion*/
			lastNode = *head ;
            //item = (*lastNode).context;

			/* make the next node to be the header node after deletion */
			*head = (*head) -> next;
			tempNode -> next = *head;
			(*head) -> prev = tempNode;
          
        }
        return ( lastNode ) ;
    }
}

void RotateQ(struct TCB **head )
{
struct TCB *tempNode;
if ( *head == NULL )
        printf ( "TCB queue is empty" ) ;
	else
	{
		
		tempNode = *head;
		/*  move the head to point to next node and add head node at the end 
		for eg: (1 2 3 4) becomes (2 3 4 1)
		*/
		*head = ( *head ) -> next;
		( *head ) -> prev = tempNode;
	    tempNode -> next = *head;
	}
}


