#include <iostream>
#include <windows.h>
#include "ModulesBalan.h"
#include "BalanLib.h"
using namespace std;
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	char command;
	char exitCommand;
	Information();
	do {
		cout << "Введіть команду (h, f, d, s): ";
		cin >> command;

		switch (command) {
		case 'h':
			double x, y, z;
			cout << "Введіть три числа для x, y, z: ";
			cin >> x >> y >> z;
			cout << "Результат роботи функції s_calculation: " << calculateS(x, y, z) << endl;
			break;

		case 'f': {
			double amount;
			int months;
			double dailyInterest, totalInterest;

			cout << "Введіть суму депозиту: ";
			cin >> amount;

			cout << "Введіть строк депозиту в місяцях (6 або 12): ";
			cin >> months;

			calculateDeposit(amount, months, dailyInterest, totalInterest);

			if (totalInterest != -1.0) {
				cout << "Щоденний відсоток: " << dailyInterest << " грн\n";
				cout << "Загальний відсоток: " << totalInterest << " грн\n";
			}

			break;
		}

		case 'd': {
			int size;
			cout << "Скільки температур хочете ввести? ";
			cin >> size;

			if (size <= 0) {
				cout << "Розмір має бути більше 0.\n";
				break;
			}

			double* tempsC = new double[size];

			for (int i = 0; i < size; ++i) {
				cout << "Температура #" << i + 1 << " (°C): ";
				cin >> tempsC[i];
			}

			double avgC, avgF;
			calculateAverageTemperatureForTest(tempsC, size, avgC, avgF);

			cout << "Середня температура: " << avgC << " °C\n";
			cout << "Середня температура: " << avgF << " °F\n";

			break;


		}


		case 's': {
			int N;

			cout << "Введіть число N (0 ≤ N ≤ 17948360): ";
			cin >> N;

			int result = analyzeBits(N);

			if (result != -1) {
				cout << "Кількість бітів, що відрізняються від 9-го біта: " << result << endl;
			}
			break;
		}

			
		default:
			cout << "\aНеправильне введення!\n";
			break;
		}

		cout << "Вихід? (a, A, p - так / інше - повторити): ";
		cin >> exitCommand;

	} while (exitCommand != 'a' && exitCommand != 'A' && exitCommand != 'p');

	cout << "Програму завершено.\n";
	system("pause");
	return 0;
}