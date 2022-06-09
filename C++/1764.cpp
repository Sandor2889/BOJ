#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set<string> s; // �赵 ���� ��� ���
vector<string> v; // �躸�� ���

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	string name;

	cin >> n >> m;


	// �赵 ���� ���
	for (int idx = 0; idx < n; idx++)
	{
		cin >> name;
		s.insert(name);
	}

	// ���� ���� ���
	for (int idx = 0; idx < m; idx++)
	{
		cin >> name;
		if (s.find(name) != s.end())
		{
			v.push_back(name);
		}
	}

	// ���� �� ����
	sort(v.begin(), v.end());

	// ��� ���
	cout << v.size() << '\n';
	for (string str : v)
	{
		cout << str << '\n';
	}

	return 0;
}