package Week6.Exercise1;

import Week6.Exercise1.util.AgeCalculator;

import java.util.Date;

public class Main {
    public static void main(String[] args){
        Date day1 = new Date(2002,0,29);
        Date day2 = new Date(2002,2,14);
        Person p1 = new Person("Moong",day1, null);
        Person p2 = new Person("Taeng", day2, null);

        System.out.println(p1.toString());
        System.out.println(p2.toString());

        System.out.printf(p1.getName() + "'s age : " + AgeCalculator.calAge(p1) + "\n");
        System.out.printf(p2.getName() + "'s age : " + AgeCalculator.calAge(p2) + "\n");

        int res = AgeCalculator.isOlder(p1, p2);

        if(res==1) {
            System.out.println(p1.getName() + " is older than " + p2.getName());
        }
        else if(res==-1){
            System.out.println(p2.getName() + " is older than " + p1.getName());
        }
        else System.out.println("They are the same age");
    }
}
