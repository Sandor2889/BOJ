#include <iostream>
#include <queue>

#define SIZE 101

using namespace std;

int n, m;
char maze[SIZE][SIZE];		// �̷� ��
int visited[SIZE][SIZE];	// �湮 ó��
int weights[SIZE][SIZE];	// ����ġ

// ���� ���� ��ġ üũ
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// bfs Ž��
void bfs(int _x, int _y)
{
	queue<pair<int, int>> q;
	q.push({_x, _y});
	visited[_x][_y] = true;
	weights[_x][_y] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// ���� ���� ��ġ
		for (int idx = 0; idx < 4; idx++)
		{
			int nextX = x + dx[idx];
			int nextY = y + dy[idx];
			if (0 <= nextX && nextX < m && 0 <= nextY && nextY < n)
			{
				if (maze[nextY][nextX] == '1' && !visited[nextY][nextX])
				{
					q.push({ nextX, nextY });
					visited[nextY][nextX] = true;
					weights[nextY][nextX] = weights[y][x] + 1;
				}
			}
		}
	}
}


int main()
{
	// �̷��� ũ��
	cin >> n >> m;

	// �̷� �Է�
	for (int i = 0; i < n; i++)
	{
		cin >> maze[i];
	}

	bfs(0, 0);
	cout << weights[n - 1][m - 1];

	return 0;
}