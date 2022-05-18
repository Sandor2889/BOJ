#include <iostream>
#include <vector>

using namespace std;

vector<int> vNums;


// sort() 사용하지말고 구현해보기
int main()
{
	// 입력
	int input;
	cin >> input;

	// 각 숫자들을 vector에 저장
	for (int idx = 0; idx < input; idx++)
	{
		int num;
		cin >> num;
		vNums.push_back(num);
	}

	// i와 j를 비교해가며 서로 자리를 바꿈
	for (int i = 0; i < vNums.size(); i++)
	{
		for (int j = i + 1; j < vNums.size(); j++)
		{
			// 작은 수가 앞으로 가도록
			if (vNums[i] > vNums[j])
			{
				int temp = vNums[i];
				vNums[i] = vNums[j];
				vNums[j] = temp;
			}
		}
	}

	// 출력
	for (int idx : vNums)
	{
		cout << idx << '\n';
	}

	return 0;
}