#include <iostream>
#include <vector>
#include <memory.h>

#define MAX 101

using namespace std;

int n;

int arr[MAX];
int visited[MAX];
vector<int> res;

void dfs(int _head, int _num)
{
	int num = arr[_num];

	if (!visited[num])
	{
		visited[_num] = true;
		dfs(_head, num);
	}
	else
	{
		if (_head == num)
		{
			res.push_back(_head);
		}
	}
}


int main()
{
	// �Է� : ������ ���� n, ������ ����
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	// dfs ����
	for (int i = 1; i <= n; i++)
	{
		dfs(i, i);
		memset(visited, false, sizeof(visited));
	}

	// ��� : ������ ��, ��������
	cout << res.size() << '\n';
	for (int i : res)
	{
		cout << i << '\n';
	}

	return 0;
}
