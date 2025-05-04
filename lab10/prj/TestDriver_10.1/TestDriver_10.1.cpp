#include "ModulesBalan.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

// Допоміжна функція для створення тимчасового вхідного файлу з заданим вмістом
void createInputFile(const string& filename, const string& content) {
    ofstream file(filename);
    file << content;
    file.close();
}

// Допоміжна функція для читання вмісту вихідного файлу
string readOutputFile(const string& filename) {
    ifstream file(filename);
    string content, line;
    while (getline(file, line)) {
        content += line + "\n";
    }
    file.close();
    return content;
}

void test_analyzeWord() {
    // Тестові кейси
    struct TestCase {
        string inputContent;
        string expectedOutput;
    };

    TestCase testCases[] = {
        {
            "Кажи",
            "Розробник: Балан Микола\n"
            "Установа: ЦНТУ\n"
            "Місто: Кропивницький\n"
            "Країна: Україна\n"
            "Рік розробки: 2025\n\n"
            "Кількість приголосних літер у слові \"Кажи\": 2\n"
            "Слово \"Кажи\" присутнє у вірші Віталія Іващенка.\n"
        },
        {
            "сильний",
            "Розробник: Балан Микола\n"
            "Установа: ЦНТУ\n"
            "Місто: Кропивницький\n"
            "Країна: Україна\n"
            "Рік розробки: 2025\n\n"
            "Кількість приголосних літер у слові \"сильний\": 4\n"
            "Слово \"сильний\" присутнє у вірші Віталія Іващенка.\n"
        },
        {
            "таємну",
            "Розробник: Балан Микола\n"
            "Установа: ЦНТУ\n"
            "Місто: Кропивницький\n"
            "Країна: Україна\n"
            "Рік розробки: 2025\n\n"
            "Кількість приголосних літер у слові \"таємну\": 3\n"
            "Слово \"таємну\" присутнє у вірші Віталія Іващенка.\n"
        }
    };

    for (int i = 0; i < 3; i++) {
        string inputFile = "test_input_10_1_" + to_string(i + 1) + ".txt";
        string outputFile = "test_output_10_1_" + to_string(i + 1) + ".txt";

        createInputFile(inputFile, testCases[i].inputContent);

        ifstream inFile(inputFile);
        ofstream outFile(outputFile);
        analyzeWord(inFile, outFile);
        inFile.close();
        outFile.close();

        string actualOutput = readOutputFile(outputFile);

        cout << "Тест кейс " << (i + 1) << " | Вхід: \"" << testCases[i].inputContent << "\"\n";
        cout << "Очікуваний результат:\n" << testCases[i].expectedOutput << "\n";
        cout << "Фактичний результат:\n" << actualOutput << "\n";

        if (actualOutput == testCases[i].expectedOutput) {
            cout << "Результат: PASSED\n";
        }
        else {
            cout << "Результат: FAILED\n";
        }
        cout << "--------------------------------------\n";
    }
}

int main() {
    SetConsoleOutputCP(1251);
    cout << "Тестування функції analyzeWord (Завдання 10.1):\n\n";
    test_analyzeWord();
    system("pause");
    return 0;
}