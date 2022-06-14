#include <iostream>

using namespace std;

int main()
{
	// 지불할 비용
	int cost;
	cin >> cost;

	int change = 1000 - cost; // 받아야 할 거스름돈
	int result = 0;	// 최저 갯수

	// 최저 수 구하기
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

	// 출력
	cout << result;

	return 0;
}