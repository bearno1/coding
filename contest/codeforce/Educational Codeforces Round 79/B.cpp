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
LL ss,mx1,mx2,tp;
bool p;
int main()
{
    int t,a,b,c,n,s,x;
    scanf("%d",&t);
    while(t--)
    {
        ss=0;
        mx1=0;
        mx2=0;
        tp=0;
        p=false;
        scanf("%d %d",&n,&s);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            ss+=x;
            if(p)continue;
            tp=max(tp,(LL)x);
            if(ss-tp>s)p=true;
            if(p)continue;
            if(mx1<x)mx1=x,mx2=i;
        }
        //printf("---%lld %d %lld\n",ss,s,mx2);
        if(ss>s)printf("%lld\n",mx2);
        else printf("0\n");
    }
}
