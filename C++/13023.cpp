#include <iostream>
#include <vector>


#define MAX 2001

using namespace std;

int n, m;

vector<int> v[MAX];
bool visited[MAX];

void dfs(int _x)
{
	for (int i = 0; i < v[_x].size(); i++)
	{
		int next = v[_x][i];
		if (!visited[next])
		{
			dfs(next);
		}
	}
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

	return 0;
}
