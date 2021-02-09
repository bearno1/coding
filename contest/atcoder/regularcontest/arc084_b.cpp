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
LL n,ans,k,rr,rrm,rrd;
int main()
{
    ans=MOD;
    scanf("%lld",&n);
    for(int i=1;i<=100000;i++)
    {
        rrd=1,rrm=10,rr=0;
        k=n*i;
        for(int j=0;j<=15;j++)
        {
            rrm*=10;
            rrd*=10;
            rr+=(k%rrm)/rrd;
        }
        if(rr<ans)ans=rr,printf("%lld %d %lld\n",rr,i,k);
    }
    printf("%lld",ans);
}
