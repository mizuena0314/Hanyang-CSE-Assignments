package Week2;

import java.text.DecimalFormat;

public class Practice1 {
    public static void main(String[] args){
        String name = "Haeul Kim";
        double studentID = 2022048022;
        System.out.println("My name is \"" + name.toUpperCase() + "\"\nand my student ID is " + String.format("%.0f", studentID) + ".");
    }
}
