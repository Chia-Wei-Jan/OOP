count = 0
summation = 0
grade = 0
average = 0.0

while True:
    string = input('Please input your score:\n')  # Read the input string
    length = len(string)     # Get the length of string

    # Check the illegal input
    for i in range(length):
        if i == 0 and string[i] == '-':
            continue
        if not(string[i] >= '0' and string[i] <= '9'):
            print('Illegal input, ending the program...')
            exit()

    grade = int(string)   # Convert string to int

    if grade == -1 and count != 0:    # Compute the average
        break

    # Check the boundary (0-100)
    if grade < 0 or grade > 100:
        print('Illegal input, ending the program...')
        exit()

    summation += grade
    count += 1

# Compute the average
average =  summation / count
print('Your average score is: {:.2f}'.format(average))

