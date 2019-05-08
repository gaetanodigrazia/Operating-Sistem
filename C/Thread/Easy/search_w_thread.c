/*H**********************************************************************
* FILENAME :        search_w_thread.c
*
* DESCRIPTION :
*       Take an array in input and make a thread search an element in it
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

struct params {
	int *array;
	int pos;
	int element;
};

void* search(void* parameters) {

	struct params* p=(struct params*) parameters;
	
	for(int i = 0; i < 10; i++){
		if(p->element == p->array[i]){
			p->pos = i;
			return (void*) &(p->pos);
		}
	}
	p->pos = -1;
	puts("Value not found");
	return (void*) &(p->pos);
}


int main(){
	int array[10];
	int element = 0;

	pthread_t thread_id;

	int *return_value;

	struct params parameters;

	for(int i = 0; i < 10; i++){
		printf("Insert element [%d]:\t", i);
		scanf("%d", &array[i]);
	}

	/* A LITTLE PART OF "DEBUG"*/
	/*
	for(int i = 0; i < 10; i++){
		printf("Inserted element [%d]:\t%d\n", i, array[i]);
	}*/

	printf("Insert element you want to search in array:\t");
	scanf("%d", &element);

	parameters.array = array;
	parameters.element = element;

	if((pthread_create(&thread_id, NULL, &search, &parameters)) != 0){
		error("Error on creating thread 1...");
	}

	if((pthread_join(thread_id, (void**) &return_value)) != 0){
		error("Error on joining thread 1...");
	}

	if(*return_value != -1){
		printf("Value found at position:\t %d\n", *return_value);
	} else{
		puts("Value not found");
	}
	return 0;
}