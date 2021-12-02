#include <iostream>

int addint(int a, int b);

int main(){
    int a, b;
    std::cout << "Enter number 1: ";

    std::cin >> a;

    std::cout << "Enter number 2: ";

    std::cin >> b;

    std::cout << addint(a, b);
    return 0;
}

int addint(int a, int b){
    return a + b;
}