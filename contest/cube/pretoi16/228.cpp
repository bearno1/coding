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
const long long MMX = (long long)(1e15);
typedef long long LL;
typedef pair<int,int> pii;
int n,m,k,tt,b,c;
LL sh[100005][2],a;
vector<pair<int,int> >v[100005];
priority_queue<pair<LL,pair<int,int> > >pq;
int main()
{
    scanf("%d %d %d %d",&n,&m,&k,&tt);
    for(int i=1;i<=m;i++)
    {
        scanf("%lld %d %d",&a,&b,&c);
        v[a].pb({c,b});
        v[b].pb({c,a});
    }
    for(int i=2;i<100005;i++)sh[i][0]=MMX,sh[i][1]=MMX;
    pq.push({0,{1,0}});
    while(!pq.empty())
    {
        a=-pq.top().F;
        b=pq.top().S.F;
        c=pq.top().S.S;
        pq.pop();
        if(c==0)
        {
            for(int i=0;i<v[b].size();i++)
            {
                if(sh[v[b][i].S][0]>a+v[b][i].F)
                {
                    sh[v[b][i].S][0]=a+v[b][i].F;
                    pq.push({-sh[v[b][i].S][0],{v[b][i].S,0}});
                }
                if(sh[v[b][i].S][1]>a+k)
                {
                    sh[v[b][i].S][1]=a+k;
                    pq.push({-sh[v[b][i].S][1],{v[b][i].S,1}});
                }
            }
        }
        else
        {
            for(int i=0;i<v[b].size();i++)
            {
                if(sh[v[b][i].S][1]>a+v[b][i].F)
                {
                    sh[v[b][i].S][1]=a+v[b][i].F;
                    pq.push({-sh[v[b][i].S][1],{v[b][i].S,1}});
                }
            }
        }
    }
    //for(int i=1;i<=n;i++)printf("%lld %lld\n",sh[i][0],sh[i][1]);
    if(sh[n][0]>tt&&sh[n][1]>tt)printf("No Honey TT");
    else printf("Happy Winnie the Pooh :3\n"),printf("%lld",min(sh[n][1],sh[n][0]));
}
