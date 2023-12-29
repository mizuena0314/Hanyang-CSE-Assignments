package Homework2;

public class BasicCargo extends Cargo{
    public BasicCargo(int id, double weight){
        super(id, weight);
    }

    @Override
    public double consumption() {
        return 1.5;
    }
}
