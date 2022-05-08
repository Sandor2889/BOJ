#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int input;
    cin >> input;

    for (int idx = input; idx > 0; idx--)
    {
        cout << idx << "\n";
    }

    return 0;
}