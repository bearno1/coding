#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("sse4")
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define imx INT_MAX
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef unsigned long long LL;
typedef pair<int,int> pii;
int n,rr;
LL di[200005],sd[200005],ans=ULLONG_MAX,mul[200005],dr,m;
int main()
{
    scanf("%d %llu",&n,&m);
    for(int i=1;i<=n;i++)
    {
        mul[i]=(i*2)+1;
        scanf("%llu",&di[i]);
        sd[i]=sd[i-1]+di[i];
    }
    mul[1]=5;
    for(int i=1;i<=n;i++)
    {
        dr=(LL)(n+i)*m;
        rr=0;
        for(int j=n;j>0;j-=i)
        {
            rr++;
            int nx=max(j-i,0);
            dr+=(sd[j]-sd[nx])*mul[rr];
        }
        ans=min(ans,dr);
        //printf("%lld %d\n",dr,i);
    }
    printf("%llu",ans);
}
