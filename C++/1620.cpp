#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> poketStr;
string poketNum[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    string input;
    cin >> n >> m;

    // ���ϸ� �Է�
    for (int idx = 0; idx < n; idx++)
    {
        cin >> input;

        poketStr.insert({ input, idx + 1 });
        poketNum[idx] = input;
    }

    for (int idx = 0; idx < m; idx++)
    {
        cin >> input;

        // �Է� Ÿ���� string�� int �϶� �����Ͽ� ���
        if ((input[0] >= 'A' && input[0] <= 'Z') || (input[0] >= 'a' && input[0] <= 'z'))
        {
            cout << poketStr[input] << '\n';
        }
        else
        {
            cout << poketNum[stoi(input) - 1] << '\n';
        }
    }

    return 0;
}