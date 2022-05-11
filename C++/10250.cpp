#include <iostream>

using namespace std;

int main()
{
    int testDatas;

    cin >> testDatas;

    for (int idx = 0; idx < testDatas; idx++)
    {
        int floor, rooms, customer;
        int roomIdx = 1;

        cin >> floor >> rooms >> customer;

        while (customer - floor > 0)
        {
            customer -= floor;
            roomIdx++;
        }

        if (roomIdx < 10)
        {
            cout << customer << 0 << roomIdx << "\n";
        }
        else
        {
            cout << customer << roomIdx << "\n";
        }
    }

    return 0;
}