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
	// 입력 : 컴퓨터, 간선의 수
	cin >> n;

	// 각 노드의 부모
	for (int i = 0; i < n; i++)
	{
		int parent;
		cin >> parent;

		if (parent == -1) { root = i; continue; }
		// 부모에서 자식으로 단반향 연결
		v[parent].push_back(i);
	}

	// 지울 노드의 번호
	cin >> del_node;

	// 리프의 수 찾기
	dfs(root);

	// 출력
	cout << cnt;

	return 0;
}
