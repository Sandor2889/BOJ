nclude <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>

#define SIZE 101

using namespace std;

int n;
char current;

int map[SIZE][SIZE];	// 지역별 높이 값
bool visited[SIZE][SIZE];	// 방문처리
vector<int> maxCnt; // 안전영역 수 저장
int maxHeight = 0; // 가장 높은 지역의 높이

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void dfs(int _x, int _y)
{
	for (int i = 0; i < 4; i++)
	{
		int nextX = _x + dx[i];
		int nextY = _y + dy[i];

		if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n)
		{
			if (!visited[nextY][nextX])
			{
				visited[nextY][nextX] = true;
				dfs(nextX, nextY);
			}
		}
	}
}

int main()
{
	// 크기 입력 n x n
	cin >> n;

	// 지역의 높이 정보 입력
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			map[i][j] = temp;
			if (temp > maxHeight)
			{
				maxHeight = temp;
			}
		}
	}

	// 최대 높이 만큼 반복
	for (int cnt = 0; cnt <= maxHeight; cnt++)
	{
		// 안전하지 않은 지역 방문처리 
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j] <= cnt)
				{
					visited[i][j] = true;
				}
			}
		}

		// DFS 탐색
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j])
				{
					visited[i][j] = true;
					count++;
					dfs(j, i);
				}
			}
		}
		maxCnt.push_back(count);

		// 초기화
		memset(visited, false, sizeof(visited));
	}
	int answer = *max_element(maxCnt.begin(), maxCnt.end());
	cout << answer;

	return 0;
}
