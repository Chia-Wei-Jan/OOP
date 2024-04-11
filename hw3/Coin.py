class Coins:
    def __init__(self, inputString):        # Constructor
        print("object is being created")
        self.__dollar = 0
        self.__cent = 0
        self.__q = 0
        self.__d = 0
        self.__n = 0
        self.__p = 0
        self.__string = inputString

        if self.get_dollar_cent(inputString):
            self.convert()
            self.display()
        else:
            print("Error input")

    def __del__(self):                  # Destructor
        print("Object is being deleted")

    def get_dollar_cent(self, inputString):
        j = 0
        k = 0
        decimalPoint = False
        dollar_arr = []
        cent_arr = []

        for i in range(len(inputString)):
            if not str.isdigit(inputString[i]) and inputString[i] != '.':
                return False

            if inputString[i] == '.':
                decimalPoint = True
            elif not decimalPoint:  # the left of decimal point
                dollar_arr.append(inputString[i])
                j += 1
            elif decimalPoint:  # the right of decimal point
                cent_arr.append(inputString[i])
                k += 1

        if k > 2:  # The smallest unit of US dollar is cent (only two digit)
            return False
        elif k == 1 or k == 0:
            cent_arr.append('0')

       

        str1 = ''.join(dollar_arr)     # convert list to string
        str2 = ''.join(cent_arr)      # convert list to string
        self.__dollar = int(str1)     # convert string to integer
        self.__cent = int(str2)      # convert string to integer

        return True

    def convert(self):    
        money = self.__dollar * 100 + self.__cent  # change to cent

        self.__q = int(money / 25)    # get quarters
        money %= 25
        self.__d = int(money / 10)    # get dimes
        money %= 10
        self.__n = int(money / 5)     # get nickels
        money %= 5
        self.__p = int(money / 1)     # get pennies

    def display(self):     
        print("$", self.__string, " = ", end='')
        print(self.__q, " quarter, ", end='')
        print(self.__d, " dimes, ", end='')
        print(self.__n, " nickels, ", end='')
        print(self.__p, " pennies")
