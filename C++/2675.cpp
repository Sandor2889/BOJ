#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int cases;
	cin >> cases;

	for (int idx = 0; idx < cases; idx++)
	{
		int repeat;
		string str;

		cin >> repeat >> str;
		vector<char> newStr(repeat * str.length());

		for (int strIdx = 0; strIdx < str.length(); strIdx++)
		{
			for (int newIdx = 0; newIdx < repeat; newIdx++)
			{
				newStr[newIdx] = str[strIdx];
				cout << newStr[newIdx];
			}
		}
		cout << "\n";
	}

	return 0;
}