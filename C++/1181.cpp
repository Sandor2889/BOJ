#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> vWords;

bool compare(string _a, string _b)
{
	// 길이가 같으면 사전순으로 정렬
	if (_a.length() == _b.length())
	{
		return _a < _b;
	}
	else
	{
		return _a.length() < _b.length();
	}
}

int main()
{
	// 점의 수 입력
	int words;
	string current = "*";
	cin >> words;

	for (int idx = 0; idx < words; idx++)
	{
		string word;
		cin >> word;
		vWords.push_back(word);
	}

	// 내림차순 정렬
	sort(vWords.begin(), vWords.end(), compare);

	// 출력
	for (int idx = 0; idx < vWords.size(); idx++)
	{
		// 중복 단어 제거
		if (current != vWords[idx])
		{
			cout << vWords[idx] << '\n';
			current = vWords[idx];
		}
	}

	return 0;
}