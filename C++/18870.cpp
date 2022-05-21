#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vCoord;

int main()
{
	// 좌표 수 입력
	int nums;
	cin >> nums;

	for (int idx = 0; idx < nums; idx++)
	{
		int coord;
		cin >> coord;
		vCoord.push_back(coord);
	}

	vector<int> vRank(vCoord);

	// 오름차순 정렬
	sort(vRank.begin(), vRank.end());

	// 중복값 제거
	vRank.erase(unique(vRank.begin(), vRank.end()), vRank.end());

	// 출력
	for (int idx = 0; idx < nums; idx++)
	{
		int rank = lower_bound(vRank.begin(), vRank.end(), vCoord[idx]) - vRank.begin();
		cout << rank << ' ';
	}

	return 0;
}