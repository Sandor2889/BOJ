#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int cases;
    int count;
    cin >> cases;
    vector<pair<string, int>> ox(cases);

    for (int idx = 0; idx < cases; idx++)
    {
        cin >> ox[idx].first;
        ox[idx].second = 0;
    }

    for (pair<string, int>& a : ox)
    {
        count = 0;

        for (char ch : a.first)
        {
            if (ch == 'O')
            {
                count += 1;
                a.second += count;
            }
            else
            {
                count = 0;
            }
        }
    }

    for (pair<string, int> a : ox)
    {
        cout << a.second << "\n";
    }
    return 0;
}