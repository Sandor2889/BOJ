#include <iostream>

using namespace std;

int main()
{
	// �丮�ؾ��� �ð� t
	int t;
	cin >> t;

	// �ּ� ��ư ����
	int a = 0, b = 0, c = 0;

	a += t / 300;
	t = t % 300;
	b += t / 60;
	t = t % 60;
	c += t / 10;
	t = t % 10;

	// ���
	if (t != 0)	// ������ �������� ������ -1
	{
		cout << -1;
	}
	else // ������ �������� �ּ� Ƚ��
	{
		cout << a << ' ' << b << ' ' << c;
	}
	
	return 0;
}