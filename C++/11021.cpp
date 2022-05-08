#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int input, a, b;
    cin >> input;

    for (int idx = 1; idx <= input; idx++)
    {
        cin >> a >> b;
        cout << "Case #" << idx << ": " << a + b << "\n";
    }

    return 0;
}