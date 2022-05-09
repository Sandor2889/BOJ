#include <iostream>

using namespace std;

int main()
{
	int answer = 0;
	int numCount;
	cin >> numCount;

	string nums;
	cin >> nums;

	for (int idx = 0; idx < numCount; idx++)
	{
		answer += (int)nums[idx] - '0';
	}

	cout << answer;

	return 0;
}