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
int t,n,q,l,r;
char c[105];
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        scanf("%d %d",&n,&q);
        scanf("%s",c+1);
        for(int i=1;i<=q;i++)
        {
            bool ans=false;
            scanf("%d %d",&l,&r);
            for(int j=r+1;j<=n;j++)if(c[r]==c[j])ans=true;
            for(int j=1;j<l;j++)if(c[l]==c[j])ans=true;
            if(ans)printf("YES\n");
            else printf("NO\n");
        }
    }
}
