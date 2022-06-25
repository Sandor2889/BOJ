#include <iostream>
#include <vector>
#include <queue>

#define SIZE 51

using namespace std;

int t, m, n, k;	// 입력 변수


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
	// 테스트 케이스의 수
	cin >> t;
	for (int c = 0; c < t; c++)
	{
		cin >> m >> n >> k;
		
		// 배추 심기
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		// BFS 실행
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

		// 결과 출력
		cout << cnt << '\n';
		init();	// 초기화
	}

	return 0;
}