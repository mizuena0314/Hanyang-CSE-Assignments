package Week11.Practice1;

public class MyException extends Exception{
    private String message;
    public MyException(String msg){
        super(msg);
        message = msg;
    }

    @Override
    public String getMessage(){
        return message;
    }
}
