#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define all(x) ((x).begin(),(x).end())
#define F first
#define S second
#define L (idx*2)
#define R ((idx*2)+1)
#define pb push_back
typedef long long LL;
typedef pair<LL,LL> pii;
int n,ty[1000005],rr,gr[1000005],a,b;
LL dis[1000005],dis2[1000005],seq[4000005][2],k,co,ans,co1;
map<int,int>mm;
priority_queue<int,vector<int>,greater<int> >pq;
vector<int>v[1000005];
queue<int>del;
queue<pii>q;
void up_seq(int st,int ed,int idx,int pos,LL val,int ty)
{
    int mid=(st+ed)/2;
    if(st>pos||ed<pos)return;
    if(st==ed)
    {
        if(abs(val-(LL)1e15)<1)seq[idx][ty]=1e15;
        else seq[idx][ty]=min(val,seq[idx][ty]);
        return;
    }
    up_seq(st,mid,L,pos,val,ty);
    up_seq(mid+1,ed,R,pos,val,ty);
    seq[idx][ty]=min(seq[L][ty],seq[R][ty]);
    return;
}
LL mx_seq(int st,int ed,int idx,int l,int r,int ty)
{
    int mid=(st+ed)/2;
    if(l>ed||r<st)return 1e15;
    if(l<=st&&r>=ed)return seq[idx][ty];
    return min(mx_seq(st,mid,L,l,r,ty),mx_seq(mid+1,ed,R,l,r,ty));
}
LL dd(int x,int y)
{
    if(x>y)
    {
        return dd(x,n)+dd(1,y)+dis[n]-dis[n-1];
    }
    else
    {
        return dis[y-1]-dis[x-1];
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&ty[i]);
        if(mm[ty[i]]==0)
        {
            mm[ty[i]]=1;
            pq.push(ty[i]);
        }
    }
    while(!pq.empty())
    {
        rr++;
        mm[pq.top()]=rr;
        pq.pop();
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&dis[i]);
    }
    for(int i=1;i<=n;i++)
    {
        ty[i]=mm[ty[i]];
        v[ty[i]].pb(i);
        gr[ty[i]]++;
        dis2[n-i+1]=dis2[n-i+2]+dis[n-i+1];
        //printf("%d ",ty[i]);
    }
    //printf("\n");
    for(int i=1;i<=n;i++)
    {
        dis[i]=dis[i-1]+dis[i];
    }
    gen()
}
