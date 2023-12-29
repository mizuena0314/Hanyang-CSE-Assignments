package Homework3;

import java.io.*;
import java.util.ArrayList;
import java.util.Iterator;

public class ContactManager {

    MyStorage<ContactInfo> contactStorage;
    CommandLineInterface cli;

    public ContactManager(CommandLineInterface _cli) {
        cli = _cli;
        contactStorage = new MyStorage<ContactInfo>();
    }

    public class MyStorage<T extends ContactInfo> {
        private int capacity = -1; //0 is INF here (?) -1 means not set yet
        private int size = 0;
        private ArrayList<ContactInfo> list;

        public MyStorage(){
            this.capacity = -1;
            this.size = 0;
            list = new ArrayList<ContactInfo>();
        }

        public void setSize(int _size) {
            this.capacity = _size;
        }

        public void addToList(ContactInfo cI){
            list.add(cI);
        }

        public ArrayList<ContactInfo> getList(){
            return list;
        }

        public void incrementSize(){
            this.size++;
        }
        public void decrementSize(){
            this.size--;
        }

        public int getCapacity() {
            return capacity;
        }

        public int getSize() {
            return size;
        }
    }

    public void setStorageSize(){
        int size = cli.getSetSizeMenu();
        contactStorage.setSize(size);
    }

    public void createContact(){
        try {
            String contact = cli.getCreateContactMenu();
            if(contact=="FAIL"){
                throw new ContactException("Invalid phone number! Phone number must be of format 010-xxxx-xxxx");
            }
            if(contact == "FAILMENU"){
                throw new ContactException("Aborted! Invalid menu choice!");
            }
            if(this.contactStorage.size == this.contactStorage.capacity && this.contactStorage.capacity!=0){
                throw new ContactException("Error! Reached maximum contact storage capacity!");
            }
            if(this.contactStorage.capacity==-1){
                throw new ContactException("Error! Storage size not yet set!");
            }
            String part1="", part2="", part3="", part4="";
            int cnt = 1;
            for(int i=0; i<contact.length(); i++){
                if(contact.charAt(i)==' '){
                    cnt++;
                }
                else{
                    if(cnt==1){
                        part1 += contact.charAt(i);
                    }
                    if(cnt==2){
                        part2 += contact.charAt(i);
                    }
                    if(cnt==3){
                        part3 += contact.charAt(i);
                    }
                    if(cnt==4){
                        part4 += contact.charAt(i);
                    }
                }
            }
            int type = Integer.parseInt(part1);
            if(type==1){
                NormalContact nc = new NormalContact(part2, part3, part4);
                contactStorage.addToList(nc);
            }
            if(type==2){
                ClubContact cc = new ClubContact(part2, part3, part4);
                contactStorage.addToList(cc);
            }
            if(type==3){
                DepartmentContact dc = new DepartmentContact(part2, part3, part4);
                contactStorage.addToList(dc);
            }
            contactStorage.incrementSize();
        }
        catch(ContactException e){
            cli.printErrorMessage(e.getMessage());
        }
    }

    public void searchContact(){
        try {
            String query = cli.getSearchContactMenu();
            if (query == "FAIL") {
                throw new ContactException("Invalid phone number! Phone number must be of format 010-xxxx-xxxx");
            }
            if (query == "FAILMENU") {
                throw new ContactException("Aborted! Invalid menu choice!");
            }
            String part1 = "", part2 = "";
            int cnt = 1;
            for (int i = 0; i < query.length(); i++) {
                if (query.charAt(i) == ' ') {
                    cnt++;
                } else {
                    if (cnt == 1) {
                        part1 += query.charAt(i);
                    }
                    if (cnt == 2) {
                        part2 += query.charAt(i);
                    }
                }
            }
            int type = Integer.parseInt(part1);
            Iterator<ContactInfo> it1 = contactStorage.getList().iterator();
            Iterator<ContactInfo> it2 = contactStorage.getList().iterator();
            Iterator<ContactInfo> it3 = contactStorage.getList().iterator();
            int matchCnt = 0;
            System.out.println("List of Matching results...");
            if(type == 1) {
                System.out.println("Normal Contacts:");
                while(it1.hasNext()){
                    ContactInfo cur = it1.next();
                    if((cur instanceof NormalContact) && cur.getName().equals(part2)){
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
                    if((cur instanceof ClubContact) && cur.getName().equals(part2)){
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
                    if((cur instanceof DepartmentContact) && cur.getName().equals(part2)){
                        System.out.printf("   %d. ", ++matchCnt);
                        System.out.println(cur.getInfo());
                    }
                }
                if(matchCnt==0){
                    System.out.println("   No matches found");
                }
            }

            if(type == 2) {
                System.out.println("Normal Contacts:");
                while(it1.hasNext()){
                    ContactInfo cur = it1.next();
                    if((cur instanceof NormalContact) && cur.getPhoneNumber().equals(part2)){
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
                    if((cur instanceof ClubContact) && cur.getPhoneNumber().equals(part2)){
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
                    if((cur instanceof DepartmentContact) && cur.getPhoneNumber().equals(part2)){
                        System.out.printf("   %d. ", ++matchCnt);
                        System.out.println(cur.getInfo());
                    }
                }
                if(matchCnt==0){
                    System.out.println("   No matches found");
                }
            }

            if(type == 3) {
                System.out.println("Normal Contacts:");
                while(it1.hasNext()){
                    ContactInfo cur = it1.next();
                    if((cur instanceof NormalContact) && ((NormalContact) cur).getRelation().equals(part2)){
                        System.out.printf("   %d. ", ++matchCnt);
                        System.out.println(cur.getInfo());
                    }
                }
                if(matchCnt==0){
                    System.out.println("   No matches found");
                }
            }

            if(type == 4) {
                System.out.println("Club Contacts:");
                while(it2.hasNext()){
                    ContactInfo cur = it2.next();
                    if((cur instanceof ClubContact) && ((ClubContact) cur).getClub().equals(part2)){
                        System.out.printf("   %d. ", ++matchCnt);
                        System.out.println(cur.getInfo());
                    }
                }
                if(matchCnt==0){
                    System.out.println("   No matches found");
                }
            }

            if(type == 5) {
                System.out.println("Normal Contacts:");
                while(it3.hasNext()){
                    ContactInfo cur = it3.next();
                    if((cur instanceof DepartmentContact) && ((DepartmentContact) cur).getDepartment().equals(part2)){
                        System.out.printf("   %d. ", ++matchCnt);
                        System.out.println(cur.getInfo());
                    }
                }
                if(matchCnt==0){
                    System.out.println("   No matches found");
                }
            }
        }
        catch(ContactException e){
            cli.printErrorMessage(e.getMessage());
        }
    }

    public void deleteContact() {
        try {
            String query = cli.getDeleteContactMenu();
            if (query == "FAIL") {
                throw new ContactException("Invalid phone number! Phone number must be of format 010-xxxx-xxxx");
            }
            if (query == "FAILMENU") {
                throw new ContactException("Aborted! Invalid menu choice!");
            }
            String part1 = "", part2 = "";
            int cnt = 1;
            for (int i = 0; i < query.length(); i++) {
                if (query.charAt(i) == ' ') {
                    cnt++;
                } else {
                    if (cnt == 1) {
                        part1 += query.charAt(i);
                    }
                    if (cnt == 2) {
                        part2 += query.charAt(i);
                    }
                }
            }
            int type = Integer.parseInt(part1);
            Iterator<ContactInfo> it1 = contactStorage.getList().iterator();
            Iterator<ContactInfo> it2 = contactStorage.getList().iterator();
            Iterator<ContactInfo> it3 = contactStorage.getList().iterator();

            int matchCnt = 0;
            if (type == 1) {
                while (it1.hasNext()) {
                    ContactInfo cur = it1.next();
                    if ((cur.getName().equals(part2))) {
                        System.out.println("Deleted: ");
                        System.out.println(cur.getInfo());
                        matchCnt++;
                        it1.remove();
                        break;
                    }
                }
            }

            if (type == 2) {
                while (it1.hasNext()) {
                    ContactInfo cur = it1.next();
                    if ((cur.getPhoneNumber().equals(part2))) {
                        System.out.println("Deleted: ");
                        System.out.println(cur.getInfo());
                        matchCnt++;
                        it1.remove();
                        break;
                    }
                }
            }

            if (type == 3) {
                while (it1.hasNext()) {
                    ContactInfo cur = it1.next();
                    if ((cur instanceof NormalContact) && ((NormalContact) cur).getRelation().equals(part2)) {
                        System.out.println("Deleted: ");
                        System.out.println(cur.getInfo());
                        matchCnt++;
                        it1.remove();
                        break;
                    }
                }
            }

            if (type == 4) {
                while (it2.hasNext()) {
                    ContactInfo cur = it2.next();
                    if ((cur instanceof ClubContact) && ((ClubContact) cur).getClub().equals(part2)) {
                        System.out.println("Deleted: ");
                        System.out.println(cur.getInfo());
                        matchCnt++;
                        it2.remove();
                        break;
                    }
                }
            }

            if (type == 5) {
                while (it3.hasNext()) {
                    ContactInfo cur = it3.next();
                    if ((cur instanceof DepartmentContact) && ((DepartmentContact) cur).getDepartment().equals(part2)) {
                        System.out.println("Deleted: ");
                        System.out.println(cur.getInfo());
                        matchCnt++;
                        it3.remove();
                        break;
                    }
                }
            }
            if(matchCnt==0) throw new ContactException("No such contact found!");
            contactStorage.decrementSize();
        } catch (ContactException e) {
            cli.printErrorMessage(e.getMessage());
        }
    }

    public void editContact() {
        try {
            String query = cli.getEditContactMenu();
            if (query == "FAIL") {
                throw new ContactException("Invalid phone number! Phone number must be of format 010-xxxx-xxxx");
            }
            if (query == "FAILMENU") {
                throw new ContactException("Aborted! Invalid menu choice!");
            }
            String part1 = "", part2 = "", part3 = "";
            int cnt = 1;
            for (int i = 0; i < query.length(); i++) {
                if (query.charAt(i) == ' ') {
                    cnt++;
                } else {
                    if (cnt == 1) {
                        part1 += query.charAt(i);
                    }
                    if (cnt == 2) {
                        part2 += query.charAt(i);
                    }
                    if(cnt == 3){
                        part3 += query.charAt(i);
                    }
                }
            }
            int type = Integer.parseInt(part1);
            Iterator<ContactInfo> it1 = contactStorage.getList().iterator();
            Iterator<ContactInfo> it2 = contactStorage.getList().iterator();
            Iterator<ContactInfo> it3 = contactStorage.getList().iterator();

            int matchCnt = 0;
            if (type == 1) {
                while (it1.hasNext()) {
                    ContactInfo cur = it1.next();
                    if ((cur.getName().equals(part2))) {
                        System.out.println("Edited: ");
                        System.out.println(cur.getInfo());
                        matchCnt++;
                        cur.setName(part3);
                        it1.remove();
                        System.out.println("to: ");
                        System.out.println(cur.getInfo());
                        contactStorage.addToList(cur);
                        break;
                    }
                }
            }

            if (type == 2) {
                while (it1.hasNext()) {
                    ContactInfo cur = it1.next();
                    if ((cur.getPhoneNumber().equals(part2))) {
                        System.out.println("Edited: ");
                        System.out.println(cur.getInfo());
                        matchCnt++;
                        cur.setPhoneNumber(part3);
                        it1.remove();
                        System.out.println("to: ");
                        System.out.println(cur.getInfo());
                        contactStorage.addToList(cur);
                        break;
                    }
                }
            }

            if (type == 3) {
                while (it1.hasNext()) {
                    ContactInfo cur = it1.next();
                    if ((cur instanceof NormalContact) && ((NormalContact) cur).getRelation().equals(part2)) {
                        System.out.println("Edited: ");
                        System.out.println(cur.getInfo());
                        matchCnt++;
                        it1.remove();
                        ((NormalContact) cur).setRelation(part3);
                        System.out.println("to: ");
                        System.out.println(cur.getInfo());
                        contactStorage.addToList(cur);
                        break;
                    }
                }
            }

            if (type == 4) {
                while (it2.hasNext()) {
                    ContactInfo cur = it2.next();
                    if ((cur instanceof ClubContact) && ((ClubContact) cur).getClub().equals(part2)) {
                        System.out.println("Editted: ");
                        System.out.println(cur.getInfo());
                        matchCnt++;
                        it2.remove();
                        ((ClubContact) cur).setClub(part3);
                        System.out.println("to: ");
                        System.out.println(cur.getInfo());
                        contactStorage.addToList(cur);
                        break;
                    }
                }
            }

            if (type == 5) {
                while (it3.hasNext()) {
                    ContactInfo cur = it3.next();
                    if ((cur instanceof DepartmentContact) && ((DepartmentContact) cur).getDepartment().equals(part2)) {
                        System.out.println("Deleted: ");
                        System.out.println(cur.getInfo());
                        matchCnt++;
                        it3.remove();
                        ((DepartmentContact) cur).setDepartment(part3);
                        System.out.println("to: ");
                        System.out.println(cur.getInfo());
                        contactStorage.addToList(cur);
                        break;
                    }
                }
            }
            if(matchCnt==0) throw new ContactException("No such contact found!");
        } catch (ContactException e) {
            cli.printErrorMessage(e.getMessage());
        }
    }

    public void viewContact(){
        cli.printContactInfo(contactStorage.getList());
    }

    public void saveToFile(){
        PrintWriter outputStream = null;
        try{
            outputStream = new PrintWriter(new FileOutputStream("src/Homework3/ContactBook.txt"));
            outputStream.println(contactStorage.getCapacity() + " " + contactStorage.getSize());
            Iterator<ContactInfo> it1 = contactStorage.getList().iterator();

            while(it1.hasNext()){
                ContactInfo cur = it1.next();
                if(cur instanceof NormalContact){
                    outputStream.println(1 + " " + cur.getName() + " " + cur.getPhoneNumber() + " " + ((NormalContact) cur).getRelation());
                }
                if(cur instanceof ClubContact){
                    outputStream.println(2 + " " + cur.getName() + " " + cur.getPhoneNumber() + " " + ((ClubContact) cur).getClub());
                }
                if(cur instanceof DepartmentContact){
                    outputStream.println(3 + " " + cur.getName() + " " + cur.getPhoneNumber() + " " + ((DepartmentContact) cur).getDepartment());
                }
            }

            outputStream.close();
            System.out.println("Saved to file successfully!");
        }
        catch(FileNotFoundException e){
            cli.printErrorMessage("Error! ContactBook not found!");
        }
    }

    public void loadFromFile(){
        ArrayList<String> data = cli.readFile();
        if(data.get(0)=="FAIL"){
            cli.printErrorMessage("Load aborted! File not found!");
        }
        else{
            String sz="", cp="";
            String line1 = data.get(0);
            int cnt = 0;
            for(int i=0; i<line1.length(); i++){
                if(line1.charAt(i)==' ') cnt++;
                else{
                    if(cnt==0){
                        cp += line1.charAt(i);
                    }
                    else{
                        sz += line1.charAt(i);
                    }
                }
            }

            int capacity = Integer.parseInt(cp);

            contactStorage = new MyStorage<ContactInfo>();
            contactStorage.setSize(capacity);

            for(int i=1; i<data.size(); i++){
                String line = data.get(i);
                cnt = 1;
                String part1="", part2="", part3="", part4="";

                for(int j=0; j<line.length(); j++){
                    if(line.charAt(j)==' ') cnt++;
                    else{
                        if(cnt==1){
                            part1 += line.charAt(j);
                        }
                        if(cnt==2){
                            part2 += line.charAt(j);
                        }
                        if(cnt==3){
                            part3 += line.charAt(j);
                        }
                        if(cnt==4){
                            part4 += line.charAt(j);
                        }
                    }
                }

                int type = Integer.parseInt(part1);

                if(type==1){
                    NormalContact nc = new NormalContact(part2, part3, part4);
                    contactStorage.addToList(nc);
                }
                if(type==2){
                    ClubContact cc = new ClubContact(part2, part3, part4);
                    contactStorage.addToList(cc);
                }
                if(type==3){
                    DepartmentContact dc = new DepartmentContact(part2, part3, part4);
                    contactStorage.addToList(dc);
                }
                contactStorage.incrementSize();
            }

            System.out.println("Loaded from file successfully!");
        }
    }
}