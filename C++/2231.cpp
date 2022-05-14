#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int answer = 0;

	// 입력
	int num;
	cin >> num;

	// 분해 합 찾기
	for (int idx = 1; idx <= num; idx++)
	{
		int temp = idx;

		int sumUnits = 0;

		// temp의 각 자리수 도출
		while (temp != 0)
		{
			sumUnits += temp % 10;
			temp /= 10;
		}

		// temp와 temp의 자리수 합
		int sum = idx + sumUnits;

		// 합이 같은경우
		if (sum == num)
		{
			answer = idx;
			break;
		}
	}

	// 출력
	cout << answer;

	return 0;
}