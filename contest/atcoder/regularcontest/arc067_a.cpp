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
int n,val[1005],fac[1005];
LL ans;
int main()
{
    ans=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)val[i]=i;
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=n;j++)
        {
            while(val[j]%i==0)
            {
                val[j]=val[j]/i;
                fac[i]++;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        //printf("%d %d\n",fac[i],i);
        ans*=(fac[i]+1);
        ans%=MOD;
    }
    printf("%lld",ans);
}
