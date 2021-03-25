#include <iomanip>
#include <iostream>
using namespace std;
int input(int M, int* Arr, int c)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            *(Arr + i * M + j) = c++;
            cout << setw(4) << *(Arr + i * M + j);
        }
        cout << endl;
    }
    return 0;
}
int output(int M, int* Arr)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
            cout << setw(4) << *(Arr + j * M + i);
        cout << endl;
    }
    return 0;
}
int input2(int M, int **Mas, int a)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            *(*(Mas + i) + j) = a++;
            cout << setw(4) << (*(*Mas + i) + j);
        }
        cout << endl;
    }
    return 0;
}
int output2(int M, int** Mas)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
            cout << setw(4) << *(*(Mas + j) + i);
        cout << endl;
    }
    return 0;
}