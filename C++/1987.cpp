#include <iostream>

#define SIZE 21
#define ALPHABETS 26

using namespace std;

char map[SIZE][SIZE];
int visited[ALPHABETS];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int r, c;
string input;
int mexWeight = 0;

void dfs(int _x, int _y, int _weight)
{
	visited[map[_y][_x] - 'A'] = true;

	// �ִ밪 ����
	mexWeight = max(mexWeight, _weight);

	// ���� ��� Ȯ��
	for (int i = 0; i < 4; i++)
	{
		int nextX = _x + dx[i];
		int nextY = _y + dy[i];

		if (0 <= nextX && nextX < c && 0 <= nextY && nextY < r)
		{
			if (!visited[map[nextY][nextX] - 'A'])
			{
				dfs(nextX, nextY, _weight + 1);
				visited[map[nextY][nextX] - 'A'] = false;
			}
		}
	}
}

int main()
{
	// ���� x ���� : r x c
	cin >> r >> c;

	// �ʿ� ���ĺ� �Է�
	for (int i = 0; i < r; i++)
	{
		cin >> map[i];
	}

	// dfs ����
	dfs(0, 0, 1);

	// �ִ� ���
	cout << mexWeight;

	return 0;
}
