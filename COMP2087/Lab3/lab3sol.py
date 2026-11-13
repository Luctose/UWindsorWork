# Mcdonalds, take the marks away I wasn't in the lab I forgor

def main():
    # Part 1
    # Open file
    with open("lab3in.txt") as fp:

        # Read ze lines
        lines = fp.readlines()
        n = len(lines)
        sum = 0
        for line in lines:
            line = line.rstrip() # What I did to your mother
            e = get_e(line)
            sum += e
            print(f"line = {line} # of e's = {e:d}")
    print(f"average # of occurences of \"e\" per line = {sum/n:.2f}")
    
    # Part 2
    wlist = makeWordList(lines)

    for item in wlist:
        print(f"The words in this line: {item}")

    with open("lab3out.txt", "w") as fp:
        for line in lines:
            fp.write(line.upper())
        fp.write('\n' + str(makeWordSet(wlist)))


# Gets number of e's in a string
def get_e(line):
    sum = 0
    for char in line:
        if char == 'e':
            sum += 1
    return sum

# Makes the word list
def makeWordList(lines):
    wlist = list()
    for line in lines:
        wlist.append(line.split())
    return wlist

# Makes the set list
def makeWordSet(wlist):
    newlist = []
    for sublist in wlist:
        for word in sublist:
            newlist.append(word)
    return set(newlist)

if __name__ == "__main__":
    main()