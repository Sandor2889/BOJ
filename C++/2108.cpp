#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int arr[8001] = { 0 };

int main()
{
	int sum = 0;
	int count = -9999;
	int value = 0;
	bool flag = false;

	// 입력
	int input;
	cin >> input;

	// 각 수들을 vector에 저장
	vector<float> vNums;
	for (int idx = 0; idx < input; idx++)
	{
		int num;
		cin >> num;
		vNums.push_back(num);
		sum += num;

		arr[num + 4000]++;
	}

	// 오름차순 정렬
	sort(vNums.begin(), vNums.end());

	// 산술 평균
	int avg = round(sum / (float)vNums.size());
	cout << avg << '\n';

	// 중앙 값
	cout << vNums[vNums.size() / 2] << '\n';

	// 최빈 값
	for (int idx = 0; idx < 8001; idx++)
	{
		if (arr[idx] == 0) { continue; }

		// 가장많이 나온 수중에 두번째로 작은 값 찾기 (flag)
		if (arr[idx] == count)
		{
			if (flag)
			{
				value = idx - 4000;
				flag = false;
			}
		}
		if (arr[idx] > count)
		{
			count = arr[idx];
			value = idx - 4000;
			flag = true;
		}

	}
	cout << value << '\n';

	// 범위 값
	cout << vNums[vNums.size() - 1] - vNums[0];

	return 0;
}