def main():
    # Part 1 of Lab
    # Enter name input
    name1 = input("Enter your first name: ")
    # Concatenate to greeting
    my_greeting = "Hello " + name1 + "!"
    # Print greeting
    print(my_greeting)

    # Part 2 of Lab
    # Define list
    mylist = [3, 7, -9, 0, 12, 21]
    # Set sum counter
    sum = 0
    # Sum the list elements
    for i in range(len(mylist)):
        sum = sum + mylist[i]
    
    # Check if pos or neg and print answer
    if sum < 0:
        print('sum is -ve')
    else:
        print('sum =', sum)

# Only run main if run as main code
if __name__ == "__main__":
    main()