import random

def main():
    # Part 1
    a = 29175
    # Init seed
    random.seed(a)
    # Ask user for input
    n = int(input("Enter an integer between 5 and 10: "))

    randlist = []
    # Loop through n random values of x
    for i in range(n):
        x = random.randint(i, 10*i + 5)
        print(f"{x:d} was chosen.")
        randlist.append(x)
    
    # Print list result
    print(randlist)

    # Part 2
    # Ask for string
    myinp = input("Enter a string: ")
    # Use last char
    chr = myinp[-1]
    # Ask for int
    n = int(input("Enter an integer between 1 and 15: "))

    # Make sure n is in the correct range and call the fnl()
    if(1 <= n and n <= 15):
        print("chr=" + chr + f", n={n:d}")
        fnl(chr, n)
    else:
        fnl(chr, 15)

# Part 2 function
# 1 <= n <= 15
def fnl(c, n):
    for i in range(n):
        # Format correct string
        mystr = str.format((" " * int(((31-(1+(i*2)))/2))) + (c*int((1+(i*2)))) + (" " * int(((31-(1+(i*2)))/2))))
        print(mystr)


if __name__ == "__main__":
    main()