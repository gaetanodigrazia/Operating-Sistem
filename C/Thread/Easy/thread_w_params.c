/*H**********************************************************************
* FILENAME :        thread_w_params.c
*
* DESCRIPTION :
*       Assign a different character to print to two thread
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

/*A struct that contains some paramaters for the thread function*/
struct print_params{
	char character;
	int times;
};

void* print(void* parameters){

	struct print_params* pp= (struct print_params*) parameters;

	for(int i=0; i<= pp->times; i++){
		printf("%c\n", pp->character);
		fflush(stdout);
		sleep(1);
	}
	return NULL;
}

int main(){
	//Declare thread_id
	pthread_t thread_id1, thread_id2;

	//Assign struct to print paramaters
	struct print_params th1_args;
	struct print_params th2_args;

	//Assign a different character to print for each thread
	th1_args.character = '1';
	th2_args.character = '2';

	//Assign a different print times value for each thread
	th1_args.times = 10;
	th2_args.times = 20;

	//Create thread
	if((pthread_create(&thread_id1, NULL, &print, &th1_args)) != 0){
		error("Error on creating thread 1");
	}
	
	if((pthread_create(&thread_id2, NULL, &print, &th2_args)) != 0){
		error("Error on creating thread 2");
	}
	
	//This is necessary to make the scheduler schedule the thread
	while(1){
		puts("Main process is alive...");
		fflush(stdout);
		sleep(3);
	}

	return 0;
}

