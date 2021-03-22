import java.util.*;
class FullNamePay{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        String name = "";
        double hourlyPay = 0.0;
        int hours = 0;

        System.out.printf("Input a full name: ");
        name = input.nextLine();
        System.out.printf("Input hourly wage: $");
        hourlyPay = input.nextDouble();
        System.out.printf("Input hours worked: ");
        hours = input.nextInt();
        
        System.out.println("--------");
        double totalWage = hourlyPay * hours;
        System.out.printf("%s / %d hrs. x $%.2f = $%.2f", name, hours, hourlyPay, totalWage);
        input.close();
    }
}

class PayFullName{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        String name = "";
        double hourlyPay = 0.0;
        int hours = 0;

        System.out.printf("Input hourly wage: $");
        hourlyPay = input.nextDouble();
        System.out.printf("Input hours worked: ");
        hours = input.nextInt();
        System.out.printf("Input a full name: ");
        input.nextLine();
        name = input.nextLine();
        
        System.out.println("--------");
        double totalWage = hourlyPay * hours;
        System.out.printf("%s / %d hrs. x $%.2f = $%.2f", name, hours, hourlyPay, totalWage);
        input.close();
    }
}

class PayFirstLastName{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        String fname = "";
        String lname = "";
        double hourlyPay = 0.0;
        int hours = 0;

        System.out.printf("Input hourly wage: $");
        hourlyPay = input.nextDouble();
        System.out.printf("Input hours worked: ");
        hours = input.nextInt();
        System.out.printf("Input a first name: ");
        fname = input.next();
        System.out.printf("Input a last name: ");
        lname = input.next();
        
        System.out.println("--------");
        double totalWage = hourlyPay * hours;
        System.out.printf("%s %s / %d hrs. x $%.2f = $%.2f", fname, lname, hours, hourlyPay, totalWage);
        input.close();
    }
}