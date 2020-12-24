// RGZ bubble sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

using namespace std;
#include <iostream>
#include <chrono>
#include <algorithm>
#include <iomanip>
//#include "windows.h"

#define M 100	// Количество цикло



int main()
{
    int* arr; // указатель для выделения памяти под массив
    int size; // размер массива
    double dur_arr[M];
    long F = 0;
    double aver_dur = 0;

    // Ввод количества элементов массива
    cout << "n = ";
    cin >> size;

    if (size <= 0) {
        // Размер масива должен быть положитлеьным
        cerr << "Invalid size" << endl;
        return 1;
    }

    arr = new int[size]; // выделение памяти под массив

    // заполнение массива
    int k = 0;
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10;
        cout << setw(4) << arr[i];

    }
    cout << endl;

    int temp; // временная переменная для обмена элементов местами

    // Сортировка массива пузырьком

    for (int i = 0; i < M; i++)
    {
        //system("pause");
        //Sleep(1000);

        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // меняем элементы местами
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }


        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        //std::cout << "Duration " << i << " = " << duration.count() << "s\n";
        dur_arr[i] = duration.count();
    }
    sort(dur_arr, dur_arr + M);
    // Вывод результата
    for (int i = 0; i < M; i++)
    {
        std::cout << "Duration " << i << " = " << dur_arr[i] << "s\n";
        if (i > 0) aver_dur += dur_arr[i];
    }
    std::cout << "Duration a" << " = " << aver_dur / (M - 1) << "s\n";

    // Вывод отсортированного массива на экран
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // освобождение памяти;

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
