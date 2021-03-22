#-------------------------------------------------------------
# Name: Michael Dinh
# Date: 10/1/2018
# Reference: Pg. #121, Problem 1
# Title: Kilometer Converter
# Inputs: User inputs a distance in kilometers
# Processes: Converts kilometer value into miles
# Outputs: Distance in miles
#-------------------------------------------------------------

#Begin defining modules
#getKilos() prompts the user for the initial kilometer value
def getKilos():
    kms = float(input("Enter the distance in kilometers you want to convert."))
    return kms

#convertKilos() converts the kilometer value to miles
def convertKilos(kms):
    miles = kms * 0.6214
    return miles

#printMiles() prints the converted value
def printMiles(miles):
    print("In miles, your inputed distance rounded to 4 decimal places is about", format(miles, '.4f'), "miles.")

#Begin defining main()
def main():
    #Initialize local variables
    kilos = 0.0
    miles = 0.0

    kilos = getKilos()
    miles = convertKilos(kilos)
    printMiles(miles)

#Call main()
main()