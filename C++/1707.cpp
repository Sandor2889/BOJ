#include <iostream>
#include <vector>
#include <string.h>

#define MAX 20001

using namespace std;

int v, e;

vector<int> graph[MAX];
int nodeColor[MAX];

// color : 0 = 방문 하지 않음
void dfs(int _node)
{	
	if (!nodeColor[_node]) { nodeColor[_node] = 1; }

	for (int i = 0; i < graph[_node].size(); i++)
	{
		int next = graph[_node][i];
		if (!nodeColor[next])
		{
			if (nodeColor[_node] == 1)
			{
				nodeColor[next] = 2;
			}
			else if (nodeColor[_node] == 2)
			{
				nodeColor[next] = 1;
			}
			dfs(next);
		}
	}
}

// 인접한 노드의 색과 같으면 "No"
string answer()
{
	for (int i = 1; i <= v; i++)
	{
		for (int j = 0; j < graph[i].size(); j++)
		{
			int next = graph[i][j];
			if (nodeColor[i] == nodeColor[next])
			{
				return "NO";
			}
		}
	}
	return "YES";
}

int main()
{
	// 케이스의 수
	int k;
	cin >> k;

	for (int idx = 0; idx < k; idx++)
	{	
		// 정점의 수, 간선의 수
		cin >> v >> e;

		// 간선 연결
		for (int i = 0; i < e; i++)
		{
			int u, v;
			cin >> u >> v;

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		// dfs 실행
		for (int i = 1; i <= v; i++)
		{
			if (!nodeColor[i])
			{
				dfs(i);
			}
		}

		// 출력
		cout << answer() << '\n';

		// 초기화
		memset(graph, 0, sizeof(graph));
		memset(nodeColor, 0, sizeof(nodeColor));
	}
	return 0;
}
