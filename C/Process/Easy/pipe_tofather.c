/*H**********************************************************************
* FILENAME :        Pipe_tofather.c
*
* DESCRIPTION :
*       Make a simple fork.
*       Let Father print a random number and child print a random letter
*
* AUTHOR :    Gaetano Di Grazia        START DATE :    01/04/2019
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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>

void error(char* msg){
	perror(msg);
	exit(1);
}

void printLetter(){
	srand (time(NULL));
	char random_letter = rand()%26 +'A';
	printf("Child:\t %c \n", random_letter);
}

void printNumber(int range){
	int random_number = rand()% range;
	printf("Father:\t %d\n", random_number);
}

int childMethod(){
	srand (time(NULL));
	int rand_child = rand()%20;
	int rand_father = rand()%26;
	printf("Random child cycle is:\t %d\n", rand_child);
	for(int i=0; i<rand_child; i++){
		printLetter();
		sleep(1);
	}
	printf("Random cycle number to father is:\t %d\n", rand_father);
	return rand_father;
}

void fatherMethod(int random_from_child){
	for(int i= 0; i<random_from_child; i++){
		printNumber(random_from_child);
		sleep(1);
	}
}

int main(){
	int child_status;
	pid_t pid;
	int fd[2];

	if((pipe(fd)) < 0){
		error("Error on piping");
	}

	if((pid = fork()) < 0){
		error("Error on forking...");
	}
	
	if(pid == 0){
		int tofather = childMethod();
		
		close(fd[0]);
		if((write(fd[1], &tofather, sizeof(tofather))) < 0){
			error("Error on sending to Father...");
		} else{
			puts("Successfully sent to Father!");
		}
	} else {
		int tofather;

		close(fd[1]);
		if((read(fd[0], &tofather, sizeof(tofather))) < 0){
			error("Error on reading from Child...");
		}

		fatherMethod(tofather);
	}
	wait(&child_status);
	return 0;
}
