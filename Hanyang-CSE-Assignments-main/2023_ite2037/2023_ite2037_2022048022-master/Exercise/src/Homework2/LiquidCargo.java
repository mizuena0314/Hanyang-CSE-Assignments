package Homework2;

public class LiquidCargo extends HeavyCargo{
    public LiquidCargo(int id, double weight){
        super(id, weight);
    }

    @Override
    public double consumption() {
        return 3.5;
    }
}
