#include <vector>

long long sum(std::vector<int>& a)
{
    long long ans = 0;

    for (int idx = 0; idx < a.size(); idx++)
    {
        ans += a[idx];
    }

    return ans;
}