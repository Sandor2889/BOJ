#include <iostream>

using namespace std;


// �ð��ʰ��� ���� �ݺ������� count++ �ϴ� ����� ������� ���Ѵ�.
// ����� �����ϱ� ���� �ð��� ���� �� �ִ� ����� �����ؾ��Ѵ�.
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