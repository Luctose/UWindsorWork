# Hi
# Angelo, 
# I 
# broke 
# my 
# toe 
# yesterday.

# Zach said at 1:45pm on 11/06/2024 - "You should tell Angelo that"
# What did I say? Well lets just say something to do with my penits.

def main():
    # Part 1
    list1 = ['alpha', 'beta', 'delta', 'zeta', 'eta', 'theta', 'nu']
    list2 = ['one', 'two', 'three', 4, 5, 6, 7, 8, 9]

    d1 = dict(zip(list1, list2))
    print(d1)
    print(f"d1 values = {d1.values()}")

    s = input("Please enter a string: ")
    try:
        print(f"d1[{s}] = {d1[s]}")
    except:
        print("The key was not found in d1")
    
    # Part 2
    try:
        i = int(input("Enter an integer: "))
    except ValueError as err:
        print(err)
        exit(1)
    
    try:
        print(list2[i])
    except:
        print("Index out of range")
    
    j = int(input(f"Enter an integer between 0 and {len(list1) - 1}: "))

    try:
        print(f"list1[j] + list2[j] = {list1[j] + list2[j]}")
    except Exception as err:
        print(err)
    finally:
        print("Done!")

if __name__ == "__main__":
    main()