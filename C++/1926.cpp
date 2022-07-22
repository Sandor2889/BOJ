#include <iostream>
#include <memory.h>

#define MAX 501

using namespace std;

int n, m;

int map[MAX][MAX];
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
			if (!visited[nextY][nextX] && !map[nextY][nextX])
			{
				dfs(nextX, nextY);
			}
		}
	}
}

int main()
{
	// ¼¼·Î x °¡·Î : n x m
	cin >> n >> m;

	// ¸ÊÀÔ·Â
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	// dfs Å½»ö
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j])
			{
				dfs(j, i);
			}
		}
	}

	return 0;
}
