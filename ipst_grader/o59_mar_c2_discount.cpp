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
typedef pair<int,pair<int,int> > PQ;
int n,m,ans=imx,a,b,co,par[20005][16],wi[20005][16],boss[20005],lv[20005];
priority_queue<PQ, vector<PQ>, greater<PQ> > pq;
queue<pair<int,pair<int,int> > >ch;
vector<pair<int,int> >v[20005];
int F(int x)
{
    if(x==boss[x])return x;
    else return boss[x]=F(boss[x]);
}
void un(int x,int y)
{
    boss[F(x)]=F(y);
    return;
}
void dfs(int N,int pr)
{
    par[N][0]=pr;
    if(N!=0)lv[N]=lv[pr]+1;
    for(int i=0;i<v[N].size();i++)
    {
        if(v[N][i].F!=pr)wi[v[N][i].F][0]=v[N][i].S,dfs(v[N][i].F,N);
    }
    return;
}
void genlca()
{
    for(int i=1;i<16;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(par[j][i-1]!=-1)
            {
                par[j][i]=par[par[j][i-1]][i-1];
                wi[j][i]=max(wi[j][i-1],wi[par[j][i-1]][i-1]);
            }
        }
    }
    return;
}
int lca(int a,int b)
{
    if(lv[a]<lv[b])swap(a,b);
    int dif=lv[a]-lv[b],re=0;
    for(int i=0;i<16;i++)
    {
        if((dif>>i)&1)re=max(re,wi[a][i]),a=par[a][i];
    }
    if(a==b)return re;
    for(int i=15;i>-1;i--)
    {
        if(par[a][i]!=par[b][i])
        {
            re=max(re,max(wi[a][i],wi[b][i]));
            a=par[a][i];
            b=par[b][i];
        }
    }
    return max(re,max(wi[a][0],wi[b][0]));
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<=n;i++)boss[i]=i;
    for(int i=0;i<20005;i++)for(int j=0;j<16;j++)par[i][j]=-1,wi[i][j]=-1;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&co);
        pq.push({co,{a,b}});
    }
    while(!pq.empty())
    {
        a=pq.top().S.F;
        b=pq.top().S.S;
        co=pq.top().F;
        pq.pop();
        if(F(a)!=F(b))
        {
            un(a,b);
            v[a].pb({b,co});
            v[b].pb({a,co});
        }
        else
        {
            ch.push({co,{a,b}});
        }
    }
    lv[0]=1;
    dfs(0,-1);
    genlca();
    while(!ch.empty())
    {
        a=ch.front().S.F;
        b=ch.front().S.S;
        co=ch.front().F;
        ch.pop();
        //printf("{%d %d %d %d}\n",co,lca(a,b),a,b);
        ans=min(ans,co-lca(a,b)+1);
    }
    printf("%d",ans);
}
