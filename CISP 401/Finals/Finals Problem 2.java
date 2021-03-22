import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
class Shapes extends JPanel implements ActionListener{
    Shapes(){
        setSize(100, 100);
        setVisible(true);
    }
    public void paint(Graphics g){
        super.paint(g);
        int[] xValues = {25, 25, 75, 75};
        int[] yValues = {25, 75, 75, 25};
        Polygon rectangle = new Polygon(xValues, yValues, 4);
        if(!Problem2.isCircle){
            g.drawPolygon(rectangle);
        }
        else if(Problem2.isCircle){
            g.drawArc(25, 25, 50, 50, 0, 360);
        }
    }
    public void actionPerformed(ActionEvent e){
        String s = e.getActionCommand();
        if(s.equals("Two")){
            Problem2.isCircle = false;
            repaint();
        }
        else if(s.equals("One")){
            Problem2.isCircle = true;
            repaint();
        }
        else{
            System.out.println("whops");
        }
    }
}

class Problem2 extends JFrame{
    static JFrame frame;
    static boolean isCircle = false;
    public static void main(String[] args){
        frame = new JFrame("Change-o-Matic");

        JPanel buttonOne = new JPanel();
        buttonOne.setSize(25, 25);

        JPanel buttonTwo = new JPanel();
        buttonTwo.setSize(25, 25);

        Shapes shapes = new Shapes();
        shapes.setSize(100, 100);

        JButton one, two;
        one = new JButton("One");
        one.addActionListener(shapes);
        two = new JButton("Two");
        two.addActionListener(shapes);

        buttonOne.add(one);
        buttonTwo.add(two);

        frame.setLayout(new GridLayout(1, 3));
        frame.add(buttonOne);
        frame.add(buttonTwo);
        frame.add(shapes);
        frame.setSize(300, 150);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}