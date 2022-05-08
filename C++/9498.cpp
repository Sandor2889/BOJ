#include <iostream>

using namespace std;

int main()
{
    int input;
    cin >> input;

    if (input >= 90 && input <= 100)
    {
        cout << "A";
    }
    else if (input >= 80 && input <= 89)
    {
        cout << "B";
    }
    else if (input >= 70 && input <= 79)
    {
        cout << "C";
    }
    else if (input >= 60 && input <= 69)
    {
        cout << "D";
    }
    else
    {
        cout << "F";
    }
    return 0;
}