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
vector<pii>x,y;
int X,Y,n,boss[100005],ans,a,b,c;
priority_queue<pair<int,pii> >pq;
int F(int N)
{
    if(N==boss[N])return boss[N];
    else return boss[N]=F(boss[N]);
}
void un(int x,int y)
{
    boss[F(x)]=F(y);
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        boss[i]=i;
        scanf("%d %d",&X,&Y);
        x.pb({X,i});
        y.pb({Y,i});
    }
    sort(all(x));
    sort(all(y));
    for(int i=1;i<n;i++)
    {
        pq.push({-abs(x[i].F-x[i-1].F),{x[i].S,x[i-1].S}});
        pq.push({-abs(y[i].F-y[i-1].F),{y[i].S,y[i-1].S}});
    }
    while(!pq.empty())
    {
        c=-pq.top().F;
        a=pq.top().S.F;
        b=pq.top().S.S;
        pq.pop();
        //printf("{%d %d %d}\n",a,b,c);
        if(F(a)!=F(b))
        {
            //printf("{%d %d %d}\n",a,b,c);
            un(a,b);
            ans+=c;
        }
    }
    printf("%d",ans);
}
