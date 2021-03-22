#-------------------------------------------------------------
# Name: Michael Dinh
# Date: 12/12/18
# Reference: Pg. 376, Problem #2
# Title: Sorted Names
# Inputs: User inputs 20 names
# Processes: Sorts list of strings with names by ascending alphabetical order
# Outputs: List of 20 names printed ascending alphabetically
#-------------------------------------------------------------
#nameInput handles user input of 20 names
def nameInput(SIZE):
    names = ["A"]*20
    num = 0
    while num <= SIZE - 1:
        names[num] = input("Input name #"+ str(num+1) +": ")
        num = num + 1
    return names
#nameSort handles sorting of the list to ascending alphabetical order
def nameSort(names,SIZE):
    scan = 0
    temp = 0
    num = 1
    while num < SIZE:
        temp = names[num]
        scan = num
        while scan > 0 and names[scan - 1] > temp:
            names[scan] = names[scan - 1]
            scan = scan - 1        
        names[scan] = temp
        num = num + 1
    return names
#namePrint handles printing of sorted list
def namePrint(names):
    print("Following is the names you input in alphabetical order:")
    print('\n'.join(names))
    return
#Define main module
def main():
    names = ["A"]*20
    sortNames = ["A"]*20
    SIZE = 20
    print("This program will sort 20 names you input into it.")
    names = nameInput(SIZE)
    sortNames = nameSort(names,SIZE)
    namePrint(sortNames)
#Call main
main()