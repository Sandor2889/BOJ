#include <iostream>

using namespace std;

int main()
{
    int count = 1;
    int input;
    cin >> input;

    while (input - count > 0)
    {
        input -= count;
        count++;
    }


    if (count % 2 != 0) // È¦¼ö
    {
        cout << count + 1 - input << "/" << input;
    }
    else // Â¦¼ö
    {
        cout << input << "/" << count + 1 - input;
    }

    return 0;
}