//Michael Dinh - CISP 401 - Methods
import java.util.*;
class Grades{
    static int high = 0, low = 100;
    public static void main(String[] args){
        int gradeA = 0, gradeB = 0, gradeC = 0, gradeD = 0, gradeF = 0, total = 0, inputVal = 0, numGrades = 0;
        Scanner input = new Scanner(System.in);
        System.out.printf("Enter an exam score (-1 to end input): ");
        inputVal = input.nextInt();
        while(inputVal != -1){
            total += inputVal;
            numGrades += 1;
            calcHigh(inputVal);
            calcLow(inputVal);
            if(inputVal >= 90) {
                gradeA += 1;
            }
            else if(inputVal >= 80 && inputVal < 90){
                gradeB += 1;
            }
            else if(inputVal >= 70 && inputVal < 80){
                gradeC += 1;
            }
            else if(inputVal >= 60 && inputVal < 70){
                gradeD += 1;
            }
            else if(inputVal < 60){
                gradeF += 1;
            }
            System.out.printf("Enter next exam score (-1 to end input): ");
            inputVal = input.nextInt();
        }
        int average = calcAvg(total, numGrades);
        System.out.println("--------");
        if(gradeA > 0){
            System.out.printf("Number of As: %d\n", gradeA);
        }
        if(gradeB > 0){
            System.out.printf("Number of Bs: %d\n", gradeB);
        }
        if(gradeC > 0){
            System.out.printf("Number of Cs: %d\n", gradeC);
        }
        if(gradeD > 0){
            System.out.printf("Number of Ds: %d\n", gradeD);
        }
        if(gradeF > 0){
            System.out.printf("Number of Fs: %d\n", gradeF);
        }
        System.out.println("Highest score: " + high);
        System.out.println("Lowest score: " + low);
        System.out.println("Average score: " + average);
        input.close();
    }
    static int calcAvg(int total, int numGrades){
        int average = total / numGrades;
        return average;
    }
    static void calcHigh(int inputVal){
        if(inputVal > high){
            high = inputVal;
        }
        else{
            return;
        }
    }
    static void calcLow(int inputVal){
        if(inputVal < low){
            low = inputVal;
        }
        else{
            return;
        }
    }
}