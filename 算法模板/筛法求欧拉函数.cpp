#include <bits/stdc++.h>

using namespace std;
#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;

const int N=1e5+10;
int primes[N],phi[N],cnt;
bool st[N];

int get_eulers(int n)
{
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!st[i])
        {
            primes[cnt++]=i;
            phi[i]=i-1;
        }
        for(int j=0;primes[j]<=n/i;j++)
        {
            st[primes[j]*i]=true;
            if(i%primes[j]==0)  //p[j]已经是i的质因子
            {
                phi[i*primes[j]]=phi[i]*primes[j];
                break;
            }
            phi[i*primes[j]]=phi[i]*(primes[j]-1);//p[j]不是i的质因子
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=phi[i];
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    cout<<get_eulers(n);
    return ;
}

signed main(void)
{
    int t = 1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}
