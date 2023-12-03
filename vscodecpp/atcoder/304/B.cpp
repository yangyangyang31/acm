#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 1000)
        cout << n << endl;
    else if (n < 10000)
        cout << n - n % 10 << endl;
    else if (n < 100000)
        cout << n - n % 100 << endl;
    else if (n < 1000000)
        cout << n - n % 1000 << endl;
    else if (n < 10000000)
        cout << n - n % 10000 << endl;
    else if (n < 1e8)
        cout << n - n % 100000 << endl;
    else
        cout << n - n % 1000000 << endl;
    return 0;
}