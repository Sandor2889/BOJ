#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int answer = 0;

	// �Է�
	int num;
	cin >> num;

	// ���� �� ã��
	for (int idx = 1; idx <= num; idx++)
	{
		int temp = idx;

		int sumUnits = 0;

		// temp�� �� �ڸ��� ����
		while (temp != 0)
		{
			sumUnits += temp % 10;
			temp /= 10;
		}

		// temp�� temp�� �ڸ��� ��
		int sum = idx + sumUnits;

		// ���� �������
		if (sum == num)
		{
			answer = idx;
			break;
		}
	}

	// ���
	cout << answer;

	return 0;
}