#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int arr[N];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, a, b, ax = 1, bx = 1;
        bool f = true;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        a = arr[1], b = arr[n];
        if (a != b)
        {
            int i = 2;
            for (; i <= n; i++)
            {
                if (ax == k)
                    break;
                if (arr[i] == a)
                    ax++;
            }
            for (; i < n; i++)
            {
                if (bx == k)
                    break;
                if (arr[i] == b)
                    bx++;
            }
            if (ax == k && bx == k)
            {
                cout << "YES" << endl;
                f = false;
            }
        }
        else
        {
            ax = 2;
            if (ax % k == 0)
                f = false;
            for (int i = 2; i < n; i++)
            {
                if (arr[i] == a)
                    ax++;
                if (ax % k == 0)
                {
                    f = false;
                    break;
                }
            }
            if (!f)
                cout << "YES" << endl;
        }
        if (f)
            cout << "NO" << endl;
    }
    return 0;
}