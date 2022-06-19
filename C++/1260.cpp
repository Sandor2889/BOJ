#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> vec[1001];
int visited[1001];

void dfs(int _x)
{
	if (visited[_x]) { return; }
	visited[_x] = true;
	cout << _x << ' ';
	for (int i = 0; i < vec[_x].size(); i++)
	{
		int y = vec[_x][i];
		dfs(y);
	}
}

void bfs(int _start)
{
	queue<int> q;
	q.push(_start);
	visited[_start] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < vec[x].size(); i++)
		{
			int y = vec[x][i];
			if (!visited[y])
			{
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

// BFS ������ ���� �迭 �ʱ�ȭ
void clearArr()
{
	for (int idx = 0; idx < 1001; idx++)
	{
		visited[idx] = false;
	}
	cout << '\n';
}

// ���� �� ���� Ž���� ���� vector�� ��� ������ ����
void sortAllVec()
{
	for (int idx = 0; idx < 1001; idx++)
	{
		sort(vec[idx].begin(), vec[idx].end());
	}
}

int main()
{
	// ����, ����, ������ �Է�
	int n, m, v;
	cin >> n >> m >> v;
	
	// ���� ����
	int num1, num2;
	for (int idx = 0; idx < m; idx++)
	{
		cin >> num1 >> num2;
		vec[num1].push_back(num2);
		vec[num2].push_back(num1);
	}
	
	// ����
	sortAllVec();
	dfs(v);
	clearArr();
	bfs(v);

	return 0;
}