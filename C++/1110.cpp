#include <iostream>

using namespace std;

int main()
{
    int answer = 0;
    int input, target;
    cin >> input;

    target = input;

    if (input == 0)
    {
        cout << 1;
        return 0;
    }

    while (true)
    {
        int units = target % 10;
        int tens = target / 10;
        int sum = units + tens;
        target = (units * 10) + (sum % 10);
        answer++;

        if (target == input)
        {
            break;
        }
    }

    cout << answer;

    return 0;
}