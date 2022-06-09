#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set<string> s; // 듣도 못한 사람 명단
vector<string> v; // 듣보잡 명단

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	string name;

	cin >> n >> m;


	// 듣도 못한 사람
	for (int idx = 0; idx < n; idx++)
	{
		cin >> name;
		s.insert(name);
	}

	// 보도 못한 사람
	for (int idx = 0; idx < m; idx++)
	{
		cin >> name;
		if (s.find(name) != s.end())
		{
			v.push_back(name);
		}
	}

	// 사전 순 정렬
	sort(v.begin(), v.end());

	// 결과 출력
	cout << v.size() << '\n';
	for (string str : v)
	{
		cout << str << '\n';
	}

	return 0;
}