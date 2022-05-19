#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> vCoord;

bool compare(pair<int, int> _a, pair<int, int> _b)
{
	// y��ǥ�� ������ x��ǥ�� ��
	if (_a.second == _b.second)
	{
		return _a.first < _b.first;
	}
	else
	{
		return _a.second < _b.second;
	}
}

int main()
{
	// ���� �� �Է�
	int nums;
	cin >> nums;

	for (int idx = 0; idx < nums; idx++)
	{
		pair<int, int> coord;
		cin >> coord.first >> coord.second;
		vCoord.push_back(coord);
	}

	// �������� ����
	sort(vCoord.begin(), vCoord.end(), compare);

	// ���
	for (int idx = 0; idx < vCoord.size(); idx++)
	{
		cout << vCoord[idx].first << ' ' << vCoord[idx].second << '\n';
	}

	return 0;
}