#pragma once
#ifndef XT
#define XT
struct DATA {
    char name[10];
    int income;
    int sell;
    int market;
};

struct list {
    DATA info;
    list* next;
};
void CreatList_File(int size, DATA str);
void Clear();
void sort(int size);
void find(int size, DATA str);
void write(int size, DATA str);
void add(int pos, DATA str, int& size);
void create(DATA str);
void print(DATA str);
void delet(int pos, int& size);

#endif
#pragma once
