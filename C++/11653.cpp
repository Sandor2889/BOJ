#include <iostream>

using namespace std;

int main()
{
	int number;

	cin >> number;

	// 입력이 1인 경우 종료
	if (number == 1) { return 0; }

	for (int idx = 2; idx * idx <= number; idx++)
	{
		while (number % idx == 0)
		{
			cout << idx << "\n";
			number /= idx;
		}
	}

	if (number > 1) { cout << number; }

	return 0;
}
