#include <iostream>

using namespace std;

bool IsPrime(int _num)
{
	if (_num < 2) { return false; }

	for (int idx = 2; idx * idx <= _num; idx++)
	{
		if (_num % idx == 0) { return false; }
	}
	return true;
}

int main()
{
	int min, max;
	cin >> min >> max;

	for (int idx = min; idx <= max; idx++)
	{
		if (IsPrime(idx)) { cout << idx << "\n"; }
	}

	return 0;
}