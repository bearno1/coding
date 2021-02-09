#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("sse4")
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
int n,q,seq[400005][2],dis[100005],x,bus[100005],m,ps,cov1[100005],cov2[100005],kp,a,b,c,ans;
LL dif[100005],k;
priority_queue<int,vector<int>,greater<int> >pq;
priority_queue<pii,vector<pii>,greater<pii> >pq1;
pii rr;
void up_seq(int st,int ed,int idx,int pos)
{
    int mid=(st+ed)/2;
    if(pos<st||pos>ed)return;
    if(st==ed)
    {
        seq[idx][0]=dis[cov2[pos]];
        seq[idx][1]=bus[cov2[pos]];
        //printf("{%d %d %d}",cov2[pos],seq[idx][0],seq[idx][1]);
        return;
    }
    up_seq(st,mid,L,pos);
    up_seq(mid+1,ed,R,pos);
    seq[idx][0]=max(seq[L][0],seq[R][0]);
    seq[idx][1]=max(seq[L][1],seq[R][1]);
    return;
}
void em_seq(int st,int ed,int idx,int pos)
{
    int mid=(st+ed)/2;
    if(pos<st||pos>ed)return;
    if(st==ed)
    {
        seq[idx][0]=0;
        seq[idx][1]=0;
        return;
    }
    em_seq(st,mid,L,pos);
    em_seq(mid+1,ed,R,pos);
    seq[idx][0]=max(seq[L][0],seq[R][0]);
    seq[idx][1]=max(seq[L][1],seq[R][1]);
    return;
}
int mx_seq(int st,int ed,int idx,int l,int r,int ty)
{
    int mid=(st+ed)/2;
    if(r<st||l>ed)return 0;
    if(l<=st&&r>=ed)return seq[idx][ty];
    return max(mx_seq(st,mid,L,l,r,ty),mx_seq(mid+1,ed,R,l,r,ty));
}
int main()
{
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&x),pq.push(x);
    for(int i=1;i<=n;i++)dis[i]=pq.top(),pq.pop();
    while(q--)
    {
        ans=0;
        ps=-(1e9);
        scanf("%d",&m);
        for(int i=1;i<=m;i++)scanf("%d",&x),pq.push(x);
        for(int i=1;i<=n;i++)
        {
            if(!pq.empty())
            {
                while(dis[i]>pq.top())
                {
                    ps=pq.top();
                    pq.pop();
                    if(pq.empty())break;
                }
            }
            if(!pq.empty())bus[i]=min(abs(dis[i]-ps),abs(dis[i]-pq.top()));
            else bus[i]=abs(dis[i]-ps);
            dif[i]=dis[i]-bus[i];
            pq1.push({dif[i],i});
        }
        for(int i=1;i<=n;i++)
        {
            //printf("=%d %d %d %d %d=\n",i,pq1.top().S,dis[pq1.top().S],bus[pq1.top().S],pq1.top().F);
            cov1[pq1.top().S]=i;
            cov2[i]=pq1.top().S;
            pq1.pop();
            up_seq(1,n,1,i);
        }
        for(int i=1;i<n;i++)
        {
            em_seq(1,n,1,cov1[i]);
            a=1,b=n,k=dis[i]+bus[i],kp=0;
            //rintf("%d",k);
            while(a<=b)
            {
                c=(a+b)/2;
                if(dif[cov2[i]]-k<0)
                {
                    kp=max(kp,c);
                    a=c+1;
                }
                else
                {
                    b=c-1;
                }
            }
            a=mx_seq(1,n,1,1,kp,0);
            b=mx_seq(1,n,1,kp+1,n,1);
            if(a!=0)a-=dis[i];
            if(b!=0)b+=bus[i];
            //printf("|%d %d %d %d|\n",i,kp,a,b);
            ans=max(ans,max(a,b));
        }
        printf("%d\n",ans);
    }
}
