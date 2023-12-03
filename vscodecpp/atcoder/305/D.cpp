#include <iostream>
#include <vector>
using namespace std;
int N, A[2 << 17];
vector<pair<int, int>> S;
int sum[2 << 17];
int f(int x)
{
    int id = lower_bound(S.begin(), S.end(), make_pair(x, 0)) - S.begin();
    int ans = sum[id];
    if (id > 0)
    {
        id--;
        pair<int, int> lr = S[id];
        if (lr.second > x)
            ans -= lr.second - x;
    }
    return ans;
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 1; i < N; i += 2)
    {
        S.push_back(make_pair(A[i], A[i + 1]));
        sum[S.size()] = sum[S.size() - 1] + A[i + 1] - A[i];
    }
    int Q;
    cin >> Q;
    for (; Q--;)
    {
        int l, r;
        cin >> l >> r;
        cout << f(r) - f(l) << "\n";
    }
}
