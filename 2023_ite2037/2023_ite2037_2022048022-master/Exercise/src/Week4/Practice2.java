package Week4;

import java.util.Scanner;
import java.util.Random;
public class Practice2 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Random rnd = new Random();

        int compSc = 0;
        int humanSc = 0;

        int turn = 0;
        while(humanSc < 100 && compSc < 100){
            int tmp = 0;
            if(turn % 2 == 0){
                System.out.print("(You) insert action r(roll) : ");
                String act;
                act = sc.nextLine();
                int roll;
                while(true){
                    roll = rnd.nextInt(7);
                    if(roll!=0){
                        break;
                    }
                }
                System.out.printf("(You) dice rolled : %d\n", roll);
                if(roll == 1){
                    turn++;
                    System.out.println("(You) No score added");
                    System.out.printf("(You) Your score %d, Computer score %d\n", humanSc, compSc);
                }
                else{
                    tmp = tmp + roll;
                    while(true) {
                        System.out.print("(You) insert action r(roll), h(hold) : ");
                        act = sc.nextLine();
                        if(act.equals("h")){
                            turn++;
                            System.out.printf("(You) %d added to You\n", tmp);
                            humanSc = humanSc + tmp;
                            System.out.printf("(You) Your score %d, Computer score %d\n", humanSc, compSc);
                            break;
                        }
                        else if(act.equals("r")){
                            while(true){
                                roll = rnd.nextInt(7);
                                if(roll!=0){
                                    break;
                                }
                            }
                            System.out.printf("(You) dice rolled : %d\n", roll);
                            if(roll == 1){
                                turn++;
                                System.out.println("(You) No score added");
                                System.out.printf("(You) Your score %d, Computer score %d\n", humanSc, compSc);
                                break;
                            }
                            tmp = tmp + roll;
                        }
                    }
                }
            }
            else{
                while(tmp < 20) {
                    System.out.println("(Computer) insert action r(roll) : r");
                    int roll;
                    while(true){
                        roll = rnd.nextInt(7);
                        if(roll!=0){
                            break;
                        }
                    }
                    System.out.printf("(Computer) dice rolled : %d\n", roll);
                    if(roll == 1){
                        System.out.println("(Computer) No score added");
                        turn++;
                        break;
                    }
                    tmp = tmp + roll;
                }
                if(tmp >= 20) {
                    turn++;
                    compSc = compSc + tmp;
                    System.out.printf("(Computer) %d added to Computer\n", tmp);
                }
                System.out.printf("(Computer) Your score %d, Computer score %d\n", humanSc, compSc);
            }
            System.out.println();
        }
        if(humanSc >= 100){
            System.out.printf("(Game) Your score %d, Computer score %d\n", humanSc, compSc);
            System.out.println("Congratulations! You win!");
        }
        else if(compSc >= 100){
            System.out.printf("(Game) Your score %d, Computer score %d\n", humanSc, compSc);
            System.out.println("Sorry, the computer wins.");
        }
    }
}
