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


    if (count % 2 != 0) // Ȧ��
    {
        cout << count + 1 - input << "/" << input;
    }
    else // ¦��
    {
        cout << input << "/" << count + 1 - input;
    }

    return 0;
}