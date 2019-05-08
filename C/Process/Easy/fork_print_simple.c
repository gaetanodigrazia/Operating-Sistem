/*H**********************************************************************
* FILENAME :        Fork_print_simple.c
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

void printRandom(int value){
	srand(time(NULL));

	/*GENERATE A RANDOM LETTER AND A RANDOM LETTER*/
	if(value == 0){
		char random_letter = rand() % 26 + 'A';
		printf("Child:\t %c\n", random_letter);
	}

	/*GENERATE A RANDOM LETTER AND A RANDOM NUMBER*/
	else{
		int  random_number = rand() % value;
		printf("Father:\t %d\n", random_number);
	}
	sleep(1);
}

int main(){
	pid_t pid;
	int child_status;

	if((pid = fork()) < 0){
		error("Error on forking...");
	}

	if(pid == 0){
	/*THIS IS THE CHILD*/
		for(int i = 0; i< 26; i++){
			printRandom(0);
		}
	}
	else{
	/*THIS IS THE FATHER*/
		for(int i=0; i<26; i++){
			printRandom(pid);
		}

/*A call to wait() blocks the calling process until 
one of its child processes exits or a signal is received. 
After child process terminates, parent continues its 
execution after wait system call instruction.*/
		wait(&child_status);
		return(0);
	}
}