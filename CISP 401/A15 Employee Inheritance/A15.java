//Michael Dinh - CISP 401 - Employee Inheritance
import java.util.*;
abstract class Employee {
    String empName;
    double empWage;
    static int empCount;
    void setName(String empName){
        this.empName = empName;
    }
    void setWage(double empWage){
        this.empWage = empWage;
    }
    String getName(){
        return this.empName;
    }
    double getWage(){
        return this.empWage;
    }
    void increaseEmpWage(double increasePerc){
        this.empWage = this.empWage * (increasePerc / 100);
    }
    abstract double computePay();
    abstract String infoString();
}
 
class HourlyEmployee extends Employee {
    double hours;
    HourlyEmployee(String empName, double empWage){
        super.empName = empName;
        super.empWage = empWage;
        this.hours = 40;
    }
    double computePay(){ //compute both regular time and overtime based on hours
        double pay = 0.0;
        System.out.printf("Enter hours worked by %s: ", this.empName);
        double hoursWorked = EmployeeDriver.input.nextDouble();
        if(hoursWorked <= this.hours){
            pay = this.empWage * hoursWorked;
            return pay;
        }
        else if(hoursWorked > this.hours){
            pay = this.empWage * this.hours;
            pay += (this.empWage * 1.5) * (hoursWorked - this.hours);
            return pay;
        }
        else{
            System.out.println("Error!");
            return pay;
        }
    } 
    String infoString(){ //return empname and wage
        return empName + ": $" + String.format("%,.2f", empWage) + "/hour";
    }   
 }
 
class SalariedEmployee extends Employee { 
    SalariedEmployee(String empName, double empWage){ //set name and wage divide by 52, divide by 40
        super.empName = empName;
        super.empWage = (empWage / 52) / 40;
    }
    double computePay(){
        double pay = this.empWage * 40;
        return pay;
    }
    String infoString(){ //return empname and annual salary
        return empName + ": $" + String.format("%,.2f", empWage * 52 * 40) + "/year";
    }
 }
 
class EmployeeDriver {
    public static final Scanner input = new Scanner(System.in);
    //declare array
    static Employee[] employees = new Employee[1];
    public static void main(String[] args) { 
    //display menu in a do/while loop  (call menu and selectOptions methods)
    boolean exit = false;
    do{
        String command = employeeMenu();
        if(!command.equalsIgnoreCase("Q")){
            selectOptions(command);
        }
        else{
            exit = true;
        }
    } while(!exit);
    System.out.println("Exiting.");
    input.close();
    }
    public static String employeeMenu(){//display menu and return user’s selection
        System.out.println("----------");
        System.out.println("N: New employee");
        System.out.println("P: Compute paychecks");
        System.out.println("R: Raise wages");
        System.out.println("L: List all employees");
        System.out.println("Q: Quit");
        System.out.println("----------");
        System.out.printf("Enter a command: ");
        char com = input.next().charAt(0);
        input.nextLine();
        String command = Character.toString(com);
        return command;
    }
    public static void selectOptions(String user){
        switch (user){
            case "n":
            case "N":
                newEmployee();
                return;
            case "p":
            case "P":
                computeWeeklyPaycheck();
                return;
            case "r":
            case "R":
                raiseWages();
                return;
            case "l":
            case "L":
                listEmployees();
                return;
            default:
                System.out.println("Error!");
                return;
       }
    }
    public static void newEmployee() {
        //grab input from user such as name, whether the employee is hourly or salaried
        System.out.printf("Input name of employee: ");
        String name = input.nextLine();
        System.out.printf("Input whether employee is hourly (H) or salaried (S): ");
        char hourSalariedChar = input.next().charAt(0);
        String hourSalaried = Character.toString(hourSalariedChar);
        while(!hourSalaried.equalsIgnoreCase("h") && !hourSalaried.equalsIgnoreCase("s")){
            System.out.printf("Error! Type H or S for hourly or salaried: ");
            hourSalariedChar = input.next().charAt(0);
            hourSalaried = Character.toString(hourSalariedChar);
        }
        input.nextLine();
        //hourly wage or salary
        //create employee object based on the input
        //expand array as needed and assign new object to the proper index of the array
        if(hourSalaried.equalsIgnoreCase("h")){
            System.out.printf("Input hourly wage of employee: $");
            double hourlyWage = input.nextDouble();
            Employee.empCount += 1;
            if(Employee.empCount != 1){
                Employee[] temp = new Employee[Employee.empCount];
                System.arraycopy(employees, 0, temp, 0, Employee.empCount - 1);
                employees = temp;
                employees[Employee.empCount - 1] = new HourlyEmployee(name, hourlyWage);
            }
            else{
                employees[0] = new HourlyEmployee(name, hourlyWage);
            }
            //HourlyEmployee employee = new HourlyEmployee(name, hourlyWage);
        }
        else if(hourSalaried.equalsIgnoreCase("s")){
            System.out.printf("Input annual wage of employee: $");
            double annualWage = input.nextDouble();
            Employee.empCount += 1;
            if(Employee.empCount != 1){
                Employee[] temp = new Employee[Employee.empCount];
                System.arraycopy(employees, 0, temp, 0, Employee.empCount - 1);
                employees = temp;
                employees[Employee.empCount - 1] = new SalariedEmployee(name, annualWage);
            }
            else{
                employees[0] = new SalariedEmployee(name, annualWage);
            }
            //SalariedEmployee employee = new SalariedEmployee(name, annualWage);
        }
        System.out.println("Employee created.");
    }
       
    public static void computeWeeklyPaycheck() {
        //display weekly pay for all employees using a loop. 
        //For hourly employees first grab hours, set hours to instance variable 
        //then call computePay which will call the 
        //appropriate overridden method for either hourly or salaried employee
        if(Employee.empCount != 0){
            for(int i = 0; i < Employee.empCount; i++){
                double pay = employees[i].computePay();
                System.out.printf("Pay for %s is $%,.2f\n", employees[i].getName(), pay);
            }
        }
        else{
            System.out.println("Cannot compute pay with no employees on file!");
        }
    }   
    
    public static void raiseWages() {
        //grab percentage from user and raise empWage for all employees using loop
        if(Employee.empCount != 0){
            System.out.printf("Enter percentage to raise or lower wages by (i.e. NOT a decimal value): ");
            double percentage = input.nextDouble();
            double percent = percentage / 100.00;
            for(int i = 0; i < Employee.empCount; i++){
                double addWage = employees[i].getWage() * percent;
                double newWage = employees[i].getWage() + addWage;
                employees[i].setWage(newWage);
                if(employees[i] instanceof HourlyEmployee){
                    System.out.printf("%s: New wage is $%,.2f/hour\n", employees[i].getName(), employees[i].getWage());
                }
                else if(employees[i] instanceof SalariedEmployee){
                    System.out.printf("%s: New wage is $%,.2f/year\n", employees[i].getName(), employees[i].getWage() * 52 * 40);
                }
            }
        }
        else{
            System.out.println("Cannot raise wages with no employees on file!");
        }
    }
    public static void listEmployees() {
        //display information for all employees using loop and toString method
        if(Employee.empCount != 0){
            for(int i = 0; i < Employee.empCount; i++){
                System.out.printf("%s\n", employees[i].infoString());
            }
        }
        else{
            System.out.println("Cannot list employee information with no employees on file!");
        }
    }
 }