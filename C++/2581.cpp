#include <iostream>
#include <vector>

using namespace std;

// 소수 = 소인수가 1,n 단 두개 존재하는 수
int main()
{
	int min, max;
	cin >> min >> max;

	vector<int> vNums;
	int answer = 0;
	int targetNum = -1;

	for (; min <= max; min++)
	{
		int count = 0;

		for (int idx = 1; idx <= min; idx++)
		{
			if (min % idx == 0)
			{
				count++;
			}
		}

		if (count == 2)
		{
			// 소수를 vector에 넣기
			vNums.push_back(min);
			answer += min;
		}
	}

	// 소수가 없을 경우
	if (answer == 0)
	{
		cout << -1;
		return 0;
	}

	// vector[0]이 첫번째 소수이다.
	cout << answer << "\n" << vNums[0];

	return 0;
}