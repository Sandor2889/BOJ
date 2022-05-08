#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << fixed;
    cout.precision(3);

    int cases;
    cin >> cases;

    vector<float> answer(cases);

    for (int idx = 0; idx < cases; idx++)
    {
        float people;
        float sum = 0, count = 0;
        float avg = 0;

        cin >> people;
        vector<int> scores(people);

        for (int idx = 0; idx < people; idx++)
        {
            cin >> scores[idx];
            sum += scores[idx];
        }

        avg = sum / people;

        for (int idx = 0; idx < people; idx++)
        {
            if (avg < scores[idx])
            {
                count++;
            }
        }

        answer[idx] = count * 100 / people;
    }

    for (float result : answer)
    {
        cout << result << "%" << "\n";
    }

    return 0;
}