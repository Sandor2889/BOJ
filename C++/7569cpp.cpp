#include <iostream>
#include <vector>
#include <queue>

#define MAX 101

using namespace std;

int n, m, h;
int res;
bool isNoRipe;

int map[MAX][MAX][MAX];

queue<pair<pair<int, int>, int>> q;

// 4���� + ���Ʒ�
int dx[] = { -1, 0, 1, 0, 0, 0 };
int dy[] = { 0, -1, 0, 1, 0, 0 };
int dz[] = {0, 0, 0, 0, 1, -1};

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			int nextZ = z + dz[i];

			if (0 <= nextX && nextX < m && 0 <= nextY && nextY < n && 0 <= nextZ && nextZ < h)
			{
				if (map[nextZ][nextY][nextX] == 0)
				{
					q.push({ {nextX, nextY}, nextZ });
					map[nextZ][nextY][nextX] = map[z][y][x] + 1;
				}
			}
		}
	}
}

// �ϳ��� �������� �丶�䰡 ������ -1 ���
// ��� �ʹµ� �����ϸ� �ּҳ�¥ ���
int search()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (map[i][j][k] == 0)
				{
					return -1;
				}

				if (res < map[i][j][k])
				{
					res = map[i][j][k];
				}
			}
		}
	}

	return res - 1;
}

int main()
{
	// �Է� : ���� x ���� x ����
	cin >> m >> n >> h;

	// �丶�� ��ġ
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				int temp;
				cin >> temp;
				map[i][j][k] = temp;

				if (temp == 1)
				{
					q.push({ { k, j } ,i});
				}
				else if (temp == 0)
				{
					isNoRipe = true;
				}
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
