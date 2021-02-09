#include<bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC target ("sse4")
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define L (idx*2)
#define R ((idx*2)+1)
#define imx INT_MAX
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
typedef pair<int,int> pii;
int n,x[200005],ap,bp,ss,ee;
pii seq[800005][2];
priority_queue<pair<int,pair<pii,pii> > >pq;
void up(int st,int ed,int idx,int pos,int val)
{
    int mid=(st+ed)/2;
    if(st>pos||ed<pos)return;
    if(st==ed)
    {
        seq[idx][pos%2]={val,pos};
        return;
    }
    up(st,mid,L,pos,val);
    up(mid+1,ed,R,pos,val);
    if(seq[L][0].F>seq[R][0].F)
    {
        seq[idx][0]=seq[R][0];
    }
    else
    {
        seq[idx][0]=seq[L][0];
    }
    if(seq[L][1].F>seq[R][1].F)
    {
        seq[idx][1]=seq[R][1];
    }
    else
    {
        seq[idx][1]=seq[L][1];
    }
    return;
}
pii mx(int st,int ed,int idx,int l,int r,int tp)
{
    int mid=(st+ed)/2;
    if(st>r||ed<l)return {imx,imx};
    if(l<=st&&r>=ed)return seq[idx][tp];
    pii a,b;
    a=mx(st,mid,L,l,r,tp);
    b=mx(mid+1,ed,R,l,r,tp);
    if(a.F>b.F)
    {
        return b;
    }
    else
    {
        return a;
    }
}
void pq_push(int st,int ed)
{
    //printf("%d %d\n",st,ed);
    if(ed-st+1<2)return;
    //printf("%d %d\n",st,ed);
    pii a=mx(1,n,1,st,ed,st%2);
    pii b=mx(1,n,1,a.S+1,ed,(st+1)%2);
    pq.push({-a.F,{{st,ed},{a.S,b.S}}});
    return;
}
int main()
{
    for(int i=0;i<800005;i++)seq[i][0]={imx,imx},seq[i][1]={imx,imx};
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x[i]);
        up(1,n,1,i,x[i]);
    }
    pq_push(1,n);
    while(!pq.empty())
    {
        ap=pq.top().S.S.F;
        bp=pq.top().S.S.S;
        ss=pq.top().S.F.F;
        ee=pq.top().S.F.S;
        pq.pop();
        printf("%d %d ",x[ap],x[bp]);
        pq_push(ss,ap-1);
        pq_push(ap+1,bp-1);
        pq_push(bp+1,ee);
    }
}
