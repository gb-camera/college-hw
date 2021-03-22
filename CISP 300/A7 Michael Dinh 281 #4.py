#-------------------------------------------------------------
# Name: Michael Dinh
# Date: 11/14/2018
# Reference: Pg. 281, Problem #4
# Title: Speeding Violation Calculator
# Inputs: User inputs a speed limit and a given driver's speed in MPH
# Processes: Checks if given values are in range and calculates how much the driver was speeding
# Outputs: Amount driver was speeding by in MPH
#-------------------------------------------------------------
#Begin defining modules
#speedInput retrieves speeds from user and checks if given values are in range
def speedInput():
    #Initialize local variables
    speedLimit = 0.0
    driverSpeed = 0.0
    #Begin inputs
    speedLimit = float(input("Input the speed limit of the motorway the driver was speeding on. "))
    #Enter loop to check value
    while 20 > speedLimit or speedLimit > 70:
        print("Error: Speed limit is not in valid range.")
        speedLimit = float(input("Enter a speed limit between 20 and 70 MPH. "))
    driverSpeed = float(input("Input the speed at which the driver was traveling at. "))
    #Enter loop to check value
    while speedLimit > driverSpeed:
        print("Error: Driver speed is less than the given speed limit.")
        driverSpeed = float(input("Input a speed greater than the given speed limit. "))
    return speedLimit, driverSpeed
#speedComp calculates the amount driver was speeding by and prints said value
def speedComp(speedLimit, driverSpeed):
    #Initialize local variables
    spdAmt = 0.0
    spdAmt = driverSpeed - speedLimit
    print("Driver was speeding by", spdAmt,"MPH.")
    return
#Begin defining main module
def main():
    #Initialize local variables
    speedLimit = 0.0
    driverSpeed = 0.0
    print("This program determines the amount at which a driver was speeding via a given speed limit.")
    #Begin calling modules
    speedLimit, driverSpeed = speedInput()
    speedComp(speedLimit, driverSpeed)
#Call main module
main()