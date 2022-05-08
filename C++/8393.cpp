#include <iostream>

using namespace std;

int main()
{
    int input;
    int answer = 0;
    cin >> input;

    for (int idx = 0; idx < input; idx++)
    {
        answer += idx + 1;
    }
    cout << answer;
    return 0;
}