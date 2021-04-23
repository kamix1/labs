#include <iostream>
#include <string>
#include <string.h>
#include <time.h>
using namespace std;
struct A
{
    char name[10];
    int num;
    int sold;
    float market;
} spis;
void input()
{
    FILE* f;
    FILE* f1;
    fopen_s(&f, "t1.dat", "wb");
    for (int i = 0; i < 3; i++)
    {
        cout << "¬ведите name, num, sold, market -> ";
        cin >> spis.name;
        cin >> spis.num;
        cin >> spis.sold;
        cin >> spis.market;
        fwrite(&spis, sizeof(A), 1, f);
    }
    fclose(f);
    fopen_s(&f1, "t2.dat", "wb");
    fopen_s(&f, "t1.dat", "rb");
    while (!feof(f))
    {
        fread(&spis, sizeof(A), 1, f);
        fwrite(&spis, sizeof(A), 1, f1);
    }
    fclose(f);
    fclose(f1);
}
void input_rand()
{
    srand(time(NULL));
    FILE* f;
    FILE* f1;
    fopen_s(&f, "t1.dat", "wb");
    if (f == NULL)
    {
        puts("ќшибка открыти€ файла на запись"); exit(0);
    }
    for (int i = 0; i < 3; i++)
    {
        strcpy_s(spis.name, "company");
        spis.num = (rand() % 50 + 100);
        spis.sold = (rand() % 100);
        spis.market = (rand() % 51);
        fwrite(&spis, sizeof(A), 1, f);
        //fprintf(f, "%d\n%d\n%d\n%g\n", spis.name, spis.num, spis.sold, spis.market);
    }
    fclose(f);
    fopen_s(&f1, "t2.dat", "wb");
    fopen_s(&f, "t1.dat", "rb");
    while (!feof(f))
    {
        fread(&spis, sizeof(A), 1, f);
        fwrite(&spis, sizeof(A), 1, f1);
    }
    fclose(f);
    fclose(f1);
}
void output(int flag, int count)
{
    FILE* f1;
    fopen_s(&f1, "t2.dat", "rb");
    printf("-------------------------------------------------------------------------\n");
    printf("|фирмы                                                                  |\n");
    printf("|-----------------------------------------------------------------------|\n");
    printf("| назва     | годова€ прибыль      | процент продаж       | часть рынка |\n");
    printf("|-----------|----------------------|----------------------|-------------|\n");
    for (int i = 0; i < 3 + count; i++)
    {
        fread(&spis, sizeof(A), 1, f1);
        printf("| %9s | %20d | %20d | %-11.1f |\n", spis.name, spis.num, spis.sold, spis.market);
        printf("|-----------|----------------------|----------------------|-------------|\n");
    }
    fclose(f1);
}
int add_end(int& count)
{
    FILE* f;
    FILE* f1;
    fopen_s(&f, "t1.dat", "ab");
    cout << "¬ведите дополнительные name, num, sold, market -> ";
    cin >> spis.name;
    cin >> spis.num;
    cin >> spis.sold;
    cin >> spis.market;
    fwrite(&spis, sizeof(A), 1, f);
    fclose(f);
    fopen_s(&f1, "t2.dat", "wb");
    fopen_s(&f, "t1.dat", "rb");
    while (!feof(f))
    {
        fread(&spis, sizeof(A), 1, f);
        fwrite(&spis, sizeof(A), 1, f1);
    }
    fclose(f);
    fclose(f1);
    count++;
    return 0;
}
int add_beg(int& flag, int& count)
{
    FILE* f;
    FILE* f1;
    fopen_s(&f1, "t2.dat", "wb");
    cin >> spis.name;
    cin >> spis.num;
    cin >> spis.sold;
    cin >> spis.market;
    fwrite(&spis, sizeof(A), 1, f1);
    fopen_s(&f, "t1.dat", "rb");
    while (!feof(f))
    {
        fread(&spis, sizeof(A), 1, f);
        fwrite(&spis, sizeof(A), 1, f1);
    }
    count++;
    remove("t1.dat");
    rename("t2.dat", "t1.dat");
    fclose(f);
    fclose(f1);
    flag = 1;
    return 0;
}
void seek(int element_number)
{
    FILE* f1;
    fopen_s(&f1, "t2.dat", "rb");
    fseek(f1, element_number * sizeof(A), SEEK_SET);
    fread(&spis, sizeof(A), 1, f1);
    cout << spis.name << " " << spis.num << " " << spis.sold << " " << spis.market << endl;
    fclose(f1);
}