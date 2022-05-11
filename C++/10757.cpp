#include <iostream>
#include <vector>

using namespace std;

// 전혀 감도 잡히지 않아서 다른 사람의 풀이를 아주 많이 참고하였다...

int num1[10001], num2[10001];
vector<int> answer;

int main()
{
    string input1, input2;

    cin >> input1 >> input2;

    // input1이 항상 큰수가 되도록 만들기
    if (input1.size() < input2.size())
    {
        string temp = input1;
        input1 = input2;
        input2 = temp;
    }

    // string을 int형 배열로 옮기기 (맨 앞자리칸은 비우기)
    for (int idx = 0; idx < input1.size(); idx++)
    {
        num1[idx + 1] = input1[idx] - '0';
    }
    for (int idx = 0; idx < input2.size(); idx++)
    {
        num2[idx + 1 + (input1.size() - input2.size())] = input2[idx] - '0';
    }

    // 배열의 끝 부분부터 덧셈하여 vector에 저장
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

    // 제외시켰던 맨 앞자리수 따로 출력
    if (num1[0] != 0) { cout << 1; }

    // 앞에서부터 거꾸로 출력
    for (int idx = answer.size() - 1; idx >= 0; idx--)
    {
        cout << answer[idx];
    }

    return 0;
}