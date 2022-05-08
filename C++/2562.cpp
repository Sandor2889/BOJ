#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int max = 0;
    int index = 0;
    vector<int> nums;

    for (int idx = 0; idx < 9; idx++)
    {
        int input;
        cin >> input;
        nums.push_back(input);
    }

    for (int vIdx = 0; vIdx < nums.size(); vIdx++)
    {
        if (max < nums[vIdx])
        {
            max = nums[vIdx];
            index = vIdx + 1;
        }
    }

    cout << max << " " << index;
    return 0;
}