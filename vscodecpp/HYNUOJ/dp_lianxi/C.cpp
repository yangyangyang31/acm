#include <iostream>
#include <vector>
using namespace std;

int get(vector<int> v, int l, int r)
{
    int sum = 0;
    for (int i = l; i >= r; i--)
        sum = sum * 10 + v[i];
    return sum;
}

int power10(int x)
{
    int sum = 1;
    while (x--)
        sum *= 10;
    return sum;
}

int count(int a, int x)
{
    if (a == 0)
        return 0;
    vector<int> v;
    while (a)
    {
        v.push_back(a % 10);
        a /= 10;
    }

    int n = v.size() - 1;

    int res = 0;
    for (int i = n; i >= 0; i--)
    {
        if (i < n)
        {
            res += get(v, n, i + 1) * power10(i);
            if (!x)
                res -= power10(i);
        }
        if (v[i] == x)
            res += get(v, i - 1, 0) + 1;
        else if (v[i] > x)
            res += power10(i);
    }
    return res;
}

int main()
{
    int a, b;
    while (cin >> a >> b, a || b)
    {
        for (int i = 0; i <= 9; i++)
        {
            cout << count(b, i) - count(a - 1, i) << " ";
        }
        cout << endl;
    }
    return 0;
}