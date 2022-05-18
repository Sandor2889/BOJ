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

	// �Է�
	int input;
	cin >> input;

	// �� ������ vector�� ����
	vector<float> vNums;
	for (int idx = 0; idx < input; idx++)
	{
		int num;
		cin >> num;
		vNums.push_back(num);
		sum += num;

		arr[num + 4000]++;
	}

	// �������� ����
	sort(vNums.begin(), vNums.end());

	// ��� ���
	int avg = round(sum / (float)vNums.size());
	cout << avg << '\n';

	// �߾� ��
	cout << vNums[vNums.size() / 2] << '\n';

	// �ֺ� ��
	for (int idx = 0; idx < 8001; idx++)
	{
		if (arr[idx] == 0) { continue; }

		// ���帹�� ���� ���߿� �ι�°�� ���� �� ã�� (flag)
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

	// ���� ��
	cout << vNums[vNums.size() - 1] - vNums[0];

	return 0;
}