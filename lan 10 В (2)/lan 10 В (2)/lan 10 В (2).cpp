#include <iostream>
using namespace std;

class SUM
{
    int x, y, s;
public:

    SUM()
    {
        x = 0;
        y = 0;
        s = 0;
    }
    SUM(int valuex, int valuey)
    {
        x = valuex;
        y = valuey;
    }
    void setX(int valx)
    {
        x = valx;
    }
    void setY(int valy)
    {
        y = valy;
    }
    void show()
    {
        cout << " x = " << x << " y = " << y << " s = " << s << endl;
    }
    void sum()
    {
        s = x + y;
        cout << "sum = " << s << endl;
    }
};

int main()
{
    SUM b, * p;
    b.show();
    b.sum();
    //p = &b;
    //p->show();
    //p->sum();
    SUM a(6, 7), * p1;
    a.setX(5);
    a.setY(6);
    a.show();
    a.sum();
    //p1 = &a;
    //p1->setX(10);
    //p1->setY(11);
    //p1->show();
    //p1->sum();

}
