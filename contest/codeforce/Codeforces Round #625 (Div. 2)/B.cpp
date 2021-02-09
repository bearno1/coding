#include<bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC target ("sse4")
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define imx INT_MAX
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
vector<int>v[1000005];
int n,x;
LL ans,cc;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        v[x+n-i].pb(x);
    }
    for(int i=1;i<1000005;i++)
    {
        cc=0;
        for(int j=0;j<v[i].size();j++)
        {
            cc+=v[i][j];
        }
        ans=max(ans,cc);
    }
    printf("%lld",ans);
}
