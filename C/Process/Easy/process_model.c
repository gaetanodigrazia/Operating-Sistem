/*H**********************************************************************
* FILENAME :        process_model.c
*
* DESCRIPTION : A model of how to write a process program in C
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

int main(){
/*DECLARE PID*/
	pid_t pid;
/*DECLARE PIPE*/
	int fd[2];
	int child_status;
/*PIPE FD*/
 pipe(fd[2]);

/*DO THE FORK*/
 pid = fork();
/*CHECK IF FATHER OR CHILD*/
 if(pid == 0){
 	int var = 1234;
  /*THIS IS THE CHILD*/
 	close(fd[0]);
 	write(fd[1], &var, sizeof(var))
 } else{
 	int var = 0;
 	close(fd[1]);
 	read(fd[0], &var, sizeof(var));
  /*THIS IS THE FATHER*/
 }
 wait(&child_status);
 return 0;
}