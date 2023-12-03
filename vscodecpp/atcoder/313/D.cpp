#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 1010;
int arr[N];
int q[N], ans[N];
vector<int> a, b;

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i < n; i++)
    {
        cout << '?';
        for (int j = 0; j < k; j++)
        {
            if (i + j <= n)
                cout << i + j << " ";
            else
                cout << i + j - n << " ";
        }
        cout << endl;
        int x;
        cin >> x;
        q[i] = x;
    }
    for (int i = 1; i < n - 1; i++)
    {
        int x = i, y = i + k > n ? i + k - n : i + k;
        if (q[i] == q[i + 1])
        {
            if (i == 1)
            {
                a.push_back(x);
                a.push_back(y);
            }
            else if (binary_search(a.begin(), a.end(), x) || binary_search(a.begin(), a.end(), y))
            {
                a.push_back(x);
                a.push_back(y);
            }
            else
            {
                b.push_back(x);
                b.push_back(y);
            }
        }
        else
        {
            if (i == 1)
            {
                a.push_back(x);
                a.push_back(y);
            }
            else if (binary_search(a.begin(), a.end(), x) || binary_search(a.begin(), a.end(), y))
            {
                a.push_back(i);
                b.push_back(y);
            }
            else
            {
                b.push_back(i);
                a.push_back(y);
            }
        }
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    if (a.size() >= k)
    {
        cout << '?';
        for (auto item : a)
            cout << item << " ";
        cout << endl;
        int x;
        cin >> x;
        if (x == 1)
        {
            for (auto item : a)
                ans[item] = 1;
            for (auto item : b)
                ans[item] = 0;
        }
    }
    else if (b.size() >= k)
    {
        cout << '?' << " ";
        for (auto item : b)
            cout << item << " ";
        cout << endl;
        char x;
        cin >> x;
        if (x == 1)
        {
            for (auto item : b)
                ans[item] = 1;
            for (auto item : a)
                ans[item] = 0;
        }
    }
    cout << '!';
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";

    return 0;
}