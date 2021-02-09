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
#define L (idx*2)
#define R ((idx*2)+1)
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
int n,m,x,a,b,c;
char o[5];
LL seq[800005][2],lz[800005];
void up_seq(int st,int ed,int idx,int l,int r,int val)
{
    int mid=(st+ed)/2;
    if(lz[idx]!=0)
    {
        seq[idx][0]+=(LL)(ed-st+1)*(LL)(lz[idx]);
        seq[idx][1]+=(LL)(lz[idx]);
        if(st!=ed)lz[L]+=lz[idx],lz[R]+=lz[idx];
        lz[idx]=0;
    }
    if(st>r||ed<l)return;
    if(st>=l&&ed<=r)
    {
        seq[idx][0]+=(LL)(ed-st+1)*(LL)(val);
        seq[idx][1]+=(LL)(val);
        if(st!=ed)lz[L]+=val,lz[R]+=val;
        return;
    }
    up_seq(st,mid,L,l,r,val);
    up_seq(mid+1,ed,R,l,r,val);
    seq[idx][0]=seq[L][0]+seq[R][0];
    seq[idx][1]=min(seq[L][1],seq[R][1]);
    return;
}
LL min_seq(int st,int ed,int idx,int l,int r)
{
    //printf("{%lld %d %d}\n",seq[idx][1],st,ed);
    int mid=(st+ed)/2;
    if(lz[idx]!=0)
    {
        seq[idx][0]+=(LL)(ed-st+1)*(LL)(lz[idx]);
        seq[idx][1]+=(LL)(lz[idx]);
        if(st!=ed)lz[L]+=lz[idx],lz[R]+=lz[idx];
        lz[idx]=0;
    }
    if(st>r||ed<l)return imx;
    if(st>=l&&ed<=r)return seq[idx][1];
    return min(min_seq(st,mid,L,l,r),min_seq(mid+1,ed,R,l,r));
}
LL ss_seq(int st,int ed,int idx,int l,int r)
{
    int mid=(st+ed)/2;
    if(lz[idx]!=0)
    {
        seq[idx][0]+=(LL)(ed-st+1)*(LL)(lz[idx]);
        seq[idx][1]+=(LL)(lz[idx]);
        if(st!=ed)lz[L]+=lz[idx],lz[R]+=lz[idx];
        lz[idx]=0;
    }
    if(st>r||ed<l)return 0;
    if(st>=l&&ed<=r)return seq[idx][0];
    return ss_seq(st,mid,L,l,r)+ss_seq(mid+1,ed,R,l,r);
}
int main()
{
    freopen("haybales.in","r",stdin);
    freopen("haybales.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        up_seq(1,n,1,i,i,x);
        //printf("==%d\n",i);
    }
    while(m--)
    {
        scanf("%s",o);
        if(o[0]=='P')scanf("%d %d %d",&a,&b,&c),up_seq(1,n,1,a,b,c);
        else if(o[0]=='M')scanf("%d %d",&a,&b),printf("%lld\n",min_seq(1,n,1,a,b));
        else scanf("%d %d",&a,&b),printf("%lld\n",ss_seq(1,n,1,a,b));
        //printf("--%d\n",m);
    }
}
