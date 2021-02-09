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
typedef pair<int,pair<int,int> > PQ;
int n,a[100005],b[100005],co[100005],r,pv=-1,l,val,ss,ans,seq[800005][2],rr,mx[800005][2];
map<int,int>m;
priority_queue<int,vector<int>,greater<int> >pq;
priority_queue<PQ,vector<PQ>,greater<PQ> >q;
void up(int st,int ed,int idx,int cc,int ll,int rr,int T)
{
    int mid=(st+ed)/2;
    if(rr<st||ll>ed)return;
    if(ll<=st&&rr>=ed)
    {
        seq[idx][T]+=cc;
        if(st==ed)
        {
            mx[idx][T]=seq[idx][T];
        }
        else
        {
            mx[idx][T]=max(mx[L][T],mx[R][T])+seq[idx][T];
        }
        return;
    }
    up(st,mid,L,cc,ll,rr,T);
    up(mid+1,ed,R,cc,ll,rr,T);
    mx[idx][T]=max(mx[L][T],mx[R][T])+seq[idx][T];
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d %d",&a[i],&b[i],&co[i]);
        pq.push(a[i]);
        pq.push(b[i]);
    }
    while(!pq.empty())
    {
        if(pq.top()!=pv)rr++,pv=pq.top(),m[pq.top()]=rr;
        pq.pop();
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=m[a[i]];
        b[i]=m[b[i]];
        q.push({a[i],{b[i],co[i]}});
        q.push({b[i]+1,{a[i],co[i]}});
        //printf("{%d %d %d}\n",i,a[i],b[i]);
    }
    for(int i=1;i<=rr;i++)
    {
        if(!q.empty())
        {
            while(q.top().F==i)
            {
                l=q.top().F;
                r=q.top().S.F;
                val=q.top().S.S;
                q.pop();
                if(l<=r)
                {
                    ss+=val;
                }
                else
                {
                    swap(l,r);
                    r--;
                    ss-=val;
                    up(1,rr,1,val,l,r,0);
                    up(1,rr,1,val,l,r,1);
                }
                if(q.empty())break;
            }
        }
        ans=max(mx[1][1]+ss,ans);
        up(1,rr,1,mx[1][0],i,i,1);
        //printf("%d %d %d %d\n",i,mx[1][0],mx[1][1],ss);
    }
    printf("%d",ans);
}
