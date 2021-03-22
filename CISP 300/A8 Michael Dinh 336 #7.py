#-------------------------------------------------------------
# Name: Michael Dinh
# Date: 12/5/2018
# Reference: Pg. 336, Problem #7
# Title: Phone Number Lookup
# Inputs: User inputs a search query (pref. a name)
# Processes: Program searches through a list of people sequentially and tries to find a match
# Outputs: Either a name and a phone number in the case of a match, or a no match message otherwise
#-------------------------------------------------------------
#infoQuery handles the bulk of the processing (input, input validation, sequential search, message printing, etc.)
def infoQuery(people, phoneNumbers):
    found = False
    index = 0
    search = ""
    search = input("Enter the name (partial or full) of the person whose number you want to find. ")
    if isinstance(search,str) == False:
        search = input("Error! Input a valid string for search. ")
    while found == False and index < len(people):
        if search.casefold() in people[index].casefold():
            found = True
        else:
            index = index + 1
    if found == True:
        print("Match found!", people[index], "—", phoneNumbers[index])
    else:
        print("No matches found.")
#Define main module
def main():
    #Define parallel arrays in main for modularization
    people = ["Robin Wong", "Breland Schaefer", "Cole Bronson", "Zoe Marie", "Jaxon Sealey", "Amadeus Miller", "Olivia Meower"]
    phoneNumbers = ["(551) 787-0529","(237) 706-1535","(387) 791-8177","(790) 360-8133","(551) 926-5543","(794) 786-5058","(684) 754-1101"]
    #Call infoQuery
    print("This program allows you to search for the phone number of seven people.")
    infoQuery(people, phoneNumbers)
#Call main
main()