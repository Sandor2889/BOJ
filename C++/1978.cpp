#include <iostream>

using namespace std;

// �Ҽ� = ���μ��� 1,n �� �ΰ� �����ϴ� ��
int main()
{
	int answer = 0;
	int numbers;

	cin >> numbers;

	for (int idx = 0; idx < numbers; idx++)
	{
		int count = 0;
		int num;
		cin >> num;

		for (int numIdx = 1; numIdx <= num; numIdx++)
		{
			if (num % numIdx == 0)
			{
				count++;
			}
		}

		// ������ ������ ���� 1�� �ڱ� �ڽ��� �� �ΰ��� ���
		if (count == 2)
		{
			answer++;
		}
	}

	cout << answer;

	return 0;
}