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
int t,n,m,a[100005],ans,k,dp[100005];
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        ans=imx;
        scanf("%d",&n);
        k=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]!=1)
            {
                ans=min(i,ans);
            }
        }
        if(ans==imx)
        {
            if(n%2==0)printf("Second\n");
            else printf("First\n");
        }
        else
        {
            if(ans%2==0)printf("Second\n");
            else printf("First\n");
        }
    }
}
