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
#define inI(x) scanf("%d",&x)
#define inI2(x,y) scanf("%d %d",&x,&y)
#define inI3(x,y,z) scanf("%d %d %d",&x,&y,&z)
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
priority_queue<pair<LL,LL> >pq;
LL n,m,ans=imx,val[100005][2],boss[100005],a;
bitset<100005>ss;
int F(int x)
{
    if(x==boss[x])return x;
    else return boss[x]=F(boss[x]);
}
void un(int x,int y)
{
    val[F(x)][0]+=val[F(y)][0];
    val[F(x)][1]=max(val[F(x)][1],val[F(y)][1]);
    boss[F(y)]=F(x);
    return;
}
int main()
{
    freopen("hayfeast.in","r",stdin);
    freopen("hayfeast.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        boss[i]=i;
        scanf("%lld %lld",&val[i][0],&val[i][1]);
        pq.push({-val[i][1],i});
        if(val[i][0]>=m)ans=min(ans,val[i][1]);
    }
    while(!pq.empty())
    {
        a=pq.top().S;
        ss[a]=true;
        pq.pop();
        if(ss[a-1])
        {
            un(a,a-1);
        }
        if(ss[a+1])
        {
            un(a,a+1);
        }
        if(val[F(a)][0]>=m)ans=min(ans,val[F(a)][1]);
    }
    printf("%lld",ans);
}
