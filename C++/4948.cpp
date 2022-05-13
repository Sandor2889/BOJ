#include <iostream>

using namespace std;

// 에라토스테네스의 체 이용


#define MAX 123456 * 2

int arr[MAX + 1];
int main()
{
	// 소수를 미리 찾아 배열에 저장
	for (int idx = 2; idx <= MAX; idx++)
	{
		arr[idx] = idx;
	}

	for (int i = 2; i * i <= MAX; i++)
	{
		if (arr[i] == 0) { continue; }

		for (int j = i * i; j <= MAX; j += i)
		{
			arr[j] = 0;
		}
	}

	// 요구하는 각각의 범위내에 있는 소수만 뽑아 출력
	while (true)
	{
		int answer = 0;
		int input;
		cin >> input;

		if (input == 0) { return 0; }

		int min = input + 1;
		int max = input * 2;

		for (int temp = min; temp <= max; temp++)
		{
			if (arr[temp] != 0) { answer++; }
		}

		cout << answer << "\n";
	}

	return 0;
}