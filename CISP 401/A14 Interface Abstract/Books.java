//Michael Dinh - CISP 401 - InterfaceAbstract
interface Amount{
    void setPrice();
}

abstract class Book implements Amount{
    String title;
    double price;
    Book(String title){
        this.title = title;
        this.price = 0.00;
    }
    String getTitle(){
        return this.title;
    }
    double getPrice(){
        return this.price;
    }
    abstract public void setPrice();
}

class Nonfiction extends Book{
    Nonfiction(String title){
        super(title);
    }
    public void setPrice(){
        this.price = 37.99;
    }
}

final class Fiction extends Book{
    String rating;
    Fiction(String title, String rating){
        super(title);
        this.rating = rating;
    }
    public void setPrice(){
        this.price = 24.99;
    }
    String getRating(){
        return this.rating;
    }
}

class Adults extends Nonfiction{
    String level;
    Adults(String title, String level){
        super(title);
        this.level = level;
    }
    public void setPrice(){
        this.price = 50.00;
    }
    String getLevel(){
        return this.level;
    }
}

class Driver{
    static Book[] books;
    public static void main(String[] args){
        books = new Book[3];
        books[0] = new Nonfiction("My Thoughts on Keanu Reeves");
        books[0].setPrice();
        books[1] = new Fiction("I Am a Cat", "G");
        books[1].setPrice();
        books[2] = new Adults("Devil May Cry", "Exciting");
        books[2].setPrice();
        System.out.println("----------");
        System.out.printf("Nonfiction: %s\nPrice: $%.2f\n----------\n", books[0].getTitle(), books[0].getPrice());
        System.out.printf("Fiction: %s\nRating: %s\nPrice: $%.2f\n----------\n", books[1].getTitle(), ((Fiction)books[1]).getRating(), books[1].getPrice());
        System.out.printf("Nonfiction Adults: %s\nLevel: %s\nPrice: $%.2f\n----------", books[2].getTitle(), ((Adults)books[2]).getLevel(), books[2].getPrice());
    }
}