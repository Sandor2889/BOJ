#include <iostream>
#include <vector>

using namespace std;

// �Ҽ� = ���μ��� 1,n �� �ΰ� �����ϴ� ��
int main()
{
	int min, max;
	cin >> min >> max;

	vector<int> vNums;
	int answer = 0;
	int targetNum = -1;

	for (; min <= max; min++)
	{
		int count = 0;

		for (int idx = 1; idx <= min; idx++)
		{
			if (min % idx == 0)
			{
				count++;
			}
		}

		if (count == 2)
		{
			// �Ҽ��� vector�� �ֱ�
			vNums.push_back(min);
			answer += min;
		}
	}

	// �Ҽ��� ���� ���
	if (answer == 0)
	{
		cout << -1;
		return 0;
	}

	// vector[0]�� ù��° �Ҽ��̴�.
	cout << answer << "\n" << vNums[0];

	return 0;
}