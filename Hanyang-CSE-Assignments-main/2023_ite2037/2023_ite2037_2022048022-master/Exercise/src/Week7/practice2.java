package Week7;

import java.util.Scanner;
import java.util.Random;
public class practice2 {
    public static boolean[][] show(int x1, int y1, int x2, int y2, boolean[][] arr){
        boolean[][] ret = new boolean[4][4];
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(i==x1-1 && j==y1-1){
                    ret[i][j] = true;
                }
                else if(i==x2-1 && j==y2-1){
                    ret[i][j] = true;
                }
                else if(arr[i][j]) ret[i][j] = true;
                else ret[i][j] = false;
            }
        }
        return ret;
    }

    public static int[][] makeGrid(){

        int[][] ret = new int[4][4];
        int[] count = new int[9];
        for(int i=1; i<=8; i++) count[i] = 0;
        Random rnd = new Random();
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                while(true){

                    int tmp = rnd.nextInt(1, 9);
                    System.out.println(tmp);
                    if(count[tmp]<2){
                        ret[i][j] = tmp;
                        count[tmp]++;
                        break;
                    }
                }
            }
        }
        return ret;
    }

    public static void drawGrid(int[][] grid, boolean[][] updown){
        System.out.printf("    1   2   3   4\n");
        for(int i=0; i<4; i++){
            System.out.printf("%d", i+1);
            for(int j=0; j<4; j++){
                if(updown[i][j]){
                    System.out.printf("   %d", grid[i][j]);
                }
                else{
                    System.out.printf("   *");
                }
            }
            System.out.println();
        }
    }

    public static void main(String[] args){
        boolean[][] updown = new boolean[4][4];
        int[][] grid = makeGrid();
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++) updown[i][j] = false;
        }
        drawGrid(grid, updown);

        Scanner sc = new Scanner(System.in);

        while(true){
            int cnt = 0;
            for(int i=0; i<4; i++){
                for(int j=0; j<4; j++){
                    if(!updown[i][j]) cnt++;
                }
            }
            if(cnt == 0) break;

            System.out.printf("Enter Coordinate: ");
            int x1, y1, x2, y2;
            x1 = sc.nextInt();
            y1 = sc.nextInt();
            x2 = sc.nextInt();
            y2 = sc.nextInt();

            if(grid[x1-1][y1-1] == grid[x2-1][y2-1]){
                updown = show(x1, y1, x2, y2, updown);
                System.out.printf("%d == %d\n", grid[x1-1][y1-1], grid[x2-1][y2-1]);
            }
            else{
                System.out.printf("%d != %d\n", grid[x1-1][y1-1], grid[x2-1][y2-1]);
            }
            drawGrid(grid, updown);
            System.out.println();
        }
    }
}
