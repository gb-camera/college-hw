//Michael Dinh - CISP 401 - Anonymous Wrapper
import java.util.*;
import javax.swing.JOptionPane;
class Family{
    //Instance variables, no specification on accessibility modifiers
    static int randomVal;
    double income;
    int children;
    //Anonymous static block for randomization
    static {
        //Create randomizer
        Random rand = new Random();
        randomVal = rand.nextInt(8)+1;
    }
    //Anonymous instance block using random value
    {
        children = randomVal;
    }
    //Constructors
    Family(){
        income = 1000 * randomVal;
    }
    Family(double income){
        this.income = income;
    }
    //Define main
    public static void main(String[] args){
        //Create a new family with no argument constructor by default, then replace with the one argument if randomVal >= 4
        Family family = new Family();
        if(randomVal >= 4){
            //Call JOptionPane and get string income
            String strIncome = JOptionPane.showInputDialog("Enter the total income your family makes: $");
            //Convert strIncome to double and pass income to one argument constructor
            double income = Double.parseDouble(strIncome);
            family = new Family(income);
        }
        //Display family information
        System.out.printf("Your family has %d children and has an income of $%.2f.", family.children, family.income);
        //End program
        return;
    }
}