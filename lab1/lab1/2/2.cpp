﻿// 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include <stdlib.h>

int main()
{
    setlocale(LC_ALL, "RUS");
    int b, c, P, S, a;
    printf("введите a: ");
    scanf_s("%d", &a);
    printf("введите b: ");
    scanf_s("%d", &b);
    printf("введите c: ");
    scanf_s("%d", &c);
    P = (a + b + c) / 2;
    S = pow((P * (P - a) * (P - b) * (P - c)), 0.5);
    printf("площадь равна: " "%d\n", S); 
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
