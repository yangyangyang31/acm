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

const int N = 2e5 + 10;
struct node
{
    int a, b;
} arr[N];

signed main(void)
{
    IOS;
    int n, k;
    vector<int> v, v1;
    cin >> n >> k;
    int f;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].a;
        if (i == 1)
        {
            f = arr[i].a;
            v1.push_back(1);
        }
        if (arr[i].a == f)
            v1.push_back(i);
        if (arr[i].a == k)
            v.push_back(i);
    }
    for (int i = 1; i <= n; i++)
        cin >> arr[i].b;
    int ans = 0;

    if (v.size() != 0)
    {
        for (auto i : v)
        {
            if (arr[i].b > arr[ans].b)
                ans = i;
        }
    }
    else
    {
        for (auto i : v1)
        {
            if (arr[i].b > arr[ans].b)
                ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}