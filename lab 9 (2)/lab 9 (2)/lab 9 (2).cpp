#include <iostream>
#include "Source.h"
#define N 3
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int pos = 0;
	int size = 0;
	int x = 0;
	for (; ; )
	{
		cout << "для ввода нажмите 1\nдля вывода с начала нажмите 2\nдля вывода с конца нажмите 3\nдля поиска по критерию с начала нажмите 4\nдля поиска по критерию с конца нажмите 5\nдля добавления элемента нажмите 6\nдля удаления элемента нажмите 7\nдля сортировки нажмите 8\nдля записи списка в файл нажмите 9\nдля создания списка из файла нажмите 10\nдля выхода нажмите 11\n";
		cin >> x;
		switch (x)
		{
		case 1:
			DATA str;
			for (int i = 0; i < N + size; i++) {
				cin >> str.name >> str.income >> str.sell >> str.market;
				Make(str);
			}
			break;
		case 2:
			print_head();
			break;
		case 3:
			print_tail();
			break;
		case 4:
			find_head(size);
			break;
		case 5:
			find_tail(size);
			break;
		case 6:
			cout << "введите место в которое хотите добавить элемент: ";
			cin >> pos;
			cin >> str.name >> str.income >> str.sell >> str.market;
			add(pos, str, size);
			break;
		case 7:
			cout << "введите место из которо хотите удалить элемент: ";
			cin >> pos;
			eraze(pos, size);
			break;
		case 8:
			sort(size);
			break;
		case 9:
			write(size, str);

			break;
		case 10:
			CreatList_File(size, str);
			break;
		case 11:
			exit(0);
			break;
		default:
			cout << "введите другое значение\n";
			break;
		}
	}
}