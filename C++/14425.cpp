#include <iostream>
#include <set>

using namespace std;

set<string> s;

int main()
{
    int n, m;
    int count = 0;
    string input;

    // �Է� ��
    cin >> n >> m;

    // ���տ� ���ԵǴ� ���ڿ� �Է�
    for (int idx = 0; idx < n; idx++)
    {
        cin >> input;
        s.insert(input);
    }

    // �˻��ؾ��ϴ� ���ڿ�
    for (int idx = 0; idx < m; idx++)
    {
        cin >> input;
        if (s.find(input) != s.end())
        {
            count++;
        }
    }
    cout << count;

    return 0;
}