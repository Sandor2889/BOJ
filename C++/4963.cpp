#include <iostream>

#define SIZE 51

using namespace std;

int map[SIZE][SIZE];
bool visited[SIZE][SIZE];

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, -1, 0, 1, -1, 1, -1, 1 };

int w, h;

void dfs(int _x, int _y)
{
	for (int i = 0; i < 8; i++)
	{
		int nextX = _x + dx[i];
		int nextY = _y + dy[i];

		if (0 <= nextX && nextX < w && 0 <= nextY && nextY < h)
		{
			if (!visited[nextY][nextX] && map[nextY][nextX])
			{
				visited[nextY][nextX] = true;
				dfs(nextX, nextY);
			}
		}
	}
}

int main()
{
	while (true)
	{
		// 너비와 높이 입력
		cin >> w >> h;

		if (w == 0 && h == 0) { break; }

		// 지도 초기화
		int temp;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> temp;
				map[i][j] = temp;
				visited[i][j] = false;
			}
		}

		// DFS 실행
		int count = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (!visited[i][j] && map[i][j])
				{
					visited[i][j] = true;
					dfs(j, i);
					count++;
				}
			}
		}

		// 결과 출력
		cout << count << '\n';
	}

	return 0;
}