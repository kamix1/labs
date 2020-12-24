// RGZ pyramidal sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iomanip>
using namespace std;
#include <iostream>
#include <chrono>
#include <algorithm>
//#include "windows.h"

#define M 100	// Количество циклов
#define A 10 


// Процедура для преобразования в двоичную кучу поддерева с корневым узлом i, что является
// индексом в arr[]. n - размер кучи

void heapify(int arr[], int n, int i)
{
    int largest = i;
    // Инициализируем наибольший элемент как корень
    int l = 2 * i + 1; // левый = 2*i + 1
    int r = 2 * i + 2; // правый = 2*i + 2 

 // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(int arr[], int n)
{
    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--)
    {
        // Перемещаем текущий корень в конец
        swap(arr[0], arr[i]);

        // вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Управляющая программа
int main()
{
    int arr[A];
    int a = 1;
    double dur_arr[M];
    long F = 0;
    double aver_dur = 0;
    int k = 10;
    for (int i = 0; i < A; i++)
    {
        arr[i] = rand() % 100;
        cout << setw(4) << arr[i];
    }
    cout << endl;


    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < M; i++)
    {
        //system("pause");
        //Sleep(1000);

        auto start = std::chrono::high_resolution_clock::now();

        heapSort(arr, n);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        //std::cout << "Duration " << i << " = " << duration.count() << "s\n";
        dur_arr[i] = duration.count();
    }

    cout << "Sorted array is \n";
    printArray(arr, n);
    sort(dur_arr, dur_arr + M);

    for (int i = 0; i < M; i++)
    {
        std::cout << "Duration " << i << " = " << dur_arr[i] << "s\n";
        if (i > 0) aver_dur += dur_arr[i];
    }
    std::cout << "Duration a" << " = " << aver_dur / (M - 1) << "s\n";

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
