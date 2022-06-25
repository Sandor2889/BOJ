#include <iostream>
#include <vector>
#include <queue>

#define SIZE 51

using namespace std;

int t, m, n, k;	// �Է� ����


int map[SIZE][SIZE];
bool visited[SIZE][SIZE];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int cnt;

void bfs(int _x, int _y)
{
	queue<pair<int, int>> q;
	q.push({_x, _y});
	visited[_y][_x] = true;
	cnt++;

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = cur.first + dx[i];
			int nextY = cur.second + dy[i];

			if (0 <= nextX && nextX < m && 0 <= nextY && nextY < n)
			{
				if (map[nextY][nextX] && !visited[nextY][nextX])
				{
					q.push({nextX, nextY});
					visited[nextY][nextX] = true;
				}
			}
		}
	}
}

void init()
{
	cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			map[i][j] = 0;
			visited[i][j] = false;
		}
	}
}

int main()
{
	// �׽�Ʈ ���̽��� ��
	cin >> t;
	for (int c = 0; c < t; c++)
	{
		cin >> m >> n >> k;
		
		// ���� �ɱ�
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		// BFS ����
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] && !visited[i][j])
				{
					bfs(j, i);
				}
			}
		}

		// ��� ���
		cout << cnt << '\n';
		init();	// �ʱ�ȭ
	}

	return 0;
}