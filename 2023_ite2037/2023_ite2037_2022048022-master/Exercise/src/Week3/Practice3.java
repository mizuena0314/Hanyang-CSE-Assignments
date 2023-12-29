package Week3;

import java.util.Scanner;
public class Practice3 {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        System.out.println("Enter name of item 1:");
        String name1;
        name1 = input.nextLine();

        System.out.println("Enter quantity of item 1:");
        int q1 = input.nextInt();

        System.out.println("Enter price of item 1:");
        double price1 = input.nextDouble();
        input.nextLine();

        System.out.println("Enter name of item 2:");
        String name2;
        name2 = input.nextLine();

        System.out.println("Enter quantity of item 2:");
        int q2 = input.nextInt();

        System.out.println("Enter price of item 2:");
        double price2 = input.nextDouble();
        input.nextLine();

        System.out.println("Enter name of item 3:");
        String name3;
        name3 = input.nextLine();

        System.out.println("Enter quantity of item 3:");
        int q3 = input.nextInt();

        System.out.println("Enter price of item 3:");
        double price3 = input.nextDouble();
        input.nextLine();

        double total1 = q1*price1;
        double total2 = q2*price2;
        double total3 = q3*price3;

        System.out.println("Your bill:");
        System.out.println();
        System.out.printf("%-30s%-10s%-10s%-10s\n", "ITEM", "QUANTITY", "PRICE", "TOTAL");
        System.out.printf("%-30s%-10d%-10.2f%-10.2f\n", name1, q1, price1, q1*price1);
        System.out.printf("%-30s%-10d%-10.2f%-10.2f\n", name2, q2, price2, q2*price2);
        System.out.printf("%-30s%-10d%-10.2f%-10.2f\n", name3, q3, price3, q3*price3);
        System.out.println();
        System.out.printf("%-50s%-10.2f\n", "SUBTOTAL", total1+total2+total3);
        System.out.printf("%-50s%-10.2f\n", "6.25% SALES TAX", (total1+total2+total3)*0.0625);
        System.out.printf("%-50s%-10.2f\n", "TOTAL",(total1+total2+total3)*1.0625);
    }
}
