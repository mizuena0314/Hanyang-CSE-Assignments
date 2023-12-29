package Week9;

import Week6.Exercise1.Person;
import java.util.Date;
public class Patient extends Person {
    private String department;

    public Patient(String name, Date born, Date died, String department){
        super(name, born, died);
        this.department = department;
    }

    public String getDepartment(){
        return this.department;
    }

    public void setDepartment(String hospital){
        this.department = department;
    }

    @Override
    public String toString(){
        return "[Patient]" + super.toString() + "Affiliation : " + this.department;
    }

    public boolean equals(Patient p){
        return super.equals(p) && this.department.equals(p.department);
    }
}
