package Week9;

import Week6.Exercise1.Person;

import java.util.Date;
public class Main {
    public static void main(String[] args) {
        Date day1 = new Date(2002, 0, 29);
        Date day2 = new Date(2002, 9, 14);
        Date day3 = new Date(1999, 6, 23);
        Patient p1 = new Patient("Moong", day1, null, "internal");
        Patient p2 = new Patient("Taeng", day2, null, "dental");
        Physician ph1 = new Physician("Jinusuke", day3, null, "Hanyang");
        Doctor d = new Doctor("Sehun", day1, null, "Hyanang");

        System.out.println(d.toString());
        System.out.println(p1.toString());
        System.out.println(ph1.toString());

        ph1.examination(p1);
        ph1.examination(p2);
    }
}
