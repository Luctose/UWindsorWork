def main():
    # Read the file
    with open("infileA2Q2.txt", "r") as fp:
        d1 = {}
        keysgen = (line.split() for line in fp.readlines())
        for keys in keysgen:
            for key in keys:
                d1.update({key:d1.setdefault(key, 0) + 1})
    
    # Map the keys and values to a function which prints required output
    list(map(lambda a, b: print(f"The word \"{a}\" occurs {b} time(s) in the file."), d1.keys(), d1.values()))

    print(f"No. of unique words in the file is: {len(d1)}")

if __name__ == "__main__":
    main()