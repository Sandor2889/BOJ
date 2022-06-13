#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];

int main()
{
	// ��� �� �Է�
	int n;
	cin >> n;

	// ���� �ð� �Է�
	for (int idx = 0; idx < n; idx++)
	{
		cin >> arr[idx];
	}

	// ���� �ð� �������� ����
	sort(arr, arr + n);

	// ���� �ð��� �ּ���
	int sum = 0;
	for (int idx = 0; idx < n; idx++)
	{
		sum += (n - idx) * arr[idx];
	}

	// �ּ��� ���
	cout << sum;

	return 0;
}