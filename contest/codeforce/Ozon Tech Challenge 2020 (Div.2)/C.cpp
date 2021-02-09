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
int n,m,p;
LL ans,rr,cc,k[1005];
bool ch;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&p),k[p%m]++;
    for(int i=0;i<=m;i++)
    {
        for(int j=i;j<=m;j++)
        {
            cc=j-i;
            rr=k[i]*k[j];
            if(rr!=0)ans*=rr*cc,ans%=m;
            if(!ch&&rr!=0)ch=true,ans=rr*cc,ans%=m;
            //printf("[%lld]",ans);
        }
    }
    printf("%lld",ans);
}
