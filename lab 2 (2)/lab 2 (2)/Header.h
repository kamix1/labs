#pragma once
#ifndef XT
#define XT
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#define DEBUG
#define PRINT_TYPE
using namespace std;
#define N 7


struct firms
{
    string name;
    int num;
    int sold;
    float market;
} fm[20]{};

void print(firms fm[]);
void sort(firms fm[]);
void PRINT_rand();
void PRINT_hand();
void PRINT_TYPE_RAND();
void PRINT_TYPE_HAND();
#endif
