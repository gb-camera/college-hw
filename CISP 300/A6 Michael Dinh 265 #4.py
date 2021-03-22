#-------------------------------------------------------------
# Name: Michael Dinh
# Date: 11/5/2018
# Reference: Pg. 265, Problem #4
# Title: Max of 2 Values
# Inputs: User inputs two integer values
# Processes: Determines which value is greater, and resolves if values are equal
# Outputs: Greatest value
#-------------------------------------------------------------
#Begin defining modules / functions
#inputVal handles user input of two values
def inputVal():
    val1 = int(input("Input the first integer value. "))
    val2 = int(input("Input the second integer value. "))
    return val1, val2
#max handles decision of greater value, and handles value equivlanency
def max(val1, val2):
    maxVal = 0
    if val1 > val2:
        maxVal = val1
    elif val1 < val2:
        maxVal = val2
    elif val1 == val2:
        while val1 == val2:
            print("Error! Values are equal; please input two new values.")
            val1, val2 = inputVal()
            if val1 != val2:
                if val1 > val2:
                    maxVal = val1
                elif val1 < val2:
                    maxVal = val2
                else:
                    print("Error!")
    else:
        print("Error!")
    return maxVal
#printVal prints the maxVal variable
def printVal(maxVal):
    print("The greater integer value is", maxVal,".")
#Define main module
def main():
    #Initialize variables
    val1 = 0
    val2 = 0
    maxVal = 0
    #User-friendly intro
    print("This program determines the greater value of two given integer values.")
    #Call functions / modules
    val1, val2 = inputVal()
    maxVal = max(val1, val2)
    printVal(maxVal)
#Call main
main()