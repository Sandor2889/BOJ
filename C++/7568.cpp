#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// 사람 수 입력
	int people;
	cin >> people;

	vector<pair<int, int>> vData(people);	// 입력값

	// 입력 값 vector에 저장
	for (int idx = 0; idx < people; idx++)
	{
		cin >> vData[idx].first >> vData[idx].second;
	}

	// 탐색
	for (int i = 0; i < vData.size(); i++)
	{
		int rank = 1;
		for (int j = 0; j < vData.size(); j++)
		{
			// 몸무게와 키 비교
			if (vData[i].first < vData[j].first && vData[i].second < vData[j].second)
			{
				rank++;
			}
		}

		cout << rank << ' ';
	}


	return 0;
}