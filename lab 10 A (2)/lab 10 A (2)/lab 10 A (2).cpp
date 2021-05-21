#include <iostream>
#include <string>
using namespace std;

class myclass
{

public:

	int plosh(int& square, int& rectangle, int a = 0, int b = 0)
	{
		if (b == 0)
		{
			square = a * a;
		}
		else
		{
			rectangle = a * b;
		}
		return 0;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	myclass first;
	int a;
	int b;
	int x;
	int square;
	int rectangle;

	cout << "введите длину: " << endl;

	cin >> a;

	cout << "хотите ввести ширину?\n 1 - yes\n 2 - no" << endl;
	cin >> x;
	if (x == 1)
	{
		cout << "введите ширину: " << endl;
		cin >> b;
		first.plosh(square, rectangle, a, b);
		cout << "площадь равна: " << rectangle;
	}
	if (x == 2)
	{
		first.plosh(square, rectangle, a);
		cout << "площадь равна: " << square;

	}

}
