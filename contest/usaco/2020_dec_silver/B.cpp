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
int n,x,y,a,b;
LL ans;
map<int,int>cx,cy;
vector<int>vx,vy;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&x,&y);
        if(cx[x]==0)
        {
            a++;
            cx[x]=1;
        }
        if(cy[y]==0)
        {
            b++;
            cy[y]=1;
        }
    }
    printf("==%d %d\n",a,b);
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            ans+=i*j;
        }
    }
    printf("%lld",ans);
}
