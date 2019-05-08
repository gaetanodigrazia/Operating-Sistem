/*H**********************************************************************
* FILENAME :        thread_w_return_value.c          
*
* DESCRIPTION :
* Return a value to main programs
*      
* AUTHOR :    Gaetano Di Grazia        START DATE :    02/05/2019
*
* CHANGES :
*
* REF NO  VERSION DATE    WHO     DETAIL
*
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
* 
* Copyright (c) 2019 by Gaetano Di Grazia, education.digrazia@gmail.com
* All rights reserved.
*H*/


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void error(char* msg){
	perror(msg);
	exit(1);
}
struct print_params{
	char character;
	int times;
};

void* print(void* paramaters){

	struct print_params* pp= (struct print_params*) paramaters;

	for(int i=0; i<= pp->times; i++){
		printf("%c\n", pp->character);
		fflush(stdout);
		sleep(1);
	}
	return (void*) &(pp->times);
}

int main(){

	//Declare thread_id
	pthread_t thread_id1, thread_id2;

	//Assign struct to print paramaters
	struct print_params th1_args;
	struct print_params th2_args;

	//Declare the return value for each thread
	int* th1_returnValue;
	int* th2_returnValue;
	
	//Assign a different character to print for each thread
	th1_args.character = '1';
	th2_args.character = '2';

	//Assign a different print times value for each thread
	th1_args.times = 10;
	th2_args.times = 20;
	
	//Create thread
	if((pthread_create(&thread_id1, NULL, &print, &th1_args)) != 0){
		error("Error on create thread 1");
	}

	if((pthread_create(&thread_id2, NULL, &print, &th2_args)) != 0){
		error("Error on create thread 2");
	}

	/*int pthread_join(pthread_t thread, void **value_ptr);

	DESCRIPTION
	The pthread_join() function suspends execution of the calling thread until the target thread terminates, 
	unless the target thread has already terminated. 
	On return from a successful pthread_join() call with a non-NULL value_ptr argument, 
	the value passed to pthread_exit() by the terminating thread is made available 
	in the location referenced by value_ptr.*/

	/*If successful, the pthread_join() function returns zero. 
	Otherwise, an error number is returned to indicate the error.*/

	//Wait until children thread has finished
	if((pthread_join(thread_id1, (void**) &th1_returnValue)) != 0){
		error("Error on join thread 1");
	}
	
	if((pthread_join(thread_id2, (void**) &th2_returnValue)) != 0){
		error("Error on join thread 2");
	}
	
	//Print return value
	printf("TH1 say:%d\n", *th1_returnValue);
	printf("TH2 say:%d\n", *th2_returnValue);

	return 0;
}

