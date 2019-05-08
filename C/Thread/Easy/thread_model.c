/*H**********************************************************************
* FILENAME :        thread_model.c
*
* DESCRIPTION : A model of how to write a thread program in C
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

struct print_params{
	int sample_value;
};

/*A FUNCTION THAT A THREAD HAS TO EXECUTE*/
/*NOTE: (VOID*) TYPE IS OBLIGATORY*/
void* print(void* parameters){
	/*DECLARE A POINTER TO THE STRUCT*/
	struct print_params* pp= (struct print_params*) parameters;
	/*HOW TO ACCES TO STRUCT VALUE*/
	pp->sample_value = 3;
	/*HOW TO RETURN SOME VALUE*/
	return (void*) &(pp->sample_value);
}

int main(){

	//Declare thread_id
	pthread_t thread_id1;

	//Assign struct to print paramaters
	struct print_params th1_args;

	//Declare the return value for thread
	int* th1_returnValue;
	
	//Assign a value to the variable in the struct
	th1_args.sample_value = 2;
	
	//Create thread
	pthread_create(&thread_id1, NULL, &print, &th1_args);
	
	//Join thread, wait thread_id1 to finish and capture the return value from the function
	pthread_join(thread_id1, (void**) &th1_returnValue);
}


