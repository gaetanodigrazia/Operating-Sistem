/*H**********************************************************************
* FILENAME :        print_array.c
*
* DESCRIPTION :
*       Send an array from father to children and print it
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


void error(char* msg){
	perror(msg);
	exit(1);
}

int main() {

	int fd[2];
	pid_t pid;
	int child_status;
	
	if(pipe(fd) < 0){
		error("Error on piping...");
	}

	if((pid = fork()) < 0){
		error("Error on forking");
	}

	if(pid == 0){
		int array[5];

		close(fd[1]);
		if(read(fd[0], array, sizeof(array)) < 0){
			error("Error on reading");
		}

		for(int i = 0; i<5; i++){
			printf("Received element [%d]:\t %d \n", i, array[i]);
		}


	}else{
		int array[5];

		for (int i = 0; i < 5; i++){
			printf("Send element [%d]:\t", i);
			scanf("%d", &array[i]);
		}

		close(fd[0]);
		if((write(fd[1], array, sizeof(array))) < 0){
			error("Error on writing");
		}
	}
	wait(&child_status);
	return 0;
}