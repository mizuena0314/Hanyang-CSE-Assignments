package Homework2;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        int truckCount = -1;
        int cargoCount = -1;
        int wareCount = -1;

        ArrayList<Warehouse> warehouseList = new ArrayList<>();
        ArrayList<Truck> truckList = new ArrayList<>();
        ArrayList<Cargo> cargoList = new ArrayList<>();

        // Generate a new Scanner object to access data from the input file in the directory indicated by "args[0]".
        Scanner in = new Scanner(new File(args[0]));


        // Your Implementation
        int N = Integer.parseInt(in.nextLine());

        for(int i=0; i<N; i++){
            String query = in.nextLine();
            StringTokenizer stk = new StringTokenizer(query);
            int type = Integer.parseInt(stk.nextToken());
            if(type == 1){
                int warehouse = Integer.parseInt(stk.nextToken());
                double weight = Double.parseDouble(stk.nextToken());
                if(stk.hasMoreTokens()){
                    String DL = stk.nextToken();
                    if(DL.equals("D")){
                        DangerousCargo c = new DangerousCargo(cargoCount+1, weight);
                        if(warehouse <= wareCount && weight>0){
                            Warehouse tmp = warehouseList.get(warehouse);
                            tmp.addCargo(c);
                            warehouseList.set(warehouse, tmp);
                            cargoCount++;
                            cargoList.add(c);
                        }
                    }
                    if(DL.equals("L")){
                        LiquidCargo c = new LiquidCargo(cargoCount+1, weight);
                        if(warehouse <= wareCount && weight>0){
                            Warehouse tmp = warehouseList.get(warehouse);
                            tmp.addCargo(c);
                            warehouseList.set(warehouse, tmp);
                            cargoCount++;
                            cargoList.add(c);
                        }
                    }
                }
                else{
                    if(weight<=1000){
                        BasicCargo c = new BasicCargo(cargoCount+1, weight);
                        if(warehouse <= wareCount && weight>0){
                            Warehouse tmp = warehouseList.get(warehouse);
                            tmp.addCargo(c);
                            warehouseList.set(warehouse, tmp);
                            cargoCount++;
                            cargoList.add(c);
                        }
                    }
                    else{
                        HeavyCargo c = new HeavyCargo(cargoCount+1, weight);
                        if(warehouse <= wareCount && weight>0){
                            Warehouse tmp = warehouseList.get(warehouse);
                            tmp.addCargo(c);
                            warehouseList.set(warehouse, tmp);
                            cargoCount++;
                            cargoList.add(c);
                        }
                    }
                }
            }
            if(type==2){
                int warehouse = Integer.parseInt(stk.nextToken());
                int maxW = Integer.parseInt(stk.nextToken());
                int maxAll = Integer.parseInt(stk.nextToken());
                int maxHeavy = Integer.parseInt(stk.nextToken());
                int maxD = Integer.parseInt(stk.nextToken());
                int maxL = Integer.parseInt(stk.nextToken());
                double fPKM = Double.parseDouble(stk.nextToken());
                if(warehouse<=wareCount){
                    Warehouse tmp = warehouseList.get(warehouse);
                    Truck t = new Truck(warehouse, warehouseList.get(warehouse), maxW, maxAll, maxHeavy, maxD, maxL, fPKM);
                    truckCount++;
                    truckList.add(t);
                }
            }
            if(type==3){
                double x, y;
                x = Double.parseDouble(stk.nextToken());
                y = Double.parseDouble(stk.nextToken());
                wareCount++;
                Warehouse w = new Warehouse(wareCount, x, y);
                warehouseList.add(w);
            }
            if(type==4){
                int truckID, cargoID;
                truckID = Integer.parseInt(stk.nextToken());
                cargoID = Integer.parseInt(stk.nextToken());
                if(truckList.get(truckID).getCurrentWarehouse().hasCargo(cargoList.get(cargoID))){
                    Truck tmp = truckList.get(truckID);
                    tmp.load(cargoList.get(cargoID));
                    truckList.set(truckID, tmp);
                }
            }
            if(type==5){
                int truckID, cargoID;
                truckID = Integer.parseInt(stk.nextToken());
                cargoID = Integer.parseInt(stk.nextToken());
                Truck tmp = truckList.get(truckID);
                tmp.unload(cargoList.get(cargoID));
                truckList.set(truckID, tmp);
            }
            if(type==6){
                int truckID, warehouseID;
                truckID = Integer.parseInt(stk.nextToken());
                warehouseID = Integer.parseInt(stk.nextToken());
                Truck tmp = truckList.get(truckID);
                tmp.sailTo(warehouseList.get(warehouseID));
            }
            if(type==7){
                int truckID;
                double addFuel;
                truckID = Integer.parseInt(stk.nextToken());
                addFuel = Double.parseDouble(stk.nextToken());
                Truck tmp = truckList.get(truckID);
                tmp.reFuel(addFuel);
            }
        }
        // Close the Scanner object.
        in.close();

        // Generate a new PrintStream object to output data to the file in the directory indicated by "args[1]"
        PrintStream out = new PrintStream(new File(args[1]));

        // Print the string to the output file.
        for(int i=0; i<warehouseList.size(); i++){
            Warehouse w = warehouseList.get(i);
            out.printf("Warehouse %d:(%.1f, %.1f)\n", i, w.getX(), w.getY());

            ArrayList<Cargo>tempCar = w.getCargoes();
            Cargo.sort(tempCar);

            out.printf("  BasicCargo: ");

            for(int j=0; j< tempCar.size(); j++){
                if(tempCar.get(j) instanceof BasicCargo){
                    out.printf("%d ", j);
                }
            }
            out.println();
            out.printf("  HeavyCargo: ");

            for(int j=0; j< tempCar.size(); j++){
                if(tempCar.get(j) instanceof HeavyCargo){
                    out.printf("%d ", j);
                }
            }
            out.println();
            out.printf("  DangerousCargo: ");

            for(int j=0; j< tempCar.size(); j++){
                if(tempCar.get(j) instanceof DangerousCargo){
                    out.printf("%d ", j);
                }
            }
            out.println();
            out.printf("  LiquidCargo: ");

            for(int j=0; j< tempCar.size(); j++){
                if(tempCar.get(j) instanceof LiquidCargo){
                    out.printf("%d ", j);
                }
            }
            out.println();

            ArrayList<Truck>tempTr = w.getCurrent();
            Collections.sort(tempTr);
            for(int k=0; k<tempTr.size(); k++){
                out.printf("  Truck %d: %.1f\n", k, tempTr.get(k).getFuel());
                out.printf("    BasicCargo: ");
                ArrayList<Cargo> tmpCar = tempTr.get(k).getCurrentCargoes();
                Cargo.sort(tmpCar);
                for(int j=0; j< tmpCar.size(); j++){
                    if(tmpCar.get(j) instanceof BasicCargo){
                        out.printf("%d ", j);
                    }
                }
                out.println();
                out.printf("    HeavyCargo: ");

                for(int j=0; j< tmpCar.size(); j++){
                    if(tmpCar.get(j) instanceof HeavyCargo){
                        out.printf("%d ", j);
                    }
                }
                out.println();
                out.printf("    DangerousCargo: ");

                for(int j=0; j< tmpCar.size(); j++){
                    if(tmpCar.get(j) instanceof DangerousCargo){
                        out.printf("%d ", j);
                    }
                }
                out.println();
                out.printf("    LiquidCargo: ");

                for(int j=0; j< tmpCar.size(); j++){
                    if(tmpCar.get(j) instanceof LiquidCargo){
                        out.printf("%d ", j);
                    }
                }
                out.println();
            }
        }

        // Close the PrintStream object.
        out.close();
    }
}
