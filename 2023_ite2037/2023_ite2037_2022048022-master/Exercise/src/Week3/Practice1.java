package Week3;

import java.util.Scanner;
public class Practice1 {
    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);

        String line = keyboard.nextLine();
        String[] vals = line.split(",");

        int val1 = Integer.parseInt(vals[0]);
        int val2 = Integer.parseInt(vals[1]);

        System.out.println("dividend: " + val1);
        System.out.println("divisor: " + val2);
        System.out.println("quotient: " + val1/val2);
        System.out.println("remainder: " + val1%val2);
    }
}
