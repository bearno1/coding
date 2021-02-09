#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("sse4")
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
LL n,ans[100000005],k[100000005],p;
bitset<100000005>bb;
void ch(int x)
{
    ans[x]++;
    if(x==1||x==0)return;
    if(x%2==0)
    {
        ch(x/2);
    }
    else
    {
        ch(x-1);
    }
    return;
}
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        ch(i);
    }
    for(int i=1;i<=n;i++)
    {
        k[ans[i]]=max(k[ans[i]],(LL)i);
        bb[ans[i]]=true;
    }
    for(int i=n;i>0;i--)
    {
        k[i]=max(k[i],k[i+1]);
    }
    for(int i=1;i<=n;i++)
    {
        if(!bb[i])continue;
        if(k[i]==k[i-1])continue;
        printf("%d %lld\n",i,k[i]);
        p++;
    }
    printf("{%lld}",p);
}
