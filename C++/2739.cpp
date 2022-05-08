#include <iostream>

using namespace std;

int main()
{
    int input;
    cin >> input;

    for (int idx = 0; idx < 9; idx++)
    {
        cout << input << " * " << idx + 1 << " = " << input * (idx + 1) << endl;
    }

    return 0;
}