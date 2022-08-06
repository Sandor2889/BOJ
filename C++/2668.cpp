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
	// 입력 : 정수의 갯수 n, 각각의 숫자
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	// dfs 실행
	for (int i = 1; i <= n; i++)
	{
		dfs(i, i);
		memset(visited, false, sizeof(visited));
	}

	// 출력 : 정수의 수, 오름차순
	cout << res.size() << '\n';
	for (int i : res)
	{
		cout << i << '\n';
	}

	return 0;
}
