#include <iostream>
#include "ModulesBalan.h"
#include <windows.h>
#include <conio.h>

using namespace std;

void test_s_calculation() {
    double x[10] = { 1.0,  0.5,  0.55,  1.5,  2.0,
                     1.25, 3.0,  3.05,  4.5,  5.0 };
    double y[10] = { 2.0,  1.5,  0.5,   1.0,  2.5,
                     3.5,  0.75, 2.2,   4.0,  1.1 };
    double z[10] = { 3.0,  2.5,  1.5,   4.0,  5.0,
                     2.75, 4.5,  3.85,  6.0,  2.2 };
    double expected[10] = { -5.4778225365650215, -1.3532695737025930, 1.3172026164100272, 3.6246066588857202, -8.8047676320641521 ,
                           -40.218144541662973 , 12.266473017193270, 1.6331651606544710, -36.538038053808343,27.233031740637784 };

    cout << "Запуск тестів для функції s_calculation:\n";
    for (int i = 0; i < 10; i++) {
        double result = calculateS(x[i], y[i], z[i]);
        cout << "Тест кейс #" << (i + 1)
            << " | x = " << x[i]
            << ", y = " << y[i]
            << ", z = " << z[i]
            << " | Результат = "  << result
            << " | Очікуваний результат = "  << expected[i];

        // Пряме порівняння результату з очікуваним значенням
        if (result == expected[i]) {
            cout << " -> PASSED\n";
        }
        else {
            cout << " -> FAILED\n";
        }
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    test_s_calculation();
    _getch();
   return 0;
}
