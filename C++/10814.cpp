#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, string>>> vPeople;

bool compare(pair<int, pair<int, string>> _a, pair<int, pair<int, string>> _b)
{
	// ���� ������ ���� �ϵ� ������ �Էµ� ������ �Ѵ�.
	if (_a.second.first == _b.second.first)
	{
		return _a.first < _b.first;
	}
	else
	{
		return _a.second.first < _b.second.first;
	}
}

int main()
{
	// ���� �� �Է�
	int people;
	cin >> people;

	for (int idx = 0; idx < people; idx++)
	{
		pair<int, pair<int, string>> data;
		cin >> data.second.first >> data.second.second;
		data.first = idx;	// �Է� ���� �߰�
		vPeople.push_back(data);
	}

	// ���� �������� ����
	sort(vPeople.begin(), vPeople.end(), compare);

	// ���
	for (int idx = 0; idx < vPeople.size(); idx++)
	{
		cout << vPeople[idx].second.first << ' ' << vPeople[idx].second.second << '\n';
	}

	return 0;
}