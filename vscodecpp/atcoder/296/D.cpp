#include <bits/stdc++.h>

using namespace std;
#define int unsigned long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define endl '\n'
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
#define all(x) (x).begin(), (x).end()
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;

int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : x;
}

signed main(void)
{
    IOS;
    int n, m;
    cin >> n >> m;
    if (m <= n)
    {
        cout << m << endl;
        return 0;
    }
    if (n * n < m)
    {
        cout << -1 << endl;
        return 0;
    }
    while (1)
    {
        for (int i = sqrt(m) + 1; i >= 1; i--)
        {
            if (i > n)
                continue;
            if (m / i > n)
                break;
            if (m % i == 0)
            {
                int a = m / i;
                if (a <= n)
                {
                    cout << m << endl;
                    return 0;
                }
                else
                    break;
            }
        }
        m++;
    }
    return 0;
}