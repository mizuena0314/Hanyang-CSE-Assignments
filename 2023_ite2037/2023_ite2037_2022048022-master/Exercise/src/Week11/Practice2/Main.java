package Week11.Practice2;

import java.util.Scanner;

public class Main {

    public static void main(String[] args){
        String id="";
        int num=0;
        int balance=0;

        Scanner in = new Scanner(System.in);

        while(true){
            System.out.println("Input account details:");
            boolean flgID = true;
            boolean flgAcc = true;
            boolean flgBal = true;
            try {
                id = in.next();
                if (id.length() != 4 || !(
                        (((id.charAt(0) >= 'a') && (id.charAt(0) <= 'z'))
                                || (((id.charAt(0)) >= 'A') && (id.charAt(0) <= 'Z')))
                                && (id.charAt(1) >= '0' && id.charAt(1) <= '9')
                                && (id.charAt(2) >= '0' && id.charAt(2) <= '9')
                                && (id.charAt(3) >= '0' && id.charAt(3) <= '9')

                )) {
                    throw (new Exception("id format incorrect"));
                }
            }
            catch(Exception e){
                System.out.println(e.getMessage());
                flgID = false;
            }
            try{
                num = in.nextInt();
                if(num<10000 || num>99999){
                    throw(new Exception("num is out of range (must be 5 digits)"));
                }
            }
            catch(Exception e){
                System.out.println(e.getMessage());
                flgAcc = false;
            }
            try{
                balance = in.nextInt();
                if(balance<=1000){
                    throw(new Exception("initial balance must be above 1000"));
                }
            }
            catch(Exception e){
                System.out.println(e.getMessage());
                flgBal = false;
            }

            if(flgID && flgAcc && flgBal){
                Account acc = new Account(id, num, balance);
                System.out.println(acc.toString());
                System.exit(0);
            }
        }
    }
}
