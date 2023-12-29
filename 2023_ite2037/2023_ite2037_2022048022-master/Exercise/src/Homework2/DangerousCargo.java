package Homework2;

public class DangerousCargo extends HeavyCargo{
    public DangerousCargo(int id, double weight){
        super(id, weight);
    }

    @Override
    public double consumption() {
        return 4.0;
    }
}
