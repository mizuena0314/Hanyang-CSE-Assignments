package Homework3;

public abstract class ContactInfo {
    private String name;
    private String phoneNumber;

    public ContactInfo(String _name, String _number){
        name = _name;
        phoneNumber = _number;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public abstract String getInfo();

    @Override
    public abstract String toString();
}
