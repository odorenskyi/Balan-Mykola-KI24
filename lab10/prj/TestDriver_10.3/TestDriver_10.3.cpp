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

void test_computeAndConvert() {
    // Тестові кейси
    struct TestCase {
        string inputContent;
        string expectedOutput;
    };

    TestCase testCases[] = {
        {
            "1 2 3 5",
            "Результат s_calculation(1, 2, 3): -5.477823\n"
            "Число 5 у двійковому коді: 101\n"
        },
        {
            "5 1 2 13",
            "Результат s_calculation(5, 1, 2): 27.239833\n"
            "Число 13 у двійковому коді: 1101\n"
        },
        {
            "12 0 1 10",
            "Результат s_calculation(12, 0, 1): 177.991905\n"
            "Число 10 у двійковому коді: 1010\n"
        }
    };

    for (int i = 0; i < 3; i++) {
        string inputFile = "test_input_10_3_" + to_string(i + 1) + ".txt";
        string outputFile = "test_output_10_3_" + to_string(i + 1) + ".txt";

        createInputFile(inputFile, testCases[i].inputContent);

        ifstream inFile(inputFile);
        ofstream outFile(outputFile);
        computeAndConvert(inFile, outFile);
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
    cout << "Тестування функції computeAndConvert (Завдання 10.3):\n\n";
    test_computeAndConvert();
    system("pause");
    return 0;
}