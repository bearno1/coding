#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("sse4")
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define imx INT_MAX
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18+5);
typedef long long LL;
typedef pair<LL,LL> pii;
vector<LL>a,b;
LL t,x,n,Q,ans[10005],ls[20005],mx,aa,bb;
priority_queue<pii>pq;
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        a.clear();
        b.clear();
        for(int i=0;i<20005;i++)ls[i]=0;
        while(!pq.empty())pq.pop();
        scanf("%lld %lld",&n,&Q);
        for(int i=1;i<=n;i++)scanf("%lld",&x),a.pb(x);
        for(int i=1;i<=n;i++)scanf("%lld",&x),b.pb(x);
        a.pb(MMX);
        b.pb(MMX);
        sort(all(a));
        sort(all(b));
        for(int i=0;i<n;i++)
        {
            pq.push({-(a[i]+b[ls[i]]),i});
            //printf("==%lld %lld %d\n",a[i],b[ls[i]],i);
        }
        mx=min((LL)10000,(n*n));
        for(int i=1;i<=mx;i++)
        {
            aa=-pq.top().F;
            bb=pq.top().S;
            pq.pop();
            //printf("==%d %lld %lld\n",i,aa,bb);
            ans[i]=aa;
            ls[bb]++;
            //printf("%lld %d\n",ls[bb],bb);
            pq.push({-(a[bb]+b[ls[bb]]),bb});
        }
        for(int i=1;i<=Q;i++)
        {
            scanf("%lld",&x);
            printf("%lld\n",ans[x]);
        }
    }
}
/*
2
4 0
1 2 3 4
1 3 7 5
4 0
1 9 3 4
1 8 7 5
*/
