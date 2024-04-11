import java.io.*;
import java.util.Scanner;

public class Avg {
    public static void main(String args[]) {
        String amtStr;
        int count = 0;
        int sum = 0;
        int grade = 0;
        double average = 0.0;

        Scanner sc = new Scanner(System.in);
        while(true) {
            System.out.println("Please input your score:");
            amtStr = sc.next();    // Read the input string
            
            int length = amtStr.length();   // Get the length of string
            
            try {    // Convert string to integer
                grade = Integer.parseInt(amtStr);
            }
            catch (NumberFormatException e) {   // Error: not integer
                System.out.println("Illegal input, ending the program...");
                System.exit(1);
            }

            if(grade == -1 && count != 0)   // Compute the average
                break;

            if(grade < 0 || grade > 100) {   // Out of boundary (0-100)
                System.out.println("Illegal input, ending the program...");
                System.exit(1);
            }
            sum += grade;
            count++;
        }

        // Compute the average
        average = (double) sum / count;
        System.out.printf("Your average score is: %.2f\n", average);
    }
}
