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
LL n,a,b,ans,aa,bb,tt;
int main()
{
    scanf("%lld %lld %lld",&n,&a,&b);
    if(abs(a-b)%2==0)printf("%lld",abs(a-b)/2);
    else
    {
        ans=min(max(a,b)-1,n-min(a,b));
        tt=a,aa=1,bb=b-tt;
        ans=min(ans,tt+(abs(aa-bb)/2));
        tt=n-b+1,aa=a+tt,bb=n;
        ans=min(ans,tt+(abs(aa-bb)/2));
        printf("%lld",ans);
    }
}
