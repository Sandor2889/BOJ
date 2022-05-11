#include <iostream>

using namespace std;

// 방의 개수
// 1 - 7 - 19 - 37 - 61 = 
//   6   12   18   24  = 6n

int main()
{
    int count = 0;
    int sum = 1;
    int input;
    cin >> input;

    if (input == 1)
    {
        count = 1;
        cout << count;
        return 0;
    }

    while (true)
    {
        sum += 6 * count;

        if (input <= sum)
        {
            count++;
            cout << count;
            break;
        }

        count++;
    }

    return 0;
}
