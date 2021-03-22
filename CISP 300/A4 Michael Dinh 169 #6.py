#-------------------------------------------------------------
# Name: Michael Dinh
# Date: 10/10/2018
# Reference: Pg. 169, Problem #6
# Title: Book Club Points
# Inputs: User inputs number of books bought from a store
# Processes: Determines point value based on number of books bought
# Outputs: Number of points user earns in correlation to number of books input
#-------------------------------------------------------------
#Start defining modules
#getBooks() prompts the user for the number of books bought
def getBooks():
    books = int(input("Welcome to the Serendipity Booksellers Book Club Awards Points Calculator! Please enter the number of books you've purchased today: "))
    return books
#defPoints() determines what points tier a user qualifies for based on book value
def detPoints(books):
    if books < 1:
        print("You've earned 0 points; buy at least one book to qualify!")
    elif books == 1:
        print("You've earned 5 points!")
    elif books == 2:
        print("You've earned 15 points!")
    elif books == 3:
        print("You've earned 30 points!")
    elif books > 3:
        print("Super reader! You've earned 60 points!")
    else:
        print("Error!")
#Define main()
def main():
    #Intialize local variable
    books = 0.0
    #Begin calling modules
    books = getBooks()
    detPoints(books)
#Call main
main()