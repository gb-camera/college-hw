//Michael Dinh - CISP 401 - Loops
import java.util.*;
public class Menu{
    static Scanner reader = new Scanner(System.in);

    public static void main(String[] args){
        int selection = 0;

        System.out.println("----------");
        do{
            selection = menu();
            switch(selection){
                case 1:
                    hypotenuse();
                    continue;
                case 2:
                    gravity();
                    continue;
                case 3:
                    break;
                default:
                    System.out.println("Error! Invalid input. Restarting program.");
                    System.out.println("----------");
                    continue;
            }
        } while(selection != 3);
        
        System.out.println("Now exiting program.");
        System.out.println("----------");
        return;
    }

    public static int menu(){
        int input = 0;
        System.out.println("Program options:");
        System.out.println("1) Hypotenuse");
        System.out.println("2) Gravity");
        System.out.println("3) Quit program");
        System.out.printf("Select an option: ");
        input = reader.nextInt();
        return input;
    }

    public static void hypotenuse(){
        double a = 0.0;
        double b = 0.0;
        double c = 0.0;
        boolean validA, validB;
        System.out.println("----------");
        do{
            validA = true;
            System.out.printf("Input the a component side of your right triangle: ");
            a = reader.nextDouble();
            if(a < 2 || a > 20){
                System.out.println("Error: invalid input. The component must be between 2 and 20 inclusive.");
                validA = false;
            }
        } while(!validA);

        do{
            validB = true;
            System.out.printf("Input the b component side of your right triangle: ");
            b = reader.nextDouble();
            if(b < 2.0 || b > 20.0){
                System.out.println("Error: invalid input. The component must be between 2 and 20 inclusive.");
                validB = false;
            }
        } while(!validB);
        
        double asqr = Math.pow(a, 2);
        double bsqr = Math.pow(b, 2);
        c = Math.sqrt(asqr + bsqr);
        System.out.printf("The hypotenuse c of a right triangle with side a = %.2f and side b = %.2f is %.2f.\n", a, b, c);
        System.out.println("----------");

        return;
    }

    public static void gravity(){
        double weight = 0.0;
        boolean validWeight = false;
        System.out.println("----------");
        System.out.printf("Enter your weight in lb.: ");
        weight = reader.nextDouble();
        if(weight > 100 & weight < 300) {
            validWeight = true;
        }

        while(!validWeight){
            System.out.println("Error: invalid input. Your weight must be between 100 lb. and 300 lb. inclusive.");
            System.out.printf("Enter your weight in lb.: ");
            weight = reader.nextDouble();
            if(weight > 100 & weight < 300) {
                validWeight = true;
            }
        }

        double moonWeight = weight * 0.17;
        System.out.printf("Your weight of %.2f lb. on Earth is %.2f lb. on the moon.\n", weight, moonWeight);
        System.out.println("----------");

        return;
    }
}