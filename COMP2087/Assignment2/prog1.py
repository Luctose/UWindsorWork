def encrypt(s1):
    s2 = ""

    for char in s1:
        s2 += chr(ord(char) - 9)
    return s2

def decrypt(s1):
    s2 = ""

    for char in s1:
        s2 += chr(ord(char) + 9)
    return s2

def main():
    with open("infileA2Q1.txt", "r") as fp:
        lines = fp.readlines()

    # The question was ambiguous and I didn't feel like asking to clarify. Hopefully this is right.
    # "Read each line of a file infileA2Q1.txt and pass the line (after removing any 
    # whitespace characters at the end) to the function encrypt()"
    # What does "the line" refer to, it is 3AM though so I can just be out of my mind (When am I not)
    # Now that I read it again it makes complete sense. Thanks for reading my schizo rant.
    lines = map(encrypt, (line.rstrip() for line in lines))
    with open("encrypted.txt", "w") as fp:
        fp.writelines(lines)
    
    with open("encrypted.txt", "r") as fp:
        lines = fp.readlines()
    
    lines = map(decrypt, (line.rstrip() for line in lines))
    with open("decrypted.txt", "w") as fp:
        fp.writelines(lines)

    with open("encrypted.txt", "r") as fp:
        lines = fp.readlines()
        print(len(lines))

if __name__ == "__main__":
    main()