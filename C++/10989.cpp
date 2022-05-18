#include <iostream>

using namespace std;

int arr[10001] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	int input;
	cin >> input;

	// 각 숫자들을 counting
	for (int idx = 0; idx < input; idx++)
	{
		int num;
		cin >> num;
		arr[num]++;
	}


	// 출력
	for (int idx = 0; idx < 10001; idx++)
	{
		if (arr[idx] == 0) { continue; }
		else // 해당 idx가 0이 될때까지 반복 출력
		{
			cout << idx << '\n';
			arr[idx]--;
			idx--;
		}
	}

	return 0;
}