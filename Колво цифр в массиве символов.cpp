//Найти кол-во цифр в массиве символов

#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL, "");

    //Создать массив символов
    char p[] = "12d3fdht4f56";

    //Найти кол-во цифр в массиве символов
    int i = 0;
    while(p[i] != '\0') {
        if (isdigit(p[i]))
            std::wcout << p[i] << std::endl;
        i++;
    }

    std::wcout << L"Длина строки: " << i << std::endl;

    return a.exec();
}
