#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE 101

bool map[SIZE][SIZE];
vector<int> squareArea;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int m, n, k;
int cnt = 0, weight = 0;

void dfs(int _x, int _y)
{
	map[_y][_x] = true;

	for (int i = 0; i < 4; i++)
	{
		int nextX = _x + dx[i];
		int nextY = _y + dy[i];

		if (0 <= nextX && nextX < n && 0 <= nextY && nextY < m)
		{
			if (!map[nextY][nextX])
			{
				weight++;
				dfs(nextX, nextY);
			}
		}
	}
}

int main()
{
	// 세로 x 가로 : m x n
	// 직사각형의 수 : k
	cin >> m >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		// 직사각형 방문처리 하기
		for (int column = y1; column < y2; column++)
		{
			for (int row = x1; row < x2; row++)
			{
				map[column][row] = true;
			}
		}
	}

	// dfs 실행
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!map[i][j])
			{
				weight = 1;
				cnt++;
				dfs(j, i);
				squareArea.push_back(weight);
			}
		}
	}
	
	sort(squareArea.begin(), squareArea.end());

	// 출력
	cout << cnt << '\n';
	for (int i = 0; i < squareArea.size(); i++)
	{
		cout << squareArea[i] << ' ';
	}

	return 0;
}
