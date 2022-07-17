#include <iostream>

#define MAX 501

using namespace std;

int m, n;
int cnt;

int map[MAX][MAX];
int dp[MAX][MAX];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int dfs(int _x, int _y)
{	
	if (_x == n - 1 && _y == m - 1) { return 1; }
	if (dp[_y][_x] != -1) { return dp[_y][_x]; }

	dp[_y][_x] = 0;

	for (int i = 0; i < 4; i++)
	{
		int nextX = _x + dx[i];
		int nextY = _y + dy[i];

		if (0 <= nextX && nextX < n && 0 <= nextY && nextY < m)
		{
			if (map[_y][_x] > map[nextY][nextX])
			{
				dp[_y][_x] = dp[_y][_x] + dfs(nextX, nextY);
			}
		}
	}
	return dp[_y][_x];
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);

	// 지도의 세로 x 가로 : m x n
	cin >> m >> n;

	// 맵 입력
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}

	// dfs 실행
	cnt = dfs(0, 0);

	// 출력
	cout << cnt;

	return 0;
}
