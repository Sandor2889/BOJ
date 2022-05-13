#include <iostream>
#include <vector>

using namespace std;

#define MAX 10000

int arr[MAX + 1];

int main()
{
	// �迭 �ʱ�ȭ
	for (int idx = 2; idx <= MAX; idx++)
	{
		arr[idx] = idx;
	}

	// �Ҽ� �����
	for (int i = 2; i * i <= MAX; i++)
	{
		if (arr[i] == 0) { continue; }

		for (int j = i * i; j <= MAX; j += i)
		{
			arr[j] = 0;
		}
	}

	// �Է�
	int cases;
	cin >> cases;

	// �� ���̽� ����
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

		// �� �Ҽ��� �� ã��
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