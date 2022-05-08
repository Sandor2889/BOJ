#include <iostream>
#include <vector>    
#include <algorithm> 

using namespace std;

int main()
{
    int answer = 0;
    int coins, goal;
    cin >> coins >> goal;

    vector<int> coinsValue(coins);

    for (int idx = 0; idx < coinsValue.size(); idx++)
    {
        cin >> coinsValue[idx];
    }

    reverse(coinsValue.begin(), coinsValue.end());

    while (goal != 0)
    {
        for (int idx = 0; idx < coinsValue.size(); idx++)
        {
            if (goal >= coinsValue[idx])
            {
                goal -= coinsValue[idx];
                idx--;
                answer++;
            }
        }
    }
    cout << answer;
    return 0;
}