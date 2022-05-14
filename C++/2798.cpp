#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int answer = 0;

	// �Է�
	int cards, target;
	cin >> cards >> target;

	// ���� ī����� vector�� ������� ����
	vector<int> vCards(cards);

	for (int idx = 0; idx < cards; idx++)
	{
		cin >> vCards[idx];
	}

	// �� ���� ī�� �̱�
	for (int i = 0; i < cards - 2; i++)
	{
		for (int j = i + 1; j < cards - 1; j++)
		{
			for (int k = j + 1; k < cards; k++)
			{
				int sum = vCards[i] + vCards[j] + vCards[k];

				// ���� ������ �� ���� �� ã�� 
				if (sum > answer && sum <= target)
				{
					answer = sum;
				}
			}
		}
	}

	// ���
	cout << answer;

	return 0;
}