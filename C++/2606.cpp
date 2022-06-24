#include <iostream>
#include <vector>

using namespace std;

vector<int> v[101]; // ��Ʈ��ũ
int visited[101]; // �湮 ó��
int cnt = 0; // ���ָ� ������ ������ ��ǻ�� ��

void dfs(int _start)
{
	if (visited[_start]) { return; }

	// �湮 ó��
	visited[_start] = true;

	// 1�� ������ �湮�ϸ� ī����
	if (_start != 1)
	{
		cnt++;
	}

	for (int i = 0; i < v[_start].size(); i++)
	{
		int next = v[_start][i];
		dfs(next);
	}
}

int main()
{
	// ��ǻ���� ��
	int coms;
	cin >> coms;
	
	// ����Ǿ��ִ� ��ǻ�� ���� ��
	int line;
	cin >> line;

	// ��Ʈ��ũ ����
	for (int i = 0; i < line; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	// DFS ����
	dfs(1);

	// ���
	cout << cnt;

	return 0;
}