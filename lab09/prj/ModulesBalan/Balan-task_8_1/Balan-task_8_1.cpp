#include <cmath>
#include <iostream>
#include <iomanip> // для форматування виводу


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

double calculateS(double x, double y, double z) {
    double numerator = abs(z * z * exp(x));
    double denominator = 12 * x + (y * y - M_PI * sqrt(z));

    double result = x * x - pow(y, 3) + sqrt(numerator / denominator);
    return result;
}

void calculateDeposit(double amount, int months, double& dailyInterest, double& totalInterest) {
    double annualRate;

    if (months == 6) {
        annualRate = 19.5;
    }
    else if (months == 12) {
        annualRate = 27.0;
    }
    else {
        cout << "Непідтримуваний строк депозиту. Доступно тільки 6 або 12 місяців." << endl;
        dailyInterest = totalInterest = -1.0; // Для перевірки у тестах
        return;
    }

    const int daysInYear = 365;
    int depositDays = months * 30;

    totalInterest = amount * (annualRate / 100.0) * (depositDays / (double)daysInYear);
    dailyInterest = totalInterest / depositDays;
}