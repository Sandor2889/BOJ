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

// 4방향 + 위아래
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

// 하나라도 익지않은 토마토가 있으면 -1 출력
// 모두 익는데 성공하면 최소날짜 출력
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
	// 입력 : 가로 x 세로 x 높이
	cin >> m >> n >> h;

	// 토마토 배치
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


	// 모두 익은 상태면 0을 출력하고 종료
	if (!isNoRipe) { cout << 0; return 0; }

	// bfs 실행
	bfs();

	cout << search();

	return 0;
}
