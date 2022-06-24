#include <iostream>
#include <vector>

using namespace std;

vector<int> v[101]; // 네트워크
int visited[101]; // 방문 처리
int cnt = 0; // 숙주를 제외한 감염된 컴퓨터 수

void dfs(int _start)
{
	if (visited[_start]) { return; }

	// 방문 처리
	visited[_start] = true;

	// 1을 제외한 방문하면 카운팅
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
	// 컴퓨터의 수
	int coms;
	cin >> coms;
	
	// 연결되어있는 컴퓨터 쌍의 수
	int line;
	cin >> line;

	// 네트워크 연결
	for (int i = 0; i < line; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	// DFS 실행
	dfs(1);

	// 출력
	cout << cnt;

	return 0;
}