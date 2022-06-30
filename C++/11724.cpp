#include <iostream>
#include <vector>

#define SIZE 1001

using namespace std;

vector<int> graph[SIZE];
bool visited[SIZE];

void dfs(int _x)
{
	if (visited[_x]) { return; }

	visited[_x] = true;
	for (int i = 0; i < graph[_x].size(); i++)
	{
		int n = graph[_x][i];
		dfs(n);
	}
}

int main()
{
	// �����Ǽ�, ������ ��
	int n, m;
	cin >> n >> m;

	// ���� ����
	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// DFS ����
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			dfs(i);
			count++;
		}
	}

	// ��� ���
	cout << count;

	return 0;
}