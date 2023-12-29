package Homework3;

public class ClubContact extends ContactInfo{
    private String club;

    public ClubContact(String _name, String _number, String _club){
        super(_name, _number);
        club = _club;
    }

    public String getClub() {
        return club;
    }

    public void setClub(String club) {
        this.club = club;
    }

    @Override
    public String toString(){
        return "name: " + super.getName() +  " / " + "phone number: " + super.getPhoneNumber() + " / " + "club name: " + club;
    }
    @Override
    public String getInfo() {
        return this.toString();
    }
}
