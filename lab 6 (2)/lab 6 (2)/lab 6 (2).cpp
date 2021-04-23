// lab 6 (2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Source.h"
using namespace std;
#define N 21
int main()
{
    setlocale(LC_ALL, "rus");
    char* str = new char[N];
    char* str1 = new char[N];
    char* S = str;
    char* S1 = str1;
    int x = 0;
    int y = 0;
    printf("Enter a string ( MAX 10 symbols ): ");
    scanf_s("%s", str, N);
    check_length(S, x);
    check_overfl(x);
    printf("Enter a string ( MAX 10 symbols ): ");
    scanf_s("%s", str1, N);
    check_length(S1, y);
    check_overfl(y);
    printf("first string: %s\n", str);
    printf("second string: %s\n", str1);
    combine(str, str1, x, y);
    printf("result: %s\n", str);
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
