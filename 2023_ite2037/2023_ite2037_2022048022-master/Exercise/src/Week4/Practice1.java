package Week4;

import java.util.Scanner;
public class Practice1 {
    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);
        System.out.println("Input string S:");
        String s = keyboard.nextLine();

        String ans = "";
        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                String tmp = "";
                for(int k=i; k<=j; k++){
                    tmp = tmp + s.charAt(k);
                }

                boolean isPalin = true;
                int l = 0;
                int r = tmp.length()-1;

                while(l<r){
                    if(tmp.charAt(l) != tmp.charAt(r)){
                        isPalin = false;
                        break;
                    }
                    l++;
                    r--;
                }

                if(isPalin){
                    if(tmp.length() > ans.length()){
                        ans = tmp;
                    }
                }
            }
        }

        System.out.println("Longest Palindrome: " + ans);
    }
}
