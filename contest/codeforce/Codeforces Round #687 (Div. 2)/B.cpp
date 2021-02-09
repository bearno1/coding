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
int t,n,co[100005],k,ans;
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        ans=imx;
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&co[i]);
        }
        for(int col=1;col<=100;col++)
        {
            int cc=0;
            for(int i=1;i<=n;i++)
            {
                if(co[i]==col)continue;
                cc++;
                i+=k-1;
            }
            ans=min(ans,cc);
        }
        printf("%d\n",ans);
    }
}
