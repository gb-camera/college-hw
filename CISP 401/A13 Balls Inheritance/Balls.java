//Michael Dinh - CISP 401 - BallsInheritance
class Ball{
    public double radius;
    public String color;
    Ball(double radius, String color){
        this.radius = radius;
        this.color = color;
    }
    double area(){
        double area = 4 * Math.PI * Math.pow(radius, 2);
        return area;
    }
}

class Basketball extends Ball{
    public int noOfStripes;
    Basketball(int noOfStripes, double radius, String color){
        super(radius, color);
        this.noOfStripes = noOfStripes;
    }
    Basketball(double radius, String color){
        super(radius, color);
        this.noOfStripes = 8;
    }
}

class Driver{
    public static void main(String[] args){
        Basketball basket1 = new Basketball(4, 5.1, "blood red");
        Basketball basket2 = new Basketball(4.7, "orange");
        display(basket1);
        display(basket2);
    }
    static void display(Basketball ball){
        System.out.printf("A basketball with %s color of %.1f in. radius and %d stripes has a surface area of %.2f in².\n", ball.color, ball.radius, ball.noOfStripes, ball.area());
    }
}