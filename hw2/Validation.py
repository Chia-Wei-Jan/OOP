import math
import random
import time

# Double every second digit from right to left
# If results in a two-digit number, add the two digits to get a single digit number
def getDigit(number):
    number *= 2
    if number >= 10:    # two-digit number
        number = 1 + number - 10
    return number

# Add all single-digit numbers by "getDigit" function
def sumOfDoubleEvenPlace(cardNumber):
    length = len(cardNumber)       # length of card number
    sum = 0

    for i in range(length - 2, -1, -2):
        digit = int(cardNumber[i]) - int('0')
        number = getDigit(digit)
        sum += number

    return sum

# Add all digits in the odd places from right to left in the card number
def sumOfOddPlace(cardNumber):
    length = len(cardNumber)
    sum = 0

    for i in range(length - 1, -1, -2):
        digit = int(cardNumber[i]) - int('0')
        sum += digit

    return sum

# Return true if the card number is valid
def isvalid(cardNumber):
    sum_double = 0
    sum_odd = 0
    sum = 0

    sum_double = sumOfDoubleEvenPlace(cardNumber)
    sum_odd = sumOfOddPlace(cardNumber)
    sum = sum_double + sum_odd

    if sum % 10 == 0:     # divisible by 10
        return True
    else:
        return False

# Return true if substr is the prefix for cardNumber
def startsWith(cardNumber, subStr):
    if subStr[0] == '4' and cardNumber[0] == subStr[0]:
        print('Visa card', end='')
    elif subStr[0] == '5' and cardNumber[0] == subStr[0]:
        print('MasterCard card', end='')
    elif subStr[0] == '6' and cardNumber[0] == subStr[0]:
        print('Discover card', end='')
    elif subStr[0] == '3' and subStr[1] == '7' and cardNumber[0] == subStr[0] and cardNumber[1] == subStr[1]:
        print('American Express card', end='')
    else:
        return False
    return True

# Generate the valid cardNumber
def generate_cardNumber(subStr):

    # End until generate a valid card number
    while True:
        k = 1         # start to generate the number from second digit
        cardNumber = []
        if subStr[0] == '4':
            cardNumber.append('4')
        elif subStr[0] == '5':
            cardNumber.append('5')
        elif subStr[0] == '6':
            cardNumber.append('6')
        elif subStr[0] == '3' and subStr[1] == '7':
            cardNumber.append('3')
            cardNumber.append('7')
            k = 2      # start to generate the number from third digit

        for i in range(k, 16):    # generate other digits
            cardNumber.append(str(random.randint(0, 10)))

        if isvalid(cardNumber) and startsWith(cardNumber, subStr):
            cardNumber = "".join(map(str, cardNumber))
            print(': {}; '.format(cardNumber), end='')
            break


with open('input.txt') as openfileobject:
    for input in openfileobject:
        input = input.rstrip('\n')     # remove newline
        subStr = []
        # input is brand
        if input == "004" or input == "005" or input == "0037" or input == "006":
            # copy prefix of brand to subStr
            if input == "0037":
                subStr.append(input[2])
                subStr.append(input[3])
            else:
                subStr.append(input[2])

            print('Generate a valid ', end='')
            start = time.time()      # timer start
            generate_cardNumber(subStr)     # generate the card number
            end = time.time()       # timer end
            diff = (end - start) * math.pow(10, 6)
            print('Time: ', diff, ' microseconds')
        # input is card number
        elif 13 <= len(input) <= 16:
            if isvalid(input):
                print('{}: a valid '.format(input), end='')
            else:
                print('{}: an invalid '.format(input), end='')

            # copy prefix of card number to subStr
            for i in range(2):
                subStr.append(input[i])

            startsWith(input, subStr)
            print('\n', end='')
        # Error input
        else:
            print('Error input: ', input)
