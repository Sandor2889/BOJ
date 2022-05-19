#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vNum;

bool compare(int _a, int _b)
{
	return _a > _b;
}

int main()
{
	// 입력
	int num;
	cin >> num;

	// 각 자릿수를 vector에 저장
	while (num > 0)
	{
		int units = num % 10;
		vNum.push_back(units);
		num /= 10;
	}

	// 내림차순 정렬
	sort(vNum.begin(), vNum.end(), compare);

	// 출력
	for (int idx : vNum)
	{
		cout << idx;
	}

	return 0;
}