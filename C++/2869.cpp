#include <iostream>

using namespace std;

int main()
{
    int day = 0;
    int morning, night, goal;

    cin >> morning >> night >> goal;

    if ((goal - morning) % (morning - night) == 0)
    {
        day = (goal - morning) / (morning - night);
        cout << day + 1;
    }
    else
    {
        day = (goal - morning) / (morning - night);
        cout << day + 2;
    }

    return 0;
}