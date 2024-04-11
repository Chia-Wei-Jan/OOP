import java.io.*;
import java.util.Scanner;
import java.util.Random;
import java.util.concurrent.TimeUnit;

public class Validation {
	public static void main(String args[]) {
		String input;
		try {
			FileInputStream file = new FileInputStream("input.txt");
			Scanner sc = new Scanner(file);     
			while(sc.hasNextLine()) {
				input = sc.nextLine();
				input = input.replace("\n", "").replace("\r", "");
			        String subStr;	
				// input is brand
				if(input.equals("004") || input.equals("005") || input.equals("006") || input.equals("0037")) {
					// copy prefix of brand to subStr
					if(input.equals("0037"))
						subStr = input.substring(2, 4);
					else
						subStr = input.substring(2, 3);

					System.out.print("Generate a valid ");
					        long startTime = System.nanoTime();    // timer start
						generate_cardNumber(subStr);           // generate the card number
						long endTime = System.nanoTime();      // timer end
	                                        long timeElapsed = (endTime - startTime) / 1000;
						System.out.println("Time: " + timeElapsed + " microseconds");
				}
				// input is card number
				else if(input.length() >= 13 && input.length() <= 16) {
					if(isvalid(input))
						System.out.print(input + ": a valid ");
					else
						System.out.print(input + ": an invalid ");
					
					// copy prefix of card number to subStr
					subStr = input.substring(0, 2);
					startsWith(input, subStr);
					System.out.println("");
				}
				// Error input
				else {
					System.out.println("Error input: " + input);
				}
			}
			sc.close();
		}
		catch(IOException e) {  
			e.printStackTrace();  
		}  
	}

	// Return true if the card number is valid
	public static boolean isvalid(String cardNumber) {
		int sum_double = 0, sum_odd = 0, sum = 0;
		
		sum_double = sumOfDoubleEvenPlace(cardNumber);
		sum_odd = sumOfOddPlace(cardNumber);
		sum = sum_double + sum_odd;

		if(sum % 10 == 0)
			return true;
		else
			return false;
	}

	// Double every second digit from right to left
	// // If results in a two-digit number, add the two digits to get a single digit number
	public static int getDigit(int number) {
		number *= 2;

		if(number >= 10) 
			number = 1 + number - 10;
		
		return number;
	}

	// Add all single-digit numbers by "getDigit" function
	public static int sumOfDoubleEvenPlace(String cardNumber) {
		int length = cardNumber.length();
		int sum = 0, digit = 0, number = 0;
		char[] cardNumber_arr = cardNumber.toCharArray();

		for(int i = length - 2; i >= 0; i -= 2) {
			digit = Character.getNumericValue(cardNumber_arr[i]) - Character.getNumericValue('0');
			number = getDigit(digit);
			sum += number;
		}

		return sum;
	}

	// Add all digits in the odd places from right to left in the card number
	public static int sumOfOddPlace(String cardNumber) {
		int length = cardNumber.length();
		int sum = 0, digit = 0;
		char[] cardNumber_arr = cardNumber.toCharArray();

		for(int i = length - 1; i >= 0; i -= 2) {
			digit = Character.getNumericValue(cardNumber_arr[i]) - Character.getNumericValue('0');
			sum += digit;
		}

		return sum;
	}

	// Return true if substr is the prefix for cardNumber
	public static boolean startsWith(String cardNumber, String subStr) {
		char[] cardNumber_arr = cardNumber.toCharArray();
		char[] subStr_arr = subStr.toCharArray();

		if(subStr_arr[0] == '4' && cardNumber_arr[0] == subStr_arr[0])
			System.out.print("Visa card");
		else if(subStr_arr[0] == '5' && cardNumber_arr[0] == subStr_arr[0])
			System.out.print("MasterCard card");
                else if(subStr_arr[0] == '6' && cardNumber_arr[0] == subStr_arr[0])
			System.out.print("Discover card");
                else if(subStr_arr[0] == '3' && subStr_arr[1] == '7' && cardNumber_arr[0] == subStr_arr[0] && cardNumber_arr[1] == subStr_arr[1])
			System.out.print("American Express card");
		else
			return false;
		
		return true;
	}

	// Generate the valid cardNumber
	public static void generate_cardNumber(String subStr) {
		char[] subStr_arr = subStr.toCharArray();
		char[] cardNumber_arr = new char[20];
		
		// End until generate a valid card number
		while(true) {
			int k = 1;    // start to generate the number from second digit
			if(subStr_arr[0] == '4')
				cardNumber_arr[0] = '4';
			else if(subStr_arr[0] == '5')
				cardNumber_arr[0] = '5';
			else if(subStr_arr[0] == '6')
				cardNumber_arr[0] = '6';
			else if(subStr_arr[0] == '3' && subStr_arr[1] == '7') {
				cardNumber_arr[0] = '3';
				cardNumber_arr[1] = '7';
				k = 2;   // start to generate the number from third digit
			}
			
			Random random = new Random();
			for(; k < 16; k++) {      // generate other digits
				int rand = random.nextInt(10);
				cardNumber_arr[k] = Integer.toString(rand).charAt(0);      	
			}
			
			String cardNumber = new String(cardNumber_arr);
			if(isvalid(cardNumber) && startsWith(cardNumber, subStr)) {
				System.out.print(": ");
				System.out.print(cardNumber);
				System.out.print("; ");
				break;
			}
		}
	}
}

