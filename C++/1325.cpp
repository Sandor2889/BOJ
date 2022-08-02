#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

#define MAX 10001

using namespace std;

int n, m;
int cnt;

vector<int> v[MAX];
bool visited[MAX];
vector<int> vCnt;

void dfs(int _x)
{
	visited[_x] = true;

	for (int i = 0; i < v[_x].size(); i++)
	{
		int next = v[_x][i];
		if (!visited[next])
		{
			cnt++;
			dfs(next);
		}
	}
}


int main()
{
	// 입력 컴퓨터, 간선의 수
	cin >> n >> m;

	// 단방향 간선 연결
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}

	// dfs 실행
	int maxCnt = 0;
	for (int i = 1; i <= n; i++)
	{
		memset(visited, false, sizeof(visited));
		cnt = 0;
		dfs(i);

		if (maxCnt == cnt) { vCnt.push_back(i); }
		else if (maxCnt < cnt)
		{
			maxCnt = cnt;
			vCnt.clear();
			vCnt.push_back(i);
		}
	}

	// 오름차순 정렬
	sort(vCnt.begin(), vCnt.end());

	// 출력
	for (int i = 0; i < vCnt.size(); i++)
	{
		cout << vCnt[i] << '\n';
	}

	return 0;
}
