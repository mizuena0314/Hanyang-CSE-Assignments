package Week9;

import Week6.Exercise1.Person;
import java.util.Date;
public class Physician extends Doctor {
    private String hospital;

    public Physician(String name, Date born, Date died, String hospital){
        super(name, born, died, hospital);
    }

    @Override
    public void examination(Patient P){
        if(P.getDepartment().equals("internal"))System.out.println("I'll take care of you!");
        else System.out.println("Sorry, but it's not my major");
    }
}
