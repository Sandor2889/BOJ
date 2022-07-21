#include <iostream>
#include <memory.h>

#define MAX 301

using namespace std;

int n, m;
int years;

int map[MAX][MAX];
int newMap[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void dfs(int _x, int _y)
{
	visited[_y][_x] = true;

	for (int i = 0; i < 4; i++)
	{
		int nextX = _x + dx[i];
		int nextY = _y + dy[i];

		if (0 <= nextX && nextX < m && 0 <= nextY && nextY < n)
		{
			if (!visited[nextY][nextX] && map[nextY][nextX])
			{
				dfs(nextX, nextY);
			}
			else if (!map[nextY][nextX] && newMap[_y][_x] > 0)
			{
				newMap[_y][_x]--;
			}
		}
	}
}

int main()
{
	// 행과 열 : n x m
	cin >> n >> m;

	// 맵 입력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;
			map[i][j] = temp;
			newMap[i][j] = temp;
		}
	}

	while (true)
	{
		int cnt = 0;
		// dfs 실행
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!visited[i][j] && map[i][j])
				{
					cnt++;

					if (cnt >= 2) { cout << years; return 0; }
					dfs(j, i);
				}
			}
		}

		if (cnt == 0) { cout << 0; return 0; }
		
		years++;
		// 초기화
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				map[i][j] = newMap[i][j];
			}
		}
		memset(visited, false, sizeof(visited));
	}

	return 0;
}
