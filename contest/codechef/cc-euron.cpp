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
const long long K = 10000005;
typedef long long LL;
typedef pair<int,int> pii;
int n,val[100005],fen[K];
LL ans;
int ss(int X)
{
    int re=0;
    while(X>0)
    {
        re+=fen[X];
        X-=X&(-X);
    }
    return re;
}
void up(int X)
{
    while(X<K)
    {
        fen[X]++;
        X+=X&(-X);
    }
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&val[i]);
    for(int i=1;i<=n;i++)
    {
        ans+=ss(K-2-val[i]);
        up(K-1-val[i]);
    }
    printf("%lld",ans);
}
