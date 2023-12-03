#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        ll sum = 0;
        for (int i = 1; i <= 7; i++)
        {
            int x;
            cin >> x;
            sum += x;
        }
        cout << sum << " ";
    }
    return 0;
}