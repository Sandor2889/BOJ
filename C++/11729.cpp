#include <iostream>
#include <cmath>

using namespace std;

// 다시 보기...
void hanoi(int _n, int _start, int _mid, int _end)
{
	if (_n == 1)
	{
		cout << _start << " " << _end << '\n';
	}
	else
	{
		hanoi(_n - 1, _start, _end, _mid);		//1. 1번기둥의 n-1개 -> 2번 기둥으로
		cout << _start << " " << _end << '\n';	//2. 1번기둥 -> 3번으로
		hanoi(_n - 1, _mid, _start, _end);		//3. 2번기둥 -> 3번기둥으로
	}
}
int main()
{
	int n;
	cin >> n;
	cout << (1 << n) - 1 << '\n';		//2^n-1...pow()로 제곱하면 오답처리됨. 왜? pow()는 실수형으로 계산되기 때문..

	hanoi(n, 1, 2, 3);

	return 0;
}