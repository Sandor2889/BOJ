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
			// ���� ���ڿ� ���� ���� ��
			if (beforeChar != word[wordIdx])
			{
				alphabet[word[wordIdx] - 'a']++;
			}
			beforeChar = word[wordIdx];
		}

		for (int idx = 0; idx < 26; idx++)
		{
			// �ߺ��ؼ� ���� ����(2�̻�)�� �������
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