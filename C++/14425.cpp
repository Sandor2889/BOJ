#include <iostream>
#include <set>

using namespace std;

set<string> s;

int main()
{
    int n, m;
    int count = 0;
    string input;

    // 입력 수
    cin >> n >> m;

    // 집합에 포함되는 문자열 입력
    for (int idx = 0; idx < n; idx++)
    {
        cin >> input;
        s.insert(input);
    }

    // 검사해야하는 문자열
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