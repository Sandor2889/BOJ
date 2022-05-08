#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int input;
    float answer = 0;
    int maxScore = 0;
    float sum = 0;

    cin >> input;
    vector<float> subjects(input);

    for (int idx = 0; idx < input; idx++)
    {
        cin >> subjects[idx];
    }

    maxScore = *max_element(subjects.begin(), subjects.end());

    for (float& score : subjects)
    {
        score = score / maxScore * 100;
        sum += score;
    }

    answer = sum / subjects.size();
    cout << answer;

    return 0;
}