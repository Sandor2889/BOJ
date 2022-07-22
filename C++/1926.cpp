#include <iostream>
#include <vector>

#define MAX 501

using namespace std;

int n, m;
int cnt;
int maxWidth = 0;

int map[MAX][MAX];
bool visited[MAX][MAX];
vector<int> v;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void dfs(int _x, int _y)
{
	visited[_y][_x] = true;
	cnt++;

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
		}
	}
}

int main()
{
	// ���� x ���� : n x m
	cin >> n >> m;

	// ���Է�
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	// dfs Ž��
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j] && map[i][j])
			{
				cnt = 0;
				dfs(j, i);
				v.push_back(cnt);

				if (maxWidth <= cnt)
				{
					maxWidth = cnt;
				}
			}
		}
	}

	// ��� : �׸��� ��, ���� ���� �׸��� ����
	cout << v.size() << '\n' << maxWidth;

	return 0;
}
