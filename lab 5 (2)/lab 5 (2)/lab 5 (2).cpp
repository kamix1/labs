// lab 5 (2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Source.h"
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
#define ptr
using namespace std;

int main() {

    setlocale(LC_ALL, "rus");
    int M;
    cout << "введите размер квадратной матрицы: ";
    cin >> M;
    int* Arr = new int[M * M];
    int c = 0;
    int a = 0;
#ifdef ptr
    input (M ,Arr, c);
    cout << endl;
    cout << endl;
    output(M, Arr);
    cout << endl;
    cout << endl;
#endif
    int** Mas = new int* [M];
    for (int i = 0; i < M; i++)
    {
        Mas[i] = new int[M];
    }
#ifndef ptr
    input2(M, Mas, a);
    cout << endl;
    cout << endl;
    output2(M, Mas);
#endif
    delete [] Arr;
    for (int i = 0; i < M; i++)
    {
        delete[] Mas[i];
    }
    delete[] Mas;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
