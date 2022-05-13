#include <iostream>

using namespace std;

// �����佺�׳׽��� ü �̿�


#define MAX 123456 * 2

int arr[MAX + 1];
int main()
{
	// �Ҽ��� �̸� ã�� �迭�� ����
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

	// �䱸�ϴ� ������ �������� �ִ� �Ҽ��� �̾� ���
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