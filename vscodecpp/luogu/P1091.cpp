// 合唱队形
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int arr[N];
int l[N], r[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
    {
        l[i] = 1;
        for (int j = 1; j < i; j++)
            if (arr[j] < arr[i])
                l[i] = max(l[i], l[j] + 1);
    }
    for (int i = n; i > 0; i--)
    {
        r[i] = 1;
        for (int j = n; j > i; j--)
            if (arr[j] < arr[i])
                r[i] = max(r[i], r[j] + 1);
    }
    int maxx = 0;
    for (int i = 1; i <= n; i++)
        maxx = max(maxx, l[i] + r[i] - 1);
    cout << n - maxx << endl;
    return 0;
}