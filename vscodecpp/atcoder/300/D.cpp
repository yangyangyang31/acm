#include <bits/stdc++.h>

using namespace std;
#define int long long
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

const int N = 1000001;
int n, ans, cnt;
int primes[N];
bool prime[N];

signed main(void)
{
    IOS;
    cin >> n;
    for (int i = 2; i <= 1000000; i++)
    {
        if (!prime[i])
            primes[++cnt] = i;
        for (int j = 1; j <= cnt && i * primes[j] <= 1000000; j++)
        {
            prime[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
    for (int i = 1; i <= cnt - 2; i++)
    {
        if (primes[i] > 251)
            break;
        for (int j = i + 1; j <= cnt - 1; j++)
        {
            if (primes[i] * primes[j] * primes[j] * primes[j] > n)
                break;
            for (int k = j + 1; k <= cnt; k++)
            {
                if (primes[i] * primes[i] * primes[j] * primes[k] * primes[k] <= n)
                {
                    ++ans;
                }
                else
                    break;
            }
        }
    }
    cout << ans;
    return 0;
}