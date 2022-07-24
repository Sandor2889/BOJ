#include <iostream>
#include <vector>

#define MAX 2001

using namespace std;

int n, m;
bool isFour;

vector<int> v[MAX];
bool visited[MAX];

void dfs(int _x, int cnt)
{
	if (cnt >= 4) { isFour = true; return; }
	visited[_x] = true;

	for (int i = 0; i < v[_x].size(); i++)
	{
		int next = v[_x][i];
		if (!visited[next] && !isFour)
		{
			dfs(next, cnt + 1);
		}
	}
	visited[_x] = false;
}

int main()
{
	// ����Ǽ� n, ģ�� ������ �� m 
	cin >> n >> m;

	// ���� ����
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	// dfs ����
	for (int j = 0; j < n; j++)
	{
		dfs(j, 0);
		if (isFour)
		{
			break;
		}
	}
	cout << isFour;

	return 0;
}
