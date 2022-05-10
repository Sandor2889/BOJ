#include <iostream>

using namespace std;

int main()
{
	int answer = 0;
	int input;
	char beforeChar = '*';

	cin >> input;
	answer = input;

	for (int idx = 0; idx < input; idx++)
	{
		int alphabet[26] = { 0 };

		string word;
		cin >> word;

		for (int wordIdx = 0; wordIdx < word.length(); wordIdx++)
		{
			// 이전 문자와 현재 문자 비교
			if (beforeChar != word[wordIdx])
			{
				alphabet[word[wordIdx] - 'a']++;
			}
			beforeChar = word[wordIdx];
		}

		for (int idx = 0; idx < 26; idx++)
		{
			// 중복해서 나온 문자(2이상)가 있을경우
			if (alphabet[idx] >= 2)
			{
				answer--;
				break;
			}
		}
		beforeChar = '*';
	}
	cout << answer;
}