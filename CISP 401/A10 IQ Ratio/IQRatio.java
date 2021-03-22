//Michael Dinh - CISP 401 - IQRatio
class RatioInfo{
    //Three instance variables and one static, all are private
    private double GPA, percent;
    private int IQ;
    static private double totalRatio;
    //RatioInfo constructor, takes two arguments that set IQ and GPA and then calls calcRatio
    RatioInfo(double GPA, int IQ){
        this.GPA = GPA;
        this.IQ = IQ;
        calcRatio();
    }
    //calcRatio method, calculates ratio, assigns to percentage, then calls calcTotalRatio by passing the current object
    void calcRatio(){
        this.percent = this.IQ/this.GPA;
        calcTotalRatio(this);
    }
    //getPercentage getter method
    double getPercentage(){
        return this.percent;
    }
    //getGPA getter method
    double getGPA(){
        return this.GPA;
    }
    //getIQ getter method
    int getIQ(){
        return this.IQ;
    }
    //getStatus method, compares ratio of student to overall ratio (which is all ratios combined divided by number of students)
    String getStatus(){
        String status;
        if(this.percent > (totalRatio/Student.getStudentCount())){
            status = "Good";
        }
        else if(this.percent < (totalRatio/Student.getStudentCount())){
            status = "Bad";
        }
        else if(this.percent == (totalRatio/Student.getStudentCount())){
            status = "Average";
        }
        else{
            status = "Error";
        }
        return status;
    }
    //calcTotalRatio method, adds new ratio to totalRatio
    static void calcTotalRatio(RatioInfo obj){
        totalRatio += obj.percent;
    }
}

class Student{
    //Three instance variables and one static variable, all private
    private String fname, lname;
    private RatioInfo ratio;
    static private int numberOfStudents;
    //First constructor, which simply increases the student count (all variables uninitialized)
    Student(){
        numberOfStudents++;
    }
    //Second constructor, which only defines the name strings
    Student(String fname, String lname){
        this();
        this.fname = fname;
        this.lname = lname;
    }
    //Third constructor, which defines all instance variables
    Student(String fname, String lname, double GPA, int IQ){
        this(fname, lname);
        setRatio(GPA, IQ);
    }
    //setRatio setter method, passes GPA and IQ and creates a new RatioInfo object
    void setRatio(double GPA, int IQ){
        this.ratio = new RatioInfo(GPA, IQ);
    }
    //setFname setter method to set a first name
    void setFname(String fname){
        this.fname = fname;
    }
    //setLname setter method to set a last name
    void setLname(String lname){
        this.lname = lname;
    }
    //getStudentName getter method to get student's name
    String getStudentName(){
        String fullName = this.fname + " " + this.lname;
        return fullName;
    }
    //getStudentRatio getter method to get a student's ratio object
    RatioInfo getStudentRatio(){
        return this.ratio;
    }
    //getStudentCount getter method to get the total number of students, static method
    static int getStudentCount(){
        return numberOfStudents;
    }
}

class Driver{
    public static void main(String[] args){
        //Create first object with no argument constructor and use setter methods to assign
        Student JD = new Student();
        JD.setFname("John");
        JD.setLname("Doe");
        JD.setRatio(3.00, 110);
        //Create second object with two argument constructor and use setter method to assign ratio
        Student AD = new Student("Adam", "Davis");
        AD.setRatio(2.00, 90);
        //Create third object with four argument constructor
        Student PA = new Student("Paul", "Avery", 4.00, 140);
        //Display all student info
        System.out.printf("Student #%d is %s, who has a GPA of %.2f and an IQ of %d, with a resulting ratio of %.2f. ", 1, JD.getStudentName(), JD.getStudentRatio().getGPA(), JD.getStudentRatio().getIQ(), JD.getStudentRatio().getPercentage());
        System.out.printf("This student is %saverage.\n", ratioTrans(JD.getStudentRatio().getStatus()));
        System.out.printf("Student #%d is %s, who has a GPA of %.2f and an IQ of %d, with a resulting ratio of %.2f. ", 2, AD.getStudentName(), AD.getStudentRatio().getGPA(), AD.getStudentRatio().getIQ(), AD.getStudentRatio().getPercentage());
        System.out.printf("This student is %saverage.\n", ratioTrans(AD.getStudentRatio().getStatus()));
        System.out.printf("Student #%d is %s, who has a GPA of %.2f and an IQ of %d, with a resulting ratio of %.2f. ", 3, PA.getStudentName(), PA.getStudentRatio().getGPA(), PA.getStudentRatio().getIQ(), PA.getStudentRatio().getPercentage());
        System.out.printf("This student is %saverage.\n", ratioTrans(PA.getStudentRatio().getStatus()));
        return;
    }
    //ratioTrans method, translates status results to a result more desired for information display
    static String ratioTrans(String result){
        String translate;
        if(result == "Good"){
            translate = "above ";
        }
        else if(result == "Bad"){
            translate = "below ";
        }
        else if(result == "Average"){
            translate = "";
        }
        else if(result == "Error"){
            translate = "Ratio Error ";
        }
        else{
            translate = "Translate Error ";
        }
        return translate;
    }
}