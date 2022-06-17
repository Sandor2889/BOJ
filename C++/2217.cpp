#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];

// 내림차순 정렬로 재정의
bool compare(int _a, int _b)
{
	return _a > _b;
}

int main()
{
	// 밧줄의 수 입력
	int n;
	cin >> n;

	// 밧줄의 무게를 배열에 저장
	int weight;
	pair<int, int> p;
	for (int i = 0; i < n; i++)
	{
		cin >> weight;
		arr[i] = weight;
	}

	// 내림차순 정렬 실행
	sort(arr, arr + n, compare);
	
	// 최대 무게 구하기
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (max < arr[i] * (i + 1))
		{
			max = arr[i] * (i + 1);
		}
	}

	// 출력
	cout << max;

	return 0;
}