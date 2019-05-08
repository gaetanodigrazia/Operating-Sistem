/*H**********************************************************************
* FILENAME :        average.c
*
* DESCRIPTION :
*       Send an array from father to children, make the sum
*       then send it to another children than make the
*       average
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

#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include <unistd.h>


void error(char* msg){
	perror(msg);
	exit(1);
}

int main(){
	int father_toch1[2];
	int ch1_toch2[2];
	pid_t pid_ch1, pid_ch2;
	int child_status;

	if((pipe(father_toch1)) < 0){
		error("Error on piping to father...");
	}

	if((pipe(ch1_toch2)) < 0){
		error("Error on piping ch1 to children...");
	}

	if((pid_ch1 = fork()) < 0){
		error("Error on forking...");
	}

	if(pid_ch1 == 0){
		int array[5];
		int sum = 0;

		close(father_toch1[1]);
		if((read(father_toch1[0], array, sizeof(array))) < 0){
			error("Error on reading from Father...");
		} else{

			for(int i = 0; i<5; i++){
				printf("Received element [%d]:\t %d \n", i, array[i]);
			}

			for(int i = 0; i < 5; i++){
				sum += array[i];
			}
			printf("Sum is:\t%d\n", sum);

			close(ch1_toch2[0]);
			if((write(ch1_toch2[1], &sum, sizeof(int))) < 0){
				error("Error on writing to Child 2...");
			} else{
				puts("Sum sent to the child 2!");
			}
		}

	} else {
		int array[5];

		for(int i = 0; i < 5; i++){
			printf("Send element [%d]:\t", i);
			scanf("%d", &array[i]);
		}

		close(father_toch1[0]);
		if((write(father_toch1[1], array, sizeof(array))) < 0){
			error("Error on writing to Child 1...");
			exit(1);
		} else{
			puts("Written to Child 1!");
		}


		if((pid_ch2 = fork()) < 0){
			error("Error on forking Child 2...");
		}

		if(pid_ch2 == 0){
			int sum = 0;
			close(ch1_toch2[1]);
			if((read(ch1_toch2[0], &sum, sizeof(int))) < 0){
				error("Error on reading from Child 2...");
			} else{
				int avg = (sum/5);
				printf("Average of inserted array is:\t%d\n", avg);
			}
			
		} else{
			/*FATHER AGAIN*/
		}
	}
	wait(&child_status);
	return 0;
}