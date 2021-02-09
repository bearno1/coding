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
const long long MMX = (long long)(1e18);
typedef long long LL;
LL a,b,k,num[100005],ans=MMX,st=0,ed=MOD,mid,di;
int n;
bool ch(long long p)
{
    long long cc=p;
    for(int i=1;i<=n;i++)
    {
        if(num[i]<=p*b)continue;
        cc-=((num[i]-(p*b)+di-1)/di);
    }
    printf("%lld %lld\n",cc,p);
    if(cc<0)return false;
    else return true;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d %lld %lld",&n,&a,&b);
    printf("%d\n",n);
    di=a-b;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&num[i]);
    }
    while(st<=ed)
    {
        mid=(st+ed)/2;
        if(ch(mid))ans=min(ans,mid),ed=mid-1;
        else st=mid+1;
    }
    printf("%lld",ans);
}
