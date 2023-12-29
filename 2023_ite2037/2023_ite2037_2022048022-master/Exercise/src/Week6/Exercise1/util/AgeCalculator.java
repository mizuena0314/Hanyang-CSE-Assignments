package Week6.Exercise1.util;

import Week6.Exercise1.Person;

import java.util.Date;

public class AgeCalculator {
    private static Date today = new Date(2023, 3, 12);
    public static int calAge(Person p){
        //today's day is fixed as 12th April 2023 for simplicity
        int ret = 0;
        ret += today.getYear()-p.getBorn().getYear();

        if(today.getMonth()>p.getBorn().getMonth()){
            ret -= 1;
        }
        else if(today.getMonth()==p.getBorn().getMonth()
        && today.getDate()>p.getBorn().getDate()){
            ret -= 1;
        }

        return ret;
    }

    public static int isOlder(Person p1, Person p2){
        int ret=0;
        if(calAge(p1)>calAge(p2)) ret = 1;
        else if(calAge(p1)==calAge(p2)) ret = 0;
        else if(calAge(p1)<calAge(p2)) ret = -1;
        return ret;
    }
}
