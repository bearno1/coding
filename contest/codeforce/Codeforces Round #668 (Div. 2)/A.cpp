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
int t,n,k[100005];
LL ans,rr;
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        rr=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&k[i]);
        }
        for(int i=n;i>0;i--)
        {
            if(k[i]>0)
            {
                rr-=k[i];
                rr=max((LL)0,rr);
            }
            else
            {
                rr-=k[i];
            }
        }
        printf("%lld\n",rr);
    }
}
