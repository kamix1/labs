#include <iostream>
#include "Source.h"
#define N 3
using namespace std;

list* head = NULL;
list* tail = NULL;


void CreatList_File(int size, DATA str) {
    Clear();
    FILE* f;
    fopen_s(&f, "t1.txt", "r");
    while (!feof(f))
    {
        fscanf_s(f, "%s", str.name, 10);
        fscanf_s(f, "%d", &str.income);
        fscanf_s(f, "%d", &str.sell);
        fscanf_s(f, "%d", &str.market);

        create(str);
    }
    fclose(f);
}

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

void find(int size, DATA str)
{
    list* temp = new list;
    temp = head;
    int y;
    cout << "введите y: ";
    cin >> y;
    printf("-------------------------------------------------------------------------\n");
    printf("|фирмы                                                                  |\n");
    printf("|-----------------------------------------------------------------------|\n");
    printf("| назва     | годовая прибыль      | процент продаж       | часть рынка |\n");
    printf("|-----------|----------------------|----------------------|-------------|\n");
    for (int i = 0; i < N + size; i++)
    {
        if (y == temp->info.income)
        {
            printf("| %9s | %20d | %20d | %-11.1d |\n", temp->info.name, temp->info.income, temp->info.sell, temp->info.market);
            printf("|-----------|----------------------|----------------------|-------------|\n");
        }
        temp = temp->next;
    }

}

void write(int size, DATA str)
{
    list* temp = new list;
    FILE* f;
    fopen_s(&f, "t1.txt", "w");
    temp = head;
    for (int i = 0; i < N + size; i++)
    {
        fprintf(f, "%s %d %d %d", temp->info.name, temp->info.income, temp->info.sell, temp->info.market);
        if (i != (N + size) - 1)
        {
            fprintf(f, "\n");
        }
        temp = temp->next;
    }
    fclose(f);
}

void add(int pos, DATA str, int& size)
{
    list* temp = new list;
    if (pos == 0)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        list* temp_pos = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp_pos = temp_pos->next;
        }
        temp->next = temp_pos->next;
        temp_pos->next = temp;
    }
    temp->info = str;
    size++;
}

void create(DATA str)
{
    list* temp = new list;
    temp->next = NULL;
    temp->info = str;
    if (head == NULL)
    {
        head = tail = temp;
    }
    tail->next = temp;
    tail = temp;
}
void print(DATA str)
{
    printf("-------------------------------------------------------------------------\n");
    printf("|фирмы                                                                  |\n");
    printf("|-----------------------------------------------------------------------|\n");
    printf("| назва     | годовая прибыль      | процент продаж       | часть рынка |\n");
    printf("|-----------|----------------------|----------------------|-------------|\n");
    list* temp;
    temp = head;
    while (temp != NULL)
    {
        printf("| %9s | %20d | %20d | %-11.1d |\n", temp->info.name, temp->info.income, temp->info.sell, temp->info.market);
        printf("|-----------|----------------------|----------------------|-------------|\n");
        if (temp != NULL)
        {
            temp = temp->next;
        }
    }
}
void delet(int pos, int& size)
{
    list* temp_pos = head;
    if (pos == 0)
    {
        head = head->next;
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
        }
        else
        {
            temp_pos->next = temp->next;
        }
        delete temp;
    }
    size--;
}