#-------------------------------------------------------------
# Name: Michael Dinh
# Date: 10/1/2018
# Reference: Pg. #121, Problem 4
# Title: Auto Costs
# Inputs: User inputs monthly cost of loan payment, insurance, gas, oil, tires, and maintenence individually
# Processes: Calculates total monthly and annual cost of all expenses
# Outputs: Total monthly and annual cost of all input expenses
#-------------------------------------------------------------

#Begin defining modules
#getPrice() asks the user to input prices for all costs
def getPrice():
    loan = float(input("Input the monthly cost of your loan payment. $"))
    insure = float(input("Input the monthly cost of your car insurance. $"))
    gas = float(input("Input the monthly cost of your gas/diesel fuelings. $"))
    oil = float(input("Input the monthly cost of your oil change(s). $"))
    tires = float(input("Input the monthly cost of your tire replacement(s). $"))
    maint = float(input("Input the monthly cost of your car maintenance. $"))
    return loan, insure, gas, oil, tires, maint

#calcMonth() calculates total monthly expense and prints the value
def calcMonth(loan, insure, gas, oil, tires, maint):
    monthCost = loan + insure + gas + oil + tires + maint
    print("The total monthly cost of all expenses is $", format(monthCost, '.2f'), ".")
    return monthCost

#calcYear() calculates total annual expense and prints the value
def calcYear(monthCost):
    yearCost = monthCost * 12
    print("The total annual cost of all expenses is $", format(yearCost, '.2f'), ".")

#Define main()
def main():
    #Initialize local variables
    loan = 0.0
    insure = 0.0
    gas = 0.0
    oil = 0.0
    tires = 0.0
    maint = 0.0
    monthCost = 0.0

    loan, insure, gas, oil, tires, maint = getPrice()
    monthCost = calcMonth(loan, insure, gas, oil, tires, maint)
    calcYear(monthCost)

#Call main()
main()