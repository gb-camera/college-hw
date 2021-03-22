#-------------------------------------------------------------
# Name: Michael Dinh
# Date: 10/24/2018
# Reference: Pg. 225, Problem #6
# Title: Distance Traveled
# Inputs: Given vehicle speed in miles per hour, and total number of hours vehicle traveled
# Processes: Determines how far vehicle has traveled in total for each individual hour
# Outputs: Distance vehicle has traveled per hour
#-------------------------------------------------------------
#Start defining modules
#unitsGet prompts the user to input speed and travel time of given vehicle
def unitsGet():
    mph = 0
    hours = 0
    mph = float(input("Enter the speed in MPH of your vehicle. "))
    hours = int(input("Enter the total travel time in integer hours of your vehicle. "))
    return mph, hours
#distLoop performs the main calculations and acts as a running total
def distLoop(mph, hours):
    #Initialize loop variables
    totalDistance = 0
    #Begin the loop
    for counter in range (hours):
        totalDistance = mph * (counter + 1)
        print("For hour", counter + 1, ", distance traveled is", totalDistance, "miles.")
        counter = counter + 1
    return
#Define main module
def main():
    #Initialize main variables
    mph = 0
    hours = 0
    #Begin calling modules
    mph, hours = unitsGet()
    distLoop(mph, hours)
#Call main module
main()