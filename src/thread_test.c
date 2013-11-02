/*
*	thread_test.c simulates scheduling of user-level threads in a non preemptive uniprocessor system  
*
*	@Authors: Obuli Karthikeyan Sampath & Akshaya Silambaram Chandrabose
*	@Version: 1.3
*	@Date: October 16, 2013
*
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "threads.h"

int global=0;

/* naturalNumbers function prints the set of natural numbers */

void naturalNumbers()
{
   int local = 0;

    while (1){
        printf("Executing Function 1: naturalNumbers ->\t global = %d  local = %d\n", global, local);
        sleep(1);
        global++; 
		local ++;
       //printf("Function 3 incremented .... global = %d  local = %d\n", global, local);
        sleep(1);
		yield();
    }
}    

/* squares funtion prints the squares of natural numbers */

void squares()
{
   int local = 0;

    while (1){
        printf("Executing Function 2: squares ->\t global = %d  local = %d\n", global, local*local);
        sleep(1);
        global++; 
		local ++;
        //printf("Function 1 incremented .... global = %d  local = %d\n", global, local);
        sleep(1);
		yield();
    }
}    

/*cubes function prints the cube of natural numbers */

void cubes()
{
   int local = 0;

    while (1){
        printf("Executing Function 3: cubes ->\t\t global = %d  local = %d\n", global, local*local*local);
        sleep(1);
        global++; 
		local ++;
        //printf("Function 2 incremented .... global = %d  local = %d\n", global, local);
        sleep(1);
		yield();
    }
}    

int main()
{  
	RunQ = InitQ(&RunQ);
	start_thread(naturalNumbers);
    start_thread(squares);
    start_thread(cubes);

	run();	
	
    while(1) 
	{
		sleep(1); 
	}

    return 0;
}

