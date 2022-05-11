#include <iostream>
#include <vector>

using namespace std;

// ���� ���� ������ �ʾƼ� �ٸ� ����� Ǯ�̸� ���� ���� �����Ͽ���...

int num1[10001], num2[10001];
vector<int> answer;

int main()
{
    string input1, input2;

    cin >> input1 >> input2;

    // input1�� �׻� ū���� �ǵ��� �����
    if (input1.size() < input2.size())
    {
        string temp = input1;
        input1 = input2;
        input2 = temp;
    }

    // string�� int�� �迭�� �ű�� (�� ���ڸ�ĭ�� ����)
    for (int idx = 0; idx < input1.size(); idx++)
    {
        num1[idx + 1] = input1[idx] - '0';
    }
    for (int idx = 0; idx < input2.size(); idx++)
    {
        num2[idx + 1 + (input1.size() - input2.size())] = input2[idx] - '0';
    }

    // �迭�� �� �κк��� �����Ͽ� vector�� ����
    for (int idx = input1.size(); idx > 0; idx--)
    {
        int sum = num1[idx] + num2[idx];
        if (sum >= 10)
        {
            num1[idx - 1]++;
            sum -= 10;
        }

        answer.push_back(sum);
    }

    // ���ܽ��״� �� ���ڸ��� ���� ���
    if (num1[0] != 0) { cout << 1; }

    // �տ������� �Ųٷ� ���
    for (int idx = answer.size() - 1; idx >= 0; idx--)
    {
        cout << answer[idx];
    }

    return 0;
}