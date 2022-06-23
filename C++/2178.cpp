#include <iostream>
#include <queue>

#define SIZE 101

using namespace std;

int n, m;
char maze[SIZE][SIZE];		// 미로 맵
int visited[SIZE][SIZE];	// 방문 처리
int weights[SIZE][SIZE];	// 가중치

// 다음 길의 위치 체크
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// bfs 탐색
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

		// 다음 길의 위치
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
	// 미로의 크기
	cin >> n >> m;

	// 미로 입력
	for (int i = 0; i < n; i++)
	{
		cin >> maze[i];
	}

	bfs(0, 0);
	cout << weights[n - 1][m - 1];

	return 0;
}