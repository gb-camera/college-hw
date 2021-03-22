#-------------------------------------------------------------
# Name: Michael Dinh
# Date: 9/17/2018
# Reference: Pg. #78, Problem 10
# Title: Stock Transaction
# Inputs: None
# Processes: Calculates gains and losses from the given information in problem 10
# Outputs: Amount paid by Joe for stocks, amount Joe sold for stocks, both commission prices paid by Joe, and total profit (either as a gain or loss)
#-------------------------------------------------------------

#Initialize constants
STOCKS = 1000
PRICE_INT = 32.87
PRICE_AFT = 33.92
COMMISSION = 0.02
COMMISSION_VAR = 2
#Initialize variables
stockPaid = 0.0
stockGain = 0.0
firstCom = 0.0
secondCom = 0.0
buyTotal = 0.0
sellTotal = 0.0
gain_loss = 0.0
#Calculate stock purchase price, first commission
stockPaid = STOCKS * PRICE_INT
firstCom = stockPaid * COMMISSION
#Calculate stock selling price, second commission
stockGain = STOCKS * PRICE_AFT
secondCom = stockGain * COMMISSION
#Calculate total purchase and sell price
buyTotal = stockPaid + firstCom
sellTotal = stockGain - secondCom
#Calculate the total profit
gain_loss = sellTotal - buyTotal
#Print and format all variables
print("Joe paid an initial $", (format(stockPaid, '.2f')), "for all", STOCKS, "stocks at a rate of $", PRICE_INT, ".")
print("Joe paid his stockbroker $", (format(firstCom, '.2f')), "when buying his stocks at a commission rate of", COMMISSION_VAR, "%.")
print("Joe sold all", STOCKS, "stocks for $", (format(stockGain, '.2f')), "at a rate of $", PRICE_AFT, "per stock.")
print("Joe paid his stockbroker $", (format(secondCom, '.2f')), "when selling his stocks at a commission rate of", COMMISSION_VAR, "%.")
print("In total, Joe lost $", (format(gain_loss, '.2f')), "from this endeavor.")
