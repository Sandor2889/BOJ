#include <iostream>

using namespace std;

int main()
{
	int answer = 0;
	int alphabetNum[] = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7,
						8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };
	string word;
	cin >> word;

	for (int idx = 0; idx < word.length(); idx++)
	{
		answer += alphabetNum[word[idx] - 'A'];
	}

	cout << answer;
}