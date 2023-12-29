package Homework3;

public class DepartmentContact extends ContactInfo{
    private String department;

    public DepartmentContact(String _name, String _number, String _department){
        super(_name, _number);
        department = _department;
    }

    public String getDepartment() {
        return department;
    }

    public void setDepartment(String department) {
        this.department = department;
    }

    @Override
    public String toString(){
        return "name: " + super.getName() +  " / " + "phone number: " + super.getPhoneNumber() + " / " + "department: " + department;
    }
    @Override
    public String getInfo() {
        return this.toString();
    }
}
