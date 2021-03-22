//Michael Dinh - CISP 401 - Employee Exception
class Employee{
    int idNum;
    double hourlyWage;
    Employee(int idNum, double hourlyWage){
        this.idNum = idNum;
        this.hourlyWage = hourlyWage;
    }
}

class EmployeeException extends RuntimeException{
    String info;
    public EmployeeException(String info){
        this.info = info;
    }
    public String getMessage(){
        return ("For ID #" + info + " is not within suitable wage range (Less than $6 or greater than $50).");
    }
}

class Driver{
    static Employee[] employees = new Employee[0];
    public static void main(String[] args){
        try{
            addEmp(123456, 5.00); //under
        }
        catch(EmployeeException e){
            System.err.println("Exception: " + e.getMessage());
        }

        try{
            addEmp(234567, 51.00); //over
        }
        catch(EmployeeException e){
            System.err.println("Exception: " + e.getMessage());
        }

        try{
            addEmp(345678, 6.00); //lower bound
        }
        catch(EmployeeException e){
            System.err.println("Exception: " + e.getMessage());
        }

        try{
            addEmp(456789, 25.00); //midrange
        }
        catch(EmployeeException e){
            System.err.println("Exception: " + e.getMessage());
        }

        try{
            addEmp(567890, 50.00); //upper bound
        }
        catch(EmployeeException e){
            System.err.println("Exception: " + e.getMessage());
        }
    }
    static void addEmp(int idNum, double hourlyWage) throws EmployeeException{
        if(hourlyWage < 6.0 || hourlyWage > 50.0){
            System.out.println("Failed to create employee.");
            String form = String.format("%.2f", hourlyWage);
            throw new EmployeeException(Integer.toString(idNum) + ", $" + form);
        }
        else{
            Employee[] temp = new Employee[employees.length + 1];
            System.arraycopy(employees, 0, temp, 0, employees.length);
            employees = temp;
            employees[employees.length - 1] = new Employee(idNum, hourlyWage);
            System.out.printf("Employee ID #%d with wage of $%.2f/hour successfully created.\n", idNum,hourlyWage);
        }
    }
}