#include <iostream>
#include <string>

using namespace std;


int main()
{
    int count[10] = {};
    int numA, numB, numC;
    int sum;

    cin >> numA >> numB >> numC;
    sum = numA * numB * numC;

    string strSum = to_string(sum);

    for (char ch : strSum)
    {
        count[ch - '0']++;
    }

    for (int idx : count)
    {
        cout << idx << "\n";
    }

    return 0;
}