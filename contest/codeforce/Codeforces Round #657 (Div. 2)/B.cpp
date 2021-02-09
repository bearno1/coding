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
LL t,l,r,m,k,p,a,b,c;
int main()
{
    scanf("%lld",&t);
    for(int tt=1;tt<=t;tt++)
    {
        scanf("%lld %lld %lld",&l,&r,&m);
        p=r-l;
        for(int i=l;i<=r;i++)
        {
            k=m%i;
            if(k<=p&&(m-k)>=i)
            {
                //printf("== %d %lld %lld\n",i,l+r,l);
                a=i;
                b=l+k;
                c=l;
            }
            else if(i-k<=p)
            {
                a=i;
                b=l;
                c=l+(i-k);
            }
        }
        printf("%lld %lld %lld\n",a,b,c);
    }
}
