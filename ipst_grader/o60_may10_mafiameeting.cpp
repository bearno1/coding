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
const int CON = 1000000;
const long long MMX = (long long)(1e18);
typedef long long LL;
typedef pair<int,int> pii;
int n,m,q,boss[100005],a,b,num[100005],rr,h[100005],par[100005][18],wi[100005][18],na,nb,rl[100005],kl[100005];
vector<int>v[100005],tp[100005];
vector<pair<int,pii> >pat[100005];
pair<int,bool> ans;
bitset<100005>ot,inn,vis;
stack<int>stk;
void dfs1(int N,int pr)
{
    vis[N]=true;
    //printf("o%do",N);
    for(int i=0;i<v[N].size();i++)
    {
        if(v[N][i]==pr)continue;
        if(!vis[v[N][i]])
        {
            dfs1(v[N][i],N);
            tp[v[N][i]].pb(N);
        }
        else
        {
            tp[v[N][i]].pb(N);
        }
    }
    stk.push(N);
    return;
}
void dfs2(int N,int bs)
{
    vis[N]=true;
    for(int i=0;i<tp[N].size();i++)
    {
        if(!vis[tp[N][i]])dfs2(tp[N][i],bs);
    }
    boss[N]=bs;
    return;
}
void dfs(int N,int pr,int d,int ps,int of)
{
    h[N]=d;
    par[N][0]=pr;
    rl[N]=ps;
    kl[N]=of;
    if(rl[N]!=kl[boss[ps]])wi[N][0]=num[pr];
    else wi[N][0]=1;
    //printf("/%d %d/\n",wi[N][0],N);
    for(int i=0;i<pat[N].size();i++)
    {
        if(pat[N][i].F!=pr)dfs(pat[N][i].F,N,d+1,pat[N][i].S.F,pat[N][i].S.S);
    }
    return;
}
void prelca()
{
    for(int i=1;i<18;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(par[j][i-1]!=-1)
            {
                par[j][i]=par[par[j][i-1]][i-1];
                wi[j][i]=wi[par[j][i-1]][i-1]+wi[j][i-1];
            }
        }
    }
    return;
}
pair<int,bool> lca(int a,int b,int ra,int rb)
{
    if(h[a]<h[b])swap(a,b),swap(ra,rb);
    int re=0,dif=h[a]-h[b],ta=a,tb=b;
    if(dif!=0)
    {
        dif--;
        for(int i=0;i<18;i++)
        {
            if((dif>>i)&1)re+=wi[a][i],a=par[a][i];
        }
        if(par[a][0]==b)
        {
            //printf("%d/\n",re);
            if(kl[a]==ra)re++;
            else re+=num[boss[ra]];
            if(ot[rb])re++;
            else re+=num[boss[rb]];
            return {re,true};
        }
        else
        {
            re+=wi[a][0],a=par[a][0];
        }
    }
    //printf("/%d",re);
    for(int i=17;i>-1;i--)
    {
        if(par[a][i]!=par[b][i])
        {
            re+=wi[a][i]+wi[b][i];
            a=par[a][i],b=par[b][i];
        }
    }
    //printf(" %d/\n",re);
    //printf("+%d %d+",rl[a],rl[b]);
    if(inn[ra])re++;
    else re+=num[boss[ra]];
    if(inn[rb])re++;
    else re+=num[boss[rb]];
    if(rl[a]==rl[b])re++;
    else re+=num[par[a][0]];
    return {re,false};
}
int main()
{
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs1(1,-1);
    for(int i=1;i<=n;i++)boss[i]=i,vis[i]=false;
    while(!stk.empty())
    {
        if(!vis[stk.top()])
        {
            dfs2(stk.top(),stk.top());
        }
        stk.pop();
    }
    MEM(num,0);
    MEM(par,-1);
    MEM(wi,-1);
    MEM(rl,-1);
    for(int i=1;i<=n;i++)
    {
        //printf("[%d]\n",boss[i]);
        num[boss[i]]++;
    }
    //for(int i=1;i<=n;i++)printf("%d\n",num[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            if(boss[v[i][j]]!=boss[i])pat[boss[i]].pb({boss[v[i][j]],{i,v[i][j]}});
        }
    }
    dfs(boss[1],-1,0,-1,-1);
    prelca();
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            if(boss[v[i][j]]!=boss[i])
            {
                if(h[boss[v[i][j]]]>h[boss[i]])
                {
                    inn[v[i][j]]=true;
                    ot[i]=true;
                }
                else
                {
                    ot[v[i][j]]=true;
                    inn[i]=true;
                }
            }
        }
    }
    while(q--)
    {
        scanf("%d %d",&a,&b);
        na=boss[a];
        nb=boss[b];
        if(na==nb)
        {
            printf("%d\n",num[na]-2);
        }
        else
        {
            ans=lca(na,nb,a,b);
            //printf("=%d %d=\n",ans.F,ans.S);
            printf("%d\n",ans.F-2);
        }
    }
}
/*
11 14 2
1 2
1 3
2 3
3 4
4 5
4 6
5 6
11 3
5 7
7 8
8 9
9 10
10 7
7 9
11 10
7 8
*/
/*
5 5 1
1 2
2 3
3 4
4 2
2 5
1 5
*/
