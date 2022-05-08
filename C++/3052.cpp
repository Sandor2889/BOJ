#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int mark;
    int answer = 0;
    vector<int> vRes(10);
    int search[43] = {};
    for (int idx = 0; idx < vRes.size(); idx++)
    {
        int input;
        cin >> input;
        vRes[idx] = input % 42;
    }


    mark = vRes[0];
    for (int num : vRes)
    {
        search[num]++;
    }

    for (int num : search)
    {
        if (num != 0)
        {
            answer++;
        }
    }

    cout << answer;
    return 0;
}