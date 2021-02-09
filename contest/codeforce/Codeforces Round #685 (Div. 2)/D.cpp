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
LL t,n,k,w[100005],x,rr,tp,a,u;
int main()
{
    scanf("%lld",&t);
    for(int tt=1;tt<=t;tt++)
    {
        a=0,u=0;
        scanf("%lld %lld",&n,&k);
        x=0,rr=0;
        for(;x<=n;rr++,x+=k)
        {
            tp=rr+(sqrt((n*n)-(x*x))/k);
            if(tp%2==0)
            {
                u++;
            }
            else
            {
                a++;
            }
        }
        if(a>u)printf("Ashish\n");
        else printf("Utkarsh\n");
    }
}
