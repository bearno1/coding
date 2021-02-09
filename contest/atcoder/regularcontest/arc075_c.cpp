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
LL n,k,dp[200005],x,fen[300005],rr;
LL ans;
map<LL,LL>mm;
set<LL>s;
set<LL>::iterator it;
void up(int idx,int val)
{
    while(idx<300005)
    {
        fen[idx]+=val;
        idx+=idx&(-idx);
    }
    return;
}
int ss(int idx)
{
    int re=0;
    while(idx>0)
    {
        re+=fen[idx];
        idx-=idx&(-idx);
    }
    return re;
}
int main()
{
    scanf("%lld %lld",&n,&k);
    s.insert(0);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&x);
        dp[i]=dp[i-1];
        dp[i]+=(x-k);
        s.insert(-dp[i]);
    }
    it=s.begin();
    while(it!=s.end())
    {
        rr++;
        mm[-(*it)]=rr;
        it++;
    }
    for(int i=0;i<=n;i++)up(mm[dp[i]],1);
    for(int i=0;i<n;i++)
    {
        up(mm[dp[i]],-1);
        ans+=ss(mm[dp[i]]);
    }
    printf("%lld",ans);
}
