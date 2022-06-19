#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> vec[1001];
int visited[1001];

void dfs(int _x)
{
	if (visited[_x]) { return; }
	visited[_x] = true;
	cout << _x << ' ';
	for (int i = 0; i < vec[_x].size(); i++)
	{
		int y = vec[_x][i];
		dfs(y);
	}
}

void bfs(int _start)
{
	queue<int> q;
	q.push(_start);
	visited[_start] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < vec[x].size(); i++)
		{
			int y = vec[x][i];
			if (!visited[y])
			{
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

// BFS 실행을 위한 배열 초기화
void clearArr()
{
	for (int idx = 0; idx < 1001; idx++)
	{
		visited[idx] = false;
	}
	cout << '\n';
}

// 작은 수 먼저 탐색을 위한 vector의 모든 공간들 정렬
void sortAllVec()
{
	for (int idx = 0; idx < 1001; idx++)
	{
		sort(vec[idx].begin(), vec[idx].end());
	}
}

int main()
{
	// 접점, 간선, 시작점 입력
	int n, m, v;
	cin >> n >> m >> v;
	
	// 간선 연결
	int num1, num2;
	for (int idx = 0; idx < m; idx++)
	{
		cin >> num1 >> num2;
		vec[num1].push_back(num2);
		vec[num2].push_back(num1);
	}
	
	// 실행
	sortAllVec();
	dfs(v);
	clearArr();
	bfs(v);

	return 0;
}