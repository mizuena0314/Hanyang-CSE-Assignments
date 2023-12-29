package Week13;

public class ComplexNumber {
    public static class RealNumber{
        private int dividend;
        private int divisor;
        public RealNumber(int num, int den){
            dividend = num;
            divisor = den;
        }

        public int getDividend() {
            return dividend;
        }

        public int getDivisor() {
            return divisor;
        }

        @Override
        public String toString(){
            return this.dividend + "/" + this.divisor;
        }
    }

    private RealNumber real;
    private RealNumber imaginary;
    public ComplexNumber(RealNumber r1, RealNumber i1){
        real = r1;
        imaginary = i1;
    }

    public RealNumber getReal() {
        return real;
    }

    public RealNumber getImaginary() {
        return imaginary;
    }
}
