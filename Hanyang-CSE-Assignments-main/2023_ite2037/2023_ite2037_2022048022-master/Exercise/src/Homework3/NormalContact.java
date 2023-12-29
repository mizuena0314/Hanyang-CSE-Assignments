package Homework3;

public class NormalContact extends ContactInfo{
    private String relation;

    public NormalContact(String _name, String _number, String _relation){
        super(_name, _number);
        relation = _relation;
    }

    public String getRelation() {
        return relation;
    }

    public void setRelation(String relation) {
        this.relation = relation;
    }

    @Override
    public String toString(){
        return "name: " + super.getName() +  " / " + "phone number: " + super.getPhoneNumber() + " / " + "relation: " + relation;
    }
    @Override
    public String getInfo() {
        return this.toString();
    }
}
