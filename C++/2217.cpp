#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];

// �������� ���ķ� ������
bool compare(int _a, int _b)
{
	return _a > _b;
}

int main()
{
	// ������ �� �Է�
	int n;
	cin >> n;

	// ������ ���Ը� �迭�� ����
	int weight;
	pair<int, int> p;
	for (int i = 0; i < n; i++)
	{
		cin >> weight;
		arr[i] = weight;
	}

	// �������� ���� ����
	sort(arr, arr + n, compare);
	
	// �ִ� ���� ���ϱ�
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (max < arr[i] * (i + 1))
		{
			max = arr[i] * (i + 1);
		}
	}

	// ���
	cout << max;

	return 0;
}