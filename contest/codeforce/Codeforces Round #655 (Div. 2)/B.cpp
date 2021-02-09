#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("sse4")
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
int t,n,k;
LL ans,a,b,aa,bb,x;
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        scanf("%d",&n);
        ans=n-1,a=n-1,b=1;
        k=(int)sqrt(n);
        for(int i=1;i<=k;i++)
        {
            LL ans1=INT_MAX,a1=n-1,b1=1,aa1,bb1;
            if(n%i==0)
            {
                //printf("[%d]",i);
                for(int j=1;j<(n/i);j++)
                {
                    aa1=j,bb1=(n/i)-j;
                    if(ans1>(aa1*bb1)/__gcd(aa1,bb1))
                    {
                        ans1=(aa1*bb1)/__gcd(aa1,bb1);
                        a1=aa1;
                        b1=bb1;
                    }
                }
                if(ans>ans1)
                {
                    ans=ans1;
                    a=a1*i;
                    b=b1*i;
                }
                ans1=INT_MAX,a1=n-1,b1=1,aa1,bb1;
                for(int j=1;j<i;j++)
                {
                    aa1=j,bb1=i-j;
                    if(ans1>(aa1*bb1)/__gcd(aa1,bb1))
                    {
                        ans1=(aa1*bb1)/__gcd(aa1,bb1);
                        a1=aa1;
                        b1=bb1;
                    }
                }
                if(ans>ans1)
                {
                    ans=ans1;
                    a=a1*(n/i);
                    b=b1*(n/i);
                }
            }
        }
        printf("%lld %lld\n",a,b);
    }
}
