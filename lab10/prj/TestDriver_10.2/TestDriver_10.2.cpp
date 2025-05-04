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

// Допоміжна функція для читання вмісту файлу
string readOutputFile(const string& filename) {
    ifstream file(filename);
    string content, line;
    while (getline(file, line)) {
        content += line + "\n";
    }
    file.close();
    return content;
}

void test_appendWordInfo() {
    // Тестові кейси
    struct TestCase {
        string inputContent;
        string expectedOutputFileContent; // Очікуваний вміст вихідного файлу
    };

    TestCase testCases[] = {
        {
            "Привіт",
            "Привіт\n"
            "Перша літера слова: П\n"
            "Остання літера слова: т\n"
            "Дата і час допису: 2025-05-04 15:37:44\n"
        },
        {
            "Слово",
            "Слово\n"
            "Перша літера слова: С\n"
            "Остання літера слова: о\n"
            "Дата і час допису: 2025-05-04 15:37:44\n"
        },
        {
            "Тест",
            "Тест\n"
            "Перша літера слова: Т\n"
            "Остання літера слова: т\n"
            "Дата і час допису: 2025-05-04 15:37:44\n"
        }
    };

    for (int i = 0; i < 3; i++) {
        string inputFile = "test_input_10_2_" + to_string(i + 1) + ".txt";
        string outputFile = "test_output_10_2_" + to_string(i + 1) + ".txt";

        createInputFile(inputFile, testCases[i].inputContent);

        ifstream inFile(inputFile);
        ofstream outFile(outputFile);
        appendWordInfo(inFile, outFile, inputFile);
        inFile.close();
        outFile.close();

        string actualOutput = readOutputFile(outputFile);

        // Очікуємо, що дата й час буде динамічною, тому порівнюємо лише префікс
        string expectedPrefix = testCases[i].expectedOutputFileContent.substr(0, testCases[i].expectedOutputFileContent.find("Дата і час допису:"));
        string actualPrefix = actualOutput.substr(0, actualOutput.find("Дата і час допису:"));
        bool outputMatch = expectedPrefix == actualPrefix &&
            actualOutput.find("Дата і час допису:") != string::npos;

        cout << "Тест кейс " << (i + 1) << " | Вхід: \"" << testCases[i].inputContent << "\"\n";
        cout << "Очікуваний результат (вихідний файл):\n" << testCases[i].expectedOutputFileContent << "\n";
        cout << "Фактичний результат (вихідний файл):\n" << actualOutput << "\n";

        if (outputMatch) {
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
    cout << "Тестування функції appendWordInfo (Завдання 10.2):\n\n";
    test_appendWordInfo();
    system("pause");
    return 0;
}