import sys
import Coin

if __name__ == '__main__':

    if len(sys.argv) > 1:
        inputString = sys.argv[1]
        coin = Coin.Coins(inputString)
    else:
        print("Error input")
