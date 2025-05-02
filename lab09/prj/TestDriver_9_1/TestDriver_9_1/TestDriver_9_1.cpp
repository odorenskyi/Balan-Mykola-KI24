#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <windows.h>
#include "ModulesBalan.h"


using namespace std;


void test_calculateDeposit() {
    cout << "Запуск тестів для функції calculateDeposit:\n\n";

    struct TestCase {
        double amount;
        int months;
        double expectedDaily;
        double expectedTotal;
    };

    TestCase testCases[] = {
        { 10000.0, 0, -1.0000000000000000, -1.0000000000000000 },
        { 10000.0, 6, 5.3424657534246576, 961.64383561643831 },
        { 20000.0, 12, 14.794520547945204, 5326.0273972602736 },
        { 15000.0, 6, 8.0136986301369859, 1442.4657534246574 },
        { 30000.0, 12, 22.191780821917810, 7989.0410958904113 },     
    };

    int testCount = sizeof(testCases) / sizeof(TestCase);
    const double EPSILON = 0.01;

    for (int i = 0; i < testCount; i++) {
        double actualDaily, actualTotal;
        calculateDeposit(testCases[i].amount, testCases[i].months, actualDaily, actualTotal);

        cout << "Тест кейс #" << (i + 1)
            << " | Сума: " << testCases[i].amount
            << " грн, Строк: " << testCases[i].months << " міс." << endl;

        cout << fixed << setprecision(2);

        if (testCases[i].expectedDaily < 0) {
            if (actualDaily < 0 && actualTotal < 0) {
                cout << "Очікувано: Некоректний строк => PASSED\n";
            }
            else {
                cout << "Очікувано: Некоректний строк => FAILED\n";
            }
        }
        else {
            cout << "Очікуване щоденне нарахування: " << testCases[i].expectedDaily << " грн\n";
            cout << "Фактичне щоденне нарахування:   " << actualDaily << " грн\n";

            cout << "Очікувана сума відсотків:      " << testCases[i].expectedTotal << " грн\n";
            cout << "Фактична сума відсотків:       " << actualTotal << " грн\n";

            bool passed = fabs(actualDaily - testCases[i].expectedDaily) < EPSILON &&
                fabs(actualTotal - testCases[i].expectedTotal) < EPSILON;

            cout << "Результат: " << (passed ? "PASSED" : "FAILED") << "\n";
        }

        cout << "-------------------------------------------\n";
    }
}


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(65001);
    SetConsoleCP(1251);
    test_calculateDeposit();
    system("pause");
    return 0;
}