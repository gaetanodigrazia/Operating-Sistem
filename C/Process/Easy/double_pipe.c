/*H**********************************************************************
* FILENAME :        double_pipe.c
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
	int rand_tofather = rand()%26;
	printf("Random child cycle is:\t %d\n", rand_child);

	for(int i=0; i<rand_child; i++){
		printLetter();
		sleep(1);
	}
	printf("Random cycle number to father is:\t %d\n", rand_tofather);
	return rand_tofather;
}

int fatherMethod(int random_from_child){
	for(int i= 0; i<random_from_child; i++){
		printNumber(2000);
		sleep(1);
	}
	srand (time(NULL));
	int back_to_child = rand()%20;
	printf("Retrieve %d number to child\n", back_to_child);
	return back_to_child;
}

int main(){
	int child_status;
	pid_t pid;
	int fd[2];
	int backfd[2];

	if((pipe(fd)) < 0 || (pipe(backfd)) < 0) {
		error("Error on piping");
	}
	
	if((pid = fork()) < 0){
		error("Fork error");
	} 
	
	if(pid == 0){
		int tofather = childMethod();
		int fromfather = 0;

		close(fd[0]);
		if((write(fd[1], &tofather, sizeof(tofather))) < 0){
			error("Error on writing to Father...");
		} else{
			puts("Data successfully written!");
		}
		
		close(backfd[1]);
		if((read(backfd[0], &fromfather, sizeof(fromfather))) < 0){
			error("Error on reading from Father...");
		} else{
			puts("Data successfully read");
			printf("Back generated number is %d\n", fromfather);
		}
		
	} else{
		int fromchild = 0;
		int tochild = 0;

		close(fd[1]);
		if((read(fd[0], &fromchild, sizeof(fromchild))) < 0){
			error("Error on reading from Father...");
		} else{
			puts("Data successfully read");
			printf("Child sent: %d\n", fromchild);
		}

		tochild = fatherMethod(fromchild);

		close(backfd[0]);		
		if((write(backfd[1], &tochild, sizeof(tochild))) < 0){
			error("Error on writing to Children...");
		}else{
			puts("Data successfully read");
			printf("Sent to child: %d\n", tochild);
		}
	}
	wait(&child_status);
	return 0;
}