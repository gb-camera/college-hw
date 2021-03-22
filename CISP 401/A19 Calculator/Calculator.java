//Michael Dinh - CISP 401 - Calculator
import java.awt.event.*;
import javax.swing.*;
import java.awt.*;
class Calculator extends JFrame implements ActionListener{
    static JPanel p1, p2; //declare 2 panels

    //b0 - b9 are numbers
    //bA, bS, bD, bM are operators
    //bE is equal, bC is clear, bP is decimal
    static JButton b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, bA, bS, bD, bM, bE, bC, bP; //declare all your buttons

    static JTextField l; //declare your textfield;
    static JLabel a; //declare your label;

    public void createGUI(){	
        //create frame
        JFrame f = new JFrame("Calculator");

        //create first panel
        p1 = new JPanel();
        p1.setLayout(new FlowLayout());
        //create new textfield and add it to the panel
        l = new JTextField(16);
        l.setEditable(false);
        p1.add(l);
        l.setText("");
        //create clear button and add to panel
        bC = new JButton("Clear");
        p1.add(bC);
        //create label and add to panel
        a = new JLabel("Do something, will ya?");
        Font bold = new Font("Courier", Font.BOLD, 12);
        a.setFont(bold);
        p1.add(a);

        //create a new panel with grid layout
        p2 = new JPanel();
        p2.setLayout(new GridLayout(4, 4));
        //add all buttons to the panel
        b0 = new JButton("0");
        b1 = new JButton("1");
        b2 = new JButton("2");
        b3 = new JButton("3");
        b4 = new JButton("4");
        b5 = new JButton("5");
        b6 = new JButton("6");
        b7 = new JButton("7");
        b8 = new JButton("8");
        b9 = new JButton("9");
        bP = new JButton(".");
        bA = new JButton("+");
        bS = new JButton("-");
        bM = new JButton("*");
        bD = new JButton("/");
        bE = new JButton("=");

        p2.add(b7);
        p2.add(b8);
        p2.add(b9);
        p2.add(bA);
        p2.add(b4);
        p2.add(b5);
        p2.add(b6);
        p2.add(bS);
        p2.add(b1);
        p2.add(b2);
        p2.add(b3);
        p2.add(bM);
        p2.add(b0);
        p2.add(bP);
        p2.add(bE);
        p2.add(bD);

        //add both panels to frame
        f.setSize(450, 175);
        f.add(p2, BorderLayout.NORTH);
        f.add(p1, BorderLayout.SOUTH);
        f.setVisible(true);
    }
    
    public void addListeners(){
        Operator o = new Operator();
        //add actionlistener to all number buttons
        b0.addActionListener(this);
        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
        b5.addActionListener(this);
        b6.addActionListener(this);
        b7.addActionListener(this);
        b8.addActionListener(this);
        b9.addActionListener(this);
        bP.addActionListener(this);
        //add a different actionlistener to the operators and clear button
        bA.addActionListener(o);
        bS.addActionListener(o);
        bM.addActionListener(o);
        bD.addActionListener(o);
        bC.addActionListener(o);
        bE.addActionListener(o);
    }
    
    public Calculator(){
        //call the above methods to setup your calculator
        createGUI();
        addListeners();	
    }

    public void actionPerformed(ActionEvent e){
        String n = e.getActionCommand();
			//You enter this method if a number was chosen
            //clear the label
            a.setText("");
            //Check a boolean flag to see if a number or an operator was chosen before
            if(Operator.chosen){
                //if operator then clear text
                l.setText("");
                l.setText(l.getText() + n);
            }
            else{
                //otherwise append old number to new number
                l.setText(l.getText() + n);
            }
            //update the textbox and set the boolean flag for operator to false
            Operator.chosen = false;
                
    }

    public static void main(String[] args){
        //create calculator object
        Calculator c = new Calculator();
        c.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}

class Operator extends Frame implements ActionListener{
    static boolean chosen=false;
    String next, previous;  //point to an operator. Process previous first
    static double total, initial, current = 0.0;
    
    void init(){
        next=previous=null;
        total = initial = current = 0;
        chosen=false;  
        //set label to clear
        Calculator.l.setText("");
    }
    
    public void actionPerformed(ActionEvent e){
        next = e.getActionCommand();
        //if clear was chosen then reset the calculator, the labels, textfield and flags (init function)
        if(next.equals("Clear")){
            init();
            return;
        }
        //if operator is chosen, make sure it wasn't chosen before (check boolean flag)
        else if(!chosen){
            //based on the operator that was chosen before, do the proper calculations
            //and update total
            try{
                current = Double.parseDouble(Calculator.l.getText());
            }
            catch (NumberFormatException g){
                Calculator.a.setText("Need a number input!");
                next = "";
            }
            initial = total;
            if(previous != null){
                if(previous.equals("+")){
                    total = initial + current;
                    System.out.printf("%f + %f = %f", initial, current, total);
                    Calculator.l.setText(Double.toString(total));
                }
                else if(previous.equals("-")){
                    total = initial - current;
                    System.out.printf("%f - %f = %f", initial, current, total);
                    Calculator.l.setText(Double.toString(total));
                }
                else if(previous.equals("*")){
                    total = initial * current;
                    System.out.printf("%f * %f = %f", initial, current, total);
                    Calculator.l.setText(Double.toString(total));
                }
                else if(previous.equals("/")){
                    total = initial / current;
                    System.out.printf("%f / %f = %f", initial, current, total);
                    Calculator.l.setText(Double.toString(total));
                }
                else{
                    Calculator.a.setText("Operation error!");
                }
            }
            else if(previous == null){
                total = current;
            }
			//set the flag for operator having been chosen to true
            //point to operator to be processed next time to the operator chosen
            chosen = true;
            if(next.equals("+")){
                previous = "+";
            }
            else if(next.equals("-")){
                previous = "-";
            }
            else if(next.equals("*")){
                previous = "*";
            }
            else if(next.equals("/")){
                previous = "/";
            }
            else if(next.equals("=")){
                Calculator.l.setText(Double.toString(total));
            }
            else if(next.equals("")){
                Calculator.a.setText("Need a number input!");
            }
            else{
                Calculator.a.setText("Next operator error!");
            }
        }
        //otherwise two operators were chosen back to back and it is illegal
        else if(chosen){
            //come up with an error message in the label section
            Calculator.a.setText("Need a number input!");
        }
    }
}