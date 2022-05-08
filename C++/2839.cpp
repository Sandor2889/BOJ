#include<iostream>

using namespace std;

int main()
{
    int input;
    int result = 0;

    cin >> input;

    while (input > 0)
    {
        if (input % 5 == 0)
        {
            input -= 5;
            result++;
        }
        else if (input % 3 == 0)
        {
            input -= 3;
            result++;
        }
        else if (input > 5)
        {
            input -= 5;
            result++;
        }
        else
        {
            result = -1;
            break;
        }
    }
    cout << result;
    return 0;
}