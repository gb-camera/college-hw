//Michael Dinh - CISP 401 - Graphics Paint (Circles and Lines)
import javax.swing.*;
import java.awt.*;
class GraphicsPaint {
	public static void main(String[] args) {
		new FrameA("FrameA").setVisible(true);
		new FrameB("FrameB").setVisible(true);
	}
}

class FrameA extends JFrame{
	public FrameA(String title){
        setSize(250, 250);
    }
	public void paint(Graphics g){
        g.setColor(Color.BLUE);

        g.drawLine(75, 75, 175, 75);
        g.drawLine(110, 100, 75, 75);
        g.drawLine(110, 50, 75, 75);
        g.drawLine(140, 50, 175, 75);
        g.drawLine(140, 100, 175, 75);
        
        g.drawLine(75, 175, 175, 175);
        g.drawLine(40, 150, 75, 175);
        g.drawLine(40, 200, 75, 175);
        g.drawLine(210, 150, 175, 175);
        g.drawLine(210, 200, 175, 175);

    }
}

class FrameB extends JFrame{
	public FrameB(String title){
        setSize(250, 250);
    }
	public void paint(Graphics g){	
        g.setColor(Color.BLACK);
        g.fillRect(0, 0, 125, 250);
        g.setColor(Color.GRAY);
        g.fillOval(15, 90, 100, 100);
        g.fillOval(130, 90, 100, 100);
    }
}
