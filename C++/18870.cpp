#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vCoord;

int main()
{
	// ��ǥ �� �Է�
	int nums;
	cin >> nums;

	for (int idx = 0; idx < nums; idx++)
	{
		int coord;
		cin >> coord;
		vCoord.push_back(coord);
	}

	vector<int> vRank(vCoord);

	// �������� ����
	sort(vRank.begin(), vRank.end());

	// �ߺ��� ����
	vRank.erase(unique(vRank.begin(), vRank.end()), vRank.end());

	// ���
	for (int idx = 0; idx < nums; idx++)
	{
		int rank = lower_bound(vRank.begin(), vRank.end(), vCoord[idx]) - vRank.begin();
		cout << rank << ' ';
	}

	return 0;
}