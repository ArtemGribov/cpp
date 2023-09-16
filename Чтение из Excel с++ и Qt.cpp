//Чтение из Excel c помощью с++ и Qt

#include <QCoreApplication>
#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtDebug>
#include <QTime>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    setlocale(LC_ALL, "");

    char NameSheet[20] = "";
    std::cin >> NameSheet;

    QStringList globalstr;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "xlsx_connection");
    db.setDatabaseName("DRIVER={Microsoft Excel Driver (*.xls, *.xlsx, *.xlsm, *.xlsb)};DBQ="
                       + QString("c:\\myfolder\\PlanFactProductionOPR.xlsx"));
        if(db.open()) {
            qDebug() << "Успешное подключение.";
            QSqlQuery query("SELECT " + QString("*") + " FROM [" + QString(NameSheet) + "$]", db);
            while (query.next()) {
                QString StepId = query.value(0).toString();
                QString RunId = query.value(1).toString();
                QString MachineId = query.value(2).toString();
                QString ProductLocationId = query.value(3).toString();
                QString OperationId = query.value(4).toString();
                QString StartDate = query.value(5).toString();

                QString str;
                str.append(StepId);
                str.push_back('\t');
                str.append(RunId);
                str.push_back('\t');
                str.append(MachineId);
                str.push_back('\t');
                str.append(ProductLocationId);
                str.push_back('\t');
                str.append(OperationId);
                str.push_back('\t');
                str.append(StartDate);
                str.push_back('\n');

                globalstr.append(str);
                /*qDebug() << StepId << '\t'
                         << RunId << '\t'
                         << MachineId << '\t'
                         << ProductLocationId << '\t'
                         << OperationId << '\t'
                         << StartDate;
                */
                qDebug() << str;
            }
            db.close(); QSqlDatabase::removeDatabase("xlsx_connection");
        }
    return app.exec();
}
