package Week12;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class BinarySearch {
    public static int BinSearch(int[] a, int st, int en, int x){
        if(st<=en){
            int mid = (int) Math.floor((st+en)/2);
            if(a[mid]==x){
                return mid;
            }
            if(a[mid]>x){
                return BinSearch(a, st, mid-1, x);
            }
            if(a[mid]<x){
                return BinSearch(a, mid+1, en, x);
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner inputStream = null;
        try {
            inputStream = new Scanner(new FileInputStream("src/input.txt"));
        } catch (FileNotFoundException e) {
            System.out.println("input.txt was not found");
        }

        int[] target = new int[100];
        int[] num = new int[100000];

        for(int i=0; i<100; i++){
            target[i] = inputStream.nextInt();
        }

        for(int i=0; i<100000; i++){
            num[i] = inputStream.nextInt();
        }

        for(int i=0; i<100; i++){
            System.out.printf("target: %d   index: %d\n", target[i], BinSearch(num, 0, 99999, target[i]));
        }
    }
}
