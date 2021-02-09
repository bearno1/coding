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
int n,m,pos[100005],ord,x,t;
LL ans;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ord=0;
        ans=0;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            pos[x]=i;
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&x);
            if(pos[x]>ord)
            {
                ans+=((pos[x]-i)*2)+1;
            }
            else ans++;
            ord=max(ord,pos[x]);
            //printf("---%lld %d\n",ans,i);
        }
        printf("%lld\n",ans);
    }
}
