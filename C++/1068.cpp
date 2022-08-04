#include <iostream>
#include <vector>

#define MAX 51

using namespace std;

int n;
int cnt;
int root;
int del_node;

vector<int> v[MAX];
int dfs(int _x)
{
	if (_x == del_node) { return -1; }

	if (!v[_x].size())
	{
		cnt++;
		return 0;
	}

	for (int i = 0; i < v[_x].size(); i++)
	{
		int next = dfs(v[_x][i]);

		if (next == -1 && v[_x].size() == 1)
		{
			cnt++;
		}
	}
	return 0;
}


int main()
{
	// �Է� : ��ǻ��, ������ ��
	cin >> n;

	// �� ����� �θ�
	for (int i = 0; i < n; i++)
	{
		int parent;
		cin >> parent;

		if (parent == -1) { root = i; continue; }
		// �θ𿡼� �ڽ����� �ܹ��� ����
		v[parent].push_back(i);
	}

	// ���� ����� ��ȣ
	cin >> del_node;

	// ������ �� ã��
	dfs(root);

	// ���
	cout << cnt;

	return 0;
}
