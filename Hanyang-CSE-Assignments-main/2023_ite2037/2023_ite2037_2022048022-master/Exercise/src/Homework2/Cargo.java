package Homework2;

import java.util.ArrayList;
import java.util.Collections;

public abstract class Cargo implements Comparable<Cargo>{
    private int ID;
    private double weight;
    public Cargo(int id, double w){
        ID = id;
        weight = w;
    }
    public abstract double consumption();
    public double getWeight(){
        return weight;
    }
    public int getID(){
        return ID;
    }
    public static void sort(ArrayList<Cargo> arr){
        Collections.sort(arr);
    }
    @Override
    public int compareTo(Cargo cargo){
        return cargo.getID()-this.getID();
    }
}
