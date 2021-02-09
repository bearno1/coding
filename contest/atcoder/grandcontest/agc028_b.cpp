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
LL ans,x,pr[100005],sf[100005],co[100005],mul[100005];
int n;
int main()
{
    scanf("%d",&n);
    pr[0]=1,sf[n+1]=1,sf[n+2]=1;
    for(int i=1;i<=n;i++)pr[i]=pr[i-1]*i,pr[i]%=MOD;
    for(int i=n;i>0;i--)sf[i]=sf[i+1]*i,sf[i]%=MOD;
    for(int i=1;i<=n;i++)co[i]=co[i-1]+(pr[i]*sf[i+2]),co[i]%=MOD;
    for(int i=1;i<=(n+1)/2;i++)
    {
        mul[i]+=co[n-i];
        mul[i]+=co[i-1];
        mul[i]%=MOD;
    }
    for(int i=n;i>n/2;i--)mul[i]=mul[n-i+1];
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&x);
        ans+=x*pr[n];
        ans%=MOD;
        ans+=x*mul[i];
        ans%=MOD;
    }
    printf("%lld",(ans+MOD*50)%MOD);
}
