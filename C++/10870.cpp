#include <iostream>

using namespace std;

int solution(int _target)
{
	if (_target == 0) { return 0; }
	if (_target == 1) { return 1; }

	return solution(_target - 1) + solution(_target - 2);
}

int main()
{
	int target;
	cin >> target;

	cout << solution(target);
	return 0;
}