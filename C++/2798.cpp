#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int answer = 0;

	// 입력
	int cards, target;
	cin >> cards >> target;

	// 뽑은 카드들을 vector에 순서대로 저장
	vector<int> vCards(cards);

	for (int idx = 0; idx < cards; idx++)
	{
		cin >> vCards[idx];
	}

	// 세 장의 카드 뽑기
	for (int i = 0; i < cards - 2; i++)
	{
		for (int j = i + 1; j < cards - 1; j++)
		{
			for (int k = j + 1; k < cards; k++)
			{
				int sum = vCards[i] + vCards[j] + vCards[k];

				// 가장 근접한 세 장의 합 찾기 
				if (sum > answer && sum <= target)
				{
					answer = sum;
				}
			}
		}
	}

	// 출력
	cout << answer;

	return 0;
}