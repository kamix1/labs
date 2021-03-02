#ifndef exe
#define exe
#include "Header.h"


void sort(firms fm[])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N - 1; j++)
        {
            if (fm[j].name > fm[j + 1].name) swap(fm[j], fm[j + 1]);
        }
#ifdef DEBUG
    {
        cout << __DATE__ << endl;
        cout << __TIME__ << endl;
        cout << __FUNCTION__ << endl;
        cout << __FILE__ << endl;

    }
#endif
}
void print(firms fm[])
{
    printf("-------------------------------------------------------------------------\n");
    printf("|Фирмы - производители СКБД                                             |\n");
    printf("|-----------------------------------------------------------------------|\n");
    printf("| Фирма     | Количество продуктов | годовой объем продаж | часть рынка |\n");
    printf("|-----------|----------------------|----------------------|-------------|\n");
    for (int i = 0; i < N; i++)
    {
        printf("| %9s | %20d | %20d | %-11.1f |\n",
            fm[i].name.c_str(), fm[i].num, fm[i].sold, fm[i].market);
        printf("|-----------|----------------------|----------------------|-------------|\n");
    }
#ifdef DEBUG
    {
        cout << __DATE__ << endl;
        cout << __TIME__ << endl;
        cout << __FUNCTION__ << endl;
        cout << __FILE__ << endl;

    }
#endif
}
void PRINT_hand()
{
    for (int i = 0; i < N; i++) {
        cout << "Введите название фирмы: ";
        cin >> fm[i].name;
        cout << "Введите количество продуктов: ";
        cin >> fm[i].num;
        cout << "Введите годовой объем продаж: ";
        cin >> fm[i].sold;
        cout << "Введите часть рынка: ";
        cin >> fm[i].market;
    }
}
void PRINT_rand()
{
    for (int i = 0; i < N; i++)
    {
        fm[i].name = "name_" + to_string((rand() % 50 + 100));
        fm[i].num = (rand() % 50 + 100);
        fm[i].sold = (rand() % 50 + 100);
        fm[i].market = (rand() % 50 + 100);
    }
}
void PRINT_TYPE_RAND()
{
#ifdef DEBUG
    {
        cout << __DATE__ << endl;
        cout << __TIME__ << endl;
        cout << __FUNCTION__ << endl;
        cout << __FILE__ << endl;

    }
#endif
#ifdef PRINT_TYPE
    PRINT_rand();
#endif
}
void PRINT_TYPE_HAND()
{
#ifdef DEBUG
    {
        cout << __DATE__ << endl;
        cout << __TIME__ << endl;
        cout << __FUNCTION__ << endl;
        cout << __FILE__ << endl;

    }
#endif
#ifdef PRINT_TYPE
    PRINT_hand();
#endif
}
#endif