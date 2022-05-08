#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int min, max = 0;
    int input;
    cin >> input;
    vector<int> vNums(input);

    for (int idx = 0; idx < input; idx++)
    {
        cin >> vNums[idx];
    }

    min = *min_element(vNums.begin(), vNums.end());
    max = *max_element(vNums.begin(), vNums.end());

    cout << min << " " << max;

    return 0;
}