#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int input, target;
    cin >> input >> target;
    vector<int> nums(input);

    for (int idx = 0; idx < input; idx++)
    {
        cin >> nums[idx];
    }

    for (int idx = 0; idx < input; idx++)
    {
        if (nums[idx] < target)
        {
            cout << nums[idx] << " ";
        }
    }

    return 0;
}