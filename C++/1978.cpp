#include <iostream>

using namespace std;

// 소수 = 소인수가 1,n 단 두개 존재하는 수
int main()
{
	int answer = 0;
	int numbers;

	cin >> numbers;

	for (int idx = 0; idx < numbers; idx++)
	{
		int count = 0;
		int num;
		cin >> num;

		for (int numIdx = 1; numIdx <= num; numIdx++)
		{
			if (num % numIdx == 0)
			{
				count++;
			}
		}

		// 나누어 떨어진 수가 1과 자기 자신인 단 두개의 경우
		if (count == 2)
		{
			answer++;
		}
	}

	cout << answer;

	return 0;
}