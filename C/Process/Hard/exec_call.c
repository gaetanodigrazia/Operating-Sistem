/*H**********************************************************************
* FILENAME :        print_array.c
*
* DESCRIPTION :
*       Take an array of 3 number from the father and sent it to a children.
*       Make the children make the average of this 3 number, add 1 and sent the result back to the father.
*       The father has to read the back calculated number (e.g. "n") and send it to another children.
*       Make this second children execute n times the exec command with ls -l option.
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
#include <unistd.h>
#include <wait.h>


void error(char* msg){
	perror(msg);
	exit(1);
}

int main(){
	int father_toch1[2];
	int ch1_tofather[2];
	int father_toch2[2];
	pid_t pid_ch1, pid_ch2;
	int child_status;
	int average = 0;

	if((pipe(father_toch1)) < 0){
		error("Error on piping");
	}

	if((pipe(father_toch2)) < 0){
		error("Error on piping");
	}

	if((pipe(ch1_tofather)) < 0){
		error("Error on piping");
	}

	if((pid_ch1 = fork()) < 0){
		error("Error on forking Child 1...");
	} else if(pid_ch1 == 0){
		int array[3];
		int average = 0;

		close(father_toch1[1]);
		if((read(father_toch1[0], array, sizeof(array))) < 0){
			error("I'm Child 1, error on reading from Father...");
		} else{

			for(int i = 0; i < 3; i++){
				printf("Received [%d]:\t%d\n", i, array[i]);
				average += array[i];
			}
			average = average/3;

			close(ch1_tofather[0]);
			if((write(ch1_tofather[1], &average, sizeof(average))) < 0){
				error("Error on sending average to Father...");
			} else{
				printf("Average is %d. Successfully sent to Father!\n", average);
			}

		}

	} else{

		if((pid_ch2 = fork()) < 0){
			error("Error on forking Child 2...");
		} else if(pid_ch2 == 0){
			int average = 0;

			close(father_toch2[1]);
			if((read(father_toch2[0], &average, sizeof(average))) < 0){
				error("I'm Child 2, error on reading average from the Father...");
			} else{
				for(int i = 0; i < average; i++){
					puts("I'm launching execl");
					execl("/bin/ls","ls","-l",0);
				}
			}
		} else{

			int array[3];
			int average = 0;
			for(int i = 0; i< 3; i++){
				printf("Send element[%d]:\t", i);
				scanf("%d", &array[i]);
			}

			close(father_toch1[0]);
			if((write(father_toch1[1], array, sizeof(array))) < 0){
				error("Error on writing array to Child 1..,");
			} else{
				puts("Array successfully sent to Child 1!");
			}

			close(ch1_tofather[1]);
			if((read(ch1_tofather[0], &average, sizeof(average))) < 0){
				error("I'm the Father, error on reading average...");
			} else{

				close(father_toch2[0]);
				if((write(father_toch2[1], &average, sizeof(average))) < 0){
					error("I'm the Father, error on sendig average to Child 2...");
				} else{
					printf("Average received is %d. Successfully sent to Child 2!\n", average);
				}
			}
		}
	}
	wait(&child_status);
	return 0;
}