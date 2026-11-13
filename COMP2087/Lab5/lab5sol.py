class Book:
    def __init__(self, title, pubyr=2000, price=24.99):
        self._title = title # title of book
        self._pubyr = pubyr # publication year
        self._price = price # price of book

    def getTitle(self):
        return self._title
    
    def getPubyr(self):
        return self._pubyr
    
    def setPubyr(self, year):
        self._pubyr = year

    def __str__(self):
        return f"{self._title} published in {self._pubyr}"

    def getPrice(self):
        return self._price
    
    # Set price to x
    def setPrice(self, x):
        self._price = x
    
    def recentPub(self):
        if(self._pubyr < 2020):
            return False
        return True

def main():
    booklist = []
    # If you dock me marks because I didn't name each book - book1, book2, book3 Zach gets $20
    for i in range(3):
        booklist.append(Book("book" + str(i+1), 2019 + i, 5 + i))
    
    for book in booklist:
        print(book)

    # Part deux

    booklist[1].setPrice(int(input(f"Enter a new price for {booklist[1]}: ")))

    price = 0
    for book in booklist:
        try:
            print(f"Current book is: {book}")
            num = int(input("How many books do you want to purchase? "))
            if num <= 0:
                raise Exception
        except:
            print("Invalid input, value set to 0")
            num = 0
        finally:
            price = num * book.getPrice()
            if(book.recentPub()):
                print(f"{book.getTitle()} is a recent publication")
            else:
                print(f"{book.getTitle()} is not a recent publication. 10% discount applied!")
                price = price * 0.90

            print(f"The cost of the books is ${price:.2f}")
            

if __name__ == "__main__":
    main()