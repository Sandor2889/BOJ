#include <iostream>
#include <queue>

#define MAX 51

using namespace std;

int n, m;
int max_cnt;

int map[MAX][MAX];
int copyMap[MAX][MAX];
int visited[MAX][MAX];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int lastX, lastY;

queue<pair<int, int>> q;

int bfs(int _x, int _y)
{
	q.push({_x, _y});
	visited[_y][_x] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		lastX = x;
		lastY = y;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			if (0 <= nextX && nextX < m && 0 <= nextY && nextY < n)
			{
				if (copyMap[nextY][nextX] == 0 && !visited[nextY][nextX])
				{
					copyMap[nextY][nextX] = copyMap[y][x] + 1;
					visited[nextY][nextX] = true;
					q.push({ nextX, nextY });
				}
			}
		}
	}

	return copyMap[lastY][lastX];
}

void Init()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			copyMap[i][j] = map[i][j];
			visited[i][j] = false;
		}
	}
}

int main()
{
	// 입력 : 세로 x 가로
	cin >> n >> m;

	// 맵 입력
	string temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		for (int j = 0; j < m; j++)
		{
			// 바다는 -1로 등록하기
			if (temp[j] == 'W')
			{
				map[i][j] = -1;
			}
		}
	}

	// bfs 실행
	// 모든 육지에 대해 bfs 실행
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
			{
				// 맵 복사 및 초기화
				Init();

				int cnt = bfs(j, i);

				if (max_cnt < cnt)
				{
					max_cnt = cnt;
				}
			}
		}
	}

	// 최댓값 출력
	cout << max_cnt;

	return 0;
}