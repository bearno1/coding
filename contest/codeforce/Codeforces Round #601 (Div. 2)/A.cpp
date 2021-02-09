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
#define out_1(x,y) printf("x",y)
const long long MMX = (long long)(1e18);
typedef long long LL;
int t,n,m;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int ans=0,k;
        scanf("%d %d",&n,&m);
        if(n<=m)
        {
            k=m-n;
            ans+=k/5;
            k%=5;
            ans+=k/2;
            k%=2;
            ans+=k;
            out_1(%d,ans);
        }
        else
        {
            k=n-m;
            ans+=k/5;
            k%=5;
            ans+=k/2;
            k%=2;
            ans+=k;
            printf("%d\n",ans);
        }
    }
}
