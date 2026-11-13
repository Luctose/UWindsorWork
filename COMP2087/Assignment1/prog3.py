import random
# This make dec num go bin
def dec2bin(n):
    output = ""
    while(n > 0):
        rem = n % 2
        output = str(rem) + output
        n = n // 2
    return output

def main():
    # The code that does the thing
    num = random.randint(1000, 5000)
    print(f"num = {num:d}")
    print(f"The binary representation of {num:d} is {dec2bin(num):s}")

if __name__ == "__main__":
    main()