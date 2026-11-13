import math

def main():
    n = float(input("Enter a positive number: "))
    while(n <= 0):
        n = float(input("Number must be positive!\nPlease enter a positive number: "))
    # Here is a comment that describes this complicated code
    print(f"The square root of {n:f} is {math.sqrt(n):f}")
    print(f"The value of pi in the math module is {math.pi:f}")
    print(f"The circumference of a circle of radius 12 is {2*math.pi*12:f}cm")
    print(f"The area of a circle of radius 12 is {math.pi*math.pow(12, 2):f}cm^2")

if __name__ == "__main__":
    main()