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
int t,n,m,a[1005],b[1005],ans;
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        bool p=false;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=m;i++)scanf("%d",&b[i]);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i]==b[j])p=true,ans=a[i];
            }
        }
        if(p)printf("YES\n1 %d\n",ans);
        else printf("NO\n");
    }
}
