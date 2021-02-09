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
typedef pair<int,pii> PQ;
int n,d,x,a,b,ans,dif,fen[300005],pl[300005],st,ed,l,r,en[300005],ll,rr,xx,ls;
priority_queue<PQ,vector<PQ>,greater<PQ> >pq;
vector<int>v;
map<int,int>conv;
set<int>s;
set<int>::iterator it;
void up(int idx,int val)
{
    while(idx<300005)
    {
        fen[idx]+=val;
        idx+=(idx)&(-idx);
    }
    return;
}
int ss(int idx)
{
    int re=0;
    while(idx>0)
    {
        re+=fen[idx];
        idx-=(idx)&(-idx);
    }
    return re;
}
int main()
{
    scanf("%d %d",&n,&d);
    ans=d;
    dif=d;
    v.pb(0);
    v.pb(d);
    conv[0]=1;
    conv[d]=d;
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d %d",&x,&a,&b);
        if(conv[x]==0)v.pb(x),conv[x]=x;
        pq.push({b,{-x,a}});
    }
    conv.clear();
    sort(all(v));
    for(int i=0;i<v.size();i++)conv[v[i]]=i+1;
    ed=conv[d];
    st=1;
    pl[st]=d;
    up(st,d);
    s.insert(0);
    s.insert(d);
    while(!pq.empty())
    {
        b=pq.top().F;
        x=-pq.top().S.F;
        a=pq.top().S.S;
        xx=conv[x];
        en[xx]+=a;
        pq.pop();
        it=s.upper_bound(x);
        r=*it;
        it--;
        l=*it;
        ll=conv[l];
        rr=conv[r];
        //printf("{%d %d %d}",ll,xx,rr);
        s.insert(x);
        dif-=pl[ll];
        ls=pl[ll];
        pl[ll]=x-l-en[ll];
        if(pl[ll]<0)
        {
            pl[ll]=max(pl[ll],ss(ll-1)-dif);
        }
        dif+=pl[ll];
        up(ll,pl[ll]-ls);
        pl[xx]=r-x-en[xx];
        //printf("%d ",dif);
        if(pl[xx]<0)
        {
            pl[xx]=max(pl[xx],ss(xx-1)-dif);
        }
        dif+=pl[xx];
        up(ll,pl[xx]);
        //printf("=%d %d %d %d\n",dif,b,pl[xx],pl[ll]);
        if(dif>b)continue;
        if(pq.empty())
        {
            ans=min(ans,dif);
        }
        else
        {
            if(b!=pq.top().F)
            {
                ans=min(ans,dif);
            }
        }
    }
    printf("%d",ans);
}
