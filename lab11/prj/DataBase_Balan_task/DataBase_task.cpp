#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <locale>
#include <windows.h>

#include "struct_type_project_1.h" 
#include "ModulesBalan.h"
#include "ModulesFedotov.h"
#include "ModulesSavelyev.h"

std::vector<Benefit> loadFromFile() {
    std::vector<Benefit> list;
    std::ifstream fin("benefit_data.bin", std::ios::binary);
    if (fin) {
        Benefit b;
        while (fin.read(reinterpret_cast<char*>(&b), sizeof(Benefit))) {
            if (b.benefitCode > 0) {
                list.push_back(b);
            }
        }
        fin.close();
    }
    return list;
}

void menu() {
    std::vector<Benefit> directory = loadFromFile();
    int choice;
    do {
        std::cout << "\n===! МЕНЮ СИСТЕМИ ПІЛЬГ !===\n"; 
        std::cout << "1. Пошук пільги за кодом\n"; 
        std::cout << "2. Переглянути всі записи\n"; 
        std::cout << "3. Експорт у текстовий файл\n"; 
        std::cout << "4. Новий запис\n"; 
        std::cout << "5. Видалити пільгу\n"; 
        std::cout << "0. Вийти та зберегти дані\n"; 
        std::cout << "Виберіть дію: "; 
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            int code;
            std::cout << "Укажіть код для пошуку пільги: "; 
            std::cin >> code;
            std::cin.ignore();
            searchByCode(directory, code);
            break;
        }
        case 2:
            displayAll(directory);
            break;
        case 3: {
            std::string filename;
            std::cout << "Назва файлу для експорту: "; // Змінено формулювання
            std::getline(std::cin, filename);
            exportToTextFile(directory, filename);
            break;
        }
        case 4:
            addBenefit(directory);
            break;
        case 5: {
            int code;
            std::cout << "Укажіть код пільги для видалення: "; // Змінено формулювання
            std::cin >> code;
            std::cin.ignore();
            deleteByCode(directory, code);
            break;
        }
        case 0:
            saveToFile(directory);
            std::cout << "Збереження виконано. Програма завершується...\n"; // Змінено формулювання
            break;
        default:
            std::cout << "Неправильний вибір. Спробуйте знову.\n"; // Змінено формулювання
        }
    } while (choice != 0);
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    menu();
    system("pause");
    return 0;
}