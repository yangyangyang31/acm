#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10;
int arr[N];
vector<pii> v;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= 3 * n; i++)
    {
        int x;
        cin >> x;
        if (arr[x] == 1)
        {
            v.push_back({i, x});
            arr[x] = 2;
        }
        if (arr[x] == 0)
            arr[x] = 1;
    }
    sort(v.begin(), v.end());
    for (auto item : v)
        cout << item.second << " ";
    return 0;
}