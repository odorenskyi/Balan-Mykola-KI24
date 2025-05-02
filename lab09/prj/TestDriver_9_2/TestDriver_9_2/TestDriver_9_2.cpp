#include <iostream>
#include <cmath>
#include <iomanip>
#include "ModulesBalan.h"
#include <windows.h>


using namespace std;

void test_calculateAverageTemperature() {
    cout << "Запуск тестів для функції calculateAverageTemperature:\n\n";

    struct TestCase {
        double tempsC[7];
        int size;
        double expectedAvgC;
        double expectedAvgF;
    };

    TestCase testCases[] = {
        { {10, 12, 11, 13, 14, 15, 10}, 7, 12.14, 53.85 },
        { {0, 0, 0, 0, 0, 0, 0}, 7, 0.00, 32.00 },
        { {-5, -3, -2, -4, -6, -3, -5}, 7, -4.00, 24.80 },
        { {20, 22, 19, 21, 23, 22, 20}, 7, 21.00, 69.80 },
        { {5, 7, 6, 8, 7, 9, 10}, 7, 7.43, 45.37 }
    };

    const double EPSILON = 0.01;
    int testCount = sizeof(testCases) / sizeof(TestCase);

    for (int i = 0; i < testCount; i++) {
        double actualAvgC = 0, actualAvgF = 0;

        calculateAverageTemperatureForTest(testCases[i].tempsC, testCases[i].size, actualAvgC, actualAvgF);

        cout << "Тест кейс #" << (i + 1) << " | Розмір: " << testCases[i].size << "\n";

        cout << fixed << setprecision(2);

        cout << "Очікувана температура (°C): " << testCases[i].expectedAvgC << "\n";
        cout << "Фактична температура (°C):   " << actualAvgC << "\n";

        cout << "Очікувана температура (°F): " << testCases[i].expectedAvgF << "\n";
        cout << "Фактична температура (°F):   " << actualAvgF << "\n";

        bool passed = fabs(actualAvgC - testCases[i].expectedAvgC) < EPSILON &&
            fabs(actualAvgF - testCases[i].expectedAvgF) < EPSILON;

        cout << "Результат: " << (passed ? "PASSED" : "FAILED") << "\n";
        cout << "-------------------------------------------\n";
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(65001);
    SetConsoleCP(1251);
    // Тестуємо розрахунок депозиту
    test_calculateAverageTemperature();
    cout << "\n============================\n\n";

    return 0;
}