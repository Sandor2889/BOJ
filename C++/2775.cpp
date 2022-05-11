#include <iostream>

using namespace std;

// 2차원 배열을 만들어 출력하면 간단하지만
// 만약 시간이 많이 주어지지 않는다면 다른 방법으로 풀어야 했을것이다.
// 그래서 다른 사람의 좋은 풀이를 참고하여 써보았다.

int getPeople(int _floor, int _room)
{
    if (_room == 1) { return 1; }
    if (_floor == 0) { return _room; }

    return (getPeople(_floor - 1, _room) + getPeople(_floor, _room - 1));
}

int main()
{
    int answer = 0;
    int cases;

    cin >> cases;

    for (int idx = 0; idx < cases; idx++)
    {
        int floor, room;
        cin >> floor >> room;

        answer = getPeople(floor, room);
        cout << answer << "\n";
    }

    return 0;
}