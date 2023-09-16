//Побитовый сдвиг

#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL, "");

    int b = 6; //0000 0000 0000 0000 0000 0000 0000 0110
    int c = 0; //0000 0000 0000 0000 0000 0000 0000 0000

    //Битовый сдвиг для деления на 2
    c = b>>1;   //после сдвига 0000 0000 0000 0000 0000 0000 0000 0011 = 3

    std::wcout << c << std::endl;

    return a.exec();
}