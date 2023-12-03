#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// priority_queue 优先队列
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

int f[300005];

void solve()
{
    std::string s;
    std::cin >> s;
    std::memset(f, -1, sizeof(f));
    int d1 = 0, d0 = 0;
    for (int i = 0; i <= s.size() - 1; i++)
    {
        if (s[i] == '1')
            f[i] = 1, d1++;
        else if (s[i] == '0')
            f[i] = 0, d0++;
        else
            f[i] = 2;
    }
    if (d1 == 0)
    {
        for (int i = 0; i < s.size(); i++)
            std::cout << 0;
        std::cout << std::endl;
        return;
    }
    else if (d0 == 0)
    {
        for (int i = 0; i <= s.size() - 1; i++)
            std::cout << 1;
        std::cout << std::endl;
        return;
    }

    /*for (int i = 0; i <= s.size() - 1; i++)
        std::cout << f[i];
    std::cout << std::endl;*/
    for (int i = 0; i <= s.size() - 1; i++)
    {
        if (f[i] == 0)
        {
            int l = i, r = i;
            while (f[l] != 1)
            {
                f[l] = 0;
                l--;
                if (l < 0)
                    break;
            }
            while (f[r] != 1)
            {
                f[r] = 0;
                r++;
                if (r > s.size() - 1)
                    break;
            }
            i = r - 1;
        }
        else if (f[i] == 1)
        {
            int l = i, r = i;
            while (f[l] != 0)
            {
                f[l] = 1;
                l--;
                if (l < 0)
                    break;
            }
            while (f[r] != 0)
            {
                f[r] = 1;
                r++;
                if (r > s.size() - 1)
                    break;
            }
            i = r - 1;
        }
    }
    for (int i = 0; i <= s.size() - 1; i++)
        std::cout << f[i];
    std::cout << std::endl;
    return;
}

int main()
{
    IOS;
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}
