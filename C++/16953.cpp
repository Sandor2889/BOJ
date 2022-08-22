#include <iostream>
#include <queue>

using namespace std;

long long a, b;

queue<pair<long long, int>> q;

int bfs(long long _start, long long _cnt)
{
	q.push({ _start, _cnt });

	while (!q.empty())
	{
		long long current = q.front().first;
		long long cnt = q.front().second;
		q.pop();
		
		if (current == b)
		{
			return cnt;
		}
		if (current * 2 <= b)
		{
			q.push({ current * 2, cnt + 1 });	
		}
		if (current * 10 + 1 <= b)
		{
			q.push({ current * 10 + 1, cnt + 1});
		}  
	}

	return -1;
}

int main()
{
	cin >> a >> b;

	cout << bfs(a, 1);

	return 0;
}