import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

class HitAndBlow extends JFrame implements ActionListener{
    // Create frame, textfield
    static JFrame silver;
    static JTextArea l;

    //Declare collections
    java.util.List<Integer> list = new ArrayList<Integer>();
    Stack<Integer> stack = new Stack<Integer>();
    Queue<Integer> queue = new LinkedList<Integer>();
    Vector<Integer> vector = new Vector<Integer>();

    //Declare map and linked key set 
    Map<Integer, Integer> map = new HashMap<Integer, Integer>();
    Set<Integer> set = map.keySet();

    //Main
    public static void main(String[] args){
        //Declare JFrame, object, and text area
        silver = new JFrame("Hit and Blow");
        HitAndBlow c = new HitAndBlow();
        l = new JTextArea(3, 40);

        //Set text area styling
        l.setLineWrap(true);
        l.setWrapStyleWord(true);
        l.setEditable(false);
        l.setText("Collections Graphics / Michael Dinh / CISP 401");

        //Declare buttons
        JButton bGen, bQue, bList, bVec, bMap;

        //Generate button
        bGen = new JButton("Generate");
        bGen.setForeground(Color.RED);
        bGen.addActionListener(c);

        //Queue button
        bQue = new JButton("Queue");
        bQue.setForeground(Color.GREEN);
        bQue.addActionListener(c);

        //List button
        bList = new JButton("List");
        bList.setForeground(Color.BLUE);
        bList.addActionListener(c);

        //Vector button
        bVec = new JButton("Vector");
        bVec.setForeground(Color.BLACK);
        bVec.addActionListener(c);

        //Map button
        bMap = new JButton("Map");
        bMap.setForeground(Color.ORANGE);
        bMap.addActionListener(c);

        //Declare JPanels
        JPanel hit = new JPanel();
        JPanel blow = new JPanel();

        //Add elements to JPanels
        hit.add(bGen);
        hit.add(bQue);
        hit.add(bList);
        hit.add(bVec);
        hit.add(bMap);
        blow.add(l);

        //Build the JFrame
        silver.setLayout(new FlowLayout());
        silver.add(hit);
        silver.add(blow);
        silver.setSize(450, 150);
        silver.setVisible(true);
        silver.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    //ActionListener
    public void actionPerformed(ActionEvent e){
        String s = e.getActionCommand();
        //Stack branch
        if(s.equals("Generate")){
            Random random = new Random();
            for(int i = 0; i < 5; i++){
                stack.push(random.nextInt(100) + 1);
            }
            l.setText("Now in stack: " + Arrays.toString(stack.toArray()));
        }
        //Queue branch
        else if(s.equals("Queue")){
            if(stack.isEmpty()){
                if(queue.isEmpty()){
                    l.setText("Stack and queue are empty!");
                    return;
                }
                else if(!queue.isEmpty()){
                    l.setText("Stack is empty! Now in queue: " + Arrays.toString(queue.toArray()));
                    return;
                }
            }
            queue.add(stack.pop());
            l.setText("Now in queue: " + Arrays.toString(queue.toArray()));
        }
        //List branch
        else if(s.equals("List")){
            if(queue.isEmpty()){
                if(list.isEmpty()){
                    l.setText("Queue and list are empty!");
                    return;
                }
                else if(!list.isEmpty()){
                    l.setText("Queue is empty! Now in list: " + Arrays.toString(list.toArray()));
                    return;
                }
            }
            list.add(queue.remove());
            l.setText("Now in list: " + Arrays.toString(list.toArray()));
        }
        //Vector branch
        else if(s.equals("Vector")){
            if(list.isEmpty()){
                if(vector.isEmpty()){
                    l.setText("List and vector are empty!");
                    return;
                }
                else if(!vector.isEmpty()){
                    l.setText("List is empty! Now in vector: " + Arrays.toString(vector.toArray()));
                    return;
                }
            }
            vector.add(list.remove(0));
            l.setText("Now in vector: " + Arrays.toString(vector.toArray()));
        }
        //Map branch
        else if(s.equals("Map")){
            if(vector.isEmpty()){
                if(map.isEmpty()){
                    l.setText("Vector and map are empty!");
                    return;
                }
                if(!map.isEmpty()){
                    l.setText("Vector is empty! Currently in map: ");
                    map.forEach((k,v) -> l.append("[" + k + ", " + v + "] "));
                    return;
                }
            }
            //Key duplication check
            Random random = new Random();
            Boolean dupe = true;
            int posKey;
            do{
                dupe = false;
                posKey = random.nextInt(100) + 1;
                for(Iterator<Integer> keys = set.iterator(); keys.hasNext();){
                    Integer compareKey = keys.next();
                    if(posKey == compareKey){
                        dupe = true;
                        break;
                    }
                }
            }while(dupe);
            map.put(posKey, vector.remove(0));
            l.setText("Currently in map: ");
            map.forEach((k,v) -> l.append("[" + k + ", " + v + "] "));
        }
        //Default
        else{
            l.setText("Error!");
        }
    }
}