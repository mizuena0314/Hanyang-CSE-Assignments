package Homework3;

public class MenuChoiceException extends Exception{
    public MenuChoiceException(int choice){
        super("Invalid menu choice of " + choice + "! Please select a valid menu.");
    }
}
