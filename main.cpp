#include <iostream>
#include <fstream>  // Для работы с файлами
#include <string>
#include <locale>

int main() {
    std::wcout.imbue(std::locale(""));
    // 1. Открываем файл
    std::wifstream file("./file.txt");
    std::wofstream outFile("./output.txt");
    // std::ofstream file2("./example.txt", std::ios::app);
     std::wofstream file2("./example.txt");

    int sdvig = 8;

    // 2. Проверяем на ошибки
    if (!file.is_open()) {
        std::cerr << "Ошибка: файл не найден!" << std::endl;
        return 1;
    } else if (file.is_open() && outFile.is_open() && file2.is_open()) {
        wchar_t ch;
        // Считываем по одному символу в переменную ch
        while (file.get(ch)) {            
            int code = static_cast<int>(ch) + sdvig; 
            ch = static_cast<wchar_t>(code);
            outFile << ch;

        }
    }
    outFile.close();
    std::wifstream outFile_2("./output.txt");

    if(outFile_2.is_open() && file2.is_open()){
        wchar_t ch;
        while(outFile_2.get(ch)){
        int code = static_cast<int>(ch) - sdvig;
        ch = static_cast<wchar_t>(code);
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