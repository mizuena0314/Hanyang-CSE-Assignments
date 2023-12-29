package Week11.Practice1;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
    public static int gcd(int a, int b){
        if(b==0) return a;
        else return gcd(b, a%b);
    }
    public static boolean isCoprime(int a, int b) throws MyException {
        if(a==1 || b==1){
            throw new MyException("a or b is 1! please ensure both values are not 1");
        }
        else if (a>1000 || b>1000) {
            throw new MyException("a or b is above 1000! please ensure both values are less than or equal to 1000");
        }
        else if(a==b){
            throw new MyException("a is equal to b! please ensure a and b are not equal");
        }
        else{
            if(gcd(a,b)==1){
                return true;
            }
            else return false;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = 0;
        int b = 0;
        try {
            a = in.nextInt();
            b = in.nextInt();
        }
        catch(InputMismatchException e){
            System.out.println("input not of type int!");
            System.exit(0);
        }

        try{
            if(isCoprime(a, b)){
                System.out.println("a and b are coprime");
            }
            else System.out.println("a and b are not coprime");
        }
        catch(MyException e){
            System.out.println(e.getMessage());
        }
    }
}
