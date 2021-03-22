//Michael Dinh - CISP 401 - Pumpkin Image
import java.awt.*;
import javax.swing.*;
class Pumpkin extends JFrame{
    public Pumpkin() {
        setSize(200, 200);
        setVisible(true);
    }
    public void paint(Graphics g){
        //Stem
        g.setColor(Color.green);
        g.drawRect(95, 50, 10, 25);
        g.fillRect(95, 50, 10, 25);

        //Main body
        g.setColor(Color.orange);
        g.drawOval(50, 60, 100, 100);
        g.fillOval(50, 60, 100, 100);

        //Eyes
        g.setColor(Color.black);

        int[] x1 = {70, 75, 80};
        int[] y1 = {90, 100, 90};
        g.drawPolygon(x1, y1, 3);
        g.fillPolygon(x1, y1, 3);

        int[] x2 = {120, 125, 130};
        int[] y2 = y1;
        g.drawPolygon(x2, y2, 3);
        g.fillPolygon(x2, y2, 3);

        //Nose
        int[] x3 = {95, 100, 105};
        int[] y3 = {120, 110, 120};
        g.drawPolygon(x3, y3, 3);
        g.fillPolygon(x3, y3, 3);

        //Mouth
        g.drawOval(65, 130, 70, 15);
        g.fillOval(65, 130, 70, 15);

        //Teeth
        g.setColor(Color.orange);

        int[] x4 = {80, 85, 90};
        int[] y4 = {130, 140, 130};
        g.drawPolygon(x4, y4, 3);
        g.fillPolygon(x4, y4, 3);

        int[] x5 = {110, 115, 120};
        int[] y5 = y4;
        g.drawPolygon(x5, y5, 3);
        g.fillPolygon(x5, y5, 3);

        //Text
        g.setColor(Color.black);
        g.setFont(new Font("Serif", Font.BOLD, 12));
        g.drawString("Jerry the Pumpkin", 50, 45);
        g.drawString("Michael Dinh - CISP 401", 35, 180);
    }
    public static void main(String[] args){
        Pumpkin obj = new Pumpkin();
        obj.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}