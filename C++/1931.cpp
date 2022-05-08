#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> _a, pair<int, int> _b)
{
    if (_a.second == _b.second) { return _a.first < _b.first; }
    return _a.second < _b.second;
}

int main()
{
    int answer = 0;
    int rooms;
    int start, end;
    int currentTime = 0;
    cin >> rooms;

    vector<pair<int, int>> meetingTime(rooms);

    for (int idx = 0; idx < meetingTime.size(); idx++)
    {
        cin >> meetingTime[idx].first >> meetingTime[idx].second;
    }

    sort(meetingTime.begin(), meetingTime.end(), compare);

    for (int idx = 0; idx < rooms; idx++)
    {
        if (meetingTime[idx].first >= currentTime)
        {
            currentTime = meetingTime[idx].second;
            answer++;
        }
    }
    cout << answer;
    return 0;
}