#include <iostream>
#include <set>

using namespace std;

set<string> setStr;

int main()
{
	// ���ڿ� �Է�
	string s;
	cin >> s;

	// �κ� ���ڿ� ����
	for(int i = 0; i < s.length(); i++)
	{
		string temp = "";
		for (int j = i; j < s.length(); j++)
		{
			temp += s[j];
			setStr.insert(temp);
		}
	}

	// ���
	cout << setStr.size();

	return 0;
}