#-------------------------------------------------------------
# Name: Michael Dinh
# Date: 12/5/2018
# Reference: Pg. 336, Problem #2
# Title: Lottery Number Generator
# Inputs: None
# Processes: Randomly selects seven integers between 0 and 9 and assigns them to a seven-element list, then prints all seven (akin to a lottery machine)
# Outputs: Seven randomly selected integers between 0 and 9 from a list
#-------------------------------------------------------------
#Import random library for RNG
import random
#lottoDraw randomly selects all seven integers and assigns them to a list through a loop
def lottoDraw():
    num = [0,0,0,0,0,0,0]
    drawVar = 0
    while drawVar < 7:
        num[drawVar] = random.randint(0,9)
        drawVar = drawVar + 1
    return num
#lottoPrint sequentially steps through the list and prints all values
def lottoPrint(num):
    printVar = 0
    while printVar < 7:
        print("The number", num[printVar],"was drawn!")
        printVar = printVar + 1
    print("The full winning number is",num,"!")
    return
#Define main module
def main():
    num = [0,0,0,0,0,0,0]
    #Begin calling modules
    print("This program will draw a winning lottery number, formatted with seven numbers from 0 to 9!")
    num = lottoDraw()
    lottoPrint(num)
#Call main module
main()