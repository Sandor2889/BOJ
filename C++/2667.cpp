#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define SIZE 26

using namespace std;

char map[SIZE][SIZE]; // 집의 배치도
int visited[SIZE][SIZE]; // 방문 처리
vector<int> houses; // 단지의 수 및 단지가 가진 집의 개수

// 다음 방문 방향
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int cnt;	// 집의 수
int n;	// 단지의 크기

void bfs(int _y, int _x)
{
	queue<pair<int, int>> q;
	q.push({ _x, _y });
	visited[_y][_x] = true;
	int width = 1;

	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();

		for (int idx = 0; idx < 4; idx++)
		{
			int nextX = p.first + dx[idx];
			int nextY = p.second + dy[idx];
			if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n)
			{
				if (map[nextY][nextX] == '1' && !visited[nextY][nextX])
				{
					q.push({ nextX, nextY });
					cnt++;
					visited[nextY][nextX] = true;
				}
			}
		}
	}
	houses.push_back(cnt);
}

int main()
{
	// 단지의 크기 입력
	cin >> n;

	// 주택 분포 입력
	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}

	// bfs 실행
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == '1' && !visited[i][j])
			{
				cnt = 1;
				bfs(i, j);
			}
		}
	}

	// 오름차순 정렬
	sort(houses.begin(), houses.end());

	// 출력
	cout << houses.size() << '\n';
	for (int house : houses)
	{
		cout << house << '\n';
	}

	return 0;
}