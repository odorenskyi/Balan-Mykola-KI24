#include <cmath>
#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>

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
void calculateAverageTemperatureForTest(const double tempsC[], int size, double& avgC, double& avgF) {
    double sumC = 0;
    for (int i = 0; i < size; ++i) {
        sumC += tempsC[i];
    }
    avgC = sumC / size;
    avgF = 32 + 9.0 / 5.0 * avgC;
}
int analyzeBits(int N) {
    if (N < 0 || N > 17948360) {
        cout << "Помилка: число поза допустимим діапазоном (0 ≤ N ≤ 17948360).\n";
        return -1;
    }

    bool D9 = (N >> 8) & 1;

    int count = 0;
    int temp = N;

    while (temp > 0) {
        count += ((temp & 1) == (D9 ? 0 : 1)) ? 1 : 0;
        temp >>= 1;
    }

    return count;
}
void analyzeWord(std::ifstream& inFile, std::ofstream& outFile) {
    std::string word;
    inFile >> word;

    std::string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZбвгґджзйклмнпрстфхцчшщБВГҐДЖЗЙКЛМНПРСТФХЦЧШЩ";
    int consonantCount = 0;
    for (char c : word) {
        if (consonants.find(c) != std::string::npos) {
            consonantCount++;
        }
    }

    std::string poem = "Про себе не кажи недобрих слів Бо має сказане таємну силу Кажи Я сильний впевнений щасливий І буде саме так як ти хотів";
    std::stringstream ss(poem);
    std::string poemWord;
    bool found = false;
    while (ss >> poemWord) {
        if (poemWord == word) {
            found = true;
            break;
        }
    }

    outFile << "Розробник: Балан Микола\n";
    outFile << "Установа: ЦНТУ\n";
    outFile << "Місто: Кропивницький\n";
    outFile << "Країна: Україна\n";
    outFile << "Рік розробки: 2025\n\n";
    outFile << "Кількість приголосних літер у слові \"" << word << "\": " << consonantCount << "\n";
    outFile << "Слово \"" << word << "\" " << (found ? "присутнє" : "відсутнє") << " у вірші Віталія Іващенка.\n";
}