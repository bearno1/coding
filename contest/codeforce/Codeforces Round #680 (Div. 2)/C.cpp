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
int t;
LL a,b,x,k,ans,kk;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ans=1;
        scanf("%lld%lld",&a,&b);
        x=a;
        if(a%b!=0)ans=a;
        for(int i=2;i<=31628;i++)
        {
            if(x%i!=0&&b%i!=0)continue;
            k=x;
            while(k%b==0&&k%i==0)
            {
                k/=i;
            }
            ans=max(ans,k);
        }

        printf("%lld\n",ans);
    }
}
