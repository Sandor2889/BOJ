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
	// 사람의수 n, 친구 관계의 수 m 
	cin >> n >> m;

	// 관계 연결
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	// dfs 실행
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
