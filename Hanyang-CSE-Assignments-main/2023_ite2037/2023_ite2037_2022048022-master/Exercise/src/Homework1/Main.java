package Homework1;

import java.util.Scanner;
public class Main {
    public static void main(String[] args){
        int funds = 0;
        int tickets = 0;
        Scanner sc = new Scanner(System.in);
        while(true){
            boolean flg = false;
            int money, toBuy;

            while(true){
                System.out.println("Input your money and number of lottery tickets:");
                System.out.printf("<<");
                money = sc.nextInt();
                toBuy = sc.nextInt();
                if(money==0 || toBuy==0){
                    flg = true;
                    break;
                }
                else if(funds+money>=toBuy*10 && (tickets==0 || toBuy<=tickets)){
                    break;
                }
            }

            funds += money;
            funds -= toBuy*10;
            tickets += toBuy;

            if(flg) break;

            int first=0, second=0, third=0, fourth=0;
            LotteryGenerator winningTicket = new LotteryGenerator();
            int[] winningNum = winningTicket.getTicket();

            System.out.printf(">>Round Winning number : %d %d %d %d %d %d + %d\n", winningNum[0], winningNum[1], winningNum[2], winningNum[3], winningNum[4], winningNum[5], winningNum[6]);

            for(int i=0; i<toBuy; i++){
                LotteryGenerator boughtTicket = new LotteryGenerator();
                int[] currentTicket = boughtTicket.getTicket();
                LotteryChecker checker = new LotteryChecker(winningNum, currentTicket);

                int placement = checker.getPlacement();

                System.out.printf(">>Lottery number : %d %d %d %d %d %d ", currentTicket[0], currentTicket[1], currentTicket[2], currentTicket[3], currentTicket[4], currentTicket[5]);
                if(placement==-1){
                    System.out.printf("Lose\n");
                }
                else{
                    if(placement==1){
                        System.out.printf("Winner (1st place)\n");
                        first++;
                    }
                    if(placement==2){
                        System.out.printf("Winner (2nd place)\n");
                        second++;
                    }
                    if(placement==3){
                        System.out.printf("Winner (3rd place)\n");
                        third++;
                    }
                    if(placement==4){
                        System.out.printf("Winner (4th place)\n");
                        fourth++;
                    }
                }
            }
            System.out.printf(">>Remaining money : %d\n", funds);
            System.out.printf(">>1st place : %d\n", first);
            System.out.printf(">>2nd place : %d\n", second);
            System.out.printf(">>3rd place : %d\n", third);
            System.out.printf(">>4th place : %d\n", fourth);
            System.out.println();
        }
        System.out.println(">>End of program");
    }
}
