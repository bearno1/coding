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
int t,n,x;
vector<int>v[2];
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        v[0].clear();
        v[1].clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            v[x%2].pb(i);
        }
        if(!v[0].empty())
        {
            printf("1\n");
            printf("%d\n",v[0][0]);
        }
        else if(v[1].size()>1)
        {
            printf("2\n");
            printf("%d %d\n",v[1][0],v[1][1]);
        }
        else printf("-1\n");
    }
}
