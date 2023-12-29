package Week3;

import java.util.Scanner;
public class Practice2 {
    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);

        int percentage = keyboard.nextInt();

        System.out.printf("(%d/%d)*%d=%.0f", percentage, 100, 4, (percentage/100.0)*4);
    }
}
