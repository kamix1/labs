#include <iostream>
#include "Source.h"
#define N 3
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int num;
    int pos;
    int size = 0;
    for (; ; )
    {
        cout << "для ввода нажмите 1\nдля вывода нажмите 2\nдля поиска по кртерию нажмите 3\nдля добавления елемента нажмите 4\nдля удаления любого элемента нажмите 5\nдля сортировки нажмите 6\nдля записи списка в файл нажмите 7\nдля создания любого списка из файла нажмите 8\nдля выхода из программы нажмите 9\n";

        cin >> num;
        switch (num)
        {
        case 1:
            cout << "введите элементы структуры: ";
            DATA str;
            for (int i = 0; i < N + size; i++) {
                cin >> str.name >> str.income >> str.sell >> str.market;
                create(str);
            }
            break;
        case 2:
            print(str);
            break;
        case 3:
            find(size, str);
            break;
        case 4:
            DATA el;
            cout << "введите место в которое хотите добавить элемент: ";
            cin >> pos;
            cout << "введите элемент: ";
            cin >> el.name >> el.income >> el.sell >> el.market;
            add(pos, el, size);
            break;
        case 5:
            cin >> pos;
            delet(pos, size);
            break;
        case 6:
            sort(size);
            break;
        case 7:
            write(size, str);
            break;
        case 8:
            CreatList_File(size, str);
            break;
        case 9:
            exit(0);
            break;
        default:
            cout << "введите другое значение\n";
            break;

        }
    }
}