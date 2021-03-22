#-------------------------------------------------------------
# Name: Michael Dinh
# Date: 12/12/18
# Reference: Pg. 376, Problem #3
# Title: Rainfall Modification
# Inputs: User inputs rainfall amount for 12 months of a given year
# Processes: Calculates total rainfall, average monthly rainfall, and max/min. rainfall months, then sorts parallel lists by ascending amount of rainfall
# Outputs: Prints total rainfall, average monthly rainfall, min/max. rainfall amounts, and ascending order rainfall amounts and corresponding months
#-------------------------------------------------------------
#rainInput handles user input of all 12 months of rain
def rainInput():
    rain = [0]*12
    index = 0
    print("Please enter your values in milimeters.")
    while index <= 11:
        rain[index] = float(input("Input the rainfall for month #"+ str(index+1) +": "))
        index = index + 1
    return rain
#rainMath handles computations of rain amounts
def rainMath(rain):
    total = 0
    avg = 0
    maximum = 0
    minimum = 0
    index = 0
    minMonth = 0
    maxMonth = 0
    while index <= 11:
        total = total + rain[index]
        index = index + 1
    avg = (total/12)
    index = 0
    maximum = rain[0]
    maxMonth = 1
    while index <= 11:
        if rain[index] > maximum:
            maximum = rain[index]
            maxMonth = index + 1
        index = index + 1
    index = 0
    minimum = rain[0]
    minMonth = 1
    while index <= 11:
        if rain[index] < minimum:
            minimum = rain[index]
            minMonth = index + 1
        index = index + 1
    print("------------------------------------------------------")
    print("The total rainfall for this specified year is "+ str(total) +" mm.")
    print("The average rainfall for any given month in this specified year is "+ str(format(avg, '.2f')) +" mm, rounded to two decimal places.")
    print("The maximum amount of rainfall was "+ str(maximum) +" mm on month "+ str(maxMonth) +".")
    print("The minimum amount of rainfall was "+ str(minimum) +" mm on month "+ str(minMonth) +".")
    return total, avg, maximum, minimum, maxMonth, minMonth
#rainSort handles sorting of rain and month parallel lists and printing of ascending list
def rainSort(rain, month):
    scan = 0
    tempMonth = 0
    tempRain = 0
    printDex = 0
    index = 1
    while index < 12:
        tempRain = rain[index]
        tempMonth = month[index]
        scan = index
        while scan > 0 and rain[scan - 1] > tempRain:
            rain[scan] = rain[scan - 1]
            month[scan] = month[scan - 1]
            scan = scan - 1
        rain[scan] = tempRain
        month[scan] = tempMonth
        index = index + 1
    print("List of months from highest to lowest amount of rainfall:")
    while printDex <= 11:
        print("Month #"+ str(month[printDex]) +": "+ str(rain[printDex]) +" mm")
        printDex = printDex + 1
    return rain, month
#rainWrite module is a test module for writing to files
def rainWrite(rain, sortRain, month, sortMonth, total, avg, maximum, minimum, maxMonth, minMonth):
    with open('rain.txt', 'a') as theFile:
        writeDex = 0
        theFile.write("---Inputted rain amounts and months---\n")
        while writeDex <= 11:
            theFile.write("Month #"+ str(month[writeDex]) +": "+ str(rain[writeDex]) +" mm\n")
            writeDex = writeDex + 1
        writeDex = 0
        theFile.write("---Inputted rain amounts and months in ascending order---\n")
        while writeDex <= 11:
            theFile.write("Month #"+ str(month[writeDex]) +": "+ str(rain[writeDex]) +" mm\n")
            writeDex = writeDex + 1
        theFile.write("---Statistics---\n")
        theFile.write("Total rain: "+ str(total) +" mm\n")
        theFile.write("Average rainfall: "+ str(format(avg,'.2f')) +" mm\n")
        theFile.write("Maximum rainfall: "+ str(maximum) + " mm during month "+ str(maxMonth)+"\n")
        theFile.write("Minimum rainfall: "+ str(minimum) + " mm during month "+ str(minMonth)+"\n")
        theFile.write("----------------------------------------------------------------------\n")
        theFile.close()
#Define main module
def main():
    rain = [0]*12
    sortRain = [0]*12
    month = [1,2,3,4,5,6,7,8,9,10,11,12]
    sortMonth = [1,2,3,4,5,6,7,8,9,10,11,12]
    total = 0
    avg = 0
    maximum = 0
    minimum = 0
    maxMonth = 0
    minMonth = 0
    rain = rainInput()
    total, avg, maximum, minimum, maxMonth, minMonth = rainMath(rain)
    sortRain, sortMonth = rainSort(rain,month)
    rainWrite(rain, sortRain, month, sortMonth, total, avg, maximum, minimum, maxMonth, minMonth)
#Call main
main()