#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // n ī�� �Է�
    int n, m, num;
    vector<int> v;
    cin >> n;
    for (int idx = 0; idx < n; idx++)
    {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());


    // m ī�� �Է�
    cin >> m;
    for (int idx = 0; idx < m; idx++)
    {
        cin >> num;
        
        // �̺� Ž��
        cout << binary_search(v.begin(), v.end(), num) << ' ';
    }

    return 0;
}