#include <iostream>
#include <vector>

using namespace std;

#define MAX 10000

int arr[MAX + 1];

int main()
{
	// 배열 초기화
	for (int idx = 2; idx <= MAX; idx++)
	{
		arr[idx] = idx;
	}

	// 소수 만들기
	for (int i = 2; i * i <= MAX; i++)
	{
		if (arr[i] == 0) { continue; }

		for (int j = i * i; j <= MAX; j += i)
		{
			arr[j] = 0;
		}
	}

	// 입력
	int cases;
	cin >> cases;

	// 각 케이스 실행
	for (int caseIdx = 0; caseIdx < cases; caseIdx++)
	{
		int evenNum;
		cin >> evenNum;

		vector<int> prime;
		bool flag = false;

		for (int vIdx = 2; vIdx <= evenNum; vIdx++)
		{
			if (arr[vIdx] != 0)
			{
				prime.push_back(arr[vIdx]);
			}
		}

		// 두 소수의 합 찾기
		for (int i = 0; i < prime.size(); i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (prime[i] + prime[j] == evenNum)
				{
					cout << prime[j] << ' ' << prime[i] << '\n';
					flag = true;
					break;
				}
			}

			if (flag) { break; }
		}
	}

	return 0;
}