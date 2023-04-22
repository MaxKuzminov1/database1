// database1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Functions.h"

int _stateMenu;

int Menu() {
    cout << "Выберите действие: " << endl
        << "(0) Выход из программы" << endl
        << "(1) Ввод данных" << endl
        << "(2) Вывод данных" << endl
        <<"(3) Сортировка по скорости"<<endl
        <<"(4) Занести данные в Excel "<<endl;

    cin >> _stateMenu;
    return 0;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Menu();

    int _actions,
        amountOfData = 0;
    //string fileName;

    Data* d = new Data[amountOfData];

    while (_stateMenu != 0) {
        switch (_stateMenu)
        {
        case 1:
            system("cls");
             
            ReadingData(d, amountOfData, "db.txt");
            system("pause");
            system("cls");
            Menu();
            break;

        case 2:
            system("cls");
            if (amountOfData != 0)
                Print(d, amountOfData);
            else
                cout << "Данные пусты!" << endl;
            system("pause");
            system("cls");
            Menu();
            break;

        case 3:
            system("cls");
            if (amountOfData != 0)
                SpeedSorting(d, amountOfData);
            else
                cout << "Ошибка " << endl;
            system("pause");
            system("cls");
            Menu();
            break;
        
         case 4:
             system("cls");
             if (amountOfData != 0)
                 Excel(d, amountOfData);
             else
                 cout << "Ошибка " << endl;
             system("pause");
             system("cls");
             Menu();
             break;
        }
    }
}