package Week13;

public class Calculator implements ComplexNumberCalculator, RealNumberCalculator{
    @Override
    public ComplexNumber.RealNumber add(ComplexNumber.RealNumber r1, ComplexNumber.RealNumber r2){
        return new ComplexNumber.RealNumber((r1.getDividend()*r2.getDivisor()) + (r1.getDivisor()*r2.getDividend()), r1.getDivisor()*r2.getDivisor());
    }
    public ComplexNumber.RealNumber sub(ComplexNumber.RealNumber r1, ComplexNumber.RealNumber r2){
        return new ComplexNumber.RealNumber(r1.getDividend()*r2.getDivisor() - r1.getDivisor()*r2.getDividend(), r1.getDivisor()*r2.getDivisor());
    }
    public ComplexNumber.RealNumber mul(ComplexNumber.RealNumber r1, ComplexNumber.RealNumber r2){
        return new ComplexNumber.RealNumber(r1.getDividend()*r2.getDividend(), r1.getDivisor()*r2.getDivisor());
    }
    public ComplexNumber add(ComplexNumber c1, ComplexNumber c2){
        return new ComplexNumber(add(c1.getReal(), c2.getReal()), add(c1.getImaginary(),c2.getImaginary()));
    }
    public ComplexNumber sub(ComplexNumber c1, ComplexNumber c2){
        return new ComplexNumber(sub(c1.getReal(), c2.getReal()), sub(c1.getImaginary(),c2.getImaginary()));
    }
    public ComplexNumber mul(ComplexNumber c1, ComplexNumber c2){
        return new ComplexNumber(sub(mul(c1.getReal(), c2.getReal()), mul(c1.getImaginary(), c2.getImaginary())), add(mul(c1.getReal(), c2.getImaginary()),mul(c1.getImaginary(), c2.getReal())));
    }
}
