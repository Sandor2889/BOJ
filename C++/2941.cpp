#include <iostream>
#include <string>
#include <vector>

using namespace std;

// if������ ���� �� �ڵ�� ������ Ǯ������.
// �ٸ� ����� Ǯ�̸� ������ ���Ҵ�.
int main()
{
	int findIdx = 0;
	vector<string> croatia = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
	string input;
	cin >> input;

	for (int idx = 0; idx < croatia.size(); idx++)
	{
		while (true)
		{
			findIdx = input.find(croatia[idx]);
			if (findIdx == string::npos)
			{
				break;
			}
			input.replace(findIdx, croatia[idx].length(), "*");
		}
	}
	cout << input.length();
}