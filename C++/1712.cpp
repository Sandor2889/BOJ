#include <iostream>

using namespace std;


// 시간초과로 인해 반복문으로 count++ 하는 방식은 사용하지 못한다.
// 결과값 도달하기 위한 시간을 줄일 수 있는 방법을 생각해야한다.
int main()
{
    int count = 0;
    int laborCost, productionCost, goodsCost;
    cin >> laborCost >> productionCost >> goodsCost;

    if (productionCost >= goodsCost)
    {
        cout << -1;
        return 0;
    }

    cout << (laborCost / (goodsCost - productionCost)) + 1;

    return 0;
}