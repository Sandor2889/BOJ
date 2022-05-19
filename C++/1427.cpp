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
	// �Է�
	int num;
	cin >> num;

	// �� �ڸ����� vector�� ����
	while (num > 0)
	{
		int units = num % 10;
		vNum.push_back(units);
		num /= 10;
	}

	// �������� ����
	sort(vNum.begin(), vNum.end(), compare);

	// ���
	for (int idx : vNum)
	{
		cout << idx;
	}

	return 0;
}