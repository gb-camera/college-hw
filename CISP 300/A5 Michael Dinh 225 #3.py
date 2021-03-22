#-------------------------------------------------------------
# Name: Michael Dinh
# Date: 10/24/2018
# Reference: Pg. 225, Problem #3
# Title: Budget Analysis
# Inputs: Total budget for a given month, as well as all expenses for said month
# Processes: Determines total expenses and whether or not user is over, under, or on budget
# Outputs: Total expenses, whether or not user is over / under / on budget
#-------------------------------------------------------------
#Define modules
#getBudget prompts the user for their monthly budget
def getBudget():
    budget = float(input("What is your budget allocation for this month? "))
    return budget
#spentCalc prompts the user for all expenses and calculates total expenses and difference from budget
def spentCalc(budget):
    #Initialize totalSpent and spentVal
    totalSpent = 0
    spentVal = 1
    #Begin constructing expense loop
    while spentVal > 0:
        spentVal = float(input("Enter an expense cost, or input anything less than $1 to end. "))
        totalSpent = totalSpent + spentVal
    print("Total expenses for this month is $", (format(totalSpent,'.2f')))
    difference = abs(budget - totalSpent)
    return totalSpent, difference
#budgetDet determines whether user is over, under, or on budget and outputs accordingly
def budgetDet(budget, totalSpent, difference):
    if totalSpent < budget:
        print("You are under your budget by $", (format(difference,'.2f')), "!")
    elif totalSpent == budget:
        print("You are exactly on budget!")
    elif totalSpent > budget:
        print("You are over your budget by $", (format(difference,'.2f')), "!")
    else:
        print("Error!")
#Define main module
def main():
    #Initialize variables
    budget = 0
    totalSpent = 0
    difference = 0
    #Begin calling modules
    budget = getBudget()
    totalSpent, difference = spentCalc(budget)
    budgetDet(budget, totalSpent, difference)
#Call main module
main()