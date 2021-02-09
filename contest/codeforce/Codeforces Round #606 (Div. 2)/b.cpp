#include<bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC target ("sse4")
using namespace std;
#define PB push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define imx INT_MAX
#define inI(x) scanf("%d",&x)
#define inI2(x,y) scanf("%d %d",&x,&y)
#define inI3(x,y,z) scanf("%d %d %d",&x,&y,&z)
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
int t,n,x;
LL ans;
map<int,bool>mm;
int main()
{
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        ans=0;
        mm.clear();
        scanf("%d",&n);
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&x);
            while(x%2==0)
            {
                if(!mm[x])mm[x]=true,ans++;
                else break;
                x/=2;
            }
        }
        printf("%lld\n",ans);
    }
}
