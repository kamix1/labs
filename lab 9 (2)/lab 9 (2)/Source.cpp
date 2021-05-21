#include <iostream>
#include "Source.h"
#define N 3

using namespace std;

list* head = NULL;
list* tail = NULL;


void Clear()
{
	if (head == 0)
	{
		return;
	}
	list* p = head;
	list* t;
	while (p)
	{
		t = p;
		p = p->next;
		delete t;
	}
	head = 0;
}

void CreatList_File(int size, DATA str) {
	Clear();
	FILE* f1;
	fopen_s(&f1, "t2.txt", "r");
	while (!feof(f1))
	{
		fscanf_s(f1, "%s", str.name, 10);
		fscanf_s(f1, "%d", &str.income);
		fscanf_s(f1, "%d", &str.sell);
		fscanf_s(f1, "%d", &str.market);

		Make(str);
	}
	fclose(f1);
}

void write(int size, DATA str)
{
	list* temp = new list;
	FILE* f1;
	fopen_s(&f1, "t2.txt", "w");
	temp = head;
	for (int i = 0; i < N + size; i++)
	{
		fprintf(f1, "%s %d %d %d", temp->info.name, temp->info.income, temp->info.sell, temp->info.market);
		temp->prev = temp;
		temp = temp->next;
		if (i != (N + size) - 1)
		{
			fprintf(f1, "\n");
		}
	}
	fclose(f1);
}

void sort(int size)
{
	list* temp;
	list* temp_temp = new list;
	temp = head;
	for (int j = 0; j < N + size - 1; j++)
	{
		for (int i = 0; i < N + size - 1; i++)
		{
			if (temp->info.income < temp->next->info.income)
			{
				temp_temp->info = temp->info;
				temp->info = temp->next->info;
				temp->next->info = temp_temp->info;
			}
			if (temp->next != NULL)
			{
				temp = temp->next;
			}
		}
		temp = head;
	}
}

void find_tail(int size)
{
	list* temp = new list;
	temp = tail;
	int x;
	cout << "введите y: ";
	cin >> x;
	printf("-------------------------------------------------------------------------\n");
	printf("|фирмы                                                                  |\n");
	printf("|-----------------------------------------------------------------------|\n");
	printf("| назва     | годовая прибыль      | процент продаж       | часть рынка |\n");
	printf("|-----------|----------------------|----------------------|-------------|\n");
	for (int i = 0; i < N + size; i++)
	{
		if (x == temp->info.income)
		{
			printf("| %9s | %20d | %20d | %-11.1d |\n", temp->info.name, temp->info.income, temp->info.sell, temp->info.market);
			printf("|-----------|----------------------|----------------------|-------------|\n");
		}
		temp = temp->prev;
	}
}

void find_head(int size)
{
	list* temp = new list;
	temp = head;
	int x;
	cout << "введите y: ";
	cin >> x;
	printf("-------------------------------------------------------------------------\n");
	printf("|фирмы                                                                  |\n");
	printf("|-----------------------------------------------------------------------|\n");
	printf("| назва     | годовая прибыль      | процент продаж       | часть рынка |\n");
	printf("|-----------|----------------------|----------------------|-------------|\n");
	for (int i = 0; i < N + size; i++)
	{
		if (x == temp->info.income)
		{
			printf("| %9s | %20d | %20d | %-11.1d |\n", temp->info.name, temp->info.income, temp->info.sell, temp->info.market);
			printf("|-----------|----------------------|----------------------|-------------|\n");
		}

		temp = temp->next;
	}
}

void Make(DATA str)
{
	list* temp = new list;
	if (head == NULL)
	{
		head = tail = temp;
		temp->prev = NULL;
	}
	else {
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	temp->next = NULL;
	temp->info = str;
}

void print_head()
{
	list* temp = head;
	printf("-------------------------------------------------------------------------\n");
	printf("|фирмы                                                                  |\n");
	printf("|-----------------------------------------------------------------------|\n");
	printf("| назва     | годовая прибыль      | процент продаж       | часть рынка |\n");
	printf("|-----------|----------------------|----------------------|-------------|\n");
	while (temp != NULL)
	{
		printf("| %9s | %20d | %20d | %-11.1d |\n", temp->info.name, temp->info.income, temp->info.sell, temp->info.market);
		printf("|-----------|----------------------|----------------------|-------------|\n");
		temp = temp->next;
	}
	cout << endl;
}

void print_tail()
{
	list* temp = tail;
	printf("-------------------------------------------------------------------------\n");
	printf("|фирмы                                                                  |\n");
	printf("|-----------------------------------------------------------------------|\n");
	printf("| назва     | годовая прибыль      | процент продаж       | часть рынка |\n");
	printf("|-----------|----------------------|----------------------|-------------|\n");
	while (temp != NULL)
	{
		printf("| %9s | %20d | %20d | %-11.1d |\n", temp->info.name, temp->info.income, temp->info.sell, temp->info.market);
		printf("|-----------|----------------------|----------------------|-------------|\n");
		//cout << temp->info.x << " " << temp->info.ch;
		temp = temp->prev;
	}
	cout << endl;
}

void add(int pos, DATA str, int& size)
{
	list* temp = new list;
	if (temp->prev = NULL)
	{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else {
		list* temp_pos = head;
		for (int i = 0; i < pos - 1; i++)
		{
			temp_pos = temp_pos->next;
		}
		if (temp_pos->next == NULL)
		{
			tail->next = temp;
			temp->prev = tail;
			temp->next = NULL;
			tail = temp;
		}
		else
		{
			temp->next = temp_pos->next;
			temp_pos->next = temp;
			temp->next->prev = temp;
			temp->prev = temp_pos;
		}
	}
	temp->info = str;
	size++;
}

void eraze(int pos, int& size)
{
	list* temp_pos = head;
	if (pos == 0)
	{
		head = head->next;
		head->prev = NULL;
		delete temp_pos;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
		{
			temp_pos = temp_pos->next;
		}
		list* temp = temp_pos->next;
		if (temp->next == NULL)
		{
			temp_pos->next = NULL;
			tail = temp_pos;
		}
		else
		{
			temp_pos->next = temp->next;
			temp->next->prev = temp_pos;
		}
		delete temp;
	}
	size--;
}