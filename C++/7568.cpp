#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// ��� �� �Է�
	int people;
	cin >> people;

	vector<pair<int, int>> vData(people);	// �Է°�

	// �Է� �� vector�� ����
	for (int idx = 0; idx < people; idx++)
	{
		cin >> vData[idx].first >> vData[idx].second;
	}

	// Ž��
	for (int i = 0; i < vData.size(); i++)
	{
		int rank = 1;
		for (int j = 0; j < vData.size(); j++)
		{
			// �����Կ� Ű ��
			if (vData[i].first < vData[j].first && vData[i].second < vData[j].second)
			{
				rank++;
			}
		}

		cout << rank << ' ';
	}


	return 0;
}