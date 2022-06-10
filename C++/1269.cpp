#include <iostream>
#include <set>

using namespace std;

set<int> sA;

int main()
{
	int a, b, num;
	cin >> a >> b;
	int count = a + b;

	// A 집합 입력
	for (int idx = 0; idx < a; idx++)
	{
		cin >> num;
		sA.insert(num);
	}

	// B 집합 입력 과 동시에 공통된 원소 찾기
	for (int idx = 0; idx < b; idx++)
	{
		cin >> num;
		
		if (sA.find(num) != sA.end())
		{
			count -= 2;
		}
	}

	// 출력
	cout << count;

	return 0;
}