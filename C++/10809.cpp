#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int alphabet[26] = {};

	string input;
	cin >> input;

	for (int idx = 0; idx < 26; idx++)
	{
		alphabet[idx] = -1;
	}

	for (int idx = 0; idx < input.length(); idx++)
	{
		if (alphabet[(int)input[idx] - 'a'] == -1)
		{
			alphabet[(int)input[idx] - 'a'] = idx;
		}
	}

	for (int idx : alphabet)
	{
		cout << idx << " ";
	}

	return 0;
}