#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> vWords;

bool compare(string _a, string _b)
{
	// ���̰� ������ ���������� ����
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
	// ���� �� �Է�
	int words;
	string current = "*";
	cin >> words;

	for (int idx = 0; idx < words; idx++)
	{
		string word;
		cin >> word;
		vWords.push_back(word);
	}

	// �������� ����
	sort(vWords.begin(), vWords.end(), compare);

	// ���
	for (int idx = 0; idx < vWords.size(); idx++)
	{
		// �ߺ� �ܾ� ����
		if (current != vWords[idx])
		{
			cout << vWords[idx] << '\n';
			current = vWords[idx];
		}
	}

	return 0;
}