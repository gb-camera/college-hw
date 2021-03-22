#-------------------------------------------------------------
# Name: Michael Dinh
# Date: 9/17/2018
# Reference: Pg. #78, Problem 8
# Title: Tax, Tip, Total
# Inputs: User inputs the price of a meal
# Processes: Calculates sales tax and gratuity tip, alongside a combined price for meal, tip, and tax
# Outputs: Sales tax, gratuity tip, and total price for meal
#-------------------------------------------------------------

#Initialize all variables / constants
mealPrice = 0.0
mealTip = 0.0
mealTax = 0.0
finalPrice = 0.0
SERVER_TIP = 0.15
SALES_TAX = 0.07
#Prompt for and input meal price, convert meal price to float / real
mealPrice = float(input("Please input the initial cost of your meal. $"))
#Calculate sales tax, gratuity tip, and final price of meal
mealTip = mealPrice * SERVER_TIP
mealTax = mealPrice * SALES_TAX
finalPrice = mealPrice + mealTip + mealTax
#Display individual sales tax and gratuity tip (rounded to 2 decimal places), and display final price
print("Your tip is $", (format(mealTip, '.2f')), ", your tax is $", (format(mealTax, '.2f')), ", and your final meal cost is $", (format(finalPrice, '.2f')), ".")