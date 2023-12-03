#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;

ll n, c;
ll arr[N];
bool check(ll x)
{
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += (arr[i] + 2 * x) * (arr[i] + 2 * x);
        if (sum > c)
            return 1;
    }
    if (sum == c)
        return 2;
    if (sum < c)
        return 0;
}

ll bsearch(ll l, ll r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        int x = check(mid);
        if (x == 1)
            r = mid;
        else if (x == 0)
            l = mid + 1;
        else if (x == 2)
            return mid;
    }
    return l;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {

        scanf("%lld %lld", &n, &c);
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &arr[i]);
            sum += arr[i] * arr[i];
        }
        ll a = sqrt(c - sum);
        // cout << bsearch(0, a) << endl;
        printf("%lld\n", bsearch(0, a));
    }
    return 0;
}