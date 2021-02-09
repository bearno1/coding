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
int t;
LL a,b,c,d,e,f,t1,t2,ans;
int main()
{
    scanf("%lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&e,&f);
    t2=min(b,c);
    t1=min(a,d);
    for(LL i=0;i<=t1;i++)
    {
        ans=max(ans,(i*e)+((min(t2,d-i))*f));
    }
    printf("%lld",ans);
}
