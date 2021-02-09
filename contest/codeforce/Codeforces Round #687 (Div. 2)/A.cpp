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
int t;
LL a,b,c,d;
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        LL ans=0;
        ans=max(ans,abs(a-c)+abs(b-d));
        ans=max(ans,abs(1-c)+abs(b-d));
        ans=max(ans,abs(a-c)+abs(1-d));
        ans=max(ans,abs(1-c)+abs(1-d));
        printf("%lld\n",ans);
    }
}
