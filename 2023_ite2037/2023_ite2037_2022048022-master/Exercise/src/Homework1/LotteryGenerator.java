package Homework1;

import java.util.Random;
public class LotteryGenerator {

    Random rnd = new Random();
    private int[] num = new int[7];
    LotteryGenerator() {
        for (int i = 0; i < 7; i++) {
            while (true) {
                this.num[i] = rnd.nextInt(1,20);
                boolean flg = true;
                for (int j = 0; j < i; j++) {
                    if (this.num[i] == this.num[j]) {
                        flg = false;
                    }
                }
                if (flg) {
                    break;
                }
            }
        }
    }

    int[] getTicket(){
        return num;
    }
}
