#include <iostream>

using namespace std;

int main()
{
	int start = 666;
	int count = 0;

	// �Է�
	int input;
	cin >> input;


	while (true)
	{
		// ���� 666���� 1�� �����Ͽ� Ž��
		int temp = start;
		while (temp > 0)
		{
			// ���ھȿ� 666�� �ִ��� Ȯ��
			if (temp % 1000 == 666)
			{
				count++;
				break;
			}
			temp /= 10;
		}

		// input ���ڸ� ã���� ���
		if (count == input)
		{
			cout << start;
			return 0;
		}

		start++;
	}

	return 0;
}