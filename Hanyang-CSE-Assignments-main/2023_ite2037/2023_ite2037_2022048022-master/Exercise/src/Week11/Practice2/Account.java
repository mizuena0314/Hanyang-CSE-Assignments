package Week11.Practice2;

public class Account {
    private String ID;
    private int account_num;
    private int balance;

    public Account(String id, int num, int bal){
        ID = id;
        account_num = num;
        balance = bal;
    }
    @Override
    public String toString() {
        return ("ID:" + ID + " account_num: " + account_num + " balance: $" + balance);
    }
}
