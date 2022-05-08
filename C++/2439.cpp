#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int input;
    cin >> input;

    for (int idx = 1; idx <= input; idx++)
    {
        for (int space = 0; space < input - idx; space++)
        {
            cout << " ";
        }
        for (int star = 0; star < idx; star++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}