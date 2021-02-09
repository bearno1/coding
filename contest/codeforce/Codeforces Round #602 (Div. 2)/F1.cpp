#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define all(x) (x).begin()s,(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define IMX INT_MAX
const long long MOD = (long long)(998244353);
const long long MMX = (long long)(1e18);
typedef long long LL;
int n,nn[2005];
long long dp[2005][4010],ans,k;
int main()
{
    scanf("%d %lld",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&nn[i]);
    }
    dp[0][1999]=1;
    for(int i=1;i<=n;i++)
    {
        int a=i+1;
        if(a>n)a=1;
        for(int j=1;j<=4005;j++)
        {
            if(nn[a]==nn[i])
            {
                dp[i][j]=dp[i-1][j]*k;
            }
            else
            {
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1]+(dp[i-1][j]*(k-2));
            }
            dp[i][j]%=MOD;
        }
    }
    for(int i=2000;i<=4005;i++)
    {
        ans+=dp[n][i];
        ans%=MOD;
    }
    printf("%lld",ans);
}
