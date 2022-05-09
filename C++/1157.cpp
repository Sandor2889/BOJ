#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> alphabet(26);
	string input;
	int max = -1;
	int maxIdx = 0;
	int count = 0;
	string answer;
	cin >> input;

	// 모든 소문자를 대문자로 변환
	for (int idx = 0; idx < input.length(); idx++)
	{
		if ((int)input[idx] >= 97)
		{
			input[idx] -= 32;
		}
	}

	// 알파벳 카운팅
	for (int idx = 0; idx < input.length(); idx++)
	{
		alphabet[(int)input[idx] - 'A']++;
	}

	// 최댓값 찾기 및 중복 체크
	for (int idx = 0; idx < alphabet.size(); idx++)
	{
		if (max < alphabet[idx])
		{
			max = alphabet[idx];
			maxIdx = idx;
			answer = maxIdx + 65;
		}
		else if (max == alphabet[idx])
		{
			answer = '?';
		}
	}

	cout << answer;

	return 0;
}