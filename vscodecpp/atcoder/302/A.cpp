#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll a, b;
    cin >> a >> b;
    if (a % b == 0)
        cout << a / b << endl;
    else
        cout << a / b + 1 << endl;
    return 0;
}