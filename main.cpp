#include <iostream>
#include <fstream>  // Для работы с файлами
#include <string>

int main() {
    // 1. Открываем файл
    std::ifstream file("./file.txt");
    std::ofstream outFile("./output.txt");
    // std::ofstream file2("./example.txt", std::ios::app);
     std::ofstream file2("./example.txt");

    int sdvig = 8;

    // 2. Проверяем на ошибки
    if (!file.is_open()) {
        std::cerr << "Ошибка: файл не найден!" << std::endl;
        return 1;
    } else if (file.is_open() && outFile.is_open() && file2.is_open()) {
        char ch;
        // Считываем по одному символу в переменную ch
        while (file.get(ch)) {            
            int code = static_cast<int>(ch) + sdvig; 
            ch = static_cast<char>(code);
            outFile << ch;

        }
    }
    outFile.close();
    std::ifstream outFile_2("./output.txt");

    if(outFile_2.is_open() && file2.is_open()){
        char ch;
        while(outFile_2.get(ch)){
        int code = static_cast<int>(ch) - sdvig;
        ch = static_cast<char>(code);
        file2 << ch;
    }
    }

    // std::string line;
    // // 3. Читаем файл построчно
    // while (std::getline(file, line)) {
    //     std::cout << line << std::endl;
    // }



    // 4. Закрываем файл (происходит автоматически при выходе из области видимости)
    file.close(); 
    outFile.close();
    file2.close();
    outFile_2.close();

    return 0;
}