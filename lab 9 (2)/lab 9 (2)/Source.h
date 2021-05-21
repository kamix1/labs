#pragma once
#ifndef XT
#define XT
struct DATA {
	char name[10];
	int income;
	int sell;
	int market;
};
struct list
{
	DATA info;
	list* next;
	list* prev;
};
void write(int size, DATA str);
void sort(int size);
void find_tail(int size);
void find_head(int size);
void Make(DATA str);
void print_head();
void print_tail();
void add(int pos, DATA str, int& size);
void eraze(int pos, int& size);
void CreatList_File(int size, DATA str);


#endif 
