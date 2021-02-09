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
const long long MOD = (long long)(33331);
const long long MMX = (long long)(1e18);
typedef long long LL;
typedef pair<int,int> pii;
int n,m,q,a,b,c,mmd[10000005],bs[100005],h[100005],par[100005][18],wi[100005][18];
vector<pii>v[100005];
priority_queue<pair<int,pair<int,int> > >pq;
int F(int x)
{
    if(bs[x]==x)return x;
    else return bs[x]=F(bs[x]);
}
void un(int x,int y)
{
    bs[F(x)]=F(y);
    return;
}
void dfs(int N,int pr,int dis,int d)
{
    h[N]=d;
    par[N][0]=pr;
    wi[N][0]=dis;
    for(int i=0;i<v[N].size();i++)
    {
        if(v[N][i].F!=pr)
        {
            //printf("-%d %d-\n",N,v[N][i].F);
            dfs(v[N][i].F,N,v[N][i].S,d+1);
        }
    }
    return;
}
int lca(int a,int b)
{
    if(h[a]<h[b])swap(a,b);
    int re=0,dif=h[a]-h[b];
    for(int i=0;i<18;i++)
    {
        if(1&(dif>>i))
        {
            re+=wi[a][i];
            a=par[a][i];
        }
    }
    if(a==b)return re;
    for(int i=17;i>-1;i--)
    {
        if(par[a][i]!=par[b][i])
        {
            re+=wi[a][i]+wi[b][i];
            a=par[a][i];
            b=par[b][i];
        }
    }
    re+=wi[a][0]+wi[b][0];
    return re;
}
int main()
{
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=n;i++)
    {
        bs[i]=i;
        for(int j=0;j<18;j++)par[i][j]=-1,wi[i][j]=-1;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        pq.push({-c,{a,b}});
    }
    mmd[0]=1;
    for(int i=1;i<10000005;i++)mmd[i]=(mmd[i-1]*2)%MOD;
    while(!pq.empty())
    {
        c=-pq.top().F;
        a=pq.top().S.F;
        b=pq.top().S.S;
        pq.pop();
        if(F(a)!=F(b))
        {
            un(a,b);
            v[a].pb({b,mmd[c]});
            v[b].pb({a,mmd[c]});
        }
    }
    dfs(1,-1,-1,1);
    for(int i=1;i<18;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(par[j][i-1]!=-1)
            {
                par[j][i]=par[par[j][i-1]][i-1];
                wi[j][i]=wi[j][i-1]+wi[par[j][i-1]][i-1];
                wi[j][i]%=MOD;
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",lca(a,b)%MOD);
    }
}
/*
4 5 4
1 2 3
3 1 0
3 2 4
2 4 5
4 3 2
2 3
3 4
1 4
2 4
*/
