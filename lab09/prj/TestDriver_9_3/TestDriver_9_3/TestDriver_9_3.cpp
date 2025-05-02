#include <iostream>
#include <cmath>
#include <iomanip>
#include "ModulesBalan.h"
#include <windows.h>

using namespace std;

void test_analyzeBits() {
    cout << "Запуск тестів для функції analyzeBits:\n\n";

    struct TestCase {
        int input;
        int expected;
    };

    TestCase testCases[] = {
        { 1, 1 },
        { 256, 8 },            
        { 511, 0 },            
        { 17948360, 12 },       
        { -1, -1 },            
    };

    int testCount = sizeof(testCases) / sizeof(TestCase);

    for (int i = 0; i < testCount; i++) {
        int result = analyzeBits(testCases[i].input);

        cout << "Тест кейс #" << (i + 1) << " | Вхідне число: " << testCases[i].input << "\n";
        cout << "Очікуваний результат: " << testCases[i].expected << "\n";
        cout << "Фактичний результат:   " << result << "\n";

        bool passed = result == testCases[i].expected;

        cout << "Результат: " << (passed ? "PASSED" : "FAILED") << "\n";
        cout << "-------------------------------------------\n";
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(65001);
    SetConsoleCP(1251);

    // Тестуємо аналіз бітів
    test_analyzeBits();

    cout << "\n============================\n\n";

    // Тестуємо середню температуру
    test_analyzeBits();

    return 0;
}
