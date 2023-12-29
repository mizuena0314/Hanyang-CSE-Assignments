package Week14.Practice1;

import java.util.ArrayList;

public class Eratos {
    public static ArrayList<Integer> sieve(int n){
        ArrayList<Integer> ret = new ArrayList<>();
        boolean[] isPrime = new boolean[n+1];
        for(int i=2; i<=n; i++) isPrime[i] = true;

        for(int i=2; i*i<=n; i++){
            if(isPrime[i]){
                int cur = i;
                while(true){
                    cur += i;
                    if(cur > n){
                        break;
                    }
                    if(!isPrime[cur]){
                        continue;
                    }
                    isPrime[cur] = false;
                }
            }
        }

        for(int i=2; i<=n; i++){
            if(isPrime[i]) ret.add(i);
        }

        return ret;
    }
}
