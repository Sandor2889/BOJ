#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int first, second;
	int ftUnits, ftTens, ftHundreds, sdUnits, sdTens, sdHundreds;

	cin >> first >> second;

	ftUnits = first % 10;
	ftTens = (first % 100) / 10;
	ftHundreds = first / 100;
	first = (ftUnits * 100) + (ftTens * 10) + (ftHundreds);

	sdUnits = second % 10;
	sdTens = (second % 100) / 10;
	sdHundreds = second / 100;
	second = (sdUnits * 100) + (sdTens * 10) + (sdHundreds);

	if (first > second)
	{
		cout << first;
	}
	else if (first < second)
	{
		cout << second;
	}

	return 0;
}