#include <iostream>
#include <vector>

#define MAX 101

using namespace std;

int n, m;
int parent, child;
int flag;
int weight;

bool visited[MAX];
vector<int> v[MAX];

void dfs(int _start, int _end, int _weight)
{
	if (_start == _end)
	{ 
		weight = _weight;
		return; 
	}

	visited[_start] = true;

	for (int i = 0; i < v[_start].size(); i++)
	{
		int next = v[_start][i];
		if (!visited[next])
		{
			_weight++;
			dfs(next, _end, _weight);
			_weight--;
		}
	}
}

int main()
{
	// 사람수, 서로 다른 두 사람의 번호, 관계의 수 입력
	cin >> n;
	cin >> parent >> child;
	cin >> m;

	// 연결
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	// dfs 실행
	dfs(parent, child, 0);
	
	// 출력
	if (weight == 0) { cout << -1; }
	else { cout << weight; }

	return 0;
}
