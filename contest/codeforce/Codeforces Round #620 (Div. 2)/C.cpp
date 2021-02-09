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
int n,m,a,b,t,q;
LL bt,l,r;
bool p;
vector<pair<int,pair<LL,LL> > >v;
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        v.clear();
        p=true;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d %d",&t,&a,&b);
            v.pb({t,{a,b}});
        }
        sort(all(v));
        l=m;
        r=m;
        bt=0;
        for(int i=0;i<n;i++)
        {
            bt=v[i].F-bt;
            l-=bt;
            r+=bt;
            //printf("{%lld %lld %lld %d %lld %lld}\n",l,r,bt,v[i].F,v[i].S.F,v[i].S.S);
            if(l>v[i].S.S||r<v[i].S.F)p=false;
            else l=max(l,v[i].S.F),r=min(r,v[i].S.S);
            //printf("{%lld %lld %lld %d %lld %lld}\n",l,r,bt,v[i].F,v[i].S.F,v[i].S.S);
            bt=v[i].F;
        }
        if(p)printf("YES\n");
        else printf("NO\n");
    }
}
