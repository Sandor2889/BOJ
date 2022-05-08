#include <iostream>

using namespace std;

int main()
{
    int h, m, cost;
    int a, b;
    cin >> h >> m;
    cin >> cost;

    m += cost;

    a = m / 60;
    b = m % 60;

    h += a;
    m = b;

    if (h >= 24)
    {
        h -= 24;
    }

    cout << h << " " << m;

    return 0;
}