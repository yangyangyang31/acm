#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 210;
int n, a, b;
int step[N], arr[N];
bool st[N];

void bfs()
{
    queue<int> q;
    q.push(a);
    st[a] = true;

    while (q.size())
    {
        int t = q.front();
        q.pop();
        if (t == b)
        {
            cout << step[t] << endl;
            return;
        }

        int t1 = t + arr[t], t2 = t - arr[t];
        if (t1 <= n && !st[t1])
        {
            st[t1] = true;
            step[t1] = step[t] + 1;
            q.push(t1);
        }
        if (t2 > 0 && !st[t2])
        {
            st[t2] = true;
            step[t2] = step[t] + 1;
            q.push(t2);
        }
    }
    cout << -1 << endl;
}

int main()
{
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    bfs();
    return 0;
}