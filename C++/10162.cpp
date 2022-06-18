#include <iostream>

using namespace std;

int main()
{
	// 요리해야할 시간 t
	int t;
	cin >> t;

	// 최소 버튼 조작
	int a = 0, b = 0, c = 0;

	a += t / 300;
	t = t % 300;
	b += t / 60;
	t = t % 60;
	c += t / 10;
	t = t % 10;

	// 출력
	if (t != 0)	// 나누어 떨어지지 않으면 -1
	{
		cout << -1;
	}
	else // 나누어 떨어지면 최소 횟수
	{
		cout << a << ' ' << b << ' ' << c;
	}
	
	return 0;
}