/*H**********************************************************************
* FILENAME :        sum_odds_pair.c
*
* DESCRIPTION :
*       Take an array in input and let two thread make the sum.
*		Th1 must sum pair index, Th2 must sum odds index.
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

struct params{
	int* array;
	int  start;
	int  sum;
};

void* sum(void* parameters){
	struct params* pp=(struct params*) parameters;

	for(int i = pp->start; i < 10; i+=2){
		pp->sum += pp->array[i]; 
	}
	return (void*) &(pp->sum);
}

int main(){
	int array[10];
	
	pthread_t thread_id1, thread_id2;

	struct params th1_args;
	struct params th2_args;

	th1_args.array = array;
	th2_args.array = array;

	th1_args.sum = 0;
	th2_args.sum = 0;

	th1_args.start = 0;
	th2_args.start = 1;

	int* th1_returnvalue;
	int* th2_returnvalue;

	for(int i = 0; i < 10; i++){
		printf("Insert element [%d]:\t", i);
		scanf("%d", &array[i]);
	}

	if((pthread_create(&thread_id1, NULL, &sum, &th1_args)) != 0){
		error("Error on creating thread 1...");
	}
	if((pthread_join(thread_id1, (void*) &th1_returnvalue)) != 0){
		error("Error on joining thread 1...");
	}


	if((pthread_create(&thread_id2, NULL, &sum, &th2_args)) != 0){
		error("Error on creating thread 2...");
	}
	if((pthread_join(thread_id2, (void*) &th2_returnvalue)) != 0){
		error("Error on joining thread 2...");
	}

	puts("Th1 says");
	printf("Sum of pair index is:\t%d\n", *th1_returnvalue);
	
	puts("Th2 says");
	printf("Sum of odds index is:\t%d\n", *th2_returnvalue);

	return 0;
}