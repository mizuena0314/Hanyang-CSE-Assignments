package Week5;

import java.util.StringTokenizer;
import java.util.Scanner;
public class Practice {
    public static void main(String args[]){
        int y, m, d;

        Scanner key = new Scanner(System.in);
        String name1, name2, line1;
        name1 = key.next();
        line1 = key.next();
        name2 = key.next();
        StringTokenizer stk = new StringTokenizer(line1, "/.");

        if(stk.countTokens()!=3){
            System.out.println("invalid input");
            return;
        }

        y = Integer.parseInt(stk.nextToken());
        m = Integer.parseInt(stk.nextToken());
        d = Integer.parseInt(stk.nextToken());

        Student stu1 = new Student(name1, y, m, d);
        Student stu2 = new Student(name2, y);

        if(stu1.checkDate()==false || stu2.checkDate()==false) {
            System.out.println("invalid input");
        }
        else{
            System.out.printf("%s %d/%d/%d age: %d\n", stu1.getName(), stu1.getYear(), stu1.getMonth(), stu1.getDay(), stu1.calAge());
            System.out.printf("%s %d/%d/%d age: %d\n", stu2.getName(), stu2.getYear(), stu2.getMonth(), stu2.getDay(), stu2.calAge());
            if(stu1.isOlder(stu2)){
                System.out.printf("%s is older than %s", stu1.getName(), stu2.getName());
            }
            else{
                System.out.printf("%s is not older than %s", stu1.getName(), stu2.getName());
            }
        }
    }
}
