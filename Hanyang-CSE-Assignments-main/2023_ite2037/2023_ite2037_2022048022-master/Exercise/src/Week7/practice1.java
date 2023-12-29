package Week7;

import java.util.Scanner;
public class practice1 {
    public static int[][] drawSnail(int n){
        int[][] ret = new int[n][n];

        int val = 1;

        int strow = 0;
        int stcol = 0;
        int enrow = n;
        int encol = n;

        int it = n/2;

        for(int k=0; k<=it; k++){
            for(int j=stcol; j<encol; j++){
                ret[strow][j] = val;
                val++;
            }
            strow++;

            for(int i=strow; i<enrow; i++){
                ret[i][encol-1] = val;
                val++;
            }
            encol--;

            for(int j=encol-1; j>=stcol; j--){
                ret[enrow-1][j] = val;
                val++;
            }
            enrow--;

            for(int i=enrow-1; i>=strow; i--){
                ret[i][stcol] = val;
                val++;
            }
            stcol++;
        }

        return ret;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int snail[][] = drawSnail(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                System.out.printf("%d ", snail[i][j]);
            }
            System.out.println();
        }
    }
}
