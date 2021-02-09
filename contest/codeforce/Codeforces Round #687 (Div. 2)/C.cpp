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
int t,n,st,k,x,y,md[100005],ans;
char c[100005];
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        ans=imx;
        scanf("%d %d %d",&n,&st,&k);
        scanf("%s",c+1);
        scanf("%d %d",&x,&y);
        for(int i=0;i<=k;i++)md[i]=0;
        for(int i=n;i>=0;i--)
        {
            if(i+st>n)
            {
                continue;
            }
            if(c[i+st]=='0')
            {
                md[(i+st)%k]+=x;
            }
            ans=min(ans,(i*y)+md[(i+st)%k]);
        }
        printf("%d\n",ans);
    }
}
