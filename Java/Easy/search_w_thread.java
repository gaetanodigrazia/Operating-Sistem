/**
 * Create a thread and make it search a value in an array
 * 
 * @author Gaetano Di Grazia
 * @version 1.0
 * License
 * @link https://www.gnu.org/licenses/gpl-3.0.en.html
 * @see SearchValue.java
 */
package search_w_thread;

import java.util.Scanner;

public class Main{
	
	public static void main(String args[]){
		int[] array = new int[10];
		int value;
		Scanner in = new Scanner(System.in);
		for(int i = 0; i < 10; i++){
			System.out.print("Insert element at position ["+i+"]: ");
			array[i] = in.nextInt();
		}

		System.out.print("Insert element you want to search: ");
		value = in.nextInt();

		SearchValue sv = new SearchValue("Search", array, value);
		sv.start();
	} 
}

package search_w_thread;

public class SearchValue extends Thread{
	private int value;
	private int[] array = new int[10];

	public SearchValue(String name, int array[], int value){
		super(name);		
		setValue(value);
		setArray(array);
	}
	public void run(){
		for(int i = 0; i < 10; i++){
			if(getElement(i) == getValue()){
				System.out.println("Value found at index: "+i);
				return;
			}
		}
		System.out.println("Value not found...");
	}

	public void setValue(int value){
		this.value = value;
	}

	public int getValue(){
		return value;
	}


	public void setArray(int array[]) {
		this.array = array;
	}
	
	public int getElement(int index){
		return array[index];
	}
}