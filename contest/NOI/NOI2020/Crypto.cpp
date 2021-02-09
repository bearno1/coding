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
int n,fen[300005],x,pos[300005],id;
LL co[300005],nn,ans;
priority_queue<pii>pq;
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
    scanf("%d",&n);
    co[1]=1;
    for(LL i=2;i<=n;i++)co[i]=(co[i-1]*i)%MOD;
    for(int i=1;i<=n;i++)up(i,1);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        pq.push({x,i});
    }
    for(int i=n;i>0;i--)
    {
        pos[pq.top().S]=i;
        pq.pop();
    }
    // for(int i=1;i<=n;i++)printf("%d ",pos[i]);
    // printf("\n");
    for(int rr=n;rr>1;rr--)
    {
        id=n-rr+1;
        nn=ss(pos[id]);
        up(pos[id],-1);
        if(rr==2)ans+=nn;
        else ans+=((nn-1)*co[rr-1]);
        //printf("=%lld %d\n",nn,x);
        ans%=MOD;
    }
    if(n==1)printf("1");
    else printf("%lld",ans);
}
