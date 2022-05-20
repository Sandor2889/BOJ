#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, string>>> vPeople;

bool compare(pair<int, pair<int, string>> _a, pair<int, pair<int, string>> _b)
{
	// 나이 순으로 정렬 하되 같으면 입력된 순서로 한다.
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
	// 점의 수 입력
	int people;
	cin >> people;

	for (int idx = 0; idx < people; idx++)
	{
		pair<int, pair<int, string>> data;
		cin >> data.second.first >> data.second.second;
		data.first = idx;	// 입력 순서 추가
		vPeople.push_back(data);
	}

	// 나이 오름차순 정렬
	sort(vPeople.begin(), vPeople.end(), compare);

	// 출력
	for (int idx = 0; idx < vPeople.size(); idx++)
	{
		cout << vPeople[idx].second.first << ' ' << vPeople[idx].second.second << '\n';
	}

	return 0;
}