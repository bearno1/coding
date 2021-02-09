#include<bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC target ("sse4")
using namespace std;
#define PB push_back
#define all(x) (x).begin()s,(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define IMX INT_MAX
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
int t,n,m;
LL ans,k,p;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d %d",&n,&m);
        if(n>=m)printf("%d\n",m);
        else
        {
            p=n/m;
            k=m%n;
            for(int i=1;i<=k;i++)ans+=(p+1)*(p+1);
            for(int i=k+1;i<=m;i++)ans+=p*p;
            printf("%lld\n",ans);
        }
    }
}
