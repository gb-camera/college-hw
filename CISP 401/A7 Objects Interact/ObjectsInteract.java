//Michael Dinh - CISP 401 - Objects Interact
import java.util.*;
class MyCar{
    //Define instance variables, no specification on accessibility modifier
    String make;
    String model;
    double MPG;

    //Define constructor
    MyCar(){
        make = "";
        model = "";
        MPG = 0.0;
    }

    //Define compareMPG method
    public MyCar compareMPG(MyCar otherCar){
        if(this.MPG > otherCar.MPG){
            return this;
        }
        else if(this.MPG < otherCar.MPG){
            return otherCar;
        }
        else{
            System.out.println("Cars have the same MPG! Returning car defined in the method argument.");
            return otherCar;
        }
    }
}

class Driver{
    public static void main(String[] args){
        //Create scanner
        Scanner input = new Scanner(System.in);

        //Create objects
        MyCar car1 = new MyCar();
        MyCar car2 = new MyCar();

        //Get user input for objects
        System.out.printf("Input the make of Car 1: ");
        car1.make = input.nextLine();
        System.out.printf("Input the model of Car 1: ");
        car1.model = input.nextLine();
        System.out.printf("Input the miles per gallon of Car 1: ");
        car1.MPG = input.nextInt();

        System.out.printf("Input the make of Car 2: ");
        input.nextLine();
        car2.make = input.nextLine();
        System.out.printf("Input the model of Car 2: ");
        car2.model = input.nextLine();
        System.out.printf("Input the miles per gallon of Car 2: ");
        car2.MPG = input.nextInt();

        //Call compareMPG and display better car
        MyCar bestCar = new MyCar();
        bestCar = car1.compareMPG(car2);
        System.out.printf("The car with the better MPG is the %s %s, with %.2f MPG.\n", bestCar.make, bestCar.model, bestCar.MPG);
        
        //Close scanner and end program
        input.close();
        return;
    }
}