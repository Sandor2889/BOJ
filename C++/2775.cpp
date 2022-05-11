#include <iostream>

using namespace std;

// 2���� �迭�� ����� ����ϸ� ����������
// ���� �ð��� ���� �־����� �ʴ´ٸ� �ٸ� ������� Ǯ��� �������̴�.
// �׷��� �ٸ� ����� ���� Ǯ�̸� �����Ͽ� �Ẹ�Ҵ�.

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