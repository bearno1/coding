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
int n,x,seq[400100],cou[400100];
LL ans;
vector<int>pos[100100];
vector<pair<int,pair<int,int> > >qr[100100];
void up(int st,int ed,int idx,int l,int r,int val)
{
    int mid=(st+ed)/2;
    if(st>r||ed<l)return;
    if(st>=l&&ed<=r)
    {
        cou[idx]+=val;
        if(cou[idx]>0)
        {
            seq[idx]=ed-st+1;
        }
        else if(st!=ed)
        {
            seq[idx]=seq[L]+seq[R];
        }
        else
        {
            seq[idx]=0;
        }
        return;
    }
    up(st,mid,L,l,r,val);
    up(mid+1,ed,R,l,r,val);
    if(cou[idx]>0)
    {
        seq[idx]=ed-st+1;
    }
    else
    {
        seq[idx]=seq[L]+seq[R];
    }
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)pos[i].pb(0);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        pos[x].pb(i);
    }
    for(int i=0;i<n;i++)
    {
        pos[i].pb(n+1);
        for(int j=6;j<pos[i].size();j++)
        {
            qr[pos[i][j-6]+1].pb({1,{pos[i][j-1],pos[i][j]-1}});
            qr[pos[i][j-5]+1].pb({-1,{pos[i][j-1],pos[i][j]-1}});
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<qr[i].size();j++)up(1,n+1,1,qr[i][j].S.F,qr[i][j].S.S,qr[i][j].F);
        ans+=seq[1];
    }
    printf("%lld",ans);
}
