#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define SIZE 26

using namespace std;

char map[SIZE][SIZE]; // ���� ��ġ��
int visited[SIZE][SIZE]; // �湮 ó��
vector<int> houses; // ������ �� �� ������ ���� ���� ����

// ���� �湮 ����
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int cnt;	// ���� ��
int n;	// ������ ũ��

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
	// ������ ũ�� �Է�
	cin >> n;

	// ���� ���� �Է�
	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}

	// bfs ����
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

	// �������� ����
	sort(houses.begin(), houses.end());

	// ���
	cout << houses.size() << '\n';
	for (int house : houses)
	{
		cout << house << '\n';
	}

	return 0;
}