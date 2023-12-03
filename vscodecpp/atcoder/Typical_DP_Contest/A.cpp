#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
bool st[N] = {true};
int arr[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = N; j >= 0; j--)
        {
            if (st[j])
                st[j + arr[i]] = true;
        }
    }
    int ans = 0;
    for (int i = 0; i <= N; i++)
    {
        if (st[i])
        {
            cout << i << " ";
            ans++;
        }
    }
    cout << endl
         << ans << endl;
    return 0;
}