nclude <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>

#define SIZE 101

using namespace std;

int n;
char current;

int map[SIZE][SIZE];	// ������ ���� ��
bool visited[SIZE][SIZE];	// �湮ó��
vector<int> maxCnt; // �������� �� ����
int maxHeight = 0; // ���� ���� ������ ����

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
	// ũ�� �Է� n x n
	cin >> n;

	// ������ ���� ���� �Է�
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

	// �ִ� ���� ��ŭ �ݺ�
	for (int cnt = 0; cnt <= maxHeight; cnt++)
	{
		// �������� ���� ���� �湮ó�� 
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

		// DFS Ž��
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

		// �ʱ�ȭ
		memset(visited, false, sizeof(visited));
	}
	int answer = *max_element(maxCnt.begin(), maxCnt.end());
	cout << answer;

	return 0;
}
