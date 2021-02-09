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
int n,m,a,b,ans;
double x,y,r,pi[105][2];
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf %lf",&pi[i][0],&pi[i][1]);
    }
    for(int i=1;i<=m;i++)
    {
        a=0,b=0;
        scanf("%lf %lf %lf",&x,&y,&r);
        r=r*r;
        for(int j=1;j<=n;j++)
        {
            double dis=((pi[j][0]-x)*(pi[j][0]-x))+((pi[j][1]-y)*(pi[j][1]-y));
            if(dis>r)
            {
                b++;
            }
            else if(abs(dis-r)<1e-6)
            {
                a++,b++;
            }
            else
            {
                a++;
            }
        }
        if(a>0&&b>0)ans++;
    }
    printf("%d",ans);
}
