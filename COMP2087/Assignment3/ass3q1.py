import random

def fib1(max):
    x = 0
    y = 1
    count = 0
    while(x < max):
        print(x)
        count += 1
        z = x + y
        x = y
        y = z
    return count

# Calculates the nth fibonacci number
def fib2(n):
    # Base case
    if n == 1:
        return 0
    elif n == 2:
        return 1
    else:
        return fib2(n-1) + fib2(n-2)

def main():
    max = random.randint(25, 250)
    print(f"max = {max}")
    print("Fibonacci sequence using fib1()")
    print(f"There are {fib1(max)} numbers < {max}")

    n = int(input("Enter an int between 5 and 16: "))
    print("Fibonacci sequence using fib2()")

    for i in range(n):
        print(fib2(i+1))

if __name__ == "__main__":
    main()