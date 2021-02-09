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
typedef pair<int,int> pii;
int n,a,b;
LL dp[100005],ans,ls[100005];
vector<int>v[100005];
void dfs(int N,int pr)
{
    LL mx1=0,mx2=0,cc,k;
    ls[N]=1;
    for(int i=0;i<v[N].size();i++)
    {
        if(v[N][i]!=pr)
        {
            dfs(v[N][i],N);
            cc=ls[v[N][i]];
            ls[N]+=cc;
            k=dp[v[N][i]]+(cc*(n-cc));
            if(k>mx1)mx2=mx1,mx1=k;
            else if(k>mx2)mx2=k;
            dp[N]=max(dp[N],k);
        }
    }
    ans=max(ans,max(dp[N],mx1+mx2));
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1,0);
    printf("%lld",ans);
}
