#include <iostream>

using namespace std;

int main()
{
	// ������ ���
	int cost;
	cin >> cost;

	int change = 1000 - cost; // �޾ƾ� �� �Ž�����
	int result = 0;	// ���� ����

	// ���� �� ���ϱ�
	result += change / 500;
	change = change % 500;
	result += change / 100;
	change = change % 100;
	result += change / 50;
	change = change % 50;
	result += change / 10;
	change = change % 10;
	result += change / 5;
	change = change % 5;
	result += change / 1;
	change = change % 1;

	// ���
	cout << result;

	return 0;
}