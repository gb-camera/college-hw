//Michael Dinh - CISP 401 - BankArray
import java.util.*;
import java.io.*;
public class Bank {
    static Scanner input = new Scanner(System.in);
    static BankAccount[] accounts = new BankAccount[1]; //This array will point to all the BankAccount objects
    static int noOfAccs = 0; //Keeps track of the total number of accounts

    public static void main(String[] args) { 
      //call bankMenu
      bankMenu();
      return;
    }
    
    //bankMenu runs the main part of the program, until user selects 'Q'
    static void bankMenu(){
      int currentIndex = -1;	//This variable tells us whether we are pointing to a valid account 
      boolean quit = false;
      do{  
        printMenu(currentIndex);
        System.out.printf("Make your selection: ");
        char userSelection = input.next().charAt(0);
        System.out.println("--------------------");
        switch(userSelection){
          case 'O': //Open account 
            //make sure you have enough space or double size OF accounts array
            //Adapted so that the program addends an element to the array rather than double the array
            if(noOfAccs == 0){
              accounts[0] = new BankAccount(-1, 0.0);
              accounts[0] = openAcc();
              currentIndex = 0;
              noOfAccs = 1;
            }
            else{
              accounts = addElement();
              accounts[noOfAccs] = openAcc();
              //set the current index
              //increment the number of accounts
              currentIndex = noOfAccs;
              noOfAccs += 1;
            }
            break;
          case 'D': //Deposit 
            //deposit only if currentIndex is not -1. you are depositing into a particular account
            if(currentIndex == -1){
              System.out.println("Please select an account first!");
            }
            else{
              System.out.printf("Enter amount to deposit: $");
              double amount = input.nextDouble();
              accounts[currentIndex].deposit(amount);
            }
            break;
          case 'S': //Select account
            //look for account and if it exists, set currentIndex to it
            currentIndex = selectAcc();
            break;
          case 'C': //Close account
            //if currentindex is not -1 close the account and reset currentIndex
            if(currentIndex == -1){
              System.out.println("Please select an account first!");
            }
            else{
              closeAcc(currentIndex);
              currentIndex = -1;
              System.out.println("Account closed.");
            }
            break;
          case 'W': //Withdraw
            //if current index is not -1, withdraw
            if(currentIndex == -1){
              System.out.println("Please select an account first!");
            }
            else{
              if(accounts[currentIndex].getBalance() <= 1.00){
                System.out.println("You cannot withdraw past $1.00 remaining in your account. Please deposit more funds into your account first.");
                break;
              }
              boolean valid = true;
              System.out.printf("Enter amount to withdraw: $");
              double amount = input.nextDouble();
              if(accounts[currentIndex].getBalance() - amount < 1.00){
                valid = false;
              }
              while(!valid){
                System.out.println("You cannot withdraw past $1.00 remaining in your account. Please try again.");
                valid = true;
                System.out.printf("Enter amount to withdraw: $");
                amount = input.nextDouble();
                if(accounts[currentIndex].getBalance() - amount < 1.00){
                  valid = false;
                }
              }
              accounts[currentIndex].withdraw(amount);
            }
            break;
          case 'L': //List accounts
            //traverse through all the accounts and display their information
            listAccounts();
            break;
          case 'Q': //Quit
            System.out.println("Exiting.");
            quit = true;
            break;
          default: //Input validation and error handler
            System.out.println("Invalid input! Please try again.");
            break;
        }
      }while(!quit);
      return;
    }
  
    //Print the menu, takes index of currently selected account
    static void printMenu(int index){
      System.out.println("--------------------");
      System.out.println("O: Open an account");
      System.out.println("D: Deposit money");
      System.out.println("S: Select an account");
      System.out.println("C: Close an account");
      System.out.println("W: Withdraw money");
      System.out.println("L: List all accounts");
      System.out.println("Q: Quit program");
      System.out.println("--------------------");
      //if index is not -1 display the account information    
      System.out.printf("Current account selected: ");
      if(index == -1){
        System.out.printf("None\n");
        System.out.println("--------------------");
      }
      else if(index != -1){
        System.out.printf("%d\n", accounts[index].getAcc());
        System.out.println("--------------------");
      }
    }

    static BankAccount openAcc(){
      //Grab account number
      boolean duplicate = false;
      System.out.printf("Enter your desired account number: ");
      int accountNum = input.nextInt();
      //validate for duplicate account number
      for(int i = 0; i < accounts.length - 1; i++){
        if(accountNum == accounts[i].getAcc()){
          duplicate = true;
        }
      }
      while(duplicate){
        System.out.printf("Error! Account with that number already exists. Enter a new number: ");
        accountNum = input.nextInt();
        duplicate = false;
        for(int i = 0; i < accounts.length - 1; i++){
          if(accountNum == accounts[i].getAcc()){
            duplicate = true;
          }
        }
      }
      //Grab balance
      System.out.printf("Enter the initial balance for your account: $");
      double balance = input.nextDouble();
      //create new account and return the object so that the array index can point to the newly created object
      BankAccount newAccount = new BankAccount(accountNum, balance);
      return newAccount;
    }
    
    static BankAccount[] addElement(){
      //resize array
      //Program adapted so that only one element is added for a new account at any time to simplify tracking of number of accounts
      BankAccount[] temp = new BankAccount[accounts.length + 1];
      System.arraycopy(accounts, 0, temp, 0, accounts.length);
      return temp;
    }
  
    static void listAccounts(){
      //Go through all the accounts using a for loop and display their content
      double bankSum = 0.00;
      if(noOfAccs == 0){
        System.out.println("No accounts currently registered.");
      }
      else{
        System.out.println("All Bank Accounts:");
        for(int i = 0; i < accounts.length; i++){
          System.out.printf("Account #%d: Balance is $%.2f\n", accounts[i].getAcc(), accounts[i].getBalance());
          bankSum += accounts[i].getBalance();
        }
        System.out.printf("Total assets in bank: $%.2f\n", bankSum);
        System.out.printf("Total number of accounts registered: %d\n", noOfAccs);
      }
      return;
    }
  
    static int selectAcc(){
      //ask for the account number, check to see if it exists and return index
      System.out.printf("Enter your account number: ");
      int accountNum = input.nextInt();
      for(int i = 0; i < accounts.length; i++){
        if(accounts[i].getAcc() == accountNum){
          return i;
        }
        else{
          continue;
        }
      }
      System.out.println("Could not find an account under that number.");
      return -1;
    }
    
    static void closeAcc(int index){
      if(noOfAccs == 1){
        accounts[0] = new BankAccount(0, 0.0);
        noOfAccs = 0;
      }
      else{
        //move last account to the index that needs to be deleted
        BankAccount temp = accounts[noOfAccs - 1];
        accounts[noOfAccs - 1] = accounts[index];
        accounts[index] = temp;
        //set last account to null
        //Adapted so that account is actually deleted and array is reduced by one element
        BankAccount[] temp2 = new BankAccount[noOfAccs - 1];
        System.arraycopy(accounts, 0, temp2, 0, accounts.length - 1);
        accounts = temp2;
        //decrement noOfAccts variable
        noOfAccs -= 1;
      }
    }
  }
  
  class BankAccount{
    private int accNbr;
    private double balance;
    
    BankAccount(int accNbr, double balance){
      this.accNbr = accNbr;
      this.balance = balance;
    }
    
    int getAcc(){
      return this.accNbr;
    }
    
    double getBalance(){
      return this.balance;
    }
    
    void deposit(double amount){     
      this.balance += amount;
      return;
    }
    
    void withdraw(double amount){
      this.balance -= amount;
      return;
    }
  }