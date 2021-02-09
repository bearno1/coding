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
int t,n,dp[2005][2005][2],cc[4005],x;
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        scanf("%d",&n);
        for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j][0]=imx,dp[i][j][1]=imx;
        dp[0][0][0]=0,dp[0][0][1]=0;
        for(int i=1;i<=n*2;i++)scanf("%d",&cc[i]);
        for(int i=1;i<=n*2;i++)
        {
            x=cc[i];
            for(int j=0;j<=n;j++)
            {
                int k=i-j;
                if(k>n)continue;
                if(j==0)
                {
                    if(dp[j][k-1][1]!=imx)
                    {
                        dp[j][k][0]=0;
                        dp[j][k][1]=x;
                    }
                }
                else if(k==0)
                {
                    if(dp[j-1][k][0]!=imx)
                    {
                        dp[j][k][0]=x;
                        dp[j][k][1]=0;
                    }
                }
                else
                {
                    if(dp[j-1][k][1]<x)
                    {
                        dp[j][k][0]=x;
                        dp[j][k][1]=dp[j-1][k][1];
                    }
                    if(dp[j][k-1][1]<x)
                    {
                        dp[j][k][1]=x;
                        dp[j][k][0]=dp[j][k-1][0];
                    }
                }
            }
        }
        if(dp[n][n][0]!=imx)printf("YES\n");
        else printf("NO\n");
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<=n;k++)printf("[%d %d] ",dp[j][k][0],dp[j][k][1]);
            printf("\n");
        }
    }
}
