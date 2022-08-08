#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

#define MAX 8

using namespace std;

int n, m;
int cnt, max_cnt;
int wall = 3;

int map[MAX][MAX];
int newMap[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void copyMap(int _newMap[MAX][MAX], int _map[MAX][MAX])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			_newMap[i][j] = _map[i][j];
		}
	}
}

void bfs_virus()
{
	copyMap(newMap, map);
	
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 2)
			{
				q.push({ j, i });
				visited[i][j] = true;
			}
		}
	}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			if (0 <= nextX && nextX < m && 0 <= nextY && nextY < n)
			{
				if (!visited[nextY][nextX] && newMap[nextY][nextX] == 0)
				{
					newMap[nextY][nextX] = 2;
					visited[nextY][nextX] = true;
					q.push({nextX, nextY});
				}
			}
		}
	}

	memset(visited, false, sizeof(visited));
	
	// 안전 구역 크기
	cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (newMap[i][j] == 0)
			{
				cnt++;
			}
		}
	}

	if (max_cnt < cnt)
	{
		max_cnt = cnt;
	}
}

void consWall()
{
	if (wall == 0)
	{
		bfs_virus();
		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				wall--;
				consWall();

				wall++;
				map[i][j] = 0;
			}
		}
	}
	
}

int main()
{
	// 입력 : 세로(n) x 가로(m)
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	// 모든 0에 대하여 wall 세우기
	consWall();

	// 출력
	cout << max_cnt;

	return 0;
}
