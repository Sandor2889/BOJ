#include <iostream>

using namespace std;

int main()
{
	int start = 666;
	int count = 0;

	// 입력
	int input;
	cin >> input;


	while (true)
	{
		// 숫자 666부터 1씩 증가하여 탐색
		int temp = start;
		while (temp > 0)
		{
			// 숫자안에 666이 있는지 확인
			if (temp % 1000 == 666)
			{
				count++;
				break;
			}
			temp /= 10;
		}

		// input 숫자를 찾으면 출력
		if (count == input)
		{
			cout << start;
			return 0;
		}

		start++;
	}

	return 0;
}