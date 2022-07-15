#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;

int arr[MAX];
bool visited[MAX];
vector<int> v[MAX];

int n;

void dfs(int _root)
{
	visited[_root] = true;
	for (int i = 0; i < v[_root].size(); i++)
	{
		int next = v[_root][i];
		if (!visited[next])
		{
			arr[next] = _root;
			dfs(next);
		}
	}
}

int main()
{
	// Ʈ�� ����� �� �Է�
	cin >> n;

	// Ʈ�� ��� ����
	for (int i = 0; i < n; i++)
	{
		int num1, num2;
		cin >> num1 >> num2;
		
		v[num1].push_back(num2);
		v[num2].push_back(num1);
	}

	// dfs ����
	dfs(1);

	// ���
	for (int i = 2; i < n; i++)
	{
		cout << arr[i] << '\n';
	}

	return 0;
}
