package Homework2;

import java.util.ArrayList;

public class Warehouse {

    int ID;
    private double X, Y;
    private ArrayList<Cargo> cargoes = new ArrayList<>();
    private ArrayList<Truck> history = new ArrayList<>();
    private ArrayList<Truck> current = new ArrayList<>();
    public Warehouse(int id, double x, double y){
        ID = id;
        X = x;
        Y = y;
    }

    public double getDistance(Warehouse other){
        return Math.sqrt((other.X-this.X)*(other.X-this.X)+(other.Y-this.Y)*(other.Y-this.Y));
    }

    void addCargo(Cargo c){
        cargoes.add(c);
    }
    void removeCargo(Cargo c){
        cargoes.remove(c);
    }

    boolean hasCargo(Cargo c){
        return cargoes.contains(c);
    }
    void incomingTruck(Truck t){
        current.add(t);
    }
    void outgoingTruck(Truck t){
        history.add(t);
        current.remove(t);
    }

    public ArrayList<Cargo> getCargoes() {
        return cargoes;
    }

    public ArrayList<Truck> getCurrent() {
        return current;
    }

    public ArrayList<Truck> getHistory() {
        return history;
    }

    public double getX() {
        return X;
    }

    public double getY() {
        return Y;
    }
}
