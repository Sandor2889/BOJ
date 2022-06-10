#include <iostream>
#include <set>

using namespace std;

set<string> setStr;

int main()
{
	// 문자열 입력
	string s;
	cin >> s;

	// 부분 문자열 저장
	for(int i = 0; i < s.length(); i++)
	{
		string temp = "";
		for (int j = i; j < s.length(); j++)
		{
			temp += s[j];
			setStr.insert(temp);
		}
	}

	// 출력
	cout << setStr.size();

	return 0;
}