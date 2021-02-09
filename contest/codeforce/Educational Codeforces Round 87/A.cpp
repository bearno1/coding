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
LL t,a,b,c,d,k;
int main()
{
    scanf("%lld",&t);
    for(int tt=1;tt<=t;tt++)
    {
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        k=c-d;
        if(a<=b)
        {
            printf("%lld\n",b);
        }
        else
        {
            a-=b;
            if(k<=0)printf("-1\n");
            else printf("%lld\n",b+(c*((a+k-1)/(k))));
        }
    }
}
