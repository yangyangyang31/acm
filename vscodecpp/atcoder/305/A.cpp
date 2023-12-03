#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int a = n % 5;
    if (a > 2)
        cout << (n / 5 + 1) * 5 << endl;
    else
        cout << (n / 5) * 5 << endl;
    return 0;
}