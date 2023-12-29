package Homework3;

import java.util.ArrayList;
import java.io.*;
import java.util.Iterator;
import java.util.Scanner;

public class CommandLineInterface{

    private Scanner scanner;
    public CommandLineInterface(){
        scanner = new Scanner(System.in);
    }

    public int getMainMenu(){
        System.out.println("----<Main Menu>----");
        System.out.println("1. Set size of total contacts");
        System.out.println("2. Save the current contact to a file");
        System.out.println("3. Load the saved contact file");
        System.out.println("4. Register new contact");
        System.out.println("5. Search contact");
        System.out.println("6. Delete contact");
        System.out.println("7. Edit contact");
        System.out.println("8. View All Contacts");
        System.out.println("9. Exit");
        System.out.printf("Select: ");

        int command = scanner.nextInt();

        return command;
    }

    public int getSetSizeMenu(){
        System.out.println("Set storage size...");
        System.out.println("0 for inf, positive integer value otherwise");

        int size = scanner.nextInt();

        return size;
    }

    public void printErrorMessage(String message){
        System.out.println(message);
    }

    public String getCreateContactMenu(){
        try {
            System.out.println("Create contact...");
            System.out.println("1. Normal contact");
            System.out.println("2. Club contact");
            System.out.println("3. Department contact");
            System.out.printf("Select: ");

            int contactType = scanner.nextInt();

            if (contactType < 1 || contactType > 3) {
                throw new MenuChoiceException(contactType);
            }

            String name, phone, thirdParameter;

            System.out.println("Input Name:");
            name = scanner.next();

            System.out.println("Input phone number:");
            phone = scanner.next();

            if (phone.length() != 13) {
                return "FAIL";
            }
            else if(!(phone.substring(0,3).equals("010")) || phone.charAt(3)!='-' || phone.charAt(8)!='-'){
                return "FAIL";
            }
            else{
                for(int i=4; i<8; i++){
                    if(phone.charAt(i)<'0' || phone.charAt(i)>'9'){
                        return "FAIL";
                    }
                }
                for(int i=9; i<13; i++){
                    if(phone.charAt(i)<'0' || phone.charAt(i)>'9'){
                        return "FAIL";
                    }
                }
            }

            if (contactType == 1) {
                System.out.println("Input relation:");
            }
            if (contactType == 2) {
                System.out.println("Input club:");
            }
            if (contactType == 3) {
                System.out.println("Input department:");
            }

            thirdParameter = scanner.next();

            return contactType + " " + name + " " + phone + " " + thirdParameter;
        }
        catch(MenuChoiceException e){
            printErrorMessage(e.getMessage());
            return "FAILMENU";
        }
    }

    public String getSearchContactMenu(){
        try {
            System.out.println("Search contact...");
            System.out.println("Choose the variable:");
            System.out.println("1. Name");
            System.out.println("2. Phone number");
            System.out.println("3. Relation");
            System.out.println("4. Club");
            System.out.println("5. Department");
            System.out.printf("Select: ");
            int choice = scanner.nextInt();

            if(choice<1 || choice>5) throw new MenuChoiceException(choice);

            if(choice==1){
                System.out.println("Enter name to search:");
                String name = scanner.next();
                return choice + " " + name;
            }
            if(choice==2){
                System.out.println("Enter phone number to search:");
                String phone = scanner.next();
                if (phone.length() != 13) {
                    return "FAIL";
                }
                else if(!(phone.substring(0,3).equals("010")) || phone.charAt(3)!='-' || phone.charAt(8)!='-'){
                    return "FAIL";
                }
                else{
                    for(int i=4; i<8; i++){
                        if(phone.charAt(i)<'0' || phone.charAt(i)>'9'){
                            return "FAIL";
                        }
                    }
                    for(int i=9; i<13; i++){
                        if(phone.charAt(i)<'0' || phone.charAt(i)>'9'){
                            return "FAIL";
                        }
                    }
                }
                return choice + " " + phone;
            }
            if(choice==3){
                System.out.println("Enter relation to search:");
                String relation = scanner.next();
                return choice + " " + relation;
            }
            if(choice==4){
                System.out.println("Enter club to search:");
                String club = scanner.next();
                return choice + " " + club;
            }
            if(choice==5){
                System.out.println("Enter department to search:");
                String department = scanner.next();
                return choice + " " + department;
            }
        }
        catch(MenuChoiceException e){
            printErrorMessage(e.getMessage());
            return "FAILMENU";
        }
        return null;
    }

    public String getDeleteContactMenu(){
        try {
            System.out.println("Delete contact...");
            System.out.println("Choose the variable:");
            System.out.println("1. Name");
            System.out.println("2. Phone number");
            System.out.println("3. Relation");
            System.out.println("4. Club");
            System.out.println("5. Department");
            System.out.printf("Select: ");
            int choice = scanner.nextInt();

            if(choice<1 || choice>5) throw new MenuChoiceException(choice);

            if(choice==1){
                System.out.println("Enter name to delete:");
                String name = scanner.next();
                return choice + " " + name;
            }
            if(choice==2){
                System.out.println("Enter phone number to delete:");
                String phone = scanner.next();
                if (phone.length() != 13) {
                    return "FAIL";
                }
                else if(!(phone.substring(0,3).equals("010")) || phone.charAt(3)!='-' || phone.charAt(8)!='-'){
                    return "FAIL";
                }
                else{
                    for(int i=4; i<8; i++){
                        if(phone.charAt(i)<'0' || phone.charAt(i)>'9'){
                            return "FAIL";
                        }
                    }
                    for(int i=9; i<13; i++){
                        if(phone.charAt(i)<'0' || phone.charAt(i)>'9'){
                            return "FAIL";
                        }
                    }
                }
                return choice + " " + phone;
            }
            if(choice==3){
                System.out.println("Enter relation to delete:");
                String relation = scanner.next();
                return choice + " " + relation;
            }
            if(choice==4){
                System.out.println("Enter club to delete:");
                String club = scanner.next();
                return choice + " " + club;
            }
            if(choice==5){
                System.out.println("Enter department to delete:");
                String department = scanner.next();
                return choice + " " + department;
            }
        }
        catch(MenuChoiceException e){
            printErrorMessage(e.getMessage());
            return "FAILMENU";
        }
        return null;
    }
    public String getEditContactMenu(){
        try {
            System.out.println("Edit contact...");
            System.out.println("Choose the variable:");
            System.out.println("1. Name");
            System.out.println("2. Phone number");
            System.out.println("3. Relation");
            System.out.println("4. Club");
            System.out.println("5. Department");
            System.out.printf("Select: ");
            int choice = scanner.nextInt();

            if(choice<1 || choice>5) throw new MenuChoiceException(choice);

            if(choice==1){
                System.out.println("Enter name to edit:");
                String name = scanner.next();
                System.out.println("Enter new name:");
                String newname = scanner.next();
                return choice + " " + name + " " + newname;
            }
            if(choice==2){
                System.out.println("Enter phone number to edit:");
                String phone = scanner.next();
                if (phone.length() != 13) {
                    return "FAIL";
                }
                else if(!(phone.substring(0,3).equals("010")) || phone.charAt(3)!='-' || phone.charAt(8)!='-'){
                    return "FAIL";
                }
                else{
                    for(int i=4; i<8; i++){
                        if(phone.charAt(i)<'0' || phone.charAt(i)>'9'){
                            return "FAIL";
                        }
                    }
                    for(int i=9; i<13; i++){
                        if(phone.charAt(i)<'0' || phone.charAt(i)>'9'){
                            return "FAIL";
                        }
                    }
                }

                System.out.println("Enter new phone number:");
                String newphone = scanner.next();
                if (newphone.length() != 13) {
                    return "FAIL";
                }
                else if(!(newphone.substring(0,3).equals("010")) || newphone.charAt(3)!='-' || newphone.charAt(8)!='-'){
                    return "FAIL";
                }
                else{
                    for(int i=4; i<8; i++){
                        if(newphone.charAt(i)<'0' || newphone.charAt(i)>'9'){
                            return "FAIL";
                        }
                    }
                    for(int i=9; i<13; i++){
                        if(newphone.charAt(i)<'0' || newphone.charAt(i)>'9'){
                            return "FAIL";
                        }
                    }
                }
                return choice + " " + phone + " " + newphone;
            }
            if(choice==3){
                System.out.println("Enter relation to edit:");
                String relation = scanner.next();
                System.out.println("Enter new relation:");
                String newrelation = scanner.next();
                return choice + " " + relation + " " + newrelation;
            }
            if(choice==4){
                System.out.println("Enter club to edit:");
                String club = scanner.next();
                System.out.println("Enter new club:");
                String newclub = scanner.next();
                return choice + " " + club + " " + newclub;
            }
            if(choice==5){
                System.out.println("Enter department to edit:");
                String department = scanner.next();
                System.out.println("Enter new department:");
                String newdepartment = scanner.next();
                return choice + " " + department + " " + newdepartment;
            }
        }
        catch(MenuChoiceException e){
            printErrorMessage(e.getMessage());
            return "FAILMENU";
        }
        return null;
    }

    public void printContactInfo(ArrayList<ContactInfo> list){
        Iterator<ContactInfo> it1 = list.iterator();
        Iterator<ContactInfo> it2 = list.iterator();
        Iterator<ContactInfo> it3 = list.iterator();

        System.out.println("Normal Contacts:");
        int matchCnt = 0;
        while(it1.hasNext()){
            ContactInfo cur = it1.next();
            if((cur instanceof NormalContact)){
                System.out.printf("   %d. ", ++matchCnt);
                System.out.println(cur.getInfo());
            }
        }
        if(matchCnt==0){
            System.out.println("   No matches found");
        }
        matchCnt=0;

        System.out.println("Club Contacts:");
        while(it2.hasNext()){
            ContactInfo cur = it2.next();
            if((cur instanceof ClubContact)){
                System.out.printf("   %d. ", ++matchCnt);
                System.out.println(cur.getInfo());
            }
        }
        if(matchCnt==0){
            System.out.println("   No matches found");
        }
        matchCnt = 0;

        System.out.println("Department Contacts:");
        while(it3.hasNext()){
            ContactInfo cur = it3.next();
            if((cur instanceof DepartmentContact)){
                System.out.printf("   %d. ", ++matchCnt);
                System.out.println(cur.getInfo());
            }
        }
        if(matchCnt==0){
            System.out.println("   No matches found");
        }
    }

    public ArrayList<String> readFile(){
        Scanner inputStream = null;
        ArrayList<String>tmp = new ArrayList<String>();
        try{
            inputStream = new Scanner(new FileInputStream("src/Homework3/ContactBook.txt"));

            while(inputStream.hasNextLine()){
                tmp.add(inputStream.nextLine());
            }

            inputStream.close();
            return tmp;
        }
        catch(FileNotFoundException e){
            System.out.println("Error! ContactBook not found!");
            tmp.add("FAIL");
            return tmp;
        }
    }
}
