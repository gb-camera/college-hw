//Michael Dinh - CISP 401 - Arrays
import java.util.*;
import java.io.*;
public class Numbers {
	public static void main(String[] args){
		int[] a, b;
		Integer[] InA;

		a = getData();

		b = new int[a.length];
		System.arraycopy(a, 0, b, 0, a.length);

		InA = toInteger(a);

		System.out.printf("Inputted values in ascending order are as follows: ");
		display(InA, false);
		System.out.printf("Inputted values in descending order are as follows: ");
		display(InA, true);
	}
	
	//Takes user input until input is -1, no duplicates, array doubled when full
	static int[] getData(){
		Scanner reader = new Scanner(System.in);
		int[] data = new int[2];
		int tracker = 0;
		int input = 0;
		do {
			System.out.printf("Enter element #%d, or -1 to end input: ", tracker + 1);
			input = reader.nextInt();
			if(input != -1){
				if(!checkDuplicate(data, input)){
					if(data.length == tracker){
						data = resize(data);
					}
					data[tracker] = input;
					tracker += 1;
				}
				else{
					System.out.println("Duplicate detected! Starting from input.");
				}
			}
		} while(input != -1);
		return data;
	}
	
	//Method returns a copy of the original array with double size
	static int[] resize(int[] data){
		int[] temp = new int[data.length * 2];
		System.arraycopy(data, 0, temp, 0, data.length);
		return temp;
	}
	
	//Method returns true/false if key is in array
	static boolean checkDuplicate(int[] data, int key){
		for(int i = 0; i < data.length; i++){
			if(data[i] == key){
				return true;
			}
		}
		return false;
	}
	
	//Boolean reverse==true will cause a reverse order print
	static void display(Integer[] data, boolean reverse){
		//use a for loop to display in ascending and descending order. Can use 
		//the sort method in the Arrays class
		Integer[] temp = new Integer[data.length];
		System.arraycopy(data, 0, temp, 0, data.length);
		Arrays.sort(temp);
		if(!reverse){
			for(int i = 0; i < temp.length; i++){
				if(temp[i] == 0){
					continue;
				}
				else{
					System.out.printf("%d ", temp[i]);
				}
			}
		}
		else if(reverse){
			for(int i = temp.length - 1; i >= 0; i--){
				if(temp[i] == 0){
					continue;
				}
				else{
					System.out.printf("%d ", temp[i]);
				}
			}
		}
		System.out.printf("\n");
	}
	
	static Integer[] toInteger(int[] data){
		Integer[] temp = new Integer[data.length];
		for(int i = 0; i < data.length; i++){
			temp[i] = Integer.valueOf(data[i]);
		}
		return temp;
	}
}