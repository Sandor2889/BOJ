#include <iostream>
#include <vector>

using namespace std;

vector<int> vNums;


// sort() ����������� �����غ���
int main()
{
	// �Է�
	int input;
	cin >> input;

	// �� ���ڵ��� vector�� ����
	for (int idx = 0; idx < input; idx++)
	{
		int num;
		cin >> num;
		vNums.push_back(num);
	}

	// i�� j�� ���ذ��� ���� �ڸ��� �ٲ�
	for (int i = 0; i < vNums.size(); i++)
	{
		for (int j = i + 1; j < vNums.size(); j++)
		{
			// ���� ���� ������ ������
			if (vNums[i] > vNums[j])
			{
				int temp = vNums[i];
				vNums[i] = vNums[j];
				vNums[j] = temp;
			}
		}
	}

	// ���
	for (int idx : vNums)
	{
		cout << idx << '\n';
	}

	return 0;
}