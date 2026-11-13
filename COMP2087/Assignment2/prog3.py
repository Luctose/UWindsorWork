def main():

    with open("infileA2Q3.txt", "r") as fp:
        try:
            mylines = (int(line.rstrip()) for line in fp.readlines())
            # Can't use, generators halt when an exception occurs unfortunatley
            # Have to use poopy way, but don't feel like it

            list(map(stuffToDo, mylines))
        except ValueError as error:
            print("Value on line could not be converted to int")
            print(error)
        except Exception as error:
            print(error)

def stuffToDo(n):
    list1 = [12, 35.8, -9, 23, -18.0, 54]
    print("******")
    if n > 10:
        i = 0.25*n
    else:
        i = n
    print(f"n = {n} ; i = {i}")
    print(f"list1[{i}] = {list1[i]}")
    print(f"list1[{0}]//{i} = {list1[0]//i}")

if __name__ == "__main__":
    main()