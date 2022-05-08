#include <iostream>

using namespace std;

int main()
{
	int input;
	int count = 0;
	cin >> input;

	for (int idx = 1; idx <= input; idx++)
	{
		if (idx < 100)
		{
			count++;
		}
		else if (idx > 100)
		{
			int units = idx % 10;
			int	tens = (idx % 100) / 10;
			int hundreds = idx / 100;

			if ((units - tens) == (tens - hundreds))
			{
				count++;
			}
		}
		else if (idx == 1000)
		{
			break;
		}
	}


	cout << count;

	return 0;
}