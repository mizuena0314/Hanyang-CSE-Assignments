package Homework2;

public class HeavyCargo extends Cargo{
    public HeavyCargo(int id, double weight){
        super(id, weight);
    }

    @Override
    public double consumption() {
        return 2.5;
    }
}
