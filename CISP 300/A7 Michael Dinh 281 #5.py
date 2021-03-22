#-------------------------------------------------------------
# Name: Michael Dinh
# Date: 11/5/2018
# Reference: Pg. 266, Problem #11
# Title: Rock, Paper, Scissors Game
# Inputs: User inputs their hand in a game of rock, paper, scissors
# Processes: Determines computer's hand and compares the two hands, with tiebreaker functionality
# Outputs: Winner of the game
#-------------------------------------------------------------
#Import the random library
import random
#Begin defining modules / functions
#comPlay determines the computer's hand
def comPlay():
    comValue = 0
    comHand = 0
    comValue = random.randrange(1,4)
    if comValue == 1:
        comHand = "rock"
    elif comValue == 2:
        comHand = "paper"
    elif comValue == 3:
        comHand = "scissors"
    else:
        comHand = "comPlay error"
    return comHand
#userPlay asks the user for their hand, and has a fallback for if the user does not enter a valid hand
def userPlay():
    userHand = input("Enter the hand you wish to play: rock, paper, or scissors. ").casefold()
    valid_plays = ("rock", "paper", "scissors")
    if userHand not in valid_plays:
        print("Error: Input a valid hand.")
        userHand = input("You must play either rock, paper, or scissors. ").casefold()
    return userHand
#hands combines the two previous functions to allow for tiebreaker functionality
def hands():
    userHand = 0
    comHand = 0
    comHand = comPlay()
    userHand = userPlay()
    return userHand, comHand
#showdownCalc determines winner and tie status, and acts accordingly
def showdownCalc(userHand, comHand):
    showdown = False
    print("The computer played", comHand,".")
    if userHand == "rock" and comHand == "scissors" or userHand == "paper" and comHand == "rock" or userHand == "scissors" and comHand == "paper":
        showdown = True
    elif comHand == "rock" and userHand == "scissors" or comHand == "paper" and userHand == "rock" or comHand == "scissors" and userHand == "paper":
        showdown = False
    elif userHand == comHand:
        print("Draw! Tiebreaker will now commence.")
        userHand, comHand = hands()
        showdown = showdownCalc(userHand, comHand)
    else:
        print("showdownCalc error!")
    return showdown
#showdownDet prints whether or not the user or the computer won
def showdownDet(showdown):
    if showdown == True:
        print("You win!")
    elif showdown == False:
        print("The computer wins.")
    else:
        print("showdownDet error!")
#Define main module
def main():
    userHand = 0
    comHand = 0
    showdown = False
    userHand, comHand = hands()
    showdown = showdownCalc(userHand, comHand)
    showdownDet(showdown)
#Call main module
main()