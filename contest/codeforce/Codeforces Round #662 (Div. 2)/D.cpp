#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("sse4")
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
int n,m,dp[2005][2005][2],k,mi,pl;
LL ans;
char c[2005][2005];
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",c[i]+1);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(c[i][j]==c[i-1][j+1])dp[i][j][0]=dp[i-1][j+1][0]+1;
            else dp[i][j][0]=1;
            if(i==1||j==m)dp[i][j][0]=1;
        }
    }
    for(int i=n;i>0;i--)
    {
        for(int j=1;j<=m;j++)
        {
            if(c[i][j]==c[i+1][j+1])dp[i][j][1]=dp[i+1][j+1][1]+1;
            else dp[i][j][1]=1;
            if(i==n||j==m)dp[i][j][1]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            mi=imx;
            k=min(dp[i][j][0],dp[i][j][1]);
            pl=1;
            //printf("%d %d [%d %d]\n",dp[i][j][0],dp[i][j][1],i,j);
            for(int di=0;di<k;di++)
            {
                if(i+di>n||j+di>m)break;
                if(di==k-1)
                {
                    mi=min(dp[i+di][j+di][1],mi);
                }
                else
                {
                    if(c[i+di][j+di+1]!=c[i+di][j+di])break;
                    mi=min(dp[i+di][j+di+1][1]+1,mi);
                    mi=min(dp[i+di][j+di][1],mi);
                }
                if(mi<=di)break;
                pl=di+1;
            }
            ans+=pl;
        }
    }
    printf("%lld",ans);
}
