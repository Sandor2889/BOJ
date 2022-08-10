#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001

using namespace std;

int n, m;
int res;
bool isNoRipe;

int map[MAX][MAX];

queue<pair<int, int>> q;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };


void bfs()
{
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
				if (map[nextY][nextX] == 0)
				{
					q.push({ nextX, nextY });
					map[nextY][nextX] = map[y][x] + 1;
				}
			}
		}
	}
}

// �ϳ��� �������� �丶�䰡 ������ -1 ���
// ��� �ʹµ� �����ϸ� �ּҳ�¥ ���
int search()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
			{
				return -1;
			}

			if (res < map[i][j])
			{
				res = map[i][j];
			}
		}
	}

	return res - 1;
}

int main()
{
	// �Է� : ���� x ����
	cin >> m >> n;

	// �丶�� ��ġ
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;
			map[i][j] = temp;

			if (temp == 1)
			{
				q.push({ j, i });
			}
			else if (temp == 0)
			{
				isNoRipe = true;
			}
		}
	}

	// ��� ���� ���¸� 0�� ����ϰ� ����
	if (!isNoRipe) { cout << 0; return 0; }

	// bfs ����
	bfs();

	cout << search();

	return 0;
}
