#include <iostream>
#include <conio.h>
#include "BalanLib.h"
#include "ModulesBalan.h"
using namespace std;

int calculateResult(int a, int b) {
    return (a <= b - 32) ? 1 : 0;
}

int main() {
    // 8.2.1
    Information();
    
    int a, b;
    std::cout << "Введіть значення a: ";
    std::cin >> a;
    std::cout << "Введіть значення b: ";
    std::cin >> b;
    //8.2.2
    int resultB = calculateResult(a, b);
    //8.2.3
    double result = calculateS(7, 3, 6);
    std::cout << "Результат: " << resultB <<endl;
    cout << "ModulesBalan.h : " << result<<endl;
    _getch();
    return 0;
}

