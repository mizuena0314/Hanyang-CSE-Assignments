package Week5;

//FOR THE SAKE OF SIMPLICITY
//TODAY'S DATE IS FIXED AS 5TH APRIL 2023

import java.util.Calendar;
import java.util.Random;
public class Student {
    private String name;
    private int year;
    private int month;
    private int day;

    Student(String name, int year, int month, int day) {
        this.name = name;
        this.year = year;
        this.month = month;
        this.day = day;
    }

    Student(String name, int year) {
        this.name = name;
        this.year = year;
        Random x = new Random();
        this.month = x.nextInt(1, 12);
        Calendar time = Calendar.getInstance();
        time.set(this.year, this.month - 1, 1);
        this.day = x.nextInt(1, time.getActualMaximum(time.DATE));
    }

    String getName() {
        return this.name;
    }

    int getYear() {
        return this.year;
    }

    int getMonth() {
        return this.month;
    }

    int getDay() {
        return this.day;
    }

    boolean checkDate() {
        Calendar time = Calendar.getInstance();
        time.set(this.year, this.month - 1, 1);
        int chk = time.getActualMaximum(time.DATE);

        //System.out.printf("chk: %d this month: %d\n", chk, this.month);

        if (chk < this.day || this.day <= 0) {
            return false;
        }
        if (this.month <= 0 || this.month > 12) {
            return false;
        }
        if(this.year>2023){
            return false;
        }
        if(this.year==2023){
            if(this.month>4){
                return false;
            }
            if(this.month==4){
                if(this.day>5){
                    return false;
                }
            }
        }
        return true;
    }

    int calAge() {
        Calendar today = Calendar.getInstance();

        int diff=0;
        diff += 2023 - this.year;
        if(this.month>4){
            diff--;
        }
        else if(this.month==4){
            if(this.day>5){
                diff--;
            }
        }
        return diff;
    }

    boolean isOlder(Student stu) {
        if (stu.getYear() > this.year) {
            return true;
        } else if (stu.getYear() == this.year) {
            if (stu.getMonth() > this.month) {
                return true;
            }
        } else if (stu.getYear() == this.year && stu.getMonth() == this.month) {
            if (stu.getDay() > this.day) {
                return true;
            }
        }
        return false;
    }
}

