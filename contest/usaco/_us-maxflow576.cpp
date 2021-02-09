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
struct node
{
    int s,t,val=0;
    node *l=NULL,*r=NULL;
}ss[50005];
int par[50005][18],n,m,h[50005],seq[50005][2],ww[50005],a,b,k,ans,tc,num,si[50005],boss[50005];
bitset<50005>ing;
vector<int>v[50005];
int dfs(int cur,int prev)
{
    h[cur]=h[prev]+1;
    par[cur][0]=prev;
    int w=0;
    for(int i=0;i<v[cur].size();i++)
    {
        if(v[cur][i]!=prev)w+=dfs(v[cur][i],cur);
    }
    ww[cur]=w+1;
    return ww[cur];
}
void cons(int cur,int prev)
{
    int go1,go2;
    ing[cur]=true;
    seq[cur][0]=tc;
    seq[cur][1]=num;
    if(num==1)boss[tc]=cur;
    si[tc]=max(si[tc],num);
    while(1)
    {
        go1=0,go2=0;
        for(int i=0;i<v[cur].size();i++)
        {
            if(!ing[v[cur][i]]&&v[cur][i]!=prev)
            {
                if(go2<ww[v[cur][i]])
                {
                    go2=ww[v[cur][i]];
                    go1=v[cur][i];
                }
            }
        }
        if(go1==0)
        {
            if(boss[tc]!=0)tc++,num=0;
            return;
        }
        num++;
        cons(go1,cur);
    }
}
int lca(int x,int y)
{
    if(h[x]<h[y])swap(x,y);
    int dif=h[x]-h[y];
    for (int i=0; i<18; i++)
    {
        if ((dif>>i)&1)x=par[x][i];
    }
    if(x==y)return x;
    for(int i=17;i>-1;i--)
    {
        if(par[x][i]!=par[y][i])
        {
            x=par[x][i];
            y=par[y][i];
        }
    }
    return par[x][0];
}
void seq_con(node *N)
{
    int mid=(N->s+N->t)/2;
    if(N->s==N->t)return;
    node *nn=new node;
    nn->s=N->s;
    nn->t=mid;
    N->l=nn;
    seq_con(nn);
    nn=new node;
    nn->s=mid+1;
    nn->t=N->t;
    N->r=nn;
    seq_con(nn);
    return;
}
void seq_up(node *N,int st,int ed)
{
    if(N->s>ed||N->t<st)return;
    if(N->s>=st&&N->t<=ed)
    {
        N->val++;
        return;
    }
    seq_up(N->l,st,ed);
    seq_up(N->r,st,ed);
    return;
}
int seq_sum(node *N,int pos)
{
    if(N->s>pos||N->t<pos)return 0;
    if(N->s==N->t)
    {
        return N->val;
    }
    return seq_sum(N->l,pos)+seq_sum(N->r,pos)+N->val;
}
void trav(int x,int y,bool o)
{
    while(x!=y)
    {
        if(seq[x][0]==seq[y][0])
        {
            if(o)seq_up(&ss[seq[x][0]],seq[y][1],seq[x][1]);
            else seq_up(&ss[seq[x][0]],seq[y][1]+1,seq[x][1]);
            x=y;
        }
        else
        {
            seq_up(&ss[seq[x][0]],1,seq[x][1]);
            x=par[boss[seq[x][0]]][0];
            if(x==y&&o)seq_up(&ss[seq[x][0]],seq[x][1],seq[x][1]);
        }
    }
    return;
}
int main()
{
    freopen("maxflow.in","r",stdin);
    freopen("maxflow.out","w",stdout);
    memset(par,-1,sizeof(par));
    scanf("%d %d",&n,&m);
    for(int i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1,-1);
    for(int i=1;i<18;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(par[j][i-1]!=-1)par[j][i]=par[par[j][i-1]][i-1];
        }
    }
    tc=1,num=1;
    cons(1,-1);
    for(int i=1;i<=n;i++)
    {
        if(si[i]!=0)
        {
            ss[i].s=1;
            ss[i].t=si[i];
            seq_con(&ss[i]);
        }
    }
    while(m--)
    {
        scanf("%d %d",&a,&b);
        k=lca(a,b);
        if(a!=k)
        {
            trav(a,k,true);
            if(b!=k)trav(b,k,false);
        }
        else
        {
            if(b!=k)trav(b,k,true);
        }
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,seq_sum(&ss[seq[i][0]],seq[i][1]));
    }
    printf("%d",ans);
}
