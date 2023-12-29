package Week14.Practice2;

import java.util.ArrayList;
import java.util.Collections;

class PriorityQueue <T>{
    ArrayList<T> data = new ArrayList<>();
    ArrayList<Integer> p = new ArrayList<>();
    public void add(T item, int priority){
        data.add(item);
        p.add(priority);

        int sz = data.size();

        for(int idx = (sz+1)/2-1; idx>=0; idx--){
            boolean flg1 = idx*2<sz && p.get(idx) < p.get(idx*2);
            boolean flg2 = idx*2+1<sz && p.get(idx) < p.get(idx*2+1);

            if(flg1 && flg2){
                if(p.get(idx*2) < p.get(idx*2+1)){
                    Collections.swap(p, idx*2+1, idx);
                    Collections.swap(data, idx*2+1, idx);
                }
                else{
                    Collections.swap(p, idx*2, idx);
                    Collections.swap(data, idx*2, idx);
                }
            }
            else if(flg1){
                Collections.swap(p, idx*2, idx);
                Collections.swap(data, idx*2, idx);
            }
            else if(flg2){
                Collections.swap(p, idx*2+1, idx);
                Collections.swap(data, idx*2+1, idx);
            }
        }
    }

    public T remove(){

        if(data.size()==0){
            return null;
        }

        T ret = data.get(0);
        data.remove(0);
        p.remove(0);

        int sz = data.size();

        for(int idx = (sz+1)/2-1; idx>=0; idx--){
            boolean flg1 = idx*2<sz && p.get(idx) < p.get(idx*2);
            boolean flg2 = idx*2+1<sz && p.get(idx) < p.get(idx*2+1);

            if(flg1 && flg2){
                if(p.get(idx*2) < p.get(idx*2+1)){
                    Collections.swap(p, idx*2+1, idx);
                    Collections.swap(data, idx*2+1, idx);
                }
                else{
                    Collections.swap(p, idx*2, idx);
                    Collections.swap(data, idx*2, idx);
                }
            }
            else if(flg1){
                Collections.swap(p, idx*2, idx);
                Collections.swap(data, idx*2, idx);
            }
            else if(flg2){
                Collections.swap(p, idx*2+1, idx);
                Collections.swap(data, idx*2+1, idx);
            }
        }

        return ret;
    }

}
