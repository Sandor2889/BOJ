#include <iostream>
#include <set>

using namespace std;

set<int> sA;

int main()
{
	int a, b, num;
	cin >> a >> b;
	int count = a + b;

	// A ���� �Է�
	for (int idx = 0; idx < a; idx++)
	{
		cin >> num;
		sA.insert(num);
	}

	// B ���� �Է� �� ���ÿ� ����� ���� ã��
	for (int idx = 0; idx < b; idx++)
	{
		cin >> num;
		
		if (sA.find(num) != sA.end())
		{
			count -= 2;
		}
	}

	// ���
	cout << count;

	return 0;
}