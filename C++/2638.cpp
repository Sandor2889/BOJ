#include <iostream>
#include <memory.h>

#define MAX 101

using namespace std;

int n, m;
int hour;
int cheese;

int map[MAX][MAX];
int nextMap[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void dfs(int _x, int _y)
{
	cheese++;
	visited[_y][_x] = true;
	int air = 0;

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
			else if (map[nextY][nextX] == -1) { air++; }
		}
	}

	if (air >= 1)
	{
		nextMap[_y][_x] = 0;
	}
	else
	{
		nextMap[_y][_x] = map[_y][_x];
	}
}

void InitOutAir(int _x, int _y)
{
	visited[_y][_x] = true;
	map[_y][_x] = -1;

	for (int i = 0; i < 4; i++)
	{
		int nextX = _x + dx[i];
		int nextY = _y + dy[i];

		if (0 <= nextX && nextX < m && 0 <= nextY && nextY < n)
		{
			if (!visited[nextY][nextX] && map[nextY][nextX] == 0)
			{
				InitOutAir(nextX, nextY);
			}
		}
	}
}

bool CheckCheese()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j]) { return true; }
		}
	}
	return false;
}

int main()
{
	// 세로 x 가로 : n, m
	cin >> n >> m;

	// 맵 입력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	// 치즈가 존재하지 않을때까지 실행
	while (CheckCheese())
	{
		cheese = 0;
		hour++;

		// 외부공기 지우기
		InitOutAir(0, 0);

		// dfs 탐색
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!visited[i][j] && map[i][j])
				{
					dfs(j, i);
				}
			}
		}

		// 초기화
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				map[i][j] = nextMap[i][j];
			}
		}	
	}

	// 결과 출력
	cout << hour << '\n';
	cout << cheese;

	return 0;
}
