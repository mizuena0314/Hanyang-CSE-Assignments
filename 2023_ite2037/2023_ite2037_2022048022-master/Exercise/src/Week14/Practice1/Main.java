package Week14.Practice1;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.print("Input max number: ");
        int n = sc.nextInt();

        ArrayList<Integer> ans = Eratos.sieve(n);
        Iterator<Integer> itr = ans.iterator();

        while(itr.hasNext()){
            int tmp = itr.next();
            System.out.printf("%d ", tmp);
        }
    }
}
