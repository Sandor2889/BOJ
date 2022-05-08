#include <iostream>

using namespace std;

int main()
{
    int answer = 0;
    int fDice, sDice, thDice;
    cin >> fDice >> sDice >> thDice;

    if (fDice == sDice && sDice == thDice)
    {
        answer += 10000 + (fDice * 1000);
        cout << answer;
    }
    else if (fDice == sDice || fDice == thDice)
    {
        answer += 1000 + (fDice * 100);
        cout << answer;
    }
    else if (sDice == thDice)
    {
        answer += 1000 + (sDice * 100);
        cout << answer;
    }
    else
    {
        if (fDice > sDice && fDice > thDice)
        {
            answer += fDice * 100;
            cout << answer;
        }
        else if (sDice > fDice && sDice > thDice)
        {
            answer += sDice * 100;
            cout << answer;
        }
        if (thDice > fDice && thDice > sDice)
        {
            answer += thDice * 100;
            cout << answer;
        }
    }

    return 0;
}