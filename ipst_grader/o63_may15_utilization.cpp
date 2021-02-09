#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define F first
#define S second
#define imx ((int)1e9)
#define all(x) ((x).begin(),((x).end())
#define pb push_back
typedef long long LL;
int n,q,a,b,gr[100005],si[100005],nu[100005],k,a1,a2;
vector<int>v[100005];
LL val[100005],ans;
multiset<LL>ms[2];
multiset<LL>::iterator it;
struct node
{
    LL va[4];
    node *l=NULL,*r=NULL;
}nn[100005];
LL dfs(int N,int pr)
{
    //printf("[%d]",N);
    LL mx1=-1e12,mx2=-1e12,k;
    for(int i=0;i<v[N].size();i++)
    {
        if(v[N][i]!=pr)
        {
            k=dfs(v[N][i],N);
            if(k>mx1)mx2=mx1,mx1=k;
            else if(k>mx2)mx2=k;
        }
    }
    ans=max(ans,mx1);
    ans=max(ans,mx1+val[N]);
    ans=max(ans,val[N]);
    ans=max(ans,mx1+mx2+val[N]);
    return max(mx1+val[N],val[N]);
}
void cons(node *N,int st,int ed)
{
    int mid=(st+ed)/2;
    if(st==ed)
    {
        for(int i=0;i<4;i++)N->va[i]=val[st];
        return;
    }
    node *c=new node;
    cons(c,st,mid);
    c=new node;
    N->l=c;
    cons(c,mid+1,ed);
    N->r=c;
    N->va[0]=N->l->va[0]+N->r->va[0];
    N->va[1]=max(N->l->va[1],max(N->r->va[1],N->l->va[2]+N->r->va[3]));
    N->va[2]=max(N->r->va[2],N->r->va[0]+N->l->va[2]);
    N->va[2]=max(N->l->va[3],N->l->va[0]+N->r->va[3]);
    return;
}
void up(node *N,int st,int ed,int pos)
{
    int mid=(st+ed)/2;
    if(st>pos||ed<pos)return;
    if(st==ed)
    {
        for(int i=0;i<4;i++)N->va[i]=val[st];
        return;
    }
    up(N->l,st,mid,pos);
    up(N->r,mid+1,ed,pos);
    N->va[0]=N->l->va[0]+N->r->va[0];
    N->va[1]=max(N->l->va[1],max(N->r->va[1],N->l->va[2]+N->r->va[3]));
    N->va[2]=max(N->r->va[2],N->r->va[0]+N->l->va[2]);
    N->va[2]=max(N->l->va[3],N->l->va[0]+N->r->va[3]);
    return;
}
void dfs1(int N,int pr,int g,int s)
{
    gr[N]=g;
    nu[N]=s;
    si[g]=max(si[g],s);
    for(int i=0;i<v[N].size();i++)
    {
        if(v[N][i]!=pr)
        {
            dfs1(v[N][i],N,g,s+1);
        }
    }
    return;
}
int main()
{
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&val[i]);
    }
    for(int i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        v[a].pb(b);
        v[b].pb(a);
    }
    if(n<=1000&&q<=1000)
    {
        ans=-1e12;
        dfs(1,-1);
        printf("%lld\n",ans);
        for(int i=1;i<=q;i++)
        {
            scanf("%d %d",&a,&b);
            val[a]=b;
            ans=-1e12;
            dfs(1,-1);
            printf("%lld\n",ans);
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(v[i].size()>2)
            {
                k=i;
            }
        }
        for(int i=0;i<=v[k].size();i++)
        {
            dfs1(v[k][i],k,0,1);
            cons(&nn[i],1,si[i]);
            ms[0].insert(nn[i].va[2]);
            ms[1].insert(nn[i].va[1]);
        }
        it=ms[0].begin();
        a1=*it;
        it++;
        if(it!=ms[0].end())a2=*it;
        it=ms[1].begin();
        printf("%lld\n",max((LL)val[k],max(val[k]+a1,max(val[k]+a1+a2,*it))));
        for(int i=1;i<=q;i++)
        {
            scanf("%d %d",&a,&b);
            val[a]=b;
            if(a!=k)
            {
                if(ms[0].find(nn[gr[a]].va[2])!=ms[0].end())ms[0].erase(ms[0].find(nn[gr[a]].va[2]));
                if(ms[1].find(nn[gr[a]].va[1])!=ms[1].end())ms[1].erase(ms[1].find(nn[gr[a]].va[1]));
                up(&nn[gr[a]],1,si[gr[a]],nu[a]);
                ms[0].insert(nn[i].va[2]);
                ms[1].insert(nn[i].va[1]);
                it=ms[0].begin();
                a1=*it;
                it++;
                if(it!=ms[0].end())a2=*it;
                it=ms[1].begin();
                printf("%lld\n",max((LL)val[k],max(val[k]+a1,max(val[k]+a1+a2,*it))));
            }
        }
    }
}
