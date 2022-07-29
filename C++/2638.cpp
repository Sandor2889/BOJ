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
	// ���� x ���� : n, m
	cin >> n >> m;

	// �� �Է�
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	// ġ� �������� ���������� ����
	while (CheckCheese())
	{
		cheese = 0;
		hour++;

		// �ܺΰ��� �����
		InitOutAir(0, 0);

		// dfs Ž��
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

		// �ʱ�ȭ
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				map[i][j] = nextMap[i][j];
			}
		}	
	}

	// ��� ���
	cout << hour << '\n';
	cout << cheese;

	return 0;
}
