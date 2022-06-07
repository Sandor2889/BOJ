#include <iostream>

using namespace std;

int cardArr[20000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, input;
    cin >> n;

    for (int idx = 0; idx < n; idx++)
    {
        cin >> input;
        cardArr[input + 10000000]++;
    }

    int m;
    cin >> m;

    for (int idx = 0; idx < m; idx++)
    {
        cin >> input;
        cout << cardArr[input + 10000000] << ' ';
    }

    return 0;
}