//Michael Dinh - CISP 401 - EmployeeBoss
class Address{
    //Define instance variables
    private String city, state;
    //Create two argument constructor
    Address(String city, String state){
        this.city = city;
        this.state = state;
    }
    //Define getter method
    public String getAddress(){
        String fullAddress = this.city.concat(", " + this.state);
        return fullAddress;
    }
}

class Employee{
    //Define instance variables
    private String fname, lname;
    private Employee boss;
    private Address address;
    //Create five argument constructor
    Employee(String fname, String lname, Employee boss, String city, String state){
        this.fname = fname;
        this.lname = lname;
        this.boss = boss;
        //Call address constructor with remaining two arguments
        this.address = new Address(city, state);
    }
    //Define setter method
    public void setBoss(Employee a){
        this.boss = a;
    }
    //Define getter methods
    public String getName(){
        String fullName = this.fname.concat(" " + this.lname);
        return fullName;
    }
    public Address getAddress(){
        return this.address;
    }
    public Employee getBoss(){
        return this.boss;
    }
}

class Driver{
    public static void main(String[] args){
        //Create employees
        Employee a = new Employee("Jane", "Doe", null, "Topeka", "KS");
        Employee b = new Employee("John", "Doe", a, "Los Angeles", "CA");
        //Display employee info
        showEmployee(a);
        showEmployee(b);
        //End program
        return;
    }
    //Create new method to display employee info and handle if any given employee object has a boss or not
    public static void showEmployee(Employee a){
        //Display information common to all employee objects
        System.out.printf("%s lives in %s, and ", a.getName(), a.getAddress().getAddress());
        //Boss is null branch
        if(a.getBoss() == null){
            System.out.printf("has no boss.\n");
        }
        //Boss exists branch
        else if(a.getBoss() != null){
            System.out.printf("their boss is %s.\n", a.getBoss().getName());
        }
        //End method
        return;
    }
}