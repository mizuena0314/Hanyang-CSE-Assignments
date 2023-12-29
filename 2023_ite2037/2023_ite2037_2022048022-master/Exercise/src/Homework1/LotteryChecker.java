package Homework1;

public class LotteryChecker {
    private int[] original;
    private int[] picked;
    LotteryChecker(int[] win, int[] ticket){
        original = win;
        picked = ticket;
    }

    int matchCount = 0;
    boolean matchBonus = false;
    int getPlacement() {
        for (int i = 0; i < 6; i++) {
            if(original[6] == picked[i]){
                matchBonus = true;
            }
        }

        for(int i=0; i<6; i++){
            for(int j=0; j<6; j++){
                if(i!=j && picked[i] == original[j]){
                    matchCount++;
                }
            }
        }

        if(matchCount == 6 || (matchCount==5 && matchBonus)){
            return 1;
        }
        else if(matchCount==5 || (matchCount==4 && matchBonus)){
            return 2;
        }
        else if(matchCount==4){
            return 3;
        }
        else if(matchCount==3){
            return 4;
        }
        else return -1;
    }
}
