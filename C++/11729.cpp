#include <iostream>
#include <cmath>

using namespace std;

// �ٽ� ����...
void hanoi(int _n, int _start, int _mid, int _end)
{
	if (_n == 1)
	{
		cout << _start << " " << _end << '\n';
	}
	else
	{
		hanoi(_n - 1, _start, _end, _mid);		//1. 1������� n-1�� -> 2�� �������
		cout << _start << " " << _end << '\n';	//2. 1����� -> 3������
		hanoi(_n - 1, _mid, _start, _end);		//3. 2����� -> 3���������
	}
}
int main()
{
	int n;
	cin >> n;
	cout << (1 << n) - 1 << '\n';		//2^n-1...pow()�� �����ϸ� ����ó����. ��? pow()�� �Ǽ������� ���Ǳ� ����..

	hanoi(n, 1, 2, 3);

	return 0;
}