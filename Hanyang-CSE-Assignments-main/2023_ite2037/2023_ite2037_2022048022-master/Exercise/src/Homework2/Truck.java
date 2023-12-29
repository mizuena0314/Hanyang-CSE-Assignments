package Homework2;

import java.util.ArrayList;
import java.util.Collections;

public class Truck implements Comparable<Truck>{
    private int ID;
    private int totalW=0;
    private int maxCargo;
    private int maxHCargo;
    private int maxDCargo;
    private int maxLCargo;
    private double fPKM;
    private double fuel=0;
    private int currentNumOfCargoes = 0;
    private int currentNumOfHeavyCargoes = 0;
    private int currentNumOfDangerousCargoes = 0;
    private int currentNumOfLiquidCargoes = 0;
    private double cargoConsumption=0;
    ArrayList<Cargo> currentCargo = new ArrayList<>();
    Warehouse currentWarehouse;
    public Truck(int id, Warehouse w, int totalWeight, int maxNumOfAllCargoes, int maxNumofHeavyCargoes, int maxNumofDangerousCargoes, int maxNumofLiquidCargoes, double fuelPerKm){
        ID = id;
        currentWarehouse = w;
        totalW = totalWeight;
        maxCargo = maxNumOfAllCargoes;
        maxHCargo = maxNumofHeavyCargoes;
        maxDCargo = maxNumofDangerousCargoes;
        maxLCargo = maxNumofLiquidCargoes;
        fPKM = fuelPerKm;
    }

    ArrayList<Cargo> getCurrentCargoes(){
        Cargo.sort(currentCargo);
        return currentCargo;
    }
    boolean sailTo(Warehouse w){
        if(currentWarehouse.equals(w)) return false;
        double dist = currentWarehouse.getDistance(w);
        if(fuel - ((fPKM*dist)+cargoConsumption)<0) return false;
        else{
            currentWarehouse.outgoingTruck(this);
            currentWarehouse = w;
            fuel -= (fPKM*dist+cargoConsumption);
            currentWarehouse.incomingTruck(this);
            return true;
        }
    }

    void reFuel(double amount){
        if(amount > 0) fuel += amount;
    }
    boolean load(Cargo c){
        if(currentCargo.contains(c)==false && maxCargo>=totalW+c.getWeight()) {
            if(currentNumOfCargoes + 1 > maxCargo) return false;
            if (c instanceof HeavyCargo) {
                if (currentNumOfHeavyCargoes + 1 > maxHCargo) return false;
                if (c instanceof DangerousCargo) {
                    if (currentNumOfDangerousCargoes + 1 > maxDCargo) return false;
                    currentNumOfHeavyCargoes += 1;
                    currentNumOfDangerousCargoes += 1;
                }
                if (c instanceof LiquidCargo) {
                    if (currentNumOfLiquidCargoes + 1 < maxLCargo) return false;
                    currentNumOfHeavyCargoes += 1;
                    currentNumOfLiquidCargoes += 1;
                }
            }
            currentNumOfCargoes += 1;

            currentCargo.add(c);
            totalW += c.getWeight();
            cargoConsumption += c.consumption();
            currentWarehouse.removeCargo(c);
            return true;
        }
        else return false;
    }
    boolean unload(Cargo c){
        if(totalW - c.getWeight() < 0) return false;
        if(currentCargo.contains(c)==true){
            if(currentNumOfCargoes == 0) return false;
            if (c instanceof HeavyCargo) {
                if (currentNumOfHeavyCargoes==0) return false;
                if (c instanceof DangerousCargo) {
                    if (currentNumOfDangerousCargoes==0) return false;
                    currentNumOfHeavyCargoes -= 1;
                    currentNumOfDangerousCargoes -= 1;
                }
                if (c instanceof LiquidCargo) {
                    if (currentNumOfLiquidCargoes==0) return false;
                    currentNumOfHeavyCargoes -= 1;
                    currentNumOfLiquidCargoes -= 1;
                }
            }
            currentNumOfCargoes -= 1;
            cargoConsumption -= c.consumption();
            currentCargo.remove(c);
            currentWarehouse.addCargo(c);
            return true;
        }
        else return false;
    }

    public Warehouse getCurrentWarehouse(){
        return currentWarehouse;
    }

    public int getID(){
        return this.ID;
    }

    public double getFuel() {
        return fuel;
    }

    @Override
    public int compareTo(Truck truck){
        return truck.getID()-this.getID();
    }
}
