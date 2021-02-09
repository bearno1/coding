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
int t,n,k,x,di,cc;
LL ans;
vector<int>v;
int main()
{
    scanf("%d",&t);
    for(int tt=0;tt<t;tt++)
    {
        ans=0;
        v.clear();
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n*k;i++)
        {
            scanf("%d",&x);
            v.pb(x);
        }
        sort(all(v));
        di=(n/2)+1,cc=v.size()-1-(n/2);
        for(int i=1;i<=k;i++,cc-=di)
        {
            ans+=v[cc];
        }
        printf("%lld\n",ans);
    }
}
