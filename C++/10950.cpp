#include <iostream>

using namespace std;

int main()
{
    int input;
    int a, b;
    cin >> input;

    for (int idx = 0; idx < input; idx++)
    {
        cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}