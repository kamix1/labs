#include <iostream>
using namespace std;

int input(int* arr1, int N)
{
    for (int i = 0; i < N; i++)
    {
        cin >> *(arr1 + i);
    }
    cout << endl;
    return 0;
}

int output(int* arr1, int  N)
{
    for (int i = 0; i < N; i++)
    {
        cout << *(arr1 + i) << " ";
    }
    cout << endl;
    return 0;
}

int sort(int* arr1, int N)
{
    int temp;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (*(arr1 + j) > * (arr1 + j + 1)) {
                // меняем элементы местами
                temp = *(arr1 + j);
                arr1[j] = *(arr1 + j + 1);
                *(arr1 + j + 1) = temp;
            }
        }
    }
    return 0;
}
int size_counter(int* arr1, int N, int& M)
{
    for (int i = 0; i < N; i++)
    {
        if (*(arr1 + i) > 0)
        {
            M++;
        }
    }
    return 0;
}
int rewrite(int* arr1, int* arr2, int N, int M)
{
    for (int i = 0; i < M; i++)
    {
        *(arr2 + i) = *(arr1 + i + (N - M));
    }
    return 0;
}