#include <iostream>

using namespace std;

int main()
{
	int numsCounting[10001] = {};

	for (int idx = 1; idx <= 10000; idx++)
	{
		int result = 0;
		if (idx < 100)
		{
			result = idx + (idx / 10) + (idx % 10);
		}
		else if (idx >= 100 && idx < 1000)
		{
			result = idx + (idx / 100) + ((idx % 100) / 10) + (idx % 10);
		}
		else if (idx >= 1000 && idx < 10000)
		{
			result = idx + (idx / 1000) + ((idx % 1000) / 100) + ((idx % 100) / 10) + (idx % 10);
		}
		else if (idx == 10000)
		{
			result = 100001;
		}

		if (result <= 10000)
		{
			numsCounting[result]++;
		}
	}

	for (int idx = 1; idx < sizeof(numsCounting) / sizeof(int); idx++)
	{
		if (numsCounting[idx] == 0)
		{
			cout << idx << "\n";
		}
	}
	return 0;
}
