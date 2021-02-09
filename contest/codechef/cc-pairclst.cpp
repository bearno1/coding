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
typedef pair<int,pair<int,int> > PQ;
int n,m,k,x,a,b,c;
vector<pair<int,int> >v[100005];
priority_queue<PQ, vector<PQ>, greater<PQ> > pq;
pair<int,int>s[100005][2],tp;
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        s[i][0]={imx,imx};
        s[i][1]={imx,imx};
    }
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&x);
        s[x][0]={0,x};
        pq.push({0,{x,x}});
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        v[a].pb({b,c});
        v[b].pb({a,c});
    }
    while(!pq.empty())
    {
        a=pq.top().F;
        b=pq.top().S.F;
        c=pq.top().S.S;
        pq.pop();
        for(int i=0;i<v[b].size();i++)
        {
            int cost=v[b][i].S+a,go=v[b][i].F;
            if(cost<s[go][0].F)
            {
                if(c!=s[go][0].S)
                {
                    tp=s[go][0];
                    s[go][1]=tp;
                }
                s[go][0]={cost,c};
                pq.push({cost,{go,c}});
            }
            if(cost<s[go][1].F)
            {
                if(c!=s[go][0].S)
                {
                    s[go][1]={cost,c};
                    pq.push({cost,{go,c}});
                }
            }
        }
    }
    int ans=imx;
    for(int i=1;i<=n;i++)
    {
        //printf("%d %d %d | %d %d\n",i,s[i][0].F,s[i][0].S,s[i][1].F,s[i][1].S);
        ans=min(ans,s[i][0].F+s[i][1].F);
    }
    printf("%d",ans);
}
