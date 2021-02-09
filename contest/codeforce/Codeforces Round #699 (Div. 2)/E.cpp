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
int n,co[200005],col[200005][3],dp[200005],k;
vector<pii>v[200005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&co[i]);
        col[co[i]][0]++;
        if(col[co[i]][0]==1)
        {
            k++;
            col[co[i]][1]=i;
        }
        col[co[i]][2]=max(col[co[i]][2],i);
    }
    for(int i=1;i<=n;i++)
    {
        if(col[i][0]==0)continue;
        v[col[i][2]].pb({col[i][1]-1,1});
    }
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1];
        for(int j=0;j<v[i].size();j++)
        {
            dp[i]=max(dp[i],dp[v[i][j].F]+v[i][j].S);
        }
    }
    printf("%d",k-dp[n]);
}
