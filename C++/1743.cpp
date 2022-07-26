#include <iostream>

#define MAX 101

using namespace std;

int n, m, k;
int depth, maxDepth;

int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void dfs(int _x, int _y)
{
	depth++;
	visited[_y][_x] = true;

	for (int i = 0; i < 4; i++)
	{
		int nextX = _x + dx[i];
		int nextY = _y + dy[i];

		if (1 <= nextX && nextX <= m && 1 <= nextY && nextY <= n)
		{
			if (!visited[nextY][nextX] && map[nextY][nextX])
			{
				dfs(nextX, nextY);
			}
		}
	}
}

int main()
{
	// 세로 x 가로, 쓰레기 수 : n x m, k
	cin >> n >> m >> k;

	// 쓰레기 좌표 입력
	for (int i = 0; i < k; i++)
	{
		int r, c;
		cin >> r >> c;
		map[r][c] = 1;
	}

	// dfs 탐색
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (!visited[i][j] && map[i][j]) 
			{
				depth = 0;
				dfs(j, i);

				if (maxDepth < depth)
				{
					maxDepth = depth;
				}
			}
		}
	}

	// 최댓값 출력
	cout << maxDepth;

	return 0;
}
