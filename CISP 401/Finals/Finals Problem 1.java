import javax.swing.*;
import java.awt.*;
class Problem1 extends JFrame{
    public Problem1(){
        setSize(100, 100);
        setVisible(true);
    }
    public void paint(Graphics g){
        super.paint(g);
        g.setColor(Color.red);
        g.drawArc(20, 50, 25, 25, 180, -180);
        g.drawString("Hello", 70, 50);

        g.setColor(Color.green);
        g.drawString("How", 70, 60);

        g.setColor(Color.blue);
        g.drawString("Are", 70, 70);

        g.setColor(Color.black);
        g.drawArc(20, 50, 25, 25, 90, -180);
        g.drawString("You", 70, 80);
    }
	public static void main(String[] args){
		Problem1 a = new Problem1();
		a.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}