#-------------------------------------------------------------
# Name: Michael Dinh
# Date: 10/10/2018
# Reference: Pg. 169, Problem #3
# Title: Mass and Weight
# Inputs: User inputs a given mass in kilograms
# Processes: Calculates newton weight from kilogram mass, and determines if newton weight is in range
# Outputs: Either a valid newton weight, an error for weight being too heavy / light, or an error for invalid mass value
#-------------------------------------------------------------
#Define global constants
NEWTON_HIGH = 1000.0
NEWTON_LOW = 10.0

#Begin defining modules
#getMass() prompts the user for the mass in kilograms
def getMass():
    mass = float(input("Please enter the desired mass to convert to newtons in kilograms: "))
    return mass

#calcWeight() converts mass into weight by given formula
def calcWeight(mass):
    weight = mass * 9.8
    return weight

#detValidity() determines if the weight is in range, and informs the user accordingly; if valid, weight is also printed
def detValidity(newt):
    if newt < NEWTON_LOW:
        print("Weight is too light!")
    elif newt > NEWTON_LOW and newt < NEWTON_HIGH:
        print("Weight is about", format(newt, '.5f'), "newtons, rounded to five decimal places.")
    elif newt > NEWTON_HIGH:
        print("Weight is too heavy!")
    else:
        print("Error!")

#Define main()
def main():
    #Initialize local variables
    mass = 0.0
    weight = 0.0
    #Begin calling modules
    mass = getMass()
    weight = calcWeight(mass)
    detValidity(weight)

#Call main()
main()