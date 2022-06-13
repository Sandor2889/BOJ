#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];

int main()
{
	// 사람 수 입력
	int n;
	cin >> n;

	// 인출 시간 입력
	for (int idx = 0; idx < n; idx++)
	{
		cin >> arr[idx];
	}

	// 인출 시간 오름차순 정렬
	sort(arr, arr + n);

	// 인출 시간의 최소합
	int sum = 0;
	for (int idx = 0; idx < n; idx++)
	{
		sum += (n - idx) * arr[idx];
	}

	// 최소합 출력
	cout << sum;

	return 0;
}