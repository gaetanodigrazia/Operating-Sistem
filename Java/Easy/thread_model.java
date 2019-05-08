/*H**********************************************************************
* FILENAME :        thread_model.java
*
* DESCRIPTION : A model of how to write a thread program in Java
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

public class ThreadTester{
	public static void main(String[] args) {
		int sample_value = 12321;
		/*CREATE AN OBJECT THREAD1 FROM CLASS PRINT THREAD*/
		PrintThread thread1 = new PrintThread("Thread_name", sample_value);
		/*START THREAD*/
		thread1.start();
		thread1.join();
	}
}

class PrintThread extends Thread {
	int value;
	public PrintThread(String name, int value){
		super(name);
		this.value = value;
	}

	public void run(){
		try{
			/*DO SOMETHING*/
			System.out.println("Print received value"+value);
		}catch(InterruptedException exception){
			exception.printStackTrace();
		}
	}
}