#include <iostream>

using namespace std;

int arr[10001] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// �Է�
	int input;
	cin >> input;

	// �� ���ڵ��� counting
	for (int idx = 0; idx < input; idx++)
	{
		int num;
		cin >> num;
		arr[num]++;
	}


	// ���
	for (int idx = 0; idx < 10001; idx++)
	{
		if (arr[idx] == 0) { continue; }
		else // �ش� idx�� 0�� �ɶ����� �ݺ� ���
		{
			cout << idx << '\n';
			arr[idx]--;
			idx--;
		}
	}

	return 0;
}