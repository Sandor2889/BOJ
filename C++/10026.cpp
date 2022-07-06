#include <iostream>
#include <memory.h>

#define SIZE 101

using namespace std;

int n;
char current;

char map[SIZE][SIZE];
bool visited[SIZE][SIZE];

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
			if (!visited[nextY][nextX] && map[_y][_x] == map[nextY][nextX])
			{
				visited[nextY][nextX] = true;
				dfs(nextX, nextY);
			}
		}
	}
}

int main()
{
	// ũ�� �Է� n x n
	cin >> n;

	// �ʿ� �׸� ��ġ
	char temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			map[i][j] = temp;
		}
	}

	// DFS Ž��
	// ���ϻ� �ƴ� ���
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				current = map[i][j];
				count++;
				visited[i][j] = true;
				dfs(j, i);
			}
		}
	}
	cout << count << ' ';
	
	// ���ϻ��� ���
	// �ʱ�ȭ
	count = 0;
	current = ' ';
	memset(visited, false, sizeof(visited));
	// �� �籸��
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 'G')
			{
				map[i][j] = 'R';
			}
		}
	}

	// DFS Ž��
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				count++;
				visited[i][j] = true;
				dfs(j, i);
			}
		}
	}
	cout << count;

	return 0;
}