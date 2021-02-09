#include<bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC target ("sse4")
using namespace std;
#define PB push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define imx INT_MAX
#define inI(x) scanf("%d",&x)
#define inI2(x,y) scanf("%d %d",&x,&y)
#define inI3(x,y,z) scanf("%d %d %d",&x,&y,&z)
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
int h,n,a,b;
LL dp[20005],ans=imx;
int main()
{
    for(int i=0;i<20005;i++)dp[i]=imx;
    dp[0]=0;
    scanf("%d %d",&h,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        for(int j=0;j<20005;j++)
        {
            if(j+a<20005)
            {
                if(dp[j+a]>dp[j]+b)
                {
                    dp[j+a]=dp[j]+b;
                    if(j+a>=h)ans=min(ans,dp[j+a]);
                }
            }
        }
    }
    printf("%d",ans);
}
