#include <bits/stdc++.h>
using namespace std;

const int N = 1100;
int n, m;

struct node
{
    int p, c;
    vector<int> v;
} arr[N];

bool is_2(node i, node j)
{
    int b[110];
    memset(b, 0, sizeof b);
    for (auto item : i.v)
        b[item] = 1;
    for (auto item : j.v)
        b[item] = 0;
    for (int i = 1; i <= m; i++)
    {
        if (b[i] == 1)
            return false;
    }
    return true;
}

bool is_3(node i, node j)
{
    if (i.p > j.p)
        return true;
    int b[110];
    memset(b, 0, sizeof b);

    for (auto item : j.v)
        b[item] = 1;
    for (auto item : i.v)
        b[item] = 0;
    for (int i = 1; i <= m; i++)
    {
        if (b[i] == 1)
            return true;
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].p >> arr[i].c;
        for (int j = 1; j <= arr[i].c; j++)
        {
            int x;
            cin >> x;
            arr[i].v.push_back(x);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (arr[i].p >= arr[j].p && is_2(arr[i], arr[j]) && is_3(arr[i], arr[j]))
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}