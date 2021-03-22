//Michael Dinh - CISP 401 - Objects
import java.util.*;
class MyPoint {
    //Instance variables, private x and public y
    private int x;
    public int y;

    //Class variable to keep track of objects
    private static int noOfObjects = 0;

    //Constructors
    MyPoint(){
        x = 0;
        y = 0;
    }
    MyPoint(int x){
        this.x = x;
        y = 0;
    }
    MyPoint(int x, int y){
        this.x = x;
        this.y = y;
    }

    //Setter method assigning x
    public void setX(int x){
        this.x = x;
    }

    //Setter method modifying noOfObjects
    public void addObject(){
        noOfObjects += 1;
    }

    //Getter method to retrieve x
    public int getX(){
        return x;
    }

    //Getter method to retrieve noOfObjects
    public int getObjNum(){
        return noOfObjects;
    }
}

class Driver{
    public static void main(String[] args){
        //Create scanner
        Scanner input = new Scanner (System.in);

        //Ask user for values of x and y
        int x, y;
        System.out.printf("Input an x-coordinate: ");
        x = input.nextInt();
        System.out.printf("Input a y-coordinate: ");
        y = input.nextInt();

        //Create objects coresponding to constructors, call addObject for each new object
        MyPoint point1 = new MyPoint();
        point1.addObject();
        MyPoint point2 = new MyPoint(x);
        point2.addObject();
        MyPoint point3 = new MyPoint(x, y);
        point3.addObject();

        //Use setter methods to finalize objects
        point1.setX(x);
        point1.y = y;
        point2.y = y;

        //Display contents of objects
        System.out.printf("Number of objects: %d\n", point1.getObjNum());
        System.out.printf("Object 1: P(%d, %d)\n", point1.getX(), point1.y);
        System.out.printf("Object 2: P(%d, %d)\n", point2.getX(), point2.y);
        System.out.printf("Object 3: P(%d, %d)\n", point3.getX(), point3.y);
        System.out.println("If all is well, all three objects should be the same...");

        //Close scanner
        input.close();

        //End program
        return;
    }
}