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
int n,k,h[105],t,x,rr,ans;
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        scanf("%d %d",&n,&k);
        h[n+1]=0,h[n+2]=1000,x=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&h[i]);
        }
        while(1)
        {
            x++;
            rr=1;
            while(h[rr]>=h[rr+1])
            {
                rr++;
            }
            if(rr==n+1)
            {
                ans=-1;
                break;
            }
            else
            {
                ans=rr;
                h[rr]++;
            }
            if(x==k)break;
        }
        printf("%d\n",ans);
    }
}
