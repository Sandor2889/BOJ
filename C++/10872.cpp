#include <iostream>

using namespace std;

int answer = 1;

int Prime(int _start)
{
	if (_start == 0) { return answer; }

	answer *= _start;
	return factorial(_start - 1);
}

int main()
{
	int num;
	cin >> num;

	cout << Prime(num);

	return 0;
}